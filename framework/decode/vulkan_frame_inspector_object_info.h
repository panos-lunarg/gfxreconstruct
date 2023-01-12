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

#ifndef GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_OBJECT_INFO_H
#define GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_OBJECT_INFO_H

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_frame_inspector_vulkan_commands_info.h"
#include "format/format.h"
#include "vulkan/vulkan.h"

#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

enum VulkanCommandBufferState : uint8_t
{
    kInitial,
    kRecording,
    kExecutable,
    kPending,
    kInvalid
};

struct CommandBufferInfo : public VulkanPoolObjectInfo<VkCommandBuffer>
{
    using command_list_t = std::map<format::CommandIndexType, std::unique_ptr<VulkanCommandInfo>>;

    command_list_t           command_list;
    VulkanCommandBufferState state;
    VkCommandBufferLevel     level;
    VkResult                 begin_result;

    // Need to keep track of indirect commands separately in order to copy the indirect
    // command information from the buffer(s) after the submission has finished
    std::vector<VulkanCommandInfo*> indirect_commands;

    const VulkanCommandBindDescriptorSetsInfo* last_bound_descriptor_sets;
    const VulkanCommandBindPipelineInfo*       last_bound_pipeline;
    const RenderPassInfo*                      active_renderpass;
    uint32_t                                   active_subpass;
    const VulkanCommandBindIndexBufferInfo*    last_bound_index_buffer;

    void EmplaceCommand(std::unique_ptr<VulkanCommandInfo> command)
    {
        auto result = command_list.emplace(command->index, std::move(command));
        if (!result.second)
        {
            GFXRECON_LOG_WARNING("Duplicate entry for command buffer %" PRIu64, command->index);
        }
    }

    void Reset()
    {
        command_list.clear();

        state                      = kInitial;
        last_bound_descriptor_sets = nullptr;
        last_bound_pipeline        = nullptr;
        active_renderpass          = nullptr;
        active_subpass             = UINT32_MAX;
        last_bound_index_buffer    = nullptr;
    }
};

enum serialized_command_types
{
    // Events
    SERIALIZED_CMD_SET_EVENT,
    SERIALIZED_CMD_RESET_EVENT,

    // Fences
    SERIALIZED_CMD_WAIT_FOR_FENCES,
    SERIALIZED_CMD_RESET_FENCES,

    // Semaphores
    SERIALIZED_CMD_WAIT_SEMAPHORES,
    SERIALIZED_CMD_SIGNAL_SEMAPHORE,

    // Sync
    SERIALIZED_CMD_QUEUE_WAIT_IDLE,
    SERIALIZED_CMD_DEVICE_WAIT_IDLE,
    SERIALIZED_CMD_QUEUE_SUBMIT,
    SERIALIZED_CMD_WAIT_FOR_PRESENT,

    // Command buffers and pools
    SERIALIZED_CMD_RESET_COMMAND_POOL,
    SERIALIZED_CMD_RESET_COMMAND_BUFFER,

    // Resource management
    SERIALIZED_CMD_UPDATE_DESCRIPTOR_SETS,

    // GFXR internal commands
    SERIALIZED_CMD_GFXR_FILL_MEMORY,
    SERIALIZED_CMD_GFXR_BEGIN_RESOURCE_INIT,
    SERIALIZED_CMD_GFXR_END_RESOURCE_INIT,
    SERIALIZED_CMD_GFXR_INIT_BUFFER,
    SERIALIZED_CMD_GFXR_INIT_IMAGE
};

#define CASE_TO_STR(_case_) \
    case _case_:            \
        return #_case_;

