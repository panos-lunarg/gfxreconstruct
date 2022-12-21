/*
** Copyright (c) 2019-2022 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_INDIRECT_COMMANDS_INFO_H
#define GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_INDIRECT_COMMANDS_INFO_H

#include "decode/vulkan_frame_inspector_vulkan_commands_info.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_frame_inspector_object_info.h"
#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/vulkan_util.h"
#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
class VulkanIndirectCommandInfo : public VulkanCommandInfo
{
  public:
    VulkanIndirectCommandInfo(format::CommandIndexType     index,
                              vulkan_command_type          type,
                              const DeviceInfo*            device_info,
                              const encode::DeviceTable*   device_table,
                              const encode::InstanceTable* instance_table) :
        VulkanCommandInfo(index, type),
        device_info_(device_info), device_table_(device_table), instance_table_(instance_table),
        params_size_(sizeof(T)), command_params_({}), indirect_buffer_copy_(VK_NULL_HANDLE),
        indirect_buffer_copy_memory_(VK_NULL_HANDLE), data_(nullptr)
    {}

    ~VulkanIndirectCommandInfo()
    {
        if (indirect_buffer_copy_ != VK_NULL_HANDLE)
        {
            device_table_->DestroyBuffer(device_info_->handle, indirect_buffer_copy_, nullptr);
            indirect_buffer_copy_ = VK_NULL_HANDLE;
        }

        if (indirect_buffer_copy_memory_ != VK_NULL_HANDLE)
        {
            device_table_->FreeMemory(device_info_->handle, indirect_buffer_copy_memory_, nullptr);
            indirect_buffer_copy_memory_ = VK_NULL_HANDLE;

            if (data_)
            {
                device_table_->UnmapMemory(device_info_->handle, indirect_buffer_copy_memory_);
                data_ = nullptr;
            }
        }
    }

    void Initialize(const CommandBufferInfo*  command_buffer_info,
                    const PhysicalDeviceInfo* phys_dev_info,
                    VkBuffer                  buffer,
                    VkDeviceSize              offset,
                    uint32_t                  drawCount,
                    uint32_t                  stride)
    {
        offset_    = offset;
        drawCount_ = drawCount;
        stride_    = stride;

        if (drawCount)
        {
            assert(command_buffer_info->state == kRecording);

            // Create auxiliary buffer and device memory
            {
                const VkBufferCreateInfo buffer_create_info = { .sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
                                                                .pNext = NULL,
                                                                .flags = 0,
                                                                .size  = drawCount * params_size_,
                                                                .usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                                                                         VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                                                .sharingMode           = VK_SHARING_MODE_EXCLUSIVE,
                                                                .queueFamilyIndexCount = 0,
                                                                .pQueueFamilyIndices   = NULL };

                VkResult err = device_table_->CreateBuffer(
                    device_info_->handle, &buffer_create_info, nullptr, &indirect_buffer_copy_);
                assert(!err);

                VkMemoryRequirements mem_reqs;
                device_table_->GetBufferMemoryRequirements(device_info_->handle, indirect_buffer_copy_, &mem_reqs);

                VkMemoryAllocateInfo mem_alloc_info;
                mem_alloc_info.sType           = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
                mem_alloc_info.pNext           = NULL;
                mem_alloc_info.allocationSize  = mem_reqs.size;
                mem_alloc_info.memoryTypeIndex = 0;

                VkPhysicalDeviceMemoryProperties phys_dev_mem_props;
                instance_table_->GetPhysicalDeviceMemoryProperties(phys_dev_info->handle, &phys_dev_mem_props);

                const VkFlags requirements = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
                bool          pass         = graphics::memory_type_from_properties(
                    phys_dev_mem_props, mem_reqs.memoryTypeBits, requirements, &mem_alloc_info.memoryTypeIndex);
                assert(pass);

                err = device_table_->AllocateMemory(
                    device_info_->handle, &mem_alloc_info, NULL, &(indirect_buffer_copy_memory_));
                assert(!err);

                err = device_table_->BindBufferMemory(
                    device_info_->handle, indirect_buffer_copy_, indirect_buffer_copy_memory_, 0);
                assert(!err);

                err = device_table_->MapMemory(
                    device_info_->handle, indirect_buffer_copy_memory_, 0, drawCount * params_size_, 0, &data_);
                assert(data_);
            }

            // Inject copy commands
            VkBufferCopy* copy_regions = new VkBufferCopy[drawCount];
            if (!copy_regions)
            {
                assert(0);
                return;
            }

            uint32_t copy_count;
            if (stride != params_size_ && drawCount > 1)
            {
                copy_count = drawCount;

                for (uint32_t i = 0; i < drawCount; ++i)
                {
                    copy_regions[i].srcOffset = offset + i * stride;
                    copy_regions[i].dstOffset = i * params_size_;
                    copy_regions[i].size      = params_size_;
                }
            }
            else
            {
                copy_count = 1;

                copy_regions[0].srcOffset = offset;
                copy_regions[0].dstOffset = 0;
                copy_regions[0].size      = drawCount * params_size_;
            }

            device_table_->CmdCopyBuffer(
                command_buffer_info->handle, buffer, indirect_buffer_copy_, copy_count, copy_regions);

            delete[] copy_regions;
        }
    }

    virtual void FetchParameters() override
    {
        assert(data_);

        util::platform::MemoryCopy(&command_params_, params_size_, data_, params_size_);
    }

    const T& GetParams() { return command_params_; }

  protected:
    const DeviceInfo*            device_info_;
    const encode::DeviceTable*   device_table_;
    const encode::InstanceTable* instance_table_;
    const size_t                 params_size_;

    T command_params_;

    VkBuffer       indirect_buffer_copy_;
    VkDeviceMemory indirect_buffer_copy_memory_;
    void*          data_;

    VkDeviceSize offset_;
    uint32_t     drawCount_;
    uint32_t     stride_;
};

struct draw_indirect_params_t
{
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t firstVertex;
    uint32_t firstInstance;
};

class VulkanCommandDrawIndirectInfo : public VulkanIndirectCommandInfo<draw_indirect_params_t>
{
  public:
    VulkanCommandDrawIndirectInfo(format::CommandIndexType     index,
                                  vulkan_command_type          type,
                                  const DeviceInfo*            device_info,
                                  const encode::DeviceTable*   device_table,
                                  const encode::InstanceTable* instance_table) :
        VulkanIndirectCommandInfo(index, type, device_info, device_table, instance_table)
    {}
};

// class VulkanCommandDrawIndexedIndirectInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawIndexedIndirectInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandDispatchIndirectInfo : public VulkanCommandInfo
// {
//     VulkanCommandDispatchIndirectInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandDrawIndirectCountInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawIndirectCountInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandDrawIndexedIndirectCountInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawIndexedIndirectCountInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandDrawIndirectCountKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawIndirectCountKHRInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandDrawIndexedIndirectCountKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawIndexedIndirectCountKHRInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandTraceRaysIndirect2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandTraceRaysIndirect2KHRInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandDrawIndirectByteCountEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawIndirectByteCountEXTInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandDrawIndirectCountAMDInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawIndirectCountAMDInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandDrawIndexedIndirectCountAMDInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawIndexedIndirectCountAMDInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandDrawMeshTasksIndirectNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawMeshTasksIndirectNVInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandDrawMeshTasksIndirectCountNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawMeshTasksIndirectCountNVInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandBuildAccelerationStructuresIndirectKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandBuildAccelerationStructuresIndirectKHRInfo(format::CommandIndexType index, vulkan_command_type type)
//     :
//         VulkanCommandInfo(index, type)
//     {}
// };
// class VulkanCommandTraceRaysIndirectKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandTraceRaysIndirectKHRInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandDrawMeshTasksEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawMeshTasksEXTInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandDrawMeshTasksIndirectEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawMeshTasksIndirectEXTInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// class VulkanCommandDrawMeshTasksIndirectCountEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawMeshTasksIndirectCountEXTInfo(format::CommandIndexType index, vulkan_command_type type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_INDIRECT_COMMANDS_INFO_H */
