/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef PEFETTO_ENTRYPOINTS_POST_H
#define PEFETTO_ENTRYPOINTS_POST_H

#include "format/platform_types.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

GFXRECON_BEGIN_NAMESPACE(encode)
 class VulkanCaptureManager;
GFXRECON_END_NAMESPACE(encode)

GFXRECON_BEGIN_NAMESPACE(plugins)

extern "C" {

VKAPI_ATTR VkResult VKAPI_CALL CreateInstance_PostCall(encode::VulkanCaptureManager* manager, VkResult result, const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);

VKAPI_ATTR void VKAPI_CALL DestroyInstance_PostCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties);

VKAPI_ATTR VkResult VKAPI_CALL CreateDevice_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice);

VKAPI_ATTR void VKAPI_CALL DestroyDevice_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);

VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue);

VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device);

VKAPI_ATTR VkResult VKAPI_CALL AllocateMemory_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);

VKAPI_ATTR void VKAPI_CALL FreeMemory_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL MapMemory_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);

VKAPI_ATTR void VKAPI_CALL UnmapMemory_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory);

VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);

VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL QueueBindSparse_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);

VKAPI_ATTR VkResult VKAPI_CALL CreateFence_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);

VKAPI_ATTR void VKAPI_CALL DestroyFence_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL ResetFences_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t fenceCount, const VkFence* pFences);

VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkFence fence);

VKAPI_ATTR VkResult VKAPI_CALL WaitForFences_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);

VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);

VKAPI_ATTR void VKAPI_CALL DestroySemaphore_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL CreateEvent_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent);

VKAPI_ATTR void VKAPI_CALL DestroyEvent_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkEvent event);

VKAPI_ATTR VkResult VKAPI_CALL SetEvent_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkEvent event);

VKAPI_ATTR VkResult VKAPI_CALL ResetEvent_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkEvent event);

VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);

VKAPI_ATTR void VKAPI_CALL DestroyQueryPool_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL GetQueryPoolResults_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags);

VKAPI_ATTR VkResult VKAPI_CALL CreateBuffer_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);

VKAPI_ATTR void VKAPI_CALL DestroyBuffer_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView);

VKAPI_ATTR void VKAPI_CALL DestroyBufferView_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL CreateImage_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage);

VKAPI_ATTR void VKAPI_CALL DestroyImage_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout);

VKAPI_ATTR VkResult VKAPI_CALL CreateImageView_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView);

VKAPI_ATTR void VKAPI_CALL DestroyImageView_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL CreateShaderModule_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule);

VKAPI_ATTR void VKAPI_CALL DestroyShaderModule_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache);

VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineCacheData_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);

VKAPI_ATTR VkResult VKAPI_CALL MergePipelineCaches_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches);

VKAPI_ATTR VkResult VKAPI_CALL CreateGraphicsPipelines_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);

VKAPI_ATTR VkResult VKAPI_CALL CreateComputePipelines_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);

VKAPI_ATTR void VKAPI_CALL DestroyPipeline_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout);

VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL CreateSampler_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler);

VKAPI_ATTR void VKAPI_CALL DestroySampler_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout);

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags);

VKAPI_ATTR VkResult VKAPI_CALL AllocateDescriptorSets_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets);

VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies);

VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);

VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);

VKAPI_ATTR void VKAPI_CALL DestroyRenderPass_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity);

VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);

VKAPI_ATTR void VKAPI_CALL DestroyCommandPool_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags);

VKAPI_ATTR VkResult VKAPI_CALL AllocateCommandBuffers_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);

VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);

VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);

VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer);

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);

VKAPI_ATTR void VKAPI_CALL CmdBindPipeline_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);

VKAPI_ATTR void VKAPI_CALL CmdSetViewport_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports);

VKAPI_ATTR void VKAPI_CALL CmdSetScissor_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors);

VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float lineWidth);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);

VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const float blendConstants[4]);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);

VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets);

VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);

VKAPI_ATTR void VKAPI_CALL CmdDraw_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDispatch_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions);

VKAPI_ATTR void VKAPI_CALL CmdCopyImage_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions);

VKAPI_ATTR void VKAPI_CALL CmdBlitImage_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter);

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);

VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData);

VKAPI_ATTR void VKAPI_CALL CmdFillBuffer_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);

VKAPI_ATTR void VKAPI_CALL CmdClearColorImage_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);

VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);

VKAPI_ATTR void VKAPI_CALL CmdClearAttachments_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects);

VKAPI_ATTR void VKAPI_CALL CmdResolveImage_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions);

VKAPI_ATTR void VKAPI_CALL CmdSetEvent_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);

VKAPI_ATTR void VKAPI_CALL CmdResetEvent_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

VKAPI_ATTR void VKAPI_CALL CmdBeginQuery_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);

VKAPI_ATTR void VKAPI_CALL CmdEndQuery_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);

VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query);

VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);

VKAPI_ATTR void VKAPI_CALL CmdPushConstants_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues);

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents);

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSubpassContents contents);

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);

VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t deviceMask);

VKAPI_ATTR void VKAPI_CALL CmdDispatchBase_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);

VKAPI_ATTR void VKAPI_CALL TrimCommandPool_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue);

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplate_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo);

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo);

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);

VKAPI_ATTR void VKAPI_CALL ResetQueryPool_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValue_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSemaphore semaphore, uint64_t* pValue);

VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphores_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);

VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphore_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo);

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddress_PostCall(encode::VulkanCaptureManager* manager, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);

VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddress_PostCall(encode::VulkanCaptureManager* manager, uint64_t result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);

VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress_PostCall(encode::VulkanCaptureManager* manager, uint64_t result, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolProperties_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties);

VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlot_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot);

VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL SetPrivateData_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);

VKAPI_ATTR void VKAPI_CALL GetPrivateData_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData);

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query);

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdBeginRendering_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);

VKAPI_ATTR void VKAPI_CALL CmdEndRendering_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);

VKAPI_ATTR void VKAPI_CALL CmdSetCullMode_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFrontFace frontFace);

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);

VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirements_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirements_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);

VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);

VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImageKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);

VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, const VkPresentInfoKHR* pPresentInfo);

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities);

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects);

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImage2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays);

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode);

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities);

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains);

VKAPI_ATTR VkResult VKAPI_CALL CreateXlibSurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR_PostCall(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID);

VKAPI_ATTR VkResult VKAPI_CALL CreateXcbSurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR_PostCall(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id);

VKAPI_ATTR VkResult VKAPI_CALL CreateWaylandSurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display);

VKAPI_ATTR VkResult VKAPI_CALL CreateAndroidSurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR VkResult VKAPI_CALL CreateWin32SurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR_PostCall(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceVideoCapabilitiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties);

VKAPI_ATTR VkResult VKAPI_CALL CreateVideoSessionKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession);

VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL GetVideoSessionMemoryRequirementsKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements);

VKAPI_ATTR VkResult VKAPI_CALL BindVideoSessionMemoryKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos);

VKAPI_ATTR VkResult VKAPI_CALL CreateVideoSessionParametersKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters);

VKAPI_ATTR VkResult VKAPI_CALL UpdateVideoSessionParametersKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo);

VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionParametersKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CmdBeginVideoCodingKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo);

VKAPI_ATTR void VKAPI_CALL CmdEndVideoCodingKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo);

VKAPI_ATTR void VKAPI_CALL CmdControlVideoCodingKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo);

VKAPI_ATTR void VKAPI_CALL CmdDecodeVideoKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo);

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderingKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);

VKAPI_ATTR void VKAPI_CALL CmdEndRenderingKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t deviceMask);

VKAPI_ATTR void VKAPI_CALL CmdDispatchBaseKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandlePropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd);

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreWin32HandleKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo);

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreWin32HandleKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo);

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd);

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites);

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplateKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo);

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo);

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceWin32HandleKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo);

VKAPI_ATTR VkResult VKAPI_CALL GetFenceWin32HandleKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo);

VKAPI_ATTR VkResult VKAPI_CALL GetFenceFdKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd);

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses);

VKAPI_ATTR VkResult VKAPI_CALL AcquireProfilingLockKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo);

VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities);

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversionKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValueKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSemaphore semaphore, uint64_t* pValue);

VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphoresKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);

VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphoreKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceFragmentShadingRatesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates);

VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);

VKAPI_ATTR VkResult VKAPI_CALL WaitForPresentKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout);

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressKHR_PostCall(encode::VulkanCaptureManager* manager, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);

VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddressKHR_PostCall(encode::VulkanCaptureManager* manager, uint64_t result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);

VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall(encode::VulkanCaptureManager* manager, uint64_t result, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);

