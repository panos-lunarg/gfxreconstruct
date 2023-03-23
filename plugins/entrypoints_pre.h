/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"), ** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense, ** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, ** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef PEFETTO_ENTRYPOINTS_PRE_H
#define PEFETTO_ENTRYPOINTS_PRE_H

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

VKAPI_ATTR void VKAPI_CALL CreateInstance_PreCall(encode::VulkanCaptureManager* manager, const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);

VKAPI_ATTR void VKAPI_CALL DestroyInstance_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDevices_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties);

VKAPI_ATTR void VKAPI_CALL CreateDevice_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice);

VKAPI_ATTR void VKAPI_CALL DestroyDevice_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);

VKAPI_ATTR void VKAPI_CALL QueueSubmit_PreCall(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);

VKAPI_ATTR void VKAPI_CALL QueueWaitIdle_PreCall(encode::VulkanCaptureManager* manager, VkQueue queue);

VKAPI_ATTR void VKAPI_CALL DeviceWaitIdle_PreCall(encode::VulkanCaptureManager* manager, VkDevice device);

VKAPI_ATTR void VKAPI_CALL AllocateMemory_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);

VKAPI_ATTR void VKAPI_CALL FreeMemory_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL MapMemory_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);

VKAPI_ATTR void VKAPI_CALL UnmapMemory_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory);

VKAPI_ATTR void VKAPI_CALL FlushMappedMemoryRanges_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);

VKAPI_ATTR void VKAPI_CALL InvalidateMappedMemoryRanges_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);

VKAPI_ATTR void VKAPI_CALL BindBufferMemory_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);

VKAPI_ATTR void VKAPI_CALL BindImageMemory_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties);

VKAPI_ATTR void VKAPI_CALL QueueBindSparse_PreCall(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);

VKAPI_ATTR void VKAPI_CALL CreateFence_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);

VKAPI_ATTR void VKAPI_CALL DestroyFence_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL ResetFences_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t fenceCount, const VkFence* pFences);

VKAPI_ATTR void VKAPI_CALL GetFenceStatus_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkFence fence);

VKAPI_ATTR void VKAPI_CALL WaitForFences_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);

VKAPI_ATTR void VKAPI_CALL CreateSemaphore_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);

VKAPI_ATTR void VKAPI_CALL DestroySemaphore_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CreateEvent_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent);

VKAPI_ATTR void VKAPI_CALL DestroyEvent_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetEventStatus_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkEvent event);

VKAPI_ATTR void VKAPI_CALL SetEvent_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkEvent event);

VKAPI_ATTR void VKAPI_CALL ResetEvent_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkEvent event);

VKAPI_ATTR void VKAPI_CALL CreateQueryPool_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);

VKAPI_ATTR void VKAPI_CALL DestroyQueryPool_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetQueryPoolResults_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags);

VKAPI_ATTR void VKAPI_CALL CreateBuffer_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);

VKAPI_ATTR void VKAPI_CALL DestroyBuffer_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CreateBufferView_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView);

VKAPI_ATTR void VKAPI_CALL DestroyBufferView_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CreateImage_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage);

VKAPI_ATTR void VKAPI_CALL DestroyImage_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout);

VKAPI_ATTR void VKAPI_CALL CreateImageView_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView);

VKAPI_ATTR void VKAPI_CALL DestroyImageView_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CreateShaderModule_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule);

VKAPI_ATTR void VKAPI_CALL DestroyShaderModule_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CreatePipelineCache_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache);

VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetPipelineCacheData_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);

VKAPI_ATTR void VKAPI_CALL MergePipelineCaches_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches);

VKAPI_ATTR void VKAPI_CALL CreateGraphicsPipelines_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);

VKAPI_ATTR void VKAPI_CALL CreateComputePipelines_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);

VKAPI_ATTR void VKAPI_CALL DestroyPipeline_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CreatePipelineLayout_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout);

VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CreateSampler_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler);

