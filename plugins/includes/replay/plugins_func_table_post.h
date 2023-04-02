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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef GFXRECON_PLUGINS_REPLAY_FUNC_TABLE_POST_H
#define GFXRECON_PLUGINS_REPLAY_FUNC_TABLE_POST_H

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
typedef void (VKAPI_ATTR *PFN_CreateInstance_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkInstance>* pInstance);
typedef void (VKAPI_ATTR *PFN_DestroyInstance_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_EnumeratePhysicalDevices_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, PointerDecoder<uint32_t>* pPhysicalDeviceCount, HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFeatures_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFormatProperties_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceImageFormatProperties_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceProperties_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceQueueFamilyProperties_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pQueueFamilyPropertyCount, StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceMemoryProperties_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties);
typedef void (VKAPI_ATTR *PFN_CreateDevice_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDevice>* pDevice);
typedef void (VKAPI_ATTR *PFN_DestroyDevice_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetDeviceQueue_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t queueFamilyIndex, uint32_t queueIndex, HandlePointerDecoder<VkQueue>* pQueue);
typedef void (VKAPI_ATTR *PFN_QueueSubmit_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t submitCount, StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits, format::HandleId fence);
typedef void (VKAPI_ATTR *PFN_QueueWaitIdle_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue);
typedef void (VKAPI_ATTR *PFN_DeviceWaitIdle_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device);
typedef void (VKAPI_ATTR *PFN_AllocateMemory_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDeviceMemory>* pMemory);
typedef void (VKAPI_ATTR *PFN_FreeMemory_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_MapMemory_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, PointerDecoder<uint64_t, void*>* ppData);
typedef void (VKAPI_ATTR *PFN_UnmapMemory_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory);
typedef void (VKAPI_ATTR *PFN_FlushMappedMemoryRanges_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t memoryRangeCount, StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges);
typedef void (VKAPI_ATTR *PFN_InvalidateMappedMemoryRanges_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t memoryRangeCount, StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges);
typedef void (VKAPI_ATTR *PFN_GetDeviceMemoryCommitment_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory, PointerDecoder<VkDeviceSize>* pCommittedMemoryInBytes);
typedef void (VKAPI_ATTR *PFN_BindBufferMemory_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId buffer, format::HandleId memory, VkDeviceSize memoryOffset);
typedef void (VKAPI_ATTR *PFN_BindImageMemory_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId image, format::HandleId memory, VkDeviceSize memoryOffset);
typedef void (VKAPI_ATTR *PFN_GetBufferMemoryRequirements_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId buffer, StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetImageMemoryRequirements_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetImageSparseMemoryRequirements_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSparseImageFormatProperties_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties);
typedef void (VKAPI_ATTR *PFN_QueueBindSparse_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo, format::HandleId fence);
typedef void (VKAPI_ATTR *PFN_CreateFence_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFence>* pFence);
typedef void (VKAPI_ATTR *PFN_DestroyFence_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId fence, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_ResetFences_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t fenceCount, HandlePointerDecoder<VkFence>* pFences);
typedef void (VKAPI_ATTR *PFN_GetFenceStatus_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId fence);
typedef void (VKAPI_ATTR *PFN_WaitForFences_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t fenceCount, HandlePointerDecoder<VkFence>* pFences, VkBool32 waitAll, uint64_t timeout);
typedef void (VKAPI_ATTR *PFN_CreateSemaphore_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSemaphore>* pSemaphore);
typedef void (VKAPI_ATTR *PFN_DestroySemaphore_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId semaphore, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateEvent_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkEvent>* pEvent);
typedef void (VKAPI_ATTR *PFN_DestroyEvent_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId event, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetEventStatus_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId event);
typedef void (VKAPI_ATTR *PFN_SetEvent_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId event);
typedef void (VKAPI_ATTR *PFN_ResetEvent_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId event);
typedef void (VKAPI_ATTR *PFN_CreateQueryPool_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkQueryPool>* pQueryPool);
typedef void (VKAPI_ATTR *PFN_DestroyQueryPool_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId queryPool, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetQueryPoolResults_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, PointerDecoder<uint8_t>* pData, VkDeviceSize stride, VkQueryResultFlags flags);
typedef void (VKAPI_ATTR *PFN_CreateBuffer_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkBuffer>* pBuffer);
typedef void (VKAPI_ATTR *PFN_DestroyBuffer_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId buffer, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateBufferView_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkBufferView>* pView);
typedef void (VKAPI_ATTR *PFN_DestroyBufferView_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId bufferView, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateImage_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkImage>* pImage);
typedef void (VKAPI_ATTR *PFN_DestroyImage_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetImageSubresourceLayout_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource, StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout);
typedef void (VKAPI_ATTR *PFN_CreateImageView_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkImageView>* pView);
typedef void (VKAPI_ATTR *PFN_DestroyImageView_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId imageView, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateShaderModule_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkShaderModule>* pShaderModule);
typedef void (VKAPI_ATTR *PFN_DestroyShaderModule_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId shaderModule, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreatePipelineCache_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipelineCache>* pPipelineCache);
typedef void (VKAPI_ATTR *PFN_DestroyPipelineCache_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId pipelineCache, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetPipelineCacheData_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, PointerDecoder<size_t>* pDataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_MergePipelineCaches_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId dstCache, uint32_t srcCacheCount, HandlePointerDecoder<VkPipelineCache>* pSrcCaches);
typedef void (VKAPI_ATTR *PFN_CreateGraphicsPipelines_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines);
typedef void (VKAPI_ATTR *PFN_CreateComputePipelines_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines);
typedef void (VKAPI_ATTR *PFN_DestroyPipeline_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId pipeline, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreatePipelineLayout_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipelineLayout>* pPipelineLayout);
typedef void (VKAPI_ATTR *PFN_DestroyPipelineLayout_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId pipelineLayout, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateSampler_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSampler>* pSampler);
typedef void (VKAPI_ATTR *PFN_DestroySampler_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId sampler, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateDescriptorSetLayout_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout);
typedef void (VKAPI_ATTR *PFN_DestroyDescriptorSetLayout_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorSetLayout, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateDescriptorPool_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorPool>* pDescriptorPool);
typedef void (VKAPI_ATTR *PFN_DestroyDescriptorPool_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorPool, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_ResetDescriptorPool_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId descriptorPool, VkDescriptorPoolResetFlags flags);
typedef void (VKAPI_ATTR *PFN_AllocateDescriptorSets_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo, HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets);
typedef void (VKAPI_ATTR *PFN_FreeDescriptorSets_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId descriptorPool, uint32_t descriptorSetCount, HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets);
typedef void (VKAPI_ATTR *PFN_UpdateDescriptorSets_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t descriptorWriteCount, StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites, uint32_t descriptorCopyCount, StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies);
typedef void (VKAPI_ATTR *PFN_CreateFramebuffer_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFramebuffer>* pFramebuffer);
typedef void (VKAPI_ATTR *PFN_DestroyFramebuffer_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId framebuffer, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateRenderPass_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkRenderPass>* pRenderPass);
typedef void (VKAPI_ATTR *PFN_DestroyRenderPass_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId renderPass, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetRenderAreaGranularity_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId renderPass, StructPointerDecoder<Decoded_VkExtent2D>* pGranularity);
typedef void (VKAPI_ATTR *PFN_CreateCommandPool_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkCommandPool>* pCommandPool);
typedef void (VKAPI_ATTR *PFN_DestroyCommandPool_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_ResetCommandPool_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId commandPool, VkCommandPoolResetFlags flags);
typedef void (VKAPI_ATTR *PFN_AllocateCommandBuffers_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo, HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers);
typedef void (VKAPI_ATTR *PFN_FreeCommandBuffers_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, uint32_t commandBufferCount, HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers);
typedef void (VKAPI_ATTR *PFN_BeginCommandBuffer_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo);
typedef void (VKAPI_ATTR *PFN_EndCommandBuffer_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_ResetCommandBuffer_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, VkCommandBufferResetFlags flags);
typedef void (VKAPI_ATTR *PFN_CmdBindPipeline_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId pipeline);
typedef void (VKAPI_ATTR *PFN_CmdSetViewport_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewport>* pViewports);
typedef void (VKAPI_ATTR *PFN_CmdSetScissor_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstScissor, uint32_t scissorCount, StructPointerDecoder<Decoded_VkRect2D>* pScissors);
typedef void (VKAPI_ATTR *PFN_CmdSetLineWidth_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float lineWidth);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthBias_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
typedef void (VKAPI_ATTR *PFN_CmdSetBlendConstants_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, PointerDecoder<float>* blendConstants);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthBounds_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float minDepthBounds, float maxDepthBounds);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilCompareMask_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilWriteMask_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilReference_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);
typedef void (VKAPI_ATTR *PFN_CmdBindDescriptorSets_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId layout, uint32_t firstSet, uint32_t descriptorSetCount, HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets, uint32_t dynamicOffsetCount, PointerDecoder<uint32_t>* pDynamicOffsets);
typedef void (VKAPI_ATTR *PFN_CmdBindIndexBuffer_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, VkIndexType indexType);
typedef void (VKAPI_ATTR *PFN_CmdBindVertexBuffers_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets);
typedef void (VKAPI_ATTR *PFN_CmdDraw_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndexed_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndirect_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndexedIndirect_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDispatch_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_ATTR *PFN_CmdDispatchIndirect_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset);
typedef void (VKAPI_ATTR *PFN_CmdCopyBuffer_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcBuffer, format::HandleId dstBuffer, uint32_t regionCount, StructPointerDecoder<Decoded_VkBufferCopy>* pRegions);
typedef void (VKAPI_ATTR *PFN_CmdCopyImage_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkImageCopy>* pRegions);
typedef void (VKAPI_ATTR *PFN_CmdBlitImage_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkImageBlit>* pRegions, VkFilter filter);
typedef void (VKAPI_ATTR *PFN_CmdCopyBufferToImage_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcBuffer, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions);
typedef void (VKAPI_ATTR *PFN_CmdCopyImageToBuffer_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstBuffer, uint32_t regionCount, StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions);
typedef void (VKAPI_ATTR *PFN_CmdUpdateBuffer_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_CmdFillBuffer_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);
typedef void (VKAPI_ATTR *PFN_CmdClearColorImage_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId image, VkImageLayout imageLayout, StructPointerDecoder<Decoded_VkClearColorValue>* pColor, uint32_t rangeCount, StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges);
typedef void (VKAPI_ATTR *PFN_CmdClearDepthStencilImage_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId image, VkImageLayout imageLayout, StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil, uint32_t rangeCount, StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges);
typedef void (VKAPI_ATTR *PFN_CmdClearAttachments_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t attachmentCount, StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments, uint32_t rectCount, StructPointerDecoder<Decoded_VkClearRect>* pRects);
typedef void (VKAPI_ATTR *PFN_CmdResolveImage_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkImageResolve>* pRegions);
typedef void (VKAPI_ATTR *PFN_CmdSetEvent_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags stageMask);
typedef void (VKAPI_ATTR *PFN_CmdResetEvent_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags stageMask);
typedef void (VKAPI_ATTR *PFN_CmdWaitEvents_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t eventCount, HandlePointerDecoder<VkEvent>* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers);
typedef void (VKAPI_ATTR *PFN_CmdPipelineBarrier_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers);
typedef void (VKAPI_ATTR *PFN_CmdBeginQuery_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query, VkQueryControlFlags flags);
typedef void (VKAPI_ATTR *PFN_CmdEndQuery_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query);
typedef void (VKAPI_ATTR *PFN_CmdResetQueryPool_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_ATTR *PFN_CmdWriteTimestamp_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlagBits pipelineStage, format::HandleId queryPool, uint32_t query);
typedef void (VKAPI_ATTR *PFN_CmdCopyQueryPoolResults_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount, format::HandleId dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);
typedef void (VKAPI_ATTR *PFN_CmdPushConstants_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, PointerDecoder<uint8_t>* pValues);
typedef void (VKAPI_ATTR *PFN_CmdBeginRenderPass_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin, VkSubpassContents contents);
typedef void (VKAPI_ATTR *PFN_CmdNextSubpass_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkSubpassContents contents);
typedef void (VKAPI_ATTR *PFN_CmdEndRenderPass_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_CmdExecuteCommands_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t commandBufferCount, HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers);
typedef void (VKAPI_ATTR *PFN_BindBufferMemory2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos);
typedef void (VKAPI_ATTR *PFN_BindImageMemory2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos);
typedef void (VKAPI_ATTR *PFN_GetDeviceGroupPeerMemoryFeatures_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, PointerDecoder<VkPeerMemoryFeatureFlags>* pPeerMemoryFeatures);
typedef void (VKAPI_ATTR *PFN_CmdSetDeviceMask_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t deviceMask);
typedef void (VKAPI_ATTR *PFN_CmdDispatchBase_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_ATTR *PFN_EnumeratePhysicalDeviceGroups_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, PointerDecoder<uint32_t>* pPhysicalDeviceGroupCount, StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties);
typedef void (VKAPI_ATTR *PFN_GetImageMemoryRequirements2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetBufferMemoryRequirements2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetImageSparseMemoryRequirements2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFeatures2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceProperties2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFormatProperties2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceImageFormatProperties2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo, StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceQueueFamilyProperties2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pQueueFamilyPropertyCount, StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceMemoryProperties2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSparseImageFormatProperties2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties);
typedef void (VKAPI_ATTR *PFN_TrimCommandPool_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, VkCommandPoolTrimFlags flags);
typedef void (VKAPI_ATTR *PFN_GetDeviceQueue2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo, HandlePointerDecoder<VkQueue>* pQueue);
typedef void (VKAPI_ATTR *PFN_CreateSamplerYcbcrConversion_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion);
typedef void (VKAPI_ATTR *PFN_DestroySamplerYcbcrConversion_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId ycbcrConversion, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateDescriptorUpdateTemplate_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate);
typedef void (VKAPI_ATTR *PFN_DestroyDescriptorUpdateTemplate_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorUpdateTemplate, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalBufferProperties_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo, StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalFenceProperties_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo, StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalSemaphoreProperties_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo, StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties);
typedef void (VKAPI_ATTR *PFN_GetDescriptorSetLayoutSupport_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndirectCount_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndexedIndirectCount_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CreateRenderPass2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkRenderPass>* pRenderPass);
typedef void (VKAPI_ATTR *PFN_CmdBeginRenderPass2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo);
typedef void (VKAPI_ATTR *PFN_CmdNextSubpass2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);
typedef void (VKAPI_ATTR *PFN_CmdEndRenderPass2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);
typedef void (VKAPI_ATTR *PFN_ResetQueryPool_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_ATTR *PFN_GetSemaphoreCounterValue_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId semaphore, PointerDecoder<uint64_t>* pValue);
typedef void (VKAPI_ATTR *PFN_WaitSemaphores_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo, uint64_t timeout);
typedef void (VKAPI_ATTR *PFN_SignalSemaphore_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo);
typedef void (VKAPI_ATTR *PFN_GetBufferDeviceAddress_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetBufferOpaqueCaptureAddress_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetDeviceMemoryOpaqueCaptureAddress_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceToolProperties_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pToolCount, StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties);
typedef void (VKAPI_ATTR *PFN_CreatePrivateDataSlot_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPrivateDataSlot>* pPrivateDataSlot);
typedef void (VKAPI_ATTR *PFN_DestroyPrivateDataSlot_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId privateDataSlot, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_SetPrivateData_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, uint64_t data);
typedef void (VKAPI_ATTR *PFN_GetPrivateData_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, PointerDecoder<uint64_t>* pData);
typedef void (VKAPI_ATTR *PFN_CmdSetEvent2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo);
typedef void (VKAPI_ATTR *PFN_CmdResetEvent2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags2 stageMask);
typedef void (VKAPI_ATTR *PFN_CmdWaitEvents2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t eventCount, HandlePointerDecoder<VkEvent>* pEvents, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos);
typedef void (VKAPI_ATTR *PFN_CmdPipelineBarrier2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo);
typedef void (VKAPI_ATTR *PFN_CmdWriteTimestamp2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags2 stage, format::HandleId queryPool, uint32_t query);
typedef void (VKAPI_ATTR *PFN_QueueSubmit2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t submitCount, StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits, format::HandleId fence);
typedef void (VKAPI_ATTR *PFN_CmdCopyBuffer2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyImage2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyBufferToImage2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyImageToBuffer2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo);
typedef void (VKAPI_ATTR *PFN_CmdBlitImage2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdResolveImage2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdBeginRendering_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo);
typedef void (VKAPI_ATTR *PFN_CmdEndRendering_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_CmdSetCullMode_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCullModeFlags cullMode);
typedef void (VKAPI_ATTR *PFN_CmdSetFrontFace_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkFrontFace frontFace);
typedef void (VKAPI_ATTR *PFN_CmdSetPrimitiveTopology_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPrimitiveTopology primitiveTopology);
typedef void (VKAPI_ATTR *PFN_CmdSetViewportWithCount_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewport>* pViewports);
typedef void (VKAPI_ATTR *PFN_CmdSetScissorWithCount_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t scissorCount, StructPointerDecoder<Decoded_VkRect2D>* pScissors);
typedef void (VKAPI_ATTR *PFN_CmdBindVertexBuffers2_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets, PointerDecoder<VkDeviceSize>* pSizes, PointerDecoder<VkDeviceSize>* pStrides);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthTestEnable_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthWriteEnable_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthWriteEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthCompareOp_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCompareOp depthCompareOp);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthBoundsTestEnable_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBoundsTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilTestEnable_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 stencilTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilOp_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
typedef void (VKAPI_ATTR *PFN_CmdSetRasterizerDiscardEnable_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 rasterizerDiscardEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthBiasEnable_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBiasEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetPrimitiveRestartEnable_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 primitiveRestartEnable);
typedef void (VKAPI_ATTR *PFN_GetDeviceBufferMemoryRequirements_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetDeviceImageMemoryRequirements_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetDeviceImageSparseMemoryRequirements_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_DestroySurfaceKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, format::HandleId surface, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfaceSupportKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, format::HandleId surface, PointerDecoder<VkBool32>* pSupported);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfaceFormatsKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, PointerDecoder<uint32_t>* pSurfaceFormatCount, StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfacePresentModesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, PointerDecoder<uint32_t>* pPresentModeCount, PointerDecoder<VkPresentModeKHR>* pPresentModes);
typedef void (VKAPI_ATTR *PFN_CreateSwapchainKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSwapchainKHR>* pSwapchain);
typedef void (VKAPI_ATTR *PFN_DestroySwapchainKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId swapchain, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetSwapchainImagesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, PointerDecoder<uint32_t>* pSwapchainImageCount, HandlePointerDecoder<VkImage>* pSwapchainImages);
typedef void (VKAPI_ATTR *PFN_AcquireNextImageKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, uint64_t timeout, format::HandleId semaphore, format::HandleId fence, PointerDecoder<uint32_t>* pImageIndex);
typedef void (VKAPI_ATTR *PFN_QueuePresentKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo);
typedef void (VKAPI_ATTR *PFN_GetDeviceGroupPresentCapabilitiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities);
typedef void (VKAPI_ATTR *PFN_GetDeviceGroupSurfacePresentModesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId surface, PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDevicePresentRectanglesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, PointerDecoder<uint32_t>* pRectCount, StructPointerDecoder<Decoded_VkRect2D>* pRects);
typedef void (VKAPI_ATTR *PFN_AcquireNextImage2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo, PointerDecoder<uint32_t>* pImageIndex);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceDisplayPropertiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetDisplayPlaneSupportedDisplaysKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t planeIndex, PointerDecoder<uint32_t>* pDisplayCount, HandlePointerDecoder<VkDisplayKHR>* pDisplays);
typedef void (VKAPI_ATTR *PFN_GetDisplayModePropertiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_CreateDisplayModeKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display, StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDisplayModeKHR>* pMode);
typedef void (VKAPI_ATTR *PFN_GetDisplayPlaneCapabilitiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId mode, uint32_t planeIndex, StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities);
typedef void (VKAPI_ATTR *PFN_CreateDisplayPlaneSurfaceKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_CreateSharedSwapchainsKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t swapchainCount, StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSwapchainKHR>* pSwapchains);
typedef void (VKAPI_ATTR *PFN_CreateXlibSurfaceKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceXlibPresentationSupportKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t dpy, size_t visualID);
typedef void (VKAPI_ATTR *PFN_CreateXcbSurfaceKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceXcbPresentationSupportKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t connection, uint32_t visual_id);
typedef void (VKAPI_ATTR *PFN_CreateWaylandSurfaceKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t display);
typedef void (VKAPI_ATTR *PFN_CreateAndroidSurfaceKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_CreateWin32SurfaceKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceWin32PresentationSupportKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceVideoCapabilitiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile, StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR>* pCapabilities);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR>* pVideoFormatInfo, PointerDecoder<uint32_t>* pVideoFormatPropertyCount, StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR>* pVideoFormatProperties);
typedef void (VKAPI_ATTR *PFN_CreateVideoSessionKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkVideoSessionKHR>* pVideoSession);
typedef void (VKAPI_ATTR *PFN_DestroyVideoSessionKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId videoSession, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetVideoSessionMemoryRequirementsKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId videoSession, PointerDecoder<uint32_t>* pMemoryRequirementsCount, StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_BindVideoSessionMemoryKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId videoSession, uint32_t bindSessionMemoryInfoCount, StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos);
typedef void (VKAPI_ATTR *PFN_CreateVideoSessionParametersKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkVideoSessionParametersKHR>* pVideoSessionParameters);
typedef void (VKAPI_ATTR *PFN_UpdateVideoSessionParametersKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId videoSessionParameters, StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR>* pUpdateInfo);
typedef void (VKAPI_ATTR *PFN_DestroyVideoSessionParametersKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId videoSessionParameters, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CmdBeginVideoCodingKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo);
typedef void (VKAPI_ATTR *PFN_CmdEndVideoCodingKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo);
typedef void (VKAPI_ATTR *PFN_CmdControlVideoCodingKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo);
typedef void (VKAPI_ATTR *PFN_CmdDecodeVideoKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo);
typedef void (VKAPI_ATTR *PFN_CmdBeginRenderingKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo);
typedef void (VKAPI_ATTR *PFN_CmdEndRenderingKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFeatures2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceProperties2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFormatProperties2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceImageFormatProperties2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo, StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pQueueFamilyPropertyCount, StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceMemoryProperties2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetDeviceGroupPeerMemoryFeaturesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, PointerDecoder<VkPeerMemoryFeatureFlags>* pPeerMemoryFeatures);
typedef void (VKAPI_ATTR *PFN_CmdSetDeviceMaskKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t deviceMask);
typedef void (VKAPI_ATTR *PFN_CmdDispatchBaseKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_ATTR *PFN_TrimCommandPoolKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, VkCommandPoolTrimFlags flags);
typedef void (VKAPI_ATTR *PFN_EnumeratePhysicalDeviceGroupsKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, PointerDecoder<uint32_t>* pPhysicalDeviceGroupCount, StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo, StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties);
typedef void (VKAPI_ATTR *PFN_GetMemoryWin32HandleKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo, PointerDecoder<uint64_t, void*>* pHandle);
typedef void (VKAPI_ATTR *PFN_GetMemoryWin32HandlePropertiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, uint64_t handle, StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties);
typedef void (VKAPI_ATTR *PFN_GetMemoryFdKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo, PointerDecoder<int>* pFd);
typedef void (VKAPI_ATTR *PFN_GetMemoryFdPropertiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo, StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties);
typedef void (VKAPI_ATTR *PFN_ImportSemaphoreWin32HandleKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo);
typedef void (VKAPI_ATTR *PFN_GetSemaphoreWin32HandleKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo, PointerDecoder<uint64_t, void*>* pHandle);
typedef void (VKAPI_ATTR *PFN_ImportSemaphoreFdKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo);
typedef void (VKAPI_ATTR *PFN_GetSemaphoreFdKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo, PointerDecoder<int>* pFd);
typedef void (VKAPI_ATTR *PFN_CmdPushDescriptorSetKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId layout, uint32_t set, uint32_t descriptorWriteCount, StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites);
typedef void (VKAPI_ATTR *PFN_CreateDescriptorUpdateTemplateKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate);
typedef void (VKAPI_ATTR *PFN_DestroyDescriptorUpdateTemplateKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorUpdateTemplate, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CreateRenderPass2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkRenderPass>* pRenderPass);
typedef void (VKAPI_ATTR *PFN_CmdBeginRenderPass2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo);
typedef void (VKAPI_ATTR *PFN_CmdNextSubpass2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);
typedef void (VKAPI_ATTR *PFN_CmdEndRenderPass2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);
typedef void (VKAPI_ATTR *PFN_GetSwapchainStatusKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalFencePropertiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo, StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties);
typedef void (VKAPI_ATTR *PFN_ImportFenceWin32HandleKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo);
typedef void (VKAPI_ATTR *PFN_GetFenceWin32HandleKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo, PointerDecoder<uint64_t, void*>* pHandle);
typedef void (VKAPI_ATTR *PFN_ImportFenceFdKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo);
typedef void (VKAPI_ATTR *PFN_GetFenceFdKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo, PointerDecoder<int>* pFd);
typedef void (VKAPI_ATTR *PFN_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, PointerDecoder<uint32_t>* pCounterCount, StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters, StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo, PointerDecoder<uint32_t>* pNumPasses);
typedef void (VKAPI_ATTR *PFN_AcquireProfilingLockKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_ReleaseProfilingLockKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfaceFormats2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, PointerDecoder<uint32_t>* pSurfaceFormatCount, StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceDisplayProperties2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetDisplayModeProperties2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetDisplayPlaneCapabilities2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo, StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities);
typedef void (VKAPI_ATTR *PFN_GetImageMemoryRequirements2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetBufferMemoryRequirements2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetImageSparseMemoryRequirements2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_CreateSamplerYcbcrConversionKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion);
typedef void (VKAPI_ATTR *PFN_DestroySamplerYcbcrConversionKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId ycbcrConversion, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_BindBufferMemory2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos);
typedef void (VKAPI_ATTR *PFN_BindImageMemory2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos);
typedef void (VKAPI_ATTR *PFN_GetDescriptorSetLayoutSupportKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndirectCountKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndexedIndirectCountKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_GetSemaphoreCounterValueKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId semaphore, PointerDecoder<uint64_t>* pValue);
typedef void (VKAPI_ATTR *PFN_WaitSemaphoresKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo, uint64_t timeout);
typedef void (VKAPI_ATTR *PFN_SignalSemaphoreKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceFragmentShadingRatesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pFragmentShadingRateCount, StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates);
typedef void (VKAPI_ATTR *PFN_CmdSetFragmentShadingRateKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkExtent2D>* pFragmentSize, PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps);
typedef void (VKAPI_ATTR *PFN_WaitForPresentKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, uint64_t presentId, uint64_t timeout);
typedef void (VKAPI_ATTR *PFN_GetBufferDeviceAddressKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetBufferOpaqueCaptureAddressKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_CreateDeferredOperationKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation);
typedef void (VKAPI_ATTR *PFN_DestroyDeferredOperationKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId operation, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetDeferredOperationMaxConcurrencyKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint32_t returnValue, format::HandleId device, format::HandleId operation);
typedef void (VKAPI_ATTR *PFN_GetDeferredOperationResultKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId operation);
typedef void (VKAPI_ATTR *PFN_DeferredOperationJoinKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId operation);
typedef void (VKAPI_ATTR *PFN_GetPipelineExecutablePropertiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo, PointerDecoder<uint32_t>* pExecutableCount, StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPipelineExecutableStatisticsKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo, PointerDecoder<uint32_t>* pStatisticCount, StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics);
typedef void (VKAPI_ATTR *PFN_GetPipelineExecutableInternalRepresentationsKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo, PointerDecoder<uint32_t>* pInternalRepresentationCount, StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations);
typedef void (VKAPI_ATTR *PFN_CmdEncodeVideoKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo);
typedef void (VKAPI_ATTR *PFN_CmdSetEvent2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo);
typedef void (VKAPI_ATTR *PFN_CmdResetEvent2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags2 stageMask);
typedef void (VKAPI_ATTR *PFN_CmdWaitEvents2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t eventCount, HandlePointerDecoder<VkEvent>* pEvents, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos);
typedef void (VKAPI_ATTR *PFN_CmdPipelineBarrier2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo);
typedef void (VKAPI_ATTR *PFN_CmdWriteTimestamp2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags2 stage, format::HandleId queryPool, uint32_t query);
typedef void (VKAPI_ATTR *PFN_QueueSubmit2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t submitCount, StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits, format::HandleId fence);
typedef void (VKAPI_ATTR *PFN_CmdWriteBufferMarker2AMD_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags2 stage, format::HandleId dstBuffer, VkDeviceSize dstOffset, uint32_t marker);
typedef void (VKAPI_ATTR *PFN_GetQueueCheckpointData2NV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, PointerDecoder<uint32_t>* pCheckpointDataCount, StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData);
typedef void (VKAPI_ATTR *PFN_CmdCopyBuffer2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyImage2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyBufferToImage2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyImageToBuffer2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo);
typedef void (VKAPI_ATTR *PFN_CmdBlitImage2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdResolveImage2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo);
typedef void (VKAPI_ATTR *PFN_CmdTraceRaysIndirect2KHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkDeviceAddress indirectDeviceAddress);
typedef void (VKAPI_ATTR *PFN_GetDeviceBufferMemoryRequirementsKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetDeviceImageMemoryRequirementsKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_GetDeviceImageSparseMemoryRequirementsKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_CreateDebugReportCallbackEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback);
typedef void (VKAPI_ATTR *PFN_DestroyDebugReportCallbackEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, format::HandleId callback, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_DebugReportMessageEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, StringDecoder* pLayerPostfix, StringDecoder* pMessage);
typedef void (VKAPI_ATTR *PFN_DebugMarkerSetObjectTagEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo);
typedef void (VKAPI_ATTR *PFN_DebugMarkerSetObjectNameEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo);
typedef void (VKAPI_ATTR *PFN_CmdDebugMarkerBeginEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo);
typedef void (VKAPI_ATTR *PFN_CmdDebugMarkerEndEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_CmdDebugMarkerInsertEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo);
typedef void (VKAPI_ATTR *PFN_CmdBindTransformFeedbackBuffersEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets, PointerDecoder<VkDeviceSize>* pSizes);
typedef void (VKAPI_ATTR *PFN_CmdBeginTransformFeedbackEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, HandlePointerDecoder<VkBuffer>* pCounterBuffers, PointerDecoder<VkDeviceSize>* pCounterBufferOffsets);
typedef void (VKAPI_ATTR *PFN_CmdEndTransformFeedbackEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, HandlePointerDecoder<VkBuffer>* pCounterBuffers, PointerDecoder<VkDeviceSize>* pCounterBufferOffsets);
typedef void (VKAPI_ATTR *PFN_CmdBeginQueryIndexedEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index);
typedef void (VKAPI_ATTR *PFN_CmdEndQueryIndexedEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query, uint32_t index);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndirectByteCountEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t instanceCount, uint32_t firstInstance, format::HandleId counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride);
typedef void (VKAPI_ATTR *PFN_GetImageViewHandleNVX_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint32_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetImageViewAddressNVX_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId imageView, StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndirectCountAMD_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawIndexedIndirectCountAMD_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_GetShaderInfoAMD_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, PointerDecoder<size_t>* pInfoSize, PointerDecoder<uint8_t>* pInfo);
typedef void (VKAPI_ATTR *PFN_CreateStreamDescriptorSurfaceGGP_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>* pExternalImageFormatProperties);
typedef void (VKAPI_ATTR *PFN_GetMemoryWin32HandleNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId memory, VkExternalMemoryHandleTypeFlagsNV handleType, PointerDecoder<uint64_t, void*>* pHandle);
typedef void (VKAPI_ATTR *PFN_CreateViSurfaceNN_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_CmdBeginConditionalRenderingEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin);
typedef void (VKAPI_ATTR *PFN_CmdEndConditionalRenderingEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_CmdSetViewportWScalingNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings);
typedef void (VKAPI_ATTR *PFN_ReleaseDisplayEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display);
typedef void (VKAPI_ATTR *PFN_AcquireXlibDisplayEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint64_t dpy, format::HandleId display);
typedef void (VKAPI_ATTR *PFN_GetRandROutputDisplayEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint64_t dpy, size_t rrOutput, HandlePointerDecoder<VkDisplayKHR>* pDisplay);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities);
typedef void (VKAPI_ATTR *PFN_DisplayPowerControlEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId display, StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo);
typedef void (VKAPI_ATTR *PFN_RegisterDeviceEventEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFence>* pFence);
typedef void (VKAPI_ATTR *PFN_RegisterDisplayEventEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId display, StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFence>* pFence);
typedef void (VKAPI_ATTR *PFN_GetSwapchainCounterEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, VkSurfaceCounterFlagBitsEXT counter, PointerDecoder<uint64_t>* pCounterValue);
typedef void (VKAPI_ATTR *PFN_GetRefreshCycleDurationGOOGLE_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties);
typedef void (VKAPI_ATTR *PFN_GetPastPresentationTimingGOOGLE_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, PointerDecoder<uint32_t>* pPresentationTimingCount, StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings);
typedef void (VKAPI_ATTR *PFN_CmdSetDiscardRectangleEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, StructPointerDecoder<Decoded_VkRect2D>* pDiscardRectangles);
typedef void (VKAPI_ATTR *PFN_CmdSetDiscardRectangleEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 discardRectangleEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDiscardRectangleModeEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode);
typedef void (VKAPI_ATTR *PFN_SetHdrMetadataEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t swapchainCount, HandlePointerDecoder<VkSwapchainKHR>* pSwapchains, StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata);
typedef void (VKAPI_ATTR *PFN_CreateIOSSurfaceMVK_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_CreateMacOSSurfaceMVK_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_SetDebugUtilsObjectNameEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo);
typedef void (VKAPI_ATTR *PFN_SetDebugUtilsObjectTagEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo);
typedef void (VKAPI_ATTR *PFN_QueueBeginDebugUtilsLabelEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo);
typedef void (VKAPI_ATTR *PFN_QueueEndDebugUtilsLabelEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue);
typedef void (VKAPI_ATTR *PFN_QueueInsertDebugUtilsLabelEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo);
typedef void (VKAPI_ATTR *PFN_CmdBeginDebugUtilsLabelEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo);
typedef void (VKAPI_ATTR *PFN_CmdEndDebugUtilsLabelEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer);
typedef void (VKAPI_ATTR *PFN_CmdInsertDebugUtilsLabelEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo);
typedef void (VKAPI_ATTR *PFN_CreateDebugUtilsMessengerEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger);
typedef void (VKAPI_ATTR *PFN_DestroyDebugUtilsMessengerEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, format::HandleId messenger, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_SubmitDebugUtilsMessageEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData);
typedef void (VKAPI_ATTR *PFN_GetAndroidHardwareBufferPropertiesANDROID_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint64_t buffer, StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetMemoryAndroidHardwareBufferANDROID_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo, PointerDecoder<uint64_t, void*>* pBuffer);
typedef void (VKAPI_ATTR *PFN_CmdSetSampleLocationsEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceMultisamplePropertiesEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkSampleCountFlagBits samples, StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties);
typedef void (VKAPI_ATTR *PFN_GetImageDrmFormatModifierPropertiesEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties);
typedef void (VKAPI_ATTR *PFN_CreateValidationCacheEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache);
typedef void (VKAPI_ATTR *PFN_DestroyValidationCacheEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId validationCache, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_MergeValidationCachesEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId dstCache, uint32_t srcCacheCount, HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches);
typedef void (VKAPI_ATTR *PFN_GetValidationCacheDataEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId validationCache, PointerDecoder<size_t>* pDataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_CmdBindShadingRateImageNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId imageView, VkImageLayout imageLayout);
typedef void (VKAPI_ATTR *PFN_CmdSetViewportShadingRatePaletteNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes);
typedef void (VKAPI_ATTR *PFN_CmdSetCoarseSampleOrderNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders);
typedef void (VKAPI_ATTR *PFN_CreateAccelerationStructureNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure);
typedef void (VKAPI_ATTR *PFN_DestroyAccelerationStructureNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId accelerationStructure, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_GetAccelerationStructureMemoryRequirementsNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_BindAccelerationStructureMemoryNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos);
typedef void (VKAPI_ATTR *PFN_CmdBuildAccelerationStructureNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV>* pInfo, format::HandleId instanceData, VkDeviceSize instanceOffset, VkBool32 update, format::HandleId dst, format::HandleId src, format::HandleId scratch, VkDeviceSize scratchOffset);
typedef void (VKAPI_ATTR *PFN_CmdCopyAccelerationStructureNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId dst, format::HandleId src, VkCopyAccelerationStructureModeKHR mode);
typedef void (VKAPI_ATTR *PFN_CmdTraceRaysNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, format::HandleId missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, format::HandleId hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, format::HandleId callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth);
typedef void (VKAPI_ATTR *PFN_CreateRayTracingPipelinesNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines);
typedef void (VKAPI_ATTR *PFN_GetRayTracingShaderGroupHandlesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_GetRayTracingShaderGroupHandlesNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_GetAccelerationStructureHandleNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId accelerationStructure, size_t dataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_CmdWriteAccelerationStructuresPropertiesNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t accelerationStructureCount, HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures, VkQueryType queryType, format::HandleId queryPool, uint32_t firstQuery);
typedef void (VKAPI_ATTR *PFN_CompileDeferredNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t shader);
typedef void (VKAPI_ATTR *PFN_GetMemoryHostPointerPropertiesEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, uint64_t pHostPointer, StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties);
typedef void (VKAPI_ATTR *PFN_CmdWriteBufferMarkerAMD_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlagBits pipelineStage, format::HandleId dstBuffer, VkDeviceSize dstOffset, uint32_t marker);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pTimeDomainCount, PointerDecoder<VkTimeDomainEXT>* pTimeDomains);
typedef void (VKAPI_ATTR *PFN_GetCalibratedTimestampsEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t timestampCount, StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>* pTimestampInfos, PointerDecoder<uint64_t>* pTimestamps, PointerDecoder<uint64_t>* pMaxDeviation);
typedef void (VKAPI_ATTR *PFN_CmdDrawMeshTasksNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t taskCount, uint32_t firstTask);
typedef void (VKAPI_ATTR *PFN_CmdDrawMeshTasksIndirectNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawMeshTasksIndirectCountNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdSetExclusiveScissorEnableNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, PointerDecoder<VkBool32>* pExclusiveScissorEnables);
typedef void (VKAPI_ATTR *PFN_CmdSetExclusiveScissorNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, StructPointerDecoder<Decoded_VkRect2D>* pExclusiveScissors);
typedef void (VKAPI_ATTR *PFN_CmdSetCheckpointNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint64_t pCheckpointMarker);
typedef void (VKAPI_ATTR *PFN_GetQueueCheckpointDataNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, PointerDecoder<uint32_t>* pCheckpointDataCount, StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData);
typedef void (VKAPI_ATTR *PFN_InitializePerformanceApiINTEL_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo);
typedef void (VKAPI_ATTR *PFN_UninitializePerformanceApiINTEL_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device);
typedef void (VKAPI_ATTR *PFN_CmdSetPerformanceMarkerINTEL_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo);
typedef void (VKAPI_ATTR *PFN_CmdSetPerformanceStreamMarkerINTEL_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo);
typedef void (VKAPI_ATTR *PFN_CmdSetPerformanceOverrideINTEL_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo);
typedef void (VKAPI_ATTR *PFN_AcquirePerformanceConfigurationINTEL_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo, HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration);
typedef void (VKAPI_ATTR *PFN_ReleasePerformanceConfigurationINTEL_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId configuration);
typedef void (VKAPI_ATTR *PFN_QueueSetPerformanceConfigurationINTEL_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, format::HandleId configuration);
typedef void (VKAPI_ATTR *PFN_GetPerformanceParameterINTEL_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkPerformanceParameterTypeINTEL parameter, StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue);
typedef void (VKAPI_ATTR *PFN_SetLocalDimmingAMD_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId swapChain, VkBool32 localDimmingEnable);
typedef void (VKAPI_ATTR *PFN_CreateImagePipeSurfaceFUCHSIA_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_CreateMetalSurfaceEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetBufferDeviceAddressEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceToolPropertiesEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pToolCount, StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pCombinationCount, StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceSurfacePresentModes2EXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, PointerDecoder<uint32_t>* pPresentModeCount, PointerDecoder<VkPresentModeKHR>* pPresentModes);
typedef void (VKAPI_ATTR *PFN_AcquireFullScreenExclusiveModeEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain);
typedef void (VKAPI_ATTR *PFN_ReleaseFullScreenExclusiveModeEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain);
typedef void (VKAPI_ATTR *PFN_GetDeviceGroupSurfacePresentModes2EXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes);
typedef void (VKAPI_ATTR *PFN_CreateHeadlessSurfaceEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_CmdSetLineStippleEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);
typedef void (VKAPI_ATTR *PFN_ResetQueryPoolEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_ATTR *PFN_CmdSetCullModeEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCullModeFlags cullMode);
typedef void (VKAPI_ATTR *PFN_CmdSetFrontFaceEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkFrontFace frontFace);
typedef void (VKAPI_ATTR *PFN_CmdSetPrimitiveTopologyEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPrimitiveTopology primitiveTopology);
typedef void (VKAPI_ATTR *PFN_CmdSetViewportWithCountEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewport>* pViewports);
typedef void (VKAPI_ATTR *PFN_CmdSetScissorWithCountEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t scissorCount, StructPointerDecoder<Decoded_VkRect2D>* pScissors);
typedef void (VKAPI_ATTR *PFN_CmdBindVertexBuffers2EXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets, PointerDecoder<VkDeviceSize>* pSizes, PointerDecoder<VkDeviceSize>* pStrides);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthTestEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthWriteEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthWriteEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthCompareOpEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCompareOp depthCompareOp);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthBoundsTestEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBoundsTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilTestEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 stencilTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetStencilOpEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
typedef void (VKAPI_ATTR *PFN_ReleaseSwapchainImagesEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo);
typedef void (VKAPI_ATTR *PFN_GetGeneratedCommandsMemoryRequirementsNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements);
typedef void (VKAPI_ATTR *PFN_CmdPostprocessGeneratedCommandsNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo);
typedef void (VKAPI_ATTR *PFN_CmdExecuteGeneratedCommandsNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 isPostprocessed, StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo);
typedef void (VKAPI_ATTR *PFN_CmdBindPipelineShaderGroupNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId pipeline, uint32_t groupIndex);
typedef void (VKAPI_ATTR *PFN_CreateIndirectCommandsLayoutNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout);
typedef void (VKAPI_ATTR *PFN_DestroyIndirectCommandsLayoutNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId indirectCommandsLayout, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_AcquireDrmDisplayEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, int32_t drmFd, format::HandleId display);
typedef void (VKAPI_ATTR *PFN_GetDrmDisplayEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, int32_t drmFd, uint32_t connectorId, HandlePointerDecoder<VkDisplayKHR>* display);
typedef void (VKAPI_ATTR *PFN_CreatePrivateDataSlotEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPrivateDataSlot>* pPrivateDataSlot);
typedef void (VKAPI_ATTR *PFN_DestroyPrivateDataSlotEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId privateDataSlot, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_SetPrivateDataEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, uint64_t data);
typedef void (VKAPI_ATTR *PFN_GetPrivateDataEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, PointerDecoder<uint64_t>* pData);
typedef void (VKAPI_ATTR *PFN_CmdSetFragmentShadingRateEnumNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkFragmentShadingRateNV shadingRate, PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps);
typedef void (VKAPI_ATTR *PFN_GetImageSubresourceLayout2EXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkImageSubresource2EXT>* pSubresource, StructPointerDecoder<Decoded_VkSubresourceLayout2EXT>* pLayout);
typedef void (VKAPI_ATTR *PFN_GetDeviceFaultInfoEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT>* pFaultCounts, StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT>* pFaultInfo);
typedef void (VKAPI_ATTR *PFN_AcquireWinrtDisplayNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display);
typedef void (VKAPI_ATTR *PFN_GetWinrtDisplayNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t deviceRelativeId, HandlePointerDecoder<VkDisplayKHR>* pDisplay);
typedef void (VKAPI_ATTR *PFN_CreateDirectFBSurfaceEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t dfb);
typedef void (VKAPI_ATTR *PFN_CmdSetVertexInputEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t vertexBindingDescriptionCount, StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions);
typedef void (VKAPI_ATTR *PFN_GetMemoryZirconHandleFUCHSIA_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo, PointerDecoder<uint32_t>* pZirconHandle);
typedef void (VKAPI_ATTR *PFN_GetMemoryZirconHandlePropertiesFUCHSIA_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, uint32_t zirconHandle, StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA>* pMemoryZirconHandleProperties);
typedef void (VKAPI_ATTR *PFN_ImportSemaphoreZirconHandleFUCHSIA_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo);
typedef void (VKAPI_ATTR *PFN_GetSemaphoreZirconHandleFUCHSIA_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo, PointerDecoder<uint32_t>* pZirconHandle);
typedef void (VKAPI_ATTR *PFN_CmdBindInvocationMaskHUAWEI_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId imageView, VkImageLayout imageLayout);
typedef void (VKAPI_ATTR *PFN_GetMemoryRemoteAddressNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo, PointerDecoder<uint64_t, void*>* pAddress);
typedef void (VKAPI_ATTR *PFN_CmdSetPatchControlPointsEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t patchControlPoints);
typedef void (VKAPI_ATTR *PFN_CmdSetRasterizerDiscardEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 rasterizerDiscardEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthBiasEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBiasEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetLogicOpEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkLogicOp logicOp);
typedef void (VKAPI_ATTR *PFN_CmdSetPrimitiveRestartEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 primitiveRestartEnable);
typedef void (VKAPI_ATTR *PFN_CreateScreenSurfaceQNX_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceScreenPresentationSupportQNX_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t window);
typedef void (VKAPI_ATTR *PFN_CmdSetColorWriteEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t attachmentCount, PointerDecoder<VkBool32>* pColorWriteEnables);
typedef void (VKAPI_ATTR *PFN_CmdDrawMultiEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t drawCount, StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawMultiIndexedEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t drawCount, StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, PointerDecoder<int32_t>* pVertexOffset);
typedef void (VKAPI_ATTR *PFN_CreateMicromapEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkMicromapEXT>* pMicromap);
typedef void (VKAPI_ATTR *PFN_DestroyMicromapEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId micromap, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CmdBuildMicromapsEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t infoCount, StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos);
typedef void (VKAPI_ATTR *PFN_BuildMicromapsEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, uint32_t infoCount, StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos);
typedef void (VKAPI_ATTR *PFN_CopyMicromapEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo);
typedef void (VKAPI_ATTR *PFN_CopyMicromapToMemoryEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo);
typedef void (VKAPI_ATTR *PFN_CopyMemoryToMicromapEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo);
typedef void (VKAPI_ATTR *PFN_WriteMicromapsPropertiesEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t micromapCount, HandlePointerDecoder<VkMicromapEXT>* pMicromaps, VkQueryType queryType, size_t dataSize, PointerDecoder<uint8_t>* pData, size_t stride);
typedef void (VKAPI_ATTR *PFN_CmdCopyMicromapEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyMicromapToMemoryEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyMemoryToMicromapEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo);
typedef void (VKAPI_ATTR *PFN_CmdWriteMicromapsPropertiesEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t micromapCount, HandlePointerDecoder<VkMicromapEXT>* pMicromaps, VkQueryType queryType, format::HandleId queryPool, uint32_t firstQuery);
typedef void (VKAPI_ATTR *PFN_GetDeviceMicromapCompatibilityEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo, PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility);
typedef void (VKAPI_ATTR *PFN_GetMicromapBuildSizesEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkAccelerationStructureBuildTypeKHR buildType, StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pBuildInfo, StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT>* pSizeInfo);
typedef void (VKAPI_ATTR *PFN_CmdDrawClusterHUAWEI_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_ATTR *PFN_CmdDrawClusterIndirectHUAWEI_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset);
typedef void (VKAPI_ATTR *PFN_SetDeviceMemoryPriorityEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory, float priority);
typedef void (VKAPI_ATTR *PFN_GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference, StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping);
typedef void (VKAPI_ATTR *PFN_GetDescriptorSetHostMappingVALVE_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorSet, PointerDecoder<uint64_t, void*>* ppData);
typedef void (VKAPI_ATTR *PFN_CmdSetTessellationDomainOriginEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkTessellationDomainOrigin domainOrigin);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthClampEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthClampEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetPolygonModeEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPolygonMode polygonMode);
typedef void (VKAPI_ATTR *PFN_CmdSetRasterizationSamplesEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkSampleCountFlagBits rasterizationSamples);
typedef void (VKAPI_ATTR *PFN_CmdSetSampleMaskEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkSampleCountFlagBits samples, PointerDecoder<VkSampleMask>* pSampleMask);
typedef void (VKAPI_ATTR *PFN_CmdSetAlphaToCoverageEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 alphaToCoverageEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetAlphaToOneEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 alphaToOneEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetLogicOpEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 logicOpEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetColorBlendEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, PointerDecoder<VkBool32>* pColorBlendEnables);
typedef void (VKAPI_ATTR *PFN_CmdSetColorBlendEquationEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations);
typedef void (VKAPI_ATTR *PFN_CmdSetColorWriteMaskEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, PointerDecoder<VkColorComponentFlags>* pColorWriteMasks);
typedef void (VKAPI_ATTR *PFN_CmdSetRasterizationStreamEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t rasterizationStream);
typedef void (VKAPI_ATTR *PFN_CmdSetConservativeRasterizationModeEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode);
typedef void (VKAPI_ATTR *PFN_CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float extraPrimitiveOverestimationSize);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthClipEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthClipEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetSampleLocationsEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 sampleLocationsEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetColorBlendAdvancedEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced);
typedef void (VKAPI_ATTR *PFN_CmdSetProvokingVertexModeEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkProvokingVertexModeEXT provokingVertexMode);
typedef void (VKAPI_ATTR *PFN_CmdSetLineRasterizationModeEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode);
typedef void (VKAPI_ATTR *PFN_CmdSetLineStippleEnableEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 stippledLineEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetDepthClipNegativeOneToOneEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 negativeOneToOne);
typedef void (VKAPI_ATTR *PFN_CmdSetViewportWScalingEnableNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 viewportWScalingEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetViewportSwizzleNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles);
typedef void (VKAPI_ATTR *PFN_CmdSetCoverageToColorEnableNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 coverageToColorEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetCoverageToColorLocationNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t coverageToColorLocation);
typedef void (VKAPI_ATTR *PFN_CmdSetCoverageModulationModeNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCoverageModulationModeNV coverageModulationMode);
typedef void (VKAPI_ATTR *PFN_CmdSetCoverageModulationTableEnableNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 coverageModulationTableEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetCoverageModulationTableNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t coverageModulationTableCount, PointerDecoder<float>* pCoverageModulationTable);
typedef void (VKAPI_ATTR *PFN_CmdSetShadingRateImageEnableNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 shadingRateImageEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetRepresentativeFragmentTestEnableNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 representativeFragmentTestEnable);
typedef void (VKAPI_ATTR *PFN_CmdSetCoverageReductionModeNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCoverageReductionModeNV coverageReductionMode);
typedef void (VKAPI_ATTR *PFN_GetShaderModuleIdentifierEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId shaderModule, StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier);
typedef void (VKAPI_ATTR *PFN_GetShaderModuleCreateInfoIdentifierEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier);
typedef void (VKAPI_ATTR *PFN_GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV>* pOpticalFlowImageFormatInfo, PointerDecoder<uint32_t>* pFormatCount, StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV>* pImageFormatProperties);
typedef void (VKAPI_ATTR *PFN_CreateOpticalFlowSessionNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession);
typedef void (VKAPI_ATTR *PFN_DestroyOpticalFlowSessionNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId session, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_BindOpticalFlowSessionImageNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId session, VkOpticalFlowSessionBindingPointNV bindingPoint, format::HandleId view, VkImageLayout layout);
typedef void (VKAPI_ATTR *PFN_CmdOpticalFlowExecuteNV_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId session, StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo);
typedef void (VKAPI_ATTR *PFN_GetFramebufferTilePropertiesQCOM_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId framebuffer, PointerDecoder<uint32_t>* pPropertiesCount, StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties);
typedef void (VKAPI_ATTR *PFN_GetDynamicRenderingTilePropertiesQCOM_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo, StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties);
typedef void (VKAPI_ATTR *PFN_CreateAccelerationStructureKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure);
typedef void (VKAPI_ATTR *PFN_DestroyAccelerationStructureKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId accelerationStructure, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);
typedef void (VKAPI_ATTR *PFN_CmdBuildAccelerationStructuresKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t infoCount, StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos, StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos);
typedef void (VKAPI_ATTR *PFN_CmdBuildAccelerationStructuresIndirectKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t infoCount, StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos, PointerDecoder<VkDeviceAddress>* pIndirectDeviceAddresses, PointerDecoder<uint32_t>* pIndirectStrides, PointerDecoder<uint32_t*>* ppMaxPrimitiveCounts);
typedef void (VKAPI_ATTR *PFN_CopyAccelerationStructureToMemoryKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_CopyMemoryToAccelerationStructureKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_WriteAccelerationStructuresPropertiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t accelerationStructureCount, HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures, VkQueryType queryType, size_t dataSize, PointerDecoder<uint8_t>* pData, size_t stride);
typedef void (VKAPI_ATTR *PFN_CmdCopyAccelerationStructureKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyAccelerationStructureToMemoryKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_CmdCopyMemoryToAccelerationStructureKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_GetAccelerationStructureDeviceAddressKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo);
typedef void (VKAPI_ATTR *PFN_CmdWriteAccelerationStructuresPropertiesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t accelerationStructureCount, HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures, VkQueryType queryType, format::HandleId queryPool, uint32_t firstQuery);
typedef void (VKAPI_ATTR *PFN_GetDeviceAccelerationStructureCompatibilityKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo, PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility);
typedef void (VKAPI_ATTR *PFN_GetAccelerationStructureBuildSizesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkAccelerationStructureBuildTypeKHR buildType, StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo, PointerDecoder<uint32_t>* pMaxPrimitiveCounts, StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>* pSizeInfo);
typedef void (VKAPI_ATTR *PFN_CmdTraceRaysKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth);
typedef void (VKAPI_ATTR *PFN_CreateRayTracingPipelinesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines);
typedef void (VKAPI_ATTR *PFN_GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, PointerDecoder<uint8_t>* pData);
typedef void (VKAPI_ATTR *PFN_CmdTraceRaysIndirectKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress);
typedef void (VKAPI_ATTR *PFN_GetRayTracingShaderGroupStackSizeKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceSize returnValue, format::HandleId device, format::HandleId pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader);
typedef void (VKAPI_ATTR *PFN_CmdSetRayTracingPipelineStackSizeKHR_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t pipelineStackSize);
typedef void (VKAPI_ATTR *PFN_CmdDrawMeshTasksEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_ATTR *PFN_CmdDrawMeshTasksIndirectEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_ATTR *PFN_CmdDrawMeshTasksIndirectCountEXT_PostCall)(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
// clang-format on

GFXRECON_BEGIN_NAMESPACE(noop)

// clang-format off
static VKAPI_ATTR void VKAPI_CALL CreateInstance_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkInstance>* pInstance) { }
static VKAPI_ATTR void VKAPI_CALL DestroyInstance_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDevices_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, PointerDecoder<uint32_t>* pPhysicalDeviceCount, HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pQueueFamilyPropertyCount, StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateDevice_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDevice>* pDevice) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDevice_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceQueue_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t queueFamilyIndex, uint32_t queueIndex, HandlePointerDecoder<VkQueue>* pQueue) { }
static VKAPI_ATTR void VKAPI_CALL QueueSubmit_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t submitCount, StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits, format::HandleId fence) { }
static VKAPI_ATTR void VKAPI_CALL QueueWaitIdle_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue) { }
static VKAPI_ATTR void VKAPI_CALL DeviceWaitIdle_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device) { }
static VKAPI_ATTR void VKAPI_CALL AllocateMemory_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDeviceMemory>* pMemory) { }
static VKAPI_ATTR void VKAPI_CALL FreeMemory_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL MapMemory_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, PointerDecoder<uint64_t, void*>* ppData) { }
static VKAPI_ATTR void VKAPI_CALL UnmapMemory_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory) { }
static VKAPI_ATTR void VKAPI_CALL FlushMappedMemoryRanges_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t memoryRangeCount, StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges) { }
static VKAPI_ATTR void VKAPI_CALL InvalidateMappedMemoryRanges_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t memoryRangeCount, StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory, PointerDecoder<VkDeviceSize>* pCommittedMemoryInBytes) { }
static VKAPI_ATTR void VKAPI_CALL BindBufferMemory_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId buffer, format::HandleId memory, VkDeviceSize memoryOffset) { }
static VKAPI_ATTR void VKAPI_CALL BindImageMemory_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId image, format::HandleId memory, VkDeviceSize memoryOffset) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId buffer, StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL QueueBindSparse_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo, format::HandleId fence) { }
static VKAPI_ATTR void VKAPI_CALL CreateFence_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFence>* pFence) { }
static VKAPI_ATTR void VKAPI_CALL DestroyFence_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId fence, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL ResetFences_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t fenceCount, HandlePointerDecoder<VkFence>* pFences) { }
static VKAPI_ATTR void VKAPI_CALL GetFenceStatus_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId fence) { }
static VKAPI_ATTR void VKAPI_CALL WaitForFences_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t fenceCount, HandlePointerDecoder<VkFence>* pFences, VkBool32 waitAll, uint64_t timeout) { }
static VKAPI_ATTR void VKAPI_CALL CreateSemaphore_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSemaphore>* pSemaphore) { }
static VKAPI_ATTR void VKAPI_CALL DestroySemaphore_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId semaphore, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateEvent_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkEvent>* pEvent) { }
static VKAPI_ATTR void VKAPI_CALL DestroyEvent_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId event, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetEventStatus_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId event) { }
static VKAPI_ATTR void VKAPI_CALL SetEvent_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId event) { }
static VKAPI_ATTR void VKAPI_CALL ResetEvent_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId event) { }
static VKAPI_ATTR void VKAPI_CALL CreateQueryPool_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkQueryPool>* pQueryPool) { }
static VKAPI_ATTR void VKAPI_CALL DestroyQueryPool_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId queryPool, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetQueryPoolResults_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, PointerDecoder<uint8_t>* pData, VkDeviceSize stride, VkQueryResultFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL CreateBuffer_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkBuffer>* pBuffer) { }
static VKAPI_ATTR void VKAPI_CALL DestroyBuffer_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId buffer, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateBufferView_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkBufferView>* pView) { }
static VKAPI_ATTR void VKAPI_CALL DestroyBufferView_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId bufferView, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateImage_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkImage>* pImage) { }
static VKAPI_ATTR void VKAPI_CALL DestroyImage_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource, StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout) { }
static VKAPI_ATTR void VKAPI_CALL CreateImageView_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkImageView>* pView) { }
static VKAPI_ATTR void VKAPI_CALL DestroyImageView_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId imageView, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateShaderModule_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkShaderModule>* pShaderModule) { }
static VKAPI_ATTR void VKAPI_CALL DestroyShaderModule_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId shaderModule, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreatePipelineCache_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipelineCache>* pPipelineCache) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId pipelineCache, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetPipelineCacheData_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, PointerDecoder<size_t>* pDataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL MergePipelineCaches_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId dstCache, uint32_t srcCacheCount, HandlePointerDecoder<VkPipelineCache>* pSrcCaches) { }
static VKAPI_ATTR void VKAPI_CALL CreateGraphicsPipelines_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines) { }
static VKAPI_ATTR void VKAPI_CALL CreateComputePipelines_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPipeline_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId pipeline, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreatePipelineLayout_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipelineLayout>* pPipelineLayout) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId pipelineLayout, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateSampler_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSampler>* pSampler) { }
static VKAPI_ATTR void VKAPI_CALL DestroySampler_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId sampler, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateDescriptorSetLayout_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorSetLayout, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateDescriptorPool_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorPool>* pDescriptorPool) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorPool, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL ResetDescriptorPool_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId descriptorPool, VkDescriptorPoolResetFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL AllocateDescriptorSets_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo, HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) { }
static VKAPI_ATTR void VKAPI_CALL FreeDescriptorSets_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId descriptorPool, uint32_t descriptorSetCount, HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) { }
static VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t descriptorWriteCount, StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites, uint32_t descriptorCopyCount, StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies) { }
static VKAPI_ATTR void VKAPI_CALL CreateFramebuffer_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFramebuffer>* pFramebuffer) { }
static VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId framebuffer, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateRenderPass_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkRenderPass>* pRenderPass) { }
static VKAPI_ATTR void VKAPI_CALL DestroyRenderPass_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId renderPass, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId renderPass, StructPointerDecoder<Decoded_VkExtent2D>* pGranularity) { }
static VKAPI_ATTR void VKAPI_CALL CreateCommandPool_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkCommandPool>* pCommandPool) { }
static VKAPI_ATTR void VKAPI_CALL DestroyCommandPool_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL ResetCommandPool_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId commandPool, VkCommandPoolResetFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL AllocateCommandBuffers_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo, HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) { }
static VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, uint32_t commandBufferCount, HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) { }
static VKAPI_ATTR void VKAPI_CALL BeginCommandBuffer_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) { }
static VKAPI_ATTR void VKAPI_CALL EndCommandBuffer_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL ResetCommandBuffer_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, VkCommandBufferResetFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindPipeline_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId pipeline) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewport_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewport>* pViewports) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissor_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstScissor, uint32_t scissorCount, StructPointerDecoder<Decoded_VkRect2D>* pScissors) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float lineWidth) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, PointerDecoder<float>* blendConstants) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float minDepthBounds, float maxDepthBounds) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId layout, uint32_t firstSet, uint32_t descriptorSetCount, HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets, uint32_t dynamicOffsetCount, PointerDecoder<uint32_t>* pDynamicOffsets) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, VkIndexType indexType) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets) { }
static VKAPI_ATTR void VKAPI_CALL CmdDraw_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDispatch_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcBuffer, format::HandleId dstBuffer, uint32_t regionCount, StructPointerDecoder<Decoded_VkBufferCopy>* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkImageCopy>* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkImageBlit>* pRegions, VkFilter filter) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcBuffer, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstBuffer, uint32_t regionCount, StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdFillBuffer_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) { }
static VKAPI_ATTR void VKAPI_CALL CmdClearColorImage_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId image, VkImageLayout imageLayout, StructPointerDecoder<Decoded_VkClearColorValue>* pColor, uint32_t rangeCount, StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges) { }
static VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId image, VkImageLayout imageLayout, StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil, uint32_t rangeCount, StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges) { }
static VKAPI_ATTR void VKAPI_CALL CmdClearAttachments_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t attachmentCount, StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments, uint32_t rectCount, StructPointerDecoder<Decoded_VkClearRect>* pRects) { }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId srcImage, VkImageLayout srcImageLayout, format::HandleId dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, StructPointerDecoder<Decoded_VkImageResolve>* pRegions) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags stageMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags stageMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t eventCount, HandlePointerDecoder<VkEvent>* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers) { }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginQuery_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query, VkQueryControlFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndQuery_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query) { }
static VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlagBits pipelineStage, format::HandleId queryPool, uint32_t query) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount, format::HandleId dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL CmdPushConstants_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, PointerDecoder<uint8_t>* pValues) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin, VkSubpassContents contents) { }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkSubpassContents contents) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t commandBufferCount, HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) { }
static VKAPI_ATTR void VKAPI_CALL BindBufferMemory2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL BindImageMemory2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, PointerDecoder<VkPeerMemoryFeatureFlags>* pPeerMemoryFeatures) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t deviceMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchBase_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceGroups_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, PointerDecoder<uint32_t>* pPhysicalDeviceGroupCount, StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo, StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pQueueFamilyPropertyCount, StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL TrimCommandPool_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, VkCommandPoolTrimFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo, HandlePointerDecoder<VkQueue>* pQueue) { }
static VKAPI_ATTR void VKAPI_CALL CreateSamplerYcbcrConversion_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion) { }
static VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId ycbcrConversion, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateDescriptorUpdateTemplate_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorUpdateTemplate, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo, StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo, StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo, StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CreateRenderPass2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkRenderPass>* pRenderPass) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) { }
static VKAPI_ATTR void VKAPI_CALL ResetQueryPool_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreCounterValue_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId semaphore, PointerDecoder<uint64_t>* pValue) { }
static VKAPI_ATTR void VKAPI_CALL WaitSemaphores_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo, uint64_t timeout) { }
static VKAPI_ATTR void VKAPI_CALL SignalSemaphore_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddress_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferOpaqueCaptureAddress_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceToolProperties_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pToolCount, StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreatePrivateDataSlot_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPrivateDataSlot>* pPrivateDataSlot) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId privateDataSlot, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL SetPrivateData_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, uint64_t data) { }
static VKAPI_ATTR void VKAPI_CALL GetPrivateData_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, PointerDecoder<uint64_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags2 stageMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t eventCount, HandlePointerDecoder<VkEvent>* pEvents, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos) { }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags2 stage, format::HandleId queryPool, uint32_t query) { }
static VKAPI_ATTR void VKAPI_CALL QueueSubmit2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t submitCount, StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits, format::HandleId fence) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRendering_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRendering_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCullMode_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCullModeFlags cullMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkFrontFace frontFace) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPrimitiveTopology primitiveTopology) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewport>* pViewports) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t scissorCount, StructPointerDecoder<Decoded_VkRect2D>* pScissors) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets, PointerDecoder<VkDeviceSize>* pSizes, PointerDecoder<VkDeviceSize>* pStrides) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthWriteEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCompareOp depthCompareOp) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBoundsTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 stencilTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 rasterizerDiscardEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBiasEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 primitiveRestartEnable) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirements_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirements_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, format::HandleId surface, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, format::HandleId surface, PointerDecoder<VkBool32>* pSupported) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, PointerDecoder<uint32_t>* pSurfaceFormatCount, StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, PointerDecoder<uint32_t>* pPresentModeCount, PointerDecoder<VkPresentModeKHR>* pPresentModes) { }
static VKAPI_ATTR void VKAPI_CALL CreateSwapchainKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSwapchainKHR>* pSwapchain) { }
static VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId swapchain, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetSwapchainImagesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, PointerDecoder<uint32_t>* pSwapchainImageCount, HandlePointerDecoder<VkImage>* pSwapchainImages) { }
static VKAPI_ATTR void VKAPI_CALL AcquireNextImageKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, uint64_t timeout, format::HandleId semaphore, format::HandleId fence, PointerDecoder<uint32_t>* pImageIndex) { }
static VKAPI_ATTR void VKAPI_CALL QueuePresentKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId surface, PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, PointerDecoder<uint32_t>* pRectCount, StructPointerDecoder<Decoded_VkRect2D>* pRects) { }
static VKAPI_ATTR void VKAPI_CALL AcquireNextImage2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo, PointerDecoder<uint32_t>* pImageIndex) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t planeIndex, PointerDecoder<uint32_t>* pDisplayCount, HandlePointerDecoder<VkDisplayKHR>* pDisplays) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayModePropertiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateDisplayModeKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display, StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDisplayModeKHR>* pMode) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneCapabilitiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId mode, uint32_t planeIndex, StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL CreateDisplayPlaneSurfaceKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CreateSharedSwapchainsKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t swapchainCount, StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSwapchainKHR>* pSwapchains) { }
static VKAPI_ATTR void VKAPI_CALL CreateXlibSurfaceKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t dpy, size_t visualID) { }
static VKAPI_ATTR void VKAPI_CALL CreateXcbSurfaceKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t connection, uint32_t visual_id) { }
static VKAPI_ATTR void VKAPI_CALL CreateWaylandSurfaceKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t display) { }
static VKAPI_ATTR void VKAPI_CALL CreateAndroidSurfaceKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CreateWin32SurfaceKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceVideoCapabilitiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile, StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR>* pCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR>* pVideoFormatInfo, PointerDecoder<uint32_t>* pVideoFormatPropertyCount, StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR>* pVideoFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateVideoSessionKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkVideoSessionKHR>* pVideoSession) { }
static VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId videoSession, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetVideoSessionMemoryRequirementsKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId videoSession, PointerDecoder<uint32_t>* pMemoryRequirementsCount, StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL BindVideoSessionMemoryKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId videoSession, uint32_t bindSessionMemoryInfoCount, StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos) { }
static VKAPI_ATTR void VKAPI_CALL CreateVideoSessionParametersKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkVideoSessionParametersKHR>* pVideoSessionParameters) { }
static VKAPI_ATTR void VKAPI_CALL UpdateVideoSessionParametersKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId videoSessionParameters, StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR>* pUpdateInfo) { }
static VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionParametersKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId videoSessionParameters, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginVideoCodingKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndVideoCodingKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdControlVideoCodingKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdDecodeVideoKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderingKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderingKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkFormat format, StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo, StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pQueueFamilyPropertyCount, StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, PointerDecoder<VkPeerMemoryFeatureFlags>* pPeerMemoryFeatures) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t deviceMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdDispatchBaseKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId commandPool, VkCommandPoolTrimFlags flags) { }
static VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, PointerDecoder<uint32_t>* pPhysicalDeviceGroupCount, StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo, StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandleKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo, PointerDecoder<uint64_t, void*>* pHandle) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandlePropertiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, uint64_t handle, StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryFdKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo, PointerDecoder<int>* pFd) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryFdPropertiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo, StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties) { }
static VKAPI_ATTR void VKAPI_CALL ImportSemaphoreWin32HandleKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreWin32HandleKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo, PointerDecoder<uint64_t, void*>* pHandle) { }
static VKAPI_ATTR void VKAPI_CALL ImportSemaphoreFdKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreFdKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo, PointerDecoder<int>* pFd) { }
static VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId layout, uint32_t set, uint32_t descriptorWriteCount, StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites) { }
static VKAPI_ATTR void VKAPI_CALL CreateDescriptorUpdateTemplateKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorUpdateTemplate, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CreateRenderPass2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkRenderPass>* pRenderPass) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetSwapchainStatusKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo, StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties) { }
static VKAPI_ATTR void VKAPI_CALL ImportFenceWin32HandleKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetFenceWin32HandleKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo, PointerDecoder<uint64_t, void*>* pHandle) { }
static VKAPI_ATTR void VKAPI_CALL ImportFenceFdKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetFenceFdKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo, PointerDecoder<int>* pFd) { }
static VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, PointerDecoder<uint32_t>* pCounterCount, StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters, StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo, PointerDecoder<uint32_t>* pNumPasses) { }
static VKAPI_ATTR void VKAPI_CALL AcquireProfilingLockKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, PointerDecoder<uint32_t>* pSurfaceFormatCount, StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayModeProperties2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneCapabilities2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo, StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL CreateSamplerYcbcrConversionKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion) { }
static VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId ycbcrConversion, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL BindBufferMemory2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL BindImageMemory2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreCounterValueKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId semaphore, PointerDecoder<uint64_t>* pValue) { }
static VKAPI_ATTR void VKAPI_CALL WaitSemaphoresKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo, uint64_t timeout) { }
static VKAPI_ATTR void VKAPI_CALL SignalSemaphoreKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFragmentShadingRatesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pFragmentShadingRateCount, StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkExtent2D>* pFragmentSize, PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps) { }
static VKAPI_ATTR void VKAPI_CALL WaitForPresentKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, uint64_t presentId, uint64_t timeout) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddressKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferOpaqueCaptureAddressKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint64_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CreateDeferredOperationKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDeferredOperationKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId operation, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetDeferredOperationMaxConcurrencyKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint32_t returnValue, format::HandleId device, format::HandleId operation) { }
static VKAPI_ATTR void VKAPI_CALL GetDeferredOperationResultKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId operation) { }
static VKAPI_ATTR void VKAPI_CALL DeferredOperationJoinKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId operation) { }
static VKAPI_ATTR void VKAPI_CALL GetPipelineExecutablePropertiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo, PointerDecoder<uint32_t>* pExecutableCount, StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPipelineExecutableStatisticsKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo, PointerDecoder<uint32_t>* pStatisticCount, StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics) { }
static VKAPI_ATTR void VKAPI_CALL GetPipelineExecutableInternalRepresentationsKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo, PointerDecoder<uint32_t>* pInternalRepresentationCount, StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations) { }
static VKAPI_ATTR void VKAPI_CALL CmdEncodeVideoKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId event, VkPipelineStageFlags2 stageMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t eventCount, HandlePointerDecoder<VkEvent>* pEvents, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos) { }
static VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags2 stage, format::HandleId queryPool, uint32_t query) { }
static VKAPI_ATTR void VKAPI_CALL QueueSubmit2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, uint32_t submitCount, StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits, format::HandleId fence) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarker2AMD_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlags2 stage, format::HandleId dstBuffer, VkDeviceSize dstOffset, uint32_t marker) { }
static VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointData2NV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, PointerDecoder<uint32_t>* pCheckpointDataCount, StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirect2KHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkDeviceAddress indirectDeviceAddress) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirementsKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirementsKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirementsKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo, PointerDecoder<uint32_t>* pSparseMemoryRequirementCount, StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL CreateDebugReportCallbackEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, format::HandleId callback, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL DebugReportMessageEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, StringDecoder* pLayerPostfix, StringDecoder* pMessage) { }
static VKAPI_ATTR void VKAPI_CALL DebugMarkerSetObjectTagEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo) { }
static VKAPI_ATTR void VKAPI_CALL DebugMarkerSetObjectNameEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindTransformFeedbackBuffersEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets, PointerDecoder<VkDeviceSize>* pSizes) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginTransformFeedbackEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, HandlePointerDecoder<VkBuffer>* pCounterBuffers, PointerDecoder<VkDeviceSize>* pCounterBufferOffsets) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndTransformFeedbackEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, HandlePointerDecoder<VkBuffer>* pCounterBuffers, PointerDecoder<VkDeviceSize>* pCounterBufferOffsets) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginQueryIndexedEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndQueryIndexedEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId queryPool, uint32_t query, uint32_t index) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectByteCountEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t instanceCount, uint32_t firstInstance, format::HandleId counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) { }
static VKAPI_ATTR void VKAPI_CALL GetImageViewHandleNVX_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, uint32_t returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetImageViewAddressNVX_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId imageView, StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountAMD_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountAMD_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL GetShaderInfoAMD_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, PointerDecoder<size_t>* pInfoSize, PointerDecoder<uint8_t>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CreateStreamDescriptorSurfaceGGP_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>* pExternalImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandleNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId memory, VkExternalMemoryHandleTypeFlagsNV handleType, PointerDecoder<uint64_t, void*>* pHandle) { }
static VKAPI_ATTR void VKAPI_CALL CreateViSurfaceNN_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings) { }
static VKAPI_ATTR void VKAPI_CALL ReleaseDisplayEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display) { }
static VKAPI_ATTR void VKAPI_CALL AcquireXlibDisplayEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint64_t dpy, format::HandleId display) { }
static VKAPI_ATTR void VKAPI_CALL GetRandROutputDisplayEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint64_t dpy, size_t rrOutput, HandlePointerDecoder<VkDisplayKHR>* pDisplay) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId surface, StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities) { }
static VKAPI_ATTR void VKAPI_CALL DisplayPowerControlEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId display, StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo) { }
static VKAPI_ATTR void VKAPI_CALL RegisterDeviceEventEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFence>* pFence) { }
static VKAPI_ATTR void VKAPI_CALL RegisterDisplayEventEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId display, StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkFence>* pFence) { }
static VKAPI_ATTR void VKAPI_CALL GetSwapchainCounterEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, VkSurfaceCounterFlagBitsEXT counter, PointerDecoder<uint64_t>* pCounterValue) { }
static VKAPI_ATTR void VKAPI_CALL GetRefreshCycleDurationGOOGLE_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPastPresentationTimingGOOGLE_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain, PointerDecoder<uint32_t>* pPresentationTimingCount, StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, StructPointerDecoder<Decoded_VkRect2D>* pDiscardRectangles) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 discardRectangleEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleModeEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode) { }
static VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, uint32_t swapchainCount, HandlePointerDecoder<VkSwapchainKHR>* pSwapchains, StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata) { }
static VKAPI_ATTR void VKAPI_CALL CreateIOSSurfaceMVK_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CreateMacOSSurfaceMVK_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL SetDebugUtilsObjectNameEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo) { }
static VKAPI_ATTR void VKAPI_CALL SetDebugUtilsObjectTagEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo) { }
static VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) { }
static VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue) { }
static VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) { }
static VKAPI_ATTR void VKAPI_CALL CreateDebugUtilsMessengerEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger) { }
static VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, format::HandleId messenger, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData) { }
static VKAPI_ATTR void VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint64_t buffer, StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo, PointerDecoder<uint64_t, void*>* pBuffer) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId physicalDevice, VkSampleCountFlagBits samples, StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateValidationCacheEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache) { }
static VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId validationCache, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL MergeValidationCachesEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId dstCache, uint32_t srcCacheCount, HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches) { }
static VKAPI_ATTR void VKAPI_CALL GetValidationCacheDataEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId validationCache, PointerDecoder<size_t>* pDataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindShadingRateImageNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId imageView, VkImageLayout imageLayout) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportShadingRatePaletteNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoarseSampleOrderNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders) { }
static VKAPI_ATTR void VKAPI_CALL CreateAccelerationStructureNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure) { }
static VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId accelerationStructure, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL BindAccelerationStructureMemoryNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t bindInfoCount, StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos) { }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructureNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV>* pInfo, format::HandleId instanceData, VkDeviceSize instanceOffset, VkBool32 update, format::HandleId dst, format::HandleId src, format::HandleId scratch, VkDeviceSize scratchOffset) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId dst, format::HandleId src, VkCopyAccelerationStructureModeKHR mode) { }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, format::HandleId missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, format::HandleId hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, format::HandleId callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) { }
static VKAPI_ATTR void VKAPI_CALL CreateRayTracingPipelinesNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines) { }
static VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupHandlesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupHandlesNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureHandleNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId accelerationStructure, size_t dataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t accelerationStructureCount, HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures, VkQueryType queryType, format::HandleId queryPool, uint32_t firstQuery) { }
static VKAPI_ATTR void VKAPI_CALL CompileDeferredNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t shader) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryHostPointerPropertiesEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, uint64_t pHostPointer, StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineStageFlagBits pipelineStage, format::HandleId dstBuffer, VkDeviceSize dstOffset, uint32_t marker) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pTimeDomainCount, PointerDecoder<VkTimeDomainEXT>* pTimeDomains) { }
static VKAPI_ATTR void VKAPI_CALL GetCalibratedTimestampsEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t timestampCount, StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>* pTimestampInfos, PointerDecoder<uint64_t>* pTimestamps, PointerDecoder<uint64_t>* pMaxDeviation) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t taskCount, uint32_t firstTask) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorEnableNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, PointerDecoder<VkBool32>* pExclusiveScissorEnables) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, StructPointerDecoder<Decoded_VkRect2D>* pExclusiveScissors) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCheckpointNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint64_t pCheckpointMarker) { }
static VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId queue, PointerDecoder<uint32_t>* pCheckpointDataCount, StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData) { }
static VKAPI_ATTR void VKAPI_CALL InitializePerformanceApiINTEL_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo) { }
static VKAPI_ATTR void VKAPI_CALL UninitializePerformanceApiINTEL_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceMarkerINTEL_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceStreamMarkerINTEL_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceOverrideINTEL_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo) { }
static VKAPI_ATTR void VKAPI_CALL AcquirePerformanceConfigurationINTEL_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo, HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration) { }
static VKAPI_ATTR void VKAPI_CALL ReleasePerformanceConfigurationINTEL_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId configuration) { }
static VKAPI_ATTR void VKAPI_CALL QueueSetPerformanceConfigurationINTEL_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId queue, format::HandleId configuration) { }
static VKAPI_ATTR void VKAPI_CALL GetPerformanceParameterINTEL_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkPerformanceParameterTypeINTEL parameter, StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue) { }
static VKAPI_ATTR void VKAPI_CALL SetLocalDimmingAMD_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId swapChain, VkBool32 localDimmingEnable) { }
static VKAPI_ATTR void VKAPI_CALL CreateImagePipeSurfaceFUCHSIA_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CreateMetalSurfaceEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddressEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pToolCount, StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pPropertyCount, StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, PointerDecoder<uint32_t>* pCombinationCount, StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfacePresentModes2EXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, PointerDecoder<uint32_t>* pPresentModeCount, PointerDecoder<VkPresentModeKHR>* pPresentModes) { }
static VKAPI_ATTR void VKAPI_CALL AcquireFullScreenExclusiveModeEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain) { }
static VKAPI_ATTR void VKAPI_CALL ReleaseFullScreenExclusiveModeEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId swapchain) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceGroupSurfacePresentModes2EXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo, PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes) { }
static VKAPI_ATTR void VKAPI_CALL CreateHeadlessSurfaceEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) { }
static VKAPI_ATTR void VKAPI_CALL ResetQueryPoolEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId queryPool, uint32_t firstQuery, uint32_t queryCount) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCullModeFlags cullMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkFrontFace frontFace) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPrimitiveTopology primitiveTopology) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewport>* pViewports) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t scissorCount, StructPointerDecoder<Decoded_VkRect2D>* pScissors) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstBinding, uint32_t bindingCount, HandlePointerDecoder<VkBuffer>* pBuffers, PointerDecoder<VkDeviceSize>* pOffsets, PointerDecoder<VkDeviceSize>* pSizes, PointerDecoder<VkDeviceSize>* pStrides) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthWriteEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCompareOp depthCompareOp) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBoundsTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 stencilTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) { }
static VKAPI_ATTR void VKAPI_CALL ReleaseSwapchainImagesEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetGeneratedCommandsMemoryRequirementsNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo, StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) { }
static VKAPI_ATTR void VKAPI_CALL CmdPostprocessGeneratedCommandsNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdExecuteGeneratedCommandsNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 isPostprocessed, StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindPipelineShaderGroupNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPipelineBindPoint pipelineBindPoint, format::HandleId pipeline, uint32_t groupIndex) { }
static VKAPI_ATTR void VKAPI_CALL CreateIndirectCommandsLayoutNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout) { }
static VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId indirectCommandsLayout, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL AcquireDrmDisplayEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, int32_t drmFd, format::HandleId display) { }
static VKAPI_ATTR void VKAPI_CALL GetDrmDisplayEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, int32_t drmFd, uint32_t connectorId, HandlePointerDecoder<VkDisplayKHR>* display) { }
static VKAPI_ATTR void VKAPI_CALL CreatePrivateDataSlotEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPrivateDataSlot>* pPrivateDataSlot) { }
static VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlotEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId privateDataSlot, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL SetPrivateDataEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, uint64_t data) { }
static VKAPI_ATTR void VKAPI_CALL GetPrivateDataEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkObjectType objectType, uint64_t objectHandle, format::HandleId privateDataSlot, PointerDecoder<uint64_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateEnumNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkFragmentShadingRateNV shadingRate, PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps) { }
static VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2EXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId image, StructPointerDecoder<Decoded_VkImageSubresource2EXT>* pSubresource, StructPointerDecoder<Decoded_VkSubresourceLayout2EXT>* pLayout) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceFaultInfoEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT>* pFaultCounts, StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT>* pFaultInfo) { }
static VKAPI_ATTR void VKAPI_CALL AcquireWinrtDisplayNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, format::HandleId display) { }
static VKAPI_ATTR void VKAPI_CALL GetWinrtDisplayNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, uint32_t deviceRelativeId, HandlePointerDecoder<VkDisplayKHR>* pDisplay) { }
static VKAPI_ATTR void VKAPI_CALL CreateDirectFBSurfaceEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t dfb) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t vertexBindingDescriptionCount, StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryZirconHandleFUCHSIA_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo, PointerDecoder<uint32_t>* pZirconHandle) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryZirconHandlePropertiesFUCHSIA_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, VkExternalMemoryHandleTypeFlagBits handleType, uint32_t zirconHandle, StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA>* pMemoryZirconHandleProperties) { }
static VKAPI_ATTR void VKAPI_CALL ImportSemaphoreZirconHandleFUCHSIA_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetSemaphoreZirconHandleFUCHSIA_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo, PointerDecoder<uint32_t>* pZirconHandle) { }
static VKAPI_ATTR void VKAPI_CALL CmdBindInvocationMaskHUAWEI_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId imageView, VkImageLayout imageLayout) { }
static VKAPI_ATTR void VKAPI_CALL GetMemoryRemoteAddressNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo, PointerDecoder<uint64_t, void*>* pAddress) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t patchControlPoints) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 rasterizerDiscardEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthBiasEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkLogicOp logicOp) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 primitiveRestartEnable) { }
static VKAPI_ATTR void VKAPI_CALL CreateScreenSurfaceQNX_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId instance, StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkSurfaceKHR>* pSurface) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceScreenPresentationSupportQNX_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkBool32 returnValue, format::HandleId physicalDevice, uint32_t queueFamilyIndex, uint64_t window) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t attachmentCount, PointerDecoder<VkBool32>* pColorWriteEnables) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMultiEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t drawCount, StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMultiIndexedEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t drawCount, StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, PointerDecoder<int32_t>* pVertexOffset) { }
static VKAPI_ATTR void VKAPI_CALL CreateMicromapEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkMicromapEXT>* pMicromap) { }
static VKAPI_ATTR void VKAPI_CALL DestroyMicromapEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId micromap, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CmdBuildMicromapsEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t infoCount, StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos) { }
static VKAPI_ATTR void VKAPI_CALL BuildMicromapsEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, uint32_t infoCount, StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos) { }
static VKAPI_ATTR void VKAPI_CALL CopyMicromapEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CopyMicromapToMemoryEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CopyMemoryToMicromapEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL WriteMicromapsPropertiesEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t micromapCount, HandlePointerDecoder<VkMicromapEXT>* pMicromaps, VkQueryType queryType, size_t dataSize, PointerDecoder<uint8_t>* pData, size_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapToMemoryEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToMicromapEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteMicromapsPropertiesEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t micromapCount, HandlePointerDecoder<VkMicromapEXT>* pMicromaps, VkQueryType queryType, format::HandleId queryPool, uint32_t firstQuery) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceMicromapCompatibilityEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo, PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility) { }
static VKAPI_ATTR void VKAPI_CALL GetMicromapBuildSizesEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkAccelerationStructureBuildTypeKHR buildType, StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pBuildInfo, StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT>* pSizeInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawClusterHUAWEI_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawClusterIndirectHUAWEI_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset) { }
static VKAPI_ATTR void VKAPI_CALL SetDeviceMemoryPriorityEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory, float priority) { }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference, StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping) { }
static VKAPI_ATTR void VKAPI_CALL GetDescriptorSetHostMappingVALVE_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId descriptorSet, PointerDecoder<uint64_t, void*>* ppData) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetTessellationDomainOriginEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkTessellationDomainOrigin domainOrigin) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthClampEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthClampEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetPolygonModeEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkPolygonMode polygonMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationSamplesEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkSampleCountFlagBits rasterizationSamples) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleMaskEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkSampleCountFlagBits samples, PointerDecoder<VkSampleMask>* pSampleMask) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToCoverageEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 alphaToCoverageEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToOneEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 alphaToOneEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 logicOpEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, PointerDecoder<VkBool32>* pColorBlendEnables) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEquationEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteMaskEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, PointerDecoder<VkColorComponentFlags>* pColorWriteMasks) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationStreamEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t rasterizationStream) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetConservativeRasterizationModeEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, float extraPrimitiveOverestimationSize) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 depthClipEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 sampleLocationsEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendAdvancedEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetProvokingVertexModeEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkProvokingVertexModeEXT provokingVertexMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineRasterizationModeEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEnableEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 stippledLineEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipNegativeOneToOneEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 negativeOneToOne) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingEnableNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 viewportWScalingEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetViewportSwizzleNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t firstViewport, uint32_t viewportCount, StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorEnableNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 coverageToColorEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorLocationNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t coverageToColorLocation) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationModeNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCoverageModulationModeNV coverageModulationMode) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableEnableNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 coverageModulationTableEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t coverageModulationTableCount, PointerDecoder<float>* pCoverageModulationTable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetShadingRateImageEnableNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 shadingRateImageEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRepresentativeFragmentTestEnableNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkBool32 representativeFragmentTestEnable) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetCoverageReductionModeNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, VkCoverageReductionModeNV coverageReductionMode) { }
static VKAPI_ATTR void VKAPI_CALL GetShaderModuleIdentifierEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId shaderModule, StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier) { }
static VKAPI_ATTR void VKAPI_CALL GetShaderModuleCreateInfoIdentifierEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier) { }
static VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId physicalDevice, StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV>* pOpticalFlowImageFormatInfo, PointerDecoder<uint32_t>* pFormatCount, StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV>* pImageFormatProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateOpticalFlowSessionNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession) { }
static VKAPI_ATTR void VKAPI_CALL DestroyOpticalFlowSessionNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId session, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL BindOpticalFlowSessionImageNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId session, VkOpticalFlowSessionBindingPointNV bindingPoint, format::HandleId view, VkImageLayout layout) { }
static VKAPI_ATTR void VKAPI_CALL CmdOpticalFlowExecuteNV_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId session, StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetFramebufferTilePropertiesQCOM_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId framebuffer, PointerDecoder<uint32_t>* pPropertiesCount, StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL GetDynamicRenderingTilePropertiesQCOM_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo, StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties) { }
static VKAPI_ATTR void VKAPI_CALL CreateAccelerationStructureKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure) { }
static VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, format::HandleId accelerationStructure, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) { }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t infoCount, StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos, StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos) { }
static VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresIndirectKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t infoCount, StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos, PointerDecoder<VkDeviceAddress>* pIndirectDeviceAddresses, PointerDecoder<uint32_t>* pIndirectStrides, PointerDecoder<uint32_t*>* ppMaxPrimitiveCounts) { }
static VKAPI_ATTR void VKAPI_CALL CopyAccelerationStructureToMemoryKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CopyMemoryToAccelerationStructureKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL WriteAccelerationStructuresPropertiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, uint32_t accelerationStructureCount, HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures, VkQueryType queryType, size_t dataSize, PointerDecoder<uint8_t>* pData, size_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureToMemoryKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToAccelerationStructureKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureDeviceAddressKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceAddress returnValue, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t accelerationStructureCount, HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures, VkQueryType queryType, format::HandleId queryPool, uint32_t firstQuery) { }
static VKAPI_ATTR void VKAPI_CALL GetDeviceAccelerationStructureCompatibilityKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo, PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility) { }
static VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureBuildSizesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId device, VkAccelerationStructureBuildTypeKHR buildType, StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo, PointerDecoder<uint32_t>* pMaxPrimitiveCounts, StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>* pSizeInfo) { }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) { }
static VKAPI_ATTR void VKAPI_CALL CreateRayTracingPipelinesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId deferredOperation, format::HandleId pipelineCache, uint32_t createInfoCount, StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkPipeline>* pPipelines) { }
static VKAPI_ATTR void VKAPI_CALL GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, format::HandleId device, format::HandleId pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, PointerDecoder<uint8_t>* pData) { }
static VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirectKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable, StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) { }
static VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupStackSizeKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkDeviceSize returnValue, format::HandleId device, format::HandleId pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) { }
static VKAPI_ATTR void VKAPI_CALL CmdSetRayTracingPipelineStackSizeKHR_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t pipelineStackSize) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { }
static VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountEXT_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, format::HandleId commandBuffer, format::HandleId buffer, VkDeviceSize offset, format::HandleId countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { }
// clang-format on

