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

#include "perfetto_replay_commands.h"
#include "../perfetto_tracing_categories.h"
#include "util/defines.h"

#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugins)
GFXRECON_BEGIN_NAMESPACE(replay)
GFXRECON_BEGIN_NAMESPACE(plugin_perfetto)

using namespace decode;

#if !defined(WIN32)

void InitializePerfetto()
{
    static bool initialized = false;

    if (!initialized)
    {
        // Initialize perfetto
        perfetto::TracingInitArgs args;
        args.backends |= perfetto::kInProcessBackend;
        args.backends |= perfetto::kSystemBackend;
        perfetto::Tracing::Initialize(args);
        perfetto::TrackEvent::Register();

        initialized = true;
    }
}

void Process_QueueSubmit(decode::VulkanReplayConsumerBase*                   consumer,
                         const decode::ApiCallInfo&                          call_info,
                         VkResult                                            returnValue,
                         format::HandleId                                    queue,
                         uint32_t                                            submitCount,
                         decode::StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                         format::HandleId                                    fence)
{

    // TRACE_EVENT_INSTANT("GFXR", "vkQueueSubmit", [&](perfetto::EventContext ctx) {
    //     const std::string command_index = std::to_string(call_info.index);
    //     ctx.AddDebugAnnotation("vkQueueSubmit:", command_index.c_str());

    //     auto                handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    //     const VkSubmitInfo* pSubmits_unwrapped = UnwrapStructArrayHandles(pSubmits, submitCount, handle_unwrap_memory);

    //     std::vector<std::string> names, handles;
    //     for (uint32_t i = 0; i < pSubmits_unwrapped->commandBufferCount; ++i)
    //     {
    //         names.push_back("vkCommandBuffer: " + std::to_string(i));
    //         std::stringstream ss;
    //         ss << std::hex << pSubmits_unwrapped->pCommandBuffers[i];
    //         handles.push_back(ss.str());
    //         ctx.AddDebugAnnotation(names[i].c_str(), perfetto::DynamicString{ handles[i].c_str() });
    //     }
    // });
}

void Process_QueuePresent(decode::VulkanReplayConsumerBase*                       consumer,
                          const decode::ApiCallInfo&                              call_info,
                          VkResult                                                returnValue,
                          format::HandleId                                        queue,
                          decode::StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    assert(consumer);

    const uint64_t    command_index = call_info.index;
    const std::string submit_name   = "QueuePresent: " + std::to_string(command_index);
    TRACE_EVENT_INSTANT("GFXR", perfetto::DynamicString{ submit_name.c_str() }, "Command ID:", command_index);
}

#endif // !defined(WIN32)

GFXRECON_END_NAMESPACE(plugin_perfetto)
GFXRECON_END_NAMESPACE(replay)
GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)