VKAPI_ATTR void VKAPI_CALL DestroySampler_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CreateDescriptorSetLayout_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout);

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CreateDescriptorPool_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL ResetDescriptorPool_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags);

VKAPI_ATTR void VKAPI_CALL AllocateDescriptorSets_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets);

VKAPI_ATTR void VKAPI_CALL FreeDescriptorSets_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies);

VKAPI_ATTR void VKAPI_CALL CreateFramebuffer_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);

VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CreateRenderPass_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);

VKAPI_ATTR void VKAPI_CALL DestroyRenderPass_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity);

VKAPI_ATTR void VKAPI_CALL CreateCommandPool_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);

VKAPI_ATTR void VKAPI_CALL DestroyCommandPool_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL ResetCommandPool_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags);

VKAPI_ATTR void VKAPI_CALL AllocateCommandBuffers_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);

VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);

VKAPI_ATTR void VKAPI_CALL BeginCommandBuffer_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);

VKAPI_ATTR void VKAPI_CALL EndCommandBuffer_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);

VKAPI_ATTR void VKAPI_CALL ResetCommandBuffer_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);

VKAPI_ATTR void VKAPI_CALL CmdBindPipeline_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);

VKAPI_ATTR void VKAPI_CALL CmdSetViewport_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports);

VKAPI_ATTR void VKAPI_CALL CmdSetScissor_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors);

VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float lineWidth);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);

VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const float blendConstants[4]);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);

VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets);

VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);

VKAPI_ATTR void VKAPI_CALL CmdDraw_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDispatch_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions);

VKAPI_ATTR void VKAPI_CALL CmdCopyImage_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions);

VKAPI_ATTR void VKAPI_CALL CmdBlitImage_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter);

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);

VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData);

VKAPI_ATTR void VKAPI_CALL CmdFillBuffer_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);

VKAPI_ATTR void VKAPI_CALL CmdClearColorImage_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);

VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);

VKAPI_ATTR void VKAPI_CALL CmdClearAttachments_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects);

VKAPI_ATTR void VKAPI_CALL CmdResolveImage_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions);

VKAPI_ATTR void VKAPI_CALL CmdSetEvent_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);

VKAPI_ATTR void VKAPI_CALL CmdResetEvent_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

VKAPI_ATTR void VKAPI_CALL CmdBeginQuery_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);

VKAPI_ATTR void VKAPI_CALL CmdEndQuery_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);

VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query);

VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);

VKAPI_ATTR void VKAPI_CALL CmdPushConstants_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues);

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents);

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSubpassContents contents);

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);

VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);

VKAPI_ATTR void VKAPI_CALL BindBufferMemory2_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);

VKAPI_ATTR void VKAPI_CALL BindImageMemory2_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t deviceMask);

VKAPI_ATTR void VKAPI_CALL CmdDispatchBase_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceGroups_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties2_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);

VKAPI_ATTR void VKAPI_CALL TrimCommandPool_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue);

VKAPI_ATTR void VKAPI_CALL CreateSamplerYcbcrConversion_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CreateDescriptorUpdateTemplate_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CreateRenderPass2_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo);

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo);

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);

VKAPI_ATTR void VKAPI_CALL ResetQueryPool_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);

VKAPI_ATTR void VKAPI_CALL GetSemaphoreCounterValue_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSemaphore semaphore, uint64_t* pValue);

VKAPI_ATTR void VKAPI_CALL WaitSemaphores_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);

VKAPI_ATTR void VKAPI_CALL SignalSemaphore_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo);

VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddress_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);

VKAPI_ATTR void VKAPI_CALL GetBufferOpaqueCaptureAddress_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceToolProperties_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties);

VKAPI_ATTR void VKAPI_CALL CreatePrivateDataSlot_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot);

VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL SetPrivateData_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);

VKAPI_ATTR void VKAPI_CALL GetPrivateData_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData);

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query);

