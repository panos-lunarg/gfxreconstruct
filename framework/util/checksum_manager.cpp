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

#include "util/checksum_manager.h"

#include "util/logging.h"
#include "util/platform.h"

#include "util/xxhash.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

ChecksumManager* ChecksumManager::instance_ = nullptr;

void ChecksumManager::Create()
{
    if (instance_ == nullptr)
    {
        instance_ = new ChecksumManager();
    }
    else
    {
        GFXRECON_LOG_WARNING("ChecksumManager creation was attempted more than once");
    }
}

void ChecksumManager::Destroy()
{
    if (instance_ != nullptr)
    {
        delete instance_;
        instance_ = nullptr;
    }
}

void* ChecksumManager::AddTrackedMemory(uint64_t memory_id,
                                        void*    mapped_memory,
                                        size_t   mapped_offset,
                                        size_t   mapped_range)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    assert(memory_info_.find(memory_id) == memory_info_.end());

    hash_t checksum = XXH64(static_cast<uint8_t*>(mapped_memory), mapped_range, hash_seed_);
    auto   entry    = memory_info_.emplace(std::piecewise_construct,
                                      std::forward_as_tuple(memory_id),
                                      std::forward_as_tuple(mapped_memory, mapped_range, checksum));
    assert(entry.second);

    return mapped_memory;
}

void ChecksumManager::RemoveTrackedMemory(uint64_t memory_id)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    auto entry = memory_info_.find(memory_id);
    if (entry != memory_info_.end())
    {
        memory_info_.erase(entry);
    }
}

void ChecksumManager::ProcessMemoryEntry(uint64_t memory_id, const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    auto entry = memory_info_.find(memory_id);
    if (entry != memory_info_.end())
    {
        auto memory_info = &entry->second;
        ProcessEntry(entry->first, memory_info, handle_modified);
    }
}

void ChecksumManager::ProcessMemoryEntries(const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    for (auto entry = memory_info_.begin(); entry != memory_info_.end(); ++entry)
    {
        auto memory_info = &entry->second;
        ProcessEntry(entry->first, memory_info, handle_modified);
    }
}

void ChecksumManager::ProcessEntry(uint64_t                  memory_id,
                                   MemoryInfo*               memory_info,
                                   const ModifiedMemoryFunc& handle_modified)
{
    hash_t new_checksum =
        XXH64(static_cast<uint8_t*>(memory_info->mapped_memory), memory_info->mapped_range, hash_seed_);

    if (memory_info->checksum != new_checksum)
    {
        handle_modified(memory_id, memory_info->mapped_memory, 0, memory_info->mapped_range);
        memory_info->checksum = new_checksum;
    }
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
