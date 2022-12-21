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
#include "decode/vulkan_handle_mapping_util.h"

#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "decode/vulkan_feature_util.h"
#include "decode/vulkan_frame_inspector_consumer_base.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "decode/vulkan_object_cleanup_util.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "graphics/vulkan_util.h"
#include "util/defines.h"

#include <vector>
#include <algorithm>

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

VulkanFrameInspectorConsumerBase::~VulkanFrameInspectorConsumerBase()
{
    // Idle all devices before destroying other resources.
    WaitDevicesIdle();

    object_cleanup::FreeAllLiveObjects(
        &object_info_table_,
        false,
        true,
        [this](const void* handle) { return GetInstanceTable(handle); },
        [this](const void* handle) { return GetDeviceTable(handle); },
        nullptr);

    // Finally destroy vkInstances
    object_cleanup::FreeAllLiveInstances(
        &object_info_table_,
        false,
        true,
        [this](const void* handle) { return GetInstanceTable(handle); },
        [this](const void* handle) { return GetDeviceTable(handle); });
}

void VulkanFrameInspectorConsumerBase::Reset()
{
    DeletePendingObjects();
    commands_.clear();
}

void VulkanFrameInspectorConsumerBase::EmplaceSerialzedCommand(std::unique_ptr<SerializedCommands> command)
{
    auto result = commands_.emplace(command->index, std::move(command));
    if (!result.second)
    {
        GFXRECON_LOG_WARNING("Duplicate entry for command %" PRIu64, command->index);
    }
}

void VulkanFrameInspectorConsumerBase::ProcessFillMemoryCommand(
    format::CommandIndexType command_index, uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data)
{
    std::unique_ptr<GFXRCommandFillMemory> command = std::make_unique<GFXRCommandFillMemory>(command_index);

    command->data      = data;
    command->memory_id = memory_id;
    command->offset    = offset;
    command->size      = size;

    EmplaceSerialzedCommand(std::move(command));

    VulkanReplayBase::ProcessFillMemoryCommand(command_index, memory_id, offset, size, data);
}

void VulkanFrameInspectorConsumerBase::ProcessBeginResourceInitCommand(format::CommandIndexType command_index,
                                                                       format::HandleId         device_id,
                                                                       uint64_t                 max_resource_size,
                                                                       uint64_t                 max_copy_size)
{
    std::unique_ptr<GFXRCommandBeginResourceInitCommand> command =
        std::make_unique<GFXRCommandBeginResourceInitCommand>(command_index);

    command->device_id         = device_id;
    command->max_copy_size     = max_copy_size;
    command->max_resource_size = max_resource_size;

    EmplaceSerialzedCommand(std::move(command));

    VulkanReplayBase::ProcessBeginResourceInitCommand(command_index, device_id, max_resource_size, max_copy_size);
}

void VulkanFrameInspectorConsumerBase::ProcessEndResourceInitCommand(format::CommandIndexType command_index,
                                                                     format::HandleId         device_id)
{
    std::unique_ptr<GFXRCommandEndResourceInitCommand> command =
        std::make_unique<GFXRCommandEndResourceInitCommand>(command_index);

    command->device_id = device_id;

    EmplaceSerialzedCommand(std::move(command));

    VulkanReplayBase::ProcessEndResourceInitCommand(command_index, device_id);
}

void VulkanFrameInspectorConsumerBase::ProcessInitBufferCommand(format::CommandIndexType command_index,
                                                                format::HandleId         device_id,
                                                                format::HandleId         buffer_id,
                                                                uint64_t                 data_size,
                                                                const uint8_t*           data)
{
    std::unique_ptr<GFXRCommandInitBufferCommand> command =
        std::make_unique<GFXRCommandInitBufferCommand>(command_index);

    command->device_id = device_id;
    command->buffer_id = buffer_id;
    command->data_size = data_size;
    command->data.reset(new uint8_t[data_size]);
    util::platform::MemoryCopy(command->data.get(), data_size, data, data_size);

    EmplaceSerialzedCommand(std::move(command));

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
    std::unique_ptr<GFXRCommandInitImageCommand> command = std::make_unique<GFXRCommandInitImageCommand>(command_index);

    command->device_id   = device_id;
    command->image_id    = image_id;
    command->data_size   = data_size;
    command->aspect      = aspect;
    command->layout      = layout;
    command->level_sizes = level_sizes;
    command->data.reset(new uint8_t[data_size]);
    util::platform::MemoryCopy(command->data.get(), data_size, data, data_size);

    EmplaceSerialzedCommand(std::move(command));

    VulkanReplayBase::ProcessInitImageCommand(
        command_index, device_id, image_id, data_size, aspect, layout, level_sizes, data);
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateInstance(
    VkResult                                                   original_result,
    const StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*                          pInstance)

{
    if (loader_handle_ == nullptr)
    {
        InitializeLoader();
    }

    auto replay_create_info = pCreateInfo->GetPointer();
    auto replay_allocator   = pAllocator->GetPointer();
    auto replay_instance    = pInstance->GetHandlePointer();

    // Replace WSI extension in extension list.
    std::vector<const char*> filtered_extensions;
    VkInstanceCreateInfo     modified_create_info{};

    if (replay_create_info != nullptr)
    {
        if (replay_create_info->ppEnabledExtensionNames)
        {
            for (uint32_t i = 0; i < replay_create_info->enabledExtensionCount; ++i)
            {
                auto current_extension = replay_create_info->ppEnabledExtensionNames[i];
                filtered_extensions.push_back(current_extension);
            }

            PFN_vkEnumerateInstanceExtensionProperties instance_extension_proc =
                reinterpret_cast<PFN_vkEnumerateInstanceExtensionProperties>(
                    get_instance_proc_addr_(nullptr, "vkEnumerateInstanceExtensionProperties"));
            std::vector<VkExtensionProperties> properties;
            if (feature_util::GetInstanceExtensions(instance_extension_proc, &properties) == VK_SUCCESS)
            {
                if (options_.remove_unsupported_features)
                {
                    // Remove enabled extensions that are not available from the replay instance.
                    // Proc addresses that can't be used in layers so are not generated into shared dispatch table, but
                    // are needed in the replay application.
                    feature_util::RemoveUnsupportedExtensions(properties, &filtered_extensions);
                }
                else
                {
                    // Check that the requested extensions are present and print warnings if not.
                    for (auto extensionIter = filtered_extensions.begin(); extensionIter != filtered_extensions.end();
                         ++extensionIter)
                    {
                        if (!feature_util::IsSupportedExtension(properties, *extensionIter))
                        {
                            GFXRECON_LOG_WARNING("Extension %s, is not supported by the replay device.",
                                                 *extensionIter);
                        }
                    }
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("Failed to get instance extensions. Cannot perform sanity checks or filters for "
                                     "extension availability.");
            }
        }

        modified_create_info                         = (*replay_create_info);
        modified_create_info.enabledExtensionCount   = static_cast<uint32_t>(filtered_extensions.size());
        modified_create_info.ppEnabledExtensionNames = filtered_extensions.data();
    }
    else
    {
        GFXRECON_LOG_WARNING("The vkCreateInstance parameter pCreateInfo is NULL.");
    }

    // Disable layers; any layers needed for replay should be enabled for the replay app with the VK_INSTANCE_LAYERS
    // environment variable or debug.vulkan.layers Android property.
    if (modified_create_info.enabledLayerCount > 0)
    {
        GFXRECON_LOG_INFO(
            "Replay has removed the following layers from VkInstanceCreateInfo when calling vkCreateInstance:");

        for (uint32_t i = 0; i < modified_create_info.enabledLayerCount; ++i)
        {
            GFXRECON_LOG_INFO("\t%s", modified_create_info.ppEnabledLayerNames[i]);
        }

        modified_create_info.enabledLayerCount   = 0;
        modified_create_info.ppEnabledLayerNames = nullptr;
    }

    VkResult result = create_instance_proc_(&modified_create_info, replay_allocator, replay_instance);

    if (result == VK_SUCCESS)
    {
        AddInstanceTable(*replay_instance);

        if (modified_create_info.pApplicationInfo != nullptr)
        {
            auto instance_info = reinterpret_cast<InstanceInfo*>(pInstance->GetConsumerData(0));
            assert(instance_info != nullptr);

            instance_info->api_version = modified_create_info.pApplicationInfo->apiVersion;
            instance_info->enabled_extensions.assign(modified_create_info.ppEnabledExtensionNames,
                                                     modified_create_info.ppEnabledExtensionNames +
                                                         modified_create_info.enabledExtensionCount);
        }
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

    command_buffer_info->Reset();

    const VkCommandBufferBeginInfo* in_pBeginInfo = pBeginInfo->GetPointer();
    MapStructHandles(pBeginInfo->GetMetaStructPointer(), GetObjectInfoTable());

    return GetDeviceTable(command_buffer_info->handle)->BeginCommandBuffer(command_buffer_info->handle, in_pBeginInfo);
}

VkResult VulkanFrameInspectorConsumerBase::OverrideEndCommandBuffer(const ApiCallInfo& call_info,
                                                                    VkResult           original_result,
                                                                    CommandBufferInfo* command_buffer_info)
{
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
        std::make_unique<VulkanCommandBindPipelineInfo>(call_info.index);

    command->pipeline          = pipeline_info->handle;
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
        std::make_unique<VulkanCommandSetViewportInfo>(call_info.index);

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
        std::make_unique<VulkanCommandSetScissorInfo>(call_info.index);

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
        std::make_unique<VulkanCommandBindDescriptorSetsInfo>(call_info.index);

    const VkDescriptorSet* desc_set_handles = pDescriptorSets->GetHandlePointer();
    assert(pDescriptorSets->GetHandleLength() == descriptorSetCount);
    for (size_t i = 0; i < pDescriptorSets->GetHandleLength(); ++i)
    {
        command->descriptor_sets.push_back(desc_set_handles[i]);
    }

    const uint32_t* dynamic_offsets = pDynamicOffsets->GetPointer();
    for (uint32_t i = 0; i < dynamicOffsetCount; ++i)
    {
        command->dynamic_offsets.push_back(dynamic_offsets[i]);
    }

    command->pipelineBindPoint = pipelineBindPoint;
    command->pipeline_layout   = pipeline_layout_info->handle;
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
        std::make_unique<VulkanCommandBindIndexBufferInfo>(call_info.index);

    command->buffer    = buffer_info->handle;
    command->offset    = offset;
    command->indexType = indexType;

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
        std::make_unique<VulkanCommandBindVertexBuffersInfo>(call_info.index);

    const VkBuffer*     buffers     = pBuffers->GetHandlePointer();
    const VkDeviceSize* in_pOffsets = pOffsets->GetPointer();
    assert(pBuffers->GetHandleLength() == bindingCount);
    for (uint32_t i = 0; i < bindingCount; ++i)
    {
        command->buffers.push_back(buffers[i]);
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
    std::unique_ptr<VulkanCommandDrawInfo> command = std::make_unique<VulkanCommandDrawInfo>(call_info.index);

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
    assert(command_buffer_info->parent_id == buffer_info->parent_id);

    auto device_info = GetObjectInfoTable().GetDeviceInfo(command_buffer_info->parent_id);

    PhysicalDeviceInfo* phys_dev_info = GetObjectInfoTable().GetPhysicalDeviceInfo(device_info->parent_id);

    std::unique_ptr<VulkanCommandDrawIndirectInfo> command =
        std::make_unique<VulkanCommandDrawIndirectInfo>(call_info.index,
                                                        device_info,
                                                        GetDeviceTable(device_info->handle),
                                                        GetInstanceTable(phys_dev_info->handle),
                                                        buffer_info);
    command->Initialize(command_buffer_info, phys_dev_info, offset, drawCount, stride);

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
        std::make_unique<VulkanCommandCopyBufferToImageInfo>(call_info.index);

    command->srcBuffer      = src_buffer->handle;
    command->dstImage       = dst_image->handle;
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
        std::make_unique<VulkanCommandPipelineBarrierInfo>(call_info.index);

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
        std::make_unique<VulkanCommandBeginRenderPassInfo>(call_info.index);

    const VkRenderPassBeginInfo* in_pRenderPassBegin = pRenderPassBegin->GetPointer();
    // MapStructHandles(pRenderPassBegin->GetMetaStructPointer(), GetObjectInfoTable());

    command->renderpass  = pRenderPassBegin->GetPointer()->renderPass;
    command->framebuffer = pRenderPassBegin->GetPointer()->framebuffer;
    command->renderArea  = *pRenderPassBegin->GetMetaStructPointer()->renderArea->decoded_value;
    command->contents    = contents;

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
        std::make_unique<VulkanCommandEndRenderPassInfo>(call_info.index);

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

VkResult
VulkanFrameInspectorConsumerBase::OverrideQueueSubmit(const ApiCallInfo&                                call_info,
                                                      VkResult                                          original_result,
                                                      const QueueInfo*                                  queue_info,
                                                      uint32_t                                          submitCount,
                                                      const StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                                      const FenceInfo*                                  fence_info)
{
    std::unique_ptr<QueueSubmitInfo> command = std::make_unique<QueueSubmitInfo>(call_info.index);
    command->queue                           = queue_info->capture_id;
    const VkSubmitInfo* submit_infos         = pSubmits->GetPointer();
    assert(submitCount == 0 || submit_infos != nullptr);
    bool     has_indirect = false;
    VkResult result       = VK_SUCCESS;
    VkFence  fence        = VK_NULL_HANDLE;

    if (fence_info != nullptr)
    {
        fence = fence_info->handle;
    }

    auto submit_info_data = pSubmits->GetMetaStructPointer();
    if (submit_info_data != nullptr)
    {
        for (uint32_t i = 0; i < submitCount; ++i)
        {
            // Get command buffers
            const format::HandleId* command_buffer_ids = submit_info_data[i].pCommandBuffers.GetPointer();
            if (command_buffer_ids != nullptr)
            {
                for (uint32_t c = 0; c < submit_info_data[i].pCommandBuffers.GetLength(); ++c)
                {
                    command->command_buffers.push_back(command_buffer_ids[c]);

                    auto cmd_buffer_info = GetObjectInfoTable().GetCommandBufferInfo(command_buffer_ids[c]);
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
                command->signal_semaphores.push_back(signal_semaphore_ids[s]);
            }

            // Get wait sempahores
            const format::HandleId* wait_semaphore_ids = submit_info_data[i].pWaitSemaphores.GetPointer();
            for (uint32_t s = 0; s < submit_info_data[i].pWaitSemaphores.GetLength(); ++s)
            {
                command->wait_semaphores.push_back(wait_semaphore_ids[s]);
                command->wait_dst_stage_mask.push_back(submit_infos[i].pWaitDstStageMask[s]);
            }
        }
    }

    command->fence = fence_info->capture_id;

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

    if (!submit_infos->waitSemaphoreCount && !submit_infos->signalSemaphoreCount)
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

                    for (const auto& sem_info : removed_semaphores)
                    {
                        command->signal_semaphores.erase(std::remove(command->signal_semaphores.begin(),
                                                                     command->signal_semaphores.end(),
                                                                     sem_info->capture_id),
                                                         command->signal_semaphores.end());

                        command->wait_semaphores.erase(std::remove(command->wait_semaphores.begin(),
                                                                   command->wait_semaphores.end(),
                                                                   sem_info->capture_id),
                                                       command->wait_semaphores.end());
                    }
                }
            }
        }

        if (altered_submits.empty())
        {
            result = GetDeviceTable(device)->QueueSubmit(queue_info->handle, submitCount, submit_infos, fence);
        }
        else
        {
            // Make shallow copies of the VkSubmit info structures and change pWaitSemaphores to reference a copy of
            // the original semaphore array with the imported semaphores omitted.
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
            auto command_buffer_info = object_info_table_.GetCommandBufferInfo(command_buffer);
            for (auto command : command_buffer_info->indirect_commands)
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
    std::unique_ptr<QueueWaitIdleInfo> command = std::make_unique<QueueWaitIdleInfo>(call_info.index);

    command->queue = queue->capture_id;

    EmplaceSerialzedCommand(std::move(command));

    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideResetFences(const ApiCallInfo&             call_info,
                                                               VkResult                       returnValue,
                                                               DeviceInfo*                    device_info,
                                                               uint32_t                       fenceCount,
                                                               HandlePointerDecoder<VkFence>* pFences)
{
    std::unique_ptr<ResetFencesInfo> command = std::make_unique<ResetFencesInfo>(call_info.index);

    const format::HandleId* fence_handles = pFences->GetPointer();
    assert(pFences->GetLength() == fenceCount);
    for (size_t i = 0; i < pFences->GetLength(); ++i)
    {
        command->fences.push_back(fence_handles[i]);
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
    std::unique_ptr<WaitForFencesInfo> command = std::make_unique<WaitForFencesInfo>(call_info.index);

    const format::HandleId* fence_handles = pFences->GetPointer();
    assert(pFences->GetLength() == fenceCount);
    for (size_t i = 0; i < pFences->GetLength(); ++i)
    {
        command->fences.push_back(fence_handles[i]);
    }

    command->device  = device_info->capture_id;
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
    std::unique_ptr<SetEventInfo> command = std::make_unique<SetEventInfo>(call_info.index);

    command->device = device_info->capture_id;
    command->event  = event_info->capture_id;

    EmplaceSerialzedCommand(std::move(command));

    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideResetEvent(const ApiCallInfo& call_info,
                                                              VkResult           original_result,
                                                              const DeviceInfo*  device_info,
                                                              const EventInfo*   event_info)
{
    std::unique_ptr<ResetEventInfo> command = std::make_unique<ResetEventInfo>(call_info.index);

    command->device = device_info->capture_id;
    command->event  = event_info->capture_id;

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
    std::unique_ptr<UpdateDescriptorSetsInfo> command = std::make_unique<UpdateDescriptorSetsInfo>(call_info.index);

    const auto meta_writes = pDescriptorWrites->GetMetaStructPointer();
    const auto writes      = pDescriptorWrites->GetPointer();
    assert(pDescriptorWrites->GetLength() == descriptorWriteCount);
    for (uint32_t i = 0; i < descriptorWriteCount; ++i)
    {
        WriteDescriptorSetInfo write{ meta_writes[i].dstSet,
                                      writes[i].dstBinding,
                                      writes[i].dstArrayElement,
                                      writes[i].descriptorCount,
                                      writes[i].descriptorType };

        const auto meta_image_writes = meta_writes[i].pImageInfo->GetMetaStructPointer();
        const auto image_writes      = meta_writes[i].pImageInfo->GetPointer();
        for (uint32_t img = 0; img < meta_writes[i].pImageInfo->GetLength(); ++img)
        {
            DescriptorImageInfo image_write = { meta_image_writes[img].sampler,
                                                meta_image_writes[img].imageView,
                                                image_writes[img].imageLayout };
            write.image_info.push_back(std::move(image_write));
        }

        const auto meta_buffer_writes = meta_writes[i].pBufferInfo->GetMetaStructPointer();
        const auto buffer_writes      = meta_writes[i].pBufferInfo->GetPointer();
        for (uint32_t buf = 0; buf < meta_writes[i].pBufferInfo->GetLength(); ++buf)
        {
            DescriptorBufferInfo buffer_write = { meta_buffer_writes[buf].buffer,
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

void VulkanFrameInspectorConsumerBase::OverrideDestroyDevice(
    PFN_vkDestroyDevice                                        func,
    const DeviceInfo*                                          device_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    pending_objects.devices.push_back(std::make_pair(device_info, *pAllocator));
}

void VulkanFrameInspectorConsumerBase::OverrideDestroyInstance(
    const ApiCallInfo&                                   call_info,
    InstanceInfo*                                        instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    pending_objects.instances.push_back(std::make_pair(instance, *pAllocator));
}

void VulkanFrameInspectorConsumerBase::OverrideFreeCommandBuffers(
    const ApiCallInfo&                     call_info,
    DeviceInfo*                            device,
    CommandPoolInfo*                       commandPool,
    uint32_t                               commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers)
{
    assert(pCommandBuffers->GetLength() == commandBufferCount);

    const format::HandleId* cmd_buf_handles = pCommandBuffers->GetPointer();
    for (uint32_t i = 0; i < commandBufferCount; ++i)
    {
        pending_objects.commandBuffers.push_back(GetObjectInfoTable().GetCommandBufferInfo(cmd_buf_handles[i]));
    }
}

void VulkanFrameInspectorConsumerBase::OverrideDestroyCommandPool(
    const ApiCallInfo&                                   call_info,
    DeviceInfo*                                          device,
    CommandPoolInfo*                                     commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    pending_objects.commandPools.push_back(std::make_pair(commandPool, *pAllocator));
}

void VulkanFrameInspectorConsumerBase::DeletePendingObjects()
{
    for (auto obj : pending_objects.accelerationStructureKHRs)
    {}
    pending_objects.accelerationStructureKHRs.clear();

    for (auto obj : pending_objects.accelerationStructureNVs)
    {}
    pending_objects.accelerationStructureNVs.clear();

    for (auto obj : pending_objects.buffers)
    {}
    pending_objects.buffers.clear();

    for (auto obj : pending_objects.bufferViews)
    {}
    pending_objects.bufferViews.clear();

    for (auto obj : pending_objects.commandBuffers)
    {
        CommandPoolInfo* pool        = GetObjectInfoTable().GetCommandPoolInfo(obj->pool_id);
        DeviceInfo*      device_info = GetObjectInfoTable().GetDeviceInfo(pool->parent_id);
        VkDevice         device      = GetObjectInfoTable().GetDeviceInfo(pool->parent_id)->handle;
        VkCommandBuffer  cmd_buf     = obj->handle;

        GetDeviceTable(device)->FreeCommandBuffers(device, pool->handle, 1, &cmd_buf);
        handle_mapping::RemovePoolObjectHandle<CommandPoolInfo>(pool->capture_id,
                                                                obj->capture_id,
                                                                &object_info_table_,
                                                                &VulkanObjectInfoTable::GetCommandPoolInfo,
                                                                &VulkanObjectInfoTable::RemoveCommandBufferInfo);
    }
    pending_objects.commandBuffers.clear();

    for (auto obj : pending_objects.commandPools)
    {
        CommandPoolInfo* pool   = GetObjectInfoTable().GetCommandPoolInfo(obj.first->capture_id);
        VkDevice         device = GetObjectInfoTable().GetDeviceInfo(pool->parent_id)->handle;

        GetDeviceTable(device)->DestroyCommandPool(device, pool->handle, obj.second.GetPointer());
        RemovePoolHandle<CommandPoolInfo>(pool->capture_id,
                                          &VulkanObjectInfoTable::GetCommandPoolInfo,
                                          &VulkanObjectInfoTable::RemoveCommandPoolInfo,
                                          &VulkanObjectInfoTable::RemoveCommandBufferInfo);
    }
    pending_objects.commandPools.clear();

    for (auto obj : pending_objects.deferredOperationKHRs)
    {}
    pending_objects.deferredOperationKHRs.clear();

    for (auto obj : pending_objects.descriptorPools)
    {}
    pending_objects.descriptorPools.clear();

    for (auto obj : pending_objects.descriptorSets)
    {}
    pending_objects.descriptorSets.clear();

    for (auto obj : pending_objects.descriptorSetLayouts)
    {}
    pending_objects.descriptorSetLayouts.clear();

    for (auto obj : pending_objects.descriptorUpdateTemplates)
    {}
    pending_objects.descriptorUpdateTemplates.clear();

    for (auto obj : pending_objects.deviceMemorys)
    {}
    pending_objects.deviceMemorys.clear();

    for (auto obj : pending_objects.displayKHRs)
    {}
    pending_objects.displayKHRs.clear();

    for (auto obj : pending_objects.displayModeKHRs)
    {}
    pending_objects.displayModeKHRs.clear();

    for (auto obj : pending_objects.events)
    {}
    pending_objects.events.clear();

    for (auto obj : pending_objects.fences)
    {}
    pending_objects.fences.clear();

    for (auto obj : pending_objects.framebuffers)
    {}
    pending_objects.framebuffers.clear();

    for (auto obj : pending_objects.images)
    {}
    pending_objects.images.clear();

    for (auto obj : pending_objects.imageViews)
    {}
    pending_objects.imageViews.clear();

    for (auto obj : pending_objects.indirectCommandsLayoutNVs)
    {}
    pending_objects.indirectCommandsLayoutNVs.clear();

    for (auto obj : pending_objects.micromapEXTs)
    {}
    pending_objects.micromapEXTs.clear();

    for (auto obj : pending_objects.opticalFlowSessionNVs)
    {}
    pending_objects.opticalFlowSessionNVs.clear();

    for (auto obj : pending_objects.performanceConfigurationINTELs)
    {}
    pending_objects.performanceConfigurationINTELs.clear();

    for (auto obj : pending_objects.physicalDevices)
    {}
    pending_objects.physicalDevices.clear();

    for (auto obj : pending_objects.pipelines)
    {}
    pending_objects.pipelines.clear();

    for (auto obj : pending_objects.pipelineCaches)
    {}
    pending_objects.pipelineCaches.clear();

    for (auto obj : pending_objects.pipelineLayouts)
    {}
    pending_objects.pipelineLayouts.clear();

    for (auto obj : pending_objects.privateDataSlots)
    {}
    pending_objects.privateDataSlots.clear();

    for (auto obj : pending_objects.queryPools)
    {}
    pending_objects.queryPools.clear();

    for (auto obj : pending_objects.queues)
    {}
    pending_objects.queues.clear();

    for (auto obj : pending_objects.renderPasss)
    {}
    pending_objects.renderPasss.clear();

    for (auto obj : pending_objects.samplers)
    {}
    pending_objects.samplers.clear();

    for (auto obj : pending_objects.samplerYcbcrConversions)
    {}
    pending_objects.samplerYcbcrConversions.clear();

    for (auto obj : pending_objects.semaphores)
    {}
    pending_objects.semaphores.clear();

    for (auto obj : pending_objects.shaderModules)
    {}
    pending_objects.shaderModules.clear();

    for (auto obj : pending_objects.surfaceKHRs)
    {}
    pending_objects.surfaceKHRs.clear();

    for (auto obj : pending_objects.swapchainKHRs)
    {}
    pending_objects.swapchainKHRs.clear();

    for (auto obj : pending_objects.validationCacheEXTs)
    {}
    pending_objects.validationCacheEXTs.clear();

    for (auto obj : pending_objects.devices)
    {
        const DeviceInfo* dev = obj.first;
        VulkanReplayBase::OverrideDestroyDevice(GetDeviceTable(dev->handle)->DestroyDevice, obj.first, &obj.second);
        RemoveHandle(dev->capture_id, &VulkanObjectInfoTable::RemoveDeviceInfo);
    }
    pending_objects.devices.clear();

    for (auto obj : pending_objects.instances)
    {
        const InstanceInfo* instance = obj.first;

        GetInstanceTable(instance->handle)->DestroyInstance(instance->handle, obj.second.GetPointer());
        RemoveHandle(instance->capture_id, &VulkanObjectInfoTable::RemoveInstanceInfo);
    }
    pending_objects.instances.clear();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