VKAPI_ATTR void VKAPI_CALL QueueSubmit2_PreCall(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdBeginRendering_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);

VKAPI_ATTR void VKAPI_CALL CmdEndRendering_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);

VKAPI_ATTR void VKAPI_CALL CmdSetCullMode_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFrontFace frontFace);

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);

VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirements_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirements_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);

VKAPI_ATTR void VKAPI_CALL CreateSwapchainKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);

VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetSwapchainImagesKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);

VKAPI_ATTR void VKAPI_CALL AcquireNextImageKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);

VKAPI_ATTR void VKAPI_CALL QueuePresentKHR_PreCall(encode::VulkanCaptureManager* manager, VkQueue queue, const VkPresentInfoKHR* pPresentInfo);

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities);

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects);

VKAPI_ATTR void VKAPI_CALL AcquireNextImage2KHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties);

VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays);

VKAPI_ATTR void VKAPI_CALL GetDisplayModePropertiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties);

VKAPI_ATTR void VKAPI_CALL CreateDisplayModeKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode);

VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneCapabilitiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities);

VKAPI_ATTR void VKAPI_CALL CreateDisplayPlaneSurfaceKHR_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL CreateSharedSwapchainsKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains);

VKAPI_ATTR void VKAPI_CALL CreateXlibSurfaceKHR_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID);

VKAPI_ATTR void VKAPI_CALL CreateXcbSurfaceKHR_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id);

VKAPI_ATTR void VKAPI_CALL CreateWaylandSurfaceKHR_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display);

VKAPI_ATTR void VKAPI_CALL CreateAndroidSurfaceKHR_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL CreateWin32SurfaceKHR_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceVideoCapabilitiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties);

VKAPI_ATTR void VKAPI_CALL CreateVideoSessionKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession);

VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetVideoSessionMemoryRequirementsKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL BindVideoSessionMemoryKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos);

VKAPI_ATTR void VKAPI_CALL CreateVideoSessionParametersKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters);

VKAPI_ATTR void VKAPI_CALL UpdateVideoSessionParametersKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo);

VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionParametersKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CmdBeginVideoCodingKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo);

VKAPI_ATTR void VKAPI_CALL CmdEndVideoCodingKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo);

VKAPI_ATTR void VKAPI_CALL CmdControlVideoCodingKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo);

VKAPI_ATTR void VKAPI_CALL CmdDecodeVideoKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo);

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderingKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);

VKAPI_ATTR void VKAPI_CALL CmdEndRenderingKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t deviceMask);

VKAPI_ATTR void VKAPI_CALL CmdDispatchBaseKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);

VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);

VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandleKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);

VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandlePropertiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties);

VKAPI_ATTR void VKAPI_CALL GetMemoryFdKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd);

VKAPI_ATTR void VKAPI_CALL GetMemoryFdPropertiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);

VKAPI_ATTR void VKAPI_CALL ImportSemaphoreWin32HandleKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo);

VKAPI_ATTR void VKAPI_CALL GetSemaphoreWin32HandleKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);

VKAPI_ATTR void VKAPI_CALL ImportSemaphoreFdKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo);

VKAPI_ATTR void VKAPI_CALL GetSemaphoreFdKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd);

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites);

VKAPI_ATTR void VKAPI_CALL CreateDescriptorUpdateTemplateKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CreateRenderPass2KHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo);

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo);

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);

VKAPI_ATTR void VKAPI_CALL GetSwapchainStatusKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);

VKAPI_ATTR void VKAPI_CALL ImportFenceWin32HandleKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo);

VKAPI_ATTR void VKAPI_CALL GetFenceWin32HandleKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);

VKAPI_ATTR void VKAPI_CALL ImportFenceFdKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo);

VKAPI_ATTR void VKAPI_CALL GetFenceFdKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd);

VKAPI_ATTR void VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses);

VKAPI_ATTR void VKAPI_CALL AcquireProfilingLockKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo);

VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties);