GFXRECON_END_NAMESPACE(noop)

// clang-format off
struct plugin_func_table_post
{
    PFN_CreateInstance_PostCall CreateInstance_PostCall { noop::CreateInstance_PostCall };
    PFN_DestroyInstance_PostCall DestroyInstance_PostCall { noop::DestroyInstance_PostCall };
    PFN_EnumeratePhysicalDevices_PostCall EnumeratePhysicalDevices_PostCall { noop::EnumeratePhysicalDevices_PostCall };
    PFN_GetPhysicalDeviceFeatures_PostCall GetPhysicalDeviceFeatures_PostCall { noop::GetPhysicalDeviceFeatures_PostCall };
    PFN_GetPhysicalDeviceFormatProperties_PostCall GetPhysicalDeviceFormatProperties_PostCall { noop::GetPhysicalDeviceFormatProperties_PostCall };
    PFN_GetPhysicalDeviceImageFormatProperties_PostCall GetPhysicalDeviceImageFormatProperties_PostCall { noop::GetPhysicalDeviceImageFormatProperties_PostCall };
    PFN_GetPhysicalDeviceProperties_PostCall GetPhysicalDeviceProperties_PostCall { noop::GetPhysicalDeviceProperties_PostCall };
    PFN_GetPhysicalDeviceQueueFamilyProperties_PostCall GetPhysicalDeviceQueueFamilyProperties_PostCall { noop::GetPhysicalDeviceQueueFamilyProperties_PostCall };
    PFN_GetPhysicalDeviceMemoryProperties_PostCall GetPhysicalDeviceMemoryProperties_PostCall { noop::GetPhysicalDeviceMemoryProperties_PostCall };
    PFN_CreateDevice_PostCall CreateDevice_PostCall { noop::CreateDevice_PostCall };
    PFN_DestroyDevice_PostCall DestroyDevice_PostCall { noop::DestroyDevice_PostCall };
    PFN_GetDeviceQueue_PostCall GetDeviceQueue_PostCall { noop::GetDeviceQueue_PostCall };
    PFN_QueueSubmit_PostCall QueueSubmit_PostCall { noop::QueueSubmit_PostCall };
    PFN_QueueWaitIdle_PostCall QueueWaitIdle_PostCall { noop::QueueWaitIdle_PostCall };
    PFN_DeviceWaitIdle_PostCall DeviceWaitIdle_PostCall { noop::DeviceWaitIdle_PostCall };
    PFN_AllocateMemory_PostCall AllocateMemory_PostCall { noop::AllocateMemory_PostCall };
    PFN_FreeMemory_PostCall FreeMemory_PostCall { noop::FreeMemory_PostCall };
    PFN_MapMemory_PostCall MapMemory_PostCall { noop::MapMemory_PostCall };
    PFN_UnmapMemory_PostCall UnmapMemory_PostCall { noop::UnmapMemory_PostCall };
    PFN_FlushMappedMemoryRanges_PostCall FlushMappedMemoryRanges_PostCall { noop::FlushMappedMemoryRanges_PostCall };
    PFN_InvalidateMappedMemoryRanges_PostCall InvalidateMappedMemoryRanges_PostCall { noop::InvalidateMappedMemoryRanges_PostCall };
    PFN_GetDeviceMemoryCommitment_PostCall GetDeviceMemoryCommitment_PostCall { noop::GetDeviceMemoryCommitment_PostCall };
    PFN_BindBufferMemory_PostCall BindBufferMemory_PostCall { noop::BindBufferMemory_PostCall };
    PFN_BindImageMemory_PostCall BindImageMemory_PostCall { noop::BindImageMemory_PostCall };
    PFN_GetBufferMemoryRequirements_PostCall GetBufferMemoryRequirements_PostCall { noop::GetBufferMemoryRequirements_PostCall };
    PFN_GetImageMemoryRequirements_PostCall GetImageMemoryRequirements_PostCall { noop::GetImageMemoryRequirements_PostCall };
    PFN_GetImageSparseMemoryRequirements_PostCall GetImageSparseMemoryRequirements_PostCall { noop::GetImageSparseMemoryRequirements_PostCall };
    PFN_GetPhysicalDeviceSparseImageFormatProperties_PostCall GetPhysicalDeviceSparseImageFormatProperties_PostCall { noop::GetPhysicalDeviceSparseImageFormatProperties_PostCall };
    PFN_QueueBindSparse_PostCall QueueBindSparse_PostCall { noop::QueueBindSparse_PostCall };
    PFN_CreateFence_PostCall CreateFence_PostCall { noop::CreateFence_PostCall };
    PFN_DestroyFence_PostCall DestroyFence_PostCall { noop::DestroyFence_PostCall };
    PFN_ResetFences_PostCall ResetFences_PostCall { noop::ResetFences_PostCall };
    PFN_GetFenceStatus_PostCall GetFenceStatus_PostCall { noop::GetFenceStatus_PostCall };
    PFN_WaitForFences_PostCall WaitForFences_PostCall { noop::WaitForFences_PostCall };
    PFN_CreateSemaphore_PostCall CreateSemaphore_PostCall { noop::CreateSemaphore_PostCall };
    PFN_DestroySemaphore_PostCall DestroySemaphore_PostCall { noop::DestroySemaphore_PostCall };
    PFN_CreateEvent_PostCall CreateEvent_PostCall { noop::CreateEvent_PostCall };
    PFN_DestroyEvent_PostCall DestroyEvent_PostCall { noop::DestroyEvent_PostCall };
    PFN_GetEventStatus_PostCall GetEventStatus_PostCall { noop::GetEventStatus_PostCall };
    PFN_SetEvent_PostCall SetEvent_PostCall { noop::SetEvent_PostCall };
    PFN_ResetEvent_PostCall ResetEvent_PostCall { noop::ResetEvent_PostCall };
    PFN_CreateQueryPool_PostCall CreateQueryPool_PostCall { noop::CreateQueryPool_PostCall };
    PFN_DestroyQueryPool_PostCall DestroyQueryPool_PostCall { noop::DestroyQueryPool_PostCall };
    PFN_GetQueryPoolResults_PostCall GetQueryPoolResults_PostCall { noop::GetQueryPoolResults_PostCall };
    PFN_CreateBuffer_PostCall CreateBuffer_PostCall { noop::CreateBuffer_PostCall };
    PFN_DestroyBuffer_PostCall DestroyBuffer_PostCall { noop::DestroyBuffer_PostCall };
    PFN_CreateBufferView_PostCall CreateBufferView_PostCall { noop::CreateBufferView_PostCall };
    PFN_DestroyBufferView_PostCall DestroyBufferView_PostCall { noop::DestroyBufferView_PostCall };
    PFN_CreateImage_PostCall CreateImage_PostCall { noop::CreateImage_PostCall };
    PFN_DestroyImage_PostCall DestroyImage_PostCall { noop::DestroyImage_PostCall };
    PFN_GetImageSubresourceLayout_PostCall GetImageSubresourceLayout_PostCall { noop::GetImageSubresourceLayout_PostCall };
    PFN_CreateImageView_PostCall CreateImageView_PostCall { noop::CreateImageView_PostCall };
    PFN_DestroyImageView_PostCall DestroyImageView_PostCall { noop::DestroyImageView_PostCall };
    PFN_CreateShaderModule_PostCall CreateShaderModule_PostCall { noop::CreateShaderModule_PostCall };
    PFN_DestroyShaderModule_PostCall DestroyShaderModule_PostCall { noop::DestroyShaderModule_PostCall };
    PFN_CreatePipelineCache_PostCall CreatePipelineCache_PostCall { noop::CreatePipelineCache_PostCall };
    PFN_DestroyPipelineCache_PostCall DestroyPipelineCache_PostCall { noop::DestroyPipelineCache_PostCall };
    PFN_GetPipelineCacheData_PostCall GetPipelineCacheData_PostCall { noop::GetPipelineCacheData_PostCall };
    PFN_MergePipelineCaches_PostCall MergePipelineCaches_PostCall { noop::MergePipelineCaches_PostCall };
    PFN_CreateGraphicsPipelines_PostCall CreateGraphicsPipelines_PostCall { noop::CreateGraphicsPipelines_PostCall };
    PFN_CreateComputePipelines_PostCall CreateComputePipelines_PostCall { noop::CreateComputePipelines_PostCall };
    PFN_DestroyPipeline_PostCall DestroyPipeline_PostCall { noop::DestroyPipeline_PostCall };
    PFN_CreatePipelineLayout_PostCall CreatePipelineLayout_PostCall { noop::CreatePipelineLayout_PostCall };
    PFN_DestroyPipelineLayout_PostCall DestroyPipelineLayout_PostCall { noop::DestroyPipelineLayout_PostCall };
    PFN_CreateSampler_PostCall CreateSampler_PostCall { noop::CreateSampler_PostCall };
    PFN_DestroySampler_PostCall DestroySampler_PostCall { noop::DestroySampler_PostCall };
    PFN_CreateDescriptorSetLayout_PostCall CreateDescriptorSetLayout_PostCall { noop::CreateDescriptorSetLayout_PostCall };
    PFN_DestroyDescriptorSetLayout_PostCall DestroyDescriptorSetLayout_PostCall { noop::DestroyDescriptorSetLayout_PostCall };
    PFN_CreateDescriptorPool_PostCall CreateDescriptorPool_PostCall { noop::CreateDescriptorPool_PostCall };
    PFN_DestroyDescriptorPool_PostCall DestroyDescriptorPool_PostCall { noop::DestroyDescriptorPool_PostCall };
    PFN_ResetDescriptorPool_PostCall ResetDescriptorPool_PostCall { noop::ResetDescriptorPool_PostCall };
    PFN_AllocateDescriptorSets_PostCall AllocateDescriptorSets_PostCall { noop::AllocateDescriptorSets_PostCall };
    PFN_FreeDescriptorSets_PostCall FreeDescriptorSets_PostCall { noop::FreeDescriptorSets_PostCall };
    PFN_UpdateDescriptorSets_PostCall UpdateDescriptorSets_PostCall { noop::UpdateDescriptorSets_PostCall };
    PFN_CreateFramebuffer_PostCall CreateFramebuffer_PostCall { noop::CreateFramebuffer_PostCall };
    PFN_DestroyFramebuffer_PostCall DestroyFramebuffer_PostCall { noop::DestroyFramebuffer_PostCall };
    PFN_CreateRenderPass_PostCall CreateRenderPass_PostCall { noop::CreateRenderPass_PostCall };
    PFN_DestroyRenderPass_PostCall DestroyRenderPass_PostCall { noop::DestroyRenderPass_PostCall };
    PFN_GetRenderAreaGranularity_PostCall GetRenderAreaGranularity_PostCall { noop::GetRenderAreaGranularity_PostCall };
    PFN_CreateCommandPool_PostCall CreateCommandPool_PostCall { noop::CreateCommandPool_PostCall };
    PFN_DestroyCommandPool_PostCall DestroyCommandPool_PostCall { noop::DestroyCommandPool_PostCall };
    PFN_ResetCommandPool_PostCall ResetCommandPool_PostCall { noop::ResetCommandPool_PostCall };
    PFN_AllocateCommandBuffers_PostCall AllocateCommandBuffers_PostCall { noop::AllocateCommandBuffers_PostCall };
    PFN_FreeCommandBuffers_PostCall FreeCommandBuffers_PostCall { noop::FreeCommandBuffers_PostCall };
    PFN_BeginCommandBuffer_PostCall BeginCommandBuffer_PostCall { noop::BeginCommandBuffer_PostCall };
    PFN_EndCommandBuffer_PostCall EndCommandBuffer_PostCall { noop::EndCommandBuffer_PostCall };
    PFN_ResetCommandBuffer_PostCall ResetCommandBuffer_PostCall { noop::ResetCommandBuffer_PostCall };
    PFN_CmdBindPipeline_PostCall CmdBindPipeline_PostCall { noop::CmdBindPipeline_PostCall };
    PFN_CmdSetViewport_PostCall CmdSetViewport_PostCall { noop::CmdSetViewport_PostCall };
    PFN_CmdSetScissor_PostCall CmdSetScissor_PostCall { noop::CmdSetScissor_PostCall };
    PFN_CmdSetLineWidth_PostCall CmdSetLineWidth_PostCall { noop::CmdSetLineWidth_PostCall };
    PFN_CmdSetDepthBias_PostCall CmdSetDepthBias_PostCall { noop::CmdSetDepthBias_PostCall };
    PFN_CmdSetBlendConstants_PostCall CmdSetBlendConstants_PostCall { noop::CmdSetBlendConstants_PostCall };
    PFN_CmdSetDepthBounds_PostCall CmdSetDepthBounds_PostCall { noop::CmdSetDepthBounds_PostCall };
    PFN_CmdSetStencilCompareMask_PostCall CmdSetStencilCompareMask_PostCall { noop::CmdSetStencilCompareMask_PostCall };
    PFN_CmdSetStencilWriteMask_PostCall CmdSetStencilWriteMask_PostCall { noop::CmdSetStencilWriteMask_PostCall };
    PFN_CmdSetStencilReference_PostCall CmdSetStencilReference_PostCall { noop::CmdSetStencilReference_PostCall };
    PFN_CmdBindDescriptorSets_PostCall CmdBindDescriptorSets_PostCall { noop::CmdBindDescriptorSets_PostCall };
    PFN_CmdBindIndexBuffer_PostCall CmdBindIndexBuffer_PostCall { noop::CmdBindIndexBuffer_PostCall };
    PFN_CmdBindVertexBuffers_PostCall CmdBindVertexBuffers_PostCall { noop::CmdBindVertexBuffers_PostCall };
    PFN_CmdDraw_PostCall CmdDraw_PostCall { noop::CmdDraw_PostCall };
    PFN_CmdDrawIndexed_PostCall CmdDrawIndexed_PostCall { noop::CmdDrawIndexed_PostCall };
    PFN_CmdDrawIndirect_PostCall CmdDrawIndirect_PostCall { noop::CmdDrawIndirect_PostCall };
    PFN_CmdDrawIndexedIndirect_PostCall CmdDrawIndexedIndirect_PostCall { noop::CmdDrawIndexedIndirect_PostCall };
    PFN_CmdDispatch_PostCall CmdDispatch_PostCall { noop::CmdDispatch_PostCall };
    PFN_CmdDispatchIndirect_PostCall CmdDispatchIndirect_PostCall { noop::CmdDispatchIndirect_PostCall };
    PFN_CmdCopyBuffer_PostCall CmdCopyBuffer_PostCall { noop::CmdCopyBuffer_PostCall };
    PFN_CmdCopyImage_PostCall CmdCopyImage_PostCall { noop::CmdCopyImage_PostCall };
    PFN_CmdBlitImage_PostCall CmdBlitImage_PostCall { noop::CmdBlitImage_PostCall };
    PFN_CmdCopyBufferToImage_PostCall CmdCopyBufferToImage_PostCall { noop::CmdCopyBufferToImage_PostCall };
    PFN_CmdCopyImageToBuffer_PostCall CmdCopyImageToBuffer_PostCall { noop::CmdCopyImageToBuffer_PostCall };
    PFN_CmdUpdateBuffer_PostCall CmdUpdateBuffer_PostCall { noop::CmdUpdateBuffer_PostCall };
    PFN_CmdFillBuffer_PostCall CmdFillBuffer_PostCall { noop::CmdFillBuffer_PostCall };
    PFN_CmdClearColorImage_PostCall CmdClearColorImage_PostCall { noop::CmdClearColorImage_PostCall };
    PFN_CmdClearDepthStencilImage_PostCall CmdClearDepthStencilImage_PostCall { noop::CmdClearDepthStencilImage_PostCall };
    PFN_CmdClearAttachments_PostCall CmdClearAttachments_PostCall { noop::CmdClearAttachments_PostCall };
    PFN_CmdResolveImage_PostCall CmdResolveImage_PostCall { noop::CmdResolveImage_PostCall };
    PFN_CmdSetEvent_PostCall CmdSetEvent_PostCall { noop::CmdSetEvent_PostCall };
    PFN_CmdResetEvent_PostCall CmdResetEvent_PostCall { noop::CmdResetEvent_PostCall };
    PFN_CmdWaitEvents_PostCall CmdWaitEvents_PostCall { noop::CmdWaitEvents_PostCall };
    PFN_CmdPipelineBarrier_PostCall CmdPipelineBarrier_PostCall { noop::CmdPipelineBarrier_PostCall };
    PFN_CmdBeginQuery_PostCall CmdBeginQuery_PostCall { noop::CmdBeginQuery_PostCall };
    PFN_CmdEndQuery_PostCall CmdEndQuery_PostCall { noop::CmdEndQuery_PostCall };
    PFN_CmdResetQueryPool_PostCall CmdResetQueryPool_PostCall { noop::CmdResetQueryPool_PostCall };
    PFN_CmdWriteTimestamp_PostCall CmdWriteTimestamp_PostCall { noop::CmdWriteTimestamp_PostCall };
    PFN_CmdCopyQueryPoolResults_PostCall CmdCopyQueryPoolResults_PostCall { noop::CmdCopyQueryPoolResults_PostCall };
    PFN_CmdPushConstants_PostCall CmdPushConstants_PostCall { noop::CmdPushConstants_PostCall };
    PFN_CmdBeginRenderPass_PostCall CmdBeginRenderPass_PostCall { noop::CmdBeginRenderPass_PostCall };
    PFN_CmdNextSubpass_PostCall CmdNextSubpass_PostCall { noop::CmdNextSubpass_PostCall };
    PFN_CmdEndRenderPass_PostCall CmdEndRenderPass_PostCall { noop::CmdEndRenderPass_PostCall };
    PFN_CmdExecuteCommands_PostCall CmdExecuteCommands_PostCall { noop::CmdExecuteCommands_PostCall };
    PFN_BindBufferMemory2_PostCall BindBufferMemory2_PostCall { noop::BindBufferMemory2_PostCall };
    PFN_BindImageMemory2_PostCall BindImageMemory2_PostCall { noop::BindImageMemory2_PostCall };
    PFN_GetDeviceGroupPeerMemoryFeatures_PostCall GetDeviceGroupPeerMemoryFeatures_PostCall { noop::GetDeviceGroupPeerMemoryFeatures_PostCall };
    PFN_CmdSetDeviceMask_PostCall CmdSetDeviceMask_PostCall { noop::CmdSetDeviceMask_PostCall };
    PFN_CmdDispatchBase_PostCall CmdDispatchBase_PostCall { noop::CmdDispatchBase_PostCall };
    PFN_EnumeratePhysicalDeviceGroups_PostCall EnumeratePhysicalDeviceGroups_PostCall { noop::EnumeratePhysicalDeviceGroups_PostCall };
    PFN_GetImageMemoryRequirements2_PostCall GetImageMemoryRequirements2_PostCall { noop::GetImageMemoryRequirements2_PostCall };
    PFN_GetBufferMemoryRequirements2_PostCall GetBufferMemoryRequirements2_PostCall { noop::GetBufferMemoryRequirements2_PostCall };
    PFN_GetImageSparseMemoryRequirements2_PostCall GetImageSparseMemoryRequirements2_PostCall { noop::GetImageSparseMemoryRequirements2_PostCall };
    PFN_GetPhysicalDeviceFeatures2_PostCall GetPhysicalDeviceFeatures2_PostCall { noop::GetPhysicalDeviceFeatures2_PostCall };
    PFN_GetPhysicalDeviceProperties2_PostCall GetPhysicalDeviceProperties2_PostCall { noop::GetPhysicalDeviceProperties2_PostCall };
    PFN_GetPhysicalDeviceFormatProperties2_PostCall GetPhysicalDeviceFormatProperties2_PostCall { noop::GetPhysicalDeviceFormatProperties2_PostCall };
    PFN_GetPhysicalDeviceImageFormatProperties2_PostCall GetPhysicalDeviceImageFormatProperties2_PostCall { noop::GetPhysicalDeviceImageFormatProperties2_PostCall };
    PFN_GetPhysicalDeviceQueueFamilyProperties2_PostCall GetPhysicalDeviceQueueFamilyProperties2_PostCall { noop::GetPhysicalDeviceQueueFamilyProperties2_PostCall };
    PFN_GetPhysicalDeviceMemoryProperties2_PostCall GetPhysicalDeviceMemoryProperties2_PostCall { noop::GetPhysicalDeviceMemoryProperties2_PostCall };
    PFN_GetPhysicalDeviceSparseImageFormatProperties2_PostCall GetPhysicalDeviceSparseImageFormatProperties2_PostCall { noop::GetPhysicalDeviceSparseImageFormatProperties2_PostCall };
    PFN_TrimCommandPool_PostCall TrimCommandPool_PostCall { noop::TrimCommandPool_PostCall };
    PFN_GetDeviceQueue2_PostCall GetDeviceQueue2_PostCall { noop::GetDeviceQueue2_PostCall };
    PFN_CreateSamplerYcbcrConversion_PostCall CreateSamplerYcbcrConversion_PostCall { noop::CreateSamplerYcbcrConversion_PostCall };
    PFN_DestroySamplerYcbcrConversion_PostCall DestroySamplerYcbcrConversion_PostCall { noop::DestroySamplerYcbcrConversion_PostCall };
    PFN_CreateDescriptorUpdateTemplate_PostCall CreateDescriptorUpdateTemplate_PostCall { noop::CreateDescriptorUpdateTemplate_PostCall };
    PFN_DestroyDescriptorUpdateTemplate_PostCall DestroyDescriptorUpdateTemplate_PostCall { noop::DestroyDescriptorUpdateTemplate_PostCall };
    PFN_GetPhysicalDeviceExternalBufferProperties_PostCall GetPhysicalDeviceExternalBufferProperties_PostCall { noop::GetPhysicalDeviceExternalBufferProperties_PostCall };
    PFN_GetPhysicalDeviceExternalFenceProperties_PostCall GetPhysicalDeviceExternalFenceProperties_PostCall { noop::GetPhysicalDeviceExternalFenceProperties_PostCall };
    PFN_GetPhysicalDeviceExternalSemaphoreProperties_PostCall GetPhysicalDeviceExternalSemaphoreProperties_PostCall { noop::GetPhysicalDeviceExternalSemaphoreProperties_PostCall };
    PFN_GetDescriptorSetLayoutSupport_PostCall GetDescriptorSetLayoutSupport_PostCall { noop::GetDescriptorSetLayoutSupport_PostCall };
    PFN_CmdDrawIndirectCount_PostCall CmdDrawIndirectCount_PostCall { noop::CmdDrawIndirectCount_PostCall };
    PFN_CmdDrawIndexedIndirectCount_PostCall CmdDrawIndexedIndirectCount_PostCall { noop::CmdDrawIndexedIndirectCount_PostCall };
    PFN_CreateRenderPass2_PostCall CreateRenderPass2_PostCall { noop::CreateRenderPass2_PostCall };
    PFN_CmdBeginRenderPass2_PostCall CmdBeginRenderPass2_PostCall { noop::CmdBeginRenderPass2_PostCall };
    PFN_CmdNextSubpass2_PostCall CmdNextSubpass2_PostCall { noop::CmdNextSubpass2_PostCall };
    PFN_CmdEndRenderPass2_PostCall CmdEndRenderPass2_PostCall { noop::CmdEndRenderPass2_PostCall };
    PFN_ResetQueryPool_PostCall ResetQueryPool_PostCall { noop::ResetQueryPool_PostCall };
    PFN_GetSemaphoreCounterValue_PostCall GetSemaphoreCounterValue_PostCall { noop::GetSemaphoreCounterValue_PostCall };
    PFN_WaitSemaphores_PostCall WaitSemaphores_PostCall { noop::WaitSemaphores_PostCall };
    PFN_SignalSemaphore_PostCall SignalSemaphore_PostCall { noop::SignalSemaphore_PostCall };
    PFN_GetBufferDeviceAddress_PostCall GetBufferDeviceAddress_PostCall { noop::GetBufferDeviceAddress_PostCall };
    PFN_GetBufferOpaqueCaptureAddress_PostCall GetBufferOpaqueCaptureAddress_PostCall { noop::GetBufferOpaqueCaptureAddress_PostCall };
    PFN_GetDeviceMemoryOpaqueCaptureAddress_PostCall GetDeviceMemoryOpaqueCaptureAddress_PostCall { noop::GetDeviceMemoryOpaqueCaptureAddress_PostCall };
    PFN_GetPhysicalDeviceToolProperties_PostCall GetPhysicalDeviceToolProperties_PostCall { noop::GetPhysicalDeviceToolProperties_PostCall };
    PFN_CreatePrivateDataSlot_PostCall CreatePrivateDataSlot_PostCall { noop::CreatePrivateDataSlot_PostCall };
    PFN_DestroyPrivateDataSlot_PostCall DestroyPrivateDataSlot_PostCall { noop::DestroyPrivateDataSlot_PostCall };
    PFN_SetPrivateData_PostCall SetPrivateData_PostCall { noop::SetPrivateData_PostCall };
    PFN_GetPrivateData_PostCall GetPrivateData_PostCall { noop::GetPrivateData_PostCall };
    PFN_CmdSetEvent2_PostCall CmdSetEvent2_PostCall { noop::CmdSetEvent2_PostCall };
    PFN_CmdResetEvent2_PostCall CmdResetEvent2_PostCall { noop::CmdResetEvent2_PostCall };
    PFN_CmdWaitEvents2_PostCall CmdWaitEvents2_PostCall { noop::CmdWaitEvents2_PostCall };
    PFN_CmdPipelineBarrier2_PostCall CmdPipelineBarrier2_PostCall { noop::CmdPipelineBarrier2_PostCall };
    PFN_CmdWriteTimestamp2_PostCall CmdWriteTimestamp2_PostCall { noop::CmdWriteTimestamp2_PostCall };
    PFN_QueueSubmit2_PostCall QueueSubmit2_PostCall { noop::QueueSubmit2_PostCall };
    PFN_CmdCopyBuffer2_PostCall CmdCopyBuffer2_PostCall { noop::CmdCopyBuffer2_PostCall };
    PFN_CmdCopyImage2_PostCall CmdCopyImage2_PostCall { noop::CmdCopyImage2_PostCall };
    PFN_CmdCopyBufferToImage2_PostCall CmdCopyBufferToImage2_PostCall { noop::CmdCopyBufferToImage2_PostCall };
    PFN_CmdCopyImageToBuffer2_PostCall CmdCopyImageToBuffer2_PostCall { noop::CmdCopyImageToBuffer2_PostCall };
    PFN_CmdBlitImage2_PostCall CmdBlitImage2_PostCall { noop::CmdBlitImage2_PostCall };
    PFN_CmdResolveImage2_PostCall CmdResolveImage2_PostCall { noop::CmdResolveImage2_PostCall };
    PFN_CmdBeginRendering_PostCall CmdBeginRendering_PostCall { noop::CmdBeginRendering_PostCall };
    PFN_CmdEndRendering_PostCall CmdEndRendering_PostCall { noop::CmdEndRendering_PostCall };
    PFN_CmdSetCullMode_PostCall CmdSetCullMode_PostCall { noop::CmdSetCullMode_PostCall };
    PFN_CmdSetFrontFace_PostCall CmdSetFrontFace_PostCall { noop::CmdSetFrontFace_PostCall };
    PFN_CmdSetPrimitiveTopology_PostCall CmdSetPrimitiveTopology_PostCall { noop::CmdSetPrimitiveTopology_PostCall };
    PFN_CmdSetViewportWithCount_PostCall CmdSetViewportWithCount_PostCall { noop::CmdSetViewportWithCount_PostCall };
    PFN_CmdSetScissorWithCount_PostCall CmdSetScissorWithCount_PostCall { noop::CmdSetScissorWithCount_PostCall };
    PFN_CmdBindVertexBuffers2_PostCall CmdBindVertexBuffers2_PostCall { noop::CmdBindVertexBuffers2_PostCall };
    PFN_CmdSetDepthTestEnable_PostCall CmdSetDepthTestEnable_PostCall { noop::CmdSetDepthTestEnable_PostCall };
    PFN_CmdSetDepthWriteEnable_PostCall CmdSetDepthWriteEnable_PostCall { noop::CmdSetDepthWriteEnable_PostCall };
    PFN_CmdSetDepthCompareOp_PostCall CmdSetDepthCompareOp_PostCall { noop::CmdSetDepthCompareOp_PostCall };
    PFN_CmdSetDepthBoundsTestEnable_PostCall CmdSetDepthBoundsTestEnable_PostCall { noop::CmdSetDepthBoundsTestEnable_PostCall };
    PFN_CmdSetStencilTestEnable_PostCall CmdSetStencilTestEnable_PostCall { noop::CmdSetStencilTestEnable_PostCall };
    PFN_CmdSetStencilOp_PostCall CmdSetStencilOp_PostCall { noop::CmdSetStencilOp_PostCall };
    PFN_CmdSetRasterizerDiscardEnable_PostCall CmdSetRasterizerDiscardEnable_PostCall { noop::CmdSetRasterizerDiscardEnable_PostCall };
    PFN_CmdSetDepthBiasEnable_PostCall CmdSetDepthBiasEnable_PostCall { noop::CmdSetDepthBiasEnable_PostCall };
    PFN_CmdSetPrimitiveRestartEnable_PostCall CmdSetPrimitiveRestartEnable_PostCall { noop::CmdSetPrimitiveRestartEnable_PostCall };
    PFN_GetDeviceBufferMemoryRequirements_PostCall GetDeviceBufferMemoryRequirements_PostCall { noop::GetDeviceBufferMemoryRequirements_PostCall };
    PFN_GetDeviceImageMemoryRequirements_PostCall GetDeviceImageMemoryRequirements_PostCall { noop::GetDeviceImageMemoryRequirements_PostCall };
    PFN_GetDeviceImageSparseMemoryRequirements_PostCall GetDeviceImageSparseMemoryRequirements_PostCall { noop::GetDeviceImageSparseMemoryRequirements_PostCall };
    PFN_DestroySurfaceKHR_PostCall DestroySurfaceKHR_PostCall { noop::DestroySurfaceKHR_PostCall };
    PFN_GetPhysicalDeviceSurfaceSupportKHR_PostCall GetPhysicalDeviceSurfaceSupportKHR_PostCall { noop::GetPhysicalDeviceSurfaceSupportKHR_PostCall };
    PFN_GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall { noop::GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall };
    PFN_GetPhysicalDeviceSurfaceFormatsKHR_PostCall GetPhysicalDeviceSurfaceFormatsKHR_PostCall { noop::GetPhysicalDeviceSurfaceFormatsKHR_PostCall };
    PFN_GetPhysicalDeviceSurfacePresentModesKHR_PostCall GetPhysicalDeviceSurfacePresentModesKHR_PostCall { noop::GetPhysicalDeviceSurfacePresentModesKHR_PostCall };
    PFN_CreateSwapchainKHR_PostCall CreateSwapchainKHR_PostCall { noop::CreateSwapchainKHR_PostCall };
    PFN_DestroySwapchainKHR_PostCall DestroySwapchainKHR_PostCall { noop::DestroySwapchainKHR_PostCall };
    PFN_GetSwapchainImagesKHR_PostCall GetSwapchainImagesKHR_PostCall { noop::GetSwapchainImagesKHR_PostCall };
    PFN_AcquireNextImageKHR_PostCall AcquireNextImageKHR_PostCall { noop::AcquireNextImageKHR_PostCall };
    PFN_QueuePresentKHR_PostCall QueuePresentKHR_PostCall { noop::QueuePresentKHR_PostCall };
    PFN_GetDeviceGroupPresentCapabilitiesKHR_PostCall GetDeviceGroupPresentCapabilitiesKHR_PostCall { noop::GetDeviceGroupPresentCapabilitiesKHR_PostCall };
    PFN_GetDeviceGroupSurfacePresentModesKHR_PostCall GetDeviceGroupSurfacePresentModesKHR_PostCall { noop::GetDeviceGroupSurfacePresentModesKHR_PostCall };
    PFN_GetPhysicalDevicePresentRectanglesKHR_PostCall GetPhysicalDevicePresentRectanglesKHR_PostCall { noop::GetPhysicalDevicePresentRectanglesKHR_PostCall };
    PFN_AcquireNextImage2KHR_PostCall AcquireNextImage2KHR_PostCall { noop::AcquireNextImage2KHR_PostCall };
    PFN_GetPhysicalDeviceDisplayPropertiesKHR_PostCall GetPhysicalDeviceDisplayPropertiesKHR_PostCall { noop::GetPhysicalDeviceDisplayPropertiesKHR_PostCall };
    PFN_GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall { noop::GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall };
    PFN_GetDisplayPlaneSupportedDisplaysKHR_PostCall GetDisplayPlaneSupportedDisplaysKHR_PostCall { noop::GetDisplayPlaneSupportedDisplaysKHR_PostCall };
    PFN_GetDisplayModePropertiesKHR_PostCall GetDisplayModePropertiesKHR_PostCall { noop::GetDisplayModePropertiesKHR_PostCall };
    PFN_CreateDisplayModeKHR_PostCall CreateDisplayModeKHR_PostCall { noop::CreateDisplayModeKHR_PostCall };
    PFN_GetDisplayPlaneCapabilitiesKHR_PostCall GetDisplayPlaneCapabilitiesKHR_PostCall { noop::GetDisplayPlaneCapabilitiesKHR_PostCall };
    PFN_CreateDisplayPlaneSurfaceKHR_PostCall CreateDisplayPlaneSurfaceKHR_PostCall { noop::CreateDisplayPlaneSurfaceKHR_PostCall };
    PFN_CreateSharedSwapchainsKHR_PostCall CreateSharedSwapchainsKHR_PostCall { noop::CreateSharedSwapchainsKHR_PostCall };
    PFN_CreateXlibSurfaceKHR_PostCall CreateXlibSurfaceKHR_PostCall { noop::CreateXlibSurfaceKHR_PostCall };
    PFN_GetPhysicalDeviceXlibPresentationSupportKHR_PostCall GetPhysicalDeviceXlibPresentationSupportKHR_PostCall { noop::GetPhysicalDeviceXlibPresentationSupportKHR_PostCall };
    PFN_CreateXcbSurfaceKHR_PostCall CreateXcbSurfaceKHR_PostCall { noop::CreateXcbSurfaceKHR_PostCall };
    PFN_GetPhysicalDeviceXcbPresentationSupportKHR_PostCall GetPhysicalDeviceXcbPresentationSupportKHR_PostCall { noop::GetPhysicalDeviceXcbPresentationSupportKHR_PostCall };
    PFN_CreateWaylandSurfaceKHR_PostCall CreateWaylandSurfaceKHR_PostCall { noop::CreateWaylandSurfaceKHR_PostCall };
    PFN_GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall { noop::GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall };
    PFN_CreateAndroidSurfaceKHR_PostCall CreateAndroidSurfaceKHR_PostCall { noop::CreateAndroidSurfaceKHR_PostCall };
    PFN_CreateWin32SurfaceKHR_PostCall CreateWin32SurfaceKHR_PostCall { noop::CreateWin32SurfaceKHR_PostCall };
    PFN_GetPhysicalDeviceWin32PresentationSupportKHR_PostCall GetPhysicalDeviceWin32PresentationSupportKHR_PostCall { noop::GetPhysicalDeviceWin32PresentationSupportKHR_PostCall };
    PFN_GetPhysicalDeviceVideoCapabilitiesKHR_PostCall GetPhysicalDeviceVideoCapabilitiesKHR_PostCall { noop::GetPhysicalDeviceVideoCapabilitiesKHR_PostCall };
    PFN_GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall { noop::GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall };
    PFN_CreateVideoSessionKHR_PostCall CreateVideoSessionKHR_PostCall { noop::CreateVideoSessionKHR_PostCall };
    PFN_DestroyVideoSessionKHR_PostCall DestroyVideoSessionKHR_PostCall { noop::DestroyVideoSessionKHR_PostCall };
    PFN_GetVideoSessionMemoryRequirementsKHR_PostCall GetVideoSessionMemoryRequirementsKHR_PostCall { noop::GetVideoSessionMemoryRequirementsKHR_PostCall };
    PFN_BindVideoSessionMemoryKHR_PostCall BindVideoSessionMemoryKHR_PostCall { noop::BindVideoSessionMemoryKHR_PostCall };
    PFN_CreateVideoSessionParametersKHR_PostCall CreateVideoSessionParametersKHR_PostCall { noop::CreateVideoSessionParametersKHR_PostCall };
    PFN_UpdateVideoSessionParametersKHR_PostCall UpdateVideoSessionParametersKHR_PostCall { noop::UpdateVideoSessionParametersKHR_PostCall };
    PFN_DestroyVideoSessionParametersKHR_PostCall DestroyVideoSessionParametersKHR_PostCall { noop::DestroyVideoSessionParametersKHR_PostCall };
    PFN_CmdBeginVideoCodingKHR_PostCall CmdBeginVideoCodingKHR_PostCall { noop::CmdBeginVideoCodingKHR_PostCall };
    PFN_CmdEndVideoCodingKHR_PostCall CmdEndVideoCodingKHR_PostCall { noop::CmdEndVideoCodingKHR_PostCall };
    PFN_CmdControlVideoCodingKHR_PostCall CmdControlVideoCodingKHR_PostCall { noop::CmdControlVideoCodingKHR_PostCall };
    PFN_CmdDecodeVideoKHR_PostCall CmdDecodeVideoKHR_PostCall { noop::CmdDecodeVideoKHR_PostCall };
    PFN_CmdBeginRenderingKHR_PostCall CmdBeginRenderingKHR_PostCall { noop::CmdBeginRenderingKHR_PostCall };
    PFN_CmdEndRenderingKHR_PostCall CmdEndRenderingKHR_PostCall { noop::CmdEndRenderingKHR_PostCall };
    PFN_GetPhysicalDeviceFeatures2KHR_PostCall GetPhysicalDeviceFeatures2KHR_PostCall { noop::GetPhysicalDeviceFeatures2KHR_PostCall };
    PFN_GetPhysicalDeviceProperties2KHR_PostCall GetPhysicalDeviceProperties2KHR_PostCall { noop::GetPhysicalDeviceProperties2KHR_PostCall };
    PFN_GetPhysicalDeviceFormatProperties2KHR_PostCall GetPhysicalDeviceFormatProperties2KHR_PostCall { noop::GetPhysicalDeviceFormatProperties2KHR_PostCall };
    PFN_GetPhysicalDeviceImageFormatProperties2KHR_PostCall GetPhysicalDeviceImageFormatProperties2KHR_PostCall { noop::GetPhysicalDeviceImageFormatProperties2KHR_PostCall };
    PFN_GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall { noop::GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall };
    PFN_GetPhysicalDeviceMemoryProperties2KHR_PostCall GetPhysicalDeviceMemoryProperties2KHR_PostCall { noop::GetPhysicalDeviceMemoryProperties2KHR_PostCall };
    PFN_GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall { noop::GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall };
    PFN_GetDeviceGroupPeerMemoryFeaturesKHR_PostCall GetDeviceGroupPeerMemoryFeaturesKHR_PostCall { noop::GetDeviceGroupPeerMemoryFeaturesKHR_PostCall };
    PFN_CmdSetDeviceMaskKHR_PostCall CmdSetDeviceMaskKHR_PostCall { noop::CmdSetDeviceMaskKHR_PostCall };
    PFN_CmdDispatchBaseKHR_PostCall CmdDispatchBaseKHR_PostCall { noop::CmdDispatchBaseKHR_PostCall };
    PFN_TrimCommandPoolKHR_PostCall TrimCommandPoolKHR_PostCall { noop::TrimCommandPoolKHR_PostCall };
    PFN_EnumeratePhysicalDeviceGroupsKHR_PostCall EnumeratePhysicalDeviceGroupsKHR_PostCall { noop::EnumeratePhysicalDeviceGroupsKHR_PostCall };
    PFN_GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall { noop::GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall };
    PFN_GetMemoryWin32HandleKHR_PostCall GetMemoryWin32HandleKHR_PostCall { noop::GetMemoryWin32HandleKHR_PostCall };
    PFN_GetMemoryWin32HandlePropertiesKHR_PostCall GetMemoryWin32HandlePropertiesKHR_PostCall { noop::GetMemoryWin32HandlePropertiesKHR_PostCall };
    PFN_GetMemoryFdKHR_PostCall GetMemoryFdKHR_PostCall { noop::GetMemoryFdKHR_PostCall };
    PFN_GetMemoryFdPropertiesKHR_PostCall GetMemoryFdPropertiesKHR_PostCall { noop::GetMemoryFdPropertiesKHR_PostCall };
    PFN_GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall { noop::GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall };
    PFN_ImportSemaphoreWin32HandleKHR_PostCall ImportSemaphoreWin32HandleKHR_PostCall { noop::ImportSemaphoreWin32HandleKHR_PostCall };
    PFN_GetSemaphoreWin32HandleKHR_PostCall GetSemaphoreWin32HandleKHR_PostCall { noop::GetSemaphoreWin32HandleKHR_PostCall };
    PFN_ImportSemaphoreFdKHR_PostCall ImportSemaphoreFdKHR_PostCall { noop::ImportSemaphoreFdKHR_PostCall };
    PFN_GetSemaphoreFdKHR_PostCall GetSemaphoreFdKHR_PostCall { noop::GetSemaphoreFdKHR_PostCall };
    PFN_CmdPushDescriptorSetKHR_PostCall CmdPushDescriptorSetKHR_PostCall { noop::CmdPushDescriptorSetKHR_PostCall };
    PFN_CreateDescriptorUpdateTemplateKHR_PostCall CreateDescriptorUpdateTemplateKHR_PostCall { noop::CreateDescriptorUpdateTemplateKHR_PostCall };
    PFN_DestroyDescriptorUpdateTemplateKHR_PostCall DestroyDescriptorUpdateTemplateKHR_PostCall { noop::DestroyDescriptorUpdateTemplateKHR_PostCall };
    PFN_CreateRenderPass2KHR_PostCall CreateRenderPass2KHR_PostCall { noop::CreateRenderPass2KHR_PostCall };
    PFN_CmdBeginRenderPass2KHR_PostCall CmdBeginRenderPass2KHR_PostCall { noop::CmdBeginRenderPass2KHR_PostCall };
    PFN_CmdNextSubpass2KHR_PostCall CmdNextSubpass2KHR_PostCall { noop::CmdNextSubpass2KHR_PostCall };
    PFN_CmdEndRenderPass2KHR_PostCall CmdEndRenderPass2KHR_PostCall { noop::CmdEndRenderPass2KHR_PostCall };
    PFN_GetSwapchainStatusKHR_PostCall GetSwapchainStatusKHR_PostCall { noop::GetSwapchainStatusKHR_PostCall };
    PFN_GetPhysicalDeviceExternalFencePropertiesKHR_PostCall GetPhysicalDeviceExternalFencePropertiesKHR_PostCall { noop::GetPhysicalDeviceExternalFencePropertiesKHR_PostCall };
    PFN_ImportFenceWin32HandleKHR_PostCall ImportFenceWin32HandleKHR_PostCall { noop::ImportFenceWin32HandleKHR_PostCall };
    PFN_GetFenceWin32HandleKHR_PostCall GetFenceWin32HandleKHR_PostCall { noop::GetFenceWin32HandleKHR_PostCall };
    PFN_ImportFenceFdKHR_PostCall ImportFenceFdKHR_PostCall { noop::ImportFenceFdKHR_PostCall };
    PFN_GetFenceFdKHR_PostCall GetFenceFdKHR_PostCall { noop::GetFenceFdKHR_PostCall };
    PFN_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall { noop::EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall };
    PFN_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall { noop::GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall };
    PFN_AcquireProfilingLockKHR_PostCall AcquireProfilingLockKHR_PostCall { noop::AcquireProfilingLockKHR_PostCall };
    PFN_ReleaseProfilingLockKHR_PostCall ReleaseProfilingLockKHR_PostCall { noop::ReleaseProfilingLockKHR_PostCall };
    PFN_GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall { noop::GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall };
    PFN_GetPhysicalDeviceSurfaceFormats2KHR_PostCall GetPhysicalDeviceSurfaceFormats2KHR_PostCall { noop::GetPhysicalDeviceSurfaceFormats2KHR_PostCall };
    PFN_GetPhysicalDeviceDisplayProperties2KHR_PostCall GetPhysicalDeviceDisplayProperties2KHR_PostCall { noop::GetPhysicalDeviceDisplayProperties2KHR_PostCall };
    PFN_GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall { noop::GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall };
    PFN_GetDisplayModeProperties2KHR_PostCall GetDisplayModeProperties2KHR_PostCall { noop::GetDisplayModeProperties2KHR_PostCall };
    PFN_GetDisplayPlaneCapabilities2KHR_PostCall GetDisplayPlaneCapabilities2KHR_PostCall { noop::GetDisplayPlaneCapabilities2KHR_PostCall };
    PFN_GetImageMemoryRequirements2KHR_PostCall GetImageMemoryRequirements2KHR_PostCall { noop::GetImageMemoryRequirements2KHR_PostCall };
    PFN_GetBufferMemoryRequirements2KHR_PostCall GetBufferMemoryRequirements2KHR_PostCall { noop::GetBufferMemoryRequirements2KHR_PostCall };
    PFN_GetImageSparseMemoryRequirements2KHR_PostCall GetImageSparseMemoryRequirements2KHR_PostCall { noop::GetImageSparseMemoryRequirements2KHR_PostCall };
    PFN_CreateSamplerYcbcrConversionKHR_PostCall CreateSamplerYcbcrConversionKHR_PostCall { noop::CreateSamplerYcbcrConversionKHR_PostCall };
    PFN_DestroySamplerYcbcrConversionKHR_PostCall DestroySamplerYcbcrConversionKHR_PostCall { noop::DestroySamplerYcbcrConversionKHR_PostCall };
    PFN_BindBufferMemory2KHR_PostCall BindBufferMemory2KHR_PostCall { noop::BindBufferMemory2KHR_PostCall };
    PFN_BindImageMemory2KHR_PostCall BindImageMemory2KHR_PostCall { noop::BindImageMemory2KHR_PostCall };
    PFN_GetDescriptorSetLayoutSupportKHR_PostCall GetDescriptorSetLayoutSupportKHR_PostCall { noop::GetDescriptorSetLayoutSupportKHR_PostCall };
    PFN_CmdDrawIndirectCountKHR_PostCall CmdDrawIndirectCountKHR_PostCall { noop::CmdDrawIndirectCountKHR_PostCall };
    PFN_CmdDrawIndexedIndirectCountKHR_PostCall CmdDrawIndexedIndirectCountKHR_PostCall { noop::CmdDrawIndexedIndirectCountKHR_PostCall };
    PFN_GetSemaphoreCounterValueKHR_PostCall GetSemaphoreCounterValueKHR_PostCall { noop::GetSemaphoreCounterValueKHR_PostCall };
    PFN_WaitSemaphoresKHR_PostCall WaitSemaphoresKHR_PostCall { noop::WaitSemaphoresKHR_PostCall };
    PFN_SignalSemaphoreKHR_PostCall SignalSemaphoreKHR_PostCall { noop::SignalSemaphoreKHR_PostCall };
    PFN_GetPhysicalDeviceFragmentShadingRatesKHR_PostCall GetPhysicalDeviceFragmentShadingRatesKHR_PostCall { noop::GetPhysicalDeviceFragmentShadingRatesKHR_PostCall };
    PFN_CmdSetFragmentShadingRateKHR_PostCall CmdSetFragmentShadingRateKHR_PostCall { noop::CmdSetFragmentShadingRateKHR_PostCall };
    PFN_WaitForPresentKHR_PostCall WaitForPresentKHR_PostCall { noop::WaitForPresentKHR_PostCall };
    PFN_GetBufferDeviceAddressKHR_PostCall GetBufferDeviceAddressKHR_PostCall { noop::GetBufferDeviceAddressKHR_PostCall };
    PFN_GetBufferOpaqueCaptureAddressKHR_PostCall GetBufferOpaqueCaptureAddressKHR_PostCall { noop::GetBufferOpaqueCaptureAddressKHR_PostCall };
    PFN_GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall { noop::GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall };
    PFN_CreateDeferredOperationKHR_PostCall CreateDeferredOperationKHR_PostCall { noop::CreateDeferredOperationKHR_PostCall };
    PFN_DestroyDeferredOperationKHR_PostCall DestroyDeferredOperationKHR_PostCall { noop::DestroyDeferredOperationKHR_PostCall };
    PFN_GetDeferredOperationMaxConcurrencyKHR_PostCall GetDeferredOperationMaxConcurrencyKHR_PostCall { noop::GetDeferredOperationMaxConcurrencyKHR_PostCall };
    PFN_GetDeferredOperationResultKHR_PostCall GetDeferredOperationResultKHR_PostCall { noop::GetDeferredOperationResultKHR_PostCall };
    PFN_DeferredOperationJoinKHR_PostCall DeferredOperationJoinKHR_PostCall { noop::DeferredOperationJoinKHR_PostCall };
    PFN_GetPipelineExecutablePropertiesKHR_PostCall GetPipelineExecutablePropertiesKHR_PostCall { noop::GetPipelineExecutablePropertiesKHR_PostCall };
    PFN_GetPipelineExecutableStatisticsKHR_PostCall GetPipelineExecutableStatisticsKHR_PostCall { noop::GetPipelineExecutableStatisticsKHR_PostCall };
    PFN_GetPipelineExecutableInternalRepresentationsKHR_PostCall GetPipelineExecutableInternalRepresentationsKHR_PostCall { noop::GetPipelineExecutableInternalRepresentationsKHR_PostCall };
    PFN_CmdEncodeVideoKHR_PostCall CmdEncodeVideoKHR_PostCall { noop::CmdEncodeVideoKHR_PostCall };
    PFN_CmdSetEvent2KHR_PostCall CmdSetEvent2KHR_PostCall { noop::CmdSetEvent2KHR_PostCall };
    PFN_CmdResetEvent2KHR_PostCall CmdResetEvent2KHR_PostCall { noop::CmdResetEvent2KHR_PostCall };
    PFN_CmdWaitEvents2KHR_PostCall CmdWaitEvents2KHR_PostCall { noop::CmdWaitEvents2KHR_PostCall };
    PFN_CmdPipelineBarrier2KHR_PostCall CmdPipelineBarrier2KHR_PostCall { noop::CmdPipelineBarrier2KHR_PostCall };
    PFN_CmdWriteTimestamp2KHR_PostCall CmdWriteTimestamp2KHR_PostCall { noop::CmdWriteTimestamp2KHR_PostCall };
    PFN_QueueSubmit2KHR_PostCall QueueSubmit2KHR_PostCall { noop::QueueSubmit2KHR_PostCall };
    PFN_CmdWriteBufferMarker2AMD_PostCall CmdWriteBufferMarker2AMD_PostCall { noop::CmdWriteBufferMarker2AMD_PostCall };
    PFN_GetQueueCheckpointData2NV_PostCall GetQueueCheckpointData2NV_PostCall { noop::GetQueueCheckpointData2NV_PostCall };
    PFN_CmdCopyBuffer2KHR_PostCall CmdCopyBuffer2KHR_PostCall { noop::CmdCopyBuffer2KHR_PostCall };
    PFN_CmdCopyImage2KHR_PostCall CmdCopyImage2KHR_PostCall { noop::CmdCopyImage2KHR_PostCall };
    PFN_CmdCopyBufferToImage2KHR_PostCall CmdCopyBufferToImage2KHR_PostCall { noop::CmdCopyBufferToImage2KHR_PostCall };
    PFN_CmdCopyImageToBuffer2KHR_PostCall CmdCopyImageToBuffer2KHR_PostCall { noop::CmdCopyImageToBuffer2KHR_PostCall };
    PFN_CmdBlitImage2KHR_PostCall CmdBlitImage2KHR_PostCall { noop::CmdBlitImage2KHR_PostCall };
    PFN_CmdResolveImage2KHR_PostCall CmdResolveImage2KHR_PostCall { noop::CmdResolveImage2KHR_PostCall };
    PFN_CmdTraceRaysIndirect2KHR_PostCall CmdTraceRaysIndirect2KHR_PostCall { noop::CmdTraceRaysIndirect2KHR_PostCall };
    PFN_GetDeviceBufferMemoryRequirementsKHR_PostCall GetDeviceBufferMemoryRequirementsKHR_PostCall { noop::GetDeviceBufferMemoryRequirementsKHR_PostCall };
    PFN_GetDeviceImageMemoryRequirementsKHR_PostCall GetDeviceImageMemoryRequirementsKHR_PostCall { noop::GetDeviceImageMemoryRequirementsKHR_PostCall };
    PFN_GetDeviceImageSparseMemoryRequirementsKHR_PostCall GetDeviceImageSparseMemoryRequirementsKHR_PostCall { noop::GetDeviceImageSparseMemoryRequirementsKHR_PostCall };
    PFN_CreateDebugReportCallbackEXT_PostCall CreateDebugReportCallbackEXT_PostCall { noop::CreateDebugReportCallbackEXT_PostCall };
    PFN_DestroyDebugReportCallbackEXT_PostCall DestroyDebugReportCallbackEXT_PostCall { noop::DestroyDebugReportCallbackEXT_PostCall };
    PFN_DebugReportMessageEXT_PostCall DebugReportMessageEXT_PostCall { noop::DebugReportMessageEXT_PostCall };
    PFN_DebugMarkerSetObjectTagEXT_PostCall DebugMarkerSetObjectTagEXT_PostCall { noop::DebugMarkerSetObjectTagEXT_PostCall };
    PFN_DebugMarkerSetObjectNameEXT_PostCall DebugMarkerSetObjectNameEXT_PostCall { noop::DebugMarkerSetObjectNameEXT_PostCall };
    PFN_CmdDebugMarkerBeginEXT_PostCall CmdDebugMarkerBeginEXT_PostCall { noop::CmdDebugMarkerBeginEXT_PostCall };
    PFN_CmdDebugMarkerEndEXT_PostCall CmdDebugMarkerEndEXT_PostCall { noop::CmdDebugMarkerEndEXT_PostCall };
    PFN_CmdDebugMarkerInsertEXT_PostCall CmdDebugMarkerInsertEXT_PostCall { noop::CmdDebugMarkerInsertEXT_PostCall };
    PFN_CmdBindTransformFeedbackBuffersEXT_PostCall CmdBindTransformFeedbackBuffersEXT_PostCall { noop::CmdBindTransformFeedbackBuffersEXT_PostCall };
    PFN_CmdBeginTransformFeedbackEXT_PostCall CmdBeginTransformFeedbackEXT_PostCall { noop::CmdBeginTransformFeedbackEXT_PostCall };
    PFN_CmdEndTransformFeedbackEXT_PostCall CmdEndTransformFeedbackEXT_PostCall { noop::CmdEndTransformFeedbackEXT_PostCall };
    PFN_CmdBeginQueryIndexedEXT_PostCall CmdBeginQueryIndexedEXT_PostCall { noop::CmdBeginQueryIndexedEXT_PostCall };
    PFN_CmdEndQueryIndexedEXT_PostCall CmdEndQueryIndexedEXT_PostCall { noop::CmdEndQueryIndexedEXT_PostCall };
    PFN_CmdDrawIndirectByteCountEXT_PostCall CmdDrawIndirectByteCountEXT_PostCall { noop::CmdDrawIndirectByteCountEXT_PostCall };
    PFN_GetImageViewHandleNVX_PostCall GetImageViewHandleNVX_PostCall { noop::GetImageViewHandleNVX_PostCall };
    PFN_GetImageViewAddressNVX_PostCall GetImageViewAddressNVX_PostCall { noop::GetImageViewAddressNVX_PostCall };
    PFN_CmdDrawIndirectCountAMD_PostCall CmdDrawIndirectCountAMD_PostCall { noop::CmdDrawIndirectCountAMD_PostCall };
    PFN_CmdDrawIndexedIndirectCountAMD_PostCall CmdDrawIndexedIndirectCountAMD_PostCall { noop::CmdDrawIndexedIndirectCountAMD_PostCall };
    PFN_GetShaderInfoAMD_PostCall GetShaderInfoAMD_PostCall { noop::GetShaderInfoAMD_PostCall };
    PFN_CreateStreamDescriptorSurfaceGGP_PostCall CreateStreamDescriptorSurfaceGGP_PostCall { noop::CreateStreamDescriptorSurfaceGGP_PostCall };
    PFN_GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall { noop::GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall };
    PFN_GetMemoryWin32HandleNV_PostCall GetMemoryWin32HandleNV_PostCall { noop::GetMemoryWin32HandleNV_PostCall };
    PFN_CreateViSurfaceNN_PostCall CreateViSurfaceNN_PostCall { noop::CreateViSurfaceNN_PostCall };
    PFN_CmdBeginConditionalRenderingEXT_PostCall CmdBeginConditionalRenderingEXT_PostCall { noop::CmdBeginConditionalRenderingEXT_PostCall };
    PFN_CmdEndConditionalRenderingEXT_PostCall CmdEndConditionalRenderingEXT_PostCall { noop::CmdEndConditionalRenderingEXT_PostCall };
    PFN_CmdSetViewportWScalingNV_PostCall CmdSetViewportWScalingNV_PostCall { noop::CmdSetViewportWScalingNV_PostCall };
    PFN_ReleaseDisplayEXT_PostCall ReleaseDisplayEXT_PostCall { noop::ReleaseDisplayEXT_PostCall };
    PFN_AcquireXlibDisplayEXT_PostCall AcquireXlibDisplayEXT_PostCall { noop::AcquireXlibDisplayEXT_PostCall };
    PFN_GetRandROutputDisplayEXT_PostCall GetRandROutputDisplayEXT_PostCall { noop::GetRandROutputDisplayEXT_PostCall };
    PFN_GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall { noop::GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall };
    PFN_DisplayPowerControlEXT_PostCall DisplayPowerControlEXT_PostCall { noop::DisplayPowerControlEXT_PostCall };
    PFN_RegisterDeviceEventEXT_PostCall RegisterDeviceEventEXT_PostCall { noop::RegisterDeviceEventEXT_PostCall };
    PFN_RegisterDisplayEventEXT_PostCall RegisterDisplayEventEXT_PostCall { noop::RegisterDisplayEventEXT_PostCall };
    PFN_GetSwapchainCounterEXT_PostCall GetSwapchainCounterEXT_PostCall { noop::GetSwapchainCounterEXT_PostCall };
    PFN_GetRefreshCycleDurationGOOGLE_PostCall GetRefreshCycleDurationGOOGLE_PostCall { noop::GetRefreshCycleDurationGOOGLE_PostCall };
    PFN_GetPastPresentationTimingGOOGLE_PostCall GetPastPresentationTimingGOOGLE_PostCall { noop::GetPastPresentationTimingGOOGLE_PostCall };
    PFN_CmdSetDiscardRectangleEXT_PostCall CmdSetDiscardRectangleEXT_PostCall { noop::CmdSetDiscardRectangleEXT_PostCall };
    PFN_CmdSetDiscardRectangleEnableEXT_PostCall CmdSetDiscardRectangleEnableEXT_PostCall { noop::CmdSetDiscardRectangleEnableEXT_PostCall };
    PFN_CmdSetDiscardRectangleModeEXT_PostCall CmdSetDiscardRectangleModeEXT_PostCall { noop::CmdSetDiscardRectangleModeEXT_PostCall };
    PFN_SetHdrMetadataEXT_PostCall SetHdrMetadataEXT_PostCall { noop::SetHdrMetadataEXT_PostCall };
    PFN_CreateIOSSurfaceMVK_PostCall CreateIOSSurfaceMVK_PostCall { noop::CreateIOSSurfaceMVK_PostCall };
    PFN_CreateMacOSSurfaceMVK_PostCall CreateMacOSSurfaceMVK_PostCall { noop::CreateMacOSSurfaceMVK_PostCall };
    PFN_SetDebugUtilsObjectNameEXT_PostCall SetDebugUtilsObjectNameEXT_PostCall { noop::SetDebugUtilsObjectNameEXT_PostCall };
    PFN_SetDebugUtilsObjectTagEXT_PostCall SetDebugUtilsObjectTagEXT_PostCall { noop::SetDebugUtilsObjectTagEXT_PostCall };
    PFN_QueueBeginDebugUtilsLabelEXT_PostCall QueueBeginDebugUtilsLabelEXT_PostCall { noop::QueueBeginDebugUtilsLabelEXT_PostCall };
    PFN_QueueEndDebugUtilsLabelEXT_PostCall QueueEndDebugUtilsLabelEXT_PostCall { noop::QueueEndDebugUtilsLabelEXT_PostCall };
    PFN_QueueInsertDebugUtilsLabelEXT_PostCall QueueInsertDebugUtilsLabelEXT_PostCall { noop::QueueInsertDebugUtilsLabelEXT_PostCall };
    PFN_CmdBeginDebugUtilsLabelEXT_PostCall CmdBeginDebugUtilsLabelEXT_PostCall { noop::CmdBeginDebugUtilsLabelEXT_PostCall };
    PFN_CmdEndDebugUtilsLabelEXT_PostCall CmdEndDebugUtilsLabelEXT_PostCall { noop::CmdEndDebugUtilsLabelEXT_PostCall };
    PFN_CmdInsertDebugUtilsLabelEXT_PostCall CmdInsertDebugUtilsLabelEXT_PostCall { noop::CmdInsertDebugUtilsLabelEXT_PostCall };
    PFN_CreateDebugUtilsMessengerEXT_PostCall CreateDebugUtilsMessengerEXT_PostCall { noop::CreateDebugUtilsMessengerEXT_PostCall };
    PFN_DestroyDebugUtilsMessengerEXT_PostCall DestroyDebugUtilsMessengerEXT_PostCall { noop::DestroyDebugUtilsMessengerEXT_PostCall };
    PFN_SubmitDebugUtilsMessageEXT_PostCall SubmitDebugUtilsMessageEXT_PostCall { noop::SubmitDebugUtilsMessageEXT_PostCall };
    PFN_GetAndroidHardwareBufferPropertiesANDROID_PostCall GetAndroidHardwareBufferPropertiesANDROID_PostCall { noop::GetAndroidHardwareBufferPropertiesANDROID_PostCall };
    PFN_GetMemoryAndroidHardwareBufferANDROID_PostCall GetMemoryAndroidHardwareBufferANDROID_PostCall { noop::GetMemoryAndroidHardwareBufferANDROID_PostCall };
    PFN_CmdSetSampleLocationsEXT_PostCall CmdSetSampleLocationsEXT_PostCall { noop::CmdSetSampleLocationsEXT_PostCall };
    PFN_GetPhysicalDeviceMultisamplePropertiesEXT_PostCall GetPhysicalDeviceMultisamplePropertiesEXT_PostCall { noop::GetPhysicalDeviceMultisamplePropertiesEXT_PostCall };
    PFN_GetImageDrmFormatModifierPropertiesEXT_PostCall GetImageDrmFormatModifierPropertiesEXT_PostCall { noop::GetImageDrmFormatModifierPropertiesEXT_PostCall };
    PFN_CreateValidationCacheEXT_PostCall CreateValidationCacheEXT_PostCall { noop::CreateValidationCacheEXT_PostCall };
    PFN_DestroyValidationCacheEXT_PostCall DestroyValidationCacheEXT_PostCall { noop::DestroyValidationCacheEXT_PostCall };
    PFN_MergeValidationCachesEXT_PostCall MergeValidationCachesEXT_PostCall { noop::MergeValidationCachesEXT_PostCall };
    PFN_GetValidationCacheDataEXT_PostCall GetValidationCacheDataEXT_PostCall { noop::GetValidationCacheDataEXT_PostCall };
    PFN_CmdBindShadingRateImageNV_PostCall CmdBindShadingRateImageNV_PostCall { noop::CmdBindShadingRateImageNV_PostCall };
    PFN_CmdSetViewportShadingRatePaletteNV_PostCall CmdSetViewportShadingRatePaletteNV_PostCall { noop::CmdSetViewportShadingRatePaletteNV_PostCall };
    PFN_CmdSetCoarseSampleOrderNV_PostCall CmdSetCoarseSampleOrderNV_PostCall { noop::CmdSetCoarseSampleOrderNV_PostCall };
    PFN_CreateAccelerationStructureNV_PostCall CreateAccelerationStructureNV_PostCall { noop::CreateAccelerationStructureNV_PostCall };
    PFN_DestroyAccelerationStructureNV_PostCall DestroyAccelerationStructureNV_PostCall { noop::DestroyAccelerationStructureNV_PostCall };
    PFN_GetAccelerationStructureMemoryRequirementsNV_PostCall GetAccelerationStructureMemoryRequirementsNV_PostCall { noop::GetAccelerationStructureMemoryRequirementsNV_PostCall };
    PFN_BindAccelerationStructureMemoryNV_PostCall BindAccelerationStructureMemoryNV_PostCall { noop::BindAccelerationStructureMemoryNV_PostCall };
    PFN_CmdBuildAccelerationStructureNV_PostCall CmdBuildAccelerationStructureNV_PostCall { noop::CmdBuildAccelerationStructureNV_PostCall };
    PFN_CmdCopyAccelerationStructureNV_PostCall CmdCopyAccelerationStructureNV_PostCall { noop::CmdCopyAccelerationStructureNV_PostCall };
    PFN_CmdTraceRaysNV_PostCall CmdTraceRaysNV_PostCall { noop::CmdTraceRaysNV_PostCall };
    PFN_CreateRayTracingPipelinesNV_PostCall CreateRayTracingPipelinesNV_PostCall { noop::CreateRayTracingPipelinesNV_PostCall };
    PFN_GetRayTracingShaderGroupHandlesKHR_PostCall GetRayTracingShaderGroupHandlesKHR_PostCall { noop::GetRayTracingShaderGroupHandlesKHR_PostCall };
    PFN_GetRayTracingShaderGroupHandlesNV_PostCall GetRayTracingShaderGroupHandlesNV_PostCall { noop::GetRayTracingShaderGroupHandlesNV_PostCall };
    PFN_GetAccelerationStructureHandleNV_PostCall GetAccelerationStructureHandleNV_PostCall { noop::GetAccelerationStructureHandleNV_PostCall };
    PFN_CmdWriteAccelerationStructuresPropertiesNV_PostCall CmdWriteAccelerationStructuresPropertiesNV_PostCall { noop::CmdWriteAccelerationStructuresPropertiesNV_PostCall };
    PFN_CompileDeferredNV_PostCall CompileDeferredNV_PostCall { noop::CompileDeferredNV_PostCall };
    PFN_GetMemoryHostPointerPropertiesEXT_PostCall GetMemoryHostPointerPropertiesEXT_PostCall { noop::GetMemoryHostPointerPropertiesEXT_PostCall };
    PFN_CmdWriteBufferMarkerAMD_PostCall CmdWriteBufferMarkerAMD_PostCall { noop::CmdWriteBufferMarkerAMD_PostCall };
    PFN_GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall { noop::GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall };
    PFN_GetCalibratedTimestampsEXT_PostCall GetCalibratedTimestampsEXT_PostCall { noop::GetCalibratedTimestampsEXT_PostCall };
    PFN_CmdDrawMeshTasksNV_PostCall CmdDrawMeshTasksNV_PostCall { noop::CmdDrawMeshTasksNV_PostCall };
    PFN_CmdDrawMeshTasksIndirectNV_PostCall CmdDrawMeshTasksIndirectNV_PostCall { noop::CmdDrawMeshTasksIndirectNV_PostCall };
    PFN_CmdDrawMeshTasksIndirectCountNV_PostCall CmdDrawMeshTasksIndirectCountNV_PostCall { noop::CmdDrawMeshTasksIndirectCountNV_PostCall };
    PFN_CmdSetExclusiveScissorEnableNV_PostCall CmdSetExclusiveScissorEnableNV_PostCall { noop::CmdSetExclusiveScissorEnableNV_PostCall };
    PFN_CmdSetExclusiveScissorNV_PostCall CmdSetExclusiveScissorNV_PostCall { noop::CmdSetExclusiveScissorNV_PostCall };
    PFN_CmdSetCheckpointNV_PostCall CmdSetCheckpointNV_PostCall { noop::CmdSetCheckpointNV_PostCall };
    PFN_GetQueueCheckpointDataNV_PostCall GetQueueCheckpointDataNV_PostCall { noop::GetQueueCheckpointDataNV_PostCall };
    PFN_InitializePerformanceApiINTEL_PostCall InitializePerformanceApiINTEL_PostCall { noop::InitializePerformanceApiINTEL_PostCall };
    PFN_UninitializePerformanceApiINTEL_PostCall UninitializePerformanceApiINTEL_PostCall { noop::UninitializePerformanceApiINTEL_PostCall };
    PFN_CmdSetPerformanceMarkerINTEL_PostCall CmdSetPerformanceMarkerINTEL_PostCall { noop::CmdSetPerformanceMarkerINTEL_PostCall };
    PFN_CmdSetPerformanceStreamMarkerINTEL_PostCall CmdSetPerformanceStreamMarkerINTEL_PostCall { noop::CmdSetPerformanceStreamMarkerINTEL_PostCall };
    PFN_CmdSetPerformanceOverrideINTEL_PostCall CmdSetPerformanceOverrideINTEL_PostCall { noop::CmdSetPerformanceOverrideINTEL_PostCall };
    PFN_AcquirePerformanceConfigurationINTEL_PostCall AcquirePerformanceConfigurationINTEL_PostCall { noop::AcquirePerformanceConfigurationINTEL_PostCall };
    PFN_ReleasePerformanceConfigurationINTEL_PostCall ReleasePerformanceConfigurationINTEL_PostCall { noop::ReleasePerformanceConfigurationINTEL_PostCall };
    PFN_QueueSetPerformanceConfigurationINTEL_PostCall QueueSetPerformanceConfigurationINTEL_PostCall { noop::QueueSetPerformanceConfigurationINTEL_PostCall };
    PFN_GetPerformanceParameterINTEL_PostCall GetPerformanceParameterINTEL_PostCall { noop::GetPerformanceParameterINTEL_PostCall };
    PFN_SetLocalDimmingAMD_PostCall SetLocalDimmingAMD_PostCall { noop::SetLocalDimmingAMD_PostCall };
    PFN_CreateImagePipeSurfaceFUCHSIA_PostCall CreateImagePipeSurfaceFUCHSIA_PostCall { noop::CreateImagePipeSurfaceFUCHSIA_PostCall };
    PFN_CreateMetalSurfaceEXT_PostCall CreateMetalSurfaceEXT_PostCall { noop::CreateMetalSurfaceEXT_PostCall };
    PFN_GetBufferDeviceAddressEXT_PostCall GetBufferDeviceAddressEXT_PostCall { noop::GetBufferDeviceAddressEXT_PostCall };
    PFN_GetPhysicalDeviceToolPropertiesEXT_PostCall GetPhysicalDeviceToolPropertiesEXT_PostCall { noop::GetPhysicalDeviceToolPropertiesEXT_PostCall };
    PFN_GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall { noop::GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall };
    PFN_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall { noop::GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall };
    PFN_GetPhysicalDeviceSurfacePresentModes2EXT_PostCall GetPhysicalDeviceSurfacePresentModes2EXT_PostCall { noop::GetPhysicalDeviceSurfacePresentModes2EXT_PostCall };
    PFN_AcquireFullScreenExclusiveModeEXT_PostCall AcquireFullScreenExclusiveModeEXT_PostCall { noop::AcquireFullScreenExclusiveModeEXT_PostCall };
    PFN_ReleaseFullScreenExclusiveModeEXT_PostCall ReleaseFullScreenExclusiveModeEXT_PostCall { noop::ReleaseFullScreenExclusiveModeEXT_PostCall };
    PFN_GetDeviceGroupSurfacePresentModes2EXT_PostCall GetDeviceGroupSurfacePresentModes2EXT_PostCall { noop::GetDeviceGroupSurfacePresentModes2EXT_PostCall };
    PFN_CreateHeadlessSurfaceEXT_PostCall CreateHeadlessSurfaceEXT_PostCall { noop::CreateHeadlessSurfaceEXT_PostCall };
    PFN_CmdSetLineStippleEXT_PostCall CmdSetLineStippleEXT_PostCall { noop::CmdSetLineStippleEXT_PostCall };
    PFN_ResetQueryPoolEXT_PostCall ResetQueryPoolEXT_PostCall { noop::ResetQueryPoolEXT_PostCall };
    PFN_CmdSetCullModeEXT_PostCall CmdSetCullModeEXT_PostCall { noop::CmdSetCullModeEXT_PostCall };
    PFN_CmdSetFrontFaceEXT_PostCall CmdSetFrontFaceEXT_PostCall { noop::CmdSetFrontFaceEXT_PostCall };
    PFN_CmdSetPrimitiveTopologyEXT_PostCall CmdSetPrimitiveTopologyEXT_PostCall { noop::CmdSetPrimitiveTopologyEXT_PostCall };
    PFN_CmdSetViewportWithCountEXT_PostCall CmdSetViewportWithCountEXT_PostCall { noop::CmdSetViewportWithCountEXT_PostCall };
    PFN_CmdSetScissorWithCountEXT_PostCall CmdSetScissorWithCountEXT_PostCall { noop::CmdSetScissorWithCountEXT_PostCall };
    PFN_CmdBindVertexBuffers2EXT_PostCall CmdBindVertexBuffers2EXT_PostCall { noop::CmdBindVertexBuffers2EXT_PostCall };
    PFN_CmdSetDepthTestEnableEXT_PostCall CmdSetDepthTestEnableEXT_PostCall { noop::CmdSetDepthTestEnableEXT_PostCall };
    PFN_CmdSetDepthWriteEnableEXT_PostCall CmdSetDepthWriteEnableEXT_PostCall { noop::CmdSetDepthWriteEnableEXT_PostCall };
    PFN_CmdSetDepthCompareOpEXT_PostCall CmdSetDepthCompareOpEXT_PostCall { noop::CmdSetDepthCompareOpEXT_PostCall };
    PFN_CmdSetDepthBoundsTestEnableEXT_PostCall CmdSetDepthBoundsTestEnableEXT_PostCall { noop::CmdSetDepthBoundsTestEnableEXT_PostCall };
    PFN_CmdSetStencilTestEnableEXT_PostCall CmdSetStencilTestEnableEXT_PostCall { noop::CmdSetStencilTestEnableEXT_PostCall };
    PFN_CmdSetStencilOpEXT_PostCall CmdSetStencilOpEXT_PostCall { noop::CmdSetStencilOpEXT_PostCall };
    PFN_ReleaseSwapchainImagesEXT_PostCall ReleaseSwapchainImagesEXT_PostCall { noop::ReleaseSwapchainImagesEXT_PostCall };
    PFN_GetGeneratedCommandsMemoryRequirementsNV_PostCall GetGeneratedCommandsMemoryRequirementsNV_PostCall { noop::GetGeneratedCommandsMemoryRequirementsNV_PostCall };
    PFN_CmdPostprocessGeneratedCommandsNV_PostCall CmdPostprocessGeneratedCommandsNV_PostCall { noop::CmdPostprocessGeneratedCommandsNV_PostCall };
    PFN_CmdExecuteGeneratedCommandsNV_PostCall CmdExecuteGeneratedCommandsNV_PostCall { noop::CmdExecuteGeneratedCommandsNV_PostCall };
    PFN_CmdBindPipelineShaderGroupNV_PostCall CmdBindPipelineShaderGroupNV_PostCall { noop::CmdBindPipelineShaderGroupNV_PostCall };
    PFN_CreateIndirectCommandsLayoutNV_PostCall CreateIndirectCommandsLayoutNV_PostCall { noop::CreateIndirectCommandsLayoutNV_PostCall };
    PFN_DestroyIndirectCommandsLayoutNV_PostCall DestroyIndirectCommandsLayoutNV_PostCall { noop::DestroyIndirectCommandsLayoutNV_PostCall };
    PFN_AcquireDrmDisplayEXT_PostCall AcquireDrmDisplayEXT_PostCall { noop::AcquireDrmDisplayEXT_PostCall };
    PFN_GetDrmDisplayEXT_PostCall GetDrmDisplayEXT_PostCall { noop::GetDrmDisplayEXT_PostCall };
    PFN_CreatePrivateDataSlotEXT_PostCall CreatePrivateDataSlotEXT_PostCall { noop::CreatePrivateDataSlotEXT_PostCall };
    PFN_DestroyPrivateDataSlotEXT_PostCall DestroyPrivateDataSlotEXT_PostCall { noop::DestroyPrivateDataSlotEXT_PostCall };
    PFN_SetPrivateDataEXT_PostCall SetPrivateDataEXT_PostCall { noop::SetPrivateDataEXT_PostCall };
    PFN_GetPrivateDataEXT_PostCall GetPrivateDataEXT_PostCall { noop::GetPrivateDataEXT_PostCall };
    PFN_CmdSetFragmentShadingRateEnumNV_PostCall CmdSetFragmentShadingRateEnumNV_PostCall { noop::CmdSetFragmentShadingRateEnumNV_PostCall };
    PFN_GetImageSubresourceLayout2EXT_PostCall GetImageSubresourceLayout2EXT_PostCall { noop::GetImageSubresourceLayout2EXT_PostCall };
    PFN_GetDeviceFaultInfoEXT_PostCall GetDeviceFaultInfoEXT_PostCall { noop::GetDeviceFaultInfoEXT_PostCall };
    PFN_AcquireWinrtDisplayNV_PostCall AcquireWinrtDisplayNV_PostCall { noop::AcquireWinrtDisplayNV_PostCall };
    PFN_GetWinrtDisplayNV_PostCall GetWinrtDisplayNV_PostCall { noop::GetWinrtDisplayNV_PostCall };
    PFN_CreateDirectFBSurfaceEXT_PostCall CreateDirectFBSurfaceEXT_PostCall { noop::CreateDirectFBSurfaceEXT_PostCall };
    PFN_GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall { noop::GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall };
    PFN_CmdSetVertexInputEXT_PostCall CmdSetVertexInputEXT_PostCall { noop::CmdSetVertexInputEXT_PostCall };
    PFN_GetMemoryZirconHandleFUCHSIA_PostCall GetMemoryZirconHandleFUCHSIA_PostCall { noop::GetMemoryZirconHandleFUCHSIA_PostCall };
    PFN_GetMemoryZirconHandlePropertiesFUCHSIA_PostCall GetMemoryZirconHandlePropertiesFUCHSIA_PostCall { noop::GetMemoryZirconHandlePropertiesFUCHSIA_PostCall };
    PFN_ImportSemaphoreZirconHandleFUCHSIA_PostCall ImportSemaphoreZirconHandleFUCHSIA_PostCall { noop::ImportSemaphoreZirconHandleFUCHSIA_PostCall };
    PFN_GetSemaphoreZirconHandleFUCHSIA_PostCall GetSemaphoreZirconHandleFUCHSIA_PostCall { noop::GetSemaphoreZirconHandleFUCHSIA_PostCall };
    PFN_CmdBindInvocationMaskHUAWEI_PostCall CmdBindInvocationMaskHUAWEI_PostCall { noop::CmdBindInvocationMaskHUAWEI_PostCall };
    PFN_GetMemoryRemoteAddressNV_PostCall GetMemoryRemoteAddressNV_PostCall { noop::GetMemoryRemoteAddressNV_PostCall };
    PFN_CmdSetPatchControlPointsEXT_PostCall CmdSetPatchControlPointsEXT_PostCall { noop::CmdSetPatchControlPointsEXT_PostCall };
    PFN_CmdSetRasterizerDiscardEnableEXT_PostCall CmdSetRasterizerDiscardEnableEXT_PostCall { noop::CmdSetRasterizerDiscardEnableEXT_PostCall };
    PFN_CmdSetDepthBiasEnableEXT_PostCall CmdSetDepthBiasEnableEXT_PostCall { noop::CmdSetDepthBiasEnableEXT_PostCall };
    PFN_CmdSetLogicOpEXT_PostCall CmdSetLogicOpEXT_PostCall { noop::CmdSetLogicOpEXT_PostCall };
    PFN_CmdSetPrimitiveRestartEnableEXT_PostCall CmdSetPrimitiveRestartEnableEXT_PostCall { noop::CmdSetPrimitiveRestartEnableEXT_PostCall };
    PFN_CreateScreenSurfaceQNX_PostCall CreateScreenSurfaceQNX_PostCall { noop::CreateScreenSurfaceQNX_PostCall };
    PFN_GetPhysicalDeviceScreenPresentationSupportQNX_PostCall GetPhysicalDeviceScreenPresentationSupportQNX_PostCall { noop::GetPhysicalDeviceScreenPresentationSupportQNX_PostCall };
    PFN_CmdSetColorWriteEnableEXT_PostCall CmdSetColorWriteEnableEXT_PostCall { noop::CmdSetColorWriteEnableEXT_PostCall };
    PFN_CmdDrawMultiEXT_PostCall CmdDrawMultiEXT_PostCall { noop::CmdDrawMultiEXT_PostCall };
    PFN_CmdDrawMultiIndexedEXT_PostCall CmdDrawMultiIndexedEXT_PostCall { noop::CmdDrawMultiIndexedEXT_PostCall };
    PFN_CreateMicromapEXT_PostCall CreateMicromapEXT_PostCall { noop::CreateMicromapEXT_PostCall };
    PFN_DestroyMicromapEXT_PostCall DestroyMicromapEXT_PostCall { noop::DestroyMicromapEXT_PostCall };
    PFN_CmdBuildMicromapsEXT_PostCall CmdBuildMicromapsEXT_PostCall { noop::CmdBuildMicromapsEXT_PostCall };
    PFN_BuildMicromapsEXT_PostCall BuildMicromapsEXT_PostCall { noop::BuildMicromapsEXT_PostCall };
    PFN_CopyMicromapEXT_PostCall CopyMicromapEXT_PostCall { noop::CopyMicromapEXT_PostCall };
    PFN_CopyMicromapToMemoryEXT_PostCall CopyMicromapToMemoryEXT_PostCall { noop::CopyMicromapToMemoryEXT_PostCall };
    PFN_CopyMemoryToMicromapEXT_PostCall CopyMemoryToMicromapEXT_PostCall { noop::CopyMemoryToMicromapEXT_PostCall };
    PFN_WriteMicromapsPropertiesEXT_PostCall WriteMicromapsPropertiesEXT_PostCall { noop::WriteMicromapsPropertiesEXT_PostCall };
    PFN_CmdCopyMicromapEXT_PostCall CmdCopyMicromapEXT_PostCall { noop::CmdCopyMicromapEXT_PostCall };
    PFN_CmdCopyMicromapToMemoryEXT_PostCall CmdCopyMicromapToMemoryEXT_PostCall { noop::CmdCopyMicromapToMemoryEXT_PostCall };
    PFN_CmdCopyMemoryToMicromapEXT_PostCall CmdCopyMemoryToMicromapEXT_PostCall { noop::CmdCopyMemoryToMicromapEXT_PostCall };
    PFN_CmdWriteMicromapsPropertiesEXT_PostCall CmdWriteMicromapsPropertiesEXT_PostCall { noop::CmdWriteMicromapsPropertiesEXT_PostCall };
    PFN_GetDeviceMicromapCompatibilityEXT_PostCall GetDeviceMicromapCompatibilityEXT_PostCall { noop::GetDeviceMicromapCompatibilityEXT_PostCall };
    PFN_GetMicromapBuildSizesEXT_PostCall GetMicromapBuildSizesEXT_PostCall { noop::GetMicromapBuildSizesEXT_PostCall };
    PFN_CmdDrawClusterHUAWEI_PostCall CmdDrawClusterHUAWEI_PostCall { noop::CmdDrawClusterHUAWEI_PostCall };
    PFN_CmdDrawClusterIndirectHUAWEI_PostCall CmdDrawClusterIndirectHUAWEI_PostCall { noop::CmdDrawClusterIndirectHUAWEI_PostCall };
    PFN_SetDeviceMemoryPriorityEXT_PostCall SetDeviceMemoryPriorityEXT_PostCall { noop::SetDeviceMemoryPriorityEXT_PostCall };
    PFN_GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall { noop::GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall };
    PFN_GetDescriptorSetHostMappingVALVE_PostCall GetDescriptorSetHostMappingVALVE_PostCall { noop::GetDescriptorSetHostMappingVALVE_PostCall };
    PFN_CmdSetTessellationDomainOriginEXT_PostCall CmdSetTessellationDomainOriginEXT_PostCall { noop::CmdSetTessellationDomainOriginEXT_PostCall };
    PFN_CmdSetDepthClampEnableEXT_PostCall CmdSetDepthClampEnableEXT_PostCall { noop::CmdSetDepthClampEnableEXT_PostCall };
    PFN_CmdSetPolygonModeEXT_PostCall CmdSetPolygonModeEXT_PostCall { noop::CmdSetPolygonModeEXT_PostCall };
    PFN_CmdSetRasterizationSamplesEXT_PostCall CmdSetRasterizationSamplesEXT_PostCall { noop::CmdSetRasterizationSamplesEXT_PostCall };
    PFN_CmdSetSampleMaskEXT_PostCall CmdSetSampleMaskEXT_PostCall { noop::CmdSetSampleMaskEXT_PostCall };
    PFN_CmdSetAlphaToCoverageEnableEXT_PostCall CmdSetAlphaToCoverageEnableEXT_PostCall { noop::CmdSetAlphaToCoverageEnableEXT_PostCall };
    PFN_CmdSetAlphaToOneEnableEXT_PostCall CmdSetAlphaToOneEnableEXT_PostCall { noop::CmdSetAlphaToOneEnableEXT_PostCall };
    PFN_CmdSetLogicOpEnableEXT_PostCall CmdSetLogicOpEnableEXT_PostCall { noop::CmdSetLogicOpEnableEXT_PostCall };
    PFN_CmdSetColorBlendEnableEXT_PostCall CmdSetColorBlendEnableEXT_PostCall { noop::CmdSetColorBlendEnableEXT_PostCall };
    PFN_CmdSetColorBlendEquationEXT_PostCall CmdSetColorBlendEquationEXT_PostCall { noop::CmdSetColorBlendEquationEXT_PostCall };
    PFN_CmdSetColorWriteMaskEXT_PostCall CmdSetColorWriteMaskEXT_PostCall { noop::CmdSetColorWriteMaskEXT_PostCall };
    PFN_CmdSetRasterizationStreamEXT_PostCall CmdSetRasterizationStreamEXT_PostCall { noop::CmdSetRasterizationStreamEXT_PostCall };
    PFN_CmdSetConservativeRasterizationModeEXT_PostCall CmdSetConservativeRasterizationModeEXT_PostCall { noop::CmdSetConservativeRasterizationModeEXT_PostCall };
    PFN_CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall { noop::CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall };
    PFN_CmdSetDepthClipEnableEXT_PostCall CmdSetDepthClipEnableEXT_PostCall { noop::CmdSetDepthClipEnableEXT_PostCall };
    PFN_CmdSetSampleLocationsEnableEXT_PostCall CmdSetSampleLocationsEnableEXT_PostCall { noop::CmdSetSampleLocationsEnableEXT_PostCall };
    PFN_CmdSetColorBlendAdvancedEXT_PostCall CmdSetColorBlendAdvancedEXT_PostCall { noop::CmdSetColorBlendAdvancedEXT_PostCall };
    PFN_CmdSetProvokingVertexModeEXT_PostCall CmdSetProvokingVertexModeEXT_PostCall { noop::CmdSetProvokingVertexModeEXT_PostCall };
    PFN_CmdSetLineRasterizationModeEXT_PostCall CmdSetLineRasterizationModeEXT_PostCall { noop::CmdSetLineRasterizationModeEXT_PostCall };
    PFN_CmdSetLineStippleEnableEXT_PostCall CmdSetLineStippleEnableEXT_PostCall { noop::CmdSetLineStippleEnableEXT_PostCall };
    PFN_CmdSetDepthClipNegativeOneToOneEXT_PostCall CmdSetDepthClipNegativeOneToOneEXT_PostCall { noop::CmdSetDepthClipNegativeOneToOneEXT_PostCall };
    PFN_CmdSetViewportWScalingEnableNV_PostCall CmdSetViewportWScalingEnableNV_PostCall { noop::CmdSetViewportWScalingEnableNV_PostCall };
    PFN_CmdSetViewportSwizzleNV_PostCall CmdSetViewportSwizzleNV_PostCall { noop::CmdSetViewportSwizzleNV_PostCall };
    PFN_CmdSetCoverageToColorEnableNV_PostCall CmdSetCoverageToColorEnableNV_PostCall { noop::CmdSetCoverageToColorEnableNV_PostCall };
    PFN_CmdSetCoverageToColorLocationNV_PostCall CmdSetCoverageToColorLocationNV_PostCall { noop::CmdSetCoverageToColorLocationNV_PostCall };
    PFN_CmdSetCoverageModulationModeNV_PostCall CmdSetCoverageModulationModeNV_PostCall { noop::CmdSetCoverageModulationModeNV_PostCall };
    PFN_CmdSetCoverageModulationTableEnableNV_PostCall CmdSetCoverageModulationTableEnableNV_PostCall { noop::CmdSetCoverageModulationTableEnableNV_PostCall };
    PFN_CmdSetCoverageModulationTableNV_PostCall CmdSetCoverageModulationTableNV_PostCall { noop::CmdSetCoverageModulationTableNV_PostCall };
    PFN_CmdSetShadingRateImageEnableNV_PostCall CmdSetShadingRateImageEnableNV_PostCall { noop::CmdSetShadingRateImageEnableNV_PostCall };
    PFN_CmdSetRepresentativeFragmentTestEnableNV_PostCall CmdSetRepresentativeFragmentTestEnableNV_PostCall { noop::CmdSetRepresentativeFragmentTestEnableNV_PostCall };
    PFN_CmdSetCoverageReductionModeNV_PostCall CmdSetCoverageReductionModeNV_PostCall { noop::CmdSetCoverageReductionModeNV_PostCall };
    PFN_GetShaderModuleIdentifierEXT_PostCall GetShaderModuleIdentifierEXT_PostCall { noop::GetShaderModuleIdentifierEXT_PostCall };
    PFN_GetShaderModuleCreateInfoIdentifierEXT_PostCall GetShaderModuleCreateInfoIdentifierEXT_PostCall { noop::GetShaderModuleCreateInfoIdentifierEXT_PostCall };
    PFN_GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall { noop::GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall };
    PFN_CreateOpticalFlowSessionNV_PostCall CreateOpticalFlowSessionNV_PostCall { noop::CreateOpticalFlowSessionNV_PostCall };
    PFN_DestroyOpticalFlowSessionNV_PostCall DestroyOpticalFlowSessionNV_PostCall { noop::DestroyOpticalFlowSessionNV_PostCall };
    PFN_BindOpticalFlowSessionImageNV_PostCall BindOpticalFlowSessionImageNV_PostCall { noop::BindOpticalFlowSessionImageNV_PostCall };
    PFN_CmdOpticalFlowExecuteNV_PostCall CmdOpticalFlowExecuteNV_PostCall { noop::CmdOpticalFlowExecuteNV_PostCall };
    PFN_GetFramebufferTilePropertiesQCOM_PostCall GetFramebufferTilePropertiesQCOM_PostCall { noop::GetFramebufferTilePropertiesQCOM_PostCall };
    PFN_GetDynamicRenderingTilePropertiesQCOM_PostCall GetDynamicRenderingTilePropertiesQCOM_PostCall { noop::GetDynamicRenderingTilePropertiesQCOM_PostCall };
    PFN_CreateAccelerationStructureKHR_PostCall CreateAccelerationStructureKHR_PostCall { noop::CreateAccelerationStructureKHR_PostCall };
    PFN_DestroyAccelerationStructureKHR_PostCall DestroyAccelerationStructureKHR_PostCall { noop::DestroyAccelerationStructureKHR_PostCall };
    PFN_CmdBuildAccelerationStructuresKHR_PostCall CmdBuildAccelerationStructuresKHR_PostCall { noop::CmdBuildAccelerationStructuresKHR_PostCall };
    PFN_CmdBuildAccelerationStructuresIndirectKHR_PostCall CmdBuildAccelerationStructuresIndirectKHR_PostCall { noop::CmdBuildAccelerationStructuresIndirectKHR_PostCall };
    PFN_CopyAccelerationStructureToMemoryKHR_PostCall CopyAccelerationStructureToMemoryKHR_PostCall { noop::CopyAccelerationStructureToMemoryKHR_PostCall };
    PFN_CopyMemoryToAccelerationStructureKHR_PostCall CopyMemoryToAccelerationStructureKHR_PostCall { noop::CopyMemoryToAccelerationStructureKHR_PostCall };
    PFN_WriteAccelerationStructuresPropertiesKHR_PostCall WriteAccelerationStructuresPropertiesKHR_PostCall { noop::WriteAccelerationStructuresPropertiesKHR_PostCall };
    PFN_CmdCopyAccelerationStructureKHR_PostCall CmdCopyAccelerationStructureKHR_PostCall { noop::CmdCopyAccelerationStructureKHR_PostCall };
    PFN_CmdCopyAccelerationStructureToMemoryKHR_PostCall CmdCopyAccelerationStructureToMemoryKHR_PostCall { noop::CmdCopyAccelerationStructureToMemoryKHR_PostCall };
    PFN_CmdCopyMemoryToAccelerationStructureKHR_PostCall CmdCopyMemoryToAccelerationStructureKHR_PostCall { noop::CmdCopyMemoryToAccelerationStructureKHR_PostCall };
    PFN_GetAccelerationStructureDeviceAddressKHR_PostCall GetAccelerationStructureDeviceAddressKHR_PostCall { noop::GetAccelerationStructureDeviceAddressKHR_PostCall };
    PFN_CmdWriteAccelerationStructuresPropertiesKHR_PostCall CmdWriteAccelerationStructuresPropertiesKHR_PostCall { noop::CmdWriteAccelerationStructuresPropertiesKHR_PostCall };
    PFN_GetDeviceAccelerationStructureCompatibilityKHR_PostCall GetDeviceAccelerationStructureCompatibilityKHR_PostCall { noop::GetDeviceAccelerationStructureCompatibilityKHR_PostCall };
    PFN_GetAccelerationStructureBuildSizesKHR_PostCall GetAccelerationStructureBuildSizesKHR_PostCall { noop::GetAccelerationStructureBuildSizesKHR_PostCall };
    PFN_CmdTraceRaysKHR_PostCall CmdTraceRaysKHR_PostCall { noop::CmdTraceRaysKHR_PostCall };
    PFN_CreateRayTracingPipelinesKHR_PostCall CreateRayTracingPipelinesKHR_PostCall { noop::CreateRayTracingPipelinesKHR_PostCall };
    PFN_GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall { noop::GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall };
    PFN_CmdTraceRaysIndirectKHR_PostCall CmdTraceRaysIndirectKHR_PostCall { noop::CmdTraceRaysIndirectKHR_PostCall };
    PFN_GetRayTracingShaderGroupStackSizeKHR_PostCall GetRayTracingShaderGroupStackSizeKHR_PostCall { noop::GetRayTracingShaderGroupStackSizeKHR_PostCall };
    PFN_CmdSetRayTracingPipelineStackSizeKHR_PostCall CmdSetRayTracingPipelineStackSizeKHR_PostCall { noop::CmdSetRayTracingPipelineStackSizeKHR_PostCall };
    PFN_CmdDrawMeshTasksEXT_PostCall CmdDrawMeshTasksEXT_PostCall { noop::CmdDrawMeshTasksEXT_PostCall };
    PFN_CmdDrawMeshTasksIndirectEXT_PostCall CmdDrawMeshTasksIndirectEXT_PostCall { noop::CmdDrawMeshTasksIndirectEXT_PostCall };
    PFN_CmdDrawMeshTasksIndirectCountEXT_PostCall CmdDrawMeshTasksIndirectCountEXT_PostCall { noop::CmdDrawMeshTasksIndirectCountEXT_PostCall };
};
// clang-format on

