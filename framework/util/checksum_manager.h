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

#ifndef GFXRECON_UTIL_CHECKSUM_MANAGER_H
#define GFXRECON_UTIL_CHECKSUM_MANAGER_H

#include "util/defines.h"
#include "format/format_util.h"

#include <unordered_map>
#include <functional>
#include <mutex>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class ChecksumManager
{
  public:
    static void             Create();
    static void             Destroy();
    static ChecksumManager* Get() { return instance_; }

    void* AddTrackedMemory(uint64_t memory_id, void* mapped_memory, size_t mapped_offset, size_t mapped_range);
    void  RemoveTrackedMemory(uint64_t memory_id);

    // Callback for processing modified memory.  The function parameters are the ID of the modified memory object,
    // a pointer to the start of the modified memory range, the offset from the initial mapped memory pointer to
    // the modified range pointer, and the size of the modified range.
    // typedef std::function<void(format::HandleId, uint64_t, uint64_t, const void*)> ModifiedMemoryFunc;
    typedef std::function<void(uint64_t, void*, size_t, size_t)> ModifiedMemoryFunc;

    void ProcessMemoryEntry(uint64_t memory_id, const ModifiedMemoryFunc& handle_modified);
    void ProcessMemoryEntries(const ModifiedMemoryFunc& handle_modified);

  private:
    static ChecksumManager* instance_;

    using hash_t                       = uint64_t;
    static constexpr hash_t hash_seed_ = 0;

    struct MemoryInfo
    {
        MemoryInfo(void* mm, size_t mr, uint32_t cs) : mapped_memory(mm), mapped_range(mr) {}
        void*  mapped_memory;
        size_t mapped_range;
        hash_t checksum;
    };

    void ProcessEntry(uint64_t memory_id, MemoryInfo* memory_info, const ModifiedMemoryFunc& handle_modified);

    typedef std::unordered_map<uint64_t, MemoryInfo> MemoryInfoMap;

    MemoryInfoMap memory_info_;
    std::mutex    tracked_memory_lock_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_CHECKSUM_MANAGER_H
