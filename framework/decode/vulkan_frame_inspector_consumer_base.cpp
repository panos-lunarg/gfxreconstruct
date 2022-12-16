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

#include "decode/vulkan_frame_inspector_consumer_base.h"
#include "graphics/vulkan_util.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "decode/vulkan_enum_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanFrameInspectorConsumerBase::VulkanFrameInspectorConsumerBase(
    std::shared_ptr<application::Application> application, const VulkanReplayOptions& options) :
    loader_handle_(nullptr),
    get_instance_proc_addr_(nullptr), create_instance_proc_(nullptr), fatal_error_handler_(nullptr)
{}

void VulkanFrameInspectorConsumerBase::InitializeLoader()
{
    loader_handle_ = graphics::InitializeLoader();
    if (loader_handle_ != nullptr)
    {
        get_instance_proc_addr_ = reinterpret_cast<PFN_vkGetInstanceProcAddr>(
            util::platform::GetProcAddress(loader_handle_, "vkGetInstanceProcAddr"));
    }

    if (get_instance_proc_addr_ != nullptr)
    {
        create_instance_proc_ =
            reinterpret_cast<PFN_vkCreateInstance>(get_instance_proc_addr_(nullptr, "vkCreateInstance"));
    }

    if (create_instance_proc_ == nullptr)
    {
        GFXRECON_LOG_FATAL("Failed to load Vulkan runtime library; please ensure that the path to the Vulkan "
                           "loader (eg. %s) has been added to the appropriate system path",
                           graphics::kLoaderLibNames[0].c_str());
        RaiseFatalError("Failed to load Vulkan runtime library");
    }
}

void VulkanFrameInspectorConsumerBase::AddInstanceTable(VkInstance instance)
{
    encode::DispatchKey dispatch_key = encode::GetDispatchKey(instance);

    get_device_proc_addrs_[dispatch_key] =
        reinterpret_cast<PFN_vkGetDeviceProcAddr>(get_instance_proc_addr_(instance, "vkGetDeviceProcAddr"));
    create_device_procs_[dispatch_key] =
        reinterpret_cast<PFN_vkCreateDevice>(get_instance_proc_addr_(instance, "vkCreateDevice"));

    encode::InstanceTable& table = instance_tables_[dispatch_key];
    encode::LoadInstanceTable(get_instance_proc_addr_, instance, &table);
}

void VulkanFrameInspectorConsumerBase::AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa)
{
    encode::DeviceTable& table = device_tables_[encode::GetDispatchKey(device)];
    encode::LoadDeviceTable(gpa, device, &table);
}

const encode::DeviceTable* VulkanFrameInspectorConsumerBase::GetDeviceTable(const void* handle) const
{
    auto table = device_tables_.find(encode::GetDispatchKey(handle));
    assert(table != device_tables_.end());
    return (table != device_tables_.end()) ? &table->second : nullptr;
}

void VulkanFrameInspectorConsumerBase::CheckResult(const char* func_name, VkResult original, VkResult replay)
{
    if (original != replay)
    {
        if ((replay < 0) && (replay != VK_ERROR_FORMAT_NOT_SUPPORTED))
        {
            // Raise a fatal error if replay produced an error that did not occur during capture.  Format not supported
            // errors are not treated as fatal, but will be reported as warnings below, allowing the replay to attempt
            // to continue for the case where an application may have queried for formats that it did not use.
            GFXRECON_LOG_FATAL("API call %s returned error value %s that does not match the result from the "
                               "capture file: %s.  Replay cannot continue.",
                               func_name,
                               util::ToString<VkResult>(replay).c_str(),
                               util::ToString<VkResult>(original).c_str());

            RaiseFatalError(enumutil::GetResultDescription(replay));
        }
        else if (!((replay == VK_SUCCESS) &&
                   ((original == VK_TIMEOUT) || (original == VK_NOT_READY) || (original == VK_ERROR_OUT_OF_DATE_KHR))))
        {
            // Report differences between replay result and capture result, unless the replay results indicates
            // that a wait operation completed before the original or a WSI function succeeded when the original failed.
            GFXRECON_LOG_WARNING(
                "API call %s returned value %s that does not match return value from capture file: %s.",
                func_name,
                util::ToString<VkResult>(replay).c_str(),
                util::ToString<VkResult>(original).c_str());
        }
    }
}

VulkanFrameInspectorConsumerBase::~VulkanFrameInspectorConsumerBase() {}

void VulkanFrameInspectorConsumerBase::WaitDevicesIdle() {}

void VulkanFrameInspectorConsumerBase::ProcessStateBeginMarker(uint64_t frame_number) {}