template <typename FuncP>
static void LoadPostFunction(util::platform::GetProcAddress_t gpa, util::platform::LibraryHandle handle, const char* name, FuncP* funcp)
{
    FuncP result = reinterpret_cast<FuncP>(gpa(handle, name));
    if (result)
    {
        *funcp = result;
    }
}

// clang-format off
static void LoadPostFunctionTable(util::platform::GetProcAddress_t gpa, util::platform::LibraryHandle handle, plugin_func_table_post *table)
{
    assert(gpa);
    assert(handle);
    assert(table);

    LoadPostFunction(gpa, handle, "CreateInstance_PostCall", &table->CreateInstance_PostCall);
    LoadPostFunction(gpa, handle, "DestroyInstance_PostCall", &table->DestroyInstance_PostCall);
    LoadPostFunction(gpa, handle, "EnumeratePhysicalDevices_PostCall", &table->EnumeratePhysicalDevices_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFeatures_PostCall", &table->GetPhysicalDeviceFeatures_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFormatProperties_PostCall", &table->GetPhysicalDeviceFormatProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceImageFormatProperties_PostCall", &table->GetPhysicalDeviceImageFormatProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceProperties_PostCall", &table->GetPhysicalDeviceProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceQueueFamilyProperties_PostCall", &table->GetPhysicalDeviceQueueFamilyProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceMemoryProperties_PostCall", &table->GetPhysicalDeviceMemoryProperties_PostCall);
    LoadPostFunction(gpa, handle, "CreateDevice_PostCall", &table->CreateDevice_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDevice_PostCall", &table->DestroyDevice_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceQueue_PostCall", &table->GetDeviceQueue_PostCall);
    LoadPostFunction(gpa, handle, "QueueSubmit_PostCall", &table->QueueSubmit_PostCall);
    LoadPostFunction(gpa, handle, "QueueWaitIdle_PostCall", &table->QueueWaitIdle_PostCall);
    LoadPostFunction(gpa, handle, "DeviceWaitIdle_PostCall", &table->DeviceWaitIdle_PostCall);
    LoadPostFunction(gpa, handle, "AllocateMemory_PostCall", &table->AllocateMemory_PostCall);
    LoadPostFunction(gpa, handle, "FreeMemory_PostCall", &table->FreeMemory_PostCall);
    LoadPostFunction(gpa, handle, "MapMemory_PostCall", &table->MapMemory_PostCall);
    LoadPostFunction(gpa, handle, "UnmapMemory_PostCall", &table->UnmapMemory_PostCall);
    LoadPostFunction(gpa, handle, "FlushMappedMemoryRanges_PostCall", &table->FlushMappedMemoryRanges_PostCall);
    LoadPostFunction(gpa, handle, "InvalidateMappedMemoryRanges_PostCall", &table->InvalidateMappedMemoryRanges_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceMemoryCommitment_PostCall", &table->GetDeviceMemoryCommitment_PostCall);
    LoadPostFunction(gpa, handle, "BindBufferMemory_PostCall", &table->BindBufferMemory_PostCall);
    LoadPostFunction(gpa, handle, "BindImageMemory_PostCall", &table->BindImageMemory_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferMemoryRequirements_PostCall", &table->GetBufferMemoryRequirements_PostCall);
    LoadPostFunction(gpa, handle, "GetImageMemoryRequirements_PostCall", &table->GetImageMemoryRequirements_PostCall);
    LoadPostFunction(gpa, handle, "GetImageSparseMemoryRequirements_PostCall", &table->GetImageSparseMemoryRequirements_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSparseImageFormatProperties_PostCall", &table->GetPhysicalDeviceSparseImageFormatProperties_PostCall);
    LoadPostFunction(gpa, handle, "QueueBindSparse_PostCall", &table->QueueBindSparse_PostCall);
    LoadPostFunction(gpa, handle, "CreateFence_PostCall", &table->CreateFence_PostCall);
    LoadPostFunction(gpa, handle, "DestroyFence_PostCall", &table->DestroyFence_PostCall);
    LoadPostFunction(gpa, handle, "ResetFences_PostCall", &table->ResetFences_PostCall);
    LoadPostFunction(gpa, handle, "GetFenceStatus_PostCall", &table->GetFenceStatus_PostCall);
    LoadPostFunction(gpa, handle, "WaitForFences_PostCall", &table->WaitForFences_PostCall);
    LoadPostFunction(gpa, handle, "CreateSemaphore_PostCall", &table->CreateSemaphore_PostCall);
    LoadPostFunction(gpa, handle, "DestroySemaphore_PostCall", &table->DestroySemaphore_PostCall);
    LoadPostFunction(gpa, handle, "CreateEvent_PostCall", &table->CreateEvent_PostCall);
    LoadPostFunction(gpa, handle, "DestroyEvent_PostCall", &table->DestroyEvent_PostCall);
    LoadPostFunction(gpa, handle, "GetEventStatus_PostCall", &table->GetEventStatus_PostCall);
    LoadPostFunction(gpa, handle, "SetEvent_PostCall", &table->SetEvent_PostCall);
    LoadPostFunction(gpa, handle, "ResetEvent_PostCall", &table->ResetEvent_PostCall);
    LoadPostFunction(gpa, handle, "CreateQueryPool_PostCall", &table->CreateQueryPool_PostCall);
    LoadPostFunction(gpa, handle, "DestroyQueryPool_PostCall", &table->DestroyQueryPool_PostCall);
    LoadPostFunction(gpa, handle, "GetQueryPoolResults_PostCall", &table->GetQueryPoolResults_PostCall);
    LoadPostFunction(gpa, handle, "CreateBuffer_PostCall", &table->CreateBuffer_PostCall);
    LoadPostFunction(gpa, handle, "DestroyBuffer_PostCall", &table->DestroyBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CreateBufferView_PostCall", &table->CreateBufferView_PostCall);
    LoadPostFunction(gpa, handle, "DestroyBufferView_PostCall", &table->DestroyBufferView_PostCall);
    LoadPostFunction(gpa, handle, "CreateImage_PostCall", &table->CreateImage_PostCall);
    LoadPostFunction(gpa, handle, "DestroyImage_PostCall", &table->DestroyImage_PostCall);
    LoadPostFunction(gpa, handle, "GetImageSubresourceLayout_PostCall", &table->GetImageSubresourceLayout_PostCall);
    LoadPostFunction(gpa, handle, "CreateImageView_PostCall", &table->CreateImageView_PostCall);
    LoadPostFunction(gpa, handle, "DestroyImageView_PostCall", &table->DestroyImageView_PostCall);
    LoadPostFunction(gpa, handle, "CreateShaderModule_PostCall", &table->CreateShaderModule_PostCall);
    LoadPostFunction(gpa, handle, "DestroyShaderModule_PostCall", &table->DestroyShaderModule_PostCall);
    LoadPostFunction(gpa, handle, "CreatePipelineCache_PostCall", &table->CreatePipelineCache_PostCall);
    LoadPostFunction(gpa, handle, "DestroyPipelineCache_PostCall", &table->DestroyPipelineCache_PostCall);
    LoadPostFunction(gpa, handle, "GetPipelineCacheData_PostCall", &table->GetPipelineCacheData_PostCall);
    LoadPostFunction(gpa, handle, "MergePipelineCaches_PostCall", &table->MergePipelineCaches_PostCall);
    LoadPostFunction(gpa, handle, "CreateGraphicsPipelines_PostCall", &table->CreateGraphicsPipelines_PostCall);
    LoadPostFunction(gpa, handle, "CreateComputePipelines_PostCall", &table->CreateComputePipelines_PostCall);
    LoadPostFunction(gpa, handle, "DestroyPipeline_PostCall", &table->DestroyPipeline_PostCall);
    LoadPostFunction(gpa, handle, "CreatePipelineLayout_PostCall", &table->CreatePipelineLayout_PostCall);
    LoadPostFunction(gpa, handle, "DestroyPipelineLayout_PostCall", &table->DestroyPipelineLayout_PostCall);
    LoadPostFunction(gpa, handle, "CreateSampler_PostCall", &table->CreateSampler_PostCall);
    LoadPostFunction(gpa, handle, "DestroySampler_PostCall", &table->DestroySampler_PostCall);
    LoadPostFunction(gpa, handle, "CreateDescriptorSetLayout_PostCall", &table->CreateDescriptorSetLayout_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDescriptorSetLayout_PostCall", &table->DestroyDescriptorSetLayout_PostCall);
    LoadPostFunction(gpa, handle, "CreateDescriptorPool_PostCall", &table->CreateDescriptorPool_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDescriptorPool_PostCall", &table->DestroyDescriptorPool_PostCall);
    LoadPostFunction(gpa, handle, "ResetDescriptorPool_PostCall", &table->ResetDescriptorPool_PostCall);
    LoadPostFunction(gpa, handle, "AllocateDescriptorSets_PostCall", &table->AllocateDescriptorSets_PostCall);
    LoadPostFunction(gpa, handle, "FreeDescriptorSets_PostCall", &table->FreeDescriptorSets_PostCall);
    LoadPostFunction(gpa, handle, "UpdateDescriptorSets_PostCall", &table->UpdateDescriptorSets_PostCall);
    LoadPostFunction(gpa, handle, "CreateFramebuffer_PostCall", &table->CreateFramebuffer_PostCall);
    LoadPostFunction(gpa, handle, "DestroyFramebuffer_PostCall", &table->DestroyFramebuffer_PostCall);
    LoadPostFunction(gpa, handle, "CreateRenderPass_PostCall", &table->CreateRenderPass_PostCall);
    LoadPostFunction(gpa, handle, "DestroyRenderPass_PostCall", &table->DestroyRenderPass_PostCall);
    LoadPostFunction(gpa, handle, "GetRenderAreaGranularity_PostCall", &table->GetRenderAreaGranularity_PostCall);
    LoadPostFunction(gpa, handle, "CreateCommandPool_PostCall", &table->CreateCommandPool_PostCall);
    LoadPostFunction(gpa, handle, "DestroyCommandPool_PostCall", &table->DestroyCommandPool_PostCall);
    LoadPostFunction(gpa, handle, "ResetCommandPool_PostCall", &table->ResetCommandPool_PostCall);
    LoadPostFunction(gpa, handle, "AllocateCommandBuffers_PostCall", &table->AllocateCommandBuffers_PostCall);
    LoadPostFunction(gpa, handle, "FreeCommandBuffers_PostCall", &table->FreeCommandBuffers_PostCall);
    LoadPostFunction(gpa, handle, "BeginCommandBuffer_PostCall", &table->BeginCommandBuffer_PostCall);
    LoadPostFunction(gpa, handle, "EndCommandBuffer_PostCall", &table->EndCommandBuffer_PostCall);
    LoadPostFunction(gpa, handle, "ResetCommandBuffer_PostCall", &table->ResetCommandBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindPipeline_PostCall", &table->CmdBindPipeline_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewport_PostCall", &table->CmdSetViewport_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetScissor_PostCall", &table->CmdSetScissor_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetLineWidth_PostCall", &table->CmdSetLineWidth_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthBias_PostCall", &table->CmdSetDepthBias_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetBlendConstants_PostCall", &table->CmdSetBlendConstants_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthBounds_PostCall", &table->CmdSetDepthBounds_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilCompareMask_PostCall", &table->CmdSetStencilCompareMask_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilWriteMask_PostCall", &table->CmdSetStencilWriteMask_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilReference_PostCall", &table->CmdSetStencilReference_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindDescriptorSets_PostCall", &table->CmdBindDescriptorSets_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindIndexBuffer_PostCall", &table->CmdBindIndexBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindVertexBuffers_PostCall", &table->CmdBindVertexBuffers_PostCall);
    LoadPostFunction(gpa, handle, "CmdDraw_PostCall", &table->CmdDraw_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndexed_PostCall", &table->CmdDrawIndexed_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndirect_PostCall", &table->CmdDrawIndirect_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndexedIndirect_PostCall", &table->CmdDrawIndexedIndirect_PostCall);
    LoadPostFunction(gpa, handle, "CmdDispatch_PostCall", &table->CmdDispatch_PostCall);
    LoadPostFunction(gpa, handle, "CmdDispatchIndirect_PostCall", &table->CmdDispatchIndirect_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyBuffer_PostCall", &table->CmdCopyBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyImage_PostCall", &table->CmdCopyImage_PostCall);
    LoadPostFunction(gpa, handle, "CmdBlitImage_PostCall", &table->CmdBlitImage_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyBufferToImage_PostCall", &table->CmdCopyBufferToImage_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyImageToBuffer_PostCall", &table->CmdCopyImageToBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CmdUpdateBuffer_PostCall", &table->CmdUpdateBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CmdFillBuffer_PostCall", &table->CmdFillBuffer_PostCall);
    LoadPostFunction(gpa, handle, "CmdClearColorImage_PostCall", &table->CmdClearColorImage_PostCall);
    LoadPostFunction(gpa, handle, "CmdClearDepthStencilImage_PostCall", &table->CmdClearDepthStencilImage_PostCall);
    LoadPostFunction(gpa, handle, "CmdClearAttachments_PostCall", &table->CmdClearAttachments_PostCall);
    LoadPostFunction(gpa, handle, "CmdResolveImage_PostCall", &table->CmdResolveImage_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetEvent_PostCall", &table->CmdSetEvent_PostCall);
    LoadPostFunction(gpa, handle, "CmdResetEvent_PostCall", &table->CmdResetEvent_PostCall);
    LoadPostFunction(gpa, handle, "CmdWaitEvents_PostCall", &table->CmdWaitEvents_PostCall);
    LoadPostFunction(gpa, handle, "CmdPipelineBarrier_PostCall", &table->CmdPipelineBarrier_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginQuery_PostCall", &table->CmdBeginQuery_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndQuery_PostCall", &table->CmdEndQuery_PostCall);
    LoadPostFunction(gpa, handle, "CmdResetQueryPool_PostCall", &table->CmdResetQueryPool_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteTimestamp_PostCall", &table->CmdWriteTimestamp_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyQueryPoolResults_PostCall", &table->CmdCopyQueryPoolResults_PostCall);
    LoadPostFunction(gpa, handle, "CmdPushConstants_PostCall", &table->CmdPushConstants_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginRenderPass_PostCall", &table->CmdBeginRenderPass_PostCall);
    LoadPostFunction(gpa, handle, "CmdNextSubpass_PostCall", &table->CmdNextSubpass_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndRenderPass_PostCall", &table->CmdEndRenderPass_PostCall);
    LoadPostFunction(gpa, handle, "CmdExecuteCommands_PostCall", &table->CmdExecuteCommands_PostCall);
    LoadPostFunction(gpa, handle, "BindBufferMemory2_PostCall", &table->BindBufferMemory2_PostCall);
    LoadPostFunction(gpa, handle, "BindImageMemory2_PostCall", &table->BindImageMemory2_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceGroupPeerMemoryFeatures_PostCall", &table->GetDeviceGroupPeerMemoryFeatures_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDeviceMask_PostCall", &table->CmdSetDeviceMask_PostCall);
    LoadPostFunction(gpa, handle, "CmdDispatchBase_PostCall", &table->CmdDispatchBase_PostCall);
    LoadPostFunction(gpa, handle, "EnumeratePhysicalDeviceGroups_PostCall", &table->EnumeratePhysicalDeviceGroups_PostCall);
    LoadPostFunction(gpa, handle, "GetImageMemoryRequirements2_PostCall", &table->GetImageMemoryRequirements2_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferMemoryRequirements2_PostCall", &table->GetBufferMemoryRequirements2_PostCall);
    LoadPostFunction(gpa, handle, "GetImageSparseMemoryRequirements2_PostCall", &table->GetImageSparseMemoryRequirements2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFeatures2_PostCall", &table->GetPhysicalDeviceFeatures2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceProperties2_PostCall", &table->GetPhysicalDeviceProperties2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFormatProperties2_PostCall", &table->GetPhysicalDeviceFormatProperties2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceImageFormatProperties2_PostCall", &table->GetPhysicalDeviceImageFormatProperties2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceQueueFamilyProperties2_PostCall", &table->GetPhysicalDeviceQueueFamilyProperties2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceMemoryProperties2_PostCall", &table->GetPhysicalDeviceMemoryProperties2_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSparseImageFormatProperties2_PostCall", &table->GetPhysicalDeviceSparseImageFormatProperties2_PostCall);
    LoadPostFunction(gpa, handle, "TrimCommandPool_PostCall", &table->TrimCommandPool_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceQueue2_PostCall", &table->GetDeviceQueue2_PostCall);
    LoadPostFunction(gpa, handle, "CreateSamplerYcbcrConversion_PostCall", &table->CreateSamplerYcbcrConversion_PostCall);
    LoadPostFunction(gpa, handle, "DestroySamplerYcbcrConversion_PostCall", &table->DestroySamplerYcbcrConversion_PostCall);
    LoadPostFunction(gpa, handle, "CreateDescriptorUpdateTemplate_PostCall", &table->CreateDescriptorUpdateTemplate_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDescriptorUpdateTemplate_PostCall", &table->DestroyDescriptorUpdateTemplate_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalBufferProperties_PostCall", &table->GetPhysicalDeviceExternalBufferProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalFenceProperties_PostCall", &table->GetPhysicalDeviceExternalFenceProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalSemaphoreProperties_PostCall", &table->GetPhysicalDeviceExternalSemaphoreProperties_PostCall);
    LoadPostFunction(gpa, handle, "GetDescriptorSetLayoutSupport_PostCall", &table->GetDescriptorSetLayoutSupport_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndirectCount_PostCall", &table->CmdDrawIndirectCount_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndexedIndirectCount_PostCall", &table->CmdDrawIndexedIndirectCount_PostCall);
    LoadPostFunction(gpa, handle, "CreateRenderPass2_PostCall", &table->CreateRenderPass2_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginRenderPass2_PostCall", &table->CmdBeginRenderPass2_PostCall);
    LoadPostFunction(gpa, handle, "CmdNextSubpass2_PostCall", &table->CmdNextSubpass2_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndRenderPass2_PostCall", &table->CmdEndRenderPass2_PostCall);
    LoadPostFunction(gpa, handle, "ResetQueryPool_PostCall", &table->ResetQueryPool_PostCall);
    LoadPostFunction(gpa, handle, "GetSemaphoreCounterValue_PostCall", &table->GetSemaphoreCounterValue_PostCall);
    LoadPostFunction(gpa, handle, "WaitSemaphores_PostCall", &table->WaitSemaphores_PostCall);
    LoadPostFunction(gpa, handle, "SignalSemaphore_PostCall", &table->SignalSemaphore_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferDeviceAddress_PostCall", &table->GetBufferDeviceAddress_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferOpaqueCaptureAddress_PostCall", &table->GetBufferOpaqueCaptureAddress_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceMemoryOpaqueCaptureAddress_PostCall", &table->GetDeviceMemoryOpaqueCaptureAddress_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceToolProperties_PostCall", &table->GetPhysicalDeviceToolProperties_PostCall);
    LoadPostFunction(gpa, handle, "CreatePrivateDataSlot_PostCall", &table->CreatePrivateDataSlot_PostCall);
    LoadPostFunction(gpa, handle, "DestroyPrivateDataSlot_PostCall", &table->DestroyPrivateDataSlot_PostCall);
    LoadPostFunction(gpa, handle, "SetPrivateData_PostCall", &table->SetPrivateData_PostCall);
    LoadPostFunction(gpa, handle, "GetPrivateData_PostCall", &table->GetPrivateData_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetEvent2_PostCall", &table->CmdSetEvent2_PostCall);
    LoadPostFunction(gpa, handle, "CmdResetEvent2_PostCall", &table->CmdResetEvent2_PostCall);
    LoadPostFunction(gpa, handle, "CmdWaitEvents2_PostCall", &table->CmdWaitEvents2_PostCall);
    LoadPostFunction(gpa, handle, "CmdPipelineBarrier2_PostCall", &table->CmdPipelineBarrier2_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteTimestamp2_PostCall", &table->CmdWriteTimestamp2_PostCall);
    LoadPostFunction(gpa, handle, "QueueSubmit2_PostCall", &table->QueueSubmit2_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyBuffer2_PostCall", &table->CmdCopyBuffer2_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyImage2_PostCall", &table->CmdCopyImage2_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyBufferToImage2_PostCall", &table->CmdCopyBufferToImage2_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyImageToBuffer2_PostCall", &table->CmdCopyImageToBuffer2_PostCall);
    LoadPostFunction(gpa, handle, "CmdBlitImage2_PostCall", &table->CmdBlitImage2_PostCall);
    LoadPostFunction(gpa, handle, "CmdResolveImage2_PostCall", &table->CmdResolveImage2_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginRendering_PostCall", &table->CmdBeginRendering_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndRendering_PostCall", &table->CmdEndRendering_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCullMode_PostCall", &table->CmdSetCullMode_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetFrontFace_PostCall", &table->CmdSetFrontFace_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPrimitiveTopology_PostCall", &table->CmdSetPrimitiveTopology_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewportWithCount_PostCall", &table->CmdSetViewportWithCount_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetScissorWithCount_PostCall", &table->CmdSetScissorWithCount_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindVertexBuffers2_PostCall", &table->CmdBindVertexBuffers2_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthTestEnable_PostCall", &table->CmdSetDepthTestEnable_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthWriteEnable_PostCall", &table->CmdSetDepthWriteEnable_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthCompareOp_PostCall", &table->CmdSetDepthCompareOp_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthBoundsTestEnable_PostCall", &table->CmdSetDepthBoundsTestEnable_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilTestEnable_PostCall", &table->CmdSetStencilTestEnable_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilOp_PostCall", &table->CmdSetStencilOp_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetRasterizerDiscardEnable_PostCall", &table->CmdSetRasterizerDiscardEnable_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthBiasEnable_PostCall", &table->CmdSetDepthBiasEnable_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPrimitiveRestartEnable_PostCall", &table->CmdSetPrimitiveRestartEnable_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceBufferMemoryRequirements_PostCall", &table->GetDeviceBufferMemoryRequirements_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceImageMemoryRequirements_PostCall", &table->GetDeviceImageMemoryRequirements_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceImageSparseMemoryRequirements_PostCall", &table->GetDeviceImageSparseMemoryRequirements_PostCall);
    LoadPostFunction(gpa, handle, "DestroySurfaceKHR_PostCall", &table->DestroySurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfaceSupportKHR_PostCall", &table->GetPhysicalDeviceSurfaceSupportKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall", &table->GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfaceFormatsKHR_PostCall", &table->GetPhysicalDeviceSurfaceFormatsKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfacePresentModesKHR_PostCall", &table->GetPhysicalDeviceSurfacePresentModesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateSwapchainKHR_PostCall", &table->CreateSwapchainKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroySwapchainKHR_PostCall", &table->DestroySwapchainKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetSwapchainImagesKHR_PostCall", &table->GetSwapchainImagesKHR_PostCall);
    LoadPostFunction(gpa, handle, "AcquireNextImageKHR_PostCall", &table->AcquireNextImageKHR_PostCall);
    LoadPostFunction(gpa, handle, "QueuePresentKHR_PostCall", &table->QueuePresentKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceGroupPresentCapabilitiesKHR_PostCall", &table->GetDeviceGroupPresentCapabilitiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceGroupSurfacePresentModesKHR_PostCall", &table->GetDeviceGroupSurfacePresentModesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDevicePresentRectanglesKHR_PostCall", &table->GetPhysicalDevicePresentRectanglesKHR_PostCall);
    LoadPostFunction(gpa, handle, "AcquireNextImage2KHR_PostCall", &table->AcquireNextImage2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceDisplayPropertiesKHR_PostCall", &table->GetPhysicalDeviceDisplayPropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall", &table->GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDisplayPlaneSupportedDisplaysKHR_PostCall", &table->GetDisplayPlaneSupportedDisplaysKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDisplayModePropertiesKHR_PostCall", &table->GetDisplayModePropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateDisplayModeKHR_PostCall", &table->CreateDisplayModeKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDisplayPlaneCapabilitiesKHR_PostCall", &table->GetDisplayPlaneCapabilitiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateDisplayPlaneSurfaceKHR_PostCall", &table->CreateDisplayPlaneSurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateSharedSwapchainsKHR_PostCall", &table->CreateSharedSwapchainsKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateXlibSurfaceKHR_PostCall", &table->CreateXlibSurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceXlibPresentationSupportKHR_PostCall", &table->GetPhysicalDeviceXlibPresentationSupportKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateXcbSurfaceKHR_PostCall", &table->CreateXcbSurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceXcbPresentationSupportKHR_PostCall", &table->GetPhysicalDeviceXcbPresentationSupportKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateWaylandSurfaceKHR_PostCall", &table->CreateWaylandSurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall", &table->GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateAndroidSurfaceKHR_PostCall", &table->CreateAndroidSurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateWin32SurfaceKHR_PostCall", &table->CreateWin32SurfaceKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceWin32PresentationSupportKHR_PostCall", &table->GetPhysicalDeviceWin32PresentationSupportKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceVideoCapabilitiesKHR_PostCall", &table->GetPhysicalDeviceVideoCapabilitiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall", &table->GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateVideoSessionKHR_PostCall", &table->CreateVideoSessionKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroyVideoSessionKHR_PostCall", &table->DestroyVideoSessionKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetVideoSessionMemoryRequirementsKHR_PostCall", &table->GetVideoSessionMemoryRequirementsKHR_PostCall);
    LoadPostFunction(gpa, handle, "BindVideoSessionMemoryKHR_PostCall", &table->BindVideoSessionMemoryKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateVideoSessionParametersKHR_PostCall", &table->CreateVideoSessionParametersKHR_PostCall);
    LoadPostFunction(gpa, handle, "UpdateVideoSessionParametersKHR_PostCall", &table->UpdateVideoSessionParametersKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroyVideoSessionParametersKHR_PostCall", &table->DestroyVideoSessionParametersKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginVideoCodingKHR_PostCall", &table->CmdBeginVideoCodingKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndVideoCodingKHR_PostCall", &table->CmdEndVideoCodingKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdControlVideoCodingKHR_PostCall", &table->CmdControlVideoCodingKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdDecodeVideoKHR_PostCall", &table->CmdDecodeVideoKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginRenderingKHR_PostCall", &table->CmdBeginRenderingKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndRenderingKHR_PostCall", &table->CmdEndRenderingKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFeatures2KHR_PostCall", &table->GetPhysicalDeviceFeatures2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceProperties2KHR_PostCall", &table->GetPhysicalDeviceProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFormatProperties2KHR_PostCall", &table->GetPhysicalDeviceFormatProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceImageFormatProperties2KHR_PostCall", &table->GetPhysicalDeviceImageFormatProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall", &table->GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceMemoryProperties2KHR_PostCall", &table->GetPhysicalDeviceMemoryProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall", &table->GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceGroupPeerMemoryFeaturesKHR_PostCall", &table->GetDeviceGroupPeerMemoryFeaturesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDeviceMaskKHR_PostCall", &table->CmdSetDeviceMaskKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdDispatchBaseKHR_PostCall", &table->CmdDispatchBaseKHR_PostCall);
    LoadPostFunction(gpa, handle, "TrimCommandPoolKHR_PostCall", &table->TrimCommandPoolKHR_PostCall);
    LoadPostFunction(gpa, handle, "EnumeratePhysicalDeviceGroupsKHR_PostCall", &table->EnumeratePhysicalDeviceGroupsKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall", &table->GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryWin32HandleKHR_PostCall", &table->GetMemoryWin32HandleKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryWin32HandlePropertiesKHR_PostCall", &table->GetMemoryWin32HandlePropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryFdKHR_PostCall", &table->GetMemoryFdKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryFdPropertiesKHR_PostCall", &table->GetMemoryFdPropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall", &table->GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "ImportSemaphoreWin32HandleKHR_PostCall", &table->ImportSemaphoreWin32HandleKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetSemaphoreWin32HandleKHR_PostCall", &table->GetSemaphoreWin32HandleKHR_PostCall);
    LoadPostFunction(gpa, handle, "ImportSemaphoreFdKHR_PostCall", &table->ImportSemaphoreFdKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetSemaphoreFdKHR_PostCall", &table->GetSemaphoreFdKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdPushDescriptorSetKHR_PostCall", &table->CmdPushDescriptorSetKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateDescriptorUpdateTemplateKHR_PostCall", &table->CreateDescriptorUpdateTemplateKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDescriptorUpdateTemplateKHR_PostCall", &table->DestroyDescriptorUpdateTemplateKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateRenderPass2KHR_PostCall", &table->CreateRenderPass2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginRenderPass2KHR_PostCall", &table->CmdBeginRenderPass2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdNextSubpass2KHR_PostCall", &table->CmdNextSubpass2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndRenderPass2KHR_PostCall", &table->CmdEndRenderPass2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetSwapchainStatusKHR_PostCall", &table->GetSwapchainStatusKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalFencePropertiesKHR_PostCall", &table->GetPhysicalDeviceExternalFencePropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "ImportFenceWin32HandleKHR_PostCall", &table->ImportFenceWin32HandleKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetFenceWin32HandleKHR_PostCall", &table->GetFenceWin32HandleKHR_PostCall);
    LoadPostFunction(gpa, handle, "ImportFenceFdKHR_PostCall", &table->ImportFenceFdKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetFenceFdKHR_PostCall", &table->GetFenceFdKHR_PostCall);
    LoadPostFunction(gpa, handle, "EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall", &table->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall", &table->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall);
    LoadPostFunction(gpa, handle, "AcquireProfilingLockKHR_PostCall", &table->AcquireProfilingLockKHR_PostCall);
    LoadPostFunction(gpa, handle, "ReleaseProfilingLockKHR_PostCall", &table->ReleaseProfilingLockKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall", &table->GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfaceFormats2KHR_PostCall", &table->GetPhysicalDeviceSurfaceFormats2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceDisplayProperties2KHR_PostCall", &table->GetPhysicalDeviceDisplayProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall", &table->GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDisplayModeProperties2KHR_PostCall", &table->GetDisplayModeProperties2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDisplayPlaneCapabilities2KHR_PostCall", &table->GetDisplayPlaneCapabilities2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetImageMemoryRequirements2KHR_PostCall", &table->GetImageMemoryRequirements2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferMemoryRequirements2KHR_PostCall", &table->GetBufferMemoryRequirements2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetImageSparseMemoryRequirements2KHR_PostCall", &table->GetImageSparseMemoryRequirements2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateSamplerYcbcrConversionKHR_PostCall", &table->CreateSamplerYcbcrConversionKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroySamplerYcbcrConversionKHR_PostCall", &table->DestroySamplerYcbcrConversionKHR_PostCall);
    LoadPostFunction(gpa, handle, "BindBufferMemory2KHR_PostCall", &table->BindBufferMemory2KHR_PostCall);
    LoadPostFunction(gpa, handle, "BindImageMemory2KHR_PostCall", &table->BindImageMemory2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDescriptorSetLayoutSupportKHR_PostCall", &table->GetDescriptorSetLayoutSupportKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndirectCountKHR_PostCall", &table->CmdDrawIndirectCountKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndexedIndirectCountKHR_PostCall", &table->CmdDrawIndexedIndirectCountKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetSemaphoreCounterValueKHR_PostCall", &table->GetSemaphoreCounterValueKHR_PostCall);
    LoadPostFunction(gpa, handle, "WaitSemaphoresKHR_PostCall", &table->WaitSemaphoresKHR_PostCall);
    LoadPostFunction(gpa, handle, "SignalSemaphoreKHR_PostCall", &table->SignalSemaphoreKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceFragmentShadingRatesKHR_PostCall", &table->GetPhysicalDeviceFragmentShadingRatesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetFragmentShadingRateKHR_PostCall", &table->CmdSetFragmentShadingRateKHR_PostCall);
    LoadPostFunction(gpa, handle, "WaitForPresentKHR_PostCall", &table->WaitForPresentKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferDeviceAddressKHR_PostCall", &table->GetBufferDeviceAddressKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferOpaqueCaptureAddressKHR_PostCall", &table->GetBufferOpaqueCaptureAddressKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall", &table->GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateDeferredOperationKHR_PostCall", &table->CreateDeferredOperationKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDeferredOperationKHR_PostCall", &table->DestroyDeferredOperationKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeferredOperationMaxConcurrencyKHR_PostCall", &table->GetDeferredOperationMaxConcurrencyKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeferredOperationResultKHR_PostCall", &table->GetDeferredOperationResultKHR_PostCall);
    LoadPostFunction(gpa, handle, "DeferredOperationJoinKHR_PostCall", &table->DeferredOperationJoinKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPipelineExecutablePropertiesKHR_PostCall", &table->GetPipelineExecutablePropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPipelineExecutableStatisticsKHR_PostCall", &table->GetPipelineExecutableStatisticsKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetPipelineExecutableInternalRepresentationsKHR_PostCall", &table->GetPipelineExecutableInternalRepresentationsKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdEncodeVideoKHR_PostCall", &table->CmdEncodeVideoKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetEvent2KHR_PostCall", &table->CmdSetEvent2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdResetEvent2KHR_PostCall", &table->CmdResetEvent2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdWaitEvents2KHR_PostCall", &table->CmdWaitEvents2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdPipelineBarrier2KHR_PostCall", &table->CmdPipelineBarrier2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteTimestamp2KHR_PostCall", &table->CmdWriteTimestamp2KHR_PostCall);
    LoadPostFunction(gpa, handle, "QueueSubmit2KHR_PostCall", &table->QueueSubmit2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteBufferMarker2AMD_PostCall", &table->CmdWriteBufferMarker2AMD_PostCall);
    LoadPostFunction(gpa, handle, "GetQueueCheckpointData2NV_PostCall", &table->GetQueueCheckpointData2NV_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyBuffer2KHR_PostCall", &table->CmdCopyBuffer2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyImage2KHR_PostCall", &table->CmdCopyImage2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyBufferToImage2KHR_PostCall", &table->CmdCopyBufferToImage2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyImageToBuffer2KHR_PostCall", &table->CmdCopyImageToBuffer2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdBlitImage2KHR_PostCall", &table->CmdBlitImage2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdResolveImage2KHR_PostCall", &table->CmdResolveImage2KHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdTraceRaysIndirect2KHR_PostCall", &table->CmdTraceRaysIndirect2KHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceBufferMemoryRequirementsKHR_PostCall", &table->GetDeviceBufferMemoryRequirementsKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceImageMemoryRequirementsKHR_PostCall", &table->GetDeviceImageMemoryRequirementsKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceImageSparseMemoryRequirementsKHR_PostCall", &table->GetDeviceImageSparseMemoryRequirementsKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateDebugReportCallbackEXT_PostCall", &table->CreateDebugReportCallbackEXT_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDebugReportCallbackEXT_PostCall", &table->DestroyDebugReportCallbackEXT_PostCall);
    LoadPostFunction(gpa, handle, "DebugReportMessageEXT_PostCall", &table->DebugReportMessageEXT_PostCall);
    LoadPostFunction(gpa, handle, "DebugMarkerSetObjectTagEXT_PostCall", &table->DebugMarkerSetObjectTagEXT_PostCall);
    LoadPostFunction(gpa, handle, "DebugMarkerSetObjectNameEXT_PostCall", &table->DebugMarkerSetObjectNameEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDebugMarkerBeginEXT_PostCall", &table->CmdDebugMarkerBeginEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDebugMarkerEndEXT_PostCall", &table->CmdDebugMarkerEndEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDebugMarkerInsertEXT_PostCall", &table->CmdDebugMarkerInsertEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindTransformFeedbackBuffersEXT_PostCall", &table->CmdBindTransformFeedbackBuffersEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginTransformFeedbackEXT_PostCall", &table->CmdBeginTransformFeedbackEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndTransformFeedbackEXT_PostCall", &table->CmdEndTransformFeedbackEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginQueryIndexedEXT_PostCall", &table->CmdBeginQueryIndexedEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndQueryIndexedEXT_PostCall", &table->CmdEndQueryIndexedEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndirectByteCountEXT_PostCall", &table->CmdDrawIndirectByteCountEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetImageViewHandleNVX_PostCall", &table->GetImageViewHandleNVX_PostCall);
    LoadPostFunction(gpa, handle, "GetImageViewAddressNVX_PostCall", &table->GetImageViewAddressNVX_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndirectCountAMD_PostCall", &table->CmdDrawIndirectCountAMD_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawIndexedIndirectCountAMD_PostCall", &table->CmdDrawIndexedIndirectCountAMD_PostCall);
    LoadPostFunction(gpa, handle, "GetShaderInfoAMD_PostCall", &table->GetShaderInfoAMD_PostCall);
    LoadPostFunction(gpa, handle, "CreateStreamDescriptorSurfaceGGP_PostCall", &table->CreateStreamDescriptorSurfaceGGP_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall", &table->GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryWin32HandleNV_PostCall", &table->GetMemoryWin32HandleNV_PostCall);
    LoadPostFunction(gpa, handle, "CreateViSurfaceNN_PostCall", &table->CreateViSurfaceNN_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginConditionalRenderingEXT_PostCall", &table->CmdBeginConditionalRenderingEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndConditionalRenderingEXT_PostCall", &table->CmdEndConditionalRenderingEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewportWScalingNV_PostCall", &table->CmdSetViewportWScalingNV_PostCall);
    LoadPostFunction(gpa, handle, "ReleaseDisplayEXT_PostCall", &table->ReleaseDisplayEXT_PostCall);
    LoadPostFunction(gpa, handle, "AcquireXlibDisplayEXT_PostCall", &table->AcquireXlibDisplayEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetRandROutputDisplayEXT_PostCall", &table->GetRandROutputDisplayEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall", &table->GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall);
    LoadPostFunction(gpa, handle, "DisplayPowerControlEXT_PostCall", &table->DisplayPowerControlEXT_PostCall);
    LoadPostFunction(gpa, handle, "RegisterDeviceEventEXT_PostCall", &table->RegisterDeviceEventEXT_PostCall);
    LoadPostFunction(gpa, handle, "RegisterDisplayEventEXT_PostCall", &table->RegisterDisplayEventEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetSwapchainCounterEXT_PostCall", &table->GetSwapchainCounterEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetRefreshCycleDurationGOOGLE_PostCall", &table->GetRefreshCycleDurationGOOGLE_PostCall);
    LoadPostFunction(gpa, handle, "GetPastPresentationTimingGOOGLE_PostCall", &table->GetPastPresentationTimingGOOGLE_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDiscardRectangleEXT_PostCall", &table->CmdSetDiscardRectangleEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDiscardRectangleEnableEXT_PostCall", &table->CmdSetDiscardRectangleEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDiscardRectangleModeEXT_PostCall", &table->CmdSetDiscardRectangleModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "SetHdrMetadataEXT_PostCall", &table->SetHdrMetadataEXT_PostCall);
    LoadPostFunction(gpa, handle, "CreateIOSSurfaceMVK_PostCall", &table->CreateIOSSurfaceMVK_PostCall);
    LoadPostFunction(gpa, handle, "CreateMacOSSurfaceMVK_PostCall", &table->CreateMacOSSurfaceMVK_PostCall);
    LoadPostFunction(gpa, handle, "SetDebugUtilsObjectNameEXT_PostCall", &table->SetDebugUtilsObjectNameEXT_PostCall);
    LoadPostFunction(gpa, handle, "SetDebugUtilsObjectTagEXT_PostCall", &table->SetDebugUtilsObjectTagEXT_PostCall);
    LoadPostFunction(gpa, handle, "QueueBeginDebugUtilsLabelEXT_PostCall", &table->QueueBeginDebugUtilsLabelEXT_PostCall);
    LoadPostFunction(gpa, handle, "QueueEndDebugUtilsLabelEXT_PostCall", &table->QueueEndDebugUtilsLabelEXT_PostCall);
    LoadPostFunction(gpa, handle, "QueueInsertDebugUtilsLabelEXT_PostCall", &table->QueueInsertDebugUtilsLabelEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBeginDebugUtilsLabelEXT_PostCall", &table->CmdBeginDebugUtilsLabelEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdEndDebugUtilsLabelEXT_PostCall", &table->CmdEndDebugUtilsLabelEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdInsertDebugUtilsLabelEXT_PostCall", &table->CmdInsertDebugUtilsLabelEXT_PostCall);
    LoadPostFunction(gpa, handle, "CreateDebugUtilsMessengerEXT_PostCall", &table->CreateDebugUtilsMessengerEXT_PostCall);
    LoadPostFunction(gpa, handle, "DestroyDebugUtilsMessengerEXT_PostCall", &table->DestroyDebugUtilsMessengerEXT_PostCall);
    LoadPostFunction(gpa, handle, "SubmitDebugUtilsMessageEXT_PostCall", &table->SubmitDebugUtilsMessageEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetAndroidHardwareBufferPropertiesANDROID_PostCall", &table->GetAndroidHardwareBufferPropertiesANDROID_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryAndroidHardwareBufferANDROID_PostCall", &table->GetMemoryAndroidHardwareBufferANDROID_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetSampleLocationsEXT_PostCall", &table->CmdSetSampleLocationsEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceMultisamplePropertiesEXT_PostCall", &table->GetPhysicalDeviceMultisamplePropertiesEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetImageDrmFormatModifierPropertiesEXT_PostCall", &table->GetImageDrmFormatModifierPropertiesEXT_PostCall);
    LoadPostFunction(gpa, handle, "CreateValidationCacheEXT_PostCall", &table->CreateValidationCacheEXT_PostCall);
    LoadPostFunction(gpa, handle, "DestroyValidationCacheEXT_PostCall", &table->DestroyValidationCacheEXT_PostCall);
    LoadPostFunction(gpa, handle, "MergeValidationCachesEXT_PostCall", &table->MergeValidationCachesEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetValidationCacheDataEXT_PostCall", &table->GetValidationCacheDataEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindShadingRateImageNV_PostCall", &table->CmdBindShadingRateImageNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewportShadingRatePaletteNV_PostCall", &table->CmdSetViewportShadingRatePaletteNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoarseSampleOrderNV_PostCall", &table->CmdSetCoarseSampleOrderNV_PostCall);
    LoadPostFunction(gpa, handle, "CreateAccelerationStructureNV_PostCall", &table->CreateAccelerationStructureNV_PostCall);
    LoadPostFunction(gpa, handle, "DestroyAccelerationStructureNV_PostCall", &table->DestroyAccelerationStructureNV_PostCall);
    LoadPostFunction(gpa, handle, "GetAccelerationStructureMemoryRequirementsNV_PostCall", &table->GetAccelerationStructureMemoryRequirementsNV_PostCall);
    LoadPostFunction(gpa, handle, "BindAccelerationStructureMemoryNV_PostCall", &table->BindAccelerationStructureMemoryNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdBuildAccelerationStructureNV_PostCall", &table->CmdBuildAccelerationStructureNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyAccelerationStructureNV_PostCall", &table->CmdCopyAccelerationStructureNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdTraceRaysNV_PostCall", &table->CmdTraceRaysNV_PostCall);
    LoadPostFunction(gpa, handle, "CreateRayTracingPipelinesNV_PostCall", &table->CreateRayTracingPipelinesNV_PostCall);
    LoadPostFunction(gpa, handle, "GetRayTracingShaderGroupHandlesKHR_PostCall", &table->GetRayTracingShaderGroupHandlesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetRayTracingShaderGroupHandlesNV_PostCall", &table->GetRayTracingShaderGroupHandlesNV_PostCall);
    LoadPostFunction(gpa, handle, "GetAccelerationStructureHandleNV_PostCall", &table->GetAccelerationStructureHandleNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteAccelerationStructuresPropertiesNV_PostCall", &table->CmdWriteAccelerationStructuresPropertiesNV_PostCall);
    LoadPostFunction(gpa, handle, "CompileDeferredNV_PostCall", &table->CompileDeferredNV_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryHostPointerPropertiesEXT_PostCall", &table->GetMemoryHostPointerPropertiesEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteBufferMarkerAMD_PostCall", &table->CmdWriteBufferMarkerAMD_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall", &table->GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetCalibratedTimestampsEXT_PostCall", &table->GetCalibratedTimestampsEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMeshTasksNV_PostCall", &table->CmdDrawMeshTasksNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMeshTasksIndirectNV_PostCall", &table->CmdDrawMeshTasksIndirectNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMeshTasksIndirectCountNV_PostCall", &table->CmdDrawMeshTasksIndirectCountNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetExclusiveScissorEnableNV_PostCall", &table->CmdSetExclusiveScissorEnableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetExclusiveScissorNV_PostCall", &table->CmdSetExclusiveScissorNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCheckpointNV_PostCall", &table->CmdSetCheckpointNV_PostCall);
    LoadPostFunction(gpa, handle, "GetQueueCheckpointDataNV_PostCall", &table->GetQueueCheckpointDataNV_PostCall);
    LoadPostFunction(gpa, handle, "InitializePerformanceApiINTEL_PostCall", &table->InitializePerformanceApiINTEL_PostCall);
    LoadPostFunction(gpa, handle, "UninitializePerformanceApiINTEL_PostCall", &table->UninitializePerformanceApiINTEL_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPerformanceMarkerINTEL_PostCall", &table->CmdSetPerformanceMarkerINTEL_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPerformanceStreamMarkerINTEL_PostCall", &table->CmdSetPerformanceStreamMarkerINTEL_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPerformanceOverrideINTEL_PostCall", &table->CmdSetPerformanceOverrideINTEL_PostCall);
    LoadPostFunction(gpa, handle, "AcquirePerformanceConfigurationINTEL_PostCall", &table->AcquirePerformanceConfigurationINTEL_PostCall);
    LoadPostFunction(gpa, handle, "ReleasePerformanceConfigurationINTEL_PostCall", &table->ReleasePerformanceConfigurationINTEL_PostCall);
    LoadPostFunction(gpa, handle, "QueueSetPerformanceConfigurationINTEL_PostCall", &table->QueueSetPerformanceConfigurationINTEL_PostCall);
    LoadPostFunction(gpa, handle, "GetPerformanceParameterINTEL_PostCall", &table->GetPerformanceParameterINTEL_PostCall);
    LoadPostFunction(gpa, handle, "SetLocalDimmingAMD_PostCall", &table->SetLocalDimmingAMD_PostCall);
    LoadPostFunction(gpa, handle, "CreateImagePipeSurfaceFUCHSIA_PostCall", &table->CreateImagePipeSurfaceFUCHSIA_PostCall);
    LoadPostFunction(gpa, handle, "CreateMetalSurfaceEXT_PostCall", &table->CreateMetalSurfaceEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetBufferDeviceAddressEXT_PostCall", &table->GetBufferDeviceAddressEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceToolPropertiesEXT_PostCall", &table->GetPhysicalDeviceToolPropertiesEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall", &table->GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall", &table->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceSurfacePresentModes2EXT_PostCall", &table->GetPhysicalDeviceSurfacePresentModes2EXT_PostCall);
    LoadPostFunction(gpa, handle, "AcquireFullScreenExclusiveModeEXT_PostCall", &table->AcquireFullScreenExclusiveModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "ReleaseFullScreenExclusiveModeEXT_PostCall", &table->ReleaseFullScreenExclusiveModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceGroupSurfacePresentModes2EXT_PostCall", &table->GetDeviceGroupSurfacePresentModes2EXT_PostCall);
    LoadPostFunction(gpa, handle, "CreateHeadlessSurfaceEXT_PostCall", &table->CreateHeadlessSurfaceEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetLineStippleEXT_PostCall", &table->CmdSetLineStippleEXT_PostCall);
    LoadPostFunction(gpa, handle, "ResetQueryPoolEXT_PostCall", &table->ResetQueryPoolEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCullModeEXT_PostCall", &table->CmdSetCullModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetFrontFaceEXT_PostCall", &table->CmdSetFrontFaceEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPrimitiveTopologyEXT_PostCall", &table->CmdSetPrimitiveTopologyEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewportWithCountEXT_PostCall", &table->CmdSetViewportWithCountEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetScissorWithCountEXT_PostCall", &table->CmdSetScissorWithCountEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindVertexBuffers2EXT_PostCall", &table->CmdBindVertexBuffers2EXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthTestEnableEXT_PostCall", &table->CmdSetDepthTestEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthWriteEnableEXT_PostCall", &table->CmdSetDepthWriteEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthCompareOpEXT_PostCall", &table->CmdSetDepthCompareOpEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthBoundsTestEnableEXT_PostCall", &table->CmdSetDepthBoundsTestEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilTestEnableEXT_PostCall", &table->CmdSetStencilTestEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetStencilOpEXT_PostCall", &table->CmdSetStencilOpEXT_PostCall);
    LoadPostFunction(gpa, handle, "ReleaseSwapchainImagesEXT_PostCall", &table->ReleaseSwapchainImagesEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetGeneratedCommandsMemoryRequirementsNV_PostCall", &table->GetGeneratedCommandsMemoryRequirementsNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdPostprocessGeneratedCommandsNV_PostCall", &table->CmdPostprocessGeneratedCommandsNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdExecuteGeneratedCommandsNV_PostCall", &table->CmdExecuteGeneratedCommandsNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindPipelineShaderGroupNV_PostCall", &table->CmdBindPipelineShaderGroupNV_PostCall);
    LoadPostFunction(gpa, handle, "CreateIndirectCommandsLayoutNV_PostCall", &table->CreateIndirectCommandsLayoutNV_PostCall);
    LoadPostFunction(gpa, handle, "DestroyIndirectCommandsLayoutNV_PostCall", &table->DestroyIndirectCommandsLayoutNV_PostCall);
    LoadPostFunction(gpa, handle, "AcquireDrmDisplayEXT_PostCall", &table->AcquireDrmDisplayEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetDrmDisplayEXT_PostCall", &table->GetDrmDisplayEXT_PostCall);
    LoadPostFunction(gpa, handle, "CreatePrivateDataSlotEXT_PostCall", &table->CreatePrivateDataSlotEXT_PostCall);
    LoadPostFunction(gpa, handle, "DestroyPrivateDataSlotEXT_PostCall", &table->DestroyPrivateDataSlotEXT_PostCall);
    LoadPostFunction(gpa, handle, "SetPrivateDataEXT_PostCall", &table->SetPrivateDataEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPrivateDataEXT_PostCall", &table->GetPrivateDataEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetFragmentShadingRateEnumNV_PostCall", &table->CmdSetFragmentShadingRateEnumNV_PostCall);
    LoadPostFunction(gpa, handle, "GetImageSubresourceLayout2EXT_PostCall", &table->GetImageSubresourceLayout2EXT_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceFaultInfoEXT_PostCall", &table->GetDeviceFaultInfoEXT_PostCall);
    LoadPostFunction(gpa, handle, "AcquireWinrtDisplayNV_PostCall", &table->AcquireWinrtDisplayNV_PostCall);
    LoadPostFunction(gpa, handle, "GetWinrtDisplayNV_PostCall", &table->GetWinrtDisplayNV_PostCall);
    LoadPostFunction(gpa, handle, "CreateDirectFBSurfaceEXT_PostCall", &table->CreateDirectFBSurfaceEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall", &table->GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetVertexInputEXT_PostCall", &table->CmdSetVertexInputEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryZirconHandleFUCHSIA_PostCall", &table->GetMemoryZirconHandleFUCHSIA_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryZirconHandlePropertiesFUCHSIA_PostCall", &table->GetMemoryZirconHandlePropertiesFUCHSIA_PostCall);
    LoadPostFunction(gpa, handle, "ImportSemaphoreZirconHandleFUCHSIA_PostCall", &table->ImportSemaphoreZirconHandleFUCHSIA_PostCall);
    LoadPostFunction(gpa, handle, "GetSemaphoreZirconHandleFUCHSIA_PostCall", &table->GetSemaphoreZirconHandleFUCHSIA_PostCall);
    LoadPostFunction(gpa, handle, "CmdBindInvocationMaskHUAWEI_PostCall", &table->CmdBindInvocationMaskHUAWEI_PostCall);
    LoadPostFunction(gpa, handle, "GetMemoryRemoteAddressNV_PostCall", &table->GetMemoryRemoteAddressNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPatchControlPointsEXT_PostCall", &table->CmdSetPatchControlPointsEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetRasterizerDiscardEnableEXT_PostCall", &table->CmdSetRasterizerDiscardEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthBiasEnableEXT_PostCall", &table->CmdSetDepthBiasEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetLogicOpEXT_PostCall", &table->CmdSetLogicOpEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPrimitiveRestartEnableEXT_PostCall", &table->CmdSetPrimitiveRestartEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CreateScreenSurfaceQNX_PostCall", &table->CreateScreenSurfaceQNX_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceScreenPresentationSupportQNX_PostCall", &table->GetPhysicalDeviceScreenPresentationSupportQNX_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetColorWriteEnableEXT_PostCall", &table->CmdSetColorWriteEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMultiEXT_PostCall", &table->CmdDrawMultiEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMultiIndexedEXT_PostCall", &table->CmdDrawMultiIndexedEXT_PostCall);
    LoadPostFunction(gpa, handle, "CreateMicromapEXT_PostCall", &table->CreateMicromapEXT_PostCall);
    LoadPostFunction(gpa, handle, "DestroyMicromapEXT_PostCall", &table->DestroyMicromapEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdBuildMicromapsEXT_PostCall", &table->CmdBuildMicromapsEXT_PostCall);
    LoadPostFunction(gpa, handle, "BuildMicromapsEXT_PostCall", &table->BuildMicromapsEXT_PostCall);
    LoadPostFunction(gpa, handle, "CopyMicromapEXT_PostCall", &table->CopyMicromapEXT_PostCall);
    LoadPostFunction(gpa, handle, "CopyMicromapToMemoryEXT_PostCall", &table->CopyMicromapToMemoryEXT_PostCall);
    LoadPostFunction(gpa, handle, "CopyMemoryToMicromapEXT_PostCall", &table->CopyMemoryToMicromapEXT_PostCall);
    LoadPostFunction(gpa, handle, "WriteMicromapsPropertiesEXT_PostCall", &table->WriteMicromapsPropertiesEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyMicromapEXT_PostCall", &table->CmdCopyMicromapEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyMicromapToMemoryEXT_PostCall", &table->CmdCopyMicromapToMemoryEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyMemoryToMicromapEXT_PostCall", &table->CmdCopyMemoryToMicromapEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteMicromapsPropertiesEXT_PostCall", &table->CmdWriteMicromapsPropertiesEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceMicromapCompatibilityEXT_PostCall", &table->GetDeviceMicromapCompatibilityEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetMicromapBuildSizesEXT_PostCall", &table->GetMicromapBuildSizesEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawClusterHUAWEI_PostCall", &table->CmdDrawClusterHUAWEI_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawClusterIndirectHUAWEI_PostCall", &table->CmdDrawClusterIndirectHUAWEI_PostCall);
    LoadPostFunction(gpa, handle, "SetDeviceMemoryPriorityEXT_PostCall", &table->SetDeviceMemoryPriorityEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall", &table->GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall);
    LoadPostFunction(gpa, handle, "GetDescriptorSetHostMappingVALVE_PostCall", &table->GetDescriptorSetHostMappingVALVE_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetTessellationDomainOriginEXT_PostCall", &table->CmdSetTessellationDomainOriginEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthClampEnableEXT_PostCall", &table->CmdSetDepthClampEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetPolygonModeEXT_PostCall", &table->CmdSetPolygonModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetRasterizationSamplesEXT_PostCall", &table->CmdSetRasterizationSamplesEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetSampleMaskEXT_PostCall", &table->CmdSetSampleMaskEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetAlphaToCoverageEnableEXT_PostCall", &table->CmdSetAlphaToCoverageEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetAlphaToOneEnableEXT_PostCall", &table->CmdSetAlphaToOneEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetLogicOpEnableEXT_PostCall", &table->CmdSetLogicOpEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetColorBlendEnableEXT_PostCall", &table->CmdSetColorBlendEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetColorBlendEquationEXT_PostCall", &table->CmdSetColorBlendEquationEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetColorWriteMaskEXT_PostCall", &table->CmdSetColorWriteMaskEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetRasterizationStreamEXT_PostCall", &table->CmdSetRasterizationStreamEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetConservativeRasterizationModeEXT_PostCall", &table->CmdSetConservativeRasterizationModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall", &table->CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthClipEnableEXT_PostCall", &table->CmdSetDepthClipEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetSampleLocationsEnableEXT_PostCall", &table->CmdSetSampleLocationsEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetColorBlendAdvancedEXT_PostCall", &table->CmdSetColorBlendAdvancedEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetProvokingVertexModeEXT_PostCall", &table->CmdSetProvokingVertexModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetLineRasterizationModeEXT_PostCall", &table->CmdSetLineRasterizationModeEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetLineStippleEnableEXT_PostCall", &table->CmdSetLineStippleEnableEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetDepthClipNegativeOneToOneEXT_PostCall", &table->CmdSetDepthClipNegativeOneToOneEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewportWScalingEnableNV_PostCall", &table->CmdSetViewportWScalingEnableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetViewportSwizzleNV_PostCall", &table->CmdSetViewportSwizzleNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoverageToColorEnableNV_PostCall", &table->CmdSetCoverageToColorEnableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoverageToColorLocationNV_PostCall", &table->CmdSetCoverageToColorLocationNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoverageModulationModeNV_PostCall", &table->CmdSetCoverageModulationModeNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoverageModulationTableEnableNV_PostCall", &table->CmdSetCoverageModulationTableEnableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoverageModulationTableNV_PostCall", &table->CmdSetCoverageModulationTableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetShadingRateImageEnableNV_PostCall", &table->CmdSetShadingRateImageEnableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetRepresentativeFragmentTestEnableNV_PostCall", &table->CmdSetRepresentativeFragmentTestEnableNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetCoverageReductionModeNV_PostCall", &table->CmdSetCoverageReductionModeNV_PostCall);
    LoadPostFunction(gpa, handle, "GetShaderModuleIdentifierEXT_PostCall", &table->GetShaderModuleIdentifierEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetShaderModuleCreateInfoIdentifierEXT_PostCall", &table->GetShaderModuleCreateInfoIdentifierEXT_PostCall);
    LoadPostFunction(gpa, handle, "GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall", &table->GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall);
    LoadPostFunction(gpa, handle, "CreateOpticalFlowSessionNV_PostCall", &table->CreateOpticalFlowSessionNV_PostCall);
    LoadPostFunction(gpa, handle, "DestroyOpticalFlowSessionNV_PostCall", &table->DestroyOpticalFlowSessionNV_PostCall);
    LoadPostFunction(gpa, handle, "BindOpticalFlowSessionImageNV_PostCall", &table->BindOpticalFlowSessionImageNV_PostCall);
    LoadPostFunction(gpa, handle, "CmdOpticalFlowExecuteNV_PostCall", &table->CmdOpticalFlowExecuteNV_PostCall);
    LoadPostFunction(gpa, handle, "GetFramebufferTilePropertiesQCOM_PostCall", &table->GetFramebufferTilePropertiesQCOM_PostCall);
    LoadPostFunction(gpa, handle, "GetDynamicRenderingTilePropertiesQCOM_PostCall", &table->GetDynamicRenderingTilePropertiesQCOM_PostCall);
    LoadPostFunction(gpa, handle, "CreateAccelerationStructureKHR_PostCall", &table->CreateAccelerationStructureKHR_PostCall);
    LoadPostFunction(gpa, handle, "DestroyAccelerationStructureKHR_PostCall", &table->DestroyAccelerationStructureKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdBuildAccelerationStructuresKHR_PostCall", &table->CmdBuildAccelerationStructuresKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdBuildAccelerationStructuresIndirectKHR_PostCall", &table->CmdBuildAccelerationStructuresIndirectKHR_PostCall);
    LoadPostFunction(gpa, handle, "CopyAccelerationStructureToMemoryKHR_PostCall", &table->CopyAccelerationStructureToMemoryKHR_PostCall);
    LoadPostFunction(gpa, handle, "CopyMemoryToAccelerationStructureKHR_PostCall", &table->CopyMemoryToAccelerationStructureKHR_PostCall);
    LoadPostFunction(gpa, handle, "WriteAccelerationStructuresPropertiesKHR_PostCall", &table->WriteAccelerationStructuresPropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyAccelerationStructureKHR_PostCall", &table->CmdCopyAccelerationStructureKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyAccelerationStructureToMemoryKHR_PostCall", &table->CmdCopyAccelerationStructureToMemoryKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdCopyMemoryToAccelerationStructureKHR_PostCall", &table->CmdCopyMemoryToAccelerationStructureKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetAccelerationStructureDeviceAddressKHR_PostCall", &table->GetAccelerationStructureDeviceAddressKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdWriteAccelerationStructuresPropertiesKHR_PostCall", &table->CmdWriteAccelerationStructuresPropertiesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetDeviceAccelerationStructureCompatibilityKHR_PostCall", &table->GetDeviceAccelerationStructureCompatibilityKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetAccelerationStructureBuildSizesKHR_PostCall", &table->GetAccelerationStructureBuildSizesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdTraceRaysKHR_PostCall", &table->CmdTraceRaysKHR_PostCall);
    LoadPostFunction(gpa, handle, "CreateRayTracingPipelinesKHR_PostCall", &table->CreateRayTracingPipelinesKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall", &table->GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdTraceRaysIndirectKHR_PostCall", &table->CmdTraceRaysIndirectKHR_PostCall);
    LoadPostFunction(gpa, handle, "GetRayTracingShaderGroupStackSizeKHR_PostCall", &table->GetRayTracingShaderGroupStackSizeKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdSetRayTracingPipelineStackSizeKHR_PostCall", &table->CmdSetRayTracingPipelineStackSizeKHR_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMeshTasksEXT_PostCall", &table->CmdDrawMeshTasksEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMeshTasksIndirectEXT_PostCall", &table->CmdDrawMeshTasksIndirectEXT_PostCall);
    LoadPostFunction(gpa, handle, "CmdDrawMeshTasksIndirectCountEXT_PostCall", &table->CmdDrawMeshTasksIndirectCountEXT_PostCall);
}
// clang-format on

GFXRECON_END_NAMESPACE(replay)
GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_PLUGINS_FUNC_TABLE_POST_H
