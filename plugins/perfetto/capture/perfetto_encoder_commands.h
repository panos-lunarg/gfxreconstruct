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

#ifndef GFXRECON_PLUGINS_CUSTOM_PERFETTO_VULKAN_ENCODER_COMMANDS_H
#define GFXRECON_PLUGINS_CUSTOM_PERFETTO_VULKAN_ENCODER_COMMANDS_H

#include "encode/vulkan_capture_manager.h"
#include "format/api_call_id.h"
#include "util/defines.h"

#include <iostream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugins)
GFXRECON_BEGIN_NAMESPACE(capture)
GFXRECON_BEGIN_NAMESPACE(plugin_perfetto)

using namespace encode;

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

#if !defined(WIN32)

void InitializePerfetto();
void Process_QueueSubmit(
    VulkanCaptureManager* manager, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
void Process_QueuePresent(VulkanCaptureManager* manager, VkQueue queue, const VkPresentInfoKHR* pPresentInfo);

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        InitializePerfetto();
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        InitializePerfetto();
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        Process_QueuePresent(manager, args...);
    }
};

template <>
struct PerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        Process_QueueSubmit(manager, args...);
    }
};

#endif // !defined(WIN32)

GFXRECON_END_NAMESPACE(plugin_perfetto)
GFXRECON_END_NAMESPACE(capture)
GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_PLUGINS_CUSTOM_PERFETTO_VULKAN_ENCODER_COMMANDS_H
