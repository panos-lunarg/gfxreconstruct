/*
** Copyright (c) 2018-2020 Valve Corporation
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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H
#define GFXRECON_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H

#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/screenshot_handler.h"
#include "decode/swapchain_image_tracker.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_resource_allocator.h"
#include "decode/vulkan_resource_tracking_consumer.h"
#include "decode/vulkan_resource_initializer.h"
#include "decode/vulkan_swapchain.h"
#include "decode/window.h"
#include "format/api_call_id.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "decode/vulkan_replay_base.h"
#include "graphics/fps_info.h"
#include "util/defines.h"
#include "util/logging.h"

#include "application/application.h"

#include "vulkan/vulkan.h"

#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Types provided by this file are defined by format/platform_types.h when VK_USE_PLATFORM_ANDROID_KHR is not set.
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <android/hardware_buffer.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReplayConsumerBase : public VulkanReplayBase
{
  public:
    VulkanReplayConsumerBase(std::shared_ptr<application::Application> application, const VulkanReplayOptions& options);

    virtual ~VulkanReplayConsumerBase() override;

    virtual void WaitDevicesIdle() override;

    void SetFpsInfo(graphics::FpsInfo* fps_info) { fps_info_ = fps_info; }

    void ProcessStateEndMarker(uint64_t frame_number);

    virtual void ProcessDisplayMessageCommand(format::CommandIndexType command_index,
                                              const std::string&       message) override;

    virtual void ProcessResizeWindowCommand(format::CommandIndexType command_index,
                                            format::HandleId         surface_id,
                                            uint32_t                 width,
                                            uint32_t                 height) override;

    virtual void ProcessResizeWindowCommand2(format::CommandIndexType command_index,
                                             format::HandleId         surface_id,
                                             uint32_t                 width,
                                             uint32_t                 height,
                                             uint32_t                 pre_transform) override;

    virtual void ProcessSetDevicePropertiesCommand(format::CommandIndexType command_index,
                                                   format::HandleId         physical_device_id,
                                                   uint32_t                 api_version,
                                                   uint32_t                 driver_version,
                                                   uint32_t                 vendor_id,
                                                   uint32_t                 device_id,
                                                   uint32_t                 device_type,
                                                   const uint8_t            pipeline_cache_uuid[format::kUuidSize],
                                                   const std::string&       device_name) override;

    virtual void
    ProcessSetDeviceMemoryPropertiesCommand(format::CommandIndexType                     command_index,
                                            format::HandleId                             physical_device_id,
                                            const std::vector<format::DeviceMemoryType>& memory_types,
                                            const std::vector<format::DeviceMemoryHeap>& memory_heaps) override;

    virtual void ProcessSetOpaqueAddressCommand(format::CommandIndexType command_index,
                                                format::HandleId         device_id,
                                                format::HandleId         object_id,
                                                uint64_t                 address) override;

    virtual void ProcessSetRayTracingShaderGroupHandlesCommand(format::CommandIndexType command_index,
                                                               format::HandleId         device_id,
                                                               format::HandleId         pipeline_id,
                                                               size_t                   data_size,
                                                               const uint8_t*           data) override;

    virtual void
    ProcessSetSwapchainImageStateCommand(format::CommandIndexType                            command_index,
                                         format::HandleId                                    device_id,
                                         format::HandleId                                    swapchain_id,
                                         uint32_t                                            last_presented_image,
                                         const std::vector<format::SwapchainImageStateInfo>& image_info) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&               call_info,
                                                           format::HandleId                 device,
                                                           format::HandleId                 descriptorSet,
                                                           format::HandleId                 descriptorUpdateTemplate,
                                                           DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                               format::HandleId   commandBuffer,
                                                               format::HandleId   descriptorUpdateTemplate,
                                                               format::HandleId   layout,
                                                               uint32_t           set,
                                                               DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&               call_info,
                                                              format::HandleId                 device,
                                                              format::HandleId                 descriptorSet,
                                                              format::HandleId                 descriptorUpdateTemplate,
                                                              DescriptorUpdateTemplateDecoder* pData) override;

  protected:
    //
    // Replay function overrides provided to the replay consumer code generator with replay_overrides.json
    //

    VkResult OverrideCreateInstance(VkResult                                                   original_result,
                                    const StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                    HandlePointerDecoder<VkInstance>*                          pInstance);

    void OverrideDestroyDevice(PFN_vkDestroyDevice                                        func,
                               const DeviceInfo*                                          device_info,
                               const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideGetPhysicalDeviceSurfaceCapabilitiesKHR(
        PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR           func,
        VkResult                                                original_result,
        PhysicalDeviceInfo*                                     physical_device_info,
        SurfaceKHRInfo*                                         surface_info,
        StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities);

    VkResult OverrideGetPhysicalDeviceSurfaceCapabilities2KHR(
        PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR                 func,
        VkResult                                                       original_result,
        PhysicalDeviceInfo*                                            physical_device_info,
        StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
        StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>*       pSurfaceCapabilities);

    VkResult OverrideWaitForFences(PFN_vkWaitForFences                  func,
                                   VkResult                             original_result,
                                   const DeviceInfo*                    device_info,
                                   uint32_t                             fenceCount,
                                   const HandlePointerDecoder<VkFence>* pFences,
                                   VkBool32                             waitAll,
                                   uint64_t                             timeout);

    VkResult OverrideQueueSubmit(PFN_vkQueueSubmit                                 func,
                                 VkResult                                          original_result,
                                 const QueueInfo*                                  queue_info,
                                 uint32_t                                          submitCount,
                                 const StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                 const FenceInfo*                                  fence_info);

    VkResult OverrideQueueSubmit2(PFN_vkQueueSubmit2                                 func,
                                  VkResult                                           original_result,
                                  const QueueInfo*                                   queue_info,
                                  uint32_t                                           submitCount,
                                  const StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                  const FenceInfo*                                   fence_info);

    VkResult OverrideQueueBindSparse(PFN_vkQueueBindSparse                                 func,
                                     VkResult                                              original_result,
                                     const QueueInfo*                                      queue_info,
                                     uint32_t                                              bindInfoCount,
                                     const StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
                                     const FenceInfo*                                      fence_info);

    VkResult OverrideCreateRenderPass(PFN_vkCreateRenderPass                                      func,
                                      VkResult                                                    original_result,
                                      const DeviceInfo*                                           device_info,
                                      const StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
                                      const StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
                                      HandlePointerDecoder<VkRenderPass>*                         pRenderPass);

    VkResult OverrideCreateRenderPass2(PFN_vkCreateRenderPass2                                      func,
                                       VkResult                                                     original_result,
                                       const DeviceInfo*                                            device_info,
                                       const StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
                                       const StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                       HandlePointerDecoder<VkRenderPass>*                          pRenderPass);

    void OverrideCmdPipelineBarrier(PFN_vkCmdPipelineBarrier                                   func,
                                    const CommandBufferInfo*                                   command_buffer_info,
                                    VkPipelineStageFlags                                       srcStageMask,
                                    VkPipelineStageFlags                                       dstStageMask,
                                    VkDependencyFlags                                          dependencyFlags,
                                    uint32_t                                                   memoryBarrierCount,
                                    const StructPointerDecoder<Decoded_VkMemoryBarrier>*       pMemoryBarriers,
                                    uint32_t                                                   bufferMemoryBarrierCount,
                                    const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
                                    uint32_t                                                   imageMemoryBarrierCount,
                                    const StructPointerDecoder<Decoded_VkImageMemoryBarrier>*  pImageMemoryBarriers);

    VkResult OverrideCreateShaderModule(PFN_vkCreateShaderModule                                      func,
                                        VkResult                                                      original_result,
                                        const DeviceInfo*                                             device_info,
                                        const StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
                                        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
                                        HandlePointerDecoder<VkShaderModule>*                         pShaderModule);

    VkResult OverrideGetPipelineCacheData(PFN_vkGetPipelineCacheData func,
                                          VkResult                   original_result,
                                          const DeviceInfo*          device_info,
                                          const PipelineCacheInfo*   pipeline_cache_info,
                                          PointerDecoder<size_t>*    pDataSize,
                                          PointerDecoder<uint8_t>*   pData);

    VkResult OverrideCreateDebugReportCallbackEXT(
        PFN_vkCreateDebugReportCallbackEXT                                      func,
        VkResult                                                                original_result,
        const InstanceInfo*                                                     instance_info,
        const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*              pAllocator,
        HandlePointerDecoder<VkDebugReportCallbackEXT>*                         pCallback);

    VkResult OverrideCreateDebugUtilsMessengerEXT(
        PFN_vkCreateDebugUtilsMessengerEXT                                      func,
        VkResult                                                                original_result,
        const InstanceInfo*                                                     instance_info,
        const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*              pAllocator,
        HandlePointerDecoder<VkDebugUtilsMessengerEXT>*                         pMessenger);

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

    VkResult OverrideAcquireNextImage2KHR(PFN_vkAcquireNextImage2KHR func,
                                          VkResult                   original_result,
                                          const DeviceInfo*          device_info,
                                          const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
                                          PointerDecoder<uint32_t>*                                      pImageIndex);

    VkResult OverrideQueuePresentKHR(PFN_vkQueuePresentKHR                                 func,
                                     VkResult                                              original_result,
                                     const QueueInfo*                                      queue_info,
                                     const StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo);

    VkResult OverrideImportSemaphoreFdKHR(
        PFN_vkImportSemaphoreFdKHR                                      func,
        VkResult                                                        original_result,
        const DeviceInfo*                                               device_info,
        const StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo);

    VkResult OverrideGetSemaphoreFdKHR(PFN_vkGetSemaphoreFdKHR                                      func,
                                       VkResult                                                     original_result,
                                       const DeviceInfo*                                            device_info,
                                       const StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
                                       const PointerDecoder<int>*                                   pFd);

    VkResult OverrideImportSemaphoreWin32HandleKHR(
        PFN_vkImportSemaphoreWin32HandleKHR                                      func,
        VkResult                                                                 original_result,
        const DeviceInfo*                                                        device_info,
        const StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo);

    VkResult OverrideGetSemaphoreWin32HandleKHR(
        PFN_vkGetSemaphoreWin32HandleKHR                                      func,
        VkResult                                                              original_result,
        const DeviceInfo*                                                     device_info,
        const StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
        const PointerDecoder<uint64_t, void*>*                                pHandle);

    VkResult OverrideGetRandROutputDisplayEXT(PFN_vkGetRandROutputDisplayEXT      func,
                                              VkResult                            original_result,
                                              const PhysicalDeviceInfo*           physicalDevice,
                                              Display*                            dpy,
                                              RROutput                            rrOutput,
                                              HandlePointerDecoder<VkDisplayKHR>* pDisplay);

    // Window/Surface related overrides, which can transform the window/surface type from the platform
    // specific type found in the trace file to the platform specific type used for replay.
    VkResult
    OverrideCreateAndroidSurfaceKHR(PFN_vkCreateAndroidSurfaceKHR                                      func,
                                    VkResult                                                           original_result,
                                    InstanceInfo*                                                      instance_info,
                                    const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
                                    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface);

    VkResult OverrideCreateWin32SurfaceKHR(PFN_vkCreateWin32SurfaceKHR func,
                                           VkResult                    original_result,
                                           InstanceInfo*               instance_info,
                                           const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
                                           const StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
                                           HandlePointerDecoder<VkSurfaceKHR>*                              pSurface);

    VkBool32
    OverrideGetPhysicalDeviceWin32PresentationSupportKHR(PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR func,
                                                         const PhysicalDeviceInfo* physical_device_info,
                                                         uint32_t                  queueFamilyIndex);

    VkResult OverrideCreateXcbSurfaceKHR(PFN_vkCreateXcbSurfaceKHR                                      func,
                                         VkResult                                                       original_result,
                                         InstanceInfo*                                                  instance_info,
                                         const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
                                         const StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
                                         HandlePointerDecoder<VkSurfaceKHR>*                            pSurface);

    VkBool32 OverrideGetPhysicalDeviceXcbPresentationSupportKHR(PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR func,
                                                                const PhysicalDeviceInfo* physical_device_info,
                                                                uint32_t                  queueFamilyIndex,
                                                                xcb_connection_t*         connection,
                                                                xcb_visualid_t            visual_id);

    VkResult OverrideCreateXlibSurfaceKHR(PFN_vkCreateXlibSurfaceKHR func,
                                          VkResult                   original_result,
                                          InstanceInfo*              instance_info,
                                          const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
                                          const StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
                                          HandlePointerDecoder<VkSurfaceKHR>*                             pSurface);

    VkBool32 OverrideGetPhysicalDeviceXlibPresentationSupportKHR(PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR func,
                                                                 const PhysicalDeviceInfo* physical_device_info,
                                                                 uint32_t                  queueFamilyIndex,
                                                                 Display*                  dpy,
                                                                 VisualID                  visualID);

    VkResult
    OverrideCreateWaylandSurfaceKHR(PFN_vkCreateWaylandSurfaceKHR                                      func,
                                    VkResult                                                           original_result,
                                    InstanceInfo*                                                      instance_info,
                                    const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
                                    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface);

    VkBool32
    OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR func,
                                                           const PhysicalDeviceInfo* physical_device_info,
                                                           uint32_t                  queueFamilyIndex,
                                                           struct wl_display*        display);

    void OverrideDestroySurfaceKHR(PFN_vkDestroySurfaceKHR                                    func,
                                   InstanceInfo*                                              instance_info,
                                   const SurfaceKHRInfo*                                      surface_info,
                                   const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideCreateAccelerationStructureKHR(
        PFN_vkCreateAccelerationStructureKHR                                      func,
        VkResult                                                                  original_result,
        const DeviceInfo*                                                         device_info,
        const StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkAccelerationStructureKHR>*                         pAccelerationStructureKHR);

    VkResult OverrideCreateRayTracingPipelinesKHR(
        PFN_vkCreateRayTracingPipelinesKHR                                     func,
        VkResult                                                               original_result,
        const DeviceInfo*                                                      device_info,
        DeferredOperationKHRInfo*                                              deferred_operation_info,
        const PipelineCacheInfo*                                               pipeline_cache_info,
        uint32_t                                                               createInfoCount,
        const StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*             pAllocator,
        HandlePointerDecoder<VkPipeline>*                                      pPipelines);

    VkResult OverrideDeferredOperationJoinKHR(PFN_vkDeferredOperationJoinKHR func,
                                              VkResult                       original_result,
                                              const DeviceInfo*              device_info,
                                              DeferredOperationKHRInfo*      deferred_operation_info);

    VkDeviceAddress
    OverrideGetBufferDeviceAddress(PFN_vkGetBufferDeviceAddress                                   func,
                                   const DeviceInfo*                                              device_info,
                                   const StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo);

    void OverrideGetAccelerationStructureDeviceAddressKHR(
        PFN_vkGetAccelerationStructureDeviceAddressKHR                                   func,
        const DeviceInfo*                                                                device_info,
        const StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo);

    VkResult OverrideGetRayTracingShaderGroupHandlesKHR(PFN_vkGetRayTracingShaderGroupHandlesKHR func,
                                                        VkResult                                 original_result,
                                                        const DeviceInfo*                        device_info,
                                                        const PipelineInfo*                      pipeline_info,
                                                        uint32_t                                 firstGroup,
                                                        uint32_t                                 groupCount,
                                                        size_t                                   dataSize,
                                                        PointerDecoder<uint8_t>*                 pData);
    VkResult OverrideGetAndroidHardwareBufferPropertiesANDROID(
        PFN_vkGetAndroidHardwareBufferPropertiesANDROID                         func,
        VkResult                                                                original_result,
        const DeviceInfo*                                                       device_info,
        const struct AHardwareBuffer*                                           hardware_buffer,
        StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties);

  private:
    VkResult CreateSurface(InstanceInfo*                       instance_info,
                           const std::string&                  wsi_extension,
                           VkFlags                             flags,
                           HandlePointerDecoder<VkSurfaceKHR>* surface);

    void MapDescriptorUpdateTemplateHandles(const DescriptorUpdateTemplateInfo* update_template_info,
                                            DescriptorUpdateTemplateDecoder*    decoder);

    void ProcessCreateInstanceDebugCallbackInfo(const Decoded_VkInstanceCreateInfo* instance_info);

    void ProcessSwapchainFullScreenExclusiveInfo(const Decoded_VkSwapchainCreateInfoKHR* swapchain_info);

    void ProcessImportAndroidHardwareBufferInfo(const Decoded_VkMemoryAllocateInfo* allocate_info);

    void SetSwapchainWindowSize(const Decoded_VkSwapchainCreateInfoKHR* swapchain_info);

    void InitializeScreenshotHandler();

    void WriteScreenshots(const Decoded_VkPresentInfoKHR* meta_info) const;

  private:
    typedef std::unordered_set<Window*> ActiveWindows;

    std::shared_ptr<application::Application> application_;
    ActiveWindows                             active_windows_;
    bool                                      loading_trim_state_;
    bool                                      have_imported_semaphores_;
    SwapchainImageTracker                     swapchain_image_tracker_;
    std::unique_ptr<ScreenshotHandler>        screenshot_handler_;
    std::unique_ptr<VulkanSwapchain>          swapchain_;
    std::string                               screenshot_file_prefix_;
    int32_t                                   create_surface_count_;
    graphics::FpsInfo*                        fps_info_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_CONSUMER_BASE_H
