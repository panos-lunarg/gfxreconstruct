/*
** Copyright (c) 2018-2020 Valve Corporation
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

#include "decode/vulkan_replay_consumer_base.h"
#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "decode/descriptor_update_template_decoder.h"
#include "decode/resource_util.h"
#include "decode/vulkan_captured_swapchain.h"
#include "decode/vulkan_feature_util.h"
#include "decode/vulkan_virtual_swapchain.h"
#include "decode/vulkan_object_cleanup_util.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "graphics/vulkan_device_util.h"
#include "graphics/vulkan_util.h"
#include "util/file_path.h"
#include "util/hash.h"
#include "util/platform.h"
#include "util/logging.h"

#include "generated/generated_vulkan_enum_to_string.h"

#include <cstdint>
#include <limits>
#include <unordered_set>
#include <future>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const int32_t  kDefaultWindowPositionX = 0;
const int32_t  kDefaultWindowPositionY = 0;
const uint32_t kDefaultWindowWidth     = 320;
const uint32_t kDefaultWindowHeight    = 240;

const std::unordered_set<std::string> kSurfaceExtensions = {
    VK_KHR_ANDROID_SURFACE_EXTENSION_NAME, VK_MVK_IOS_SURFACE_EXTENSION_NAME, VK_MVK_MACOS_SURFACE_EXTENSION_NAME,
    VK_KHR_MIR_SURFACE_EXTENSION_NAME,     VK_NN_VI_SURFACE_EXTENSION_NAME,   VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME,
    VK_KHR_WIN32_SURFACE_EXTENSION_NAME,   VK_KHR_XCB_SURFACE_EXTENSION_NAME, VK_KHR_XLIB_SURFACE_EXTENSION_NAME
};

static VKAPI_ATTR VkBool32 VKAPI_CALL DebugReportCallback(VkDebugReportFlagsEXT      flags,
                                                          VkDebugReportObjectTypeEXT objectType,
                                                          uint64_t                   object,
                                                          size_t                     location,
                                                          int32_t                    messageCode,
                                                          const char*                pLayerPrefix,
                                                          const char*                pMessage,
                                                          void*                      pUserData)
{
    GFXRECON_UNREFERENCED_PARAMETER(objectType);
    GFXRECON_UNREFERENCED_PARAMETER(object);
    GFXRECON_UNREFERENCED_PARAMETER(location);
    GFXRECON_UNREFERENCED_PARAMETER(messageCode);
    GFXRECON_UNREFERENCED_PARAMETER(pUserData);

    if ((pLayerPrefix != nullptr) && (pMessage != nullptr) &&
        ((flags & VK_DEBUG_REPORT_ERROR_BIT_EXT) == VK_DEBUG_REPORT_ERROR_BIT_EXT))
    {
        GFXRECON_WRITE_CONSOLE("DEBUG REPORT: %s: %s", pLayerPrefix, pMessage);
    }

    return VK_FALSE;
}

static VKAPI_ATTR VkBool32 VKAPI_CALL DebugUtilsCallback(VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
                                                         VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
                                                         const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                         void*                                       pUserData)
{
    GFXRECON_UNREFERENCED_PARAMETER(pUserData);

    if ((pCallbackData != nullptr) && (pCallbackData->pMessageIdName != nullptr) &&
        (pCallbackData->pMessage != nullptr) &&
        ((messageTypes & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) ==
         VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) &&
        ((messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT) ==
         VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT))
    {
        GFXRECON_WRITE_CONSOLE("DEBUG MESSENGER: %s: %s", pCallbackData->pMessageIdName, pCallbackData->pMessage);
    }

    return VK_FALSE;
}

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
static uint32_t GetHardwareBufferFormatBpp(uint32_t format)
{
    switch (format)
    {
        case AHARDWAREBUFFER_FORMAT_BLOB:
        case AHARDWAREBUFFER_FORMAT_S8_UINT: // VK_FORMAT_S8_UINT
            return 1;
        case AHARDWAREBUFFER_FORMAT_R5G6B5_UNORM: // VK_FORMAT_R5G6B5_UNORM_PACK16
        case AHARDWAREBUFFER_FORMAT_D16_UNORM:    // VK_FORMAT_D16_UNORM
            return 2;
        case AHARDWAREBUFFER_FORMAT_R8G8B8_UNORM: // VK_FORMAT_R8G8B8_UNORM
            return 3;
        case AHARDWAREBUFFER_FORMAT_R8G8B8A8_UNORM:    // VK_FORMAT_R8G8B8A8_UNORM
        case AHARDWAREBUFFER_FORMAT_R8G8B8X8_UNORM:    // VK_FORMAT_R8G8B8A8_UNORM
        case AHARDWAREBUFFER_FORMAT_R10G10B10A2_UNORM: // VK_FORMAT_A2B10G10R10_UNORM_PACK32
        case AHARDWAREBUFFER_FORMAT_D24_UNORM:         // VK_FORMAT_X8_D24_UNORM_PACK32
        case AHARDWAREBUFFER_FORMAT_D24_UNORM_S8_UINT: // VK_FORMAT_D24_UNORM_S8_UINT
        case AHARDWAREBUFFER_FORMAT_D32_FLOAT:         // VK_FORMAT_D32_SFLOAT
            return 4;
        case AHARDWAREBUFFER_FORMAT_R16G16B16A16_FLOAT: // VK_FORMAT_R16G16B16A16_SFLOAT
        case AHARDWAREBUFFER_FORMAT_D32_FLOAT_S8_UINT:  // VK_FORMAT_D32_SFLOAT_S8_UINT
            return 8;
        default:
            break;
    }

    return 0;
}
#endif

VulkanReplayConsumerBase::VulkanReplayConsumerBase(std::shared_ptr<application::Application> application,
                                                   const VulkanReplayOptions&                options) :
    VulkanReplayBase(options),
    application_(application), have_imported_semaphores_(false), create_surface_count_(0), fps_info_(nullptr)
{
    assert(application_ != nullptr);
    assert(options.create_resource_allocator != nullptr);

    if (!options.screenshot_ranges.empty())
    {
        InitializeScreenshotHandler();
    }

    // Process option to select swapchain handler. The options is '--use-captured-swapchain-indices'.
    if (options.enable_use_captured_swapchain_indices)
    {
        swapchain_ = std::make_unique<VulkanCapturedSwapchain>();
    }
    else
    {
        swapchain_ = std::make_unique<VulkanVirtualSwapchain>();
    }
}

VulkanReplayConsumerBase::~VulkanReplayConsumerBase()
{
    if (options_.surface_index >= create_surface_count_)
    {
        GFXRECON_LOG_WARNING("Rendering was restricted to surface index %u, but a surface was never created for that "
                             "index; replay created %d surface(s)",
                             options_.surface_index,
                             create_surface_count_);
    }

    // Idle all devices before destroying other resources.
    WaitDevicesIdle();

    // Cleanup screenshot resources before destroying device.
    object_info_table_.VisitDeviceInfo([this](const DeviceInfo* info) {
        assert(info != nullptr);
        VkDevice device = info->handle;

        auto device_table = GetDeviceTable(device);
        assert(device_table != nullptr);

        if (screenshot_handler_ != nullptr)
        {
            screenshot_handler_->DestroyDeviceResources(device, device_table);
        }
    });

    object_cleanup::FreeAllLiveObjects(
        &object_info_table_,
        false,
        true,
        [this](const void* handle) { return GetInstanceTable(handle); },
        [this](const void* handle) { return GetDeviceTable(handle); },
        swapchain_.get());

    // Destroy any windows that were created for Vulkan surfaces.
    for (auto window : active_windows_)
    {
        auto wsi_context    = application_ ? application_->GetWsiContext(window->GetWsiExtension()) : nullptr;
        auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
        assert(window_factory);
        window_factory->Destroy(window);
    }

    // Finally destroy vkInstances
    object_cleanup::FreeAllLiveInstances(
        &object_info_table_,
        false,
        true,
        [this](const void* handle) { return GetInstanceTable(handle); },
        [this](const void* handle) { return GetDeviceTable(handle); });
}

void VulkanReplayConsumerBase::WaitDevicesIdle()
{
    object_info_table_.VisitDeviceInfo([this](const DeviceInfo* info) {
        assert(info != nullptr);
        VkDevice device = info->handle;

        auto device_table = GetDeviceTable(device);
        assert(device_table != nullptr);

        device_table->DeviceWaitIdle(device);
    });
}

void VulkanReplayConsumerBase::ProcessStateEndMarker(uint64_t frame_number)
{
    GFXRECON_LOG_INFO("Finished loading state for captured frame %" PRId64, frame_number);

    if (fps_info_ != nullptr)
    {
        fps_info_->ProcessStateEndMarker(frame_number);
    }

    VulkanReplayBase::ProcessStateEndMarker(frame_number);
}

void VulkanReplayConsumerBase::ProcessDisplayMessageCommand(format::CommandIndexType command_index,
                                                            const std::string&       message)
{
    GFXRECON_LOG_INFO("Trace Message: %s", message.c_str());
}

void VulkanReplayConsumerBase::ProcessResizeWindowCommand(format::CommandIndexType command_index,
                                                          format::HandleId         surface_id,
                                                          uint32_t                 width,
                                                          uint32_t                 height)
{
    // We need to find the surface associated with this ID, and then lookup its window.
    const SurfaceKHRInfo* surface_info = object_info_table_.GetSurfaceKHRInfo(surface_id);

    if (surface_info != nullptr)
    {
        Window* window = surface_info->window;

        if (window != nullptr)
        {
            window->SetSize(width, height);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping window resize for VkSurface object (ID = %" PRIu64
                                 ") without an associated window",
                                 surface_id);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping window resize for unrecognized VkSurface object (ID = %" PRIu64 ")", surface_id);
    }
}

void VulkanReplayConsumerBase::ProcessResizeWindowCommand2(format::CommandIndexType command_index,
                                                           format::HandleId         surface_id,
                                                           uint32_t                 width,
                                                           uint32_t                 height,
                                                           uint32_t                 pre_transform)
{
    // We need to find the surface associated with this ID, and then lookup its window.
    const SurfaceKHRInfo* surface_info = object_info_table_.GetSurfaceKHRInfo(surface_id);

    if (surface_info != nullptr)
    {
        Window* window = surface_info->window;

        if (window != nullptr)
        {
            window->SetSizePreTransform(width, height, pre_transform);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping window resize for VkSurface object (ID = %" PRIu64
                                 ") without an associated window",
                                 surface_id);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping window resize for unrecognized VkSurface object (ID = %" PRIu64 ")", surface_id);
    }
}

void VulkanReplayConsumerBase::ProcessSetDevicePropertiesCommand(format::CommandIndexType command_index,
                                                                 format::HandleId         physical_device_id,
                                                                 uint32_t                 api_version,
                                                                 uint32_t                 driver_version,
                                                                 uint32_t                 vendor_id,
                                                                 uint32_t                 device_id,
                                                                 uint32_t                 device_type,
                                                                 const uint8_t pipeline_cache_uuid[format::kUuidSize],
                                                                 const std::string& device_name)
{
    PhysicalDeviceInfo* physical_device_info = object_info_table_.GetPhysicalDeviceInfo(physical_device_id);

    if (physical_device_info != nullptr)
    {
        physical_device_info->capture_api_version    = api_version;
        physical_device_info->capture_driver_version = driver_version;
        physical_device_info->capture_vendor_id      = vendor_id;
        physical_device_info->capture_device_id      = device_id;
        physical_device_info->capture_device_type    = static_cast<VkPhysicalDeviceType>(device_type);
        physical_device_info->capture_device_name    = device_name;

        util::platform::MemoryCopy(physical_device_info->capture_pipeline_cache_uuid,
                                   format::kUuidSize,
                                   pipeline_cache_uuid,
                                   format::kUuidSize);
    }
}

void VulkanReplayConsumerBase::ProcessSetDeviceMemoryPropertiesCommand(
    format::CommandIndexType                     command_index,
    format::HandleId                             physical_device_id,
    const std::vector<format::DeviceMemoryType>& memory_types,
    const std::vector<format::DeviceMemoryHeap>& memory_heaps)
{
    PhysicalDeviceInfo* physical_device_info = object_info_table_.GetPhysicalDeviceInfo(physical_device_id);

    if (physical_device_info != nullptr)
    {
        VkPhysicalDeviceMemoryProperties* memory_properties = &physical_device_info->capture_memory_properties;

        memory_properties->memoryTypeCount = static_cast<uint32_t>(memory_types.size());
        memory_properties->memoryHeapCount = static_cast<uint32_t>(memory_heaps.size());

        for (uint32_t i = 0; i < memory_properties->memoryTypeCount; ++i)
        {
            memory_properties->memoryTypes[i].propertyFlags = memory_types[i].property_flags;
            memory_properties->memoryTypes[i].heapIndex     = memory_types[i].heap_index;
        }

        for (uint32_t i = 0; i < memory_properties->memoryHeapCount; ++i)
        {
            memory_properties->memoryHeaps[i].size  = memory_heaps[i].size;
            memory_properties->memoryHeaps[i].flags = memory_heaps[i].flags;
        }
    }
}

void VulkanReplayConsumerBase::ProcessSetOpaqueAddressCommand(format::CommandIndexType command_index,
                                                              format::HandleId         device_id,
                                                              format::HandleId         object_id,
                                                              uint64_t                 address)
{
    DeviceInfo* device_info = object_info_table_.GetDeviceInfo(device_id);

    if (device_info != nullptr)
    {
        // Store the opaque address to use at object creation.
        device_info->opaque_addresses[object_id] = address;
    }
}

void VulkanReplayConsumerBase::ProcessSetRayTracingShaderGroupHandlesCommand(format::CommandIndexType command_index,
                                                                             format::HandleId         device_id,
                                                                             format::HandleId         pipeline_id,
                                                                             size_t                   data_size,
                                                                             const uint8_t*           data)
{
    DeviceInfo* device_info = object_info_table_.GetDeviceInfo(device_id);
    if (device_info != nullptr)
    {
        // There should only be one dataset per pipeline.
        assert(device_info->shader_group_handles.find(pipeline_id) == device_info->shader_group_handles.end());

        // Store the ray tracing shader group handle data to use at ray tracing pipeline creation.
        device_info->shader_group_handles.emplace(pipeline_id, std::vector<uint8_t>(data, data + data_size));
    }
}

void VulkanReplayConsumerBase::ProcessSetSwapchainImageStateCommand(
    format::CommandIndexType                            command_index,
    format::HandleId                                    device_id,
    format::HandleId                                    swapchain_id,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_info)
{
    const DeviceInfo* device_info    = object_info_table_.GetDeviceInfo(device_id);
    SwapchainKHRInfo* swapchain_info = object_info_table_.GetSwapchainKHRInfo(swapchain_id);

    if ((device_info != nullptr) && (swapchain_info != nullptr))
    {
        assert((device_info->handle != VK_NULL_HANDLE) && (swapchain_info->handle != VK_NULL_HANDLE));
        swapchain_->ProcessSetSwapchainImageStateCommand(device_info,
                                                         swapchain_info,
                                                         last_presented_image,
                                                         image_info,
                                                         object_info_table_,
                                                         swapchain_image_tracker_);
    }
    else
    {
        if (device_info != nullptr)
        {
            GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkSwapchainKHR object (ID = %" PRIu64 ")",
                                 swapchain_id);
        }
        else if (swapchain_info != nullptr)
        {
            GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkDevice object (ID = %" PRIu64 ")",
                                 device_id);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkDevice (ID = %" PRIu64
                                 ") and VkSwapchainKHR (ID = %" PRIu64 ") objects",
                                 device_id,
                                 swapchain_id);
        }
    }
}

VkResult VulkanReplayConsumerBase::CreateSurface(InstanceInfo*                       instance_info,
                                                 const std::string&                  wsi_extension,
                                                 VkFlags                             flags,
                                                 HandlePointerDecoder<VkSurfaceKHR>* surface)
{
    assert(instance_info != nullptr);

    VkInstance    instance       = instance_info->handle;
    VkSurfaceKHR* replay_surface = nullptr;
    VkResult      result         = VK_SUCCESS;

    if (surface != nullptr)
    {
        replay_surface = surface->GetHandlePointer();
    }

    // For multi-surface captures, when replay is restricted to a specific surface, only create a surface for the
    // specified index.
    if ((options_.surface_index == -1) || (options_.surface_index == create_surface_count_))
    {
        // Create a window for our surface.
        assert(application_);
        auto wsi_context = application_ ? application_->GetWsiContext(wsi_extension, true) : nullptr;
        assert(wsi_context);
        auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
        assert(window_factory);
        auto window =
            window_factory
                ? window_factory->Create(
                      kDefaultWindowPositionX, kDefaultWindowPositionY, kDefaultWindowWidth, kDefaultWindowHeight)
                : nullptr;

        if (window == nullptr)
        {
            // Failure to create a window is a fatal error.
            GFXRECON_LOG_FATAL("Failed to create a window for use with surface creation.  Replay cannot continue.");
            RaiseFatalError("Replay has encountered a fatal error and cannot continue (window creation failed)");
        }

        VkResult result = window->CreateSurface(GetInstanceTable(instance), instance, flags, replay_surface);

        if ((result == VK_SUCCESS) && (replay_surface != nullptr))
        {
            auto surface_id   = surface->GetPointer();
            auto surface_info = reinterpret_cast<SurfaceKHRInfo*>(surface->GetConsumerData(0));
            assert((surface_id != nullptr) && (surface_info != nullptr));
            assert(!surface_info->surface_creation_skipped);

            surface_info->window = window;
            active_windows_.insert(window);
        }
        else
        {
            window_factory->Destroy(window);
        }
    }
    else
    {
        if (surface != nullptr)
        {
            auto surface_info                      = reinterpret_cast<SurfaceKHRInfo*>(surface->GetConsumerData(0));
            surface_info->surface_creation_skipped = true;
        }

        GFXRECON_LOG_INFO("Skipping surface creation for surface index %d", create_surface_count_);
    }

    // Count the number of surfaces created for restricting replay to a specific surface.
    ++create_surface_count_;

    return result;
}

void VulkanReplayConsumerBase::ProcessCreateInstanceDebugCallbackInfo(const Decoded_VkInstanceCreateInfo* instance_info)
{
    assert(instance_info != nullptr);

    if (instance_info->pNext != nullptr)
    {
        // 'Out' struct for non-const pNext pointers.
        auto pnext = reinterpret_cast<VkBaseOutStructure*>(instance_info->pNext->GetPointer());
        while (pnext != nullptr)
        {
            if (pnext->sType == VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT)
            {
                auto debug_report_info         = reinterpret_cast<VkDebugReportCallbackCreateInfoEXT*>(pnext);
                debug_report_info->pfnCallback = DebugReportCallback;
            }
            else if (pnext->sType == VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT)
            {
                auto debug_utils_info             = reinterpret_cast<VkDebugUtilsMessengerCreateInfoEXT*>(pnext);
                debug_utils_info->pfnUserCallback = DebugUtilsCallback;
            }

            pnext = pnext->pNext;
        }
    }
}

void VulkanReplayConsumerBase::ProcessSwapchainFullScreenExclusiveInfo(
    const Decoded_VkSwapchainCreateInfoKHR* swapchain_info)
{
    assert(swapchain_info != nullptr);

    if (swapchain_info->pNext != nullptr)
    {
        // 'Out' struct for non-const pNext pointers.
        auto pnext = reinterpret_cast<VkBaseOutStructure*>(swapchain_info->pNext->GetPointer());
        while (pnext != nullptr)
        {
            if (pnext->sType == VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT)
            {
#if defined(VK_USE_PLATFORM_WIN32_KHR)
                // Get the surface info from the Decoded_VkSwapchainCreateInfoKHR handle id.
                HMONITOR   hmonitor     = nullptr;
                const auto surface_info = object_info_table_.GetSurfaceKHRInfo(swapchain_info->surface);

                if ((surface_info != nullptr) && (surface_info->window != nullptr))
                {
                    // Try to retrieve an HWND value from the window.
                    HWND hwnd = nullptr;
                    if (surface_info->window->GetNativeHandle(Window::kWin32HWnd, reinterpret_cast<void**>(&hwnd)))
                    {
                        hmonitor = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
                    }
                }

                if (hmonitor != nullptr)
                {
                    auto full_screen_info      = reinterpret_cast<VkSurfaceFullScreenExclusiveWin32InfoEXT*>(pnext);
                    full_screen_info->hmonitor = hmonitor;
                }
                else
                {
                    GFXRECON_LOG_WARNING(
                        "Failed to obtain a valid HMONITOR handle for the VkSurfaceFullScreenExclusiveWin32InfoEXT "
                        "extension structure provided to vkCreateSwapchainKHR")
                }
#else
                GFXRECON_LOG_WARNING("vkCreateSwapchainKHR called with the VkSurfaceFullScreenExclusiveWin32InfoEXT "
                                     "extension structure, which is not supported by this platform")
#endif
                break;
            }

            pnext = pnext->pNext;
        }
    }
}

void VulkanReplayConsumerBase::ProcessImportAndroidHardwareBufferInfo(const Decoded_VkMemoryAllocateInfo* allocate_info)
{
    assert(allocate_info != nullptr);

    if (allocate_info->pNext != nullptr)
    {
        auto pnext = reinterpret_cast<Decoded_VkBaseOutStructure*>(allocate_info->pNext->GetMetaStructPointer());
        while (pnext != nullptr)
        {
            if (pnext->decoded_value->sType == VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID)
            {
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
                auto import_ahb_info = reinterpret_cast<Decoded_VkImportAndroidHardwareBufferInfoANDROID*>(pnext);

                // Get the hardware buffer from the Decoded_VkImportAndroidHardwareBufferInfoANDROID buffer id.
                auto entry = hardware_buffers_.find(import_ahb_info->buffer);
                if (entry != hardware_buffers_.end())
                {
                    import_ahb_info->decoded_value->buffer = entry->second.hardware_buffer;
                }
                else
                {
                    GFXRECON_LOG_WARNING("Failed to find a valid AHardwareBuffer handle for the "
                                         "VkImportAndroidHardwareBufferInfoANDROID "
                                         "extension structure provided to vkAllocateMemory")
                }
#else
                GFXRECON_LOG_WARNING("vkAllocateMemory called with the VkImportAndroidHardwareBufferInfoANDROID "
                                     "extension structure, which is not supported by this platform")
#endif
                break;
            }

            if (pnext->pNext != nullptr)
            {
                pnext = reinterpret_cast<Decoded_VkBaseOutStructure*>(pnext->pNext->GetMetaStructPointer());
            }
            else
            {
                pnext = nullptr;
            }
        }
    }
}

void VulkanReplayConsumerBase::SetSwapchainWindowSize(const Decoded_VkSwapchainCreateInfoKHR* swapchain_info)
{
    assert(swapchain_info != nullptr);

    const auto create_info = swapchain_info->decoded_value;
    if (create_info != nullptr)
    {
        const auto surface_info = object_info_table_.GetSurfaceKHRInfo(swapchain_info->surface);
        if (surface_info && (surface_info->window != nullptr))
        {
            uint32_t pre_transform = 0;
            switch (create_info->preTransform)
            {
                default:
                case VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR:
                case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR:
                case VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR:
                    pre_transform = format::ResizeWindowPreTransform::kPreTransform0;
                    break;
                case VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR:
                case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR:
                    pre_transform = format::ResizeWindowPreTransform::kPreTransform90;
                    break;
                case VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR:
                case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR:
                    pre_transform = format::ResizeWindowPreTransform::kPreTransform180;
                    break;
                case VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR:
                case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR:
                    pre_transform = format::ResizeWindowPreTransform::kPreTransform270;
                    break;
            }

            surface_info->window->SetSizePreTransform(
                create_info->imageExtent.width, create_info->imageExtent.height, pre_transform);
        }
    }
}

void VulkanReplayConsumerBase::InitializeScreenshotHandler()
{
    screenshot_file_prefix_ = options_.screenshot_file_prefix;

    if (screenshot_file_prefix_.empty())
    {
        screenshot_file_prefix_ = kDefaultScreenshotFilePrefix;
    }

    if (!options_.screenshot_dir.empty())
    {
        screenshot_file_prefix_ = util::filepath::Join(options_.screenshot_dir, screenshot_file_prefix_);
    }

    screenshot_handler_ = std::make_unique<ScreenshotHandler>(options_.screenshot_format, options_.screenshot_ranges);
}

void VulkanReplayConsumerBase::WriteScreenshots(const Decoded_VkPresentInfoKHR* meta_info) const
{
    if ((meta_info != nullptr) && (meta_info->decoded_value != nullptr) && !meta_info->pSwapchains.IsNull())
    {
        auto present_info  = meta_info->decoded_value;
        auto swapchain_ids = meta_info->pSwapchains.GetPointer();

        for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
        {
            auto swapchain_info = object_info_table_.GetSwapchainKHRInfo(swapchain_ids[i]);
            if ((swapchain_info != nullptr) && (swapchain_info->device_info != nullptr) &&
                (swapchain_info->images.size() > 0))
            {
                auto     device_info = swapchain_info->device_info;
                uint32_t image_index = present_info->pImageIndices[i];

                auto instance_table = GetInstanceTable(device_info->parent);
                assert(instance_table != nullptr);

                // TODO: This should be stored in the DeviceInfo structure to avoid the need for frequent queries.
                VkPhysicalDeviceMemoryProperties memory_properties;
                instance_table->GetPhysicalDeviceMemoryProperties(device_info->parent, &memory_properties);

                std::string filename_prefix = screenshot_file_prefix_;

                if (present_info->swapchainCount > 1)
                {
                    filename_prefix += "_swapchain_";
                    filename_prefix += std::to_string(i);
                }

                filename_prefix += "_frame_";
                filename_prefix += std::to_string(screenshot_handler_->GetCurrentFrame());

                screenshot_handler_->WriteImage(filename_prefix,
                                                device_info->handle,
                                                GetDeviceTable(device_info->handle),
                                                memory_properties,
                                                device_info->allocator.get(),
                                                swapchain_info->images[image_index],
                                                swapchain_info->format,
                                                swapchain_info->width,
                                                swapchain_info->height);
            }
        }
    }
}

VkResult
VulkanReplayConsumerBase::OverrideCreateInstance(VkResult original_result,
                                                 const StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                                 const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                 HandlePointerDecoder<VkInstance>*                          pInstance)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((pInstance != nullptr) && !pInstance->IsNull() && (pInstance->GetHandlePointer() != nullptr) &&
           (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();
    auto replay_instance    = pInstance->GetHandlePointer();

    if (loader_handle_ == nullptr)
    {
        InitializeLoader();
    }

    // Replace WSI extension in extension list.
    std::vector<const char*> filtered_extensions;
    VkInstanceCreateInfo     modified_create_info{};

    if (replay_create_info != nullptr)
    {
        // If VkDebugUtilsMessengerCreateInfoEXT or VkDebugReportCallbackCreateInfoEXT are in the pNext chain, update
        // the callback pointers.
        ProcessCreateInstanceDebugCallbackInfo(pCreateInfo->GetMetaStructPointer());

        if (replay_create_info->ppEnabledExtensionNames)
        {
            // If a specific WSI extension was selected on the command line we need to make sure that extension is
            // loaded
            assert(application_);
            for (const auto& itr : application_->GetWsiContexts())
            {
                filtered_extensions.push_back(itr.first.c_str());
            }

            for (uint32_t i = 0; i < replay_create_info->enabledExtensionCount; ++i)
            {
                auto current_extension = replay_create_info->ppEnabledExtensionNames[i];
                filtered_extensions.push_back(current_extension);
                if (kSurfaceExtensions.find(current_extension) != kSurfaceExtensions.end())
                {
                    application_->InitializeWsiContext(current_extension);
                }
            }

            PFN_vkEnumerateInstanceExtensionProperties instance_extension_proc =
                reinterpret_cast<PFN_vkEnumerateInstanceExtensionProperties>(
                    get_instance_proc_addr_(nullptr, "vkEnumerateInstanceExtensionProperties"));
            std::vector<VkExtensionProperties> properties;
            if (feature_util::GetInstanceExtensions(instance_extension_proc, &properties) == VK_SUCCESS)
            {
                if (options_.remove_unsupported_features)
                {
                    // Remove enabled extensions that are not available from the replay instance.
                    // Proc addresses that can't be used in layers so are not generated into shared dispatch table, but
                    // are needed in the replay application.
                    feature_util::RemoveUnsupportedExtensions(properties, &filtered_extensions);
                }
                else
                {
                    // Check that the requested extensions are present and print warnings if not.
                    for (auto extensionIter = filtered_extensions.begin(); extensionIter != filtered_extensions.end();
                         ++extensionIter)
                    {
                        if (!feature_util::IsSupportedExtension(properties, *extensionIter))
                        {
                            GFXRECON_LOG_WARNING("Extension %s, is not supported by the replay device.",
                                                 *extensionIter);
                        }
                    }
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("Failed to get instance extensions. Cannot perform sanity checks or filters for "
                                     "extension availability.");
            }
        }

        modified_create_info                         = (*replay_create_info);
        modified_create_info.enabledExtensionCount   = static_cast<uint32_t>(filtered_extensions.size());
        modified_create_info.ppEnabledExtensionNames = filtered_extensions.data();
    }
    else
    {
        GFXRECON_LOG_WARNING("The vkCreateInstance parameter pCreateInfo is NULL.");
    }

    // Disable layers; any layers needed for replay should be enabled for the replay app with the VK_INSTANCE_LAYERS
    // environment variable or debug.vulkan.layers Android property.
    if (modified_create_info.enabledLayerCount > 0)
    {
        GFXRECON_LOG_INFO(
            "Replay has removed the following layers from VkInstanceCreateInfo when calling vkCreateInstance:");

        for (uint32_t i = 0; i < modified_create_info.enabledLayerCount; ++i)
        {
            GFXRECON_LOG_INFO("\t%s", modified_create_info.ppEnabledLayerNames[i]);
        }

        modified_create_info.enabledLayerCount   = 0;
        modified_create_info.ppEnabledLayerNames = nullptr;
    }

    VkResult result = create_instance_proc_(&modified_create_info, GetAllocationCallbacks(pAllocator), replay_instance);

    if ((replay_instance != nullptr) && (result == VK_SUCCESS))
    {
        AddInstanceTable(*replay_instance);

        if (modified_create_info.pApplicationInfo != nullptr)
        {
            auto instance_info = reinterpret_cast<InstanceInfo*>(pInstance->GetConsumerData(0));
            assert(instance_info != nullptr);

            instance_info->api_version = modified_create_info.pApplicationInfo->apiVersion;
            instance_info->enabled_extensions.assign(modified_create_info.ppEnabledExtensionNames,
                                                     modified_create_info.ppEnabledExtensionNames +
                                                         modified_create_info.enabledExtensionCount);
        }
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideDestroyDevice(
    PFN_vkDestroyDevice                                        func,
    const DeviceInfo*                                          device_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (device_info != nullptr)
    {
        if (screenshot_handler_ != nullptr)
        {
            VkDevice device = device_info->handle;
            screenshot_handler_->DestroyDeviceResources(device, GetDeviceTable(device));
        }
    }

    VulkanReplayBase::OverrideDestroyDevice(func, device_info, pAllocator);
}

VkResult VulkanReplayConsumerBase::OverrideGetPhysicalDeviceSurfaceCapabilitiesKHR(
    PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR           func,
    VkResult                                                original_result,
    PhysicalDeviceInfo*                                     physical_device_info,
    SurfaceKHRInfo*                                         surface_info,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    assert((physical_device_info != nullptr) && (surface_info != nullptr) && (pSurfaceCapabilities != nullptr) &&
           !pSurfaceCapabilities->IsNull() && (pSurfaceCapabilities->GetOutputPointer() != nullptr));

    VkPhysicalDevice physical_device             = physical_device_info->handle;
    VkSurfaceKHR     surface                     = surface_info->handle;
    auto             replay_surface_capabilities = pSurfaceCapabilities->GetOutputPointer();

    VkResult result = func(physical_device, surface, replay_surface_capabilities);
    if (result == VK_SUCCESS)
    {
        surface_info->surface_capabilities[physical_device] = *replay_surface_capabilities;
    }
    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetPhysicalDeviceSurfaceCapabilities2KHR(
    PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR                 func,
    VkResult                                                       original_result,
    PhysicalDeviceInfo*                                            physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>*       pSurfaceCapabilities)
{
    assert((physical_device_info != nullptr) && (pSurfaceInfo != nullptr) && (!pSurfaceInfo->IsNull()) &&
           (pSurfaceInfo->GetPointer() != nullptr) && (pSurfaceCapabilities != nullptr) &&
           !pSurfaceCapabilities->IsNull() && (pSurfaceCapabilities->GetOutputPointer() != nullptr));

    VkPhysicalDevice physical_device             = physical_device_info->handle;
    auto             replay_surface_info         = pSurfaceInfo->GetPointer();
    auto             replay_surface_capabilities = pSurfaceCapabilities->GetOutputPointer();

    VkResult result = func(physical_device, replay_surface_info, replay_surface_capabilities);
    if (result == VK_SUCCESS)
    {
        auto surface_id                                     = pSurfaceInfo->GetMetaStructPointer()->surface;
        auto surface_info                                   = GetObjectInfoTable().GetSurfaceKHRInfo(surface_id);
        surface_info->surface_capabilities[physical_device] = replay_surface_capabilities->surfaceCapabilities;
    }
    return result;
}

VkResult VulkanReplayConsumerBase::OverrideWaitForFences(PFN_vkWaitForFences                  func,
                                                         VkResult                             original_result,
                                                         const DeviceInfo*                    device_info,
                                                         uint32_t                             fenceCount,
                                                         const HandlePointerDecoder<VkFence>* pFences,
                                                         VkBool32                             waitAll,
                                                         uint64_t                             timeout)
{
    assert((device_info != nullptr) && (pFences != nullptr));

    VkResult             result               = VK_SUCCESS;
    VkDevice             device               = device_info->handle;
    uint32_t             modified_fence_count = fenceCount;
    const VkFence*       modified_fences      = nullptr;
    std::vector<VkFence> valid_fences;

    // Check for fences that need to be removed.
    if (shadow_fences_.empty())
    {
        modified_fences = pFences->GetHandlePointer();
    }
    else
    {
        const format::HandleId* fence_handles = pFences->GetPointer();
        for (size_t i = 0; i < pFences->GetLength(); ++i)
        {
            FenceInfo* fence_info = object_info_table_.GetFenceInfo(fence_handles[i]);
            if (fence_info != nullptr)
            {
                VkFence fence_handle = fence_info->handle;
                if (fence_info->shadow_signaled)
                {
                    // If found, unsignal the fence to represent it being used.
                    fence_info->shadow_signaled = false;
                    shadow_fences_.erase(fence_handle);
                }
                else
                {
                    valid_fences.push_back(fence_handle);
                }
            }
        }

        modified_fence_count = static_cast<uint32_t>(valid_fences.size());
        modified_fences      = valid_fences.data();
    }

    if (original_result == VK_SUCCESS)
    {
        // Ensure that wait for fences waits until the fences have been signaled (or error occurs) by changing the
        // timeout to UINT64_MAX.
        result = func(device, modified_fence_count, modified_fences, waitAll, std::numeric_limits<uint64_t>::max());
    }
    else if (original_result == VK_TIMEOUT)
    {
        // Try to get a timeout result with a 0 timeout.
        result = func(device, modified_fence_count, modified_fences, waitAll, 0);
    }
    else
    {
        result = func(device, modified_fence_count, modified_fences, waitAll, timeout);
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideQueueSubmit(PFN_vkQueueSubmit func,
                                                       VkResult          original_result,
                                                       const QueueInfo*  queue_info,
                                                       uint32_t          submitCount,
                                                       const StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                                       const FenceInfo*                                  fence_info)
{
    assert((queue_info != nullptr) && (pSubmits != nullptr));

    VkResult            result       = VK_SUCCESS;
    const VkSubmitInfo* submit_infos = pSubmits->GetPointer();
    assert(submitCount == 0 || submit_infos != nullptr);
    auto    submit_info_data = pSubmits->GetMetaStructPointer();
    VkFence fence            = VK_NULL_HANDLE;

    if (fence_info != nullptr)
    {
        fence = fence_info->handle;
    }

    // Only attempt to filter imported semaphores if we know at least one has been imported.
    // If rendering is restricted to a specific surface, shadow semaphore and forward progress state will need to be
    // tracked.
    if ((!have_imported_semaphores_) && (options_.surface_index == -1))
    {
        result = func(queue_info->handle, submitCount, submit_infos, fence);
    }
    else
    {
        // Check for imported semaphores in the current submission list, mapping the pSubmits array index to a vector of
        // imported semaphore info structures.
        std::unordered_map<uint32_t, std::vector<const SemaphoreInfo*>> altered_submits;
        std::vector<const SemaphoreInfo*>                               removed_semaphores;

        if (submit_info_data != nullptr)
        {
            for (uint32_t i = 0; i < submitCount; i++)
            {
                GetImportedSemaphores(submit_info_data[i].pWaitSemaphores, &removed_semaphores);
                GetShadowSemaphores(submit_info_data[i].pWaitSemaphores, &removed_semaphores);

                // If rendering is restricted to a specific surface, need to track forward progress for semaphores that
                // have been submitted with a null-swapchain.
                TrackSemaphoreForwardProgress(submit_info_data[i].pWaitSemaphores, &removed_semaphores);

                // Remove non-forward progress of signal semaphores.
                GetNonForwardProgress(submit_info_data[i].pSignalSemaphores, &removed_semaphores);

                if (!removed_semaphores.empty())
                {
                    altered_submits[i].swap(removed_semaphores);
                    assert(removed_semaphores.empty());
                }
            }
        }

        if (altered_submits.empty())
        {
            result = func(queue_info->handle, submitCount, submit_infos, fence);
        }
        else
        {
            // Make shallow copies of the VkSubmit info structures and change pWaitSemaphores to reference a copy of the
            // original semaphore array with the imported semaphores omitted.
            std::vector<VkSubmitInfo> modified_submit_infos(submit_infos, std::next(submit_infos, submitCount));

            std::vector<VkSemaphore> wait_semaphores;
            std::vector<VkSemaphore> signal_semaphores;

            for (const auto& submit_iter : altered_submits)
            {
                // Shallow copy with filtered copy of pWaitSemaphores for submission info with imported semaphores.
                VkSubmitInfo& modified_submit_info = modified_submit_infos[submit_iter.first];
                auto          semaphore_iter       = submit_iter.second.begin();

                for (uint32_t i = 0; i < modified_submit_info.waitSemaphoreCount; ++i)
                {
                    VkSemaphore semaphore = modified_submit_info.pWaitSemaphores[i];

                    if ((semaphore_iter == submit_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        wait_semaphores.push_back(semaphore);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                for (uint32_t i = 0; i < modified_submit_info.signalSemaphoreCount; ++i)
                {
                    VkSemaphore semaphore = modified_submit_info.pSignalSemaphores[i];

                    if ((semaphore_iter == submit_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        signal_semaphores.push_back(semaphore);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                modified_submit_info.waitSemaphoreCount   = static_cast<uint32_t>(wait_semaphores.size());
                modified_submit_info.pWaitSemaphores      = wait_semaphores.data();
                modified_submit_info.signalSemaphoreCount = static_cast<uint32_t>(signal_semaphores.size());
                modified_submit_info.pSignalSemaphores    = signal_semaphores.data();
            }

            result = func(queue_info->handle,
                          static_cast<uint32_t>(modified_submit_infos.size()),
                          modified_submit_infos.data(),
                          fence);
        }
    }

    if ((options_.sync_queue_submissions) && (result == VK_SUCCESS))
    {
        GetDeviceTable(queue_info->handle)->QueueWaitIdle(queue_info->handle);
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideQueueSubmit2(PFN_vkQueueSubmit2 func,
                                                        VkResult           original_result,
                                                        const QueueInfo*   queue_info,
                                                        uint32_t           submitCount,
                                                        const StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                                        const FenceInfo*                                   fence_info)
{
    assert((queue_info != nullptr) && (pSubmits != nullptr));

    VkResult             result       = VK_SUCCESS;
    const VkSubmitInfo2* submit_infos = pSubmits->GetPointer();
    assert(submitCount == 0 || submit_infos != nullptr);
    auto    submit_info_data = pSubmits->GetMetaStructPointer();
    VkFence fence            = VK_NULL_HANDLE;

    if (fence_info != nullptr)
    {
        fence = fence_info->handle;
    }

    // Only attempt to filter imported semaphores if we know at least one has been imported.
    // If rendering is restricted to a specific surface, shadow semaphore and forward progress state will need to be
    // tracked.
    if ((!have_imported_semaphores_) && (options_.surface_index == -1))
    {
        result = func(queue_info->handle, submitCount, submit_infos, fence);
    }
    else
    {
        // Check for imported semaphores in the current submission list, mapping the pSubmits array index to a vector of
        // imported semaphore info structures.
        std::unordered_map<uint32_t, std::vector<const SemaphoreInfo*>> altered_submits;
        std::vector<const SemaphoreInfo*>                               removed_semaphores;

        if (submit_info_data != nullptr)
        {
            for (uint32_t i = 0; i < submitCount; i++)
            {
                GetImportedSemaphores(submit_info_data[i].pWaitSemaphoreInfos, &removed_semaphores);
                GetShadowSemaphores(submit_info_data[i].pWaitSemaphoreInfos, &removed_semaphores);

                // If rendering is restricted to a specific surface, need to track forward progress for semaphores that
                // have been submitted with a null-swapchain.
                TrackSemaphoreForwardProgress(submit_info_data[i].pWaitSemaphoreInfos, &removed_semaphores);

                // Remove non-forward progress of signal semaphores.
                GetNonForwardProgress(submit_info_data[i].pWaitSemaphoreInfos, &removed_semaphores);

                if (!removed_semaphores.empty())
                {
                    altered_submits[i].swap(removed_semaphores);
                    assert(removed_semaphores.empty());
                }
            }
        }

        if (altered_submits.empty())
        {
            result = func(queue_info->handle, submitCount, submit_infos, fence);
        }
        else
        {
            // Make shallow copies of the VkSubmit info structures and change pWaitSemaphores to reference a copy of the
            // original semaphore array with the imported semaphores omitted.
            std::vector<VkSubmitInfo2> modified_submit_infos(submit_infos, std::next(submit_infos, submitCount));
            std::vector<std::vector<VkSemaphore>> semaphore_memory(altered_submits.size());

            std::vector<VkSemaphoreSubmitInfo> wait_semaphore_infos;
            std::vector<VkSemaphoreSubmitInfo> signal_semaphore_infos;

            for (const auto& submit_iter : altered_submits)
            {
                // Shallow copy with filtered copy of pWaitSemaphores for submission info with imported semaphores.
                VkSubmitInfo2& modified_submit_info = modified_submit_infos[submit_iter.first];
                auto           semaphore_iter       = submit_iter.second.begin();

                for (uint32_t i = 0; i < modified_submit_info.waitSemaphoreInfoCount; ++i)
                {
                    VkSemaphore semaphore = modified_submit_info.pWaitSemaphoreInfos[i].semaphore;

                    if ((semaphore_iter == submit_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        VkSemaphoreSubmitInfo info{};
                        info.sType     = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO;
                        info.semaphore = semaphore;

                        wait_semaphore_infos.emplace_back(info);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                for (uint32_t i = 0; i < modified_submit_info.signalSemaphoreInfoCount; ++i)
                {
                    VkSemaphore semaphore = modified_submit_info.pSignalSemaphoreInfos[i].semaphore;

                    if ((semaphore_iter == submit_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        VkSemaphoreSubmitInfo info{};
                        info.sType     = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO;
                        info.semaphore = semaphore;

                        signal_semaphore_infos.emplace_back(info);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                modified_submit_info.waitSemaphoreInfoCount   = static_cast<uint32_t>(wait_semaphore_infos.size());
                modified_submit_info.pWaitSemaphoreInfos      = wait_semaphore_infos.data();
                modified_submit_info.signalSemaphoreInfoCount = static_cast<uint32_t>(signal_semaphore_infos.size());
                modified_submit_info.pSignalSemaphoreInfos    = signal_semaphore_infos.data();
            }

            result = func(queue_info->handle,
                          static_cast<uint32_t>(modified_submit_infos.size()),
                          modified_submit_infos.data(),
                          fence);
        }
    }

    if ((options_.sync_queue_submissions) && (result == VK_SUCCESS))
    {
        GetDeviceTable(queue_info->handle)->QueueWaitIdle(queue_info->handle);
    }

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideQueueBindSparse(PFN_vkQueueBindSparse                                 func,
                                                  VkResult                                              original_result,
                                                  const QueueInfo*                                      queue_info,
                                                  uint32_t                                              bindInfoCount,
                                                  const StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
                                                  const FenceInfo*                                      fence_info)
{
    assert((queue_info != nullptr) && (pBindInfo != nullptr) && !pBindInfo->IsNull());

    VkResult                result     = VK_SUCCESS;
    const VkBindSparseInfo* bind_infos = pBindInfo->GetPointer();
    VkFence                 fence      = VK_NULL_HANDLE;

    if (fence_info != nullptr)
    {
        fence = fence_info->handle;
    }

    // Only attempt to filter imported semaphores if we know at least one has been imported.
    // If rendering is restricted to a specific surface, shadow semaphore and forward progress state will need to be
    // tracked.
    if ((!have_imported_semaphores_) && (options_.surface_index == -1))
    {
        result = func(queue_info->handle, bindInfoCount, bind_infos, fence);
    }
    else
    {
        // Check for imported semaphores in the current bind info list, mapping the pBindInfo array index to a vector of
        // imported semaphore info structures.
        std::unordered_map<uint32_t, std::vector<const SemaphoreInfo*>> altered_submits;
        std::vector<const SemaphoreInfo*>                               removed_semaphores;

        auto bind_info_data = pBindInfo->GetMetaStructPointer();
        if (bind_info_data != nullptr)
        {
            for (uint32_t i = 0; i < bindInfoCount; i++)
            {
                GetImportedSemaphores(bind_info_data[i].pWaitSemaphores, &removed_semaphores);
                GetShadowSemaphores(bind_info_data[i].pWaitSemaphores, &removed_semaphores);

                // If rendering is restricted to a specific surface, need to track forward progress for semaphores that
                // have been submitted with a null-swapchain.
                TrackSemaphoreForwardProgress(bind_info_data[i].pWaitSemaphores, &removed_semaphores);

                // Remove non-forward progress of signal semaphores.
                GetNonForwardProgress(bind_info_data[i].pSignalSemaphores, &removed_semaphores);

                if (!removed_semaphores.empty())
                {
                    altered_submits[i].swap(removed_semaphores);
                    assert(removed_semaphores.empty());
                }
            }
        }

        if (altered_submits.empty())
        {
            result = func(queue_info->handle, bindInfoCount, bind_infos, fence);
        }
        else
        {
            // Make shallow copies of the VkBindSparseInfo structures and change pWaitSemaphores to reference a copy of
            // the original semaphore array with the imported semaphores omitted.
            std::vector<VkBindSparseInfo>         modified_bind_infos(bind_infos, std::next(bind_infos, bindInfoCount));
            std::vector<std::vector<VkSemaphore>> semaphore_memory(altered_submits.size());

            std::vector<VkSemaphore> wait_semaphores;
            std::vector<VkSemaphore> signal_semaphores;

            for (const auto& bind_iter : altered_submits)
            {
                // Shallow copy with filtered copy of pWaitSemaphores for bind info with imported semaphores.
                VkBindSparseInfo& modified_bind_info = modified_bind_infos[bind_iter.first];
                auto              semaphore_iter     = bind_iter.second.begin();

                for (uint32_t j = 0; j < modified_bind_info.waitSemaphoreCount; ++j)
                {
                    VkSemaphore semaphore = modified_bind_info.pWaitSemaphores[j];

                    if ((semaphore_iter == bind_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        wait_semaphores.push_back(semaphore);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                for (uint32_t j = 0; j < modified_bind_info.signalSemaphoreCount; ++j)
                {
                    VkSemaphore semaphore = modified_bind_info.pSignalSemaphores[j];

                    if ((semaphore_iter == bind_iter.second.end()) || ((*semaphore_iter)->handle != semaphore))
                    {
                        signal_semaphores.push_back(semaphore);
                    }
                    else
                    {
                        // Omit the ignored semaphore from the current submission.
                        ++semaphore_iter;
                    }
                }

                modified_bind_info.waitSemaphoreCount = static_cast<uint32_t>(wait_semaphores.size());
                modified_bind_info.pWaitSemaphores    = wait_semaphores.data();
                modified_bind_info.waitSemaphoreCount = static_cast<uint32_t>(signal_semaphores.size());
                modified_bind_info.pWaitSemaphores    = signal_semaphores.data();
            }

            result = func(queue_info->handle,
                          static_cast<uint32_t>(modified_bind_infos.size()),
                          modified_bind_infos.data(),
                          fence);
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateRenderPass(
    PFN_vkCreateRenderPass                                      func,
    VkResult                                                    original_result,
    const DeviceInfo*                                           device_info,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
    HandlePointerDecoder<VkRenderPass>*                         pRenderPass)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    return swapchain_->CreateRenderPass(func,
                                        device_info,
                                        pCreateInfo->GetPointer(),
                                        GetAllocationCallbacks(pAllocator),
                                        pRenderPass->GetHandlePointer());
}

VkResult VulkanReplayConsumerBase::OverrideCreateRenderPass2(
    PFN_vkCreateRenderPass2                                      func,
    VkResult                                                     original_result,
    const DeviceInfo*                                            device_info,
    const StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
    HandlePointerDecoder<VkRenderPass>*                          pRenderPass)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    return swapchain_->CreateRenderPass2(func,
                                         device_info,
                                         pCreateInfo->GetPointer(),
                                         GetAllocationCallbacks(pAllocator),
                                         pRenderPass->GetHandlePointer());
}

void VulkanReplayConsumerBase::OverrideCmdPipelineBarrier(
    PFN_vkCmdPipelineBarrier                                   func,
    const CommandBufferInfo*                                   command_buffer_info,
    VkPipelineStageFlags                                       srcStageMask,
    VkPipelineStageFlags                                       dstStageMask,
    VkDependencyFlags                                          dependencyFlags,
    uint32_t                                                   memoryBarrierCount,
    const StructPointerDecoder<Decoded_VkMemoryBarrier>*       pMemoryBarriers,
    uint32_t                                                   bufferMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
    uint32_t                                                   imageMemoryBarrierCount,
    const StructPointerDecoder<Decoded_VkImageMemoryBarrier>*  pImageMemoryBarriers)
{
    swapchain_->CmdPipelineBarrier(func,
                                   command_buffer_info,
                                   srcStageMask,
                                   dstStageMask,
                                   dependencyFlags,
                                   memoryBarrierCount,
                                   pMemoryBarriers->GetPointer(),
                                   bufferMemoryBarrierCount,
                                   pBufferMemoryBarriers->GetPointer(),
                                   imageMemoryBarrierCount,
                                   pImageMemoryBarriers->GetPointer());
}

VkResult VulkanReplayConsumerBase::OverrideCreateShaderModule(
    PFN_vkCreateShaderModule                                      func,
    VkResult                                                      original_result,
    const DeviceInfo*                                             device_info,
    const StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkShaderModule>*                         pShaderModule)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && !pCreateInfo->IsNull() &&
           (pShaderModule != nullptr) && !pShaderModule->IsNull());

    auto original_info = pCreateInfo->GetPointer();
    if (original_result < 0 || options_.replace_dir.empty())
    {
        return func(
            device_info->handle, original_info, GetAllocationCallbacks(pAllocator), pShaderModule->GetHandlePointer());
    }

    VkShaderModuleCreateInfo override_info = *original_info;

    // Replace shader in 'override_info'
    std::unique_ptr<char[]> file_code;
    const uint32_t*         orig_code = original_info->pCode;
    size_t                  orig_size = original_info->codeSize;
    uint64_t                handle_id = *pShaderModule->GetPointer();
    std::string             file_name = "sh" + std::to_string(handle_id);
    std::string             file_path = util::filepath::Join(options_.replace_dir, file_name);

    FILE*   fp     = nullptr;
    int32_t result = util::platform::FileOpen(&fp, file_path.c_str(), "rb");
    if (result == 0)
    {
        util::platform::FileSeek(fp, 0L, util::platform::FileSeekEnd);
        size_t file_size = static_cast<size_t>(util::platform::FileTell(fp));
        file_code        = std::make_unique<char[]>(file_size);
        util::platform::FileSeek(fp, 0L, util::platform::FileSeekSet);
        util::platform::FileRead(file_code.get(), sizeof(char), file_size, fp);
        override_info.pCode    = (uint32_t*)file_code.get();
        override_info.codeSize = file_size;
        GFXRECON_LOG_INFO("Replacement shader found: %s", file_path.c_str());
    }

    return func(
        device_info->handle, &override_info, GetAllocationCallbacks(pAllocator), pShaderModule->GetHandlePointer());
}

VkResult VulkanReplayConsumerBase::OverrideGetPipelineCacheData(PFN_vkGetPipelineCacheData func,
                                                                VkResult                   original_result,
                                                                const DeviceInfo*          device_info,
                                                                const PipelineCacheInfo*   pipeline_cache_info,
                                                                PointerDecoder<size_t>*    pDataSize,
                                                                PointerDecoder<uint8_t>*   pData)
{
    if (options_.omit_pipeline_cache_data)
    {
        return original_result;
    }
    else
    {
        return func(
            device_info->handle, pipeline_cache_info->handle, pDataSize->GetOutputPointer(), pData->GetOutputPointer());
    }
}

VkResult VulkanReplayConsumerBase::OverrideCreateDebugReportCallbackEXT(
    PFN_vkCreateDebugReportCallbackEXT                                      func,
    VkResult                                                                original_result,
    const InstanceInfo*                                                     instance_info,
    const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*              pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>*                         pCallback)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr) && (pCallback != nullptr) &&
           (pCallback->GetHandlePointer() != nullptr));

    VkDebugReportCallbackCreateInfoEXT modified_create_info{};

    if (!pCreateInfo->IsNull())
    {
        modified_create_info             = (*pCreateInfo->GetPointer());
        modified_create_info.pfnCallback = DebugReportCallback;
    }
    else
    {
        GFXRECON_LOG_WARNING("The vkCreateDebugReportCallbackEXT parameter pCreateInfo is NULL.");
    }

    return func(instance_info->handle,
                &modified_create_info,
                GetAllocationCallbacks(pAllocator),
                pCallback->GetHandlePointer());
}

VkResult VulkanReplayConsumerBase::OverrideCreateDebugUtilsMessengerEXT(
    PFN_vkCreateDebugUtilsMessengerEXT                                      func,
    VkResult                                                                original_result,
    const InstanceInfo*                                                     instance_info,
    const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*              pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>*                         pMessenger)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr) && (pMessenger != nullptr) &&
           (pMessenger->GetHandlePointer() != nullptr));

    VkDebugUtilsMessengerCreateInfoEXT modified_create_info{};
    if (!pCreateInfo->IsNull())
    {
        modified_create_info                 = (*pCreateInfo->GetPointer());
        modified_create_info.pfnUserCallback = DebugUtilsCallback;
    }
    else
    {
        GFXRECON_LOG_WARNING("The vkCreateDebugUtilsMessengerEXT parameter pCreateInfo is NULL.");
    }

    return func(instance_info->handle,
                &modified_create_info,
                GetAllocationCallbacks(pAllocator),
                pMessenger->GetHandlePointer());
}

VkResult VulkanReplayConsumerBase::OverrideCreateSwapchainKHR(
    PFN_vkCreateSwapchainKHR                                      func,
    VkResult                                                      original_result,
    DeviceInfo*                                                   device_info,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*                         pSwapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && !pCreateInfo->IsNull() && (pSwapchain != nullptr) &&
           !pSwapchain->IsNull() && (pSwapchain->GetHandlePointer() != nullptr));

    VkResult result             = VK_SUCCESS;
    auto     replay_create_info = pCreateInfo->GetPointer();
    GFXRECON_ASSERT(replay_create_info != nullptr);
    auto replay_swapchain = pSwapchain->GetHandlePointer();
    auto swapchain_info   = reinterpret_cast<SwapchainKHRInfo*>(pSwapchain->GetConsumerData(0));
    assert(swapchain_info != nullptr);

    // Ignore swapchain creation if surface creation was skipped when rendering is restricted to a specific surface.
    if (replay_create_info->surface != VK_NULL_HANDLE)
    {
        // Ensure that the window has been resized properly.  For Android, this ensures that we will set the proper
        // screen orientation when the swapchain pre-transform specifies a 90 or 270 degree rotation for older files
        // that do not include a ResizeWindowCmd2 command.
        auto meta_info = pCreateInfo->GetMetaStructPointer();
        if (meta_info != nullptr)
        {
            SetSwapchainWindowSize(meta_info);
        }

        ProcessSwapchainFullScreenExclusiveInfo(pCreateInfo->GetMetaStructPointer());

        VkPhysicalDevice             physical_device = device_info->parent;
        const encode::InstanceTable* instance_table  = GetInstanceTable(physical_device);
        VkDevice                     device          = device_info->handle;
        const encode::DeviceTable*   device_table    = GetDeviceTable(device);

        if (screenshot_handler_ == nullptr)
        {
            result = swapchain_->CreateSwapchainKHR(func,
                                                    device_info,
                                                    replay_create_info,
                                                    GetAllocationCallbacks(pAllocator),
                                                    replay_swapchain,
                                                    physical_device,
                                                    instance_table,
                                                    device_table);
        }
        else
        {
            // Screenshots are active, so ensure that swapchain images can be used as a transfer source.
            VkSwapchainCreateInfoKHR modified_create_info = (*replay_create_info);
            modified_create_info.imageUsage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
            result = swapchain_->CreateSwapchainKHR(func,
                                                    device_info,
                                                    &modified_create_info,
                                                    GetAllocationCallbacks(pAllocator),
                                                    replay_swapchain,
                                                    physical_device,
                                                    instance_table,
                                                    device_table);
        }
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping creation for swapchain (ID = %" PRIu64 "), which is backed by a disabled surface",
                          swapchain_info->capture_id);

        // Set fax handle data to find uncreated swapchain later.
        // Possible colision of handles from driver, but should not occur starting with uint max.
        static format::HandleId dummy_handle = std::numeric_limits<uint64_t>::max();
        (*replay_swapchain)                  = format::FromHandleId<VkSwapchainKHR>(dummy_handle);
        --dummy_handle;

        swapchain_info->surface    = VK_NULL_HANDLE;
        swapchain_info->surface_id = format::kNullHandleId;
    }

    swapchain_info->image_flags        = replay_create_info->flags;
    swapchain_info->image_array_layers = replay_create_info->imageArrayLayers;
    swapchain_info->image_usage        = replay_create_info->imageUsage;
    swapchain_info->image_sharing_mode = replay_create_info->imageSharingMode;
    swapchain_info->device_info        = device_info;
    swapchain_info->width              = replay_create_info->imageExtent.width;
    swapchain_info->height             = replay_create_info->imageExtent.height;
    swapchain_info->format             = replay_create_info->imageFormat;

    if ((result == VK_SUCCESS) && ((*replay_swapchain) != VK_NULL_HANDLE))
    {
        if ((replay_create_info->imageSharingMode == VK_SHARING_MODE_CONCURRENT) &&
            (replay_create_info->queueFamilyIndexCount > 0) && (replay_create_info->pQueueFamilyIndices != nullptr))
        {
            swapchain_info->queue_family_indices.resize(replay_create_info->queueFamilyIndexCount);
            std::memcpy(swapchain_info->queue_family_indices.data(),
                        replay_create_info->pQueueFamilyIndices,
                        sizeof(uint32_t) * replay_create_info->queueFamilyIndexCount);
        }
        else
        {
            swapchain_info->queue_family_indices.clear();
            swapchain_info->queue_family_indices.emplace_back(0);
        }

        swapchain_info->surface    = replay_create_info->surface;
        swapchain_info->surface_id = pCreateInfo->GetMetaStructPointer()->surface;
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideDestroySwapchainKHR(
    PFN_vkDestroySwapchainKHR                                  func,
    DeviceInfo*                                                device_info,
    SwapchainKHRInfo*                                          swapchain_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Delete backed images of dummy swapchain.
    if ((swapchain_info != nullptr) && (swapchain_info->surface == VK_NULL_HANDLE))
    {
        auto allocator = device_info->allocator.get();
        assert(allocator != nullptr);

        for (const ImageInfo& image_info : swapchain_info->image_infos)
        {
            allocator->DestroyImageDirect(image_info.handle, nullptr, image_info.allocator_data);
            allocator->FreeMemoryDirect(image_info.memory, nullptr, image_info.memory_allocator_data);
        }
    }
    else
    {
        swapchain_->DestroySwapchainKHR(func, device_info, swapchain_info, GetAllocationCallbacks(pAllocator));
    }
}

VkResult VulkanReplayConsumerBase::OverrideGetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR    func,
                                                                 VkResult                       original_result,
                                                                 const DeviceInfo*              device_info,
                                                                 SwapchainKHRInfo*              swapchain_info,
                                                                 PointerDecoder<uint32_t>*      pSwapchainImageCount,
                                                                 HandlePointerDecoder<VkImage>* pSwapchainImages)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (swapchain_info != nullptr) && (pSwapchainImageCount != nullptr) &&
           !pSwapchainImageCount->IsNull() && (pSwapchainImages != nullptr));

    VkResult result              = original_result;
    auto     replay_image_count  = pSwapchainImageCount->GetOutputPointer();
    auto     replay_images       = pSwapchainImages->GetHandlePointer();
    uint32_t capture_image_count = *pSwapchainImageCount->GetPointer();

    // Handle if swapchain was never created due to surface-index being skipped
    if (swapchain_info->surface == VK_NULL_HANDLE)
    {
        if (replay_images == nullptr)
        {
            // Set the image count from data saved in trace file.
            (*replay_image_count) = capture_image_count;
        }
        else
        {
            // Create an image for the null swapchain.  Based on vkspec.html#swapchain-wsi-image-create-info.
            VkImageCreateInfo image_create_info = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
            image_create_info.pNext             = nullptr;
            image_create_info.flags             = 0;
            image_create_info.imageType         = VK_IMAGE_TYPE_2D;
            image_create_info.format            = swapchain_info->format;
            image_create_info.extent            = { swapchain_info->width, swapchain_info->height, 1 };
            image_create_info.mipLevels         = 1;
            image_create_info.arrayLayers       = swapchain_info->image_array_layers;
            image_create_info.samples           = VK_SAMPLE_COUNT_1_BIT;
            image_create_info.tiling            = VK_IMAGE_TILING_OPTIMAL;
            image_create_info.usage             = swapchain_info->image_usage;
            image_create_info.sharingMode       = swapchain_info->image_sharing_mode;
            image_create_info.queueFamilyIndexCount =
                static_cast<uint32_t>(swapchain_info->queue_family_indices.size());
            image_create_info.pQueueFamilyIndices = swapchain_info->queue_family_indices.data();
            image_create_info.initialLayout       = VK_IMAGE_LAYOUT_UNDEFINED;

            if ((swapchain_info->image_flags & VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR) ==
                VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR)
            {
                image_create_info.flags |= VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT;
            }

            GFXRECON_LOG_INFO("Creating %u images of %ux%u to back dummy swapchain (ID = %" PRIu64 ")",
                              capture_image_count,
                              image_create_info.extent.width,
                              image_create_info.extent.height,
                              swapchain_info->capture_id);

            for (uint32_t i = 0; i < capture_image_count; ++i)
            {
                VkImage*   replay_image = &(replay_images[i]);
                ImageInfo* image_info   = reinterpret_cast<ImageInfo*>(pSwapchainImages->GetConsumerData(i));
                assert(image_info != nullptr);

                result = CreateSwapchainImage(device_info, &image_create_info, replay_image, image_info);

                if ((result != VK_SUCCESS) || (replay_image == VK_NULL_HANDLE))
                {
                    GFXRECON_LOG_ERROR("Unable to create backing images for dummy swapchain (ID = %" PRIu64 ")",
                                       swapchain_info->capture_id);
                    break;
                }

                image_info->is_swapchain_image = true;

                // Create a copy of the image info to use for image cleanup when the swapchain is destroyed.
                swapchain_info->image_infos.push_back(*image_info);
            }
        }
    }
    else
    {
        // It means the application only ran GetSwapchainImage once. It didn't get image count first.
        if (swapchain_info->replay_image_count == 0 && replay_images != nullptr)
        {
            func(device_info->handle, swapchain_info->handle, &swapchain_info->replay_image_count, nullptr);
        }

        result = swapchain_->GetSwapchainImagesKHR(
            func, device_info, swapchain_info, capture_image_count, replay_image_count, replay_images);

        if ((result == VK_SUCCESS) && (replay_images != nullptr) && (replay_image_count != nullptr))
        {
            uint32_t count = (*replay_image_count);

            swapchain_info->acquired_indices.resize(count);

            for (uint32_t i = 0; i < count; ++i)
            {
                auto image_info = reinterpret_cast<ImageInfo*>(pSwapchainImages->GetConsumerData(i));
                assert(image_info != nullptr);

                image_info->is_swapchain_image = true;
            }

            // Store image handles for screenshot generation.
            if ((screenshot_handler_ != nullptr) && (swapchain_info->images.size() < count))
            {
                if (!swapchain_info->images.empty())
                {
                    // Clear any images that may have been stored by a previous, incomplete call to
                    // vkGetSwapchainImagesKHR.
                    swapchain_info->images.clear();
                }

                for (uint32_t i = 0; i < count; ++i)
                {
                    swapchain_info->images.push_back(replay_images[i]);
                }
            }
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                                               VkResult                  original_result,
                                                               const DeviceInfo*         device_info,
                                                               SwapchainKHRInfo*         swapchain_info,
                                                               uint64_t                  timeout,
                                                               SemaphoreInfo*            semaphore_info,
                                                               FenceInfo*                fence_info,
                                                               PointerDecoder<uint32_t>* pImageIndex)
{
    assert(swapchain_info != nullptr);

    VkResult result = VK_SUCCESS;

    // If image acquire failed at capture, there is nothing worth replaying as the fence and semaphore aren't processed
    // and a successful acquire on replay of an image that does not have a corresponding present to replay can lead to
    // OUT_OF_DATE errors.
    if (original_result < 0)
    {
        result = original_result;
    }
    else if (swapchain_info->surface != VK_NULL_HANDLE)
    {
        assert((device_info != nullptr) && (pImageIndex != nullptr) && !pImageIndex->IsNull());

        VkDevice       device               = device_info->handle;
        VkSwapchainKHR swapchain            = swapchain_info->handle;
        VkSemaphore    semaphore            = (semaphore_info != nullptr) ? semaphore_info->handle : VK_NULL_HANDLE;
        VkFence        fence                = (fence_info != nullptr) ? fence_info->handle : VK_NULL_HANDLE;
        VkSemaphore    preacquire_semaphore = VK_NULL_HANDLE;
        VkFence        preacquire_fence     = VK_NULL_HANDLE;
        uint32_t       captured_index       = (*pImageIndex->GetPointer());

        if (swapchain_image_tracker_.RetrievePreAcquiredImage(
                swapchain, captured_index, &preacquire_semaphore, &preacquire_fence))
        {
            auto table = GetDeviceTable(device);
            assert(table != nullptr);

            if (captured_index >= static_cast<uint32_t>(swapchain_info->acquired_indices.size()))
            {
                swapchain_info->acquired_indices.resize(captured_index + 1);
            }

            swapchain_info->acquired_indices[captured_index] = { captured_index, true };

            // The image has already been acquired. Swap the synchronization objects.
            if (semaphore != VK_NULL_HANDLE)
            {
                // TODO: This should be processed at a higher level where the original handle IDs are available, so that
                // the swap can be performed with the original handle ID and the semaphore can be guaranteed not to be
                // used after destroy.
                object_info_table_.ReplaceSemaphore(semaphore, preacquire_semaphore);
                preacquire_semaphore = semaphore;
            }

            if (fence != VK_NULL_HANDLE)
            {
                // TODO: This should be processed at a higher level where the original handle IDs are available, so that
                // the swap can be performed with the original handle ID and the fence can be guaranteed not to be used
                // after destroy.
                object_info_table_.ReplaceFence(fence, preacquire_fence);
                preacquire_fence = fence;
            }

            table->DestroySemaphore(device, preacquire_semaphore, nullptr);
            table->DestroyFence(device, preacquire_fence, nullptr);
        }
        else
        {
            auto replay_index = pImageIndex->GetOutputPointer();

            assert(replay_index != nullptr);

            result = swapchain_->AcquireNextImageKHR(
                func, device_info, swapchain_info, timeout, semaphore_info, fence_info, captured_index, replay_index);

            if (captured_index >= static_cast<uint32_t>(swapchain_info->acquired_indices.size()))
            {
                swapchain_info->acquired_indices.resize(captured_index + 1);
            }

            // Track the index that was acquired on replay, which may be different than the captured index.
            swapchain_info->acquired_indices[captured_index] = { (*replay_index), true };
        }
    }
    else
    {
        // Track semphore and fence objects as shadow objects so that they can be ignored when they would have been
        // unsignaled (waited on).
        if (semaphore_info != nullptr)
        {
            semaphore_info->shadow_signaled = true;
            shadow_semaphores_.insert(semaphore_info->handle);
        }

        if (fence_info != nullptr)
        {
            fence_info->shadow_signaled = true;
            shadow_fences_.insert(fence_info->handle);
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAcquireNextImage2KHR(
    PFN_vkAcquireNextImage2KHR                                     func,
    VkResult                                                       original_result,
    const DeviceInfo*                                              device_info,
    const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                                      pImageIndex)
{
    assert((pAcquireInfo != nullptr) && !pAcquireInfo->IsNull());

    VkResult          result            = VK_SUCCESS;
    auto              acquire_meta_info = pAcquireInfo->GetMetaStructPointer();
    SwapchainKHRInfo* swapchain_info    = object_info_table_.GetSwapchainKHRInfo(acquire_meta_info->swapchain);
    assert(swapchain_info != nullptr);

    // If image acquire failed at capture, there is nothing worth replaying as the fence and semaphore aren't processed
    // and a successful acquire on replay of an image that does not have a corresponding present to replay can lead to
    // OUT_OF_DATE errors.
    if (original_result < 0)
    {
        result = original_result;
    }
    else if (swapchain_info->surface != VK_NULL_HANDLE)
    {
        assert((device_info != nullptr) && (pImageIndex != nullptr) && !pImageIndex->IsNull());

        VkDevice    device               = device_info->handle;
        VkSemaphore preacquire_semaphore = VK_NULL_HANDLE;
        VkFence     preacquire_fence     = VK_NULL_HANDLE;
        auto        replay_acquire_info  = pAcquireInfo->GetPointer();
        uint32_t    captured_index       = (*pImageIndex->GetPointer());

        if (swapchain_image_tracker_.RetrievePreAcquiredImage(
                replay_acquire_info->swapchain, captured_index, &preacquire_semaphore, &preacquire_fence))
        {
            auto table = GetDeviceTable(device);
            assert(table != nullptr);

            if (captured_index >= static_cast<uint32_t>(swapchain_info->acquired_indices.size()))
            {
                swapchain_info->acquired_indices.resize(captured_index + 1);
            }

            if (swapchain_info != nullptr)
            {
                swapchain_info->acquired_indices[captured_index] = { captured_index, true };
            }

            // The image has already been acquired. Swap the synchronization objects.
            if (replay_acquire_info->semaphore != VK_NULL_HANDLE)
            {
                // TODO: This should be processed at a higher level where the original handle IDs are available, so that
                // the swap can be performed with the original handle ID and the semaphore can be guaranteed not to be
                // used after destroy.
                object_info_table_.ReplaceSemaphore(replay_acquire_info->semaphore, preacquire_semaphore);
                preacquire_semaphore = replay_acquire_info->semaphore;
            }

            if (replay_acquire_info->fence != VK_NULL_HANDLE)
            {
                // TODO: This should be processed at a higher level where the original handle IDs are available, so that
                // the swap can be performed with the original handle ID and the fence can be guaranteed not to be used
                // after destroy.
                object_info_table_.ReplaceFence(replay_acquire_info->fence, preacquire_fence);
                preacquire_fence = replay_acquire_info->fence;
            }

            table->DestroySemaphore(device, preacquire_semaphore, nullptr);
            table->DestroyFence(device, preacquire_fence, nullptr);
        }
        else
        {
            auto replay_index = pImageIndex->GetOutputPointer();

            assert(replay_index != nullptr);

            auto swapchain_info = object_info_table_.GetSwapchainKHRInfo(acquire_meta_info->swapchain);

            result = swapchain_->AcquireNextImage2KHR(
                func, device_info, swapchain_info, replay_acquire_info, captured_index, replay_index);

            if (captured_index >= static_cast<uint32_t>(swapchain_info->acquired_indices.size()))
            {
                swapchain_info->acquired_indices.resize(captured_index + 1);
            }

            // Track the index that was acquired on replay, which may be different than the captured index.
            swapchain_info->acquired_indices[captured_index] = { (*replay_index), true };
        }
    }
    else
    {
        // Track semphore and fence objects as shadow objects so that they can be ignored when they would have been
        // unsignaled (waited on).
        SemaphoreInfo* semaphore_info = object_info_table_.GetSemaphoreInfo(acquire_meta_info->semaphore);
        FenceInfo*     fence_info     = object_info_table_.GetFenceInfo(acquire_meta_info->fence);

        if (semaphore_info != nullptr)
        {
            semaphore_info->shadow_signaled = true;
            shadow_semaphores_.insert(semaphore_info->handle);
        }

        if (fence_info != nullptr)
        {
            fence_info->shadow_signaled = true;
            shadow_fences_.insert(fence_info->handle);
        }
    }

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideQueuePresentKHR(PFN_vkQueuePresentKHR                                 func,
                                                  VkResult                                              original_result,
                                                  const QueueInfo*                                      queue_info,
                                                  const StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    assert((queue_info != nullptr) && (pPresentInfo != nullptr) && !pPresentInfo->IsNull());

    VkResult   result             = VK_SUCCESS;
    const auto present_info       = pPresentInfo->GetPointer();
    auto       present_info_data  = pPresentInfo->GetMetaStructPointer();
    bool       dispatched_command = true;

    // Make a shallow copy of the VkPresentInfoKHR structure and change pSwapchains to reference a copy of
    // the original swapchain array with the dummy swapchains omitted.
    VkPresentInfoKHR            modified_present_info = *present_info;
    VkDeviceGroupPresentInfoKHR modified_device_group_present_info{ VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR };
    VkPresentRegionsKHR         modified_present_region_info{ VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR };
    VkPresentTimesInfoGOOGLE    modified_present_times_info{ VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE };

    std::vector<VkSwapchainKHR>       valid_swapchains;
    std::vector<uint32_t>             modified_image_indices;
    std::vector<uint32_t>             modified_device_masks;
    std::vector<VkPresentRegionKHR>   modified_regions;
    std::vector<VkPresentTimeGOOGLE>  modified_times;
    std::vector<const SemaphoreInfo*> removed_semaphores;
    std::unordered_set<uint32_t>      removed_swapchain_indices;
    std::vector<uint32_t>             capture_image_indices;
    std::vector<SwapchainKHRInfo*>    swapchain_infos;

    if ((screenshot_handler_ != nullptr) && (screenshot_handler_->IsScreenshotFrame()))
    {
        auto meta_info = pPresentInfo->GetMetaStructPointer();
        assert((meta_info != nullptr) && !meta_info->pSwapchains.IsNull());

        WriteScreenshots(meta_info);
    }

    // If rendering is restricted to a specific surface, need to check for dummy swapchains at present.
    if (options_.surface_index != -1)
    {
        const auto swapchain_ids = present_info_data->pSwapchains.GetPointer();
        for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
        {
            assert(swapchain_ids != nullptr);

            const auto swapchain_info = object_info_table_.GetSwapchainKHRInfo(swapchain_ids[i]);
            if ((swapchain_info != nullptr) && (swapchain_info->surface != VK_NULL_HANDLE))
            {
                valid_swapchains.emplace_back(swapchain_info->handle);
                swapchain_infos.emplace_back(swapchain_info);

                uint32_t capture_image_index = present_info->pImageIndices[i];
                capture_image_indices.emplace_back(capture_image_index);

                if (capture_image_index >= static_cast<uint32_t>(swapchain_info->acquired_indices.size()))
                {
                    swapchain_info->acquired_indices.resize(capture_image_index + 1);
                }

                if (!swapchain_info->acquired_indices[capture_image_index].acquired)
                {
                    GFXRECON_ASSERT(swapchain_info->device_info);

                    VkDevice device = swapchain_info->device_info->handle;
                    GFXRECON_ASSERT(device);

                    auto    device_table  = GetDeviceTable(device);
                    VkFence acquire_fence = VK_NULL_HANDLE;

                    VkFenceCreateInfo fence_create_info = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO };
                    fence_create_info.pNext             = nullptr;
                    fence_create_info.flags             = 0;
                    result = device_table->CreateFence(device, &fence_create_info, nullptr, &acquire_fence);
                    GFXRECON_ASSERT(result == VK_SUCCESS);

                    uint32_t replay_index = 0;
                    result                = swapchain_->AcquireNextImageKHR(device_table->AcquireNextImageKHR,
                                                             swapchain_info->device_info,
                                                             swapchain_info,
                                                             std::numeric_limits<uint64_t>::max(),
                                                             VK_NULL_HANDLE,
                                                             acquire_fence,
                                                             capture_image_index,
                                                             &replay_index);
                    GFXRECON_ASSERT((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR));

                    result = device_table->WaitForFences(
                        device, 1, &acquire_fence, true, std::numeric_limits<uint64_t>::max());
                    GFXRECON_ASSERT(result == VK_SUCCESS);

                    swapchain_info->acquired_indices[capture_image_index] = { replay_index, true };
                }

                uint32_t replay_image_index = swapchain_info->acquired_indices[capture_image_index].index;
                modified_image_indices.emplace_back(replay_image_index);
            }
            else
            {
                removed_swapchain_indices.insert(i);
            }
        }

        // If a swapchain was removed, pNext stucts that reference the swapchain need to be modified as well.
        if (removed_swapchain_indices.empty() == false)
        {
            const VkBaseInStructure* next = reinterpret_cast<const VkBaseInStructure*>(modified_present_info.pNext);
            while (next != nullptr)
            {
                switch (next->sType)
                {
                    case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
                    {
                        const VkDeviceGroupPresentInfoKHR* pNext =
                            reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(next);

                        if (pNext->pDeviceMasks != nullptr)
                        {
                            for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
                            {
                                if (removed_swapchain_indices.find(i) == removed_swapchain_indices.end())
                                {
                                    modified_device_masks.push_back(pNext->pDeviceMasks[i]);
                                }
                            }

                            assert(valid_swapchains.size() == modified_device_masks.size());

                            modified_device_group_present_info.pNext = pNext->pNext;
                            modified_device_group_present_info.swapchainCount =
                                static_cast<uint32_t>(modified_device_masks.size());
                            modified_device_group_present_info.pDeviceMasks = modified_device_masks.data();
                            modified_device_group_present_info.mode         = pNext->mode;
                            pNext                                           = &modified_device_group_present_info;
                        }
                        break;
                    }
                    case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
                    {
                        const VkPresentRegionsKHR* pNext = reinterpret_cast<const VkPresentRegionsKHR*>(next);

                        if (pNext->pRegions != nullptr)
                        {
                            for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
                            {
                                if (removed_swapchain_indices.find(i) == removed_swapchain_indices.end())
                                {
                                    modified_regions.push_back(pNext->pRegions[i]);
                                }
                            }

                            assert(valid_swapchains.size() == modified_regions.size());

                            modified_present_region_info.pNext = pNext->pNext;
                            modified_present_region_info.swapchainCount =
                                static_cast<uint32_t>(modified_regions.size());
                            modified_present_region_info.pRegions = modified_regions.data();
                            pNext                                 = &modified_present_region_info;
                        }
                        break;
                    }
                    case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
                    {
                        const VkPresentTimesInfoGOOGLE* pNext = reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(next);

                        if (pNext->pTimes != nullptr)
                        {
                            for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
                            {
                                if (removed_swapchain_indices.find(i) == removed_swapchain_indices.end())
                                {
                                    modified_times.push_back(pNext->pTimes[i]);
                                }
                            }

                            assert(valid_swapchains.size() == modified_times.size());

                            modified_present_times_info.pNext          = pNext->pNext;
                            modified_present_times_info.swapchainCount = static_cast<uint32_t>(modified_times.size());
                            modified_present_times_info.pTimes         = modified_times.data();
                            pNext                                      = &modified_present_times_info;
                        }
                        break;
                    }
                    default:
                        break;
                }

                next = reinterpret_cast<const VkBaseInStructure*>(next->pNext);
            }
        }

        modified_present_info.swapchainCount = static_cast<uint32_t>(valid_swapchains.size());
        modified_present_info.pSwapchains    = valid_swapchains.data();
        modified_present_info.pImageIndices  = modified_image_indices.data();
    }
    else
    {
        // Need to match the last acquired image index from replay to avoid OUT_OF_DATE errors from present.
        modified_image_indices.insert(modified_image_indices.end(),
                                      present_info->pImageIndices,
                                      std::next(present_info->pImageIndices, present_info->swapchainCount));

        capture_image_indices.insert(capture_image_indices.end(),
                                     present_info->pImageIndices,
                                     std::next(present_info->pImageIndices, present_info->swapchainCount));

        swapchain_infos.insert(swapchain_infos.end(), present_info->swapchainCount, nullptr);

        const auto swapchain_ids = present_info_data->pSwapchains.GetPointer();
        for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
        {
            assert(swapchain_ids != nullptr);

            const auto swapchain_info = object_info_table_.GetSwapchainKHRInfo(swapchain_ids[i]);
            if (swapchain_info != nullptr)
            {
                swapchain_infos[i] = swapchain_info;

                uint32_t capture_image_index = present_info->pImageIndices[i];
                capture_image_indices[i]     = capture_image_index;

                if (capture_image_index >= static_cast<uint32_t>(swapchain_info->acquired_indices.size()))
                {
                    swapchain_info->acquired_indices.resize(capture_image_index + 1);
                }

                if (!swapchain_info->acquired_indices[capture_image_index].acquired)
                {
                    GFXRECON_ASSERT(swapchain_info->device_info);

                    VkDevice device = swapchain_info->device_info->handle;
                    GFXRECON_ASSERT(device);

                    auto device_table = GetDeviceTable(device);
                    GFXRECON_ASSERT(device_table);

                    VkFence acquire_fence = VK_NULL_HANDLE;

                    VkFenceCreateInfo fence_create_info = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO };
                    fence_create_info.pNext             = nullptr;
                    fence_create_info.flags             = 0;
                    result = device_table->CreateFence(device, &fence_create_info, nullptr, &acquire_fence);
                    GFXRECON_ASSERT(result == VK_SUCCESS);

                    uint32_t replay_index = 0;
                    result                = swapchain_->AcquireNextImageKHR(device_table->AcquireNextImageKHR,
                                                             swapchain_info->device_info,
                                                             swapchain_info,
                                                             std::numeric_limits<uint64_t>::max(),
                                                             VK_NULL_HANDLE,
                                                             acquire_fence,
                                                             capture_image_index,
                                                             &replay_index);
                    GFXRECON_ASSERT((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR));

                    result = device_table->WaitForFences(
                        device, 1, &acquire_fence, true, std::numeric_limits<uint64_t>::max());
                    GFXRECON_ASSERT(result == VK_SUCCESS);

                    swapchain_info->acquired_indices[capture_image_index] = { replay_index, true };
                }
                uint32_t replay_image_index = swapchain_info->acquired_indices[capture_image_index].index;
                modified_image_indices[i]   = replay_image_index;
            }
        }

        modified_present_info.pImageIndices = modified_image_indices.data();
    }

    // Only attempt to find imported or shadow semaphores if we know at least one around.
    if ((!have_imported_semaphores_) && (shadow_semaphores_.empty()) && (modified_present_info.swapchainCount != 0))
    {
        result = swapchain_->QueuePresentKHR(
            func, capture_image_indices, swapchain_infos, queue_info, &modified_present_info);
    }
    else if (modified_present_info.swapchainCount == 0)
    {
        // No need to progress farther if there is no valid swapchain to present.
        dispatched_command = false;

        // Used to mark shadow semaphores as signaled in case acquireNextImage signals were supposed to be waited on
        // here.
        GetShadowSemaphores(present_info_data->pWaitSemaphores, &removed_semaphores);
    }
    else
    {
        // Check for imported semaphores in the present info, creating a vector of imported semaphore info structures.
        if (present_info_data != nullptr)
        {
            GetImportedSemaphores(present_info_data->pWaitSemaphores, &removed_semaphores);
            GetShadowSemaphores(present_info_data->pWaitSemaphores, &removed_semaphores);
        }

        if (removed_semaphores.empty())
        {
            result = swapchain_->QueuePresentKHR(
                func, capture_image_indices, swapchain_infos, queue_info, &modified_present_info);
        }
        else
        {
            std::vector<VkSemaphore> semaphore_memory;
            auto                     semaphore_iter = removed_semaphores.begin();

            for (uint32_t i = 0; i < modified_present_info.waitSemaphoreCount; ++i)
            {
                VkSemaphore semaphore = modified_present_info.pWaitSemaphores[i];

                if ((semaphore_iter == removed_semaphores.end()) || ((*semaphore_iter)->handle != semaphore))
                {
                    semaphore_memory.push_back(semaphore);
                }
                else
                {
                    // Omit the imported semaphore from the current submission.
                    ++semaphore_iter;
                }
            }

            modified_present_info.waitSemaphoreCount = static_cast<uint32_t>(semaphore_memory.size());
            modified_present_info.pWaitSemaphores    = semaphore_memory.data();

            result = swapchain_->QueuePresentKHR(
                func, capture_image_indices, swapchain_infos, queue_info, &modified_present_info);
        }
    }

    // If running with surface-index on, need to track forward progress of semaphore that have been submitted
    if (options_.surface_index != -1)
    {
        if (dispatched_command)
        {
            TrackSemaphoreForwardProgress(present_info_data->pWaitSemaphores, &removed_semaphores);
        }
        else
        {
            // Need to mark all wait semaphores as not in forward progress.
            const format::HandleId* semaphore_ids = present_info_data->pWaitSemaphores.GetPointer();
            if (semaphore_ids != nullptr)
            {
                size_t count = present_info_data->pWaitSemaphores.GetLength();
                for (uint32_t i = 0; i < count; ++i)
                {
                    SemaphoreInfo* semaphore_info = object_info_table_.GetSemaphoreInfo(semaphore_ids[i]);
                    if (semaphore_info)
                    {
                        semaphore_info->forward_progress = false;
                    }
                }
            }
        }
    }

    if (screenshot_handler_ != nullptr)
    {
        screenshot_handler_->EndFrame();
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideImportSemaphoreFdKHR(
    PFN_vkImportSemaphoreFdKHR                                      func,
    VkResult                                                        original_result,
    const DeviceInfo*                                               device_info,
    const StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    // Skip external semaphore import.  There is no actual file descriptor backing it in replay.
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(device_info);

    assert(pImportSemaphoreFdInfo != nullptr);

    // Track and remove imported sempahore from future wait operations as it will never be signaled.
    if (original_result == VK_SUCCESS)
    {
        auto info = pImportSemaphoreFdInfo->GetMetaStructPointer();
        assert(info != nullptr);

        SemaphoreInfo* semaphore_info = object_info_table_.GetSemaphoreInfo(info->semaphore);

        if (semaphore_info != nullptr)
        {
            have_imported_semaphores_   = true;
            semaphore_info->is_external = true;
        }
    }

    return original_result;
}

VkResult VulkanReplayConsumerBase::OverrideGetSemaphoreFdKHR(
    PFN_vkGetSemaphoreFdKHR                                      func,
    VkResult                                                     original_result,
    const DeviceInfo*                                            device_info,
    const StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    const PointerDecoder<int>*                                   pFd)
{
    // Skip external semaphore file descriptor acquire so that replay is not responsible for closing the file
    // descriptor.
    // From spec:
    //      To avoid leaking resources, the application must release ownership
    //      of the file descriptor when it is no longer needed.
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(device_info);
    GFXRECON_UNREFERENCED_PARAMETER(pGetFdInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pFd);
    return original_result;
}

VkResult VulkanReplayConsumerBase::OverrideImportSemaphoreWin32HandleKHR(
    PFN_vkImportSemaphoreWin32HandleKHR                                      func,
    VkResult                                                                 original_result,
    const DeviceInfo*                                                        device_info,
    const StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    // Skip external semaphore import.  There is no actual OS resource backing it in replay.
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(device_info);

    assert(pImportSemaphoreWin32HandleInfo != nullptr);

    // Track and remove imported sempahore from future wait operations as it will never be signaled.
    if (original_result == VK_SUCCESS)
    {
        auto info = pImportSemaphoreWin32HandleInfo->GetMetaStructPointer();
        assert(info != nullptr);

        SemaphoreInfo* semaphore_info = object_info_table_.GetSemaphoreInfo(info->semaphore);

        if (semaphore_info != nullptr)
        {
            have_imported_semaphores_   = true;
            semaphore_info->is_external = true;
        }
    }

    return original_result;
}

VkResult VulkanReplayConsumerBase::OverrideGetSemaphoreWin32HandleKHR(
    PFN_vkGetSemaphoreWin32HandleKHR                                      func,
    VkResult                                                              original_result,
    const DeviceInfo*                                                     device_info,
    const StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    const PointerDecoder<uint64_t, void*>*                                pHandle)
{
    // Skip external semaphore handle acquire so that replay is not responsible for closing the handle.
    // From spec:
    //      To avoid leaking resources, the application must release ownership
    //      of them using the CloseHandle system call when they are no longer needed.
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(device_info);
    GFXRECON_UNREFERENCED_PARAMETER(pGetWin32HandleInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pHandle);
    return original_result;
}

VkResult VulkanReplayConsumerBase::OverrideGetRandROutputDisplayEXT(PFN_vkGetRandROutputDisplayEXT      func,
                                                                    VkResult                            original_result,
                                                                    const PhysicalDeviceInfo*           physicalDevice,
                                                                    Display*                            dpy,
                                                                    RROutput                            rrOutput,
                                                                    HandlePointerDecoder<VkDisplayKHR>* pDisplay)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(physicalDevice);
    GFXRECON_UNREFERENCED_PARAMETER(dpy);
    GFXRECON_UNREFERENCED_PARAMETER(rrOutput);
    GFXRECON_UNREFERENCED_PARAMETER(pDisplay);
    return original_result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateAndroidSurfaceKHR(
    PFN_vkCreateAndroidSurfaceKHR                                      func,
    VkResult                                                           original_result,
    InstanceInfo*                                                      instance_info,
    const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info, "VK_KHR_android_surface", replay_create_info->flags, pSurface);
}

VkResult VulkanReplayConsumerBase::OverrideCreateWin32SurfaceKHR(
    PFN_vkCreateWin32SurfaceKHR                                      func,
    VkResult                                                         original_result,
    InstanceInfo*                                                    instance_info,
    const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                              pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info, "VK_KHR_win32_surface", replay_create_info->flags, pSurface);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceWin32PresentationSupportKHR(
    PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR func,
    const PhysicalDeviceInfo*                          physical_device_info,
    uint32_t                                           queueFamilyIndex)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    auto wsi_context    = application_ ? application_->GetWsiContext("VK_KHR_win32_surface") : nullptr;
    auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
    return window_factory ? window_factory->GetPhysicalDevicePresentationSupport(
                                GetInstanceTable(physical_device), physical_device, queueFamilyIndex)
                          : false;
}

VkResult VulkanReplayConsumerBase::OverrideCreateXcbSurfaceKHR(
    PFN_vkCreateXcbSurfaceKHR                                      func,
    VkResult                                                       original_result,
    InstanceInfo*                                                  instance_info,
    const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                            pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info, "VK_KHR_xcb_surface", replay_create_info->flags, pSurface);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceXcbPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR func,
    const PhysicalDeviceInfo*                        physical_device_info,
    uint32_t                                         queueFamilyIndex,
    xcb_connection_t*                                connection,
    xcb_visualid_t                                   visual_id)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(connection);
    GFXRECON_UNREFERENCED_PARAMETER(visual_id);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    auto wsi_context    = application_ ? application_->GetWsiContext("VK_KHR_xcb_surface") : nullptr;
    auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
    return window_factory ? window_factory->GetPhysicalDevicePresentationSupport(
                                GetInstanceTable(physical_device), physical_device, queueFamilyIndex)
                          : false;
}

VkResult VulkanReplayConsumerBase::OverrideCreateXlibSurfaceKHR(
    PFN_vkCreateXlibSurfaceKHR                                      func,
    VkResult                                                        original_result,
    InstanceInfo*                                                   instance_info,
    const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                             pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info, "VK_KHR_xlib_surface", replay_create_info->flags, pSurface);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceXlibPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR func,
    const PhysicalDeviceInfo*                         physical_device_info,
    uint32_t                                          queueFamilyIndex,
    Display*                                          dpy,
    VisualID                                          visualID)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(dpy);
    GFXRECON_UNREFERENCED_PARAMETER(visualID);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    auto wsi_context    = application_ ? application_->GetWsiContext("VK_KHR_xlib_surface") : nullptr;
    auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
    return window_factory ? window_factory->GetPhysicalDevicePresentationSupport(
                                GetInstanceTable(physical_device), physical_device, queueFamilyIndex)
                          : false;
}

VkResult VulkanReplayConsumerBase::OverrideCreateWaylandSurfaceKHR(
    PFN_vkCreateWaylandSurfaceKHR                                      func,
    VkResult                                                           original_result,
    InstanceInfo*                                                      instance_info,
    const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert((instance_info != nullptr) && (pCreateInfo != nullptr));

    auto replay_create_info = pCreateInfo->GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info, "VK_KHR_wayland_surface", replay_create_info->flags, pSurface);
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR func,
    const PhysicalDeviceInfo*                            physical_device_info,
    uint32_t                                             queueFamilyIndex,
    struct wl_display*                                   display)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(display);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    auto wsi_context    = application_ ? application_->GetWsiContext("VK_KHR_wayland_surface") : nullptr;
    auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
    return window_factory ? window_factory->GetPhysicalDevicePresentationSupport(
                                GetInstanceTable(physical_device), physical_device, queueFamilyIndex)
                          : false;
}

void VulkanReplayConsumerBase::OverrideDestroySurfaceKHR(
    PFN_vkDestroySurfaceKHR                                    func,
    InstanceInfo*                                              instance_info,
    const SurfaceKHRInfo*                                      surface_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    assert(instance_info != nullptr);

    VkInstance   instance = instance_info->handle;
    VkSurfaceKHR surface  = VK_NULL_HANDLE;
    Window*      window   = nullptr;

    if (surface_info != nullptr)
    {
        surface = surface_info->handle;
        window  = surface_info->window;
    }

    if (window != nullptr)
    {
        window->DestroySurface(GetInstanceTable(instance), instance, surface);
        active_windows_.erase(window);
        auto wsi_context    = application_ ? application_->GetWsiContext(window->GetWsiExtension()) : nullptr;
        auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
        if (window_factory)
        {
            window_factory->Destroy(window);
        }
    }
    else
    {
        func(instance, surface, GetAllocationCallbacks(pAllocator));
    }
}

VkResult VulkanReplayConsumerBase::OverrideCreateAccelerationStructureKHR(
    PFN_vkCreateAccelerationStructureKHR                                      func,
    VkResult                                                                  original_result,
    const DeviceInfo*                                                         device_info,
    const StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>*                         pAccelerationStructureKHR)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfo != nullptr) && (pAccelerationStructureKHR != nullptr) &&
           !pAccelerationStructureKHR->IsNull() && (pAccelerationStructureKHR->GetHandlePointer() != nullptr));

    VkResult result              = VK_SUCCESS;
    auto     replay_accel_struct = pAccelerationStructureKHR->GetHandlePointer();
    auto     capture_id          = (*pAccelerationStructureKHR->GetPointer());
    auto     replay_create_info  = pCreateInfo->GetPointer();
    VkDevice device              = device_info->handle;
    auto     device_table        = GetDeviceTable(device);
    assert(device_table != nullptr);

    if (device_info->property_feature_info.feature_accelerationStructureCaptureReplay)
    {
        // Set opaque device address
        VkAccelerationStructureCreateInfoKHR modified_create_info = (*replay_create_info);
        modified_create_info.createFlags |= VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR;
        auto entry = device_info->opaque_addresses.find(capture_id);
        if (entry != device_info->opaque_addresses.end())
        {
            modified_create_info.deviceAddress = entry->second;
        }
        else
        {
            GFXRECON_LOG_DEBUG(
                "Opaque device address is not available for VkAccelerationStructureKHR object (ID = %" PRIu64 ")",
                capture_id);
        }

        result = device_table->CreateAccelerationStructureKHR(
            device, &modified_create_info, GetAllocationCallbacks(pAllocator), replay_accel_struct);
    }
    else
    {
        result = device_table->CreateAccelerationStructureKHR(
            device, replay_create_info, GetAllocationCallbacks(pAllocator), replay_accel_struct);
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateRayTracingPipelinesKHR(
    PFN_vkCreateRayTracingPipelinesKHR                                     func,
    VkResult                                                               original_result,
    const DeviceInfo*                                                      device_info,
    DeferredOperationKHRInfo*                                              deferred_operation_info,
    const PipelineCacheInfo*                                               pipeline_cache_info,
    uint32_t                                                               createInfoCount,
    const StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>*             pAllocator,
    HandlePointerDecoder<VkPipeline>*                                      pPipelines)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pCreateInfos != nullptr) && (pAllocator != nullptr) &&
           (pPipelines != nullptr) && !pPipelines->IsNull() && (pPipelines->GetHandlePointer() != nullptr));

    VkResult                                 result          = VK_SUCCESS;
    VkDevice                                 device          = device_info->handle;
    auto                                     device_table    = GetDeviceTable(device);
    const VkRayTracingPipelineCreateInfoKHR* in_pCreateInfos = pCreateInfos->GetPointer();
    const VkAllocationCallbacks*             in_pAllocator   = GetAllocationCallbacks(pAllocator);
    VkPipeline*                              out_pPipelines  = pPipelines->GetHandlePointer();
    VkDeferredOperationKHR                   in_deferredOperation =
        (deferred_operation_info != nullptr) ? deferred_operation_info->handle : VK_NULL_HANDLE;
    VkPipelineCache in_pipelineCache = (pipeline_cache_info != nullptr) ? pipeline_cache_info->handle : VK_NULL_HANDLE;

    if (deferred_operation_info)
    {
        deferred_operation_info->join_state = VK_NOT_READY;
        deferred_operation_info->record_modified_create_infos.clear();
        deferred_operation_info->record_modified_pgroups.clear();
    }

    if (device_info->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
    {
        // Modify pipeline create infos with capture replay flag and data.
        std::vector<VkRayTracingPipelineCreateInfoKHR>                 modified_create_infos;
        std::vector<std::vector<VkRayTracingShaderGroupCreateInfoKHR>> modified_pgroups;
        modified_create_infos.reserve(createInfoCount);
        modified_pgroups.resize(createInfoCount);
        for (uint32_t create_info_i = 0; create_info_i < createInfoCount; ++create_info_i)
        {
            format::HandleId pipeline_capture_id = (*pPipelines[create_info_i].GetPointer());

            // Enable capture replay flag.
            modified_create_infos.push_back(in_pCreateInfos[create_info_i]);
            modified_create_infos[create_info_i].flags |=
                VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR;

            uint32_t group_info_count = in_pCreateInfos[create_info_i].groupCount;
            bool     has_data         = (device_info->shader_group_handles.find(pipeline_capture_id) !=
                             device_info->shader_group_handles.end());

            if (has_data)
            {
                assert(device_info->shader_group_handles.at(pipeline_capture_id).size() ==
                       (device_info->property_feature_info.property_shaderGroupHandleCaptureReplaySize *
                        group_info_count));
            }
            else
            {
                GFXRECON_LOG_WARNING("Missing shader group handle data in for ray tracing pipeline (ID = %" PRIu64 ").",
                                     pipeline_capture_id);
            }

            // Set pShaderGroupCaptureReplayHandle in shader group create infos.
            std::vector<VkRayTracingShaderGroupCreateInfoKHR>& modified_group_infos = modified_pgroups[create_info_i];
            modified_group_infos.reserve(group_info_count);

            for (uint32_t group_info_i = 0; group_info_i < group_info_count; ++group_info_i)
            {
                modified_group_infos.push_back(in_pCreateInfos[create_info_i].pGroups[group_info_i]);

                if (has_data)
                {
                    uint32_t byte_offset =
                        device_info->property_feature_info.property_shaderGroupHandleCaptureReplaySize * group_info_i;
                    modified_group_infos[group_info_i].pShaderGroupCaptureReplayHandle =
                        device_info->shader_group_handles.at(pipeline_capture_id).data() + byte_offset;
                }
                else
                {
                    modified_group_infos[group_info_i].pShaderGroupCaptureReplayHandle = nullptr;
                }
            }

            // Use modified shader group infos.
            modified_create_infos[create_info_i].pGroups = modified_group_infos.data();
        }
        result = device_table->CreateRayTracingPipelinesKHR(device,
                                                            in_deferredOperation,
                                                            in_pipelineCache,
                                                            createInfoCount,
                                                            modified_create_infos.data(),
                                                            in_pAllocator,
                                                            out_pPipelines);
        if (deferred_operation_info)
        {
            deferred_operation_info->record_modified_create_infos = std::move(modified_create_infos);
            deferred_operation_info->record_modified_pgroups      = std::move(modified_pgroups);
        }
    }
    else
    {
        GFXRECON_LOG_ERROR_ONCE("The replay used vkCreateRayTracingPipelinesKHR, which may require the "
                                "rayTracingPipelineShaderGroupHandleCaptureReplay feature for accurate capture and "
                                "replay. The replay device does not support this feature, so replay may fail.");

        result = device_table->CreateRayTracingPipelinesKHR(device,
                                                            in_deferredOperation,
                                                            in_pipelineCache,
                                                            createInfoCount,
                                                            in_pCreateInfos,
                                                            in_pAllocator,
                                                            out_pPipelines);
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideDeferredOperationJoinKHR(PFN_vkDeferredOperationJoinKHR func,
                                                                    VkResult                       original_result,
                                                                    const DeviceInfo*              device_info,
                                                                    DeferredOperationKHRInfo* deferred_operation_info)
{
    if (deferred_operation_info->join_state == VK_SUCCESS)
    {
        return VK_SUCCESS;
    }

    VkDevice               device             = device_info->handle;
    VkDeferredOperationKHR deferred_operation = deferred_operation_info->handle;

    PFN_vkGetDeferredOperationMaxConcurrencyKHR vkGetDeferredOperationMaxConcurrencyKHR =
        GetDeviceTable(device)->GetDeferredOperationMaxConcurrencyKHR;

    uint32_t max_threads  = std::thread::hardware_concurrency();
    uint32_t thread_count = std::min(vkGetDeferredOperationMaxConcurrencyKHR(device, deferred_operation), max_threads);
    bool     deferred_operation_completed = false;
    std::vector<std::future<void>> deferred_operation_joins;

    for (uint32_t i = 0; i < thread_count; i++)
    {
        // At least one vkDeferredOperationJoinKHR in a thread has to get VK_SUCCESS.
        deferred_operation_joins.emplace_back(
            std::async(std::launch::async, [func, device, deferred_operation, &deferred_operation_completed]() {
                VkResult result = VK_ERROR_UNKNOWN;
                while (result != VK_SUCCESS && !deferred_operation_completed)
                {
                    result = func(device, deferred_operation);
                    assert(result == VK_SUCCESS || result == VK_THREAD_DONE_KHR || result == VK_THREAD_IDLE_KHR);
                    if (result == VK_SUCCESS)
                    {
                        deferred_operation_completed = true;
                    }
                }
            }));
    }

    for (auto& j : deferred_operation_joins)
    {
        j.get();
    }

    deferred_operation_info->join_state = VK_SUCCESS;
    deferred_operation_info->record_modified_create_infos.clear();
    deferred_operation_info->record_modified_pgroups.clear();
    return VK_SUCCESS;
}

VkDeviceAddress VulkanReplayConsumerBase::OverrideGetBufferDeviceAddress(
    PFN_vkGetBufferDeviceAddress                                   func,
    const DeviceInfo*                                              device_info,
    const StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    assert((device_info != nullptr) && (pInfo != nullptr) && !pInfo->IsNull() && (pInfo->GetPointer() != nullptr));

    if (!device_info->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        GFXRECON_LOG_ERROR_ONCE("The captured application used vkGetBufferDeviceAddress, which requires the "
                                "bufferDeviceAddressCaptureReplay feature for accurate capture and replay. The "
                                "replay device does not support this feature, so replay may fail.");
    }

    if (!device_info->allocator->SupportsOpaqueDeviceAddresses())
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The captured application used vkGetBufferDeviceAddress. The specified replay option '-m rebind' may not "
            "support the replay of captured device addresses, so replay may fail.");
    }

    VkDevice                         device       = device_info->handle;
    const VkBufferDeviceAddressInfo* address_info = pInfo->GetPointer();

    return func(device, address_info);
}

void VulkanReplayConsumerBase::OverrideGetAccelerationStructureDeviceAddressKHR(
    PFN_vkGetAccelerationStructureDeviceAddressKHR                                   func,
    const DeviceInfo*                                                                device_info,
    const StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    assert((device_info != nullptr) && (pInfo != nullptr) && !pInfo->IsNull() && (pInfo->GetPointer() != nullptr));

    if (!device_info->property_feature_info.feature_accelerationStructureCaptureReplay)
    {
        GFXRECON_LOG_WARNING_ONCE("The captured application used vkGetAccelerationStructureDeviceAddressKHR, which may "
                                  "require the accelerationStructureCaptureReplay feature for accurate capture and "
                                  "replay. The replay device does not support this feature, so replay may fail.");
    }

    if (!device_info->allocator->SupportsOpaqueDeviceAddresses())
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The captured application used vkGetAccelerationStructureDeviceAddressKHR. The specified replay option '-m "
            "rebind' may not support the replay of captured device addresses, so replay may fail.");
    }

    VkDevice                                           device       = device_info->handle;
    const VkAccelerationStructureDeviceAddressInfoKHR* address_info = pInfo->GetPointer();

    func(device, address_info);
}

VkResult
VulkanReplayConsumerBase::OverrideGetRayTracingShaderGroupHandlesKHR(PFN_vkGetRayTracingShaderGroupHandlesKHR func,
                                                                     VkResult                 original_result,
                                                                     const DeviceInfo*        device_info,
                                                                     const PipelineInfo*      pipeline_info,
                                                                     uint32_t                 firstGroup,
                                                                     uint32_t                 groupCount,
                                                                     size_t                   dataSize,
                                                                     PointerDecoder<uint8_t>* pData)
{
    assert((device_info != nullptr) && (pipeline_info != nullptr) && (pData != nullptr) &&
           (pData->GetOutputPointer() != nullptr));

    if (!device_info->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The captured application used vkGetRayTracingShaderGroupHandlesKHR, which may require the "
            "rayTracingPipelineShaderGroupHandleCaptureReplay feature for accurate capture and replay. The replay "
            "device does not support this feature, so replay may fail.");
    }

    VkDevice   device      = device_info->handle;
    VkPipeline pipeline    = pipeline_info->handle;
    uint8_t*   output_data = pData->GetOutputPointer();

    return func(device, pipeline, firstGroup, groupCount, dataSize, output_data);
}

VkResult VulkanReplayConsumerBase::OverrideGetAndroidHardwareBufferPropertiesANDROID(
    PFN_vkGetAndroidHardwareBufferPropertiesANDROID                         func,
    VkResult                                                                original_result,
    const DeviceInfo*                                                       device_info,
    const struct AHardwareBuffer*                                           hardware_buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    assert((device_info != nullptr) && (pProperties != nullptr) && (pProperties->GetOutputPointer() != nullptr));

    if ((hardware_buffer == nullptr) && options_.omit_null_hardware_buffers)
    {

        GFXRECON_LOG_INFO_ONCE("A call to vkGetAndroidHardwareBufferPropertiesANDROID with a NULL "
                               "AHardwareBuffer* was omitted during replay.");
        return original_result;
    }
    else
    {

        if (hardware_buffer == nullptr)
        {
            GFXRECON_LOG_WARNING_ONCE("The captured application used vkGetAndroidHardwareBufferPropertiesANDROID but "
                                      "replay has no way of mapping the captured AHardwareBuffer*; replay may fail. "
                                      "If replay of this call appears to fail, try the replay option "
                                      "\"--omit-null-hardware-buffers\".");
        }

        VkDevice device            = device_info->handle;
        auto*    output_properties = pProperties->GetOutputPointer();

        return func(device, hardware_buffer, output_properties);
    }
}

void VulkanReplayConsumerBase::MapDescriptorUpdateTemplateHandles(
    const DescriptorUpdateTemplateInfo* update_template_info, DescriptorUpdateTemplateDecoder* decoder)
{
    assert(decoder != nullptr);

    size_t image_info_count        = decoder->GetImageInfoCount();
    size_t buffer_info_count       = decoder->GetBufferInfoCount();
    size_t texel_buffer_view_count = decoder->GetTexelBufferViewCount();
    size_t accel_struct_count      = decoder->GetAccelerationStructureKHRCount();

    if (image_info_count > 0)
    {
        if (update_template_info != nullptr)
        {
            assert(update_template_info->descriptor_image_types.size() >= image_info_count);

            Decoded_VkDescriptorImageInfo* structs = decoder->GetImageInfoMetaStructPointer();
            for (size_t i = 0; i < image_info_count; ++i)
            {
                MapStructHandles(update_template_info->descriptor_image_types[i], &structs[i], object_info_table_);
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Missing descriptor update template image descriptor type info; attempting to map both "
                               "VkDescriptorImageInfo handles");

            Decoded_VkDescriptorImageInfo* structs = decoder->GetImageInfoMetaStructPointer();
            for (size_t i = 0; i < image_info_count; ++i)
            {
                MapStructHandles(VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, &structs[i], object_info_table_);
            }
        }
    }

    if (buffer_info_count > 0)
    {
        MapStructArrayHandles(decoder->GetBufferInfoMetaStructPointer(), buffer_info_count, object_info_table_);
    }

    if (texel_buffer_view_count > 0)
    {
        auto texel_buffer_view_ids     = decoder->GetTexelBufferViewHandleIdsPointer();
        auto texel_buffer_view_handles = decoder->GetTexelBufferViewPointer();

        for (size_t i = 0; i < texel_buffer_view_count; ++i)
        {
            auto texel_buffer_view_info = object_info_table_.GetBufferViewInfo(texel_buffer_view_ids[i]);

            if (texel_buffer_view_info != nullptr)
            {
                texel_buffer_view_handles[i] = texel_buffer_view_info->handle;
            }
            else
            {
                texel_buffer_view_handles[i] = VK_NULL_HANDLE;
            }
        }
    }

    if (accel_struct_count > 0)
    {
        auto accel_struct_ids     = decoder->GetAccelerationStructureKHRHandleIdsPointer();
        auto accel_struct_handles = decoder->GetAccelerationStructureKHRPointer();

        for (size_t i = 0; i < accel_struct_count; ++i)
        {
            auto accel_struct_info = object_info_table_.GetAccelerationStructureKHRInfo(accel_struct_ids[i]);

            if (accel_struct_info != nullptr)
            {
                accel_struct_handles[i] = accel_struct_info->handle;
            }
            else
            {
                accel_struct_handles[i] = VK_NULL_HANDLE;
            }
        }
    }
}

void VulkanReplayConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo& call_info,
                                                                         format::HandleId   device,
                                                                         format::HandleId   descriptorSet,
                                                                         format::HandleId   descriptorUpdateTemplate,
                                                                         DescriptorUpdateTemplateDecoder* pData)
{
    assert(pData != nullptr);

    VkDevice        in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDescriptorSet in_descriptorSet =
        MapHandle<DescriptorSetInfo>(descriptorSet, &VulkanObjectInfoTable::GetDescriptorSetInfo);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = VK_NULL_HANDLE;
    auto update_template_info = object_info_table_.GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

    MapDescriptorUpdateTemplateHandles(update_template_info, pData);

    if (update_template_info != nullptr)
    {
        in_descriptorUpdateTemplate = update_template_info->handle;
    }

    GetDeviceTable(in_device)->UpdateDescriptorSetWithTemplate(
        in_device, in_descriptorSet, in_descriptorUpdateTemplate, pData->GetPointer());
}

void VulkanReplayConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                                             format::HandleId   commandBuffer,
                                                                             format::HandleId descriptorUpdateTemplate,
                                                                             format::HandleId layout,
                                                                             uint32_t         set,
                                                                             DescriptorUpdateTemplateDecoder* pData)
{
    assert(pData != nullptr);

    VkCommandBuffer in_commandBuffer =
        MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = VK_NULL_HANDLE;
    VkPipelineLayout in_layout = MapHandle<PipelineLayoutInfo>(layout, &VulkanObjectInfoTable::GetPipelineLayoutInfo);
    auto update_template_info  = object_info_table_.GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

    MapDescriptorUpdateTemplateHandles(update_template_info, pData);

    if (update_template_info != nullptr)
    {
        in_descriptorUpdateTemplate = update_template_info->handle;
    }

    GetDeviceTable(in_commandBuffer)
        ->CmdPushDescriptorSetWithTemplateKHR(
            in_commandBuffer, in_descriptorUpdateTemplate, in_layout, set, pData->GetPointer());
}

void VulkanReplayConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                                            format::HandleId   device,
                                                                            format::HandleId   descriptorSet,
                                                                            format::HandleId   descriptorUpdateTemplate,
                                                                            DescriptorUpdateTemplateDecoder* pData)
{
    assert(pData != nullptr);

    VkDevice        in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDescriptorSet in_descriptorSet =
        MapHandle<DescriptorSetInfo>(descriptorSet, &VulkanObjectInfoTable::GetDescriptorSetInfo);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = VK_NULL_HANDLE;
    auto update_template_info = object_info_table_.GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

    MapDescriptorUpdateTemplateHandles(update_template_info, pData);

    if (update_template_info != nullptr)
    {
        in_descriptorUpdateTemplate = update_template_info->handle;
    }

    GetDeviceTable(in_device)->UpdateDescriptorSetWithTemplateKHR(
        in_device, in_descriptorSet, in_descriptorUpdateTemplate, pData->GetPointer());
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