static const char* serialized_command_to_str(serialized_command_types type)
{
    switch (type)
    {
        CASE_TO_STR(SERIALIZED_CMD_SET_EVENT)
        CASE_TO_STR(SERIALIZED_CMD_RESET_EVENT)
        CASE_TO_STR(SERIALIZED_CMD_WAIT_FOR_FENCES)
        CASE_TO_STR(SERIALIZED_CMD_RESET_FENCES)
        CASE_TO_STR(SERIALIZED_CMD_WAIT_SEMAPHORES)
        CASE_TO_STR(SERIALIZED_CMD_SIGNAL_SEMAPHORE)
        CASE_TO_STR(SERIALIZED_CMD_QUEUE_WAIT_IDLE)
        CASE_TO_STR(SERIALIZED_CMD_DEVICE_WAIT_IDLE)
        CASE_TO_STR(SERIALIZED_CMD_QUEUE_SUBMIT)
        CASE_TO_STR(SERIALIZED_CMD_WAIT_FOR_PRESENT)
        CASE_TO_STR(SERIALIZED_CMD_RESET_COMMAND_POOL)
        CASE_TO_STR(SERIALIZED_CMD_RESET_COMMAND_BUFFER)
        CASE_TO_STR(SERIALIZED_CMD_UPDATE_DESCRIPTOR_SETS)
        CASE_TO_STR(SERIALIZED_CMD_GFXR_FILL_MEMORY)
        CASE_TO_STR(SERIALIZED_CMD_GFXR_BEGIN_RESOURCE_INIT)
        CASE_TO_STR(SERIALIZED_CMD_GFXR_END_RESOURCE_INIT)
        CASE_TO_STR(SERIALIZED_CMD_GFXR_INIT_BUFFER)
        CASE_TO_STR(SERIALIZED_CMD_GFXR_INIT_IMAGE)
        default:
            assert(0);
            return "XXX";
    }
}

//
// Serialized commands
//

struct SerializedCommands
{
    SerializedCommands(format::CommandIndexType index, serialized_command_types type) : index(index), type(type) {}
    virtual ~SerializedCommands() {}

    format::CommandIndexType index;
    serialized_command_types type;
};

//
// Events
//
struct SetEventInfo : public SerializedCommands
{
    SetEventInfo(format::CommandIndexType index, serialized_command_types type) : SerializedCommands(index, type) {}

    const DeviceInfo* device;
    const EventInfo*  event;
};
struct ResetEventInfo : public SerializedCommands
{
    ResetEventInfo(format::CommandIndexType index, serialized_command_types type) : SerializedCommands(index, type) {}

    const DeviceInfo* device;
    const EventInfo*  event;
};

//
// Fences
//
struct ResetFencesInfo : public SerializedCommands
{
    ResetFencesInfo(format::CommandIndexType index, serialized_command_types type) : SerializedCommands(index, type) {}

    DeviceInfo*             device;
    std::vector<FenceInfo*> fences;
};
struct WaitForFencesInfo : public SerializedCommands
{
    WaitForFencesInfo(format::CommandIndexType index, serialized_command_types type) : SerializedCommands(index, type)
    {}

    const DeviceInfo*       device;
    std::vector<FenceInfo*> fences;
    VkBool32                waitAll;
    uint64_t                timeout;
};

//
// Semaphores
//
struct WaitSemaphoresInfo : public SerializedCommands
{
    WaitSemaphoresInfo(format::CommandIndexType index, serialized_command_types type) : SerializedCommands(index, type)
    {}

    DeviceInfo*                 device;
    std::vector<SemaphoreInfo*> semaphores;
    std::vector<uint64_t>       values;
};
struct SignalSemaphore : public SerializedCommands
{
    SignalSemaphore(format::CommandIndexType index, serialized_command_types type) : SerializedCommands(index, type) {}

    DeviceInfo*    device;
    SemaphoreInfo* semaphore;
    uint64_t       values;
};

//
// Sync
//
struct QueueWaitIdleInfo : public SerializedCommands
{
    QueueWaitIdleInfo(format::CommandIndexType index, serialized_command_types type) : SerializedCommands(index, type)
    {}

    QueueInfo* queue;
};

struct DeviceWaitIdle : public SerializedCommands
{
    DeviceWaitIdle(format::CommandIndexType index, serialized_command_types type) : SerializedCommands(index, type) {}

    DeviceInfo* device;
};

