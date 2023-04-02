/*
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef GFXRECON_PLUGINS_REPLAY_FUNC_TABLE_PRE_H
#define GFXRECON_PLUGINS_REPLAY_FUNC_TABLE_PRE_H

#include "format/platform_types.h"
#include "decode/api_decoder.h"
#include "util/defines.h"
#include "util/platform.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/handle_pointer_decoder.h"
#include "generated/generated_vulkan_struct_decoders.h"

#include "vulkan/vk_layer.h"
#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#ifdef WIN32
#ifdef CreateEvent
#undef CreateEvent
#endif
#ifdef CreateSemaphore
#undef CreateSemaphore
#endif
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugins)
GFXRECON_BEGIN_NAMESPACE(replay)

using namespace decode;

// clang-format off
typedef void (VKAPI_ATTR *PFN_CreateInstance_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkInstance>* pInstance);
typedef void (VKAPI_ATTR *PFN_DestroyInstance_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_EnumeratePhysicalDevices_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, PointerDecoder<uint32_t>* pPhysicalDeviceCount, HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFeatures_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFormatProperties_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceImageFormatProperties_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceProperties_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceQueueFamilyProperties_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pQueueFamilyPropertyCount, StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceMemoryProperties_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties);
typedef void (VKAPI_ATTR *PFN_CreateDevice_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDevice>* pDevice);
typedef void (VKAPI_ATTR *PFN_DestroyDevice_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetDeviceQueue_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t queueFamilyIndex, uint32_t queueIndex, HandlePointerDecoder<VkQueue>* pQueue);
typedef void (VKAPI_ATTR *PFN_QueueSubmit_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t submitCount, StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits, format::HandleId fence);
typedef void (VKAPI_ATTR *PFN_QueueWaitIdle_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue);
typedef void (VKAPI_ATTR *PFN_DeviceWaitIdle_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device);
typedef void (VKAPI_ATTR *PFN_AllocateMemory_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDeviceMemory>* pMemory);
typedef void (VKAPI_ATTR *PFN_FreeMemory_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_MapMemory_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, PointerDecoder<uint64_t, void*>* ppData);
typedef void (VKAPI_ATTR *PFN_UnmapMemory_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory);
typedef void (VKAPI_ATTR *PFN_FlushMappedMemoryRanges_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t memoryRangeCount, StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges);
typedef void (VKAPI_ATTR *PFN_InvalidateMappedMemoryRanges_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t memoryRangeCount, StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges);
typedef void (VKAPI_ATTR *PFN_GetDeviceMemoryCommitment_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory, PointerDecoder<VkDeviceSize>* pCommittedMemoryInBytes);
typedef void (VKAPI_ATTR *PFN_BindBufferMemory_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId buffer, format::HandleId memory, VkDeviceSize memoryOffset);
typedef void (VKAPI_ATTR *PFN_BindImageMemory_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId image, format::HandleId memory, VkDeviceSize memoryOffset);
typedef void (VKAPI_ATTR *PFN_GetBufferMemoryRequirements_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId buffer, StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetImageMemoryRequirements_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetImageSparseMemoryRequirements_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSparseImageFormatProperties_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties);
typedef void (VKAPI_ATTR *PFN_QueueBindSparse_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo, format::HandleId fence);
typedef void (VKAPI_ATTR *PFN_CreateFence_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFence>* pFence);
typedef void (VKAPI_ATTR *PFN_DestroyFence_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId fence, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_ResetFences_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t fenceCount, HandlePointerDecoder<VkFence>* pFences);
typedef void (VKAPI_ATTR *PFN_GetFenceStatus_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId fence);
typedef void (VKAPI_ATTR *PFN_WaitForFences_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t fenceCount, HandlePointerDecoder<VkFence>* pFences, VkBool32 waitAll, uint64_t timeout);
typedef void (VKAPI_ATTR *PFN_CreateSemaphore_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSemaphore>* pSemaphore);
typedef void (VKAPI_ATTR *PFN_DestroySemaphore_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId semaphore, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateEvent_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkEvent>* pEvent);
typedef void (VKAPI_ATTR *PFN_DestroyEvent_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId event, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetEventStatus_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId event);
typedef void (VKAPI_ATTR *PFN_SetEvent_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId event);
typedef void (VKAPI_ATTR *PFN_ResetEvent_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId event);
typedef void (VKAPI_ATTR *PFN_CreateQueryPool_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkQueryPool>* pQueryPool);
typedef void (VKAPI_ATTR *PFN_DestroyQueryPool_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId queryPool, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetQueryPoolResults_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, PointerDecoder<uint8_t>* pData, VkDeviceSize stride, VkQueryResultFlags flags);
typedef void (VKAPI_ATTR *PFN_CreateBuffer_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkBuffer>* pBuffer);
typedef void (VKAPI_ATTR *PFN_DestroyBuffer_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId buffer, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateBufferView_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkBufferView>* pView);
typedef void (VKAPI_ATTR *PFN_DestroyBufferView_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId bufferView, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateImage_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkImage>* pImage);
typedef void (VKAPI_ATTR *PFN_DestroyImage_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetImageSubresourceLayout_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource, StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout);
typedef void (VKAPI_ATTR *PFN_CreateImageView_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkImageView>* pView);
typedef void (VKAPI_ATTR *PFN_DestroyImageView_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId imageView, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateShaderModule_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkShaderModule>* pShaderModule);
typedef void (VKAPI_ATTR *PFN_DestroyShaderModule_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId shaderModule, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreatePipelineCache_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipelineCache>* pPipelineCache);
typedef void (VKAPI_ATTR *PFN_DestroyPipelineCache_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId pipelineCache, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetPipelineCacheData_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, PointerDecoder<size_t>* pDataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_MergePipelineCaches_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId dstCache, uint32_t srcCacheCount, HandlePointerDecoder<VkPipelineCache>* pSrcCaches);
typedef void (VKAPI_ATTR *PFN_CreateGraphicsPipelines_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines);
typedef void (VKAPI_ATTR *PFN_CreateComputePipelines_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines);
typedef void (VKAPI_ATTR *PFN_DestroyPipeline_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId pipeline, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreatePipelineLayout_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipelineLayout>* pPipelineLayout);
typedef void (VKAPI_ATTR *PFN_DestroyPipelineLayout_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId pipelineLayout, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateSampler_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSampler>* pSampler);
typedef void (VKAPI_ATTR *PFN_DestroySampler_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId sampler, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateDescriptorSetLayout_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout);
typedef void (VKAPI_ATTR *PFN_DestroyDescriptorSetLayout_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorSetLayout, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateDescriptorPool_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorPool>* pDescriptorPool);
typedef void (VKAPI_ATTR *PFN_DestroyDescriptorPool_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorPool, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_ResetDescriptorPool_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId descriptorPool, VkDescriptorPoolResetFlags flags);
typedef void (VKAPI_ATTR *PFN_AllocateDescriptorSets_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo, HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets);
typedef void (VKAPI_ATTR *PFN_FreeDescriptorSets_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId descriptorPool, uint32_t descriptorSetCount, HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets);
typedef void (VKAPI_ATTR *PFN_UpdateDescriptorSets_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t descriptorWriteCount, StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites, uint32_t descriptorCopyCount, StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies);
typedef void (VKAPI_ATTR *PFN_CreateFramebuffer_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFramebuffer>* pFramebuffer);
typedef void (VKAPI_ATTR *PFN_DestroyFramebuffer_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId framebuffer, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateRenderPass_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkRenderPass>* pRenderPass);
typedef void (VKAPI_ATTR *PFN_DestroyRenderPass_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId renderPass, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetRenderAreaGranularity_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId renderPass, StructPointerDecoder<Decoded_VkExtent2D>* pGranularity);
typedef void (VKAPI_ATTR *PFN_CreateCommandPool_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkCommandPool>* pCommandPool);
typedef void (VKAPI_ATTR *PFN_DestroyCommandPool_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_ResetCommandPool_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId commandPool, VkCommandPoolResetFlags flags);
typedef void (VKAPI_ATTR *PFN_AllocateCommandBuffers_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo, HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers);
typedef void (VKAPI_ATTR *PFN_FreeCommandBuffers_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, uint32_t commandBufferCount, HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers);
typedef void (VKAPI_ATTR *PFN_BeginCommandBuffer_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo);
typedef void (VKAPI_ATTR *PFN_EndCommandBuffer_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_ResetCommandBuffer_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, VkCommandBufferResetFlags flags);
typedef void (VKAPI_ATTR *PFN_CmdBindPipeline_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId pipeline);
typedef void (VKAPI_ATTR *PFN_CmdSetViewport_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewport>* pViewports);
typedef void (VKAPI_ATTR *PFN_CmdSetScissor_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstScissor, uint32_t scissorCount, StructPointerDecoder<Decoded_VkRect2D>* pScissors);
typedef void (VKAPI_ATTR *PFN_CmdSetLineWidth_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float lineWidth);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthBias_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
typedef void (VKAPI_ATTR *PFN_CmdSetBlendConstants_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, PointerDecoder<float>* blendConstants);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthBounds_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float minDepthBounds, float maxDepthBounds);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilCompareMask_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilWriteMask_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilReference_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);
typedef void (VKAPI_ATTR *PFN_CmdBindDescriptorSets_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId layout, uint32_t firstSet, uint32_t descriptorSetCount, HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets, uint32_t dynamicOffsetCount, PointerDecoder<uint32_t>* pDynamicOffsets);
typedef void (VKAPI_ATTR *PFN_CmdBindIndexBuffer_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, VkIndexType indexType);
typedef void (VKAPI_ATTR *PFN_CmdBindVertexBuffers_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets);
typedef void (VKAPI_ATTR *PFN_CmdDraw_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndexed_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndirect_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndexedIndirect_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDispatch_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_ATTR *PFN_CmdDispatchIndirect_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset);
typedef void (VKAPI_ATTR *PFN_CmdCopyBuffer_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcBuffer, format::HandleId dstBuffer, uint32_t regionCount, StructPointerDecoder<Decoded_VkBufferCopy>* pRegions);
typedef void (VKAPI_ATTR *PFN_CmdCopyImage_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkImageCopy>* pRegions);
typedef void (VKAPI_ATTR *PFN_CmdBlitImage_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkImageBlit>* pRegions, VkFilter filter);
typedef void (VKAPI_ATTR *PFN_CmdCopyBufferToImage_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcBuffer, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions);
typedef void (VKAPI_ATTR *PFN_CmdCopyImageToBuffer_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstBuffer, uint32_t regionCount, StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions);
typedef void (VKAPI_ATTR *PFN_CmdUpdateBuffer_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_CmdFillBuffer_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);
typedef void (VKAPI_ATTR *PFN_CmdClearColorImage_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId image, VkImageLayout imageLayout, StructPointerDecoder<Decoded_VkClearColorValue>* pColor, uint32_t rangeCount, StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges);
typedef void (VKAPI_ATTR *PFN_CmdClearDepthStencilImage_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId image, VkImageLayout imageLayout, StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil, uint32_t rangeCount, StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges);
typedef void (VKAPI_ATTR *PFN_CmdClearAttachments_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t attachmentCount, StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments, uint32_t rectCount, StructPointerDecoder<Decoded_VkClearRect>* pRects);
typedef void (VKAPI_ATTR *PFN_CmdResolveImage_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkImageResolve>* pRegions);
typedef void (VKAPI_ATTR *PFN_CmdSetEvent_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags stageMask);
typedef void (VKAPI_ATTR *PFN_CmdResetEvent_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags stageMask);
typedef void (VKAPI_ATTR *PFN_CmdWaitEvents_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t eventCount, HandlePointerDecoder<VkEvent>* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers);
typedef void (VKAPI_ATTR *PFN_CmdPipelineBarrier_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers);
typedef void (VKAPI_ATTR *PFN_CmdBeginQuery_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query, VkQueryControlFlags flags);
typedef void (VKAPI_ATTR *PFN_CmdEndQuery_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query);
typedef void (VKAPI_ATTR *PFN_CmdResetQueryPool_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_ATTR *PFN_CmdWriteTimestamp_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlagBits pipelineStage, format::HandleId queryPool, uint32_t query);
typedef void (VKAPI_ATTR *PFN_CmdCopyQueryPoolResults_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount, format::HandleId dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);
typedef void (VKAPI_ATTR *PFN_CmdPushConstants_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, PointerDecoder<uint8_t>* pValues);
typedef void (VKAPI_ATTR *PFN_CmdBeginRenderPass_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin, VkSubpassContents contents);
typedef void (VKAPI_ATTR *PFN_CmdNextSubpass_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkSubpassContents contents);
typedef void (VKAPI_ATTR *PFN_CmdEndRenderPass_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_CmdExecuteCommands_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t commandBufferCount, HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers);
typedef void (VKAPI_ATTR *PFN_BindBufferMemory2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos);
typedef void (VKAPI_ATTR *PFN_BindImageMemory2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos);
typedef void (VKAPI_ATTR *PFN_GetDeviceGroupPeerMemoryFeatures_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, PointerDecoder<VkPeerMemoryFeatureFlags>* pPeerMemoryFeatures);
typedef void (VKAPI_ATTR *PFN_CmdSetDeviceMask_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t deviceMask);
typedef void (VKAPI_ATTR *PFN_CmdDispatchBase_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_ATTR *PFN_EnumeratePhysicalDeviceGroups_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, PointerDecoder<uint32_t>* pPhysicalDeviceGroupCount, StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties);
typedef void (VKAPI_ATTR *PFN_GetImageMemoryRequirements2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetBufferMemoryRequirements2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetImageSparseMemoryRequirements2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFeatures2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceProperties2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFormatProperties2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceImageFormatProperties2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo, StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceQueueFamilyProperties2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pQueueFamilyPropertyCount, StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceMemoryProperties2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSparseImageFormatProperties2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties);
typedef void (VKAPI_ATTR *PFN_TrimCommandPool_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, VkCommandPoolTrimFlags flags);
typedef void (VKAPI_ATTR *PFN_GetDeviceQueue2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo, HandlePointerDecoder<VkQueue>* pQueue);
typedef void (VKAPI_ATTR *PFN_CreateSamplerYcbcrConversion_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion);
typedef void (VKAPI_ATTR *PFN_DestroySamplerYcbcrConversion_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId ycbcrConversion, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateDescriptorUpdateTemplate_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate);
typedef void (VKAPI_ATTR *PFN_DestroyDescriptorUpdateTemplate_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorUpdateTemplate, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalBufferProperties_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo, StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalFenceProperties_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo, StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalSemaphoreProperties_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo, StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties);
typedef void (VKAPI_ATTR *PFN_GetDescriptorSetLayoutSupport_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndirectCount_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndexedIndirectCount_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CreateRenderPass2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkRenderPass>* pRenderPass);
typedef void (VKAPI_ATTR *PFN_CmdBeginRenderPass2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo);
typedef void (VKAPI_ATTR *PFN_CmdNextSubpass2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);
typedef void (VKAPI_ATTR *PFN_CmdEndRenderPass2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);
typedef void (VKAPI_ATTR *PFN_ResetQueryPool_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_ATTR *PFN_GetSemaphoreCounterValue_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId semaphore, PointerDecoder<uint64_t>* pValue);
typedef void (VKAPI_ATTR *PFN_WaitSemaphores_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo, uint64_t timeout);
typedef void (VKAPI_ATTR *PFN_SignalSemaphore_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo);
typedef void (VKAPI_ATTR *PFN_GetBufferDeviceAddress_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetBufferOpaqueCaptureAddress_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetDeviceMemoryOpaqueCaptureAddress_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceToolProperties_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pToolCount, StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties);
typedef void (VKAPI_ATTR *PFN_CreatePrivateDataSlot_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPrivateDataSlot>* pPrivateDataSlot);
typedef void (VKAPI_ATTR *PFN_DestroyPrivateDataSlot_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId privateDataSlot, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_SetPrivateData_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, uint64_t data);
typedef void (VKAPI_ATTR *PFN_GetPrivateData_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, PointerDecoder<uint64_t>* pData);
typedef void (VKAPI_ATTR *PFN_CmdSetEvent2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo);
typedef void (VKAPI_ATTR *PFN_CmdResetEvent2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags2 stageMask);
typedef void (VKAPI_ATTR *PFN_CmdWaitEvents2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t eventCount, HandlePointerDecoder<VkEvent>* pEvents, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos);
typedef void (VKAPI_ATTR *PFN_CmdPipelineBarrier2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo);
typedef void (VKAPI_ATTR *PFN_CmdWriteTimestamp2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags2 stage, format::HandleId queryPool, uint32_t query);
typedef void (VKAPI_ATTR *PFN_QueueSubmit2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t submitCount, StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits, format::HandleId fence);
typedef void (VKAPI_ATTR *PFN_CmdCopyBuffer2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyImage2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyBufferToImage2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyImageToBuffer2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo);
typedef void (VKAPI_ATTR *PFN_CmdBlitImage2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdResolveImage2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdBeginRendering_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo);
typedef void (VKAPI_ATTR *PFN_CmdEndRendering_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_CmdSetCullMode_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCullModeFlags cullMode);
typedef void (VKAPI_ATTR *PFN_CmdSetFrontFace_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkFrontFace frontFace);
typedef void (VKAPI_ATTR *PFN_CmdSetPrimitiveTopology_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPrimitiveTopology primitiveTopology);
typedef void (VKAPI_ATTR *PFN_CmdSetViewportWithCount_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewport>* pViewports);
typedef void (VKAPI_ATTR *PFN_CmdSetScissorWithCount_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t scissorCount, StructPointerDecoder<Decoded_VkRect2D>* pScissors);
typedef void (VKAPI_ATTR *PFN_CmdBindVertexBuffers2_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets, PointerDecoder<VkDeviceSize>* pSizes, PointerDecoder<VkDeviceSize>* pStrides);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthTestEnable_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthWriteEnable_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthWriteEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthCompareOp_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCompareOp depthCompareOp);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthBoundsTestEnable_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBoundsTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilTestEnable_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 stencilTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilOp_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
typedef void (VKAPI_ATTR *PFN_CmdSetRasterizerDiscardEnable_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 rasterizerDiscardEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthBiasEnable_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBiasEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetPrimitiveRestartEnable_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 primitiveRestartEnable);
typedef void (VKAPI_ATTR *PFN_GetDeviceBufferMemoryRequirements_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetDeviceImageMemoryRequirements_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetDeviceImageSparseMemoryRequirements_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_DestroySurfaceKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, format::HandleId surface, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfaceSupportKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, format::HandleId surface, PointerDecoder<VkBool32>* pSupported);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfaceFormatsKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, PointerDecoder<uint32_t>* pSurfaceFormatCount, StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfacePresentModesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, PointerDecoder<uint32_t>* pPresentModeCount, PointerDecoder<VkPresentModeKHR>* pPresentModes);
typedef void (VKAPI_ATTR *PFN_CreateSwapchainKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSwapchainKHR>* pSwapchain);
typedef void (VKAPI_ATTR *PFN_DestroySwapchainKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId swapchain, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetSwapchainImagesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, PointerDecoder<uint32_t>* pSwapchainImageCount, HandlePointerDecoder<VkImage>* pSwapchainImages);
typedef void (VKAPI_ATTR *PFN_AcquireNextImageKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, uint64_t timeout, format::HandleId semaphore, format::HandleId fence, PointerDecoder<uint32_t>* pImageIndex);
typedef void (VKAPI_ATTR *PFN_QueuePresentKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo);
typedef void (VKAPI_ATTR *PFN_GetDeviceGroupPresentCapabilitiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities);
typedef void (VKAPI_ATTR *PFN_GetDeviceGroupSurfacePresentModesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId surface, PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDevicePresentRectanglesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, PointerDecoder<uint32_t>* pRectCount, StructPointerDecoder<Decoded_VkRect2D>* pRects);
typedef void (VKAPI_ATTR *PFN_AcquireNextImage2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo, PointerDecoder<uint32_t>* pImageIndex);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceDisplayPropertiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetDisplayPlaneSupportedDisplaysKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t planeIndex, PointerDecoder<uint32_t>* pDisplayCount, HandlePointerDecoder<VkDisplayKHR>* pDisplays);
typedef void (VKAPI_ATTR *PFN_GetDisplayModePropertiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_CreateDisplayModeKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display, StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDisplayModeKHR>* pMode);
typedef void (VKAPI_ATTR *PFN_GetDisplayPlaneCapabilitiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId mode, uint32_t planeIndex, StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities);
typedef void (VKAPI_ATTR *PFN_CreateDisplayPlaneSurfaceKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_CreateSharedSwapchainsKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t swapchainCount, StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSwapchainKHR>* pSwapchains);
typedef void (VKAPI_ATTR *PFN_CreateXlibSurfaceKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceXlibPresentationSupportKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t dpy, size_t visualID);
typedef void (VKAPI_ATTR *PFN_CreateXcbSurfaceKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceXcbPresentationSupportKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t connection, uint32_t visual_id);
typedef void (VKAPI_ATTR *PFN_CreateWaylandSurfaceKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t display);
typedef void (VKAPI_ATTR *PFN_CreateAndroidSurfaceKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_CreateWin32SurfaceKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceWin32PresentationSupportKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceVideoCapabilitiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile, StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR>* pCapabilities);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR>* pVideoFormatInfo, PointerDecoder<uint32_t>* pVideoFormatPropertyCount, StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR>* pVideoFormatProperties);
typedef void (VKAPI_ATTR *PFN_CreateVideoSessionKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkVideoSessionKHR>* pVideoSession);
typedef void (VKAPI_ATTR *PFN_DestroyVideoSessionKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId videoSession, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetVideoSessionMemoryRequirementsKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId videoSession, PointerDecoder<uint32_t>* pMemoryRequirementsCount, StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_BindVideoSessionMemoryKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId videoSession, uint32_t bindSessionMemoryInfoCount, StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos);
typedef void (VKAPI_ATTR *PFN_CreateVideoSessionParametersKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkVideoSessionParametersKHR>* pVideoSessionParameters);
typedef void (VKAPI_ATTR *PFN_UpdateVideoSessionParametersKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId videoSessionParameters, StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR>* pUpdateInfo);
typedef void (VKAPI_ATTR *PFN_DestroyVideoSessionParametersKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId videoSessionParameters, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CmdBeginVideoCodingKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo);
typedef void (VKAPI_ATTR *PFN_CmdEndVideoCodingKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo);
typedef void (VKAPI_ATTR *PFN_CmdControlVideoCodingKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo);
typedef void (VKAPI_ATTR *PFN_CmdDecodeVideoKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo);
typedef void (VKAPI_ATTR *PFN_CmdBeginRenderingKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo);
typedef void (VKAPI_ATTR *PFN_CmdEndRenderingKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFeatures2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceProperties2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFormatProperties2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceImageFormatProperties2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo, StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pQueueFamilyPropertyCount, StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceMemoryProperties2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetDeviceGroupPeerMemoryFeaturesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, PointerDecoder<VkPeerMemoryFeatureFlags>* pPeerMemoryFeatures);
typedef void (VKAPI_ATTR *PFN_CmdSetDeviceMaskKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t deviceMask);
typedef void (VKAPI_ATTR *PFN_CmdDispatchBaseKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_ATTR *PFN_TrimCommandPoolKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, VkCommandPoolTrimFlags flags);
typedef void (VKAPI_ATTR *PFN_EnumeratePhysicalDeviceGroupsKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, PointerDecoder<uint32_t>* pPhysicalDeviceGroupCount, StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo, StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties);
typedef void (VKAPI_ATTR *PFN_GetMemoryWin32HandleKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo, PointerDecoder<uint64_t, void*>* pHandle);
typedef void (VKAPI_ATTR *PFN_GetMemoryWin32HandlePropertiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, uint64_t handle, StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties);
typedef void (VKAPI_ATTR *PFN_GetMemoryFdKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo, PointerDecoder<int>* pFd);
typedef void (VKAPI_ATTR *PFN_GetMemoryFdPropertiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo, StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties);
typedef void (VKAPI_ATTR *PFN_ImportSemaphoreWin32HandleKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo);
typedef void (VKAPI_ATTR *PFN_GetSemaphoreWin32HandleKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo, PointerDecoder<uint64_t, void*>* pHandle);
typedef void (VKAPI_ATTR *PFN_ImportSemaphoreFdKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo);
typedef void (VKAPI_ATTR *PFN_GetSemaphoreFdKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo, PointerDecoder<int>* pFd);
typedef void (VKAPI_ATTR *PFN_CmdPushDescriptorSetKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId layout, uint32_t set, uint32_t descriptorWriteCount, StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites);
typedef void (VKAPI_ATTR *PFN_CreateDescriptorUpdateTemplateKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate);
typedef void (VKAPI_ATTR *PFN_DestroyDescriptorUpdateTemplateKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorUpdateTemplate, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateRenderPass2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkRenderPass>* pRenderPass);
typedef void (VKAPI_ATTR *PFN_CmdBeginRenderPass2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo);
typedef void (VKAPI_ATTR *PFN_CmdNextSubpass2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);
typedef void (VKAPI_ATTR *PFN_CmdEndRenderPass2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);
typedef void (VKAPI_ATTR *PFN_GetSwapchainStatusKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalFencePropertiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo, StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties);
typedef void (VKAPI_ATTR *PFN_ImportFenceWin32HandleKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo);
typedef void (VKAPI_ATTR *PFN_GetFenceWin32HandleKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo, PointerDecoder<uint64_t, void*>* pHandle);
typedef void (VKAPI_ATTR *PFN_ImportFenceFdKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo);
typedef void (VKAPI_ATTR *PFN_GetFenceFdKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo, PointerDecoder<int>* pFd);
typedef void (VKAPI_ATTR *PFN_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, PointerDecoder<uint32_t>* pCounterCount, StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters, StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo, PointerDecoder<uint32_t>* pNumPasses);
typedef void (VKAPI_ATTR *PFN_AcquireProfilingLockKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_ReleaseProfilingLockKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfaceFormats2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, PointerDecoder<uint32_t>* pSurfaceFormatCount, StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceDisplayProperties2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetDisplayModeProperties2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetDisplayPlaneCapabilities2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo, StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities);
typedef void (VKAPI_ATTR *PFN_GetImageMemoryRequirements2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetBufferMemoryRequirements2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetImageSparseMemoryRequirements2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_CreateSamplerYcbcrConversionKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion);
typedef void (VKAPI_ATTR *PFN_DestroySamplerYcbcrConversionKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId ycbcrConversion, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_BindBufferMemory2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos);
typedef void (VKAPI_ATTR *PFN_BindImageMemory2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos);
typedef void (VKAPI_ATTR *PFN_GetDescriptorSetLayoutSupportKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndirectCountKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndexedIndirectCountKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_GetSemaphoreCounterValueKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId semaphore, PointerDecoder<uint64_t>* pValue);
typedef void (VKAPI_ATTR *PFN_WaitSemaphoresKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo, uint64_t timeout);
typedef void (VKAPI_ATTR *PFN_SignalSemaphoreKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFragmentShadingRatesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pFragmentShadingRateCount, StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates);
typedef void (VKAPI_ATTR *PFN_CmdSetFragmentShadingRateKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkExtent2D>* pFragmentSize, PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps);
typedef void (VKAPI_ATTR *PFN_WaitForPresentKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, uint64_t presentId, uint64_t timeout);
typedef void (VKAPI_ATTR *PFN_GetBufferDeviceAddressKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetBufferOpaqueCaptureAddressKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_CreateDeferredOperationKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation);
typedef void (VKAPI_ATTR *PFN_DestroyDeferredOperationKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId operation, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetDeferredOperationMaxConcurrencyKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint32_t returnValue, format::HandleId device, format::HandleId operation);
typedef void (VKAPI_ATTR *PFN_GetDeferredOperationResultKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId operation);
typedef void (VKAPI_ATTR *PFN_DeferredOperationJoinKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId operation);
typedef void (VKAPI_ATTR *PFN_GetPipelineExecutablePropertiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo, PointerDecoder<uint32_t>* pExecutableCount, StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPipelineExecutableStatisticsKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo, PointerDecoder<uint32_t>* pStatisticCount, StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics);
typedef void (VKAPI_ATTR *PFN_GetPipelineExecutableInternalRepresentationsKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo, PointerDecoder<uint32_t>* pInternalRepresentationCount, StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations);
typedef void (VKAPI_ATTR *PFN_CmdEncodeVideoKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo);
typedef void (VKAPI_ATTR *PFN_CmdSetEvent2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo);
typedef void (VKAPI_ATTR *PFN_CmdResetEvent2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags2 stageMask);
typedef void (VKAPI_ATTR *PFN_CmdWaitEvents2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t eventCount, HandlePointerDecoder<VkEvent>* pEvents, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos);
typedef void (VKAPI_ATTR *PFN_CmdPipelineBarrier2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo);
typedef void (VKAPI_ATTR *PFN_CmdWriteTimestamp2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags2 stage, format::HandleId queryPool, uint32_t query);
typedef void (VKAPI_ATTR *PFN_QueueSubmit2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t submitCount, StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits, format::HandleId fence);
typedef void (VKAPI_ATTR *PFN_CmdWriteBufferMarker2AMD_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags2 stage, format::HandleId dstBuffer, VkDeviceSize dstOffset, uint32_t marker);
typedef void (VKAPI_ATTR *PFN_GetQueueCheckpointData2NV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, PointerDecoder<uint32_t>* pCheckpointDataCount, StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData);
typedef void (VKAPI_ATTR *PFN_CmdCopyBuffer2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyImage2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyBufferToImage2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyImageToBuffer2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo);
typedef void (VKAPI_ATTR *PFN_CmdBlitImage2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdResolveImage2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdTraceRaysIndirect2KHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkDeviceAddress indirectDeviceAddress);
typedef void (VKAPI_ATTR *PFN_GetDeviceBufferMemoryRequirementsKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetDeviceImageMemoryRequirementsKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetDeviceImageSparseMemoryRequirementsKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_CreateDebugReportCallbackEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback);
typedef void (VKAPI_ATTR *PFN_DestroyDebugReportCallbackEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, format::HandleId callback, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_DebugReportMessageEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, StringDecoder* pLayerPrefix, StringDecoder* pMessage);
typedef void (VKAPI_ATTR *PFN_DebugMarkerSetObjectTagEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo);
typedef void (VKAPI_ATTR *PFN_DebugMarkerSetObjectNameEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo);
typedef void (VKAPI_ATTR *PFN_CmdDebugMarkerBeginEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo);
typedef void (VKAPI_ATTR *PFN_CmdDebugMarkerEndEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_CmdDebugMarkerInsertEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo);
typedef void (VKAPI_ATTR *PFN_CmdBindTransformFeedbackBuffersEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets, PointerDecoder<VkDeviceSize>* pSizes);
typedef void (VKAPI_ATTR *PFN_CmdBeginTransformFeedbackEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, HandlePointerDecoder<VkBuffer>* pCounterBuffers, PointerDecoder<VkDeviceSize>* pCounterBufferOffsets);
typedef void (VKAPI_ATTR *PFN_CmdEndTransformFeedbackEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, HandlePointerDecoder<VkBuffer>* pCounterBuffers, PointerDecoder<VkDeviceSize>* pCounterBufferOffsets);
typedef void (VKAPI_ATTR *PFN_CmdBeginQueryIndexedEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index);
typedef void (VKAPI_ATTR *PFN_CmdEndQueryIndexedEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query, uint32_t index);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndirectByteCountEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t instanceCount, uint32_t firstInstance, format::HandleId counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride);
typedef void (VKAPI_ATTR *PFN_GetImageViewHandleNVX_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint32_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetImageViewAddressNVX_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId imageView, StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndirectCountAMD_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndexedIndirectCountAMD_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_GetShaderInfoAMD_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, PointerDecoder<size_t>* pInfoSize, PointerDecoder<uint8_t>* pInfo);
typedef void (VKAPI_ATTR *PFN_CreateStreamDescriptorSurfaceGGP_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>* pExternalImageFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetMemoryWin32HandleNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId memory, VkExternalMemoryHandleTypeFlagsNV handleType, PointerDecoder<uint64_t, void*>* pHandle);
typedef void (VKAPI_ATTR *PFN_CreateViSurfaceNN_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_CmdBeginConditionalRenderingEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin);
typedef void (VKAPI_ATTR *PFN_CmdEndConditionalRenderingEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_CmdSetViewportWScalingNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings);
typedef void (VKAPI_ATTR *PFN_ReleaseDisplayEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display);
typedef void (VKAPI_ATTR *PFN_AcquireXlibDisplayEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint64_t dpy, format::HandleId display);
typedef void (VKAPI_ATTR *PFN_GetRandROutputDisplayEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint64_t dpy, size_t rrOutput, HandlePointerDecoder<VkDisplayKHR>* pDisplay);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities);
typedef void (VKAPI_ATTR *PFN_DisplayPowerControlEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId display, StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo);
typedef void (VKAPI_ATTR *PFN_RegisterDeviceEventEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFence>* pFence);
typedef void (VKAPI_ATTR *PFN_RegisterDisplayEventEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId display, StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFence>* pFence);
typedef void (VKAPI_ATTR *PFN_GetSwapchainCounterEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, VkSurfaceCounterFlagBitsEXT counter, PointerDecoder<uint64_t>* pCounterValue);
typedef void (VKAPI_ATTR *PFN_GetRefreshCycleDurationGOOGLE_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties);
typedef void (VKAPI_ATTR *PFN_GetPastPresentationTimingGOOGLE_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, PointerDecoder<uint32_t>* pPresentationTimingCount, StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings);
typedef void (VKAPI_ATTR *PFN_CmdSetDiscardRectangleEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, StructPointerDecoder<Decoded_VkRect2D>* pDiscardRectangles);
typedef void (VKAPI_ATTR *PFN_CmdSetDiscardRectangleEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 discardRectangleEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDiscardRectangleModeEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode);
typedef void (VKAPI_ATTR *PFN_SetHdrMetadataEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t swapchainCount, HandlePointerDecoder<VkSwapchainKHR>* pSwapchains, StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata);
typedef void (VKAPI_ATTR *PFN_CreateIOSSurfaceMVK_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_CreateMacOSSurfaceMVK_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_SetDebugUtilsObjectNameEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo);
typedef void (VKAPI_ATTR *PFN_SetDebugUtilsObjectTagEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo);
typedef void (VKAPI_ATTR *PFN_QueueBeginDebugUtilsLabelEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo);
typedef void (VKAPI_ATTR *PFN_QueueEndDebugUtilsLabelEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue);
typedef void (VKAPI_ATTR *PFN_QueueInsertDebugUtilsLabelEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo);
typedef void (VKAPI_ATTR *PFN_CmdBeginDebugUtilsLabelEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo);
typedef void (VKAPI_ATTR *PFN_CmdEndDebugUtilsLabelEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_CmdInsertDebugUtilsLabelEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo);
typedef void (VKAPI_ATTR *PFN_CreateDebugUtilsMessengerEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger);
typedef void (VKAPI_ATTR *PFN_DestroyDebugUtilsMessengerEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, format::HandleId messenger, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_SubmitDebugUtilsMessageEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData);
typedef void (VKAPI_ATTR *PFN_GetAndroidHardwareBufferPropertiesANDROID_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint64_t buffer, StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetMemoryAndroidHardwareBufferANDROID_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo, PointerDecoder<uint64_t, void*>* pBuffer);
typedef void (VKAPI_ATTR *PFN_CmdSetSampleLocationsEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceMultisamplePropertiesEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkSampleCountFlagBits samples, StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties);
typedef void (VKAPI_ATTR *PFN_GetImageDrmFormatModifierPropertiesEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties);
typedef void (VKAPI_ATTR *PFN_CreateValidationCacheEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache);
typedef void (VKAPI_ATTR *PFN_DestroyValidationCacheEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId validationCache, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_MergeValidationCachesEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId dstCache, uint32_t srcCacheCount, HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches);
typedef void (VKAPI_ATTR *PFN_GetValidationCacheDataEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId validationCache, PointerDecoder<size_t>* pDataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_CmdBindShadingRateImageNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId imageView, VkImageLayout imageLayout);
typedef void (VKAPI_ATTR *PFN_CmdSetViewportShadingRatePaletteNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes);
typedef void (VKAPI_ATTR *PFN_CmdSetCoarseSampleOrderNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders);
typedef void (VKAPI_ATTR *PFN_CreateAccelerationStructureNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure);
typedef void (VKAPI_ATTR *PFN_DestroyAccelerationStructureNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId accelerationStructure, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetAccelerationStructureMemoryRequirementsNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_BindAccelerationStructureMemoryNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos);
typedef void (VKAPI_ATTR *PFN_CmdBuildAccelerationStructureNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV>* pInfo, format::HandleId instanceData, VkDeviceSize instanceOffset, VkBool32 update, format::HandleId dst, format::HandleId src, format::HandleId scratch, VkDeviceSize scratchOffset);
typedef void (VKAPI_ATTR *PFN_CmdCopyAccelerationStructureNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId dst, format::HandleId src, VkCopyAccelerationStructureModeKHR mode);
typedef void (VKAPI_ATTR *PFN_CmdTraceRaysNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, format::HandleId missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, format::HandleId hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, format::HandleId callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth);
typedef void (VKAPI_ATTR *PFN_CreateRayTracingPipelinesNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines);
typedef void (VKAPI_ATTR *PFN_GetRayTracingShaderGroupHandlesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_GetRayTracingShaderGroupHandlesNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_GetAccelerationStructureHandleNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId accelerationStructure, size_t dataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_CmdWriteAccelerationStructuresPropertiesNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t accelerationStructureCount, HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures, VkQueryType queryType, format::HandleId queryPool, uint32_t firstQuery);
typedef void (VKAPI_ATTR *PFN_CompileDeferredNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t shader);
typedef void (VKAPI_ATTR *PFN_GetMemoryHostPointerPropertiesEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, uint64_t pHostPointer, StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties);
typedef void (VKAPI_ATTR *PFN_CmdWriteBufferMarkerAMD_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlagBits pipelineStage, format::HandleId dstBuffer, VkDeviceSize dstOffset, uint32_t marker);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pTimeDomainCount, PointerDecoder<VkTimeDomainEXT>* pTimeDomains);
typedef void (VKAPI_ATTR *PFN_GetCalibratedTimestampsEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t timestampCount, StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>* pTimestampInfos, PointerDecoder<uint64_t>* pTimestamps, PointerDecoder<uint64_t>* pMaxDeviation);
typedef void (VKAPI_ATTR *PFN_CmdDrawMeshTasksNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t taskCount, uint32_t firstTask);
typedef void (VKAPI_ATTR *PFN_CmdDrawMeshTasksIndirectNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawMeshTasksIndirectCountNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdSetExclusiveScissorEnableNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, PointerDecoder<VkBool32>* pExclusiveScissorEnables);
typedef void (VKAPI_ATTR *PFN_CmdSetExclusiveScissorNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, StructPointerDecoder<Decoded_VkRect2D>* pExclusiveScissors);
typedef void (VKAPI_ATTR *PFN_CmdSetCheckpointNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint64_t pCheckpointMarker);
typedef void (VKAPI_ATTR *PFN_GetQueueCheckpointDataNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, PointerDecoder<uint32_t>* pCheckpointDataCount, StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData);
typedef void (VKAPI_ATTR *PFN_InitializePerformanceApiINTEL_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo);
typedef void (VKAPI_ATTR *PFN_UninitializePerformanceApiINTEL_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device);
typedef void (VKAPI_ATTR *PFN_CmdSetPerformanceMarkerINTEL_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo);
typedef void (VKAPI_ATTR *PFN_CmdSetPerformanceStreamMarkerINTEL_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo);
typedef void (VKAPI_ATTR *PFN_CmdSetPerformanceOverrideINTEL_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo);
typedef void (VKAPI_ATTR *PFN_AcquirePerformanceConfigurationINTEL_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo, HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration);
typedef void (VKAPI_ATTR *PFN_ReleasePerformanceConfigurationINTEL_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId configuration);
typedef void (VKAPI_ATTR *PFN_QueueSetPerformanceConfigurationINTEL_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, format::HandleId configuration);
typedef void (VKAPI_ATTR *PFN_GetPerformanceParameterINTEL_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkPerformanceParameterTypeINTEL parameter, StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue);
typedef void (VKAPI_ATTR *PFN_SetLocalDimmingAMD_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId swapChain, VkBool32 localDimmingEnable);
typedef void (VKAPI_ATTR *PFN_CreateImagePipeSurfaceFUCHSIA_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_CreateMetalSurfaceEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetBufferDeviceAddressEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceToolPropertiesEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pToolCount, StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pCombinationCount, StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfacePresentModes2EXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, PointerDecoder<uint32_t>* pPresentModeCount, PointerDecoder<VkPresentModeKHR>* pPresentModes);
typedef void (VKAPI_ATTR *PFN_AcquireFullScreenExclusiveModeEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain);
typedef void (VKAPI_ATTR *PFN_ReleaseFullScreenExclusiveModeEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain);
typedef void (VKAPI_ATTR *PFN_GetDeviceGroupSurfacePresentModes2EXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes);
typedef void (VKAPI_ATTR *PFN_CreateHeadlessSurfaceEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_CmdSetLineStippleEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);
typedef void (VKAPI_ATTR *PFN_ResetQueryPoolEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_ATTR *PFN_CmdSetCullModeEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCullModeFlags cullMode);
typedef void (VKAPI_ATTR *PFN_CmdSetFrontFaceEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkFrontFace frontFace);
typedef void (VKAPI_ATTR *PFN_CmdSetPrimitiveTopologyEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPrimitiveTopology primitiveTopology);
typedef void (VKAPI_ATTR *PFN_CmdSetViewportWithCountEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewport>* pViewports);
typedef void (VKAPI_ATTR *PFN_CmdSetScissorWithCountEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t scissorCount, StructPointerDecoder<Decoded_VkRect2D>* pScissors);
typedef void (VKAPI_ATTR *PFN_CmdBindVertexBuffers2EXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets, PointerDecoder<VkDeviceSize>* pSizes, PointerDecoder<VkDeviceSize>* pStrides);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthTestEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthWriteEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthWriteEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthCompareOpEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCompareOp depthCompareOp);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthBoundsTestEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBoundsTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilTestEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 stencilTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilOpEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
typedef void (VKAPI_ATTR *PFN_ReleaseSwapchainImagesEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo);
typedef void (VKAPI_ATTR *PFN_GetGeneratedCommandsMemoryRequirementsNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_CmdPreprocessGeneratedCommandsNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo);
typedef void (VKAPI_ATTR *PFN_CmdExecuteGeneratedCommandsNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 isPreprocessed, StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo);
typedef void (VKAPI_ATTR *PFN_CmdBindPipelineShaderGroupNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId pipeline, uint32_t groupIndex);
typedef void (VKAPI_ATTR *PFN_CreateIndirectCommandsLayoutNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout);
typedef void (VKAPI_ATTR *PFN_DestroyIndirectCommandsLayoutNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId indirectCommandsLayout, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_AcquireDrmDisplayEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, int32_t drmFd, format::HandleId display);
typedef void (VKAPI_ATTR *PFN_GetDrmDisplayEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, int32_t drmFd, uint32_t connectorId, HandlePointerDecoder<VkDisplayKHR>* display);
typedef void (VKAPI_ATTR *PFN_CreatePrivateDataSlotEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPrivateDataSlot>* pPrivateDataSlot);
typedef void (VKAPI_ATTR *PFN_DestroyPrivateDataSlotEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId privateDataSlot, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_SetPrivateDataEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, uint64_t data);
typedef void (VKAPI_ATTR *PFN_GetPrivateDataEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, PointerDecoder<uint64_t>* pData);
typedef void (VKAPI_ATTR *PFN_CmdSetFragmentShadingRateEnumNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkFragmentShadingRateNV shadingRate, PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps);
typedef void (VKAPI_ATTR *PFN_GetImageSubresourceLayout2EXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkImageSubresource2EXT>* pSubresource, StructPointerDecoder<Decoded_VkSubresourceLayout2EXT>* pLayout);
typedef void (VKAPI_ATTR *PFN_GetDeviceFaultInfoEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT>* pFaultCounts, StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT>* pFaultInfo);
typedef void (VKAPI_ATTR *PFN_AcquireWinrtDisplayNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display);
typedef void (VKAPI_ATTR *PFN_GetWinrtDisplayNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t deviceRelativeId, HandlePointerDecoder<VkDisplayKHR>* pDisplay);
typedef void (VKAPI_ATTR *PFN_CreateDirectFBSurfaceEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t dfb);
typedef void (VKAPI_ATTR *PFN_CmdSetVertexInputEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t vertexBindingDescriptionCount, StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions);
typedef void (VKAPI_ATTR *PFN_GetMemoryZirconHandleFUCHSIA_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo, PointerDecoder<uint32_t>* pZirconHandle);
typedef void (VKAPI_ATTR *PFN_GetMemoryZirconHandlePropertiesFUCHSIA_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, uint32_t zirconHandle, StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA>* pMemoryZirconHandleProperties);
typedef void (VKAPI_ATTR *PFN_ImportSemaphoreZirconHandleFUCHSIA_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo);
typedef void (VKAPI_ATTR *PFN_GetSemaphoreZirconHandleFUCHSIA_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo, PointerDecoder<uint32_t>* pZirconHandle);
typedef void (VKAPI_ATTR *PFN_CmdBindInvocationMaskHUAWEI_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId imageView, VkImageLayout imageLayout);
typedef void (VKAPI_ATTR *PFN_GetMemoryRemoteAddressNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo, PointerDecoder<uint64_t, void*>* pAddress);
typedef void (VKAPI_ATTR *PFN_CmdSetPatchControlPointsEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t patchControlPoints);
typedef void (VKAPI_ATTR *PFN_CmdSetRasterizerDiscardEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 rasterizerDiscardEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthBiasEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBiasEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetLogicOpEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkLogicOp logicOp);
typedef void (VKAPI_ATTR *PFN_CmdSetPrimitiveRestartEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 primitiveRestartEnable);
typedef void (VKAPI_ATTR *PFN_CreateScreenSurfaceQNX_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceScreenPresentationSupportQNX_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t window);
typedef void (VKAPI_ATTR *PFN_CmdSetColorWriteEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t attachmentCount, PointerDecoder<VkBool32>* pColorWriteEnables);
typedef void (VKAPI_ATTR *PFN_CmdDrawMultiEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t drawCount, StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawMultiIndexedEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t drawCount, StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, PointerDecoder<int32_t>* pVertexOffset);
typedef void (VKAPI_ATTR *PFN_CreateMicromapEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkMicromapEXT>* pMicromap);
typedef void (VKAPI_ATTR *PFN_DestroyMicromapEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId micromap, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CmdBuildMicromapsEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t infoCount, StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos);
typedef void (VKAPI_ATTR *PFN_BuildMicromapsEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, uint32_t infoCount, StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos);
typedef void (VKAPI_ATTR *PFN_CopyMicromapEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo);
typedef void (VKAPI_ATTR *PFN_CopyMicromapToMemoryEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo);
typedef void (VKAPI_ATTR *PFN_CopyMemoryToMicromapEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo);
typedef void (VKAPI_ATTR *PFN_WriteMicromapsPropertiesEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t micromapCount, HandlePointerDecoder<VkMicromapEXT>* pMicromaps, VkQueryType queryType, size_t dataSize, PointerDecoder<uint8_t>* pData, size_t stride);
typedef void (VKAPI_ATTR *PFN_CmdCopyMicromapEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyMicromapToMemoryEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyMemoryToMicromapEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo);
typedef void (VKAPI_ATTR *PFN_CmdWriteMicromapsPropertiesEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t micromapCount, HandlePointerDecoder<VkMicromapEXT>* pMicromaps, VkQueryType queryType, format::HandleId queryPool, uint32_t firstQuery);
typedef void (VKAPI_ATTR *PFN_GetDeviceMicromapCompatibilityEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo, PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility);
typedef void (VKAPI_ATTR *PFN_GetMicromapBuildSizesEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkAccelerationStructureBuildTypeKHR buildType, StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pBuildInfo, StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT>* pSizeInfo);
typedef void (VKAPI_ATTR *PFN_CmdDrawClusterHUAWEI_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_ATTR *PFN_CmdDrawClusterIndirectHUAWEI_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset);
typedef void (VKAPI_ATTR *PFN_SetDeviceMemoryPriorityEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory, float priority);
typedef void (VKAPI_ATTR *PFN_GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference, StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping);
typedef void (VKAPI_ATTR *PFN_GetDescriptorSetHostMappingVALVE_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorSet, PointerDecoder<uint64_t, void*>* ppData);
typedef void (VKAPI_ATTR *PFN_CmdSetTessellationDomainOriginEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkTessellationDomainOrigin domainOrigin);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthClampEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthClampEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetPolygonModeEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPolygonMode polygonMode);
typedef void (VKAPI_ATTR *PFN_CmdSetRasterizationSamplesEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkSampleCountFlagBits rasterizationSamples);
typedef void (VKAPI_ATTR *PFN_CmdSetSampleMaskEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkSampleCountFlagBits samples, PointerDecoder<VkSampleMask>* pSampleMask);
typedef void (VKAPI_ATTR *PFN_CmdSetAlphaToCoverageEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 alphaToCoverageEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetAlphaToOneEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 alphaToOneEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetLogicOpEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 logicOpEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetColorBlendEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, PointerDecoder<VkBool32>* pColorBlendEnables);
typedef void (VKAPI_ATTR *PFN_CmdSetColorBlendEquationEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations);
typedef void (VKAPI_ATTR *PFN_CmdSetColorWriteMaskEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, PointerDecoder<VkColorComponentFlags>* pColorWriteMasks);
typedef void (VKAPI_ATTR *PFN_CmdSetRasterizationStreamEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t rasterizationStream);
typedef void (VKAPI_ATTR *PFN_CmdSetConservativeRasterizationModeEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode);
typedef void (VKAPI_ATTR *PFN_CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float extraPrimitiveOverestimationSize);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthClipEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthClipEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetSampleLocationsEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 sampleLocationsEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetColorBlendAdvancedEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced);
typedef void (VKAPI_ATTR *PFN_CmdSetProvokingVertexModeEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkProvokingVertexModeEXT provokingVertexMode);
typedef void (VKAPI_ATTR *PFN_CmdSetLineRasterizationModeEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode);
typedef void (VKAPI_ATTR *PFN_CmdSetLineStippleEnableEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 stippledLineEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthClipNegativeOneToOneEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 negativeOneToOne);
typedef void (VKAPI_ATTR *PFN_CmdSetViewportWScalingEnableNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 viewportWScalingEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetViewportSwizzleNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles);
typedef void (VKAPI_ATTR *PFN_CmdSetCoverageToColorEnableNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 coverageToColorEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetCoverageToColorLocationNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t coverageToColorLocation);
typedef void (VKAPI_ATTR *PFN_CmdSetCoverageModulationModeNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCoverageModulationModeNV coverageModulationMode);
typedef void (VKAPI_ATTR *PFN_CmdSetCoverageModulationTableEnableNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 coverageModulationTableEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetCoverageModulationTableNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t coverageModulationTableCount, PointerDecoder<float>* pCoverageModulationTable);
typedef void (VKAPI_ATTR *PFN_CmdSetShadingRateImageEnableNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 shadingRateImageEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetRepresentativeFragmentTestEnableNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 representativeFragmentTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetCoverageReductionModeNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCoverageReductionModeNV coverageReductionMode);
typedef void (VKAPI_ATTR *PFN_GetShaderModuleIdentifierEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId shaderModule, StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier);
typedef void (VKAPI_ATTR *PFN_GetShaderModuleCreateInfoIdentifierEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV>* pOpticalFlowImageFormatInfo, PointerDecoder<uint32_t>* pFormatCount, StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV>* pImageFormatProperties);
typedef void (VKAPI_ATTR *PFN_CreateOpticalFlowSessionNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession);
typedef void (VKAPI_ATTR *PFN_DestroyOpticalFlowSessionNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId session, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_BindOpticalFlowSessionImageNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId session, VkOpticalFlowSessionBindingPointNV bindingPoint, format::HandleId view, VkImageLayout layout);
typedef void (VKAPI_ATTR *PFN_CmdOpticalFlowExecuteNV_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId session, StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo);
typedef void (VKAPI_ATTR *PFN_GetFramebufferTilePropertiesQCOM_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId framebuffer, PointerDecoder<uint32_t>* pPropertiesCount, StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetDynamicRenderingTilePropertiesQCOM_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo, StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties);
typedef void (VKAPI_ATTR *PFN_CreateAccelerationStructureKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure);
typedef void (VKAPI_ATTR *PFN_DestroyAccelerationStructureKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId accelerationStructure, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CmdBuildAccelerationStructuresKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t infoCount, StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos, StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos);
typedef void (VKAPI_ATTR *PFN_CmdBuildAccelerationStructuresIndirectKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t infoCount, StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos, PointerDecoder<VkDeviceAddress>* pIndirectDeviceAddresses, PointerDecoder<uint32_t>* pIndirectStrides, PointerDecoder<uint32_t*>* ppMaxPrimitiveCounts);
typedef void (VKAPI_ATTR *PFN_CopyAccelerationStructureToMemoryKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_CopyMemoryToAccelerationStructureKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_WriteAccelerationStructuresPropertiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t accelerationStructureCount, HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures, VkQueryType queryType, size_t dataSize, PointerDecoder<uint8_t>* pData, size_t stride);
typedef void (VKAPI_ATTR *PFN_CmdCopyAccelerationStructureKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyAccelerationStructureToMemoryKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyMemoryToAccelerationStructureKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetAccelerationStructureDeviceAddressKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_CmdWriteAccelerationStructuresPropertiesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t accelerationStructureCount, HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures, VkQueryType queryType, format::HandleId queryPool, uint32_t firstQuery);
typedef void (VKAPI_ATTR *PFN_GetDeviceAccelerationStructureCompatibilityKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo, PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility);
typedef void (VKAPI_ATTR *PFN_GetAccelerationStructureBuildSizesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkAccelerationStructureBuildTypeKHR buildType, StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo, PointerDecoder<uint32_t>* pMaxPrimitiveCounts, StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>* pSizeInfo);
typedef void (VKAPI_ATTR *PFN_CmdTraceRaysKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth);
typedef void (VKAPI_ATTR *PFN_CreateRayTracingPipelinesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines);
typedef void (VKAPI_ATTR *PFN_GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_CmdTraceRaysIndirectKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress);
typedef void (VKAPI_ATTR *PFN_GetRayTracingShaderGroupStackSizeKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceSize returnValue, format::HandleId device, format::HandleId pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader);
typedef void (VKAPI_ATTR *PFN_CmdSetRayTracingPipelineStackSizeKHR_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t pipelineStackSize);
typedef void (VKAPI_ATTR *PFN_CmdDrawMeshTasksEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_ATTR *PFN_CmdDrawMeshTasksIndirectEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawMeshTasksIndirectCountEXT_PreCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
// clang-format on

GFXRECON_BEGIN_NAMESPACE(noop)

// clang-format off
static VKAPI_ATTR void VKAPI_CALL CreateInstance_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkInstance>* pInstance) { }
static VKAPI_ATTR void VKAPI_CALL DestroyInstance_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDevices_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, PointerDecoder<uint32_t>* pPhysicalDeviceCount, HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pQueueFamilyPropertyCount, StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateDevice_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDevice>* pDevice) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDevice_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceQueue_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t queueFamilyIndex, uint32_t queueIndex, HandlePointerDecoder<VkQueue>* pQueue) { }
static VKAPI_ATTR void VKAPI_CALL QueueSubmit_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t submitCount, StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits, format::HandleId fence) { }
static VKAPI_ATTR void VKAPI_CALL QueueWaitIdle_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue) { }
static VKAPI_ATTR void VKAPI_CALL DeviceWaitIdle_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device) { }
static VKAPI_ATTR void VKAPI_CALL AllocateMemory_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDeviceMemory>* pMemory) { }
static VKAPI_ATTR void VKAPI_CALL FreeMemory_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL MapMemory_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, PointerDecoder<uint64_t, void*>* ppData) { }
static VKAPI_ATTR void VKAPI_CALL UnmapMemory_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory) { }
static VKAPI_ATTR void VKAPI_CALL FlushMappedMemoryRanges_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t memoryRangeCount, StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges) { }
static VKAPI_ATTR void VKAPI_CALL InvalidateMappedMemoryRanges_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t memoryRangeCount, StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory, PointerDecoder<VkDeviceSize>* pCommittedMemoryInBytes) { }
static VKAPI_ATTR void VKAPI_CALL BindBufferMemory_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId buffer, format::HandleId memory, VkDeviceSize memoryOffset) { }
static VKAPI_ATTR void VKAPI_CALL BindImageMemory_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId image, format::HandleId memory, VkDeviceSize memoryOffset) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId buffer, StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL QueueBindSparse_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo, format::HandleId fence) { }
static VKAPI_ATTR void VKAPI_CALL CreateFence_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFence>* pFence) { }
static VKAPI_ATTR void VKAPI_CALL DestroyFence_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId fence, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL ResetFences_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t fenceCount, HandlePointerDecoder<VkFence>* pFences) { }
static VKAPI_ATTR void VKAPI_CALL GetFenceStatus_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId fence) { }
static VKAPI_ATTR void VKAPI_CALL WaitForFences_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t fenceCount, HandlePointerDecoder<VkFence>* pFences, VkBool32 waitAll, uint64_t timeout) { }
static VKAPI_ATTR void VKAPI_CALL CreateSemaphore_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSemaphore>* pSemaphore) { }
static VKAPI_ATTR void VKAPI_CALL DestroySemaphore_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId semaphore, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateEvent_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkEvent>* pEvent) { }
static VKAPI_ATTR void VKAPI_CALL DestroyEvent_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId event, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetEventStatus_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId event) { }
static VKAPI_ATTR void VKAPI_CALL SetEvent_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId event) { }
static VKAPI_ATTR void VKAPI_CALL ResetEvent_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId event) { }
static VKAPI_ATTR void VKAPI_CALL CreateQueryPool_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkQueryPool>* pQueryPool) { }
static VKAPI_ATTR void VKAPI_CALL DestroyQueryPool_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId queryPool, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetQueryPoolResults_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, PointerDecoder<uint8_t>* pData, VkDeviceSize stride, VkQueryResultFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL CreateBuffer_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkBuffer>* pBuffer) { }
static VKAPI_ATTR void VKAPI_CALL DestroyBuffer_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId buffer, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateBufferView_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkBufferView>* pView) { }
static VKAPI_ATTR void VKAPI_CALL DestroyBufferView_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId bufferView, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateImage_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkImage>* pImage) { }
static VKAPI_ATTR void VKAPI_CALL DestroyImage_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource, StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout) { }
static VKAPI_ATTR void VKAPI_CALL CreateImageView_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkImageView>* pView) { }
static VKAPI_ATTR void VKAPI_CALL DestroyImageView_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId imageView, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateShaderModule_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkShaderModule>* pShaderModule) { }
static VKAPI_ATTR void VKAPI_CALL DestroyShaderModule_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId shaderModule, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreatePipelineCache_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipelineCache>* pPipelineCache) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId pipelineCache, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetPipelineCacheData_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, PointerDecoder<size_t>* pDataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL MergePipelineCaches_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId dstCache, uint32_t srcCacheCount, HandlePointerDecoder<VkPipelineCache>* pSrcCaches) { }
static VKAPI_ATTR void VKAPI_CALL CreateGraphicsPipelines_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines) { }
static VKAPI_ATTR void VKAPI_CALL CreateComputePipelines_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPipeline_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId pipeline, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreatePipelineLayout_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipelineLayout>* pPipelineLayout) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId pipelineLayout, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateSampler_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSampler>* pSampler) { }
static VKAPI_ATTR void VKAPI_CALL DestroySampler_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId sampler, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateDescriptorSetLayout_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorSetLayout, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateDescriptorPool_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorPool>* pDescriptorPool) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorPool, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL ResetDescriptorPool_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId descriptorPool, VkDescriptorPoolResetFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL AllocateDescriptorSets_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo, HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) { }
static VKAPI_ATTR void VKAPI_CALL FreeDescriptorSets_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId descriptorPool, uint32_t descriptorSetCount, HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) { }
static VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t descriptorWriteCount, StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites, uint32_t descriptorCopyCount, StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies) { }
static VKAPI_ATTR void VKAPI_CALL CreateFramebuffer_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFramebuffer>* pFramebuffer) { }
static VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId framebuffer, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateRenderPass_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkRenderPass>* pRenderPass) { }
static VKAPI_ATTR void VKAPI_CALL DestroyRenderPass_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId renderPass, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId renderPass, StructPointerDecoder<Decoded_VkExtent2D>* pGranularity) { }
static VKAPI_ATTR void VKAPI_CALL CreateCommandPool_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkCommandPool>* pCommandPool) { }
static VKAPI_ATTR void VKAPI_CALL DestroyCommandPool_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL ResetCommandPool_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId commandPool, VkCommandPoolResetFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL AllocateCommandBuffers_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo, HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) { }
static VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, uint32_t commandBufferCount, HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) { }
static VKAPI_ATTR void VKAPI_CALL BeginCommandBuffer_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) { }
static VKAPI_ATTR void VKAPI_CALL EndCommandBuffer_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL ResetCommandBuffer_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, VkCommandBufferResetFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindPipeline_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId pipeline) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewport_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewport>* pViewports) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissor_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstScissor, uint32_t scissorCount, StructPointerDecoder<Decoded_VkRect2D>* pScissors) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float lineWidth) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, PointerDecoder<float>* blendConstants) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float minDepthBounds, float maxDepthBounds) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId layout, uint32_t firstSet, uint32_t descriptorSetCount, HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets, uint32_t dynamicOffsetCount, PointerDecoder<uint32_t>* pDynamicOffsets) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, VkIndexType indexType) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets) { }
static VKAPI_ATTR void VKAPI_CALL CmdDraw_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDispatch_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcBuffer, format::HandleId dstBuffer, uint32_t regionCount, StructPointerDecoder<Decoded_VkBufferCopy>* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkImageCopy>* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkImageBlit>* pRegions, VkFilter filter) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcBuffer, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstBuffer, uint32_t regionCount, StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdFillBuffer_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) { }
static VKAPI_ATTR void VKAPI_CALL CmdClearColorImage_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId image, VkImageLayout imageLayout, StructPointerDecoder<Decoded_VkClearColorValue>* pColor, uint32_t rangeCount, StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges) { }
static VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId image, VkImageLayout imageLayout, StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil, uint32_t rangeCount, StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges) { }
static VKAPI_ATTR void VKAPI_CALL CmdClearAttachments_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t attachmentCount, StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments, uint32_t rectCount, StructPointerDecoder<Decoded_VkClearRect>* pRects) { }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkImageResolve>* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags stageMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags stageMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t eventCount, HandlePointerDecoder<VkEvent>* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers) { }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginQuery_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query, VkQueryControlFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndQuery_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query) { }
static VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlagBits pipelineStage, format::HandleId queryPool, uint32_t query) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount, format::HandleId dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL CmdPushConstants_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, PointerDecoder<uint8_t>* pValues) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin, VkSubpassContents contents) { }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkSubpassContents contents) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t commandBufferCount, HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) { }
static VKAPI_ATTR void VKAPI_CALL BindBufferMemory2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL BindImageMemory2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, PointerDecoder<VkPeerMemoryFeatureFlags>* pPeerMemoryFeatures) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t deviceMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchBase_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceGroups_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, PointerDecoder<uint32_t>* pPhysicalDeviceGroupCount, StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo, StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pQueueFamilyPropertyCount, StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL TrimCommandPool_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, VkCommandPoolTrimFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo, HandlePointerDecoder<VkQueue>* pQueue) { }
static VKAPI_ATTR void VKAPI_CALL CreateSamplerYcbcrConversion_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion) { }
static VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId ycbcrConversion, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateDescriptorUpdateTemplate_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorUpdateTemplate, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo, StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo, StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo, StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CreateRenderPass2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkRenderPass>* pRenderPass) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) { }
static VKAPI_ATTR void VKAPI_CALL ResetQueryPool_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreCounterValue_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId semaphore, PointerDecoder<uint64_t>* pValue) { }
static VKAPI_ATTR void VKAPI_CALL WaitSemaphores_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo, uint64_t timeout) { }
static VKAPI_ATTR void VKAPI_CALL SignalSemaphore_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddress_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferOpaqueCaptureAddress_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceToolProperties_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pToolCount, StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreatePrivateDataSlot_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPrivateDataSlot>* pPrivateDataSlot) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId privateDataSlot, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL SetPrivateData_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, uint64_t data) { }
static VKAPI_ATTR void VKAPI_CALL GetPrivateData_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, PointerDecoder<uint64_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags2 stageMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t eventCount, HandlePointerDecoder<VkEvent>* pEvents, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos) { }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags2 stage, format::HandleId queryPool, uint32_t query) { }
static VKAPI_ATTR void VKAPI_CALL QueueSubmit2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t submitCount, StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits, format::HandleId fence) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRendering_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRendering_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCullMode_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCullModeFlags cullMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkFrontFace frontFace) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPrimitiveTopology primitiveTopology) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewport>* pViewports) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t scissorCount, StructPointerDecoder<Decoded_VkRect2D>* pScissors) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets, PointerDecoder<VkDeviceSize>* pSizes, PointerDecoder<VkDeviceSize>* pStrides) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthWriteEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCompareOp depthCompareOp) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBoundsTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 stencilTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 rasterizerDiscardEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBiasEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 primitiveRestartEnable) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirements_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirements_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, format::HandleId surface, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, format::HandleId surface, PointerDecoder<VkBool32>* pSupported) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, PointerDecoder<uint32_t>* pSurfaceFormatCount, StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, PointerDecoder<uint32_t>* pPresentModeCount, PointerDecoder<VkPresentModeKHR>* pPresentModes) { }
static VKAPI_ATTR void VKAPI_CALL CreateSwapchainKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSwapchainKHR>* pSwapchain) { }
static VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId swapchain, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetSwapchainImagesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, PointerDecoder<uint32_t>* pSwapchainImageCount, HandlePointerDecoder<VkImage>* pSwapchainImages) { }
static VKAPI_ATTR void VKAPI_CALL AcquireNextImageKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, uint64_t timeout, format::HandleId semaphore, format::HandleId fence, PointerDecoder<uint32_t>* pImageIndex) { }
static VKAPI_ATTR void VKAPI_CALL QueuePresentKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId surface, PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, PointerDecoder<uint32_t>* pRectCount, StructPointerDecoder<Decoded_VkRect2D>* pRects) { }
static VKAPI_ATTR void VKAPI_CALL AcquireNextImage2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo, PointerDecoder<uint32_t>* pImageIndex) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t planeIndex, PointerDecoder<uint32_t>* pDisplayCount, HandlePointerDecoder<VkDisplayKHR>* pDisplays) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayModePropertiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateDisplayModeKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display, StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDisplayModeKHR>* pMode) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneCapabilitiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId mode, uint32_t planeIndex, StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL CreateDisplayPlaneSurfaceKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CreateSharedSwapchainsKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t swapchainCount, StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSwapchainKHR>* pSwapchains) { }
static VKAPI_ATTR void VKAPI_CALL CreateXlibSurfaceKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t dpy, size_t visualID) { }
static VKAPI_ATTR void VKAPI_CALL CreateXcbSurfaceKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t connection, uint32_t visual_id) { }
static VKAPI_ATTR void VKAPI_CALL CreateWaylandSurfaceKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t display) { }
static VKAPI_ATTR void VKAPI_CALL CreateAndroidSurfaceKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CreateWin32SurfaceKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceVideoCapabilitiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile, StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR>* pCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR>* pVideoFormatInfo, PointerDecoder<uint32_t>* pVideoFormatPropertyCount, StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR>* pVideoFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateVideoSessionKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkVideoSessionKHR>* pVideoSession) { }
static VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId videoSession, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetVideoSessionMemoryRequirementsKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId videoSession, PointerDecoder<uint32_t>* pMemoryRequirementsCount, StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL BindVideoSessionMemoryKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId videoSession, uint32_t bindSessionMemoryInfoCount, StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos) { }
static VKAPI_ATTR void VKAPI_CALL CreateVideoSessionParametersKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkVideoSessionParametersKHR>* pVideoSessionParameters) { }
static VKAPI_ATTR void VKAPI_CALL UpdateVideoSessionParametersKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId videoSessionParameters, StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR>* pUpdateInfo) { }
static VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionParametersKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId videoSessionParameters, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginVideoCodingKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndVideoCodingKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdControlVideoCodingKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdDecodeVideoKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderingKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderingKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo, StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pQueueFamilyPropertyCount, StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, PointerDecoder<VkPeerMemoryFeatureFlags>* pPeerMemoryFeatures) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t deviceMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchBaseKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, VkCommandPoolTrimFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, PointerDecoder<uint32_t>* pPhysicalDeviceGroupCount, StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo, StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandleKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo, PointerDecoder<uint64_t, void*>* pHandle) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandlePropertiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, uint64_t handle, StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryFdKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo, PointerDecoder<int>* pFd) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryFdPropertiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo, StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties) { }
static VKAPI_ATTR void VKAPI_CALL ImportSemaphoreWin32HandleKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreWin32HandleKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo, PointerDecoder<uint64_t, void*>* pHandle) { }
static VKAPI_ATTR void VKAPI_CALL ImportSemaphoreFdKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreFdKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo, PointerDecoder<int>* pFd) { }
static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId layout, uint32_t set, uint32_t descriptorWriteCount, StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites) { }
static VKAPI_ATTR void VKAPI_CALL CreateDescriptorUpdateTemplateKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorUpdateTemplate, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateRenderPass2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkRenderPass>* pRenderPass) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetSwapchainStatusKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo, StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties) { }
static VKAPI_ATTR void VKAPI_CALL ImportFenceWin32HandleKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetFenceWin32HandleKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo, PointerDecoder<uint64_t, void*>* pHandle) { }
static VKAPI_ATTR void VKAPI_CALL ImportFenceFdKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetFenceFdKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo, PointerDecoder<int>* pFd) { }
static VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, PointerDecoder<uint32_t>* pCounterCount, StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters, StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo, PointerDecoder<uint32_t>* pNumPasses) { }
static VKAPI_ATTR void VKAPI_CALL AcquireProfilingLockKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, PointerDecoder<uint32_t>* pSurfaceFormatCount, StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayModeProperties2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneCapabilities2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo, StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL CreateSamplerYcbcrConversionKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion) { }
static VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId ycbcrConversion, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL BindBufferMemory2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL BindImageMemory2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreCounterValueKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId semaphore, PointerDecoder<uint64_t>* pValue) { }
static VKAPI_ATTR void VKAPI_CALL WaitSemaphoresKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo, uint64_t timeout) { }
static VKAPI_ATTR void VKAPI_CALL SignalSemaphoreKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFragmentShadingRatesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pFragmentShadingRateCount, StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkExtent2D>* pFragmentSize, PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps) { }
static VKAPI_ATTR void VKAPI_CALL WaitForPresentKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, uint64_t presentId, uint64_t timeout) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddressKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferOpaqueCaptureAddressKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CreateDeferredOperationKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDeferredOperationKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId operation, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetDeferredOperationMaxConcurrencyKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint32_t returnValue, format::HandleId device, format::HandleId operation) { }
static VKAPI_ATTR void VKAPI_CALL GetDeferredOperationResultKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId operation) { }
static VKAPI_ATTR void VKAPI_CALL DeferredOperationJoinKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId operation) { }
static VKAPI_ATTR void VKAPI_CALL GetPipelineExecutablePropertiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo, PointerDecoder<uint32_t>* pExecutableCount, StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPipelineExecutableStatisticsKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo, PointerDecoder<uint32_t>* pStatisticCount, StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics) { }
static VKAPI_ATTR void VKAPI_CALL GetPipelineExecutableInternalRepresentationsKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo, PointerDecoder<uint32_t>* pInternalRepresentationCount, StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations) { }
static VKAPI_ATTR void VKAPI_CALL CmdEncodeVideoKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags2 stageMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t eventCount, HandlePointerDecoder<VkEvent>* pEvents, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos) { }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags2 stage, format::HandleId queryPool, uint32_t query) { }
static VKAPI_ATTR void VKAPI_CALL QueueSubmit2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t submitCount, StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits, format::HandleId fence) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarker2AMD_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags2 stage, format::HandleId dstBuffer, VkDeviceSize dstOffset, uint32_t marker) { }
static VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointData2NV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, PointerDecoder<uint32_t>* pCheckpointDataCount, StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirect2KHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkDeviceAddress indirectDeviceAddress) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirementsKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirementsKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirementsKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL CreateDebugReportCallbackEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, format::HandleId callback, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL DebugReportMessageEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, StringDecoder* pLayerPrefix, StringDecoder* pMessage) { }
static VKAPI_ATTR void VKAPI_CALL DebugMarkerSetObjectTagEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo) { }
static VKAPI_ATTR void VKAPI_CALL DebugMarkerSetObjectNameEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindTransformFeedbackBuffersEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets, PointerDecoder<VkDeviceSize>* pSizes) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginTransformFeedbackEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, HandlePointerDecoder<VkBuffer>* pCounterBuffers, PointerDecoder<VkDeviceSize>* pCounterBufferOffsets) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndTransformFeedbackEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, HandlePointerDecoder<VkBuffer>* pCounterBuffers, PointerDecoder<VkDeviceSize>* pCounterBufferOffsets) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginQueryIndexedEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndQueryIndexedEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query, uint32_t index) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectByteCountEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t instanceCount, uint32_t firstInstance, format::HandleId counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) { }
static VKAPI_ATTR void VKAPI_CALL GetImageViewHandleNVX_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint32_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetImageViewAddressNVX_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId imageView, StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountAMD_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountAMD_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL GetShaderInfoAMD_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, PointerDecoder<size_t>* pInfoSize, PointerDecoder<uint8_t>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CreateStreamDescriptorSurfaceGGP_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>* pExternalImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandleNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId memory, VkExternalMemoryHandleTypeFlagsNV handleType, PointerDecoder<uint64_t, void*>* pHandle) { }
static VKAPI_ATTR void VKAPI_CALL CreateViSurfaceNN_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings) { }
static VKAPI_ATTR void VKAPI_CALL ReleaseDisplayEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display) { }
static VKAPI_ATTR void VKAPI_CALL AcquireXlibDisplayEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint64_t dpy, format::HandleId display) { }
static VKAPI_ATTR void VKAPI_CALL GetRandROutputDisplayEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint64_t dpy, size_t rrOutput, HandlePointerDecoder<VkDisplayKHR>* pDisplay) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL DisplayPowerControlEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId display, StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo) { }
static VKAPI_ATTR void VKAPI_CALL RegisterDeviceEventEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFence>* pFence) { }
static VKAPI_ATTR void VKAPI_CALL RegisterDisplayEventEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId display, StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFence>* pFence) { }
static VKAPI_ATTR void VKAPI_CALL GetSwapchainCounterEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, VkSurfaceCounterFlagBitsEXT counter, PointerDecoder<uint64_t>* pCounterValue) { }
static VKAPI_ATTR void VKAPI_CALL GetRefreshCycleDurationGOOGLE_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPastPresentationTimingGOOGLE_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, PointerDecoder<uint32_t>* pPresentationTimingCount, StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, StructPointerDecoder<Decoded_VkRect2D>* pDiscardRectangles) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 discardRectangleEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleModeEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode) { }
static VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t swapchainCount, HandlePointerDecoder<VkSwapchainKHR>* pSwapchains, StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata) { }
static VKAPI_ATTR void VKAPI_CALL CreateIOSSurfaceMVK_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CreateMacOSSurfaceMVK_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL SetDebugUtilsObjectNameEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo) { }
static VKAPI_ATTR void VKAPI_CALL SetDebugUtilsObjectTagEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo) { }
static VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) { }
static VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue) { }
static VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) { }
static VKAPI_ATTR void VKAPI_CALL CreateDebugUtilsMessengerEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, format::HandleId messenger, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData) { }
static VKAPI_ATTR void VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint64_t buffer, StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo, PointerDecoder<uint64_t, void*>* pBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkSampleCountFlagBits samples, StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateValidationCacheEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache) { }
static VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId validationCache, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL MergeValidationCachesEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId dstCache, uint32_t srcCacheCount, HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches) { }
static VKAPI_ATTR void VKAPI_CALL GetValidationCacheDataEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId validationCache, PointerDecoder<size_t>* pDataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindShadingRateImageNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId imageView, VkImageLayout imageLayout) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportShadingRatePaletteNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoarseSampleOrderNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders) { }
static VKAPI_ATTR void VKAPI_CALL CreateAccelerationStructureNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure) { }
static VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId accelerationStructure, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL BindAccelerationStructureMemoryNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructureNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV>* pInfo, format::HandleId instanceData, VkDeviceSize instanceOffset, VkBool32 update, format::HandleId dst, format::HandleId src, format::HandleId scratch, VkDeviceSize scratchOffset) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId dst, format::HandleId src, VkCopyAccelerationStructureModeKHR mode) { }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, format::HandleId missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, format::HandleId hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, format::HandleId callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) { }
static VKAPI_ATTR void VKAPI_CALL CreateRayTracingPipelinesNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines) { }
static VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupHandlesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupHandlesNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureHandleNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId accelerationStructure, size_t dataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t accelerationStructureCount, HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures, VkQueryType queryType, format::HandleId queryPool, uint32_t firstQuery) { }
static VKAPI_ATTR void VKAPI_CALL CompileDeferredNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t shader) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryHostPointerPropertiesEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, uint64_t pHostPointer, StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlagBits pipelineStage, format::HandleId dstBuffer, VkDeviceSize dstOffset, uint32_t marker) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pTimeDomainCount, PointerDecoder<VkTimeDomainEXT>* pTimeDomains) { }
static VKAPI_ATTR void VKAPI_CALL GetCalibratedTimestampsEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t timestampCount, StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>* pTimestampInfos, PointerDecoder<uint64_t>* pTimestamps, PointerDecoder<uint64_t>* pMaxDeviation) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t taskCount, uint32_t firstTask) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorEnableNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, PointerDecoder<VkBool32>* pExclusiveScissorEnables) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, StructPointerDecoder<Decoded_VkRect2D>* pExclusiveScissors) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCheckpointNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint64_t pCheckpointMarker) { }
static VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, PointerDecoder<uint32_t>* pCheckpointDataCount, StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData) { }
static VKAPI_ATTR void VKAPI_CALL InitializePerformanceApiINTEL_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo) { }
static VKAPI_ATTR void VKAPI_CALL UninitializePerformanceApiINTEL_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceMarkerINTEL_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceStreamMarkerINTEL_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceOverrideINTEL_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo) { }
static VKAPI_ATTR void VKAPI_CALL AcquirePerformanceConfigurationINTEL_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo, HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration) { }
static VKAPI_ATTR void VKAPI_CALL ReleasePerformanceConfigurationINTEL_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId configuration) { }
static VKAPI_ATTR void VKAPI_CALL QueueSetPerformanceConfigurationINTEL_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, format::HandleId configuration) { }
static VKAPI_ATTR void VKAPI_CALL GetPerformanceParameterINTEL_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkPerformanceParameterTypeINTEL parameter, StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue) { }
static VKAPI_ATTR void VKAPI_CALL SetLocalDimmingAMD_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId swapChain, VkBool32 localDimmingEnable) { }
static VKAPI_ATTR void VKAPI_CALL CreateImagePipeSurfaceFUCHSIA_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CreateMetalSurfaceEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddressEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pToolCount, StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pCombinationCount, StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfacePresentModes2EXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, PointerDecoder<uint32_t>* pPresentModeCount, PointerDecoder<VkPresentModeKHR>* pPresentModes) { }
static VKAPI_ATTR void VKAPI_CALL AcquireFullScreenExclusiveModeEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain) { }
static VKAPI_ATTR void VKAPI_CALL ReleaseFullScreenExclusiveModeEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupSurfacePresentModes2EXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes) { }
static VKAPI_ATTR void VKAPI_CALL CreateHeadlessSurfaceEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) { }
static VKAPI_ATTR void VKAPI_CALL ResetQueryPoolEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCullModeFlags cullMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkFrontFace frontFace) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPrimitiveTopology primitiveTopology) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewport>* pViewports) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t scissorCount, StructPointerDecoder<Decoded_VkRect2D>* pScissors) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets, PointerDecoder<VkDeviceSize>* pSizes, PointerDecoder<VkDeviceSize>* pStrides) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthWriteEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCompareOp depthCompareOp) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBoundsTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 stencilTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) { }
static VKAPI_ATTR void VKAPI_CALL ReleaseSwapchainImagesEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetGeneratedCommandsMemoryRequirementsNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL CmdPreprocessGeneratedCommandsNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdExecuteGeneratedCommandsNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 isPreprocessed, StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindPipelineShaderGroupNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId pipeline, uint32_t groupIndex) { }
static VKAPI_ATTR void VKAPI_CALL CreateIndirectCommandsLayoutNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout) { }
static VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId indirectCommandsLayout, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL AcquireDrmDisplayEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, int32_t drmFd, format::HandleId display) { }
static VKAPI_ATTR void VKAPI_CALL GetDrmDisplayEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, int32_t drmFd, uint32_t connectorId, HandlePointerDecoder<VkDisplayKHR>* display) { }
static VKAPI_ATTR void VKAPI_CALL CreatePrivateDataSlotEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPrivateDataSlot>* pPrivateDataSlot) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlotEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId privateDataSlot, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL SetPrivateDataEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, uint64_t data) { }
static VKAPI_ATTR void VKAPI_CALL GetPrivateDataEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, PointerDecoder<uint64_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateEnumNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkFragmentShadingRateNV shadingRate, PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2EXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkImageSubresource2EXT>* pSubresource, StructPointerDecoder<Decoded_VkSubresourceLayout2EXT>* pLayout) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceFaultInfoEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT>* pFaultCounts, StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT>* pFaultInfo) { }
static VKAPI_ATTR void VKAPI_CALL AcquireWinrtDisplayNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display) { }
static VKAPI_ATTR void VKAPI_CALL GetWinrtDisplayNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t deviceRelativeId, HandlePointerDecoder<VkDisplayKHR>* pDisplay) { }
static VKAPI_ATTR void VKAPI_CALL CreateDirectFBSurfaceEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t dfb) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t vertexBindingDescriptionCount, StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryZirconHandleFUCHSIA_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo, PointerDecoder<uint32_t>* pZirconHandle) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryZirconHandlePropertiesFUCHSIA_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, uint32_t zirconHandle, StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA>* pMemoryZirconHandleProperties) { }
static VKAPI_ATTR void VKAPI_CALL ImportSemaphoreZirconHandleFUCHSIA_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreZirconHandleFUCHSIA_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo, PointerDecoder<uint32_t>* pZirconHandle) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindInvocationMaskHUAWEI_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId imageView, VkImageLayout imageLayout) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryRemoteAddressNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo, PointerDecoder<uint64_t, void*>* pAddress) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t patchControlPoints) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 rasterizerDiscardEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBiasEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkLogicOp logicOp) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 primitiveRestartEnable) { }
static VKAPI_ATTR void VKAPI_CALL CreateScreenSurfaceQNX_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceScreenPresentationSupportQNX_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t window) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t attachmentCount, PointerDecoder<VkBool32>* pColorWriteEnables) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMultiEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t drawCount, StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMultiIndexedEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t drawCount, StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, PointerDecoder<int32_t>* pVertexOffset) { }
static VKAPI_ATTR void VKAPI_CALL CreateMicromapEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkMicromapEXT>* pMicromap) { }
static VKAPI_ATTR void VKAPI_CALL DestroyMicromapEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId micromap, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CmdBuildMicromapsEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t infoCount, StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos) { }
static VKAPI_ATTR void VKAPI_CALL BuildMicromapsEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, uint32_t infoCount, StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos) { }
static VKAPI_ATTR void VKAPI_CALL CopyMicromapEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CopyMicromapToMemoryEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CopyMemoryToMicromapEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL WriteMicromapsPropertiesEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t micromapCount, HandlePointerDecoder<VkMicromapEXT>* pMicromaps, VkQueryType queryType, size_t dataSize, PointerDecoder<uint8_t>* pData, size_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapToMemoryEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToMicromapEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteMicromapsPropertiesEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t micromapCount, HandlePointerDecoder<VkMicromapEXT>* pMicromaps, VkQueryType queryType, format::HandleId queryPool, uint32_t firstQuery) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMicromapCompatibilityEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo, PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility) { }
static VKAPI_ATTR void VKAPI_CALL GetMicromapBuildSizesEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkAccelerationStructureBuildTypeKHR buildType, StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pBuildInfo, StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT>* pSizeInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawClusterHUAWEI_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawClusterIndirectHUAWEI_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset) { }
static VKAPI_ATTR void VKAPI_CALL SetDeviceMemoryPriorityEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory, float priority) { }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference, StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping) { }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetHostMappingVALVE_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorSet, PointerDecoder<uint64_t, void*>* ppData) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetTessellationDomainOriginEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkTessellationDomainOrigin domainOrigin) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthClampEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthClampEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPolygonModeEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPolygonMode polygonMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationSamplesEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkSampleCountFlagBits rasterizationSamples) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleMaskEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkSampleCountFlagBits samples, PointerDecoder<VkSampleMask>* pSampleMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToCoverageEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 alphaToCoverageEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToOneEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 alphaToOneEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 logicOpEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, PointerDecoder<VkBool32>* pColorBlendEnables) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEquationEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteMaskEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, PointerDecoder<VkColorComponentFlags>* pColorWriteMasks) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationStreamEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t rasterizationStream) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetConservativeRasterizationModeEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float extraPrimitiveOverestimationSize) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthClipEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 sampleLocationsEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendAdvancedEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetProvokingVertexModeEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkProvokingVertexModeEXT provokingVertexMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineRasterizationModeEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEnableEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 stippledLineEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipNegativeOneToOneEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 negativeOneToOne) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingEnableNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 viewportWScalingEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportSwizzleNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorEnableNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 coverageToColorEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorLocationNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t coverageToColorLocation) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationModeNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCoverageModulationModeNV coverageModulationMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableEnableNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 coverageModulationTableEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t coverageModulationTableCount, PointerDecoder<float>* pCoverageModulationTable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetShadingRateImageEnableNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 shadingRateImageEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRepresentativeFragmentTestEnableNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 representativeFragmentTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageReductionModeNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCoverageReductionModeNV coverageReductionMode) { }
static VKAPI_ATTR void VKAPI_CALL GetShaderModuleIdentifierEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId shaderModule, StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier) { }
static VKAPI_ATTR void VKAPI_CALL GetShaderModuleCreateInfoIdentifierEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV>* pOpticalFlowImageFormatInfo, PointerDecoder<uint32_t>* pFormatCount, StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV>* pImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateOpticalFlowSessionNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession) { }
static VKAPI_ATTR void VKAPI_CALL DestroyOpticalFlowSessionNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId session, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL BindOpticalFlowSessionImageNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId session, VkOpticalFlowSessionBindingPointNV bindingPoint, format::HandleId view, VkImageLayout layout) { }
static VKAPI_ATTR void VKAPI_CALL CmdOpticalFlowExecuteNV_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId session, StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetFramebufferTilePropertiesQCOM_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId framebuffer, PointerDecoder<uint32_t>* pPropertiesCount, StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDynamicRenderingTilePropertiesQCOM_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo, StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateAccelerationStructureKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure) { }
static VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId accelerationStructure, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t infoCount, StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos, StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos) { }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresIndirectKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t infoCount, StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos, PointerDecoder<VkDeviceAddress>* pIndirectDeviceAddresses, PointerDecoder<uint32_t>* pIndirectStrides, PointerDecoder<uint32_t*>* ppMaxPrimitiveCounts) { }
static VKAPI_ATTR void VKAPI_CALL CopyAccelerationStructureToMemoryKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CopyMemoryToAccelerationStructureKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL WriteAccelerationStructuresPropertiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t accelerationStructureCount, HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures, VkQueryType queryType, size_t dataSize, PointerDecoder<uint8_t>* pData, size_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureToMemoryKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToAccelerationStructureKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureDeviceAddressKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t accelerationStructureCount, HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures, VkQueryType queryType, format::HandleId queryPool, uint32_t firstQuery) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceAccelerationStructureCompatibilityKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo, PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility) { }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureBuildSizesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkAccelerationStructureBuildTypeKHR buildType, StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo, PointerDecoder<uint32_t>* pMaxPrimitiveCounts, StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>* pSizeInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) { }
static VKAPI_ATTR void VKAPI_CALL CreateRayTracingPipelinesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines) { }
static VKAPI_ATTR void VKAPI_CALL GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirectKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) { }
static VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupStackSizeKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceSize returnValue, format::HandleId device, format::HandleId pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRayTracingPipelineStackSizeKHR_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t pipelineStackSize) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountEXT_PreCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
// clang-format on

GFXRECON_END_NAMESPACE(noop)

// clang-format off
struct plugin_func_table_pre
{
    PFN_CreateInstance_PreCall CreateInstance_PreCall { noop::CreateInstance_PreCall };
    PFN_DestroyInstance_PreCall DestroyInstance_PreCall { noop::DestroyInstance_PreCall };
    PFN_EnumeratePhysicalDevices_PreCall EnumeratePhysicalDevices_PreCall { noop::EnumeratePhysicalDevices_PreCall };
    PFN_GetPhysicalDeviceFeatures_PreCall GetPhysicalDeviceFeatures_PreCall { noop::GetPhysicalDeviceFeatures_PreCall };
    PFN_GetPhysicalDeviceFormatProperties_PreCall GetPhysicalDeviceFormatProperties_PreCall { noop::GetPhysicalDeviceFormatProperties_PreCall };
    PFN_GetPhysicalDeviceImageFormatProperties_PreCall GetPhysicalDeviceImageFormatProperties_PreCall { noop::GetPhysicalDeviceImageFormatProperties_PreCall };
    PFN_GetPhysicalDeviceProperties_PreCall GetPhysicalDeviceProperties_PreCall { noop::GetPhysicalDeviceProperties_PreCall };
    PFN_GetPhysicalDeviceQueueFamilyProperties_PreCall GetPhysicalDeviceQueueFamilyProperties_PreCall { noop::GetPhysicalDeviceQueueFamilyProperties_PreCall };
    PFN_GetPhysicalDeviceMemoryProperties_PreCall GetPhysicalDeviceMemoryProperties_PreCall { noop::GetPhysicalDeviceMemoryProperties_PreCall };
    PFN_CreateDevice_PreCall CreateDevice_PreCall { noop::CreateDevice_PreCall };
    PFN_DestroyDevice_PreCall DestroyDevice_PreCall { noop::DestroyDevice_PreCall };
    PFN_GetDeviceQueue_PreCall GetDeviceQueue_PreCall { noop::GetDeviceQueue_PreCall };
    PFN_QueueSubmit_PreCall QueueSubmit_PreCall { noop::QueueSubmit_PreCall };
    PFN_QueueWaitIdle_PreCall QueueWaitIdle_PreCall { noop::QueueWaitIdle_PreCall };
    PFN_DeviceWaitIdle_PreCall DeviceWaitIdle_PreCall { noop::DeviceWaitIdle_PreCall };
    PFN_AllocateMemory_PreCall AllocateMemory_PreCall { noop::AllocateMemory_PreCall };
    PFN_FreeMemory_PreCall FreeMemory_PreCall { noop::FreeMemory_PreCall };
    PFN_MapMemory_PreCall MapMemory_PreCall { noop::MapMemory_PreCall };
    PFN_UnmapMemory_PreCall UnmapMemory_PreCall { noop::UnmapMemory_PreCall };
    PFN_FlushMappedMemoryRanges_PreCall FlushMappedMemoryRanges_PreCall { noop::FlushMappedMemoryRanges_PreCall };
    PFN_InvalidateMappedMemoryRanges_PreCall InvalidateMappedMemoryRanges_PreCall { noop::InvalidateMappedMemoryRanges_PreCall };
    PFN_GetDeviceMemoryCommitment_PreCall GetDeviceMemoryCommitment_PreCall { noop::GetDeviceMemoryCommitment_PreCall };
    PFN_BindBufferMemory_PreCall BindBufferMemory_PreCall { noop::BindBufferMemory_PreCall };
    PFN_BindImageMemory_PreCall BindImageMemory_PreCall { noop::BindImageMemory_PreCall };
    PFN_GetBufferMemoryRequirements_PreCall GetBufferMemoryRequirements_PreCall { noop::GetBufferMemoryRequirements_PreCall };
    PFN_GetImageMemoryRequirements_PreCall GetImageMemoryRequirements_PreCall { noop::GetImageMemoryRequirements_PreCall };
    PFN_GetImageSparseMemoryRequirements_PreCall GetImageSparseMemoryRequirements_PreCall { noop::GetImageSparseMemoryRequirements_PreCall };
    PFN_GetPhysicalDeviceSparseImageFormatProperties_PreCall GetPhysicalDeviceSparseImageFormatProperties_PreCall { noop::GetPhysicalDeviceSparseImageFormatProperties_PreCall };
    PFN_QueueBindSparse_PreCall QueueBindSparse_PreCall { noop::QueueBindSparse_PreCall };
    PFN_CreateFence_PreCall CreateFence_PreCall { noop::CreateFence_PreCall };
    PFN_DestroyFence_PreCall DestroyFence_PreCall { noop::DestroyFence_PreCall };
    PFN_ResetFences_PreCall ResetFences_PreCall { noop::ResetFences_PreCall };
    PFN_GetFenceStatus_PreCall GetFenceStatus_PreCall { noop::GetFenceStatus_PreCall };
    PFN_WaitForFences_PreCall WaitForFences_PreCall { noop::WaitForFences_PreCall };
    PFN_CreateSemaphore_PreCall CreateSemaphore_PreCall { noop::CreateSemaphore_PreCall };
    PFN_DestroySemaphore_PreCall DestroySemaphore_PreCall { noop::DestroySemaphore_PreCall };
    PFN_CreateEvent_PreCall CreateEvent_PreCall { noop::CreateEvent_PreCall };
    PFN_DestroyEvent_PreCall DestroyEvent_PreCall { noop::DestroyEvent_PreCall };
    PFN_GetEventStatus_PreCall GetEventStatus_PreCall { noop::GetEventStatus_PreCall };
    PFN_SetEvent_PreCall SetEvent_PreCall { noop::SetEvent_PreCall };
    PFN_ResetEvent_PreCall ResetEvent_PreCall { noop::ResetEvent_PreCall };
    PFN_CreateQueryPool_PreCall CreateQueryPool_PreCall { noop::CreateQueryPool_PreCall };
    PFN_DestroyQueryPool_PreCall DestroyQueryPool_PreCall { noop::DestroyQueryPool_PreCall };
    PFN_GetQueryPoolResults_PreCall GetQueryPoolResults_PreCall { noop::GetQueryPoolResults_PreCall };
    PFN_CreateBuffer_PreCall CreateBuffer_PreCall { noop::CreateBuffer_PreCall };
    PFN_DestroyBuffer_PreCall DestroyBuffer_PreCall { noop::DestroyBuffer_PreCall };
    PFN_CreateBufferView_PreCall CreateBufferView_PreCall { noop::CreateBufferView_PreCall };
    PFN_DestroyBufferView_PreCall DestroyBufferView_PreCall { noop::DestroyBufferView_PreCall };
    PFN_CreateImage_PreCall CreateImage_PreCall { noop::CreateImage_PreCall };
    PFN_DestroyImage_PreCall DestroyImage_PreCall { noop::DestroyImage_PreCall };
    PFN_GetImageSubresourceLayout_PreCall GetImageSubresourceLayout_PreCall { noop::GetImageSubresourceLayout_PreCall };
    PFN_CreateImageView_PreCall CreateImageView_PreCall { noop::CreateImageView_PreCall };
    PFN_DestroyImageView_PreCall DestroyImageView_PreCall { noop::DestroyImageView_PreCall };
    PFN_CreateShaderModule_PreCall CreateShaderModule_PreCall { noop::CreateShaderModule_PreCall };
    PFN_DestroyShaderModule_PreCall DestroyShaderModule_PreCall { noop::DestroyShaderModule_PreCall };
    PFN_CreatePipelineCache_PreCall CreatePipelineCache_PreCall { noop::CreatePipelineCache_PreCall };
    PFN_DestroyPipelineCache_PreCall DestroyPipelineCache_PreCall { noop::DestroyPipelineCache_PreCall };
    PFN_GetPipelineCacheData_PreCall GetPipelineCacheData_PreCall { noop::GetPipelineCacheData_PreCall };
    PFN_MergePipelineCaches_PreCall MergePipelineCaches_PreCall { noop::MergePipelineCaches_PreCall };
    PFN_CreateGraphicsPipelines_PreCall CreateGraphicsPipelines_PreCall { noop::CreateGraphicsPipelines_PreCall };
    PFN_CreateComputePipelines_PreCall CreateComputePipelines_PreCall { noop::CreateComputePipelines_PreCall };
    PFN_DestroyPipeline_PreCall DestroyPipeline_PreCall { noop::DestroyPipeline_PreCall };
    PFN_CreatePipelineLayout_PreCall CreatePipelineLayout_PreCall { noop::CreatePipelineLayout_PreCall };
    PFN_DestroyPipelineLayout_PreCall DestroyPipelineLayout_PreCall { noop::DestroyPipelineLayout_PreCall };
    PFN_CreateSampler_PreCall CreateSampler_PreCall { noop::CreateSampler_PreCall };
    PFN_DestroySampler_PreCall DestroySampler_PreCall { noop::DestroySampler_PreCall };
    PFN_CreateDescriptorSetLayout_PreCall CreateDescriptorSetLayout_PreCall { noop::CreateDescriptorSetLayout_PreCall };
    PFN_DestroyDescriptorSetLayout_PreCall DestroyDescriptorSetLayout_PreCall { noop::DestroyDescriptorSetLayout_PreCall };
    PFN_CreateDescriptorPool_PreCall CreateDescriptorPool_PreCall { noop::CreateDescriptorPool_PreCall };
    PFN_DestroyDescriptorPool_PreCall DestroyDescriptorPool_PreCall { noop::DestroyDescriptorPool_PreCall };
    PFN_ResetDescriptorPool_PreCall ResetDescriptorPool_PreCall { noop::ResetDescriptorPool_PreCall };
    PFN_AllocateDescriptorSets_PreCall AllocateDescriptorSets_PreCall { noop::AllocateDescriptorSets_PreCall };
    PFN_FreeDescriptorSets_PreCall FreeDescriptorSets_PreCall { noop::FreeDescriptorSets_PreCall };
    PFN_UpdateDescriptorSets_PreCall UpdateDescriptorSets_PreCall { noop::UpdateDescriptorSets_PreCall };
    PFN_CreateFramebuffer_PreCall CreateFramebuffer_PreCall { noop::CreateFramebuffer_PreCall };
    PFN_DestroyFramebuffer_PreCall DestroyFramebuffer_PreCall { noop::DestroyFramebuffer_PreCall };
    PFN_CreateRenderPass_PreCall CreateRenderPass_PreCall { noop::CreateRenderPass_PreCall };
    PFN_DestroyRenderPass_PreCall DestroyRenderPass_PreCall { noop::DestroyRenderPass_PreCall };
    PFN_GetRenderAreaGranularity_PreCall GetRenderAreaGranularity_PreCall { noop::GetRenderAreaGranularity_PreCall };
    PFN_CreateCommandPool_PreCall CreateCommandPool_PreCall { noop::CreateCommandPool_PreCall };
    PFN_DestroyCommandPool_PreCall DestroyCommandPool_PreCall { noop::DestroyCommandPool_PreCall };
    PFN_ResetCommandPool_PreCall ResetCommandPool_PreCall { noop::ResetCommandPool_PreCall };
    PFN_AllocateCommandBuffers_PreCall AllocateCommandBuffers_PreCall { noop::AllocateCommandBuffers_PreCall };
    PFN_FreeCommandBuffers_PreCall FreeCommandBuffers_PreCall { noop::FreeCommandBuffers_PreCall };
    PFN_BeginCommandBuffer_PreCall BeginCommandBuffer_PreCall { noop::BeginCommandBuffer_PreCall };
    PFN_EndCommandBuffer_PreCall EndCommandBuffer_PreCall { noop::EndCommandBuffer_PreCall };
    PFN_ResetCommandBuffer_PreCall ResetCommandBuffer_PreCall { noop::ResetCommandBuffer_PreCall };
    PFN_CmdBindPipeline_PreCall CmdBindPipeline_PreCall { noop::CmdBindPipeline_PreCall };
    PFN_CmdSetViewport_PreCall CmdSetViewport_PreCall { noop::CmdSetViewport_PreCall };
    PFN_CmdSetScissor_PreCall CmdSetScissor_PreCall { noop::CmdSetScissor_PreCall };
    PFN_CmdSetLineWidth_PreCall CmdSetLineWidth_PreCall { noop::CmdSetLineWidth_PreCall };
    PFN_CmdSetDepthBias_PreCall CmdSetDepthBias_PreCall { noop::CmdSetDepthBias_PreCall };
    PFN_CmdSetBlendConstants_PreCall CmdSetBlendConstants_PreCall { noop::CmdSetBlendConstants_PreCall };
    PFN_CmdSetDepthBounds_PreCall CmdSetDepthBounds_PreCall { noop::CmdSetDepthBounds_PreCall };
    PFN_CmdSetStencilCompareMask_PreCall CmdSetStencilCompareMask_PreCall { noop::CmdSetStencilCompareMask_PreCall };
    PFN_CmdSetStencilWriteMask_PreCall CmdSetStencilWriteMask_PreCall { noop::CmdSetStencilWriteMask_PreCall };
    PFN_CmdSetStencilReference_PreCall CmdSetStencilReference_PreCall { noop::CmdSetStencilReference_PreCall };
    PFN_CmdBindDescriptorSets_PreCall CmdBindDescriptorSets_PreCall { noop::CmdBindDescriptorSets_PreCall };
    PFN_CmdBindIndexBuffer_PreCall CmdBindIndexBuffer_PreCall { noop::CmdBindIndexBuffer_PreCall };
    PFN_CmdBindVertexBuffers_PreCall CmdBindVertexBuffers_PreCall { noop::CmdBindVertexBuffers_PreCall };
    PFN_CmdDraw_PreCall CmdDraw_PreCall { noop::CmdDraw_PreCall };
    PFN_CmdDrawIndexed_PreCall CmdDrawIndexed_PreCall { noop::CmdDrawIndexed_PreCall };
    PFN_CmdDrawIndirect_PreCall CmdDrawIndirect_PreCall { noop::CmdDrawIndirect_PreCall };
    PFN_CmdDrawIndexedIndirect_PreCall CmdDrawIndexedIndirect_PreCall { noop::CmdDrawIndexedIndirect_PreCall };
    PFN_CmdDispatch_PreCall CmdDispatch_PreCall { noop::CmdDispatch_PreCall };
    PFN_CmdDispatchIndirect_PreCall CmdDispatchIndirect_PreCall { noop::CmdDispatchIndirect_PreCall };
    PFN_CmdCopyBuffer_PreCall CmdCopyBuffer_PreCall { noop::CmdCopyBuffer_PreCall };
    PFN_CmdCopyImage_PreCall CmdCopyImage_PreCall { noop::CmdCopyImage_PreCall };
    PFN_CmdBlitImage_PreCall CmdBlitImage_PreCall { noop::CmdBlitImage_PreCall };
    PFN_CmdCopyBufferToImage_PreCall CmdCopyBufferToImage_PreCall { noop::CmdCopyBufferToImage_PreCall };
    PFN_CmdCopyImageToBuffer_PreCall CmdCopyImageToBuffer_PreCall { noop::CmdCopyImageToBuffer_PreCall };
    PFN_CmdUpdateBuffer_PreCall CmdUpdateBuffer_PreCall { noop::CmdUpdateBuffer_PreCall };
    PFN_CmdFillBuffer_PreCall CmdFillBuffer_PreCall { noop::CmdFillBuffer_PreCall };
    PFN_CmdClearColorImage_PreCall CmdClearColorImage_PreCall { noop::CmdClearColorImage_PreCall };
    PFN_CmdClearDepthStencilImage_PreCall CmdClearDepthStencilImage_PreCall { noop::CmdClearDepthStencilImage_PreCall };
    PFN_CmdClearAttachments_PreCall CmdClearAttachments_PreCall { noop::CmdClearAttachments_PreCall };
    PFN_CmdResolveImage_PreCall CmdResolveImage_PreCall { noop::CmdResolveImage_PreCall };
    PFN_CmdSetEvent_PreCall CmdSetEvent_PreCall { noop::CmdSetEvent_PreCall };
    PFN_CmdResetEvent_PreCall CmdResetEvent_PreCall { noop::CmdResetEvent_PreCall };
    PFN_CmdWaitEvents_PreCall CmdWaitEvents_PreCall { noop::CmdWaitEvents_PreCall };
    PFN_CmdPipelineBarrier_PreCall CmdPipelineBarrier_PreCall { noop::CmdPipelineBarrier_PreCall };
    PFN_CmdBeginQuery_PreCall CmdBeginQuery_PreCall { noop::CmdBeginQuery_PreCall };
    PFN_CmdEndQuery_PreCall CmdEndQuery_PreCall { noop::CmdEndQuery_PreCall };
    PFN_CmdResetQueryPool_PreCall CmdResetQueryPool_PreCall { noop::CmdResetQueryPool_PreCall };
    PFN_CmdWriteTimestamp_PreCall CmdWriteTimestamp_PreCall { noop::CmdWriteTimestamp_PreCall };
    PFN_CmdCopyQueryPoolResults_PreCall CmdCopyQueryPoolResults_PreCall { noop::CmdCopyQueryPoolResults_PreCall };
    PFN_CmdPushConstants_PreCall CmdPushConstants_PreCall { noop::CmdPushConstants_PreCall };
    PFN_CmdBeginRenderPass_PreCall CmdBeginRenderPass_PreCall { noop::CmdBeginRenderPass_PreCall };
    PFN_CmdNextSubpass_PreCall CmdNextSubpass_PreCall { noop::CmdNextSubpass_PreCall };
    PFN_CmdEndRenderPass_PreCall CmdEndRenderPass_PreCall { noop::CmdEndRenderPass_PreCall };
    PFN_CmdExecuteCommands_PreCall CmdExecuteCommands_PreCall { noop::CmdExecuteCommands_PreCall };
    PFN_BindBufferMemory2_PreCall BindBufferMemory2_PreCall { noop::BindBufferMemory2_PreCall };
    PFN_BindImageMemory2_PreCall BindImageMemory2_PreCall { noop::BindImageMemory2_PreCall };
    PFN_GetDeviceGroupPeerMemoryFeatures_PreCall GetDeviceGroupPeerMemoryFeatures_PreCall { noop::GetDeviceGroupPeerMemoryFeatures_PreCall };
    PFN_CmdSetDeviceMask_PreCall CmdSetDeviceMask_PreCall { noop::CmdSetDeviceMask_PreCall };
    PFN_CmdDispatchBase_PreCall CmdDispatchBase_PreCall { noop::CmdDispatchBase_PreCall };
    PFN_EnumeratePhysicalDeviceGroups_PreCall EnumeratePhysicalDeviceGroups_PreCall { noop::EnumeratePhysicalDeviceGroups_PreCall };
    PFN_GetImageMemoryRequirements2_PreCall GetImageMemoryRequirements2_PreCall { noop::GetImageMemoryRequirements2_PreCall };
    PFN_GetBufferMemoryRequirements2_PreCall GetBufferMemoryRequirements2_PreCall { noop::GetBufferMemoryRequirements2_PreCall };
    PFN_GetImageSparseMemoryRequirements2_PreCall GetImageSparseMemoryRequirements2_PreCall { noop::GetImageSparseMemoryRequirements2_PreCall };
    PFN_GetPhysicalDeviceFeatures2_PreCall GetPhysicalDeviceFeatures2_PreCall { noop::GetPhysicalDeviceFeatures2_PreCall };
    PFN_GetPhysicalDeviceProperties2_PreCall GetPhysicalDeviceProperties2_PreCall { noop::GetPhysicalDeviceProperties2_PreCall };
    PFN_GetPhysicalDeviceFormatProperties2_PreCall GetPhysicalDeviceFormatProperties2_PreCall { noop::GetPhysicalDeviceFormatProperties2_PreCall };
    PFN_GetPhysicalDeviceImageFormatProperties2_PreCall GetPhysicalDeviceImageFormatProperties2_PreCall { noop::GetPhysicalDeviceImageFormatProperties2_PreCall };
    PFN_GetPhysicalDeviceQueueFamilyProperties2_PreCall GetPhysicalDeviceQueueFamilyProperties2_PreCall { noop::GetPhysicalDeviceQueueFamilyProperties2_PreCall };
    PFN_GetPhysicalDeviceMemoryProperties2_PreCall GetPhysicalDeviceMemoryProperties2_PreCall { noop::GetPhysicalDeviceMemoryProperties2_PreCall };
    PFN_GetPhysicalDeviceSparseImageFormatProperties2_PreCall GetPhysicalDeviceSparseImageFormatProperties2_PreCall { noop::GetPhysicalDeviceSparseImageFormatProperties2_PreCall };
    PFN_TrimCommandPool_PreCall TrimCommandPool_PreCall { noop::TrimCommandPool_PreCall };
    PFN_GetDeviceQueue2_PreCall GetDeviceQueue2_PreCall { noop::GetDeviceQueue2_PreCall };
    PFN_CreateSamplerYcbcrConversion_PreCall CreateSamplerYcbcrConversion_PreCall { noop::CreateSamplerYcbcrConversion_PreCall };
    PFN_DestroySamplerYcbcrConversion_PreCall DestroySamplerYcbcrConversion_PreCall { noop::DestroySamplerYcbcrConversion_PreCall };
    PFN_CreateDescriptorUpdateTemplate_PreCall CreateDescriptorUpdateTemplate_PreCall { noop::CreateDescriptorUpdateTemplate_PreCall };
    PFN_DestroyDescriptorUpdateTemplate_PreCall DestroyDescriptorUpdateTemplate_PreCall { noop::DestroyDescriptorUpdateTemplate_PreCall };
    PFN_GetPhysicalDeviceExternalBufferProperties_PreCall GetPhysicalDeviceExternalBufferProperties_PreCall { noop::GetPhysicalDeviceExternalBufferProperties_PreCall };
    PFN_GetPhysicalDeviceExternalFenceProperties_PreCall GetPhysicalDeviceExternalFenceProperties_PreCall { noop::GetPhysicalDeviceExternalFenceProperties_PreCall };
    PFN_GetPhysicalDeviceExternalSemaphoreProperties_PreCall GetPhysicalDeviceExternalSemaphoreProperties_PreCall { noop::GetPhysicalDeviceExternalSemaphoreProperties_PreCall };
    PFN_GetDescriptorSetLayoutSupport_PreCall GetDescriptorSetLayoutSupport_PreCall { noop::GetDescriptorSetLayoutSupport_PreCall };
    PFN_CmdDrawIndirectCount_PreCall CmdDrawIndirectCount_PreCall { noop::CmdDrawIndirectCount_PreCall };
    PFN_CmdDrawIndexedIndirectCount_PreCall CmdDrawIndexedIndirectCount_PreCall { noop::CmdDrawIndexedIndirectCount_PreCall };
    PFN_CreateRenderPass2_PreCall CreateRenderPass2_PreCall { noop::CreateRenderPass2_PreCall };
    PFN_CmdBeginRenderPass2_PreCall CmdBeginRenderPass2_PreCall { noop::CmdBeginRenderPass2_PreCall };
    PFN_CmdNextSubpass2_PreCall CmdNextSubpass2_PreCall { noop::CmdNextSubpass2_PreCall };
    PFN_CmdEndRenderPass2_PreCall CmdEndRenderPass2_PreCall { noop::CmdEndRenderPass2_PreCall };
    PFN_ResetQueryPool_PreCall ResetQueryPool_PreCall { noop::ResetQueryPool_PreCall };
    PFN_GetSemaphoreCounterValue_PreCall GetSemaphoreCounterValue_PreCall { noop::GetSemaphoreCounterValue_PreCall };
    PFN_WaitSemaphores_PreCall WaitSemaphores_PreCall { noop::WaitSemaphores_PreCall };
    PFN_SignalSemaphore_PreCall SignalSemaphore_PreCall { noop::SignalSemaphore_PreCall };
    PFN_GetBufferDeviceAddress_PreCall GetBufferDeviceAddress_PreCall { noop::GetBufferDeviceAddress_PreCall };
    PFN_GetBufferOpaqueCaptureAddress_PreCall GetBufferOpaqueCaptureAddress_PreCall { noop::GetBufferOpaqueCaptureAddress_PreCall };
    PFN_GetDeviceMemoryOpaqueCaptureAddress_PreCall GetDeviceMemoryOpaqueCaptureAddress_PreCall { noop::GetDeviceMemoryOpaqueCaptureAddress_PreCall };
    PFN_GetPhysicalDeviceToolProperties_PreCall GetPhysicalDeviceToolProperties_PreCall { noop::GetPhysicalDeviceToolProperties_PreCall };
    PFN_CreatePrivateDataSlot_PreCall CreatePrivateDataSlot_PreCall { noop::CreatePrivateDataSlot_PreCall };
    PFN_DestroyPrivateDataSlot_PreCall DestroyPrivateDataSlot_PreCall { noop::DestroyPrivateDataSlot_PreCall };
    PFN_SetPrivateData_PreCall SetPrivateData_PreCall { noop::SetPrivateData_PreCall };
    PFN_GetPrivateData_PreCall GetPrivateData_PreCall { noop::GetPrivateData_PreCall };
    PFN_CmdSetEvent2_PreCall CmdSetEvent2_PreCall { noop::CmdSetEvent2_PreCall };
    PFN_CmdResetEvent2_PreCall CmdResetEvent2_PreCall { noop::CmdResetEvent2_PreCall };
    PFN_CmdWaitEvents2_PreCall CmdWaitEvents2_PreCall { noop::CmdWaitEvents2_PreCall };
    PFN_CmdPipelineBarrier2_PreCall CmdPipelineBarrier2_PreCall { noop::CmdPipelineBarrier2_PreCall };
    PFN_CmdWriteTimestamp2_PreCall CmdWriteTimestamp2_PreCall { noop::CmdWriteTimestamp2_PreCall };
    PFN_QueueSubmit2_PreCall QueueSubmit2_PreCall { noop::QueueSubmit2_PreCall };
    PFN_CmdCopyBuffer2_PreCall CmdCopyBuffer2_PreCall { noop::CmdCopyBuffer2_PreCall };
    PFN_CmdCopyImage2_PreCall CmdCopyImage2_PreCall { noop::CmdCopyImage2_PreCall };
    PFN_CmdCopyBufferToImage2_PreCall CmdCopyBufferToImage2_PreCall { noop::CmdCopyBufferToImage2_PreCall };
    PFN_CmdCopyImageToBuffer2_PreCall CmdCopyImageToBuffer2_PreCall { noop::CmdCopyImageToBuffer2_PreCall };
    PFN_CmdBlitImage2_PreCall CmdBlitImage2_PreCall { noop::CmdBlitImage2_PreCall };
    PFN_CmdResolveImage2_PreCall CmdResolveImage2_PreCall { noop::CmdResolveImage2_PreCall };
    PFN_CmdBeginRendering_PreCall CmdBeginRendering_PreCall { noop::CmdBeginRendering_PreCall };
    PFN_CmdEndRendering_PreCall CmdEndRendering_PreCall { noop::CmdEndRendering_PreCall };
    PFN_CmdSetCullMode_PreCall CmdSetCullMode_PreCall { noop::CmdSetCullMode_PreCall };
    PFN_CmdSetFrontFace_PreCall CmdSetFrontFace_PreCall { noop::CmdSetFrontFace_PreCall };
    PFN_CmdSetPrimitiveTopology_PreCall CmdSetPrimitiveTopology_PreCall { noop::CmdSetPrimitiveTopology_PreCall };
    PFN_CmdSetViewportWithCount_PreCall CmdSetViewportWithCount_PreCall { noop::CmdSetViewportWithCount_PreCall };
    PFN_CmdSetScissorWithCount_PreCall CmdSetScissorWithCount_PreCall { noop::CmdSetScissorWithCount_PreCall };
    PFN_CmdBindVertexBuffers2_PreCall CmdBindVertexBuffers2_PreCall { noop::CmdBindVertexBuffers2_PreCall };
    PFN_CmdSetDepthTestEnable_PreCall CmdSetDepthTestEnable_PreCall { noop::CmdSetDepthTestEnable_PreCall };
    PFN_CmdSetDepthWriteEnable_PreCall CmdSetDepthWriteEnable_PreCall { noop::CmdSetDepthWriteEnable_PreCall };
    PFN_CmdSetDepthCompareOp_PreCall CmdSetDepthCompareOp_PreCall { noop::CmdSetDepthCompareOp_PreCall };
    PFN_CmdSetDepthBoundsTestEnable_PreCall CmdSetDepthBoundsTestEnable_PreCall { noop::CmdSetDepthBoundsTestEnable_PreCall };
    PFN_CmdSetStencilTestEnable_PreCall CmdSetStencilTestEnable_PreCall { noop::CmdSetStencilTestEnable_PreCall };
    PFN_CmdSetStencilOp_PreCall CmdSetStencilOp_PreCall { noop::CmdSetStencilOp_PreCall };
    PFN_CmdSetRasterizerDiscardEnable_PreCall CmdSetRasterizerDiscardEnable_PreCall { noop::CmdSetRasterizerDiscardEnable_PreCall };
    PFN_CmdSetDepthBiasEnable_PreCall CmdSetDepthBiasEnable_PreCall { noop::CmdSetDepthBiasEnable_PreCall };
    PFN_CmdSetPrimitiveRestartEnable_PreCall CmdSetPrimitiveRestartEnable_PreCall { noop::CmdSetPrimitiveRestartEnable_PreCall };
    PFN_GetDeviceBufferMemoryRequirements_PreCall GetDeviceBufferMemoryRequirements_PreCall { noop::GetDeviceBufferMemoryRequirements_PreCall };
    PFN_GetDeviceImageMemoryRequirements_PreCall GetDeviceImageMemoryRequirements_PreCall { noop::GetDeviceImageMemoryRequirements_PreCall };
    PFN_GetDeviceImageSparseMemoryRequirements_PreCall GetDeviceImageSparseMemoryRequirements_PreCall { noop::GetDeviceImageSparseMemoryRequirements_PreCall };
    PFN_DestroySurfaceKHR_PreCall DestroySurfaceKHR_PreCall { noop::DestroySurfaceKHR_PreCall };
    PFN_GetPhysicalDeviceSurfaceSupportKHR_PreCall GetPhysicalDeviceSurfaceSupportKHR_PreCall { noop::GetPhysicalDeviceSurfaceSupportKHR_PreCall };
    PFN_GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall { noop::GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall };
    PFN_GetPhysicalDeviceSurfaceFormatsKHR_PreCall GetPhysicalDeviceSurfaceFormatsKHR_PreCall { noop::GetPhysicalDeviceSurfaceFormatsKHR_PreCall };
    PFN_GetPhysicalDeviceSurfacePresentModesKHR_PreCall GetPhysicalDeviceSurfacePresentModesKHR_PreCall { noop::GetPhysicalDeviceSurfacePresentModesKHR_PreCall };
    PFN_CreateSwapchainKHR_PreCall CreateSwapchainKHR_PreCall { noop::CreateSwapchainKHR_PreCall };
    PFN_DestroySwapchainKHR_PreCall DestroySwapchainKHR_PreCall { noop::DestroySwapchainKHR_PreCall };
    PFN_GetSwapchainImagesKHR_PreCall GetSwapchainImagesKHR_PreCall { noop::GetSwapchainImagesKHR_PreCall };
    PFN_AcquireNextImageKHR_PreCall AcquireNextImageKHR_PreCall { noop::AcquireNextImageKHR_PreCall };
    PFN_QueuePresentKHR_PreCall QueuePresentKHR_PreCall { noop::QueuePresentKHR_PreCall };
    PFN_GetDeviceGroupPresentCapabilitiesKHR_PreCall GetDeviceGroupPresentCapabilitiesKHR_PreCall { noop::GetDeviceGroupPresentCapabilitiesKHR_PreCall };
    PFN_GetDeviceGroupSurfacePresentModesKHR_PreCall GetDeviceGroupSurfacePresentModesKHR_PreCall { noop::GetDeviceGroupSurfacePresentModesKHR_PreCall };
    PFN_GetPhysicalDevicePresentRectanglesKHR_PreCall GetPhysicalDevicePresentRectanglesKHR_PreCall { noop::GetPhysicalDevicePresentRectanglesKHR_PreCall };
    PFN_AcquireNextImage2KHR_PreCall AcquireNextImage2KHR_PreCall { noop::AcquireNextImage2KHR_PreCall };
    PFN_GetPhysicalDeviceDisplayPropertiesKHR_PreCall GetPhysicalDeviceDisplayPropertiesKHR_PreCall { noop::GetPhysicalDeviceDisplayPropertiesKHR_PreCall };
    PFN_GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall { noop::GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall };
    PFN_GetDisplayPlaneSupportedDisplaysKHR_PreCall GetDisplayPlaneSupportedDisplaysKHR_PreCall { noop::GetDisplayPlaneSupportedDisplaysKHR_PreCall };
    PFN_GetDisplayModePropertiesKHR_PreCall GetDisplayModePropertiesKHR_PreCall { noop::GetDisplayModePropertiesKHR_PreCall };
    PFN_CreateDisplayModeKHR_PreCall CreateDisplayModeKHR_PreCall { noop::CreateDisplayModeKHR_PreCall };
    PFN_GetDisplayPlaneCapabilitiesKHR_PreCall GetDisplayPlaneCapabilitiesKHR_PreCall { noop::GetDisplayPlaneCapabilitiesKHR_PreCall };
    PFN_CreateDisplayPlaneSurfaceKHR_PreCall CreateDisplayPlaneSurfaceKHR_PreCall { noop::CreateDisplayPlaneSurfaceKHR_PreCall };
    PFN_CreateSharedSwapchainsKHR_PreCall CreateSharedSwapchainsKHR_PreCall { noop::CreateSharedSwapchainsKHR_PreCall };
    PFN_CreateXlibSurfaceKHR_PreCall CreateXlibSurfaceKHR_PreCall { noop::CreateXlibSurfaceKHR_PreCall };
    PFN_GetPhysicalDeviceXlibPresentationSupportKHR_PreCall GetPhysicalDeviceXlibPresentationSupportKHR_PreCall { noop::GetPhysicalDeviceXlibPresentationSupportKHR_PreCall };
    PFN_CreateXcbSurfaceKHR_PreCall CreateXcbSurfaceKHR_PreCall { noop::CreateXcbSurfaceKHR_PreCall };
    PFN_GetPhysicalDeviceXcbPresentationSupportKHR_PreCall GetPhysicalDeviceXcbPresentationSupportKHR_PreCall { noop::GetPhysicalDeviceXcbPresentationSupportKHR_PreCall };
    PFN_CreateWaylandSurfaceKHR_PreCall CreateWaylandSurfaceKHR_PreCall { noop::CreateWaylandSurfaceKHR_PreCall };
    PFN_GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall { noop::GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall };
    PFN_CreateAndroidSurfaceKHR_PreCall CreateAndroidSurfaceKHR_PreCall { noop::CreateAndroidSurfaceKHR_PreCall };
    PFN_CreateWin32SurfaceKHR_PreCall CreateWin32SurfaceKHR_PreCall { noop::CreateWin32SurfaceKHR_PreCall };
    PFN_GetPhysicalDeviceWin32PresentationSupportKHR_PreCall GetPhysicalDeviceWin32PresentationSupportKHR_PreCall { noop::GetPhysicalDeviceWin32PresentationSupportKHR_PreCall };
    PFN_GetPhysicalDeviceVideoCapabilitiesKHR_PreCall GetPhysicalDeviceVideoCapabilitiesKHR_PreCall { noop::GetPhysicalDeviceVideoCapabilitiesKHR_PreCall };
    PFN_GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall { noop::GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall };
    PFN_CreateVideoSessionKHR_PreCall CreateVideoSessionKHR_PreCall { noop::CreateVideoSessionKHR_PreCall };
    PFN_DestroyVideoSessionKHR_PreCall DestroyVideoSessionKHR_PreCall { noop::DestroyVideoSessionKHR_PreCall };
    PFN_GetVideoSessionMemoryRequirementsKHR_PreCall GetVideoSessionMemoryRequirementsKHR_PreCall { noop::GetVideoSessionMemoryRequirementsKHR_PreCall };
    PFN_BindVideoSessionMemoryKHR_PreCall BindVideoSessionMemoryKHR_PreCall { noop::BindVideoSessionMemoryKHR_PreCall };
    PFN_CreateVideoSessionParametersKHR_PreCall CreateVideoSessionParametersKHR_PreCall { noop::CreateVideoSessionParametersKHR_PreCall };
    PFN_UpdateVideoSessionParametersKHR_PreCall UpdateVideoSessionParametersKHR_PreCall { noop::UpdateVideoSessionParametersKHR_PreCall };
    PFN_DestroyVideoSessionParametersKHR_PreCall DestroyVideoSessionParametersKHR_PreCall { noop::DestroyVideoSessionParametersKHR_PreCall };
    PFN_CmdBeginVideoCodingKHR_PreCall CmdBeginVideoCodingKHR_PreCall { noop::CmdBeginVideoCodingKHR_PreCall };
    PFN_CmdEndVideoCodingKHR_PreCall CmdEndVideoCodingKHR_PreCall { noop::CmdEndVideoCodingKHR_PreCall };
    PFN_CmdControlVideoCodingKHR_PreCall CmdControlVideoCodingKHR_PreCall { noop::CmdControlVideoCodingKHR_PreCall };
    PFN_CmdDecodeVideoKHR_PreCall CmdDecodeVideoKHR_PreCall { noop::CmdDecodeVideoKHR_PreCall };
    PFN_CmdBeginRenderingKHR_PreCall CmdBeginRenderingKHR_PreCall { noop::CmdBeginRenderingKHR_PreCall };
    PFN_CmdEndRenderingKHR_PreCall CmdEndRenderingKHR_PreCall { noop::CmdEndRenderingKHR_PreCall };
    PFN_GetPhysicalDeviceFeatures2KHR_PreCall GetPhysicalDeviceFeatures2KHR_PreCall { noop::GetPhysicalDeviceFeatures2KHR_PreCall };
    PFN_GetPhysicalDeviceProperties2KHR_PreCall GetPhysicalDeviceProperties2KHR_PreCall { noop::GetPhysicalDeviceProperties2KHR_PreCall };
    PFN_GetPhysicalDeviceFormatProperties2KHR_PreCall GetPhysicalDeviceFormatProperties2KHR_PreCall { noop::GetPhysicalDeviceFormatProperties2KHR_PreCall };
    PFN_GetPhysicalDeviceImageFormatProperties2KHR_PreCall GetPhysicalDeviceImageFormatProperties2KHR_PreCall { noop::GetPhysicalDeviceImageFormatProperties2KHR_PreCall };
    PFN_GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall { noop::GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall };
    PFN_GetPhysicalDeviceMemoryProperties2KHR_PreCall GetPhysicalDeviceMemoryProperties2KHR_PreCall { noop::GetPhysicalDeviceMemoryProperties2KHR_PreCall };
    PFN_GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall { noop::GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall };
    PFN_GetDeviceGroupPeerMemoryFeaturesKHR_PreCall GetDeviceGroupPeerMemoryFeaturesKHR_PreCall { noop::GetDeviceGroupPeerMemoryFeaturesKHR_PreCall };
    PFN_CmdSetDeviceMaskKHR_PreCall CmdSetDeviceMaskKHR_PreCall { noop::CmdSetDeviceMaskKHR_PreCall };
    PFN_CmdDispatchBaseKHR_PreCall CmdDispatchBaseKHR_PreCall { noop::CmdDispatchBaseKHR_PreCall };
    PFN_TrimCommandPoolKHR_PreCall TrimCommandPoolKHR_PreCall { noop::TrimCommandPoolKHR_PreCall };
    PFN_EnumeratePhysicalDeviceGroupsKHR_PreCall EnumeratePhysicalDeviceGroupsKHR_PreCall { noop::EnumeratePhysicalDeviceGroupsKHR_PreCall };
    PFN_GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall { noop::GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall };
    PFN_GetMemoryWin32HandleKHR_PreCall GetMemoryWin32HandleKHR_PreCall { noop::GetMemoryWin32HandleKHR_PreCall };
    PFN_GetMemoryWin32HandlePropertiesKHR_PreCall GetMemoryWin32HandlePropertiesKHR_PreCall { noop::GetMemoryWin32HandlePropertiesKHR_PreCall };
    PFN_GetMemoryFdKHR_PreCall GetMemoryFdKHR_PreCall { noop::GetMemoryFdKHR_PreCall };
    PFN_GetMemoryFdPropertiesKHR_PreCall GetMemoryFdPropertiesKHR_PreCall { noop::GetMemoryFdPropertiesKHR_PreCall };
    PFN_GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall { noop::GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall };
    PFN_ImportSemaphoreWin32HandleKHR_PreCall ImportSemaphoreWin32HandleKHR_PreCall { noop::ImportSemaphoreWin32HandleKHR_PreCall };
    PFN_GetSemaphoreWin32HandleKHR_PreCall GetSemaphoreWin32HandleKHR_PreCall { noop::GetSemaphoreWin32HandleKHR_PreCall };
    PFN_ImportSemaphoreFdKHR_PreCall ImportSemaphoreFdKHR_PreCall { noop::ImportSemaphoreFdKHR_PreCall };
    PFN_GetSemaphoreFdKHR_PreCall GetSemaphoreFdKHR_PreCall { noop::GetSemaphoreFdKHR_PreCall };
    PFN_CmdPushDescriptorSetKHR_PreCall CmdPushDescriptorSetKHR_PreCall { noop::CmdPushDescriptorSetKHR_PreCall };
    PFN_CreateDescriptorUpdateTemplateKHR_PreCall CreateDescriptorUpdateTemplateKHR_PreCall { noop::CreateDescriptorUpdateTemplateKHR_PreCall };
    PFN_DestroyDescriptorUpdateTemplateKHR_PreCall DestroyDescriptorUpdateTemplateKHR_PreCall { noop::DestroyDescriptorUpdateTemplateKHR_PreCall };
    PFN_CreateRenderPass2KHR_PreCall CreateRenderPass2KHR_PreCall { noop::CreateRenderPass2KHR_PreCall };
    PFN_CmdBeginRenderPass2KHR_PreCall CmdBeginRenderPass2KHR_PreCall { noop::CmdBeginRenderPass2KHR_PreCall };
    PFN_CmdNextSubpass2KHR_PreCall CmdNextSubpass2KHR_PreCall { noop::CmdNextSubpass2KHR_PreCall };
    PFN_CmdEndRenderPass2KHR_PreCall CmdEndRenderPass2KHR_PreCall { noop::CmdEndRenderPass2KHR_PreCall };
    PFN_GetSwapchainStatusKHR_PreCall GetSwapchainStatusKHR_PreCall { noop::GetSwapchainStatusKHR_PreCall };
    PFN_GetPhysicalDeviceExternalFencePropertiesKHR_PreCall GetPhysicalDeviceExternalFencePropertiesKHR_PreCall { noop::GetPhysicalDeviceExternalFencePropertiesKHR_PreCall };
    PFN_ImportFenceWin32HandleKHR_PreCall ImportFenceWin32HandleKHR_PreCall { noop::ImportFenceWin32HandleKHR_PreCall };
    PFN_GetFenceWin32HandleKHR_PreCall GetFenceWin32HandleKHR_PreCall { noop::GetFenceWin32HandleKHR_PreCall };
    PFN_ImportFenceFdKHR_PreCall ImportFenceFdKHR_PreCall { noop::ImportFenceFdKHR_PreCall };
    PFN_GetFenceFdKHR_PreCall GetFenceFdKHR_PreCall { noop::GetFenceFdKHR_PreCall };
    PFN_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall { noop::EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall };
    PFN_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall { noop::GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall };
    PFN_AcquireProfilingLockKHR_PreCall AcquireProfilingLockKHR_PreCall { noop::AcquireProfilingLockKHR_PreCall };
    PFN_ReleaseProfilingLockKHR_PreCall ReleaseProfilingLockKHR_PreCall { noop::ReleaseProfilingLockKHR_PreCall };
    PFN_GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall { noop::GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall };
    PFN_GetPhysicalDeviceSurfaceFormats2KHR_PreCall GetPhysicalDeviceSurfaceFormats2KHR_PreCall { noop::GetPhysicalDeviceSurfaceFormats2KHR_PreCall };
    PFN_GetPhysicalDeviceDisplayProperties2KHR_PreCall GetPhysicalDeviceDisplayProperties2KHR_PreCall { noop::GetPhysicalDeviceDisplayProperties2KHR_PreCall };
    PFN_GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall { noop::GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall };
    PFN_GetDisplayModeProperties2KHR_PreCall GetDisplayModeProperties2KHR_PreCall { noop::GetDisplayModeProperties2KHR_PreCall };
    PFN_GetDisplayPlaneCapabilities2KHR_PreCall GetDisplayPlaneCapabilities2KHR_PreCall { noop::GetDisplayPlaneCapabilities2KHR_PreCall };
    PFN_GetImageMemoryRequirements2KHR_PreCall GetImageMemoryRequirements2KHR_PreCall { noop::GetImageMemoryRequirements2KHR_PreCall };
    PFN_GetBufferMemoryRequirements2KHR_PreCall GetBufferMemoryRequirements2KHR_PreCall { noop::GetBufferMemoryRequirements2KHR_PreCall };
    PFN_GetImageSparseMemoryRequirements2KHR_PreCall GetImageSparseMemoryRequirements2KHR_PreCall { noop::GetImageSparseMemoryRequirements2KHR_PreCall };
    PFN_CreateSamplerYcbcrConversionKHR_PreCall CreateSamplerYcbcrConversionKHR_PreCall { noop::CreateSamplerYcbcrConversionKHR_PreCall };
    PFN_DestroySamplerYcbcrConversionKHR_PreCall DestroySamplerYcbcrConversionKHR_PreCall { noop::DestroySamplerYcbcrConversionKHR_PreCall };
    PFN_BindBufferMemory2KHR_PreCall BindBufferMemory2KHR_PreCall { noop::BindBufferMemory2KHR_PreCall };
    PFN_BindImageMemory2KHR_PreCall BindImageMemory2KHR_PreCall { noop::BindImageMemory2KHR_PreCall };
    PFN_GetDescriptorSetLayoutSupportKHR_PreCall GetDescriptorSetLayoutSupportKHR_PreCall { noop::GetDescriptorSetLayoutSupportKHR_PreCall };
    PFN_CmdDrawIndirectCountKHR_PreCall CmdDrawIndirectCountKHR_PreCall { noop::CmdDrawIndirectCountKHR_PreCall };
    PFN_CmdDrawIndexedIndirectCountKHR_PreCall CmdDrawIndexedIndirectCountKHR_PreCall { noop::CmdDrawIndexedIndirectCountKHR_PreCall };
    PFN_GetSemaphoreCounterValueKHR_PreCall GetSemaphoreCounterValueKHR_PreCall { noop::GetSemaphoreCounterValueKHR_PreCall };
    PFN_WaitSemaphoresKHR_PreCall WaitSemaphoresKHR_PreCall { noop::WaitSemaphoresKHR_PreCall };
    PFN_SignalSemaphoreKHR_PreCall SignalSemaphoreKHR_PreCall { noop::SignalSemaphoreKHR_PreCall };
    PFN_GetPhysicalDeviceFragmentShadingRatesKHR_PreCall GetPhysicalDeviceFragmentShadingRatesKHR_PreCall { noop::GetPhysicalDeviceFragmentShadingRatesKHR_PreCall };
    PFN_CmdSetFragmentShadingRateKHR_PreCall CmdSetFragmentShadingRateKHR_PreCall { noop::CmdSetFragmentShadingRateKHR_PreCall };
    PFN_WaitForPresentKHR_PreCall WaitForPresentKHR_PreCall { noop::WaitForPresentKHR_PreCall };
    PFN_GetBufferDeviceAddressKHR_PreCall GetBufferDeviceAddressKHR_PreCall { noop::GetBufferDeviceAddressKHR_PreCall };
    PFN_GetBufferOpaqueCaptureAddressKHR_PreCall GetBufferOpaqueCaptureAddressKHR_PreCall { noop::GetBufferOpaqueCaptureAddressKHR_PreCall };
    PFN_GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall { noop::GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall };
    PFN_CreateDeferredOperationKHR_PreCall CreateDeferredOperationKHR_PreCall { noop::CreateDeferredOperationKHR_PreCall };
    PFN_DestroyDeferredOperationKHR_PreCall DestroyDeferredOperationKHR_PreCall { noop::DestroyDeferredOperationKHR_PreCall };
    PFN_GetDeferredOperationMaxConcurrencyKHR_PreCall GetDeferredOperationMaxConcurrencyKHR_PreCall { noop::GetDeferredOperationMaxConcurrencyKHR_PreCall };
    PFN_GetDeferredOperationResultKHR_PreCall GetDeferredOperationResultKHR_PreCall { noop::GetDeferredOperationResultKHR_PreCall };
    PFN_DeferredOperationJoinKHR_PreCall DeferredOperationJoinKHR_PreCall { noop::DeferredOperationJoinKHR_PreCall };
    PFN_GetPipelineExecutablePropertiesKHR_PreCall GetPipelineExecutablePropertiesKHR_PreCall { noop::GetPipelineExecutablePropertiesKHR_PreCall };
    PFN_GetPipelineExecutableStatisticsKHR_PreCall GetPipelineExecutableStatisticsKHR_PreCall { noop::GetPipelineExecutableStatisticsKHR_PreCall };
    PFN_GetPipelineExecutableInternalRepresentationsKHR_PreCall GetPipelineExecutableInternalRepresentationsKHR_PreCall { noop::GetPipelineExecutableInternalRepresentationsKHR_PreCall };
    PFN_CmdEncodeVideoKHR_PreCall CmdEncodeVideoKHR_PreCall { noop::CmdEncodeVideoKHR_PreCall };
    PFN_CmdSetEvent2KHR_PreCall CmdSetEvent2KHR_PreCall { noop::CmdSetEvent2KHR_PreCall };
    PFN_CmdResetEvent2KHR_PreCall CmdResetEvent2KHR_PreCall { noop::CmdResetEvent2KHR_PreCall };
    PFN_CmdWaitEvents2KHR_PreCall CmdWaitEvents2KHR_PreCall { noop::CmdWaitEvents2KHR_PreCall };
    PFN_CmdPipelineBarrier2KHR_PreCall CmdPipelineBarrier2KHR_PreCall { noop::CmdPipelineBarrier2KHR_PreCall };
    PFN_CmdWriteTimestamp2KHR_PreCall CmdWriteTimestamp2KHR_PreCall { noop::CmdWriteTimestamp2KHR_PreCall };
    PFN_QueueSubmit2KHR_PreCall QueueSubmit2KHR_PreCall { noop::QueueSubmit2KHR_PreCall };
    PFN_CmdWriteBufferMarker2AMD_PreCall CmdWriteBufferMarker2AMD_PreCall { noop::CmdWriteBufferMarker2AMD_PreCall };
    PFN_GetQueueCheckpointData2NV_PreCall GetQueueCheckpointData2NV_PreCall { noop::GetQueueCheckpointData2NV_PreCall };
    PFN_CmdCopyBuffer2KHR_PreCall CmdCopyBuffer2KHR_PreCall { noop::CmdCopyBuffer2KHR_PreCall };
    PFN_CmdCopyImage2KHR_PreCall CmdCopyImage2KHR_PreCall { noop::CmdCopyImage2KHR_PreCall };
    PFN_CmdCopyBufferToImage2KHR_PreCall CmdCopyBufferToImage2KHR_PreCall { noop::CmdCopyBufferToImage2KHR_PreCall };
    PFN_CmdCopyImageToBuffer2KHR_PreCall CmdCopyImageToBuffer2KHR_PreCall { noop::CmdCopyImageToBuffer2KHR_PreCall };
    PFN_CmdBlitImage2KHR_PreCall CmdBlitImage2KHR_PreCall { noop::CmdBlitImage2KHR_PreCall };
    PFN_CmdResolveImage2KHR_PreCall CmdResolveImage2KHR_PreCall { noop::CmdResolveImage2KHR_PreCall };
    PFN_CmdTraceRaysIndirect2KHR_PreCall CmdTraceRaysIndirect2KHR_PreCall { noop::CmdTraceRaysIndirect2KHR_PreCall };
    PFN_GetDeviceBufferMemoryRequirementsKHR_PreCall GetDeviceBufferMemoryRequirementsKHR_PreCall { noop::GetDeviceBufferMemoryRequirementsKHR_PreCall };
    PFN_GetDeviceImageMemoryRequirementsKHR_PreCall GetDeviceImageMemoryRequirementsKHR_PreCall { noop::GetDeviceImageMemoryRequirementsKHR_PreCall };
    PFN_GetDeviceImageSparseMemoryRequirementsKHR_PreCall GetDeviceImageSparseMemoryRequirementsKHR_PreCall { noop::GetDeviceImageSparseMemoryRequirementsKHR_PreCall };
    PFN_CreateDebugReportCallbackEXT_PreCall CreateDebugReportCallbackEXT_PreCall { noop::CreateDebugReportCallbackEXT_PreCall };
    PFN_DestroyDebugReportCallbackEXT_PreCall DestroyDebugReportCallbackEXT_PreCall { noop::DestroyDebugReportCallbackEXT_PreCall };
    PFN_DebugReportMessageEXT_PreCall DebugReportMessageEXT_PreCall { noop::DebugReportMessageEXT_PreCall };
    PFN_DebugMarkerSetObjectTagEXT_PreCall DebugMarkerSetObjectTagEXT_PreCall { noop::DebugMarkerSetObjectTagEXT_PreCall };
    PFN_DebugMarkerSetObjectNameEXT_PreCall DebugMarkerSetObjectNameEXT_PreCall { noop::DebugMarkerSetObjectNameEXT_PreCall };
    PFN_CmdDebugMarkerBeginEXT_PreCall CmdDebugMarkerBeginEXT_PreCall { noop::CmdDebugMarkerBeginEXT_PreCall };
    PFN_CmdDebugMarkerEndEXT_PreCall CmdDebugMarkerEndEXT_PreCall { noop::CmdDebugMarkerEndEXT_PreCall };
    PFN_CmdDebugMarkerInsertEXT_PreCall CmdDebugMarkerInsertEXT_PreCall { noop::CmdDebugMarkerInsertEXT_PreCall };
    PFN_CmdBindTransformFeedbackBuffersEXT_PreCall CmdBindTransformFeedbackBuffersEXT_PreCall { noop::CmdBindTransformFeedbackBuffersEXT_PreCall };
    PFN_CmdBeginTransformFeedbackEXT_PreCall CmdBeginTransformFeedbackEXT_PreCall { noop::CmdBeginTransformFeedbackEXT_PreCall };
    PFN_CmdEndTransformFeedbackEXT_PreCall CmdEndTransformFeedbackEXT_PreCall { noop::CmdEndTransformFeedbackEXT_PreCall };
    PFN_CmdBeginQueryIndexedEXT_PreCall CmdBeginQueryIndexedEXT_PreCall { noop::CmdBeginQueryIndexedEXT_PreCall };
    PFN_CmdEndQueryIndexedEXT_PreCall CmdEndQueryIndexedEXT_PreCall { noop::CmdEndQueryIndexedEXT_PreCall };
    PFN_CmdDrawIndirectByteCountEXT_PreCall CmdDrawIndirectByteCountEXT_PreCall { noop::CmdDrawIndirectByteCountEXT_PreCall };
    PFN_GetImageViewHandleNVX_PreCall GetImageViewHandleNVX_PreCall { noop::GetImageViewHandleNVX_PreCall };
    PFN_GetImageViewAddressNVX_PreCall GetImageViewAddressNVX_PreCall { noop::GetImageViewAddressNVX_PreCall };
    PFN_CmdDrawIndirectCountAMD_PreCall CmdDrawIndirectCountAMD_PreCall { noop::CmdDrawIndirectCountAMD_PreCall };
    PFN_CmdDrawIndexedIndirectCountAMD_PreCall CmdDrawIndexedIndirectCountAMD_PreCall { noop::CmdDrawIndexedIndirectCountAMD_PreCall };
    PFN_GetShaderInfoAMD_PreCall GetShaderInfoAMD_PreCall { noop::GetShaderInfoAMD_PreCall };
    PFN_CreateStreamDescriptorSurfaceGGP_PreCall CreateStreamDescriptorSurfaceGGP_PreCall { noop::CreateStreamDescriptorSurfaceGGP_PreCall };
    PFN_GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall { noop::GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall };
    PFN_GetMemoryWin32HandleNV_PreCall GetMemoryWin32HandleNV_PreCall { noop::GetMemoryWin32HandleNV_PreCall };
    PFN_CreateViSurfaceNN_PreCall CreateViSurfaceNN_PreCall { noop::CreateViSurfaceNN_PreCall };
    PFN_CmdBeginConditionalRenderingEXT_PreCall CmdBeginConditionalRenderingEXT_PreCall { noop::CmdBeginConditionalRenderingEXT_PreCall };
    PFN_CmdEndConditionalRenderingEXT_PreCall CmdEndConditionalRenderingEXT_PreCall { noop::CmdEndConditionalRenderingEXT_PreCall };
    PFN_CmdSetViewportWScalingNV_PreCall CmdSetViewportWScalingNV_PreCall { noop::CmdSetViewportWScalingNV_PreCall };
    PFN_ReleaseDisplayEXT_PreCall ReleaseDisplayEXT_PreCall { noop::ReleaseDisplayEXT_PreCall };
    PFN_AcquireXlibDisplayEXT_PreCall AcquireXlibDisplayEXT_PreCall { noop::AcquireXlibDisplayEXT_PreCall };
    PFN_GetRandROutputDisplayEXT_PreCall GetRandROutputDisplayEXT_PreCall { noop::GetRandROutputDisplayEXT_PreCall };
    PFN_GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall { noop::GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall };
    PFN_DisplayPowerControlEXT_PreCall DisplayPowerControlEXT_PreCall { noop::DisplayPowerControlEXT_PreCall };
    PFN_RegisterDeviceEventEXT_PreCall RegisterDeviceEventEXT_PreCall { noop::RegisterDeviceEventEXT_PreCall };
    PFN_RegisterDisplayEventEXT_PreCall RegisterDisplayEventEXT_PreCall { noop::RegisterDisplayEventEXT_PreCall };
    PFN_GetSwapchainCounterEXT_PreCall GetSwapchainCounterEXT_PreCall { noop::GetSwapchainCounterEXT_PreCall };
    PFN_GetRefreshCycleDurationGOOGLE_PreCall GetRefreshCycleDurationGOOGLE_PreCall { noop::GetRefreshCycleDurationGOOGLE_PreCall };
    PFN_GetPastPresentationTimingGOOGLE_PreCall GetPastPresentationTimingGOOGLE_PreCall { noop::GetPastPresentationTimingGOOGLE_PreCall };
    PFN_CmdSetDiscardRectangleEXT_PreCall CmdSetDiscardRectangleEXT_PreCall { noop::CmdSetDiscardRectangleEXT_PreCall };
    PFN_CmdSetDiscardRectangleEnableEXT_PreCall CmdSetDiscardRectangleEnableEXT_PreCall { noop::CmdSetDiscardRectangleEnableEXT_PreCall };
    PFN_CmdSetDiscardRectangleModeEXT_PreCall CmdSetDiscardRectangleModeEXT_PreCall { noop::CmdSetDiscardRectangleModeEXT_PreCall };
    PFN_SetHdrMetadataEXT_PreCall SetHdrMetadataEXT_PreCall { noop::SetHdrMetadataEXT_PreCall };
    PFN_CreateIOSSurfaceMVK_PreCall CreateIOSSurfaceMVK_PreCall { noop::CreateIOSSurfaceMVK_PreCall };
    PFN_CreateMacOSSurfaceMVK_PreCall CreateMacOSSurfaceMVK_PreCall { noop::CreateMacOSSurfaceMVK_PreCall };
    PFN_SetDebugUtilsObjectNameEXT_PreCall SetDebugUtilsObjectNameEXT_PreCall { noop::SetDebugUtilsObjectNameEXT_PreCall };
    PFN_SetDebugUtilsObjectTagEXT_PreCall SetDebugUtilsObjectTagEXT_PreCall { noop::SetDebugUtilsObjectTagEXT_PreCall };
    PFN_QueueBeginDebugUtilsLabelEXT_PreCall QueueBeginDebugUtilsLabelEXT_PreCall { noop::QueueBeginDebugUtilsLabelEXT_PreCall };
    PFN_QueueEndDebugUtilsLabelEXT_PreCall QueueEndDebugUtilsLabelEXT_PreCall { noop::QueueEndDebugUtilsLabelEXT_PreCall };
    PFN_QueueInsertDebugUtilsLabelEXT_PreCall QueueInsertDebugUtilsLabelEXT_PreCall { noop::QueueInsertDebugUtilsLabelEXT_PreCall };
    PFN_CmdBeginDebugUtilsLabelEXT_PreCall CmdBeginDebugUtilsLabelEXT_PreCall { noop::CmdBeginDebugUtilsLabelEXT_PreCall };
    PFN_CmdEndDebugUtilsLabelEXT_PreCall CmdEndDebugUtilsLabelEXT_PreCall { noop::CmdEndDebugUtilsLabelEXT_PreCall };
    PFN_CmdInsertDebugUtilsLabelEXT_PreCall CmdInsertDebugUtilsLabelEXT_PreCall { noop::CmdInsertDebugUtilsLabelEXT_PreCall };
    PFN_CreateDebugUtilsMessengerEXT_PreCall CreateDebugUtilsMessengerEXT_PreCall { noop::CreateDebugUtilsMessengerEXT_PreCall };
    PFN_DestroyDebugUtilsMessengerEXT_PreCall DestroyDebugUtilsMessengerEXT_PreCall { noop::DestroyDebugUtilsMessengerEXT_PreCall };
    PFN_SubmitDebugUtilsMessageEXT_PreCall SubmitDebugUtilsMessageEXT_PreCall { noop::SubmitDebugUtilsMessageEXT_PreCall };
    PFN_GetAndroidHardwareBufferPropertiesANDROID_PreCall GetAndroidHardwareBufferPropertiesANDROID_PreCall { noop::GetAndroidHardwareBufferPropertiesANDROID_PreCall };
    PFN_GetMemoryAndroidHardwareBufferANDROID_PreCall GetMemoryAndroidHardwareBufferANDROID_PreCall { noop::GetMemoryAndroidHardwareBufferANDROID_PreCall };
    PFN_CmdSetSampleLocationsEXT_PreCall CmdSetSampleLocationsEXT_PreCall { noop::CmdSetSampleLocationsEXT_PreCall };
    PFN_GetPhysicalDeviceMultisamplePropertiesEXT_PreCall GetPhysicalDeviceMultisamplePropertiesEXT_PreCall { noop::GetPhysicalDeviceMultisamplePropertiesEXT_PreCall };
    PFN_GetImageDrmFormatModifierPropertiesEXT_PreCall GetImageDrmFormatModifierPropertiesEXT_PreCall { noop::GetImageDrmFormatModifierPropertiesEXT_PreCall };
    PFN_CreateValidationCacheEXT_PreCall CreateValidationCacheEXT_PreCall { noop::CreateValidationCacheEXT_PreCall };
    PFN_DestroyValidationCacheEXT_PreCall DestroyValidationCacheEXT_PreCall { noop::DestroyValidationCacheEXT_PreCall };
    PFN_MergeValidationCachesEXT_PreCall MergeValidationCachesEXT_PreCall { noop::MergeValidationCachesEXT_PreCall };
    PFN_GetValidationCacheDataEXT_PreCall GetValidationCacheDataEXT_PreCall { noop::GetValidationCacheDataEXT_PreCall };
    PFN_CmdBindShadingRateImageNV_PreCall CmdBindShadingRateImageNV_PreCall { noop::CmdBindShadingRateImageNV_PreCall };
    PFN_CmdSetViewportShadingRatePaletteNV_PreCall CmdSetViewportShadingRatePaletteNV_PreCall { noop::CmdSetViewportShadingRatePaletteNV_PreCall };
    PFN_CmdSetCoarseSampleOrderNV_PreCall CmdSetCoarseSampleOrderNV_PreCall { noop::CmdSetCoarseSampleOrderNV_PreCall };
    PFN_CreateAccelerationStructureNV_PreCall CreateAccelerationStructureNV_PreCall { noop::CreateAccelerationStructureNV_PreCall };
    PFN_DestroyAccelerationStructureNV_PreCall DestroyAccelerationStructureNV_PreCall { noop::DestroyAccelerationStructureNV_PreCall };
    PFN_GetAccelerationStructureMemoryRequirementsNV_PreCall GetAccelerationStructureMemoryRequirementsNV_PreCall { noop::GetAccelerationStructureMemoryRequirementsNV_PreCall };
    PFN_BindAccelerationStructureMemoryNV_PreCall BindAccelerationStructureMemoryNV_PreCall { noop::BindAccelerationStructureMemoryNV_PreCall };
    PFN_CmdBuildAccelerationStructureNV_PreCall CmdBuildAccelerationStructureNV_PreCall { noop::CmdBuildAccelerationStructureNV_PreCall };
    PFN_CmdCopyAccelerationStructureNV_PreCall CmdCopyAccelerationStructureNV_PreCall { noop::CmdCopyAccelerationStructureNV_PreCall };
    PFN_CmdTraceRaysNV_PreCall CmdTraceRaysNV_PreCall { noop::CmdTraceRaysNV_PreCall };
    PFN_CreateRayTracingPipelinesNV_PreCall CreateRayTracingPipelinesNV_PreCall { noop::CreateRayTracingPipelinesNV_PreCall };
    PFN_GetRayTracingShaderGroupHandlesKHR_PreCall GetRayTracingShaderGroupHandlesKHR_PreCall { noop::GetRayTracingShaderGroupHandlesKHR_PreCall };
    PFN_GetRayTracingShaderGroupHandlesNV_PreCall GetRayTracingShaderGroupHandlesNV_PreCall { noop::GetRayTracingShaderGroupHandlesNV_PreCall };
    PFN_GetAccelerationStructureHandleNV_PreCall GetAccelerationStructureHandleNV_PreCall { noop::GetAccelerationStructureHandleNV_PreCall };
    PFN_CmdWriteAccelerationStructuresPropertiesNV_PreCall CmdWriteAccelerationStructuresPropertiesNV_PreCall { noop::CmdWriteAccelerationStructuresPropertiesNV_PreCall };
    PFN_CompileDeferredNV_PreCall CompileDeferredNV_PreCall { noop::CompileDeferredNV_PreCall };
    PFN_GetMemoryHostPointerPropertiesEXT_PreCall GetMemoryHostPointerPropertiesEXT_PreCall { noop::GetMemoryHostPointerPropertiesEXT_PreCall };
    PFN_CmdWriteBufferMarkerAMD_PreCall CmdWriteBufferMarkerAMD_PreCall { noop::CmdWriteBufferMarkerAMD_PreCall };
    PFN_GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall { noop::GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall };
    PFN_GetCalibratedTimestampsEXT_PreCall GetCalibratedTimestampsEXT_PreCall { noop::GetCalibratedTimestampsEXT_PreCall };
    PFN_CmdDrawMeshTasksNV_PreCall CmdDrawMeshTasksNV_PreCall { noop::CmdDrawMeshTasksNV_PreCall };
    PFN_CmdDrawMeshTasksIndirectNV_PreCall CmdDrawMeshTasksIndirectNV_PreCall { noop::CmdDrawMeshTasksIndirectNV_PreCall };
    PFN_CmdDrawMeshTasksIndirectCountNV_PreCall CmdDrawMeshTasksIndirectCountNV_PreCall { noop::CmdDrawMeshTasksIndirectCountNV_PreCall };
    PFN_CmdSetExclusiveScissorEnableNV_PreCall CmdSetExclusiveScissorEnableNV_PreCall { noop::CmdSetExclusiveScissorEnableNV_PreCall };
    PFN_CmdSetExclusiveScissorNV_PreCall CmdSetExclusiveScissorNV_PreCall { noop::CmdSetExclusiveScissorNV_PreCall };
    PFN_CmdSetCheckpointNV_PreCall CmdSetCheckpointNV_PreCall { noop::CmdSetCheckpointNV_PreCall };
    PFN_GetQueueCheckpointDataNV_PreCall GetQueueCheckpointDataNV_PreCall { noop::GetQueueCheckpointDataNV_PreCall };
    PFN_InitializePerformanceApiINTEL_PreCall InitializePerformanceApiINTEL_PreCall { noop::InitializePerformanceApiINTEL_PreCall };
    PFN_UninitializePerformanceApiINTEL_PreCall UninitializePerformanceApiINTEL_PreCall { noop::UninitializePerformanceApiINTEL_PreCall };
    PFN_CmdSetPerformanceMarkerINTEL_PreCall CmdSetPerformanceMarkerINTEL_PreCall { noop::CmdSetPerformanceMarkerINTEL_PreCall };
    PFN_CmdSetPerformanceStreamMarkerINTEL_PreCall CmdSetPerformanceStreamMarkerINTEL_PreCall { noop::CmdSetPerformanceStreamMarkerINTEL_PreCall };
    PFN_CmdSetPerformanceOverrideINTEL_PreCall CmdSetPerformanceOverrideINTEL_PreCall { noop::CmdSetPerformanceOverrideINTEL_PreCall };
    PFN_AcquirePerformanceConfigurationINTEL_PreCall AcquirePerformanceConfigurationINTEL_PreCall { noop::AcquirePerformanceConfigurationINTEL_PreCall };
    PFN_ReleasePerformanceConfigurationINTEL_PreCall ReleasePerformanceConfigurationINTEL_PreCall { noop::ReleasePerformanceConfigurationINTEL_PreCall };
    PFN_QueueSetPerformanceConfigurationINTEL_PreCall QueueSetPerformanceConfigurationINTEL_PreCall { noop::QueueSetPerformanceConfigurationINTEL_PreCall };
    PFN_GetPerformanceParameterINTEL_PreCall GetPerformanceParameterINTEL_PreCall { noop::GetPerformanceParameterINTEL_PreCall };
    PFN_SetLocalDimmingAMD_PreCall SetLocalDimmingAMD_PreCall { noop::SetLocalDimmingAMD_PreCall };
    PFN_CreateImagePipeSurfaceFUCHSIA_PreCall CreateImagePipeSurfaceFUCHSIA_PreCall { noop::CreateImagePipeSurfaceFUCHSIA_PreCall };
    PFN_CreateMetalSurfaceEXT_PreCall CreateMetalSurfaceEXT_PreCall { noop::CreateMetalSurfaceEXT_PreCall };
    PFN_GetBufferDeviceAddressEXT_PreCall GetBufferDeviceAddressEXT_PreCall { noop::GetBufferDeviceAddressEXT_PreCall };
    PFN_GetPhysicalDeviceToolPropertiesEXT_PreCall GetPhysicalDeviceToolPropertiesEXT_PreCall { noop::GetPhysicalDeviceToolPropertiesEXT_PreCall };
    PFN_GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall { noop::GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall };
    PFN_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall { noop::GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall };
    PFN_GetPhysicalDeviceSurfacePresentModes2EXT_PreCall GetPhysicalDeviceSurfacePresentModes2EXT_PreCall { noop::GetPhysicalDeviceSurfacePresentModes2EXT_PreCall };
    PFN_AcquireFullScreenExclusiveModeEXT_PreCall AcquireFullScreenExclusiveModeEXT_PreCall { noop::AcquireFullScreenExclusiveModeEXT_PreCall };
    PFN_ReleaseFullScreenExclusiveModeEXT_PreCall ReleaseFullScreenExclusiveModeEXT_PreCall { noop::ReleaseFullScreenExclusiveModeEXT_PreCall };
    PFN_GetDeviceGroupSurfacePresentModes2EXT_PreCall GetDeviceGroupSurfacePresentModes2EXT_PreCall { noop::GetDeviceGroupSurfacePresentModes2EXT_PreCall };
    PFN_CreateHeadlessSurfaceEXT_PreCall CreateHeadlessSurfaceEXT_PreCall { noop::CreateHeadlessSurfaceEXT_PreCall };
    PFN_CmdSetLineStippleEXT_PreCall CmdSetLineStippleEXT_PreCall { noop::CmdSetLineStippleEXT_PreCall };
    PFN_ResetQueryPoolEXT_PreCall ResetQueryPoolEXT_PreCall { noop::ResetQueryPoolEXT_PreCall };
    PFN_CmdSetCullModeEXT_PreCall CmdSetCullModeEXT_PreCall { noop::CmdSetCullModeEXT_PreCall };
    PFN_CmdSetFrontFaceEXT_PreCall CmdSetFrontFaceEXT_PreCall { noop::CmdSetFrontFaceEXT_PreCall };
    PFN_CmdSetPrimitiveTopologyEXT_PreCall CmdSetPrimitiveTopologyEXT_PreCall { noop::CmdSetPrimitiveTopologyEXT_PreCall };
    PFN_CmdSetViewportWithCountEXT_PreCall CmdSetViewportWithCountEXT_PreCall { noop::CmdSetViewportWithCountEXT_PreCall };
    PFN_CmdSetScissorWithCountEXT_PreCall CmdSetScissorWithCountEXT_PreCall { noop::CmdSetScissorWithCountEXT_PreCall };
    PFN_CmdBindVertexBuffers2EXT_PreCall CmdBindVertexBuffers2EXT_PreCall { noop::CmdBindVertexBuffers2EXT_PreCall };
    PFN_CmdSetDepthTestEnableEXT_PreCall CmdSetDepthTestEnableEXT_PreCall { noop::CmdSetDepthTestEnableEXT_PreCall };
    PFN_CmdSetDepthWriteEnableEXT_PreCall CmdSetDepthWriteEnableEXT_PreCall { noop::CmdSetDepthWriteEnableEXT_PreCall };
    PFN_CmdSetDepthCompareOpEXT_PreCall CmdSetDepthCompareOpEXT_PreCall { noop::CmdSetDepthCompareOpEXT_PreCall };
    PFN_CmdSetDepthBoundsTestEnableEXT_PreCall CmdSetDepthBoundsTestEnableEXT_PreCall { noop::CmdSetDepthBoundsTestEnableEXT_PreCall };
    PFN_CmdSetStencilTestEnableEXT_PreCall CmdSetStencilTestEnableEXT_PreCall { noop::CmdSetStencilTestEnableEXT_PreCall };
    PFN_CmdSetStencilOpEXT_PreCall CmdSetStencilOpEXT_PreCall { noop::CmdSetStencilOpEXT_PreCall };
    PFN_ReleaseSwapchainImagesEXT_PreCall ReleaseSwapchainImagesEXT_PreCall { noop::ReleaseSwapchainImagesEXT_PreCall };
    PFN_GetGeneratedCommandsMemoryRequirementsNV_PreCall GetGeneratedCommandsMemoryRequirementsNV_PreCall { noop::GetGeneratedCommandsMemoryRequirementsNV_PreCall };
    PFN_CmdPreprocessGeneratedCommandsNV_PreCall CmdPreprocessGeneratedCommandsNV_PreCall { noop::CmdPreprocessGeneratedCommandsNV_PreCall };
    PFN_CmdExecuteGeneratedCommandsNV_PreCall CmdExecuteGeneratedCommandsNV_PreCall { noop::CmdExecuteGeneratedCommandsNV_PreCall };
    PFN_CmdBindPipelineShaderGroupNV_PreCall CmdBindPipelineShaderGroupNV_PreCall { noop::CmdBindPipelineShaderGroupNV_PreCall };
    PFN_CreateIndirectCommandsLayoutNV_PreCall CreateIndirectCommandsLayoutNV_PreCall { noop::CreateIndirectCommandsLayoutNV_PreCall };
    PFN_DestroyIndirectCommandsLayoutNV_PreCall DestroyIndirectCommandsLayoutNV_PreCall { noop::DestroyIndirectCommandsLayoutNV_PreCall };
    PFN_AcquireDrmDisplayEXT_PreCall AcquireDrmDisplayEXT_PreCall { noop::AcquireDrmDisplayEXT_PreCall };
    PFN_GetDrmDisplayEXT_PreCall GetDrmDisplayEXT_PreCall { noop::GetDrmDisplayEXT_PreCall };
    PFN_CreatePrivateDataSlotEXT_PreCall CreatePrivateDataSlotEXT_PreCall { noop::CreatePrivateDataSlotEXT_PreCall };
    PFN_DestroyPrivateDataSlotEXT_PreCall DestroyPrivateDataSlotEXT_PreCall { noop::DestroyPrivateDataSlotEXT_PreCall };
    PFN_SetPrivateDataEXT_PreCall SetPrivateDataEXT_PreCall { noop::SetPrivateDataEXT_PreCall };
    PFN_GetPrivateDataEXT_PreCall GetPrivateDataEXT_PreCall { noop::GetPrivateDataEXT_PreCall };
    PFN_CmdSetFragmentShadingRateEnumNV_PreCall CmdSetFragmentShadingRateEnumNV_PreCall { noop::CmdSetFragmentShadingRateEnumNV_PreCall };
    PFN_GetImageSubresourceLayout2EXT_PreCall GetImageSubresourceLayout2EXT_PreCall { noop::GetImageSubresourceLayout2EXT_PreCall };
    PFN_GetDeviceFaultInfoEXT_PreCall GetDeviceFaultInfoEXT_PreCall { noop::GetDeviceFaultInfoEXT_PreCall };
    PFN_AcquireWinrtDisplayNV_PreCall AcquireWinrtDisplayNV_PreCall { noop::AcquireWinrtDisplayNV_PreCall };
    PFN_GetWinrtDisplayNV_PreCall GetWinrtDisplayNV_PreCall { noop::GetWinrtDisplayNV_PreCall };
    PFN_CreateDirectFBSurfaceEXT_PreCall CreateDirectFBSurfaceEXT_PreCall { noop::CreateDirectFBSurfaceEXT_PreCall };
    PFN_GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall { noop::GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall };
    PFN_CmdSetVertexInputEXT_PreCall CmdSetVertexInputEXT_PreCall { noop::CmdSetVertexInputEXT_PreCall };
    PFN_GetMemoryZirconHandleFUCHSIA_PreCall GetMemoryZirconHandleFUCHSIA_PreCall { noop::GetMemoryZirconHandleFUCHSIA_PreCall };
    PFN_GetMemoryZirconHandlePropertiesFUCHSIA_PreCall GetMemoryZirconHandlePropertiesFUCHSIA_PreCall { noop::GetMemoryZirconHandlePropertiesFUCHSIA_PreCall };
    PFN_ImportSemaphoreZirconHandleFUCHSIA_PreCall ImportSemaphoreZirconHandleFUCHSIA_PreCall { noop::ImportSemaphoreZirconHandleFUCHSIA_PreCall };
    PFN_GetSemaphoreZirconHandleFUCHSIA_PreCall GetSemaphoreZirconHandleFUCHSIA_PreCall { noop::GetSemaphoreZirconHandleFUCHSIA_PreCall };
    PFN_CmdBindInvocationMaskHUAWEI_PreCall CmdBindInvocationMaskHUAWEI_PreCall { noop::CmdBindInvocationMaskHUAWEI_PreCall };
    PFN_GetMemoryRemoteAddressNV_PreCall GetMemoryRemoteAddressNV_PreCall { noop::GetMemoryRemoteAddressNV_PreCall };
    PFN_CmdSetPatchControlPointsEXT_PreCall CmdSetPatchControlPointsEXT_PreCall { noop::CmdSetPatchControlPointsEXT_PreCall };
    PFN_CmdSetRasterizerDiscardEnableEXT_PreCall CmdSetRasterizerDiscardEnableEXT_PreCall { noop::CmdSetRasterizerDiscardEnableEXT_PreCall };
    PFN_CmdSetDepthBiasEnableEXT_PreCall CmdSetDepthBiasEnableEXT_PreCall { noop::CmdSetDepthBiasEnableEXT_PreCall };
    PFN_CmdSetLogicOpEXT_PreCall CmdSetLogicOpEXT_PreCall { noop::CmdSetLogicOpEXT_PreCall };
    PFN_CmdSetPrimitiveRestartEnableEXT_PreCall CmdSetPrimitiveRestartEnableEXT_PreCall { noop::CmdSetPrimitiveRestartEnableEXT_PreCall };
    PFN_CreateScreenSurfaceQNX_PreCall CreateScreenSurfaceQNX_PreCall { noop::CreateScreenSurfaceQNX_PreCall };
    PFN_GetPhysicalDeviceScreenPresentationSupportQNX_PreCall GetPhysicalDeviceScreenPresentationSupportQNX_PreCall { noop::GetPhysicalDeviceScreenPresentationSupportQNX_PreCall };
    PFN_CmdSetColorWriteEnableEXT_PreCall CmdSetColorWriteEnableEXT_PreCall { noop::CmdSetColorWriteEnableEXT_PreCall };
    PFN_CmdDrawMultiEXT_PreCall CmdDrawMultiEXT_PreCall { noop::CmdDrawMultiEXT_PreCall };
    PFN_CmdDrawMultiIndexedEXT_PreCall CmdDrawMultiIndexedEXT_PreCall { noop::CmdDrawMultiIndexedEXT_PreCall };
    PFN_CreateMicromapEXT_PreCall CreateMicromapEXT_PreCall { noop::CreateMicromapEXT_PreCall };
    PFN_DestroyMicromapEXT_PreCall DestroyMicromapEXT_PreCall { noop::DestroyMicromapEXT_PreCall };
    PFN_CmdBuildMicromapsEXT_PreCall CmdBuildMicromapsEXT_PreCall { noop::CmdBuildMicromapsEXT_PreCall };
    PFN_BuildMicromapsEXT_PreCall BuildMicromapsEXT_PreCall { noop::BuildMicromapsEXT_PreCall };
    PFN_CopyMicromapEXT_PreCall CopyMicromapEXT_PreCall { noop::CopyMicromapEXT_PreCall };
    PFN_CopyMicromapToMemoryEXT_PreCall CopyMicromapToMemoryEXT_PreCall { noop::CopyMicromapToMemoryEXT_PreCall };
    PFN_CopyMemoryToMicromapEXT_PreCall CopyMemoryToMicromapEXT_PreCall { noop::CopyMemoryToMicromapEXT_PreCall };
    PFN_WriteMicromapsPropertiesEXT_PreCall WriteMicromapsPropertiesEXT_PreCall { noop::WriteMicromapsPropertiesEXT_PreCall };
    PFN_CmdCopyMicromapEXT_PreCall CmdCopyMicromapEXT_PreCall { noop::CmdCopyMicromapEXT_PreCall };
    PFN_CmdCopyMicromapToMemoryEXT_PreCall CmdCopyMicromapToMemoryEXT_PreCall { noop::CmdCopyMicromapToMemoryEXT_PreCall };
    PFN_CmdCopyMemoryToMicromapEXT_PreCall CmdCopyMemoryToMicromapEXT_PreCall { noop::CmdCopyMemoryToMicromapEXT_PreCall };
    PFN_CmdWriteMicromapsPropertiesEXT_PreCall CmdWriteMicromapsPropertiesEXT_PreCall { noop::CmdWriteMicromapsPropertiesEXT_PreCall };
    PFN_GetDeviceMicromapCompatibilityEXT_PreCall GetDeviceMicromapCompatibilityEXT_PreCall { noop::GetDeviceMicromapCompatibilityEXT_PreCall };
    PFN_GetMicromapBuildSizesEXT_PreCall GetMicromapBuildSizesEXT_PreCall { noop::GetMicromapBuildSizesEXT_PreCall };
    PFN_CmdDrawClusterHUAWEI_PreCall CmdDrawClusterHUAWEI_PreCall { noop::CmdDrawClusterHUAWEI_PreCall };
    PFN_CmdDrawClusterIndirectHUAWEI_PreCall CmdDrawClusterIndirectHUAWEI_PreCall { noop::CmdDrawClusterIndirectHUAWEI_PreCall };
    PFN_SetDeviceMemoryPriorityEXT_PreCall SetDeviceMemoryPriorityEXT_PreCall { noop::SetDeviceMemoryPriorityEXT_PreCall };
    PFN_GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall { noop::GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall };
    PFN_GetDescriptorSetHostMappingVALVE_PreCall GetDescriptorSetHostMappingVALVE_PreCall { noop::GetDescriptorSetHostMappingVALVE_PreCall };
    PFN_CmdSetTessellationDomainOriginEXT_PreCall CmdSetTessellationDomainOriginEXT_PreCall { noop::CmdSetTessellationDomainOriginEXT_PreCall };
    PFN_CmdSetDepthClampEnableEXT_PreCall CmdSetDepthClampEnableEXT_PreCall { noop::CmdSetDepthClampEnableEXT_PreCall };
    PFN_CmdSetPolygonModeEXT_PreCall CmdSetPolygonModeEXT_PreCall { noop::CmdSetPolygonModeEXT_PreCall };
    PFN_CmdSetRasterizationSamplesEXT_PreCall CmdSetRasterizationSamplesEXT_PreCall { noop::CmdSetRasterizationSamplesEXT_PreCall };
    PFN_CmdSetSampleMaskEXT_PreCall CmdSetSampleMaskEXT_PreCall { noop::CmdSetSampleMaskEXT_PreCall };
    PFN_CmdSetAlphaToCoverageEnableEXT_PreCall CmdSetAlphaToCoverageEnableEXT_PreCall { noop::CmdSetAlphaToCoverageEnableEXT_PreCall };
    PFN_CmdSetAlphaToOneEnableEXT_PreCall CmdSetAlphaToOneEnableEXT_PreCall { noop::CmdSetAlphaToOneEnableEXT_PreCall };
    PFN_CmdSetLogicOpEnableEXT_PreCall CmdSetLogicOpEnableEXT_PreCall { noop::CmdSetLogicOpEnableEXT_PreCall };
    PFN_CmdSetColorBlendEnableEXT_PreCall CmdSetColorBlendEnableEXT_PreCall { noop::CmdSetColorBlendEnableEXT_PreCall };
    PFN_CmdSetColorBlendEquationEXT_PreCall CmdSetColorBlendEquationEXT_PreCall { noop::CmdSetColorBlendEquationEXT_PreCall };
    PFN_CmdSetColorWriteMaskEXT_PreCall CmdSetColorWriteMaskEXT_PreCall { noop::CmdSetColorWriteMaskEXT_PreCall };
    PFN_CmdSetRasterizationStreamEXT_PreCall CmdSetRasterizationStreamEXT_PreCall { noop::CmdSetRasterizationStreamEXT_PreCall };
    PFN_CmdSetConservativeRasterizationModeEXT_PreCall CmdSetConservativeRasterizationModeEXT_PreCall { noop::CmdSetConservativeRasterizationModeEXT_PreCall };
    PFN_CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall { noop::CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall };
    PFN_CmdSetDepthClipEnableEXT_PreCall CmdSetDepthClipEnableEXT_PreCall { noop::CmdSetDepthClipEnableEXT_PreCall };
    PFN_CmdSetSampleLocationsEnableEXT_PreCall CmdSetSampleLocationsEnableEXT_PreCall { noop::CmdSetSampleLocationsEnableEXT_PreCall };
    PFN_CmdSetColorBlendAdvancedEXT_PreCall CmdSetColorBlendAdvancedEXT_PreCall { noop::CmdSetColorBlendAdvancedEXT_PreCall };
    PFN_CmdSetProvokingVertexModeEXT_PreCall CmdSetProvokingVertexModeEXT_PreCall { noop::CmdSetProvokingVertexModeEXT_PreCall };
    PFN_CmdSetLineRasterizationModeEXT_PreCall CmdSetLineRasterizationModeEXT_PreCall { noop::CmdSetLineRasterizationModeEXT_PreCall };
    PFN_CmdSetLineStippleEnableEXT_PreCall CmdSetLineStippleEnableEXT_PreCall { noop::CmdSetLineStippleEnableEXT_PreCall };
    PFN_CmdSetDepthClipNegativeOneToOneEXT_PreCall CmdSetDepthClipNegativeOneToOneEXT_PreCall { noop::CmdSetDepthClipNegativeOneToOneEXT_PreCall };
    PFN_CmdSetViewportWScalingEnableNV_PreCall CmdSetViewportWScalingEnableNV_PreCall { noop::CmdSetViewportWScalingEnableNV_PreCall };
    PFN_CmdSetViewportSwizzleNV_PreCall CmdSetViewportSwizzleNV_PreCall { noop::CmdSetViewportSwizzleNV_PreCall };
    PFN_CmdSetCoverageToColorEnableNV_PreCall CmdSetCoverageToColorEnableNV_PreCall { noop::CmdSetCoverageToColorEnableNV_PreCall };
    PFN_CmdSetCoverageToColorLocationNV_PreCall CmdSetCoverageToColorLocationNV_PreCall { noop::CmdSetCoverageToColorLocationNV_PreCall };
    PFN_CmdSetCoverageModulationModeNV_PreCall CmdSetCoverageModulationModeNV_PreCall { noop::CmdSetCoverageModulationModeNV_PreCall };
    PFN_CmdSetCoverageModulationTableEnableNV_PreCall CmdSetCoverageModulationTableEnableNV_PreCall { noop::CmdSetCoverageModulationTableEnableNV_PreCall };
    PFN_CmdSetCoverageModulationTableNV_PreCall CmdSetCoverageModulationTableNV_PreCall { noop::CmdSetCoverageModulationTableNV_PreCall };
    PFN_CmdSetShadingRateImageEnableNV_PreCall CmdSetShadingRateImageEnableNV_PreCall { noop::CmdSetShadingRateImageEnableNV_PreCall };
    PFN_CmdSetRepresentativeFragmentTestEnableNV_PreCall CmdSetRepresentativeFragmentTestEnableNV_PreCall { noop::CmdSetRepresentativeFragmentTestEnableNV_PreCall };
    PFN_CmdSetCoverageReductionModeNV_PreCall CmdSetCoverageReductionModeNV_PreCall { noop::CmdSetCoverageReductionModeNV_PreCall };
    PFN_GetShaderModuleIdentifierEXT_PreCall GetShaderModuleIdentifierEXT_PreCall { noop::GetShaderModuleIdentifierEXT_PreCall };
    PFN_GetShaderModuleCreateInfoIdentifierEXT_PreCall GetShaderModuleCreateInfoIdentifierEXT_PreCall { noop::GetShaderModuleCreateInfoIdentifierEXT_PreCall };
    PFN_GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall { noop::GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall };
    PFN_CreateOpticalFlowSessionNV_PreCall CreateOpticalFlowSessionNV_PreCall { noop::CreateOpticalFlowSessionNV_PreCall };
    PFN_DestroyOpticalFlowSessionNV_PreCall DestroyOpticalFlowSessionNV_PreCall { noop::DestroyOpticalFlowSessionNV_PreCall };
    PFN_BindOpticalFlowSessionImageNV_PreCall BindOpticalFlowSessionImageNV_PreCall { noop::BindOpticalFlowSessionImageNV_PreCall };
    PFN_CmdOpticalFlowExecuteNV_PreCall CmdOpticalFlowExecuteNV_PreCall { noop::CmdOpticalFlowExecuteNV_PreCall };
    PFN_GetFramebufferTilePropertiesQCOM_PreCall GetFramebufferTilePropertiesQCOM_PreCall { noop::GetFramebufferTilePropertiesQCOM_PreCall };
    PFN_GetDynamicRenderingTilePropertiesQCOM_PreCall GetDynamicRenderingTilePropertiesQCOM_PreCall { noop::GetDynamicRenderingTilePropertiesQCOM_PreCall };
    PFN_CreateAccelerationStructureKHR_PreCall CreateAccelerationStructureKHR_PreCall { noop::CreateAccelerationStructureKHR_PreCall };
    PFN_DestroyAccelerationStructureKHR_PreCall DestroyAccelerationStructureKHR_PreCall { noop::DestroyAccelerationStructureKHR_PreCall };
    PFN_CmdBuildAccelerationStructuresKHR_PreCall CmdBuildAccelerationStructuresKHR_PreCall { noop::CmdBuildAccelerationStructuresKHR_PreCall };
    PFN_CmdBuildAccelerationStructuresIndirectKHR_PreCall CmdBuildAccelerationStructuresIndirectKHR_PreCall { noop::CmdBuildAccelerationStructuresIndirectKHR_PreCall };
    PFN_CopyAccelerationStructureToMemoryKHR_PreCall CopyAccelerationStructureToMemoryKHR_PreCall { noop::CopyAccelerationStructureToMemoryKHR_PreCall };
    PFN_CopyMemoryToAccelerationStructureKHR_PreCall CopyMemoryToAccelerationStructureKHR_PreCall { noop::CopyMemoryToAccelerationStructureKHR_PreCall };
    PFN_WriteAccelerationStructuresPropertiesKHR_PreCall WriteAccelerationStructuresPropertiesKHR_PreCall { noop::WriteAccelerationStructuresPropertiesKHR_PreCall };
    PFN_CmdCopyAccelerationStructureKHR_PreCall CmdCopyAccelerationStructureKHR_PreCall { noop::CmdCopyAccelerationStructureKHR_PreCall };
    PFN_CmdCopyAccelerationStructureToMemoryKHR_PreCall CmdCopyAccelerationStructureToMemoryKHR_PreCall { noop::CmdCopyAccelerationStructureToMemoryKHR_PreCall };
    PFN_CmdCopyMemoryToAccelerationStructureKHR_PreCall CmdCopyMemoryToAccelerationStructureKHR_PreCall { noop::CmdCopyMemoryToAccelerationStructureKHR_PreCall };
    PFN_GetAccelerationStructureDeviceAddressKHR_PreCall GetAccelerationStructureDeviceAddressKHR_PreCall { noop::GetAccelerationStructureDeviceAddressKHR_PreCall };
    PFN_CmdWriteAccelerationStructuresPropertiesKHR_PreCall CmdWriteAccelerationStructuresPropertiesKHR_PreCall { noop::CmdWriteAccelerationStructuresPropertiesKHR_PreCall };
    PFN_GetDeviceAccelerationStructureCompatibilityKHR_PreCall GetDeviceAccelerationStructureCompatibilityKHR_PreCall { noop::GetDeviceAccelerationStructureCompatibilityKHR_PreCall };
    PFN_GetAccelerationStructureBuildSizesKHR_PreCall GetAccelerationStructureBuildSizesKHR_PreCall { noop::GetAccelerationStructureBuildSizesKHR_PreCall };
    PFN_CmdTraceRaysKHR_PreCall CmdTraceRaysKHR_PreCall { noop::CmdTraceRaysKHR_PreCall };
    PFN_CreateRayTracingPipelinesKHR_PreCall CreateRayTracingPipelinesKHR_PreCall { noop::CreateRayTracingPipelinesKHR_PreCall };
    PFN_GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall { noop::GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall };
    PFN_CmdTraceRaysIndirectKHR_PreCall CmdTraceRaysIndirectKHR_PreCall { noop::CmdTraceRaysIndirectKHR_PreCall };
    PFN_GetRayTracingShaderGroupStackSizeKHR_PreCall GetRayTracingShaderGroupStackSizeKHR_PreCall { noop::GetRayTracingShaderGroupStackSizeKHR_PreCall };
    PFN_CmdSetRayTracingPipelineStackSizeKHR_PreCall CmdSetRayTracingPipelineStackSizeKHR_PreCall { noop::CmdSetRayTracingPipelineStackSizeKHR_PreCall };
    PFN_CmdDrawMeshTasksEXT_PreCall CmdDrawMeshTasksEXT_PreCall { noop::CmdDrawMeshTasksEXT_PreCall };
    PFN_CmdDrawMeshTasksIndirectEXT_PreCall CmdDrawMeshTasksIndirectEXT_PreCall { noop::CmdDrawMeshTasksIndirectEXT_PreCall };
    PFN_CmdDrawMeshTasksIndirectCountEXT_PreCall CmdDrawMeshTasksIndirectCountEXT_PreCall { noop::CmdDrawMeshTasksIndirectCountEXT_PreCall };
};
// clang-format on

template <typename FuncP>
static void LoadPreFunction(util::platform::GetProcAddress_t gpa, util::platform::LibraryHandle handle, const char* name, FuncP* funcp)
{
    FuncP result = reinterpret_cast<FuncP>(gpa(handle, name));
    if (result)
    {
        *funcp = result;
    }
}

// clang-format off
static void LoadPreFunctionTable(util::platform::GetProcAddress_t gpa, util::platform::LibraryHandle handle, plugin_func_table_pre *table)
{
    assert(gpa);
    assert(handle);
    assert(table);

    LoadPreFunction(gpa, handle, "CreateInstance_PreCall", &table->CreateInstance_PreCall);
    LoadPreFunction(gpa, handle, "DestroyInstance_PreCall", &table->DestroyInstance_PreCall);
    LoadPreFunction(gpa, handle, "EnumeratePhysicalDevices_PreCall", &table->EnumeratePhysicalDevices_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceFeatures_PreCall", &table->GetPhysicalDeviceFeatures_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceFormatProperties_PreCall", &table->GetPhysicalDeviceFormatProperties_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceImageFormatProperties_PreCall", &table->GetPhysicalDeviceImageFormatProperties_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceProperties_PreCall", &table->GetPhysicalDeviceProperties_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceQueueFamilyProperties_PreCall", &table->GetPhysicalDeviceQueueFamilyProperties_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceMemoryProperties_PreCall", &table->GetPhysicalDeviceMemoryProperties_PreCall);
    LoadPreFunction(gpa, handle, "CreateDevice_PreCall", &table->CreateDevice_PreCall);
    LoadPreFunction(gpa, handle, "DestroyDevice_PreCall", &table->DestroyDevice_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceQueue_PreCall", &table->GetDeviceQueue_PreCall);
    LoadPreFunction(gpa, handle, "QueueSubmit_PreCall", &table->QueueSubmit_PreCall);
    LoadPreFunction(gpa, handle, "QueueWaitIdle_PreCall", &table->QueueWaitIdle_PreCall);
    LoadPreFunction(gpa, handle, "DeviceWaitIdle_PreCall", &table->DeviceWaitIdle_PreCall);
    LoadPreFunction(gpa, handle, "AllocateMemory_PreCall", &table->AllocateMemory_PreCall);
    LoadPreFunction(gpa, handle, "FreeMemory_PreCall", &table->FreeMemory_PreCall);
    LoadPreFunction(gpa, handle, "MapMemory_PreCall", &table->MapMemory_PreCall);
    LoadPreFunction(gpa, handle, "UnmapMemory_PreCall", &table->UnmapMemory_PreCall);
    LoadPreFunction(gpa, handle, "FlushMappedMemoryRanges_PreCall", &table->FlushMappedMemoryRanges_PreCall);
    LoadPreFunction(gpa, handle, "InvalidateMappedMemoryRanges_PreCall", &table->InvalidateMappedMemoryRanges_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceMemoryCommitment_PreCall", &table->GetDeviceMemoryCommitment_PreCall);
    LoadPreFunction(gpa, handle, "BindBufferMemory_PreCall", &table->BindBufferMemory_PreCall);
    LoadPreFunction(gpa, handle, "BindImageMemory_PreCall", &table->BindImageMemory_PreCall);
    LoadPreFunction(gpa, handle, "GetBufferMemoryRequirements_PreCall", &table->GetBufferMemoryRequirements_PreCall);
    LoadPreFunction(gpa, handle, "GetImageMemoryRequirements_PreCall", &table->GetImageMemoryRequirements_PreCall);
    LoadPreFunction(gpa, handle, "GetImageSparseMemoryRequirements_PreCall", &table->GetImageSparseMemoryRequirements_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceSparseImageFormatProperties_PreCall", &table->GetPhysicalDeviceSparseImageFormatProperties_PreCall);
    LoadPreFunction(gpa, handle, "QueueBindSparse_PreCall", &table->QueueBindSparse_PreCall);
    LoadPreFunction(gpa, handle, "CreateFence_PreCall", &table->CreateFence_PreCall);
    LoadPreFunction(gpa, handle, "DestroyFence_PreCall", &table->DestroyFence_PreCall);
    LoadPreFunction(gpa, handle, "ResetFences_PreCall", &table->ResetFences_PreCall);
    LoadPreFunction(gpa, handle, "GetFenceStatus_PreCall", &table->GetFenceStatus_PreCall);
    LoadPreFunction(gpa, handle, "WaitForFences_PreCall", &table->WaitForFences_PreCall);
    LoadPreFunction(gpa, handle, "CreateSemaphore_PreCall", &table->CreateSemaphore_PreCall);
    LoadPreFunction(gpa, handle, "DestroySemaphore_PreCall", &table->DestroySemaphore_PreCall);
    LoadPreFunction(gpa, handle, "CreateEvent_PreCall", &table->CreateEvent_PreCall);
    LoadPreFunction(gpa, handle, "DestroyEvent_PreCall", &table->DestroyEvent_PreCall);
    LoadPreFunction(gpa, handle, "GetEventStatus_PreCall", &table->GetEventStatus_PreCall);
    LoadPreFunction(gpa, handle, "SetEvent_PreCall", &table->SetEvent_PreCall);
    LoadPreFunction(gpa, handle, "ResetEvent_PreCall", &table->ResetEvent_PreCall);
    LoadPreFunction(gpa, handle, "CreateQueryPool_PreCall", &table->CreateQueryPool_PreCall);
    LoadPreFunction(gpa, handle, "DestroyQueryPool_PreCall", &table->DestroyQueryPool_PreCall);
    LoadPreFunction(gpa, handle, "GetQueryPoolResults_PreCall", &table->GetQueryPoolResults_PreCall);
    LoadPreFunction(gpa, handle, "CreateBuffer_PreCall", &table->CreateBuffer_PreCall);
    LoadPreFunction(gpa, handle, "DestroyBuffer_PreCall", &table->DestroyBuffer_PreCall);
    LoadPreFunction(gpa, handle, "CreateBufferView_PreCall", &table->CreateBufferView_PreCall);
    LoadPreFunction(gpa, handle, "DestroyBufferView_PreCall", &table->DestroyBufferView_PreCall);
    LoadPreFunction(gpa, handle, "CreateImage_PreCall", &table->CreateImage_PreCall);
    LoadPreFunction(gpa, handle, "DestroyImage_PreCall", &table->DestroyImage_PreCall);
    LoadPreFunction(gpa, handle, "GetImageSubresourceLayout_PreCall", &table->GetImageSubresourceLayout_PreCall);
    LoadPreFunction(gpa, handle, "CreateImageView_PreCall", &table->CreateImageView_PreCall);
    LoadPreFunction(gpa, handle, "DestroyImageView_PreCall", &table->DestroyImageView_PreCall);
    LoadPreFunction(gpa, handle, "CreateShaderModule_PreCall", &table->CreateShaderModule_PreCall);
    LoadPreFunction(gpa, handle, "DestroyShaderModule_PreCall", &table->DestroyShaderModule_PreCall);
    LoadPreFunction(gpa, handle, "CreatePipelineCache_PreCall", &table->CreatePipelineCache_PreCall);
    LoadPreFunction(gpa, handle, "DestroyPipelineCache_PreCall", &table->DestroyPipelineCache_PreCall);
    LoadPreFunction(gpa, handle, "GetPipelineCacheData_PreCall", &table->GetPipelineCacheData_PreCall);
    LoadPreFunction(gpa, handle, "MergePipelineCaches_PreCall", &table->MergePipelineCaches_PreCall);
    LoadPreFunction(gpa, handle, "CreateGraphicsPipelines_PreCall", &table->CreateGraphicsPipelines_PreCall);
    LoadPreFunction(gpa, handle, "CreateComputePipelines_PreCall", &table->CreateComputePipelines_PreCall);
    LoadPreFunction(gpa, handle, "DestroyPipeline_PreCall", &table->DestroyPipeline_PreCall);
    LoadPreFunction(gpa, handle, "CreatePipelineLayout_PreCall", &table->CreatePipelineLayout_PreCall);
    LoadPreFunction(gpa, handle, "DestroyPipelineLayout_PreCall", &table->DestroyPipelineLayout_PreCall);
    LoadPreFunction(gpa, handle, "CreateSampler_PreCall", &table->CreateSampler_PreCall);
    LoadPreFunction(gpa, handle, "DestroySampler_PreCall", &table->DestroySampler_PreCall);
    LoadPreFunction(gpa, handle, "CreateDescriptorSetLayout_PreCall", &table->CreateDescriptorSetLayout_PreCall);
    LoadPreFunction(gpa, handle, "DestroyDescriptorSetLayout_PreCall", &table->DestroyDescriptorSetLayout_PreCall);
    LoadPreFunction(gpa, handle, "CreateDescriptorPool_PreCall", &table->CreateDescriptorPool_PreCall);
    LoadPreFunction(gpa, handle, "DestroyDescriptorPool_PreCall", &table->DestroyDescriptorPool_PreCall);
    LoadPreFunction(gpa, handle, "ResetDescriptorPool_PreCall", &table->ResetDescriptorPool_PreCall);
    LoadPreFunction(gpa, handle, "AllocateDescriptorSets_PreCall", &table->AllocateDescriptorSets_PreCall);
    LoadPreFunction(gpa, handle, "FreeDescriptorSets_PreCall", &table->FreeDescriptorSets_PreCall);
    LoadPreFunction(gpa, handle, "UpdateDescriptorSets_PreCall", &table->UpdateDescriptorSets_PreCall);
    LoadPreFunction(gpa, handle, "CreateFramebuffer_PreCall", &table->CreateFramebuffer_PreCall);
    LoadPreFunction(gpa, handle, "DestroyFramebuffer_PreCall", &table->DestroyFramebuffer_PreCall);
    LoadPreFunction(gpa, handle, "CreateRenderPass_PreCall", &table->CreateRenderPass_PreCall);
    LoadPreFunction(gpa, handle, "DestroyRenderPass_PreCall", &table->DestroyRenderPass_PreCall);
    LoadPreFunction(gpa, handle, "GetRenderAreaGranularity_PreCall", &table->GetRenderAreaGranularity_PreCall);
    LoadPreFunction(gpa, handle, "CreateCommandPool_PreCall", &table->CreateCommandPool_PreCall);
    LoadPreFunction(gpa, handle, "DestroyCommandPool_PreCall", &table->DestroyCommandPool_PreCall);
    LoadPreFunction(gpa, handle, "ResetCommandPool_PreCall", &table->ResetCommandPool_PreCall);
    LoadPreFunction(gpa, handle, "AllocateCommandBuffers_PreCall", &table->AllocateCommandBuffers_PreCall);
    LoadPreFunction(gpa, handle, "FreeCommandBuffers_PreCall", &table->FreeCommandBuffers_PreCall);
    LoadPreFunction(gpa, handle, "BeginCommandBuffer_PreCall", &table->BeginCommandBuffer_PreCall);
    LoadPreFunction(gpa, handle, "EndCommandBuffer_PreCall", &table->EndCommandBuffer_PreCall);
    LoadPreFunction(gpa, handle, "ResetCommandBuffer_PreCall", &table->ResetCommandBuffer_PreCall);
    LoadPreFunction(gpa, handle, "CmdBindPipeline_PreCall", &table->CmdBindPipeline_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetViewport_PreCall", &table->CmdSetViewport_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetScissor_PreCall", &table->CmdSetScissor_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetLineWidth_PreCall", &table->CmdSetLineWidth_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthBias_PreCall", &table->CmdSetDepthBias_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetBlendConstants_PreCall", &table->CmdSetBlendConstants_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthBounds_PreCall", &table->CmdSetDepthBounds_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetStencilCompareMask_PreCall", &table->CmdSetStencilCompareMask_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetStencilWriteMask_PreCall", &table->CmdSetStencilWriteMask_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetStencilReference_PreCall", &table->CmdSetStencilReference_PreCall);
    LoadPreFunction(gpa, handle, "CmdBindDescriptorSets_PreCall", &table->CmdBindDescriptorSets_PreCall);
    LoadPreFunction(gpa, handle, "CmdBindIndexBuffer_PreCall", &table->CmdBindIndexBuffer_PreCall);
    LoadPreFunction(gpa, handle, "CmdBindVertexBuffers_PreCall", &table->CmdBindVertexBuffers_PreCall);
    LoadPreFunction(gpa, handle, "CmdDraw_PreCall", &table->CmdDraw_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawIndexed_PreCall", &table->CmdDrawIndexed_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawIndirect_PreCall", &table->CmdDrawIndirect_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawIndexedIndirect_PreCall", &table->CmdDrawIndexedIndirect_PreCall);
    LoadPreFunction(gpa, handle, "CmdDispatch_PreCall", &table->CmdDispatch_PreCall);
    LoadPreFunction(gpa, handle, "CmdDispatchIndirect_PreCall", &table->CmdDispatchIndirect_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyBuffer_PreCall", &table->CmdCopyBuffer_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyImage_PreCall", &table->CmdCopyImage_PreCall);
    LoadPreFunction(gpa, handle, "CmdBlitImage_PreCall", &table->CmdBlitImage_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyBufferToImage_PreCall", &table->CmdCopyBufferToImage_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyImageToBuffer_PreCall", &table->CmdCopyImageToBuffer_PreCall);
    LoadPreFunction(gpa, handle, "CmdUpdateBuffer_PreCall", &table->CmdUpdateBuffer_PreCall);
    LoadPreFunction(gpa, handle, "CmdFillBuffer_PreCall", &table->CmdFillBuffer_PreCall);
    LoadPreFunction(gpa, handle, "CmdClearColorImage_PreCall", &table->CmdClearColorImage_PreCall);
    LoadPreFunction(gpa, handle, "CmdClearDepthStencilImage_PreCall", &table->CmdClearDepthStencilImage_PreCall);
    LoadPreFunction(gpa, handle, "CmdClearAttachments_PreCall", &table->CmdClearAttachments_PreCall);
    LoadPreFunction(gpa, handle, "CmdResolveImage_PreCall", &table->CmdResolveImage_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetEvent_PreCall", &table->CmdSetEvent_PreCall);
    LoadPreFunction(gpa, handle, "CmdResetEvent_PreCall", &table->CmdResetEvent_PreCall);
    LoadPreFunction(gpa, handle, "CmdWaitEvents_PreCall", &table->CmdWaitEvents_PreCall);
    LoadPreFunction(gpa, handle, "CmdPipelineBarrier_PreCall", &table->CmdPipelineBarrier_PreCall);
    LoadPreFunction(gpa, handle, "CmdBeginQuery_PreCall", &table->CmdBeginQuery_PreCall);
    LoadPreFunction(gpa, handle, "CmdEndQuery_PreCall", &table->CmdEndQuery_PreCall);
    LoadPreFunction(gpa, handle, "CmdResetQueryPool_PreCall", &table->CmdResetQueryPool_PreCall);
    LoadPreFunction(gpa, handle, "CmdWriteTimestamp_PreCall", &table->CmdWriteTimestamp_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyQueryPoolResults_PreCall", &table->CmdCopyQueryPoolResults_PreCall);
    LoadPreFunction(gpa, handle, "CmdPushConstants_PreCall", &table->CmdPushConstants_PreCall);
    LoadPreFunction(gpa, handle, "CmdBeginRenderPass_PreCall", &table->CmdBeginRenderPass_PreCall);
    LoadPreFunction(gpa, handle, "CmdNextSubpass_PreCall", &table->CmdNextSubpass_PreCall);
    LoadPreFunction(gpa, handle, "CmdEndRenderPass_PreCall", &table->CmdEndRenderPass_PreCall);
    LoadPreFunction(gpa, handle, "CmdExecuteCommands_PreCall", &table->CmdExecuteCommands_PreCall);
    LoadPreFunction(gpa, handle, "BindBufferMemory2_PreCall", &table->BindBufferMemory2_PreCall);
    LoadPreFunction(gpa, handle, "BindImageMemory2_PreCall", &table->BindImageMemory2_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceGroupPeerMemoryFeatures_PreCall", &table->GetDeviceGroupPeerMemoryFeatures_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDeviceMask_PreCall", &table->CmdSetDeviceMask_PreCall);
    LoadPreFunction(gpa, handle, "CmdDispatchBase_PreCall", &table->CmdDispatchBase_PreCall);
    LoadPreFunction(gpa, handle, "EnumeratePhysicalDeviceGroups_PreCall", &table->EnumeratePhysicalDeviceGroups_PreCall);
    LoadPreFunction(gpa, handle, "GetImageMemoryRequirements2_PreCall", &table->GetImageMemoryRequirements2_PreCall);
    LoadPreFunction(gpa, handle, "GetBufferMemoryRequirements2_PreCall", &table->GetBufferMemoryRequirements2_PreCall);
    LoadPreFunction(gpa, handle, "GetImageSparseMemoryRequirements2_PreCall", &table->GetImageSparseMemoryRequirements2_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceFeatures2_PreCall", &table->GetPhysicalDeviceFeatures2_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceProperties2_PreCall", &table->GetPhysicalDeviceProperties2_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceFormatProperties2_PreCall", &table->GetPhysicalDeviceFormatProperties2_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceImageFormatProperties2_PreCall", &table->GetPhysicalDeviceImageFormatProperties2_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceQueueFamilyProperties2_PreCall", &table->GetPhysicalDeviceQueueFamilyProperties2_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceMemoryProperties2_PreCall", &table->GetPhysicalDeviceMemoryProperties2_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceSparseImageFormatProperties2_PreCall", &table->GetPhysicalDeviceSparseImageFormatProperties2_PreCall);
    LoadPreFunction(gpa, handle, "TrimCommandPool_PreCall", &table->TrimCommandPool_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceQueue2_PreCall", &table->GetDeviceQueue2_PreCall);
    LoadPreFunction(gpa, handle, "CreateSamplerYcbcrConversion_PreCall", &table->CreateSamplerYcbcrConversion_PreCall);
    LoadPreFunction(gpa, handle, "DestroySamplerYcbcrConversion_PreCall", &table->DestroySamplerYcbcrConversion_PreCall);
    LoadPreFunction(gpa, handle, "CreateDescriptorUpdateTemplate_PreCall", &table->CreateDescriptorUpdateTemplate_PreCall);
    LoadPreFunction(gpa, handle, "DestroyDescriptorUpdateTemplate_PreCall", &table->DestroyDescriptorUpdateTemplate_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceExternalBufferProperties_PreCall", &table->GetPhysicalDeviceExternalBufferProperties_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceExternalFenceProperties_PreCall", &table->GetPhysicalDeviceExternalFenceProperties_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceExternalSemaphoreProperties_PreCall", &table->GetPhysicalDeviceExternalSemaphoreProperties_PreCall);
    LoadPreFunction(gpa, handle, "GetDescriptorSetLayoutSupport_PreCall", &table->GetDescriptorSetLayoutSupport_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawIndirectCount_PreCall", &table->CmdDrawIndirectCount_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawIndexedIndirectCount_PreCall", &table->CmdDrawIndexedIndirectCount_PreCall);
    LoadPreFunction(gpa, handle, "CreateRenderPass2_PreCall", &table->CreateRenderPass2_PreCall);
    LoadPreFunction(gpa, handle, "CmdBeginRenderPass2_PreCall", &table->CmdBeginRenderPass2_PreCall);
    LoadPreFunction(gpa, handle, "CmdNextSubpass2_PreCall", &table->CmdNextSubpass2_PreCall);
    LoadPreFunction(gpa, handle, "CmdEndRenderPass2_PreCall", &table->CmdEndRenderPass2_PreCall);
    LoadPreFunction(gpa, handle, "ResetQueryPool_PreCall", &table->ResetQueryPool_PreCall);
    LoadPreFunction(gpa, handle, "GetSemaphoreCounterValue_PreCall", &table->GetSemaphoreCounterValue_PreCall);
    LoadPreFunction(gpa, handle, "WaitSemaphores_PreCall", &table->WaitSemaphores_PreCall);
    LoadPreFunction(gpa, handle, "SignalSemaphore_PreCall", &table->SignalSemaphore_PreCall);
    LoadPreFunction(gpa, handle, "GetBufferDeviceAddress_PreCall", &table->GetBufferDeviceAddress_PreCall);
    LoadPreFunction(gpa, handle, "GetBufferOpaqueCaptureAddress_PreCall", &table->GetBufferOpaqueCaptureAddress_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceMemoryOpaqueCaptureAddress_PreCall", &table->GetDeviceMemoryOpaqueCaptureAddress_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceToolProperties_PreCall", &table->GetPhysicalDeviceToolProperties_PreCall);
    LoadPreFunction(gpa, handle, "CreatePrivateDataSlot_PreCall", &table->CreatePrivateDataSlot_PreCall);
    LoadPreFunction(gpa, handle, "DestroyPrivateDataSlot_PreCall", &table->DestroyPrivateDataSlot_PreCall);
    LoadPreFunction(gpa, handle, "SetPrivateData_PreCall", &table->SetPrivateData_PreCall);
    LoadPreFunction(gpa, handle, "GetPrivateData_PreCall", &table->GetPrivateData_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetEvent2_PreCall", &table->CmdSetEvent2_PreCall);
    LoadPreFunction(gpa, handle, "CmdResetEvent2_PreCall", &table->CmdResetEvent2_PreCall);
    LoadPreFunction(gpa, handle, "CmdWaitEvents2_PreCall", &table->CmdWaitEvents2_PreCall);
    LoadPreFunction(gpa, handle, "CmdPipelineBarrier2_PreCall", &table->CmdPipelineBarrier2_PreCall);
    LoadPreFunction(gpa, handle, "CmdWriteTimestamp2_PreCall", &table->CmdWriteTimestamp2_PreCall);
    LoadPreFunction(gpa, handle, "QueueSubmit2_PreCall", &table->QueueSubmit2_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyBuffer2_PreCall", &table->CmdCopyBuffer2_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyImage2_PreCall", &table->CmdCopyImage2_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyBufferToImage2_PreCall", &table->CmdCopyBufferToImage2_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyImageToBuffer2_PreCall", &table->CmdCopyImageToBuffer2_PreCall);
    LoadPreFunction(gpa, handle, "CmdBlitImage2_PreCall", &table->CmdBlitImage2_PreCall);
    LoadPreFunction(gpa, handle, "CmdResolveImage2_PreCall", &table->CmdResolveImage2_PreCall);
    LoadPreFunction(gpa, handle, "CmdBeginRendering_PreCall", &table->CmdBeginRendering_PreCall);
    LoadPreFunction(gpa, handle, "CmdEndRendering_PreCall", &table->CmdEndRendering_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetCullMode_PreCall", &table->CmdSetCullMode_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetFrontFace_PreCall", &table->CmdSetFrontFace_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetPrimitiveTopology_PreCall", &table->CmdSetPrimitiveTopology_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetViewportWithCount_PreCall", &table->CmdSetViewportWithCount_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetScissorWithCount_PreCall", &table->CmdSetScissorWithCount_PreCall);
    LoadPreFunction(gpa, handle, "CmdBindVertexBuffers2_PreCall", &table->CmdBindVertexBuffers2_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthTestEnable_PreCall", &table->CmdSetDepthTestEnable_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthWriteEnable_PreCall", &table->CmdSetDepthWriteEnable_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthCompareOp_PreCall", &table->CmdSetDepthCompareOp_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthBoundsTestEnable_PreCall", &table->CmdSetDepthBoundsTestEnable_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetStencilTestEnable_PreCall", &table->CmdSetStencilTestEnable_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetStencilOp_PreCall", &table->CmdSetStencilOp_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetRasterizerDiscardEnable_PreCall", &table->CmdSetRasterizerDiscardEnable_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthBiasEnable_PreCall", &table->CmdSetDepthBiasEnable_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetPrimitiveRestartEnable_PreCall", &table->CmdSetPrimitiveRestartEnable_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceBufferMemoryRequirements_PreCall", &table->GetDeviceBufferMemoryRequirements_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceImageMemoryRequirements_PreCall", &table->GetDeviceImageMemoryRequirements_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceImageSparseMemoryRequirements_PreCall", &table->GetDeviceImageSparseMemoryRequirements_PreCall);
    LoadPreFunction(gpa, handle, "DestroySurfaceKHR_PreCall", &table->DestroySurfaceKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceSurfaceSupportKHR_PreCall", &table->GetPhysicalDeviceSurfaceSupportKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall", &table->GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceSurfaceFormatsKHR_PreCall", &table->GetPhysicalDeviceSurfaceFormatsKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceSurfacePresentModesKHR_PreCall", &table->GetPhysicalDeviceSurfacePresentModesKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateSwapchainKHR_PreCall", &table->CreateSwapchainKHR_PreCall);
    LoadPreFunction(gpa, handle, "DestroySwapchainKHR_PreCall", &table->DestroySwapchainKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetSwapchainImagesKHR_PreCall", &table->GetSwapchainImagesKHR_PreCall);
    LoadPreFunction(gpa, handle, "AcquireNextImageKHR_PreCall", &table->AcquireNextImageKHR_PreCall);
    LoadPreFunction(gpa, handle, "QueuePresentKHR_PreCall", &table->QueuePresentKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceGroupPresentCapabilitiesKHR_PreCall", &table->GetDeviceGroupPresentCapabilitiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceGroupSurfacePresentModesKHR_PreCall", &table->GetDeviceGroupSurfacePresentModesKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDevicePresentRectanglesKHR_PreCall", &table->GetPhysicalDevicePresentRectanglesKHR_PreCall);
    LoadPreFunction(gpa, handle, "AcquireNextImage2KHR_PreCall", &table->AcquireNextImage2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceDisplayPropertiesKHR_PreCall", &table->GetPhysicalDeviceDisplayPropertiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall", &table->GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDisplayPlaneSupportedDisplaysKHR_PreCall", &table->GetDisplayPlaneSupportedDisplaysKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDisplayModePropertiesKHR_PreCall", &table->GetDisplayModePropertiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateDisplayModeKHR_PreCall", &table->CreateDisplayModeKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDisplayPlaneCapabilitiesKHR_PreCall", &table->GetDisplayPlaneCapabilitiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateDisplayPlaneSurfaceKHR_PreCall", &table->CreateDisplayPlaneSurfaceKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateSharedSwapchainsKHR_PreCall", &table->CreateSharedSwapchainsKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateXlibSurfaceKHR_PreCall", &table->CreateXlibSurfaceKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceXlibPresentationSupportKHR_PreCall", &table->GetPhysicalDeviceXlibPresentationSupportKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateXcbSurfaceKHR_PreCall", &table->CreateXcbSurfaceKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceXcbPresentationSupportKHR_PreCall", &table->GetPhysicalDeviceXcbPresentationSupportKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateWaylandSurfaceKHR_PreCall", &table->CreateWaylandSurfaceKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall", &table->GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateAndroidSurfaceKHR_PreCall", &table->CreateAndroidSurfaceKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateWin32SurfaceKHR_PreCall", &table->CreateWin32SurfaceKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceWin32PresentationSupportKHR_PreCall", &table->GetPhysicalDeviceWin32PresentationSupportKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceVideoCapabilitiesKHR_PreCall", &table->GetPhysicalDeviceVideoCapabilitiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall", &table->GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateVideoSessionKHR_PreCall", &table->CreateVideoSessionKHR_PreCall);
    LoadPreFunction(gpa, handle, "DestroyVideoSessionKHR_PreCall", &table->DestroyVideoSessionKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetVideoSessionMemoryRequirementsKHR_PreCall", &table->GetVideoSessionMemoryRequirementsKHR_PreCall);
    LoadPreFunction(gpa, handle, "BindVideoSessionMemoryKHR_PreCall", &table->BindVideoSessionMemoryKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateVideoSessionParametersKHR_PreCall", &table->CreateVideoSessionParametersKHR_PreCall);
    LoadPreFunction(gpa, handle, "UpdateVideoSessionParametersKHR_PreCall", &table->UpdateVideoSessionParametersKHR_PreCall);
    LoadPreFunction(gpa, handle, "DestroyVideoSessionParametersKHR_PreCall", &table->DestroyVideoSessionParametersKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdBeginVideoCodingKHR_PreCall", &table->CmdBeginVideoCodingKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdEndVideoCodingKHR_PreCall", &table->CmdEndVideoCodingKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdControlVideoCodingKHR_PreCall", &table->CmdControlVideoCodingKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdDecodeVideoKHR_PreCall", &table->CmdDecodeVideoKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdBeginRenderingKHR_PreCall", &table->CmdBeginRenderingKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdEndRenderingKHR_PreCall", &table->CmdEndRenderingKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceFeatures2KHR_PreCall", &table->GetPhysicalDeviceFeatures2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceProperties2KHR_PreCall", &table->GetPhysicalDeviceProperties2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceFormatProperties2KHR_PreCall", &table->GetPhysicalDeviceFormatProperties2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceImageFormatProperties2KHR_PreCall", &table->GetPhysicalDeviceImageFormatProperties2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall", &table->GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceMemoryProperties2KHR_PreCall", &table->GetPhysicalDeviceMemoryProperties2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall", &table->GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceGroupPeerMemoryFeaturesKHR_PreCall", &table->GetDeviceGroupPeerMemoryFeaturesKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDeviceMaskKHR_PreCall", &table->CmdSetDeviceMaskKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdDispatchBaseKHR_PreCall", &table->CmdDispatchBaseKHR_PreCall);
    LoadPreFunction(gpa, handle, "TrimCommandPoolKHR_PreCall", &table->TrimCommandPoolKHR_PreCall);
    LoadPreFunction(gpa, handle, "EnumeratePhysicalDeviceGroupsKHR_PreCall", &table->EnumeratePhysicalDeviceGroupsKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall", &table->GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetMemoryWin32HandleKHR_PreCall", &table->GetMemoryWin32HandleKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetMemoryWin32HandlePropertiesKHR_PreCall", &table->GetMemoryWin32HandlePropertiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetMemoryFdKHR_PreCall", &table->GetMemoryFdKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetMemoryFdPropertiesKHR_PreCall", &table->GetMemoryFdPropertiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall", &table->GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "ImportSemaphoreWin32HandleKHR_PreCall", &table->ImportSemaphoreWin32HandleKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetSemaphoreWin32HandleKHR_PreCall", &table->GetSemaphoreWin32HandleKHR_PreCall);
    LoadPreFunction(gpa, handle, "ImportSemaphoreFdKHR_PreCall", &table->ImportSemaphoreFdKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetSemaphoreFdKHR_PreCall", &table->GetSemaphoreFdKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdPushDescriptorSetKHR_PreCall", &table->CmdPushDescriptorSetKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateDescriptorUpdateTemplateKHR_PreCall", &table->CreateDescriptorUpdateTemplateKHR_PreCall);
    LoadPreFunction(gpa, handle, "DestroyDescriptorUpdateTemplateKHR_PreCall", &table->DestroyDescriptorUpdateTemplateKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateRenderPass2KHR_PreCall", &table->CreateRenderPass2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdBeginRenderPass2KHR_PreCall", &table->CmdBeginRenderPass2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdNextSubpass2KHR_PreCall", &table->CmdNextSubpass2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdEndRenderPass2KHR_PreCall", &table->CmdEndRenderPass2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetSwapchainStatusKHR_PreCall", &table->GetSwapchainStatusKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceExternalFencePropertiesKHR_PreCall", &table->GetPhysicalDeviceExternalFencePropertiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "ImportFenceWin32HandleKHR_PreCall", &table->ImportFenceWin32HandleKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetFenceWin32HandleKHR_PreCall", &table->GetFenceWin32HandleKHR_PreCall);
    LoadPreFunction(gpa, handle, "ImportFenceFdKHR_PreCall", &table->ImportFenceFdKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetFenceFdKHR_PreCall", &table->GetFenceFdKHR_PreCall);
    LoadPreFunction(gpa, handle, "EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall", &table->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall", &table->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall);
    LoadPreFunction(gpa, handle, "AcquireProfilingLockKHR_PreCall", &table->AcquireProfilingLockKHR_PreCall);
    LoadPreFunction(gpa, handle, "ReleaseProfilingLockKHR_PreCall", &table->ReleaseProfilingLockKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall", &table->GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceSurfaceFormats2KHR_PreCall", &table->GetPhysicalDeviceSurfaceFormats2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceDisplayProperties2KHR_PreCall", &table->GetPhysicalDeviceDisplayProperties2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall", &table->GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDisplayModeProperties2KHR_PreCall", &table->GetDisplayModeProperties2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDisplayPlaneCapabilities2KHR_PreCall", &table->GetDisplayPlaneCapabilities2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetImageMemoryRequirements2KHR_PreCall", &table->GetImageMemoryRequirements2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetBufferMemoryRequirements2KHR_PreCall", &table->GetBufferMemoryRequirements2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetImageSparseMemoryRequirements2KHR_PreCall", &table->GetImageSparseMemoryRequirements2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateSamplerYcbcrConversionKHR_PreCall", &table->CreateSamplerYcbcrConversionKHR_PreCall);
    LoadPreFunction(gpa, handle, "DestroySamplerYcbcrConversionKHR_PreCall", &table->DestroySamplerYcbcrConversionKHR_PreCall);
    LoadPreFunction(gpa, handle, "BindBufferMemory2KHR_PreCall", &table->BindBufferMemory2KHR_PreCall);
    LoadPreFunction(gpa, handle, "BindImageMemory2KHR_PreCall", &table->BindImageMemory2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDescriptorSetLayoutSupportKHR_PreCall", &table->GetDescriptorSetLayoutSupportKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawIndirectCountKHR_PreCall", &table->CmdDrawIndirectCountKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawIndexedIndirectCountKHR_PreCall", &table->CmdDrawIndexedIndirectCountKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetSemaphoreCounterValueKHR_PreCall", &table->GetSemaphoreCounterValueKHR_PreCall);
    LoadPreFunction(gpa, handle, "WaitSemaphoresKHR_PreCall", &table->WaitSemaphoresKHR_PreCall);
    LoadPreFunction(gpa, handle, "SignalSemaphoreKHR_PreCall", &table->SignalSemaphoreKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceFragmentShadingRatesKHR_PreCall", &table->GetPhysicalDeviceFragmentShadingRatesKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetFragmentShadingRateKHR_PreCall", &table->CmdSetFragmentShadingRateKHR_PreCall);
    LoadPreFunction(gpa, handle, "WaitForPresentKHR_PreCall", &table->WaitForPresentKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetBufferDeviceAddressKHR_PreCall", &table->GetBufferDeviceAddressKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetBufferOpaqueCaptureAddressKHR_PreCall", &table->GetBufferOpaqueCaptureAddressKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall", &table->GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateDeferredOperationKHR_PreCall", &table->CreateDeferredOperationKHR_PreCall);
    LoadPreFunction(gpa, handle, "DestroyDeferredOperationKHR_PreCall", &table->DestroyDeferredOperationKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDeferredOperationMaxConcurrencyKHR_PreCall", &table->GetDeferredOperationMaxConcurrencyKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDeferredOperationResultKHR_PreCall", &table->GetDeferredOperationResultKHR_PreCall);
    LoadPreFunction(gpa, handle, "DeferredOperationJoinKHR_PreCall", &table->DeferredOperationJoinKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPipelineExecutablePropertiesKHR_PreCall", &table->GetPipelineExecutablePropertiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPipelineExecutableStatisticsKHR_PreCall", &table->GetPipelineExecutableStatisticsKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetPipelineExecutableInternalRepresentationsKHR_PreCall", &table->GetPipelineExecutableInternalRepresentationsKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdEncodeVideoKHR_PreCall", &table->CmdEncodeVideoKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetEvent2KHR_PreCall", &table->CmdSetEvent2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdResetEvent2KHR_PreCall", &table->CmdResetEvent2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdWaitEvents2KHR_PreCall", &table->CmdWaitEvents2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdPipelineBarrier2KHR_PreCall", &table->CmdPipelineBarrier2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdWriteTimestamp2KHR_PreCall", &table->CmdWriteTimestamp2KHR_PreCall);
    LoadPreFunction(gpa, handle, "QueueSubmit2KHR_PreCall", &table->QueueSubmit2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdWriteBufferMarker2AMD_PreCall", &table->CmdWriteBufferMarker2AMD_PreCall);
    LoadPreFunction(gpa, handle, "GetQueueCheckpointData2NV_PreCall", &table->GetQueueCheckpointData2NV_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyBuffer2KHR_PreCall", &table->CmdCopyBuffer2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyImage2KHR_PreCall", &table->CmdCopyImage2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyBufferToImage2KHR_PreCall", &table->CmdCopyBufferToImage2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyImageToBuffer2KHR_PreCall", &table->CmdCopyImageToBuffer2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdBlitImage2KHR_PreCall", &table->CmdBlitImage2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdResolveImage2KHR_PreCall", &table->CmdResolveImage2KHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdTraceRaysIndirect2KHR_PreCall", &table->CmdTraceRaysIndirect2KHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceBufferMemoryRequirementsKHR_PreCall", &table->GetDeviceBufferMemoryRequirementsKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceImageMemoryRequirementsKHR_PreCall", &table->GetDeviceImageMemoryRequirementsKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceImageSparseMemoryRequirementsKHR_PreCall", &table->GetDeviceImageSparseMemoryRequirementsKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateDebugReportCallbackEXT_PreCall", &table->CreateDebugReportCallbackEXT_PreCall);
    LoadPreFunction(gpa, handle, "DestroyDebugReportCallbackEXT_PreCall", &table->DestroyDebugReportCallbackEXT_PreCall);
    LoadPreFunction(gpa, handle, "DebugReportMessageEXT_PreCall", &table->DebugReportMessageEXT_PreCall);
    LoadPreFunction(gpa, handle, "DebugMarkerSetObjectTagEXT_PreCall", &table->DebugMarkerSetObjectTagEXT_PreCall);
    LoadPreFunction(gpa, handle, "DebugMarkerSetObjectNameEXT_PreCall", &table->DebugMarkerSetObjectNameEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdDebugMarkerBeginEXT_PreCall", &table->CmdDebugMarkerBeginEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdDebugMarkerEndEXT_PreCall", &table->CmdDebugMarkerEndEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdDebugMarkerInsertEXT_PreCall", &table->CmdDebugMarkerInsertEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdBindTransformFeedbackBuffersEXT_PreCall", &table->CmdBindTransformFeedbackBuffersEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdBeginTransformFeedbackEXT_PreCall", &table->CmdBeginTransformFeedbackEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdEndTransformFeedbackEXT_PreCall", &table->CmdEndTransformFeedbackEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdBeginQueryIndexedEXT_PreCall", &table->CmdBeginQueryIndexedEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdEndQueryIndexedEXT_PreCall", &table->CmdEndQueryIndexedEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawIndirectByteCountEXT_PreCall", &table->CmdDrawIndirectByteCountEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetImageViewHandleNVX_PreCall", &table->GetImageViewHandleNVX_PreCall);
    LoadPreFunction(gpa, handle, "GetImageViewAddressNVX_PreCall", &table->GetImageViewAddressNVX_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawIndirectCountAMD_PreCall", &table->CmdDrawIndirectCountAMD_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawIndexedIndirectCountAMD_PreCall", &table->CmdDrawIndexedIndirectCountAMD_PreCall);
    LoadPreFunction(gpa, handle, "GetShaderInfoAMD_PreCall", &table->GetShaderInfoAMD_PreCall);
    LoadPreFunction(gpa, handle, "CreateStreamDescriptorSurfaceGGP_PreCall", &table->CreateStreamDescriptorSurfaceGGP_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall", &table->GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall);
    LoadPreFunction(gpa, handle, "GetMemoryWin32HandleNV_PreCall", &table->GetMemoryWin32HandleNV_PreCall);
    LoadPreFunction(gpa, handle, "CreateViSurfaceNN_PreCall", &table->CreateViSurfaceNN_PreCall);
    LoadPreFunction(gpa, handle, "CmdBeginConditionalRenderingEXT_PreCall", &table->CmdBeginConditionalRenderingEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdEndConditionalRenderingEXT_PreCall", &table->CmdEndConditionalRenderingEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetViewportWScalingNV_PreCall", &table->CmdSetViewportWScalingNV_PreCall);
    LoadPreFunction(gpa, handle, "ReleaseDisplayEXT_PreCall", &table->ReleaseDisplayEXT_PreCall);
    LoadPreFunction(gpa, handle, "AcquireXlibDisplayEXT_PreCall", &table->AcquireXlibDisplayEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetRandROutputDisplayEXT_PreCall", &table->GetRandROutputDisplayEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall", &table->GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall);
    LoadPreFunction(gpa, handle, "DisplayPowerControlEXT_PreCall", &table->DisplayPowerControlEXT_PreCall);
    LoadPreFunction(gpa, handle, "RegisterDeviceEventEXT_PreCall", &table->RegisterDeviceEventEXT_PreCall);
    LoadPreFunction(gpa, handle, "RegisterDisplayEventEXT_PreCall", &table->RegisterDisplayEventEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetSwapchainCounterEXT_PreCall", &table->GetSwapchainCounterEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetRefreshCycleDurationGOOGLE_PreCall", &table->GetRefreshCycleDurationGOOGLE_PreCall);
    LoadPreFunction(gpa, handle, "GetPastPresentationTimingGOOGLE_PreCall", &table->GetPastPresentationTimingGOOGLE_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDiscardRectangleEXT_PreCall", &table->CmdSetDiscardRectangleEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDiscardRectangleEnableEXT_PreCall", &table->CmdSetDiscardRectangleEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDiscardRectangleModeEXT_PreCall", &table->CmdSetDiscardRectangleModeEXT_PreCall);
    LoadPreFunction(gpa, handle, "SetHdrMetadataEXT_PreCall", &table->SetHdrMetadataEXT_PreCall);
    LoadPreFunction(gpa, handle, "CreateIOSSurfaceMVK_PreCall", &table->CreateIOSSurfaceMVK_PreCall);
    LoadPreFunction(gpa, handle, "CreateMacOSSurfaceMVK_PreCall", &table->CreateMacOSSurfaceMVK_PreCall);
    LoadPreFunction(gpa, handle, "SetDebugUtilsObjectNameEXT_PreCall", &table->SetDebugUtilsObjectNameEXT_PreCall);
    LoadPreFunction(gpa, handle, "SetDebugUtilsObjectTagEXT_PreCall", &table->SetDebugUtilsObjectTagEXT_PreCall);
    LoadPreFunction(gpa, handle, "QueueBeginDebugUtilsLabelEXT_PreCall", &table->QueueBeginDebugUtilsLabelEXT_PreCall);
    LoadPreFunction(gpa, handle, "QueueEndDebugUtilsLabelEXT_PreCall", &table->QueueEndDebugUtilsLabelEXT_PreCall);
    LoadPreFunction(gpa, handle, "QueueInsertDebugUtilsLabelEXT_PreCall", &table->QueueInsertDebugUtilsLabelEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdBeginDebugUtilsLabelEXT_PreCall", &table->CmdBeginDebugUtilsLabelEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdEndDebugUtilsLabelEXT_PreCall", &table->CmdEndDebugUtilsLabelEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdInsertDebugUtilsLabelEXT_PreCall", &table->CmdInsertDebugUtilsLabelEXT_PreCall);
    LoadPreFunction(gpa, handle, "CreateDebugUtilsMessengerEXT_PreCall", &table->CreateDebugUtilsMessengerEXT_PreCall);
    LoadPreFunction(gpa, handle, "DestroyDebugUtilsMessengerEXT_PreCall", &table->DestroyDebugUtilsMessengerEXT_PreCall);
    LoadPreFunction(gpa, handle, "SubmitDebugUtilsMessageEXT_PreCall", &table->SubmitDebugUtilsMessageEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetAndroidHardwareBufferPropertiesANDROID_PreCall", &table->GetAndroidHardwareBufferPropertiesANDROID_PreCall);
    LoadPreFunction(gpa, handle, "GetMemoryAndroidHardwareBufferANDROID_PreCall", &table->GetMemoryAndroidHardwareBufferANDROID_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetSampleLocationsEXT_PreCall", &table->CmdSetSampleLocationsEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceMultisamplePropertiesEXT_PreCall", &table->GetPhysicalDeviceMultisamplePropertiesEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetImageDrmFormatModifierPropertiesEXT_PreCall", &table->GetImageDrmFormatModifierPropertiesEXT_PreCall);
    LoadPreFunction(gpa, handle, "CreateValidationCacheEXT_PreCall", &table->CreateValidationCacheEXT_PreCall);
    LoadPreFunction(gpa, handle, "DestroyValidationCacheEXT_PreCall", &table->DestroyValidationCacheEXT_PreCall);
    LoadPreFunction(gpa, handle, "MergeValidationCachesEXT_PreCall", &table->MergeValidationCachesEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetValidationCacheDataEXT_PreCall", &table->GetValidationCacheDataEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdBindShadingRateImageNV_PreCall", &table->CmdBindShadingRateImageNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetViewportShadingRatePaletteNV_PreCall", &table->CmdSetViewportShadingRatePaletteNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetCoarseSampleOrderNV_PreCall", &table->CmdSetCoarseSampleOrderNV_PreCall);
    LoadPreFunction(gpa, handle, "CreateAccelerationStructureNV_PreCall", &table->CreateAccelerationStructureNV_PreCall);
    LoadPreFunction(gpa, handle, "DestroyAccelerationStructureNV_PreCall", &table->DestroyAccelerationStructureNV_PreCall);
    LoadPreFunction(gpa, handle, "GetAccelerationStructureMemoryRequirementsNV_PreCall", &table->GetAccelerationStructureMemoryRequirementsNV_PreCall);
    LoadPreFunction(gpa, handle, "BindAccelerationStructureMemoryNV_PreCall", &table->BindAccelerationStructureMemoryNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdBuildAccelerationStructureNV_PreCall", &table->CmdBuildAccelerationStructureNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyAccelerationStructureNV_PreCall", &table->CmdCopyAccelerationStructureNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdTraceRaysNV_PreCall", &table->CmdTraceRaysNV_PreCall);
    LoadPreFunction(gpa, handle, "CreateRayTracingPipelinesNV_PreCall", &table->CreateRayTracingPipelinesNV_PreCall);
    LoadPreFunction(gpa, handle, "GetRayTracingShaderGroupHandlesKHR_PreCall", &table->GetRayTracingShaderGroupHandlesKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetRayTracingShaderGroupHandlesNV_PreCall", &table->GetRayTracingShaderGroupHandlesNV_PreCall);
    LoadPreFunction(gpa, handle, "GetAccelerationStructureHandleNV_PreCall", &table->GetAccelerationStructureHandleNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdWriteAccelerationStructuresPropertiesNV_PreCall", &table->CmdWriteAccelerationStructuresPropertiesNV_PreCall);
    LoadPreFunction(gpa, handle, "CompileDeferredNV_PreCall", &table->CompileDeferredNV_PreCall);
    LoadPreFunction(gpa, handle, "GetMemoryHostPointerPropertiesEXT_PreCall", &table->GetMemoryHostPointerPropertiesEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdWriteBufferMarkerAMD_PreCall", &table->CmdWriteBufferMarkerAMD_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall", &table->GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetCalibratedTimestampsEXT_PreCall", &table->GetCalibratedTimestampsEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawMeshTasksNV_PreCall", &table->CmdDrawMeshTasksNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawMeshTasksIndirectNV_PreCall", &table->CmdDrawMeshTasksIndirectNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawMeshTasksIndirectCountNV_PreCall", &table->CmdDrawMeshTasksIndirectCountNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetExclusiveScissorEnableNV_PreCall", &table->CmdSetExclusiveScissorEnableNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetExclusiveScissorNV_PreCall", &table->CmdSetExclusiveScissorNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetCheckpointNV_PreCall", &table->CmdSetCheckpointNV_PreCall);
    LoadPreFunction(gpa, handle, "GetQueueCheckpointDataNV_PreCall", &table->GetQueueCheckpointDataNV_PreCall);
    LoadPreFunction(gpa, handle, "InitializePerformanceApiINTEL_PreCall", &table->InitializePerformanceApiINTEL_PreCall);
    LoadPreFunction(gpa, handle, "UninitializePerformanceApiINTEL_PreCall", &table->UninitializePerformanceApiINTEL_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetPerformanceMarkerINTEL_PreCall", &table->CmdSetPerformanceMarkerINTEL_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetPerformanceStreamMarkerINTEL_PreCall", &table->CmdSetPerformanceStreamMarkerINTEL_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetPerformanceOverrideINTEL_PreCall", &table->CmdSetPerformanceOverrideINTEL_PreCall);
    LoadPreFunction(gpa, handle, "AcquirePerformanceConfigurationINTEL_PreCall", &table->AcquirePerformanceConfigurationINTEL_PreCall);
    LoadPreFunction(gpa, handle, "ReleasePerformanceConfigurationINTEL_PreCall", &table->ReleasePerformanceConfigurationINTEL_PreCall);
    LoadPreFunction(gpa, handle, "QueueSetPerformanceConfigurationINTEL_PreCall", &table->QueueSetPerformanceConfigurationINTEL_PreCall);
    LoadPreFunction(gpa, handle, "GetPerformanceParameterINTEL_PreCall", &table->GetPerformanceParameterINTEL_PreCall);
    LoadPreFunction(gpa, handle, "SetLocalDimmingAMD_PreCall", &table->SetLocalDimmingAMD_PreCall);
    LoadPreFunction(gpa, handle, "CreateImagePipeSurfaceFUCHSIA_PreCall", &table->CreateImagePipeSurfaceFUCHSIA_PreCall);
    LoadPreFunction(gpa, handle, "CreateMetalSurfaceEXT_PreCall", &table->CreateMetalSurfaceEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetBufferDeviceAddressEXT_PreCall", &table->GetBufferDeviceAddressEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceToolPropertiesEXT_PreCall", &table->GetPhysicalDeviceToolPropertiesEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall", &table->GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall", &table->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceSurfacePresentModes2EXT_PreCall", &table->GetPhysicalDeviceSurfacePresentModes2EXT_PreCall);
    LoadPreFunction(gpa, handle, "AcquireFullScreenExclusiveModeEXT_PreCall", &table->AcquireFullScreenExclusiveModeEXT_PreCall);
    LoadPreFunction(gpa, handle, "ReleaseFullScreenExclusiveModeEXT_PreCall", &table->ReleaseFullScreenExclusiveModeEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceGroupSurfacePresentModes2EXT_PreCall", &table->GetDeviceGroupSurfacePresentModes2EXT_PreCall);
    LoadPreFunction(gpa, handle, "CreateHeadlessSurfaceEXT_PreCall", &table->CreateHeadlessSurfaceEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetLineStippleEXT_PreCall", &table->CmdSetLineStippleEXT_PreCall);
    LoadPreFunction(gpa, handle, "ResetQueryPoolEXT_PreCall", &table->ResetQueryPoolEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetCullModeEXT_PreCall", &table->CmdSetCullModeEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetFrontFaceEXT_PreCall", &table->CmdSetFrontFaceEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetPrimitiveTopologyEXT_PreCall", &table->CmdSetPrimitiveTopologyEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetViewportWithCountEXT_PreCall", &table->CmdSetViewportWithCountEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetScissorWithCountEXT_PreCall", &table->CmdSetScissorWithCountEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdBindVertexBuffers2EXT_PreCall", &table->CmdBindVertexBuffers2EXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthTestEnableEXT_PreCall", &table->CmdSetDepthTestEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthWriteEnableEXT_PreCall", &table->CmdSetDepthWriteEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthCompareOpEXT_PreCall", &table->CmdSetDepthCompareOpEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthBoundsTestEnableEXT_PreCall", &table->CmdSetDepthBoundsTestEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetStencilTestEnableEXT_PreCall", &table->CmdSetStencilTestEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetStencilOpEXT_PreCall", &table->CmdSetStencilOpEXT_PreCall);
    LoadPreFunction(gpa, handle, "ReleaseSwapchainImagesEXT_PreCall", &table->ReleaseSwapchainImagesEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetGeneratedCommandsMemoryRequirementsNV_PreCall", &table->GetGeneratedCommandsMemoryRequirementsNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdPreprocessGeneratedCommandsNV_PreCall", &table->CmdPreprocessGeneratedCommandsNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdExecuteGeneratedCommandsNV_PreCall", &table->CmdExecuteGeneratedCommandsNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdBindPipelineShaderGroupNV_PreCall", &table->CmdBindPipelineShaderGroupNV_PreCall);
    LoadPreFunction(gpa, handle, "CreateIndirectCommandsLayoutNV_PreCall", &table->CreateIndirectCommandsLayoutNV_PreCall);
    LoadPreFunction(gpa, handle, "DestroyIndirectCommandsLayoutNV_PreCall", &table->DestroyIndirectCommandsLayoutNV_PreCall);
    LoadPreFunction(gpa, handle, "AcquireDrmDisplayEXT_PreCall", &table->AcquireDrmDisplayEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetDrmDisplayEXT_PreCall", &table->GetDrmDisplayEXT_PreCall);
    LoadPreFunction(gpa, handle, "CreatePrivateDataSlotEXT_PreCall", &table->CreatePrivateDataSlotEXT_PreCall);
    LoadPreFunction(gpa, handle, "DestroyPrivateDataSlotEXT_PreCall", &table->DestroyPrivateDataSlotEXT_PreCall);
    LoadPreFunction(gpa, handle, "SetPrivateDataEXT_PreCall", &table->SetPrivateDataEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetPrivateDataEXT_PreCall", &table->GetPrivateDataEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetFragmentShadingRateEnumNV_PreCall", &table->CmdSetFragmentShadingRateEnumNV_PreCall);
    LoadPreFunction(gpa, handle, "GetImageSubresourceLayout2EXT_PreCall", &table->GetImageSubresourceLayout2EXT_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceFaultInfoEXT_PreCall", &table->GetDeviceFaultInfoEXT_PreCall);
    LoadPreFunction(gpa, handle, "AcquireWinrtDisplayNV_PreCall", &table->AcquireWinrtDisplayNV_PreCall);
    LoadPreFunction(gpa, handle, "GetWinrtDisplayNV_PreCall", &table->GetWinrtDisplayNV_PreCall);
    LoadPreFunction(gpa, handle, "CreateDirectFBSurfaceEXT_PreCall", &table->CreateDirectFBSurfaceEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall", &table->GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetVertexInputEXT_PreCall", &table->CmdSetVertexInputEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetMemoryZirconHandleFUCHSIA_PreCall", &table->GetMemoryZirconHandleFUCHSIA_PreCall);
    LoadPreFunction(gpa, handle, "GetMemoryZirconHandlePropertiesFUCHSIA_PreCall", &table->GetMemoryZirconHandlePropertiesFUCHSIA_PreCall);
    LoadPreFunction(gpa, handle, "ImportSemaphoreZirconHandleFUCHSIA_PreCall", &table->ImportSemaphoreZirconHandleFUCHSIA_PreCall);
    LoadPreFunction(gpa, handle, "GetSemaphoreZirconHandleFUCHSIA_PreCall", &table->GetSemaphoreZirconHandleFUCHSIA_PreCall);
    LoadPreFunction(gpa, handle, "CmdBindInvocationMaskHUAWEI_PreCall", &table->CmdBindInvocationMaskHUAWEI_PreCall);
    LoadPreFunction(gpa, handle, "GetMemoryRemoteAddressNV_PreCall", &table->GetMemoryRemoteAddressNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetPatchControlPointsEXT_PreCall", &table->CmdSetPatchControlPointsEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetRasterizerDiscardEnableEXT_PreCall", &table->CmdSetRasterizerDiscardEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthBiasEnableEXT_PreCall", &table->CmdSetDepthBiasEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetLogicOpEXT_PreCall", &table->CmdSetLogicOpEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetPrimitiveRestartEnableEXT_PreCall", &table->CmdSetPrimitiveRestartEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CreateScreenSurfaceQNX_PreCall", &table->CreateScreenSurfaceQNX_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceScreenPresentationSupportQNX_PreCall", &table->GetPhysicalDeviceScreenPresentationSupportQNX_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetColorWriteEnableEXT_PreCall", &table->CmdSetColorWriteEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawMultiEXT_PreCall", &table->CmdDrawMultiEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawMultiIndexedEXT_PreCall", &table->CmdDrawMultiIndexedEXT_PreCall);
    LoadPreFunction(gpa, handle, "CreateMicromapEXT_PreCall", &table->CreateMicromapEXT_PreCall);
    LoadPreFunction(gpa, handle, "DestroyMicromapEXT_PreCall", &table->DestroyMicromapEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdBuildMicromapsEXT_PreCall", &table->CmdBuildMicromapsEXT_PreCall);
    LoadPreFunction(gpa, handle, "BuildMicromapsEXT_PreCall", &table->BuildMicromapsEXT_PreCall);
    LoadPreFunction(gpa, handle, "CopyMicromapEXT_PreCall", &table->CopyMicromapEXT_PreCall);
    LoadPreFunction(gpa, handle, "CopyMicromapToMemoryEXT_PreCall", &table->CopyMicromapToMemoryEXT_PreCall);
    LoadPreFunction(gpa, handle, "CopyMemoryToMicromapEXT_PreCall", &table->CopyMemoryToMicromapEXT_PreCall);
    LoadPreFunction(gpa, handle, "WriteMicromapsPropertiesEXT_PreCall", &table->WriteMicromapsPropertiesEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyMicromapEXT_PreCall", &table->CmdCopyMicromapEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyMicromapToMemoryEXT_PreCall", &table->CmdCopyMicromapToMemoryEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyMemoryToMicromapEXT_PreCall", &table->CmdCopyMemoryToMicromapEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdWriteMicromapsPropertiesEXT_PreCall", &table->CmdWriteMicromapsPropertiesEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceMicromapCompatibilityEXT_PreCall", &table->GetDeviceMicromapCompatibilityEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetMicromapBuildSizesEXT_PreCall", &table->GetMicromapBuildSizesEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawClusterHUAWEI_PreCall", &table->CmdDrawClusterHUAWEI_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawClusterIndirectHUAWEI_PreCall", &table->CmdDrawClusterIndirectHUAWEI_PreCall);
    LoadPreFunction(gpa, handle, "SetDeviceMemoryPriorityEXT_PreCall", &table->SetDeviceMemoryPriorityEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall", &table->GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall);
    LoadPreFunction(gpa, handle, "GetDescriptorSetHostMappingVALVE_PreCall", &table->GetDescriptorSetHostMappingVALVE_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetTessellationDomainOriginEXT_PreCall", &table->CmdSetTessellationDomainOriginEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthClampEnableEXT_PreCall", &table->CmdSetDepthClampEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetPolygonModeEXT_PreCall", &table->CmdSetPolygonModeEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetRasterizationSamplesEXT_PreCall", &table->CmdSetRasterizationSamplesEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetSampleMaskEXT_PreCall", &table->CmdSetSampleMaskEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetAlphaToCoverageEnableEXT_PreCall", &table->CmdSetAlphaToCoverageEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetAlphaToOneEnableEXT_PreCall", &table->CmdSetAlphaToOneEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetLogicOpEnableEXT_PreCall", &table->CmdSetLogicOpEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetColorBlendEnableEXT_PreCall", &table->CmdSetColorBlendEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetColorBlendEquationEXT_PreCall", &table->CmdSetColorBlendEquationEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetColorWriteMaskEXT_PreCall", &table->CmdSetColorWriteMaskEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetRasterizationStreamEXT_PreCall", &table->CmdSetRasterizationStreamEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetConservativeRasterizationModeEXT_PreCall", &table->CmdSetConservativeRasterizationModeEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall", &table->CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthClipEnableEXT_PreCall", &table->CmdSetDepthClipEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetSampleLocationsEnableEXT_PreCall", &table->CmdSetSampleLocationsEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetColorBlendAdvancedEXT_PreCall", &table->CmdSetColorBlendAdvancedEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetProvokingVertexModeEXT_PreCall", &table->CmdSetProvokingVertexModeEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetLineRasterizationModeEXT_PreCall", &table->CmdSetLineRasterizationModeEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetLineStippleEnableEXT_PreCall", &table->CmdSetLineStippleEnableEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetDepthClipNegativeOneToOneEXT_PreCall", &table->CmdSetDepthClipNegativeOneToOneEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetViewportWScalingEnableNV_PreCall", &table->CmdSetViewportWScalingEnableNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetViewportSwizzleNV_PreCall", &table->CmdSetViewportSwizzleNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetCoverageToColorEnableNV_PreCall", &table->CmdSetCoverageToColorEnableNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetCoverageToColorLocationNV_PreCall", &table->CmdSetCoverageToColorLocationNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetCoverageModulationModeNV_PreCall", &table->CmdSetCoverageModulationModeNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetCoverageModulationTableEnableNV_PreCall", &table->CmdSetCoverageModulationTableEnableNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetCoverageModulationTableNV_PreCall", &table->CmdSetCoverageModulationTableNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetShadingRateImageEnableNV_PreCall", &table->CmdSetShadingRateImageEnableNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetRepresentativeFragmentTestEnableNV_PreCall", &table->CmdSetRepresentativeFragmentTestEnableNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetCoverageReductionModeNV_PreCall", &table->CmdSetCoverageReductionModeNV_PreCall);
    LoadPreFunction(gpa, handle, "GetShaderModuleIdentifierEXT_PreCall", &table->GetShaderModuleIdentifierEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetShaderModuleCreateInfoIdentifierEXT_PreCall", &table->GetShaderModuleCreateInfoIdentifierEXT_PreCall);
    LoadPreFunction(gpa, handle, "GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall", &table->GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall);
    LoadPreFunction(gpa, handle, "CreateOpticalFlowSessionNV_PreCall", &table->CreateOpticalFlowSessionNV_PreCall);
    LoadPreFunction(gpa, handle, "DestroyOpticalFlowSessionNV_PreCall", &table->DestroyOpticalFlowSessionNV_PreCall);
    LoadPreFunction(gpa, handle, "BindOpticalFlowSessionImageNV_PreCall", &table->BindOpticalFlowSessionImageNV_PreCall);
    LoadPreFunction(gpa, handle, "CmdOpticalFlowExecuteNV_PreCall", &table->CmdOpticalFlowExecuteNV_PreCall);
    LoadPreFunction(gpa, handle, "GetFramebufferTilePropertiesQCOM_PreCall", &table->GetFramebufferTilePropertiesQCOM_PreCall);
    LoadPreFunction(gpa, handle, "GetDynamicRenderingTilePropertiesQCOM_PreCall", &table->GetDynamicRenderingTilePropertiesQCOM_PreCall);
    LoadPreFunction(gpa, handle, "CreateAccelerationStructureKHR_PreCall", &table->CreateAccelerationStructureKHR_PreCall);
    LoadPreFunction(gpa, handle, "DestroyAccelerationStructureKHR_PreCall", &table->DestroyAccelerationStructureKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdBuildAccelerationStructuresKHR_PreCall", &table->CmdBuildAccelerationStructuresKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdBuildAccelerationStructuresIndirectKHR_PreCall", &table->CmdBuildAccelerationStructuresIndirectKHR_PreCall);
    LoadPreFunction(gpa, handle, "CopyAccelerationStructureToMemoryKHR_PreCall", &table->CopyAccelerationStructureToMemoryKHR_PreCall);
    LoadPreFunction(gpa, handle, "CopyMemoryToAccelerationStructureKHR_PreCall", &table->CopyMemoryToAccelerationStructureKHR_PreCall);
    LoadPreFunction(gpa, handle, "WriteAccelerationStructuresPropertiesKHR_PreCall", &table->WriteAccelerationStructuresPropertiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyAccelerationStructureKHR_PreCall", &table->CmdCopyAccelerationStructureKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyAccelerationStructureToMemoryKHR_PreCall", &table->CmdCopyAccelerationStructureToMemoryKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdCopyMemoryToAccelerationStructureKHR_PreCall", &table->CmdCopyMemoryToAccelerationStructureKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetAccelerationStructureDeviceAddressKHR_PreCall", &table->GetAccelerationStructureDeviceAddressKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdWriteAccelerationStructuresPropertiesKHR_PreCall", &table->CmdWriteAccelerationStructuresPropertiesKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetDeviceAccelerationStructureCompatibilityKHR_PreCall", &table->GetDeviceAccelerationStructureCompatibilityKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetAccelerationStructureBuildSizesKHR_PreCall", &table->GetAccelerationStructureBuildSizesKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdTraceRaysKHR_PreCall", &table->CmdTraceRaysKHR_PreCall);
    LoadPreFunction(gpa, handle, "CreateRayTracingPipelinesKHR_PreCall", &table->CreateRayTracingPipelinesKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall", &table->GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdTraceRaysIndirectKHR_PreCall", &table->CmdTraceRaysIndirectKHR_PreCall);
    LoadPreFunction(gpa, handle, "GetRayTracingShaderGroupStackSizeKHR_PreCall", &table->GetRayTracingShaderGroupStackSizeKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdSetRayTracingPipelineStackSizeKHR_PreCall", &table->CmdSetRayTracingPipelineStackSizeKHR_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawMeshTasksEXT_PreCall", &table->CmdDrawMeshTasksEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawMeshTasksIndirectEXT_PreCall", &table->CmdDrawMeshTasksIndirectEXT_PreCall);
    LoadPreFunction(gpa, handle, "CmdDrawMeshTasksIndirectCountEXT_PreCall", &table->CmdDrawMeshTasksIndirectCountEXT_PreCall);
}
// clang-format on

GFXRECON_END_NAMESPACE(replay)
GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_PLUGINS_REPLAY_FUNC_TABLE_PRE_H
