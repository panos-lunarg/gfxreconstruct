/*
** Copyright (c) 2019-2020 Valve Corporation
** Copyright (c) 2019-2023 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_OPTIONS_H
#define GFXRECON_DECODE_VULKAN_REPLAY_OPTIONS_H

#include "decode/replay_options.h"

#include "decode/vulkan_resource_allocator.h"
#include "util/defines.h"

#include <functional>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

typedef std::function<VulkanResourceAllocator*()> CreateResourceAllocator;

// Default log level to use prior to loading settings.
const util::Log::Severity kDefaultLogLevel = util::Log::Severity::kInfoSeverity;

// Sascha's Compute ray tracing
// static constexpr uint64_t g_BeginCommandBuffer_Index = 185;
// static constexpr uint64_t g_CmdDraw_Index            = 0;
// static constexpr uint64_t g_CmdDispatch_Index        = 189;
// static constexpr uint64_t g_CmdTraceRaysKHR_Index    = 0;
// static constexpr uint64_t g_QueueSubmit_Index        = 1942;

// Modified vkCube
static constexpr uint64_t                 g_BeginCommandBuffer_Index = { 107 };
static std::vector<std::vector<uint64_t>> g_CmdDraw_Index            = { { 113, 114, 115, 116, 117 } };
static constexpr uint64_t                 g_CmdDispatch_Index        = 0;
static constexpr uint64_t                 g_CmdTraceRaysKHR_Index    = 0;
static constexpr uint64_t                 g_QueueSubmit_Index        = { 579 };

static constexpr bool g_isolate_draw = false;

struct VulkanReplayOptions : public ReplayOptions
{
    bool                         enable_vulkan{ true };
    bool                         skip_failed_allocations{ false };
    bool                         omit_pipeline_cache_data{ false };
    bool                         remove_unsupported_features{ false };
    bool                         use_colorspace_fallback{ false };
    bool                         dumping_resource{ true };
    util::SwapchainOption        swapchain_option{ util::SwapchainOption::kVirtual };
    int32_t                      override_gpu_group_index{ -1 };
    int32_t                      surface_index{ -1 };
    CreateResourceAllocator      create_resource_allocator;
    util::ScreenshotFormat       screenshot_format{ util::ScreenshotFormat::kBmp };
    std::vector<ScreenshotRange> screenshot_ranges;
    std::string                  screenshot_dir;
    std::string                  screenshot_file_prefix{ kDefaultScreenshotFilePrefix };
    uint32_t                     screenshot_width, screenshot_height;
    float                        screenshot_scale;
    std::string                  replace_dir;

    std::vector<uint64_t>              BeginCommandBuffer_Index{ std::move(g_BeginCommandBuffer_Index) };
    std::vector<std::vector<uint64_t>> CmdDraw_Index{ std::move(g_CmdDraw_Index) };
    uint64_t                           CmdDispatch_Index{ g_CmdDispatch_Index };
    uint64_t                           CmdTraceRaysKHR_Index{ g_CmdTraceRaysKHR_Index };
    std::vector<uint64_t>              QueueSubmit_Index{ std::move(g_QueueSubmit_Index) };
    bool                               isolate_draw{ g_isolate_draw };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_OPTIONS_H
