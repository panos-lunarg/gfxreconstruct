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

#include "../entrypoints_pre.h"
#include "perfetto_encoder_commands.h"
#include "format/api_call_id.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugins)
GFXRECON_BEGIN_NAMESPACE(plugin_perfetto)
extern "C" {
VKAPI_ATTR void VKAPI_CALL CreateInstance_PreCall(encode::VulkanCaptureManager* manager,
    const VkInstanceCreateInfo*                 pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, pCreateInfo, pAllocator, pInstance); }

VKAPI_ATTR void VKAPI_CALL DestroyInstance_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(manager, instance, pAllocator); }

VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDevices_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(manager, instance, pPhysicalDeviceCount, pPhysicalDevices); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures*                   pFeatures)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(manager, physicalDevice, pFeatures); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties*                         pFormatProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(manager, physicalDevice, format, pFormatProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkImageFormatProperties*                    pImageFormatProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties*                 pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(manager, physicalDevice, pProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties*                    pQueueFamilyProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(manager, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties*           pMemoryProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(manager, physicalDevice, pMemoryProperties); }

VKAPI_ATTR void VKAPI_CALL CreateDevice_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(manager, physicalDevice, pCreateInfo, pAllocator, pDevice); }

VKAPI_ATTR void VKAPI_CALL DestroyDevice_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(manager, device, pAllocator); }

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    VkQueue*                                    pQueue)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(manager, device, queueFamilyIndex, queueIndex, pQueue); }

VKAPI_ATTR void VKAPI_CALL QueueSubmit_PreCall(encode::VulkanCaptureManager* manager,
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo*                         pSubmits,
    VkFence                                     fence)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, queue, submitCount, pSubmits, fence); }

VKAPI_ATTR void VKAPI_CALL QueueWaitIdle_PreCall(encode::VulkanCaptureManager* manager,
    VkQueue                                     queue)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(manager, queue); }

VKAPI_ATTR void VKAPI_CALL DeviceWaitIdle_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(manager, device); }

VKAPI_ATTR void VKAPI_CALL AllocateMemory_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDeviceMemory*                             pMemory)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(manager, device, pAllocateInfo, pAllocator, pMemory); }

VKAPI_ATTR void VKAPI_CALL FreeMemory_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(manager, device, memory, pAllocator); }

VKAPI_ATTR void VKAPI_CALL MapMemory_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    void**                                      ppData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(manager, device, memory, offset, size, flags, ppData); }

VKAPI_ATTR void VKAPI_CALL UnmapMemory_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeviceMemory                              memory)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(manager, device, memory); }

VKAPI_ATTR void VKAPI_CALL FlushMappedMemoryRanges_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(manager, device, memoryRangeCount, pMemoryRanges); }

VKAPI_ATTR void VKAPI_CALL InvalidateMappedMemoryRanges_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(manager, device, memoryRangeCount, pMemoryRanges); }

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize*                               pCommittedMemoryInBytes)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(manager, device, memory, pCommittedMemoryInBytes); }

VKAPI_ATTR void VKAPI_CALL BindBufferMemory_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(manager, device, buffer, memory, memoryOffset); }

VKAPI_ATTR void VKAPI_CALL BindImageMemory_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(manager, device, image, memory, memoryOffset); }

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkMemoryRequirements*                       pMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(manager, device, buffer, pMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkImage                                     image,
    VkMemoryRequirements*                       pMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(manager, device, image, pMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkImage                                     image,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements*            pSparseMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(manager, device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties*              pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties); }

VKAPI_ATTR void VKAPI_CALL QueueBindSparse_PreCall(encode::VulkanCaptureManager* manager,
    VkQueue                                     queue,
    uint32_t                                    bindInfoCount,
    const VkBindSparseInfo*                     pBindInfo,
    VkFence                                     fence)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(manager, queue, bindInfoCount, pBindInfo, fence); }

VKAPI_ATTR void VKAPI_CALL CreateFence_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(manager, device, pCreateInfo, pAllocator, pFence); }

VKAPI_ATTR void VKAPI_CALL DestroyFence_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkFence                                     fence,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(manager, device, fence, pAllocator); }

VKAPI_ATTR void VKAPI_CALL ResetFences_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(manager, device, fenceCount, pFences); }

VKAPI_ATTR void VKAPI_CALL GetFenceStatus_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkFence                                     fence)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(manager, device, fence); }

VKAPI_ATTR void VKAPI_CALL WaitForFences_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(manager, device, fenceCount, pFences, waitAll, timeout); }

VKAPI_ATTR void VKAPI_CALL CreateSemaphore_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphore*                                pSemaphore)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(manager, device, pCreateInfo, pAllocator, pSemaphore); }

VKAPI_ATTR void VKAPI_CALL DestroySemaphore_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(manager, device, semaphore, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CreateEvent_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkEvent*                                    pEvent)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(manager, device, pCreateInfo, pAllocator, pEvent); }

VKAPI_ATTR void VKAPI_CALL DestroyEvent_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkEvent                                     event,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(manager, device, event, pAllocator); }

VKAPI_ATTR void VKAPI_CALL GetEventStatus_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkEvent                                     event)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(manager, device, event); }

VKAPI_ATTR void VKAPI_CALL SetEvent_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkEvent                                     event)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(manager, device, event); }

VKAPI_ATTR void VKAPI_CALL ResetEvent_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkEvent                                     event)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(manager, device, event); }

VKAPI_ATTR void VKAPI_CALL CreateQueryPool_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkQueryPool*                                pQueryPool)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(manager, device, pCreateInfo, pAllocator, pQueryPool); }

VKAPI_ATTR void VKAPI_CALL DestroyQueryPool_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(manager, device, queryPool, pAllocator); }

VKAPI_ATTR void VKAPI_CALL GetQueryPoolResults_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    void*                                       pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(manager, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags); }

VKAPI_ATTR void VKAPI_CALL CreateBuffer_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBuffer*                                   pBuffer)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(manager, device, pCreateInfo, pAllocator, pBuffer); }

VKAPI_ATTR void VKAPI_CALL DestroyBuffer_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(manager, device, buffer, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CreateBufferView_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferView*                               pView)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(manager, device, pCreateInfo, pAllocator, pView); }

VKAPI_ATTR void VKAPI_CALL DestroyBufferView_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkBufferView                                bufferView,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(manager, device, bufferView, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CreateImage_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImage*                                    pImage)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(manager, device, pCreateInfo, pAllocator, pImage); }

VKAPI_ATTR void VKAPI_CALL DestroyImage_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkImage                                     image,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(manager, device, image, pAllocator); }

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource*                   pSubresource,
    VkSubresourceLayout*                        pLayout)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(manager, device, image, pSubresource, pLayout); }

VKAPI_ATTR void VKAPI_CALL CreateImageView_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImageView*                                pView)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(manager, device, pCreateInfo, pAllocator, pView); }

VKAPI_ATTR void VKAPI_CALL DestroyImageView_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkImageView                                 imageView,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(manager, device, imageView, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CreateShaderModule_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkShaderModule*                             pShaderModule)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(manager, device, pCreateInfo, pAllocator, pShaderModule); }

VKAPI_ATTR void VKAPI_CALL DestroyShaderModule_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(manager, device, shaderModule, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CreatePipelineCache_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineCache*                            pPipelineCache)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(manager, device, pCreateInfo, pAllocator, pPipelineCache); }

VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(manager, device, pipelineCache, pAllocator); }

VKAPI_ATTR void VKAPI_CALL GetPipelineCacheData_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(manager, device, pipelineCache, pDataSize, pData); }

VKAPI_ATTR void VKAPI_CALL MergePipelineCaches_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipelineCache                             dstCache,
    uint32_t                                    srcCacheCount,
    const VkPipelineCache*                      pSrcCaches)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(manager, device, dstCache, srcCacheCount, pSrcCaches); }

VKAPI_ATTR void VKAPI_CALL CreateGraphicsPipelines_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(manager, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines); }

VKAPI_ATTR void VKAPI_CALL CreateComputePipelines_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(manager, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines); }

VKAPI_ATTR void VKAPI_CALL DestroyPipeline_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(manager, device, pipeline, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CreatePipelineLayout_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineLayout*                           pPipelineLayout)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(manager, device, pCreateInfo, pAllocator, pPipelineLayout); }

VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(manager, device, pipelineLayout, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CreateSampler_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSampler*                                  pSampler)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(manager, device, pCreateInfo, pAllocator, pSampler); }

VKAPI_ATTR void VKAPI_CALL DestroySampler_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSampler                                   sampler,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(manager, device, sampler, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CreateDescriptorSetLayout_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorSetLayout*                      pSetLayout)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(manager, device, pCreateInfo, pAllocator, pSetLayout); }

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(manager, device, descriptorSetLayout, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CreateDescriptorPool_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorPool*                           pDescriptorPool)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(manager, device, pCreateInfo, pAllocator, pDescriptorPool); }

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(manager, device, descriptorPool, pAllocator); }

