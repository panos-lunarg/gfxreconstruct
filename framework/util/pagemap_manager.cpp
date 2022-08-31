/*
** Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2015-2020 Valve Corporation
** Copyright (c) 2015-2022 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include "util/pagemap_manager.h"

#include "util/logging.h"
#include "util/platform.h"

#include <sys/mman.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

using namespace platform;

PagemapManager* PagemapManager::instance_ = nullptr;

#define GET_BIT(X, Y) (((X) & ((uint64_t)1 << (Y))) >> (Y))
#define PAGEMAP_SOFT_DIRTY_PTE_BIT 55
#define PAGEMAP_ENTRY_SIZE sizeof(uint64_t)

PagemapManager::PagemapManager(bool enable_copy_on_map) :
    system_page_size_(GetSystemPageSize()), system_page_pot_shift_(platform::GetSystemPagePotShift()),
    enable_copy_on_map_(enable_copy_on_map)
{}

bool PagemapManager::OpenPagemapFile()
{
    assert(pagemap_fd_ == nullptr);

    GFXRECON_WRITE_CONSOLE("Opening %s\n", pagemap_filename_);

    if (FileOpen(&pagemap_fd_, pagemap_filename_, "r"))
    {
        GFXRECON_LOG_ERROR("Failed opening %s (perror: %d)\n", pagemap_filename_, perror);
        return false;
    }

    return true;
}

void PagemapManager::ClosePagemapFile()
{
    if (pagemap_fd_)
    {
        FileClose(pagemap_fd_);
        pagemap_fd_ = nullptr;
    }
}

void PagemapManager::Create(bool enable_copy_on_map)
{
    if (instance_ == nullptr)
    {
        instance_ = new PagemapManager(enable_copy_on_map);

        memset(instance_->pagemap_filename_, 0, sizeof(instance_->pagemap_filename_));
        snprintf(instance_->pagemap_filename_, sizeof(instance_->pagemap_filename_), "/proc/%d/pagemap", getpid());

        instance_->OpenPagemapFile();
    }
    else
    {
        GFXRECON_LOG_WARNING("PagemapManager creation was attempted more than once");
    }
}

void PagemapManager::Destroy()
{
    if (instance_ != nullptr)
    {
        instance_->ClosePagemapFile();

        delete instance_;
        instance_ = nullptr;
    }
}

void PagemapManager::ClearSoftDirtyBits()
{
    char clear_refs_filename[64] = {};
    snprintf(clear_refs_filename, sizeof(clear_refs_filename), "/proc/%d/clear_refs", getpid());

    GFXRECON_WRITE_CONSOLE("Opening %s\n", clear_refs_filename);
    FILE* clear_refs_fd;
    if (FileOpen(&clear_refs_fd, clear_refs_filename, "w"))
    {
        GFXRECON_LOG_ERROR("Failed opening %s (perror: %d)\n", clear_refs_filename, perror);
        return;
    }

    constexpr int clear_soft_dirty_bits_value = 4;
    // if (!FileWrite(&clear_soft_dirty_bits_value, sizeof(clear_soft_dirty_bits_value), 1, clear_refs_fd))
    if (!fprintf(clear_refs_fd, "4"))
    {
        GFXRECON_LOG_ERROR("Error writing to %s file (perror: %d)\n", clear_refs_filename, perror);
    }

    FileClose(clear_refs_fd);
}

void PagemapManager::UpdatePageTableEntry(MemoryInfo* memory_info)
{
    const size_t file_offset =
        reinterpret_cast<uintptr_t>(memory_info->shadow_memory) / system_page_size_ * PAGEMAP_ENTRY_SIZE;

    // GFXRECON_WRITE_CONSOLE("base: %p reading %s at 0x%x\n", memory_info->shadow_memory, pagemap_filename_, file_offset);

    if (!FileSeek(pagemap_fd_, file_offset, FileSeekSet))
    {
        GFXRECON_LOG_ERROR("Failed to fseek in file %s (perror: %d)\n", pagemap_filename_, perror);
        return;
    }

    for (int page = 0; page < memory_info->n_pages; ++page)
    {
        // Read up page entry from file
        uint64_t pagemap_entry;
        uint8_t  c_buf[PAGEMAP_ENTRY_SIZE];
        for (int i = 0; i < PAGEMAP_ENTRY_SIZE; i++)
        {
            uint8_t c;
            if (!FileRead(&c, sizeof(c), 1, pagemap_fd_))
            {
                GFXRECON_LOG_ERROR("Error reading %s (feof: %d ferror: %d)",
                                   pagemap_filename_,
                                   feof(pagemap_fd_),
                                   ferror(pagemap_fd_));
                return;
            }

            if (IsBigEndian())
            {
                c_buf[i] = c;
            }
            else
            {
                c_buf[PAGEMAP_ENTRY_SIZE - i - 1] = c;
            }
        }

        for (int i = 0; i < PAGEMAP_ENTRY_SIZE; i++)
        {
            pagemap_entry = (pagemap_entry << 8) + c_buf[i];
        }

        // Read dirty bit
        if (GET_BIT(pagemap_entry, PAGEMAP_SOFT_DIRTY_PTE_BIT))
        {
            memory_info->dirty = true;
            break;
        }
    }
}

void PagemapManager::UpdatePageTableEntries()
{
    assert(pagemap_fd_);

    for (auto entry = memory_info_.begin(); entry != memory_info_.end(); ++entry)
    {
        auto memory_info = &entry->second;
        if (memory_info->dirty)
            continue;

        UpdatePageTableEntry(memory_info);
    }
}

static size_t GetPageAlignedSize(size_t size, size_t page_size)
{
    size_t extra = size & (page_size - 1); // size % system_page_size_
    if (extra != 0)
    {
        // Adjust the size to be a multiple of the system page size.
        size = size - extra + page_size;
    }

    return size;
}

static void* AllocateMemory(size_t aligned_size)
{
    assert(aligned_size > 0);

    if (aligned_size > 0)
    {
        void* memory = mmap(nullptr, aligned_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

        if (memory == MAP_FAILED)
        {
            GFXRECON_LOG_ERROR(
                "Failed to allocate memory with \"mmap()\" and size = %" PRIuPTR " (errno: %d)", aligned_size, errno);
            return nullptr;
        }

        return memory;
    }
    else
    {
        GFXRECON_LOG_ERROR("PageGuardManager::AllocateMemory(): aligned_size must be greater than 0.");
        return nullptr;
    }
}

void* PagemapManager::AddTrackedMemory(uint64_t memory_id,
                                       void*    mapped_memory,
                                       size_t   mapped_offset,
                                       size_t   mapped_range)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    assert(memory_info_.find(memory_id) == memory_info_.end());

    memset(mapped_memory, 0, mapped_range);

    // Read pagemap entries before clearing dirty bits and also before allocating new memory
    // (freshly mapped pages have their dirty bits set)
    UpdatePageTableEntries();

    const size_t shadow_size   = GetPageAlignedSize(mapped_range, system_page_size_);
    void*        shadow_memory = AllocateMemory(shadow_size);

    if (shadow_memory != nullptr)
    {
        if (enable_copy_on_map_)
        {
            platform::MemoryCopy(shadow_memory, mapped_range, mapped_memory, mapped_range);
        }

        size_t total_pages       = mapped_range >> system_page_pot_shift_;
        size_t last_segment_size = mapped_range & (system_page_size_ - 1);

        if (last_segment_size != 0)
        {
            ++total_pages;
        }

        auto entry = memory_info_.emplace(
            std::piecewise_construct,
            std::forward_as_tuple(memory_id),
            std::forward_as_tuple(
                mapped_memory, shadow_memory, mapped_range, total_pages, last_segment_size, enable_copy_on_map_));

        assert(entry.second);

        ClearSoftDirtyBits();
    }

    return shadow_memory;
}

void PagemapManager::RemoveTrackedMemory(uint64_t memory_id)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    auto entry = memory_info_.find(memory_id);
    if (entry != memory_info_.end())
    {
        memory_info_.erase(entry);
    }
}

void PagemapManager::ProcessMemoryEntry(uint64_t memory_id, const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    auto entry = memory_info_.find(memory_id);
    if (entry != memory_info_.end())
    {
        auto memory_info = &entry->second;
        ProcessEntry(entry->first, memory_info, handle_modified);
    }
}

void PagemapManager::ProcessMemoryEntries(const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    for (auto entry = memory_info_.begin(); entry != memory_info_.end(); ++entry)
    {
        auto memory_info = &entry->second;
        ProcessEntry(entry->first, memory_info, handle_modified);
    }

    ClearSoftDirtyBits();
}

void PagemapManager::ProcessEntry(uint64_t                  memory_id,
                                  MemoryInfo*               memory_info,
                                  const ModifiedMemoryFunc& handle_modified)
{
    UpdatePageTableEntry(memory_info);

    // GFXRECON_WRITE_CONSOLE("%s() shadow: %p dirty: %u\n", __func__, memory_info->shadow_memory, memory_info->dirty);

    if (memory_info->dirty)
    {
        handle_modified(memory_id, memory_info->shadow_memory, 0, memory_info->mapped_range);
        MemoryCopy(memory_info->mapped_memory, memory_info->mapped_range, memory_info->shadow_memory, memory_info->mapped_range);
        memory_info->dirty = false;
    }
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
