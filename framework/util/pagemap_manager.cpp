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

#include <fcntl.h>
#include <sstream>
#include <type_traits>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_NAME "GFXRECON_SOCKET"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

using namespace platform;

PagemapManager* PagemapManager::instance_ = nullptr;

PagemapManager::PagemapManager(bool enable_copy_on_map) :
    system_page_size_(GetSystemPageSize()), system_page_pot_shift_(platform::GetSystemPagePotShift()),
    enable_copy_on_map_(enable_copy_on_map)
{}

bool PagemapManager::ConnectToDaemon(void)
{
    socket_ = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socket_ < 0)
    {
        GFXRECON_WRITE_CONSOLE("Error: %s() error creating socket: %s\n", __func__, strerror(errno));
        return false;
    }

    char socket_name[108];
    memcpy(&socket_name[0], "\0", 1);
    strcpy(&socket_name[1], SOCKET_NAME);

    struct sockaddr_un server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, socket_name, sizeof(server_addr.sun_path) - 1);

    // Assuming only one init connection for demo
    int ret = connect(socket_, (const struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret < 0)
    {
        GFXRECON_WRITE_CONSOLE("Error: %s() error connect: %s\n", __func__, strerror(errno));
    }
    else
    {
        GFXRECON_WRITE_CONSOLE("Connection established");
    }

    return true;
}

