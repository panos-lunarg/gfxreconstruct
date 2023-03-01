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

#ifndef GFXRECON_ENCODE_GENERATED_PERFETTO_VULKAN_ENCODER_COMMANDS_H
#define GFXRECON_ENCODE_GENERATED_PERFETTO_VULKAN_ENCODER_COMMANDS_H

#include "encode/perfetto/custom_perfetto_encoder_commands.h"
#include "encode/perfetto/perfetto_tracing_categories.h"
#include "encode/vulkan_capture_manager.h"
#include "format/api_call_id.h"
#include "util/defines.h"

#include <iostream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <format::ApiCallId Id>
struct PerfettoEncoderPreCall
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*, Args...)
    {}
};

template <format::ApiCallId Id>
struct PerfettoEncoderPostCall
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*, Args...)
    {}

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*, VkResult, Args...)
    {}
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        CustomPerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, args...);
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        CustomPerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, args...);
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        CustomPerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, result, args...);
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyInstance", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkEnumeratePhysicalDevices", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceFeatures", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceFormatProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceImageFormatProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceQueueFamilyProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceMemoryProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetInstanceProcAddr", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceProcAddr", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateDevice", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyDevice", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkEnumerateInstanceExtensionProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkEnumerateDeviceExtensionProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkEnumerateInstanceLayerProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkEnumerateDeviceLayerProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceQueue", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        CustomPerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, args...);
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        CustomPerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, args...);
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        CustomPerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, result, args...);
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkQueueWaitIdle", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDeviceWaitIdle", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkAllocateMemory", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkFreeMemory", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkMapMemory", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkUnmapMemory", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkFlushMappedMemoryRanges", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkInvalidateMappedMemoryRanges", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceMemoryCommitment", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkBindBufferMemory", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkBindImageMemory", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetBufferMemoryRequirements", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetImageMemoryRequirements", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetImageSparseMemoryRequirements", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceSparseImageFormatProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkQueueBindSparse", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateFence", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyFence", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkResetFences", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetFenceStatus", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkWaitForFences", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateSemaphore", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroySemaphore", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateEvent", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyEvent", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetEventStatus", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkSetEvent", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkResetEvent", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateQueryPool", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyQueryPool", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetQueryPoolResults", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateBuffer", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyBuffer", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateBufferView", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyBufferView", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateImage", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyImage", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetImageSubresourceLayout", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateImageView", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyImageView", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateShaderModule", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyShaderModule", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreatePipelineCache", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyPipelineCache", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPipelineCacheData", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkMergePipelineCaches", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateGraphicsPipelines", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateComputePipelines", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyPipeline", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreatePipelineLayout", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyPipelineLayout", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateSampler", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySampler>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroySampler", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateDescriptorSetLayout", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyDescriptorSetLayout", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateDescriptorPool", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyDescriptorPool", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkResetDescriptorPool", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkAllocateDescriptorSets", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkFreeDescriptorSets", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkUpdateDescriptorSets", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateFramebuffer", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyFramebuffer", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateRenderPass", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyRenderPass", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetRenderAreaGranularity", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateCommandPool", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyCommandPool", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkResetCommandPool", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkAllocateCommandBuffers", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkFreeCommandBuffers", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkBeginCommandBuffer", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkEndCommandBuffer", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkResetCommandBuffer", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBindPipeline", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetViewport", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetScissor", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetLineWidth", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthBias", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetBlendConstants", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthBounds", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetStencilCompareMask", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetStencilWriteMask", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetStencilReference", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBindDescriptorSets", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBindIndexBuffer", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBindVertexBuffers", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDraw>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDraw", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawIndexed", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawIndirect", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawIndexedIndirect", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDispatch", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDispatchIndirect", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyBuffer", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyImage", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBlitImage", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyBufferToImage", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyImageToBuffer", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdUpdateBuffer", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdFillBuffer", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdClearColorImage", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdClearDepthStencilImage", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdClearAttachments", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdResolveImage", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetEvent", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdResetEvent", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdWaitEvents", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdPipelineBarrier", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBeginQuery", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdEndQuery", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdResetQueryPool", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdWriteTimestamp", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyQueryPoolResults", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdPushConstants", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBeginRenderPass", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdNextSubpass", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdEndRenderPass", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdExecuteCommands", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkEnumerateInstanceVersion", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkBindBufferMemory2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkBindImageMemory2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceGroupPeerMemoryFeatures", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDeviceMask", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDispatchBase", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkEnumeratePhysicalDeviceGroups", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetImageMemoryRequirements2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetBufferMemoryRequirements2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetImageSparseMemoryRequirements2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceFeatures2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceProperties2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceFormatProperties2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceImageFormatProperties2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceQueueFamilyProperties2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceMemoryProperties2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceSparseImageFormatProperties2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkTrimCommandPool", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceQueue2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateSamplerYcbcrConversion", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroySamplerYcbcrConversion", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateDescriptorUpdateTemplate", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyDescriptorUpdateTemplate", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkUpdateDescriptorSetWithTemplate", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceExternalBufferProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceExternalFenceProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceExternalSemaphoreProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDescriptorSetLayoutSupport", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroySurfaceKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceSurfaceSupportKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceSurfaceCapabilitiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceSurfaceFormatsKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceSurfacePresentModesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateSwapchainKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroySwapchainKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetSwapchainImagesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkAcquireNextImageKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        CustomPerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, args...);
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        CustomPerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, args...);
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        CustomPerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, result, args...);
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceGroupPresentCapabilitiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceGroupSurfacePresentModesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDevicePresentRectanglesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkAcquireNextImage2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceDisplayPropertiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceDisplayPlanePropertiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDisplayPlaneSupportedDisplaysKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDisplayModePropertiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateDisplayModeKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDisplayPlaneCapabilitiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateDisplayPlaneSurfaceKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateSharedSwapchainsKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateXlibSurfaceKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceXlibPresentationSupportKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateXcbSurfaceKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceXcbPresentationSupportKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateWaylandSurfaceKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceWaylandPresentationSupportKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateMirSurfaceKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceMirPresentationSupportKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateAndroidSurfaceKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateWin32SurfaceKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceWin32PresentationSupportKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceFeatures2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceProperties2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceFormatProperties2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceImageFormatProperties2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceQueueFamilyProperties2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceMemoryProperties2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceSparseImageFormatProperties2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceGroupPeerMemoryFeaturesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDeviceMaskKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDispatchBaseKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkTrimCommandPoolKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkEnumeratePhysicalDeviceGroupsKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceExternalBufferPropertiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetMemoryWin32HandleKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetMemoryWin32HandlePropertiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetMemoryFdKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetMemoryFdPropertiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkImportSemaphoreWin32HandleKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetSemaphoreWin32HandleKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkImportSemaphoreFdKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetSemaphoreFdKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdPushDescriptorSetKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdPushDescriptorSetWithTemplateKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateDescriptorUpdateTemplateKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyDescriptorUpdateTemplateKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkUpdateDescriptorSetWithTemplateKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateRenderPass2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBeginRenderPass2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdNextSubpass2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdEndRenderPass2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetSwapchainStatusKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceExternalFencePropertiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkImportFenceWin32HandleKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetFenceWin32HandleKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkImportFenceFdKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetFenceFdKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceSurfaceCapabilities2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceSurfaceFormats2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceDisplayProperties2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceDisplayPlaneProperties2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDisplayModeProperties2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDisplayPlaneCapabilities2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetImageMemoryRequirements2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetBufferMemoryRequirements2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetImageSparseMemoryRequirements2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateSamplerYcbcrConversionKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroySamplerYcbcrConversionKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkBindBufferMemory2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkBindImageMemory2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDescriptorSetLayoutSupportKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawIndirectCountKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawIndexedIndirectCountKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateDebugReportCallbackEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyDebugReportCallbackEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDebugReportMessageEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDebugMarkerSetObjectTagEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDebugMarkerSetObjectNameEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDebugMarkerBeginEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDebugMarkerEndEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDebugMarkerInsertEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawIndirectCountAMD", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawIndexedIndirectCountAMD", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetShaderInfoAMD", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceExternalImageFormatPropertiesNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetMemoryWin32HandleNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateViSurfaceNN", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBeginConditionalRenderingEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdEndConditionalRenderingEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdProcessCommandsNVX", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdReserveSpaceForCommandsNVX", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateIndirectCommandsLayoutNVX", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyIndirectCommandsLayoutNVX", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateObjectTableNVX", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyObjectTableNVX", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkRegisterObjectsNVX", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkUnregisterObjectsNVX", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetViewportWScalingNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkReleaseDisplayEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkAcquireXlibDisplayEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetRandROutputDisplayEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceSurfaceCapabilities2EXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDisplayPowerControlEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkRegisterDeviceEventEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkRegisterDisplayEventEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetSwapchainCounterEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetRefreshCycleDurationGOOGLE", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPastPresentationTimingGOOGLE", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDiscardRectangleEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkSetHdrMetadataEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateIOSSurfaceMVK", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateMacOSSurfaceMVK", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkSetDebugUtilsObjectNameEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkSetDebugUtilsObjectTagEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkQueueBeginDebugUtilsLabelEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkQueueEndDebugUtilsLabelEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkQueueInsertDebugUtilsLabelEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBeginDebugUtilsLabelEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdEndDebugUtilsLabelEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdInsertDebugUtilsLabelEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateDebugUtilsMessengerEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyDebugUtilsMessengerEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkSubmitDebugUtilsMessageEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetAndroidHardwareBufferPropertiesANDROID", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetMemoryAndroidHardwareBufferANDROID", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetSampleLocationsEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceMultisamplePropertiesEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateValidationCacheEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyValidationCacheEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkMergeValidationCachesEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetValidationCacheDataEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetMemoryHostPointerPropertiesEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdWriteBufferMarkerAMD", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBindShadingRateImageNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetViewportShadingRatePaletteNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetCoarseSampleOrderNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetImageDrmFormatModifierPropertiesEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateAccelerationStructureNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyAccelerationStructureNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetAccelerationStructureMemoryRequirementsNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkBindAccelerationStructureMemoryNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBuildAccelerationStructureNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyAccelerationStructureNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdTraceRaysNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateRayTracingPipelinesNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetRayTracingShaderGroupHandlesNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetAccelerationStructureHandleNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdWriteAccelerationStructuresPropertiesNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCompileDeferredNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawMeshTasksNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawMeshTasksIndirectNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawMeshTasksIndirectCountNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetExclusiveScissorNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetCheckpointNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetQueueCheckpointDataNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateImagePipeSurfaceFUCHSIA", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBindTransformFeedbackBuffersEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBeginTransformFeedbackEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdEndTransformFeedbackEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBeginQueryIndexedEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdEndQueryIndexedEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawIndirectByteCountEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetCalibratedTimestampsEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetBufferDeviceAddressEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetImageViewHandleNVX", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateMetalSurfaceEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateStreamDescriptorSurfaceGGP", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkSetLocalDimmingAMD", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceSurfacePresentModes2EXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkAcquireFullScreenExclusiveModeEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkReleaseFullScreenExclusiveModeEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceGroupSurfacePresentModes2EXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateHeadlessSurfaceEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkResetQueryPoolEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPipelineExecutablePropertiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPipelineExecutableStatisticsKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPipelineExecutableInternalRepresentationsKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkInitializePerformanceApiINTEL", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkUninitializePerformanceApiINTEL", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetPerformanceMarkerINTEL", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetPerformanceStreamMarkerINTEL", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetPerformanceOverrideINTEL", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkAcquirePerformanceConfigurationINTEL", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkReleasePerformanceConfigurationINTEL", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkQueueSetPerformanceConfigurationINTEL", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPerformanceParameterINTEL", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetLineStippleEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetSemaphoreCounterValueKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkWaitSemaphoresKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkSignalSemaphoreKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkAcquireProfilingLockKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkReleaseProfilingLockKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetBufferDeviceAddressKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetBufferOpaqueCaptureAddressKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceMemoryOpaqueCaptureAddressKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceToolPropertiesEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawIndirectCount", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawIndexedIndirectCount", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateRenderPass2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBeginRenderPass2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdNextSubpass2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdEndRenderPass2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkResetQueryPool", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetSemaphoreCounterValue", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphores>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkWaitSemaphores", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkSignalSemaphore", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetBufferDeviceAddress", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetBufferOpaqueCaptureAddress", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceMemoryOpaqueCaptureAddress", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateDeferredOperationKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyDeferredOperationKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeferredOperationMaxConcurrencyKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeferredOperationResultKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDeferredOperationJoinKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateAccelerationStructureKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyAccelerationStructureKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetAccelerationStructureMemoryRequirementsKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkBindAccelerationStructureMemoryKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBuildAccelerationStructuresKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBuildAccelerationStructuresIndirectKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkBuildAccelerationStructuresKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCopyAccelerationStructureKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCopyAccelerationStructureToMemoryKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCopyMemoryToAccelerationStructureKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkWriteAccelerationStructuresPropertiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyAccelerationStructureKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyAccelerationStructureToMemoryKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyMemoryToAccelerationStructureKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdTraceRaysKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateRayTracingPipelinesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetRayTracingShaderGroupHandlesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdWriteAccelerationStructuresPropertiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetAccelerationStructureDeviceAddressKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdTraceRaysIndirectKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceAccelerationStructureCompatibilityKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetGeneratedCommandsMemoryRequirementsNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdPreprocessGeneratedCommandsNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdExecuteGeneratedCommandsNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBindPipelineShaderGroupNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateIndirectCommandsLayoutNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyIndirectCommandsLayoutNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetImageViewAddressNVX", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreatePrivateDataSlotEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyPrivateDataSlotEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkSetPrivateDataEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPrivateDataEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetCullModeEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetFrontFaceEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetPrimitiveTopologyEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetViewportWithCountEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetScissorWithCountEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBindVertexBuffers2EXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthTestEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthWriteEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthCompareOpEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthBoundsTestEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetStencilTestEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetStencilOpEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateDirectFBSurfaceEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceDirectFBPresentationSupportEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyBuffer2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyImage2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyBufferToImage2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyImageToBuffer2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBlitImage2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdResolveImage2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetAccelerationStructureBuildSizesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetRayTracingShaderGroupStackSizeKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetRayTracingPipelineStackSizeKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceFragmentShadingRatesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetFragmentShadingRateKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetFragmentShadingRateEnumNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkAcquireWinrtDisplayNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetWinrtDisplayNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetEvent2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdResetEvent2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdWaitEvents2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdPipelineBarrier2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdWriteTimestamp2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkQueueSubmit2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdWriteBufferMarker2AMD", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetQueueCheckpointData2NV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetVertexInputEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetMemoryZirconHandleFUCHSIA", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetMemoryZirconHandlePropertiesFUCHSIA", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkImportSemaphoreZirconHandleFUCHSIA", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetSemaphoreZirconHandleFUCHSIA", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetPatchControlPointsEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetRasterizerDiscardEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthBiasEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetLogicOpEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetPrimitiveRestartEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateScreenSurfaceQNX", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceScreenPresentationSupportQNX", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetColorWriteEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkAcquireDrmDisplayEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDrmDisplayEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawMultiEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawMultiIndexedEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkWaitForPresentKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBindInvocationMaskHUAWEI", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetMemoryRemoteAddressNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceBufferMemoryRequirementsKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceImageMemoryRequirementsKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceImageSparseMemoryRequirementsKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkSetDeviceMemoryPriorityEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBeginRenderingKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdEndRenderingKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceToolProperties", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreatePrivateDataSlot", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyPrivateDataSlot", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkSetPrivateData", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPrivateData", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetEvent2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdResetEvent2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdWaitEvents2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdPipelineBarrier2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdWriteTimestamp2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkQueueSubmit2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyBuffer2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyImage2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyBufferToImage2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyImageToBuffer2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBlitImage2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdResolveImage2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBeginRendering", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdEndRendering", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetCullMode", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetFrontFace", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetPrimitiveTopology", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetViewportWithCount", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetScissorWithCount", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBindVertexBuffers2", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthTestEnable", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthWriteEnable", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthCompareOp", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthBoundsTestEnable", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetStencilTestEnable", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetStencilOp", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetRasterizerDiscardEnable", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthBiasEnable", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetPrimitiveRestartEnable", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceBufferMemoryRequirements", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceImageMemoryRequirements", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceImageSparseMemoryRequirements", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDescriptorSetLayoutHostMappingInfoVALVE", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDescriptorSetHostMappingVALVE", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdTraceRaysIndirect2KHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetImageSubresourceLayout2EXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelinePropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPipelinePropertiesEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelinePropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetShaderModuleIdentifierEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetShaderModuleCreateInfoIdentifierEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetFramebufferTilePropertiesQCOM", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDynamicRenderingTilePropertiesQCOM", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceFaultInfoEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateMicromapEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyMicromapEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBuildMicromapsEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkBuildMicromapsEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCopyMicromapEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCopyMicromapToMemoryEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCopyMemoryToMicromapEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkWriteMicromapsPropertiesEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyMicromapEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyMicromapToMemoryEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdCopyMemoryToMicromapEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdWriteMicromapsPropertiesEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetDeviceMicromapCompatibilityEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetMicromapBuildSizesEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetTessellationDomainOriginEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthClampEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetPolygonModeEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetRasterizationSamplesEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetSampleMaskEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetAlphaToCoverageEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetAlphaToOneEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetLogicOpEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetColorBlendEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetColorBlendEquationEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetColorWriteMaskEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetRasterizationStreamEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetConservativeRasterizationModeEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetExtraPrimitiveOverestimationSizeEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthClipEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetSampleLocationsEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetColorBlendAdvancedEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetProvokingVertexModeEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetLineRasterizationModeEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetLineStippleEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDepthClipNegativeOneToOneEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetViewportWScalingEnableNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetViewportSwizzleNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetCoverageToColorEnableNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetCoverageToColorLocationNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetCoverageModulationModeNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetCoverageModulationTableEnableNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetCoverageModulationTableNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetShadingRateImageEnableNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetRepresentativeFragmentTestEnableNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetCoverageReductionModeNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceOpticalFlowImageFormatsNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateOpticalFlowSessionNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyOpticalFlowSessionNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkBindOpticalFlowSessionImageNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdOpticalFlowExecuteNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawMeshTasksEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawMeshTasksIndirectEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawMeshTasksIndirectCountEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkReleaseSwapchainImagesEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawClusterHUAWEI", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDrawClusterIndirectHUAWEI", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceVideoCapabilitiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetPhysicalDeviceVideoFormatPropertiesKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateVideoSessionKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyVideoSessionKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkGetVideoSessionMemoryRequirementsKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkBindVideoSessionMemoryKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCreateVideoSessionParametersKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkUpdateVideoSessionParametersKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkDestroyVideoSessionParametersKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdBeginVideoCodingKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdEndVideoCodingKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdControlVideoCodingKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdDecodeVideoKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdEncodeVideoKHR", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDiscardRectangleEnableEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetDiscardRectangleModeEXT", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_BEGIN("GFXR", "vkCmdSetExclusiveScissorEnableNV", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);
        TRACE_EVENT_END("GFXR");
    }
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(encode)

#endif /* GFXRECON_ENCODE_GENERATED_PERFETTO_VULKAN_ENCODER_COMMANDS_H */