VKAPI_ATTR VkResult VKAPI_CALL CreateDeferredOperationKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation);

VKAPI_ATTR void VKAPI_CALL DestroyDeferredOperationKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR uint32_t VKAPI_CALL GetDeferredOperationMaxConcurrencyKHR_PostCall(encode::VulkanCaptureManager* manager, uint32_t result, VkDevice device, VkDeferredOperationKHR operation);

VKAPI_ATTR VkResult VKAPI_CALL GetDeferredOperationResultKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR operation);

VKAPI_ATTR VkResult VKAPI_CALL DeferredOperationJoinKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR operation);

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutablePropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutableStatisticsKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics);

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutableInternalRepresentationsKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations);

VKAPI_ATTR void VKAPI_CALL CmdEncodeVideoKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo);

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query);

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarker2AMD_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointData2NV_PostCall(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData);

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirect2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress);

VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirementsKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirementsKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirementsKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugReportCallbackEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);

VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT_PostCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL DebugReportMessageEXT_PostCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage);

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectTagEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo);

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectNameEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo);

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);

VKAPI_ATTR void VKAPI_CALL CmdBindTransformFeedbackBuffersEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes);

VKAPI_ATTR void VKAPI_CALL CmdBeginTransformFeedbackEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets);

VKAPI_ATTR void VKAPI_CALL CmdEndTransformFeedbackEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets);

VKAPI_ATTR void VKAPI_CALL CmdBeginQueryIndexedEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index);

VKAPI_ATTR void VKAPI_CALL CmdEndQueryIndexedEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectByteCountEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride);

VKAPI_ATTR uint32_t VKAPI_CALL GetImageViewHandleNVX_PostCall(encode::VulkanCaptureManager* manager, uint32_t result, VkDevice device, const VkImageViewHandleInfoNVX* pInfo);

VKAPI_ATTR VkResult VKAPI_CALL GetImageViewAddressNVX_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountAMD_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountAMD_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR VkResult VKAPI_CALL GetShaderInfoAMD_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo);

VKAPI_ATTR VkResult VKAPI_CALL CreateStreamDescriptorSurfaceGGP_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle);

VKAPI_ATTR VkResult VKAPI_CALL CreateViSurfaceNN_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);

VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings);

VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display);

VKAPI_ATTR VkResult VKAPI_CALL AcquireXlibDisplayEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display);

VKAPI_ATTR VkResult VKAPI_CALL GetRandROutputDisplayEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities);

VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo);

VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);

VKAPI_ATTR VkResult VKAPI_CALL RegisterDisplayEventEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue);

VKAPI_ATTR VkResult VKAPI_CALL GetRefreshCycleDurationGOOGLE_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetPastPresentationTimingGOOGLE_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings);

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles);

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode);

VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata);

VKAPI_ATTR VkResult VKAPI_CALL CreateIOSSurfaceMVK_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR VkResult VKAPI_CALL CreateMacOSSurfaceMVK_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo);

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo);

VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT_PostCall(encode::VulkanCaptureManager* manager, VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);

VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT_PostCall(encode::VulkanCaptureManager* manager, VkQueue queue);

VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT_PostCall(encode::VulkanCaptureManager* manager, VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);

VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);

VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);

VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger);

VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT_PostCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT_PostCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData);

VKAPI_ATTR VkResult VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer);

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL CreateValidationCacheEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache);

VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL MergeValidationCachesEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches);

VKAPI_ATTR VkResult VKAPI_CALL GetValidationCacheDataEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData);

VKAPI_ATTR void VKAPI_CALL CmdBindShadingRateImageNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);

VKAPI_ATTR void VKAPI_CALL CmdSetViewportShadingRatePaletteNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes);

VKAPI_ATTR void VKAPI_CALL CmdSetCoarseSampleOrderNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders);

VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure);

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNV_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNV_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements);

VKAPI_ATTR VkResult VKAPI_CALL BindAccelerationStructureMemoryNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos);

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructureNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset);

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode);

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth);

VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);

VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingShaderGroupHandlesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);

VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingShaderGroupHandlesNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);

VKAPI_ATTR VkResult VKAPI_CALL GetAccelerationStructureHandleNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData);

VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);

VKAPI_ATTR VkResult VKAPI_CALL CompileDeferredNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t shader);

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryHostPointerPropertiesEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties);

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainEXT* pTimeDomains);