VKAPI_ATTR void VKAPI_CALL GetDisplayModeProperties2KHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties);

VKAPI_ATTR void VKAPI_CALL GetDisplayPlaneCapabilities2KHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities);

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL CreateSamplerYcbcrConversionKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL BindBufferMemory2KHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);

VKAPI_ATTR void VKAPI_CALL BindImageMemory2KHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL GetSemaphoreCounterValueKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSemaphore semaphore, uint64_t* pValue);

VKAPI_ATTR void VKAPI_CALL WaitSemaphoresKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);

VKAPI_ATTR void VKAPI_CALL SignalSemaphoreKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFragmentShadingRatesKHR_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates);

VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);

VKAPI_ATTR void VKAPI_CALL WaitForPresentKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout);

VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddressKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);

VKAPI_ATTR void VKAPI_CALL GetBufferOpaqueCaptureAddressKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);

VKAPI_ATTR void VKAPI_CALL CreateDeferredOperationKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation);

VKAPI_ATTR void VKAPI_CALL DestroyDeferredOperationKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetDeferredOperationMaxConcurrencyKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR operation);

VKAPI_ATTR void VKAPI_CALL GetDeferredOperationResultKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR operation);

VKAPI_ATTR void VKAPI_CALL DeferredOperationJoinKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR operation);

VKAPI_ATTR void VKAPI_CALL GetPipelineExecutablePropertiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties);

VKAPI_ATTR void VKAPI_CALL GetPipelineExecutableStatisticsKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics);

VKAPI_ATTR void VKAPI_CALL GetPipelineExecutableInternalRepresentationsKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations);

VKAPI_ATTR void VKAPI_CALL CmdEncodeVideoKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo);

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query);

VKAPI_ATTR void VKAPI_CALL QueueSubmit2KHR_PreCall(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarker2AMD_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointData2NV_PreCall(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData);

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirect2KHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress);

VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirementsKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirementsKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirementsKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL CreateDebugReportCallbackEXT_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);

VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL DebugReportMessageEXT_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage);

VKAPI_ATTR void VKAPI_CALL DebugMarkerSetObjectTagEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo);

VKAPI_ATTR void VKAPI_CALL DebugMarkerSetObjectNameEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo);

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);

VKAPI_ATTR void VKAPI_CALL CmdBindTransformFeedbackBuffersEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes);

VKAPI_ATTR void VKAPI_CALL CmdBeginTransformFeedbackEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets);

VKAPI_ATTR void VKAPI_CALL CmdEndTransformFeedbackEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets);

VKAPI_ATTR void VKAPI_CALL CmdBeginQueryIndexedEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index);

VKAPI_ATTR void VKAPI_CALL CmdEndQueryIndexedEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectByteCountEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride);

VKAPI_ATTR void VKAPI_CALL GetImageViewHandleNVX_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageViewHandleInfoNVX* pInfo);

VKAPI_ATTR void VKAPI_CALL GetImageViewAddressNVX_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountAMD_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountAMD_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL GetShaderInfoAMD_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo);

VKAPI_ATTR void VKAPI_CALL CreateStreamDescriptorSurfaceGGP_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties);

VKAPI_ATTR void VKAPI_CALL GetMemoryWin32HandleNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle);

VKAPI_ATTR void VKAPI_CALL CreateViSurfaceNN_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);

VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings);

VKAPI_ATTR void VKAPI_CALL ReleaseDisplayEXT_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkDisplayKHR display);

VKAPI_ATTR void VKAPI_CALL AcquireXlibDisplayEXT_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display);

VKAPI_ATTR void VKAPI_CALL GetRandROutputDisplayEXT_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities);

VKAPI_ATTR void VKAPI_CALL DisplayPowerControlEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo);

VKAPI_ATTR void VKAPI_CALL RegisterDeviceEventEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);

VKAPI_ATTR void VKAPI_CALL RegisterDisplayEventEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);

