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

#ifndef GFXRECON_DECODE_GENERATED_VULKAN_CONSUMER_POST_COMMANDS_H
#define GFXRECON_DECODE_GENERATED_VULKAN_CONSUMER_POST_COMMANDS_H

#include "decode/vulkan_replay_consumer_base.h"
#include "format/api_call_id.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <format::ApiCallId Id>
struct ConsumerPostCall
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {}

    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult, Args... args)
    {}
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        // for (auto &plugin : consumer->loaded_plugins_)
        // {
        //     plugin.func_table_post.DestroyInstance_PostCall(consumer, call_info, args...);
        // }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceFeatures_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceFormatProperties_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceProperties_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceQueueFamilyProperties_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceMemoryProperties_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyDevice_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceQueue_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.FreeMemory_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.UnmapMemory_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceMemoryCommitment_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetBufferMemoryRequirements_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetImageMemoryRequirements_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetImageSparseMemoryRequirements_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceSparseImageFormatProperties_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyFence>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyFence_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroySemaphore_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyEvent_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyQueryPool_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyBuffer_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyBufferView_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyImage_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetImageSubresourceLayout_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyImageView_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyShaderModule_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyPipelineCache_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyPipeline_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyPipelineLayout_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroySampler>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroySampler_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyDescriptorSetLayout_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyDescriptorPool_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.UpdateDescriptorSets_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyFramebuffer_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyRenderPass_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetRenderAreaGranularity_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyCommandPool_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.FreeCommandBuffers_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBindPipeline_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetViewport_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetScissor_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetLineWidth_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthBias_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetBlendConstants_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthBounds_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetStencilCompareMask_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetStencilWriteMask_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetStencilReference_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBindDescriptorSets_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBindIndexBuffer_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBindVertexBuffers_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDraw>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDraw_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawIndexed_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawIndirect_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawIndexedIndirect_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDispatch_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDispatchIndirect_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyBuffer_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyImage_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBlitImage_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyBufferToImage_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyImageToBuffer_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdUpdateBuffer_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdFillBuffer_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdClearColorImage_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdClearDepthStencilImage_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdClearAttachments_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdResolveImage_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetEvent_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdResetEvent_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdWaitEvents_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdPipelineBarrier_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBeginQuery_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdEndQuery_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdResetQueryPool_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdWriteTimestamp_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyQueryPoolResults_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdPushConstants_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBeginRenderPass_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdNextSubpass_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdEndRenderPass_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdExecuteCommands_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceGroupPeerMemoryFeatures_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDeviceMask_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDispatchBase_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetImageMemoryRequirements2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetBufferMemoryRequirements2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetImageSparseMemoryRequirements2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceFeatures2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceProperties2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceFormatProperties2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceQueueFamilyProperties2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceMemoryProperties2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceSparseImageFormatProperties2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.TrimCommandPool_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceQueue2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroySamplerYcbcrConversion_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyDescriptorUpdateTemplate_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceExternalBufferProperties_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceExternalFenceProperties_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceExternalSemaphoreProperties_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDescriptorSetLayoutSupport_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawIndirectCount_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawIndexedIndirectCount_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBeginRenderPass2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdNextSubpass2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdEndRenderPass2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ResetQueryPool_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyPrivateDataSlot_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPrivateData_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetEvent2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdResetEvent2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdWaitEvents2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdPipelineBarrier2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdWriteTimestamp2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyBuffer2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyImage2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyBufferToImage2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyImageToBuffer2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBlitImage2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdResolveImage2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBeginRendering_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdEndRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdEndRendering_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetCullMode_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetFrontFace_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetPrimitiveTopology_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetViewportWithCount_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetScissorWithCount_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBindVertexBuffers2_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthTestEnable_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthWriteEnable_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthCompareOp_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthBoundsTestEnable_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetStencilTestEnable_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetStencilOp_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetRasterizerDiscardEnable_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthBiasEnable_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetPrimitiveRestartEnable_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceBufferMemoryRequirements_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceImageMemoryRequirements_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceImageSparseMemoryRequirements_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroySurfaceKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroySwapchainKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyVideoSessionKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyVideoSessionParametersKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBeginVideoCodingKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdEndVideoCodingKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdControlVideoCodingKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDecodeVideoKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBeginRenderingKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdEndRenderingKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceFeatures2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceProperties2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceFormatProperties2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceMemoryProperties2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceGroupPeerMemoryFeaturesKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDeviceMaskKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDispatchBaseKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.TrimCommandPoolKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdPushDescriptorSetKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyDescriptorUpdateTemplateKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBeginRenderPass2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdNextSubpass2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdEndRenderPass2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceExternalFencePropertiesKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ReleaseProfilingLockKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetImageMemoryRequirements2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetBufferMemoryRequirements2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetImageSparseMemoryRequirements2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroySamplerYcbcrConversionKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDescriptorSetLayoutSupportKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawIndirectCountKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawIndexedIndirectCountKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetFragmentShadingRateKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyDeferredOperationKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdEncodeVideoKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetEvent2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdResetEvent2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdWaitEvents2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdPipelineBarrier2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdWriteTimestamp2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdWriteBufferMarker2AMD_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetQueueCheckpointData2NV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyBuffer2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyImage2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyBufferToImage2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyImageToBuffer2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBlitImage2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdResolveImage2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdTraceRaysIndirect2KHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceBufferMemoryRequirementsKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceImageMemoryRequirementsKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceImageSparseMemoryRequirementsKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyDebugReportCallbackEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DebugReportMessageEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDebugMarkerBeginEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDebugMarkerEndEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDebugMarkerInsertEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBindTransformFeedbackBuffersEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBeginTransformFeedbackEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdEndTransformFeedbackEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBeginQueryIndexedEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdEndQueryIndexedEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawIndirectByteCountEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawIndirectCountAMD_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawIndexedIndirectCountAMD_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBeginConditionalRenderingEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdEndConditionalRenderingEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetViewportWScalingNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDiscardRectangleEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDiscardRectangleEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDiscardRectangleModeEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.SetHdrMetadataEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.QueueBeginDebugUtilsLabelEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.QueueEndDebugUtilsLabelEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.QueueInsertDebugUtilsLabelEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBeginDebugUtilsLabelEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdEndDebugUtilsLabelEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdInsertDebugUtilsLabelEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyDebugUtilsMessengerEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.SubmitDebugUtilsMessageEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetSampleLocationsEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceMultisamplePropertiesEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyValidationCacheEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBindShadingRateImageNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetViewportShadingRatePaletteNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetCoarseSampleOrderNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyAccelerationStructureNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetAccelerationStructureMemoryRequirementsNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBuildAccelerationStructureNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyAccelerationStructureNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdTraceRaysNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdWriteAccelerationStructuresPropertiesNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdWriteBufferMarkerAMD_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawMeshTasksNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawMeshTasksIndirectNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawMeshTasksIndirectCountNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetExclusiveScissorEnableNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetExclusiveScissorNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetCheckpointNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetQueueCheckpointDataNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.UninitializePerformanceApiINTEL_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.SetLocalDimmingAMD_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetLineStippleEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ResetQueryPoolEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetCullModeEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetFrontFaceEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetPrimitiveTopologyEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetViewportWithCountEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetScissorWithCountEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBindVertexBuffers2EXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthTestEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthWriteEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthCompareOpEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthBoundsTestEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetStencilTestEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetStencilOpEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetGeneratedCommandsMemoryRequirementsNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdExecuteGeneratedCommandsNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBindPipelineShaderGroupNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyIndirectCommandsLayoutNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyPrivateDataSlotEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPrivateDataEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetFragmentShadingRateEnumNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetImageSubresourceLayout2EXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetVertexInputEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBindInvocationMaskHUAWEI_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetPatchControlPointsEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetRasterizerDiscardEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthBiasEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetLogicOpEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetPrimitiveRestartEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetColorWriteEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawMultiEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawMultiIndexedEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyMicromapEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBuildMicromapsEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyMicromapEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyMicromapToMemoryEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyMemoryToMicromapEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdWriteMicromapsPropertiesEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceMicromapCompatibilityEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetMicromapBuildSizesEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawClusterHUAWEI_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawClusterIndirectHUAWEI_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.SetDeviceMemoryPriorityEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDescriptorSetHostMappingVALVE_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetTessellationDomainOriginEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthClampEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetPolygonModeEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetRasterizationSamplesEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetSampleMaskEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetAlphaToCoverageEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetAlphaToOneEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetLogicOpEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetColorBlendEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetColorBlendEquationEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetColorWriteMaskEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetRasterizationStreamEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetConservativeRasterizationModeEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthClipEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetSampleLocationsEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetColorBlendAdvancedEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetProvokingVertexModeEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetLineRasterizationModeEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetLineStippleEnableEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetDepthClipNegativeOneToOneEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetViewportWScalingEnableNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetViewportSwizzleNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetCoverageToColorEnableNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetCoverageToColorLocationNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetCoverageModulationModeNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetCoverageModulationTableEnableNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetCoverageModulationTableNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetShadingRateImageEnableNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetRepresentativeFragmentTestEnableNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetCoverageReductionModeNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetShaderModuleIdentifierEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetShaderModuleCreateInfoIdentifierEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyOpticalFlowSessionNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdOpticalFlowExecuteNV_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DestroyAccelerationStructureKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBuildAccelerationStructuresKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdBuildAccelerationStructuresIndirectKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyAccelerationStructureKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyAccelerationStructureToMemoryKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdCopyMemoryToAccelerationStructureKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdWriteAccelerationStructuresPropertiesKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceAccelerationStructureCompatibilityKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetAccelerationStructureBuildSizesKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdTraceRaysKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdTraceRaysIndirectKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetRayTracingPipelineStackSizeKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawMeshTasksEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawMeshTasksIndirectEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdDrawMeshTasksIndirectCountEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetBufferOpaqueCaptureAddress_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceMemoryOpaqueCaptureAddress_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceXlibPresentationSupportKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceXcbPresentationSupportKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceWin32PresentationSupportKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetBufferDeviceAddressKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetBufferOpaqueCaptureAddressKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeferredOperationMaxConcurrencyKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetImageViewHandleNVX_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetBufferDeviceAddressEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceScreenPresentationSupportQNX_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetAccelerationStructureDeviceAddressKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetRayTracingShaderGroupStackSizeKHR_PostCall(consumer, call_info, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateInstance_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.EnumeratePhysicalDevices_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceImageFormatProperties_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateDevice_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.QueueSubmit_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.QueueWaitIdle_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DeviceWaitIdle_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.AllocateMemory_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkMapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.MapMemory_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.FlushMappedMemoryRanges_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.InvalidateMappedMemoryRanges_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.BindBufferMemory_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.BindImageMemory_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.QueueBindSparse_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateFence>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateFence_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkResetFences>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ResetFences_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetFenceStatus_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkWaitForFences>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.WaitForFences_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateSemaphore_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateEvent_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetEventStatus_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.SetEvent_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ResetEvent_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateQueryPool_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetQueryPoolResults_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateBuffer_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateBufferView_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateImage>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateImage_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateImageView_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateShaderModule_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreatePipelineCache_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPipelineCacheData_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.MergePipelineCaches_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateGraphicsPipelines_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateComputePipelines_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreatePipelineLayout_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateSampler>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateSampler_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateDescriptorSetLayout_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateDescriptorPool_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ResetDescriptorPool_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.AllocateDescriptorSets_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.FreeDescriptorSets_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateFramebuffer_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateRenderPass_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateCommandPool_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ResetCommandPool_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.AllocateCommandBuffers_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.BeginCommandBuffer_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.EndCommandBuffer_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ResetCommandBuffer_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.BindBufferMemory2_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.BindImageMemory2_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.EnumeratePhysicalDeviceGroups_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceImageFormatProperties2_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateSamplerYcbcrConversion_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateRenderPass2_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetSemaphoreCounterValue_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.WaitSemaphores_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.SignalSemaphore_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceToolProperties_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreatePrivateDataSlot_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.SetPrivateData_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.QueueSubmit2_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceSupportKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceFormatsKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceSurfacePresentModesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateSwapchainKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetSwapchainImagesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.AcquireNextImageKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.QueuePresentKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceGroupPresentCapabilitiesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceGroupSurfacePresentModesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDevicePresentRectanglesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.AcquireNextImage2KHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceDisplayPropertiesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDisplayPlaneSupportedDisplaysKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDisplayModePropertiesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateDisplayModeKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDisplayPlaneCapabilitiesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateDisplayPlaneSurfaceKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateSharedSwapchainsKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateXlibSurfaceKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateXcbSurfaceKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateWaylandSurfaceKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateAndroidSurfaceKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateWin32SurfaceKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceVideoCapabilitiesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateVideoSessionKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetVideoSessionMemoryRequirementsKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.BindVideoSessionMemoryKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateVideoSessionParametersKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.UpdateVideoSessionParametersKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceImageFormatProperties2KHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.EnumeratePhysicalDeviceGroupsKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetMemoryWin32HandleKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetMemoryWin32HandlePropertiesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetMemoryFdKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetMemoryFdPropertiesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ImportSemaphoreWin32HandleKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetSemaphoreWin32HandleKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ImportSemaphoreFdKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetSemaphoreFdKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateDescriptorUpdateTemplateKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateRenderPass2KHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetSwapchainStatusKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ImportFenceWin32HandleKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetFenceWin32HandleKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ImportFenceFdKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetFenceFdKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.AcquireProfilingLockKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceFormats2KHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceDisplayProperties2KHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDisplayModeProperties2KHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDisplayPlaneCapabilities2KHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateSamplerYcbcrConversionKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.BindBufferMemory2KHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.BindImageMemory2KHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetSemaphoreCounterValueKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.WaitSemaphoresKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.SignalSemaphoreKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceFragmentShadingRatesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.WaitForPresentKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateDeferredOperationKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeferredOperationResultKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DeferredOperationJoinKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPipelineExecutablePropertiesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPipelineExecutableStatisticsKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPipelineExecutableInternalRepresentationsKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.QueueSubmit2KHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateDebugReportCallbackEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DebugMarkerSetObjectTagEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DebugMarkerSetObjectNameEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetImageViewAddressNVX_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetShaderInfoAMD_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateStreamDescriptorSurfaceGGP_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetMemoryWin32HandleNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateViSurfaceNN_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ReleaseDisplayEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.AcquireXlibDisplayEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetRandROutputDisplayEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.DisplayPowerControlEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.RegisterDeviceEventEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.RegisterDisplayEventEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetSwapchainCounterEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetRefreshCycleDurationGOOGLE_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPastPresentationTimingGOOGLE_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateIOSSurfaceMVK_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateMacOSSurfaceMVK_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.SetDebugUtilsObjectNameEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.SetDebugUtilsObjectTagEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateDebugUtilsMessengerEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetAndroidHardwareBufferPropertiesANDROID_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetMemoryAndroidHardwareBufferANDROID_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetImageDrmFormatModifierPropertiesEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateValidationCacheEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.MergeValidationCachesEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetValidationCacheDataEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateAccelerationStructureNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.BindAccelerationStructureMemoryNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateRayTracingPipelinesNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetRayTracingShaderGroupHandlesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetRayTracingShaderGroupHandlesNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetAccelerationStructureHandleNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CompileDeferredNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetMemoryHostPointerPropertiesEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetCalibratedTimestampsEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.InitializePerformanceApiINTEL_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetPerformanceMarkerINTEL_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetPerformanceStreamMarkerINTEL_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CmdSetPerformanceOverrideINTEL_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.AcquirePerformanceConfigurationINTEL_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ReleasePerformanceConfigurationINTEL_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.QueueSetPerformanceConfigurationINTEL_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPerformanceParameterINTEL_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateImagePipeSurfaceFUCHSIA_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateMetalSurfaceEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceToolPropertiesEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceSurfacePresentModes2EXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.AcquireFullScreenExclusiveModeEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ReleaseFullScreenExclusiveModeEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceGroupSurfacePresentModes2EXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateHeadlessSurfaceEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ReleaseSwapchainImagesEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateIndirectCommandsLayoutNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.AcquireDrmDisplayEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDrmDisplayEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreatePrivateDataSlotEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.SetPrivateDataEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDeviceFaultInfoEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.AcquireWinrtDisplayNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetWinrtDisplayNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateDirectFBSurfaceEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetMemoryZirconHandleFUCHSIA_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetMemoryZirconHandlePropertiesFUCHSIA_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.ImportSemaphoreZirconHandleFUCHSIA_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetSemaphoreZirconHandleFUCHSIA_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetMemoryRemoteAddressNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateScreenSurfaceQNX_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateMicromapEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.BuildMicromapsEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CopyMicromapEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CopyMicromapToMemoryEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CopyMemoryToMicromapEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.WriteMicromapsPropertiesEXT_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateOpticalFlowSessionNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.BindOpticalFlowSessionImageNV_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetFramebufferTilePropertiesQCOM_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetDynamicRenderingTilePropertiesQCOM_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateAccelerationStructureKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CopyAccelerationStructureToMemoryKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CopyMemoryToAccelerationStructureKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.WriteAccelerationStructuresPropertiesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.CreateRayTracingPipelinesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

template <>
struct ConsumerPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult result, Args... args)
    {
        assert(consumer);

        for (auto &plugin : consumer->loaded_plugins_)
        {
            plugin.func_table_post.GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall(consumer, call_info, result, args...);
        }
    }
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif // GFXRECON_DECODE_GENERATED_VULKAN_CONSUMER_POST_COMMANDS_H