VKAPI_ATTR VkResult VKAPI_CALL GetCalibratedTimestampsEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation);

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask);

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorEnableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables);

VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors);

VKAPI_ATTR void VKAPI_CALL CmdSetCheckpointNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const void* pCheckpointMarker);

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV_PostCall(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData);

VKAPI_ATTR VkResult VKAPI_CALL InitializePerformanceApiINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo);

VKAPI_ATTR void VKAPI_CALL UninitializePerformanceApiINTEL_PostCall(encode::VulkanCaptureManager* manager, VkDevice device);

VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceMarkerINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo);

VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceStreamMarkerINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo);

VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceOverrideINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo);

VKAPI_ATTR VkResult VKAPI_CALL AcquirePerformanceConfigurationINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration);

VKAPI_ATTR VkResult VKAPI_CALL ReleasePerformanceConfigurationINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPerformanceConfigurationINTEL configuration);

VKAPI_ATTR VkResult VKAPI_CALL QueueSetPerformanceConfigurationINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, VkPerformanceConfigurationINTEL configuration);

VKAPI_ATTR VkResult VKAPI_CALL GetPerformanceParameterINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue);

VKAPI_ATTR void VKAPI_CALL SetLocalDimmingAMD_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable);

VKAPI_ATTR VkResult VKAPI_CALL CreateImagePipeSurfaceFUCHSIA_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR VkResult VKAPI_CALL CreateMetalSurfaceEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressEXT_PostCall(encode::VulkanCaptureManager* manager, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModes2EXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);

VKAPI_ATTR VkResult VKAPI_CALL AcquireFullScreenExclusiveModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain);

VKAPI_ATTR VkResult VKAPI_CALL ReleaseFullScreenExclusiveModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain);

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModes2EXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes);

VKAPI_ATTR VkResult VKAPI_CALL CreateHeadlessSurfaceEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);

VKAPI_ATTR void VKAPI_CALL ResetQueryPoolEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);

VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFrontFace frontFace);

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);

VKAPI_ATTR VkResult VKAPI_CALL ReleaseSwapchainImagesEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkReleaseSwapchainImagesInfoEXT* pReleaseInfo);

VKAPI_ATTR void VKAPI_CALL GetGeneratedCommandsMemoryRequirementsNV_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL CmdPreprocessGeneratedCommandsNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

VKAPI_ATTR void VKAPI_CALL CmdExecuteGeneratedCommandsNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

VKAPI_ATTR void VKAPI_CALL CmdBindPipelineShaderGroupNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex);

VKAPI_ATTR VkResult VKAPI_CALL CreateIndirectCommandsLayoutNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout);

VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNV_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL AcquireDrmDisplayEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display);

VKAPI_ATTR VkResult VKAPI_CALL GetDrmDisplayEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display);

VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlotEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot);

VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlotEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL SetPrivateDataEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);

VKAPI_ATTR void VKAPI_CALL GetPrivateDataEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData);

VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateEnumNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2EXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkImageSubresource2EXT* pSubresource, VkSubresourceLayout2EXT* pLayout);

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceFaultInfoEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo);

VKAPI_ATTR VkResult VKAPI_CALL AcquireWinrtDisplayNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display);

VKAPI_ATTR VkResult VKAPI_CALL GetWinrtDisplayNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay);

VKAPI_ATTR VkResult VKAPI_CALL CreateDirectFBSurfaceEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb);

VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryZirconHandleFUCHSIA_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryZirconHandlePropertiesFUCHSIA_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties);

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreZirconHandleFUCHSIA_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo);

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreZirconHandleFUCHSIA_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);

VKAPI_ATTR void VKAPI_CALL CmdBindInvocationMaskHUAWEI_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryRemoteAddressNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress);

VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t patchControlPoints);

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkLogicOp logicOp);

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);

VKAPI_ATTR VkResult VKAPI_CALL CreateScreenSurfaceQNX_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceScreenPresentationSupportQNX_PostCall(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window);

VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables);

VKAPI_ATTR void VKAPI_CALL CmdDrawMultiEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawMultiIndexedEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset);

VKAPI_ATTR VkResult VKAPI_CALL CreateMicromapEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap);

VKAPI_ATTR void VKAPI_CALL DestroyMicromapEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CmdBuildMicromapsEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);