VKAPI_ATTR void VKAPI_CALL GetSwapchainCounterEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue);

VKAPI_ATTR void VKAPI_CALL GetRefreshCycleDurationGOOGLE_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties);

VKAPI_ATTR void VKAPI_CALL GetPastPresentationTimingGOOGLE_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings);

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles);

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleModeEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode);

VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata);

VKAPI_ATTR void VKAPI_CALL CreateIOSSurfaceMVK_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL CreateMacOSSurfaceMVK_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL SetDebugUtilsObjectNameEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo);

VKAPI_ATTR void VKAPI_CALL SetDebugUtilsObjectTagEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo);

VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT_PreCall(encode::VulkanCaptureManager* manager, VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);

VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT_PreCall(encode::VulkanCaptureManager* manager, VkQueue queue);

VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT_PreCall(encode::VulkanCaptureManager* manager, VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);

VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);

VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);

VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);

VKAPI_ATTR void VKAPI_CALL CreateDebugUtilsMessengerEXT_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger);

VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData);

VKAPI_ATTR void VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties);

VKAPI_ATTR void VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer);

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties);

VKAPI_ATTR void VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties);

VKAPI_ATTR void VKAPI_CALL CreateValidationCacheEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache);

VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL MergeValidationCachesEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches);

VKAPI_ATTR void VKAPI_CALL GetValidationCacheDataEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData);

VKAPI_ATTR void VKAPI_CALL CmdBindShadingRateImageNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);

VKAPI_ATTR void VKAPI_CALL CmdSetViewportShadingRatePaletteNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes);

VKAPI_ATTR void VKAPI_CALL CmdSetCoarseSampleOrderNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders);

VKAPI_ATTR void VKAPI_CALL CreateAccelerationStructureNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure);

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL BindAccelerationStructureMemoryNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos);

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructureNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset);

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode);

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth);

VKAPI_ATTR void VKAPI_CALL CreateRayTracingPipelinesNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);

VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupHandlesKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);

VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupHandlesNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureHandleNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData);

VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);

VKAPI_ATTR void VKAPI_CALL CompileDeferredNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, uint32_t shader);

VKAPI_ATTR void VKAPI_CALL GetMemoryHostPointerPropertiesEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties);

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainEXT* pTimeDomains);

VKAPI_ATTR void VKAPI_CALL GetCalibratedTimestampsEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation);

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask);

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorEnableNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables);

VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors);

VKAPI_ATTR void VKAPI_CALL CmdSetCheckpointNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const void* pCheckpointMarker);

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV_PreCall(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData);

VKAPI_ATTR void VKAPI_CALL InitializePerformanceApiINTEL_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo);

VKAPI_ATTR void VKAPI_CALL UninitializePerformanceApiINTEL_PreCall(encode::VulkanCaptureManager* manager, VkDevice device);

VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceMarkerINTEL_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo);

VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceStreamMarkerINTEL_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo);

VKAPI_ATTR void VKAPI_CALL CmdSetPerformanceOverrideINTEL_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo);

VKAPI_ATTR void VKAPI_CALL AcquirePerformanceConfigurationINTEL_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration);

VKAPI_ATTR void VKAPI_CALL ReleasePerformanceConfigurationINTEL_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPerformanceConfigurationINTEL configuration);

VKAPI_ATTR void VKAPI_CALL QueueSetPerformanceConfigurationINTEL_PreCall(encode::VulkanCaptureManager* manager, VkQueue queue, VkPerformanceConfigurationINTEL configuration);

VKAPI_ATTR void VKAPI_CALL GetPerformanceParameterINTEL_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue);

VKAPI_ATTR void VKAPI_CALL SetLocalDimmingAMD_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable);

VKAPI_ATTR void VKAPI_CALL CreateImagePipeSurfaceFUCHSIA_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL CreateMetalSurfaceEXT_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL GetBufferDeviceAddressEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSurfacePresentModes2EXT_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);

