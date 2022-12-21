/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include "decode/vulkan_frame_inspector_vulkan_commands_info.h"
#include "decode/vulkan_frame_inspector_indirect_commands_info.h"

#include "decode/vulkan_frame_inspector_consumer_base.h"
#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "util/defines.h"
#include "graphics/vulkan_util.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanFrameInspectorConsumerBase::RaiseFatalError(const char* message) const
{
    // TODO: Should there be a default action if no error handler has been provided?
    if (fatal_error_handler_ != nullptr)
    {
        fatal_error_handler_(message);
    }
}

void VulkanFrameInspectorConsumerBase::Reset()
{
    commands_.clear();
}

void VulkanFrameInspectorConsumerBase::ProcessFillMemoryCommand(
    format::CommandIndexType command_index, uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data)
{
    std::unique_ptr<GFXRCommandFillMemory> command =
        std::make_unique<GFXRCommandFillMemory>(command_index, SERIALIZED_CMD_GFXR_FILL_MEMORY);

    command->data      = data;
    command->memory_id = memory_id;
    command->offset    = offset;
    command->size      = size;

    commands_.emplace(command_index, std::move(command));

    VulkanReplayBase::ProcessFillMemoryCommand(command_index, memory_id, offset, size, data);
}

void VulkanFrameInspectorConsumerBase::ProcessBeginResourceInitCommand(format::CommandIndexType command_index,
                                                                       format::HandleId         device_id,
                                                                       uint64_t                 max_resource_size,
                                                                       uint64_t                 max_copy_size)
{
    std::unique_ptr<GFXRCommandBeginResourceInitCommand> command =
        std::make_unique<GFXRCommandBeginResourceInitCommand>(command_index, SERIALIZED_CMD_GFXR_BEGIN_RESOURCE_INIT);

    command->device_id         = device_id;
    command->max_copy_size     = max_copy_size;
    command->max_resource_size = max_resource_size;

    commands_.emplace(command_index, std::move(command));

    VulkanReplayBase::ProcessBeginResourceInitCommand(command_index, device_id, max_resource_size, max_copy_size);
}

void VulkanFrameInspectorConsumerBase::ProcessEndResourceInitCommand(format::CommandIndexType command_index,
                                                                     format::HandleId         device_id)
{
    std::unique_ptr<GFXRCommandEndResourceInitCommand> command =
        std::make_unique<GFXRCommandEndResourceInitCommand>(command_index, SERIALIZED_CMD_GFXR_END_RESOURCE_INIT);

    command->device_id = device_id;

    commands_.emplace(command_index, std::move(command));

    VulkanReplayBase::ProcessEndResourceInitCommand(command_index, device_id);
}

void VulkanFrameInspectorConsumerBase::ProcessInitBufferCommand(format::CommandIndexType command_index,
                                                                format::HandleId         device_id,
                                                                format::HandleId         buffer_id,
                                                                uint64_t                 data_size,
                                                                const uint8_t*           data)
{
    std::unique_ptr<GFXRCommandInitBufferCommand> command =
        std::make_unique<GFXRCommandInitBufferCommand>(command_index, SERIALIZED_CMD_GFXR_INIT_BUFFER);

    command->device_id = device_id;
    command->buffer_id = buffer_id;
    command->data_size = data_size;
    command->data      = std::make_unique<uint8_t>(data_size);
    util::platform::MemoryCopy(command->data.get(), data_size, data, data_size);

    commands_.emplace(command_index, std::move(command));

    VulkanReplayBase::ProcessInitBufferCommand(command_index, device_id, buffer_id, data_size, data);
}

