#include "../entrypoints_post.h"
#include "perfetto_encoder_commands.h"
#include "format/api_call_id.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugins)
GFXRECON_BEGIN_NAMESPACE(plugin_perfetto)
extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL CreateInstance_PostCall(encode::VulkanCaptureManager* manager, VkResult result, const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, result, pCreateInfo, pAllocator, pInstance);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyInstance_PostCall(encode::VulkanCaptureManager* manager, VkInstance instance, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(manager, instance, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(manager, result, instance, pPhysicalDeviceCount, pPhysicalDevices);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(manager, physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(manager, physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, result, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(manager, physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(manager, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(manager, physicalDevice, pMemoryProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDevice_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(manager, result, physicalDevice, pCreateInfo, pAllocator, pDevice);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDevice_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(manager, device, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(manager, device, queueFamilyIndex, queueIndex, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, result, queue, submitCount, pSubmits, fence);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(manager, result, queue);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(manager, result, device);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateMemory_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(manager, result, device, pAllocateInfo, pAllocator, pMemory);
return result;
}

VKAPI_ATTR void VKAPI_CALL FreeMemory_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(manager, device, memory, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL MapMemory_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(manager, result, device, memory, offset, size, flags, ppData);
return result;
}

VKAPI_ATTR void VKAPI_CALL UnmapMemory_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(manager, device, memory);
}

VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(manager, result, device, memoryRangeCount, pMemoryRanges);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(manager, result, device, memoryRangeCount, pMemoryRanges);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(manager, device, memory, pCommittedMemoryInBytes);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(manager, result, device, buffer, memory, memoryOffset);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(manager, result, device, image, memory, memoryOffset);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(manager, device, buffer, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(manager, device, image, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(manager, device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueBindSparse_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(manager, result, queue, bindInfoCount, pBindInfo, fence);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFence_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pFence);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFence_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(manager, device, fence, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetFences_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t fenceCount, const VkFence* pFences)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(manager, result, device, fenceCount, pFences);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkFence fence)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(manager, result, device, fence);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitForFences_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(manager, result, device, fenceCount, pFences, waitAll, timeout);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pSemaphore);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySemaphore_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(manager, device, semaphore, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateEvent_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pEvent);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyEvent_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(manager, device, event, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkEvent event)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(manager, result, device, event);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetEvent_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkEvent event)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(manager, result, device, event);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetEvent_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkEvent event)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(manager, result, device, event);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pQueryPool);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyQueryPool_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(manager, device, queryPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetQueryPoolResults_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(manager, result, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBuffer_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pBuffer);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBuffer_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(manager, device, buffer, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pView);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBufferView_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(manager, device, bufferView, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImage_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pImage);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImage_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(manager, device, image, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(manager, device, image, pSubresource, pLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImageView_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pView);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImageView_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(manager, device, imageView, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateShaderModule_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pShaderModule);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyShaderModule_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(manager, device, shaderModule, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pPipelineCache);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(manager, device, pipelineCache, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineCacheData_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(manager, result, device, pipelineCache, pDataSize, pData);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL MergePipelineCaches_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(manager, result, device, dstCache, srcCacheCount, pSrcCaches);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateGraphicsPipelines_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(manager, result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateComputePipelines_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(manager, result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipeline_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(manager, device, pipeline, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pPipelineLayout);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(manager, device, pipelineLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSampler_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pSampler);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySampler_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(manager, device, sampler, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pSetLayout);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(manager, device, descriptorSetLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pDescriptorPool);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(manager, device, descriptorPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(manager, result, device, descriptorPool, flags);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateDescriptorSets_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(manager, result, device, pAllocateInfo, pDescriptorSets);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(manager, result, device, descriptorPool, descriptorSetCount, pDescriptorSets);
return result;
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(manager, device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pFramebuffer);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(manager, device, framebuffer, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pRenderPass);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyRenderPass_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(manager, device, renderPass, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(manager, device, renderPass, pGranularity);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pCommandPool);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyCommandPool_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(manager, device, commandPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(manager, result, device, commandPool, flags);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateCommandBuffers_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(manager, result, device, pAllocateInfo, pCommandBuffers);
return result;
}

VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(manager, device, commandPool, commandBufferCount, pCommandBuffers);
}

VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(manager, result, commandBuffer, pBeginInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(manager, result, commandBuffer);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(manager, result, commandBuffer, flags);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindPipeline_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(manager, commandBuffer, pipelineBindPoint, pipeline);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewport_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pViewports);
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissor_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(manager, commandBuffer, firstScissor, scissorCount, pScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float lineWidth)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(manager, commandBuffer, lineWidth);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(manager, commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const float blendConstants[4])

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(manager, commandBuffer, blendConstants);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(manager, commandBuffer, minDepthBounds, maxDepthBounds);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(manager, commandBuffer, faceMask, compareMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(manager, commandBuffer, faceMask, writeMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(manager, commandBuffer, faceMask, reference);
}

VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(manager, commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(manager, commandBuffer, buffer, offset, indexType);
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdDraw_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(manager, commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(manager, commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatch_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(manager, commandBuffer, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(manager, commandBuffer, buffer, offset);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(manager, commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(manager, commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(manager, commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

VKAPI_ATTR void VKAPI_CALL CmdFillBuffer_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(manager, commandBuffer, dstBuffer, dstOffset, size, data);
}

VKAPI_ATTR void VKAPI_CALL CmdClearColorImage_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(manager, commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(manager, commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}

VKAPI_ATTR void VKAPI_CALL CmdClearAttachments_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(manager, commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(manager, commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(manager, commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(manager, commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(manager, commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginQuery_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(manager, commandBuffer, queryPool, query, flags);
}

VKAPI_ATTR void VKAPI_CALL CmdEndQuery_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(manager, commandBuffer, queryPool, query);
}

VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(manager, commandBuffer, queryPool, firstQuery, queryCount);
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(manager, commandBuffer, pipelineStage, queryPool, query);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(manager, commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}

VKAPI_ATTR void VKAPI_CALL CmdPushConstants_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(manager, commandBuffer, layout, stageFlags, offset, size, pValues);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(manager, commandBuffer, pRenderPassBegin, contents);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSubpassContents contents)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(manager, commandBuffer, contents);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(manager, commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(manager, commandBuffer, commandBufferCount, pCommandBuffers);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(manager, result, device, bindInfoCount, pBindInfos);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(manager, result, device, bindInfoCount, pBindInfos);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(manager, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t deviceMask)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(manager, commandBuffer, deviceMask);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchBase_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(manager, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(manager, result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(manager, device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(manager, device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(manager, physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(manager, physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(manager, physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(manager, result, physicalDevice, pImageFormatInfo, pImageFormatProperties);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(manager, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(manager, physicalDevice, pMemoryProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(manager, physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPool_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(manager, device, commandPool, flags);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(manager, device, pQueueInfo, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pYcbcrConversion);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(manager, device, ycbcrConversion, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplate_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(manager, device, descriptorUpdateTemplate, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(manager, device, pCreateInfo, pSupport);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pRenderPass);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(manager, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(manager, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(manager, commandBuffer, pSubpassEndInfo);
}

VKAPI_ATTR void VKAPI_CALL ResetQueryPool_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(manager, device, queryPool, firstQuery, queryCount);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValue_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSemaphore semaphore, uint64_t* pValue)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(manager, result, device, semaphore, pValue);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphores_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(manager, result, device, pWaitInfo, timeout);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphore_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(manager, result, device, pSignalInfo);
return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddress_PostCall(encode::VulkanCaptureManager* manager, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(manager, result, device, pInfo);
return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddress_PostCall(encode::VulkanCaptureManager* manager, uint64_t result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(manager, result, device, pInfo);
return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress_PostCall(encode::VulkanCaptureManager* manager, uint64_t result, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(manager, result, device, pInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolProperties_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(manager, result, physicalDevice, pToolCount, pToolProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlot_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pPrivateDataSlot);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(manager, device, privateDataSlot, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL SetPrivateData_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(manager, result, device, objectType, objectHandle, privateDataSlot, data);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetPrivateData_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(manager, device, objectType, objectHandle, privateDataSlot, pData);
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(manager, commandBuffer, event, pDependencyInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(manager, commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(manager, commandBuffer, eventCount, pEvents, pDependencyInfos);
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(manager, commandBuffer, pDependencyInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(manager, commandBuffer, stage, queryPool, query);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2>::Dispatch(manager, result, queue, submitCount, pSubmits, fence);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(manager, commandBuffer, pCopyBufferInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(manager, commandBuffer, pCopyImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(manager, commandBuffer, pCopyBufferToImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(manager, commandBuffer, pCopyImageToBufferInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(manager, commandBuffer, pBlitImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(manager, commandBuffer, pResolveImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRendering_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(manager, commandBuffer, pRenderingInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRendering_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(manager, commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCullMode_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCullModeFlags cullMode)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(manager, commandBuffer, cullMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFrontFace frontFace)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(manager, commandBuffer, frontFace);
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(manager, commandBuffer, primitiveTopology);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(manager, commandBuffer, viewportCount, pViewports);
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(manager, commandBuffer, scissorCount, pScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthTestEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(manager, commandBuffer, depthTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(manager, commandBuffer, depthWriteEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(manager, commandBuffer, depthCompareOp);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(manager, commandBuffer, depthBoundsTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(manager, commandBuffer, stencilTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(manager, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(manager, commandBuffer, rasterizerDiscardEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(manager, commandBuffer, depthBiasEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(manager, commandBuffer, primitiveRestartEnable);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirements_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(manager, device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirements_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(manager, device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(manager, instance, surface, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, surface, pSupported);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(manager, result, physicalDevice, surface, pSurfaceCapabilities);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(manager, result, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(manager, result, physicalDevice, surface, pPresentModeCount, pPresentModes);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pSwapchain);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(manager, device, swapchain, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(manager, result, device, swapchain, pSwapchainImageCount, pSwapchainImages);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImageKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(manager, result, device, swapchain, timeout, semaphore, fence, pImageIndex);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, result, queue, pPresentInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(manager, result, device, pDeviceGroupPresentCapabilities);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(manager, result, device, surface, pModes);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(manager, result, physicalDevice, surface, pRectCount, pRects);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImage2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(manager, result, device, pAcquireInfo, pImageIndex);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(manager, result, physicalDevice, pPropertyCount, pProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, result, physicalDevice, pPropertyCount, pProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(manager, result, physicalDevice, planeIndex, pDisplayCount, pDisplays);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(manager, result, physicalDevice, display, pPropertyCount, pProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(manager, result, physicalDevice, display, pCreateInfo, pAllocator, pMode);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(manager, result, physicalDevice, mode, planeIndex, pCapabilities);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(manager, result, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateXlibSurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR_PostCall(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, dpy, visualID);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateXcbSurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR_PostCall(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, connection, visual_id);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateWaylandSurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, display);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateAndroidSurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateWin32SurfaceKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR_PostCall(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(manager, result, physicalDevice, queueFamilyIndex);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceVideoCapabilitiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(manager, result, physicalDevice, pVideoProfile, pCapabilities);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(manager, result, physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateVideoSessionKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pVideoSession);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(manager, device, videoSession, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetVideoSessionMemoryRequirementsKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(manager, result, device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindVideoSessionMemoryKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(manager, result, device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateVideoSessionParametersKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pVideoSessionParameters);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL UpdateVideoSessionParametersKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(manager, result, device, videoSessionParameters, pUpdateInfo);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionParametersKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(manager, device, videoSessionParameters, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginVideoCodingKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(manager, commandBuffer, pBeginInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndVideoCodingKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(manager, commandBuffer, pEndCodingInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdControlVideoCodingKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(manager, commandBuffer, pCodingControlInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdDecodeVideoKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(manager, commandBuffer, pDecodeInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderingKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(manager, commandBuffer, pRenderingInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderingKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(manager, commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(manager, physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(manager, physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(manager, physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(manager, result, physicalDevice, pImageFormatInfo, pImageFormatProperties);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(manager, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(manager, physicalDevice, pMemoryProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(manager, physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(manager, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t deviceMask)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(manager, commandBuffer, deviceMask);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchBaseKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(manager, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(manager, device, commandPool, flags);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(manager, result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(manager, physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(manager, result, device, pGetWin32HandleInfo, pHandle);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandlePropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(manager, result, device, handleType, handle, pMemoryWin32HandleProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(manager, result, device, pGetFdInfo, pFd);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(manager, result, device, handleType, fd, pMemoryFdProperties);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(manager, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreWin32HandleKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(manager, result, device, pImportSemaphoreWin32HandleInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreWin32HandleKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(manager, result, device, pGetWin32HandleInfo, pHandle);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(manager, result, device, pImportSemaphoreFdInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(manager, result, device, pGetFdInfo, pFd);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(manager, commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplateKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(manager, device, descriptorUpdateTemplate, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pRenderPass);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(manager, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(manager, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(manager, commandBuffer, pSubpassEndInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(manager, result, device, swapchain);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(manager, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceWin32HandleKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(manager, result, device, pImportFenceWin32HandleInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceWin32HandleKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(manager, result, device, pGetWin32HandleInfo, pHandle);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(manager, result, device, pImportFenceFdInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceFdKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(manager, result, device, pGetFdInfo, pFd);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(manager, physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireProfilingLockKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(manager, result, device, pInfo);
return result;
}

VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(manager, device);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(manager, result, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(manager, result, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(manager, result, physicalDevice, pPropertyCount, pProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(manager, result, physicalDevice, pPropertyCount, pProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(manager, result, physicalDevice, display, pPropertyCount, pProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(manager, result, physicalDevice, pDisplayPlaneInfo, pCapabilities);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(manager, device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(manager, device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversionKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pYcbcrConversion);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(manager, device, ycbcrConversion, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(manager, result, device, bindInfoCount, pBindInfos);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(manager, result, device, bindInfoCount, pBindInfos);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(manager, device, pCreateInfo, pSupport);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValueKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSemaphore semaphore, uint64_t* pValue)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(manager, result, device, semaphore, pValue);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphoresKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(manager, result, device, pWaitInfo, timeout);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphoreKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(manager, result, device, pSignalInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceFragmentShadingRatesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(manager, result, physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2])

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(manager, commandBuffer, pFragmentSize, combinerOps);
}

VKAPI_ATTR VkResult VKAPI_CALL WaitForPresentKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(manager, result, device, swapchain, presentId, timeout);
return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressKHR_PostCall(encode::VulkanCaptureManager* manager, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(manager, result, device, pInfo);
return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddressKHR_PostCall(encode::VulkanCaptureManager* manager, uint64_t result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(manager, result, device, pInfo);
return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall(encode::VulkanCaptureManager* manager, uint64_t result, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(manager, result, device, pInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDeferredOperationKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(manager, result, device, pAllocator, pDeferredOperation);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDeferredOperationKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(manager, device, operation, pAllocator);
}

VKAPI_ATTR uint32_t VKAPI_CALL GetDeferredOperationMaxConcurrencyKHR_PostCall(encode::VulkanCaptureManager* manager, uint32_t result, VkDevice device, VkDeferredOperationKHR operation)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(manager, result, device, operation);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeferredOperationResultKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR operation)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(manager, result, device, operation);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DeferredOperationJoinKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR operation)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(manager, result, device, operation);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutablePropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(manager, result, device, pPipelineInfo, pExecutableCount, pProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutableStatisticsKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(manager, result, device, pExecutableInfo, pStatisticCount, pStatistics);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutableInternalRepresentationsKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(manager, result, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdEncodeVideoKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(manager, commandBuffer, pEncodeInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(manager, commandBuffer, event, pDependencyInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(manager, commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(manager, commandBuffer, eventCount, pEvents, pDependencyInfos);
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(manager, commandBuffer, pDependencyInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(manager, commandBuffer, stage, queryPool, query);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2KHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(manager, result, queue, submitCount, pSubmits, fence);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarker2AMD_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(manager, commandBuffer, stage, dstBuffer, dstOffset, marker);
}

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointData2NV_PostCall(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(manager, queue, pCheckpointDataCount, pCheckpointData);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(manager, commandBuffer, pCopyBufferInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(manager, commandBuffer, pCopyImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(manager, commandBuffer, pCopyBufferToImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(manager, commandBuffer, pCopyImageToBufferInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(manager, commandBuffer, pBlitImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(manager, commandBuffer, pResolveImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirect2KHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(manager, commandBuffer, indirectDeviceAddress);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirementsKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(manager, device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirementsKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(manager, device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirementsKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugReportCallbackEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pCallback);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT_PostCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(manager, instance, callback, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL DebugReportMessageEXT_PostCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(manager, instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectTagEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(manager, result, device, pTagInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectNameEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(manager, result, device, pNameInfo);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(manager, commandBuffer, pMarkerInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(manager, commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(manager, commandBuffer, pMarkerInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBindTransformFeedbackBuffersEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginTransformFeedbackEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(manager, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdEndTransformFeedbackEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(manager, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginQueryIndexedEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(manager, commandBuffer, queryPool, query, flags, index);
}

VKAPI_ATTR void VKAPI_CALL CmdEndQueryIndexedEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(manager, commandBuffer, queryPool, query, index);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectByteCountEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(manager, commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

VKAPI_ATTR uint32_t VKAPI_CALL GetImageViewHandleNVX_PostCall(encode::VulkanCaptureManager* manager, uint32_t result, VkDevice device, const VkImageViewHandleInfoNVX* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(manager, result, device, pInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetImageViewAddressNVX_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(manager, result, device, imageView, pProperties);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountAMD_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountAMD_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL GetShaderInfoAMD_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(manager, result, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateStreamDescriptorSurfaceGGP_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(manager, result, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(manager, result, device, memory, handleType, pHandle);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateViSurfaceNN_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(manager, commandBuffer, pConditionalRenderingBegin);
}

VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(manager, commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(manager, result, physicalDevice, display);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireXlibDisplayEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(manager, result, physicalDevice, dpy, display);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRandROutputDisplayEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(manager, result, physicalDevice, dpy, rrOutput, pDisplay);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(manager, result, physicalDevice, surface, pSurfaceCapabilities);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(manager, result, device, display, pDisplayPowerInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(manager, result, device, pDeviceEventInfo, pAllocator, pFence);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDisplayEventEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(manager, result, device, display, pDisplayEventInfo, pAllocator, pFence);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(manager, result, device, swapchain, counter, pCounterValue);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRefreshCycleDurationGOOGLE_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(manager, result, device, swapchain, pDisplayTimingProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPastPresentationTimingGOOGLE_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(manager, result, device, swapchain, pPresentationTimingCount, pPresentationTimings);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(manager, commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>::Dispatch(manager, commandBuffer, discardRectangleEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>::Dispatch(manager, commandBuffer, discardRectangleMode);
}

VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(manager, device, swapchainCount, pSwapchains, pMetadata);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateIOSSurfaceMVK_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateMacOSSurfaceMVK_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(manager, result, device, pNameInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(manager, result, device, pTagInfo);
return result;
}

VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT_PostCall(encode::VulkanCaptureManager* manager, VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(manager, queue, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT_PostCall(encode::VulkanCaptureManager* manager, VkQueue queue)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(manager, queue);
}

VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT_PostCall(encode::VulkanCaptureManager* manager, VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(manager, queue, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(manager, commandBuffer, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(manager, commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(manager, commandBuffer, pLabelInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pMessenger);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT_PostCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(manager, instance, messenger, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT_PostCall(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(manager, instance, messageSeverity, messageTypes, pCallbackData);
}

VKAPI_ATTR VkResult VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(manager, result, device, buffer, pProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(manager, result, device, pInfo, pBuffer);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(manager, commandBuffer, pSampleLocationsInfo);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT_PostCall(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(manager, physicalDevice, samples, pMultisampleProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(manager, result, device, image, pProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateValidationCacheEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pValidationCache);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(manager, device, validationCache, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL MergeValidationCachesEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(manager, result, device, dstCache, srcCacheCount, pSrcCaches);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetValidationCacheDataEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(manager, result, device, validationCache, pDataSize, pData);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindShadingRateImageNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(manager, commandBuffer, imageView, imageLayout);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportShadingRatePaletteNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoarseSampleOrderNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(manager, commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pAccelerationStructure);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNV_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(manager, device, accelerationStructure, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNV_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL BindAccelerationStructureMemoryNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(manager, result, device, bindInfoCount, pBindInfos);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructureNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(manager, commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(manager, commandBuffer, dst, src, mode);
}

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(manager, commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(manager, result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingShaderGroupHandlesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(manager, result, device, pipeline, firstGroup, groupCount, dataSize, pData);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingShaderGroupHandlesNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(manager, result, device, pipeline, firstGroup, groupCount, dataSize, pData);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetAccelerationStructureHandleNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(manager, result, device, accelerationStructure, dataSize, pData);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(manager, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

VKAPI_ATTR VkResult VKAPI_CALL CompileDeferredNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t shader)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(manager, result, device, pipeline, shader);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryHostPointerPropertiesEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(manager, result, device, handleType, pHostPointer, pMemoryHostPointerProperties);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(manager, commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainEXT* pTimeDomains)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(manager, result, physicalDevice, pTimeDomainCount, pTimeDomains);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetCalibratedTimestampsEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(manager, result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(manager, commandBuffer, taskCount, firstTask);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorEnableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>::Dispatch(manager, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
}

VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(manager, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCheckpointNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const void* pCheckpointMarker)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(manager, commandBuffer, pCheckpointMarker);
}

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV_PostCall(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(manager, queue, pCheckpointDataCount, pCheckpointData);
}

VKAPI_ATTR VkResult VKAPI_CALL InitializePerformanceApiINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(manager, result, device, pInitializeInfo);
return result;
}

VKAPI_ATTR void VKAPI_CALL UninitializePerformanceApiINTEL_PostCall(encode::VulkanCaptureManager* manager, VkDevice device)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(manager, device);
}

VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceMarkerINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(manager, result, commandBuffer, pMarkerInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceStreamMarkerINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(manager, result, commandBuffer, pMarkerInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceOverrideINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(manager, result, commandBuffer, pOverrideInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquirePerformanceConfigurationINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(manager, result, device, pAcquireInfo, pConfiguration);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ReleasePerformanceConfigurationINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPerformanceConfigurationINTEL configuration)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(manager, result, device, configuration);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSetPerformanceConfigurationINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, VkPerformanceConfigurationINTEL configuration)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(manager, result, queue, configuration);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPerformanceParameterINTEL_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(manager, result, device, parameter, pValue);
return result;
}

VKAPI_ATTR void VKAPI_CALL SetLocalDimmingAMD_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(manager, device, swapChain, localDimmingEnable);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImagePipeSurfaceFUCHSIA_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateMetalSurfaceEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressEXT_PostCall(encode::VulkanCaptureManager* manager, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(manager, result, device, pInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(manager, result, physicalDevice, pToolCount, pToolProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(manager, result, physicalDevice, pPropertyCount, pProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(manager, result, physicalDevice, pCombinationCount, pCombinations);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModes2EXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(manager, result, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireFullScreenExclusiveModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(manager, result, device, swapchain);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseFullScreenExclusiveModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(manager, result, device, swapchain);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModes2EXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(manager, result, device, pSurfaceInfo, pModes);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateHeadlessSurfaceEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(manager, commandBuffer, lineStippleFactor, lineStipplePattern);
}

VKAPI_ATTR void VKAPI_CALL ResetQueryPoolEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(manager, device, queryPool, firstQuery, queryCount);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCullModeFlags cullMode)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(manager, commandBuffer, cullMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFrontFace frontFace)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(manager, commandBuffer, frontFace);
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(manager, commandBuffer, primitiveTopology);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(manager, commandBuffer, viewportCount, pViewports);
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(manager, commandBuffer, scissorCount, pScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthTestEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(manager, commandBuffer, depthTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(manager, commandBuffer, depthWriteEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(manager, commandBuffer, depthCompareOp);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(manager, commandBuffer, depthBoundsTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(manager, commandBuffer, stencilTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(manager, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseSwapchainImagesEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkReleaseSwapchainImagesInfoEXT* pReleaseInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(manager, result, device, pReleaseInfo);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetGeneratedCommandsMemoryRequirementsNV_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(manager, device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL CmdPreprocessGeneratedCommandsNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(manager, commandBuffer, pGeneratedCommandsInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdExecuteGeneratedCommandsNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(manager, commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBindPipelineShaderGroupNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(manager, commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateIndirectCommandsLayoutNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNV_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(manager, device, indirectCommandsLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireDrmDisplayEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(manager, result, physicalDevice, drmFd, display);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDrmDisplayEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(manager, result, physicalDevice, drmFd, connectorId, display);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlotEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pPrivateDataSlot);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlotEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(manager, device, privateDataSlot, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL SetPrivateDataEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(manager, result, device, objectType, objectHandle, privateDataSlot, data);
return result;
}

VKAPI_ATTR void VKAPI_CALL GetPrivateDataEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(manager, device, objectType, objectHandle, privateDataSlot, pData);
}

VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateEnumNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, const VkFragmentShadingRateCombinerOpKHR combinerOps[2])

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(manager, commandBuffer, shadingRate, combinerOps);
}

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2EXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkImageSubresource2EXT* pSubresource, VkSubresourceLayout2EXT* pLayout)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(manager, device, image, pSubresource, pLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceFaultInfoEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(manager, result, device, pFaultCounts, pFaultInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireWinrtDisplayNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(manager, result, physicalDevice, display);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetWinrtDisplayNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(manager, result, physicalDevice, deviceRelativeId, pDisplay);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDirectFBSurfaceEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, dfb);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(manager, commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryZirconHandleFUCHSIA_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(manager, result, device, pGetZirconHandleInfo, pZirconHandle);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryZirconHandlePropertiesFUCHSIA_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(manager, result, device, handleType, zirconHandle, pMemoryZirconHandleProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreZirconHandleFUCHSIA_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, result, device, pImportSemaphoreZirconHandleInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreZirconHandleFUCHSIA_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, result, device, pGetZirconHandleInfo, pZirconHandle);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindInvocationMaskHUAWEI_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(manager, commandBuffer, imageView, imageLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryRemoteAddressNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(manager, result, device, pMemoryGetRemoteAddressInfo, pAddress);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t patchControlPoints)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(manager, commandBuffer, patchControlPoints);
}

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(manager, commandBuffer, rasterizerDiscardEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(manager, commandBuffer, depthBiasEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkLogicOp logicOp)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(manager, commandBuffer, logicOp);
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(manager, commandBuffer, primitiveRestartEnable);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateScreenSurfaceQNX_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);
return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceScreenPresentationSupportQNX_PostCall(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, window);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(manager, commandBuffer, attachmentCount, pColorWriteEnables);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMultiEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(manager, commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMultiIndexedEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(manager, commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateMicromapEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pMicromap);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyMicromapEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(manager, device, micromap, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL CmdBuildMicromapsEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(manager, commandBuffer, infoCount, pInfos);
}

VKAPI_ATTR VkResult VKAPI_CALL BuildMicromapsEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(manager, result, device, deferredOperation, infoCount, pInfos);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CopyMicromapEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(manager, result, device, deferredOperation, pInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CopyMicromapToMemoryEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(manager, result, device, deferredOperation, pInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToMicromapEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(manager, result, device, deferredOperation, pInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WriteMicromapsPropertiesEXT_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, size_t dataSize, void* pData, size_t stride)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(manager, result, device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(manager, commandBuffer, pInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapToMemoryEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(manager, commandBuffer, pInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToMicromapEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(manager, commandBuffer, pInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdWriteMicromapsPropertiesEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(manager, commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceMicromapCompatibilityEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(manager, device, pVersionInfo, pCompatibility);
}

VKAPI_ATTR void VKAPI_CALL GetMicromapBuildSizesEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT* pBuildInfo, VkMicromapBuildSizesInfoEXT* pSizeInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(manager, device, buildType, pBuildInfo, pSizeInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawClusterHUAWEI_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(manager, commandBuffer, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawClusterIndirectHUAWEI_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(manager, commandBuffer, buffer, offset);
}

VKAPI_ATTR void VKAPI_CALL SetDeviceMemoryPriorityEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, float priority)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(manager, device, memory, priority);
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(manager, device, pBindingReference, pHostMapping);
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetHostMappingVALVE_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorSet descriptorSet, void** ppData)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(manager, device, descriptorSet, ppData);
}

VKAPI_ATTR void VKAPI_CALL CmdSetTessellationDomainOriginEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(manager, commandBuffer, domainOrigin);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClampEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthClampEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(manager, commandBuffer, depthClampEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetPolygonModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPolygonMode polygonMode)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(manager, commandBuffer, polygonMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationSamplesEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(manager, commandBuffer, rasterizationSamples);
}

VKAPI_ATTR void VKAPI_CALL CmdSetSampleMaskEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples, const VkSampleMask* pSampleMask)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(manager, commandBuffer, samples, pSampleMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToCoverageEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(manager, commandBuffer, alphaToCoverageEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToOneEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(manager, commandBuffer, alphaToOneEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 logicOpEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(manager, commandBuffer, logicOpEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEquationEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}

VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteMaskEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationStreamEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t rasterizationStream)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(manager, commandBuffer, rasterizationStream);
}

VKAPI_ATTR void VKAPI_CALL CmdSetConservativeRasterizationModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(manager, commandBuffer, conservativeRasterizationMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(manager, commandBuffer, extraPrimitiveOverestimationSize);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthClipEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(manager, commandBuffer, depthClipEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(manager, commandBuffer, sampleLocationsEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendAdvancedEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}

VKAPI_ATTR void VKAPI_CALL CmdSetProvokingVertexModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(manager, commandBuffer, provokingVertexMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineRasterizationModeEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(manager, commandBuffer, lineRasterizationMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEnableEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(manager, commandBuffer, stippledLineEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipNegativeOneToOneEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(manager, commandBuffer, negativeOneToOne);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingEnableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(manager, commandBuffer, viewportWScalingEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportSwizzleNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorEnableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(manager, commandBuffer, coverageToColorEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorLocationNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(manager, commandBuffer, coverageToColorLocation);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationModeNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(manager, commandBuffer, coverageModulationMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableEnableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(manager, commandBuffer, coverageModulationTableEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(manager, commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetShadingRateImageEnableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(manager, commandBuffer, shadingRateImageEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetRepresentativeFragmentTestEnableNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(manager, commandBuffer, representativeFragmentTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageReductionModeNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(manager, commandBuffer, coverageReductionMode);
}

VKAPI_ATTR void VKAPI_CALL GetShaderModuleIdentifierEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(manager, device, shaderModule, pIdentifier);
}

VKAPI_ATTR void VKAPI_CALL GetShaderModuleCreateInfoIdentifierEXT_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(manager, device, pCreateInfo, pIdentifier);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(manager, result, physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateOpticalFlowSessionNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pSession);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyOpticalFlowSessionNV_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(manager, device, session, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL BindOpticalFlowSessionImageNV_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(manager, result, device, session, bindingPoint, view, layout);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdOpticalFlowExecuteNV_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(manager, commandBuffer, session, pExecuteInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL GetFramebufferTilePropertiesQCOM_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(manager, result, device, framebuffer, pPropertiesCount, pProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDynamicRenderingTilePropertiesQCOM_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(manager, result, device, pRenderingInfo, pProperties);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pAccelerationStructure);
return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(manager, device, accelerationStructure, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(manager, commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresIndirectKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(manager, commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}

VKAPI_ATTR VkResult VKAPI_CALL CopyAccelerationStructureToMemoryKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, result, device, deferredOperation, pInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToAccelerationStructureKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, result, device, deferredOperation, pInfo);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WriteAccelerationStructuresPropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, result, device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(manager, commandBuffer, pInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureToMemoryKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, commandBuffer, pInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToAccelerationStructureKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, commandBuffer, pInfo);
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetAccelerationStructureDeviceAddressKHR_PostCall(encode::VulkanCaptureManager* manager, VkDeviceAddress result, VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(manager, result, device, pInfo);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceAccelerationStructureCompatibilityKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(manager, device, pVersionInfo, pCompatibility);
}

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureBuildSizesKHR_PostCall(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(manager, device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(manager, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(manager, result, device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(manager, result, device, pipeline, firstGroup, groupCount, dataSize, pData);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirectKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(manager, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}

VKAPI_ATTR VkDeviceSize VKAPI_CALL GetRayTracingShaderGroupStackSizeKHR_PostCall(encode::VulkanCaptureManager* manager, VkDeviceSize result, VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(manager, result, device, pipeline, group, groupShader);
return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetRayTracingPipelineStackSizeKHR_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t pipelineStackSize)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(manager, commandBuffer, pipelineStackSize);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(manager, commandBuffer, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountEXT_PostCall(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)

{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
}
GFXRECON_END_NAMESPACE(plugin_perfetto)
GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)