VKAPI_ATTR void VKAPI_CALL AcquireFullScreenExclusiveModeEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain);

VKAPI_ATTR void VKAPI_CALL ReleaseFullScreenExclusiveModeEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain);

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupSurfacePresentModes2EXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes);

VKAPI_ATTR void VKAPI_CALL CreateHeadlessSurfaceEXT_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);

VKAPI_ATTR void VKAPI_CALL ResetQueryPoolEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);

VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFrontFace frontFace);

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);

VKAPI_ATTR void VKAPI_CALL ReleaseSwapchainImagesEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkReleaseSwapchainImagesInfoEXT* pReleaseInfo);

VKAPI_ATTR void VKAPI_CALL GetGeneratedCommandsMemoryRequirementsNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements);

VKAPI_ATTR void VKAPI_CALL CmdPreprocessGeneratedCommandsNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

VKAPI_ATTR void VKAPI_CALL CmdExecuteGeneratedCommandsNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

VKAPI_ATTR void VKAPI_CALL CmdBindPipelineShaderGroupNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex);

VKAPI_ATTR void VKAPI_CALL CreateIndirectCommandsLayoutNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout);

VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL AcquireDrmDisplayEXT_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display);

VKAPI_ATTR void VKAPI_CALL GetDrmDisplayEXT_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display);

VKAPI_ATTR void VKAPI_CALL CreatePrivateDataSlotEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot);

VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlotEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL SetPrivateDataEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);

VKAPI_ATTR void VKAPI_CALL GetPrivateDataEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData);

VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateEnumNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2EXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkImageSubresource2EXT* pSubresource, VkSubresourceLayout2EXT* pLayout);

VKAPI_ATTR void VKAPI_CALL GetDeviceFaultInfoEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo);

VKAPI_ATTR void VKAPI_CALL AcquireWinrtDisplayNV_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkDisplayKHR display);

VKAPI_ATTR void VKAPI_CALL GetWinrtDisplayNV_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay);

VKAPI_ATTR void VKAPI_CALL CreateDirectFBSurfaceEXT_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb);

VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);

VKAPI_ATTR void VKAPI_CALL GetMemoryZirconHandleFUCHSIA_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);

VKAPI_ATTR void VKAPI_CALL GetMemoryZirconHandlePropertiesFUCHSIA_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties);

VKAPI_ATTR void VKAPI_CALL ImportSemaphoreZirconHandleFUCHSIA_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo);

VKAPI_ATTR void VKAPI_CALL GetSemaphoreZirconHandleFUCHSIA_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);

VKAPI_ATTR void VKAPI_CALL CmdBindInvocationMaskHUAWEI_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);

VKAPI_ATTR void VKAPI_CALL GetMemoryRemoteAddressNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress);

VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t patchControlPoints);

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkLogicOp logicOp);

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);

VKAPI_ATTR void VKAPI_CALL CreateScreenSurfaceQNX_PreCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceScreenPresentationSupportQNX_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window);

VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables);

VKAPI_ATTR void VKAPI_CALL CmdDrawMultiEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawMultiIndexedEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset);

VKAPI_ATTR void VKAPI_CALL CreateMicromapEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap);

VKAPI_ATTR void VKAPI_CALL DestroyMicromapEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CmdBuildMicromapsEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);

VKAPI_ATTR void VKAPI_CALL BuildMicromapsEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);

VKAPI_ATTR void VKAPI_CALL CopyMicromapEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo);

VKAPI_ATTR void VKAPI_CALL CopyMicromapToMemoryEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo);

VKAPI_ATTR void VKAPI_CALL CopyMemoryToMicromapEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo);

VKAPI_ATTR void VKAPI_CALL WriteMicromapsPropertiesEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, size_t dataSize, void* pData, size_t stride);

VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapToMemoryEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToMicromapEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo);

VKAPI_ATTR void VKAPI_CALL CmdWriteMicromapsPropertiesEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);

