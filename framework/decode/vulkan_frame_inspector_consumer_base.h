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

#ifndef GFXRECON_GENERATED_VULKAN_FRAME_INSPECTOR_CONSUMER_BASE_H
#define GFXRECON_GENERATED_VULKAN_FRAME_INSPECTOR_CONSUMER_BASE_H

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_object_info_table.h"
#include "util/defines.h"
#include "decode/vulkan_replay_base.h"
#include "application/application.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_frame_inspector_object_info.h"
#include "decode/vulkan_frame_inspector_serialized_commands.h"
#include "decode/vulkan_frame_inspector_indirect_commands_info.h"

#include "vulkan/vulkan.h"
#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanFrameInspectorConsumerBase : public VulkanReplayBase
{
  public:
    VulkanFrameInspectorConsumerBase(std::shared_ptr<application::Application> application,
                                     const VulkanReplayOptions&                options) :
        VulkanReplayBase(options)
    {}

    virtual ~VulkanFrameInspectorConsumerBase() override;

    virtual void ProcessFillMemoryCommand(format::CommandIndexType command_index,
                                          uint64_t                 memory_id,
                                          uint64_t                 offset,
                                          uint64_t                 size,
                                          const uint8_t*           data) override;

    virtual void ProcessBeginResourceInitCommand(format::CommandIndexType command_index,
                                                 format::HandleId         device_id,
                                                 uint64_t                 max_resource_size,
                                                 uint64_t                 max_copy_size) override;

    virtual void ProcessEndResourceInitCommand(format::CommandIndexType command_index,
                                               format::HandleId         device_id) override;

    virtual void ProcessInitBufferCommand(format::CommandIndexType command_index,
                                          format::HandleId         device_id,
                                          format::HandleId         buffer_id,
                                          uint64_t                 data_size,
                                          const uint8_t*           data) override;

    virtual void ProcessInitImageCommand(format::CommandIndexType     command_index,
                                         format::HandleId             device_id,
                                         format::HandleId             image_id,
                                         uint64_t                     data_size,
                                         uint32_t                     aspect,
                                         uint32_t                     layout,
                                         const std::vector<uint64_t>& level_sizes,
                                         const uint8_t*               data) override;

    VkResult OverrideCreateInstance(VkResult                                                   original_result,
                                    const StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                    HandlePointerDecoder<VkInstance>*                          pInstance);

    VkResult OverrideQueueSubmit(const ApiCallInfo&                                call_info,
                                 VkResult                                          original_result,
                                 const QueueInfo*                                  queue_info,
                                 uint32_t                                          submitCount,
                                 const StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                 const FenceInfo*                                  fence_info);

    VkResult OverrideQueueWaitIdle(const ApiCallInfo& call_info, VkResult original_result, QueueInfo* queue);

    VkResult OverrideResetCommandPool(const ApiCallInfo&      call_info,
                                      VkResult                returnValue,
                                      DeviceInfo*             device_info,
                                      CommandPoolInfo*        commandPool_info,
                                      VkCommandPoolResetFlags flags);

    VkResult OverrideBeginCommandBuffer(const ApiCallInfo&                                      call_info,
                                        VkResult                                                original_result,
                                        CommandBufferInfo*                                      command_buffer_info,
                                        StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo);

    VkResult OverrideEndCommandBuffer(const ApiCallInfo& call_info,
                                      VkResult           original_result,
                                      CommandBufferInfo* command_buffer_info);

    VkResult OverrideResetCommandBuffer(const ApiCallInfo&        call_info,
                                        CommandBufferInfo*        command_buffer_info,
                                        VkCommandBufferResetFlags flags);

    void OverrideCmdBindPipeline(const ApiCallInfo&  call_info,
                                 CommandBufferInfo*  command_buffer_info,
                                 VkPipelineBindPoint pipelineBindPoint,
                                 const PipelineInfo* pipeline_info);

    void OverrideCmdSetViewport(const ApiCallInfo&                        call_info,
                                CommandBufferInfo*                        command_buffer_info,
                                uint32_t                                  firstViewport,
                                uint32_t                                  viewportCount,
                                StructPointerDecoder<Decoded_VkViewport>* pViewports);

    void OverrideCmdSetScissor(const ApiCallInfo&                      call_info,
                               CommandBufferInfo*                      command_buffer_info,
                               uint32_t                                firstScissor,
                               uint32_t                                scissorCount,
                               StructPointerDecoder<Decoded_VkRect2D>* pScissors);

    void OverrideCmdBindDescriptorSets(const ApiCallInfo&                     call_info,
                                       CommandBufferInfo*                     command_buffer_info,
                                       VkPipelineBindPoint                    pipelineBindPoint,
                                       const PipelineLayoutInfo*              pipeline_layout_info,
                                       uint32_t                               firstSet,
                                       uint32_t                               descriptorSetCount,
                                       HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets,
                                       uint32_t                               dynamicOffsetCount,
                                       PointerDecoder<uint32_t>*              pDynamicOffsets);

    void OverrideCmdBindIndexBuffer(const ApiCallInfo& call_info,
                                    CommandBufferInfo* command_buffer_info,
                                    const BufferInfo*  buffer_info,
                                    VkDeviceSize       offset,
                                    VkIndexType        indexType);

    void OverrideCmdBindVertexBuffers(const ApiCallInfo&              call_info,
                                      CommandBufferInfo*              command_buffer_info,
                                      uint32_t                        firstBinding,
                                      uint32_t                        bindingCount,
                                      HandlePointerDecoder<VkBuffer>* pBuffers,
                                      PointerDecoder<VkDeviceSize>*   pOffsets);

    void OverrideCmdDraw(const ApiCallInfo& call_info,
                         CommandBufferInfo* command_buffer_info,
                         uint32_t           vertexCount,
                         uint32_t           instanceCount,
                         uint32_t           firstVertex,
                         uint32_t           firstInstance);

    void OverrideCmdDrawIndexed(const ApiCallInfo& call_info,
                                CommandBufferInfo* command_buffer_info,
                                uint32_t           indexCount,
                                uint32_t           instanceCount,
                                uint32_t           firstIndex,
                                int32_t            vertexOffset,
                                uint32_t           firstInstance);

    void OverrideCmdDrawIndirect(const ApiCallInfo& call_info,
                                 CommandBufferInfo* command_buffer_info,
                                 BufferInfo*        buffer_info,
                                 VkDeviceSize       offset,
                                 uint32_t           drawCount,
                                 uint32_t           stride);

    void OverrideCmdDrawIndexedIndirect(const ApiCallInfo& call_info,
                                        CommandBufferInfo* command_buffer_info,
                                        BufferInfo*        buffer_info,
                                        VkDeviceSize       offset,
                                        uint32_t           drawCount,
                                        uint32_t           stride);

    void OverrideCmdDispatch(const ApiCallInfo& call_info,
                             CommandBufferInfo* command_buffer_info,
                             uint32_t           groupCountX,
                             uint32_t           groupCountY,
                             uint32_t           groupCountZ);

    void OverrideCmdDispatchIndirect(const ApiCallInfo& call_info,
                                     CommandBufferInfo* command_buffer_info,
                                     BufferInfo*        buffer_info,
                                     VkDeviceSize       offset);

    void OverrideCmdCopyBuffer(const ApiCallInfo&                          call_info,
                               CommandBufferInfo*                          command_buffer_info,
                               BufferInfo*                                 src_buffer,
                               BufferInfo*                                 dst_buffer,
                               uint32_t                                    regionCount,
                               StructPointerDecoder<Decoded_VkBufferCopy>* pRegions);

    void OverrideCmdCopyImage(const ApiCallInfo&                         call_info,
                              CommandBufferInfo*                         command_buffer_info,
                              ImageInfo*                                 src_image,
                              VkImageLayout                              srcImageLayout,
                              ImageInfo*                                 dst_image,
                              VkImageLayout                              dstImageLayout,
                              uint32_t                                   regionCount,
                              StructPointerDecoder<Decoded_VkImageCopy>* pRegions);

    void OverrideCmdBlitImage(const ApiCallInfo&                         call_info,
                              CommandBufferInfo*                         command_buffer_info,
                              ImageInfo*                                 src_image,
                              VkImageLayout                              srcImageLayout,
                              ImageInfo*                                 dst_image,
                              VkImageLayout                              dstImageLayout,
                              uint32_t                                   regionCount,
                              StructPointerDecoder<Decoded_VkImageBlit>* pRegions,
                              VkFilter                                   filter);

    void OverrideCmdCopyBufferToImage(const ApiCallInfo&                               call_info,
                                      CommandBufferInfo*                               command_buffer_info,
                                      BufferInfo*                                      src_buffer,
                                      ImageInfo*                                       dst_image,
                                      VkImageLayout                                    dstImageLayout,
                                      uint32_t                                         regionCount,
                                      StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions);

    void OverrideCmdCopyImageToBuffer(const ApiCallInfo&                               call_info,
                                      CommandBufferInfo*                               command_buffer_info,
                                      ImageInfo*                                       src_image,
                                      VkImageLayout                                    srcImageLayout,
                                      BufferInfo*                                      dst_buffer,
                                      uint32_t                                         regionCount,
                                      StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions);

    void OverrideCmdUpdateBuffer(const ApiCallInfo&       call_info,
                                 CommandBufferInfo*       command_buffer_info,
                                 BufferInfo*              dst_buffer,
                                 VkDeviceSize             dstOffset,
                                 VkDeviceSize             dataSize,
                                 PointerDecoder<uint8_t>* pData);

    void OverrideCmdFillBuffer(const ApiCallInfo& call_info,
                               CommandBufferInfo* command_buffer_info,
                               BufferInfo*        dst_buffer,
                               VkDeviceSize       dstOffset,
                               VkDeviceSize       size,
                               uint32_t           data);

    void OverrideCmdClearColorImage(const ApiCallInfo&                                     call_info,
                                    CommandBufferInfo*                                     command_buffer_info,
                                    ImageInfo*                                             image_info,
                                    VkImageLayout                                          imageLayout,
                                    StructPointerDecoder<Decoded_VkClearColorValue>*       pColor,
                                    uint32_t                                               rangeCount,
                                    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges);

    void OverrideCmdClearDepthStencilImage(const ApiCallInfo&                                      call_info,
                                           CommandBufferInfo*                                      command_buffer_info,
                                           ImageInfo*                                              image_info,
                                           VkImageLayout                                           imageLayout,
                                           StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
                                           uint32_t                                                rangeCount,
                                           StructPointerDecoder<Decoded_VkImageSubresourceRange>*  pRanges);

    void OverrideCmdClearAttachments(const ApiCallInfo&                               call_info,
                                     CommandBufferInfo*                               command_buffer_info,
                                     uint32_t                                         attachmentCount,
                                     StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
                                     uint32_t                                         rectCount,
                                     StructPointerDecoder<Decoded_VkClearRect>*       pRects);

    void OverrideCmdResolveImage(const ApiCallInfo&                            call_info,
                                 CommandBufferInfo*                            command_buffer_info,
                                 ImageInfo*                                    src_image,
                                 VkImageLayout                                 srcImageLayout,
                                 ImageInfo*                                    dst_image,
                                 VkImageLayout                                 dstImageLayout,
                                 uint32_t                                      regionCount,
                                 StructPointerDecoder<Decoded_VkImageResolve>* pRegions);

    void OverrideCmdSetEvent(const ApiCallInfo&   call_info,
                             CommandBufferInfo*   command_buffer_info,
                             EventInfo*           event_info,
                             VkPipelineStageFlags stageMask);

    void OverrideCmdResetEvent(const ApiCallInfo&   call_info,
                               CommandBufferInfo*   command_buffer_info,
                               EventInfo*           event_info,
                               VkPipelineStageFlags stageMask);

    void OverrideCmdWaitEvents(const ApiCallInfo&                                   call_info,
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
                               StructPointerDecoder<Decoded_VkImageMemoryBarrier>*  pImageMemoryBarriers);

    void OverrideCmdPipelineBarrier(const ApiCallInfo&                                   call_info,
                                    CommandBufferInfo*                                   command_buffer_info,
                                    VkPipelineStageFlags                                 srcStageMask,
                                    VkPipelineStageFlags                                 dstStageMask,
                                    VkDependencyFlags                                    dependencyFlags,
                                    uint32_t                                             memoryBarrierCount,
                                    StructPointerDecoder<Decoded_VkMemoryBarrier>*       pMemoryBarriers,
                                    uint32_t                                             bufferMemoryBarrierCount,
                                    StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
                                    uint32_t                                             imageMemoryBarrierCount,
                                    StructPointerDecoder<Decoded_VkImageMemoryBarrier>*  pImageMemoryBarriers);

    void OverrideCmdBeginQuery(const ApiCallInfo&  call_info,
                               CommandBufferInfo*  command_buffer_info,
                               QueryPoolInfo*      query_pool_info,
                               uint32_t            query,
                               VkQueryControlFlags flags);

    void OverrideCmdEndQuery(const ApiCallInfo& call_info,
                             CommandBufferInfo* command_buffer_info,
                             QueryPoolInfo*     query_pool_info,
                             uint32_t           query);

    void OverrideCmdResetQueryPool(const ApiCallInfo& call_info,
                                   CommandBufferInfo* command_buffer_info,
                                   QueryPoolInfo*     query_pool_info,
                                   uint32_t           firstQuery,
                                   uint32_t           queryCount);

    void OverrideCmdWriteTimestamp(const ApiCallInfo&      call_info,
                                   CommandBufferInfo*      command_buffer_info,
                                   VkPipelineStageFlagBits pipelineStage,
                                   QueryPoolInfo*          query_pool_info,
                                   uint32_t                query);

    void OverrideCmdCopyQueryPoolResults(const ApiCallInfo& call_info,
                                         CommandBufferInfo* command_buffer_info,
                                         QueryPoolInfo*     query_pool_info,
                                         uint32_t           firstQuery,
                                         uint32_t           queryCount,
                                         BufferInfo*        dst_buffer,
                                         VkDeviceSize       dstOffset,
                                         VkDeviceSize       stride,
                                         VkQueryResultFlags flags);

    void OverrideCmdPushConstants(const ApiCallInfo&       call_info,
                                  CommandBufferInfo*       command_buffer_info,
                                  PipelineLayoutInfo*      pipeline_layout_info,
                                  VkShaderStageFlags       stageFlags,
                                  uint32_t                 offset,
                                  uint32_t                 size,
                                  PointerDecoder<uint8_t>* pValues);

    void OverrideCmdBeginRenderPass(const ApiCallInfo&                                   call_info,
                                    CommandBufferInfo*                                   command_buffer_info,
                                    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
                                    VkSubpassContents                                    contents);

    void OverrideCmdNextSubpass(const ApiCallInfo& call_info,
                                CommandBufferInfo* command_buffer_info,
                                VkSubpassContents  contents);

    void OverrideCmdEndRenderPass(const ApiCallInfo& call_info, CommandBufferInfo* command_buffer_info);

    void OverrideWaitSemaphores(const ApiCallInfo&                                 call_info,
                                VkResult                                           returnValue,
                                DeviceInfo*                                        device_info,
                                StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
                                uint64_t                                           timeout);

    void OverrideSignalSemaphore(const ApiCallInfo&                                   call_info,
                                 VkResult                                             returnValue,
                                 DeviceInfo*                                          device_info,
                                 StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo);

    VkResult OverrideResetFences(const ApiCallInfo&             call_info,
                                 VkResult                       returnValue,
                                 DeviceInfo*                    device_info,
                                 uint32_t                       fenceCount,
                                 HandlePointerDecoder<VkFence>* pFences);

    VkResult OverrideWaitForFences(const ApiCallInfo&                   call_info,
                                   VkResult                             original_result,
                                   const DeviceInfo*                    device_info,
                                   uint32_t                             fenceCount,
                                   const HandlePointerDecoder<VkFence>* pFences,
                                   VkBool32                             waitAll,
                                   uint64_t                             timeout);

    VkResult OverrideSetEvent(const ApiCallInfo& call_info,
                              VkResult           original_result,
                              const DeviceInfo*  device_info,
                              const EventInfo*   event_info);

    VkResult OverrideResetEvent(const ApiCallInfo& call_info,
                                VkResult           original_result,
                                const DeviceInfo*  device_info,
                                const EventInfo*   event_info);

    VkResult OverrideCreateXcbSurfaceKHR(PFN_vkCreateXcbSurfaceKHR                                      func,
                                         VkResult                                                       original_result,
                                         InstanceInfo*                                                  instance_info,
                                         const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
                                         const StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
                                         HandlePointerDecoder<VkSurfaceKHR>*                            pSurface);

    VkResult OverrideCreateSwapchainKHR(PFN_vkCreateSwapchainKHR                                      func,
                                        VkResult                                                      original_result,
                                        DeviceInfo*                                                   device_info,
                                        const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
                                        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
                                        HandlePointerDecoder<VkSwapchainKHR>*                         pSwapchain);

    void OverrideDestroySwapchainKHR(PFN_vkDestroySwapchainKHR                                  func,
                                     DeviceInfo*                                                device_info,
                                     SwapchainKHRInfo*                                          swapchain_info,
                                     const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideGetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR    func,
                                           VkResult                       original_result,
                                           const DeviceInfo*              device_info,
                                           SwapchainKHRInfo*              swapchain_info,
                                           PointerDecoder<uint32_t>*      pSwapchainImageCount,
                                           HandlePointerDecoder<VkImage>* pSwapchainImages);

    VkResult OverrideAcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                         VkResult                  original_result,
                                         const DeviceInfo*         device_info,
                                         SwapchainKHRInfo*         swapchain_info,
                                         uint64_t                  timeout,
                                         SemaphoreInfo*            semaphore_info,
                                         FenceInfo*                fence_info,
                                         PointerDecoder<uint32_t>* pImageIndex);

    void OverrideUpdateDescriptorSets(const ApiCallInfo&                                  call_info,
                                      DeviceInfo*                                         device_info,
                                      uint32_t                                            descriptorWriteCount,
                                      StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
                                      uint32_t                                            descriptorCopyCount,
                                      StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies);

    void OverrideDestroyInstance(const ApiCallInfo&                                   call_info,
                                 InstanceInfo*                                        instance,
                                 StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    void OverrideDestroyDevice(PFN_vkDestroyDevice                                        func,
                               const DeviceInfo*                                          device_info,
                               const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    void OverrideDestroyCommandPool(const ApiCallInfo&                                   call_info,
                                    DeviceInfo*                                          device,
                                    CommandPoolInfo*                                     commandPool,
                                    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    void OverrideFreeCommandBuffers(const ApiCallInfo&                     call_info,
                                    DeviceInfo*                            device,
                                    CommandPoolInfo*                       commandPool,
                                    uint32_t                               commandBufferCount,
                                    HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers);

    virtual void Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                               format::HandleId   commandBuffer,
                                                               format::HandleId   descriptorUpdateTemplate,
                                                               format::HandleId   layout,
                                                               uint32_t           set,
                                                               DescriptorUpdateTemplateDecoder* pData) override
    {}

    virtual void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&               call_info,
                                                           format::HandleId                 device,
                                                           format::HandleId                 descriptorSet,
                                                           format::HandleId                 descriptorUpdateTemplate,
                                                           DescriptorUpdateTemplateDecoder* pData) override
    {}

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&               call_info,
                                                              format::HandleId                 device,
                                                              format::HandleId                 descriptorSet,
                                                              format::HandleId                 descriptorUpdateTemplate,
                                                              DescriptorUpdateTemplateDecoder* pData) override
    {}

    void Replay(format::CommandIndexType replay_until);

  private:
    void RaiseFatalError(const char* message) const;

    void EmplaceSerialzedCommand(std::unique_ptr<SerializedCommands> command);

    // void FinalizeRecordingCommandBuffer()
    void ReplayQueueSubmit(QueueSubmitInfo* submit_cmd, format::CommandIndexType replay_until);

    format::CommandIndexType
    ReplayCommandBuffer(CommandBufferInfo* cmd_buf, VkCommandBuffer vk_cmd, format::CommandIndexType replay_until);

    void ReplayCmdPipelineBarrier(CommandBufferInfo*                cmd_buf,
                                  VulkanCommandPipelineBarrierInfo* cmd_info,
                                  VkCommandBuffer                   vk_cmd,
                                  VkDevice                          device);

    void ReplayCmdBeginRenderpas(CommandBufferInfo*                cmd_buf,
                                 VulkanCommandBeginRenderPassInfo* cmd_info,
                                 VkCommandBuffer                   vk_cmd,
                                 VkDevice                          device);

    void ReplayCmdBindPipeline(CommandBufferInfo*             cmd_buf,
                               VulkanCommandBindPipelineInfo* cmd_info,
                               VkCommandBuffer                vk_cmd,
                               VkDevice                       device);

    void ReplayCmdBindDescriptorSets(CommandBufferInfo*                   cmd_buf,
                                     VulkanCommandBindDescriptorSetsInfo* cmd_info,
                                     VkCommandBuffer                      vk_cmd,
                                     VkDevice                             device);

    void ReplayCmdSetViewport(CommandBufferInfo*            cmd_buf,
                              VulkanCommandSetViewportInfo* cmd_info,
                              VkCommandBuffer               vk_cmd,
                              VkDevice                      device);

    void ReplayCmdSetScissor(CommandBufferInfo*           cmd_buf,
                             VulkanCommandSetScissorInfo* cmd_info,
                             VkCommandBuffer              vk_cmd,
                             VkDevice                     device);

    void
    ReplayCmdDraw(CommandBufferInfo* cmd_buf, VulkanCommandDrawInfo* cmd_info, VkCommandBuffer vk_cmd, VkDevice device);

    void ReplayCmdDrawIndirect(CommandBufferInfo*             cmd_buf,
                               VulkanCommandDrawIndirectInfo* cmd_info,
                               VkCommandBuffer                vk_cmd,
                               VkDevice                       device);

    void ReplayCmdEndRenderpass(CommandBufferInfo*              cmd_buf,
                                VulkanCommandEndRenderPassInfo* cmd_info,
                                VkCommandBuffer                 vk_cmd,
                                VkDevice                        device);

  protected:
    virtual void Reset() override;

  private:
    serialized_commands_map_t commands_;

    enum vulkan_object_type
    {
        VULKAN_OBJECT,
        VULKAN_POOL_OBJECT,
        VULKAN_POOL_MEMBER
    };

    struct objects_pending_for_deletion
    {
        std::vector<AccelerationStructureKHRInfo*> accelerationStructureKHRs;
        std::vector<AccelerationStructureNVInfo*>  accelerationStructureNVs;
        std::vector<BufferInfo*>                   buffers;
        std::vector<BufferViewInfo*>               bufferViews;
        std::vector<const CommandBufferInfo*>      commandBuffers;
        std::vector<std::pair<const CommandPoolInfo*, const StructPointerDecoder<Decoded_VkAllocationCallbacks>>>
                                                   commandPools;
        std::vector<DeferredOperationKHRInfo*>     deferredOperationKHRs;
        std::vector<DescriptorPoolInfo*>           descriptorPools;
        std::vector<DescriptorSetInfo*>            descriptorSets;
        std::vector<DescriptorSetLayoutInfo*>      descriptorSetLayouts;
        std::vector<DescriptorUpdateTemplateInfo*> descriptorUpdateTemplates;
        std::vector<std::pair<const DeviceInfo*, const StructPointerDecoder<Decoded_VkAllocationCallbacks>>> devices;
        std::vector<DeviceMemoryInfo*>             deviceMemorys;
        std::vector<DisplayKHRInfo*>               displayKHRs;
        std::vector<DisplayModeKHRInfo*>           displayModeKHRs;
        std::vector<EventInfo*>                    events;
        std::vector<FenceInfo*>                    fences;
        std::vector<FramebufferInfo*>              framebuffers;
        std::vector<ImageInfo*>                    images;
        std::vector<ImageViewInfo*>                imageViews;
        std::vector<IndirectCommandsLayoutNVInfo*> indirectCommandsLayoutNVs;
        std::vector<std::pair<const InstanceInfo*, const StructPointerDecoder<Decoded_VkAllocationCallbacks>>>
                                                        instances;
        std::vector<MicromapEXTInfo*>                   micromapEXTs;
        std::vector<OpticalFlowSessionNVInfo*>          opticalFlowSessionNVs;
        std::vector<PerformanceConfigurationINTELInfo*> performanceConfigurationINTELs;
        std::vector<PhysicalDeviceInfo*>                physicalDevices;
        std::vector<PipelineInfo*>                      pipelines;
        std::vector<PipelineCacheInfo*>                 pipelineCaches;
        std::vector<PipelineLayoutInfo*>                pipelineLayouts;
        std::vector<PrivateDataSlotInfo*>               privateDataSlots;
        std::vector<QueryPoolInfo*>                     queryPools;
        std::vector<QueueInfo*>                         queues;
        std::vector<RenderPassInfo*>                    renderPasss;
        std::vector<SamplerInfo*>                       samplers;
        std::vector<SamplerYcbcrConversionInfo*>        samplerYcbcrConversions;
        std::vector<SemaphoreInfo*>                     semaphores;
        std::vector<ShaderModuleInfo*>                  shaderModules;
        std::vector<SurfaceKHRInfo*>                    surfaceKHRs;
        std::vector<SwapchainKHRInfo*>                  swapchainKHRs;
        std::vector<ValidationCacheEXTInfo*>            validationCacheEXTs;
    } pending_objects;

    void DeletePendingObjects();

  public:
    serialized_commands_map_t& GetCommands() { return commands_; }
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif /* GFXRECON_GENERATED_VULKAN_FRAME_INSPECTOR_CONSUMER_BASE_H */
