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

#include "decode/vulkan_frame_inspector_consumer_base.h"
#include "graphics/vulkan_util.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "decode/vulkan_enum_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateInstance(
    VkResult                                                   original_result,
    const StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*                          pInstance)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    return VulkanReplayConsumerBase::OverrideCreateInstance(original_result, pCreateInfo, pAllocator, pInstance);
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateDevice(
    VkResult                                                   original_result,
    PhysicalDeviceInfo*                                        physical_device_info,
    const StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*                            pDevice)
{
    return VulkanReplayConsumerBase::OverrideCreateDevice(
        original_result, physical_device_info, pCreateInfo, pAllocator, pDevice);
}

void VulkanFrameInspectorConsumerBase::OverrideBeginCommandBuffer(
    PFN_vkBeginCommandBuffer                                      func,
    VkResult                                                      original_result,
    CommandBufferInfo*                                            commandBuffer,
    const StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    commandBuffer->state        = kRecording;
    commandBuffer->begin_result = original_result;
    // commandBuffer->command_list.empty();
}

//
//
//
//
//
//
//
//

void VulkanFrameInspectorConsumerBase::OverrideDestroyDevice(
    PFN_vkDestroyDevice                                        func,
    const DeviceInfo*                                          device_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideEnumeratePhysicalDevices(
    PFN_vkEnumeratePhysicalDevices          func,
    VkResult                                original_result,
    InstanceInfo*                           instance_info,
    PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideEnumeratePhysicalDeviceGroups(
    PFN_vkEnumeratePhysicalDeviceGroups                            func,
    VkResult                                                       original_result,
    InstanceInfo*                                                  instance_info,
    PointerDecoder<uint32_t>*                                      pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideGetPhysicalDeviceProperties(
    PFN_vkGetPhysicalDeviceProperties                         func,
    PhysicalDeviceInfo*                                       physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    // return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideGetPhysicalDeviceProperties2(
    PFN_vkGetPhysicalDeviceProperties2                         func,
    PhysicalDeviceInfo*                                        physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    // return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideGetPhysicalDeviceMemoryProperties(
    PFN_vkGetPhysicalDeviceMemoryProperties                         func,
    PhysicalDeviceInfo*                                             physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    // return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideGetPhysicalDeviceMemoryProperties2(
    PFN_vkGetPhysicalDeviceMemoryProperties2                         func,
    PhysicalDeviceInfo*                                              physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    // return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideGetPhysicalDeviceSurfaceCapabilitiesKHR(
    PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR           func,
    VkResult                                                original_result,
    PhysicalDeviceInfo*                                     physical_device_info,
    SurfaceKHRInfo*                                         surface_info,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideGetPhysicalDeviceSurfaceCapabilities2KHR(
    PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR                 func,
    VkResult                                                       original_result,
    PhysicalDeviceInfo*                                            physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>*       pSurfaceCapabilities)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideWaitForFences(PFN_vkWaitForFences                  func,
                                                                 VkResult                             original_result,
                                                                 const DeviceInfo*                    device_info,
                                                                 uint32_t                             fenceCount,
                                                                 const HandlePointerDecoder<VkFence>* pFences,
                                                                 VkBool32                             waitAll,
                                                                 uint64_t                             timeout)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideGetFenceStatus(PFN_vkGetFenceStatus func,
                                                                  VkResult             original_result,
                                                                  const DeviceInfo*    device_info,
                                                                  const FenceInfo*     fence_info)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideGetEventStatus(PFN_vkGetEventStatus func,
                                                                  VkResult             original_result,
                                                                  const DeviceInfo*    device_info,
                                                                  const EventInfo*     event_info)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideGetQueryPoolResults(PFN_vkGetQueryPoolResults func,
                                                                       VkResult                  original_result,
                                                                       const DeviceInfo*         device_info,
                                                                       const QueryPoolInfo*      query_pool_info,
                                                                       uint32_t                  firstQuery,
                                                                       uint32_t                  queryCount,
                                                                       size_t                    dataSize,
                                                                       PointerDecoder<uint8_t>*  pData,
                                                                       VkDeviceSize              stride,
                                                                       VkQueryResultFlags        flags)
{
    return VK_SUCCESS;
}

VkResult
VulkanFrameInspectorConsumerBase::OverrideQueueSubmit(PFN_vkQueueSubmit                                 func,
                                                      VkResult                                          original_result,
                                                      const QueueInfo*                                  queue_info,
                                                      uint32_t                                          submitCount,
                                                      const StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                                      const FenceInfo*                                  fence_info)
{
    return VK_SUCCESS;
}

VkResult
VulkanFrameInspectorConsumerBase::OverrideQueueSubmit2(PFN_vkQueueSubmit2 func,
                                                       VkResult           original_result,
                                                       const QueueInfo*   queue_info,
                                                       uint32_t           submitCount,
                                                       const StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                                       const FenceInfo*                                   fence_info)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideQueueBindSparse(
    PFN_vkQueueBindSparse                                 func,
    VkResult                                              original_result,
    const QueueInfo*                                      queue_info,
    uint32_t                                              bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
    const FenceInfo*                                      fence_info)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateDescriptorPool(
    PFN_vkCreateDescriptorPool                                      func,
    VkResult                                                        original_result,
    const DeviceInfo*                                               device_info,
    const StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*                         pDescriptorPool)
{
    return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideDestroyDescriptorPool(
    PFN_vkDestroyDescriptorPool                                func,
    const DeviceInfo*                                          device_info,
    DescriptorPoolInfo*                                        descriptor_pool_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideAllocateDescriptorSets(
    PFN_vkAllocateDescriptorSets                                     func,
    VkResult                                                         original_result,
    const DeviceInfo*                                                device_info,
    const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*                           pDescriptorSets)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideAllocateCommandBuffers(
    PFN_vkAllocateCommandBuffers                                     func,
    VkResult                                                         original_result,
    const DeviceInfo*                                                device_info,
    const StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*                           pCommandBuffers)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideAllocateMemory(
    PFN_vkAllocateMemory                                       func,
    VkResult                                                   original_result,
    const DeviceInfo*                                          device_info,
    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  pAllocateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*                      pMemory)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideMapMemory(PFN_vkMapMemory   func,
                                                             VkResult          original_result,
                                                             const DeviceInfo* device_info,
                                                             DeviceMemoryInfo* memory_info,
                                                             VkDeviceSize      offset,
                                                             VkDeviceSize      size,
                                                             VkMemoryMapFlags  flags,
                                                             void**            ppData)
{
    return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideUnmapMemory(PFN_vkUnmapMemory func,
                                                           const DeviceInfo* device_info,
                                                           DeviceMemoryInfo* memory_info)
{
    // return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideFlushMappedMemoryRanges(
    PFN_vkFlushMappedMemoryRanges                            func,
    VkResult                                                 original_result,
    const DeviceInfo*                                        device_info,
    uint32_t                                                 memoryRangeCount,
    const StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideInvalidateMappedMemoryRanges(
    PFN_vkInvalidateMappedMemoryRanges                       func,
    VkResult                                                 original_result,
    const DeviceInfo*                                        device_info,
    uint32_t                                                 memoryRangeCount,
    const StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideFreeMemory(
    PFN_vkFreeMemory                                           func,
    const DeviceInfo*                                          device_info,
    DeviceMemoryInfo*                                          memory_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideBindBufferMemory(PFN_vkBindBufferMemory func,
                                                                    VkResult               original_result,
                                                                    const DeviceInfo*      device_info,
                                                                    BufferInfo*            buffer_info,
                                                                    DeviceMemoryInfo*      memory_info,
                                                                    VkDeviceSize           memoryOffset)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideBindBufferMemory2(
    PFN_vkBindBufferMemory2                                     func,
    VkResult                                                    original_result,
    const DeviceInfo*                                           device_info,
    uint32_t                                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideBindImageMemory(PFN_vkBindImageMemory func,
                                                                   VkResult              original_result,
                                                                   const DeviceInfo*     device_info,
                                                                   ImageInfo*            image_info,
                                                                   DeviceMemoryInfo*     memory_info,
                                                                   VkDeviceSize          memoryOffset)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideBindImageMemory2(
    PFN_vkBindImageMemory2                                     func,
    VkResult                                                   original_result,
    const DeviceInfo*                                          device_info,
    uint32_t                                                   bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateBuffer(
    PFN_vkCreateBuffer                                         func,
    VkResult                                                   original_result,
    const DeviceInfo*                                          device_info,
    const StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*                            pBuffer)
{
    return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideDestroyBuffer(
    PFN_vkDestroyBuffer                                        func,
    const DeviceInfo*                                          device_info,
    BufferInfo*                                                buffer_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateImage(
    PFN_vkCreateImage                                          func,
    VkResult                                                   original_result,
    const DeviceInfo*                                          device_info,
    const StructPointerDecoder<Decoded_VkImageCreateInfo>*     pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*                             pImage)
{
    return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideDestroyImage(
    PFN_vkDestroyImage                                         func,
    const DeviceInfo*                                          device_info,
    ImageInfo*                                                 image_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideGetImageSubresourceLayout(
    PFN_vkGetImageSubresourceLayout                         func,
    const DeviceInfo*                                       device_info,
    const ImageInfo*                                        image_info,
    const StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>*      pLayout)
{
    // return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateRenderPass(
    PFN_vkCreateRenderPass                                      func,
    VkResult                                                    original_result,
    const DeviceInfo*                                           device_info,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
    HandlePointerDecoder<VkRenderPass>*                         pRenderPass)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateRenderPass2(
    PFN_vkCreateRenderPass2                                      func,
    VkResult                                                     original_result,
    const DeviceInfo*                                            device_info,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
    HandlePointerDecoder<VkRenderPass>*                          pRenderPass)
{
    return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideCmdPipelineBarrier(
    PFN_vkCmdPipelineBarrier                                   func,
    const CommandBufferInfo*                                   command_buffer_info,
    VkPipelineStageFlags                                       srcStageMask,
    VkPipelineStageFlags                                       dstStageMask,
    VkDependencyFlags                                          dependencyFlags,
    uint32_t                                                   memoryBarrierCount,
    const StructPointerDecoder<Decoded_VkMemoryBarrier>*       pMemoryBarriers,
    uint32_t                                                   bufferMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
    uint32_t                                                   imageMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkImageMemoryBarrier>*  pImageMemoryBarriers)
{
    // return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateDescriptorUpdateTemplate(
    PFN_vkCreateDescriptorUpdateTemplate                                      func,
    VkResult                                                                  original_result,
    const DeviceInfo*                                                         device_info,
    const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>*                         pDescriptorUpdateTemplate)
{
    return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideDestroyDescriptorUpdateTemplate(
    PFN_vkDestroyDescriptorUpdateTemplate                      func,
    const DeviceInfo*                                          device_info,
    const DescriptorUpdateTemplateInfo*                        descriptor_update_template_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateShaderModule(
    PFN_vkCreateShaderModule                                      func,
    VkResult                                                      original_result,
    const DeviceInfo*                                             device_info,
    const StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkShaderModule>*                         pShaderModule)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideGetPipelineCacheData(PFN_vkGetPipelineCacheData func,
                                                                        VkResult                   original_result,
                                                                        const DeviceInfo*          device_info,
                                                                        const PipelineCacheInfo*   pipeline_cache_info,
                                                                        PointerDecoder<size_t>*    pDataSize,
                                                                        PointerDecoder<uint8_t>*   pData)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreatePipelineCache(
    PFN_vkCreatePipelineCache                                      func,
    VkResult                                                       original_result,
    const DeviceInfo*                                              device_info,
    const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkPipelineCache>*                         pPipelineCache)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideResetDescriptorPool(PFN_vkResetDescriptorPool  func,
                                                                       VkResult                   original_result,
                                                                       const DeviceInfo*          device_info,
                                                                       DescriptorPoolInfo*        pool_info,
                                                                       VkDescriptorPoolResetFlags flags)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateDebugReportCallbackEXT(
    PFN_vkCreateDebugReportCallbackEXT                                      func,
    VkResult                                                                original_result,
    const InstanceInfo*                                                     instance_info,
    const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*              pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>*                         pCallback)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateDebugUtilsMessengerEXT(
    PFN_vkCreateDebugUtilsMessengerEXT                                      func,
    VkResult                                                                original_result,
    const InstanceInfo*                                                     instance_info,
    const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*              pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>*                         pMessenger)
{
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
    return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideDestroySwapchainKHR(
    PFN_vkDestroySwapchainKHR                                  func,
    DeviceInfo*                                                device_info,
    SwapchainKHRInfo*                                          swapchain_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // return VK_SUCCESS;
}

VkResult
VulkanFrameInspectorConsumerBase::OverrideGetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR    func,
                                                                VkResult                       original_result,
                                                                const DeviceInfo*              device_info,
                                                                SwapchainKHRInfo*              swapchain_info,
                                                                PointerDecoder<uint32_t>*      pSwapchainImageCount,
                                                                HandlePointerDecoder<VkImage>* pSwapchainImages)
{
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
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideAcquireNextImage2KHR(
    PFN_vkAcquireNextImage2KHR                                     func,
    VkResult                                                       original_result,
    const DeviceInfo*                                              device_info,
    const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                                      pImageIndex)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideQueuePresentKHR(
    PFN_vkQueuePresentKHR                                 func,
    VkResult                                              original_result,
    const QueueInfo*                                      queue_info,
    const StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideImportSemaphoreFdKHR(
    PFN_vkImportSemaphoreFdKHR                                      func,
    VkResult                                                        original_result,
    const DeviceInfo*                                               device_info,
    const StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideGetSemaphoreFdKHR(
    PFN_vkGetSemaphoreFdKHR                                      func,
    VkResult                                                     original_result,
    const DeviceInfo*                                            device_info,
    const StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    const PointerDecoder<int>*                                   pFd)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideImportSemaphoreWin32HandleKHR(
    PFN_vkImportSemaphoreWin32HandleKHR                                      func,
    VkResult                                                                 original_result,
    const DeviceInfo*                                                        device_info,
    const StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideGetSemaphoreWin32HandleKHR(
    PFN_vkGetSemaphoreWin32HandleKHR                                      func,
    VkResult                                                              original_result,
    const DeviceInfo*                                                     device_info,
    const StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    const PointerDecoder<uint64_t, void*>*                                pHandle)
{
    return VK_SUCCESS;
}

VkResult
VulkanFrameInspectorConsumerBase::OverrideGetRandROutputDisplayEXT(PFN_vkGetRandROutputDisplayEXT      func,
                                                                   VkResult                            original_result,
                                                                   const PhysicalDeviceInfo*           physicalDevice,
                                                                   Display*                            dpy,
                                                                   RROutput                            rrOutput,
                                                                   HandlePointerDecoder<VkDisplayKHR>* pDisplay)
{
    return VK_SUCCESS;
}

// Window/Surface related overrides, which can transform the window/surface type from the platform
// specific type found in the trace file to the platform specific type used for replay.
VkResult VulkanFrameInspectorConsumerBase::OverrideCreateAndroidSurfaceKHR(
    PFN_vkCreateAndroidSurfaceKHR                                      func,
    VkResult                                                           original_result,
    InstanceInfo*                                                      instance_info,
    const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateWin32SurfaceKHR(
    PFN_vkCreateWin32SurfaceKHR                                      func,
    VkResult                                                         original_result,
    InstanceInfo*                                                    instance_info,
    const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                              pSurface)
{
    return VK_SUCCESS;
}

VkBool32 VulkanFrameInspectorConsumerBase::OverrideGetPhysicalDeviceWin32PresentationSupportKHR(
    PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR func,
    const PhysicalDeviceInfo*                          physical_device_info,
    uint32_t                                           queueFamilyIndex)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateXcbSurfaceKHR(
    PFN_vkCreateXcbSurfaceKHR                                      func,
    VkResult                                                       original_result,
    InstanceInfo*                                                  instance_info,
    const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                            pSurface)
{
    return VK_SUCCESS;
}

VkBool32 VulkanFrameInspectorConsumerBase::OverrideGetPhysicalDeviceXcbPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR func,
    const PhysicalDeviceInfo*                        physical_device_info,
    uint32_t                                         queueFamilyIndex,
    xcb_connection_t*                                connection,
    xcb_visualid_t                                   visual_id)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateXlibSurfaceKHR(
    PFN_vkCreateXlibSurfaceKHR                                      func,
    VkResult                                                        original_result,
    InstanceInfo*                                                   instance_info,
    const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                             pSurface)
{
    return VK_SUCCESS;
}

VkBool32 VulkanFrameInspectorConsumerBase::OverrideGetPhysicalDeviceXlibPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR func,
    const PhysicalDeviceInfo*                         physical_device_info,
    uint32_t                                          queueFamilyIndex,
    Display*                                          dpy,
    VisualID                                          visualID)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateWaylandSurfaceKHR(
    PFN_vkCreateWaylandSurfaceKHR                                      func,
    VkResult                                                           original_result,
    InstanceInfo*                                                      instance_info,
    const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface)
{
    return VK_SUCCESS;
}

VkBool32 VulkanFrameInspectorConsumerBase::OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR func,
    const PhysicalDeviceInfo*                            physical_device_info,
    uint32_t                                             queueFamilyIndex,
    struct wl_display*                                   display)
{
    return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideDestroySurfaceKHR(
    PFN_vkDestroySurfaceKHR                                    func,
    InstanceInfo*                                              instance_info,
    const SurfaceKHRInfo*                                      surface_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateAccelerationStructureKHR(
    PFN_vkCreateAccelerationStructureKHR                                      func,
    VkResult                                                                  original_result,
    const DeviceInfo*                                                         device_info,
    const StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>*                         pAccelerationStructureKHR)
{
    return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateRayTracingPipelinesKHR(
    PFN_vkCreateRayTracingPipelinesKHR                                     func,
    VkResult                                                               original_result,
    const DeviceInfo*                                                      device_info,
    DeferredOperationKHRInfo*                                              deferred_operation_info,
    const PipelineCacheInfo*                                               pipeline_cache_info,
    uint32_t                                                               createInfoCount,
    const StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*             pAllocator,
    HandlePointerDecoder<VkPipeline>*                                      pPipelines)
{
    return VK_SUCCESS;
}

VkResult
VulkanFrameInspectorConsumerBase::OverrideDeferredOperationJoinKHR(PFN_vkDeferredOperationJoinKHR func,
                                                                   VkResult                       original_result,
                                                                   const DeviceInfo*              device_info,
                                                                   DeferredOperationKHRInfo* deferred_operation_info)
{
    return VK_SUCCESS;
}

VkDeviceAddress VulkanFrameInspectorConsumerBase::OverrideGetBufferDeviceAddress(
    PFN_vkGetBufferDeviceAddress                                   func,
    const DeviceInfo*                                              device_info,
    const StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    return VK_SUCCESS;
}

void VulkanFrameInspectorConsumerBase::OverrideGetAccelerationStructureDeviceAddressKHR(
    PFN_vkGetAccelerationStructureDeviceAddressKHR                                   func,
    const DeviceInfo*                                                                device_info,
    const StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    // return VK_SUCCESS;
}

VkResult VulkanFrameInspectorConsumerBase::OverrideGetRayTracingShaderGroupHandlesKHR(
    PFN_vkGetRayTracingShaderGroupHandlesKHR func,
    VkResult                                 original_result,
    const DeviceInfo*                        device_info,
    const PipelineInfo*                      pipeline_info,
    uint32_t                                 firstGroup,
    uint32_t                                 groupCount,
    size_t                                   dataSize,
    PointerDecoder<uint8_t>*                 pData)
{
    return VK_SUCCESS;
}
VkResult VulkanFrameInspectorConsumerBase::OverrideGetAndroidHardwareBufferPropertiesANDROID(
    PFN_vkGetAndroidHardwareBufferPropertiesANDROID                         func,
    VkResult                                                                original_result,
    const DeviceInfo*                                                       device_info,
    const struct AHardwareBuffer*                                           hardware_buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    return VK_SUCCESS;
}

GFXRECON_END_NAMESPACE(gfxrecon) GFXRECON_END_NAMESPACE(decode)