void VulkanFrameInspectorConsumerBase::ProcessStateEndMarker(uint64_t frame_number) {}

void VulkanFrameInspectorConsumerBase::ProcessDisplayMessageCommand(const std::string& message) {}

void VulkanFrameInspectorConsumerBase::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                                uint64_t       offset,
                                                                uint64_t       size,
                                                                const uint8_t* data)
{}

void VulkanFrameInspectorConsumerBase::ProcessResizeWindowCommand(format::HandleId surface_id,
                                                                  uint32_t         width,
                                                                  uint32_t         height)
{}

void VulkanFrameInspectorConsumerBase::ProcessResizeWindowCommand2(format::HandleId surface_id,
                                                                   uint32_t         width,
                                                                   uint32_t         height,
                                                                   uint32_t         pre_transform)
{}

void VulkanFrameInspectorConsumerBase::ProcessCreateHardwareBufferCommand(
    format::HandleId                                    memory_id,
    uint64_t                                            buffer_id,
    uint32_t                                            format,
    uint32_t                                            width,
    uint32_t                                            height,
    uint32_t                                            stride,
    uint64_t                                            usage,
    uint32_t                                            layers,
    const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{}

void VulkanFrameInspectorConsumerBase::ProcessDestroyHardwareBufferCommand(uint64_t buffer_id) {}

void VulkanFrameInspectorConsumerBase::ProcessSetDevicePropertiesCommand(
    format::HandleId   physical_device_id,
    uint32_t           api_version,
    uint32_t           driver_version,
    uint32_t           vendor_id,
    uint32_t           device_id,
    uint32_t           device_type,
    const uint8_t      pipeline_cache_uuid[format::kUuidSize],
    const std::string& device_name)
{}

void VulkanFrameInspectorConsumerBase::ProcessSetDeviceMemoryPropertiesCommand(
    format::HandleId                             physical_device_id,
    const std::vector<format::DeviceMemoryType>& memory_types,
    const std::vector<format::DeviceMemoryHeap>& memory_heaps)
{}

void VulkanFrameInspectorConsumerBase::ProcessSetOpaqueAddressCommand(format::HandleId device_id,
                                                                      format::HandleId object_id,
                                                                      uint64_t         address)
{}

void VulkanFrameInspectorConsumerBase::ProcessSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                                                     format::HandleId pipeline_id,
                                                                                     size_t           data_size,
                                                                                     const uint8_t*   data)
{}

void VulkanFrameInspectorConsumerBase::ProcessSetSwapchainImageStateCommand(
    format::HandleId                                    device_id,
    format::HandleId                                    swapchain_id,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_info)
{}

void VulkanFrameInspectorConsumerBase::ProcessBeginResourceInitCommand(format::HandleId device_id,
                                                                       uint64_t         max_resource_size,
                                                                       uint64_t         max_copy_size)
{}

void VulkanFrameInspectorConsumerBase::ProcessEndResourceInitCommand(format::HandleId device_id) {}

void VulkanFrameInspectorConsumerBase::ProcessInitBufferCommand(format::HandleId device_id,
                                                                format::HandleId buffer_id,
                                                                uint64_t         data_size,
                                                                const uint8_t*   data)
{}

void VulkanFrameInspectorConsumerBase::ProcessInitImageCommand(format::HandleId             device_id,
                                                               format::HandleId             image_id,
                                                               uint64_t                     data_size,
                                                               uint32_t                     aspect,
                                                               uint32_t                     layout,
                                                               const std::vector<uint64_t>& level_sizes,
                                                               const uint8_t*               data)
{}

void VulkanFrameInspectorConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(
    const ApiCallInfo&               call_info,
    format::HandleId                 device,
    format::HandleId                 descriptorSet,
    format::HandleId                 descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData)
{}

void VulkanFrameInspectorConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    const ApiCallInfo&               call_info,
    format::HandleId                 commandBuffer,
    format::HandleId                 descriptorUpdateTemplate,
    format::HandleId                 layout,
    uint32_t                         set,
    DescriptorUpdateTemplateDecoder* pData)
{}

void VulkanFrameInspectorConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(
    const ApiCallInfo&               call_info,
    format::HandleId                 device,
    format::HandleId                 descriptorSet,
    format::HandleId                 descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData)
{}

VkResult VulkanFrameInspectorConsumerBase::OverrideCreateInstance(
    VkResult                                                   original_result,
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

    VkResult result = create_instance_proc_(replay_create_info, pAllocator->GetPointer(), replay_instance);

    if ((replay_instance != nullptr) && (result == VK_SUCCESS))
    {
        AddInstanceTable(*replay_instance);
    }

    return result;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)