VKAPI_ATTR void VKAPI_CALL ResetDescriptorPool_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(manager, device, descriptorPool, flags); }

VKAPI_ATTR void VKAPI_CALL AllocateDescriptorSets_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDescriptorSetAllocateInfo*          pAllocateInfo,
    VkDescriptorSet*                            pDescriptorSets)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(manager, device, pAllocateInfo, pDescriptorSets); }

VKAPI_ATTR void VKAPI_CALL FreeDescriptorSets_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(manager, device, descriptorPool, descriptorSetCount, pDescriptorSets); }

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    const VkCopyDescriptorSet*                  pDescriptorCopies)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(manager, device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies); }

VKAPI_ATTR void VKAPI_CALL CreateFramebuffer_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFramebuffer*                              pFramebuffer)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(manager, device, pCreateInfo, pAllocator, pFramebuffer); }

VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(manager, device, framebuffer, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CreateRenderPass_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(manager, device, pCreateInfo, pAllocator, pRenderPass); }

VKAPI_ATTR void VKAPI_CALL DestroyRenderPass_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(manager, device, renderPass, pAllocator); }

VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    VkExtent2D*                                 pGranularity)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(manager, device, renderPass, pGranularity); }

VKAPI_ATTR void VKAPI_CALL CreateCommandPool_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCommandPool*                              pCommandPool)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(manager, device, pCreateInfo, pAllocator, pCommandPool); }

VKAPI_ATTR void VKAPI_CALL DestroyCommandPool_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(manager, device, commandPool, pAllocator); }

VKAPI_ATTR void VKAPI_CALL ResetCommandPool_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(manager, device, commandPool, flags); }

VKAPI_ATTR void VKAPI_CALL AllocateCommandBuffers_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkCommandBufferAllocateInfo*          pAllocateInfo,
    VkCommandBuffer*                            pCommandBuffers)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(manager, device, pAllocateInfo, pCommandBuffers); }

VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(manager, device, commandPool, commandBufferCount, pCommandBuffers); }

VKAPI_ATTR void VKAPI_CALL BeginCommandBuffer_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCommandBufferBeginInfo*             pBeginInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(manager, commandBuffer, pBeginInfo); }

VKAPI_ATTR void VKAPI_CALL EndCommandBuffer_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(manager, commandBuffer); }

VKAPI_ATTR void VKAPI_CALL ResetCommandBuffer_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(manager, commandBuffer, flags); }

VKAPI_ATTR void VKAPI_CALL CmdBindPipeline_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(manager, commandBuffer, pipelineBindPoint, pipeline); }

VKAPI_ATTR void VKAPI_CALL CmdSetViewport_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pViewports); }

VKAPI_ATTR void VKAPI_CALL CmdSetScissor_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(manager, commandBuffer, firstScissor, scissorCount, pScissors); }

VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(manager, commandBuffer, lineWidth); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(manager, commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor); }

VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4])
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(manager, commandBuffer, blendConstants); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(manager, commandBuffer, minDepthBounds, maxDepthBounds); }

VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(manager, commandBuffer, faceMask, compareMask); }

VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(manager, commandBuffer, faceMask, writeMask); }

VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(manager, commandBuffer, faceMask, reference); }

VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(manager, commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets); }

VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(manager, commandBuffer, buffer, offset, indexType); }

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets); }

VKAPI_ATTR void VKAPI_CALL CmdDraw_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(manager, commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance); }

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(manager, commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance); }

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride); }

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride); }

VKAPI_ATTR void VKAPI_CALL CmdDispatch_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(manager, commandBuffer, groupCountX, groupCountY, groupCountZ); }

VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(manager, commandBuffer, buffer, offset); }

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(manager, commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions); }

VKAPI_ATTR void VKAPI_CALL CmdCopyImage_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions); }

VKAPI_ATTR void VKAPI_CALL CmdBlitImage_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter); }

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(manager, commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions); }

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions); }

VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(manager, commandBuffer, dstBuffer, dstOffset, dataSize, pData); }

VKAPI_ATTR void VKAPI_CALL CmdFillBuffer_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(manager, commandBuffer, dstBuffer, dstOffset, size, data); }

VKAPI_ATTR void VKAPI_CALL CmdClearColorImage_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(manager, commandBuffer, image, imageLayout, pColor, rangeCount, pRanges); }

VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(manager, commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges); }

VKAPI_ATTR void VKAPI_CALL CmdClearAttachments_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(manager, commandBuffer, attachmentCount, pAttachments, rectCount, pRects); }

VKAPI_ATTR void VKAPI_CALL CmdResolveImage_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions); }

VKAPI_ATTR void VKAPI_CALL CmdSetEvent_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(manager, commandBuffer, event, stageMask); }

VKAPI_ATTR void VKAPI_CALL CmdResetEvent_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(manager, commandBuffer, event, stageMask); }

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(manager, commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers); }

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(manager, commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers); }

VKAPI_ATTR void VKAPI_CALL CmdBeginQuery_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(manager, commandBuffer, queryPool, query, flags); }

VKAPI_ATTR void VKAPI_CALL CmdEndQuery_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(manager, commandBuffer, queryPool, query); }

VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(manager, commandBuffer, queryPool, firstQuery, queryCount); }

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(manager, commandBuffer, pipelineStage, queryPool, query); }

VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(manager, commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags); }

VKAPI_ATTR void VKAPI_CALL CmdPushConstants_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(manager, commandBuffer, layout, stageFlags, offset, size, pValues); }

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(manager, commandBuffer, pRenderPassBegin, contents); }

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(manager, commandBuffer, contents); }

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(manager, commandBuffer); }

VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(manager, commandBuffer, commandBufferCount, pCommandBuffers); }

VKAPI_ATTR void VKAPI_CALL BindBufferMemory2_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(manager, device, bindInfoCount, pBindInfos); }

VKAPI_ATTR void VKAPI_CALL BindImageMemory2_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(manager, device, bindInfoCount, pBindInfos); }

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(manager, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures); }

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(manager, commandBuffer, deviceMask); }

VKAPI_ATTR void VKAPI_CALL CmdDispatchBase_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(manager, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ); }

VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceGroups_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(manager, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties); }

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(manager, device, pInfo, pMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(manager, device, pInfo, pMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(manager, physicalDevice, pFeatures); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(manager, physicalDevice, pProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(manager, physicalDevice, format, pFormatProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties2_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(manager, physicalDevice, pImageFormatInfo, pImageFormatProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(manager, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(manager, physicalDevice, pMemoryProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(manager, physicalDevice, pFormatInfo, pPropertyCount, pProperties); }

VKAPI_ATTR void VKAPI_CALL TrimCommandPool_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(manager, device, commandPool, flags); }

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDeviceQueueInfo2*                   pQueueInfo,
    VkQueue*                                    pQueue)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(manager, device, pQueueInfo, pQueue); }

VKAPI_ATTR void VKAPI_CALL CreateSamplerYcbcrConversion_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(manager, device, pCreateInfo, pAllocator, pYcbcrConversion); }

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(manager, device, ycbcrConversion, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CreateDescriptorUpdateTemplate_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(manager, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate); }

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(manager, device, descriptorUpdateTemplate, pAllocator); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, physicalDevice, pExternalBufferInfo, pExternalBufferProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager, physicalDevice, pExternalFenceInfo, pExternalFenceProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties); }

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(manager, device, pCreateInfo, pSupport); }

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }

VKAPI_ATTR void VKAPI_CALL CreateRenderPass2_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkRenderPassCreateInfo2*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(manager, device, pCreateInfo, pAllocator, pRenderPass); }

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(manager, commandBuffer, pRenderPassBegin, pSubpassBeginInfo); }

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(manager, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo); }

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(manager, commandBuffer, pSubpassEndInfo); }

VKAPI_ATTR void VKAPI_CALL ResetQueryPool_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(manager, device, queryPool, firstQuery, queryCount); }

VKAPI_ATTR void VKAPI_CALL GetSemaphoreCounterValue_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    uint64_t*                                   pValue)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(manager, device, semaphore, pValue); }

VKAPI_ATTR void VKAPI_CALL WaitSemaphores_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkSemaphoreWaitInfo*                  pWaitInfo,
    uint64_t                                    timeout)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(manager, device, pWaitInfo, timeout); }

VKAPI_ATTR void VKAPI_CALL SignalSemaphore_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkSemaphoreSignalInfo*                pSignalInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(manager, device, pSignalInfo); }

VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddress_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(manager, device, pInfo); }

VKAPI_ATTR void VKAPI_CALL GetBufferOpaqueCaptureAddress_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(manager, device, pInfo); }

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(manager, device, pInfo); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceToolProperties_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pToolCount,
    VkPhysicalDeviceToolProperties*             pToolProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(manager, physicalDevice, pToolCount, pToolProperties); }

