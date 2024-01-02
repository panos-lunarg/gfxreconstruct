/*
** Copyright (c) 2019-2023 LunarG, Inc.
** Copyright (c) 2021-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "project_version.h"

#if defined(D3D12_SUPPORT)
#include "decode/dx_replay_options.h"
#include <initguid.h>
#include "generated/generated_dx12_decoder.h"
#endif
#include "decode/file_processor.h"
#include "decode/vulkan_default_allocator.h"
#include "decode/vulkan_realign_allocator.h"
#include "decode/vulkan_rebind_allocator.h"
#include "decode/vulkan_remap_allocator.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_resource_tracking_consumer.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "generated/generated_vulkan_decoder.h"
#include "util/argument_parser.h"
#include "util/logging.h"
#include "util/platform.h"
#include "util/options.h"
#include "util/strings.h"

#include "vulkan/vulkan_core.h"

#include <cstdlib>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

#ifndef GFXRECON_PLATFORM_SETTINGS_H
#define GFXRECON_PLATFORM_SETTINGS_H

const char kApplicationName[] = "GFXReconstruct Replay";
const char kCaptureLayer[]    = "VK_LAYER_LUNARG_gfxreconstruct";

const char kHelpShortOption[]                    = "-h";
const char kHelpLongOption[]                     = "--help";
const char kVersionOption[]                      = "--version";
const char kLogLevelArgument[]                   = "--log-level";
const char kLogFileArgument[]                    = "--log-file";
const char kLogDebugView[]                       = "--log-debugview";
const char kNoDebugPopup[]                       = "--no-debug-popup";
const char kOverrideGpuArgument[]                = "--gpu";
const char kOverrideGpuGroupArgument[]           = "--gpu-group";
const char kPausedOption[]                       = "--paused";
const char kPauseFrameArgument[]                 = "--pause-frame";
const char kSkipFailedAllocationShortOption[]    = "--sfa";
const char kSkipFailedAllocationLongOption[]     = "--skip-failed-allocations";
const char kDiscardCachedPsosShortOption[]       = "--dcp";
const char kDiscardCachedPsosLongOption[]        = "--discard-cached-psos";
const char kUseCachedPsosOption[]                = "--use-cached-psos";
const char kOmitPipelineCacheDataShortOption[]   = "--opcd";
const char kOmitPipelineCacheDataLongOption[]    = "--omit-pipeline-cache-data";
const char kWsiArgument[]                        = "--wsi";
const char kSurfaceIndexArgument[]               = "--surface-index";
const char kMemoryPortabilityShortOption[]       = "-m";
const char kMemoryPortabilityLongOption[]        = "--memory-translation";
const char kSyncOption[]                         = "--sync";
const char kRemoveUnsupportedOption[]            = "--remove-unsupported";
const char kValidateOption[]                     = "--validate";
const char kDebugDeviceLostOption[]              = "--debug-device-lost";
const char kCreateDummyAllocationsOption[]       = "--create-dummy-allocations";
const char kOmitNullHardwareBuffersLongOption[]  = "--omit-null-hardware-buffers";
const char kOmitNullHardwareBuffersShortOption[] = "--onhb";
const char kDeniedMessages[]                     = "--denied-messages";
const char kAllowedMessages[]                    = "--allowed-messages";
const char kShaderReplaceArgument[]              = "--replace-shaders";
const char kScreenshotAllOption[]                = "--screenshot-all";
const char kScreenshotRangeArgument[]            = "--screenshots";
const char kScreenshotFormatArgument[]           = "--screenshot-format";
const char kScreenshotDirArgument[]              = "--screenshot-dir";
const char kScreenshotFilePrefixArgument[]       = "--screenshot-prefix";
const char kScreenshotSizeArgument[]             = "--screenshot-size";
const char kScreenshotScaleArgument[]            = "--screenshot-scale";
const char kForceWindowedShortArgument[]         = "--fw";
const char kForceWindowedLongArgument[]          = "--force-windowed";
const char kOutput[]                             = "--output";
const char kMeasurementRangeArgument[]           = "--measurement-frame-range";
const char kMeasurementFileArgument[]            = "--measurement-file";
const char kQuitAfterMeasurementRangeOption[]    = "--quit-after-measurement-range";
const char kFlushMeasurementRangeOption[]        = "--flush-measurement-range";
const char kSwapchainOption[]                    = "--swapchain";
const char kEnableUseCapturedSwapchainIndices[] =
    "--use-captured-swapchain-indices"; // The same: util::SwapchainOption::kCaptured
const char kFormatArgument[]        = "--format";
const char kIncludeBinariesOption[] = "--include-binaries";
const char kExpandFlagsOption[]     = "--expand-flags";
const char kFilePerFrameOption[]    = "--file-per-frame";
#if defined(WIN32)
const char kApiFamilyOption[]             = "--api";
const char kDxTwoPassReplay[]             = "--dx12-two-pass-replay";
const char kDxOverrideObjectNames[]       = "--dx12-override-object-names";
const char kBatchingMemoryUsageArgument[] = "--batching-memory-usage";
#endif
const char kDumpResourcesArgument[]             = "--dump-resources";
const char kDumpResourcesBeforeDrawOption[]     = "--dump-resources-before-draw";

enum class WsiPlatform
{
    kAuto,
    kWin32,
    kXlib,
    kXcb,
    kWayland,
    kDisplay,
    kHeadless
};

const char kWsiPlatformAuto[]     = "auto";
const char kWsiPlatformWin32[]    = "win32";
const char kWsiPlatformXlib[]     = "xlib";
const char kWsiPlatformXcb[]      = "xcb";
const char kWsiPlatformWayland[]  = "wayland";
const char kWsiPlatformDisplay[]  = "display";
const char kWsiPlatformHeadless[] = "headless";

const char kMemoryTranslationNone[]    = "none";
const char kMemoryTranslationRemap[]   = "remap";
const char kMemoryTranslationRealign[] = "realign";
const char kMemoryTranslationRebind[]  = "rebind";

const char kSwapchainVirtual[]   = "virtual";
const char kSwapchainCaptured[]  = "captured";
const char kSwapchainOffscreen[] = "offscreen";

#if defined(WIN32)
const char kApiFamilyVulkan[] = "vulkan";
const char kApiFamilyD3D12[]  = "d3d12";
const char kApiFamilyAll[]    = "all";
#endif

const char kScreenshotFormatBmp[] = "bmp";
const char kScreenshotFormatPng[] = "png";

#if defined(__ANDROID__)
const char kDefaultScreenshotDir[] = "/sdcard";
#else
const char kDefaultScreenshotDir[] = "";
#endif

static void ProcessDisableDebugPopup(const gfxrecon::util::ArgumentParser& arg_parser)
{
#if defined(WIN32) && defined(_DEBUG)
    if (arg_parser.IsOptionSet(kNoDebugPopup))
    {
        _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    }
#endif
}

static void CheckActiveLayers(const std::string& list)
{
    if (!list.empty())
    {
        // Check for the presence of the layer name in the list of active layers.
        size_t start = list.find(kCaptureLayer);

        if (start != std::string::npos)
        {
            size_t end         = start + gfxrecon::util::platform::StringLength(kCaptureLayer);
            bool   match_start = false;
            bool   match_end   = false;

            // For an exact match, the start of the layer name is either at the start of the list or comes after a path
            // separator.
            if ((start == 0) || ((list[start - 1] == ';') || (list[start - 1] == ':')))
            {
                match_start = true;
            }

            // For an exact match, the end of the layer name is either at the end of the list or comes before a path
            // separator.
            if ((list.length() == end) || ((list[end] == ';') || (list[end] == ':')))
            {
                match_end = true;
            }

            if (match_start && match_end)
            {
                GFXRECON_LOG_WARNING("Replay tool has detected that the capture layer is enabled");
            }
        }
    }
}

static gfxrecon::decode::VulkanResourceAllocator* CreateDefaultAllocator()
{
    return new gfxrecon::decode::VulkanDefaultAllocator(
        "Try replay with the '-m remap' or '-m rebind' options to enable memory translation.");
}

static gfxrecon::decode::VulkanResourceAllocator* CreateRemapAllocator()
{
    return new gfxrecon::decode::VulkanRemapAllocator(
        "Try replay with the '-m rebind' option to enable advanced memory translation.");
}

static gfxrecon::decode::VulkanResourceAllocator* CreateRebindAllocator()
{
    return new gfxrecon::decode::VulkanRebindAllocator();
}

static gfxrecon::decode::CreateResourceAllocator
InitRealignAllocatorCreateFunc(const std::string&                              filename,
                               const gfxrecon::decode::VulkanReplayOptions&    replay_options,
                               gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table)
{
    // Enable first pass of replay to generate resource tracking information.
    GFXRECON_WRITE_CONSOLE("First pass of replay resource tracking for realign memory portability mode. This may take "
                           "some time. Please wait...");

    gfxrecon::decode::FileProcessor file_processor_resource_tracking;
    gfxrecon::decode::VulkanDecoder decoder;

    auto resource_tracking_consumer =
        new gfxrecon::decode::VulkanResourceTrackingConsumer(replay_options, tracked_object_info_table);

    if (file_processor_resource_tracking.Initialize(filename))
    {
        decoder.AddConsumer(resource_tracking_consumer);
        file_processor_resource_tracking.AddDecoder(&decoder);
        file_processor_resource_tracking.ProcessAllFrames();
        file_processor_resource_tracking.RemoveDecoder(&decoder);
        decoder.RemoveConsumer(resource_tracking_consumer);
    }

    // Sort the bound resources according to the binding offsets.
    resource_tracking_consumer->SortMemoriesBoundResourcesByOffset();

    // calculate the replay binding offset of the bound resources and replay memory allocation size
    resource_tracking_consumer->CalculateReplayBindingOffsetAndMemoryAllocationSize();

    GFXRECON_WRITE_CONSOLE("First pass of replay resource tracking done.");

    return [tracked_object_info_table]() -> gfxrecon::decode::VulkanResourceAllocator* {
        return new gfxrecon::decode::VulkanRealignAllocator(
            tracked_object_info_table, "Try replay with the '-m rebind' option to enable advanced memory translation.");
    };
}

static uint32_t GetPauseFrame(const gfxrecon::util::ArgumentParser& arg_parser)
{
    uint32_t    pause_frame = 0;
    const auto& value       = arg_parser.GetArgumentValue(kPauseFrameArgument);

    if (arg_parser.IsOptionSet(kPausedOption))
    {
        pause_frame = 1;
    }
    else if (!value.empty())
    {
        pause_frame = std::stoi(value);
    }

    return pause_frame;
}

static WsiPlatform GetWsiPlatform(const gfxrecon::util::ArgumentParser& arg_parser)
{
    WsiPlatform wsi_platform = WsiPlatform::kAuto;
    const auto& value        = arg_parser.GetArgumentValue(kWsiArgument);

    if (!value.empty())
    {
        if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformAuto, value.c_str()) == 0)
        {
            wsi_platform = WsiPlatform::kAuto;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformWin32, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_WIN32_KHR)
            wsi_platform = WsiPlatform::kWin32;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option \"%s\", which is not enabled on this system", value.c_str());
#endif
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformXlib, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_XLIB_KHR)
            wsi_platform = WsiPlatform::kXlib;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option %s, which is not enabled on this system", value.c_str());
#endif
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformXcb, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_XCB_KHR)
            wsi_platform = WsiPlatform::kXcb;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option \"%s\", which is not enabled on this system", value.c_str());
#endif
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformWayland, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
            wsi_platform = WsiPlatform::kWayland;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option \"%s\", which is not enabled on this system", value.c_str());
#endif
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformDisplay, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
            wsi_platform = WsiPlatform::kDisplay;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option \"%s\", which is not enabled on this system", value.c_str());
#endif
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformHeadless, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_HEADLESS)
            wsi_platform = WsiPlatform::kHeadless;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option \"%s\", which is not enabled on this system", value.c_str());
#endif
        }
        else
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized wsi option \"%s\"", value.c_str());
        }
    }

    return wsi_platform;
}

static std::string GetWsiExtensionName(WsiPlatform wsi_platform)
{
    switch (wsi_platform)
    {
#if defined(VK_USE_PLATFORM_WIN32_KHR)
        case WsiPlatform::kWin32:
        {
            return VK_KHR_WIN32_SURFACE_EXTENSION_NAME;
        }
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
        case WsiPlatform::kXlib:
        {
            return VK_KHR_XLIB_SURFACE_EXTENSION_NAME;
        }
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
        case WsiPlatform::kXcb:
        {
            return VK_KHR_XCB_SURFACE_EXTENSION_NAME;
        }
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
        case WsiPlatform::kWayland:
        {
            return VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME;
        }
#endif
#if defined(VK_USE_PLATFORM_HEADLESS)
        case WsiPlatform::kHeadless:
        {
            return VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME;
        }
#endif
        default:
        {
            return std::string();
        }
    }
}

static std::string GetWsiArgString()
{
    std::string wsi_args = kWsiPlatformAuto;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    wsi_args += ',';
    wsi_args += kWsiPlatformWin32;
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    wsi_args += ',';
    wsi_args += kWsiPlatformXlib;
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
    wsi_args += ',';
    wsi_args += kWsiPlatformXcb;
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    wsi_args += ',';
    wsi_args += kWsiPlatformWayland;
#endif
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
    wsi_args += ',';
    wsi_args += kWsiPlatformDisplay;
#endif
#if defined(VK_USE_PLATFORM_HEADLESS)
    wsi_args += ',';
    wsi_args += kWsiPlatformHeadless;
#endif
    return wsi_args;
}

// Modifies settings parameter with values set via command line
static void GetLogSettings(const gfxrecon::util::ArgumentParser& arg_parser,
                           gfxrecon::util::Log::Settings&        log_settings)
{
    // Parse log level
    gfxrecon::util::Log::Severity log_level;
    const std::string&            value_string = arg_parser.GetArgumentValue(kLogLevelArgument);
    if (value_string.empty() || !gfxrecon::util::Log::StringToSeverity(value_string, log_level))
    {
        log_level = gfxrecon::decode::kDefaultLogLevel;
        if (!value_string.empty())
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized log level option value \"%s\"", value_string.c_str());
        }
    }

    // Update settings
    log_settings.min_severity              = log_level;
    log_settings.file_name                 = arg_parser.GetArgumentValue(kLogFileArgument);
    log_settings.output_to_os_debug_string = arg_parser.IsOptionSet(kLogDebugView);
}

static void GetMeasurementFilename(const gfxrecon::util::ArgumentParser& arg_parser, std::string& file_name)
{
    file_name = arg_parser.GetArgumentValue(kMeasurementFileArgument);
    if (file_name.empty())
    {
#if defined(__ANDROID__)
        file_name = "/sdcard/gfxrecon-measurements.json";
#else
        file_name = "./gfxrecon-measurements.json";
#endif
    }
}

static gfxrecon::util::ScreenshotFormat GetScreenshotFormat(const gfxrecon::util::ArgumentParser& arg_parser)
{
    gfxrecon::util::ScreenshotFormat format = gfxrecon::util::ScreenshotFormat::kBmp;
    const auto&                      value  = arg_parser.GetArgumentValue(kScreenshotFormatArgument);

    if (!value.empty())
    {
        if (gfxrecon::util::platform::StringCompareNoCase(kScreenshotFormatBmp, value.c_str()) == 0)
        {
            format = gfxrecon::util::ScreenshotFormat::kBmp;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kScreenshotFormatPng, value.c_str()) == 0)
        {
            format = gfxrecon::util::ScreenshotFormat::kPng;
        }
        else
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized screenshot format option \"%s\"", value.c_str());
        }
    }

    return format;
}

static std::string GetScreenshotDir(const gfxrecon::util::ArgumentParser& arg_parser)
{
    const auto& value = arg_parser.GetArgumentValue(kScreenshotDirArgument);

    if (!value.empty())
    {
        return value;
    }

    return kDefaultScreenshotDir;
}

static void GetScreenshotSize(const gfxrecon::util::ArgumentParser& arg_parser, uint32_t& width, uint32_t& height)
{
    const auto& value = arg_parser.GetArgumentValue(kScreenshotSizeArgument);

    if (!value.empty())
    {
        std::size_t x = value.find("x");
        if (x != std::string::npos)
        {
            try
            {
                width  = std::stoul(value.substr(0, x));
                height = std::stoul(value.substr(x + 1));
            }
            catch (std::exception&)
            {
                GFXRECON_LOG_WARNING("Ignoring invalid screenshot width x height option. Expected format is "
                                     "--screenshot-size [width]x[height]");
                width = height = 0;
            }
        }
        else
        {
            width = height = 0;
        }
    }
    else
    {
        width = height = 0;
    }
}

static float GetScreenshotScale(const gfxrecon::util::ArgumentParser& arg_parser)
{
    const auto& value = arg_parser.GetArgumentValue(kScreenshotScaleArgument);

    float scale = 0.0f;

    if (!value.empty())
    {
        try
        {
            scale = std::stof(value);
        }
        catch (std::exception&)
        {
            GFXRECON_LOG_WARNING(
                "Ignoring invalid screenshot scale option. Expected format is --screenshot-scale [scale]");
        }
    }

    return scale;
}

static std::vector<gfxrecon::decode::ScreenshotRange>
GetScreenshotRanges(const gfxrecon::util::ArgumentParser& arg_parser)
{
    std::vector<gfxrecon::decode::ScreenshotRange> ranges;

    if (arg_parser.IsOptionSet(kScreenshotAllOption))
    {
        gfxrecon::decode::ScreenshotRange screenshot_range;
        screenshot_range.first = 1;
        screenshot_range.last  = std::numeric_limits<uint32_t>::max();
        ranges.emplace_back(std::move(screenshot_range));
    }
    else
    {
        const auto& value = arg_parser.GetArgumentValue(kScreenshotRangeArgument);

        if (!value.empty())
        {
            std::vector<gfxrecon::util::UintRange> frame_ranges =
                gfxrecon::util::GetUintRanges(value.c_str(), "screenshot frames");

            for (uint32_t i = 0; i < frame_ranges.size(); ++i)
            {
                gfxrecon::decode::ScreenshotRange range{};
                range.first = frame_ranges[i].first;
                range.last  = frame_ranges[i].last;
                ranges.push_back(range);
            }
        }
    }

    return ranges;
}

static bool
GetMeasurementFrameRange(const gfxrecon::util::ArgumentParser& arg_parser, uint32_t& start_frame, uint32_t& end_frame)
{
    start_frame = 1;
    end_frame   = std::numeric_limits<uint32_t>::max();

    const auto& value = arg_parser.GetArgumentValue(kMeasurementRangeArgument);
    if (!value.empty())
    {
        std::vector<std::string> values  = gfxrecon::util::strings::SplitString(value, '-');
        bool                     invalid = false;

        if (values.size() != 2)
        {
            GFXRECON_LOG_WARNING(
                "Ignoring invalid measurement frame range \"%s\". Must have format: <start_frame>-<end_frame>",
                value.c_str());
            invalid = true;
        }

        for (std::string& num : values)
        {
            gfxrecon::util::strings::RemoveWhitespace(num);

            // Check that the range string only contains numbers.
            const size_t count = std::count_if(num.begin(), num.end(), ::isdigit);
            if (count != num.length())
            {
                GFXRECON_LOG_WARNING(
                    "Ignoring invalid measurement frame range \"%s\", which contains non-numeric values",
                    value.c_str());
                invalid = true;
                break;
            }
        }

        if (!invalid)
        {
            uint32_t start_frame_arg = std::stoi(values[0]);
            uint32_t end_frame_arg   = std::stoi(values[1]);

            if (start_frame_arg >= end_frame_arg)
            {
                GFXRECON_LOG_WARNING("Ignoring invalid measurement frame range \"%s\", where first frame is "
                                     "greater than or equal to the last frame",
                                     value.c_str());

                return false;
            }

            start_frame = start_frame_arg;
            end_frame   = end_frame_arg;
            return true;
        }
    }

    return false;
}
static gfxrecon::decode::CreateResourceAllocator
GetCreateResourceAllocatorFunc(const gfxrecon::util::ArgumentParser&           arg_parser,
                               const std::string&                              filename,
                               const gfxrecon::decode::VulkanReplayOptions&    replay_options,
                               gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table)
{
    gfxrecon::decode::CreateResourceAllocator func  = CreateDefaultAllocator;
    const auto&                               value = arg_parser.GetArgumentValue(kMemoryPortabilityShortOption);

    if (!value.empty())
    {
        if (gfxrecon::util::platform::StringCompareNoCase(kMemoryTranslationRebind, value.c_str()) == 0)
        {
            func = CreateRebindAllocator;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kMemoryTranslationRemap, value.c_str()) == 0)
        {
            func = CreateRemapAllocator;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kMemoryTranslationRealign, value.c_str()) == 0)
        {
            func = InitRealignAllocatorCreateFunc(filename, replay_options, tracked_object_info_table);
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kMemoryTranslationNone, value.c_str()) != 0)
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized memory translation option \"%s\"", value.c_str());
        }
    }

    return func;
}

#if defined(WIN32)
static bool IsApiFamilyIdEnabled(const gfxrecon::util::ArgumentParser& arg_parser, gfxrecon::format::ApiFamilyId api)
{
    const std::string& value = arg_parser.GetArgumentValue(kApiFamilyOption);

    // If the --api argument was specified, parse the option.
    if (!value.empty())
    {
        if (gfxrecon::util::platform::StringCompareNoCase(kApiFamilyAll, value.c_str()) == 0)
        {
            return true;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kApiFamilyVulkan, value.c_str()) == 0)
        {
            return (api == gfxrecon::format::ApiFamilyId::ApiFamily_Vulkan);
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kApiFamilyD3D12, value.c_str()) == 0)
        {
            return (api == gfxrecon::format::ApiFamilyId::ApiFamily_D3D12);
        }
        else
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized API option \"%s\"", value.c_str());
            return true;
        }
    }
    // If the --api argument was not specified, default so that all APIs are enabled.
    else
    {
        return true;
    }
}
#endif

static void IsForceWindowed(gfxrecon::decode::ReplayOptions& options, const gfxrecon::util::ArgumentParser& arg_parser)
{
    auto value = arg_parser.GetArgumentValue(kForceWindowedShortArgument);

    if (value.empty())
    {
        value = arg_parser.GetArgumentValue(kForceWindowedLongArgument);
    }
    if (!value.empty())
    {
        options.force_windowed = true;

        std::istringstream value_input;
        value_input.str(value);
        std::string val;

        std::getline(value_input, val, ',');
        options.windowed_width = std::stoi(val);
        std::getline(value_input, val, ',');
        options.windowed_height = std::stoi(val);
    }
}

static std::vector<int32_t> GetFilteredMsgs(const gfxrecon::util::ArgumentParser& arg_parser,
                                            const char*                           filter_messages)
{
    const auto&          value = arg_parser.GetArgumentValue(filter_messages);
    std::vector<int32_t> msgs;
    if (!value.empty())
    {
        std::vector<std::string> values;
        std::istringstream       value_input;
        value_input.str(value);

        for (std::string val; std::getline(value_input, val, ',');)
        {
            size_t count = std::count_if(val.begin(), val.end(), ::isdigit);
            if (count == val.length())
            {
                msgs.push_back(std::stoi(val));
            }
            else
            {
                GFXRECON_LOG_WARNING("Ignoring invalid filter messages\"%s\", which contains non-numeric values",
                                     val.c_str());
                break;
            }
        }
    }
    return msgs;
}

static void GetReplayOptions(gfxrecon::decode::ReplayOptions&      options,
                             const gfxrecon::util::ArgumentParser& arg_parser,
                             const std::string&                    filename)
{
    options.filename = filename;

    if (arg_parser.IsOptionSet(kValidateOption))
    {
        options.enable_validation_layer = true;
    }

    if (arg_parser.IsOptionSet(kDebugDeviceLostOption))
    {
        options.enable_debug_device_lost = true;
    }

    if (arg_parser.IsOptionSet(kSyncOption))
    {
        options.sync_queue_submissions = true;
    }

    if (arg_parser.IsOptionSet(kCreateDummyAllocationsOption))
    {
        options.create_dummy_allocations = true;
    }

    if (arg_parser.IsOptionSet(kOmitNullHardwareBuffersLongOption) ||
        arg_parser.IsOptionSet(kOmitNullHardwareBuffersShortOption))
    {
        options.omit_null_hardware_buffers = true;
    }

    if (arg_parser.IsOptionSet(kQuitAfterMeasurementRangeOption))
    {
        options.quit_after_measurement_frame_range = true;
    }

    if (arg_parser.IsOptionSet(kFlushMeasurementRangeOption))
    {
        options.flush_measurement_frame_range = true;
    }

    const auto& override_gpu = arg_parser.GetArgumentValue(kOverrideGpuArgument);
    if (!override_gpu.empty())
    {
        options.override_gpu_index = std::stoi(override_gpu);
    }

    IsForceWindowed(options, arg_parser);
}

static gfxrecon::decode::VulkanReplayOptions
GetVulkanReplayOptions(const gfxrecon::util::ArgumentParser&           arg_parser,
                       const std::string&                              filename,
                       gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table)
{
    gfxrecon::decode::VulkanReplayOptions replay_options;
    GetReplayOptions(replay_options, arg_parser, filename);

#if defined(WIN32)
    replay_options.enable_vulkan = IsApiFamilyIdEnabled(arg_parser, gfxrecon::format::ApiFamily_Vulkan);
#else
    replay_options.enable_vulkan = true;
#endif

    const auto& override_gpu_group = arg_parser.GetArgumentValue(kOverrideGpuGroupArgument);
    if (!override_gpu_group.empty())
    {
        replay_options.override_gpu_group_index = std::stoi(override_gpu_group);
    }

    if (arg_parser.IsOptionSet(kRemoveUnsupportedOption))
    {
        replay_options.remove_unsupported_features = true;
    }

    if (arg_parser.IsOptionSet(kSkipFailedAllocationLongOption) ||
        arg_parser.IsOptionSet(kSkipFailedAllocationShortOption))
    {
        replay_options.skip_failed_allocations = true;
    }

    if (arg_parser.IsOptionSet(kOmitPipelineCacheDataLongOption) ||
        arg_parser.IsOptionSet(kOmitPipelineCacheDataShortOption))
    {
        replay_options.omit_pipeline_cache_data = true;
    }

    auto swapchain_option          = arg_parser.GetArgumentValue(kSwapchainOption);
    auto enable_captured_swapchain = arg_parser.IsOptionSet(kEnableUseCapturedSwapchainIndices);
    if (swapchain_option.empty())
    {
        if (enable_captured_swapchain)
        {
            replay_options.swapchain_option = gfxrecon::util::SwapchainOption::kCaptured;
        }
    }
    else
    {
        if (enable_captured_swapchain)
        {
            GFXRECON_LOG_WARNING("Ignoring option: \"%s\" because option: \"%s\" is added",
                                 kEnableUseCapturedSwapchainIndices,
                                 kSwapchainOption);
        }

        if (gfxrecon::util::platform::StringCompareNoCase(kSwapchainCaptured, swapchain_option.c_str()) == 0)
        {
            replay_options.swapchain_option = gfxrecon::util::SwapchainOption::kCaptured;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kSwapchainOffscreen, swapchain_option.c_str()) == 0)
        {
            replay_options.swapchain_option = gfxrecon::util::SwapchainOption::kOffscreen;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kSwapchainVirtual, swapchain_option.c_str()) != 0)
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized \"--swapchain\" option: %s", swapchain_option.c_str());
        }
    }

    replay_options.replace_dir = arg_parser.GetArgumentValue(kShaderReplaceArgument);
    replay_options.create_resource_allocator =
        GetCreateResourceAllocatorFunc(arg_parser, filename, replay_options, tracked_object_info_table);

    replay_options.screenshot_ranges      = GetScreenshotRanges(arg_parser);
    replay_options.screenshot_format      = GetScreenshotFormat(arg_parser);
    replay_options.screenshot_dir         = GetScreenshotDir(arg_parser);
    replay_options.screenshot_file_prefix = arg_parser.GetArgumentValue(kScreenshotFilePrefixArgument);
    GetScreenshotSize(arg_parser, replay_options.screenshot_width, replay_options.screenshot_height);
    replay_options.screenshot_scale = GetScreenshotScale(arg_parser);

    if (arg_parser.IsOptionSet(kQuitAfterMeasurementRangeOption))
    {
        replay_options.quit_after_measurement_frame_range = true;
    }

    if (arg_parser.IsOptionSet(kFlushMeasurementRangeOption))
    {
        replay_options.flush_measurement_frame_range = true;
    }

    std::string surface_index = arg_parser.GetArgumentValue(kSurfaceIndexArgument);
    if (!surface_index.empty())
    {
        replay_options.surface_index = std::stoi(surface_index);
    }

    const std::string& dump_resources = arg_parser.GetArgumentValue(kDumpResourcesArgument);
    if (!dump_resources.empty())
    {
        std::vector<std::string> values = gfxrecon::util::strings::SplitString(dump_resources, ',');
        if (!values.empty())
        {
            bool error = false;
            if (values.size() % 3 == 0)
            {
                for (auto i = 0; i < values.size(); i += 3)
                {
                    char* endptr;
                    struct gfxrecon::decode::ReplayOptionsTripletStruct triplet;
                    triplet.opt_BeginCommandBuffer_Index = strtol(values[i + 0].c_str(), &endptr, 10);
                    error |= (errno != 0 || *endptr != 0);
                    triplet.opt_CmdDraw_Index = strtol(values[i + 1].c_str(), &endptr, 10);
                    error |= (errno != 0 || *endptr != 0);
                    triplet.opt_QueueSubmit_Index = strtol(values[i + 2].c_str(), &endptr, 10);
                    error |= (errno != 0 || *endptr != 0);
                    if (!error)
                    {
                        replay_options.OrigReplayOptions.push_back(triplet);
                    }
                }
            }

#if !defined(D3D12_SUPPORT)
            // Ignore dump-resources arg errors if D3D12_SUPPORT is enabled -- args may be for D3D12 replay, so let GetDxReplayOptions generate an error.
            if (error)
            {
                replay_options.dump_resources_params.erase();
                GFXRECON_LOG_ERROR("The parameter to --dump-resources is invalid.");
            }
#endif
            if (!error)
            {
                // Transfer dr args to vectors
                for (auto it=replay_options.OrigReplayOptions.begin(); it != replay_options.OrigReplayOptions.end(); it++)
                {
                    replay_options.BeginCommandBuffer_Index.push_back(it->opt_BeginCommandBuffer_Index);
                    replay_options.QueueSubmit_indices.push_back(it->opt_QueueSubmit_Index);

                    // Get index of BeginCommandBuffer_Index item we just inserted into
                    size_t cdi = std::find(replay_options.BeginCommandBuffer_Index.begin(),replay_options.BeginCommandBuffer_Index.end(), it->opt_BeginCommandBuffer_Index) -
                                 replay_options.BeginCommandBuffer_Index.begin();

                    if (replay_options.CmdDraw_Index.size() <= cdi)
                    {
                        // Add a row to CommandDraw_Index by pushing new value
                        replay_options.CmdDraw_Index.push_back({it->opt_CmdDraw_Index});
                        replay_options.CmdDispatch_Index.push_back({it->opt_CmdDraw_Index});      //TODO: This is a kludge
                        replay_options.CmdTraceRaysKHR_Index.push_back({it->opt_CmdDraw_Index});  //TODO: This is a kludge
                        replay_options.RenderPass_Indices.push_back({{it->opt_CmdDraw_Index}});   //TODO: This is a kludge
                    }
                    else
                    {
                        // Append a new value to existing CommandDraw_Index row
                        replay_options.CmdDraw_Index[cdi].push_back(it->opt_CmdDraw_Index);
                    }
                }
            }
        }
    }

    replay_options.dump_rts_before_dc = arg_parser.IsOptionSet(kDumpResourcesBeforeDrawOption);

    return replay_options;
}

#if defined(D3D12_SUPPORT)
static gfxrecon::decode::DxReplayOptions GetDxReplayOptions(const gfxrecon::util::ArgumentParser& arg_parser,
                                                            const std::string&                    filename)
{
    gfxrecon::decode::DxReplayOptions replay_options;
    GetReplayOptions(replay_options, arg_parser, filename);

    replay_options.enable_d3d12         = IsApiFamilyIdEnabled(arg_parser, gfxrecon::format::ApiFamily_D3D12);
    replay_options.DeniedDebugMessages  = GetFilteredMsgs(arg_parser, kDeniedMessages);
    replay_options.AllowedDebugMessages = GetFilteredMsgs(arg_parser, kAllowedMessages);

    if (arg_parser.IsOptionSet(kDxTwoPassReplay))
    {
        replay_options.enable_d3d12_two_pass_replay = true;
    }

    if (arg_parser.IsOptionSet(kDiscardCachedPsosLongOption) || arg_parser.IsOptionSet(kDiscardCachedPsosShortOption))
    {
        GFXRECON_LOG_WARNING("The parameters --dcp and --discard-cached-psos have been deprecated in favor for "
                             "--use-cached-psos");
    }

    if (arg_parser.IsOptionSet(kUseCachedPsosOption))
    {
        replay_options.use_cached_psos = true;
    }

    if (arg_parser.IsOptionSet(kDxOverrideObjectNames))
    {
        replay_options.override_object_names = true;
    }

    const std::string& dump_resources = arg_parser.GetArgumentValue(kDumpResourcesArgument);
    if (!dump_resources.empty())
    {
        // Ignore this option is it is of the form --dump-resource i1,i2,i3.  That is the Vulkan
        // form of this option and the args should have already been parsed in GetVulkanReplayOptions.
        std::vector<std::string> vvalues = gfxrecon::util::strings::SplitString(dump_resources, ',');
        bool isVulkanDumpResources = false;
        if (vvalues.size() % 3 == 0)
        {
            isVulkanDumpResources = true;
        }
        std::vector<std::string> values = gfxrecon::util::strings::SplitString(dump_resources, '-');
        if (!isVulkanDumpResources && !values.empty())
        {
            if (values.size() != 2)
            {
                GFXRECON_LOG_ERROR("Ignoring invalid --dump-resources parameter: %s", dump_resources.c_str());
            }
            else if (values[0].compare("drawcall") == 0)
            {
                replay_options.dump_resources_type     = gfxrecon::decode::DumpResourcesType::kDrawCall;
                replay_options.dump_resources_argument = std::stoi(values[1]);
            }
            else
            {
                GFXRECON_LOG_ERROR("Ignoring invalid --dump-resources parameter: %s", dump_resources.c_str());
            }
        }
    }

    const std::string& memory_usage = arg_parser.GetArgumentValue(kBatchingMemoryUsageArgument);
    if (!memory_usage.empty())
    {
        int memory_usage_int = std::stoi(memory_usage);
        if (memory_usage_int >= 0 && memory_usage_int <= 100)
        {
            replay_options.memory_usage = static_cast<uint32_t>(memory_usage_int);
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "The parameter to --batching-memory-usage is out of range [0, 100], will use 80 as default value.");
        }
    }

    replay_options.screenshot_ranges      = GetScreenshotRanges(arg_parser);
    replay_options.screenshot_format      = GetScreenshotFormat(arg_parser);
    replay_options.screenshot_dir         = GetScreenshotDir(arg_parser);
    replay_options.screenshot_file_prefix = arg_parser.GetArgumentValue(kScreenshotFilePrefixArgument);
    return replay_options;
}
#endif

static bool CheckOptionPrintVersion(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kVersionOption))
    {
        std::string app_name     = exe_name;
        size_t      dir_location = app_name.find_last_of("/\\");

        if (dir_location >= 0)
        {
            app_name.replace(0, dir_location + 1, "");
        }

        GFXRECON_WRITE_CONSOLE("%s version info:", app_name.c_str());
        GFXRECON_WRITE_CONSOLE("  GFXReconstruct Version %s", GFXRECON_PROJECT_VERSION_STRING);
        GFXRECON_WRITE_CONSOLE("  Vulkan Header Version %u.%u.%u",
                               VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE),
                               VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE),
                               VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));

        return true;
    }

    return false;
}

static void PrintUsage(const char* exe_name);

static bool CheckOptionPrintUsage(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kHelpShortOption) || arg_parser.IsOptionSet(kHelpLongOption))
    {
        PrintUsage(exe_name);
        return true;
    }

    return false;
}

#endif // GFXRECON_PLATFORM_SETTINGS_H