void PagemapManager::Create(bool enable_copy_on_map)
{
    if (instance_ == nullptr)
    {
        instance_       = new PagemapManager(enable_copy_on_map);
        instance_->pid_ = getpid();

        if (!instance_->ConnectToDaemon())
        {
            GFXRECON_WRITE_CONSOLE("Pagemap manager initialization failed");
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Error: PagemapManager creation was attempted more than once");
    }
}

struct client_id_t
{
    pid_t  pid;
    void*  virtual_address;
    size_t nof_pages;
};

void PagemapManager::Destroy()
{
    if (instance_ != nullptr)
    {
        GFXRECON_WRITE_CONSOLE("Closing connection");

        client_id_t term_op = { -1, 0, 0 };
        if (write(instance_->socket_, &term_op, sizeof(term_op)) == -1)
        {
            GFXRECON_WRITE_CONSOLE("Error: write error %s", __func__, strerror(errno));
            assert(0);
        }

        delete instance_;
        instance_ = nullptr;
    }
}

void PagemapManager::GetFileModificationTime(int fd, timespec* m_time)
{
    struct stat file_stat;
    static_assert(std::is_same<timespec, decltype(file_stat.st_mtim)>::value, "timespec is not the right type");

    if (fstat(fd, &file_stat) == -1)
    {
        GFXRECON_LOG_ERROR("error: fstat: %s", strerror(errno));
        return;
    }

    MemoryCopy(m_time, sizeof(*m_time), &file_stat.st_mtim, sizeof(*m_time));
}

bool operator<(const timespec& lhs, const timespec& rhs)
{
    if (lhs.tv_sec == rhs.tv_sec)
        return lhs.tv_nsec < rhs.tv_nsec;
    else
        return lhs.tv_sec < rhs.tv_sec;
}

bool operator<=(const timespec& lhs, const timespec& rhs)
{
    if (lhs.tv_sec == rhs.tv_sec)
        return lhs.tv_nsec <= rhs.tv_nsec;
    else
        return lhs.tv_sec <= rhs.tv_sec;
}

bool operator>(const timespec& lhs, const timespec& rhs)
{
    if (lhs.tv_sec == rhs.tv_sec)
        return lhs.tv_nsec > rhs.tv_nsec;
    else
        return lhs.tv_sec > rhs.tv_sec;
}

bool operator>=(const timespec& lhs, const timespec& rhs)
{
    if (lhs.tv_sec == rhs.tv_sec)
        return lhs.tv_nsec >= rhs.tv_nsec;
    else
        return lhs.tv_sec >= rhs.tv_sec;
}

bool operator==(const timespec& lhs, const timespec& rhs)
{
    return lhs.tv_nsec == rhs.tv_nsec && lhs.tv_sec >= rhs.tv_sec;
}

void PagemapManager::UpdatePageTableEntry(MemoryInfo* memory_info)
{
    assert(pid_ != -1 && pid_);
    assert(memory_info->shadow_memory != 0);
    assert(memory_info->n_pages != 0);

    struct client_id_t client_id = { pid_, memory_info->shadow_memory, memory_info->n_pages };
    int                n         = write(socket_, &client_id, sizeof(client_id));
    if (n != sizeof(client_id))
    {
        GFXRECON_WRITE_CONSOLE("Error: sizeof(client_id): %zu n: %d error: %s)", sizeof(client_id), n, strerror(errno));
        assert(0);
    }

    if (read(socket_, &memory_info->dirty, sizeof(memory_info->dirty)) == -1)
    {
        GFXRECON_WRITE_CONSOLE("Error: Read error %s\n", strerror(errno));
        assert(0);
    }
    assert(memory_info->dirty == 0 || memory_info->dirty == 1);

    if (memory_info->dirty)
    {
        assert(memory_info->page_status.size() == memory_info->n_pages);

        memset(memory_info->page_status.data(), 222, memory_info->page_status.size() * sizeof(uint8_t));
        if (read(socket_, memory_info->page_status.data(), memory_info->page_status.size() * sizeof(uint8_t)) == -1)
        {
            GFXRECON_WRITE_CONSOLE("Error: Read error %s\n", strerror(errno));
            assert(0);
        }

        // for (size_t i = 0; i < memory_info->n_pages; ++i)
        // {
        //     GFXRECON_WRITE_CONSOLE("  page %zu: %u", i, memory_info->page_status[i]);
        // }

        timespec m_time;
        GetFileModificationTime(memory_info->shadow_file_fd, &m_time);
        assert(memory_info->shadow_file_mtime <= m_time);
        MemoryCopy(&memory_info->shadow_file_mtime, sizeof(memory_info->shadow_file_mtime), &m_time, sizeof(m_time));
    }
    else
    {
        timespec m_time;
        GetFileModificationTime(memory_info->shadow_file_fd, &m_time);
        assert(memory_info->shadow_file_mtime == m_time);
        if (m_time > memory_info->shadow_file_mtime)
        {
            GFXRECON_LOG_WARNING("Warning: Loss of data detected");
            GFXRECON_WRITE_CONSOLE("Warning: Loss of data detected");
        }
    }
}

size_t PagemapManager::GetAlignedSize(size_t size) const
{
    size_t extra = size & (system_page_size_ - 1); // size % system_page_size_
    if (extra != 0)
    {
        // Adjust the size to be a multiple of the system page size.
        size = size - extra + system_page_size_;
    }

    assert(!(size % system_page_size_));
    return size;
}

static void* AllocateMemory(size_t aligned_size, int fd)
{
    assert(aligned_size > 0);

    if (aligned_size > 0)
    {
        const int flags  = fd == -1 ? MAP_PRIVATE | MAP_ANONYMOUS : MAP_SHARED;
        void*     memory = mmap(nullptr, aligned_size, PROT_READ | PROT_WRITE, flags, fd, 0);

        if (memory == MAP_FAILED)
        {
            GFXRECON_WRITE_CONSOLE("Error: Failed to allocate memory with \"mmap()\" and size = %" PRIuPTR " (%s)",
                                   aligned_size,
                                   strerror(errno));
            return nullptr;
        }

        return memory;
    }
    else
    {
        GFXRECON_WRITE_CONSOLE("PageGuardManager::AllocateMemory(): aligned_size must be greater than 0.");
        return nullptr;
    }
}

int PagemapManager::CreateShadowFile(void* mapped_memory, size_t size) const
{
    std::ostringstream filename;
    filename << "/storage/emulated/0/Download/shadow_file_" << mapped_memory << ".bin";

    // GFXRECON_WRITE_CONSOLE("%s() creating shadow file %s", __func__, filename.str().c_str());

    // int fd;
    // if (!access(filename.str().c_str(), F_OK))
    // {
    //     // GFXRECON_WRITE_CONSOLE("file exists");
    //     if (!access(filename.str().c_str(), O_RDWR))
    //     {
    //         // GFXRECON_WRITE_CONSOLE("  can be read/write");
    //         fd = open(filename.str().c_str(), O_RDWR);
    //     }
    //     else
    //     {
    //         GFXRECON_WRITE_CONSOLE("  Missing permissions opening file(?)");
    //     }
    // }
    // else
    // {
    //     // GFXRECON_WRITE_CONSOLE("file does not exist");
    //     fd = open(filename.str().c_str(), O_RDWR | O_CREAT, 0666);
    // }

    int fd = open(filename.str().c_str(), O_RDWR | O_CREAT, 0666);
    if (fd == -1)
    {
        GFXRECON_WRITE_CONSOLE("Error: open failed with error: %s", strerror(errno));
        if (errno == EEXIST)
        {
            fd = open(filename.str().c_str(), O_RDWR);
        }
    }

    if (fd == -1)
    {
        GFXRECON_WRITE_CONSOLE("Error: open failed creating %s (%s)", filename.str().c_str(), strerror(errno));
        assert(0);
        return -1;
    }

    if (ftruncate(fd, size) == -1)
    {
        GFXRECON_WRITE_CONSOLE("Error: ftruncate failed %s", strerror(errno));
        close(fd);
        assert(0);
        return -1;
    }

    return fd;
}

void* PagemapManager::AddTrackedMemory(uint64_t memory_id,
                                       void*    mapped_memory,
                                       size_t   mapped_offset,
                                       size_t   mapped_range)
{
    const size_t shadow_size = GetAlignedSize(mapped_range);
    // const size_t shadow_size = mapped_range;

    // GFXRECON_WRITE_CONSOLE("%s() ", __func__);
    // GFXRECON_WRITE_CONSOLE(
    //     "  mapped_range: %zu GetAlignedSize(mapped_range): %zu", mapped_range, GetAlignedSize(mapped_range));

    const int fd = CreateShadowFile(mapped_memory, shadow_size);
    if (fd < 0)
    {
        assert(0);
        return mapped_memory;
    }

    void* shadow_memory = AllocateMemory(shadow_size, fd);
    assert(shadow_memory);

    if (shadow_memory != nullptr)
    {

        if (enable_copy_on_map_)
        {
            platform::MemoryCopy(shadow_memory, mapped_range, mapped_memory, mapped_range);
        }

        if (msync(shadow_memory, shadow_size, MS_SYNC) == -1)
        {
            GFXRECON_WRITE_CONSOLE("Error: msync failed: %s", strerror(errno));
            close(fd);
            assert(0);
            return mapped_memory;
        }

        size_t total_pages       = mapped_range >> system_page_pot_shift_;
        size_t last_segment_size = mapped_range & (system_page_size_ - 1);

        if (last_segment_size != 0)
        {
            ++total_pages;
        }

        // GFXRECON_WRITE_CONSOLE("  shadow_memory: %p total_pages: %zu last_segment_size: %zu",
        //                        shadow_memory,
        //                        total_pages,
        //                        last_segment_size);

        std::lock_guard<std::mutex> lock(tracked_memory_lock_);
        assert(memory_info_.find(memory_id) == memory_info_.end());

        auto entry = memory_info_.emplace(
            std::piecewise_construct,
            std::forward_as_tuple(memory_id),
            std::forward_as_tuple(
                mapped_memory, shadow_memory, mapped_range, shadow_size, total_pages, last_segment_size, false));

        assert(entry.second);

        auto& memory_info          = entry.first->second;
        memory_info.shadow_file_fd = fd;

        GetFileModificationTime(fd, &memory_info.shadow_file_mtime);
    }

    // GFXRECON_WRITE_CONSOLE("%s()", __func__);
    // GFXRECON_WRITE_CONSOLE("  mapped_memory: %p", mapped_memory);
    // GFXRECON_WRITE_CONSOLE("  mapped_offset: %zu", mapped_offset);
    // GFXRECON_WRITE_CONSOLE("  mapped_range: %zu", mapped_range);
    // GFXRECON_WRITE_CONSOLE("  shadow_memory: %p", shadow_memory);
    // GFXRECON_WRITE_CONSOLE("  shadow_size: %zu", shadow_size);

    return shadow_memory;
}

void PagemapManager::RemoveTrackedMemory(uint64_t memory_id)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    auto entry = memory_info_.find(memory_id);
    if (entry != memory_info_.end())
    {
        auto memory_info = entry->second;
        munmap(memory_info.shadow_memory, memory_info.shadow_size);
        if (memory_info.shadow_file_fd != -1)
        {
            close(memory_info.shadow_file_fd);
        }

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
}

void PagemapManager::ProcessEntry(uint64_t                  memory_id,
                                  MemoryInfo*               memory_info,
                                  const ModifiedMemoryFunc& handle_modified)
{
    assert(memory_info != nullptr);

    // GFXRECON_WRITE_CONSOLE("%s() memory_info->shadow_memory: %p", __func__, memory_info->shadow_memory);

    UpdatePageTableEntry(memory_info);

    if (memory_info->dirty)
    {
        bool   active_range = false;
        size_t start_index  = 0;

        for (size_t i = 0; i < memory_info->n_pages; ++i)
        {
            if (memory_info->page_status[i])
            {
                memory_info->page_status[i] = 0;

                if (!active_range)
                {
                    active_range = true;
                    start_index  = i;
                }
            }
            else
            {
                if (active_range)
                {
                    ProcessActiveRange(memory_id, memory_info, start_index, i, handle_modified);
                    active_range = false;
                }
            }
        }

        if (active_range)
        {
            ProcessActiveRange(memory_id, memory_info, start_index, memory_info->n_pages, handle_modified);
        }

        msync(memory_info->shadow_memory, memory_info->shadow_size, MS_SYNC);
        memory_info->dirty = false;
    }

    // ProcessActiveRange(memory_id, memory_info, 0, memory_info->n_pages, handle_modified);
}

void PagemapManager::ProcessActiveRange(uint64_t                  memory_id,
                                        MemoryInfo*               memory_info,
                                        size_t                    start_index,
                                        size_t                    end_index,
                                        const ModifiedMemoryFunc& handle_modified)
{
    assert((memory_info != nullptr));
    // assert(end_index > start_index);
    assert(memory_info->shadow_memory);

    // GFXRECON_WRITE_CONSOLE("%s memory_info->shadow_memory: %p start_index: %zu end_index: %zu",
    //                        __func__,
    //                        memory_info->shadow_memory,
    //                        start_index,
    //                        end_index);

    size_t page_count  = end_index - start_index;
    size_t page_offset = start_index << system_page_pot_shift_;
    size_t page_range  = page_count << system_page_pot_shift_;

    if (end_index == memory_info->n_pages && memory_info->last_segment_size)
    {
        // Adjust range for memory ranges that end with a partial page.
        page_range -= system_page_size_ - memory_info->last_segment_size;
    }

    // Copy from shadow memory to the original mapped memory.
    if (start_index == 0)
    {
        assert(!memory_info->aligned_offset);
        page_range -= memory_info->aligned_offset;
    }
    else
    {
        assert(!memory_info->aligned_offset);
        page_offset -= memory_info->aligned_offset;
    }

    // GFXRECON_WRITE_CONSOLE("  page_count: %zu", page_count);
    // GFXRECON_WRITE_CONSOLE("  page_offset: %zu", page_offset);
    // GFXRECON_WRITE_CONSOLE("  page_range: %zu", page_range);
    // GFXRECON_WRITE_CONSOLE("  memory_info->mapped_range: %zu", memory_info->mapped_range);


    void* source_address      = static_cast<uint8_t*>(memory_info->shadow_memory) + page_offset;
    void* destination_address = static_cast<uint8_t*>(memory_info->mapped_memory) + page_offset;
    // GFXRECON_WRITE_CONSOLE("  source_address: %p destination_address: %p", source_address, destination_address);
    MemoryCopy(destination_address, page_range, source_address, page_range);

    // The shadow memory address, page offset, and range values to be provided to the callback, which will process
    // the memory range.
    handle_modified(memory_id, memory_info->shadow_memory, page_offset, page_range);

    // MemoryCopy(
    //     memory_info->mapped_memory, memory_info->mapped_range, memory_info->shadow_memory,
    //     memory_info->mapped_range);
}

void PagemapManager::UpdateEntry(uint64_t memory_id, size_t offset, size_t size)
{
    GFXRECON_WRITE_CONSOLE("%s()", __func__);

    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    auto entry = memory_info_.find(memory_id);
    if (entry != memory_info_.end())
    {
        auto  memory_info = &entry->second;
        void* destination = static_cast<void*>(static_cast<uint8_t*>(memory_info->shadow_memory) + offset);
        void* source      = static_cast<void*>(static_cast<uint8_t*>(memory_info->mapped_memory) + offset);
        MemoryCopy(destination, size, source, size);
    }
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