VKAPI_ATTR void VKAPI_CALL CreatePrivateDataSlot_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkPrivateDataSlotCreateInfo*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPrivateDataSlot*                          pPrivateDataSlot)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(manager, device, pCreateInfo, pAllocator, pPrivateDataSlot); }

VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPrivateDataSlot                           privateDataSlot,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(manager, device, privateDataSlot, pAllocator); }

VKAPI_ATTR void VKAPI_CALL SetPrivateData_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t                                    data)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(manager, device, objectType, objectHandle, privateDataSlot, data); }

VKAPI_ATTR void VKAPI_CALL GetPrivateData_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t*                                   pData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(manager, device, objectType, objectHandle, privateDataSlot, pData); }

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(manager, commandBuffer, event, pDependencyInfo); }

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(manager, commandBuffer, event, stageMask); }

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(manager, commandBuffer, eventCount, pEvents, pDependencyInfos); }

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(manager, commandBuffer, pDependencyInfo); }

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(manager, commandBuffer, stage, queryPool, query); }

VKAPI_ATTR void VKAPI_CALL QueueSubmit2_PreCall(encode::VulkanCaptureManager* manager,
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo2*                        pSubmits,
    VkFence                                     fence)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2>::Dispatch(manager, queue, submitCount, pSubmits, fence); }

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(manager, commandBuffer, pCopyBufferInfo); }

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(manager, commandBuffer, pCopyImageInfo); }

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(manager, commandBuffer, pCopyBufferToImageInfo); }

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(manager, commandBuffer, pCopyImageToBufferInfo); }

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(manager, commandBuffer, pBlitImageInfo); }

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(manager, commandBuffer, pResolveImageInfo); }

VKAPI_ATTR void VKAPI_CALL CmdBeginRendering_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(manager, commandBuffer, pRenderingInfo); }

VKAPI_ATTR void VKAPI_CALL CmdEndRendering_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(manager, commandBuffer); }

VKAPI_ATTR void VKAPI_CALL CmdSetCullMode_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(manager, commandBuffer, cullMode); }

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(manager, commandBuffer, frontFace); }

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(manager, commandBuffer, primitiveTopology); }

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(manager, commandBuffer, viewportCount, pViewports); }

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(manager, commandBuffer, scissorCount, pScissors); }

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(manager, commandBuffer, depthTestEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(manager, commandBuffer, depthWriteEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(manager, commandBuffer, depthCompareOp); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(manager, commandBuffer, depthBoundsTestEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(manager, commandBuffer, stencilTestEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(manager, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp); }

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(manager, commandBuffer, rasterizerDiscardEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(manager, commandBuffer, depthBiasEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(manager, commandBuffer, primitiveRestartEnable); }

VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirements_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDeviceBufferMemoryRequirements*     pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(manager, device, pInfo, pMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirements_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(manager, device, pInfo, pMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    VkSurfaceKHR                                surface,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(manager, instance, surface, pAllocator); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    VkSurfaceKHR                                surface,
    VkBool32*                                   pSupported)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(manager, physicalDevice, queueFamilyIndex, surface, pSupported); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilitiesKHR*                   pSurfaceCapabilities)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(manager, physicalDevice, surface, pSurfaceCapabilities); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormatKHR*                         pSurfaceFormats)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(manager, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(manager, physicalDevice, surface, pPresentModeCount, pPresentModes); }

VKAPI_ATTR void VKAPI_CALL CreateSwapchainKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkSwapchainCreateInfoKHR*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchain)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pSwapchain); }

VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(manager, device, swapchain, pAllocator); }

VKAPI_ATTR void VKAPI_CALL GetSwapchainImagesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pSwapchainImageCount,
    VkImage*                                    pSwapchainImages)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(manager, device, swapchain, pSwapchainImageCount, pSwapchainImages); }

VKAPI_ATTR void VKAPI_CALL AcquireNextImageKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    timeout,
    VkSemaphore                                 semaphore,
    VkFence                                     fence,
    uint32_t*                                   pImageIndex)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(manager, device, swapchain, timeout, semaphore, fence, pImageIndex); }

VKAPI_ATTR void VKAPI_CALL QueuePresentKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkQueue                                     queue,
    const VkPresentInfoKHR*                     pPresentInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, queue, pPresentInfo); }

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeviceGroupPresentCapabilitiesKHR*        pDeviceGroupPresentCapabilities)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(manager, device, pDeviceGroupPresentCapabilities); }

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSurfaceKHR                                surface,
    VkDeviceGroupPresentModeFlagsKHR*           pModes)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(manager, device, surface, pModes); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pRectCount,
    VkRect2D*                                   pRects)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(manager, physicalDevice, surface, pRectCount, pRects); }

VKAPI_ATTR void VKAPI_CALL AcquireNextImage2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkAcquireNextImageInfoKHR*            pAcquireInfo,
    uint32_t*                                   pImageIndex)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(manager, device, pAcquireInfo, pImageIndex); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPropertiesKHR*                     pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(manager, physicalDevice, pPropertyCount, pProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlanePropertiesKHR*                pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, physicalDevice, pPropertyCount, pProperties); }

VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    planeIndex,
    uint32_t*                                   pDisplayCount,
    VkDisplayKHR*                               pDisplays)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(manager, physicalDevice, planeIndex, pDisplayCount, pDisplays); }

VKAPI_ATTR void VKAPI_CALL GetDisplayModePropertiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModePropertiesKHR*                 pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(manager, physicalDevice, display, pPropertyCount, pProperties); }

VKAPI_ATTR void VKAPI_CALL CreateDisplayModeKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const VkDisplayModeCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDisplayModeKHR*                           pMode)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(manager, physicalDevice, display, pCreateInfo, pAllocator, pMode); }

VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneCapabilitiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayModeKHR                            mode,
    uint32_t                                    planeIndex,
    VkDisplayPlaneCapabilitiesKHR*              pCapabilities)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(manager, physicalDevice, mode, planeIndex, pCapabilities); }

VKAPI_ATTR void VKAPI_CALL CreateDisplayPlaneSurfaceKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkDisplaySurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL CreateSharedSwapchainsKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainCreateInfoKHR*             pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchains)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(manager, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains); }

VKAPI_ATTR void VKAPI_CALL CreateXlibSurfaceKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkXlibSurfaceCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    Display*                                    dpy,
    VisualID                                    visualID)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(manager, physicalDevice, queueFamilyIndex, dpy, visualID); }

VKAPI_ATTR void VKAPI_CALL CreateXcbSurfaceKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkXcbSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    xcb_connection_t*                           connection,
    xcb_visualid_t                              visual_id)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(manager, physicalDevice, queueFamilyIndex, connection, visual_id); }

VKAPI_ATTR void VKAPI_CALL CreateWaylandSurfaceKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkWaylandSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct wl_display*                          display)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(manager, physicalDevice, queueFamilyIndex, display); }

VKAPI_ATTR void VKAPI_CALL CreateAndroidSurfaceKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkAndroidSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL CreateWin32SurfaceKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkWin32SurfaceCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(manager, physicalDevice, queueFamilyIndex); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceVideoCapabilitiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkVideoProfileInfoKHR*                pVideoProfile,
    VkVideoCapabilitiesKHR*                     pCapabilities)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(manager, physicalDevice, pVideoProfile, pCapabilities); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceVideoFormatInfoKHR*   pVideoFormatInfo,
    uint32_t*                                   pVideoFormatPropertyCount,
    VkVideoFormatPropertiesKHR*                 pVideoFormatProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(manager, physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties); }

VKAPI_ATTR void VKAPI_CALL CreateVideoSessionKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkVideoSessionCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkVideoSessionKHR*                          pVideoSession)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pVideoSession); }

VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkVideoSessionKHR                           videoSession,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(manager, device, videoSession, pAllocator); }

VKAPI_ATTR void VKAPI_CALL GetVideoSessionMemoryRequirementsKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkVideoSessionKHR                           videoSession,
    uint32_t*                                   pMemoryRequirementsCount,
    VkVideoSessionMemoryRequirementsKHR*        pMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(manager, device, videoSession, pMemoryRequirementsCount, pMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL BindVideoSessionMemoryKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkVideoSessionKHR                           videoSession,
    uint32_t                                    bindSessionMemoryInfoCount,
    const VkBindVideoSessionMemoryInfoKHR*      pBindSessionMemoryInfos)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(manager, device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos); }

VKAPI_ATTR void VKAPI_CALL CreateVideoSessionParametersKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkVideoSessionParametersCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkVideoSessionParametersKHR*                pVideoSessionParameters)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pVideoSessionParameters); }

VKAPI_ATTR void VKAPI_CALL UpdateVideoSessionParametersKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkVideoSessionParametersKHR                 videoSessionParameters,
    const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(manager, device, videoSessionParameters, pUpdateInfo); }

VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionParametersKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkVideoSessionParametersKHR                 videoSessionParameters,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(manager, device, videoSessionParameters, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CmdBeginVideoCodingKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkVideoBeginCodingInfoKHR*            pBeginInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(manager, commandBuffer, pBeginInfo); }