struct QueueSubmitInfo : public SerializedCommands
{
    QueueSubmitInfo(format::CommandIndexType index, serialized_command_types type) : SerializedCommands(index, type) {}

    std::vector<CommandBufferInfo*>   command_buffers;
    const QueueInfo*                  queue = nullptr;
    std::vector<SemaphoreInfo*>       wait_semaphores;
    std::vector<VkPipelineStageFlags> wait_dst_stage_mask;
    std::vector<SemaphoreInfo*>       signal_semaphores;
    const FenceInfo*                  fence = nullptr;
};

struct WaitForPresentInfo : public SerializedCommands
{
    WaitForPresentInfo(format::CommandIndexType index, serialized_command_types type) : SerializedCommands(index, type)
    {}

    DeviceInfo*       device;
    SwapchainKHRInfo* swapchain;
    uint64_t          presentId;
    uint64_t          timeout;
};

struct DescriptorImageInfo
{
    SamplerInfo*   sampler;
    ImageViewInfo* image_view;
    VkImageLayout  image_layout;
};

struct DescriptorBufferInfo
{
    BufferInfo*  buffer;
    VkDeviceSize offset;
    VkDeviceSize range;
};

//
// Resource management
//
struct WriteDescriptorSetInfo
{
    DescriptorSetInfo* desc_set;
    uint32_t           dst_binding;
    uint32_t           dst_array_element;
    uint32_t           descriptor_count;
    VkDescriptorType   descriptor_type;

    std::vector<DescriptorImageInfo>  image_info;
    std::vector<DescriptorBufferInfo> buffer_info;
    std::vector<BufferViewInfo*>      texel_buffer_view;
};

struct CopyDescriptorSetInfo
{};

struct UpdateDescriptorSetsInfo : public SerializedCommands
{
    UpdateDescriptorSetsInfo(format::CommandIndexType index, serialized_command_types type) :
        SerializedCommands(index, type)
    {}

    std::vector<WriteDescriptorSetInfo> writes;
    std::vector<CopyDescriptorSetInfo>  copies;
};

//
// GFXR internal commands
//
struct GFXRCommandFillMemory : public SerializedCommands
{
    GFXRCommandFillMemory(format::CommandIndexType index, serialized_command_types type) :
        SerializedCommands(index, type)
    {}

    uint64_t       memory_id;
    uint64_t       offset;
    uint64_t       size;
    const uint8_t* data;
};

struct GFXRCommandBeginResourceInitCommand : public SerializedCommands
{
    GFXRCommandBeginResourceInitCommand(format::CommandIndexType index, serialized_command_types type) :
        SerializedCommands(index, type)
    {}

    format::HandleId device_id;
    uint64_t         max_resource_size;
    uint64_t         max_copy_size;
};

struct GFXRCommandEndResourceInitCommand : public SerializedCommands
{
    GFXRCommandEndResourceInitCommand(format::CommandIndexType index, serialized_command_types type) :
        SerializedCommands(index, type)
    {}

    format::HandleId device_id;
};

struct GFXRCommandInitBufferCommand : public SerializedCommands
{
    GFXRCommandInitBufferCommand(format::CommandIndexType index, serialized_command_types type) :
        SerializedCommands(index, type)
    {}

    format::HandleId         device_id;
    format::HandleId         buffer_id;
    uint64_t                 data_size;
    std::unique_ptr<uint8_t[]> data;
};

struct GFXRCommandInitImageCommand : public SerializedCommands
{
    GFXRCommandInitImageCommand(format::CommandIndexType index, serialized_command_types type) :
        SerializedCommands(index, type)
    {}

    format::HandleId         device_id;
    format::HandleId         image_id;
    uint64_t                 data_size;
    uint32_t                 aspect;
    uint32_t                 layout;
    std::vector<uint64_t>    level_sizes;
    std::unique_ptr<uint8_t[]> data;
};

using serialized_commands_map_t = std::map<format::CommandIndexType, std::unique_ptr<SerializedCommands>>;

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif // GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_OBJECT_INFO_H
