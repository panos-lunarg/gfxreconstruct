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

#ifndef GFXRECON_DECODE_GENERATED_VULKAN_CONSUMER_PRE_COMMANDS_H
#define GFXRECON_DECODE_GENERATED_VULKAN_CONSUMER_PRE_COMMANDS_H

#include "decode/vulkan_replay_consumer_base.h"
#include "format/api_call_id.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <format::ApiCallId Id>
struct ConsumerPreCall
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {}
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {}
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyInstance_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.EnumeratePhysicalDevices_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceFeatures_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceFormatProperties_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceImageFormatProperties_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceProperties_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceQueueFamilyProperties_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceMemoryProperties_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateDevice_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyDevice_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceQueue_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.QueueSubmit_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.QueueWaitIdle_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DeviceWaitIdle_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.AllocateMemory_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.FreeMemory_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkMapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.MapMemory_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.UnmapMemory_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.FlushMappedMemoryRanges_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.InvalidateMappedMemoryRanges_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceMemoryCommitment_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.BindBufferMemory_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.BindImageMemory_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetBufferMemoryRequirements_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetImageMemoryRequirements_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetImageSparseMemoryRequirements_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceSparseImageFormatProperties_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.QueueBindSparse_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateFence>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateFence_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyFence>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyFence_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkResetFences>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ResetFences_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetFenceStatus_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkWaitForFences>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.WaitForFences_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateSemaphore_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroySemaphore_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateEvent_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyEvent_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetEventStatus_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.SetEvent_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ResetEvent_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateQueryPool_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyQueryPool_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetQueryPoolResults_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateBuffer_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyBuffer_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateBufferView_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyBufferView_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateImage_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyImage_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetImageSubresourceLayout_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateImageView_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyImageView_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateShaderModule_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyShaderModule_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreatePipelineCache_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyPipelineCache_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPipelineCacheData_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.MergePipelineCaches_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateGraphicsPipelines_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateComputePipelines_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyPipeline_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreatePipelineLayout_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyPipelineLayout_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateSampler>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateSampler_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroySampler>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroySampler_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateDescriptorSetLayout_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyDescriptorSetLayout_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateDescriptorPool_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyDescriptorPool_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ResetDescriptorPool_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.AllocateDescriptorSets_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.FreeDescriptorSets_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.UpdateDescriptorSets_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateFramebuffer_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyFramebuffer_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateRenderPass_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyRenderPass_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetRenderAreaGranularity_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateCommandPool_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyCommandPool_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ResetCommandPool_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.AllocateCommandBuffers_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.FreeCommandBuffers_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.BeginCommandBuffer_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.EndCommandBuffer_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ResetCommandBuffer_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBindPipeline_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetViewport_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetScissor_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetLineWidth_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthBias_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetBlendConstants_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthBounds_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetStencilCompareMask_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetStencilWriteMask_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetStencilReference_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBindDescriptorSets_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBindIndexBuffer_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBindVertexBuffers_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDraw>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDraw_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawIndexed_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawIndirect_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawIndexedIndirect_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDispatch_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDispatchIndirect_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyBuffer_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyImage_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBlitImage_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyBufferToImage_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyImageToBuffer_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdUpdateBuffer_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdFillBuffer_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdClearColorImage_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdClearDepthStencilImage_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdClearAttachments_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdResolveImage_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetEvent_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdResetEvent_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdWaitEvents_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdPipelineBarrier_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBeginQuery_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdEndQuery_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdResetQueryPool_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdWriteTimestamp_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyQueryPoolResults_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdPushConstants_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBeginRenderPass_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdNextSubpass_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdEndRenderPass_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdExecuteCommands_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.BindBufferMemory2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.BindImageMemory2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceGroupPeerMemoryFeatures_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDeviceMask_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDispatchBase_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.EnumeratePhysicalDeviceGroups_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetImageMemoryRequirements2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetBufferMemoryRequirements2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetImageSparseMemoryRequirements2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceFeatures2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceProperties2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceFormatProperties2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceImageFormatProperties2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceQueueFamilyProperties2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceMemoryProperties2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceSparseImageFormatProperties2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.TrimCommandPool_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceQueue2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateSamplerYcbcrConversion_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroySamplerYcbcrConversion_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateDescriptorUpdateTemplate_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyDescriptorUpdateTemplate_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalBufferProperties_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalFenceProperties_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalSemaphoreProperties_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDescriptorSetLayoutSupport_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawIndirectCount_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawIndexedIndirectCount_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateRenderPass2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBeginRenderPass2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdNextSubpass2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdEndRenderPass2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ResetQueryPool_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetSemaphoreCounterValue_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkWaitSemaphores>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.WaitSemaphores_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkSignalSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.SignalSemaphore_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetBufferDeviceAddress_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetBufferOpaqueCaptureAddress_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceMemoryOpaqueCaptureAddress_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceToolProperties_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreatePrivateDataSlot_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyPrivateDataSlot_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkSetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.SetPrivateData_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPrivateData_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetEvent2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdResetEvent2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdWaitEvents2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdPipelineBarrier2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdWriteTimestamp2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.QueueSubmit2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyBuffer2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyImage2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyBufferToImage2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyImageToBuffer2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBlitImage2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdResolveImage2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBeginRendering_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdEndRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdEndRendering_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetCullMode_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetFrontFace_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetPrimitiveTopology_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetViewportWithCount_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetScissorWithCount_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBindVertexBuffers2_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthTestEnable_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthWriteEnable_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthCompareOp_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthBoundsTestEnable_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetStencilTestEnable_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetStencilOp_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetRasterizerDiscardEnable_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthBiasEnable_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetPrimitiveRestartEnable_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceBufferMemoryRequirements_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceImageMemoryRequirements_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceImageSparseMemoryRequirements_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroySurfaceKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceSupportKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceFormatsKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfacePresentModesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateSwapchainKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroySwapchainKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetSwapchainImagesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.AcquireNextImageKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.QueuePresentKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceGroupPresentCapabilitiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceGroupSurfacePresentModesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDevicePresentRectanglesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.AcquireNextImage2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceDisplayPropertiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDisplayPlaneSupportedDisplaysKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDisplayModePropertiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateDisplayModeKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDisplayPlaneCapabilitiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateDisplayPlaneSurfaceKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateSharedSwapchainsKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateXlibSurfaceKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceXlibPresentationSupportKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateXcbSurfaceKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceXcbPresentationSupportKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateWaylandSurfaceKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateAndroidSurfaceKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateWin32SurfaceKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceWin32PresentationSupportKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceVideoCapabilitiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateVideoSessionKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyVideoSessionKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetVideoSessionMemoryRequirementsKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.BindVideoSessionMemoryKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateVideoSessionParametersKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.UpdateVideoSessionParametersKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyVideoSessionParametersKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBeginVideoCodingKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdEndVideoCodingKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdControlVideoCodingKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDecodeVideoKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBeginRenderingKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdEndRenderingKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceFeatures2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceProperties2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceFormatProperties2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceImageFormatProperties2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceMemoryProperties2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceGroupPeerMemoryFeaturesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDeviceMaskKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDispatchBaseKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.TrimCommandPoolKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.EnumeratePhysicalDeviceGroupsKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetMemoryWin32HandleKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetMemoryWin32HandlePropertiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetMemoryFdKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetMemoryFdPropertiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ImportSemaphoreWin32HandleKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetSemaphoreWin32HandleKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ImportSemaphoreFdKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetSemaphoreFdKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdPushDescriptorSetKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateDescriptorUpdateTemplateKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyDescriptorUpdateTemplateKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateRenderPass2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBeginRenderPass2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdNextSubpass2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdEndRenderPass2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetSwapchainStatusKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalFencePropertiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ImportFenceWin32HandleKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetFenceWin32HandleKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ImportFenceFdKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetFenceFdKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.AcquireProfilingLockKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ReleaseProfilingLockKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceFormats2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceDisplayProperties2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDisplayModeProperties2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDisplayPlaneCapabilities2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetImageMemoryRequirements2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetBufferMemoryRequirements2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetImageSparseMemoryRequirements2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateSamplerYcbcrConversionKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroySamplerYcbcrConversionKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.BindBufferMemory2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.BindImageMemory2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDescriptorSetLayoutSupportKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawIndirectCountKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawIndexedIndirectCountKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetSemaphoreCounterValueKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.WaitSemaphoresKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.SignalSemaphoreKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceFragmentShadingRatesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetFragmentShadingRateKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.WaitForPresentKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetBufferDeviceAddressKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetBufferOpaqueCaptureAddressKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateDeferredOperationKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyDeferredOperationKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeferredOperationMaxConcurrencyKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeferredOperationResultKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DeferredOperationJoinKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPipelineExecutablePropertiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPipelineExecutableStatisticsKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPipelineExecutableInternalRepresentationsKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdEncodeVideoKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetEvent2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdResetEvent2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdWaitEvents2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdPipelineBarrier2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdWriteTimestamp2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.QueueSubmit2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdWriteBufferMarker2AMD_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetQueueCheckpointData2NV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyBuffer2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyImage2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyBufferToImage2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyImageToBuffer2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBlitImage2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdResolveImage2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdTraceRaysIndirect2KHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceBufferMemoryRequirementsKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceImageMemoryRequirementsKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceImageSparseMemoryRequirementsKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateDebugReportCallbackEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyDebugReportCallbackEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DebugReportMessageEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DebugMarkerSetObjectTagEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DebugMarkerSetObjectNameEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDebugMarkerBeginEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDebugMarkerEndEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDebugMarkerInsertEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBindTransformFeedbackBuffersEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBeginTransformFeedbackEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdEndTransformFeedbackEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBeginQueryIndexedEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdEndQueryIndexedEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawIndirectByteCountEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetImageViewHandleNVX_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetImageViewAddressNVX_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawIndirectCountAMD_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawIndexedIndirectCountAMD_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetShaderInfoAMD_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateStreamDescriptorSurfaceGGP_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetMemoryWin32HandleNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateViSurfaceNN_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBeginConditionalRenderingEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdEndConditionalRenderingEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetViewportWScalingNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ReleaseDisplayEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.AcquireXlibDisplayEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetRandROutputDisplayEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DisplayPowerControlEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.RegisterDeviceEventEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.RegisterDisplayEventEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetSwapchainCounterEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetRefreshCycleDurationGOOGLE_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPastPresentationTimingGOOGLE_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDiscardRectangleEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDiscardRectangleEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDiscardRectangleModeEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.SetHdrMetadataEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateIOSSurfaceMVK_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateMacOSSurfaceMVK_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.SetDebugUtilsObjectNameEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.SetDebugUtilsObjectTagEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.QueueBeginDebugUtilsLabelEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.QueueEndDebugUtilsLabelEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.QueueInsertDebugUtilsLabelEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBeginDebugUtilsLabelEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdEndDebugUtilsLabelEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdInsertDebugUtilsLabelEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateDebugUtilsMessengerEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyDebugUtilsMessengerEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.SubmitDebugUtilsMessageEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetAndroidHardwareBufferPropertiesANDROID_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetMemoryAndroidHardwareBufferANDROID_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetSampleLocationsEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceMultisamplePropertiesEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetImageDrmFormatModifierPropertiesEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateValidationCacheEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyValidationCacheEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.MergeValidationCachesEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetValidationCacheDataEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBindShadingRateImageNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetViewportShadingRatePaletteNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetCoarseSampleOrderNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateAccelerationStructureNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyAccelerationStructureNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetAccelerationStructureMemoryRequirementsNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.BindAccelerationStructureMemoryNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBuildAccelerationStructureNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyAccelerationStructureNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdTraceRaysNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateRayTracingPipelinesNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetRayTracingShaderGroupHandlesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetRayTracingShaderGroupHandlesNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetAccelerationStructureHandleNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdWriteAccelerationStructuresPropertiesNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CompileDeferredNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetMemoryHostPointerPropertiesEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdWriteBufferMarkerAMD_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetCalibratedTimestampsEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawMeshTasksNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawMeshTasksIndirectNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawMeshTasksIndirectCountNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetExclusiveScissorEnableNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetExclusiveScissorNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetCheckpointNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetQueueCheckpointDataNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.InitializePerformanceApiINTEL_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.UninitializePerformanceApiINTEL_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetPerformanceMarkerINTEL_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetPerformanceStreamMarkerINTEL_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetPerformanceOverrideINTEL_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.AcquirePerformanceConfigurationINTEL_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ReleasePerformanceConfigurationINTEL_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.QueueSetPerformanceConfigurationINTEL_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPerformanceParameterINTEL_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.SetLocalDimmingAMD_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateImagePipeSurfaceFUCHSIA_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateMetalSurfaceEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetBufferDeviceAddressEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceToolPropertiesEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfacePresentModes2EXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.AcquireFullScreenExclusiveModeEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ReleaseFullScreenExclusiveModeEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceGroupSurfacePresentModes2EXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateHeadlessSurfaceEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetLineStippleEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ResetQueryPoolEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetCullModeEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetFrontFaceEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetPrimitiveTopologyEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetViewportWithCountEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetScissorWithCountEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBindVertexBuffers2EXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthTestEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthWriteEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthCompareOpEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthBoundsTestEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetStencilTestEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetStencilOpEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ReleaseSwapchainImagesEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetGeneratedCommandsMemoryRequirementsNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdPreprocessGeneratedCommandsNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdExecuteGeneratedCommandsNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBindPipelineShaderGroupNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateIndirectCommandsLayoutNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyIndirectCommandsLayoutNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.AcquireDrmDisplayEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDrmDisplayEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreatePrivateDataSlotEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyPrivateDataSlotEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.SetPrivateDataEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPrivateDataEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetFragmentShadingRateEnumNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetImageSubresourceLayout2EXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceFaultInfoEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.AcquireWinrtDisplayNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetWinrtDisplayNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateDirectFBSurfaceEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetVertexInputEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetMemoryZirconHandleFUCHSIA_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetMemoryZirconHandlePropertiesFUCHSIA_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.ImportSemaphoreZirconHandleFUCHSIA_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetSemaphoreZirconHandleFUCHSIA_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBindInvocationMaskHUAWEI_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetMemoryRemoteAddressNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetPatchControlPointsEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetRasterizerDiscardEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthBiasEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetLogicOpEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetPrimitiveRestartEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateScreenSurfaceQNX_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceScreenPresentationSupportQNX_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetColorWriteEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawMultiEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawMultiIndexedEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateMicromapEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyMicromapEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBuildMicromapsEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.BuildMicromapsEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CopyMicromapEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CopyMicromapToMemoryEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CopyMemoryToMicromapEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.WriteMicromapsPropertiesEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyMicromapEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyMicromapToMemoryEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyMemoryToMicromapEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdWriteMicromapsPropertiesEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceMicromapCompatibilityEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetMicromapBuildSizesEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawClusterHUAWEI_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawClusterIndirectHUAWEI_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.SetDeviceMemoryPriorityEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDescriptorSetHostMappingVALVE_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetTessellationDomainOriginEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthClampEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetPolygonModeEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetRasterizationSamplesEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetSampleMaskEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetAlphaToCoverageEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetAlphaToOneEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetLogicOpEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetColorBlendEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetColorBlendEquationEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetColorWriteMaskEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetRasterizationStreamEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetConservativeRasterizationModeEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthClipEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetSampleLocationsEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetColorBlendAdvancedEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetProvokingVertexModeEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetLineRasterizationModeEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetLineStippleEnableEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetDepthClipNegativeOneToOneEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetViewportWScalingEnableNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetViewportSwizzleNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetCoverageToColorEnableNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetCoverageToColorLocationNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetCoverageModulationModeNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetCoverageModulationTableEnableNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetCoverageModulationTableNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetShadingRateImageEnableNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetRepresentativeFragmentTestEnableNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetCoverageReductionModeNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetShaderModuleIdentifierEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetShaderModuleCreateInfoIdentifierEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateOpticalFlowSessionNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyOpticalFlowSessionNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.BindOpticalFlowSessionImageNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdOpticalFlowExecuteNV_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetFramebufferTilePropertiesQCOM_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDynamicRenderingTilePropertiesQCOM_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateAccelerationStructureKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.DestroyAccelerationStructureKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBuildAccelerationStructuresKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdBuildAccelerationStructuresIndirectKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CopyAccelerationStructureToMemoryKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CopyMemoryToAccelerationStructureKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.WriteAccelerationStructuresPropertiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyAccelerationStructureKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyAccelerationStructureToMemoryKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdCopyMemoryToAccelerationStructureKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetAccelerationStructureDeviceAddressKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdWriteAccelerationStructuresPropertiesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetDeviceAccelerationStructureCompatibilityKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetAccelerationStructureBuildSizesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdTraceRaysKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CreateRayTracingPipelinesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdTraceRaysIndirectKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.GetRayTracingShaderGroupStackSizeKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdSetRayTracingPipelineStackSizeKHR_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawMeshTasksEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawMeshTasksIndirectEXT_PreCall(consumer, call_info, args...);
        }
    }
};

template<>
struct ConsumerPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_pre.CmdDrawMeshTasksIndirectCountEXT_PreCall(consumer, call_info, args...);
        }
    }
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_GENERATED_VULKAN_CONSUMER_PRE_COMMANDS_H
