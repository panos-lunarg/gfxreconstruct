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

#ifndef GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_COMMANDS_H
#define GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_COMMANDS_H

#include "encode/custom_vulkan_encoder_commands.h"
#include "encode/perfetto/perfetto_encoder_commands.h"

#include "encode/vulkan_capture_manager.h"
#include "format/api_call_id.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <format::ApiCallId Id>
struct EncoderPreCall
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {}
};

template <format::ApiCallId Id>
struct EncoderPostCall
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {}

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult, Args... args)
    {}
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, args...);

        if (manager && manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySampler>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDraw>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<
            format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<
            format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<
            format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphores>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelinePropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelinePropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelinePropertiesEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelinePropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelinePropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelinePropertiesEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelinePropertiesEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelinePropertiesEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(manager,  args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(manager);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(manager);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>::Dispatch(manager, result, args...);
        }
    }
};

template <>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>::Dispatch(manager, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>::Dispatch(manager, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>::Dispatch(manager, args...);
        }
    }

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>::Dispatch(manager, result, args...);

        if (manager->GetEmitPerfettoData())
        {
            PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>::Dispatch(manager, result, args...);
        }
    }
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_COMMANDS_H
