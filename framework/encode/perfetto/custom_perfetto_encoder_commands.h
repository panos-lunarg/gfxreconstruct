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

#ifndef GFXRECON_ENCODE_CUSTOM_PERFETTO_VULKAN_ENCODER_COMMANDS_H
#define GFXRECON_ENCODE_CUSTOM_PERFETTO_VULKAN_ENCODER_COMMANDS_H

#include "encode/vulkan_capture_manager.h"
#include "encode/perfetto/perfetto_tracing_categories.h"
#include "format/api_call_id.h"
#include "util/defines.h"

#include <iostream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <format::ApiCallId Id>
struct CustomPerfettoEncoderPreCall
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*, Args...)
    {}
};

template <format::ApiCallId Id>
struct CustomPerfettoEncoderPostCall
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*, Args...)
    {}

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*, VkResult, Args...)
    {}
};

void Process_QueueSubmit(
    VulkanCaptureManager* manager, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);

void InitializePerfetto(VulkanCaptureManager* manager);

template <>
struct CustomPerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        TRACE_EVENT_BEGIN("GFXR", "vkCreateInstance", "Command ID:", manager->GetBlockIndex());
    }
};

template <>
struct CustomPerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        if (result == VK_SUCCESS)
        {
            InitializePerfetto(manager);
        }

        TRACE_EVENT_END("GFXR");
    }
};

template <>
struct CustomPerfettoEncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        const uint64_t    command_index = manager->GetBlockIndex();
        const std::string submit_name   = "QueuePresent: " + std::to_string(command_index);
        TRACE_EVENT_INSTANT("GFXR", perfetto::DynamicString{ submit_name.c_str() }, "Command ID:", command_index);
    }
};

template <>
struct CustomPerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        if (result == VK_SUCCESS)
        {
            Process_QueueSubmit(manager, args...);
        }
    }
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(encode)

#endif /* GFXRECON_ENCODE_CUSTOM_PERFETTO_VULKAN_ENCODER_COMMANDS_H */