VKAPI_ATTR void VKAPI_CALL CmdEndVideoCodingKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkVideoEndCodingInfoKHR*              pEndCodingInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(manager, commandBuffer, pEndCodingInfo); }

VKAPI_ATTR void VKAPI_CALL CmdControlVideoCodingKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkVideoCodingControlInfoKHR*          pCodingControlInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(manager, commandBuffer, pCodingControlInfo); }

VKAPI_ATTR void VKAPI_CALL CmdDecodeVideoKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkVideoDecodeInfoKHR*                 pDecodeInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(manager, commandBuffer, pDecodeInfo); }

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderingKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(manager, commandBuffer, pRenderingInfo); }

VKAPI_ATTR void VKAPI_CALL CmdEndRenderingKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(manager, commandBuffer); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(manager, physicalDevice, pFeatures); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(manager, physicalDevice, pProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(manager, physicalDevice, format, pFormatProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(manager, physicalDevice, pImageFormatInfo, pImageFormatProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(manager, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(manager, physicalDevice, pMemoryProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(manager, physicalDevice, pFormatInfo, pPropertyCount, pProperties); }

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(manager, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures); }

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(manager, commandBuffer, deviceMask); }

VKAPI_ATTR void VKAPI_CALL CmdDispatchBaseKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(manager, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ); }

VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(manager, device, commandPool, flags); }

VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(manager, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(manager, physicalDevice, pExternalBufferInfo, pExternalBufferProperties); }

VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandleKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkMemoryGetWin32HandleInfoKHR*        pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(manager, device, pGetWin32HandleInfo, pHandle); }

VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandlePropertiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    HANDLE                                      handle,
    VkMemoryWin32HandlePropertiesKHR*           pMemoryWin32HandleProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(manager, device, handleType, handle, pMemoryWin32HandleProperties); }

VKAPI_ATTR void VKAPI_CALL GetMemoryFdKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkMemoryGetFdInfoKHR*                 pGetFdInfo,
    int*                                        pFd)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(manager, device, pGetFdInfo, pFd); }

VKAPI_ATTR void VKAPI_CALL GetMemoryFdPropertiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    VkMemoryFdPropertiesKHR*                    pMemoryFdProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(manager, device, handleType, fd, pMemoryFdProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(manager, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties); }

VKAPI_ATTR void VKAPI_CALL ImportSemaphoreWin32HandleKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkImportSemaphoreWin32HandleInfoKHR*  pImportSemaphoreWin32HandleInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(manager, device, pImportSemaphoreWin32HandleInfo); }

VKAPI_ATTR void VKAPI_CALL GetSemaphoreWin32HandleKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkSemaphoreGetWin32HandleInfoKHR*     pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(manager, device, pGetWin32HandleInfo, pHandle); }

VKAPI_ATTR void VKAPI_CALL ImportSemaphoreFdKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkImportSemaphoreFdInfoKHR*           pImportSemaphoreFdInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(manager, device, pImportSemaphoreFdInfo); }

VKAPI_ATTR void VKAPI_CALL GetSemaphoreFdKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkSemaphoreGetFdInfoKHR*              pGetFdInfo,
    int*                                        pFd)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(manager, device, pGetFdInfo, pFd); }

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(manager, commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites); }

VKAPI_ATTR void VKAPI_CALL CreateDescriptorUpdateTemplateKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate); }

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(manager, device, descriptorUpdateTemplate, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CreateRenderPass2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkRenderPassCreateInfo2*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pRenderPass); }

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(manager, commandBuffer, pRenderPassBegin, pSubpassBeginInfo); }

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(manager, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo); }

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(manager, commandBuffer, pSubpassEndInfo); }

VKAPI_ATTR void VKAPI_CALL GetSwapchainStatusKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(manager, device, swapchain); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(manager, physicalDevice, pExternalFenceInfo, pExternalFenceProperties); }

VKAPI_ATTR void VKAPI_CALL ImportFenceWin32HandleKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkImportFenceWin32HandleInfoKHR*      pImportFenceWin32HandleInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(manager, device, pImportFenceWin32HandleInfo); }

VKAPI_ATTR void VKAPI_CALL GetFenceWin32HandleKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkFenceGetWin32HandleInfoKHR*         pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(manager, device, pGetWin32HandleInfo, pHandle); }

VKAPI_ATTR void VKAPI_CALL ImportFenceFdKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkImportFenceFdInfoKHR*               pImportFenceFdInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(manager, device, pImportFenceFdInfo); }

VKAPI_ATTR void VKAPI_CALL GetFenceFdKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkFenceGetFdInfoKHR*                  pGetFdInfo,
    int*                                        pFd)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(manager, device, pGetFdInfo, pFd); }

VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint32_t*                                   pCounterCount,
    VkPerformanceCounterKHR*                    pCounters,
    VkPerformanceCounterDescriptionKHR*         pCounterDescriptions)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(manager, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkQueryPoolPerformanceCreateInfoKHR*  pPerformanceQueryCreateInfo,
    uint32_t*                                   pNumPasses)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(manager, physicalDevice, pPerformanceQueryCreateInfo, pNumPasses); }

VKAPI_ATTR void VKAPI_CALL AcquireProfilingLockKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkAcquireProfilingLockInfoKHR*        pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(manager, device, pInfo); }

VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(manager, device); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkSurfaceCapabilities2KHR*                  pSurfaceCapabilities)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(manager, physicalDevice, pSurfaceInfo, pSurfaceCapabilities); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormat2KHR*                        pSurfaceFormats)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(manager, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayProperties2KHR*                    pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(manager, physicalDevice, pPropertyCount, pProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlaneProperties2KHR*               pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(manager, physicalDevice, pPropertyCount, pProperties); }

VKAPI_ATTR void VKAPI_CALL GetDisplayModeProperties2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModeProperties2KHR*                pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(manager, physicalDevice, display, pPropertyCount, pProperties); }

VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneCapabilities2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkDisplayPlaneInfo2KHR*               pDisplayPlaneInfo,
    VkDisplayPlaneCapabilities2KHR*             pCapabilities)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(manager, physicalDevice, pDisplayPlaneInfo, pCapabilities); }

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(manager, device, pInfo, pMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(manager, device, pInfo, pMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL CreateSamplerYcbcrConversionKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pYcbcrConversion); }

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(manager, device, ycbcrConversion, pAllocator); }

VKAPI_ATTR void VKAPI_CALL BindBufferMemory2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(manager, device, bindInfoCount, pBindInfos); }

VKAPI_ATTR void VKAPI_CALL BindImageMemory2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(manager, device, bindInfoCount, pBindInfos); }

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(manager, device, pCreateInfo, pSupport); }

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }

VKAPI_ATTR void VKAPI_CALL GetSemaphoreCounterValueKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    uint64_t*                                   pValue)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(manager, device, semaphore, pValue); }

VKAPI_ATTR void VKAPI_CALL WaitSemaphoresKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkSemaphoreWaitInfo*                  pWaitInfo,
    uint64_t                                    timeout)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(manager, device, pWaitInfo, timeout); }

VKAPI_ATTR void VKAPI_CALL SignalSemaphoreKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkSemaphoreSignalInfo*                pSignalInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(manager, device, pSignalInfo); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFragmentShadingRatesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pFragmentShadingRateCount,
    VkPhysicalDeviceFragmentShadingRateKHR*     pFragmentShadingRates)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(manager, physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates); }

VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkExtent2D*                           pFragmentSize,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2])
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(manager, commandBuffer, pFragmentSize, combinerOps); }

VKAPI_ATTR void VKAPI_CALL WaitForPresentKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    presentId,
    uint64_t                                    timeout)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(manager, device, swapchain, presentId, timeout); }

VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddressKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(manager, device, pInfo); }

VKAPI_ATTR void VKAPI_CALL GetBufferOpaqueCaptureAddressKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(manager, device, pInfo); }

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(manager, device, pInfo); }

VKAPI_ATTR void VKAPI_CALL CreateDeferredOperationKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator,
    VkDeferredOperationKHR*                     pDeferredOperation)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(manager, device, pAllocator, pDeferredOperation); }

VKAPI_ATTR void VKAPI_CALL DestroyDeferredOperationKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(manager, device, operation, pAllocator); }

VKAPI_ATTR void VKAPI_CALL GetDeferredOperationMaxConcurrencyKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(manager, device, operation); }

VKAPI_ATTR void VKAPI_CALL GetDeferredOperationResultKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(manager, device, operation); }

VKAPI_ATTR void VKAPI_CALL DeferredOperationJoinKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(manager, device, operation); }

VKAPI_ATTR void VKAPI_CALL GetPipelineExecutablePropertiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkPipelineInfoKHR*                    pPipelineInfo,
    uint32_t*                                   pExecutableCount,
    VkPipelineExecutablePropertiesKHR*          pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(manager, device, pPipelineInfo, pExecutableCount, pProperties); }