VKAPI_ATTR VkResult VKAPI_CALL BuildMicromapsEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);

VKAPI_ATTR VkResult VKAPI_CALL CopyMicromapEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo);

VKAPI_ATTR VkResult VKAPI_CALL CopyMicromapToMemoryEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo);

VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToMicromapEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo);

VKAPI_ATTR VkResult VKAPI_CALL WriteMicromapsPropertiesEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, size_t dataSize, void* pData, size_t stride);

VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapToMemoryEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToMicromapEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo);

VKAPI_ATTR void VKAPI_CALL CmdWriteMicromapsPropertiesEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);

VKAPI_ATTR void VKAPI_CALL GetDeviceMicromapCompatibilityEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility);

VKAPI_ATTR void VKAPI_CALL GetMicromapBuildSizesEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT* pBuildInfo, VkMicromapBuildSizesInfoEXT* pSizeInfo);

VKAPI_ATTR void VKAPI_CALL CmdDrawClusterHUAWEI_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

VKAPI_ATTR void VKAPI_CALL CmdDrawClusterIndirectHUAWEI_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);

VKAPI_ATTR void VKAPI_CALL SetDeviceMemoryPriorityEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, float priority);

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping);

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetHostMappingVALVE_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorSet descriptorSet, void** ppData);

VKAPI_ATTR void VKAPI_CALL CmdSetTessellationDomainOriginEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClampEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthClampEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetPolygonModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPolygonMode polygonMode);

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationSamplesEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples);

VKAPI_ATTR void VKAPI_CALL CmdSetSampleMaskEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples, const VkSampleMask* pSampleMask);

VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToCoverageEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToOneEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 logicOpEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables);

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEquationEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations);

VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteMaskEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks);

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationStreamEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t rasterizationStream);

VKAPI_ATTR void VKAPI_CALL CmdSetConservativeRasterizationModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode);

VKAPI_ATTR void VKAPI_CALL CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthClipEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendAdvancedEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced);

VKAPI_ATTR void VKAPI_CALL CmdSetProvokingVertexModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode);

VKAPI_ATTR void VKAPI_CALL CmdSetLineRasterizationModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode);

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipNegativeOneToOneEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne);

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingEnableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetViewportSwizzleNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles);

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorEnableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorLocationNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation);

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationModeNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode);

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableEnableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable);

VKAPI_ATTR void VKAPI_CALL CmdSetShadingRateImageEnableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetRepresentativeFragmentTestEnableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageReductionModeNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode);

VKAPI_ATTR void VKAPI_CALL GetShaderModuleIdentifierEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier);

VKAPI_ATTR void VKAPI_CALL GetShaderModuleCreateInfoIdentifierEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier);

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties);

VKAPI_ATTR VkResult VKAPI_CALL CreateOpticalFlowSessionNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession);

VKAPI_ATTR void VKAPI_CALL DestroyOpticalFlowSessionNV_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR VkResult VKAPI_CALL BindOpticalFlowSessionImageNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout);

VKAPI_ATTR void VKAPI_CALL CmdOpticalFlowExecuteNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo);

VKAPI_ATTR VkResult VKAPI_CALL GetFramebufferTilePropertiesQCOM_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL GetDynamicRenderingTilePropertiesQCOM_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties);

VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure);

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresIndirectKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts);

VKAPI_ATTR VkResult VKAPI_CALL CopyAccelerationStructureToMemoryKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);

VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToAccelerationStructureKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);

VKAPI_ATTR VkResult VKAPI_CALL WriteAccelerationStructuresPropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride);

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureToMemoryKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToAccelerationStructureKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetAccelerationStructureDeviceAddressKHR_PostCall(encode::VulkanCaptureManager* manager, VkDeviceAddress result, VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo);

VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);

VKAPI_ATTR void VKAPI_CALL GetDeviceAccelerationStructureCompatibilityKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility);

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureBuildSizesKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo);

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth);

VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);

VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirectKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress);

VKAPI_ATTR VkDeviceSize VKAPI_CALL GetRayTracingShaderGroupStackSizeKHR_PostCall(encode::VulkanCaptureManager* manager, VkDeviceSize result, VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader);

VKAPI_ATTR void VKAPI_CALL CmdSetRayTracingPipelineStackSizeKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t pipelineStackSize);

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

}

GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif