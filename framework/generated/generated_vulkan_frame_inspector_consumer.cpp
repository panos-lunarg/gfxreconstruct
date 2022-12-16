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

#include "generated/generated_vulkan_frame_inspector_consumer.h"

#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanFrameInspectorConsumer::Process_vkCreateInstance(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    if (!pInstance->IsNull()) { pInstance->SetHandleLength(1); }
    InstanceInfo handle_info;
    pInstance->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateInstance(returnValue, pCreateInfo, pAllocator, pInstance);
    CheckResult("vkCreateInstance", returnValue, replay_result);

    AddHandle<InstanceInfo>(format::kNullHandleId, pInstance->GetPointer(), pInstance->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddInstanceInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);

   //  OverrideDestroyInstance(GetInstanceTable(in_instance->handle)->DestroyInstance, in_instance, pAllocator);
    RemoveHandle(instance, &VulkanObjectInfoTable::RemoveInstanceInfo);
}

void VulkanFrameInspectorConsumer::Process_vkEnumeratePhysicalDevices(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    pPhysicalDeviceCount->IsNull() ? nullptr : pPhysicalDeviceCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, InstanceInfo>("vkEnumeratePhysicalDevices", returnValue, instance, kInstanceArrayEnumeratePhysicalDevices, pPhysicalDeviceCount, pPhysicalDevices, &VulkanObjectInfoTable::GetInstanceInfo));
    if (!pPhysicalDevices->IsNull()) { pPhysicalDevices->SetHandleLength(*pPhysicalDeviceCount->GetOutputPointer()); }
    std::vector<PhysicalDeviceInfo> handle_info(*pPhysicalDeviceCount->GetOutputPointer());
    for (size_t i = 0; i < *pPhysicalDeviceCount->GetOutputPointer(); ++i) { pPhysicalDevices->SetConsumerData(i, &handle_info[i]); }

//     VkResult replay_result = OverrideEnumeratePhysicalDevices(GetInstanceTable(in_instance->handle)->EnumeratePhysicalDevices, returnValue, in_instance, pPhysicalDeviceCount, pPhysicalDevices);
    // CheckResult("vkEnumeratePhysicalDevices", returnValue, replay_result);

    if (pPhysicalDevices->IsNull()) { SetOutputArrayCount<InstanceInfo>(instance, kInstanceArrayEnumeratePhysicalDevices, *pPhysicalDeviceCount->GetOutputPointer(), &VulkanObjectInfoTable::GetInstanceInfo); }
    AddHandles<PhysicalDeviceInfo>(instance, pPhysicalDevices->GetPointer(), pPhysicalDevices->GetLength(), pPhysicalDevices->GetHandlePointer(), *pPhysicalDeviceCount->GetOutputPointer(), std::move(handle_info), &VulkanObjectInfoTable::AddPhysicalDeviceInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pFeatures->IsNull() ? nullptr : pFeatures->AllocateOutputData(1);

   //  OverrideGetPhysicalDeviceFeatures(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceFeatures, in_physicalDevice, pFeatures);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pFormatProperties->IsNull() ? nullptr : pFormatProperties->AllocateOutputData(1);

   //  OverrideGetPhysicalDeviceFormatProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceFormatProperties, in_physicalDevice, format, pFormatProperties);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pImageFormatProperties->IsNull() ? nullptr : pImageFormatProperties->AllocateOutputData(1);

//     VkResult replay_result = OverrideGetPhysicalDeviceImageFormatProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceImageFormatProperties, returnValue, in_physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    // CheckResult("vkGetPhysicalDeviceImageFormatProperties", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1);

   //  OverrideGetPhysicalDeviceProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceProperties, in_physicalDevice, pProperties);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pQueueFamilyPropertyCount->IsNull() ? nullptr : pQueueFamilyPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyProperties", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties, pQueueFamilyPropertyCount, pQueueFamilyProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pQueueFamilyProperties->IsNull()) { pQueueFamilyProperties->AllocateOutputData(*pQueueFamilyPropertyCount->GetOutputPointer()); }

   //  OverrideGetPhysicalDeviceQueueFamilyProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceQueueFamilyProperties, in_physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    if (pQueueFamilyProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties, *pQueueFamilyPropertyCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pMemoryProperties->IsNull() ? nullptr : pMemoryProperties->AllocateOutputData(1);

   //  OverrideGetPhysicalDeviceMemoryProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceMemoryProperties, in_physicalDevice, pMemoryProperties);
}

void VulkanFrameInspectorConsumer::Process_vkCreateDevice(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*             pDevice)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pDevice->IsNull()) { pDevice->SetHandleLength(1); }
    DeviceInfo handle_info;
    pDevice->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateDevice(returnValue, in_physicalDevice, pCreateInfo, pAllocator, pDevice);
    // CheckResult("vkCreateDevice", returnValue, replay_result);

    AddHandle<DeviceInfo>(physicalDevice, pDevice->GetPointer(), pDevice->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDeviceInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

   //  OverrideDestroyDevice(GetDeviceTable(in_device->handle)->DestroyDevice, in_device, pAllocator);
    RemoveHandle(device, &VulkanObjectInfoTable::RemoveDeviceInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceQueue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pQueue->IsNull()) { pQueue->SetHandleLength(1); }
    QueueInfo handle_info;
    pQueue->SetConsumerData(0, &handle_info);

   //  OverrideGetDeviceQueue(GetDeviceTable(in_device->handle)->GetDeviceQueue, in_device, queueFamilyIndex, queueIndex, pQueue);

    AddHandle<QueueInfo>(device, pQueue->GetPointer(), pQueue->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddQueueInfo);
}

void VulkanFrameInspectorConsumer::Process_vkQueueSubmit(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
    format::HandleId                            fence)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

    MapStructArrayHandles(pSubmits->GetMetaStructPointer(), pSubmits->GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetFenceInfo(fence);

//     VkResult replay_result = OverrideQueueSubmit(GetDeviceTable(in_queue->handle)->QueueSubmit, returnValue, in_queue, submitCount, pSubmits, in_fence);
    // CheckResult("vkQueueSubmit", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

//     VkResult replay_result = OverrideQueueWaitIdle(GetDeviceTable(in_queue->handle)->QueueWaitIdle, returnValue, in_queue);
    // CheckResult("vkQueueWaitIdle", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

//     VkResult replay_result = OverrideDeviceWaitIdle(GetDeviceTable(in_device->handle)->DeviceWaitIdle, returnValue, in_device);
    // CheckResult("vkDeviceWaitIdle", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkAllocateMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*       pMemory)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pAllocateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pMemory->IsNull()) { pMemory->SetHandleLength(1); }
    DeviceMemoryInfo handle_info;
    pMemory->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideAllocateMemory(GetDeviceTable(in_device->handle)->AllocateMemory, returnValue, in_device, pAllocateInfo, pAllocator, pMemory);
    // CheckResult("vkAllocateMemory", returnValue, replay_result);

    AddHandle<DeviceMemoryInfo>(device, pMemory->GetPointer(), pMemory->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDeviceMemoryInfo);
}

void VulkanFrameInspectorConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_memory = GetObjectInfoTable().GetDeviceMemoryInfo(memory);

   //  OverrideFreeMemory(GetDeviceTable(in_device->handle)->FreeMemory, in_device, in_memory, pAllocator);
    RemoveHandle(memory, &VulkanObjectInfoTable::RemoveDeviceMemoryInfo);
}

void VulkanFrameInspectorConsumer::Process_vkMapMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_memory = GetObjectInfoTable().GetDeviceMemoryInfo(memory);
    void** out_ppData = ppData->IsNull() ? nullptr : ppData->AllocateOutputData(1);

//     VkResult replay_result = OverrideMapMemory(GetDeviceTable(in_device->handle)->MapMemory, returnValue, in_device, in_memory, offset, size, flags, out_ppData);
    // CheckResult("vkMapMemory", returnValue, replay_result);

    // PostProcessExternalObject(replay_result, (*ppData->GetPointer()), *ppData->GetOutputPointer(), format::ApiCallId::ApiCall_vkMapMemory, "vkMapMemory");
}

void VulkanFrameInspectorConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_memory = GetObjectInfoTable().GetDeviceMemoryInfo(memory);

   //  OverrideUnmapMemory(GetDeviceTable(in_device->handle)->UnmapMemory, in_device, in_memory);
}

void VulkanFrameInspectorConsumer::Process_vkFlushMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pMemoryRanges->GetMetaStructPointer(), pMemoryRanges->GetLength(), GetObjectInfoTable());

//     VkResult replay_result = OverrideFlushMappedMemoryRanges(GetDeviceTable(in_device->handle)->FlushMappedMemoryRanges, returnValue, in_device, memoryRangeCount, pMemoryRanges);
    // CheckResult("vkFlushMappedMemoryRanges", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkInvalidateMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pMemoryRanges->GetMetaStructPointer(), pMemoryRanges->GetLength(), GetObjectInfoTable());

//     VkResult replay_result = OverrideInvalidateMappedMemoryRanges(GetDeviceTable(in_device->handle)->InvalidateMappedMemoryRanges, returnValue, in_device, memoryRangeCount, pMemoryRanges);
    // CheckResult("vkInvalidateMappedMemoryRanges", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_memory = GetObjectInfoTable().GetDeviceMemoryInfo(memory);
    pCommittedMemoryInBytes->IsNull() ? nullptr : pCommittedMemoryInBytes->AllocateOutputData(1, static_cast<VkDeviceSize>(0));

   //  OverrideGetDeviceMemoryCommitment(GetDeviceTable(in_device->handle)->GetDeviceMemoryCommitment, in_device, in_memory, pCommittedMemoryInBytes);
}

void VulkanFrameInspectorConsumer::Process_vkBindBufferMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            buffer,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);
    auto in_memory = GetObjectInfoTable().GetDeviceMemoryInfo(memory);

//     VkResult replay_result = OverrideBindBufferMemory(GetDeviceTable(in_device->handle)->BindBufferMemory, returnValue, in_device, in_buffer, in_memory, memoryOffset);
    // CheckResult("vkBindBufferMemory", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkBindImageMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_image = GetObjectInfoTable().GetImageInfo(image);
    auto in_memory = GetObjectInfoTable().GetDeviceMemoryInfo(memory);

//     VkResult replay_result = OverrideBindImageMemory(GetDeviceTable(in_device->handle)->BindImageMemory, returnValue, in_device, in_image, in_memory, memoryOffset);
    // CheckResult("vkBindImageMemory", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);
    pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1);

   //  OverrideGetBufferMemoryRequirements(GetDeviceTable(in_device->handle)->GetBufferMemoryRequirements, in_device, in_buffer, pMemoryRequirements);
}

void VulkanFrameInspectorConsumer::Process_vkGetImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_image = GetObjectInfoTable().GetImageInfo(image);
    pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1);

   //  OverrideGetImageMemoryRequirements(GetDeviceTable(in_device->handle)->GetImageMemoryRequirements, in_device, in_image, pMemoryRequirements);
}

void VulkanFrameInspectorConsumer::Process_vkGetImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_image = GetObjectInfoTable().GetImageInfo(image);
    pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, ImageInfo>("vkGetImageSparseMemoryRequirements", VK_SUCCESS, image, kImageArrayGetImageSparseMemoryRequirements, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &VulkanObjectInfoTable::GetImageInfo));
    if (!pSparseMemoryRequirements->IsNull()) { pSparseMemoryRequirements->AllocateOutputData(*pSparseMemoryRequirementCount->GetOutputPointer()); }

   //  OverrideGetImageSparseMemoryRequirements(GetDeviceTable(in_device->handle)->GetImageSparseMemoryRequirements, in_device, in_image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<ImageInfo>(image, kImageArrayGetImageSparseMemoryRequirements, *pSparseMemoryRequirementCount->GetOutputPointer(), &VulkanObjectInfoTable::GetImageInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceSparseImageFormatProperties", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pProperties->IsNull()) { pProperties->AllocateOutputData(*pPropertyCount->GetOutputPointer()); }

   //  OverrideGetPhysicalDeviceSparseImageFormatProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSparseImageFormatProperties, in_physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties, *pPropertyCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkQueueBindSparse(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
    format::HandleId                            fence)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

    MapStructArrayHandles(pBindInfo->GetMetaStructPointer(), pBindInfo->GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetFenceInfo(fence);

//     VkResult replay_result = OverrideQueueBindSparse(GetDeviceTable(in_queue->handle)->QueueBindSparse, returnValue, in_queue, bindInfoCount, pBindInfo, in_fence);
    // CheckResult("vkQueueBindSparse", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCreateFence(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pFence->IsNull()) { pFence->SetHandleLength(1); }
    FenceInfo handle_info;
    pFence->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateFence(GetDeviceTable(in_device->handle)->CreateFence, returnValue, in_device, pCreateInfo, pAllocator, pFence);
    // CheckResult("vkCreateFence", returnValue, replay_result);

    AddHandle<FenceInfo>(device, pFence->GetPointer(), pFence->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddFenceInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_fence = GetObjectInfoTable().GetFenceInfo(fence);

   //  OverrideDestroyFence(GetDeviceTable(in_device->handle)->DestroyFence, in_device, in_fence, pAllocator);
    RemoveHandle(fence, &VulkanObjectInfoTable::RemoveFenceInfo);
}

void VulkanFrameInspectorConsumer::Process_vkResetFences(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    MapHandles<FenceInfo>(pFences, fenceCount, &VulkanObjectInfoTable::GetFenceInfo);

//     VkResult replay_result = OverrideResetFences(GetDeviceTable(in_device->handle)->ResetFences, returnValue, in_device, fenceCount, pFences);
    // CheckResult("vkResetFences", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_fence = GetObjectInfoTable().GetFenceInfo(fence);

//     VkResult replay_result = OverrideGetFenceStatus(GetDeviceTable(in_device->handle)->GetFenceStatus, returnValue, in_device, in_fence);
    // CheckResult("vkGetFenceStatus", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkWaitForFences(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    MapHandles<FenceInfo>(pFences, fenceCount, &VulkanObjectInfoTable::GetFenceInfo);

//     VkResult replay_result = OverrideWaitForFences(GetDeviceTable(in_device->handle)->WaitForFences, returnValue, in_device, fenceCount, pFences, waitAll, timeout);
    // CheckResult("vkWaitForFences", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCreateSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSemaphore>*          pSemaphore)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pSemaphore->IsNull()) { pSemaphore->SetHandleLength(1); }
    SemaphoreInfo handle_info;
    pSemaphore->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateSemaphore(GetDeviceTable(in_device->handle)->CreateSemaphore, returnValue, in_device, pCreateInfo, pAllocator, pSemaphore);
    // CheckResult("vkCreateSemaphore", returnValue, replay_result);

    AddHandle<SemaphoreInfo>(device, pSemaphore->GetPointer(), pSemaphore->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSemaphoreInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_semaphore = GetObjectInfoTable().GetSemaphoreInfo(semaphore);

   //  OverrideDestroySemaphore(GetDeviceTable(in_device->handle)->DestroySemaphore, in_device, in_semaphore, pAllocator);
    RemoveHandle(semaphore, &VulkanObjectInfoTable::RemoveSemaphoreInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkEvent>*              pEvent)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pEvent->IsNull()) { pEvent->SetHandleLength(1); }
    EventInfo handle_info;
    pEvent->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateEvent(GetDeviceTable(in_device->handle)->CreateEvent, returnValue, in_device, pCreateInfo, pAllocator, pEvent);
    // CheckResult("vkCreateEvent", returnValue, replay_result);

    AddHandle<EventInfo>(device, pEvent->GetPointer(), pEvent->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddEventInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_event = GetObjectInfoTable().GetEventInfo(event);

   //  OverrideDestroyEvent(GetDeviceTable(in_device->handle)->DestroyEvent, in_device, in_event, pAllocator);
    RemoveHandle(event, &VulkanObjectInfoTable::RemoveEventInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_event = GetObjectInfoTable().GetEventInfo(event);

//     VkResult replay_result = OverrideGetEventStatus(GetDeviceTable(in_device->handle)->GetEventStatus, returnValue, in_device, in_event);
    // CheckResult("vkGetEventStatus", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_event = GetObjectInfoTable().GetEventInfo(event);

//     VkResult replay_result = OverrideSetEvent(GetDeviceTable(in_device->handle)->SetEvent, returnValue, in_device, in_event);
    // CheckResult("vkSetEvent", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_event = GetObjectInfoTable().GetEventInfo(event);

//     VkResult replay_result = OverrideResetEvent(GetDeviceTable(in_device->handle)->ResetEvent, returnValue, in_device, in_event);
    // CheckResult("vkResetEvent", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCreateQueryPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkQueryPool>*          pQueryPool)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pQueryPool->IsNull()) { pQueryPool->SetHandleLength(1); }
    QueryPoolInfo handle_info;
    pQueryPool->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateQueryPool(GetDeviceTable(in_device->handle)->CreateQueryPool, returnValue, in_device, pCreateInfo, pAllocator, pQueryPool);
    // CheckResult("vkCreateQueryPool", returnValue, replay_result);

    AddHandle<QueryPoolInfo>(device, pQueryPool->GetPointer(), pQueryPool->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddQueryPoolInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideDestroyQueryPool(GetDeviceTable(in_device->handle)->DestroyQueryPool, in_device, in_queryPool, pAllocator);
    RemoveHandle(queryPool, &VulkanObjectInfoTable::RemoveQueryPoolInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetQueryPoolResults(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);
    if (!pData->IsNull()) { pData->AllocateOutputData(dataSize); }

//     VkResult replay_result = OverrideGetQueryPoolResults(GetDeviceTable(in_device->handle)->GetQueryPoolResults, returnValue, in_device, in_queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    // CheckResult("vkGetQueryPoolResults", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*             pBuffer)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pBuffer->IsNull()) { pBuffer->SetHandleLength(1); }
    BufferInfo handle_info;
    pBuffer->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateBuffer(GetDeviceTable(in_device->handle)->CreateBuffer, returnValue, in_device, pCreateInfo, pAllocator, pBuffer);
    // CheckResult("vkCreateBuffer", returnValue, replay_result);

    AddHandle<BufferInfo>(device, pBuffer->GetPointer(), pBuffer->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddBufferInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);

   //  OverrideDestroyBuffer(GetDeviceTable(in_device->handle)->DestroyBuffer, in_device, in_buffer, pAllocator);
    RemoveHandle(buffer, &VulkanObjectInfoTable::RemoveBufferInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateBufferView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBufferView>*         pView)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pView->IsNull()) { pView->SetHandleLength(1); }
    BufferViewInfo handle_info;
    pView->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateBufferView(GetDeviceTable(in_device->handle)->CreateBufferView, returnValue, in_device, pCreateInfo, pAllocator, pView);
    // CheckResult("vkCreateBufferView", returnValue, replay_result);

    AddHandle<BufferViewInfo>(device, pView->GetPointer(), pView->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddBufferViewInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_bufferView = GetObjectInfoTable().GetBufferViewInfo(bufferView);

   //  OverrideDestroyBufferView(GetDeviceTable(in_device->handle)->DestroyBufferView, in_device, in_bufferView, pAllocator);
    RemoveHandle(bufferView, &VulkanObjectInfoTable::RemoveBufferViewInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateImage(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*              pImage)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pImage->IsNull()) { pImage->SetHandleLength(1); }
    ImageInfo handle_info;
    pImage->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateImage(GetDeviceTable(in_device->handle)->CreateImage, returnValue, in_device, pCreateInfo, pAllocator, pImage);
    // CheckResult("vkCreateImage", returnValue, replay_result);

    AddHandle<ImageInfo>(device, pImage->GetPointer(), pImage->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddImageInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_image = GetObjectInfoTable().GetImageInfo(image);

   //  OverrideDestroyImage(GetDeviceTable(in_device->handle)->DestroyImage, in_device, in_image, pAllocator);
    RemoveHandle(image, &VulkanObjectInfoTable::RemoveImageInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_image = GetObjectInfoTable().GetImageInfo(image);
    pLayout->IsNull() ? nullptr : pLayout->AllocateOutputData(1);

   //  OverrideGetImageSubresourceLayout(GetDeviceTable(in_device->handle)->GetImageSubresourceLayout, in_device, in_image, pSubresource, pLayout);
}

void VulkanFrameInspectorConsumer::Process_vkCreateImageView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImageView>*          pView)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pView->IsNull()) { pView->SetHandleLength(1); }
    ImageViewInfo handle_info;
    pView->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateImageView(GetDeviceTable(in_device->handle)->CreateImageView, returnValue, in_device, pCreateInfo, pAllocator, pView);
    // CheckResult("vkCreateImageView", returnValue, replay_result);

    AddHandle<ImageViewInfo>(device, pView->GetPointer(), pView->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddImageViewInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_imageView = GetObjectInfoTable().GetImageViewInfo(imageView);

   //  OverrideDestroyImageView(GetDeviceTable(in_device->handle)->DestroyImageView, in_device, in_imageView, pAllocator);
    RemoveHandle(imageView, &VulkanObjectInfoTable::RemoveImageViewInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateShaderModule(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderModule>*       pShaderModule)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pShaderModule->IsNull()) { pShaderModule->SetHandleLength(1); }
    ShaderModuleInfo handle_info;
    pShaderModule->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateShaderModule(GetDeviceTable(in_device->handle)->CreateShaderModule, returnValue, in_device, pCreateInfo, pAllocator, pShaderModule);
    // CheckResult("vkCreateShaderModule", returnValue, replay_result);

    AddHandle<ShaderModuleInfo>(device, pShaderModule->GetPointer(), pShaderModule->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddShaderModuleInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_shaderModule = GetObjectInfoTable().GetShaderModuleInfo(shaderModule);

   //  OverrideDestroyShaderModule(GetDeviceTable(in_device->handle)->DestroyShaderModule, in_device, in_shaderModule, pAllocator);
    RemoveHandle(shaderModule, &VulkanObjectInfoTable::RemoveShaderModuleInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreatePipelineCache(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineCache>*      pPipelineCache)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pPipelineCache->IsNull()) { pPipelineCache->SetHandleLength(1); }
    PipelineCacheInfo handle_info;
    pPipelineCache->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreatePipelineCache(GetDeviceTable(in_device->handle)->CreatePipelineCache, returnValue, in_device, pCreateInfo, pAllocator, pPipelineCache);
    // CheckResult("vkCreatePipelineCache", returnValue, replay_result);

    AddHandle<PipelineCacheInfo>(device, pPipelineCache->GetPointer(), pPipelineCache->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddPipelineCacheInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipelineCache = GetObjectInfoTable().GetPipelineCacheInfo(pipelineCache);

   //  OverrideDestroyPipelineCache(GetDeviceTable(in_device->handle)->DestroyPipelineCache, in_device, in_pipelineCache, pAllocator);
    RemoveHandle(pipelineCache, &VulkanObjectInfoTable::RemovePipelineCacheInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPipelineCacheData(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipelineCache = GetObjectInfoTable().GetPipelineCacheInfo(pipelineCache);
    pDataSize->IsNull() ? nullptr : pDataSize->AllocateOutputData(1, GetOutputArrayCount<size_t, PipelineCacheInfo>("vkGetPipelineCacheData", returnValue, pipelineCache, kPipelineCacheArrayGetPipelineCacheData, pDataSize, pData, &VulkanObjectInfoTable::GetPipelineCacheInfo));
    if (!pData->IsNull()) { pData->AllocateOutputData(*pDataSize->GetOutputPointer()); }

//     VkResult replay_result = OverrideGetPipelineCacheData(GetDeviceTable(in_device->handle)->GetPipelineCacheData, returnValue, in_device, in_pipelineCache, pDataSize, pData);
    // CheckResult("vkGetPipelineCacheData", returnValue, replay_result);

    if (pData->IsNull()) { SetOutputArrayCount<PipelineCacheInfo>(pipelineCache, kPipelineCacheArrayGetPipelineCacheData, *pDataSize->GetOutputPointer(), &VulkanObjectInfoTable::GetPipelineCacheInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkMergePipelineCaches(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkPipelineCache>*      pSrcCaches)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_dstCache = GetObjectInfoTable().GetPipelineCacheInfo(dstCache);
    MapHandles<PipelineCacheInfo>(pSrcCaches, srcCacheCount, &VulkanObjectInfoTable::GetPipelineCacheInfo);

//     VkResult replay_result = OverrideMergePipelineCaches(GetDeviceTable(in_device->handle)->MergePipelineCaches, returnValue, in_device, in_dstCache, srcCacheCount, pSrcCaches);
    // CheckResult("vkMergePipelineCaches", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCreateGraphicsPipelines(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipelineCache = GetObjectInfoTable().GetPipelineCacheInfo(pipelineCache);

    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    if (!pPipelines->IsNull()) { pPipelines->SetHandleLength(createInfoCount); }
    std::vector<PipelineInfo> handle_info(createInfoCount);
    for (size_t i = 0; i < createInfoCount; ++i) { pPipelines->SetConsumerData(i, &handle_info[i]); }

//     VkResult replay_result = OverrideCreateGraphicsPipelines(GetDeviceTable(in_device->handle)->CreateGraphicsPipelines, returnValue, in_device, in_pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    // CheckResult("vkCreateGraphicsPipelines", returnValue, replay_result);

    AddHandles<PipelineInfo>(device, pPipelines->GetPointer(), pPipelines->GetLength(), pPipelines->GetHandlePointer(), createInfoCount, std::move(handle_info), &VulkanObjectInfoTable::AddPipelineInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateComputePipelines(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipelineCache = GetObjectInfoTable().GetPipelineCacheInfo(pipelineCache);

    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    if (!pPipelines->IsNull()) { pPipelines->SetHandleLength(createInfoCount); }
    std::vector<PipelineInfo> handle_info(createInfoCount);
    for (size_t i = 0; i < createInfoCount; ++i) { pPipelines->SetConsumerData(i, &handle_info[i]); }

//     VkResult replay_result = OverrideCreateComputePipelines(GetDeviceTable(in_device->handle)->CreateComputePipelines, returnValue, in_device, in_pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    // CheckResult("vkCreateComputePipelines", returnValue, replay_result);

    AddHandles<PipelineInfo>(device, pPipelines->GetPointer(), pPipelines->GetLength(), pPipelines->GetHandlePointer(), createInfoCount, std::move(handle_info), &VulkanObjectInfoTable::AddPipelineInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipeline = GetObjectInfoTable().GetPipelineInfo(pipeline);

   //  OverrideDestroyPipeline(GetDeviceTable(in_device->handle)->DestroyPipeline, in_device, in_pipeline, pAllocator);
    RemoveHandle(pipeline, &VulkanObjectInfoTable::RemovePipelineInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pPipelineLayout->IsNull()) { pPipelineLayout->SetHandleLength(1); }
    PipelineLayoutInfo handle_info;
    pPipelineLayout->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreatePipelineLayout(GetDeviceTable(in_device->handle)->CreatePipelineLayout, returnValue, in_device, pCreateInfo, pAllocator, pPipelineLayout);
    // CheckResult("vkCreatePipelineLayout", returnValue, replay_result);

    AddHandle<PipelineLayoutInfo>(device, pPipelineLayout->GetPointer(), pPipelineLayout->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddPipelineLayoutInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipelineLayout = GetObjectInfoTable().GetPipelineLayoutInfo(pipelineLayout);

   //  OverrideDestroyPipelineLayout(GetDeviceTable(in_device->handle)->DestroyPipelineLayout, in_device, in_pipelineLayout, pAllocator);
    RemoveHandle(pipelineLayout, &VulkanObjectInfoTable::RemovePipelineLayoutInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateSampler(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSampler>*            pSampler)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pSampler->IsNull()) { pSampler->SetHandleLength(1); }
    SamplerInfo handle_info;
    pSampler->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateSampler(GetDeviceTable(in_device->handle)->CreateSampler, returnValue, in_device, pCreateInfo, pAllocator, pSampler);
    // CheckResult("vkCreateSampler", returnValue, replay_result);

    AddHandle<SamplerInfo>(device, pSampler->GetPointer(), pSampler->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSamplerInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_sampler = GetObjectInfoTable().GetSamplerInfo(sampler);

   //  OverrideDestroySampler(GetDeviceTable(in_device->handle)->DestroySampler, in_device, in_sampler, pAllocator);
    RemoveHandle(sampler, &VulkanObjectInfoTable::RemoveSamplerInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pSetLayout->IsNull()) { pSetLayout->SetHandleLength(1); }
    DescriptorSetLayoutInfo handle_info;
    pSetLayout->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateDescriptorSetLayout(GetDeviceTable(in_device->handle)->CreateDescriptorSetLayout, returnValue, in_device, pCreateInfo, pAllocator, pSetLayout);
    // CheckResult("vkCreateDescriptorSetLayout", returnValue, replay_result);

    AddHandle<DescriptorSetLayoutInfo>(device, pSetLayout->GetPointer(), pSetLayout->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDescriptorSetLayoutInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_descriptorSetLayout = GetObjectInfoTable().GetDescriptorSetLayoutInfo(descriptorSetLayout);

   //  OverrideDestroyDescriptorSetLayout(GetDeviceTable(in_device->handle)->DestroyDescriptorSetLayout, in_device, in_descriptorSetLayout, pAllocator);
    RemoveHandle(descriptorSetLayout, &VulkanObjectInfoTable::RemoveDescriptorSetLayoutInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pDescriptorPool->IsNull()) { pDescriptorPool->SetHandleLength(1); }
    DescriptorPoolInfo handle_info;
    pDescriptorPool->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateDescriptorPool(GetDeviceTable(in_device->handle)->CreateDescriptorPool, returnValue, in_device, pCreateInfo, pAllocator, pDescriptorPool);
    // CheckResult("vkCreateDescriptorPool", returnValue, replay_result);

    AddHandle<DescriptorPoolInfo>(device, pDescriptorPool->GetPointer(), pDescriptorPool->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDescriptorPoolInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_descriptorPool = GetObjectInfoTable().GetDescriptorPoolInfo(descriptorPool);

   //  OverrideDestroyDescriptorPool(GetDeviceTable(in_device->handle)->DestroyDescriptorPool, in_device, in_descriptorPool, pAllocator);
    RemovePoolHandle<DescriptorPoolInfo>(descriptorPool, &VulkanObjectInfoTable::GetDescriptorPoolInfo, &VulkanObjectInfoTable::RemoveDescriptorPoolInfo, &VulkanObjectInfoTable::RemoveDescriptorSetInfo);
}

void VulkanFrameInspectorConsumer::Process_vkResetDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_descriptorPool = GetObjectInfoTable().GetDescriptorPoolInfo(descriptorPool);

//     VkResult replay_result = OverrideResetDescriptorPool(GetDeviceTable(in_device->handle)->ResetDescriptorPool, returnValue, in_device, in_descriptorPool, flags);
    // CheckResult("vkResetDescriptorPool", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pAllocateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pDescriptorSets->IsNull()) { pDescriptorSets->SetHandleLength(pAllocateInfo->GetPointer()->descriptorSetCount); }
    std::vector<DescriptorSetInfo> handle_info(pAllocateInfo->GetPointer()->descriptorSetCount);
    for (size_t i = 0; i < pAllocateInfo->GetPointer()->descriptorSetCount; ++i) { pDescriptorSets->SetConsumerData(i, &handle_info[i]); }

//     VkResult replay_result = OverrideAllocateDescriptorSets(GetDeviceTable(in_device->handle)->AllocateDescriptorSets, returnValue, in_device, pAllocateInfo, pDescriptorSets);
    // CheckResult("vkAllocateDescriptorSets", returnValue, replay_result);

    AddPoolHandles<DescriptorPoolInfo, DescriptorSetInfo>(device, handle_mapping::GetPoolId(pAllocateInfo->GetMetaStructPointer()), pDescriptorSets->GetPointer(), pDescriptorSets->GetLength(), pDescriptorSets->GetHandlePointer(), pAllocateInfo->GetPointer()->descriptorSetCount, std::move(handle_info), &VulkanObjectInfoTable::GetDescriptorPoolInfo, &VulkanObjectInfoTable::AddDescriptorSetInfo);
}

void VulkanFrameInspectorConsumer::Process_vkFreeDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_descriptorPool = GetObjectInfoTable().GetDescriptorPoolInfo(descriptorPool);
    MapHandles<DescriptorSetInfo>(pDescriptorSets, descriptorSetCount, &VulkanObjectInfoTable::GetDescriptorSetInfo);

//     VkResult replay_result = OverrideFreeDescriptorSets(GetDeviceTable(in_device->handle)->FreeDescriptorSets, returnValue, in_device, in_descriptorPool, descriptorSetCount, pDescriptorSets);
    // CheckResult("vkFreeDescriptorSets", returnValue, replay_result);
    RemovePoolHandles<DescriptorPoolInfo, DescriptorSetInfo>(descriptorPool, pDescriptorSets, descriptorSetCount, &VulkanObjectInfoTable::GetDescriptorPoolInfo, &VulkanObjectInfoTable::RemoveDescriptorSetInfo);
}

void VulkanFrameInspectorConsumer::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pDescriptorWrites->GetMetaStructPointer(), pDescriptorWrites->GetLength(), GetObjectInfoTable());

    MapStructArrayHandles(pDescriptorCopies->GetMetaStructPointer(), pDescriptorCopies->GetLength(), GetObjectInfoTable());

   //  OverrideUpdateDescriptorSets(GetDeviceTable(in_device->handle)->UpdateDescriptorSets, in_device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

void VulkanFrameInspectorConsumer::Process_vkCreateFramebuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFramebuffer>*        pFramebuffer)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pFramebuffer->IsNull()) { pFramebuffer->SetHandleLength(1); }
    FramebufferInfo handle_info;
    pFramebuffer->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateFramebuffer(GetDeviceTable(in_device->handle)->CreateFramebuffer, returnValue, in_device, pCreateInfo, pAllocator, pFramebuffer);
    // CheckResult("vkCreateFramebuffer", returnValue, replay_result);

    AddHandle<FramebufferInfo>(device, pFramebuffer->GetPointer(), pFramebuffer->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddFramebufferInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_framebuffer = GetObjectInfoTable().GetFramebufferInfo(framebuffer);

   //  OverrideDestroyFramebuffer(GetDeviceTable(in_device->handle)->DestroyFramebuffer, in_device, in_framebuffer, pAllocator);
    RemoveHandle(framebuffer, &VulkanObjectInfoTable::RemoveFramebufferInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateRenderPass(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pRenderPass->IsNull()) { pRenderPass->SetHandleLength(1); }
    RenderPassInfo handle_info;
    pRenderPass->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateRenderPass(GetDeviceTable(in_device->handle)->CreateRenderPass, returnValue, in_device, pCreateInfo, pAllocator, pRenderPass);
    // CheckResult("vkCreateRenderPass", returnValue, replay_result);

    AddHandle<RenderPassInfo>(device, pRenderPass->GetPointer(), pRenderPass->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddRenderPassInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_renderPass = GetObjectInfoTable().GetRenderPassInfo(renderPass);

   //  OverrideDestroyRenderPass(GetDeviceTable(in_device->handle)->DestroyRenderPass, in_device, in_renderPass, pAllocator);
    RemoveHandle(renderPass, &VulkanObjectInfoTable::RemoveRenderPassInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetRenderAreaGranularity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_renderPass = GetObjectInfoTable().GetRenderPassInfo(renderPass);
    pGranularity->IsNull() ? nullptr : pGranularity->AllocateOutputData(1);

   //  OverrideGetRenderAreaGranularity(GetDeviceTable(in_device->handle)->GetRenderAreaGranularity, in_device, in_renderPass, pGranularity);
}

void VulkanFrameInspectorConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkCommandPool>*        pCommandPool)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pCommandPool->IsNull()) { pCommandPool->SetHandleLength(1); }
    CommandPoolInfo handle_info;
    pCommandPool->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateCommandPool(GetDeviceTable(in_device->handle)->CreateCommandPool, returnValue, in_device, pCreateInfo, pAllocator, pCommandPool);
    // CheckResult("vkCreateCommandPool", returnValue, replay_result);

    AddHandle<CommandPoolInfo>(device, pCommandPool->GetPointer(), pCommandPool->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddCommandPoolInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_commandPool = GetObjectInfoTable().GetCommandPoolInfo(commandPool);

   //  OverrideDestroyCommandPool(GetDeviceTable(in_device->handle)->DestroyCommandPool, in_device, in_commandPool, pAllocator);
    RemovePoolHandle<CommandPoolInfo>(commandPool, &VulkanObjectInfoTable::GetCommandPoolInfo, &VulkanObjectInfoTable::RemoveCommandPoolInfo, &VulkanObjectInfoTable::RemoveCommandBufferInfo);
}

void VulkanFrameInspectorConsumer::Process_vkResetCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolResetFlags                     flags)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_commandPool = GetObjectInfoTable().GetCommandPoolInfo(commandPool);

//     VkResult replay_result = OverrideResetCommandPool(GetDeviceTable(in_device->handle)->ResetCommandPool, returnValue, in_device, in_commandPool, flags);
    // CheckResult("vkResetCommandPool", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pAllocateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pCommandBuffers->IsNull()) { pCommandBuffers->SetHandleLength(pAllocateInfo->GetPointer()->commandBufferCount); }
    std::vector<CommandBufferInfo> handle_info(pAllocateInfo->GetPointer()->commandBufferCount);
    for (size_t i = 0; i < pAllocateInfo->GetPointer()->commandBufferCount; ++i) { pCommandBuffers->SetConsumerData(i, &handle_info[i]); }

//     VkResult replay_result = OverrideAllocateCommandBuffers(GetDeviceTable(in_device->handle)->AllocateCommandBuffers, returnValue, in_device, pAllocateInfo, pCommandBuffers);
    // CheckResult("vkAllocateCommandBuffers", returnValue, replay_result);

    AddPoolHandles<CommandPoolInfo, CommandBufferInfo>(device, handle_mapping::GetPoolId(pAllocateInfo->GetMetaStructPointer()), pCommandBuffers->GetPointer(), pCommandBuffers->GetLength(), pCommandBuffers->GetHandlePointer(), pAllocateInfo->GetPointer()->commandBufferCount, std::move(handle_info), &VulkanObjectInfoTable::GetCommandPoolInfo, &VulkanObjectInfoTable::AddCommandBufferInfo);
}

void VulkanFrameInspectorConsumer::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_commandPool = GetObjectInfoTable().GetCommandPoolInfo(commandPool);
    MapHandles<CommandBufferInfo>(pCommandBuffers, commandBufferCount, &VulkanObjectInfoTable::GetCommandBufferInfo);

   //  OverrideFreeCommandBuffers(GetDeviceTable(in_device->handle)->FreeCommandBuffers, in_device, in_commandPool, commandBufferCount, pCommandBuffers);
    RemovePoolHandles<CommandPoolInfo, CommandBufferInfo>(commandPool, pCommandBuffers, commandBufferCount, &VulkanObjectInfoTable::GetCommandPoolInfo, &VulkanObjectInfoTable::RemoveCommandBufferInfo);
}

void VulkanFrameInspectorConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pBeginInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideBeginCommandBuffer(GetDeviceTable(in_commandBuffer->handle)->BeginCommandBuffer, returnValue, in_commandBuffer, pBeginInfo);
    // CheckResult("vkBeginCommandBuffer", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

//     VkResult replay_result = OverrideEndCommandBuffer(GetDeviceTable(in_commandBuffer->handle)->EndCommandBuffer, returnValue, in_commandBuffer);
    // CheckResult("vkEndCommandBuffer", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

//     VkResult replay_result = OverrideResetCommandBuffer(GetDeviceTable(in_commandBuffer->handle)->ResetCommandBuffer, returnValue, in_commandBuffer, flags);
    // CheckResult("vkResetCommandBuffer", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_pipeline = GetObjectInfoTable().GetPipelineInfo(pipeline);

   //  OverrideCmdBindPipeline(GetDeviceTable(in_commandBuffer->handle)->CmdBindPipeline, in_commandBuffer, pipelineBindPoint, in_pipeline);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetViewport(GetDeviceTable(in_commandBuffer->handle)->CmdSetViewport, in_commandBuffer, firstViewport, viewportCount, pViewports);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetScissor(GetDeviceTable(in_commandBuffer->handle)->CmdSetScissor, in_commandBuffer, firstScissor, scissorCount, pScissors);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetLineWidth(GetDeviceTable(in_commandBuffer->handle)->CmdSetLineWidth, in_commandBuffer, lineWidth);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthBias(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthBias, in_commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetBlendConstants(GetDeviceTable(in_commandBuffer->handle)->CmdSetBlendConstants, in_commandBuffer, blendConstants);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthBounds(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthBounds, in_commandBuffer, minDepthBounds, maxDepthBounds);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetStencilCompareMask(GetDeviceTable(in_commandBuffer->handle)->CmdSetStencilCompareMask, in_commandBuffer, faceMask, compareMask);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetStencilWriteMask(GetDeviceTable(in_commandBuffer->handle)->CmdSetStencilWriteMask, in_commandBuffer, faceMask, writeMask);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetStencilReference(GetDeviceTable(in_commandBuffer->handle)->CmdSetStencilReference, in_commandBuffer, faceMask, reference);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    PointerDecoder<uint32_t>*                   pDynamicOffsets)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_layout = GetObjectInfoTable().GetPipelineLayoutInfo(layout);
    MapHandles<DescriptorSetInfo>(pDescriptorSets, descriptorSetCount, &VulkanObjectInfoTable::GetDescriptorSetInfo);

   //  OverrideCmdBindDescriptorSets(GetDeviceTable(in_commandBuffer->handle)->CmdBindDescriptorSets, in_commandBuffer, pipelineBindPoint, in_layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);

   //  OverrideCmdBindIndexBuffer(GetDeviceTable(in_commandBuffer->handle)->CmdBindIndexBuffer, in_commandBuffer, in_buffer, offset, indexType);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    MapHandles<BufferInfo>(pBuffers, bindingCount, &VulkanObjectInfoTable::GetBufferInfo);

   //  OverrideCmdBindVertexBuffers(GetDeviceTable(in_commandBuffer->handle)->CmdBindVertexBuffers, in_commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdDraw(GetDeviceTable(in_commandBuffer->handle)->CmdDraw, in_commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdDrawIndexed(GetDeviceTable(in_commandBuffer->handle)->CmdDrawIndexed, in_commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);

   //  OverrideCmdDrawIndirect(GetDeviceTable(in_commandBuffer->handle)->CmdDrawIndirect, in_commandBuffer, in_buffer, offset, drawCount, stride);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);

   //  OverrideCmdDrawIndexedIndirect(GetDeviceTable(in_commandBuffer->handle)->CmdDrawIndexedIndirect, in_commandBuffer, in_buffer, offset, drawCount, stride);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdDispatch(GetDeviceTable(in_commandBuffer->handle)->CmdDispatch, in_commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);

   //  OverrideCmdDispatchIndirect(GetDeviceTable(in_commandBuffer->handle)->CmdDispatchIndirect, in_commandBuffer, in_buffer, offset);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_srcBuffer = GetObjectInfoTable().GetBufferInfo(srcBuffer);
    auto in_dstBuffer = GetObjectInfoTable().GetBufferInfo(dstBuffer);

   //  OverrideCmdCopyBuffer(GetDeviceTable(in_commandBuffer->handle)->CmdCopyBuffer, in_commandBuffer, in_srcBuffer, in_dstBuffer, regionCount, pRegions);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageCopy>*  pRegions)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_srcImage = GetObjectInfoTable().GetImageInfo(srcImage);
    auto in_dstImage = GetObjectInfoTable().GetImageInfo(dstImage);

   //  OverrideCmdCopyImage(GetDeviceTable(in_commandBuffer->handle)->CmdCopyImage, in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, pRegions);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageBlit>*  pRegions,
    VkFilter                                    filter)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_srcImage = GetObjectInfoTable().GetImageInfo(srcImage);
    auto in_dstImage = GetObjectInfoTable().GetImageInfo(dstImage);

   //  OverrideCmdBlitImage(GetDeviceTable(in_commandBuffer->handle)->CmdBlitImage, in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, pRegions, filter);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_srcBuffer = GetObjectInfoTable().GetBufferInfo(srcBuffer);
    auto in_dstImage = GetObjectInfoTable().GetImageInfo(dstImage);

   //  OverrideCmdCopyBufferToImage(GetDeviceTable(in_commandBuffer->handle)->CmdCopyBufferToImage, in_commandBuffer, in_srcBuffer, in_dstImage, dstImageLayout, regionCount, pRegions);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_srcImage = GetObjectInfoTable().GetImageInfo(srcImage);
    auto in_dstBuffer = GetObjectInfoTable().GetBufferInfo(dstBuffer);

   //  OverrideCmdCopyImageToBuffer(GetDeviceTable(in_commandBuffer->handle)->CmdCopyImageToBuffer, in_commandBuffer, in_srcImage, srcImageLayout, in_dstBuffer, regionCount, pRegions);
}

void VulkanFrameInspectorConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_dstBuffer = GetObjectInfoTable().GetBufferInfo(dstBuffer);

   //  OverrideCmdUpdateBuffer(GetDeviceTable(in_commandBuffer->handle)->CmdUpdateBuffer, in_commandBuffer, in_dstBuffer, dstOffset, dataSize, pData);
}

void VulkanFrameInspectorConsumer::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_dstBuffer = GetObjectInfoTable().GetBufferInfo(dstBuffer);

   //  OverrideCmdFillBuffer(GetDeviceTable(in_commandBuffer->handle)->CmdFillBuffer, in_commandBuffer, in_dstBuffer, dstOffset, size, data);
}

void VulkanFrameInspectorConsumer::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_image = GetObjectInfoTable().GetImageInfo(image);

   //  OverrideCmdClearColorImage(GetDeviceTable(in_commandBuffer->handle)->CmdClearColorImage, in_commandBuffer, in_image, imageLayout, pColor, rangeCount, pRanges);
}

void VulkanFrameInspectorConsumer::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_image = GetObjectInfoTable().GetImageInfo(image);

   //  OverrideCmdClearDepthStencilImage(GetDeviceTable(in_commandBuffer->handle)->CmdClearDepthStencilImage, in_commandBuffer, in_image, imageLayout, pDepthStencil, rangeCount, pRanges);
}

void VulkanFrameInspectorConsumer::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
    uint32_t                                    rectCount,
    StructPointerDecoder<Decoded_VkClearRect>*  pRects)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdClearAttachments(GetDeviceTable(in_commandBuffer->handle)->CmdClearAttachments, in_commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

void VulkanFrameInspectorConsumer::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageResolve>* pRegions)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_srcImage = GetObjectInfoTable().GetImageInfo(srcImage);
    auto in_dstImage = GetObjectInfoTable().GetImageInfo(dstImage);

   //  OverrideCmdResolveImage(GetDeviceTable(in_commandBuffer->handle)->CmdResolveImage, in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, pRegions);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_event = GetObjectInfoTable().GetEventInfo(event);

   //  OverrideCmdSetEvent(GetDeviceTable(in_commandBuffer->handle)->CmdSetEvent, in_commandBuffer, in_event, stageMask);
}

void VulkanFrameInspectorConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_event = GetObjectInfoTable().GetEventInfo(event);

   //  OverrideCmdResetEvent(GetDeviceTable(in_commandBuffer->handle)->CmdResetEvent, in_commandBuffer, in_event, stageMask);
}

void VulkanFrameInspectorConsumer::Process_vkCmdWaitEvents(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    MapHandles<EventInfo>(pEvents, eventCount, &VulkanObjectInfoTable::GetEventInfo);

    MapStructArrayHandles(pBufferMemoryBarriers->GetMetaStructPointer(), pBufferMemoryBarriers->GetLength(), GetObjectInfoTable());

    MapStructArrayHandles(pImageMemoryBarriers->GetMetaStructPointer(), pImageMemoryBarriers->GetLength(), GetObjectInfoTable());

   //  OverrideCmdWaitEvents(GetDeviceTable(in_commandBuffer->handle)->CmdWaitEvents, in_commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

void VulkanFrameInspectorConsumer::Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructArrayHandles(pBufferMemoryBarriers->GetMetaStructPointer(), pBufferMemoryBarriers->GetLength(), GetObjectInfoTable());

    MapStructArrayHandles(pImageMemoryBarriers->GetMetaStructPointer(), pImageMemoryBarriers->GetLength(), GetObjectInfoTable());

   //  OverrideCmdPipelineBarrier(GetDeviceTable(in_commandBuffer->handle)->CmdPipelineBarrier, in_commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideCmdBeginQuery(GetDeviceTable(in_commandBuffer->handle)->CmdBeginQuery, in_commandBuffer, in_queryPool, query, flags);
}

void VulkanFrameInspectorConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideCmdEndQuery(GetDeviceTable(in_commandBuffer->handle)->CmdEndQuery, in_commandBuffer, in_queryPool, query);
}

void VulkanFrameInspectorConsumer::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideCmdResetQueryPool(GetDeviceTable(in_commandBuffer->handle)->CmdResetQueryPool, in_commandBuffer, in_queryPool, firstQuery, queryCount);
}

void VulkanFrameInspectorConsumer::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideCmdWriteTimestamp(GetDeviceTable(in_commandBuffer->handle)->CmdWriteTimestamp, in_commandBuffer, pipelineStage, in_queryPool, query);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyQueryPoolResults(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);
    auto in_dstBuffer = GetObjectInfoTable().GetBufferInfo(dstBuffer);

   //  OverrideCmdCopyQueryPoolResults(GetDeviceTable(in_commandBuffer->handle)->CmdCopyQueryPoolResults, in_commandBuffer, in_queryPool, firstQuery, queryCount, in_dstBuffer, dstOffset, stride, flags);
}

void VulkanFrameInspectorConsumer::Process_vkCmdPushConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    PointerDecoder<uint8_t>*                    pValues)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_layout = GetObjectInfoTable().GetPipelineLayoutInfo(layout);

   //  OverrideCmdPushConstants(GetDeviceTable(in_commandBuffer->handle)->CmdPushConstants, in_commandBuffer, in_layout, stageFlags, offset, size, pValues);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pRenderPassBegin->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdBeginRenderPass(GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderPass, in_commandBuffer, pRenderPassBegin, contents);
}

void VulkanFrameInspectorConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdNextSubpass(GetDeviceTable(in_commandBuffer->handle)->CmdNextSubpass, in_commandBuffer, contents);
}

void VulkanFrameInspectorConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdEndRenderPass(GetDeviceTable(in_commandBuffer->handle)->CmdEndRenderPass, in_commandBuffer);
}

void VulkanFrameInspectorConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    MapHandles<CommandBufferInfo>(pCommandBuffers, commandBufferCount, &VulkanObjectInfoTable::GetCommandBufferInfo);

   //  OverrideCmdExecuteCommands(GetDeviceTable(in_commandBuffer->handle)->CmdExecuteCommands, in_commandBuffer, commandBufferCount, pCommandBuffers);
}

void VulkanFrameInspectorConsumer::Process_vkBindBufferMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

//     VkResult replay_result = OverrideBindBufferMemory2(GetDeviceTable(in_device->handle)->BindBufferMemory2, returnValue, in_device, bindInfoCount, pBindInfos);
    // CheckResult("vkBindBufferMemory2", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

//     VkResult replay_result = OverrideBindImageMemory2(GetDeviceTable(in_device->handle)->BindImageMemory2, returnValue, in_device, bindInfoCount, pBindInfos);
    // CheckResult("vkBindImageMemory2", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    pPeerMemoryFeatures->IsNull() ? nullptr : pPeerMemoryFeatures->AllocateOutputData(1, static_cast<VkPeerMemoryFeatureFlags>(0));

   //  OverrideGetDeviceGroupPeerMemoryFeatures(GetDeviceTable(in_device->handle)->GetDeviceGroupPeerMemoryFeatures, in_device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDeviceMask(GetDeviceTable(in_commandBuffer->handle)->CmdSetDeviceMask, in_commandBuffer, deviceMask);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdDispatchBase(GetDeviceTable(in_commandBuffer->handle)->CmdDispatchBase, in_commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void VulkanFrameInspectorConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    pPhysicalDeviceGroupCount->IsNull() ? nullptr : pPhysicalDeviceGroupCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, InstanceInfo>("vkEnumeratePhysicalDeviceGroups", returnValue, instance, kInstanceArrayEnumeratePhysicalDeviceGroups, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties, &VulkanObjectInfoTable::GetInstanceInfo));
    SetStructArrayHandleLengths<Decoded_VkPhysicalDeviceGroupProperties>(pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength());
    if (!pPhysicalDeviceGroupProperties->IsNull()) { pPhysicalDeviceGroupProperties->AllocateOutputData(*pPhysicalDeviceGroupCount->GetOutputPointer(), VkPhysicalDeviceGroupProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES, nullptr }); }

//     VkResult replay_result = OverrideEnumeratePhysicalDeviceGroups(GetInstanceTable(in_instance->handle)->EnumeratePhysicalDeviceGroups, returnValue, in_instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    // CheckResult("vkEnumeratePhysicalDeviceGroups", returnValue, replay_result);

    if (pPhysicalDeviceGroupProperties->IsNull()) { SetOutputArrayCount<InstanceInfo>(instance, kInstanceArrayEnumeratePhysicalDeviceGroups, *pPhysicalDeviceGroupCount->GetOutputPointer(), &VulkanObjectInfoTable::GetInstanceInfo); }
    AddStructArrayHandles<Decoded_VkPhysicalDeviceGroupProperties>(instance, pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength(), pPhysicalDeviceGroupProperties->GetOutputPointer(), *pPhysicalDeviceGroupCount->GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanFrameInspectorConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

   //  OverrideGetImageMemoryRequirements2(GetDeviceTable(in_device->handle)->GetImageMemoryRequirements2, in_device, pInfo, pMemoryRequirements);
}

void VulkanFrameInspectorConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

   //  OverrideGetBufferMemoryRequirements2(GetDeviceTable(in_device->handle)->GetBufferMemoryRequirements2, in_device, pInfo, pMemoryRequirements);
}

void VulkanFrameInspectorConsumer::Process_vkGetImageSparseMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetImageSparseMemoryRequirements2", VK_SUCCESS, device, kDeviceArrayGetImageSparseMemoryRequirements2, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &VulkanObjectInfoTable::GetDeviceInfo));
    if (!pSparseMemoryRequirements->IsNull()) { pSparseMemoryRequirements->AllocateOutputData(*pSparseMemoryRequirementCount->GetOutputPointer(), VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr }); }

   //  OverrideGetImageSparseMemoryRequirements2(GetDeviceTable(in_device->handle)->GetImageSparseMemoryRequirements2, in_device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetImageSparseMemoryRequirements2, *pSparseMemoryRequirementCount->GetOutputPointer(), &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pFeatures->IsNull() ? nullptr : pFeatures->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, nullptr });

   //  OverrideGetPhysicalDeviceFeatures2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceFeatures2, in_physicalDevice, pFeatures);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, nullptr });

   //  OverrideGetPhysicalDeviceProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceProperties2, in_physicalDevice, pProperties);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pFormatProperties->IsNull() ? nullptr : pFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2, nullptr });

   //  OverrideGetPhysicalDeviceFormatProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceFormatProperties2, in_physicalDevice, format, pFormatProperties);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pImageFormatProperties->IsNull() ? nullptr : pImageFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

//     VkResult replay_result = OverrideGetPhysicalDeviceImageFormatProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceImageFormatProperties2, returnValue, in_physicalDevice, pImageFormatInfo, pImageFormatProperties);
    // CheckResult("vkGetPhysicalDeviceImageFormatProperties2", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pQueueFamilyPropertyCount->IsNull() ? nullptr : pQueueFamilyPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyProperties2", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2, pQueueFamilyPropertyCount, pQueueFamilyProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pQueueFamilyProperties->IsNull()) { pQueueFamilyProperties->AllocateOutputData(*pQueueFamilyPropertyCount->GetOutputPointer(), VkQueueFamilyProperties2{ VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2, nullptr }); }

   //  OverrideGetPhysicalDeviceQueueFamilyProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceQueueFamilyProperties2, in_physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    if (pQueueFamilyProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2, *pQueueFamilyPropertyCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pMemoryProperties->IsNull() ? nullptr : pMemoryProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2, nullptr });

   //  OverrideGetPhysicalDeviceMemoryProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceMemoryProperties2, in_physicalDevice, pMemoryProperties);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceSparseImageFormatProperties2", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pProperties->IsNull()) { pProperties->AllocateOutputData(*pPropertyCount->GetOutputPointer(), VkSparseImageFormatProperties2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2, nullptr }); }

   //  OverrideGetPhysicalDeviceSparseImageFormatProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSparseImageFormatProperties2, in_physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2, *pPropertyCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_commandPool = GetObjectInfoTable().GetCommandPoolInfo(commandPool);

   //  OverrideTrimCommandPool(GetDeviceTable(in_device->handle)->TrimCommandPool, in_device, in_commandPool, flags);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceQueue2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pQueue->IsNull()) { pQueue->SetHandleLength(1); }
    QueueInfo handle_info;
    pQueue->SetConsumerData(0, &handle_info);

   //  OverrideGetDeviceQueue2(GetDeviceTable(in_device->handle)->GetDeviceQueue2, in_device, pQueueInfo, pQueue);

    AddHandle<QueueInfo>(device, pQueue->GetPointer(), pQueue->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddQueueInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateSamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pYcbcrConversion->IsNull()) { pYcbcrConversion->SetHandleLength(1); }
    SamplerYcbcrConversionInfo handle_info;
    pYcbcrConversion->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateSamplerYcbcrConversion(GetDeviceTable(in_device->handle)->CreateSamplerYcbcrConversion, returnValue, in_device, pCreateInfo, pAllocator, pYcbcrConversion);
    // CheckResult("vkCreateSamplerYcbcrConversion", returnValue, replay_result);

    AddHandle<SamplerYcbcrConversionInfo>(device, pYcbcrConversion->GetPointer(), pYcbcrConversion->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSamplerYcbcrConversionInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_ycbcrConversion = GetObjectInfoTable().GetSamplerYcbcrConversionInfo(ycbcrConversion);

   //  OverrideDestroySamplerYcbcrConversion(GetDeviceTable(in_device->handle)->DestroySamplerYcbcrConversion, in_device, in_ycbcrConversion, pAllocator);
    RemoveHandle(ycbcrConversion, &VulkanObjectInfoTable::RemoveSamplerYcbcrConversionInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pDescriptorUpdateTemplate->IsNull()) { pDescriptorUpdateTemplate->SetHandleLength(1); }
    DescriptorUpdateTemplateInfo handle_info;
    pDescriptorUpdateTemplate->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->CreateDescriptorUpdateTemplate, returnValue, in_device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    // CheckResult("vkCreateDescriptorUpdateTemplate", returnValue, replay_result);

    AddHandle<DescriptorUpdateTemplateInfo>(device, pDescriptorUpdateTemplate->GetPointer(), pDescriptorUpdateTemplate->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDescriptorUpdateTemplateInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_descriptorUpdateTemplate = GetObjectInfoTable().GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

   //  OverrideDestroyDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->DestroyDescriptorUpdateTemplate, in_device, in_descriptorUpdateTemplate, pAllocator);
    RemoveHandle(descriptorUpdateTemplate, &VulkanObjectInfoTable::RemoveDescriptorUpdateTemplateInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pExternalBufferProperties->IsNull() ? nullptr : pExternalBufferProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES, nullptr });

   //  OverrideGetPhysicalDeviceExternalBufferProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceExternalBufferProperties, in_physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pExternalFenceProperties->IsNull() ? nullptr : pExternalFenceProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES, nullptr });

   //  OverrideGetPhysicalDeviceExternalFenceProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceExternalFenceProperties, in_physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pExternalSemaphoreProperties->IsNull() ? nullptr : pExternalSemaphoreProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES, nullptr });

   //  OverrideGetPhysicalDeviceExternalSemaphoreProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceExternalSemaphoreProperties, in_physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

void VulkanFrameInspectorConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pSupport->IsNull() ? nullptr : pSupport->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT, nullptr });

   //  OverrideGetDescriptorSetLayoutSupport(GetDeviceTable(in_device->handle)->GetDescriptorSetLayoutSupport, in_device, pCreateInfo, pSupport);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);
    auto in_countBuffer = GetObjectInfoTable().GetBufferInfo(countBuffer);

   //  OverrideCmdDrawIndirectCount(GetDeviceTable(in_commandBuffer->handle)->CmdDrawIndirectCount, in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);
    auto in_countBuffer = GetObjectInfoTable().GetBufferInfo(countBuffer);

   //  OverrideCmdDrawIndexedIndirectCount(GetDeviceTable(in_commandBuffer->handle)->CmdDrawIndexedIndirectCount, in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanFrameInspectorConsumer::Process_vkCreateRenderPass2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pRenderPass->IsNull()) { pRenderPass->SetHandleLength(1); }
    RenderPassInfo handle_info;
    pRenderPass->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateRenderPass2(GetDeviceTable(in_device->handle)->CreateRenderPass2, returnValue, in_device, pCreateInfo, pAllocator, pRenderPass);
    // CheckResult("vkCreateRenderPass2", returnValue, replay_result);

    AddHandle<RenderPassInfo>(device, pRenderPass->GetPointer(), pRenderPass->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddRenderPassInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pRenderPassBegin->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdBeginRenderPass2(GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderPass2, in_commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdNextSubpass2(GetDeviceTable(in_commandBuffer->handle)->CmdNextSubpass2, in_commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdEndRenderPass2(GetDeviceTable(in_commandBuffer->handle)->CmdEndRenderPass2, in_commandBuffer, pSubpassEndInfo);
}

void VulkanFrameInspectorConsumer::Process_vkResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideResetQueryPool(GetDeviceTable(in_device->handle)->ResetQueryPool, in_device, in_queryPool, firstQuery, queryCount);
}

void VulkanFrameInspectorConsumer::Process_vkGetSemaphoreCounterValue(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_semaphore = GetObjectInfoTable().GetSemaphoreInfo(semaphore);
    pValue->IsNull() ? nullptr : pValue->AllocateOutputData(1, static_cast<uint64_t>(0));

//     VkResult replay_result = OverrideGetSemaphoreCounterValue(GetDeviceTable(in_device->handle)->GetSemaphoreCounterValue, returnValue, in_device, in_semaphore, pValue);
    // CheckResult("vkGetSemaphoreCounterValue", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkWaitSemaphores(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pWaitInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideWaitSemaphores(GetDeviceTable(in_device->handle)->WaitSemaphores, returnValue, in_device, pWaitInfo, timeout);
    // CheckResult("vkWaitSemaphores", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pSignalInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideSignalSemaphore(GetDeviceTable(in_device->handle)->SignalSemaphore, returnValue, in_device, pSignalInfo);
    // CheckResult("vkSignalSemaphore", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideGetBufferDeviceAddress(GetDeviceTable(in_device->handle)->GetBufferDeviceAddress, in_device, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideGetBufferOpaqueCaptureAddress(GetDeviceTable(in_device->handle)->GetBufferOpaqueCaptureAddress, in_device, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideGetDeviceMemoryOpaqueCaptureAddress(GetDeviceTable(in_device->handle)->GetDeviceMemoryOpaqueCaptureAddress, in_device, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceToolProperties(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pToolCount->IsNull() ? nullptr : pToolCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceToolProperties", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolProperties, pToolCount, pToolProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pToolProperties->IsNull()) { pToolProperties->AllocateOutputData(*pToolCount->GetOutputPointer(), VkPhysicalDeviceToolProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES, nullptr }); }

//     VkResult replay_result = OverrideGetPhysicalDeviceToolProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceToolProperties, returnValue, in_physicalDevice, pToolCount, pToolProperties);
    // CheckResult("vkGetPhysicalDeviceToolProperties", returnValue, replay_result);

    if (pToolProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolProperties, *pToolCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pPrivateDataSlot->IsNull()) { pPrivateDataSlot->SetHandleLength(1); }
    PrivateDataSlotInfo handle_info;
    pPrivateDataSlot->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreatePrivateDataSlot(GetDeviceTable(in_device->handle)->CreatePrivateDataSlot, returnValue, in_device, pCreateInfo, pAllocator, pPrivateDataSlot);
    // CheckResult("vkCreatePrivateDataSlot", returnValue, replay_result);

    AddHandle<PrivateDataSlotInfo>(device, pPrivateDataSlot->GetPointer(), pPrivateDataSlot->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddPrivateDataSlotInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_privateDataSlot = GetObjectInfoTable().GetPrivateDataSlotInfo(privateDataSlot);

   //  OverrideDestroyPrivateDataSlot(GetDeviceTable(in_device->handle)->DestroyPrivateDataSlot, in_device, in_privateDataSlot, pAllocator);
    RemoveHandle(privateDataSlot, &VulkanObjectInfoTable::RemovePrivateDataSlotInfo);
}

void VulkanFrameInspectorConsumer::Process_vkSetPrivateData(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    uint64_t in_objectHandle = MapHandle(objectHandle, objectType);
    auto in_privateDataSlot = GetObjectInfoTable().GetPrivateDataSlotInfo(privateDataSlot);

//     VkResult replay_result = OverrideSetPrivateData(GetDeviceTable(in_device->handle)->SetPrivateData, returnValue, in_device, objectType, in_objectHandle, in_privateDataSlot, data);
    // CheckResult("vkSetPrivateData", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    uint64_t in_objectHandle = MapHandle(objectHandle, objectType);
    auto in_privateDataSlot = GetObjectInfoTable().GetPrivateDataSlotInfo(privateDataSlot);
    pData->IsNull() ? nullptr : pData->AllocateOutputData(1, static_cast<uint64_t>(0));

   //  OverrideGetPrivateData(GetDeviceTable(in_device->handle)->GetPrivateData, in_device, objectType, in_objectHandle, in_privateDataSlot, pData);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_event = GetObjectInfoTable().GetEventInfo(event);

    MapStructHandles(pDependencyInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdSetEvent2(GetDeviceTable(in_commandBuffer->handle)->CmdSetEvent2, in_commandBuffer, in_event, pDependencyInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_event = GetObjectInfoTable().GetEventInfo(event);

   //  OverrideCmdResetEvent2(GetDeviceTable(in_commandBuffer->handle)->CmdResetEvent2, in_commandBuffer, in_event, stageMask);
}

void VulkanFrameInspectorConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    MapHandles<EventInfo>(pEvents, eventCount, &VulkanObjectInfoTable::GetEventInfo);

    MapStructArrayHandles(pDependencyInfos->GetMetaStructPointer(), pDependencyInfos->GetLength(), GetObjectInfoTable());

   //  OverrideCmdWaitEvents2(GetDeviceTable(in_commandBuffer->handle)->CmdWaitEvents2, in_commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void VulkanFrameInspectorConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pDependencyInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdPipelineBarrier2(GetDeviceTable(in_commandBuffer->handle)->CmdPipelineBarrier2, in_commandBuffer, pDependencyInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideCmdWriteTimestamp2(GetDeviceTable(in_commandBuffer->handle)->CmdWriteTimestamp2, in_commandBuffer, stage, in_queryPool, query);
}

void VulkanFrameInspectorConsumer::Process_vkQueueSubmit2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

    MapStructArrayHandles(pSubmits->GetMetaStructPointer(), pSubmits->GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetFenceInfo(fence);

//     VkResult replay_result = OverrideQueueSubmit2(GetDeviceTable(in_queue->handle)->QueueSubmit2, returnValue, in_queue, submitCount, pSubmits, in_fence);
    // CheckResult("vkQueueSubmit2", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pCopyBufferInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyBuffer2(GetDeviceTable(in_commandBuffer->handle)->CmdCopyBuffer2, in_commandBuffer, pCopyBufferInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pCopyImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyImage2(GetDeviceTable(in_commandBuffer->handle)->CmdCopyImage2, in_commandBuffer, pCopyImageInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pCopyBufferToImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyBufferToImage2(GetDeviceTable(in_commandBuffer->handle)->CmdCopyBufferToImage2, in_commandBuffer, pCopyBufferToImageInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pCopyImageToBufferInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyImageToBuffer2(GetDeviceTable(in_commandBuffer->handle)->CmdCopyImageToBuffer2, in_commandBuffer, pCopyImageToBufferInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pBlitImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdBlitImage2(GetDeviceTable(in_commandBuffer->handle)->CmdBlitImage2, in_commandBuffer, pBlitImageInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pResolveImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdResolveImage2(GetDeviceTable(in_commandBuffer->handle)->CmdResolveImage2, in_commandBuffer, pResolveImageInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pRenderingInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdBeginRendering(GetDeviceTable(in_commandBuffer->handle)->CmdBeginRendering, in_commandBuffer, pRenderingInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdEndRendering(GetDeviceTable(in_commandBuffer->handle)->CmdEndRendering, in_commandBuffer);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetCullMode(GetDeviceTable(in_commandBuffer->handle)->CmdSetCullMode, in_commandBuffer, cullMode);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetFrontFace(GetDeviceTable(in_commandBuffer->handle)->CmdSetFrontFace, in_commandBuffer, frontFace);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetPrimitiveTopology(GetDeviceTable(in_commandBuffer->handle)->CmdSetPrimitiveTopology, in_commandBuffer, primitiveTopology);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetViewportWithCount(GetDeviceTable(in_commandBuffer->handle)->CmdSetViewportWithCount, in_commandBuffer, viewportCount, pViewports);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetScissorWithCount(GetDeviceTable(in_commandBuffer->handle)->CmdSetScissorWithCount, in_commandBuffer, scissorCount, pScissors);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    MapHandles<BufferInfo>(pBuffers, bindingCount, &VulkanObjectInfoTable::GetBufferInfo);

   //  OverrideCmdBindVertexBuffers2(GetDeviceTable(in_commandBuffer->handle)->CmdBindVertexBuffers2, in_commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthTestEnable(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthTestEnable, in_commandBuffer, depthTestEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthWriteEnable(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthWriteEnable, in_commandBuffer, depthWriteEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthCompareOp(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthCompareOp, in_commandBuffer, depthCompareOp);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthBoundsTestEnable(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthBoundsTestEnable, in_commandBuffer, depthBoundsTestEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetStencilTestEnable(GetDeviceTable(in_commandBuffer->handle)->CmdSetStencilTestEnable, in_commandBuffer, stencilTestEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetStencilOp(GetDeviceTable(in_commandBuffer->handle)->CmdSetStencilOp, in_commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetRasterizerDiscardEnable(GetDeviceTable(in_commandBuffer->handle)->CmdSetRasterizerDiscardEnable, in_commandBuffer, rasterizerDiscardEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthBiasEnable(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthBiasEnable, in_commandBuffer, depthBiasEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetPrimitiveRestartEnable(GetDeviceTable(in_commandBuffer->handle)->CmdSetPrimitiveRestartEnable, in_commandBuffer, primitiveRestartEnable);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

   //  OverrideGetDeviceBufferMemoryRequirements(GetDeviceTable(in_device->handle)->GetDeviceBufferMemoryRequirements, in_device, pInfo, pMemoryRequirements);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

   //  OverrideGetDeviceImageMemoryRequirements(GetDeviceTable(in_device->handle)->GetDeviceImageMemoryRequirements, in_device, pInfo, pMemoryRequirements);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetDeviceImageSparseMemoryRequirements", VK_SUCCESS, device, kDeviceArrayGetDeviceImageSparseMemoryRequirements, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &VulkanObjectInfoTable::GetDeviceInfo));
    if (!pSparseMemoryRequirements->IsNull()) { pSparseMemoryRequirements->AllocateOutputData(*pSparseMemoryRequirementCount->GetOutputPointer(), VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr }); }

   //  OverrideGetDeviceImageSparseMemoryRequirements(GetDeviceTable(in_device->handle)->GetDeviceImageSparseMemoryRequirements, in_device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetDeviceImageSparseMemoryRequirements, *pSparseMemoryRequirementCount->GetOutputPointer(), &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    auto in_surface = GetObjectInfoTable().GetSurfaceKHRInfo(surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }

   //  OverrideDestroySurfaceKHR(GetInstanceTable(in_instance->handle)->DestroySurfaceKHR, in_instance, in_surface, pAllocator);
    RemoveHandle(surface, &VulkanObjectInfoTable::RemoveSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    format::HandleId                            surface,
    PointerDecoder<VkBool32>*                   pSupported)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_surface = GetObjectInfoTable().GetSurfaceKHRInfo(surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }
    pSupported->IsNull() ? nullptr : pSupported->AllocateOutputData(1, static_cast<VkBool32>(0));

//     VkResult replay_result = OverrideGetPhysicalDeviceSurfaceSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceSupportKHR, returnValue, in_physicalDevice, queueFamilyIndex, in_surface, pSupported);
    // CheckResult("vkGetPhysicalDeviceSurfaceSupportKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_surface = GetObjectInfoTable().GetSurfaceKHRInfo(surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }
    pSurfaceCapabilities->IsNull() ? nullptr : pSurfaceCapabilities->AllocateOutputData(1);

//     VkResult replay_result = OverrideGetPhysicalDeviceSurfaceCapabilitiesKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceCapabilitiesKHR, returnValue, in_physicalDevice, in_surface, pSurfaceCapabilities);
    // CheckResult("vkGetPhysicalDeviceSurfaceCapabilitiesKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_surface = GetObjectInfoTable().GetSurfaceKHRInfo(surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }
    pSurfaceFormatCount->IsNull() ? nullptr : pSurfaceFormatCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, SurfaceKHRInfo>("vkGetPhysicalDeviceSurfaceFormatsKHR", returnValue, surface, kSurfaceKHRArrayGetPhysicalDeviceSurfaceFormatsKHR, pSurfaceFormatCount, pSurfaceFormats, &VulkanObjectInfoTable::GetSurfaceKHRInfo));
    if (!pSurfaceFormats->IsNull()) { pSurfaceFormats->AllocateOutputData(*pSurfaceFormatCount->GetOutputPointer()); }

//     VkResult replay_result = OverrideGetPhysicalDeviceSurfaceFormatsKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceFormatsKHR, returnValue, in_physicalDevice, in_surface, pSurfaceFormatCount, pSurfaceFormats);
    // CheckResult("vkGetPhysicalDeviceSurfaceFormatsKHR", returnValue, replay_result);

    if (pSurfaceFormats->IsNull()) { SetOutputArrayCount<SurfaceKHRInfo>(surface, kSurfaceKHRArrayGetPhysicalDeviceSurfaceFormatsKHR, *pSurfaceFormatCount->GetOutputPointer(), &VulkanObjectInfoTable::GetSurfaceKHRInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_surface = GetObjectInfoTable().GetSurfaceKHRInfo(surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }
    pPresentModeCount->IsNull() ? nullptr : pPresentModeCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, SurfaceKHRInfo>("vkGetPhysicalDeviceSurfacePresentModesKHR", returnValue, surface, kSurfaceKHRArrayGetPhysicalDeviceSurfacePresentModesKHR, pPresentModeCount, pPresentModes, &VulkanObjectInfoTable::GetSurfaceKHRInfo));
    if (pPresentModes->IsNull()) { pPresentModes->AllocateOutputData(*pPresentModeCount->GetOutputPointer()); }

//     VkResult replay_result = OverrideGetPhysicalDeviceSurfacePresentModesKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfacePresentModesKHR, returnValue, in_physicalDevice, in_surface, pPresentModeCount, pPresentModes);
    // CheckResult("vkGetPhysicalDeviceSurfacePresentModesKHR", returnValue, replay_result);

    if (pPresentModes->IsNull()) { SetOutputArrayCount<SurfaceKHRInfo>(surface, kSurfaceKHRArrayGetPhysicalDeviceSurfacePresentModesKHR, *pPresentModeCount->GetOutputPointer(), &VulkanObjectInfoTable::GetSurfaceKHRInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pSwapchain->IsNull()) { pSwapchain->SetHandleLength(1); }
    SwapchainKHRInfo handle_info;
    pSwapchain->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateSwapchainKHR(GetDeviceTable(in_device->handle)->CreateSwapchainKHR, returnValue, in_device, pCreateInfo, pAllocator, pSwapchain);
    // CheckResult("vkCreateSwapchainKHR", returnValue, replay_result);

    AddHandle<SwapchainKHRInfo>(device, pSwapchain->GetPointer(), pSwapchain->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSwapchainKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetSwapchainKHRInfo(swapchain);

   //  OverrideDestroySwapchainKHR(GetDeviceTable(in_device->handle)->DestroySwapchainKHR, in_device, in_swapchain, pAllocator);
    RemoveHandle(swapchain, &VulkanObjectInfoTable::RemoveSwapchainKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pSwapchainImageCount,
    HandlePointerDecoder<VkImage>*              pSwapchainImages)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetSwapchainKHRInfo(swapchain);
    pSwapchainImageCount->IsNull() ? nullptr : pSwapchainImageCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, SwapchainKHRInfo>("vkGetSwapchainImagesKHR", returnValue, swapchain, kSwapchainKHRArrayGetSwapchainImagesKHR, pSwapchainImageCount, pSwapchainImages, &VulkanObjectInfoTable::GetSwapchainKHRInfo));
    if (!pSwapchainImages->IsNull()) { pSwapchainImages->SetHandleLength(*pSwapchainImageCount->GetOutputPointer()); }
    std::vector<ImageInfo> handle_info(*pSwapchainImageCount->GetOutputPointer());
    for (size_t i = 0; i < *pSwapchainImageCount->GetOutputPointer(); ++i) { pSwapchainImages->SetConsumerData(i, &handle_info[i]); }

//     VkResult replay_result = OverrideGetSwapchainImagesKHR(GetDeviceTable(in_device->handle)->GetSwapchainImagesKHR, returnValue, in_device, in_swapchain, pSwapchainImageCount, pSwapchainImages);
    // CheckResult("vkGetSwapchainImagesKHR", returnValue, replay_result);

    if (pSwapchainImages->IsNull()) { SetOutputArrayCount<SwapchainKHRInfo>(swapchain, kSwapchainKHRArrayGetSwapchainImagesKHR, *pSwapchainImageCount->GetOutputPointer(), &VulkanObjectInfoTable::GetSwapchainKHRInfo); }
    AddHandles<ImageInfo>(device, pSwapchainImages->GetPointer(), pSwapchainImages->GetLength(), pSwapchainImages->GetHandlePointer(), *pSwapchainImageCount->GetOutputPointer(), std::move(handle_info), &VulkanObjectInfoTable::AddImageInfo);
}

void VulkanFrameInspectorConsumer::Process_vkAcquireNextImageKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    timeout,
    format::HandleId                            semaphore,
    format::HandleId                            fence,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetSwapchainKHRInfo(swapchain);
    auto in_semaphore = GetObjectInfoTable().GetSemaphoreInfo(semaphore);
    auto in_fence = GetObjectInfoTable().GetFenceInfo(fence);
    pImageIndex->IsNull() ? nullptr : pImageIndex->AllocateOutputData(1, static_cast<uint32_t>(0));

//     VkResult replay_result = OverrideAcquireNextImageKHR(GetDeviceTable(in_device->handle)->AcquireNextImageKHR, returnValue, in_device, in_swapchain, timeout, in_semaphore, in_fence, pImageIndex);
    // CheckResult("vkAcquireNextImageKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

    MapStructHandles(pPresentInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideQueuePresentKHR(GetDeviceTable(in_queue->handle)->QueuePresentKHR, returnValue, in_queue, pPresentInfo);
    // CheckResult("vkQueuePresentKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    pDeviceGroupPresentCapabilities->IsNull() ? nullptr : pDeviceGroupPresentCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR, nullptr });

//     VkResult replay_result = OverrideGetDeviceGroupPresentCapabilitiesKHR(GetDeviceTable(in_device->handle)->GetDeviceGroupPresentCapabilitiesKHR, returnValue, in_device, pDeviceGroupPresentCapabilities);
    // CheckResult("vkGetDeviceGroupPresentCapabilitiesKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            surface,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_surface = GetObjectInfoTable().GetSurfaceKHRInfo(surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }
    pModes->IsNull() ? nullptr : pModes->AllocateOutputData(1, static_cast<VkDeviceGroupPresentModeFlagsKHR>(0));

//     VkResult replay_result = OverrideGetDeviceGroupSurfacePresentModesKHR(GetDeviceTable(in_device->handle)->GetDeviceGroupSurfacePresentModesKHR, returnValue, in_device, in_surface, pModes);
    // CheckResult("vkGetDeviceGroupSurfacePresentModesKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pRectCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pRects)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_surface = GetObjectInfoTable().GetSurfaceKHRInfo(surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }
    pRectCount->IsNull() ? nullptr : pRectCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, SurfaceKHRInfo>("vkGetPhysicalDevicePresentRectanglesKHR", returnValue, surface, kSurfaceKHRArrayGetPhysicalDevicePresentRectanglesKHR, pRectCount, pRects, &VulkanObjectInfoTable::GetSurfaceKHRInfo));
    if (!pRects->IsNull()) { pRects->AllocateOutputData(*pRectCount->GetOutputPointer()); }

//     VkResult replay_result = OverrideGetPhysicalDevicePresentRectanglesKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDevicePresentRectanglesKHR, returnValue, in_physicalDevice, in_surface, pRectCount, pRects);
    // CheckResult("vkGetPhysicalDevicePresentRectanglesKHR", returnValue, replay_result);

    if (pRects->IsNull()) { SetOutputArrayCount<SurfaceKHRInfo>(surface, kSurfaceKHRArrayGetPhysicalDevicePresentRectanglesKHR, *pRectCount->GetOutputPointer(), &VulkanObjectInfoTable::GetSurfaceKHRInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pAcquireInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pImageIndex->IsNull() ? nullptr : pImageIndex->AllocateOutputData(1, static_cast<uint32_t>(0));

//     VkResult replay_result = OverrideAcquireNextImage2KHR(GetDeviceTable(in_device->handle)->AcquireNextImage2KHR, returnValue, in_device, pAcquireInfo, pImageIndex);
    // CheckResult("vkAcquireNextImage2KHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayPropertiesKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPropertiesKHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pProperties->IsNull()) { pProperties->AllocateOutputData(*pPropertyCount->GetOutputPointer()); }

//     VkResult replay_result = OverrideGetPhysicalDeviceDisplayPropertiesKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceDisplayPropertiesKHR, returnValue, in_physicalDevice, pPropertyCount, pProperties);
    // CheckResult("vkGetPhysicalDeviceDisplayPropertiesKHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPropertiesKHR, *pPropertyCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayPropertiesKHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), pProperties->GetOutputPointer(), *pPropertyCount->GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlanePropertiesKHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pProperties->IsNull()) { pProperties->AllocateOutputData(*pPropertyCount->GetOutputPointer()); }

//     VkResult replay_result = OverrideGetPhysicalDeviceDisplayPlanePropertiesKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceDisplayPlanePropertiesKHR, returnValue, in_physicalDevice, pPropertyCount, pProperties);
    // CheckResult("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlanePropertiesKHR, *pPropertyCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayPlanePropertiesKHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), pProperties->GetOutputPointer(), *pPropertyCount->GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanFrameInspectorConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    planeIndex,
    PointerDecoder<uint32_t>*                   pDisplayCount,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplays)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pDisplayCount->IsNull() ? nullptr : pDisplayCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetDisplayPlaneSupportedDisplaysKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetDisplayPlaneSupportedDisplaysKHR, pDisplayCount, pDisplays, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pDisplays->IsNull()) { pDisplays->SetHandleLength(*pDisplayCount->GetOutputPointer()); }
    std::vector<DisplayKHRInfo> handle_info(*pDisplayCount->GetOutputPointer());
    for (size_t i = 0; i < *pDisplayCount->GetOutputPointer(); ++i) { pDisplays->SetConsumerData(i, &handle_info[i]); }

//     VkResult replay_result = OverrideGetDisplayPlaneSupportedDisplaysKHR(GetInstanceTable(in_physicalDevice->handle)->GetDisplayPlaneSupportedDisplaysKHR, returnValue, in_physicalDevice, planeIndex, pDisplayCount, pDisplays);
    // CheckResult("vkGetDisplayPlaneSupportedDisplaysKHR", returnValue, replay_result);

    if (pDisplays->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetDisplayPlaneSupportedDisplaysKHR, *pDisplayCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
    AddHandles<DisplayKHRInfo>(physicalDevice, pDisplays->GetPointer(), pDisplays->GetLength(), pDisplays->GetHandlePointer(), *pDisplayCount->GetOutputPointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDisplayKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetDisplayModePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_display = GetObjectInfoTable().GetDisplayKHRInfo(display);
    pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DisplayKHRInfo>("vkGetDisplayModePropertiesKHR", returnValue, display, kDisplayKHRArrayGetDisplayModePropertiesKHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetDisplayKHRInfo));
    if (!pProperties->IsNull()) { pProperties->AllocateOutputData(*pPropertyCount->GetOutputPointer()); }

//     VkResult replay_result = OverrideGetDisplayModePropertiesKHR(GetInstanceTable(in_physicalDevice->handle)->GetDisplayModePropertiesKHR, returnValue, in_physicalDevice, in_display, pPropertyCount, pProperties);
    // CheckResult("vkGetDisplayModePropertiesKHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<DisplayKHRInfo>(display, kDisplayKHRArrayGetDisplayModePropertiesKHR, *pPropertyCount->GetOutputPointer(), &VulkanObjectInfoTable::GetDisplayKHRInfo); }
    AddStructArrayHandles<Decoded_VkDisplayModePropertiesKHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), pProperties->GetOutputPointer(), *pPropertyCount->GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanFrameInspectorConsumer::Process_vkCreateDisplayModeKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDisplayModeKHR>*     pMode)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_display = GetObjectInfoTable().GetDisplayKHRInfo(display);
    if (!pMode->IsNull()) { pMode->SetHandleLength(1); }
    DisplayModeKHRInfo handle_info;
    pMode->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateDisplayModeKHR(GetInstanceTable(in_physicalDevice->handle)->CreateDisplayModeKHR, returnValue, in_physicalDevice, in_display, pCreateInfo, pAllocator, pMode);
    // CheckResult("vkCreateDisplayModeKHR", returnValue, replay_result);

    AddHandle<DisplayModeKHRInfo>(physicalDevice, pMode->GetPointer(), pMode->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDisplayModeKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            mode,
    uint32_t                                    planeIndex,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_mode = GetObjectInfoTable().GetDisplayModeKHRInfo(mode);
    pCapabilities->IsNull() ? nullptr : pCapabilities->AllocateOutputData(1);

//     VkResult replay_result = OverrideGetDisplayPlaneCapabilitiesKHR(GetInstanceTable(in_physicalDevice->handle)->GetDisplayPlaneCapabilitiesKHR, returnValue, in_physicalDevice, in_mode, planeIndex, pCapabilities);
    // CheckResult("vkGetDisplayPlaneCapabilitiesKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateDisplayPlaneSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateDisplayPlaneSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateDisplayPlaneSurfaceKHR", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateSharedSwapchainsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    if (!pSwapchains->IsNull()) { pSwapchains->SetHandleLength(swapchainCount); }
    std::vector<SwapchainKHRInfo> handle_info(swapchainCount);
    for (size_t i = 0; i < swapchainCount; ++i) { pSwapchains->SetConsumerData(i, &handle_info[i]); }

//     VkResult replay_result = OverrideCreateSharedSwapchainsKHR(GetDeviceTable(in_device->handle)->CreateSharedSwapchainsKHR, returnValue, in_device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    // CheckResult("vkCreateSharedSwapchainsKHR", returnValue, replay_result);

    AddHandles<SwapchainKHRInfo>(device, pSwapchains->GetPointer(), pSwapchains->GetLength(), pSwapchains->GetHandlePointer(), swapchainCount, std::move(handle_info), &VulkanObjectInfoTable::AddSwapchainKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateXlibSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateXlibSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateXlibSurfaceKHR", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dpy,
    size_t                                      visualID)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    // Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(dpy, format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR, "vkGetPhysicalDeviceXlibPresentationSupportKHR"));

   //  OverrideGetPhysicalDeviceXlibPresentationSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceXlibPresentationSupportKHR, in_physicalDevice, queueFamilyIndex, in_dpy, visualID);
}

void VulkanFrameInspectorConsumer::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateXcbSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateXcbSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateXcbSurfaceKHR", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    connection,
    uint32_t                                    visual_id)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    // xcb_connection_t* in_connection = static_cast<xcb_connection_t*>(PreProcessExternalObject(connection, format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR, "vkGetPhysicalDeviceXcbPresentationSupportKHR"));

   //  OverrideGetPhysicalDeviceXcbPresentationSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceXcbPresentationSupportKHR, in_physicalDevice, queueFamilyIndex, in_connection, visual_id);
}

void VulkanFrameInspectorConsumer::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateWaylandSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateWaylandSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateWaylandSurfaceKHR", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    display)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    // struct wl_display* in_display = static_cast<struct wl_display*>(PreProcessExternalObject(display, format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR, "vkGetPhysicalDeviceWaylandPresentationSupportKHR"));

   //  OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceWaylandPresentationSupportKHR, in_physicalDevice, queueFamilyIndex, in_display);
}

void VulkanFrameInspectorConsumer::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateAndroidSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateAndroidSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateAndroidSurfaceKHR", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateWin32SurfaceKHR(GetInstanceTable(in_instance->handle)->CreateWin32SurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateWin32SurfaceKHR", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);

   //  OverrideGetPhysicalDeviceWin32PresentationSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceWin32PresentationSupportKHR, in_physicalDevice, queueFamilyIndex);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pRenderingInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdBeginRenderingKHR(GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderingKHR, in_commandBuffer, pRenderingInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdEndRenderingKHR(GetDeviceTable(in_commandBuffer->handle)->CmdEndRenderingKHR, in_commandBuffer);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pFeatures->IsNull() ? nullptr : pFeatures->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, nullptr });

   //  OverrideGetPhysicalDeviceFeatures2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceFeatures2KHR, in_physicalDevice, pFeatures);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, nullptr });

   //  OverrideGetPhysicalDeviceProperties2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceProperties2KHR, in_physicalDevice, pProperties);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pFormatProperties->IsNull() ? nullptr : pFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2, nullptr });

   //  OverrideGetPhysicalDeviceFormatProperties2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceFormatProperties2KHR, in_physicalDevice, format, pFormatProperties);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pImageFormatProperties->IsNull() ? nullptr : pImageFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

//     VkResult replay_result = OverrideGetPhysicalDeviceImageFormatProperties2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceImageFormatProperties2KHR, returnValue, in_physicalDevice, pImageFormatInfo, pImageFormatProperties);
    // CheckResult("vkGetPhysicalDeviceImageFormatProperties2KHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pQueueFamilyPropertyCount->IsNull() ? nullptr : pQueueFamilyPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyProperties2KHR", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2KHR, pQueueFamilyPropertyCount, pQueueFamilyProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pQueueFamilyProperties->IsNull()) { pQueueFamilyProperties->AllocateOutputData(*pQueueFamilyPropertyCount->GetOutputPointer(), VkQueueFamilyProperties2{ VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2, nullptr }); }

   //  OverrideGetPhysicalDeviceQueueFamilyProperties2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceQueueFamilyProperties2KHR, in_physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    if (pQueueFamilyProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2KHR, *pQueueFamilyPropertyCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pMemoryProperties->IsNull() ? nullptr : pMemoryProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2, nullptr });

   //  OverrideGetPhysicalDeviceMemoryProperties2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceMemoryProperties2KHR, in_physicalDevice, pMemoryProperties);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceSparseImageFormatProperties2KHR", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2KHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pProperties->IsNull()) { pProperties->AllocateOutputData(*pPropertyCount->GetOutputPointer(), VkSparseImageFormatProperties2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2, nullptr }); }

   //  OverrideGetPhysicalDeviceSparseImageFormatProperties2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSparseImageFormatProperties2KHR, in_physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2KHR, *pPropertyCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    pPeerMemoryFeatures->IsNull() ? nullptr : pPeerMemoryFeatures->AllocateOutputData(1, static_cast<VkPeerMemoryFeatureFlags>(0));

   //  OverrideGetDeviceGroupPeerMemoryFeaturesKHR(GetDeviceTable(in_device->handle)->GetDeviceGroupPeerMemoryFeaturesKHR, in_device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDeviceMaskKHR(GetDeviceTable(in_commandBuffer->handle)->CmdSetDeviceMaskKHR, in_commandBuffer, deviceMask);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdDispatchBaseKHR(GetDeviceTable(in_commandBuffer->handle)->CmdDispatchBaseKHR, in_commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void VulkanFrameInspectorConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_commandPool = GetObjectInfoTable().GetCommandPoolInfo(commandPool);

   //  OverrideTrimCommandPoolKHR(GetDeviceTable(in_device->handle)->TrimCommandPoolKHR, in_device, in_commandPool, flags);
}

void VulkanFrameInspectorConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    pPhysicalDeviceGroupCount->IsNull() ? nullptr : pPhysicalDeviceGroupCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, InstanceInfo>("vkEnumeratePhysicalDeviceGroupsKHR", returnValue, instance, kInstanceArrayEnumeratePhysicalDeviceGroupsKHR, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties, &VulkanObjectInfoTable::GetInstanceInfo));
    SetStructArrayHandleLengths<Decoded_VkPhysicalDeviceGroupProperties>(pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength());
    if (!pPhysicalDeviceGroupProperties->IsNull()) { pPhysicalDeviceGroupProperties->AllocateOutputData(*pPhysicalDeviceGroupCount->GetOutputPointer(), VkPhysicalDeviceGroupProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES, nullptr }); }

//     VkResult replay_result = OverrideEnumeratePhysicalDeviceGroupsKHR(GetInstanceTable(in_instance->handle)->EnumeratePhysicalDeviceGroupsKHR, returnValue, in_instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    // CheckResult("vkEnumeratePhysicalDeviceGroupsKHR", returnValue, replay_result);

    if (pPhysicalDeviceGroupProperties->IsNull()) { SetOutputArrayCount<InstanceInfo>(instance, kInstanceArrayEnumeratePhysicalDeviceGroupsKHR, *pPhysicalDeviceGroupCount->GetOutputPointer(), &VulkanObjectInfoTable::GetInstanceInfo); }
    AddStructArrayHandles<Decoded_VkPhysicalDeviceGroupProperties>(instance, pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength(), pPhysicalDeviceGroupProperties->GetOutputPointer(), *pPhysicalDeviceGroupCount->GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pExternalBufferProperties->IsNull() ? nullptr : pExternalBufferProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES, nullptr });

   //  OverrideGetPhysicalDeviceExternalBufferPropertiesKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceExternalBufferPropertiesKHR, in_physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

void VulkanFrameInspectorConsumer::Process_vkGetMemoryWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pGetWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    HANDLE* out_pHandle = pHandle->IsNull() ? nullptr : reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

//     VkResult replay_result = OverrideGetMemoryWin32HandleKHR(GetDeviceTable(in_device->handle)->GetMemoryWin32HandleKHR, returnValue, in_device, pGetWin32HandleInfo, out_pHandle);
    // CheckResult("vkGetMemoryWin32HandleKHR", returnValue, replay_result);

    // PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR, "vkGetMemoryWin32HandleKHR");
}

void VulkanFrameInspectorConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    handle,
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    // HANDLE in_handle = static_cast<HANDLE>(PreProcessExternalObject(handle, format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR, "vkGetMemoryWin32HandlePropertiesKHR"));
    // pMemoryWin32HandleProperties->IsNull() ? nullptr : pMemoryWin32HandleProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR, nullptr });

//     VkResult replay_result = OverrideGetMemoryWin32HandlePropertiesKHR(GetDeviceTable(in_device->handle)->GetMemoryWin32HandlePropertiesKHR, returnValue, in_device, handleType, in_handle, pMemoryWin32HandleProperties);
    // CheckResult("vkGetMemoryWin32HandlePropertiesKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetMemoryFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pGetFdInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pFd->IsNull() ? nullptr : pFd->AllocateOutputData(1, static_cast<int>(0));

//     VkResult replay_result = OverrideGetMemoryFdKHR(GetDeviceTable(in_device->handle)->GetMemoryFdKHR, returnValue, in_device, pGetFdInfo, pFd);
    // CheckResult("vkGetMemoryFdKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetMemoryFdPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    pMemoryFdProperties->IsNull() ? nullptr : pMemoryFdProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR, nullptr });

//     VkResult replay_result = OverrideGetMemoryFdPropertiesKHR(GetDeviceTable(in_device->handle)->GetMemoryFdPropertiesKHR, returnValue, in_device, handleType, fd, pMemoryFdProperties);
    // CheckResult("vkGetMemoryFdPropertiesKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pExternalSemaphoreProperties->IsNull() ? nullptr : pExternalSemaphoreProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES, nullptr });

   //  OverrideGetPhysicalDeviceExternalSemaphorePropertiesKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceExternalSemaphorePropertiesKHR, in_physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

void VulkanFrameInspectorConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pImportSemaphoreWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideImportSemaphoreWin32HandleKHR(GetDeviceTable(in_device->handle)->ImportSemaphoreWin32HandleKHR, returnValue, in_device, pImportSemaphoreWin32HandleInfo);
    // CheckResult("vkImportSemaphoreWin32HandleKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pGetWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    HANDLE* out_pHandle = pHandle->IsNull() ? nullptr : reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

//     VkResult replay_result = OverrideGetSemaphoreWin32HandleKHR(GetDeviceTable(in_device->handle)->GetSemaphoreWin32HandleKHR, returnValue, in_device, pGetWin32HandleInfo, out_pHandle);
    // CheckResult("vkGetSemaphoreWin32HandleKHR", returnValue, replay_result);

    // PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR, "vkGetSemaphoreWin32HandleKHR");
}

void VulkanFrameInspectorConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pImportSemaphoreFdInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideImportSemaphoreFdKHR(GetDeviceTable(in_device->handle)->ImportSemaphoreFdKHR, returnValue, in_device, pImportSemaphoreFdInfo);
    // CheckResult("vkImportSemaphoreFdKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pGetFdInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pFd->IsNull() ? nullptr : pFd->AllocateOutputData(1, static_cast<int>(0));

//     VkResult replay_result = OverrideGetSemaphoreFdKHR(GetDeviceTable(in_device->handle)->GetSemaphoreFdKHR, returnValue, in_device, pGetFdInfo, pFd);
    // CheckResult("vkGetSemaphoreFdKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_layout = GetObjectInfoTable().GetPipelineLayoutInfo(layout);

    MapStructArrayHandles(pDescriptorWrites->GetMetaStructPointer(), pDescriptorWrites->GetLength(), GetObjectInfoTable());

   //  OverrideCmdPushDescriptorSetKHR(GetDeviceTable(in_commandBuffer->handle)->CmdPushDescriptorSetKHR, in_commandBuffer, pipelineBindPoint, in_layout, set, descriptorWriteCount, pDescriptorWrites);
}

void VulkanFrameInspectorConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pDescriptorUpdateTemplate->IsNull()) { pDescriptorUpdateTemplate->SetHandleLength(1); }
    DescriptorUpdateTemplateInfo handle_info;
    pDescriptorUpdateTemplate->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateDescriptorUpdateTemplateKHR(GetDeviceTable(in_device->handle)->CreateDescriptorUpdateTemplateKHR, returnValue, in_device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    // CheckResult("vkCreateDescriptorUpdateTemplateKHR", returnValue, replay_result);

    AddHandle<DescriptorUpdateTemplateInfo>(device, pDescriptorUpdateTemplate->GetPointer(), pDescriptorUpdateTemplate->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDescriptorUpdateTemplateInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_descriptorUpdateTemplate = GetObjectInfoTable().GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

   //  OverrideDestroyDescriptorUpdateTemplateKHR(GetDeviceTable(in_device->handle)->DestroyDescriptorUpdateTemplateKHR, in_device, in_descriptorUpdateTemplate, pAllocator);
    RemoveHandle(descriptorUpdateTemplate, &VulkanObjectInfoTable::RemoveDescriptorUpdateTemplateInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pRenderPass->IsNull()) { pRenderPass->SetHandleLength(1); }
    RenderPassInfo handle_info;
    pRenderPass->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateRenderPass2KHR(GetDeviceTable(in_device->handle)->CreateRenderPass2KHR, returnValue, in_device, pCreateInfo, pAllocator, pRenderPass);
    // CheckResult("vkCreateRenderPass2KHR", returnValue, replay_result);

    AddHandle<RenderPassInfo>(device, pRenderPass->GetPointer(), pRenderPass->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddRenderPassInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pRenderPassBegin->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdBeginRenderPass2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderPass2KHR, in_commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdNextSubpass2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdNextSubpass2KHR, in_commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdEndRenderPass2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdEndRenderPass2KHR, in_commandBuffer, pSubpassEndInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetSwapchainKHRInfo(swapchain);

//     VkResult replay_result = OverrideGetSwapchainStatusKHR(GetDeviceTable(in_device->handle)->GetSwapchainStatusKHR, returnValue, in_device, in_swapchain);
    // CheckResult("vkGetSwapchainStatusKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pExternalFenceProperties->IsNull() ? nullptr : pExternalFenceProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES, nullptr });

   //  OverrideGetPhysicalDeviceExternalFencePropertiesKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceExternalFencePropertiesKHR, in_physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

void VulkanFrameInspectorConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pImportFenceWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideImportFenceWin32HandleKHR(GetDeviceTable(in_device->handle)->ImportFenceWin32HandleKHR, returnValue, in_device, pImportFenceWin32HandleInfo);
    // CheckResult("vkImportFenceWin32HandleKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pGetWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    HANDLE* out_pHandle = pHandle->IsNull() ? nullptr : reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

//     VkResult replay_result = OverrideGetFenceWin32HandleKHR(GetDeviceTable(in_device->handle)->GetFenceWin32HandleKHR, returnValue, in_device, pGetWin32HandleInfo, out_pHandle);
    // CheckResult("vkGetFenceWin32HandleKHR", returnValue, replay_result);

    // PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR, "vkGetFenceWin32HandleKHR");
}

void VulkanFrameInspectorConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pImportFenceFdInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideImportFenceFdKHR(GetDeviceTable(in_device->handle)->ImportFenceFdKHR, returnValue, in_device, pImportFenceFdInfo);
    // CheckResult("vkImportFenceFdKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pGetFdInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pFd->IsNull() ? nullptr : pFd->AllocateOutputData(1, static_cast<int>(0));

//     VkResult replay_result = OverrideGetFenceFdKHR(GetDeviceTable(in_device->handle)->GetFenceFdKHR, returnValue, in_device, pGetFdInfo, pFd);
    // CheckResult("vkGetFenceFdKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    PointerDecoder<uint32_t>*                   pCounterCount,
    StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters,
    StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pCounterCount->IsNull() ? nullptr : pCounterCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", returnValue, physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, pCounterCount, pCounterDescriptions, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pCounters->IsNull()) { pCounters->AllocateOutputData(*pCounterCount->GetOutputPointer(), VkPerformanceCounterKHR{ VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR, nullptr }); }
    if (!pCounterDescriptions->IsNull()) { pCounterDescriptions->AllocateOutputData(*pCounterCount->GetOutputPointer(), VkPerformanceCounterDescriptionKHR{ VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR, nullptr }); }

//     VkResult replay_result = OverrideEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(GetInstanceTable(in_physicalDevice->handle)->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, returnValue, in_physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    // CheckResult("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", returnValue, replay_result);

    if (pCounters->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, *pCounterCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
    if (pCounterDescriptions->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, *pCounterCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pNumPasses->IsNull() ? nullptr : pNumPasses->AllocateOutputData(1, static_cast<uint32_t>(0));

   //  OverrideGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR, in_physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
}

void VulkanFrameInspectorConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

//     VkResult replay_result = OverrideAcquireProfilingLockKHR(GetDeviceTable(in_device->handle)->AcquireProfilingLockKHR, returnValue, in_device, pInfo);
    // CheckResult("vkAcquireProfilingLockKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

   //  OverrideReleaseProfilingLockKHR(GetDeviceTable(in_device->handle)->ReleaseProfilingLockKHR, in_device);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);

    if (pSurfaceInfo->GetPointer()->surface == VK_NULL_HANDLE) { return; }
    MapStructHandles(pSurfaceInfo->GetMetaStructPointer(), GetObjectInfoTable());
    auto in_pSurfaceInfo_meta = pSurfaceInfo->GetMetaStructPointer();
    if (GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    pSurfaceCapabilities->IsNull() ? nullptr : pSurfaceCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR, nullptr });

//     VkResult replay_result = OverrideGetPhysicalDeviceSurfaceCapabilities2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceCapabilities2KHR, returnValue, in_physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    // CheckResult("vkGetPhysicalDeviceSurfaceCapabilities2KHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);

    if (pSurfaceInfo->GetPointer()->surface == VK_NULL_HANDLE) { return; }
    MapStructHandles(pSurfaceInfo->GetMetaStructPointer(), GetObjectInfoTable());
    auto in_pSurfaceInfo_meta = pSurfaceInfo->GetMetaStructPointer();
    if (GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    pSurfaceFormatCount->IsNull() ? nullptr : pSurfaceFormatCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceSurfaceFormats2KHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfaceFormats2KHR, pSurfaceFormatCount, pSurfaceFormats, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pSurfaceFormats->IsNull()) { pSurfaceFormats->AllocateOutputData(*pSurfaceFormatCount->GetOutputPointer(), VkSurfaceFormat2KHR{ VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR, nullptr }); }

//     VkResult replay_result = OverrideGetPhysicalDeviceSurfaceFormats2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceFormats2KHR, returnValue, in_physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    // CheckResult("vkGetPhysicalDeviceSurfaceFormats2KHR", returnValue, replay_result);

    if (pSurfaceFormats->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfaceFormats2KHR, *pSurfaceFormatCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayProperties2KHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayProperties2KHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pProperties->IsNull()) { pProperties->AllocateOutputData(*pPropertyCount->GetOutputPointer(), VkDisplayProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR, nullptr }); }

//     VkResult replay_result = OverrideGetPhysicalDeviceDisplayProperties2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceDisplayProperties2KHR, returnValue, in_physicalDevice, pPropertyCount, pProperties);
    // CheckResult("vkGetPhysicalDeviceDisplayProperties2KHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayProperties2KHR, *pPropertyCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayProperties2KHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), pProperties->GetOutputPointer(), *pPropertyCount->GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlaneProperties2KHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pProperties->IsNull()) { pProperties->AllocateOutputData(*pPropertyCount->GetOutputPointer(), VkDisplayPlaneProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR, nullptr }); }

//     VkResult replay_result = OverrideGetPhysicalDeviceDisplayPlaneProperties2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceDisplayPlaneProperties2KHR, returnValue, in_physicalDevice, pPropertyCount, pProperties);
    // CheckResult("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlaneProperties2KHR, *pPropertyCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayPlaneProperties2KHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), pProperties->GetOutputPointer(), *pPropertyCount->GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanFrameInspectorConsumer::Process_vkGetDisplayModeProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_display = GetObjectInfoTable().GetDisplayKHRInfo(display);
    pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DisplayKHRInfo>("vkGetDisplayModeProperties2KHR", returnValue, display, kDisplayKHRArrayGetDisplayModeProperties2KHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetDisplayKHRInfo));
    if (!pProperties->IsNull()) { pProperties->AllocateOutputData(*pPropertyCount->GetOutputPointer(), VkDisplayModeProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR, nullptr }); }

//     VkResult replay_result = OverrideGetDisplayModeProperties2KHR(GetInstanceTable(in_physicalDevice->handle)->GetDisplayModeProperties2KHR, returnValue, in_physicalDevice, in_display, pPropertyCount, pProperties);
    // CheckResult("vkGetDisplayModeProperties2KHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<DisplayKHRInfo>(display, kDisplayKHRArrayGetDisplayModeProperties2KHR, *pPropertyCount->GetOutputPointer(), &VulkanObjectInfoTable::GetDisplayKHRInfo); }
    AddStructArrayHandles<Decoded_VkDisplayModeProperties2KHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), pProperties->GetOutputPointer(), *pPropertyCount->GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanFrameInspectorConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);

    MapStructHandles(pDisplayPlaneInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pCapabilities->IsNull() ? nullptr : pCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR, nullptr });

//     VkResult replay_result = OverrideGetDisplayPlaneCapabilities2KHR(GetInstanceTable(in_physicalDevice->handle)->GetDisplayPlaneCapabilities2KHR, returnValue, in_physicalDevice, pDisplayPlaneInfo, pCapabilities);
    // CheckResult("vkGetDisplayPlaneCapabilities2KHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

   //  OverrideGetImageMemoryRequirements2KHR(GetDeviceTable(in_device->handle)->GetImageMemoryRequirements2KHR, in_device, pInfo, pMemoryRequirements);
}

void VulkanFrameInspectorConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

   //  OverrideGetBufferMemoryRequirements2KHR(GetDeviceTable(in_device->handle)->GetBufferMemoryRequirements2KHR, in_device, pInfo, pMemoryRequirements);
}

void VulkanFrameInspectorConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetImageSparseMemoryRequirements2KHR", VK_SUCCESS, device, kDeviceArrayGetImageSparseMemoryRequirements2KHR, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &VulkanObjectInfoTable::GetDeviceInfo));
    if (!pSparseMemoryRequirements->IsNull()) { pSparseMemoryRequirements->AllocateOutputData(*pSparseMemoryRequirementCount->GetOutputPointer(), VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr }); }

   //  OverrideGetImageSparseMemoryRequirements2KHR(GetDeviceTable(in_device->handle)->GetImageSparseMemoryRequirements2KHR, in_device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetImageSparseMemoryRequirements2KHR, *pSparseMemoryRequirementCount->GetOutputPointer(), &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pYcbcrConversion->IsNull()) { pYcbcrConversion->SetHandleLength(1); }
    SamplerYcbcrConversionInfo handle_info;
    pYcbcrConversion->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateSamplerYcbcrConversionKHR(GetDeviceTable(in_device->handle)->CreateSamplerYcbcrConversionKHR, returnValue, in_device, pCreateInfo, pAllocator, pYcbcrConversion);
    // CheckResult("vkCreateSamplerYcbcrConversionKHR", returnValue, replay_result);

    AddHandle<SamplerYcbcrConversionInfo>(device, pYcbcrConversion->GetPointer(), pYcbcrConversion->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSamplerYcbcrConversionInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_ycbcrConversion = GetObjectInfoTable().GetSamplerYcbcrConversionInfo(ycbcrConversion);

   //  OverrideDestroySamplerYcbcrConversionKHR(GetDeviceTable(in_device->handle)->DestroySamplerYcbcrConversionKHR, in_device, in_ycbcrConversion, pAllocator);
    RemoveHandle(ycbcrConversion, &VulkanObjectInfoTable::RemoveSamplerYcbcrConversionInfo);
}

void VulkanFrameInspectorConsumer::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

//     VkResult replay_result = OverrideBindBufferMemory2KHR(GetDeviceTable(in_device->handle)->BindBufferMemory2KHR, returnValue, in_device, bindInfoCount, pBindInfos);
    // CheckResult("vkBindBufferMemory2KHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

//     VkResult replay_result = OverrideBindImageMemory2KHR(GetDeviceTable(in_device->handle)->BindImageMemory2KHR, returnValue, in_device, bindInfoCount, pBindInfos);
    // CheckResult("vkBindImageMemory2KHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pSupport->IsNull() ? nullptr : pSupport->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT, nullptr });

   //  OverrideGetDescriptorSetLayoutSupportKHR(GetDeviceTable(in_device->handle)->GetDescriptorSetLayoutSupportKHR, in_device, pCreateInfo, pSupport);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);
    auto in_countBuffer = GetObjectInfoTable().GetBufferInfo(countBuffer);

   //  OverrideCmdDrawIndirectCountKHR(GetDeviceTable(in_commandBuffer->handle)->CmdDrawIndirectCountKHR, in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);
    auto in_countBuffer = GetObjectInfoTable().GetBufferInfo(countBuffer);

   //  OverrideCmdDrawIndexedIndirectCountKHR(GetDeviceTable(in_commandBuffer->handle)->CmdDrawIndexedIndirectCountKHR, in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanFrameInspectorConsumer::Process_vkGetSemaphoreCounterValueKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_semaphore = GetObjectInfoTable().GetSemaphoreInfo(semaphore);
    pValue->IsNull() ? nullptr : pValue->AllocateOutputData(1, static_cast<uint64_t>(0));

//     VkResult replay_result = OverrideGetSemaphoreCounterValueKHR(GetDeviceTable(in_device->handle)->GetSemaphoreCounterValueKHR, returnValue, in_device, in_semaphore, pValue);
    // CheckResult("vkGetSemaphoreCounterValueKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkWaitSemaphoresKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pWaitInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideWaitSemaphoresKHR(GetDeviceTable(in_device->handle)->WaitSemaphoresKHR, returnValue, in_device, pWaitInfo, timeout);
    // CheckResult("vkWaitSemaphoresKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pSignalInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideSignalSemaphoreKHR(GetDeviceTable(in_device->handle)->SignalSemaphoreKHR, returnValue, in_device, pSignalInfo);
    // CheckResult("vkSignalSemaphoreKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pFragmentShadingRateCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pFragmentShadingRateCount->IsNull() ? nullptr : pFragmentShadingRateCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceFragmentShadingRatesKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceFragmentShadingRatesKHR, pFragmentShadingRateCount, pFragmentShadingRates, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pFragmentShadingRates->IsNull()) { pFragmentShadingRates->AllocateOutputData(*pFragmentShadingRateCount->GetOutputPointer(), VkPhysicalDeviceFragmentShadingRateKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR, nullptr }); }

//     VkResult replay_result = OverrideGetPhysicalDeviceFragmentShadingRatesKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceFragmentShadingRatesKHR, returnValue, in_physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
    // CheckResult("vkGetPhysicalDeviceFragmentShadingRatesKHR", returnValue, replay_result);

    if (pFragmentShadingRates->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceFragmentShadingRatesKHR, *pFragmentShadingRateCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetFragmentShadingRateKHR(GetDeviceTable(in_commandBuffer->handle)->CmdSetFragmentShadingRateKHR, in_commandBuffer, pFragmentSize, combinerOps);
}

void VulkanFrameInspectorConsumer::Process_vkWaitForPresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    presentId,
    uint64_t                                    timeout)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetSwapchainKHRInfo(swapchain);

//     VkResult replay_result = OverrideWaitForPresentKHR(GetDeviceTable(in_device->handle)->WaitForPresentKHR, returnValue, in_device, in_swapchain, presentId, timeout);
    // CheckResult("vkWaitForPresentKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideGetBufferDeviceAddressKHR(GetDeviceTable(in_device->handle)->GetBufferDeviceAddressKHR, in_device, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideGetBufferOpaqueCaptureAddressKHR(GetDeviceTable(in_device->handle)->GetBufferOpaqueCaptureAddressKHR, in_device, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideGetDeviceMemoryOpaqueCaptureAddressKHR(GetDeviceTable(in_device->handle)->GetDeviceMemoryOpaqueCaptureAddressKHR, in_device, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pDeferredOperation->IsNull()) { pDeferredOperation->SetHandleLength(1); }
    DeferredOperationKHRInfo handle_info;
    pDeferredOperation->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateDeferredOperationKHR(GetDeviceTable(in_device->handle)->CreateDeferredOperationKHR, returnValue, in_device, pAllocator, pDeferredOperation);
    // CheckResult("vkCreateDeferredOperationKHR", returnValue, replay_result);

    AddHandle<DeferredOperationKHRInfo>(device, pDeferredOperation->GetPointer(), pDeferredOperation->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDeferredOperationKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_operation = GetObjectInfoTable().GetDeferredOperationKHRInfo(operation);

   //  OverrideDestroyDeferredOperationKHR(GetDeviceTable(in_device->handle)->DestroyDeferredOperationKHR, in_device, in_operation, pAllocator);
    RemoveHandle(operation, &VulkanObjectInfoTable::RemoveDeferredOperationKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_operation = GetObjectInfoTable().GetDeferredOperationKHRInfo(operation);

   //  OverrideGetDeferredOperationMaxConcurrencyKHR(GetDeviceTable(in_device->handle)->GetDeferredOperationMaxConcurrencyKHR, in_device, in_operation);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_operation = GetObjectInfoTable().GetDeferredOperationKHRInfo(operation);

//     VkResult replay_result = OverrideGetDeferredOperationResultKHR(GetDeviceTable(in_device->handle)->GetDeferredOperationResultKHR, returnValue, in_device, in_operation);
    // CheckResult("vkGetDeferredOperationResultKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_operation = GetObjectInfoTable().GetDeferredOperationKHRInfo(operation);

//     VkResult replay_result = OverrideDeferredOperationJoinKHR(GetDeviceTable(in_device->handle)->DeferredOperationJoinKHR, returnValue, in_device, in_operation);
    // CheckResult("vkDeferredOperationJoinKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo,
    PointerDecoder<uint32_t>*                   pExecutableCount,
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pPipelineInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pExecutableCount->IsNull() ? nullptr : pExecutableCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetPipelineExecutablePropertiesKHR", returnValue, device, kDeviceArrayGetPipelineExecutablePropertiesKHR, pExecutableCount, pProperties, &VulkanObjectInfoTable::GetDeviceInfo));
    if (!pProperties->IsNull()) { pProperties->AllocateOutputData(*pExecutableCount->GetOutputPointer(), VkPipelineExecutablePropertiesKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR, nullptr }); }

//     VkResult replay_result = OverrideGetPipelineExecutablePropertiesKHR(GetDeviceTable(in_device->handle)->GetPipelineExecutablePropertiesKHR, returnValue, in_device, pPipelineInfo, pExecutableCount, pProperties);
    // CheckResult("vkGetPipelineExecutablePropertiesKHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetPipelineExecutablePropertiesKHR, *pExecutableCount->GetOutputPointer(), &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pStatisticCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pExecutableInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pStatisticCount->IsNull() ? nullptr : pStatisticCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetPipelineExecutableStatisticsKHR", returnValue, device, kDeviceArrayGetPipelineExecutableStatisticsKHR, pStatisticCount, pStatistics, &VulkanObjectInfoTable::GetDeviceInfo));
    if (!pStatistics->IsNull()) { pStatistics->AllocateOutputData(*pStatisticCount->GetOutputPointer(), VkPipelineExecutableStatisticKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR, nullptr }); }

//     VkResult replay_result = OverrideGetPipelineExecutableStatisticsKHR(GetDeviceTable(in_device->handle)->GetPipelineExecutableStatisticsKHR, returnValue, in_device, pExecutableInfo, pStatisticCount, pStatistics);
    // CheckResult("vkGetPipelineExecutableStatisticsKHR", returnValue, replay_result);

    if (pStatistics->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetPipelineExecutableStatisticsKHR, *pStatisticCount->GetOutputPointer(), &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pExecutableInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pInternalRepresentationCount->IsNull() ? nullptr : pInternalRepresentationCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetPipelineExecutableInternalRepresentationsKHR", returnValue, device, kDeviceArrayGetPipelineExecutableInternalRepresentationsKHR, pInternalRepresentationCount, pInternalRepresentations, &VulkanObjectInfoTable::GetDeviceInfo));
    if (!pInternalRepresentations->IsNull()) { pInternalRepresentations->AllocateOutputData(*pInternalRepresentationCount->GetOutputPointer(), VkPipelineExecutableInternalRepresentationKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR, nullptr }); }

//     VkResult replay_result = OverrideGetPipelineExecutableInternalRepresentationsKHR(GetDeviceTable(in_device->handle)->GetPipelineExecutableInternalRepresentationsKHR, returnValue, in_device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
    // CheckResult("vkGetPipelineExecutableInternalRepresentationsKHR", returnValue, replay_result);

    if (pInternalRepresentations->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetPipelineExecutableInternalRepresentationsKHR, *pInternalRepresentationCount->GetOutputPointer(), &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_event = GetObjectInfoTable().GetEventInfo(event);

    MapStructHandles(pDependencyInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdSetEvent2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdSetEvent2KHR, in_commandBuffer, in_event, pDependencyInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_event = GetObjectInfoTable().GetEventInfo(event);

   //  OverrideCmdResetEvent2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdResetEvent2KHR, in_commandBuffer, in_event, stageMask);
}

void VulkanFrameInspectorConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    MapHandles<EventInfo>(pEvents, eventCount, &VulkanObjectInfoTable::GetEventInfo);

    MapStructArrayHandles(pDependencyInfos->GetMetaStructPointer(), pDependencyInfos->GetLength(), GetObjectInfoTable());

   //  OverrideCmdWaitEvents2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdWaitEvents2KHR, in_commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void VulkanFrameInspectorConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pDependencyInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdPipelineBarrier2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdPipelineBarrier2KHR, in_commandBuffer, pDependencyInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideCmdWriteTimestamp2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdWriteTimestamp2KHR, in_commandBuffer, stage, in_queryPool, query);
}

void VulkanFrameInspectorConsumer::Process_vkQueueSubmit2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

    MapStructArrayHandles(pSubmits->GetMetaStructPointer(), pSubmits->GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetFenceInfo(fence);

//     VkResult replay_result = OverrideQueueSubmit2KHR(GetDeviceTable(in_queue->handle)->QueueSubmit2KHR, returnValue, in_queue, submitCount, pSubmits, in_fence);
    // CheckResult("vkQueueSubmit2KHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_dstBuffer = GetObjectInfoTable().GetBufferInfo(dstBuffer);

   //  OverrideCmdWriteBufferMarker2AMD(GetDeviceTable(in_commandBuffer->handle)->CmdWriteBufferMarker2AMD, in_commandBuffer, stage, in_dstBuffer, dstOffset, marker);
}

void VulkanFrameInspectorConsumer::Process_vkGetQueueCheckpointData2NV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);
    pCheckpointDataCount->IsNull() ? nullptr : pCheckpointDataCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, QueueInfo>("vkGetQueueCheckpointData2NV", VK_SUCCESS, queue, kQueueArrayGetQueueCheckpointData2NV, pCheckpointDataCount, pCheckpointData, &VulkanObjectInfoTable::GetQueueInfo));
    if (!pCheckpointData->IsNull()) { pCheckpointData->AllocateOutputData(*pCheckpointDataCount->GetOutputPointer(), VkCheckpointData2NV{ VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV, nullptr }); }

   //  OverrideGetQueueCheckpointData2NV(GetDeviceTable(in_queue->handle)->GetQueueCheckpointData2NV, in_queue, pCheckpointDataCount, pCheckpointData);

    if (pCheckpointData->IsNull()) { SetOutputArrayCount<QueueInfo>(queue, kQueueArrayGetQueueCheckpointData2NV, *pCheckpointDataCount->GetOutputPointer(), &VulkanObjectInfoTable::GetQueueInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pCopyBufferInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyBuffer2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdCopyBuffer2KHR, in_commandBuffer, pCopyBufferInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pCopyImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyImage2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdCopyImage2KHR, in_commandBuffer, pCopyImageInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pCopyBufferToImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyBufferToImage2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdCopyBufferToImage2KHR, in_commandBuffer, pCopyBufferToImageInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pCopyImageToBufferInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyImageToBuffer2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdCopyImageToBuffer2KHR, in_commandBuffer, pCopyImageToBufferInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pBlitImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdBlitImage2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdBlitImage2KHR, in_commandBuffer, pBlitImageInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pResolveImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdResolveImage2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdResolveImage2KHR, in_commandBuffer, pResolveImageInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdTraceRaysIndirect2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdTraceRaysIndirect2KHR, in_commandBuffer, indirectDeviceAddress);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

   //  OverrideGetDeviceBufferMemoryRequirementsKHR(GetDeviceTable(in_device->handle)->GetDeviceBufferMemoryRequirementsKHR, in_device, pInfo, pMemoryRequirements);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

   //  OverrideGetDeviceImageMemoryRequirementsKHR(GetDeviceTable(in_device->handle)->GetDeviceImageMemoryRequirementsKHR, in_device, pInfo, pMemoryRequirements);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetDeviceImageSparseMemoryRequirementsKHR", VK_SUCCESS, device, kDeviceArrayGetDeviceImageSparseMemoryRequirementsKHR, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &VulkanObjectInfoTable::GetDeviceInfo));
    if (!pSparseMemoryRequirements->IsNull()) { pSparseMemoryRequirements->AllocateOutputData(*pSparseMemoryRequirementCount->GetOutputPointer(), VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr }); }

   //  OverrideGetDeviceImageSparseMemoryRequirementsKHR(GetDeviceTable(in_device->handle)->GetDeviceImageSparseMemoryRequirementsKHR, in_device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetDeviceImageSparseMemoryRequirementsKHR, *pSparseMemoryRequirementCount->GetOutputPointer(), &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pCallback->IsNull()) { pCallback->SetHandleLength(1); }
    DebugReportCallbackEXTInfo handle_info;
    pCallback->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateDebugReportCallbackEXT(GetInstanceTable(in_instance->handle)->CreateDebugReportCallbackEXT, returnValue, in_instance, pCreateInfo, pAllocator, pCallback);
    // CheckResult("vkCreateDebugReportCallbackEXT", returnValue, replay_result);

    AddHandle<DebugReportCallbackEXTInfo>(instance, pCallback->GetPointer(), pCallback->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDebugReportCallbackEXTInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    auto in_callback = GetObjectInfoTable().GetDebugReportCallbackEXTInfo(callback);

   //  OverrideDestroyDebugReportCallbackEXT(GetInstanceTable(in_instance->handle)->DestroyDebugReportCallbackEXT, in_instance, in_callback, pAllocator);
    RemoveHandle(callback, &VulkanObjectInfoTable::RemoveDebugReportCallbackEXTInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDebugReportMessageEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    StringDecoder*                              pLayerPrefix,
    StringDecoder*                              pMessage)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    uint64_t in_object = MapHandle(object, objectType);

   //  OverrideDebugReportMessageEXT(GetInstanceTable(in_instance->handle)->DebugReportMessageEXT, in_instance, flags, objectType, in_object, location, messageCode, pLayerPrefix, pMessage);
}

void VulkanFrameInspectorConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pTagInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideDebugMarkerSetObjectTagEXT(GetDeviceTable(in_device->handle)->DebugMarkerSetObjectTagEXT, returnValue, in_device, pTagInfo);
    // CheckResult("vkDebugMarkerSetObjectTagEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pNameInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideDebugMarkerSetObjectNameEXT(GetDeviceTable(in_device->handle)->DebugMarkerSetObjectNameEXT, returnValue, in_device, pNameInfo);
    // CheckResult("vkDebugMarkerSetObjectNameEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdDebugMarkerBeginEXT(GetDeviceTable(in_commandBuffer->handle)->CmdDebugMarkerBeginEXT, in_commandBuffer, pMarkerInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdDebugMarkerEndEXT(GetDeviceTable(in_commandBuffer->handle)->CmdDebugMarkerEndEXT, in_commandBuffer);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdDebugMarkerInsertEXT(GetDeviceTable(in_commandBuffer->handle)->CmdDebugMarkerInsertEXT, in_commandBuffer, pMarkerInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    MapHandles<BufferInfo>(pBuffers, bindingCount, &VulkanObjectInfoTable::GetBufferInfo);

   //  OverrideCmdBindTransformFeedbackBuffersEXT(GetDeviceTable(in_commandBuffer->handle)->CmdBindTransformFeedbackBuffersEXT, in_commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    MapHandles<BufferInfo>(pCounterBuffers, counterBufferCount, &VulkanObjectInfoTable::GetBufferInfo);

   //  OverrideCmdBeginTransformFeedbackEXT(GetDeviceTable(in_commandBuffer->handle)->CmdBeginTransformFeedbackEXT, in_commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

void VulkanFrameInspectorConsumer::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    MapHandles<BufferInfo>(pCounterBuffers, counterBufferCount, &VulkanObjectInfoTable::GetBufferInfo);

   //  OverrideCmdEndTransformFeedbackEXT(GetDeviceTable(in_commandBuffer->handle)->CmdEndTransformFeedbackEXT, in_commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideCmdBeginQueryIndexedEXT(GetDeviceTable(in_commandBuffer->handle)->CmdBeginQueryIndexedEXT, in_commandBuffer, in_queryPool, query, flags, index);
}

void VulkanFrameInspectorConsumer::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideCmdEndQueryIndexedEXT(GetDeviceTable(in_commandBuffer->handle)->CmdEndQueryIndexedEXT, in_commandBuffer, in_queryPool, query, index);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    format::HandleId                            counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_counterBuffer = GetObjectInfoTable().GetBufferInfo(counterBuffer);

   //  OverrideCmdDrawIndirectByteCountEXT(GetDeviceTable(in_commandBuffer->handle)->CmdDrawIndirectByteCountEXT, in_commandBuffer, instanceCount, firstInstance, in_counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

void VulkanFrameInspectorConsumer::Process_vkGetImageViewHandleNVX(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideGetImageViewHandleNVX(GetDeviceTable(in_device->handle)->GetImageViewHandleNVX, in_device, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetImageViewAddressNVX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_imageView = GetObjectInfoTable().GetImageViewInfo(imageView);
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX, nullptr });

//     VkResult replay_result = OverrideGetImageViewAddressNVX(GetDeviceTable(in_device->handle)->GetImageViewAddressNVX, returnValue, in_device, in_imageView, pProperties);
    // CheckResult("vkGetImageViewAddressNVX", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);
    auto in_countBuffer = GetObjectInfoTable().GetBufferInfo(countBuffer);

   //  OverrideCmdDrawIndirectCountAMD(GetDeviceTable(in_commandBuffer->handle)->CmdDrawIndirectCountAMD, in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);
    auto in_countBuffer = GetObjectInfoTable().GetBufferInfo(countBuffer);

   //  OverrideCmdDrawIndexedIndirectCountAMD(GetDeviceTable(in_commandBuffer->handle)->CmdDrawIndexedIndirectCountAMD, in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanFrameInspectorConsumer::Process_vkGetShaderInfoAMD(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    PointerDecoder<size_t>*                     pInfoSize,
    PointerDecoder<uint8_t>*                    pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipeline = GetObjectInfoTable().GetPipelineInfo(pipeline);
    pInfoSize->IsNull() ? nullptr : pInfoSize->AllocateOutputData(1, GetOutputArrayCount<size_t, PipelineInfo>("vkGetShaderInfoAMD", returnValue, pipeline, kPipelineArrayGetShaderInfoAMD, pInfoSize, pInfo, &VulkanObjectInfoTable::GetPipelineInfo));
    if (!pInfo->IsNull()) { pInfo->AllocateOutputData(*pInfoSize->GetOutputPointer()); }

//     VkResult replay_result = OverrideGetShaderInfoAMD(GetDeviceTable(in_device->handle)->GetShaderInfoAMD, returnValue, in_device, in_pipeline, shaderStage, infoType, pInfoSize, pInfo);
    // CheckResult("vkGetShaderInfoAMD", returnValue, replay_result);

    if (pInfo->IsNull()) { SetOutputArrayCount<PipelineInfo>(pipeline, kPipelineArrayGetShaderInfoAMD, *pInfoSize->GetOutputPointer(), &VulkanObjectInfoTable::GetPipelineInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateStreamDescriptorSurfaceGGP(GetInstanceTable(in_instance->handle)->CreateStreamDescriptorSurfaceGGP, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateStreamDescriptorSurfaceGGP", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
    StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>* pExternalImageFormatProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pExternalImageFormatProperties->IsNull() ? nullptr : pExternalImageFormatProperties->AllocateOutputData(1);

//     VkResult replay_result = OverrideGetPhysicalDeviceExternalImageFormatPropertiesNV(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceExternalImageFormatPropertiesNV, returnValue, in_physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
    // CheckResult("vkGetPhysicalDeviceExternalImageFormatPropertiesNV", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetMemoryWin32HandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_memory = GetObjectInfoTable().GetDeviceMemoryInfo(memory);
    HANDLE* out_pHandle = pHandle->IsNull() ? nullptr : reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

//     VkResult replay_result = OverrideGetMemoryWin32HandleNV(GetDeviceTable(in_device->handle)->GetMemoryWin32HandleNV, returnValue, in_device, in_memory, handleType, out_pHandle);
    // CheckResult("vkGetMemoryWin32HandleNV", returnValue, replay_result);

    // PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV, "vkGetMemoryWin32HandleNV");
}

void VulkanFrameInspectorConsumer::Process_vkCreateViSurfaceNN(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateViSurfaceNN(GetInstanceTable(in_instance->handle)->CreateViSurfaceNN, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateViSurfaceNN", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pConditionalRenderingBegin->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdBeginConditionalRenderingEXT(GetDeviceTable(in_commandBuffer->handle)->CmdBeginConditionalRenderingEXT, in_commandBuffer, pConditionalRenderingBegin);
}

void VulkanFrameInspectorConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdEndConditionalRenderingEXT(GetDeviceTable(in_commandBuffer->handle)->CmdEndConditionalRenderingEXT, in_commandBuffer);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetViewportWScalingNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetViewportWScalingNV, in_commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}

void VulkanFrameInspectorConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_display = GetObjectInfoTable().GetDisplayKHRInfo(display);

//     VkResult replay_result = OverrideReleaseDisplayEXT(GetInstanceTable(in_physicalDevice->handle)->ReleaseDisplayEXT, returnValue, in_physicalDevice, in_display);
    // CheckResult("vkReleaseDisplayEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkAcquireXlibDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    format::HandleId                            display)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    // Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(dpy, format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT, "vkAcquireXlibDisplayEXT"));
    auto in_display = GetObjectInfoTable().GetDisplayKHRInfo(display);

//     VkResult replay_result = OverrideAcquireXlibDisplayEXT(GetInstanceTable(in_physicalDevice->handle)->AcquireXlibDisplayEXT, returnValue, in_physicalDevice, in_dpy, in_display);
    // CheckResult("vkAcquireXlibDisplayEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetRandROutputDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    size_t                                      rrOutput,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    // Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(dpy, format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT, "vkGetRandROutputDisplayEXT"));
    if (!pDisplay->IsNull()) { pDisplay->SetHandleLength(1); }
    DisplayKHRInfo handle_info;
    pDisplay->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideGetRandROutputDisplayEXT(GetInstanceTable(in_physicalDevice->handle)->GetRandROutputDisplayEXT, returnValue, in_physicalDevice, in_dpy, rrOutput, pDisplay);
    // CheckResult("vkGetRandROutputDisplayEXT", returnValue, replay_result);

    AddHandle<DisplayKHRInfo>(physicalDevice, pDisplay->GetPointer(), pDisplay->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDisplayKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_surface = GetObjectInfoTable().GetSurfaceKHRInfo(surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }
    pSurfaceCapabilities->IsNull() ? nullptr : pSurfaceCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT, nullptr });

//     VkResult replay_result = OverrideGetPhysicalDeviceSurfaceCapabilities2EXT(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceCapabilities2EXT, returnValue, in_physicalDevice, in_surface, pSurfaceCapabilities);
    // CheckResult("vkGetPhysicalDeviceSurfaceCapabilities2EXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkDisplayPowerControlEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_display = GetObjectInfoTable().GetDisplayKHRInfo(display);

//     VkResult replay_result = OverrideDisplayPowerControlEXT(GetDeviceTable(in_device->handle)->DisplayPowerControlEXT, returnValue, in_device, in_display, pDisplayPowerInfo);
    // CheckResult("vkDisplayPowerControlEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkRegisterDeviceEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pFence->IsNull()) { pFence->SetHandleLength(1); }
    FenceInfo handle_info;
    pFence->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideRegisterDeviceEventEXT(GetDeviceTable(in_device->handle)->RegisterDeviceEventEXT, returnValue, in_device, pDeviceEventInfo, pAllocator, pFence);
    // CheckResult("vkRegisterDeviceEventEXT", returnValue, replay_result);

    AddHandle<FenceInfo>(device, pFence->GetPointer(), pFence->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddFenceInfo);
}

void VulkanFrameInspectorConsumer::Process_vkRegisterDisplayEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_display = GetObjectInfoTable().GetDisplayKHRInfo(display);
    if (!pFence->IsNull()) { pFence->SetHandleLength(1); }
    FenceInfo handle_info;
    pFence->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideRegisterDisplayEventEXT(GetDeviceTable(in_device->handle)->RegisterDisplayEventEXT, returnValue, in_device, in_display, pDisplayEventInfo, pAllocator, pFence);
    // CheckResult("vkRegisterDisplayEventEXT", returnValue, replay_result);

    AddHandle<FenceInfo>(device, pFence->GetPointer(), pFence->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddFenceInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetSwapchainCounterEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    PointerDecoder<uint64_t>*                   pCounterValue)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetSwapchainKHRInfo(swapchain);
    pCounterValue->IsNull() ? nullptr : pCounterValue->AllocateOutputData(1, static_cast<uint64_t>(0));

//     VkResult replay_result = OverrideGetSwapchainCounterEXT(GetDeviceTable(in_device->handle)->GetSwapchainCounterEXT, returnValue, in_device, in_swapchain, counter, pCounterValue);
    // CheckResult("vkGetSwapchainCounterEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetSwapchainKHRInfo(swapchain);
    pDisplayTimingProperties->IsNull() ? nullptr : pDisplayTimingProperties->AllocateOutputData(1);

//     VkResult replay_result = OverrideGetRefreshCycleDurationGOOGLE(GetDeviceTable(in_device->handle)->GetRefreshCycleDurationGOOGLE, returnValue, in_device, in_swapchain, pDisplayTimingProperties);
    // CheckResult("vkGetRefreshCycleDurationGOOGLE", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pPresentationTimingCount,
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetSwapchainKHRInfo(swapchain);
    pPresentationTimingCount->IsNull() ? nullptr : pPresentationTimingCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, SwapchainKHRInfo>("vkGetPastPresentationTimingGOOGLE", returnValue, swapchain, kSwapchainKHRArrayGetPastPresentationTimingGOOGLE, pPresentationTimingCount, pPresentationTimings, &VulkanObjectInfoTable::GetSwapchainKHRInfo));
    if (!pPresentationTimings->IsNull()) { pPresentationTimings->AllocateOutputData(*pPresentationTimingCount->GetOutputPointer()); }

//     VkResult replay_result = OverrideGetPastPresentationTimingGOOGLE(GetDeviceTable(in_device->handle)->GetPastPresentationTimingGOOGLE, returnValue, in_device, in_swapchain, pPresentationTimingCount, pPresentationTimings);
    // CheckResult("vkGetPastPresentationTimingGOOGLE", returnValue, replay_result);

    if (pPresentationTimings->IsNull()) { SetOutputArrayCount<SwapchainKHRInfo>(swapchain, kSwapchainKHRArrayGetPastPresentationTimingGOOGLE, *pPresentationTimingCount->GetOutputPointer(), &VulkanObjectInfoTable::GetSwapchainKHRInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDiscardRectangleEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetDiscardRectangleEXT, in_commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}

void VulkanFrameInspectorConsumer::Process_vkSetHdrMetadataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains,
    StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    MapHandles<SwapchainKHRInfo>(pSwapchains, swapchainCount, &VulkanObjectInfoTable::GetSwapchainKHRInfo);

   //  OverrideSetHdrMetadataEXT(GetDeviceTable(in_device->handle)->SetHdrMetadataEXT, in_device, swapchainCount, pSwapchains, pMetadata);
}

void VulkanFrameInspectorConsumer::Process_vkCreateIOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateIOSSurfaceMVK(GetInstanceTable(in_instance->handle)->CreateIOSSurfaceMVK, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateIOSSurfaceMVK", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateMacOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateMacOSSurfaceMVK(GetInstanceTable(in_instance->handle)->CreateMacOSSurfaceMVK, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateMacOSSurfaceMVK", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pNameInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideSetDebugUtilsObjectNameEXT(GetDeviceTable(in_device->handle)->SetDebugUtilsObjectNameEXT, returnValue, in_device, pNameInfo);
    // CheckResult("vkSetDebugUtilsObjectNameEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pTagInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideSetDebugUtilsObjectTagEXT(GetDeviceTable(in_device->handle)->SetDebugUtilsObjectTagEXT, returnValue, in_device, pTagInfo);
    // CheckResult("vkSetDebugUtilsObjectTagEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

   //  OverrideQueueBeginDebugUtilsLabelEXT(GetDeviceTable(in_queue->handle)->QueueBeginDebugUtilsLabelEXT, in_queue, pLabelInfo);
}

void VulkanFrameInspectorConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

   //  OverrideQueueEndDebugUtilsLabelEXT(GetDeviceTable(in_queue->handle)->QueueEndDebugUtilsLabelEXT, in_queue);
}

void VulkanFrameInspectorConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

   //  OverrideQueueInsertDebugUtilsLabelEXT(GetDeviceTable(in_queue->handle)->QueueInsertDebugUtilsLabelEXT, in_queue, pLabelInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdBeginDebugUtilsLabelEXT(GetDeviceTable(in_commandBuffer->handle)->CmdBeginDebugUtilsLabelEXT, in_commandBuffer, pLabelInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdEndDebugUtilsLabelEXT(GetDeviceTable(in_commandBuffer->handle)->CmdEndDebugUtilsLabelEXT, in_commandBuffer);
}

void VulkanFrameInspectorConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdInsertDebugUtilsLabelEXT(GetDeviceTable(in_commandBuffer->handle)->CmdInsertDebugUtilsLabelEXT, in_commandBuffer, pLabelInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pMessenger->IsNull()) { pMessenger->SetHandleLength(1); }
    DebugUtilsMessengerEXTInfo handle_info;
    pMessenger->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateDebugUtilsMessengerEXT(GetInstanceTable(in_instance->handle)->CreateDebugUtilsMessengerEXT, returnValue, in_instance, pCreateInfo, pAllocator, pMessenger);
    // CheckResult("vkCreateDebugUtilsMessengerEXT", returnValue, replay_result);

    AddHandle<DebugUtilsMessengerEXTInfo>(instance, pMessenger->GetPointer(), pMessenger->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDebugUtilsMessengerEXTInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    auto in_messenger = GetObjectInfoTable().GetDebugUtilsMessengerEXTInfo(messenger);

   //  OverrideDestroyDebugUtilsMessengerEXT(GetInstanceTable(in_instance->handle)->DestroyDebugUtilsMessengerEXT, in_instance, in_messenger, pAllocator);
    RemoveHandle(messenger, &VulkanObjectInfoTable::RemoveDebugUtilsMessengerEXTInfo);
}

void VulkanFrameInspectorConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);

   //  OverrideSubmitDebugUtilsMessageEXT(GetInstanceTable(in_instance->handle)->SubmitDebugUtilsMessageEXT, in_instance, messageSeverity, messageTypes, pCallbackData);
}

void VulkanFrameInspectorConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    // const struct AHardwareBuffer* in_buffer = static_cast<const struct AHardwareBuffer*>(PreProcessExternalObject(buffer, format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID, "vkGetAndroidHardwareBufferPropertiesANDROID"));
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID, nullptr });

//     VkResult replay_result = OverrideGetAndroidHardwareBufferPropertiesANDROID(GetDeviceTable(in_device->handle)->GetAndroidHardwareBufferPropertiesANDROID, returnValue, in_device, in_buffer, pProperties);
    // CheckResult("vkGetAndroidHardwareBufferPropertiesANDROID", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    struct AHardwareBuffer** out_pBuffer = pBuffer->IsNull() ? nullptr : reinterpret_cast<struct AHardwareBuffer**>(pBuffer->AllocateOutputData(1));

//     VkResult replay_result = OverrideGetMemoryAndroidHardwareBufferANDROID(GetDeviceTable(in_device->handle)->GetMemoryAndroidHardwareBufferANDROID, returnValue, in_device, pInfo, out_pBuffer);
    // CheckResult("vkGetMemoryAndroidHardwareBufferANDROID", returnValue, replay_result);

    // PostProcessExternalObject(replay_result, (*pBuffer->GetPointer()), static_cast<void*>(*out_pBuffer), format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID, "vkGetMemoryAndroidHardwareBufferANDROID");
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetSampleLocationsEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetSampleLocationsEXT, in_commandBuffer, pSampleLocationsInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pMultisampleProperties->IsNull() ? nullptr : pMultisampleProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT, nullptr });

   //  OverrideGetPhysicalDeviceMultisamplePropertiesEXT(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceMultisamplePropertiesEXT, in_physicalDevice, samples, pMultisampleProperties);
}

void VulkanFrameInspectorConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_image = GetObjectInfoTable().GetImageInfo(image);
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT, nullptr });

//     VkResult replay_result = OverrideGetImageDrmFormatModifierPropertiesEXT(GetDeviceTable(in_device->handle)->GetImageDrmFormatModifierPropertiesEXT, returnValue, in_device, in_image, pProperties);
    // CheckResult("vkGetImageDrmFormatModifierPropertiesEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pValidationCache->IsNull()) { pValidationCache->SetHandleLength(1); }
    ValidationCacheEXTInfo handle_info;
    pValidationCache->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateValidationCacheEXT(GetDeviceTable(in_device->handle)->CreateValidationCacheEXT, returnValue, in_device, pCreateInfo, pAllocator, pValidationCache);
    // CheckResult("vkCreateValidationCacheEXT", returnValue, replay_result);

    AddHandle<ValidationCacheEXTInfo>(device, pValidationCache->GetPointer(), pValidationCache->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddValidationCacheEXTInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_validationCache = GetObjectInfoTable().GetValidationCacheEXTInfo(validationCache);

   //  OverrideDestroyValidationCacheEXT(GetDeviceTable(in_device->handle)->DestroyValidationCacheEXT, in_device, in_validationCache, pAllocator);
    RemoveHandle(validationCache, &VulkanObjectInfoTable::RemoveValidationCacheEXTInfo);
}

void VulkanFrameInspectorConsumer::Process_vkMergeValidationCachesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_dstCache = GetObjectInfoTable().GetValidationCacheEXTInfo(dstCache);
    MapHandles<ValidationCacheEXTInfo>(pSrcCaches, srcCacheCount, &VulkanObjectInfoTable::GetValidationCacheEXTInfo);

//     VkResult replay_result = OverrideMergeValidationCachesEXT(GetDeviceTable(in_device->handle)->MergeValidationCachesEXT, returnValue, in_device, in_dstCache, srcCacheCount, pSrcCaches);
    // CheckResult("vkMergeValidationCachesEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetValidationCacheDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_validationCache = GetObjectInfoTable().GetValidationCacheEXTInfo(validationCache);
    pDataSize->IsNull() ? nullptr : pDataSize->AllocateOutputData(1, GetOutputArrayCount<size_t, ValidationCacheEXTInfo>("vkGetValidationCacheDataEXT", returnValue, validationCache, kValidationCacheEXTArrayGetValidationCacheDataEXT, pDataSize, pData, &VulkanObjectInfoTable::GetValidationCacheEXTInfo));
    if (!pData->IsNull()) { pData->AllocateOutputData(*pDataSize->GetOutputPointer()); }

//     VkResult replay_result = OverrideGetValidationCacheDataEXT(GetDeviceTable(in_device->handle)->GetValidationCacheDataEXT, returnValue, in_device, in_validationCache, pDataSize, pData);
    // CheckResult("vkGetValidationCacheDataEXT", returnValue, replay_result);

    if (pData->IsNull()) { SetOutputArrayCount<ValidationCacheEXTInfo>(validationCache, kValidationCacheEXTArrayGetValidationCacheDataEXT, *pDataSize->GetOutputPointer(), &VulkanObjectInfoTable::GetValidationCacheEXTInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_imageView = GetObjectInfoTable().GetImageViewInfo(imageView);

   //  OverrideCmdBindShadingRateImageNV(GetDeviceTable(in_commandBuffer->handle)->CmdBindShadingRateImageNV, in_commandBuffer, in_imageView, imageLayout);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetViewportShadingRatePaletteNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetViewportShadingRatePaletteNV, in_commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetCoarseSampleOrderNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetCoarseSampleOrderNV, in_commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}

void VulkanFrameInspectorConsumer::Process_vkCreateAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pAccelerationStructure->IsNull()) { pAccelerationStructure->SetHandleLength(1); }
    AccelerationStructureNVInfo handle_info;
    pAccelerationStructure->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateAccelerationStructureNV(GetDeviceTable(in_device->handle)->CreateAccelerationStructureNV, returnValue, in_device, pCreateInfo, pAllocator, pAccelerationStructure);
    // CheckResult("vkCreateAccelerationStructureNV", returnValue, replay_result);

    AddHandle<AccelerationStructureNVInfo>(device, pAccelerationStructure->GetPointer(), pAccelerationStructure->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddAccelerationStructureNVInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_accelerationStructure = GetObjectInfoTable().GetAccelerationStructureNVInfo(accelerationStructure);

   //  OverrideDestroyAccelerationStructureNV(GetDeviceTable(in_device->handle)->DestroyAccelerationStructureNV, in_device, in_accelerationStructure, pAllocator);
    RemoveHandle(accelerationStructure, &VulkanObjectInfoTable::RemoveAccelerationStructureNVInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1);

   //  OverrideGetAccelerationStructureMemoryRequirementsNV(GetDeviceTable(in_device->handle)->GetAccelerationStructureMemoryRequirementsNV, in_device, pInfo, pMemoryRequirements);
}

void VulkanFrameInspectorConsumer::Process_vkBindAccelerationStructureMemoryNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

//     VkResult replay_result = OverrideBindAccelerationStructureMemoryNV(GetDeviceTable(in_device->handle)->BindAccelerationStructureMemoryNV, returnValue, in_device, bindInfoCount, pBindInfos);
    // CheckResult("vkBindAccelerationStructureMemoryNV", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV>* pInfo,
    format::HandleId                            instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    format::HandleId                            dst,
    format::HandleId                            src,
    format::HandleId                            scratch,
    VkDeviceSize                                scratchOffset)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    auto in_instanceData = GetObjectInfoTable().GetBufferInfo(instanceData);
    auto in_dst = GetObjectInfoTable().GetAccelerationStructureNVInfo(dst);
    auto in_src = GetObjectInfoTable().GetAccelerationStructureNVInfo(src);
    auto in_scratch = GetObjectInfoTable().GetBufferInfo(scratch);

   //  OverrideCmdBuildAccelerationStructureNV(GetDeviceTable(in_commandBuffer->handle)->CmdBuildAccelerationStructureNV, in_commandBuffer, pInfo, in_instanceData, instanceOffset, update, in_dst, in_src, in_scratch, scratchOffset);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_dst = GetObjectInfoTable().GetAccelerationStructureNVInfo(dst);
    auto in_src = GetObjectInfoTable().GetAccelerationStructureNVInfo(src);

   //  OverrideCmdCopyAccelerationStructureNV(GetDeviceTable(in_commandBuffer->handle)->CmdCopyAccelerationStructureNV, in_commandBuffer, in_dst, in_src, mode);
}

void VulkanFrameInspectorConsumer::Process_vkCmdTraceRaysNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            raygenShaderBindingTableBuffer,
    VkDeviceSize                                raygenShaderBindingOffset,
    format::HandleId                            missShaderBindingTableBuffer,
    VkDeviceSize                                missShaderBindingOffset,
    VkDeviceSize                                missShaderBindingStride,
    format::HandleId                            hitShaderBindingTableBuffer,
    VkDeviceSize                                hitShaderBindingOffset,
    VkDeviceSize                                hitShaderBindingStride,
    format::HandleId                            callableShaderBindingTableBuffer,
    VkDeviceSize                                callableShaderBindingOffset,
    VkDeviceSize                                callableShaderBindingStride,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_raygenShaderBindingTableBuffer = GetObjectInfoTable().GetBufferInfo(raygenShaderBindingTableBuffer);
    auto in_missShaderBindingTableBuffer = GetObjectInfoTable().GetBufferInfo(missShaderBindingTableBuffer);
    auto in_hitShaderBindingTableBuffer = GetObjectInfoTable().GetBufferInfo(hitShaderBindingTableBuffer);
    auto in_callableShaderBindingTableBuffer = GetObjectInfoTable().GetBufferInfo(callableShaderBindingTableBuffer);

   //  OverrideCmdTraceRaysNV(GetDeviceTable(in_commandBuffer->handle)->CmdTraceRaysNV, in_commandBuffer, in_raygenShaderBindingTableBuffer, raygenShaderBindingOffset, in_missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, in_hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, in_callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}

void VulkanFrameInspectorConsumer::Process_vkCreateRayTracingPipelinesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipelineCache = GetObjectInfoTable().GetPipelineCacheInfo(pipelineCache);

    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    if (!pPipelines->IsNull()) { pPipelines->SetHandleLength(createInfoCount); }
    std::vector<PipelineInfo> handle_info(createInfoCount);
    for (size_t i = 0; i < createInfoCount; ++i) { pPipelines->SetConsumerData(i, &handle_info[i]); }

//     VkResult replay_result = OverrideCreateRayTracingPipelinesNV(GetDeviceTable(in_device->handle)->CreateRayTracingPipelinesNV, returnValue, in_device, in_pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    // CheckResult("vkCreateRayTracingPipelinesNV", returnValue, replay_result);

    AddHandles<PipelineInfo>(device, pPipelines->GetPointer(), pPipelines->GetLength(), pPipelines->GetHandlePointer(), createInfoCount, std::move(handle_info), &VulkanObjectInfoTable::AddPipelineInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetRayTracingShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipeline = GetObjectInfoTable().GetPipelineInfo(pipeline);
    if (!pData->IsNull()) { pData->AllocateOutputData(dataSize); }

//     VkResult replay_result = OverrideGetRayTracingShaderGroupHandlesKHR(GetDeviceTable(in_device->handle)->GetRayTracingShaderGroupHandlesKHR, returnValue, in_device, in_pipeline, firstGroup, groupCount, dataSize, pData);
    // CheckResult("vkGetRayTracingShaderGroupHandlesKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetRayTracingShaderGroupHandlesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipeline = GetObjectInfoTable().GetPipelineInfo(pipeline);
    if (!pData->IsNull()) { pData->AllocateOutputData(dataSize); }

//     VkResult replay_result = OverrideGetRayTracingShaderGroupHandlesNV(GetDeviceTable(in_device->handle)->GetRayTracingShaderGroupHandlesNV, returnValue, in_device, in_pipeline, firstGroup, groupCount, dataSize, pData);
    // CheckResult("vkGetRayTracingShaderGroupHandlesNV", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetAccelerationStructureHandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_accelerationStructure = GetObjectInfoTable().GetAccelerationStructureNVInfo(accelerationStructure);
    if (!pData->IsNull()) { pData->AllocateOutputData(dataSize); }

//     VkResult replay_result = OverrideGetAccelerationStructureHandleNV(GetDeviceTable(in_device->handle)->GetAccelerationStructureHandleNV, returnValue, in_device, in_accelerationStructure, dataSize, pData);
    // CheckResult("vkGetAccelerationStructureHandleNV", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    MapHandles<AccelerationStructureNVInfo>(pAccelerationStructures, accelerationStructureCount, &VulkanObjectInfoTable::GetAccelerationStructureNVInfo);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideCmdWriteAccelerationStructuresPropertiesNV(GetDeviceTable(in_commandBuffer->handle)->CmdWriteAccelerationStructuresPropertiesNV, in_commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, in_queryPool, firstQuery);
}

void VulkanFrameInspectorConsumer::Process_vkCompileDeferredNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    shader)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipeline = GetObjectInfoTable().GetPipelineInfo(pipeline);

//     VkResult replay_result = OverrideCompileDeferredNV(GetDeviceTable(in_device->handle)->CompileDeferredNV, returnValue, in_device, in_pipeline, shader);
    // CheckResult("vkCompileDeferredNV", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    // const void* in_pHostPointer = PreProcessExternalObject(pHostPointer, format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT, "vkGetMemoryHostPointerPropertiesEXT");
    pMemoryHostPointerProperties->IsNull() ? nullptr : pMemoryHostPointerProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT, nullptr });

//     VkResult replay_result = OverrideGetMemoryHostPointerPropertiesEXT(GetDeviceTable(in_device->handle)->GetMemoryHostPointerPropertiesEXT, returnValue, in_device, handleType, in_pHostPointer, pMemoryHostPointerProperties);
    // CheckResult("vkGetMemoryHostPointerPropertiesEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_dstBuffer = GetObjectInfoTable().GetBufferInfo(dstBuffer);

   //  OverrideCmdWriteBufferMarkerAMD(GetDeviceTable(in_commandBuffer->handle)->CmdWriteBufferMarkerAMD, in_commandBuffer, pipelineStage, in_dstBuffer, dstOffset, marker);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainEXT>*            pTimeDomains)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pTimeDomainCount->IsNull() ? nullptr : pTimeDomainCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsEXT, pTimeDomainCount, pTimeDomains, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (pTimeDomains->IsNull()) { pTimeDomains->AllocateOutputData(*pTimeDomainCount->GetOutputPointer()); }

//     VkResult replay_result = OverrideGetPhysicalDeviceCalibrateableTimeDomainsEXT(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceCalibrateableTimeDomainsEXT, returnValue, in_physicalDevice, pTimeDomainCount, pTimeDomains);
    // CheckResult("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", returnValue, replay_result);

    if (pTimeDomains->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsEXT, *pTimeDomainCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetCalibratedTimestampsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (pTimestamps->IsNull()) { pTimestamps->AllocateOutputData(timestampCount); }
    pMaxDeviation->IsNull() ? nullptr : pMaxDeviation->AllocateOutputData(1, static_cast<uint64_t>(0));

//     VkResult replay_result = OverrideGetCalibratedTimestampsEXT(GetDeviceTable(in_device->handle)->GetCalibratedTimestampsEXT, returnValue, in_device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    // CheckResult("vkGetCalibratedTimestampsEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdDrawMeshTasksNV(GetDeviceTable(in_commandBuffer->handle)->CmdDrawMeshTasksNV, in_commandBuffer, taskCount, firstTask);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);

   //  OverrideCmdDrawMeshTasksIndirectNV(GetDeviceTable(in_commandBuffer->handle)->CmdDrawMeshTasksIndirectNV, in_commandBuffer, in_buffer, offset, drawCount, stride);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);
    auto in_countBuffer = GetObjectInfoTable().GetBufferInfo(countBuffer);

   //  OverrideCmdDrawMeshTasksIndirectCountNV(GetDeviceTable(in_commandBuffer->handle)->CmdDrawMeshTasksIndirectCountNV, in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetExclusiveScissorNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetExclusiveScissorNV, in_commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    // const void* in_pCheckpointMarker = PreProcessExternalObject(pCheckpointMarker, format::ApiCallId::ApiCall_vkCmdSetCheckpointNV, "vkCmdSetCheckpointNV");

   //  OverrideCmdSetCheckpointNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetCheckpointNV, in_commandBuffer, in_pCheckpointMarker);
}

void VulkanFrameInspectorConsumer::Process_vkGetQueueCheckpointDataNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);
    pCheckpointDataCount->IsNull() ? nullptr : pCheckpointDataCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, QueueInfo>("vkGetQueueCheckpointDataNV", VK_SUCCESS, queue, kQueueArrayGetQueueCheckpointDataNV, pCheckpointDataCount, pCheckpointData, &VulkanObjectInfoTable::GetQueueInfo));
    if (!pCheckpointData->IsNull()) { pCheckpointData->AllocateOutputData(*pCheckpointDataCount->GetOutputPointer(), VkCheckpointDataNV{ VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV, nullptr }); }

   //  OverrideGetQueueCheckpointDataNV(GetDeviceTable(in_queue->handle)->GetQueueCheckpointDataNV, in_queue, pCheckpointDataCount, pCheckpointData);

    if (pCheckpointData->IsNull()) { SetOutputArrayCount<QueueInfo>(queue, kQueueArrayGetQueueCheckpointDataNV, *pCheckpointDataCount->GetOutputPointer(), &VulkanObjectInfoTable::GetQueueInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

//     VkResult replay_result = OverrideInitializePerformanceApiINTEL(GetDeviceTable(in_device->handle)->InitializePerformanceApiINTEL, returnValue, in_device, pInitializeInfo);
    // CheckResult("vkInitializePerformanceApiINTEL", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

   //  OverrideUninitializePerformanceApiINTEL(GetDeviceTable(in_device->handle)->UninitializePerformanceApiINTEL, in_device);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

//     VkResult replay_result = OverrideCmdSetPerformanceMarkerINTEL(GetDeviceTable(in_commandBuffer->handle)->CmdSetPerformanceMarkerINTEL, returnValue, in_commandBuffer, pMarkerInfo);
    // CheckResult("vkCmdSetPerformanceMarkerINTEL", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

//     VkResult replay_result = OverrideCmdSetPerformanceStreamMarkerINTEL(GetDeviceTable(in_commandBuffer->handle)->CmdSetPerformanceStreamMarkerINTEL, returnValue, in_commandBuffer, pMarkerInfo);
    // CheckResult("vkCmdSetPerformanceStreamMarkerINTEL", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

//     VkResult replay_result = OverrideCmdSetPerformanceOverrideINTEL(GetDeviceTable(in_commandBuffer->handle)->CmdSetPerformanceOverrideINTEL, returnValue, in_commandBuffer, pOverrideInfo);
    // CheckResult("vkCmdSetPerformanceOverrideINTEL", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
    HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pConfiguration->IsNull()) { pConfiguration->SetHandleLength(1); }
    PerformanceConfigurationINTELInfo handle_info;
    pConfiguration->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideAcquirePerformanceConfigurationINTEL(GetDeviceTable(in_device->handle)->AcquirePerformanceConfigurationINTEL, returnValue, in_device, pAcquireInfo, pConfiguration);
    // CheckResult("vkAcquirePerformanceConfigurationINTEL", returnValue, replay_result);

    AddHandle<PerformanceConfigurationINTELInfo>(device, pConfiguration->GetPointer(), pConfiguration->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddPerformanceConfigurationINTELInfo);
}

void VulkanFrameInspectorConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_configuration = GetObjectInfoTable().GetPerformanceConfigurationINTELInfo(configuration);

//     VkResult replay_result = OverrideReleasePerformanceConfigurationINTEL(GetDeviceTable(in_device->handle)->ReleasePerformanceConfigurationINTEL, returnValue, in_device, in_configuration);
    // CheckResult("vkReleasePerformanceConfigurationINTEL", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);
    auto in_configuration = GetObjectInfoTable().GetPerformanceConfigurationINTELInfo(configuration);

//     VkResult replay_result = OverrideQueueSetPerformanceConfigurationINTEL(GetDeviceTable(in_queue->handle)->QueueSetPerformanceConfigurationINTEL, returnValue, in_queue, in_configuration);
    // CheckResult("vkQueueSetPerformanceConfigurationINTEL", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPerformanceParameterINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkPerformanceParameterTypeINTEL             parameter,
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    pValue->IsNull() ? nullptr : pValue->AllocateOutputData(1);

//     VkResult replay_result = OverrideGetPerformanceParameterINTEL(GetDeviceTable(in_device->handle)->GetPerformanceParameterINTEL, returnValue, in_device, parameter, pValue);
    // CheckResult("vkGetPerformanceParameterINTEL", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapChain = GetObjectInfoTable().GetSwapchainKHRInfo(swapChain);

   //  OverrideSetLocalDimmingAMD(GetDeviceTable(in_device->handle)->SetLocalDimmingAMD, in_device, in_swapChain, localDimmingEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateImagePipeSurfaceFUCHSIA(GetInstanceTable(in_instance->handle)->CreateImagePipeSurfaceFUCHSIA, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateImagePipeSurfaceFUCHSIA", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateMetalSurfaceEXT(GetInstanceTable(in_instance->handle)->CreateMetalSurfaceEXT, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateMetalSurfaceEXT", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideGetBufferDeviceAddressEXT(GetDeviceTable(in_device->handle)->GetBufferDeviceAddressEXT, in_device, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pToolCount->IsNull() ? nullptr : pToolCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceToolPropertiesEXT", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolPropertiesEXT, pToolCount, pToolProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pToolProperties->IsNull()) { pToolProperties->AllocateOutputData(*pToolCount->GetOutputPointer(), VkPhysicalDeviceToolProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES, nullptr }); }

//     VkResult replay_result = OverrideGetPhysicalDeviceToolPropertiesEXT(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceToolPropertiesEXT, returnValue, in_physicalDevice, pToolCount, pToolProperties);
    // CheckResult("vkGetPhysicalDeviceToolPropertiesEXT", returnValue, replay_result);

    if (pToolProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolPropertiesEXT, *pToolCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesNV, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pProperties->IsNull()) { pProperties->AllocateOutputData(*pPropertyCount->GetOutputPointer(), VkCooperativeMatrixPropertiesNV{ VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV, nullptr }); }

//     VkResult replay_result = OverrideGetPhysicalDeviceCooperativeMatrixPropertiesNV(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceCooperativeMatrixPropertiesNV, returnValue, in_physicalDevice, pPropertyCount, pProperties);
    // CheckResult("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesNV, *pPropertyCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pCombinationCount,
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pCombinationCount->IsNull() ? nullptr : pCombinationCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV, pCombinationCount, pCombinations, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pCombinations->IsNull()) { pCombinations->AllocateOutputData(*pCombinationCount->GetOutputPointer(), VkFramebufferMixedSamplesCombinationNV{ VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV, nullptr }); }

//     VkResult replay_result = OverrideGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV, returnValue, in_physicalDevice, pCombinationCount, pCombinations);
    // CheckResult("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", returnValue, replay_result);

    if (pCombinations->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV, *pCombinationCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);

    if (pSurfaceInfo->GetPointer()->surface == VK_NULL_HANDLE) { return; }
    MapStructHandles(pSurfaceInfo->GetMetaStructPointer(), GetObjectInfoTable());
    auto in_pSurfaceInfo_meta = pSurfaceInfo->GetMetaStructPointer();
    if (GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    pPresentModeCount->IsNull() ? nullptr : pPresentModeCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceSurfacePresentModes2EXT", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfacePresentModes2EXT, pPresentModeCount, pPresentModes, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (pPresentModes->IsNull()) { pPresentModes->AllocateOutputData(*pPresentModeCount->GetOutputPointer()); }

//     VkResult replay_result = OverrideGetPhysicalDeviceSurfacePresentModes2EXT(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfacePresentModes2EXT, returnValue, in_physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
    // CheckResult("vkGetPhysicalDeviceSurfacePresentModes2EXT", returnValue, replay_result);

    if (pPresentModes->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfacePresentModes2EXT, *pPresentModeCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetSwapchainKHRInfo(swapchain);

//     VkResult replay_result = OverrideAcquireFullScreenExclusiveModeEXT(GetDeviceTable(in_device->handle)->AcquireFullScreenExclusiveModeEXT, returnValue, in_device, in_swapchain);
    // CheckResult("vkAcquireFullScreenExclusiveModeEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetSwapchainKHRInfo(swapchain);

//     VkResult replay_result = OverrideReleaseFullScreenExclusiveModeEXT(GetDeviceTable(in_device->handle)->ReleaseFullScreenExclusiveModeEXT, returnValue, in_device, in_swapchain);
    // CheckResult("vkReleaseFullScreenExclusiveModeEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    if (pSurfaceInfo->GetPointer()->surface == VK_NULL_HANDLE) { return; }
    MapStructHandles(pSurfaceInfo->GetMetaStructPointer(), GetObjectInfoTable());
    auto in_pSurfaceInfo_meta = pSurfaceInfo->GetMetaStructPointer();
    if (GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    pModes->IsNull() ? nullptr : pModes->AllocateOutputData(1, static_cast<VkDeviceGroupPresentModeFlagsKHR>(0));

//     VkResult replay_result = OverrideGetDeviceGroupSurfacePresentModes2EXT(GetDeviceTable(in_device->handle)->GetDeviceGroupSurfacePresentModes2EXT, returnValue, in_device, pSurfaceInfo, pModes);
    // CheckResult("vkGetDeviceGroupSurfacePresentModes2EXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateHeadlessSurfaceEXT(GetInstanceTable(in_instance->handle)->CreateHeadlessSurfaceEXT, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateHeadlessSurfaceEXT", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetLineStippleEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetLineStippleEXT, in_commandBuffer, lineStippleFactor, lineStipplePattern);
}

void VulkanFrameInspectorConsumer::Process_vkResetQueryPoolEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideResetQueryPoolEXT(GetDeviceTable(in_device->handle)->ResetQueryPoolEXT, in_device, in_queryPool, firstQuery, queryCount);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetCullModeEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetCullModeEXT, in_commandBuffer, cullMode);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetFrontFaceEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetFrontFaceEXT, in_commandBuffer, frontFace);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetPrimitiveTopologyEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetPrimitiveTopologyEXT, in_commandBuffer, primitiveTopology);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetViewportWithCountEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetViewportWithCountEXT, in_commandBuffer, viewportCount, pViewports);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetScissorWithCountEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetScissorWithCountEXT, in_commandBuffer, scissorCount, pScissors);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    MapHandles<BufferInfo>(pBuffers, bindingCount, &VulkanObjectInfoTable::GetBufferInfo);

   //  OverrideCmdBindVertexBuffers2EXT(GetDeviceTable(in_commandBuffer->handle)->CmdBindVertexBuffers2EXT, in_commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthTestEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthTestEnableEXT, in_commandBuffer, depthTestEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthWriteEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthWriteEnableEXT, in_commandBuffer, depthWriteEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthCompareOpEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthCompareOpEXT, in_commandBuffer, depthCompareOp);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthBoundsTestEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthBoundsTestEnableEXT, in_commandBuffer, depthBoundsTestEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetStencilTestEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetStencilTestEnableEXT, in_commandBuffer, stencilTestEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetStencilOpEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetStencilOpEXT, in_commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void VulkanFrameInspectorConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

   //  OverrideGetGeneratedCommandsMemoryRequirementsNV(GetDeviceTable(in_device->handle)->GetGeneratedCommandsMemoryRequirementsNV, in_device, pInfo, pMemoryRequirements);
}

void VulkanFrameInspectorConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pGeneratedCommandsInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdPreprocessGeneratedCommandsNV(GetDeviceTable(in_commandBuffer->handle)->CmdPreprocessGeneratedCommandsNV, in_commandBuffer, pGeneratedCommandsInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pGeneratedCommandsInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdExecuteGeneratedCommandsNV(GetDeviceTable(in_commandBuffer->handle)->CmdExecuteGeneratedCommandsNV, in_commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline,
    uint32_t                                    groupIndex)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_pipeline = GetObjectInfoTable().GetPipelineInfo(pipeline);

   //  OverrideCmdBindPipelineShaderGroupNV(GetDeviceTable(in_commandBuffer->handle)->CmdBindPipelineShaderGroupNV, in_commandBuffer, pipelineBindPoint, in_pipeline, groupIndex);
}

void VulkanFrameInspectorConsumer::Process_vkCreateIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pIndirectCommandsLayout->IsNull()) { pIndirectCommandsLayout->SetHandleLength(1); }
    IndirectCommandsLayoutNVInfo handle_info;
    pIndirectCommandsLayout->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateIndirectCommandsLayoutNV(GetDeviceTable(in_device->handle)->CreateIndirectCommandsLayoutNV, returnValue, in_device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
    // CheckResult("vkCreateIndirectCommandsLayoutNV", returnValue, replay_result);

    AddHandle<IndirectCommandsLayoutNVInfo>(device, pIndirectCommandsLayout->GetPointer(), pIndirectCommandsLayout->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddIndirectCommandsLayoutNVInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_indirectCommandsLayout = GetObjectInfoTable().GetIndirectCommandsLayoutNVInfo(indirectCommandsLayout);

   //  OverrideDestroyIndirectCommandsLayoutNV(GetDeviceTable(in_device->handle)->DestroyIndirectCommandsLayoutNV, in_device, in_indirectCommandsLayout, pAllocator);
    RemoveHandle(indirectCommandsLayout, &VulkanObjectInfoTable::RemoveIndirectCommandsLayoutNVInfo);
}

void VulkanFrameInspectorConsumer::Process_vkAcquireDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    format::HandleId                            display)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_display = GetObjectInfoTable().GetDisplayKHRInfo(display);

//     VkResult replay_result = OverrideAcquireDrmDisplayEXT(GetInstanceTable(in_physicalDevice->handle)->AcquireDrmDisplayEXT, returnValue, in_physicalDevice, drmFd, in_display);
    // CheckResult("vkAcquireDrmDisplayEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    uint32_t                                    connectorId,
    HandlePointerDecoder<VkDisplayKHR>*         display)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    if (!display->IsNull()) { display->SetHandleLength(1); }
    DisplayKHRInfo handle_info;
    display->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideGetDrmDisplayEXT(GetInstanceTable(in_physicalDevice->handle)->GetDrmDisplayEXT, returnValue, in_physicalDevice, drmFd, connectorId, display);
    // CheckResult("vkGetDrmDisplayEXT", returnValue, replay_result);

    AddHandle<DisplayKHRInfo>(physicalDevice, display->GetPointer(), display->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDisplayKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pPrivateDataSlot->IsNull()) { pPrivateDataSlot->SetHandleLength(1); }
    PrivateDataSlotInfo handle_info;
    pPrivateDataSlot->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreatePrivateDataSlotEXT(GetDeviceTable(in_device->handle)->CreatePrivateDataSlotEXT, returnValue, in_device, pCreateInfo, pAllocator, pPrivateDataSlot);
    // CheckResult("vkCreatePrivateDataSlotEXT", returnValue, replay_result);

    AddHandle<PrivateDataSlotInfo>(device, pPrivateDataSlot->GetPointer(), pPrivateDataSlot->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddPrivateDataSlotInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_privateDataSlot = GetObjectInfoTable().GetPrivateDataSlotInfo(privateDataSlot);

   //  OverrideDestroyPrivateDataSlotEXT(GetDeviceTable(in_device->handle)->DestroyPrivateDataSlotEXT, in_device, in_privateDataSlot, pAllocator);
    RemoveHandle(privateDataSlot, &VulkanObjectInfoTable::RemovePrivateDataSlotInfo);
}

void VulkanFrameInspectorConsumer::Process_vkSetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    uint64_t in_objectHandle = MapHandle(objectHandle, objectType);
    auto in_privateDataSlot = GetObjectInfoTable().GetPrivateDataSlotInfo(privateDataSlot);

//     VkResult replay_result = OverrideSetPrivateDataEXT(GetDeviceTable(in_device->handle)->SetPrivateDataEXT, returnValue, in_device, objectType, in_objectHandle, in_privateDataSlot, data);
    // CheckResult("vkSetPrivateDataEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    uint64_t in_objectHandle = MapHandle(objectHandle, objectType);
    auto in_privateDataSlot = GetObjectInfoTable().GetPrivateDataSlotInfo(privateDataSlot);
    pData->IsNull() ? nullptr : pData->AllocateOutputData(1, static_cast<uint64_t>(0));

   //  OverrideGetPrivateDataEXT(GetDeviceTable(in_device->handle)->GetPrivateDataEXT, in_device, objectType, in_objectHandle, in_privateDataSlot, pData);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetFragmentShadingRateEnumNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetFragmentShadingRateEnumNV, in_commandBuffer, shadingRate, combinerOps);
}

void VulkanFrameInspectorConsumer::Process_vkGetImageSubresourceLayout2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2EXT>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2EXT>* pLayout)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_image = GetObjectInfoTable().GetImageInfo(image);
    pLayout->IsNull() ? nullptr : pLayout->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_EXT, nullptr });

   //  OverrideGetImageSubresourceLayout2EXT(GetDeviceTable(in_device->handle)->GetImageSubresourceLayout2EXT, in_device, in_image, pSubresource, pLayout);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceFaultInfoEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT>* pFaultCounts,
    StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT>* pFaultInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    pFaultCounts->IsNull() ? nullptr : pFaultCounts->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT, nullptr });
    pFaultInfo->IsNull() ? nullptr : pFaultInfo->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT, nullptr });

//     VkResult replay_result = OverrideGetDeviceFaultInfoEXT(GetDeviceTable(in_device->handle)->GetDeviceFaultInfoEXT, returnValue, in_device, pFaultCounts, pFaultInfo);
    // CheckResult("vkGetDeviceFaultInfoEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_display = GetObjectInfoTable().GetDisplayKHRInfo(display);

//     VkResult replay_result = OverrideAcquireWinrtDisplayNV(GetInstanceTable(in_physicalDevice->handle)->AcquireWinrtDisplayNV, returnValue, in_physicalDevice, in_display);
    // CheckResult("vkAcquireWinrtDisplayNV", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    if (!pDisplay->IsNull()) { pDisplay->SetHandleLength(1); }
    DisplayKHRInfo handle_info;
    pDisplay->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideGetWinrtDisplayNV(GetInstanceTable(in_physicalDevice->handle)->GetWinrtDisplayNV, returnValue, in_physicalDevice, deviceRelativeId, pDisplay);
    // CheckResult("vkGetWinrtDisplayNV", returnValue, replay_result);

    AddHandle<DisplayKHRInfo>(physicalDevice, pDisplay->GetPointer(), pDisplay->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDisplayKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateDirectFBSurfaceEXT(GetInstanceTable(in_instance->handle)->CreateDirectFBSurfaceEXT, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateDirectFBSurfaceEXT", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dfb)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    // IDirectFB* in_dfb = static_cast<IDirectFB*>(PreProcessExternalObject(dfb, format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT"));

   //  OverrideGetPhysicalDeviceDirectFBPresentationSupportEXT(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceDirectFBPresentationSupportEXT, in_physicalDevice, queueFamilyIndex, in_dfb);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetVertexInputEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetVertexInputEXT, in_commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}

void VulkanFrameInspectorConsumer::Process_vkGetMemoryZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pGetZirconHandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pZirconHandle->IsNull() ? nullptr : pZirconHandle->AllocateOutputData(1, static_cast<uint32_t>(0));

//     VkResult replay_result = OverrideGetMemoryZirconHandleFUCHSIA(GetDeviceTable(in_device->handle)->GetMemoryZirconHandleFUCHSIA, returnValue, in_device, pGetZirconHandleInfo, pZirconHandle);
    // CheckResult("vkGetMemoryZirconHandleFUCHSIA", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint32_t                                    zirconHandle,
    StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA>* pMemoryZirconHandleProperties)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    pMemoryZirconHandleProperties->IsNull() ? nullptr : pMemoryZirconHandleProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA, nullptr });

//     VkResult replay_result = OverrideGetMemoryZirconHandlePropertiesFUCHSIA(GetDeviceTable(in_device->handle)->GetMemoryZirconHandlePropertiesFUCHSIA, returnValue, in_device, handleType, zirconHandle, pMemoryZirconHandleProperties);
    // CheckResult("vkGetMemoryZirconHandlePropertiesFUCHSIA", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pImportSemaphoreZirconHandleInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideImportSemaphoreZirconHandleFUCHSIA(GetDeviceTable(in_device->handle)->ImportSemaphoreZirconHandleFUCHSIA, returnValue, in_device, pImportSemaphoreZirconHandleInfo);
    // CheckResult("vkImportSemaphoreZirconHandleFUCHSIA", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkGetSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pGetZirconHandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pZirconHandle->IsNull() ? nullptr : pZirconHandle->AllocateOutputData(1, static_cast<uint32_t>(0));

//     VkResult replay_result = OverrideGetSemaphoreZirconHandleFUCHSIA(GetDeviceTable(in_device->handle)->GetSemaphoreZirconHandleFUCHSIA, returnValue, in_device, pGetZirconHandleInfo, pZirconHandle);
    // CheckResult("vkGetSemaphoreZirconHandleFUCHSIA", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_imageView = GetObjectInfoTable().GetImageViewInfo(imageView);

   //  OverrideCmdBindInvocationMaskHUAWEI(GetDeviceTable(in_commandBuffer->handle)->CmdBindInvocationMaskHUAWEI, in_commandBuffer, in_imageView, imageLayout);
}

void VulkanFrameInspectorConsumer::Process_vkGetMemoryRemoteAddressNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo,
    PointerDecoder<uint64_t, void*>*            pAddress)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pMemoryGetRemoteAddressInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkRemoteAddressNV* out_pAddress = pAddress->IsNull() ? nullptr : reinterpret_cast<VkRemoteAddressNV*>(pAddress->AllocateOutputData(1));

//     VkResult replay_result = OverrideGetMemoryRemoteAddressNV(GetDeviceTable(in_device->handle)->GetMemoryRemoteAddressNV, returnValue, in_device, pMemoryGetRemoteAddressInfo, out_pAddress);
    // CheckResult("vkGetMemoryRemoteAddressNV", returnValue, replay_result);

    // PostProcessExternalObject(replay_result, (*pAddress->GetPointer()), static_cast<void*>(*out_pAddress), format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV, "vkGetMemoryRemoteAddressNV");
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetPatchControlPointsEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetPatchControlPointsEXT, in_commandBuffer, patchControlPoints);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetRasterizerDiscardEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetRasterizerDiscardEnableEXT, in_commandBuffer, rasterizerDiscardEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthBiasEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthBiasEnableEXT, in_commandBuffer, depthBiasEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetLogicOpEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetLogicOpEXT, in_commandBuffer, logicOp);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetPrimitiveRestartEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetPrimitiveRestartEnableEXT, in_commandBuffer, primitiveRestartEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateScreenSurfaceQNX(GetInstanceTable(in_instance->handle)->CreateScreenSurfaceQNX, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    // CheckResult("vkCreateScreenSurfaceQNX", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    window)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    // struct _screen_window* in_window = static_cast<struct _screen_window*>(PreProcessExternalObject(window, format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX, "vkGetPhysicalDeviceScreenPresentationSupportQNX"));

   //  OverrideGetPhysicalDeviceScreenPresentationSupportQNX(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceScreenPresentationSupportQNX, in_physicalDevice, queueFamilyIndex, in_window);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetColorWriteEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetColorWriteEnableEXT, in_commandBuffer, attachmentCount, pColorWriteEnables);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdDrawMultiEXT(GetDeviceTable(in_commandBuffer->handle)->CmdDrawMultiEXT, in_commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    PointerDecoder<int32_t>*                    pVertexOffset)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdDrawMultiIndexedEXT(GetDeviceTable(in_commandBuffer->handle)->CmdDrawMultiIndexedEXT, in_commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
}

void VulkanFrameInspectorConsumer::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromap)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pMicromap->IsNull()) { pMicromap->SetHandleLength(1); }
    MicromapEXTInfo handle_info;
    pMicromap->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateMicromapEXT(GetDeviceTable(in_device->handle)->CreateMicromapEXT, returnValue, in_device, pCreateInfo, pAllocator, pMicromap);
    // CheckResult("vkCreateMicromapEXT", returnValue, replay_result);

    AddHandle<MicromapEXTInfo>(device, pMicromap->GetPointer(), pMicromap->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddMicromapEXTInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            micromap,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_micromap = GetObjectInfoTable().GetMicromapEXTInfo(micromap);

   //  OverrideDestroyMicromapEXT(GetDeviceTable(in_device->handle)->DestroyMicromapEXT, in_device, in_micromap, pAllocator);
    RemoveHandle(micromap, &VulkanObjectInfoTable::RemoveMicromapEXTInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructArrayHandles(pInfos->GetMetaStructPointer(), pInfos->GetLength(), GetObjectInfoTable());

   //  OverrideCmdBuildMicromapsEXT(GetDeviceTable(in_commandBuffer->handle)->CmdBuildMicromapsEXT, in_commandBuffer, infoCount, pInfos);
}

void VulkanFrameInspectorConsumer::Process_vkBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_deferredOperation = GetObjectInfoTable().GetDeferredOperationKHRInfo(deferredOperation);

    MapStructArrayHandles(pInfos->GetMetaStructPointer(), pInfos->GetLength(), GetObjectInfoTable());

//     VkResult replay_result = OverrideBuildMicromapsEXT(GetDeviceTable(in_device->handle)->BuildMicromapsEXT, returnValue, in_device, in_deferredOperation, infoCount, pInfos);
    // CheckResult("vkBuildMicromapsEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_deferredOperation = GetObjectInfoTable().GetDeferredOperationKHRInfo(deferredOperation);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideCopyMicromapEXT(GetDeviceTable(in_device->handle)->CopyMicromapEXT, returnValue, in_device, in_deferredOperation, pInfo);
    // CheckResult("vkCopyMicromapEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_deferredOperation = GetObjectInfoTable().GetDeferredOperationKHRInfo(deferredOperation);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideCopyMicromapToMemoryEXT(GetDeviceTable(in_device->handle)->CopyMicromapToMemoryEXT, returnValue, in_device, in_deferredOperation, pInfo);
    // CheckResult("vkCopyMicromapToMemoryEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_deferredOperation = GetObjectInfoTable().GetDeferredOperationKHRInfo(deferredOperation);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideCopyMemoryToMicromapEXT(GetDeviceTable(in_device->handle)->CopyMemoryToMicromapEXT, returnValue, in_device, in_deferredOperation, pInfo);
    // CheckResult("vkCopyMemoryToMicromapEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    size_t                                      stride)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    MapHandles<MicromapEXTInfo>(pMicromaps, micromapCount, &VulkanObjectInfoTable::GetMicromapEXTInfo);
    if (!pData->IsNull()) { pData->AllocateOutputData(dataSize); }

//     VkResult replay_result = OverrideWriteMicromapsPropertiesEXT(GetDeviceTable(in_device->handle)->WriteMicromapsPropertiesEXT, returnValue, in_device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
    // CheckResult("vkWriteMicromapsPropertiesEXT", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyMicromapEXT(GetDeviceTable(in_commandBuffer->handle)->CmdCopyMicromapEXT, in_commandBuffer, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyMicromapToMemoryEXT(GetDeviceTable(in_commandBuffer->handle)->CmdCopyMicromapToMemoryEXT, in_commandBuffer, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyMemoryToMicromapEXT(GetDeviceTable(in_commandBuffer->handle)->CmdCopyMemoryToMicromapEXT, in_commandBuffer, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    MapHandles<MicromapEXTInfo>(pMicromaps, micromapCount, &VulkanObjectInfoTable::GetMicromapEXTInfo);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideCmdWriteMicromapsPropertiesEXT(GetDeviceTable(in_commandBuffer->handle)->CmdWriteMicromapsPropertiesEXT, in_commandBuffer, micromapCount, pMicromaps, queryType, in_queryPool, firstQuery);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceMicromapCompatibilityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    pCompatibility->IsNull() ? nullptr : pCompatibility->AllocateOutputData(1, static_cast<VkAccelerationStructureCompatibilityKHR>(0));

   //  OverrideGetDeviceMicromapCompatibilityEXT(GetDeviceTable(in_device->handle)->GetDeviceMicromapCompatibilityEXT, in_device, pVersionInfo, pCompatibility);
}

void VulkanFrameInspectorConsumer::Process_vkGetMicromapBuildSizesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pBuildInfo,
    StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT>* pSizeInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pBuildInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pSizeInfo->IsNull() ? nullptr : pSizeInfo->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT, nullptr });

   //  OverrideGetMicromapBuildSizesEXT(GetDeviceTable(in_device->handle)->GetMicromapBuildSizesEXT, in_device, buildType, pBuildInfo, pSizeInfo);
}

void VulkanFrameInspectorConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    float                                       priority)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_memory = GetObjectInfoTable().GetDeviceMemoryInfo(memory);

   //  OverrideSetDeviceMemoryPriorityEXT(GetDeviceTable(in_device->handle)->SetDeviceMemoryPriorityEXT, in_device, in_memory, priority);
}

void VulkanFrameInspectorConsumer::Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pBindingReference->GetMetaStructPointer(), GetObjectInfoTable());
    pHostMapping->IsNull() ? nullptr : pHostMapping->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE, nullptr });

   //  OverrideGetDescriptorSetLayoutHostMappingInfoVALVE(GetDeviceTable(in_device->handle)->GetDescriptorSetLayoutHostMappingInfoVALVE, in_device, pBindingReference, pHostMapping);
}

void VulkanFrameInspectorConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSet,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_descriptorSet = GetObjectInfoTable().GetDescriptorSetInfo(descriptorSet);
    void** out_ppData = ppData->IsNull() ? nullptr : ppData->AllocateOutputData(1);

   //  OverrideGetDescriptorSetHostMappingVALVE(GetDeviceTable(in_device->handle)->GetDescriptorSetHostMappingVALVE, in_device, in_descriptorSet, out_ppData);

    // PostProcessExternalObject(VK_SUCCESS, (*ppData->GetPointer()), *ppData->GetOutputPointer(), format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE, "vkGetDescriptorSetHostMappingVALVE");
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetTessellationDomainOriginEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetTessellationDomainOriginEXT, in_commandBuffer, domainOrigin);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClampEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthClampEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthClampEnableEXT, in_commandBuffer, depthClampEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPolygonMode                               polygonMode)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetPolygonModeEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetPolygonModeEXT, in_commandBuffer, polygonMode);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetRasterizationSamplesEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetRasterizationSamplesEXT, in_commandBuffer, rasterizationSamples);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       samples,
    PointerDecoder<VkSampleMask>*               pSampleMask)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetSampleMaskEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetSampleMaskEXT, in_commandBuffer, samples, pSampleMask);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetAlphaToCoverageEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetAlphaToCoverageEnableEXT, in_commandBuffer, alphaToCoverageEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetAlphaToOneEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetAlphaToOneEnableEXT, in_commandBuffer, alphaToOneEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    logicOpEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetLogicOpEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetLogicOpEnableEXT, in_commandBuffer, logicOpEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorBlendEnables)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetColorBlendEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetColorBlendEnableEXT, in_commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetColorBlendEquationEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetColorBlendEquationEXT, in_commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkColorComponentFlags>*      pColorWriteMasks)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetColorWriteMaskEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetColorWriteMaskEXT, in_commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    rasterizationStream)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetRasterizationStreamEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetRasterizationStreamEXT, in_commandBuffer, rasterizationStream);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetConservativeRasterizationModeEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetConservativeRasterizationModeEXT, in_commandBuffer, conservativeRasterizationMode);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetExtraPrimitiveOverestimationSizeEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetExtraPrimitiveOverestimationSizeEXT, in_commandBuffer, extraPrimitiveOverestimationSize);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClipEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthClipEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthClipEnableEXT, in_commandBuffer, depthClipEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetSampleLocationsEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetSampleLocationsEnableEXT, in_commandBuffer, sampleLocationsEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetColorBlendAdvancedEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetColorBlendAdvancedEXT, in_commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetProvokingVertexModeEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetProvokingVertexModeEXT, in_commandBuffer, provokingVertexMode);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetLineRasterizationModeEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetLineRasterizationModeEXT, in_commandBuffer, lineRasterizationMode);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetLineStippleEnableEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetLineStippleEnableEXT, in_commandBuffer, stippledLineEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetDepthClipNegativeOneToOneEXT(GetDeviceTable(in_commandBuffer->handle)->CmdSetDepthClipNegativeOneToOneEXT, in_commandBuffer, negativeOneToOne);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetViewportWScalingEnableNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetViewportWScalingEnableNV, in_commandBuffer, viewportWScalingEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetViewportSwizzleNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetViewportSwizzleNV, in_commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetCoverageToColorEnableNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetCoverageToColorEnableNV, in_commandBuffer, coverageToColorEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetCoverageToColorLocationNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetCoverageToColorLocationNV, in_commandBuffer, coverageToColorLocation);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetCoverageModulationModeNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetCoverageModulationModeNV, in_commandBuffer, coverageModulationMode);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetCoverageModulationTableEnableNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetCoverageModulationTableEnableNV, in_commandBuffer, coverageModulationTableEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    PointerDecoder<float>*                      pCoverageModulationTable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetCoverageModulationTableNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetCoverageModulationTableNV, in_commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetShadingRateImageEnableNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetShadingRateImageEnableNV, in_commandBuffer, shadingRateImageEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetRepresentativeFragmentTestEnableNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetRepresentativeFragmentTestEnableNV, in_commandBuffer, representativeFragmentTestEnable);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetCoverageReductionModeNV(GetDeviceTable(in_commandBuffer->handle)->CmdSetCoverageReductionModeNV, in_commandBuffer, coverageReductionMode);
}

void VulkanFrameInspectorConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_shaderModule = GetObjectInfoTable().GetShaderModuleInfo(shaderModule);
    pIdentifier->IsNull() ? nullptr : pIdentifier->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT, nullptr });

   //  OverrideGetShaderModuleIdentifierEXT(GetDeviceTable(in_device->handle)->GetShaderModuleIdentifierEXT, in_device, in_shaderModule, pIdentifier);
}

void VulkanFrameInspectorConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pIdentifier->IsNull() ? nullptr : pIdentifier->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT, nullptr });

   //  OverrideGetShaderModuleCreateInfoIdentifierEXT(GetDeviceTable(in_device->handle)->GetShaderModuleCreateInfoIdentifierEXT, in_device, pCreateInfo, pIdentifier);
}

void VulkanFrameInspectorConsumer::Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV>* pOpticalFlowImageFormatInfo,
    PointerDecoder<uint32_t>*                   pFormatCount,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV>* pImageFormatProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pFormatCount->IsNull() ? nullptr : pFormatCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceOpticalFlowImageFormatsNV", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceOpticalFlowImageFormatsNV, pFormatCount, pImageFormatProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pImageFormatProperties->IsNull()) { pImageFormatProperties->AllocateOutputData(*pFormatCount->GetOutputPointer(), VkOpticalFlowImageFormatPropertiesNV{ VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV, nullptr }); }

//     VkResult replay_result = OverrideGetPhysicalDeviceOpticalFlowImageFormatsNV(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceOpticalFlowImageFormatsNV, returnValue, in_physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
    // CheckResult("vkGetPhysicalDeviceOpticalFlowImageFormatsNV", returnValue, replay_result);

    if (pImageFormatProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceOpticalFlowImageFormatsNV, *pFormatCount->GetOutputPointer(), &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pSession->IsNull()) { pSession->SetHandleLength(1); }
    OpticalFlowSessionNVInfo handle_info;
    pSession->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateOpticalFlowSessionNV(GetDeviceTable(in_device->handle)->CreateOpticalFlowSessionNV, returnValue, in_device, pCreateInfo, pAllocator, pSession);
    // CheckResult("vkCreateOpticalFlowSessionNV", returnValue, replay_result);

    AddHandle<OpticalFlowSessionNVInfo>(device, pSession->GetPointer(), pSession->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddOpticalFlowSessionNVInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_session = GetObjectInfoTable().GetOpticalFlowSessionNVInfo(session);

   //  OverrideDestroyOpticalFlowSessionNV(GetDeviceTable(in_device->handle)->DestroyOpticalFlowSessionNV, in_device, in_session, pAllocator);
    RemoveHandle(session, &VulkanObjectInfoTable::RemoveOpticalFlowSessionNVInfo);
}

void VulkanFrameInspectorConsumer::Process_vkBindOpticalFlowSessionImageNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            session,
    VkOpticalFlowSessionBindingPointNV          bindingPoint,
    format::HandleId                            view,
    VkImageLayout                               layout)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_session = GetObjectInfoTable().GetOpticalFlowSessionNVInfo(session);
    auto in_view = GetObjectInfoTable().GetImageViewInfo(view);

//     VkResult replay_result = OverrideBindOpticalFlowSessionImageNV(GetDeviceTable(in_device->handle)->BindOpticalFlowSessionImageNV, returnValue, in_device, in_session, bindingPoint, in_view, layout);
    // CheckResult("vkBindOpticalFlowSessionImageNV", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_session = GetObjectInfoTable().GetOpticalFlowSessionNVInfo(session);

   //  OverrideCmdOpticalFlowExecuteNV(GetDeviceTable(in_commandBuffer->handle)->CmdOpticalFlowExecuteNV, in_commandBuffer, in_session, pExecuteInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetFramebufferTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    PointerDecoder<uint32_t>*                   pPropertiesCount,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_framebuffer = GetObjectInfoTable().GetFramebufferInfo(framebuffer);
    pPropertiesCount->IsNull() ? nullptr : pPropertiesCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, FramebufferInfo>("vkGetFramebufferTilePropertiesQCOM", returnValue, framebuffer, kFramebufferArrayGetFramebufferTilePropertiesQCOM, pPropertiesCount, pProperties, &VulkanObjectInfoTable::GetFramebufferInfo));
    if (!pProperties->IsNull()) { pProperties->AllocateOutputData(*pPropertiesCount->GetOutputPointer(), VkTilePropertiesQCOM{ VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM, nullptr }); }

//     VkResult replay_result = OverrideGetFramebufferTilePropertiesQCOM(GetDeviceTable(in_device->handle)->GetFramebufferTilePropertiesQCOM, returnValue, in_device, in_framebuffer, pPropertiesCount, pProperties);
    // CheckResult("vkGetFramebufferTilePropertiesQCOM", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<FramebufferInfo>(framebuffer, kFramebufferArrayGetFramebufferTilePropertiesQCOM, *pPropertiesCount->GetOutputPointer(), &VulkanObjectInfoTable::GetFramebufferInfo); }
}

void VulkanFrameInspectorConsumer::Process_vkGetDynamicRenderingTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pRenderingInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM, nullptr });

//     VkResult replay_result = OverrideGetDynamicRenderingTilePropertiesQCOM(GetDeviceTable(in_device->handle)->GetDynamicRenderingTilePropertiesQCOM, returnValue, in_device, pRenderingInfo, pProperties);
    // CheckResult("vkGetDynamicRenderingTilePropertiesQCOM", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pAccelerationStructure->IsNull()) { pAccelerationStructure->SetHandleLength(1); }
    AccelerationStructureKHRInfo handle_info;
    pAccelerationStructure->SetConsumerData(0, &handle_info);

//     VkResult replay_result = OverrideCreateAccelerationStructureKHR(GetDeviceTable(in_device->handle)->CreateAccelerationStructureKHR, returnValue, in_device, pCreateInfo, pAllocator, pAccelerationStructure);
    // CheckResult("vkCreateAccelerationStructureKHR", returnValue, replay_result);

    AddHandle<AccelerationStructureKHRInfo>(device, pAccelerationStructure->GetPointer(), pAccelerationStructure->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddAccelerationStructureKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_accelerationStructure = GetObjectInfoTable().GetAccelerationStructureKHRInfo(accelerationStructure);

   //  OverrideDestroyAccelerationStructureKHR(GetDeviceTable(in_device->handle)->DestroyAccelerationStructureKHR, in_device, in_accelerationStructure, pAllocator);
    RemoveHandle(accelerationStructure, &VulkanObjectInfoTable::RemoveAccelerationStructureKHRInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructArrayHandles(pInfos->GetMetaStructPointer(), pInfos->GetLength(), GetObjectInfoTable());

   //  OverrideCmdBuildAccelerationStructuresKHR(GetDeviceTable(in_commandBuffer->handle)->CmdBuildAccelerationStructuresKHR, in_commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

void VulkanFrameInspectorConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    PointerDecoder<VkDeviceAddress>*            pIndirectDeviceAddresses,
    PointerDecoder<uint32_t>*                   pIndirectStrides,
    PointerDecoder<uint32_t*>*                  ppMaxPrimitiveCounts)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructArrayHandles(pInfos->GetMetaStructPointer(), pInfos->GetLength(), GetObjectInfoTable());

   //  OverrideCmdBuildAccelerationStructuresIndirectKHR(GetDeviceTable(in_commandBuffer->handle)->CmdBuildAccelerationStructuresIndirectKHR, in_commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}

void VulkanFrameInspectorConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_deferredOperation = GetObjectInfoTable().GetDeferredOperationKHRInfo(deferredOperation);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideCopyAccelerationStructureToMemoryKHR(GetDeviceTable(in_device->handle)->CopyAccelerationStructureToMemoryKHR, returnValue, in_device, in_deferredOperation, pInfo);
    // CheckResult("vkCopyAccelerationStructureToMemoryKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_deferredOperation = GetObjectInfoTable().GetDeferredOperationKHRInfo(deferredOperation);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

//     VkResult replay_result = OverrideCopyMemoryToAccelerationStructureKHR(GetDeviceTable(in_device->handle)->CopyMemoryToAccelerationStructureKHR, returnValue, in_device, in_deferredOperation, pInfo);
    // CheckResult("vkCopyMemoryToAccelerationStructureKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    size_t                                      stride)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    MapHandles<AccelerationStructureKHRInfo>(pAccelerationStructures, accelerationStructureCount, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo);
    if (!pData->IsNull()) { pData->AllocateOutputData(dataSize); }

//     VkResult replay_result = OverrideWriteAccelerationStructuresPropertiesKHR(GetDeviceTable(in_device->handle)->WriteAccelerationStructuresPropertiesKHR, returnValue, in_device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
    // CheckResult("vkWriteAccelerationStructuresPropertiesKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyAccelerationStructureKHR(GetDeviceTable(in_commandBuffer->handle)->CmdCopyAccelerationStructureKHR, in_commandBuffer, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyAccelerationStructureToMemoryKHR(GetDeviceTable(in_commandBuffer->handle)->CmdCopyAccelerationStructureToMemoryKHR, in_commandBuffer, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideCmdCopyMemoryToAccelerationStructureKHR(GetDeviceTable(in_commandBuffer->handle)->CmdCopyMemoryToAccelerationStructureKHR, in_commandBuffer, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

   //  OverrideGetAccelerationStructureDeviceAddressKHR(GetDeviceTable(in_device->handle)->GetAccelerationStructureDeviceAddressKHR, in_device, pInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    MapHandles<AccelerationStructureKHRInfo>(pAccelerationStructures, accelerationStructureCount, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);

   //  OverrideCmdWriteAccelerationStructuresPropertiesKHR(GetDeviceTable(in_commandBuffer->handle)->CmdWriteAccelerationStructuresPropertiesKHR, in_commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, in_queryPool, firstQuery);
}

void VulkanFrameInspectorConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    pCompatibility->IsNull() ? nullptr : pCompatibility->AllocateOutputData(1, static_cast<VkAccelerationStructureCompatibilityKHR>(0));

   //  OverrideGetDeviceAccelerationStructureCompatibilityKHR(GetDeviceTable(in_device->handle)->GetDeviceAccelerationStructureCompatibilityKHR, in_device, pVersionInfo, pCompatibility);
}

void VulkanFrameInspectorConsumer::Process_vkGetAccelerationStructureBuildSizesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo,
    PointerDecoder<uint32_t>*                   pMaxPrimitiveCounts,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>* pSizeInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pBuildInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pSizeInfo->IsNull() ? nullptr : pSizeInfo->AllocateOutputData(1, { VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR, nullptr });

   //  OverrideGetAccelerationStructureBuildSizesKHR(GetDeviceTable(in_device->handle)->GetAccelerationStructureBuildSizesKHR, in_device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
}

void VulkanFrameInspectorConsumer::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdTraceRaysKHR(GetDeviceTable(in_commandBuffer->handle)->CmdTraceRaysKHR, in_commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}

void VulkanFrameInspectorConsumer::Process_vkCreateRayTracingPipelinesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_deferredOperation = GetObjectInfoTable().GetDeferredOperationKHRInfo(deferredOperation);
    auto in_pipelineCache = GetObjectInfoTable().GetPipelineCacheInfo(pipelineCache);

    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    if (!pPipelines->IsNull()) { pPipelines->SetHandleLength(createInfoCount); }
    std::vector<PipelineInfo> handle_info(createInfoCount);
    for (size_t i = 0; i < createInfoCount; ++i) { pPipelines->SetConsumerData(i, &handle_info[i]); }

//     VkResult replay_result = OverrideCreateRayTracingPipelinesKHR(GetDeviceTable(in_device->handle)->CreateRayTracingPipelinesKHR, returnValue, in_device, in_deferredOperation, in_pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    // CheckResult("vkCreateRayTracingPipelinesKHR", returnValue, replay_result);

    AddHandles<PipelineInfo>(device, pPipelines->GetPointer(), pPipelines->GetLength(), pPipelines->GetHandlePointer(), createInfoCount, std::move(handle_info), &VulkanObjectInfoTable::AddPipelineInfo);
}

void VulkanFrameInspectorConsumer::Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipeline = GetObjectInfoTable().GetPipelineInfo(pipeline);
    if (!pData->IsNull()) { pData->AllocateOutputData(dataSize); }

//     VkResult replay_result = OverrideGetRayTracingCaptureReplayShaderGroupHandlesKHR(GetDeviceTable(in_device->handle)->GetRayTracingCaptureReplayShaderGroupHandlesKHR, returnValue, in_device, in_pipeline, firstGroup, groupCount, dataSize, pData);
    // CheckResult("vkGetRayTracingCaptureReplayShaderGroupHandlesKHR", returnValue, replay_result);
}

void VulkanFrameInspectorConsumer::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdTraceRaysIndirectKHR(GetDeviceTable(in_commandBuffer->handle)->CmdTraceRaysIndirectKHR, in_commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}

void VulkanFrameInspectorConsumer::Process_vkGetRayTracingShaderGroupStackSizeKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceSize                                returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    group,
    VkShaderGroupShaderKHR                      groupShader)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipeline = GetObjectInfoTable().GetPipelineInfo(pipeline);

   //  OverrideGetRayTracingShaderGroupStackSizeKHR(GetDeviceTable(in_device->handle)->GetRayTracingShaderGroupStackSizeKHR, in_device, in_pipeline, group, groupShader);
}

void VulkanFrameInspectorConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdSetRayTracingPipelineStackSizeKHR(GetDeviceTable(in_commandBuffer->handle)->CmdSetRayTracingPipelineStackSizeKHR, in_commandBuffer, pipelineStackSize);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

   //  OverrideCmdDrawMeshTasksEXT(GetDeviceTable(in_commandBuffer->handle)->CmdDrawMeshTasksEXT, in_commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);

   //  OverrideCmdDrawMeshTasksIndirectEXT(GetDeviceTable(in_commandBuffer->handle)->CmdDrawMeshTasksIndirectEXT, in_commandBuffer, in_buffer, offset, drawCount, stride);
}

void VulkanFrameInspectorConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);
    auto in_countBuffer = GetObjectInfoTable().GetBufferInfo(countBuffer);

   //  OverrideCmdDrawMeshTasksIndirectCountEXT(GetDeviceTable(in_commandBuffer->handle)->CmdDrawMeshTasksIndirectCountEXT, in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
