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

#ifndef GFXRECON_PLUGINS_PERFETTO_
#define GFXRECON_PLUGINS_PERFETTO_

#include "decode/vulkan_replay_consumer_base.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/handle_pointer_decoder.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "format/api_call_id.h"
#include "util/defines.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugins)
GFXRECON_BEGIN_NAMESPACE(replay)
GFXRECON_BEGIN_NAMESPACE(plugin_perfetto)

template <format::ApiCallId Id>
struct PerfettoReplayPreCall
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase*, const decode::ApiCallInfo&, Args...)
    {}
};

template <format::ApiCallId Id>
struct PerfettoEncoderPostCall
{
    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase*, const decode::ApiCallInfo&, Args...)
    {}

    template <typename... Args>
    static void Dispatch(VulkanReplayConsumerBase*, const decode::ApiCallInfo&, VkResult, Args...)
    {}
};

#if !defined(WIN32)

void InitializePerfetto();
void Process_QueueSubmit(decode::VulkanReplayConsumerBase*                   consumer,
                         const decode::ApiCallInfo&                          call_info,
                         VkResult                                            returnValue,
                         format::HandleId                                    queue,
                         uint32_t                                            submitCount,
                         decode::StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                         format::HandleId                                    fence);

void Process_QueuePresent(decode::VulkanReplayConsumerBase*                       consumer,
                          const decode::ApiCallInfo&                              call_info,
                          VkResult                                                returnValue,
                          format::HandleId                                        queue,
                          decode::StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo);

template <>
struct PerfettoReplayPreCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(decode::VulkanReplayConsumerBase* consumer, const decode::ApiCallInfo& call_info, Args... args)
    {
        InitializePerfetto();
    }
};

template <>
struct PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(decode::VulkanReplayConsumerBase* consumer, const decode::ApiCallInfo& call_info, VkResult result, Args... args)
    {
        InitializePerfetto();
    }
};

template <>
struct PerfettoReplayPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    template <typename... Args>
    static void Dispatch(decode::VulkanReplayConsumerBase* consumer, const decode::ApiCallInfo& call_info, Args... args)
    {
        Process_QueuePresent(consumer, call_info, args...);
    }
};

template <>
struct PerfettoReplayPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(decode::VulkanReplayConsumerBase* consumer, const decode::ApiCallInfo& call_info, Args... args)
    {
        assert(consumer);

        Process_QueueSubmit(consumer, call_info, args...);
    }
};

#endif // !defined(WIN32)

GFXRECON_END_NAMESPACE(plugin_perfetto)
GFXRECON_END_NAMESPACE(replay)
GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_PLUGINS_PERFETTO_VULKAN_REPLAY_COMMANDS_H