VKAPI_ATTR void VKAPI_CALL GetPipelineExecutableStatisticsKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkPipelineExecutableInfoKHR*          pExecutableInfo,
    uint32_t*                                   pStatisticCount,
    VkPipelineExecutableStatisticKHR*           pStatistics)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(manager, device, pExecutableInfo, pStatisticCount, pStatistics); }

VKAPI_ATTR void VKAPI_CALL GetPipelineExecutableInternalRepresentationsKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkPipelineExecutableInfoKHR*          pExecutableInfo,
    uint32_t*                                   pInternalRepresentationCount,
    VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(manager, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations); }

VKAPI_ATTR void VKAPI_CALL CmdEncodeVideoKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkVideoEncodeInfoKHR*                 pEncodeInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(manager, commandBuffer, pEncodeInfo); }

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(manager, commandBuffer, event, pDependencyInfo); }

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(manager, commandBuffer, event, stageMask); }

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(manager, commandBuffer, eventCount, pEvents, pDependencyInfos); }

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(manager, commandBuffer, pDependencyInfo); }

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(manager, commandBuffer, stage, queryPool, query); }

VKAPI_ATTR void VKAPI_CALL QueueSubmit2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo2*                        pSubmits,
    VkFence                                     fence)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(manager, queue, submitCount, pSubmits, fence); }

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarker2AMD_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(manager, commandBuffer, stage, dstBuffer, dstOffset, marker); }

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointData2NV_PreCall(encode::VulkanCaptureManager* manager,
    VkQueue                                     queue,
    uint32_t*                                   pCheckpointDataCount,
    VkCheckpointData2NV*                        pCheckpointData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(manager, queue, pCheckpointDataCount, pCheckpointData); }

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(manager, commandBuffer, pCopyBufferInfo); }

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(manager, commandBuffer, pCopyImageInfo); }

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(manager, commandBuffer, pCopyBufferToImageInfo); }

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(manager, commandBuffer, pCopyImageToBufferInfo); }

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(manager, commandBuffer, pBlitImageInfo); }

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(manager, commandBuffer, pResolveImageInfo); }

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirect2KHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(manager, commandBuffer, indirectDeviceAddress); }

VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirementsKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDeviceBufferMemoryRequirements*     pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(manager, device, pInfo, pMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirementsKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(manager, device, pInfo, pMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirementsKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL CreateDebugReportCallbackEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkDebugReportCallbackCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugReportCallbackEXT*                   pCallback)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(manager, instance, pCreateInfo, pAllocator, pCallback); }

VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    VkDebugReportCallbackEXT                    callback,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(manager, instance, callback, pAllocator); }

VKAPI_ATTR void VKAPI_CALL DebugReportMessageEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    const char*                                 pLayerPrefix,
    const char*                                 pMessage)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(manager, instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage); }

VKAPI_ATTR void VKAPI_CALL DebugMarkerSetObjectTagEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDebugMarkerObjectTagInfoEXT*        pTagInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(manager, device, pTagInfo); }

VKAPI_ATTR void VKAPI_CALL DebugMarkerSetObjectNameEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDebugMarkerObjectNameInfoEXT*       pNameInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(manager, device, pNameInfo); }

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(manager, commandBuffer, pMarkerInfo); }

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(manager, commandBuffer); }

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(manager, commandBuffer, pMarkerInfo); }

VKAPI_ATTR void VKAPI_CALL CmdBindTransformFeedbackBuffersEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes); }

VKAPI_ATTR void VKAPI_CALL CmdBeginTransformFeedbackEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(manager, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets); }

VKAPI_ATTR void VKAPI_CALL CmdEndTransformFeedbackEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(manager, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets); }

VKAPI_ATTR void VKAPI_CALL CmdBeginQueryIndexedEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(manager, commandBuffer, queryPool, query, flags, index); }

VKAPI_ATTR void VKAPI_CALL CmdEndQueryIndexedEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(manager, commandBuffer, queryPool, query, index); }

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectByteCountEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    VkBuffer                                    counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(manager, commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride); }

VKAPI_ATTR void VKAPI_CALL GetImageViewHandleNVX_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkImageViewHandleInfoNVX*             pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(manager, device, pInfo); }

VKAPI_ATTR void VKAPI_CALL GetImageViewAddressNVX_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkImageView                                 imageView,
    VkImageViewAddressPropertiesNVX*            pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(manager, device, imageView, pProperties); }

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountAMD_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountAMD_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }

VKAPI_ATTR void VKAPI_CALL GetShaderInfoAMD_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    size_t*                                     pInfoSize,
    void*                                       pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(manager, device, pipeline, shaderStage, infoType, pInfoSize, pInfo); }

VKAPI_ATTR void VKAPI_CALL CreateStreamDescriptorSurfaceGGP_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
    VkExternalImageFormatPropertiesNV*          pExternalImageFormatProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(manager, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties); }

VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandleNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    HANDLE*                                     pHandle)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(manager, device, memory, handleType, pHandle); }

VKAPI_ATTR void VKAPI_CALL CreateViSurfaceNN_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkViSurfaceCreateInfoNN*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(manager, commandBuffer, pConditionalRenderingBegin); }

VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(manager, commandBuffer); }

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pViewportWScalings); }

VKAPI_ATTR void VKAPI_CALL ReleaseDisplayEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(manager, physicalDevice, display); }

VKAPI_ATTR void VKAPI_CALL AcquireXlibDisplayEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    VkDisplayKHR                                display)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(manager, physicalDevice, dpy, display); }

VKAPI_ATTR void VKAPI_CALL GetRandROutputDisplayEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    RROutput                                    rrOutput,
    VkDisplayKHR*                               pDisplay)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(manager, physicalDevice, dpy, rrOutput, pDisplay); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilities2EXT*                  pSurfaceCapabilities)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(manager, physicalDevice, surface, pSurfaceCapabilities); }

VKAPI_ATTR void VKAPI_CALL DisplayPowerControlEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayPowerInfoEXT*                pDisplayPowerInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(manager, device, display, pDisplayPowerInfo); }

VKAPI_ATTR void VKAPI_CALL RegisterDeviceEventEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDeviceEventInfoEXT*                 pDeviceEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(manager, device, pDeviceEventInfo, pAllocator, pFence); }

VKAPI_ATTR void VKAPI_CALL RegisterDisplayEventEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayEventInfoEXT*                pDisplayEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(manager, device, display, pDisplayEventInfo, pAllocator, pFence); }

VKAPI_ATTR void VKAPI_CALL GetSwapchainCounterEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    uint64_t*                                   pCounterValue)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(manager, device, swapchain, counter, pCounterValue); }

VKAPI_ATTR void VKAPI_CALL GetRefreshCycleDurationGOOGLE_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkRefreshCycleDurationGOOGLE*               pDisplayTimingProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(manager, device, swapchain, pDisplayTimingProperties); }

VKAPI_ATTR void VKAPI_CALL GetPastPresentationTimingGOOGLE_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pPresentationTimingCount,
    VkPastPresentationTimingGOOGLE*             pPresentationTimings)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(manager, device, swapchain, pPresentationTimingCount, pPresentationTimings); }

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(manager, commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles); }

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    discardRectangleEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>::Dispatch(manager, commandBuffer, discardRectangleEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleModeEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>::Dispatch(manager, commandBuffer, discardRectangleMode); }

VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainKHR*                       pSwapchains,
    const VkHdrMetadataEXT*                     pMetadata)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(manager, device, swapchainCount, pSwapchains, pMetadata); }

VKAPI_ATTR void VKAPI_CALL CreateIOSSurfaceMVK_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkIOSSurfaceCreateInfoMVK*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL CreateMacOSSurfaceMVK_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkMacOSSurfaceCreateInfoMVK*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL SetDebugUtilsObjectNameEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDebugUtilsObjectNameInfoEXT*        pNameInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(manager, device, pNameInfo); }

VKAPI_ATTR void VKAPI_CALL SetDebugUtilsObjectTagEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDebugUtilsObjectTagInfoEXT*         pTagInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(manager, device, pTagInfo); }

VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(manager, queue, pLabelInfo); }

VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkQueue                                     queue)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(manager, queue); }

VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(manager, queue, pLabelInfo); }

VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(manager, commandBuffer, pLabelInfo); }

VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(manager, commandBuffer); }

VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(manager, commandBuffer, pLabelInfo); }

VKAPI_ATTR void VKAPI_CALL CreateDebugUtilsMessengerEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkDebugUtilsMessengerCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugUtilsMessengerEXT*                   pMessenger)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(manager, instance, pCreateInfo, pAllocator, pMessenger); }

VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    VkDebugUtilsMessengerEXT                    messenger,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(manager, instance, messenger, pAllocator); }

VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(manager, instance, messageSeverity, messageTypes, pCallbackData); }

VKAPI_ATTR void VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const struct AHardwareBuffer*               buffer,
    VkAndroidHardwareBufferPropertiesANDROID*   pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(manager, device, buffer, pProperties); }

