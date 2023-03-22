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

#ifndef GFXRECON_GENERATED_VULKAN_FRAME_INSPECTOR_CONSUMER_CLIENT_BASE_H
#define GFXRECON_GENERATED_VULKAN_FRAME_INSPECTOR_CONSUMER_CLIENT_BASE_H

#include "util/defines.h"
#include "application/application.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_frame_inspector_client_object_info.h"
#include "decode/vulkan_frame_inspector_serialized_commands.h"
#include "decode/vulkan_frame_inspector_client_indirect_commands.h"
#include "generated/generated_vulkan_consumer.h"
#include "decode/vulkan_frame_inspector_consumer_client_object_table.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanFrameInspectorConsumerClientBase : public VulkanConsumer
{
  public:
    VulkanFrameInspectorConsumerClientBase(const VulkanReplayOptions& options) : options_(options) {}
    VulkanFrameInspectorConsumerClientBase(const VulkanFrameInspectorConsumerClientBase& other) = delete;
    VulkanFrameInspectorConsumerClientBase& operator=(const VulkanFrameInspectorConsumerClientBase& other) = delete;

    virtual ~VulkanFrameInspectorConsumerClientBase() override {}

    virtual void Process_vkCreateInstance(const ApiCallInfo&                                   call_info,
                                          VkResult                                             returnValue,
                                          StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                          HandlePointerDecoder<VkInstance>*                    pInstance) override;

    virtual void Process_vkDestroyInstance(const ApiCallInfo&                                   call_info,
                                           format::HandleId                                     instance,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkEnumeratePhysicalDevices(const ApiCallInfo&                      call_info,
                                                    VkResult                                returnValue,
                                                    format::HandleId                        instance,
                                                    PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
                                                    HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices) override;

    virtual void Process_vkCreateDevice(const ApiCallInfo&                                   call_info,
                                        VkResult                                             returnValue,
                                        format::HandleId                                     physicalDevice,
                                        StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                        HandlePointerDecoder<VkDevice>*                      pDevice) override;

    virtual void Process_vkDestroyDevice(const ApiCallInfo&                                   call_info,
                                         format::HandleId                                     device,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateRenderPass(const ApiCallInfo&                                    call_info,
                                            VkResult                                              returnValue,
                                            format::HandleId                                      device,
                                            StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
                                            HandlePointerDecoder<VkRenderPass>*                   pRenderPass) override;

    virtual void Process_vkDestroyRenderPass(const ApiCallInfo&                                   call_info,
                                             format::HandleId                                     device,
                                             format::HandleId                                     renderPass,
                                             StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateFramebuffer(const ApiCallInfo&                                     call_info,
                                             VkResult                                               returnValue,
                                             format::HandleId                                       device,
                                             StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
                                             StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                             HandlePointerDecoder<VkFramebuffer>* pFramebuffer) override;

    virtual void Process_vkDestroyFramebuffer(const ApiCallInfo&                                   call_info,
                                              format::HandleId                                     device,
                                              format::HandleId                                     framebuffer,
                                              StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void
    Process_vkCreateDescriptorSetLayout(const ApiCallInfo&                                             call_info,
                                        VkResult                                                       returnValue,
                                        format::HandleId                                               device,
                                        StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*           pAllocator,
                                        HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout) override;

    virtual void
    Process_vkDestroyDescriptorSetLayout(const ApiCallInfo&                                   call_info,
                                         format::HandleId                                     device,
                                         format::HandleId                                     descriptorSetLayout,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateDescriptorPool(const ApiCallInfo&                                        call_info,
                                                VkResult                                                  returnValue,
                                                format::HandleId                                          device,
                                                StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
                                                StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
                                                HandlePointerDecoder<VkDescriptorPool>* pDescriptorPool) override;

    virtual void
    Process_vkAllocateDescriptorSets(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    virtual void Process_vkFreeDescriptorSets(const ApiCallInfo&                     call_info,
                                              VkResult                               returnValue,
                                              format::HandleId                       device,
                                              format::HandleId                       descriptorPool,
                                              uint32_t                               descriptorSetCount,
                                              HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    virtual void Process_vkResetDescriptorPool(const ApiCallInfo&         call_info,
                                               VkResult                   returnValue,
                                               format::HandleId           device,
                                               format::HandleId           descriptorPool,
                                               VkDescriptorPoolResetFlags flags) override;

    virtual void
    Process_vkDestroyDescriptorPool(const ApiCallInfo&                                   call_info,
                                    format::HandleId                                     device,
                                    format::HandleId                                     descriptorPool,
                                    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateShaderModule(const ApiCallInfo&                                      call_info,
                                              VkResult                                                returnValue,
                                              format::HandleId                                        device,
                                              StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
                                              StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
                                              HandlePointerDecoder<VkShaderModule>* pShaderModule) override;

    virtual void
    Process_vkDestroyShaderModule(const ApiCallInfo&                                   call_info,
                                  format::HandleId                                     device,
                                  format::HandleId                                     shaderModule,
                                  StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreatePipelineLayout(const ApiCallInfo&                                        call_info,
                                                VkResult                                                  returnValue,
                                                format::HandleId                                          device,
                                                StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
                                                StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
                                                HandlePointerDecoder<VkPipelineLayout>* pPipelineLayout) override;

    virtual void
    Process_vkDestroyPipelineLayout(const ApiCallInfo&                                   call_info,
                                    format::HandleId                                     device,
                                    format::HandleId                                     pipelineLayout,
                                    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateSampler(const ApiCallInfo&                                   call_info,
                                         VkResult                                             returnValue,
                                         format::HandleId                                     device,
                                         StructPointerDecoder<Decoded_VkSamplerCreateInfo>*   pCreateInfo,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                         HandlePointerDecoder<VkSampler>*                     pSampler) override;

    virtual void Process_vkDestroySampler(const ApiCallInfo&                                   call_info,
                                          format::HandleId                                     device,
                                          format::HandleId                                     sampler,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateBuffer(const ApiCallInfo&                                   call_info,
                                        VkResult                                             returnValue,
                                        format::HandleId                                     device,
                                        StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                        HandlePointerDecoder<VkBuffer>*                      pBuffer) override;

    virtual void Process_vkDestroyBuffer(const ApiCallInfo&                                   call_info,
                                         format::HandleId                                     device,
                                         format::HandleId                                     buffer,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateBufferView(const ApiCallInfo&                                    call_info,
                                            VkResult                                              returnValue,
                                            format::HandleId                                      device,
                                            StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
                                            HandlePointerDecoder<VkBufferView>*                   pView) override;

    virtual void Process_vkDestroyBufferView(const ApiCallInfo&                                   call_info,
                                             format::HandleId                                     device,
                                             format::HandleId                                     bufferView,
                                             StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateImage(const ApiCallInfo&                                   call_info,
                                       VkResult                                             returnValue,
                                       format::HandleId                                     device,
                                       StructPointerDecoder<Decoded_VkImageCreateInfo>*     pCreateInfo,
                                       StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                       HandlePointerDecoder<VkImage>*                       pImage) override;

    virtual void Process_vkDestroyImage(const ApiCallInfo&                                   call_info,
                                        format::HandleId                                     device,
                                        format::HandleId                                     image,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateImageView(const ApiCallInfo&                                   call_info,
                                           VkResult                                             returnValue,
                                           format::HandleId                                     device,
                                           StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                           HandlePointerDecoder<VkImageView>*                   pView) override;

    virtual void Process_vkDestroyImageView(const ApiCallInfo&                                   call_info,
                                            format::HandleId                                     device,
                                            format::HandleId                                     imageView,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void
    Process_vkCreateGraphicsPipelines(const ApiCallInfo&                                          call_info,
                                      VkResult                                                    returnValue,
                                      format::HandleId                                            device,
                                      format::HandleId                                            pipelineCache,
                                      uint32_t                                                    createInfoCount,
                                      StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
                                      StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
                                      HandlePointerDecoder<VkPipeline>*                           pPipelines) override;

    virtual void Process_vkDestroyPipeline(const ApiCallInfo&                                   call_info,
                                           format::HandleId                                     device,
                                           format::HandleId                                     pipeline,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateCommandPool(const ApiCallInfo&                                     call_info,
                                             VkResult                                               returnValue,
                                             format::HandleId                                       device,
                                             StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
                                             StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                             HandlePointerDecoder<VkCommandPool>* pCommandPool) override;

    virtual void Process_vkDestroyCommandPool(const ApiCallInfo&                                   call_info,
                                              format::HandleId                                     device,
                                              format::HandleId                                     commandPool,
                                              StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void
    Process_vkAllocateCommandBuffers(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    virtual void Process_vkResetCommandBuffer(const ApiCallInfo&        call_info,
                                              VkResult                  returnValue,
                                              format::HandleId          commandBuffer,
                                              VkCommandBufferResetFlags flags) override;

    virtual void Process_vkResetCommandPool(const ApiCallInfo&      call_info,
                                            VkResult                returnValue,
                                            format::HandleId        device,
                                            format::HandleId        commandPool,
                                            VkCommandPoolResetFlags flags) override;

    virtual void
    Process_vkBeginCommandBuffer(const ApiCallInfo&                                      call_info,
                                 VkResult                                                returnValue,
                                 format::HandleId                                        commandBuffer,
                                 StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) override;

    virtual void Process_vkEndCommandBuffer(const ApiCallInfo& call_info,
                                            VkResult           returnValue,
                                            format::HandleId   commandBuffer) override;

    virtual void Process_vkFreeCommandBuffers(const ApiCallInfo&                     call_info,
                                              format::HandleId                       device,
                                              format::HandleId                       commandPool,
                                              uint32_t                               commandBufferCount,
                                              HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    virtual void Process_vkCmdBeginRenderPass(const ApiCallInfo&                                   call_info,
                                              format::HandleId                                     commandBuffer,
                                              StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
                                              VkSubpassContents                                    contents) override;

    virtual void Process_vkCmdEndRenderPass(const ApiCallInfo& call_info, format::HandleId commandBuffer) override;

    virtual void Process_vkCmdBindPipeline(const ApiCallInfo&  call_info,
                                           format::HandleId    commandBuffer,
                                           VkPipelineBindPoint pipelineBindPoint,
                                           format::HandleId    pipeline) override;

    virtual void Process_vkCmdSetViewport(const ApiCallInfo&                        call_info,
                                          format::HandleId                          commandBuffer,
                                          uint32_t                                  firstViewport,
                                          uint32_t                                  viewportCount,
                                          StructPointerDecoder<Decoded_VkViewport>* pViewports) override;

    virtual void Process_vkCmdSetScissor(const ApiCallInfo&                      call_info,
                                         format::HandleId                        commandBuffer,
                                         uint32_t                                firstScissor,
                                         uint32_t                                scissorCount,
                                         StructPointerDecoder<Decoded_VkRect2D>* pScissors) override;

    virtual void Process_vkCmdBindIndexBuffer(const ApiCallInfo& call_info,
                                              format::HandleId   commandBuffer,
                                              format::HandleId   buffer,
                                              VkDeviceSize       offset,
                                              VkIndexType        indexType) override;

    virtual void Process_vkCmdBindVertexBuffers(const ApiCallInfo&              call_info,
                                                format::HandleId                commandBuffer,
                                                uint32_t                        firstBinding,
                                                uint32_t                        bindingCount,
                                                HandlePointerDecoder<VkBuffer>* pBuffers,
                                                PointerDecoder<VkDeviceSize>*   pOffsets) override;

    virtual void Process_vkCmdDraw(const ApiCallInfo& call_info,
                                   format::HandleId   commandBuffer,
                                   uint32_t           vertexCount,
                                   uint32_t           instanceCount,
                                   uint32_t           firstVertex,
                                   uint32_t           firstInstance) override;

    virtual void Process_vkCmdDrawIndexed(const ApiCallInfo& call_info,
                                          format::HandleId   commandBuffer,
                                          uint32_t           indexCount,
                                          uint32_t           instanceCount,
                                          uint32_t           firstIndex,
                                          int32_t            vertexOffset,
                                          uint32_t           firstInstance) override;

    virtual void Process_vkCmdDrawIndirect(const ApiCallInfo& call_info,
                                           format::HandleId   commandBuffer,
                                           format::HandleId   buffer,
                                           VkDeviceSize       offset,
                                           uint32_t           drawCount,
                                           uint32_t           stride) override;

    virtual void Process_vkCmdDrawIndirectCount(const ApiCallInfo& call_info,
                                                format::HandleId   commandBuffer,
                                                format::HandleId   buffer,
                                                VkDeviceSize       offset,
                                                format::HandleId   countBuffer,
                                                VkDeviceSize       countBufferOffset,
                                                uint32_t           maxDrawCount,
                                                uint32_t           stride) override;

    virtual void Process_vkCmdBindDescriptorSets(const ApiCallInfo&                     call_info,
                                                 format::HandleId                       commandBuffer,
                                                 VkPipelineBindPoint                    pipelineBindPoint,
                                                 format::HandleId                       layout,
                                                 uint32_t                               firstSet,
                                                 uint32_t                               descriptorSetCount,
                                                 HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets,
                                                 uint32_t                               dynamicOffsetCount,
                                                 PointerDecoder<uint32_t>*              pDynamicOffsets) override;

    virtual void
    Process_vkUpdateDescriptorSets(const ApiCallInfo&                                  call_info,
                                   format::HandleId                                    device,
                                   uint32_t                                            descriptorWriteCount,
                                   StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
                                   uint32_t                                            descriptorCopyCount,
                                   StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies) override;

    virtual void Process_vkQueueSubmit(const ApiCallInfo&                          call_info,
                                       VkResult                                    returnValue,
                                       format::HandleId                            queue,
                                       uint32_t                                    submitCount,
                                       StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                       format::HandleId                            fence) override;

    virtual void Process_vkQueuePresentKHR(const ApiCallInfo&                              call_info,
                                           VkResult                                        returnValue,
                                           format::HandleId                                queue,
                                           StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo) override;

    virtual void Process_vkAllocateMemory(const ApiCallInfo&                                   call_info,
                                          VkResult                                             returnValue,
                                          format::HandleId                                     device,
                                          StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  pAllocateInfo,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                          HandlePointerDecoder<VkDeviceMemory>*                pMemory) override;

    virtual void Process_vkFreeMemory(const ApiCallInfo&                                   call_info,
                                      format::HandleId                                     device,
                                      format::HandleId                                     memory,
                                      StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkBindBufferMemory(const ApiCallInfo& call_info,
                                            VkResult           returnValue,
                                            format::HandleId   device,
                                            format::HandleId   buffer,
                                            format::HandleId   memory,
                                            VkDeviceSize       memoryOffset) override;

    virtual void Process_vkBindImageMemory(const ApiCallInfo& call_info,
                                           VkResult           returnValue,
                                           format::HandleId   device,
                                           format::HandleId   image,
                                           format::HandleId   memory,
                                           VkDeviceSize       memoryOffset) override;

    void EmplaceSerializedCommand(std::unique_ptr<SerializedCommands> command)
    {
        commands_.emplace_back(std::move(command));
    }

    virtual void Reset() override
    {
        commands_.clear();
        DeletePendingObjects();
    }

    void DumpFrame() const;

    bool GetIndirectCommandParamsOverSocket(util::Socket& socket);

  private:
    std::vector<std::unique_ptr<SerializedCommands>> commands_;
    VulkanFrameInspectorObjectTable                  object_table_;
    const VulkanReplayOptions&                       options_;

    struct
    {
        std::vector<format::HandleId>                              objects;
        std::vector<std::pair<format::HandleId, format::HandleId>> pool_object;
        std::vector<format::HandleId>                              pools;
    } objects_pending_for_deletion_;

    void DeletePendingObjects();

    std::map<std::pair<format::CommandIndexType, format::CommandIndexType>, draw_indirect_command_t>
        draw_indirect_params;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif /* GFXRECON_GENERATED_VULKAN_FRAME_INSPECTOR_CONSUMER_CLIENT_BASE_H */
