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
#include "generated/generated_vulkan_consumer.h"
#include "decode/vulkan_frame_inspector_consumer_client_object_table.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanFrameInspectorConsumerClientBase : public VulkanConsumer
{
  public:
    VulkanFrameInspectorConsumerClientBase(const VulkanReplayOptions& options) : options_(options) {}

    virtual ~VulkanFrameInspectorConsumerClientBase() override {}

    virtual void Process_vkCreateInstance(const ApiCallInfo&                                   call_info,
                                          VkResult                                             returnValue,
                                          StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                          HandlePointerDecoder<VkInstance>*                    pInstance) override;

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

    virtual void Process_vkCreateRenderPass(const ApiCallInfo&                                    call_info,
                                            VkResult                                              returnValue,
                                            format::HandleId                                      device,
                                            StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
                                            HandlePointerDecoder<VkRenderPass>*                   pRenderPass) override;

    virtual void Process_vkCreateFramebuffer(const ApiCallInfo&                                     call_info,
                                             VkResult                                               returnValue,
                                             format::HandleId                                       device,
                                             StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
                                             StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                             HandlePointerDecoder<VkFramebuffer>* pFramebuffer) override;

    virtual void
    Process_vkCreateDescriptorSetLayout(const ApiCallInfo&                                             call_info,
                                        VkResult                                                       returnValue,
                                        format::HandleId                                               device,
                                        StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*           pAllocator,
                                        HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout) override;

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

    virtual void Process_vkCreatePipelineLayout(const ApiCallInfo&                                        call_info,
                                                VkResult                                                  returnValue,
                                                format::HandleId                                          device,
                                                StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
                                                StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
                                                HandlePointerDecoder<VkPipelineLayout>* pPipelineLayout) override;

    virtual void
    Process_vkCreateGraphicsPipelines(const ApiCallInfo&                                          call_info,
                                      VkResult                                                    returnValue,
                                      format::HandleId                                            device,
                                      format::HandleId                                            pipelineCache,
                                      uint32_t                                                    createInfoCount,
                                      StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
                                      StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
                                      HandlePointerDecoder<VkPipeline>*                           pPipelines) override;

    virtual void Process_vkCreateCommandPool(const ApiCallInfo&                                     call_info,
                                             VkResult                                               returnValue,
                                             format::HandleId                                       device,
                                             StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
                                             StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                             HandlePointerDecoder<VkCommandPool>* pCommandPool) override;

    virtual void
    Process_vkAllocateCommandBuffers(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    virtual void
    Process_vkBeginCommandBuffer(const ApiCallInfo&                                      call_info,
                                 VkResult                                                returnValue,
                                 format::HandleId                                        commandBuffer,
                                 StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) override;

    virtual void Process_vkEndCommandBuffer(const ApiCallInfo& call_info,
                                            VkResult           returnValue,
                                            format::HandleId   commandBuffer) override;

    virtual void Process_vkCmdBeginRenderPass(const ApiCallInfo&                                   call_info,
                                              format::HandleId                                     commandBuffer,
                                              StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
                                              VkSubpassContents                                    contents) override;

    virtual void Process_vkCmdBindPipeline(const ApiCallInfo&  call_info,
                                           format::HandleId    commandBuffer,
                                           VkPipelineBindPoint pipelineBindPoint,
                                           format::HandleId    pipeline) override;

    virtual void Process_vkCmdDraw(const ApiCallInfo& call_info,
                                   format::HandleId   commandBuffer,
                                   uint32_t           vertexCount,
                                   uint32_t           instanceCount,
                                   uint32_t           firstVertex,
                                   uint32_t           firstInstance) override;

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

    //   virtual void WaitDevicesIdle() override {}

    //   virtual bool IsComplete(uint64_t block_index) override { return false; }

    //   virtual void Process_ExeFileInfo(util::filepath::FileInfo& info_record) override {}

    //   virtual void ProcessStateBeginMarker(uint64_t frame_number) override {}

    //   virtual void ProcessStateEndMarker(uint64_t frame_number) override {}

    //   virtual void ProcessDisplayMessageCommand(format::CommandIndexType command_index,
    //                                             const std::string&       message) override
    //   {}

    //   virtual void ProcessFillMemoryCommand(format::CommandIndexType command_index,
    //                                         uint64_t                 memory_id,
    //                                         uint64_t                 offset,
    //                                         uint64_t                 size,
    //                                         const uint8_t*           data) override
    //   {}

    //   virtual void
    //   ProcessFillMemoryResourceValueCommand(const format::FillMemoryResourceValueCommandHeader& command_header,
    //                                         const uint8_t*                                      data) override
    //   {}

    //   virtual void ProcessResizeWindowCommand(format::CommandIndexType command_index,
    //                                           format::HandleId         surface_id,
    //                                           uint32_t                 width,
    //                                           uint32_t                 height) override
    //   {}

    //   virtual void ProcessResizeWindowCommand2(format::CommandIndexType command_index,
    //                                            format::HandleId         surface_id,
    //                                            uint32_t                 width,
    //                                            uint32_t                 height,
    //                                            uint32_t                 pre_transform) override
    //   {}

    //   virtual void
    //   ProcessCreateHardwareBufferCommand(format::CommandIndexType                            command_index,
    //                                      format::HandleId                                    memory_id,
    //                                      uint64_t                                            buffer_id,
    //                                      uint32_t                                            format,
    //                                      uint32_t                                            width,
    //                                      uint32_t                                            height,
    //                                      uint32_t                                            stride,
    //                                      uint64_t                                            usage,
    //                                      uint32_t                                            layers,
    //                                      const std::vector<format::HardwareBufferPlaneInfo>& plane_info) override
    //   {}

    //   virtual void ProcessDestroyHardwareBufferCommand(format::CommandIndexType command_index,
    //                                                    uint64_t                 buffer_id) override
    //   {}

    //   virtual void ProcessCreateHeapAllocationCommand(uint64_t allocation_id, uint64_t allocation_size) override {}

    //   virtual void ProcessSetDevicePropertiesCommand(format::CommandIndexType command_index,
    //                                                  format::HandleId         physical_device_id,
    //                                                  uint32_t                 api_version,
    //                                                  uint32_t                 driver_version,
    //                                                  uint32_t                 vendor_id,
    //                                                  uint32_t                 device_id,
    //                                                  uint32_t                 device_type,
    //                                                  const uint8_t            pipeline_cache_uuid[format::kUuidSize],
    //                                                  const std::string&       device_name) override
    //   {}

    //   virtual void
    //   ProcessSetDeviceMemoryPropertiesCommand(format::CommandIndexType                     command_index,
    //                                           format::HandleId                             physical_device_id,
    //                                           const std::vector<format::DeviceMemoryType>& memory_types,
    //                                           const std::vector<format::DeviceMemoryHeap>& memory_heaps) override
    //   {}

    //   virtual void ProcessSetOpaqueAddressCommand(format::CommandIndexType command_index,
    //                                               format::HandleId         device_id,
    //                                               format::HandleId         object_id,
    //                                               uint64_t                 address) override
    //   {}

    //   virtual void ProcessSetRayTracingShaderGroupHandlesCommand(format::CommandIndexType command_index,
    //                                                              format::HandleId         device_id,
    //                                                              format::HandleId         pipeline_id,
    //                                                              size_t                   data_size,
    //                                                              const uint8_t*           data) override
    //   {}

    //   virtual void
    //   ProcessSetSwapchainImageStateCommand(format::CommandIndexType                            command_index,
    //                                        format::HandleId                                    device_id,
    //                                        format::HandleId                                    swapchain_id,
    //                                        uint32_t                                            last_presented_image,
    //                                        const std::vector<format::SwapchainImageStateInfo>& image_state) override
    //   {}

    //   virtual void ProcessBeginResourceInitCommand(format::CommandIndexType command_index,
    //                                                format::HandleId         device_id,
    //                                                uint64_t                 max_resource_size,
    //                                                uint64_t                 max_copy_size) override
    //   {}

    //   virtual void ProcessEndResourceInitCommand(format::CommandIndexType command_index,
    //                                              format::HandleId         device_id) override
    //   {}

    //   virtual void ProcessInitBufferCommand(format::CommandIndexType command_index,
    //                                         format::HandleId         device_id,
    //                                         format::HandleId         buffer_id,
    //                                         uint64_t                 data_size,
    //                                         const uint8_t*           data) override
    //   {}

    //   virtual void ProcessInitImageCommand(format::CommandIndexType     command_index,
    //                                        format::HandleId             device_id,
    //                                        format::HandleId             image_id,
    //                                        uint64_t                     data_size,
    //                                        uint32_t                     aspect,
    //                                        uint32_t                     layout,
    //                                        const std::vector<uint64_t>& level_sizes,
    //                                        const uint8_t*               data) override
    //   {}

    //   virtual void ProcessInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
    //                                              const uint8_t*                              data) override
    //   {}

    //   virtual void ProcessInitDx12AccelerationStructureCommand(
    //       const format::InitDx12AccelerationStructureCommandHeader&       command_header,
    //       std::vector<format::InitDx12AccelerationStructureGeometryDesc>& geometry_descs,
    //       const uint8_t*                                                  build_inputs_data) override
    //   {}

    //   virtual void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&               call_info,
    //                                                          format::HandleId                 device,
    //                                                          format::HandleId                 descriptorSet,
    //                                                          format::HandleId descriptorUpdateTemplate,
    //                                                          DescriptorUpdateTemplateDecoder* pData) override
    //   {}

    //   virtual void Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
    //                                                              format::HandleId   commandBuffer,
    //                                                              format::HandleId   descriptorUpdateTemplate,
    //                                                              format::HandleId   layout,
    //                                                              uint32_t           set,
    //                                                              DescriptorUpdateTemplateDecoder* pData) override
    //   {}

    //   virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&               call_info,
    //                                                             format::HandleId                 device,
    //                                                             format::HandleId                 descriptorSet,
    //                                                             format::HandleId descriptorUpdateTemplate,
    //                                                             DescriptorUpdateTemplateDecoder* pData) override
    //   {}

    // private:
    //   void RaiseFatalError(const char* message) const;

    //   void EmplaceSerialzedCommand(std::unique_ptr<SerializedCommands> command);

    // protected:
    //   virtual void Reset() override {}

  private:
    serialized_commands_map_t       commands_;
    VulkanFrameInspectorObjectTable object_table_;
    const VulkanReplayOptions&      options_;

    // public:
    //   serialized_commands_map_t& GetCommands() { return commands_; }
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif /* GFXRECON_GENERATED_VULKAN_FRAME_INSPECTOR_CONSUMER_CLIENT_BASE_H */