VKAPI_ATTR void VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo,
    struct AHardwareBuffer**                    pBuffer)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(manager, device, pInfo, pBuffer); }

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(manager, commandBuffer, pSampleLocationsInfo); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    VkMultisamplePropertiesEXT*                 pMultisampleProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(manager, physicalDevice, samples, pMultisampleProperties); }

VKAPI_ATTR void VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkImage                                     image,
    VkImageDrmFormatModifierPropertiesEXT*      pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(manager, device, image, pProperties); }

VKAPI_ATTR void VKAPI_CALL CreateValidationCacheEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkValidationCacheCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkValidationCacheEXT*                       pValidationCache)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(manager, device, pCreateInfo, pAllocator, pValidationCache); }

VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(manager, device, validationCache, pAllocator); }

VKAPI_ATTR void VKAPI_CALL MergeValidationCachesEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkValidationCacheEXT                        dstCache,
    uint32_t                                    srcCacheCount,
    const VkValidationCacheEXT*                 pSrcCaches)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(manager, device, dstCache, srcCacheCount, pSrcCaches); }

VKAPI_ATTR void VKAPI_CALL GetValidationCacheDataEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(manager, device, validationCache, pDataSize, pData); }

VKAPI_ATTR void VKAPI_CALL CmdBindShadingRateImageNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(manager, commandBuffer, imageView, imageLayout); }

VKAPI_ATTR void VKAPI_CALL CmdSetViewportShadingRatePaletteNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pShadingRatePalettes); }

VKAPI_ATTR void VKAPI_CALL CmdSetCoarseSampleOrderNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(manager, commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders); }

VKAPI_ATTR void VKAPI_CALL CreateAccelerationStructureNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkAccelerationStructureCreateInfoNV*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkAccelerationStructureNV*                  pAccelerationStructure)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(manager, device, pCreateInfo, pAllocator, pAccelerationStructure); }

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkAccelerationStructureNV                   accelerationStructure,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(manager, device, accelerationStructure, pAllocator); }

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo,
    VkMemoryRequirements2KHR*                   pMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, device, pInfo, pMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL BindAccelerationStructureMemoryNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindAccelerationStructureMemoryInfoNV* pBindInfos)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(manager, device, bindInfoCount, pBindInfos); }

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructureNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkAccelerationStructureInfoNV*        pInfo,
    VkBuffer                                    instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(manager, commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset); }

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkCopyAccelerationStructureModeKHR          mode)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(manager, commandBuffer, dst, src, mode); }

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    raygenShaderBindingTableBuffer,
    VkDeviceSize                                raygenShaderBindingOffset,
    VkBuffer                                    missShaderBindingTableBuffer,
    VkDeviceSize                                missShaderBindingOffset,
    VkDeviceSize                                missShaderBindingStride,
    VkBuffer                                    hitShaderBindingTableBuffer,
    VkDeviceSize                                hitShaderBindingOffset,
    VkDeviceSize                                hitShaderBindingStride,
    VkBuffer                                    callableShaderBindingTableBuffer,
    VkDeviceSize                                callableShaderBindingOffset,
    VkDeviceSize                                callableShaderBindingStride,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(manager, commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth); }

VKAPI_ATTR void VKAPI_CALL CreateRayTracingPipelinesNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkRayTracingPipelineCreateInfoNV*     pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(manager, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines); }

VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupHandlesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    void*                                       pData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(manager, device, pipeline, firstGroup, groupCount, dataSize, pData); }

VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupHandlesNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    void*                                       pData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(manager, device, pipeline, firstGroup, groupCount, dataSize, pData); }

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureHandleNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkAccelerationStructureNV                   accelerationStructure,
    size_t                                      dataSize,
    void*                                       pData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(manager, device, accelerationStructure, dataSize, pData); }

VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureNV*            pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(manager, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery); }

VKAPI_ATTR void VKAPI_CALL CompileDeferredNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    shader)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(manager, device, pipeline, shader); }

VKAPI_ATTR void VKAPI_CALL GetMemoryHostPointerPropertiesEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    const void*                                 pHostPointer,
    VkMemoryHostPointerPropertiesEXT*           pMemoryHostPointerProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(manager, device, handleType, pHostPointer, pMemoryHostPointerProperties); }

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(manager, commandBuffer, pipelineStage, dstBuffer, dstOffset, marker); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pTimeDomainCount,
    VkTimeDomainEXT*                            pTimeDomains)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(manager, physicalDevice, pTimeDomainCount, pTimeDomains); }

VKAPI_ATTR void VKAPI_CALL GetCalibratedTimestampsEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    timestampCount,
    const VkCalibratedTimestampInfoEXT*         pTimestampInfos,
    uint64_t*                                   pTimestamps,
    uint64_t*                                   pMaxDeviation)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(manager, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation); }

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(manager, commandBuffer, taskCount, firstTask); }

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride); }

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }

VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorEnableNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkBool32*                             pExclusiveScissorEnables)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>::Dispatch(manager, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables); }

VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(manager, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors); }

VKAPI_ATTR void VKAPI_CALL CmdSetCheckpointNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(manager, commandBuffer, pCheckpointMarker); }

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV_PreCall(encode::VulkanCaptureManager* manager,
    VkQueue                                     queue,
    uint32_t*                                   pCheckpointDataCount,
    VkCheckpointDataNV*                         pCheckpointData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(manager, queue, pCheckpointDataCount, pCheckpointData); }

VKAPI_ATTR void VKAPI_CALL InitializePerformanceApiINTEL_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkInitializePerformanceApiInfoINTEL*  pInitializeInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(manager, device, pInitializeInfo); }

VKAPI_ATTR void VKAPI_CALL UninitializePerformanceApiINTEL_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(manager, device); }

VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceMarkerINTEL_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceMarkerInfoINTEL*         pMarkerInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(manager, commandBuffer, pMarkerInfo); }

VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceStreamMarkerINTEL_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceStreamMarkerInfoINTEL*   pMarkerInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(manager, commandBuffer, pMarkerInfo); }

VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceOverrideINTEL_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceOverrideInfoINTEL*       pOverrideInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(manager, commandBuffer, pOverrideInfo); }

VKAPI_ATTR void VKAPI_CALL AcquirePerformanceConfigurationINTEL_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo,
    VkPerformanceConfigurationINTEL*            pConfiguration)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(manager, device, pAcquireInfo, pConfiguration); }

VKAPI_ATTR void VKAPI_CALL ReleasePerformanceConfigurationINTEL_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPerformanceConfigurationINTEL             configuration)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(manager, device, configuration); }

VKAPI_ATTR void VKAPI_CALL QueueSetPerformanceConfigurationINTEL_PreCall(encode::VulkanCaptureManager* manager,
    VkQueue                                     queue,
    VkPerformanceConfigurationINTEL             configuration)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(manager, queue, configuration); }

VKAPI_ATTR void VKAPI_CALL GetPerformanceParameterINTEL_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPerformanceParameterTypeINTEL             parameter,
    VkPerformanceValueINTEL*                    pValue)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(manager, device, parameter, pValue); }

VKAPI_ATTR void VKAPI_CALL SetLocalDimmingAMD_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSwapchainKHR                              swapChain,
    VkBool32                                    localDimmingEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(manager, device, swapChain, localDimmingEnable); }

VKAPI_ATTR void VKAPI_CALL CreateImagePipeSurfaceFUCHSIA_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkImagePipeSurfaceCreateInfoFUCHSIA*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL CreateMetalSurfaceEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkMetalSurfaceCreateInfoEXT*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddressEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(manager, device, pInfo); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pToolCount,
    VkPhysicalDeviceToolProperties*             pToolProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(manager, physicalDevice, pToolCount, pToolProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkCooperativeMatrixPropertiesNV*            pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(manager, physicalDevice, pPropertyCount, pProperties); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pCombinationCount,
    VkFramebufferMixedSamplesCombinationNV*     pCombinations)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(manager, physicalDevice, pCombinationCount, pCombinations); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfacePresentModes2EXT_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(manager, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes); }

VKAPI_ATTR void VKAPI_CALL AcquireFullScreenExclusiveModeEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(manager, device, swapchain); }

VKAPI_ATTR void VKAPI_CALL ReleaseFullScreenExclusiveModeEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(manager, device, swapchain); }

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupSurfacePresentModes2EXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkDeviceGroupPresentModeFlagsKHR*           pModes)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(manager, device, pSurfaceInfo, pModes); }

VKAPI_ATTR void VKAPI_CALL CreateHeadlessSurfaceEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkHeadlessSurfaceCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(manager, commandBuffer, lineStippleFactor, lineStipplePattern); }

VKAPI_ATTR void VKAPI_CALL ResetQueryPoolEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(manager, device, queryPool, firstQuery, queryCount); }

VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(manager, commandBuffer, cullMode); }

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(manager, commandBuffer, frontFace); }

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(manager, commandBuffer, primitiveTopology); }

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(manager, commandBuffer, viewportCount, pViewports); }

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(manager, commandBuffer, scissorCount, pScissors); }

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(manager, commandBuffer, depthTestEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(manager, commandBuffer, depthWriteEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(manager, commandBuffer, depthCompareOp); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(manager, commandBuffer, depthBoundsTestEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(manager, commandBuffer, stencilTestEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(manager, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp); }

VKAPI_ATTR void VKAPI_CALL ReleaseSwapchainImagesEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkReleaseSwapchainImagesInfoEXT*      pReleaseInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(manager, device, pReleaseInfo); }

VKAPI_ATTR void VKAPI_CALL GetGeneratedCommandsMemoryRequirementsNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(manager, device, pInfo, pMemoryRequirements); }

VKAPI_ATTR void VKAPI_CALL CmdPreprocessGeneratedCommandsNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(manager, commandBuffer, pGeneratedCommandsInfo); }

VKAPI_ATTR void VKAPI_CALL CmdExecuteGeneratedCommandsNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(manager, commandBuffer, isPreprocessed, pGeneratedCommandsInfo); }

VKAPI_ATTR void VKAPI_CALL CmdBindPipelineShaderGroupNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline,
    uint32_t                                    groupIndex)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(manager, commandBuffer, pipelineBindPoint, pipeline, groupIndex); }

VKAPI_ATTR void VKAPI_CALL CreateIndirectCommandsLayoutNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkIndirectCommandsLayoutNV*                 pIndirectCommandsLayout)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(manager, device, pCreateInfo, pAllocator, pIndirectCommandsLayout); }

VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkIndirectCommandsLayoutNV                  indirectCommandsLayout,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(manager, device, indirectCommandsLayout, pAllocator); }

VKAPI_ATTR void VKAPI_CALL AcquireDrmDisplayEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    int32_t                                     drmFd,
    VkDisplayKHR                                display)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(manager, physicalDevice, drmFd, display); }

VKAPI_ATTR void VKAPI_CALL GetDrmDisplayEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    int32_t                                     drmFd,
    uint32_t                                    connectorId,
    VkDisplayKHR*                               display)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(manager, physicalDevice, drmFd, connectorId, display); }

VKAPI_ATTR void VKAPI_CALL CreatePrivateDataSlotEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkPrivateDataSlotCreateInfo*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPrivateDataSlot*                          pPrivateDataSlot)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(manager, device, pCreateInfo, pAllocator, pPrivateDataSlot); }

VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlotEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPrivateDataSlot                           privateDataSlot,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(manager, device, privateDataSlot, pAllocator); }

VKAPI_ATTR void VKAPI_CALL SetPrivateDataEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t                                    data)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(manager, device, objectType, objectHandle, privateDataSlot, data); }

VKAPI_ATTR void VKAPI_CALL GetPrivateDataEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t*                                   pData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(manager, device, objectType, objectHandle, privateDataSlot, pData); }

VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateEnumNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2])
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(manager, commandBuffer, shadingRate, combinerOps); }

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2EXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource2EXT*               pSubresource,
    VkSubresourceLayout2EXT*                    pLayout)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(manager, device, image, pSubresource, pLayout); }

VKAPI_ATTR void VKAPI_CALL GetDeviceFaultInfoEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeviceFaultCountsEXT*                     pFaultCounts,
    VkDeviceFaultInfoEXT*                       pFaultInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(manager, device, pFaultCounts, pFaultInfo); }

VKAPI_ATTR void VKAPI_CALL AcquireWinrtDisplayNV_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(manager, physicalDevice, display); }

VKAPI_ATTR void VKAPI_CALL GetWinrtDisplayNV_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    VkDisplayKHR*                               pDisplay)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(manager, physicalDevice, deviceRelativeId, pDisplay); }

VKAPI_ATTR void VKAPI_CALL CreateDirectFBSurfaceEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkDirectFBSurfaceCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    IDirectFB*                                  dfb)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(manager, physicalDevice, queueFamilyIndex, dfb); }

VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT*  pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(manager, commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions); }

VKAPI_ATTR void VKAPI_CALL GetMemoryZirconHandleFUCHSIA_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkMemoryGetZirconHandleInfoFUCHSIA*   pGetZirconHandleInfo,
    zx_handle_t*                                pZirconHandle)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(manager, device, pGetZirconHandleInfo, pZirconHandle); }

VKAPI_ATTR void VKAPI_CALL GetMemoryZirconHandlePropertiesFUCHSIA_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    zx_handle_t                                 zirconHandle,
    VkMemoryZirconHandlePropertiesFUCHSIA*      pMemoryZirconHandleProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(manager, device, handleType, zirconHandle, pMemoryZirconHandleProperties); }

VKAPI_ATTR void VKAPI_CALL ImportSemaphoreZirconHandleFUCHSIA_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, device, pImportSemaphoreZirconHandleInfo); }

VKAPI_ATTR void VKAPI_CALL GetSemaphoreZirconHandleFUCHSIA_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo,
    zx_handle_t*                                pZirconHandle)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, device, pGetZirconHandleInfo, pZirconHandle); }

VKAPI_ATTR void VKAPI_CALL CmdBindInvocationMaskHUAWEI_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(manager, commandBuffer, imageView, imageLayout); }

VKAPI_ATTR void VKAPI_CALL GetMemoryRemoteAddressNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkMemoryGetRemoteAddressInfoNV*       pMemoryGetRemoteAddressInfo,
    VkRemoteAddressNV*                          pAddress)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(manager, device, pMemoryGetRemoteAddressInfo, pAddress); }

VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    patchControlPoints)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(manager, commandBuffer, patchControlPoints); }

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(manager, commandBuffer, rasterizerDiscardEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(manager, commandBuffer, depthBiasEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkLogicOp                                   logicOp)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(manager, commandBuffer, logicOp); }

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(manager, commandBuffer, primitiveRestartEnable); }

VKAPI_ATTR void VKAPI_CALL CreateScreenSurfaceQNX_PreCall(encode::VulkanCaptureManager* manager,
    VkInstance                                  instance,
    const VkScreenSurfaceCreateInfoQNX*         pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceScreenPresentationSupportQNX_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct _screen_window*                      window)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(manager, physicalDevice, queueFamilyIndex, window); }

VKAPI_ATTR void                                    VKAPI_CALL CmdSetColorWriteEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorWriteEnables)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(manager, commandBuffer, attachmentCount, pColorWriteEnables); }

VKAPI_ATTR void VKAPI_CALL CmdDrawMultiEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawInfoEXT*                   pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(manager, commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride); }

VKAPI_ATTR void VKAPI_CALL CmdDrawMultiIndexedEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawIndexedInfoEXT*            pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    const int32_t*                              pVertexOffset)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(manager, commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset); }

VKAPI_ATTR void VKAPI_CALL CreateMicromapEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkMicromapCreateInfoEXT*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkMicromapEXT*                              pMicromap)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(manager, device, pCreateInfo, pAllocator, pMicromap); }

VKAPI_ATTR void VKAPI_CALL DestroyMicromapEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkMicromapEXT                               micromap,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(manager, device, micromap, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CmdBuildMicromapsEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(manager, commandBuffer, infoCount, pInfos); }

VKAPI_ATTR void VKAPI_CALL BuildMicromapsEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(manager, device, deferredOperation, infoCount, pInfos); }

VKAPI_ATTR void VKAPI_CALL CopyMicromapEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyMicromapInfoEXT*                pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(manager, device, deferredOperation, pInfo); }

VKAPI_ATTR void VKAPI_CALL CopyMicromapToMemoryEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(manager, device, deferredOperation, pInfo); }

VKAPI_ATTR void VKAPI_CALL CopyMemoryToMicromapEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(manager, device, deferredOperation, pInfo); }

VKAPI_ATTR void VKAPI_CALL WriteMicromapsPropertiesEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    micromapCount,
    const VkMicromapEXT*                        pMicromaps,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    void*                                       pData,
    size_t                                      stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(manager, device, micromapCount, pMicromaps, queryType, dataSize, pData, stride); }

VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapInfoEXT*                pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(manager, commandBuffer, pInfo); }

VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapToMemoryEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(manager, commandBuffer, pInfo); }

VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToMicromapEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(manager, commandBuffer, pInfo); }

VKAPI_ATTR void VKAPI_CALL CmdWriteMicromapsPropertiesEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    micromapCount,
    const VkMicromapEXT*                        pMicromaps,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(manager, commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery); }

VKAPI_ATTR void VKAPI_CALL GetDeviceMicromapCompatibilityEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkMicromapVersionInfoEXT*             pVersionInfo,
    VkAccelerationStructureCompatibilityKHR*    pCompatibility)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(manager, device, pVersionInfo, pCompatibility); }

VKAPI_ATTR void VKAPI_CALL GetMicromapBuildSizesEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    const VkMicromapBuildInfoEXT*               pBuildInfo,
    VkMicromapBuildSizesInfoEXT*                pSizeInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(manager, device, buildType, pBuildInfo, pSizeInfo); }

VKAPI_ATTR void VKAPI_CALL CmdDrawClusterHUAWEI_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(manager, commandBuffer, groupCountX, groupCountY, groupCountZ); }

