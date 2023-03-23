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

#include "perfetto_encoder_commands.h"
#include "perfetto_tracing_categories.h"
#include "encode/vulkan_capture_manager.h"
#include "format/api_call_id.h"
#include "util/defines.h"

#include <thread>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugins)
GFXRECON_BEGIN_NAMESPACE(plugin_perfetto)

using namespace encode;

#if !defined(WIN32)

void InitializePerfetto(VulkanCaptureManager* manager)
{
    static bool initialized = false;

    assert(manager);

    if (!initialized && manager->GetEmitPerfettoData())
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

void Process_QueueSubmit(
    VulkanCaptureManager* manager, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence)
{
    const uint64_t    command_index = manager->GetBlockIndex();
    const std::string submit_name   = "QueueSubmit: " + std::to_string(command_index);

    // Piggyback fence
    if (fence != VK_NULL_HANDLE)
    {
        QueueWrapper* queue_wrapper = reinterpret_cast<QueueWrapper*>(queue);
        assert(queue_wrapper);

        DeviceWrapper* device_wrapper = queue_wrapper->device_wrapper;
        assert(device_wrapper);

        FenceWrapper* fence_wrapper = reinterpret_cast<FenceWrapper*>(fence);
        assert(fence_wrapper);

        TRACE_EVENT_INSTANT("GFXR", perfetto::DynamicString{ submit_name.c_str() }, "Command ID:", command_index);
        TRACE_EVENT_BEGIN("GFXR",
                          perfetto::DynamicString{ submit_name.c_str() },
                          perfetto::Track(command_index),
                          "Command ID:",
                          command_index);

        std::thread worker_thread([=] {
            queue_wrapper->layer_table_ref->WaitForFences(
                device_wrapper->handle, 1, &fence_wrapper->handle, VK_TRUE, UINT64_MAX);

            // Close the slice for the request now that we finished handling it.
            TRACE_EVENT_END("GFXR", perfetto::Track(command_index));
        });

        worker_thread.detach();
    }
    else
    {
        // Piggyback a signal semaphore
        VkSemaphore sem = VK_NULL_HANDLE;
        if (submitCount && pSubmits)
        {
            for (uint32_t i = 0; i < submitCount; ++i)
            {
                if (pSubmits[i].signalSemaphoreCount && pSubmits[i].pSignalSemaphores)
                {
                    sem = pSubmits[i].pSignalSemaphores[0];
                    break;
                }
            }
        }

        QueueWrapper* queue_wrapper = reinterpret_cast<QueueWrapper*>(queue);
        assert(queue_wrapper);

        DeviceWrapper* device_wrapper = queue_wrapper->device_wrapper;
        assert(device_wrapper);

        if (queue_wrapper->layer_table_ref->WaitSemaphores != noop::WaitSemaphores && sem != VK_NULL_HANDLE)
        {
            SemaphoreWrapper* sem_wrapper = reinterpret_cast<SemaphoreWrapper*>(sem);
            assert(sem_wrapper);

            TRACE_EVENT_INSTANT("GFXR", perfetto::DynamicString{ submit_name.c_str() }, "Command ID:", command_index);
            TRACE_EVENT_BEGIN("GFXR",
                              perfetto::DynamicString{ submit_name.c_str() },
                              perfetto::Track(command_index),
                              "Command ID:",
                              command_index);

            std::thread worker_thread([=] {
                const uint64_t            value[]   = { 1 };
                const VkSemaphoreWaitInfo wait_info = { VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO,
                                                        nullptr,
                                                        VkSemaphoreWaitFlags(0),
                                                        1,
                                                        &sem_wrapper->handle,
                                                        value };
                queue_wrapper->layer_table_ref->WaitSemaphores(device_wrapper->handle, &wait_info, UINT64_MAX);

                // Close the slice for the request now that we finished handling it.
                TRACE_EVENT_END("GFXR", perfetto::Track(command_index));
            });

            worker_thread.detach();
        }
        else
        {
            // Nothing to piggyback
            GFXRECON_LOG_WARNING("No perfetto data emitted for vkQueueSubmit(%" PRIu64 ")", command_index);
            TRACE_EVENT_INSTANT("GFXR", perfetto::DynamicString{ submit_name.c_str() }, "Command ID:", command_index);
        }
    }
}

#endif // !defined(WIN32)

GFXRECON_END_NAMESPACE(plugin_perfetto)
GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)
