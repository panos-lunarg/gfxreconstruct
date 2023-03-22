/*
** Copyright (c) 2019-2023 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_INDIRECT_COMMANDS_INFO_H
#define GFXRECON_DECODE_VULKAN_INDIRECT_COMMANDS_INFO_H

#include "decode/vulkan_commands_info_common.h"
#include "decode/vulkan_object_info.h"
#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/vulkan_util.h"
#include "util/logging.h"
#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanIndirectCommandInfo;

struct CommandBufferInfo : public VulkanPoolObjectInfo<VkCommandBuffer>
{
    std::unordered_map<format::CommandIndexType, std::unique_ptr<VulkanIndirectCommandInfo>> indirect_commands_info;
};

class VulkanIndirectCommandInfo
{
  public:
    VulkanIndirectCommandInfo(format::CommandIndexType     index,
                              vulkan_command_type          type,
                              const DeviceInfo*            device_info,
                              const encode::DeviceTable*   device_table,
                              const encode::InstanceTable* instance_table,
                              BufferInfo*                  buffer,
                              BufferInfo*                  count_buffer) :
        index_(index),
        type_(type),
        is_count_variant_(VULKAN_CMD_DRAW_INDIRECT_COUNT == type_ || VULKAN_CMD_DRAW_INDEXED_INDIRECT_COUNT == type_),
        count_buffer_size_(sizeof(uint32_t)), device_info_(device_info), device_table_(device_table),
        instance_table_(instance_table), buffer_(buffer), count_buffer_(count_buffer),
        params_size_(sizeof(indirect_draw_parameters_union)), command_params_({}),
        indirect_buffer_copy_(VK_NULL_HANDLE), count_buffer_copy_(VK_NULL_HANDLE),
        indirect_buffer_copy_memory_(VK_NULL_HANDLE), count_buffer_copy_memory_(VK_NULL_HANDLE), data_(nullptr),
        count_data_(nullptr)
    {}

    virtual ~VulkanIndirectCommandInfo()
    {
        if (indirect_buffer_copy_ != VK_NULL_HANDLE)
        {
            device_table_->DestroyBuffer(device_info_->handle, indirect_buffer_copy_, nullptr);
            indirect_buffer_copy_ = VK_NULL_HANDLE;
        }

        if (count_buffer_copy_ != VK_NULL_HANDLE)
        {
            device_table_->DestroyBuffer(device_info_->handle, count_buffer_copy_, nullptr);
            count_buffer_copy_ = VK_NULL_HANDLE;
        }

        if (indirect_buffer_copy_memory_ != VK_NULL_HANDLE)
        {
            if (data_)
            {
                device_table_->UnmapMemory(device_info_->handle, indirect_buffer_copy_memory_);
                data_ = nullptr;
            }

            device_table_->FreeMemory(device_info_->handle, indirect_buffer_copy_memory_, nullptr);
            indirect_buffer_copy_memory_ = VK_NULL_HANDLE;
        }

        if (count_buffer_copy_memory_ != VK_NULL_HANDLE)
        {
            if (count_data_)
            {
                device_table_->UnmapMemory(device_info_->handle, count_buffer_copy_memory_);
                count_data_ = nullptr;
            }

            device_table_->FreeMemory(device_info_->handle, count_buffer_copy_memory_, nullptr);
            count_buffer_copy_memory_ = VK_NULL_HANDLE;
        }
    }

    void Initialize(const CommandBufferInfo*  command_buffer_info,
                    const PhysicalDeviceInfo* phys_dev_info,
                    VkDeviceSize              buffer_offset,
                    VkDeviceSize              count_buffer_offset,
                    uint32_t                  drawCount,
                    uint32_t                  stride)
    {
        draw_count_ = drawCount;
        stride_     = stride;

        if (drawCount)
        {
            GFXRECON_WRITE_CONSOLE("%s() drawCount: %u", __func__, drawCount);

            // Create auxiliary buffer and device memory
            {
                const VkBufferCreateInfo buffer_create_info = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
                                                                nullptr,
                                                                VkBufferCreateFlags(0),
                                                                drawCount * params_size_,
                                                                VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                                                                    VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                                                VK_SHARING_MODE_EXCLUSIVE,
                                                                0,
                                                                nullptr };

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

            if (is_count_variant_)
            {
                const VkBufferCreateInfo buffer_create_info = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
                                                                nullptr,
                                                                VkBufferCreateFlags(0),
                                                                count_buffer_size_,
                                                                VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                                                                    VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                                                VK_SHARING_MODE_EXCLUSIVE,
                                                                0,
                                                                nullptr };

                VkResult err = device_table_->CreateBuffer(
                    device_info_->handle, &buffer_create_info, nullptr, &count_buffer_copy_);
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
                    device_info_->handle, &mem_alloc_info, NULL, &(count_buffer_copy_memory_));
                assert(!err);

                err = device_table_->BindBufferMemory(
                    device_info_->handle, count_buffer_copy_, count_buffer_copy_memory_, 0);
                assert(!err);

                err = device_table_->MapMemory(
                    device_info_->handle, count_buffer_copy_memory_, 0, count_buffer_size_, 0, &count_data_);
                assert(count_data_);
            }

            command_params_.resize(drawCount);

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
                    copy_regions[i].srcOffset = buffer_offset + i * stride;
                    copy_regions[i].dstOffset = i * params_size_;
                    copy_regions[i].size      = params_size_;
                }
            }
            else
            {
                copy_count = 1;

                copy_regions[0].srcOffset = buffer_offset;
                copy_regions[0].dstOffset = 0;
                copy_regions[0].size      = drawCount * params_size_;
            }

            GFXRECON_WRITE_CONSOLE("%s() copy_count: %u", __func__, copy_count);

            assert(buffer_);
            device_table_->CmdCopyBuffer(
                command_buffer_info->handle, buffer_->handle, indirect_buffer_copy_, copy_count, copy_regions);

            delete[] copy_regions;

            // Copy count buffer if applicable
            if (is_count_variant_)
            {
                assert(count_buffer_);

                const VkBufferCopy count_buffer_copy{ count_buffer_offset, 0, count_buffer_size_ };

                device_table_->CmdCopyBuffer(
                    command_buffer_info->handle, count_buffer_->handle, count_buffer_copy_, 1, &count_buffer_copy);
            }
        }
    }

    void FetchParameters()
    {
        assert(data_);

        GFXRECON_WRITE_CONSOLE("%s()", __func__);

        const size_t size = params_size_ * draw_count_;
        util::platform::MemoryCopy(command_params_.data(), size, data_, size);

        if (is_count_variant_)
        {
            assert(count_data_);
            util::platform::MemoryCopy(&draw_count_, count_buffer_size_, count_data_, count_buffer_size_);
        }
    }

    const std::vector<indirect_draw_parameters_union>& GetParams() const { return command_params_; }

    format::CommandIndexType GetIndex() const { return index_; }
    vulkan_command_type      GetType() const { return type_; }
    uint32_t                 GetDrawCount() const { return draw_count_; }

  protected:
    const format::CommandIndexType index_;
    const vulkan_command_type      type_;
    const bool                     is_count_variant_;
    const size_t                   count_buffer_size_;

    BufferInfo *buffer_, *count_buffer_;
    uint32_t    draw_count_;
    uint32_t    stride_;

    std::vector<indirect_draw_parameters_union> command_params_;
    const DeviceInfo*                           device_info_;
    const encode::DeviceTable*                  device_table_;
    const encode::InstanceTable*                instance_table_;

    const size_t   params_size_;
    VkBuffer       indirect_buffer_copy_, count_buffer_copy_;
    VkDeviceMemory indirect_buffer_copy_memory_, count_buffer_copy_memory_;
    void *         data_, *count_data_;
};

class VulkanCommandDrawIndirectInfo : public VulkanIndirectCommandInfo
{
  public:
    VulkanCommandDrawIndirectInfo(format::CommandIndexType     index,
                                  const DeviceInfo*            device_info,
                                  const encode::DeviceTable*   device_table,
                                  const encode::InstanceTable* instance_table,
                                  BufferInfo*                  buffer) :
        VulkanIndirectCommandInfo(
            index, VULKAN_CMD_DRAW_INDIRECT, device_info, device_table, instance_table, buffer, nullptr)
    {}

    void Initialize(const CommandBufferInfo*  command_buffer_info,
                    const PhysicalDeviceInfo* phys_dev_info,
                    VkDeviceSize              buffer_offset,
                    uint32_t                  drawCount,
                    uint32_t                  stride)
    {
        VulkanIndirectCommandInfo::Initialize(command_buffer_info, phys_dev_info, buffer_offset, 0, drawCount, stride);
    }

    void Dump() const
    {
        GFXRECON_WRITE_CONSOLE("  VULKAN_CMD_DRAW_INDIRECT: %u %u %u %u",
                               command_params_[0].indirect.vertexCount,
                               command_params_[0].indirect.instanceCount,
                               command_params_[0].indirect.firstVertex,
                               command_params_[0].indirect.firstInstance);
    }
};

class VulkanCommandDrawIndirectCountInfo : public VulkanIndirectCommandInfo
{
  public:
    VulkanCommandDrawIndirectCountInfo(format::CommandIndexType     index,
                                       const DeviceInfo*            device_info,
                                       const encode::DeviceTable*   device_table,
                                       const encode::InstanceTable* instance_table,
                                       BufferInfo*                  buffer,
                                       BufferInfo*                  count_buffer) :
        VulkanIndirectCommandInfo(
            index, VULKAN_CMD_DRAW_INDIRECT_COUNT, device_info, device_table, instance_table, buffer, count_buffer)
    {}

    void Initialize(const CommandBufferInfo*  command_buffer_info,
                    const PhysicalDeviceInfo* phys_dev_info,
                    VkDeviceSize              buffer_offset,
                    VkDeviceSize              count_buffer_offset,
                    uint32_t                  drawCount,
                    uint32_t                  stride)
    {
        VulkanIndirectCommandInfo::Initialize(
            command_buffer_info, phys_dev_info, buffer_offset, count_buffer_offset, drawCount, stride);
    }

    void Dump() const
    {
        GFXRECON_WRITE_CONSOLE("  VULKAN_CMD_DRAW_INDIRECT_COUNT: %u %u %u %u",
                               command_params_[0].indirect.vertexCount,
                               command_params_[0].indirect.instanceCount,
                               command_params_[0].indirect.firstVertex,
                               command_params_[0].indirect.firstInstance);
    }
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

#endif /* GFXRECON_DECODE_VULKAN_INDIRECT_COMMANDS_INFO_H */