void VulkanFrameInspectorConsumerBase::ProcessInitImageCommand(format::CommandIndexType     command_index,
                                                               format::HandleId             device_id,
                                                               format::HandleId             image_id,
                                                               uint64_t                     data_size,
                                                               uint32_t                     aspect,
                                                               uint32_t                     layout,
                                                               const std::vector<uint64_t>& level_sizes,
                                                               const uint8_t*               data)
{
    std::unique_ptr<GFXRCommandInitImageCommand> command =
        std::make_unique<GFXRCommandInitImageCommand>(command_index, SERIALIZED_CMD_GFXR_INIT_IMAGE);

    command->device_id   = device_id;
    command->image_id    = image_id;
    command->data_size   = data_size;
    command->aspect      = aspect;
    command->layout      = layout;
    command->level_sizes = level_sizes;
    command->data        = std::make_unique<uint8_t>(data_size);
    util::platform::MemoryCopy(command->data.get(), data_size, data, data_size);

    commands_.emplace(command_index, std::move(command));

    VulkanReplayBase::ProcessInitImageCommand(
        command_index, device_id, image_id, data_size, aspect, layout, level_sizes, data);
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateInstance(
    VkResult                                                   original_result,
    const StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*                          pInstance)

{
    InstanceInfo handle_info;
    pInstance->SetConsumerData(0, &handle_info);

    if (loader_handle_ == nullptr)
    {
        InitializeLoader();
    }

    auto replay_create_info = pCreateInfo->GetPointer();
    auto replay_allocator   = pAllocator->GetPointer();
    auto replay_instance    = pInstance->GetHandlePointer();

    VkResult result = create_instance_proc_(replay_create_info, replay_allocator, replay_instance);

    if (result == VK_SUCCESS)
    {
        AddInstanceTable(*replay_instance);
    }

    return result;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideBeginCommandBuffer(
    const ApiCallInfo&                                      call_info,
    VkResult                                                original_result,
    CommandBufferInfo*                                      command_buffer_info,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    assert(command_buffer_info->command_list.size() == 0);
    assert(command_buffer_info->state == kInitial);

    command_buffer_info->Reset();
    command_buffer_info->state = kRecording;

    const VkCommandBufferBeginInfo* in_pBeginInfo = pBeginInfo->GetPointer();
    MapStructHandles(pBeginInfo->GetMetaStructPointer(), GetObjectInfoTable());

    return GetDeviceTable(command_buffer_info->handle)->BeginCommandBuffer(command_buffer_info->handle, in_pBeginInfo);
}

VkResult VulkanFrameInspectorConsumerBase::OverrideEndCommandBuffer(const ApiCallInfo& call_info,
                                                                    VkResult           original_result,
                                                                    CommandBufferInfo* command_buffer_info)
{
    assert(command_buffer_info->state == kRecording);

    command_buffer_info->state = kExecutable;

    return GetDeviceTable(command_buffer_info->handle)->EndCommandBuffer(command_buffer_info->handle);
}

VkResult VulkanFrameInspectorConsumerBase::OverrideResetCommandBuffer(const ApiCallInfo&        call_info,
                                                                      CommandBufferInfo*        command_buffer_info,
                                                                      VkCommandBufferResetFlags flags)
{
    command_buffer_info->Reset();

    auto in_device = GetObjectInfoTable().GetDeviceInfo(command_buffer_info->parent_id);
    return GetDeviceTable(in_device->handle)->ResetCommandBuffer(command_buffer_info->handle, flags);
}

VkResult VulkanFrameInspectorConsumerBase::OverrideResetCommandPool(const ApiCallInfo&      call_info,
                                                                    VkResult                returnValue,
                                                                    DeviceInfo*             device_info,
                                                                    CommandPoolInfo*        commandPool_info,
                                                                    VkCommandPoolResetFlags flags)
{
    for (auto child_id : commandPool_info->child_ids)
    {
        auto command_buffer_info = GetObjectInfoTable().GetCommandBufferInfo(child_id);
        command_buffer_info->Reset();
    }

    return GetDeviceTable(device_info->handle)->ResetCommandPool(device_info->handle, commandPool_info->handle, flags);
}

void VulkanFrameInspectorConsumerBase::OverrideCmdBindPipeline(const ApiCallInfo&  call_info,
                                                               CommandBufferInfo*  command_buffer_info,
                                                               VkPipelineBindPoint pipelineBindPoint,
                                                               const PipelineInfo* pipeline_info)
{
    std::unique_ptr<VulkanCommandBindPipelineInfo> command =
        std::make_unique<VulkanCommandBindPipelineInfo>(call_info.index, VULKAN_CMD_BIND_PIPELINE);

    command->pipeline          = pipeline_info;
    command->pipelineBindPoint = pipelineBindPoint;

    command_buffer_info->EmplaceCommand(std::move(command));

    GetDeviceTable(command_buffer_info->handle)
        ->CmdBindPipeline(command_buffer_info->handle, pipelineBindPoint, pipeline_info->handle);
}

void VulkanFrameInspectorConsumerBase::OverrideCmdSetViewport(const ApiCallInfo& call_info,
                                                              CommandBufferInfo* command_buffer_info,
                                                              uint32_t           firstViewport,
                                                              uint32_t           viewportCount,
                                                              StructPointerDecoder<Decoded_VkViewport>* pViewports)
{
    std::unique_ptr<VulkanCommandSetViewportInfo> command =
        std::make_unique<VulkanCommandSetViewportInfo>(call_info.index, VULKAN_CMD_SET_VIEWPORT);

    const VkViewport* viewports = pViewports->GetPointer();
    assert(pViewports->GetLength() == viewportCount);
    for (uint32_t i = 0; i < viewportCount; ++i)
    {
        command->viewports.push_back(viewports[i]);
    }

    command->first_viewport = firstViewport;

    command_buffer_info->EmplaceCommand(std::move(command));

    GetDeviceTable(command_buffer_info->handle)
        ->CmdSetViewport(command_buffer_info->handle, firstViewport, viewportCount, viewports);
}

void VulkanFrameInspectorConsumerBase::OverrideCmdSetScissor(const ApiCallInfo& call_info,
                                                             CommandBufferInfo* command_buffer_info,
                                                             uint32_t           firstScissor,
                                                             uint32_t           scissorCount,
                                                             StructPointerDecoder<Decoded_VkRect2D>* pScissors)
{
    std::unique_ptr<VulkanCommandSetScissorInfo> command =
        std::make_unique<VulkanCommandSetScissorInfo>(call_info.index, VULKAN_CMD_SET_SCISSOR);

    const VkRect2D* scissors = pScissors->GetPointer();
    assert(pScissors->GetLength() == scissorCount);
    for (uint32_t i = 0; i < scissorCount; ++i)
    {
        command->scissors.push_back(scissors[i]);
    }

    command->first_scissor = firstScissor;

    command_buffer_info->EmplaceCommand(std::move(command));

    GetDeviceTable(command_buffer_info->handle)
        ->CmdSetScissor(command_buffer_info->handle, firstScissor, scissorCount, scissors);
}

void VulkanFrameInspectorConsumerBase::OverrideCmdBindDescriptorSets(
    const ApiCallInfo&                     call_info,
    CommandBufferInfo*                     command_buffer_info,
    VkPipelineBindPoint                    pipelineBindPoint,
    const PipelineLayoutInfo*              pipeline_layout_info,
    uint32_t                               firstSet,
    uint32_t                               descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets,
    uint32_t                               dynamicOffsetCount,
    PointerDecoder<uint32_t>*              pDynamicOffsets)
{
    std::unique_ptr<VulkanCommandBindDescriptorSetsInfo> command =
        std::make_unique<VulkanCommandBindDescriptorSetsInfo>(call_info.index, VULKAN_CMD_BIND_DESCRIPTOR_SETS);

    const format::HandleId* desc_set_handles = pDescriptorSets->GetPointer();
    assert(pDescriptorSets->GetLength() == descriptorSetCount);
    for (size_t i = 0; i < pDescriptorSets->GetLength(); ++i)
    {
        command->descriptor_sets.push_back(GetObjectInfoTable().GetDescriptorSetInfo(desc_set_handles[i]));
    }

    const uint32_t* dynamic_offsets = pDynamicOffsets->GetPointer();
    for (uint32_t i = 0; i < dynamicOffsetCount; ++i)
    {
        command->dynamic_offsets.push_back(dynamic_offsets[i]);
    }

    command->pipelineBindPoint = pipelineBindPoint;
    command->pipeline_layout   = pipeline_layout_info;
    command->first_set         = firstSet;

    command_buffer_info->EmplaceCommand(std::move(command));

    const VkDescriptorSet* in_pDescriptorSets = MapHandles<DescriptorSetInfo>(
        pDescriptorSets, descriptorSetCount, &VulkanObjectInfoTable::GetDescriptorSetInfo);

    GetDeviceTable(command_buffer_info->handle)
        ->CmdBindDescriptorSets(command_buffer_info->handle,
                                pipelineBindPoint,
                                pipeline_layout_info->handle,
                                firstSet,
                                descriptorSetCount,
                                in_pDescriptorSets,
                                dynamicOffsetCount,
                                dynamic_offsets);
}

void VulkanFrameInspectorConsumerBase::OverrideCmdBindIndexBuffer(const ApiCallInfo& call_info,
                                                                  CommandBufferInfo* command_buffer_info,
                                                                  const BufferInfo*  buffer_info,
                                                                  VkDeviceSize       offset,
                                                                  VkIndexType        indexType)
{
    std::unique_ptr<VulkanCommandBindIndexBufferInfo> command =
        std::make_unique<VulkanCommandBindIndexBufferInfo>(call_info.index, VULKAN_CMD_BIND_INDEX_BUFFER);

    command->buffer_info = buffer_info;
    command->offset      = offset;
    command->indexType   = indexType;

    command_buffer_info->EmplaceCommand(std::move(command));

    GetDeviceTable(command_buffer_info->handle)
        ->CmdBindIndexBuffer(command_buffer_info->handle, buffer_info->handle, offset, indexType);
}

void VulkanFrameInspectorConsumerBase::OverrideCmdBindVertexBuffers(const ApiCallInfo&              call_info,
                                                                    CommandBufferInfo*              command_buffer_info,
                                                                    uint32_t                        firstBinding,
                                                                    uint32_t                        bindingCount,
                                                                    HandlePointerDecoder<VkBuffer>* pBuffers,
                                                                    PointerDecoder<VkDeviceSize>*   pOffsets)
{
    std::unique_ptr<VulkanCommandBindVertexBuffersInfo> command =
        std::make_unique<VulkanCommandBindVertexBuffersInfo>(call_info.index, VULKAN_CMD_BIND_VERTEX_BUFFERS);

    const format::HandleId* buffer_handles = pBuffers->GetPointer();
    const VkDeviceSize*     in_pOffsets    = pOffsets->GetPointer();
    assert(pBuffers->GetLength() == bindingCount);
    for (uint32_t i = 0; i < bindingCount; ++i)
    {
        command->buffers.push_back(GetObjectInfoTable().GetBufferInfo(buffer_handles[i]));
        command->offsets.push_back(in_pOffsets[i]);
    }

    command_buffer_info->EmplaceCommand(std::move(command));

    const VkBuffer* in_pBuffers = MapHandles<BufferInfo>(pBuffers, bindingCount, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(command_buffer_info->handle)
        ->CmdBindVertexBuffers(command_buffer_info->handle, firstBinding, bindingCount, in_pBuffers, in_pOffsets);
}

void VulkanFrameInspectorConsumerBase::OverrideCmdDraw(const ApiCallInfo& call_info,
                                                       CommandBufferInfo* command_buffer_info,
                                                       uint32_t           vertexCount,
                                                       uint32_t           instanceCount,
                                                       uint32_t           firstVertex,
                                                       uint32_t           firstInstance)
{

    std::unique_ptr<VulkanCommandDrawInfo> command =
        std::make_unique<VulkanCommandDrawInfo>(call_info.index, VULKAN_CMD_DRAW);

    command->vertexCount   = vertexCount;
    command->instanceCount = instanceCount;
    command->firstVertex   = firstVertex;
    command->firstInstance = firstInstance;

    command_buffer_info->EmplaceCommand(std::move(command));

    GetDeviceTable(command_buffer_info->handle)
        ->CmdDraw(command_buffer_info->handle, vertexCount, instanceCount, firstVertex, firstInstance);
}

void VulkanFrameInspectorConsumerBase::OverrideCmdDrawIndexed(const ApiCallInfo& call_info,
                                                              CommandBufferInfo* command_buffer_info,
                                                              uint32_t           indexCount,
                                                              uint32_t           instanceCount,
                                                              uint32_t           firstIndex,
                                                              int32_t            vertexOffset,
                                                              uint32_t           firstInstance)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdDrawIndirect(const ApiCallInfo& call_info,
                                                               CommandBufferInfo* command_buffer_info,
                                                               BufferInfo*        buffer_info,
                                                               VkDeviceSize       offset,
                                                               uint32_t           drawCount,
                                                               uint32_t           stride)
{
    assert(command_buffer_info->state == kRecording);
    assert(command_buffer_info->parent_id == buffer_info->parent_id);

    auto device_info = GetObjectInfoTable().GetDeviceInfo(command_buffer_info->parent_id);

    PhysicalDeviceInfo* phys_dev_info = GetObjectInfoTable().GetPhysicalDeviceInfo(device_info->parent_id);

    std::unique_ptr<VulkanCommandDrawIndirectInfo> command =
        std::make_unique<VulkanCommandDrawIndirectInfo>(call_info.index,
                                                        VULKAN_CMD_DRAW_INDIRECT,
                                                        device_info,
                                                        GetDeviceTable(device_info->handle),
                                                        GetInstanceTable(phys_dev_info->handle));
    command->Initialize(command_buffer_info, phys_dev_info, buffer_info->handle, offset, drawCount, stride);

    assert(GetInstanceTable(device_info->parent) == GetInstanceTable(phys_dev_info->handle));

    command_buffer_info->indirect_commands.push_back(command.get());
    command_buffer_info->EmplaceCommand(std::move(command));

    GetDeviceTable(command_buffer_info->handle)
        ->CmdDrawIndirect(command_buffer_info->handle, buffer_info->handle, offset, drawCount, stride);
}

void VulkanFrameInspectorConsumerBase::OverrideCmdDrawIndexedIndirect(const ApiCallInfo& call_info,
                                                                      CommandBufferInfo* command_buffer_info,
                                                                      BufferInfo*        buffer_info,
                                                                      VkDeviceSize       offset,
                                                                      uint32_t           drawCount,
                                                                      uint32_t           stride)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdDispatch(const ApiCallInfo& call_info,
                                                           CommandBufferInfo* command_buffer_info,
                                                           uint32_t           groupCountX,
                                                           uint32_t           groupCountY,
                                                           uint32_t           groupCountZ)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdDispatchIndirect(const ApiCallInfo& call_info,
                                                                   CommandBufferInfo* command_buffer_info,
                                                                   BufferInfo*        buffer_info,
                                                                   VkDeviceSize       offset)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdCopyBuffer(const ApiCallInfo& call_info,
                                                             CommandBufferInfo* command_buffer_info,
                                                             BufferInfo*        src_buffer,
                                                             BufferInfo*        dst_buffer,
                                                             uint32_t           regionCount,
                                                             StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdCopyImage(const ApiCallInfo& call_info,
                                                            CommandBufferInfo* command_buffer_info,
                                                            ImageInfo*         src_image,
                                                            VkImageLayout      srcImageLayout,
                                                            ImageInfo*         dst_image,
                                                            VkImageLayout      dstImageLayout,
                                                            uint32_t           regionCount,
                                                            StructPointerDecoder<Decoded_VkImageCopy>* pRegions)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdBlitImage(const ApiCallInfo& call_info,
                                                            CommandBufferInfo* command_buffer_info,
                                                            ImageInfo*         src_image,
                                                            VkImageLayout      srcImageLayout,
                                                            ImageInfo*         dst_image,
                                                            VkImageLayout      dstImageLayout,
                                                            uint32_t           regionCount,
                                                            StructPointerDecoder<Decoded_VkImageBlit>* pRegions,
                                                            VkFilter                                   filter)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdCopyBufferToImage(
    const ApiCallInfo&                               call_info,
    CommandBufferInfo*                               command_buffer_info,
    BufferInfo*                                      src_buffer,
    ImageInfo*                                       dst_image,
    VkImageLayout                                    dstImageLayout,
    uint32_t                                         regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    std::unique_ptr<VulkanCommandCopyBufferToImageInfo> command =
        std::make_unique<VulkanCommandCopyBufferToImageInfo>(call_info.index, VULKAN_CMD_COPY_BUFFER_TO_IMAGE);

    command->srcBuffer      = src_buffer;
    command->dstImage       = dst_image;
    command->dstImageLayout = dstImageLayout;

    const VkBufferImageCopy* regions = pRegions->GetPointer();
    assert(pRegions->GetLength() == regionCount);
    for (uint32_t i = 0; i < regionCount; ++i)
    {
        command->regions.push_back(regions[i]);
    }

    command_buffer_info->EmplaceCommand(std::move(command));

    GetDeviceTable(command_buffer_info->handle)
        ->CmdCopyBufferToImage(
            command_buffer_info->handle, src_buffer->handle, dst_image->handle, dstImageLayout, regionCount, regions);
}

void VulkanFrameInspectorConsumerBase::OverrideCmdCopyImageToBuffer(
    const ApiCallInfo&                               call_info,
    CommandBufferInfo*                               command_buffer_info,
    ImageInfo*                                       src_image,
    VkImageLayout                                    srcImageLayout,
    BufferInfo*                                      dst_buffer,
    uint32_t                                         regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdUpdateBuffer(const ApiCallInfo&       call_info,
                                                               CommandBufferInfo*       command_buffer_info,
                                                               BufferInfo*              dst_buffer,
                                                               VkDeviceSize             dstOffset,
                                                               VkDeviceSize             dataSize,
                                                               PointerDecoder<uint8_t>* pData)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdFillBuffer(const ApiCallInfo& call_info,
                                                             CommandBufferInfo* command_buffer_info,
                                                             BufferInfo*        dst_buffer,
                                                             VkDeviceSize       dstOffset,
                                                             VkDeviceSize       size,
                                                             uint32_t           data)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdClearColorImage(
    const ApiCallInfo&                                     call_info,
    CommandBufferInfo*                                     command_buffer_info,
    ImageInfo*                                             image_info,
    VkImageLayout                                          imageLayout,
    StructPointerDecoder<Decoded_VkClearColorValue>*       pColor,
    uint32_t                                               rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdClearDepthStencilImage(
    const ApiCallInfo&                                      call_info,
    CommandBufferInfo*                                      command_buffer_info,
    ImageInfo*                                              image_info,
    VkImageLayout                                           imageLayout,
    StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
    uint32_t                                                rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>*  pRanges)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdClearAttachments(
    const ApiCallInfo&                               call_info,
    CommandBufferInfo*                               command_buffer_info,
    uint32_t                                         attachmentCount,
    StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
    uint32_t                                         rectCount,
    StructPointerDecoder<Decoded_VkClearRect>*       pRects)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdResolveImage(const ApiCallInfo& call_info,
                                                               CommandBufferInfo* command_buffer_info,
                                                               ImageInfo*         src_image,
                                                               VkImageLayout      srcImageLayout,
                                                               ImageInfo*         dst_image,
                                                               VkImageLayout      dstImageLayout,
                                                               uint32_t           regionCount,
                                                               StructPointerDecoder<Decoded_VkImageResolve>* pRegions)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdSetEvent(const ApiCallInfo&   call_info,
                                                           CommandBufferInfo*   command_buffer_info,
                                                           EventInfo*           event_info,
                                                           VkPipelineStageFlags stageMask)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdResetEvent(const ApiCallInfo&   call_info,
                                                             CommandBufferInfo*   command_buffer_info,
                                                             EventInfo*           event_info,
                                                             VkPipelineStageFlags stageMask)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdWaitEvents(
    const ApiCallInfo&                                   call_info,
    CommandBufferInfo*                                   command_buffer_info,
    uint32_t                                             eventCount,
    HandlePointerDecoder<VkEvent>*                       pEvents,
    VkPipelineStageFlags                                 srcStageMask,
    VkPipelineStageFlags                                 dstStageMask,
    uint32_t                                             memoryBarrierCount,
    StructPointerDecoder<Decoded_VkMemoryBarrier>*       pMemoryBarriers,
    uint32_t                                             bufferMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
    uint32_t                                             imageMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkImageMemoryBarrier>*  pImageMemoryBarriers)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdPipelineBarrier(
    const ApiCallInfo&                                   call_info,
    CommandBufferInfo*                                   command_buffer_info,
    VkPipelineStageFlags                                 srcStageMask,
    VkPipelineStageFlags                                 dstStageMask,
    VkDependencyFlags                                    dependencyFlags,
    uint32_t                                             memoryBarrierCount,
    StructPointerDecoder<Decoded_VkMemoryBarrier>*       pMemoryBarriers,
    uint32_t                                             bufferMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
    uint32_t                                             imageMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkImageMemoryBarrier>*  pImageMemoryBarriers)
{
    std::unique_ptr<VulkanCommandPipelineBarrierInfo> command =
        std::make_unique<VulkanCommandPipelineBarrierInfo>(call_info.index, VULKAN_CMD_PIPELINE_BARRIER);

    command->srcStageMask    = srcStageMask;
    command->dstStageMask    = dstStageMask;
    command->dependencyFlags = dependencyFlags;

    const VkMemoryBarrier* memory_barriers = pMemoryBarriers->GetPointer();
    assert(memoryBarrierCount == pMemoryBarriers->GetLength());
    for (uint32_t i = 0; i < memoryBarrierCount; ++i)
    {
        command->MemoryBarriers.push_back(memory_barriers[i]);
    }

    const VkBufferMemoryBarrier* buffer_barriers = pBufferMemoryBarriers->GetPointer();
    assert(bufferMemoryBarrierCount == pBufferMemoryBarriers->GetLength());
    for (uint32_t i = 0; i < bufferMemoryBarrierCount; ++i)
    {
        command->BufferMemoryBarriers.push_back(buffer_barriers[i]);
    }

    const VkImageMemoryBarrier* image_barriers = pImageMemoryBarriers->GetPointer();
    assert(imageMemoryBarrierCount == pImageMemoryBarriers->GetLength());
    for (uint32_t i = 0; i < imageMemoryBarrierCount; ++i)
    {
        command->ImageMemoryBarriers.push_back(image_barriers[i]);
    }

    command_buffer_info->EmplaceCommand(std::move(command));

    GetDeviceTable(command_buffer_info->handle)
        ->CmdPipelineBarrier(command_buffer_info->handle,
                             srcStageMask,
                             dstStageMask,
                             dependencyFlags,
                             memoryBarrierCount,
                             memory_barriers,
                             bufferMemoryBarrierCount,
                             buffer_barriers,
                             imageMemoryBarrierCount,
                             image_barriers);
}

void VulkanFrameInspectorConsumerBase::OverrideCmdBeginQuery(const ApiCallInfo&  call_info,
                                                             CommandBufferInfo*  command_buffer_info,
                                                             QueryPoolInfo*      query_pool_info,
                                                             uint32_t            query,
                                                             VkQueryControlFlags flags)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdEndQuery(const ApiCallInfo& call_info,
                                                           CommandBufferInfo* command_buffer_info,
                                                           QueryPoolInfo*     query_pool_info,
                                                           uint32_t           query)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdResetQueryPool(const ApiCallInfo& call_info,
                                                                 CommandBufferInfo* command_buffer_info,
                                                                 QueryPoolInfo*     query_pool_info,
                                                                 uint32_t           firstQuery,
                                                                 uint32_t           queryCount)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdWriteTimestamp(const ApiCallInfo&      call_info,
                                                                 CommandBufferInfo*      command_buffer_info,
                                                                 VkPipelineStageFlagBits pipelineStage,
                                                                 QueryPoolInfo*          query_pool_info,
                                                                 uint32_t                query)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdCopyQueryPoolResults(const ApiCallInfo& call_info,
                                                                       CommandBufferInfo* command_buffer_info,
                                                                       QueryPoolInfo*     query_pool_info,
                                                                       uint32_t           firstQuery,
                                                                       uint32_t           queryCount,
                                                                       BufferInfo*        dst_buffer,
                                                                       VkDeviceSize       dstOffset,
                                                                       VkDeviceSize       stride,
                                                                       VkQueryResultFlags flags)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdPushConstants(const ApiCallInfo&       call_info,
                                                                CommandBufferInfo*       command_buffer_info,
                                                                PipelineLayoutInfo*      pipeline_layout_info,
                                                                VkShaderStageFlags       stageFlags,
                                                                uint32_t                 offset,
                                                                uint32_t                 size,
                                                                PointerDecoder<uint8_t>* pValues)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdBeginRenderPass(
    const ApiCallInfo&                                   call_info,
    CommandBufferInfo*                                   command_buffer_info,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                                    contents)
{
    std::unique_ptr<VulkanCommandBeginRenderPassInfo> command =
        std::make_unique<VulkanCommandBeginRenderPassInfo>(call_info.index, VULKAN_CMD_BEGIN_RENDER_PASS);

    const VkRenderPassBeginInfo* in_pRenderPassBegin = pRenderPassBegin->GetPointer();
    MapStructHandles(pRenderPassBegin->GetMetaStructPointer(), GetObjectInfoTable());

    command->renderpass_info =
        GetObjectInfoTable().GetRenderPassInfo(pRenderPassBegin->GetMetaStructPointer()->renderPass);
    command->framebuffer_info =
        GetObjectInfoTable().GetFramebufferInfo(pRenderPassBegin->GetMetaStructPointer()->framebuffer);
    command->renderArea = *pRenderPassBegin->GetMetaStructPointer()->renderArea->decoded_value;
    command->contents   = contents;

    command_buffer_info->EmplaceCommand(std::move(command));

    GetDeviceTable(command_buffer_info->handle)
        ->CmdBeginRenderPass(command_buffer_info->handle, pRenderPassBegin->GetPointer(), contents);
}

void VulkanFrameInspectorConsumerBase::OverrideCmdNextSubpass(const ApiCallInfo& call_info,
                                                              CommandBufferInfo* command_buffer_info,
                                                              VkSubpassContents  contents)
{}

void VulkanFrameInspectorConsumerBase::OverrideCmdEndRenderPass(const ApiCallInfo& call_info,
                                                                CommandBufferInfo* command_buffer_info)
{
    std::unique_ptr<VulkanCommandEndRenderPassInfo> command =
        std::make_unique<VulkanCommandEndRenderPassInfo>(call_info.index, VULKAN_CMD_END_RENDER_PASS);

    command_buffer_info->EmplaceCommand(std::move(command));

    GetDeviceTable(command_buffer_info->handle)->CmdEndRenderPass(command_buffer_info->handle);
}

void VulkanFrameInspectorConsumerBase::OverrideWaitSemaphores(
    const ApiCallInfo&                                 call_info,
    VkResult                                           returnValue,
    DeviceInfo*                                        device_info,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                           timeout)
{}

void VulkanFrameInspectorConsumerBase::OverrideSignalSemaphore(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    DeviceInfo*                                          device_info,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{}

void VulkanFrameInspectorConsumerBase::EmplaceSerialzedCommand(std::unique_ptr<SerializedCommands> command)
{
    auto result = commands_.emplace(command->index, std::move(command));
    if (!result.second)
    {
        GFXRECON_LOG_WARNING("Duplicate entry for command %" PRIu64, command->index);
    }
}

VkResult
VulkanFrameInspectorConsumerBase::OverrideQueueSubmit(const ApiCallInfo&                                call_info,
                                                      VkResult                                          original_result,
                                                      const QueueInfo*                                  queue_info,
                                                      uint32_t                                          submitCount,
                                                      const StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                                      const FenceInfo*                                  fence_info)
{
    std::unique_ptr<QueueSubmitInfo> command =
        std::make_unique<QueueSubmitInfo>(call_info.index, SERIALIZED_CMD_QUEUE_SUBMIT);
    command->queue                   = queue_info;
    const VkSubmitInfo* submit_infos = pSubmits->GetPointer();
    bool                has_indirect = false;
    VkResult            result;
    VkFence             fence = VK_NULL_HANDLE;

    if (fence_info != nullptr)
    {
        fence = fence_info->handle;
    }

    auto submit_info_data = pSubmits->GetMetaStructPointer();
    for (uint32_t i = 0; i < submitCount; ++i)
    {
        // Get command buffers
        const format::HandleId* command_buffer_ids = submit_info_data[i].pCommandBuffers.GetPointer();
        if (command_buffer_ids != nullptr)
        {
            for (uint32_t c = 0; c < submit_info_data[i].pCommandBuffers.GetLength(); ++c)
            {
                auto cmd_buffer_info = GetObjectInfoTable().GetCommandBufferInfo(command_buffer_ids[c]);
                command->command_buffers.push_back(cmd_buffer_info);

                if (cmd_buffer_info->indirect_commands.size())
                {
                    has_indirect = true;
                }
            }
        }

        // Get signal sempahores
        const format::HandleId* signal_semaphore_ids = submit_info_data[i].pSignalSemaphores.GetPointer();
        for (uint32_t s = 0; s < submit_info_data[i].pSignalSemaphores.GetLength(); ++s)
        {
            command->signal_semaphores.push_back(GetObjectInfoTable().GetSemaphoreInfo(signal_semaphore_ids[s]));
        }

        // Get wait sempahores
        const format::HandleId* wait_semaphore_ids = submit_info_data[i].pWaitSemaphores.GetPointer();
        for (uint32_t s = 0; s < submit_info_data[i].pWaitSemaphores.GetLength(); ++s)
        {
            command->wait_semaphores.push_back(GetObjectInfoTable().GetSemaphoreInfo(wait_semaphore_ids[s]));
            command->wait_dst_stage_mask.push_back(submit_infos[i].pWaitDstStageMask[s]);
        }
    }

    command->fence = fence_info;

    VkDevice device = GetObjectInfoTable().GetDeviceInfo(queue_info->parent_id)->handle;

    VkFence submission_fence;
    if (has_indirect && !fence_info)
    {
        const VkFenceCreateInfo ci = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, VkFenceCreateFlags(0) };

        VkResult res = GetDeviceTable(device)->CreateFence(device, &ci, nullptr, &submission_fence);
        assert(res == VK_SUCCESS);
    }
    else
    {
        submission_fence = fence_info ? fence_info->handle : VK_NULL_HANDLE;
    }

    if (options_.surface_index == -1 && submit_infos->waitSemaphoreCount)
    {
        GetDeviceTable(device)->QueueSubmit(
            queue_info->handle, pSubmits->GetLength(), pSubmits->GetPointer(), submission_fence);
    }
    else
    {
        // Check for imported semaphores in the current submission list, mapping the pSubmits array index to a vector of
        // imported semaphore info structures.
        std::unordered_map<uint32_t, std::vector<const SemaphoreInfo*>> altered_submits;
        std::vector<const SemaphoreInfo*>                               removed_semaphores;

        if (submit_info_data != nullptr)
        {
            for (uint32_t i = 0; i < submitCount; i++)
            {
                GetImportedSemaphores(submit_info_data[i].pWaitSemaphores, &removed_semaphores);
                GetShadowSemaphores(submit_info_data[i].pWaitSemaphores, &removed_semaphores);

                // If rendering is restricted to a specific surface, need to track forward progress for semaphores that
                // have been submitted with a null-swapchain.
                TrackSemaphoreForwardProgress(submit_info_data[i].pWaitSemaphores, &removed_semaphores);

                // Remove non-forward progress of signal semaphores.
                GetNonForwardProgress(submit_info_data[i].pSignalSemaphores, &removed_semaphores);

                if (!removed_semaphores.empty())
                {
                    altered_submits[i].swap(removed_semaphores);
                    assert(removed_semaphores.empty());
                }
            }
        }

        if (altered_submits.empty())
        {
            result = GetDeviceTable(device)->QueueSubmit(queue_info->handle, submitCount, submit_infos, fence);
        }
        else
        {
            // Make shallow copies of the VkSubmit info structures and change pWaitSemaphores to reference a copy of the
            // original semaphore array with the imported semaphores omitted.
            std::vector<VkSubmitInfo> modified_submit_infos(submit_infos, std::next(submit_infos, submitCount));

            std::vector<VkSemaphore> wait_semaphores;
            std::vector<VkSemaphore> signal_semaphores;

            for (const auto& submit_iter : altered_submits)
            {
                // Shallow copy with filtered copy of pWaitSemaphores for submission info with imported semaphores.
                VkSubmitInfo& modified_submit_info = modified_submit_infos[submit_iter.first];
                auto          semaphore_iter       = submit_iter.second.begin();

                for (uint32_t i = 0; i < modified_submit_info.waitSemaphoreCount; ++i)
                {
                    VkSemaphore semaphore = modified_submit_info.pWaitSemaphores[i];

                    if ((semaphore_iter == submit_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        wait_semaphores.push_back(semaphore);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                for (uint32_t i = 0; i < modified_submit_info.signalSemaphoreCount; ++i)
                {
                    VkSemaphore semaphore = modified_submit_info.pSignalSemaphores[i];

                    if ((semaphore_iter == submit_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        signal_semaphores.push_back(semaphore);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                modified_submit_info.waitSemaphoreCount   = static_cast<uint32_t>(wait_semaphores.size());
                modified_submit_info.pWaitSemaphores      = wait_semaphores.data();
                modified_submit_info.signalSemaphoreCount = static_cast<uint32_t>(signal_semaphores.size());
                modified_submit_info.pSignalSemaphores    = signal_semaphores.data();
            }

            result = GetDeviceTable(device)->QueueSubmit(queue_info->handle,
                                                         static_cast<uint32_t>(modified_submit_infos.size()),
                                                         modified_submit_infos.data(),
                                                         fence);
        }
    }

    GetDeviceTable(queue_info->handle)->QueueWaitIdle(queue_info->handle);

    // Fetch data from buffers used in indirect commands
    if (has_indirect)
    {
        assert(submission_fence != VK_NULL_HANDLE);

        GetDeviceTable(device)->WaitForFences(device, 1, &submission_fence, VK_TRUE, UINT64_MAX);

        for (auto command_buffer : command->command_buffers)
        {
            for (auto command : command_buffer->indirect_commands)
            {
                command->FetchParameters();
            }
        }
    }

    EmplaceSerialzedCommand(std::move(command));

    return result;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideQueueWaitIdle(const ApiCallInfo& call_info,
                                                                 VkResult           original_result,
                                                                 QueueInfo*         queue)
{
    std::unique_ptr<QueueWaitIdleInfo> command =
        std::make_unique<QueueWaitIdleInfo>(call_info.index, SERIALIZED_CMD_QUEUE_WAIT_IDLE);

    command->queue = queue;

    EmplaceSerialzedCommand(std::move(command));

    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideResetFences(const ApiCallInfo&             call_info,
                                                               VkResult                       returnValue,
                                                               DeviceInfo*                    device_info,
                                                               uint32_t                       fenceCount,
                                                               HandlePointerDecoder<VkFence>* pFences)
{
    std::unique_ptr<ResetFencesInfo> command =
        std::make_unique<ResetFencesInfo>(call_info.index, SERIALIZED_CMD_RESET_FENCES);

    const format::HandleId* fence_handles = pFences->GetPointer();
    assert(pFences->GetLength() == fenceCount);
    for (size_t i = 0; i < pFences->GetLength(); ++i)
    {
        command->fences.push_back(GetObjectInfoTable().GetFenceInfo(fence_handles[i]));
    }

    EmplaceSerialzedCommand(std::move(command));

    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideWaitForFences(const ApiCallInfo&                   call_info,
                                                                 VkResult                             original_result,
                                                                 const DeviceInfo*                    device_info,
                                                                 uint32_t                             fenceCount,
                                                                 const HandlePointerDecoder<VkFence>* pFences,
                                                                 VkBool32                             waitAll,
                                                                 uint64_t                             timeout)
{
    std::unique_ptr<WaitForFencesInfo> command =
        std::make_unique<WaitForFencesInfo>(call_info.index, SERIALIZED_CMD_WAIT_FOR_FENCES);

    const format::HandleId* fence_handles = pFences->GetPointer();
    assert(pFences->GetLength() == fenceCount);
    for (size_t i = 0; i < pFences->GetLength(); ++i)
    {
        command->fences.push_back(GetObjectInfoTable().GetFenceInfo(fence_handles[i]));
    }

    command->device  = device_info;
    command->timeout = timeout;
    command->waitAll = waitAll;

    EmplaceSerialzedCommand(std::move(command));

    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideSetEvent(const ApiCallInfo& call_info,
                                                            VkResult           original_result,
                                                            const DeviceInfo*  device_info,
                                                            const EventInfo*   event_info)
{
    std::unique_ptr<SetEventInfo> command = std::make_unique<SetEventInfo>(call_info.index, SERIALIZED_CMD_SET_EVENT);

    command->device = device_info;
    command->event  = event_info;

    EmplaceSerialzedCommand(std::move(command));

    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideResetEvent(const ApiCallInfo& call_info,
                                                              VkResult           original_result,
                                                              const DeviceInfo*  device_info,
                                                              const EventInfo*   event_info)
{
    std::unique_ptr<ResetEventInfo> command =
        std::make_unique<ResetEventInfo>(call_info.index, SERIALIZED_CMD_RESET_EVENT);

    command->device = device_info;
    command->event  = event_info;

    EmplaceSerialzedCommand(std::move(command));

    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateXcbSurfaceKHR(
    PFN_vkCreateXcbSurfaceKHR                                      func,
    VkResult                                                       original_result,
    InstanceInfo*                                                  instance_info,
    const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                            surface)
{
    if (surface != nullptr)
    {
        auto surface_info                      = reinterpret_cast<SurfaceKHRInfo*>(surface->GetConsumerData(0));
        surface_info->surface_creation_skipped = true;
    }

    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateSwapchainKHR(
    PFN_vkCreateSwapchainKHR                                      func,
    VkResult                                                      original_result,
    DeviceInfo*                                                   device_info,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*                         pSwapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && !pCreateInfo->IsNull() && (pSwapchain != nullptr) &&
           !pSwapchain->IsNull() && (pSwapchain->GetHandlePointer() != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();
    GFXRECON_ASSERT(replay_create_info != nullptr);
    auto replay_swapchain = pSwapchain->GetHandlePointer();
    auto swapchain_info   = reinterpret_cast<SwapchainKHRInfo*>(pSwapchain->GetConsumerData(0));
    assert(swapchain_info != nullptr);

    GFXRECON_LOG_INFO("Skipping creation for swapchain (ID = %" PRIu64 "), which is backed by a disabled surface",
                      swapchain_info->capture_id);

    // Set fax handle data to find uncreated swapchain later.
    // Possible colision of handles from driver, but should not occur starting with uint max.
    static format::HandleId dummy_handle = std::numeric_limits<uint64_t>::max();
    (*replay_swapchain)                  = format::FromHandleId<VkSwapchainKHR>(dummy_handle);
    --dummy_handle;

    swapchain_info->surface    = VK_NULL_HANDLE;
    swapchain_info->surface_id = format::kNullHandleId;

    swapchain_info->image_flags        = replay_create_info->flags;
    swapchain_info->image_array_layers = replay_create_info->imageArrayLayers;
    swapchain_info->image_usage        = replay_create_info->imageUsage;
    swapchain_info->image_sharing_mode = replay_create_info->imageSharingMode;
    swapchain_info->device_info        = device_info;
    swapchain_info->width              = replay_create_info->imageExtent.width;
    swapchain_info->height             = replay_create_info->imageExtent.height;
    swapchain_info->format             = replay_create_info->imageFormat;

    if ((replay_create_info->imageSharingMode == VK_SHARING_MODE_CONCURRENT) &&
        (replay_create_info->queueFamilyIndexCount > 0) && (replay_create_info->pQueueFamilyIndices != nullptr))
    {
        swapchain_info->queue_family_indices.resize(replay_create_info->queueFamilyIndexCount);
        std::memcpy(swapchain_info->queue_family_indices.data(),
                    replay_create_info->pQueueFamilyIndices,
                    sizeof(uint32_t) * replay_create_info->queueFamilyIndexCount);
    }
    else
    {
        swapchain_info->queue_family_indices.clear();
        swapchain_info->queue_family_indices.emplace_back(0);
    }

    swapchain_info->surface    = replay_create_info->surface;
    swapchain_info->surface_id = pCreateInfo->GetMetaStructPointer()->surface;

    return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideDestroySwapchainKHR(
    PFN_vkDestroySwapchainKHR                                  func,
    DeviceInfo*                                                device_info,
    SwapchainKHRInfo*                                          swapchain_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Delete backed images of dummy swapchain.
    assert((swapchain_info != nullptr) && (swapchain_info->surface == VK_NULL_HANDLE));
}

VkResult
VulkanFrameInspectorConsumerBase::OverrideGetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR    func,
                                                                VkResult                       original_result,
                                                                const DeviceInfo*              device_info,
                                                                SwapchainKHRInfo*              swapchain_info,
                                                                PointerDecoder<uint32_t>*      pSwapchainImageCount,
                                                                HandlePointerDecoder<VkImage>* pSwapchainImages)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (swapchain_info != nullptr) && (pSwapchainImageCount != nullptr) &&
           !pSwapchainImageCount->IsNull() && (pSwapchainImages != nullptr));

    VkResult result              = original_result;
    auto     replay_image_count  = pSwapchainImageCount->GetOutputPointer();
    auto     replay_images       = pSwapchainImages->GetHandlePointer();
    uint32_t capture_image_count = *pSwapchainImageCount->GetPointer();

    // Handle if swapchain was never created due to surface-index being skipped
    assert(swapchain_info->surface == VK_NULL_HANDLE);
    if (replay_images == nullptr)
    {
        // Set the image count from data saved in trace file.
        (*replay_image_count) = capture_image_count;
    }
    else
    {
        // Create an image for the null swapchain.  Based on vkspec.html#swapchain-wsi-image-create-info.
        VkImageCreateInfo image_create_info     = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
        image_create_info.pNext                 = nullptr;
        image_create_info.flags                 = 0;
        image_create_info.imageType             = VK_IMAGE_TYPE_2D;
        image_create_info.format                = swapchain_info->format;
        image_create_info.extent                = { swapchain_info->width, swapchain_info->height, 1 };
        image_create_info.mipLevels             = 1;
        image_create_info.arrayLayers           = swapchain_info->image_array_layers;
        image_create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
        image_create_info.tiling                = VK_IMAGE_TILING_OPTIMAL;
        image_create_info.usage                 = swapchain_info->image_usage;
        image_create_info.sharingMode           = swapchain_info->image_sharing_mode;
        image_create_info.queueFamilyIndexCount = static_cast<uint32_t>(swapchain_info->queue_family_indices.size());
        image_create_info.pQueueFamilyIndices   = swapchain_info->queue_family_indices.data();
        image_create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

        if ((swapchain_info->image_flags & VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR) ==
            VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR)
        {
            image_create_info.flags |= VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT;
        }

        GFXRECON_LOG_INFO("Creating %u images of %ux%u to back dummy swapchain (ID = %" PRIu64 ")",
                          capture_image_count,
                          image_create_info.extent.width,
                          image_create_info.extent.height,
                          swapchain_info->capture_id);

        for (uint32_t i = 0; i < capture_image_count; ++i)
        {
            VkImage*   replay_image = &(replay_images[i]);
            ImageInfo* image_info   = reinterpret_cast<ImageInfo*>(pSwapchainImages->GetConsumerData(i));
            assert(image_info != nullptr);

            result = CreateSwapchainImage(device_info, &image_create_info, replay_image, image_info);

            if ((result != VK_SUCCESS) || (replay_image == VK_NULL_HANDLE))
            {
                GFXRECON_LOG_ERROR("Unable to create backing images for dummy swapchain (ID = %" PRIu64 ")",
                                   swapchain_info->capture_id);
                break;
            }

            image_info->is_swapchain_image = true;

            // Create a copy of the image info to use for image cleanup when the swapchain is destroyed.
            swapchain_info->image_infos.push_back(*image_info);
        }
    }

    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideAcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                                                       VkResult                  original_result,
                                                                       const DeviceInfo*         device_info,
                                                                       SwapchainKHRInfo*         swapchain_info,
                                                                       uint64_t                  timeout,
                                                                       SemaphoreInfo*            semaphore_info,
                                                                       FenceInfo*                fence_info,
                                                                       PointerDecoder<uint32_t>* pImageIndex)
{
    assert(swapchain_info->surface == VK_NULL_HANDLE);

    // Track semphore and fence objects as shadow objects so that they can be ignored when they would have been
    // unsignaled (waited on).
    if (semaphore_info != nullptr)
    {
        semaphore_info->shadow_signaled = true;
        shadow_semaphores_.insert(semaphore_info->handle);
    }

    if (fence_info != nullptr)
    {
        fence_info->shadow_signaled = true;
        shadow_fences_.insert(fence_info->handle);
    }

    return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideUpdateDescriptorSets(
    const ApiCallInfo&                                  call_info,
    DeviceInfo*                                         device_info,
    uint32_t                                            descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                            descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies)
{
    std::unique_ptr<UpdateDescriptorSetsInfo> command =
        std::make_unique<UpdateDescriptorSetsInfo>(call_info.index, SERIALIZED_CMD_UPDATE_DESCRIPTOR_SETS);

    const auto meta_writes = pDescriptorWrites->GetMetaStructPointer();
    const auto writes      = pDescriptorWrites->GetPointer();
    assert(pDescriptorWrites->GetLength() == descriptorWriteCount);
    for (uint32_t i = 0; i < descriptorWriteCount; ++i)
    {
        WriteDescriptorSetInfo write{ GetObjectInfoTable().GetDescriptorSetInfo(meta_writes[i].dstSet),
                                      writes[i].dstBinding,
                                      writes[i].dstArrayElement,
                                      writes[i].descriptorCount,
                                      writes[i].descriptorType };

        const auto meta_image_writes = meta_writes[i].pImageInfo->GetMetaStructPointer();
        const auto image_writes      = meta_writes[i].pImageInfo->GetPointer();
        for (uint32_t img = 0; img < meta_writes[i].pImageInfo->GetLength(); ++img)
        {
            DescriptorImageInfo image_write = { GetObjectInfoTable().GetSamplerInfo(meta_image_writes[img].sampler),
                                                GetObjectInfoTable().GetImageViewInfo(meta_image_writes[img].imageView),
                                                image_writes[img].imageLayout };
            write.image_info.push_back(std::move(image_write));
        }

        const auto meta_buffer_writes = meta_writes[i].pBufferInfo->GetMetaStructPointer();
        const auto buffer_writes      = meta_writes[i].pBufferInfo->GetPointer();
        for (uint32_t buf = 0; buf < meta_writes[i].pBufferInfo->GetLength(); ++buf)
        {
            DescriptorBufferInfo buffer_write = { GetObjectInfoTable().GetBufferInfo(meta_buffer_writes[buf].buffer),
                                                  buffer_writes[buf].offset,
                                                  buffer_writes[buf].range };

            write.buffer_info.push_back(std::move(buffer_write));
        }

        command->writes.push_back(std::move(write));
    }

    EmplaceSerialzedCommand(std::move(command));

    const auto copies = pDescriptorCopies->GetPointer();

    GetDeviceTable(device_info->handle)
        ->UpdateDescriptorSets(device_info->handle, descriptorWriteCount, writes, descriptorCopyCount, copies);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