VKAPI_ATTR void VKAPI_CALL GetDeviceMicromapCompatibilityEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility);

VKAPI_ATTR void VKAPI_CALL GetMicromapBuildSizesEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT* pBuildInfo, VkMicromapBuildSizesInfoEXT* pSizeInfo);

VKAPI_ATTR void VKAPI_CALL CmdDrawClusterHUAWEI_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

VKAPI_ATTR void VKAPI_CALL CmdDrawClusterIndirectHUAWEI_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);

VKAPI_ATTR void VKAPI_CALL SetDeviceMemoryPriorityEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, float priority);

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping);

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetHostMappingVALVE_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorSet descriptorSet, void** ppData);

VKAPI_ATTR void VKAPI_CALL CmdSetTessellationDomainOriginEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClampEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthClampEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetPolygonModeEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPolygonMode polygonMode);

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationSamplesEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples);

VKAPI_ATTR void VKAPI_CALL CmdSetSampleMaskEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples, const VkSampleMask* pSampleMask);

VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToCoverageEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToOneEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 logicOpEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables);

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEquationEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations);

VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteMaskEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks);

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationStreamEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t rasterizationStream);

VKAPI_ATTR void VKAPI_CALL CmdSetConservativeRasterizationModeEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode);

VKAPI_ATTR void VKAPI_CALL CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthClipEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendAdvancedEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced);

VKAPI_ATTR void VKAPI_CALL CmdSetProvokingVertexModeEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode);

VKAPI_ATTR void VKAPI_CALL CmdSetLineRasterizationModeEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode);

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEnableEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipNegativeOneToOneEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne);

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingEnableNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetViewportSwizzleNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles);

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorEnableNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorLocationNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation);

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationModeNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode);

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableEnableNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable);

VKAPI_ATTR void VKAPI_CALL CmdSetShadingRateImageEnableNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetRepresentativeFragmentTestEnableNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable);

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageReductionModeNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode);

VKAPI_ATTR void VKAPI_CALL GetShaderModuleIdentifierEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier);

VKAPI_ATTR void VKAPI_CALL GetShaderModuleCreateInfoIdentifierEXT_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier);

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties);

VKAPI_ATTR void VKAPI_CALL CreateOpticalFlowSessionNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession);

VKAPI_ATTR void VKAPI_CALL DestroyOpticalFlowSessionNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL BindOpticalFlowSessionImageNV_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout);

VKAPI_ATTR void VKAPI_CALL CmdOpticalFlowExecuteNV_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo);

VKAPI_ATTR void VKAPI_CALL GetFramebufferTilePropertiesQCOM_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties);

VKAPI_ATTR void VKAPI_CALL GetDynamicRenderingTilePropertiesQCOM_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties);

VKAPI_ATTR void VKAPI_CALL CreateAccelerationStructureKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure);

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator);

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresIndirectKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts);

VKAPI_ATTR void VKAPI_CALL CopyAccelerationStructureToMemoryKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);

VKAPI_ATTR void VKAPI_CALL CopyMemoryToAccelerationStructureKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);

VKAPI_ATTR void VKAPI_CALL WriteAccelerationStructuresPropertiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride);

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureToMemoryKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);

VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToAccelerationStructureKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureDeviceAddressKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo);

VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);

VKAPI_ATTR void VKAPI_CALL GetDeviceAccelerationStructureCompatibilityKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility);

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureBuildSizesKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo);

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth);

VKAPI_ATTR void VKAPI_CALL CreateRayTracingPipelinesKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);

VKAPI_ATTR void VKAPI_CALL GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirectKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress);

VKAPI_ATTR void VKAPI_CALL GetRayTracingShaderGroupStackSizeKHR_PreCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader);

VKAPI_ATTR void VKAPI_CALL CmdSetRayTracingPipelineStackSizeKHR_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t pipelineStackSize);

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountEXT_PreCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

}

GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