VKAPI_ATTR void VKAPI_CALL CmdDrawClusterIndirectHUAWEI_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(manager, commandBuffer, buffer, offset); }

VKAPI_ATTR void VKAPI_CALL SetDeviceMemoryPriorityEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    float                                       priority)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(manager, device, memory, priority); }

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkDescriptorSetBindingReferenceVALVE* pBindingReference,
    VkDescriptorSetLayoutHostMappingInfoVALVE*  pHostMapping)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(manager, device, pBindingReference, pHostMapping); }

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetHostMappingVALVE_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDescriptorSet                             descriptorSet,
    void**                                      ppData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(manager, device, descriptorSet, ppData); }

VKAPI_ATTR void VKAPI_CALL CmdSetTessellationDomainOriginEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(manager, commandBuffer, domainOrigin); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClampEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClampEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(manager, commandBuffer, depthClampEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetPolygonModeEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkPolygonMode                               polygonMode)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(manager, commandBuffer, polygonMode); }

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationSamplesEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(manager, commandBuffer, rasterizationSamples); }

VKAPI_ATTR void VKAPI_CALL CmdSetSampleMaskEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       samples,
    const VkSampleMask*                         pSampleMask)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(manager, commandBuffer, samples, pSampleMask); }

VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToCoverageEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(manager, commandBuffer, alphaToCoverageEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToOneEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToOneEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(manager, commandBuffer, alphaToOneEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    logicOpEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(manager, commandBuffer, logicOpEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorBlendEnables)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables); }

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEquationEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendEquationEXT*              pColorBlendEquations)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations); }

VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteMaskEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorComponentFlags*                pColorWriteMasks)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks); }

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationStreamEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    rasterizationStream)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(manager, commandBuffer, rasterizationStream); }

VKAPI_ATTR void VKAPI_CALL CmdSetConservativeRasterizationModeEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(manager, commandBuffer, conservativeRasterizationMode); }

VKAPI_ATTR void VKAPI_CALL CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(manager, commandBuffer, extraPrimitiveOverestimationSize); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClipEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(manager, commandBuffer, depthClipEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(manager, commandBuffer, sampleLocationsEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendAdvancedEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendAdvancedEXT*              pColorBlendAdvanced)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced); }

VKAPI_ATTR void VKAPI_CALL CmdSetProvokingVertexModeEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(manager, commandBuffer, provokingVertexMode); }

VKAPI_ATTR void VKAPI_CALL CmdSetLineRasterizationModeEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(manager, commandBuffer, lineRasterizationMode); }

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEnableEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stippledLineEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(manager, commandBuffer, stippledLineEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipNegativeOneToOneEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    negativeOneToOne)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(manager, commandBuffer, negativeOneToOne); }

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingEnableNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(manager, commandBuffer, viewportWScalingEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetViewportSwizzleNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportSwizzleNV*                  pViewportSwizzles)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pViewportSwizzles); }

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorEnableNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageToColorEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(manager, commandBuffer, coverageToColorEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorLocationNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageToColorLocation)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(manager, commandBuffer, coverageToColorLocation); }

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationModeNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(manager, commandBuffer, coverageModulationMode); }

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableEnableNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(manager, commandBuffer, coverageModulationTableEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    const float*                                pCoverageModulationTable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(manager, commandBuffer, coverageModulationTableCount, pCoverageModulationTable); }

VKAPI_ATTR void VKAPI_CALL CmdSetShadingRateImageEnableNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(manager, commandBuffer, shadingRateImageEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetRepresentativeFragmentTestEnableNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(manager, commandBuffer, representativeFragmentTestEnable); }

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageReductionModeNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(manager, commandBuffer, coverageReductionMode); }

VKAPI_ATTR void VKAPI_CALL GetShaderModuleIdentifierEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    VkShaderModuleIdentifierEXT*                pIdentifier)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(manager, device, shaderModule, pIdentifier); }

VKAPI_ATTR void VKAPI_CALL GetShaderModuleCreateInfoIdentifierEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    VkShaderModuleIdentifierEXT*                pIdentifier)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(manager, device, pCreateInfo, pIdentifier); }

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall(encode::VulkanCaptureManager* manager,
    VkPhysicalDevice                            physicalDevice,
    const VkOpticalFlowImageFormatInfoNV*       pOpticalFlowImageFormatInfo,
    uint32_t*                                   pFormatCount,
    VkOpticalFlowImageFormatPropertiesNV*       pImageFormatProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(manager, physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties); }

VKAPI_ATTR void VKAPI_CALL CreateOpticalFlowSessionNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkOpticalFlowSessionCreateInfoNV*     pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkOpticalFlowSessionNV*                     pSession)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(manager, device, pCreateInfo, pAllocator, pSession); }

VKAPI_ATTR void VKAPI_CALL DestroyOpticalFlowSessionNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkOpticalFlowSessionNV                      session,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(manager, device, session, pAllocator); }

VKAPI_ATTR void VKAPI_CALL BindOpticalFlowSessionImageNV_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkOpticalFlowSessionNV                      session,
    VkOpticalFlowSessionBindingPointNV          bindingPoint,
    VkImageView                                 view,
    VkImageLayout                               layout)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(manager, device, session, bindingPoint, view, layout); }

VKAPI_ATTR void VKAPI_CALL CmdOpticalFlowExecuteNV_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkOpticalFlowSessionNV                      session,
    const VkOpticalFlowExecuteInfoNV*           pExecuteInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(manager, commandBuffer, session, pExecuteInfo); }

VKAPI_ATTR void VKAPI_CALL GetFramebufferTilePropertiesQCOM_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    uint32_t*                                   pPropertiesCount,
    VkTilePropertiesQCOM*                       pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(manager, device, framebuffer, pPropertiesCount, pProperties); }

VKAPI_ATTR void VKAPI_CALL GetDynamicRenderingTilePropertiesQCOM_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkRenderingInfo*                      pRenderingInfo,
    VkTilePropertiesQCOM*                       pProperties)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(manager, device, pRenderingInfo, pProperties); }

VKAPI_ATTR void VKAPI_CALL CreateAccelerationStructureKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkAccelerationStructureKHR*                 pAccelerationStructure)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pAccelerationStructure); }

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkAccelerationStructureKHR                  accelerationStructure,
    const VkAllocationCallbacks*                pAllocator)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(manager, device, accelerationStructure, pAllocator); }

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(manager, commandBuffer, infoCount, pInfos, ppBuildRangeInfos); }

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresIndirectKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress*                      pIndirectDeviceAddresses,
    const uint32_t*                             pIndirectStrides,
    const uint32_t* const*                      ppMaxPrimitiveCounts)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(manager, commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts); }

VKAPI_ATTR void VKAPI_CALL CopyAccelerationStructureToMemoryKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, device, deferredOperation, pInfo); }

VKAPI_ATTR void VKAPI_CALL CopyMemoryToAccelerationStructureKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, device, deferredOperation, pInfo); }

VKAPI_ATTR void VKAPI_CALL WriteAccelerationStructuresPropertiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    void*                                       pData,
    size_t                                      stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride); }

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureInfoKHR*   pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(manager, commandBuffer, pInfo); }

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureToMemoryKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, commandBuffer, pInfo); }

VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToAccelerationStructureKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, commandBuffer, pInfo); }

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureDeviceAddressKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkAccelerationStructureDeviceAddressInfoKHR* pInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(manager, device, pInfo); }

VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery); }

VKAPI_ATTR void VKAPI_CALL GetDeviceAccelerationStructureCompatibilityKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    const VkAccelerationStructureVersionInfoKHR* pVersionInfo,
    VkAccelerationStructureCompatibilityKHR*    pCompatibility)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(manager, device, pVersionInfo, pCompatibility); }

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureBuildSizesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo,
    const uint32_t*                             pMaxPrimitiveCounts,
    VkAccelerationStructureBuildSizesInfoKHR*   pSizeInfo)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(manager, device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo); }

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(manager, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth); }

VKAPI_ATTR void VKAPI_CALL CreateRayTracingPipelinesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkRayTracingPipelineCreateInfoKHR*    pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(manager, device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines); }

VKAPI_ATTR void VKAPI_CALL GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    void*                                       pData)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(manager, device, pipeline, firstGroup, groupCount, dataSize, pData); }

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirectKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(manager, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress); }

VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupStackSizeKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    group,
    VkShaderGroupShaderKHR                      groupShader)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(manager, device, pipeline, group, groupShader); }

VKAPI_ATTR void VKAPI_CALL CmdSetRayTracingPipelineStackSizeKHR_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    pipelineStackSize)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(manager, commandBuffer, pipelineStackSize); }

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(manager, commandBuffer, groupCountX, groupCountY, groupCountZ); }

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride); }

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountEXT_PreCall(encode::VulkanCaptureManager* manager,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{ PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }
}
GFXRECON_END_NAMESPACE(plugin_perfetto)
GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)
