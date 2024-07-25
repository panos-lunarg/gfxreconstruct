/*
 ** Copyright (c) 2018-2021 Valve Corporation
 ** Copyright (c) 2018-2023 LunarG, Inc.
 ** Copyright (c) 2019-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/vulkan_handle_wrappers.h"
#include "format/format.h"
#include "vulkan/vulkan_core.h"
#include <cstdint>
#include PROJECT_VERSION_HEADER_FILE

#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_capture_manager.h"

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_state_writer.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "graphics/vulkan_device_util.h"
#include "graphics/vulkan_util.h"
#include "util/compressor.h"
#include "util/logging.h"
#include "util/page_guard_manager.h"
#include "util/platform.h"
#include "util/spirv_parsing_util.h"

#include <cassert>
#include <unordered_set>

#if defined(__linux__) && !defined(__ANDROID__)
#if defined(VK_USE_PLATFORM_XCB_KHR)
#include <xcb/xcb_keysyms.h>
#endif
#endif

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <android/hardware_buffer.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VulkanCaptureManager* VulkanCaptureManager::singleton_ = nullptr;
VulkanLayerTable      VulkanCaptureManager::vulkan_layer_table_;

bool VulkanCaptureManager::CreateInstance()
{

    bool result = CommonCaptureManager::CreateInstance<VulkanCaptureManager>();
    GFXRECON_ASSERT(singleton_);

    GFXRECON_LOG_INFO("  Vulkan Header Version %u.%u.%u",
                      VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE),
                      VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE),
                      VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));

    return result;
}

VulkanCaptureManager* VulkanCaptureManager::InitSingleton()
{
    if (!singleton_)
    {
        singleton_ = new VulkanCaptureManager();
    }
    return singleton_;
}

void VulkanCaptureManager::DestroySingleton()
{
    if (singleton_)
    {
        delete singleton_;
        singleton_ = nullptr;
    }
}

void VulkanCaptureManager::DestroyInstance()
{
    GFXRECON_ASSERT(singleton_ && singleton_->common_manager_);
    singleton_->common_manager_->DestroyInstance(singleton_);
}

void VulkanCaptureManager::WriteTrackedState(util::FileOutputStream* file_stream,
                                             format::ThreadId        thread_id,
                                             util::FileOutputStream* asset_file_stream)
{
    uint64_t n_blocks =
        state_tracker_->WriteState(file_stream, thread_id, asset_file_stream, GetCompressor(), GetCurrentFrame());
    common_manager_->IncrementBlockIndex(n_blocks);
}

void VulkanCaptureManager::SetLayerFuncs(PFN_vkCreateInstance create_instance, PFN_vkCreateDevice create_device)
{
    assert((create_instance != nullptr) && (create_device != nullptr));
    vulkan_layer_table_.CreateInstance = create_instance;
    vulkan_layer_table_.CreateDevice   = create_device;
}

void VulkanCaptureManager::CheckVkCreateInstanceStatus(VkResult result)
{
    if (result != VK_SUCCESS)
    {
        DestroyInstance();
    }
}

void VulkanCaptureManager::InitVkInstance(VkInstance* instance, PFN_vkGetInstanceProcAddr gpa)
{
    assert(instance != nullptr);

    vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::NoParentWrapper,
                                         vulkan_wrappers::NoParentWrapper,
                                         vulkan_wrappers::InstanceWrapper>(
        vulkan_wrappers::NoParentWrapper::kHandleValue,
        vulkan_wrappers::NoParentWrapper::kHandleValue,
        instance,
        GetUniqueId);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::InstanceWrapper>(*instance);
    LoadVulkanInstanceTable(gpa, wrapper->handle, &wrapper->layer_table);
}

void VulkanCaptureManager::InitVkDevice(VkDevice* device, PFN_vkGetDeviceProcAddr gpa)
{
    assert((device != nullptr) && ((*device) != VK_NULL_HANDLE));

    vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::PhysicalDeviceWrapper,
                                         vulkan_wrappers::NoParentWrapper,
                                         vulkan_wrappers::DeviceWrapper>(
        VK_NULL_HANDLE, vulkan_wrappers::NoParentWrapper::kHandleValue, device, GetUniqueId);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(*device);
    LoadVulkanDeviceTable(gpa, wrapper->handle, &wrapper->layer_table);
}

void VulkanCaptureManager::WriteResizeWindowCmd2(format::HandleId              surface_id,
                                                 uint32_t                      width,
                                                 uint32_t                      height,
                                                 VkSurfaceTransformFlagBitsKHR pre_transform)
{
    if (IsCaptureModeWrite())
    {
        auto thread_data = GetThreadData();

        format::ResizeWindowCommand2 resize_cmd2;
        resize_cmd2.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        resize_cmd2.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(resize_cmd2);
        resize_cmd2.meta_header.meta_data_id =
            format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kResizeWindowCommand2);
        resize_cmd2.thread_id = thread_data->thread_id_;

        resize_cmd2.surface_id = surface_id;
        resize_cmd2.width      = width;
        resize_cmd2.height     = height;

        switch (pre_transform)
        {
            default:
            case VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR:
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR:
            case VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR:
                resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform0;
                break;
            case VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR:
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR:
                resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform90;
                break;
            case VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR:
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR:
                resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform180;
                break;
            case VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR:
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR:
                resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform270;
                break;
        }

        WriteToFile(&resize_cmd2, sizeof(resize_cmd2));
    }
}

void VulkanCaptureManager::WriteCreateHardwareBufferCmd(format::HandleId                                    memory_id,
                                                        AHardwareBuffer*                                    buffer,
                                                        const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{
    if (IsCaptureModeWrite())
    {
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        assert(buffer != nullptr);

        format::CreateHardwareBufferCommandHeader create_buffer_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        create_buffer_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        create_buffer_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(create_buffer_cmd);
        create_buffer_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kCreateHardwareBufferCommand);
        create_buffer_cmd.thread_id = thread_data->thread_id_;
        create_buffer_cmd.memory_id = memory_id;
        create_buffer_cmd.buffer_id = reinterpret_cast<uint64_t>(buffer);

        // Get AHB description data.
        AHardwareBuffer_Desc ahb_desc = {};
        AHardwareBuffer_describe(buffer, &ahb_desc);

        create_buffer_cmd.format = ahb_desc.format;
        create_buffer_cmd.width  = ahb_desc.width;
        create_buffer_cmd.height = ahb_desc.height;
        create_buffer_cmd.stride = ahb_desc.stride;
        create_buffer_cmd.usage  = ahb_desc.usage;
        create_buffer_cmd.layers = ahb_desc.layers;

        size_t planes_size = 0;

        if (plane_info.empty())
        {
            create_buffer_cmd.planes = 0;
        }
        else
        {
            create_buffer_cmd.planes = static_cast<uint32_t>(plane_info.size());
            // Update size of packet with size of plane info.
            planes_size = sizeof(plane_info[0]) * plane_info.size();
            create_buffer_cmd.meta_header.block_header.size += planes_size;
        }

        {
            if (planes_size > 0)
            {
                CombineAndWriteToFile(
                    { { &create_buffer_cmd, sizeof(create_buffer_cmd) }, { plane_info.data(), planes_size } });
            }
            else
            {
                WriteToFile(&create_buffer_cmd, sizeof(create_buffer_cmd));
            }
        }
#else
        GFXRECON_UNREFERENCED_PARAMETER(memory_id);
        GFXRECON_UNREFERENCED_PARAMETER(buffer);
        GFXRECON_UNREFERENCED_PARAMETER(plane_info);

        GFXRECON_LOG_ERROR("Skipping create AHardwareBuffer command write for unsupported platform");
#endif
    }
}

void VulkanCaptureManager::WriteDestroyHardwareBufferCmd(AHardwareBuffer* buffer)
{
    if (IsCaptureModeWrite())
    {
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        assert(buffer != nullptr);

        format::DestroyHardwareBufferCommand destroy_buffer_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        destroy_buffer_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        destroy_buffer_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(destroy_buffer_cmd);
        destroy_buffer_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kDestroyHardwareBufferCommand);
        destroy_buffer_cmd.thread_id = thread_data->thread_id_;
        destroy_buffer_cmd.buffer_id = reinterpret_cast<uint64_t>(buffer);

        WriteToFile(&destroy_buffer_cmd, sizeof(destroy_buffer_cmd));
#else
        GFXRECON_LOG_ERROR("Skipping destroy AHardwareBuffer command write for unsupported platform");
#endif
    }
}

void VulkanCaptureManager::WriteSetDevicePropertiesCommand(format::HandleId                  physical_device_id,
                                                           const VkPhysicalDeviceProperties& properties)
{
    if (IsCaptureModeWrite())
    {
        format::SetDevicePropertiesCommand properties_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        uint32_t device_name_len = static_cast<uint32_t>(util::platform::StringLength(properties.deviceName));

        properties_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        properties_cmd.meta_header.block_header.size =
            format::GetMetaDataBlockBaseSize(properties_cmd) + device_name_len;
        properties_cmd.meta_header.meta_data_id = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kSetDevicePropertiesCommand);
        properties_cmd.thread_id          = thread_data->thread_id_;
        properties_cmd.physical_device_id = physical_device_id;
        properties_cmd.api_version        = properties.apiVersion;
        properties_cmd.driver_version     = properties.driverVersion;
        properties_cmd.vendor_id          = properties.vendorID;
        properties_cmd.device_id          = properties.deviceID;
        properties_cmd.device_type        = properties.deviceType;
        util::platform::MemoryCopy(
            properties_cmd.pipeline_cache_uuid, format::kUuidSize, properties.pipelineCacheUUID, VK_UUID_SIZE);
        properties_cmd.device_name_len = device_name_len;

        CombineAndWriteToFile(
            { { &properties_cmd, sizeof(properties_cmd) }, { properties.deviceName, properties_cmd.device_name_len } });
    }
}

void VulkanCaptureManager::WriteSetDeviceMemoryPropertiesCommand(
    format::HandleId physical_device_id, const VkPhysicalDeviceMemoryProperties& memory_properties)
{
    if (IsCaptureModeWrite())
    {
        format::SetDeviceMemoryPropertiesCommand memory_properties_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        memory_properties_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        memory_properties_cmd.meta_header.block_header.size =
            format::GetMetaDataBlockBaseSize(memory_properties_cmd) +
            (sizeof(format::DeviceMemoryType) * memory_properties.memoryTypeCount) +
            (sizeof(format::DeviceMemoryHeap) * memory_properties.memoryHeapCount);
        memory_properties_cmd.meta_header.meta_data_id = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kSetDeviceMemoryPropertiesCommand);
        memory_properties_cmd.thread_id          = thread_data->thread_id_;
        memory_properties_cmd.physical_device_id = physical_device_id;
        memory_properties_cmd.memory_type_count  = memory_properties.memoryTypeCount;
        memory_properties_cmd.memory_heap_count  = memory_properties.memoryHeapCount;

        // Since the number of file writes below is dynamic, CombineAndWriteToFile is not suitable. Instead, manually
        // populate thread_data's scratch_buffer_ then write to file.
        auto& scratch_buffer = thread_data->GetScratchBuffer();
        scratch_buffer.clear();
        std::copy(reinterpret_cast<uint8_t*>(&memory_properties_cmd),
                  reinterpret_cast<uint8_t*>(&memory_properties_cmd) + sizeof(memory_properties_cmd),
                  std::back_inserter(scratch_buffer));

        format::DeviceMemoryType type;
        for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
        {
            type.property_flags = memory_properties.memoryTypes[i].propertyFlags;
            type.heap_index     = memory_properties.memoryTypes[i].heapIndex;

            scratch_buffer.insert(scratch_buffer.end(),
                                  reinterpret_cast<uint8_t*>(&type),
                                  reinterpret_cast<uint8_t*>(&type) + sizeof(type));
        }

        format::DeviceMemoryHeap heap;
        for (uint32_t i = 0; i < memory_properties.memoryHeapCount; ++i)
        {
            heap.size  = memory_properties.memoryHeaps[i].size;
            heap.flags = memory_properties.memoryHeaps[i].flags;

            scratch_buffer.insert(scratch_buffer.end(),
                                  reinterpret_cast<uint8_t*>(&heap),
                                  reinterpret_cast<uint8_t*>(&heap) + sizeof(heap));
        }

        WriteToFile(scratch_buffer.data(), scratch_buffer.size());
    }
}

void VulkanCaptureManager::WriteSetOpaqueAddressCommand(format::HandleId device_id,
                                                        format::HandleId object_id,
                                                        uint64_t         address)
{
    if (IsCaptureModeWrite())
    {
        format::SetOpaqueAddressCommand opaque_address_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        opaque_address_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        opaque_address_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(opaque_address_cmd);
        opaque_address_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kSetOpaqueAddressCommand);
        opaque_address_cmd.thread_id = thread_data->thread_id_;
        opaque_address_cmd.device_id = device_id;
        opaque_address_cmd.object_id = object_id;
        opaque_address_cmd.address   = address;

        WriteToFile(&opaque_address_cmd, sizeof(opaque_address_cmd));
    }
}

void VulkanCaptureManager::WriteSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                                       format::HandleId pipeline_id,
                                                                       size_t           data_size,
                                                                       const void*      data)
{
    if (IsCaptureModeWrite())
    {
        format::SetRayTracingShaderGroupHandlesCommandHeader set_handles_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        set_handles_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        set_handles_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(set_handles_cmd) + data_size;
        set_handles_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kSetRayTracingShaderGroupHandlesCommand);
        set_handles_cmd.thread_id   = thread_data->thread_id_;
        set_handles_cmd.device_id   = device_id;
        set_handles_cmd.pipeline_id = pipeline_id;
        set_handles_cmd.data_size   = data_size;

        CombineAndWriteToFile({ { &set_handles_cmd, sizeof(set_handles_cmd) }, { data, data_size } });
    }
}

void VulkanCaptureManager::SetDescriptorUpdateTemplateInfo(VkDescriptorUpdateTemplate                  update_template,
                                                           const VkDescriptorUpdateTemplateCreateInfo* create_info)
{
    // A NULL check should have been performed by the caller.
    assert((create_info != nullptr));

    if (create_info->descriptorUpdateEntryCount > 0)
    {
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(update_template);
        UpdateTemplateInfo* info = &wrapper->info;

        for (size_t i = 0; i < create_info->descriptorUpdateEntryCount; ++i)
        {
            const VkDescriptorUpdateTemplateEntry* entry      = &create_info->pDescriptorUpdateEntries[i];
            VkDescriptorType                       type       = entry->descriptorType;
            size_t                                 entry_size = 0;

            // Sort the descriptor update template info by type, so it can be written to the capture file
            // as tightly packed arrays of structures.  One array will be written for each descriptor info
            // structure/textel buffer view.
            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                UpdateTemplateEntryInfo image_info;
                image_info.binding       = entry->dstBinding;
                image_info.array_element = entry->dstArrayElement;
                image_info.count         = entry->descriptorCount;
                image_info.offset        = entry->offset;
                image_info.stride        = entry->stride;
                image_info.type          = type;

                info->image_info_count += entry->descriptorCount;
                info->image_info.emplace_back(image_info);

                entry_size = sizeof(VkDescriptorImageInfo);
            }
            if (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE)
            {
                UpdateTemplateEntryInfo image_info;
                image_info.binding       = entry->dstBinding;
                image_info.array_element = entry->dstArrayElement;
                image_info.count         = entry->descriptorCount;
                image_info.offset        = entry->offset;
                image_info.stride        = entry->stride;
                image_info.type          = type;

                info->storage_image_info_count += entry->descriptorCount;
                info->storage_image_info.emplace_back(image_info);

                entry_size = sizeof(VkDescriptorImageInfo);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC))
            {
                UpdateTemplateEntryInfo buffer_info;
                buffer_info.binding       = entry->dstBinding;
                buffer_info.array_element = entry->dstArrayElement;
                buffer_info.count         = entry->descriptorCount;
                buffer_info.offset        = entry->offset;
                buffer_info.stride        = entry->stride;
                buffer_info.type          = type;

                info->buffer_info_count += entry->descriptorCount;
                info->buffer_info.emplace_back(buffer_info);

                entry_size = sizeof(VkDescriptorBufferInfo);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                UpdateTemplateEntryInfo buffer_info;
                buffer_info.binding       = entry->dstBinding;
                buffer_info.array_element = entry->dstArrayElement;
                buffer_info.count         = entry->descriptorCount;
                buffer_info.offset        = entry->offset;
                buffer_info.stride        = entry->stride;
                buffer_info.type          = type;

                info->storage_buffer_info_count += entry->descriptorCount;
                info->storage_buffer_info.emplace_back(buffer_info);

                entry_size = sizeof(VkDescriptorBufferInfo);
            }
            else if (type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER)
            {
                UpdateTemplateEntryInfo texel_buffer_view_info;
                texel_buffer_view_info.binding       = entry->dstBinding;
                texel_buffer_view_info.array_element = entry->dstArrayElement;
                texel_buffer_view_info.count         = entry->descriptorCount;
                texel_buffer_view_info.offset        = entry->offset;
                texel_buffer_view_info.stride        = entry->stride;
                texel_buffer_view_info.type          = type;

                info->uniform_texel_buffer_view_count += entry->descriptorCount;
                info->uniform_texel_buffer_view.emplace_back(texel_buffer_view_info);

                entry_size = sizeof(VkBufferView);
            }
            else if (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER)
            {
                UpdateTemplateEntryInfo texel_buffer_view_info;
                texel_buffer_view_info.binding       = entry->dstBinding;
                texel_buffer_view_info.array_element = entry->dstArrayElement;
                texel_buffer_view_info.count         = entry->descriptorCount;
                texel_buffer_view_info.offset        = entry->offset;
                texel_buffer_view_info.stride        = entry->stride;
                texel_buffer_view_info.type          = type;

                info->storage_texel_buffer_view_count += entry->descriptorCount;
                info->storage_texel_buffer_view.emplace_back(texel_buffer_view_info);

                entry_size = sizeof(VkBufferView);
            }
            else if (type == VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
            {
                UpdateTemplateEntryInfo accel_struct_info;
                accel_struct_info.binding       = entry->dstBinding;
                accel_struct_info.array_element = entry->dstArrayElement;
                accel_struct_info.count         = entry->descriptorCount;
                accel_struct_info.offset        = entry->offset;
                accel_struct_info.stride        = entry->stride;
                accel_struct_info.type          = type;

                info->acceleration_structure_khr_count += entry->descriptorCount;
                info->acceleration_structure_khr.emplace_back(accel_struct_info);

                entry_size = sizeof(VkAccelerationStructureKHR);
            }
            else if (type == VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK)
            {
                constexpr size_t byte_stride = 1;
                GFXRECON_ASSERT(entry->stride == byte_stride);

                UpdateTemplateEntryInfo inline_uniform_info;
                inline_uniform_info.binding       = entry->dstBinding;
                inline_uniform_info.array_element = entry->dstArrayElement;

                // count is interpreted as number of bytes here
                inline_uniform_info.count  = entry->descriptorCount;
                inline_uniform_info.offset = entry->offset;
                inline_uniform_info.stride = entry->stride;
                inline_uniform_info.type   = type;

                info->inline_uniform_block_count += entry->descriptorCount;
                info->inline_uniform_block.emplace_back(inline_uniform_info);

                entry_size = byte_stride;
            }
            else
            {
                GFXRECON_LOG_ERROR("Unrecognized/unsupported descriptor type in descriptor update template.");
                assert(false);
            }

            if (entry->descriptorCount > 0)
            {
                size_t max_size = ((entry->descriptorCount - 1) * entry->stride) + entry->offset + entry_size;
                if (max_size > info->max_size)
                {
                    info->max_size = max_size;
                }
            }
        }
    }
}

bool VulkanCaptureManager::GetDescriptorUpdateTemplateInfo(VkDescriptorUpdateTemplate update_template,
                                                           const UpdateTemplateInfo** info) const
{
    assert(info != nullptr);

    bool found = false;

    if (update_template != VK_NULL_HANDLE)
    {
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(update_template);
        (*info)      = &wrapper->info;
        found        = true;
    }

    return found;
}

void VulkanCaptureManager::TrackUpdateDescriptorSetWithTemplate(VkDescriptorSet            set,
                                                                VkDescriptorUpdateTemplate update_template,
                                                                const void*                data)
{
    const UpdateTemplateInfo* template_info = nullptr;
    if (!GetDescriptorUpdateTemplateInfo(update_template, &template_info))
    {
        return;
    }

    assert(set != VK_NULL_HANDLE);

    // When processing descriptor updates, we pack the unique handle ID into the stored
    // VkWriteDescriptorSet/VkCopyDescriptorSet handles so that the state writer can determine if the object still
    // exists at state write time by checking for the ID in the active state table.
    if ((template_info != nullptr) && (data != nullptr))
    {
        auto           wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(set);
        const uint8_t* bytes   = reinterpret_cast<const uint8_t*>(data);

        wrapper->dirty = true;

        for (const auto& entry : template_info->image_info)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[current_binding];

                assert(binding.images != nullptr);

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                format::HandleId*      dst_sampler_ids = &binding.sampler_ids[current_array_element];
                format::HandleId*      dst_image_ids   = &binding.handle_ids[current_array_element];
                VkDescriptorImageInfo* dst_info        = &binding.images[current_array_element];
                const uint8_t*         src_address     = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto image_info = reinterpret_cast<const VkDescriptorImageInfo*>(src_address);
                    if ((binding.type == VK_DESCRIPTOR_TYPE_SAMPLER) ||
                        (binding.type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
                    {
                        dst_sampler_ids[i] =
                            vulkan_wrappers::GetWrappedId<vulkan_wrappers::SamplerWrapper>(image_info->sampler);
                    }

                    if (binding.type != VK_DESCRIPTOR_TYPE_SAMPLER)
                    {
                        dst_image_ids[i] =
                            vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(image_info->imageView);
                    }

                    memcpy(&dst_info[i], image_info, sizeof(dst_info[i]));

                    src_address += entry.stride;
                }

                // Check for consecutive update.
                if (current_count == current_writes)
                {
                    break;
                }
                else
                {
                    current_count -= current_writes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_writes * entry.stride);
                }
            }
        }

        for (const auto& entry : template_info->storage_image_info)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[current_binding];

                assert(binding.storage_images != nullptr);

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                format::HandleId*      dst_image_ids = &binding.handle_ids[current_array_element];
                VkDescriptorImageInfo* dst_info      = &binding.storage_images[current_array_element];
                const uint8_t*         src_address   = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    assert(binding.type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE);

                    auto image_info = reinterpret_cast<const VkDescriptorImageInfo*>(src_address);
                    dst_image_ids[i] =
                        vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(image_info->imageView);

                    memcpy(&dst_info[i], image_info, sizeof(dst_info[i]));

                    src_address += entry.stride;
                }

                // Check for consecutive update.
                if (current_count == current_writes)
                {
                    break;
                }
                else
                {
                    current_count -= current_writes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_writes * entry.stride);
                }
            }
        }

        for (const auto& entry : template_info->buffer_info)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[current_binding];

                assert(binding.buffers != nullptr);

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                format::HandleId*       dst_buffer_ids = &binding.handle_ids[current_array_element];
                VkDescriptorBufferInfo* dst_info       = &binding.buffers[current_array_element];
                const uint8_t*          src_address    = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto buffer_info = reinterpret_cast<const VkDescriptorBufferInfo*>(src_address);
                    dst_buffer_ids[i] =
                        vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer_info->buffer);
                    memcpy(&dst_info[i], buffer_info, sizeof(dst_info[i]));

                    src_address += entry.stride;
                }

                // Check for consecutive update.
                if (current_count == current_writes)
                {
                    break;
                }
                else
                {
                    current_count -= current_writes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_writes * entry.stride);
                }
            }
        }

        for (const auto& entry : template_info->storage_buffer_info)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[current_binding];

                assert(binding.storage_buffers != nullptr);

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                format::HandleId*       dst_buffer_ids = &binding.handle_ids[current_array_element];
                VkDescriptorBufferInfo* dst_info       = &binding.storage_buffers[current_array_element];
                const uint8_t*          src_address    = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto buffer_info = reinterpret_cast<const VkDescriptorBufferInfo*>(src_address);
                    dst_buffer_ids[i] =
                        vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer_info->buffer);
                    memcpy(&dst_info[i], buffer_info, sizeof(dst_info[i]));

                    src_address += entry.stride;
                }

                // Check for consecutive update.
                if (current_count == current_writes)
                {
                    break;
                }
                else
                {
                    current_count -= current_writes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_writes * entry.stride);
                }
            }
        }

        for (const auto& entry : template_info->uniform_texel_buffer_view)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[current_binding];

                assert(binding.uniform_texel_buffer_views != nullptr);

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                format::HandleId* dst_view_ids = &binding.handle_ids[current_array_element];
                VkBufferView*     dst_info     = &binding.uniform_texel_buffer_views[current_array_element];
                const uint8_t*    src_address  = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto buffer_view = reinterpret_cast<const VkBufferView*>(src_address);
                    dst_view_ids[i]  = vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferViewWrapper>(*buffer_view);
                    dst_info[i]      = *buffer_view;

                    src_address += entry.stride;
                }

                // Check for consecutive update.
                if (current_count == current_writes)
                {
                    break;
                }
                else
                {
                    current_count -= current_writes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_writes * entry.stride);
                }
            }
        }

        for (const auto& entry : template_info->storage_texel_buffer_view)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[current_binding];

                assert(binding.storage_texel_buffer_views != nullptr);

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                format::HandleId* dst_view_ids = &binding.handle_ids[current_array_element];
                VkBufferView*     dst_info     = &binding.storage_texel_buffer_views[current_array_element];
                const uint8_t*    src_address  = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto buffer_view = reinterpret_cast<const VkBufferView*>(src_address);
                    dst_view_ids[i]  = vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferViewWrapper>(*buffer_view);
                    dst_info[i]      = *buffer_view;

                    src_address += entry.stride;
                }

                // Check for consecutive update.
                if (current_count == current_writes)
                {
                    break;
                }
                else
                {
                    current_count -= current_writes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_writes * entry.stride);
                }
            }
        }

        for (const auto& entry : template_info->acceleration_structure_khr)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[current_binding];

                assert(binding.acceleration_structures != nullptr);

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                format::HandleId*           dst_view_ids = &binding.handle_ids[current_array_element];
                VkAccelerationStructureKHR* dst_info     = &binding.acceleration_structures[current_array_element];
                const uint8_t*              src_address  = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    const auto* accel_struct = reinterpret_cast<const VkAccelerationStructureKHR*>(src_address);
                    dst_view_ids[i] =
                        vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(*accel_struct);
                    dst_info[i] = *accel_struct;

                    src_address += entry.stride;
                }

                // Check for consecutive update.
                if (current_count == current_writes)
                {
                    break;
                }
                else
                {
                    current_count -= current_writes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_writes * entry.stride);
                }
            }
        }
        for (const auto& entry : template_info->inline_uniform_block)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[entry.binding];
                GFXRECON_ASSERT(binding.inline_uniform_block != nullptr);

                // Check count for consecutive updates.
                const uint32_t current_num_bytes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_num_bytes, true);

                const uint8_t* src_address = bytes + current_offset;
                uint8_t*       dst_address = binding.inline_uniform_block.get() + entry.array_element;
                memcpy(dst_address, src_address, current_num_bytes);

                // Check for consecutive update.
                if (current_count == current_num_bytes)
                {
                    break;
                }
                else
                {
                    current_count -= current_num_bytes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_num_bytes * entry.stride);
                }
            }
        }
    }
}

VkResult VulkanCaptureManager::OverrideCreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator,
                                                      VkInstance*                  pInstance)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (CreateInstance())
    {
        if (singleton_->IsPageGuardMemoryModeExternal())
        {
            assert(pCreateInfo != nullptr);

            VkInstanceCreateInfo create_info_copy = (*pCreateInfo);

            // TODO: Only enable KHR_get_physical_device_properties_2 for 1.0 API version.
            size_t                   extension_count = create_info_copy.enabledExtensionCount;
            const char* const*       extensions      = create_info_copy.ppEnabledExtensionNames;
            std::vector<const char*> modified_extensions;

            bool has_dev_prop2    = false;
            bool has_ext_mem_caps = false;

            for (size_t i = 0; i < extension_count; ++i)
            {
                auto entry = extensions[i];

                modified_extensions.push_back(entry);

                if (util::platform::StringCompare(entry, VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME) == 0)
                {
                    has_dev_prop2 = true;
                }

                if (util::platform::StringCompare(entry, VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME) == 0)
                {
                    has_ext_mem_caps = true;
                }
            }

            if (!has_dev_prop2)
            {
                modified_extensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
            }

            if (!has_ext_mem_caps)
            {
                modified_extensions.push_back(VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME);
            }

            create_info_copy.enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
            create_info_copy.ppEnabledExtensionNames = modified_extensions.data();

            result = vulkan_layer_table_.CreateInstance(&create_info_copy, pAllocator, pInstance);
        }
        else
        {
            result = vulkan_layer_table_.CreateInstance(pCreateInfo, pAllocator, pInstance);
        }
    }

    if ((result == VK_SUCCESS) && (pCreateInfo->pApplicationInfo != nullptr))
    {
        auto api_version              = pCreateInfo->pApplicationInfo->apiVersion;
        auto instance_wrapper         = vulkan_wrappers::GetWrapper<vulkan_wrappers::InstanceWrapper>(*pInstance);
        instance_wrapper->api_version = api_version;

        // Warn when enabled API version is newer than the supported API version.
        if (api_version > VK_HEADER_VERSION_COMPLETE)
        {
            GFXRECON_LOG_WARNING(
                "The application has specified that it uses Vulkan API version %u.%u.%u, which is newer than the "
                "version supported by GFXReconstruct.  Use of unsupported Vulkan features may cause capture or replay "
                "to fail.",
                VK_VERSION_MAJOR(api_version),
                VK_VERSION_MINOR(api_version),
                VK_VERSION_PATCH(api_version));
        }
    }

    return result;
}

VkResult VulkanCaptureManager::OverrideCreateDevice(VkPhysicalDevice             physicalDevice,
                                                    const VkDeviceCreateInfo*    pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator,
                                                    VkDevice*                    pDevice)
{
    auto                handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDeviceCreateInfo* pCreateInfo_unwrapped =
        const_cast<VkDeviceCreateInfo*>(vulkan_wrappers::UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory));

    assert(pCreateInfo_unwrapped != nullptr);

    const VulkanInstanceTable* instance_table = vulkan_wrappers::GetInstanceTable(physicalDevice);
    auto physical_device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physicalDevice);

    graphics::VulkanDeviceUtil                device_util;
    graphics::VulkanDevicePropertyFeatureInfo property_feature_info = device_util.EnableRequiredPhysicalDeviceFeatures(
        physical_device_wrapper->instance_api_version, instance_table, physicalDevice, pCreateInfo_unwrapped);

    // TODO: Only enable KHR_external_memory_capabilities for 1.0 API version.
    size_t                   extension_count = pCreateInfo_unwrapped->enabledExtensionCount;
    const char* const*       extensions      = pCreateInfo_unwrapped->ppEnabledExtensionNames;
    std::vector<const char*> modified_extensions;

    bool has_ext_mem      = false;
    bool has_ext_mem_host = false;

    for (size_t i = 0; i < extension_count; ++i)
    {
        auto entry = pCreateInfo_unwrapped->ppEnabledExtensionNames[i];

        modified_extensions.push_back(entry);

        if (IsPageGuardMemoryModeExternal())
        {
            if (util::platform::StringCompare(entry, VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME) == 0)
            {
                has_ext_mem = true;
            }
            else if (util::platform::StringCompare(entry, VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME) == 0)
            {
                has_ext_mem_host = true;
            }
        }
    }

    if (IsPageGuardMemoryModeExternal())
    {
        if (!has_ext_mem)
        {
            modified_extensions.push_back(VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME);
        }

        if (!has_ext_mem_host)
        {
            modified_extensions.push_back(VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME);
        }
    }

    pCreateInfo_unwrapped->enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
    pCreateInfo_unwrapped->ppEnabledExtensionNames = modified_extensions.data();

    VkDeviceQueueCreateInfo modified_queue_ci = {};

    if (GetQueueZeroOnly())
    {
        // GetPhysicalDeviceQueueFamilyProperties force to return only FamilyIndex: 0 and queueCount: 1, so it shouldn't
        // need to modifiy. If modified happens, it means the application doesn't follow
        // GetPhysicalDeviceQueueFamilyProperties to set DeviceQueueCreateInfo. This modified could break the
        // application setting. It might cause error.
        GFXRECON_ASSERT(pCreateInfo_unwrapped->pQueueCreateInfos != nullptr);

        if (pCreateInfo_unwrapped->queueCreateInfoCount > 1)
        {
            GFXRECON_LOG_WARNING("Because QUEUE_ZERO_ONLY is enabled, force queueCreateInfoCount to 1 on CreateDevice. "
                                 "It might cause error.");
            pCreateInfo_unwrapped->queueCreateInfoCount = 1;
        }

        modified_queue_ci = pCreateInfo_unwrapped->pQueueCreateInfos[0];

        if (modified_queue_ci.queueFamilyIndex > 0)
        {
            GFXRECON_LOG_WARNING("Because QUEUE_ZERO_ONLY is enabled, force queueFamilyIndex to 0 on CreateDevice. It "
                                 "might cause error.");
            modified_queue_ci.queueFamilyIndex = 0;
        }

        if (modified_queue_ci.queueCount > 1)
        {
            GFXRECON_LOG_WARNING(
                "Because QUEUE_ZERO_ONLY is enabled, force queueCount to 1 on CreateDevice. It might cause error.");
            modified_queue_ci.queueCount = 1;
        }
        pCreateInfo_unwrapped->pQueueCreateInfos = &modified_queue_ci;
    }

    VkResult result = vulkan_layer_table_.CreateDevice(physicalDevice, pCreateInfo_unwrapped, pAllocator, pDevice);

    if (result == VK_SUCCESS)
    {
        assert((pDevice != nullptr) && (*pDevice != VK_NULL_HANDLE));

        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(*pDevice);

        // Track state of physical device properties and features at device creation
        wrapper->property_feature_info = property_feature_info;

        if (!IsCaptureModeTrack())
        {
            // The state tracker will set this value when it is enabled. When state tracking is disabled it is set here
            // to ensure it is available.
            wrapper->physical_device = physical_device_wrapper;
        }

        for (uint32_t q = 0; q < pCreateInfo_unwrapped->queueCreateInfoCount; ++q)
        {
            const VkDeviceQueueCreateInfo* queue_create_info = &pCreateInfo_unwrapped->pQueueCreateInfos[q];
            assert(wrapper->queue_family_creation_flags.find(queue_create_info->queueFamilyIndex) ==
                   wrapper->queue_family_creation_flags.end());
            wrapper->queue_family_creation_flags[queue_create_info->queueFamilyIndex] = queue_create_info->flags;
        }
    }

    // Restore modified property/feature create info values to the original application values
    device_util.RestoreModifiedPhysicalDeviceFeatures();

    return result;
}

VkResult VulkanCaptureManager::OverrideCreateBuffer(VkDevice                     device,
                                                    const VkBufferCreateInfo*    pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator,
                                                    VkBuffer*                    pBuffer)
{
    VkResult result               = VK_SUCCESS;
    auto     device_wrapper       = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    VkDevice device_unwrapped     = device_wrapper->handle;
    auto     device_table         = vulkan_wrappers::GetDeviceTable(device);
    auto     handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();

    VkBufferCreateInfo modified_create_info = (*pCreateInfo);

    if (IsTrimEnabled())
    {
        modified_create_info.usage |= VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    }

    bool                uses_address         = false;
    VkBufferCreateFlags address_create_flags = 0;
    VkBufferUsageFlags  address_usage_flags  = 0;

    if (device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        if ((pCreateInfo->usage & VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT) ==
            VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT)
        {
            uses_address = true;
            address_create_flags |= VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
        }
        if ((pCreateInfo->usage & VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR) ==
            VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR)
        {
            uses_address = true;
            address_create_flags |= VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
            address_usage_flags |= VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT;
        }
    }

    // NOTE: VkBufferCreateInfo does not currently support pNext structures with handles, so does not have a handle
    // unwrapping function.  If a pNext struct with handles is added in the future, it will be necessary to unwrap
    // pCreateInfo before calling CreateBuffer.  The unwrapping process will create a mutable copy of the original
    // pCreateInfo, with unwrapped handles, which can be modified directly and would not require the
    // 'modified_create_info' copy performed below.
    if (uses_address && (((pCreateInfo->flags & address_create_flags) != address_create_flags) ||
                         ((pCreateInfo->usage & address_usage_flags) != address_usage_flags)))
    {
        // If the buffer has shader device address usage, but the device address capture replay flag was not set, it
        // needs to be set here.  We create copy from an override to prevent the modified pCreateInfo from being
        // written to the capture file.
        modified_create_info.flags |= address_create_flags;
        modified_create_info.usage |= address_usage_flags;
    }
    result = device_table->CreateBuffer(device_unwrapped, &modified_create_info, pAllocator, pBuffer);

    if ((result == VK_SUCCESS) && (pBuffer != nullptr))
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::BufferWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pBuffer, GetUniqueId);

        if (uses_address)
        {
            // If the buffer has a device address, write the 'set buffer address' command before writing the API call to
            // create the buffer.  The address will need to be passed to vkCreateBuffer through the pCreateInfo pNext
            // list.
            auto buffer_wrapper            = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(*pBuffer);
            VkBufferDeviceAddressInfo info = { VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO };
            info.pNext                     = nullptr;
            info.buffer                    = buffer_wrapper->handle;
            uint64_t address               = 0;

            if (device_wrapper->physical_device->instance_api_version >= VK_MAKE_VERSION(1, 2, 0))
            {
                address = device_table->GetBufferOpaqueCaptureAddress(device_unwrapped, &info);
            }
            else
            {
                address = device_table->GetBufferOpaqueCaptureAddressKHR(device_unwrapped, &info);
            }

            WriteSetOpaqueAddressCommand(device_wrapper->handle_id, buffer_wrapper->handle_id, address);

            if (IsCaptureModeTrack())
            {
                state_tracker_->TrackBufferDeviceAddress(device, *pBuffer, address);
            }
        }

        vulkan_wrappers::BufferWrapper* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(*pBuffer);
        assert(wrapper != nullptr);
        wrapper->size = pCreateInfo->size;
    }

    return result;
}

VkResult VulkanCaptureManager::OverrideCreateImage(VkDevice                     device,
                                                   const VkImageCreateInfo*     pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator,
                                                   VkImage*                     pImage)
{
    auto                     handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    const VkImageCreateInfo* pCreateInfo_unwrapped =
        vulkan_wrappers::UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkImageCreateInfo modified_create_info = (*pCreateInfo_unwrapped);

    if (IsTrimEnabled())
    {
        modified_create_info.usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    }

    VkResult result =
        vulkan_wrappers::GetDeviceTable(device)->CreateImage(device, &modified_create_info, pAllocator, pImage);

    if (result >= 0)
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::ImageWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pImage, VulkanCaptureManager::GetUniqueId);

        const VulkanDeviceTable* device_table = vulkan_wrappers::GetDeviceTable(device);
        VkMemoryRequirements     image_mem_reqs;

        vulkan_wrappers::ImageWrapper* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(*pImage);
        assert(wrapper != nullptr);

        device_table->GetImageMemoryRequirements(device, *pImage, &image_mem_reqs);
        wrapper->size = image_mem_reqs.size;
    }

    return result;
}

VkResult
VulkanCaptureManager::OverrideCreateAccelerationStructureKHR(VkDevice                                    device,
                                                             const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
                                                             const VkAllocationCallbacks*                pAllocator,
                                                             VkAccelerationStructureKHR* pAccelerationStructureKHR)
{
    auto                     handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    auto                     device_wrapper       = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    VkDevice                 device_unwrapped     = device_wrapper->handle;
    const VulkanDeviceTable* device_table         = vulkan_wrappers::GetDeviceTable(device);
    const VkAccelerationStructureCreateInfoKHR* pCreateInfo_unwrapped =
        vulkan_wrappers::UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result;
    if (device_wrapper->property_feature_info.feature_accelerationStructureCaptureReplay)
    {
        // Add flag to allow for opaque address capture
        VkAccelerationStructureCreateInfoKHR modified_create_info = (*pCreateInfo_unwrapped);
        modified_create_info.createFlags |= VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR;
        result = device_table->CreateAccelerationStructureKHR(
            device_unwrapped, &modified_create_info, pAllocator, pAccelerationStructureKHR);
    }
    else
    {
        result = device_table->CreateAccelerationStructureKHR(
            device_unwrapped, pCreateInfo_unwrapped, pAllocator, pAccelerationStructureKHR);
    }

    if ((result == VK_SUCCESS) && (pAccelerationStructureKHR != nullptr))
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::AccelerationStructureKHRWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pAccelerationStructureKHR, GetUniqueId);

        if (device_wrapper->property_feature_info.feature_accelerationStructureCaptureReplay)
        {
            auto accel_struct_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                *pAccelerationStructureKHR);

            VkAccelerationStructureDeviceAddressInfoKHR address_info{
                VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR, nullptr, accel_struct_wrapper->handle
            };

            // save address to use as pCreateInfo->deviceAddress during replay
            VkDeviceAddress address =
                device_table->GetAccelerationStructureDeviceAddressKHR(device_unwrapped, &address_info);

            WriteSetOpaqueAddressCommand(device_wrapper->handle_id, accel_struct_wrapper->handle_id, address);

            if (IsCaptureModeTrack())
            {
                state_tracker_->TrackAccelerationStructureKHRDeviceAddress(device, *pAccelerationStructureKHR, address);
            }
        }
    }

    return result;
}

void VulkanCaptureManager::OverrideCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer                                        commandBuffer,
    uint32_t                                               infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR*     pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackTLASBuildCommand(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
    }

    const VulkanDeviceTable* device_table = vulkan_wrappers::GetDeviceTable(commandBuffer);
    device_table->CmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

VkResult VulkanCaptureManager::OverrideAllocateMemory(VkDevice                     device,
                                                      const VkMemoryAllocateInfo*  pAllocateInfo,
                                                      const VkAllocationCallbacks* pAllocator,
                                                      VkDeviceMemory*              pMemory)
{
    VkResult                         result          = VK_SUCCESS;
    void*                            external_memory = nullptr;
    VkImportMemoryHostPointerInfoEXT import_info;

    auto                  device_wrapper       = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    VkDevice              device_unwrapped     = device_wrapper->handle;
    auto                  handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkMemoryAllocateInfo* pAllocateInfo_unwrapped =
        const_cast<VkMemoryAllocateInfo*>(vulkan_wrappers::UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory));

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    const VkImportAndroidHardwareBufferInfoANDROID* import_ahb_info =
        FindAllocateMemoryExtensions(pAllocateInfo_unwrapped);
#endif

    bool                   uses_address         = false;
    VkMemoryAllocateFlags* modified_alloc_flags = nullptr;
    VkMemoryAllocateFlags  incoming_alloc_flags;
    if (device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        VkBaseOutStructure* current_struct = reinterpret_cast<VkBaseOutStructure*>(pAllocateInfo_unwrapped)->pNext;
        while (current_struct != nullptr)
        {
            if (current_struct->sType == VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO)
            {
                auto alloc_flags_info = reinterpret_cast<VkMemoryAllocateFlagsInfo*>(current_struct);
                if ((alloc_flags_info->flags & VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT) ==
                    VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT)
                {
                    uses_address         = true;
                    incoming_alloc_flags = alloc_flags_info->flags;
                    alloc_flags_info->flags |= VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
                    modified_alloc_flags = &(alloc_flags_info->flags);
                }
                break;
            }
            current_struct = current_struct->pNext;
        }
    }

    if (IsPageGuardMemoryModeExternal())
    {
        VkMemoryPropertyFlags properties = GetMemoryProperties(device_wrapper, pAllocateInfo->memoryTypeIndex);

        if ((properties & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
        {
            // Use the external memory extension to provide a memory allocation that can be watched directly by the page
            // guard implementation.
            assert(pAllocateInfo_unwrapped != nullptr);

            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pAllocateInfo_unwrapped->allocationSize);

            // TODO: This should be aligned to minImportedHostPointerAlignment, but there is a currently a loader bug
            // that prevents the layer from querying for that value when a 1.0 application does not explicitly enable
            // physical_device_properties2.  For now we align to system page size.
            size_t external_memory_size =
                manager->GetAlignedSize(static_cast<size_t>(pAllocateInfo_unwrapped->allocationSize));
            external_memory = manager->AllocateMemory(external_memory_size, true);

            if (external_memory != nullptr)
            {
                pAllocateInfo_unwrapped->allocationSize = external_memory_size;

                import_info.sType        = VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT;
                import_info.pNext        = nullptr;
                import_info.handleType   = VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT;
                import_info.pHostPointer = external_memory;

                // TODO: Check pNext chain for use of incompatible extension types.
                VkBaseOutStructure* end = reinterpret_cast<VkBaseOutStructure*>(pAllocateInfo_unwrapped);
                while (end->pNext != nullptr)
                {
                    end = end->pNext;
                }

                end->pNext = reinterpret_cast<VkBaseOutStructure*>(&import_info);
            }
        }
    }

    result = vulkan_wrappers::GetDeviceTable(device)->AllocateMemory(
        device_unwrapped, pAllocateInfo_unwrapped, pAllocator, pMemory);

    if (result == VK_SUCCESS)
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::DeviceMemoryWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pMemory, GetUniqueId);

        assert(pMemory != nullptr);
        auto memory_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(*pMemory);

        if (uses_address)
        {
            // Restore modified allocation flags
            assert(modified_alloc_flags != nullptr);
            *modified_alloc_flags = incoming_alloc_flags;

            VkDeviceMemoryOpaqueCaptureAddressInfo info{ VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO,
                                                         nullptr,
                                                         memory_wrapper->handle };

            uint64_t address = 0;
            if (device_wrapper->physical_device->instance_api_version >= VK_MAKE_VERSION(1, 2, 0))
            {
                address = vulkan_wrappers::GetDeviceTable(device)->GetDeviceMemoryOpaqueCaptureAddress(device_unwrapped,
                                                                                                       &info);
            }
            else
            {
                address = vulkan_wrappers::GetDeviceTable(device)->GetDeviceMemoryOpaqueCaptureAddressKHR(
                    device_unwrapped, &info);
            }

            WriteSetOpaqueAddressCommand(device_wrapper->handle_id, memory_wrapper->handle_id, address);

            if (IsCaptureModeTrack())
            {
                state_tracker_->TrackDeviceMemoryDeviceAddress(device, *pMemory, address);
            }
        }

        memory_wrapper->external_allocation = external_memory;

        if (!IsCaptureModeTrack())
        {
            // The state tracker will set this value when it is enabled. When state tracking is disabled it is set
            // here to ensure it is available for mapped memory tracking.
            memory_wrapper->allocation_size = pAllocateInfo->allocationSize;
        }

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        if ((import_ahb_info != nullptr) && (import_ahb_info->buffer != nullptr))
        {
            ProcessImportAndroidHardwareBuffer(device, *pMemory, import_ahb_info->buffer);
        }
#endif
    }
    else if (external_memory != nullptr)
    {
        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        size_t external_memory_size = manager->GetAlignedSize(static_cast<size_t>(pAllocateInfo->allocationSize));
        manager->FreeMemory(external_memory, external_memory_size);
    }

    return result;
}

VkResult VulkanCaptureManager::OverrideGetPhysicalDeviceToolPropertiesEXT(
    VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolPropertiesEXT* pToolProperties)
{
    auto original_pToolProperties = pToolProperties;
    if (pToolProperties != nullptr)
    {
        pToolProperties->sType    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT;
        pToolProperties->pNext    = nullptr;
        pToolProperties->purposes = VK_TOOL_PURPOSE_TRACING_BIT_EXT;

        util::platform::StringCopy(pToolProperties->name,
                                   VK_MAX_EXTENSION_NAME_SIZE,
                                   GFXRECON_PROJECT_NAME,
                                   util::platform::StringLength(GFXRECON_PROJECT_NAME));

        util::platform::StringCopy(pToolProperties->version,
                                   VK_MAX_EXTENSION_NAME_SIZE,
                                   GFXRECON_PROJECT_VERSION_STRING,
                                   util::platform::StringLength(GFXRECON_PROJECT_VERSION_STRING));

        util::platform::StringCopy(pToolProperties->description,
                                   VK_MAX_DESCRIPTION_SIZE,
                                   GFXRECON_PROJECT_DESCRIPTION,
                                   util::platform::StringLength(GFXRECON_PROJECT_DESCRIPTION));

        util::platform::StringCopy(pToolProperties->layer,
                                   VK_MAX_EXTENSION_NAME_SIZE,
                                   GFXRECON_PROJECT_VULKAN_LAYER_NAME,
                                   util::platform::StringLength(GFXRECON_PROJECT_VULKAN_LAYER_NAME));

        if (pToolCount != nullptr)
        {
            pToolProperties = ((*pToolCount > 1) ? &pToolProperties[1] : nullptr);
            --(*pToolCount);
        }
    }

    VkResult result = vulkan_wrappers::GetInstanceTable(physicalDevice)
                          ->GetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);

    if (original_pToolProperties != nullptr)
    {
        pToolProperties = original_pToolProperties;
    }

    if (pToolCount != nullptr)
    {
        ++(*pToolCount);
    }

    return result;
}

VkResult
VulkanCaptureManager::OverrideCreateRayTracingPipelinesKHR(VkDevice                                 device,
                                                           VkDeferredOperationKHR                   deferredOperation,
                                                           VkPipelineCache                          pipelineCache,
                                                           uint32_t                                 createInfoCount,
                                                           const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
                                                           const VkAllocationCallbacks*             pAllocator,
                                                           VkPipeline*                              pPipelines)
{
    auto                     device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    const VulkanDeviceTable* device_table   = vulkan_wrappers::GetDeviceTable(device);
    auto                     deferred_operation_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::DeferredOperationKHRWrapper>(deferredOperation);

    HandleUnwrapMemory* handle_unwrap_memory = nullptr;

    if (deferred_operation_wrapper)
    {
        handle_unwrap_memory = &deferred_operation_wrapper->handle_unwrap_memory;
        if (pAllocator)
        {
            deferred_operation_wrapper->allocator   = *pAllocator;
            deferred_operation_wrapper->p_allocator = &deferred_operation_wrapper->allocator;
        }
        else
        {
            deferred_operation_wrapper->allocator   = {};
            deferred_operation_wrapper->p_allocator = nullptr;
        }
        deferred_operation_wrapper->create_infos.resize(createInfoCount);
        deferred_operation_wrapper->pipelines.resize(createInfoCount);
        deferred_operation_wrapper->pPipelines    = pPipelines;
        deferred_operation_wrapper->pipelineCache = pipelineCache;
    }
    else
    {
        handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    }
    const VkRayTracingPipelineCreateInfoKHR* pCreateInfos_unwrapped =
        vulkan_wrappers::UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

    VkResult result;
    if (device_wrapper->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
    {
        auto modified_create_infos = std::make_unique<VkRayTracingPipelineCreateInfoKHR[]>(createInfoCount);
        for (uint32_t i = 0; i < createInfoCount; ++i)
        {
            modified_create_infos[i] = pCreateInfos_unwrapped[i];
            modified_create_infos[i].flags |= VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR;
        }
        if (deferred_operation_wrapper)
        {
            deferred_operation_wrapper->create_infos.clear();
            deferred_operation_wrapper->create_infos.insert(deferred_operation_wrapper->create_infos.end(),
                                                            &modified_create_infos.get()[0],
                                                            &modified_create_infos.get()[createInfoCount]);
            result = device_table->CreateRayTracingPipelinesKHR(device,
                                                                deferredOperation,
                                                                pipelineCache,
                                                                createInfoCount,
                                                                deferred_operation_wrapper->create_infos.data(),
                                                                deferred_operation_wrapper->p_allocator,
                                                                deferred_operation_wrapper->pipelines.data());

            if ((result == VK_OPERATION_NOT_DEFERRED_KHR) || (result == VK_SUCCESS))
            {
                // VK_OPERATION_NOT_DEFERRED_KHR means the operation successfully completed immediately, so here we copy
                // the created pipelines to original array which is used to store them by target application.
                //
                // Note:
                //       VK_OPERATION_DEFERRED_KHR means the operation is successfully deferred, but the pipeline
                //       creation might not be finished. We must therefore lean on
                //       vkDeferredOperationJoinKHR/vkGetDeferredOperationResultKHR to get the final result. If the
                //       result indicated the operation has finished, then the created pipelines are ready for use.
                //
                //       By Vulkan doc of VK_KHR_deferred_host_operations, if deferred operation object was
                //       provided and the operation successfully completed immediately without deferring, the
                //       command return VK_OPERATION_NOT_DEFERRED_KHR. Some hardware/driver may return VK_SUCCESS on
                //       such case, so same handling is proceeded with VK_SUCCESS.
                //
                std::memcpy(
                    pPipelines, deferred_operation_wrapper->pipelines.data(), sizeof(VkPipeline) * createInfoCount);
            }
            else if (result == VK_OPERATION_DEFERRED_KHR)
            {
                const std::lock_guard<std::mutex> lock(deferred_operation_mutex);
                deferred_operation_wrapper->pending_state = true;
            }
        }
        else
        {
            result = device_table->CreateRayTracingPipelinesKHR(device,
                                                                deferredOperation,
                                                                pipelineCache,
                                                                createInfoCount,
                                                                modified_create_infos.get(),
                                                                pAllocator,
                                                                pPipelines);
        }
    }
    else
    {
        GFXRECON_LOG_ERROR_ONCE(
            "The capturing application used vkCreateRayTracingPipelinesKHR, which may require the "
            "rayTracingPipelineShaderGroupHandleCaptureReplay feature for accurate capture and replay. The capturing "
            "device does not support this feature, so replay may fail.");

        if (deferred_operation_wrapper)
        {
            deferred_operation_wrapper->create_infos.clear();
            deferred_operation_wrapper->create_infos.insert(deferred_operation_wrapper->create_infos.end(),
                                                            &pCreateInfos_unwrapped[0],
                                                            &pCreateInfos_unwrapped[createInfoCount]);
            result = device_table->CreateRayTracingPipelinesKHR(device,
                                                                deferredOperation,
                                                                pipelineCache,
                                                                createInfoCount,
                                                                deferred_operation_wrapper->create_infos.data(),
                                                                deferred_operation_wrapper->p_allocator,
                                                                deferred_operation_wrapper->pipelines.data());
            if ((result == VK_OPERATION_NOT_DEFERRED_KHR) || (result == VK_SUCCESS))
            {
                // If the driver doesn't defer the command, and instead completed the operation immediately, we copy the
                // created pipelines to original array which is used to store them by target application.
                std::memcpy(
                    pPipelines, deferred_operation_wrapper->pipelines.data(), sizeof(VkPipeline) * createInfoCount);
            }
            else if (result == VK_OPERATION_DEFERRED_KHR)
            {
                const std::lock_guard<std::mutex> lock(deferred_operation_mutex);
                deferred_operation_wrapper->pending_state = true;
            }
        }
        else
        {
            result = device_table->CreateRayTracingPipelinesKHR(device,
                                                                deferredOperation,
                                                                pipelineCache,
                                                                createInfoCount,
                                                                pCreateInfos_unwrapped,
                                                                pAllocator,
                                                                pPipelines);
        }
    }

    if (((result == VK_SUCCESS) || (result == VK_OPERATION_NOT_DEFERRED_KHR)) && (pPipelines != nullptr))
    {
        // If the return result show the creation is successfully finished, we do the following process.

        vulkan_wrappers::CreateWrappedHandles<vulkan_wrappers::DeviceWrapper,
                                              vulkan_wrappers::DeferredOperationKHRWrapper,
                                              vulkan_wrappers::PipelineWrapper>(
            device, deferredOperation, pPipelines, createInfoCount, GetUniqueId);

        for (uint32_t i = 0; i < createInfoCount; ++i)
        {
            auto pipeline_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(pPipelines[i]);

            if (deferred_operation_wrapper)
            {
                // We need to set device_id here because some hardware may not have the feature
                // rayTracingPipelineShaderGroupHandleCaptureReplay so the device_id cannot be set by
                // VulkanStateTracker::TrackRayTracingShaderGroupHandles
                pipeline_wrapper->device_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
                pipeline_wrapper->deferred_operation.handle_id         = deferred_operation_wrapper->handle_id;
                pipeline_wrapper->deferred_operation.create_call_id    = deferred_operation_wrapper->create_call_id;
                pipeline_wrapper->deferred_operation.create_parameters = deferred_operation_wrapper->create_parameters;
            }
            if (device_wrapper->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
            {
                uint32_t data_size = device_wrapper->property_feature_info.property_shaderGroupHandleCaptureReplaySize *
                                     pCreateInfos[i].groupCount;
                std::vector<uint8_t> data(data_size);

                result = device_table->GetRayTracingCaptureReplayShaderGroupHandlesKHR(
                    device, pipeline_wrapper->handle, 0, pCreateInfos[i].groupCount, data_size, data.data());

                if (result == VK_SUCCESS)
                {
                    WriteSetRayTracingShaderGroupHandlesCommand(
                        device_wrapper->handle_id, pipeline_wrapper->handle_id, data_size, data.data());

                    if (IsCaptureModeTrack())
                    {
                        state_tracker_->TrackRayTracingShaderGroupHandles(
                            device, pPipelines[i], data_size, data.data());
                    }
                }
            }
        }
    }

    return result;
}

void VulkanCaptureManager::DeferredOperationPostProcess(VkDevice               device,
                                                        VkDeferredOperationKHR deferredOperation,
                                                        bool                   capture_manager_tracking)
{
    const std::lock_guard<std::mutex> lock(deferred_operation_mutex);
    VkResult                          result = VK_SUCCESS;
    auto                              deferred_operation_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::DeferredOperationKHRWrapper>(deferredOperation);
    auto                     device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    const VulkanDeviceTable* device_table   = vulkan_wrappers::GetDeviceTable(device);

    GFXRECON_ASSERT(device_table != nullptr);

    if ((deferred_operation_wrapper != nullptr) && (deferred_operation_wrapper->pending_state))
    {
        deferred_operation_wrapper->pending_state = false;
        uint32_t create_info_count                = deferred_operation_wrapper->create_infos.size();
        std::memcpy(deferred_operation_wrapper->pPipelines,
                    deferred_operation_wrapper->pipelines.data(),
                    sizeof(VkPipeline) * deferred_operation_wrapper->create_infos.size());

        vulkan_wrappers::CreateWrappedHandles<vulkan_wrappers::DeviceWrapper,
                                              vulkan_wrappers::DeferredOperationKHRWrapper,
                                              vulkan_wrappers::PipelineWrapper>(
            device, deferredOperation, deferred_operation_wrapper->pPipelines, create_info_count, GetUniqueId);

        for (uint32_t i = 0; i < create_info_count; ++i)
        {
            auto pipeline_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(
                deferred_operation_wrapper->pPipelines[i]);

            if (deferred_operation_wrapper)
            {
                // We need to set device_id here because some hardware may not have the feature
                // rayTracingPipelineShaderGroupHandleCaptureReplay so the device_id cannot be set by
                // VulkanStateTracker::TrackRayTracingShaderGroupHandles
                pipeline_wrapper->device_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
                pipeline_wrapper->deferred_operation.handle_id         = deferred_operation_wrapper->handle_id;
                pipeline_wrapper->deferred_operation.create_call_id    = deferred_operation_wrapper->create_call_id;
                pipeline_wrapper->deferred_operation.create_parameters = deferred_operation_wrapper->create_parameters;
            }

            if (device_wrapper->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
            {
                const uint32_t data_size =
                    device_wrapper->property_feature_info.property_shaderGroupHandleCaptureReplaySize *
                    deferred_operation_wrapper->create_infos[i].groupCount;

                std::vector<uint8_t> data(data_size);
                result = device_table->GetRayTracingCaptureReplayShaderGroupHandlesKHR(
                    device_wrapper->handle,
                    pipeline_wrapper->handle,
                    0,
                    deferred_operation_wrapper->create_infos[i].groupCount,
                    data_size,
                    data.data());

                if (result == VK_SUCCESS)
                {
                    WriteSetRayTracingShaderGroupHandlesCommand(
                        device_wrapper->handle_id, pipeline_wrapper->handle_id, data_size, data.data());

                    if (capture_manager_tracking == true)
                    {
                        state_tracker_->TrackRayTracingShaderGroupHandles(
                            device, deferred_operation_wrapper->pPipelines[i], data_size, data.data());
                    }
                }
            }
        }

        // When the command vkCreateRayTracingPipelinesKHR is deferred at capture time, the created pipelines might not
        // be ready on the return of the API call, because the pipeline creation workload might not be finished. But for
        // replay time, we must guarantee the data relevant to vkGetRayTracingCaptureReplayShaderGroupHandlesKHR is
        // ready before calling vkCreateRaytracingPipelines so shader group handles during playback are the same with
        // capture time. The special handling needed here that when the command vkCreateRayTracingPipelinesKHR is
        // deferred, the writing of its block will be delayed writing to file, until it is confirmed that the deferred
        // command is finished.
        auto encoder = BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR);

        if (encoder)
        {
            encoder->EncodeVulkanHandleValue<vulkan_wrappers::DeviceWrapper>(device);
            encoder->EncodeVulkanHandleValue<vulkan_wrappers::DeferredOperationKHRWrapper>(deferredOperation);
            encoder->EncodeVulkanHandleValue<vulkan_wrappers::PipelineCacheWrapper>(
                deferred_operation_wrapper->pipelineCache);
            encoder->EncodeUInt32Value(create_info_count);
            EncodeStructArray(encoder, deferred_operation_wrapper->create_infos.data(), create_info_count);
            EncodeStructPtr(encoder, deferred_operation_wrapper->p_allocator);
            encoder->EncodeVulkanHandleArray<vulkan_wrappers::PipelineWrapper>(
                deferred_operation_wrapper->pPipelines, create_info_count, false);
            encoder->EncodeEnumValue(VK_OPERATION_DEFERRED_KHR);
            EndGroupCreateApiCallCapture<VkDevice,
                                         VkDeferredOperationKHR,
                                         vulkan_wrappers::PipelineWrapper,
                                         VkRayTracingPipelineCreateInfoKHR>(
                result,
                device,
                deferredOperation,
                create_info_count,
                deferred_operation_wrapper->pPipelines,
                deferred_operation_wrapper->create_infos.data());
        }
    }
}

VkResult VulkanCaptureManager::OverrideDeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation)
{
    auto device_table = vulkan_wrappers::GetDeviceTable(device);
    GFXRECON_ASSERT(device_table != nullptr);
    VkResult result = device_table->DeferredOperationJoinKHR(device, operation);

    if (result == VK_SUCCESS)
    {
        // The deferred operation done and we continue to get the deferred command return value.
        VkResult deferred_command_result = device_table->GetDeferredOperationResultKHR(device, operation);

        if ((deferred_command_result == VK_SUCCESS) || (deferred_command_result == VK_OPERATION_NOT_DEFERRED_KHR))
        {
            DeferredOperationPostProcess(device, operation, IsCaptureModeTrack());
        }
    }

    return result;
}

VkResult VulkanCaptureManager::OverrideGetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation)
{
    auto device_table = vulkan_wrappers::GetDeviceTable(device);
    GFXRECON_ASSERT(device_table != nullptr);
    VkResult result = device_table->GetDeferredOperationResultKHR(device, operation);

    if ((result == VK_SUCCESS) || (result == VK_OPERATION_NOT_DEFERRED_KHR))
    {
        // There are the following two cases with VK_SUCCESS for vkGetDeferredOperationResultKHR. Both are covered by
        // DeferredOperationPostProcess. We also provide same handling for VK_OPERATION_NOT_DEFERRED_KHR in case some
        // hardware/driver return VK_OPERATION_NOT_DEFERRED_KHR:
        //    1. The deferred operation finished and returned VK_SUCCESS.
        //    2. No command has been deferred on the deferred operation object.
        DeferredOperationPostProcess(device, operation, IsCaptureModeTrack());
    }

    return result;
}

void VulkanCaptureManager::OverrideGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice         physicalDevice,
    uint32_t*                pQueueFamilyPropertyCount,
    VkQueueFamilyProperties* pQueueFamilyProperties)
{
    GFXRECON_ASSERT(pQueueFamilyPropertyCount != nullptr);

    vulkan_wrappers::GetInstanceTable(physicalDevice)
        ->GetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    if (GetQueueZeroOnly())
    {
        *pQueueFamilyPropertyCount = 1;
        if (pQueueFamilyProperties != nullptr)
        {
            pQueueFamilyProperties[0].queueCount = 1;
        }
    }
}

void VulkanCaptureManager::OverrideGetPhysicalDeviceQueueFamilyProperties2(
    VkPhysicalDevice          physicalDevice,
    uint32_t*                 pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2* pQueueFamilyProperties)
{
    GFXRECON_ASSERT(pQueueFamilyPropertyCount != nullptr);

    vulkan_wrappers::GetInstanceTable(physicalDevice)
        ->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    if (GetQueueZeroOnly())
    {
        *pQueueFamilyPropertyCount = 1;
        if (pQueueFamilyProperties != nullptr)
        {
            pQueueFamilyProperties[0].queueFamilyProperties.queueCount = 1;
        }
    }
}

void VulkanCaptureManager::OverrideGetPhysicalDeviceQueueFamilyProperties2KHR(
    VkPhysicalDevice          physicalDevice,
    uint32_t*                 pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2* pQueueFamilyProperties)
{
    GFXRECON_ASSERT(pQueueFamilyPropertyCount != nullptr);

    vulkan_wrappers::GetInstanceTable(physicalDevice)
        ->GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    if (GetQueueZeroOnly())
    {
        *pQueueFamilyPropertyCount = 1;
        if (pQueueFamilyProperties != nullptr)
        {
            pQueueFamilyProperties[0].queueFamilyProperties.queueCount = 1;
        }
    }
}

void VulkanCaptureManager::ProcessEnumeratePhysicalDevices(VkResult          result,
                                                           VkInstance        instance,
                                                           uint32_t          count,
                                                           VkPhysicalDevice* devices)
{
    assert(devices != nullptr);

    auto instance_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::InstanceWrapper>(instance);
    assert(instance_wrapper != nullptr);

    // Write meta-data describing physical device properties on first call to vkEnumeratePhysicalDevices or
    // vkEnumeratePhysicalDeviceGroups.
    if (!instance_wrapper->have_device_properties)
    {
        // Only filter duplicate checks when we have a complete list of physical devices.
        if (result != VK_INCOMPLETE)
        {
            instance_wrapper->have_device_properties = true;
        }

        for (uint32_t i = 0; i < count; ++i)
        {
            VkPhysicalDevice physical_device = devices[i];

            if (physical_device != VK_NULL_HANDLE)
            {
                const VulkanInstanceTable* instance_table = vulkan_wrappers::GetInstanceTable(physical_device);
                assert(instance_table != nullptr);

                auto physical_device_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device);
                format::HandleId physical_device_id     = physical_device_wrapper->handle_id;
                VkPhysicalDevice physical_device_handle = physical_device_wrapper->handle;
                uint32_t         count                  = 0;

                VkPhysicalDeviceProperties       properties;
                VkPhysicalDeviceMemoryProperties memory_properties;

                instance_table->GetPhysicalDeviceProperties(physical_device_handle, &properties);
                instance_table->GetPhysicalDeviceMemoryProperties(physical_device_handle, &memory_properties);

                if (IsCaptureModeTrack())
                {
                    // Let the state tracker process the memory properties.
                    assert(state_tracker_ != nullptr);
                    state_tracker_->TrackPhysicalDeviceMemoryProperties(physical_device, &memory_properties);
                }
                else
                {
                    // When not tracking state, set the memory types directly.
                    physical_device_wrapper->memory_properties = std::move(memory_properties);
                }

                physical_device_wrapper->instance_api_version = instance_wrapper->api_version;

                WriteSetDevicePropertiesCommand(physical_device_id, properties);
                WriteSetDeviceMemoryPropertiesCommand(physical_device_id, physical_device_wrapper->memory_properties);
            }
        }
    }
}

VkMemoryPropertyFlags VulkanCaptureManager::GetMemoryProperties(vulkan_wrappers::DeviceWrapper* device_wrapper,
                                                                uint32_t                        memory_type_index)
{
    vulkan_wrappers::PhysicalDeviceWrapper* physical_device_wrapper = device_wrapper->physical_device;
    const VkPhysicalDeviceMemoryProperties* memory_properties       = &physical_device_wrapper->memory_properties;

    assert(memory_type_index < memory_properties->memoryTypeCount);

    return memory_properties->memoryTypes[memory_type_index].propertyFlags;
}

const VkImportAndroidHardwareBufferInfoANDROID*
VulkanCaptureManager::FindAllocateMemoryExtensions(const VkMemoryAllocateInfo* allocate_info)
{
    const VkImportAndroidHardwareBufferInfoANDROID* import_ahb_info = nullptr;

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    assert(allocate_info != nullptr);

    const VkBaseInStructure* pnext = reinterpret_cast<const VkBaseInStructure*>(allocate_info->pNext);
    while (pnext != nullptr)
    {
        if (pnext->sType == VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID)
        {
            import_ahb_info = reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(pnext);
            break;
        }

        pnext = pnext->pNext;
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(allocate_info);
#endif

    return import_ahb_info;
}

void VulkanCaptureManager::ProcessReferenceToAndroidHardwareBuffer(VkDevice device, AHardwareBuffer* hardware_buffer)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    assert(hardware_buffer != nullptr);
    auto     device_wrapper   = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    VkDevice device_unwrapped = device_wrapper->handle;
    auto     device_table     = vulkan_wrappers::GetDeviceTable(device);

    auto entry = hardware_buffers_.find(hardware_buffer);
    if (entry == hardware_buffers_.end())
    {
        // If this is the first device memory object to reference the hardware buffer, write a buffer creation
        // command to the capture file and setup memory tracking.

        std::vector<format::HardwareBufferPlaneInfo> plane_info;

        AHardwareBuffer_Desc desc;
        AHardwareBuffer_describe(hardware_buffer, &desc);

        if ((desc.usage & AHARDWAREBUFFER_USAGE_CPU_READ_MASK) != 0)
        {
            void* data   = nullptr;
            int   result = -1;

            // The multi-plane functions are declared for API 26, but are only available to link with API 29.  So, this
            // could be turned into a run-time check dependent on dlsym returning a valid pointer for
            // AHardwareBuffer_lockPlanes.
#if __ANDROID_API__ >= 29
            AHardwareBuffer_Planes ahb_planes;
            result = AHardwareBuffer_lockPlanes(
                hardware_buffer, AHARDWAREBUFFER_USAGE_CPU_READ_OFTEN, -1, nullptr, &ahb_planes);
            if (result == 0)
            {
                data = ahb_planes.planes[0].data;

                for (uint32_t i = 0; i < ahb_planes.planeCount; ++i)
                {
                    format::HardwareBufferPlaneInfo ahb_plane_info;
                    ahb_plane_info.offset =
                        reinterpret_cast<uint8_t*>(ahb_planes.planes[i].data) - reinterpret_cast<uint8_t*>(data);
                    ahb_plane_info.pixel_stride = ahb_planes.planes[i].pixelStride;
                    ahb_plane_info.row_pitch    = ahb_planes.planes[i].rowStride;
                    plane_info.emplace_back(std::move(ahb_plane_info));
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("AHardwareBuffer_lockPlanes failed: AHardwareBuffer_lock will be used instead");
            }
#endif

            // Only store buffer IDs and reference count if a creation command is written to the capture file.
            format::HandleId memory_id = GetUniqueId();

            HardwareBufferInfo& ahb_info = hardware_buffers_[hardware_buffer];
            ahb_info.memory_id           = memory_id;
            ahb_info.reference_count     = 0;

            // Write CreateHardwareBufferCmd with or without the AHB payload
            WriteCreateHardwareBufferCmd(memory_id, hardware_buffer, plane_info);

            // Query the AHB size
            VkAndroidHardwareBufferPropertiesANDROID properties = {
                VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID
            };
            properties.pNext = nullptr;

            VkResult vk_result =
                device_table->GetAndroidHardwareBufferPropertiesANDROID(device_unwrapped, hardware_buffer, &properties);

            if (vk_result == VK_SUCCESS)
            {
                const size_t ahb_size = properties.allocationSize;
                assert(ahb_size);

                // If AHardwareBuffer_lockPlanes() failed (or is not available) try AHardwareBuffer_lock()
                if (result != 0)
                {
                    result =
                        AHardwareBuffer_lock(hardware_buffer, AHARDWAREBUFFER_USAGE_CPU_READ_OFTEN, -1, nullptr, &data);
                }

                if (result == 0 && data != nullptr)
                {
                    WriteFillMemoryCmd(memory_id, 0, ahb_size, data);

                    // Track the memory with the PageGuardManager
                    if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
                         GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
                        GetPageGuardTrackAhbMemory())
                    {
                        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, ahb_size);

                        util::PageGuardManager* manager = util::PageGuardManager::Get();
                        assert(manager != nullptr);

                        manager->AddTrackedMemory(memory_id,
                                                  data,
                                                  0,
                                                  static_cast<size_t>(ahb_size),
                                                  util::PageGuardManager::kNullShadowHandle,
                                                  false,  // No shadow memory for the imported AHB memory.
                                                  false); // Write watch is not supported for this case.
                    }

                    result = AHardwareBuffer_unlock(hardware_buffer, nullptr);
                    if (result != 0)
                    {
                        GFXRECON_LOG_ERROR("AHardwareBuffer_unlock failed");
                    }
                }
                else
                {
                    GFXRECON_LOG_ERROR(
                        "AHardwareBuffer_lock failed: hardware buffer data will be omitted from the capture file");

                    // Dump zeros for AHB payload.
                    std::vector<uint8_t> zeros(ahb_size, 0);
                    WriteFillMemoryCmd(memory_id, 0, ahb_size, zeros.data());
                }
            }
            else
            {
                GFXRECON_LOG_ERROR(
                    "GetAndroidHardwareBufferPropertiesANDROID failed: hardware buffer data will be omitted "
                    "from the capture file");

                // In case AHardwareBuffer_lockPlanes() succeeded
                if (result == 0)
                {
                    result = AHardwareBuffer_unlock(hardware_buffer, nullptr);
                    if (result != 0)
                    {
                        GFXRECON_LOG_ERROR("AHardwareBuffer_unlock failed");
                    }
                }
            }
        }
        else
        {
            // The AHB is not CPU-readable, so store only the creation command.
            // Only store buffer IDs and reference count if a creation command is written to the capture file.
            format::HandleId memory_id = GetUniqueId();

            HardwareBufferInfo& ahb_info = hardware_buffers_[hardware_buffer];
            ahb_info.memory_id           = memory_id;
            ahb_info.reference_count     = 0;

            WriteCreateHardwareBufferCmd(memory_id, hardware_buffer, plane_info);
        }
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
#endif
}

void VulkanCaptureManager::ProcessImportAndroidHardwareBuffer(VkDevice         device,
                                                              VkDeviceMemory   memory,
                                                              AHardwareBuffer* hardware_buffer)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    GFXRECON_UNREFERENCED_PARAMETER(device);

    auto memory_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    assert((memory_wrapper != nullptr) && (hardware_buffer != nullptr));

    ProcessReferenceToAndroidHardwareBuffer(device, hardware_buffer);
    auto entry = hardware_buffers_.find(hardware_buffer);
    GFXRECON_ASSERT(entry != hardware_buffers_.end());

    ++entry->second.reference_count;

    memory_wrapper->hardware_buffer           = hardware_buffer;
    memory_wrapper->hardware_buffer_memory_id = entry->second.memory_id;
#else
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(memory);
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
#endif
}

void VulkanCaptureManager::ReleaseAndroidHardwareBuffer(AHardwareBuffer* hardware_buffer)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    assert(hardware_buffer != nullptr);

    auto entry = hardware_buffers_.find(hardware_buffer);
    if ((entry != hardware_buffers_.end()) && (--entry->second.reference_count == 0))
    {
        if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
            GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            manager->RemoveTrackedMemory(entry->second.memory_id);
        }

        // There are no more references to the buffer, so we can submit a destroy buffer command.
        WriteDestroyHardwareBufferCmd(entry->first);
        hardware_buffers_.erase(entry);
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
#endif
}

void VulkanCaptureManager::PostProcess_vkEnumeratePhysicalDevices(VkResult          result,
                                                                  VkInstance        instance,
                                                                  uint32_t*         pPhysicalDeviceCount,
                                                                  VkPhysicalDevice* pPhysicalDevices)
{
    if ((result >= 0) && (pPhysicalDeviceCount != nullptr) && (pPhysicalDevices != nullptr))
    {
        ProcessEnumeratePhysicalDevices(result, instance, *pPhysicalDeviceCount, pPhysicalDevices);
    }
}

void VulkanCaptureManager::PostProcess_vkEnumeratePhysicalDeviceGroups(
    VkResult                         result,
    VkInstance                       instance,
    uint32_t*                        pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties)
{
    if ((result >= 0) && (pPhysicalDeviceGroupCount != nullptr) && (pPhysicalDeviceGroupProperties != nullptr))
    {
        std::unordered_set<VkPhysicalDevice> unique_handles;
        uint32_t                             count = *pPhysicalDeviceGroupCount;

        // Build a list of retrieved physical device handles, filtering duplicates.
        for (uint32_t i = 0; i < count; ++i)
        {
            for (uint32_t j = 0; j < pPhysicalDeviceGroupProperties[i].physicalDeviceCount; ++j)
            {
                unique_handles.insert(pPhysicalDeviceGroupProperties[i].physicalDevices[j]);
            }
        }

        std::vector<VkPhysicalDevice> devices(unique_handles.begin(), unique_handles.end());

        ProcessEnumeratePhysicalDevices(result, instance, static_cast<uint32_t>(devices.size()), devices.data());
    }
}

void VulkanCaptureManager::PreProcess_vkCreateXlibSurfaceKHR(VkInstance                        instance,
                                                             const VkXlibSurfaceCreateInfoKHR* pCreateInfo,
                                                             const VkAllocationCallbacks*      pAllocator,
                                                             VkSurfaceKHR*                     pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSurface);

#if defined(VK_USE_PLATFORM_XLIB_KHR)
    assert(pCreateInfo != nullptr);
    if (pCreateInfo && !GetTrimKey().empty())
    {
        if (!GetKeyboard().Initialize(pCreateInfo->dpy))
        {
            GFXRECON_LOG_ERROR("Failed to initialize Xlib keyboard capture trigger");
        }
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    if (!GetTrimKey().empty())
    {
        GFXRECON_LOG_WARNING("Xlib keyboard capture trigger is not enabled on this system");
    }
#endif
}

void VulkanCaptureManager::PreProcess_vkCreateXcbSurfaceKHR(VkInstance                       instance,
                                                            const VkXcbSurfaceCreateInfoKHR* pCreateInfo,
                                                            const VkAllocationCallbacks*     pAllocator,
                                                            VkSurfaceKHR*                    pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSurface);

#if defined(VK_USE_PLATFORM_XCB_KHR)
    assert(pCreateInfo != nullptr);
    if (pCreateInfo && !GetTrimKey().empty())
    {
        if (!GetKeyboard().Initialize(pCreateInfo->connection))
        {
            GFXRECON_LOG_ERROR("Failed to initialize XCB keyboard capture trigger");
        }
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    if (!GetTrimKey().empty())
    {
        GFXRECON_LOG_WARNING("Xcb keyboard capture trigger is not enabled on this system");
    }
#endif
}

void VulkanCaptureManager::PreProcess_vkCreateWaylandSurfaceKHR(VkInstance                           instance,
                                                                const VkWaylandSurfaceCreateInfoKHR* pCreateInfo,
                                                                const VkAllocationCallbacks*         pAllocator,
                                                                VkSurfaceKHR*                        pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSurface);
    if (!GetTrimKey().empty())
    {
        GFXRECON_LOG_WARNING("Wayland keyboard capture trigger is not implemented");
    }
}

void VulkanCaptureManager::PreProcess_vkCreateSwapchain(VkDevice                        device,
                                                        const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                        const VkAllocationCallbacks*    pAllocator,
                                                        VkSwapchainKHR*                 pSwapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSwapchain);

    assert(pCreateInfo != nullptr);

    if (pCreateInfo)
    {
        WriteResizeWindowCmd2(vulkan_wrappers::GetWrappedId<vulkan_wrappers::SurfaceKHRWrapper>(pCreateInfo->surface),
                              pCreateInfo->imageExtent.width,
                              pCreateInfo->imageExtent.height,
                              pCreateInfo->preTransform);
    }
}

void VulkanCaptureManager::PostProcess_vkMapMemory(VkResult         result,
                                                   VkDevice         device,
                                                   VkDeviceMemory   memory,
                                                   VkDeviceSize     offset,
                                                   VkDeviceSize     size,
                                                   VkMemoryMapFlags flags,
                                                   void**           ppData)
{
    if ((result == VK_SUCCESS) && (ppData != nullptr))
    {
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
        assert(wrapper != nullptr);

        if (wrapper->mapped_data == nullptr)
        {
            wrapper->mapped_data   = (*ppData);
            wrapper->mapped_offset = offset;
            wrapper->mapped_size   = size;
            wrapper->mapped_flags  = flags;

            if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
                GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
                    // Hardware buffer memory is tracked separately, so VkDeviceMemory mappings should be ignored to
                    // avoid duplicate memory tracking entries.
                    && (wrapper->hardware_buffer == nullptr)
#endif
            )
            {
                if (size == VK_WHOLE_SIZE)
                {
                    assert(offset <= wrapper->allocation_size);
                    size = wrapper->allocation_size - offset;
                }

                if (size > 0)
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, offset);
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

                    util::PageGuardManager* manager = util::PageGuardManager::Get();
                    assert(manager != nullptr);

                    bool use_shadow_memory = true;
                    bool use_write_watch   = false;

                    if (IsPageGuardMemoryModeExternal())
                    {
                        use_shadow_memory = false;
                        use_write_watch   = true;
                    }
                    else if (IsPageGuardMemoryModeShadowPersistent() &&
                             (wrapper->shadow_allocation == util::PageGuardManager::kNullShadowHandle))
                    {
                        wrapper->shadow_allocation = manager->AllocatePersistentShadowMemory(static_cast<size_t>(size));
                    }

                    // Return the pointer provided by the pageguard manager, which may be a pointer to shadow memory,
                    // not the mapped memory.
                    (*ppData) = manager->AddTrackedMemory(wrapper->handle_id,
                                                          (*ppData),
                                                          static_cast<size_t>(offset),
                                                          static_cast<size_t>(size),
                                                          wrapper->shadow_allocation,
                                                          use_shadow_memory,
                                                          use_write_watch);
                }
            }
            else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
            {
                // Need to keep track of mapped memory objects so memory content can be written at queue submit.
                std::lock_guard<std::mutex> lock(GetMappedMemoryLock());
                mapped_memory_.insert(wrapper);
            }
        }
        else
        {
            // The application has mapped the same VkDeviceMemory object more than once and the pageguard
            // manager is already tracking it, so we will return the pointer obtained from the pageguard manager
            // on the first map call.
            GFXRECON_LOG_WARNING("VkDeviceMemory object with handle = %" PRIx64 " has been mapped more than once",
                                 memory);

            if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
                GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
            {
                assert((wrapper->mapped_offset == offset) && (wrapper->mapped_size == size));

                // Return the shadow memory that was allocated for the previous map operation.
                util::PageGuardManager* manager = util::PageGuardManager::Get();
                assert(manager != nullptr);

                if (!manager->GetTrackedMemory(wrapper->handle_id, ppData))
                {
                    GFXRECON_LOG_ERROR("Modifications to the VkDeviceMemory object that has been mapped more than once "
                                       "are not being track by PageGuardManager");
                }
            }
        }
    }
}

void VulkanCaptureManager::PreProcess_vkFlushMappedMemoryRanges(VkDevice                   device,
                                                                uint32_t                   memoryRangeCount,
                                                                const VkMappedMemoryRange* pMemoryRanges)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    if (pMemoryRanges != nullptr)
    {
        if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
            GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
        {
            const vulkan_wrappers::DeviceMemoryWrapper* current_memory_wrapper = nullptr;
            util::PageGuardManager*                     manager                = util::PageGuardManager::Get();
            assert(manager != nullptr);

            for (uint32_t i = 0; i < memoryRangeCount; ++i)
            {
                auto next_memory_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(pMemoryRanges[i].memory);

                // Currently processing all dirty pages for the mapped memory, so filter multiple ranges from the same
                // object.
                if (next_memory_wrapper != current_memory_wrapper)
                {
                    current_memory_wrapper = next_memory_wrapper;

                    if ((current_memory_wrapper != nullptr) && (current_memory_wrapper->mapped_data != nullptr))
                    {
                        assert(0);
                        const size_t             page_size = util::platform::GetSystemPageSize();
                        std::map<size_t, size_t> ranges;
                        for (auto& asset : current_memory_wrapper->bound_assets)
                        {
                            assert(asset.second->size);
                            const size_t first_page = asset.second->bind_offset / page_size;
                            const size_t last_page  = (asset.second->bind_offset + asset.second->size - 1) / page_size;
                            assert(first_page <= last_page);

                            auto new_entry = ranges.emplace(first_page, last_page);
                            assert(new_entry.second);
                        }

                        manager->ProcessMemoryEntry(
                            current_memory_wrapper->handle_id,
                            [this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
                                WriteFillMemoryCmd(memory_id, offset, size, start_address);
                            },
                            ranges);
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING("vkFlushMappedMemoryRanges called for memory that is not mapped");
                    }
                }
            }
        }
        else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kAssisted)
        {
            const vulkan_wrappers::DeviceMemoryWrapper* current_memory_wrapper = nullptr;

            for (uint32_t i = 0; i < memoryRangeCount; ++i)
            {
                current_memory_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(pMemoryRanges[i].memory);

                if ((current_memory_wrapper != nullptr) && (current_memory_wrapper->mapped_data != nullptr))
                {
                    assert(pMemoryRanges[i].offset >= current_memory_wrapper->mapped_offset);

                    // The mapped pointer already includes the mapped offset.  Because the memory range
                    // offset is relative to the start of the memory object, we need to adjust it to be
                    // relative to the start of the mapped pointer.
                    VkDeviceSize relative_offset = pMemoryRanges[i].offset - current_memory_wrapper->mapped_offset;
                    VkDeviceSize size            = pMemoryRanges[i].size;
                    if (size == VK_WHOLE_SIZE)
                    {
                        assert(pMemoryRanges[i].offset <= current_memory_wrapper->allocation_size);
                        size = current_memory_wrapper->allocation_size - pMemoryRanges[i].offset;
                    }

                    WriteFillMemoryCmd(
                        current_memory_wrapper->handle_id, relative_offset, size, current_memory_wrapper->mapped_data);
                }
            }
        }
    }
}

void VulkanCaptureManager::PreProcess_vkUnmapMemory(VkDevice device, VkDeviceMemory memory)
{
    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    assert(wrapper != nullptr);

    if (wrapper->mapped_data != nullptr)
    {
        if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
            GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            const size_t             page_size = util::platform::GetSystemPageSize();
            std::map<size_t, size_t> ranges;
            for (auto& asset : wrapper->bound_assets)
            {
                assert(asset.second->size);
                const size_t first_page = asset.second->bind_offset / page_size;
                const size_t last_page  = (asset.second->bind_offset + asset.second->size - 1) / page_size;
                assert(first_page <= last_page);

                auto new_entry = ranges.emplace(first_page, last_page);
                assert(new_entry.second);
            }

            manager->ProcessMemoryEntry(
                wrapper->handle_id,
                [this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
                    WriteFillMemoryCmd(memory_id, offset, size, start_address);
                },
                ranges);

            manager->RemoveTrackedMemory(wrapper->handle_id);
        }
        else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
        {
            VkDeviceSize size = wrapper->mapped_size;
            if (size == VK_WHOLE_SIZE)
            {
                assert(wrapper->mapped_offset <= wrapper->allocation_size);
                size = wrapper->allocation_size - wrapper->mapped_offset;
            }

            // Write the entire mapped region.
            // We set offset to 0, because the pointer returned by vkMapMemory already includes the offset.
            WriteFillMemoryCmd(wrapper->handle_id, 0, size, wrapper->mapped_data);

            {
                std::lock_guard<std::mutex> lock(GetMappedMemoryLock());
                mapped_memory_.erase(wrapper);
            }
        }

        wrapper->mapped_data   = nullptr;
        wrapper->mapped_offset = 0;
        wrapper->mapped_size   = 0;
        wrapper->mapped_flags  = 0;
    }
    else
    {
        GFXRECON_LOG_WARNING(
            "Attempting to unmap VkDeviceMemory object with handle = %" PRIx64 " that has not been mapped", memory);
    }
}

void VulkanCaptureManager::PreProcess_vkFreeMemory(VkDevice                     device,
                                                   VkDeviceMemory               memory,
                                                   const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if (memory != VK_NULL_HANDLE)
    {
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);

        if (wrapper->mapped_data != nullptr)
        {
            if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
                GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
            {
                util::PageGuardManager* manager = util::PageGuardManager::Get();
                assert(manager != nullptr);

                // Remove memory tracking.
                manager->RemoveTrackedMemory(wrapper->handle_id);
            }
            else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
            {
                std::lock_guard<std::mutex> lock(GetMappedMemoryLock());
                mapped_memory_.erase(wrapper);
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkFreeMemory(VkDevice                     device,
                                                    VkDeviceMemory               memory,
                                                    const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if (memory != VK_NULL_HANDLE)
    {
        // Destroy external resources.
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);

        if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
            GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            if ((IsPageGuardMemoryModeExternal()) && (wrapper->external_allocation != nullptr))
            {
                size_t external_memory_size = manager->GetAlignedSize(static_cast<size_t>(wrapper->allocation_size));
                manager->FreeMemory(wrapper->external_allocation, external_memory_size);
            }
            else if (IsPageGuardMemoryModeShadowPersistent() &&
                     (wrapper->shadow_allocation != util::PageGuardManager::kNullShadowHandle))
            {
                manager->FreePersistentShadowMemory(wrapper->shadow_allocation);
            }

            vulkan_wrappers::DeviceWrapper* dev_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
            assert(dev_wrapper != nullptr);
        }

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        if (wrapper->hardware_buffer != nullptr)
        {
            ReleaseAndroidHardwareBuffer(wrapper->hardware_buffer);
        }
#endif
    }
}

void VulkanCaptureManager::PostProcess_vkAcquireFullScreenExclusiveModeEXT(VkResult       result,
                                                                           VkDevice       device,
                                                                           VkSwapchainKHR swapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(swapchain);

    if (IsCaptureModeTrack())
    {
        assert(state_tracker_ != nullptr);
        state_tracker_->TrackAcquireFullScreenExclusiveMode(device, swapchain);
    }
}

void VulkanCaptureManager::PostProcess_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    VkResult                               result,
    VkPhysicalDevice                       physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
    uint32_t*                              pPresentModeCount,
    VkPresentModeKHR*                      pPresentModes)
{
    if ((pPresentModeCount != nullptr) && (pPresentModes != nullptr) && (pSurfaceInfo != nullptr))
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackPhysicalDeviceSurfacePresentModes(
                physicalDevice, pSurfaceInfo->surface, *pPresentModeCount, pPresentModes, pSurfaceInfo->pNext);
        }

#if defined(__ANDROID__)
        OverrideGetPhysicalDeviceSurfacePresentModesKHR(pPresentModeCount, pPresentModes);
#endif
    }
}

void VulkanCaptureManager::PostProcess_vkReleaseFullScreenExclusiveModeEXT(VkResult       result,
                                                                           VkDevice       device,
                                                                           VkSwapchainKHR swapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(swapchain);

    if (IsCaptureModeTrack())
    {
        assert(state_tracker_ != nullptr);
        state_tracker_->TrackReleaseFullScreenExclusiveMode(device, swapchain);
    }
}

void VulkanCaptureManager::PostProcess_vkGetDeviceGroupSurfacePresentModesKHR(VkResult                          result,
                                                                              VkDevice                          device,
                                                                              VkSurfaceKHR                      surface,
                                                                              VkDeviceGroupPresentModeFlagsKHR* pModes)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    if (pModes != nullptr)
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackDeviceGroupSurfacePresentModes(device, surface, pModes);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkGetDeviceGroupSurfacePresentModes2EXT(
    VkResult                               result,
    VkDevice                               device,
    const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
    VkDeviceGroupPresentModeFlagsKHR*      pModes)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    if ((pSurfaceInfo != nullptr) && (pModes != nullptr))
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackDeviceGroupSurfacePresentModes(
                device, pSurfaceInfo->surface, pModes, pSurfaceInfo->pNext);
        }
    }
}

void VulkanCaptureManager::PreProcess_vkQueueSubmit(VkQueue             queue,
                                                    uint32_t            submitCount,
                                                    const VkSubmitInfo* pSubmits,
                                                    VkFence             fence)
{
    GFXRECON_UNREFERENCED_PARAMETER(fence);

    std::unordered_map<uint64_t, std::map<size_t, size_t>> ranges;

    // This must be done before QueueSubmitWriteFillMemoryCmd is called
    // and tracked mapped memory regions are reseted
    if (pSubmits)
    {
        for (uint32_t s = 0; s < submitCount; ++s)
        {
            for (uint32_t c = 0; c < pSubmits[s].commandBufferCount; ++c)
            {
                vulkan_wrappers::CommandBufferWrapper* primary =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(pSubmits[s].pCommandBuffers[c]);

                if (primary != nullptr)
                {
                    if (IsCaptureModeTrack())
                    {
                        assert(state_tracker_ != nullptr);

                        state_tracker_->TrackMappedAssetsWrites(primary);
                        state_tracker_->MarkDirtyAssets(primary);
                    }

                    MarkReferencedMemoryRanges(primary, ranges);

                    for (auto secondary : primary->secondaries)
                    {
                        if (IsCaptureModeTrack())
                        {
                            state_tracker_->TrackMappedAssetsWrites(secondary);
                            state_tracker_->MarkDirtyAssets(secondary);
                        }

                        MarkReferencedMemoryRanges(secondary, ranges);
                    }
                }
            }
        }
    }

    QueueSubmitWriteFillMemoryCmd(ranges);

    vulkan_wrappers::QueueWrapper* queue_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::QueueWrapper>(queue);
    assert(queue_wrapper != nullptr);
    vulkan_wrappers::DeviceWrapper* dev_wrapper = queue_wrapper->parent_device;

    PreQueueSubmit();

    if (IsCaptureModeTrack())
    {
        if (pSubmits)
        {
            for (uint32_t s = 0; s < submitCount; ++s)
            {
                state_tracker_->TrackTlasToBlasDependencies(pSubmits[s].commandBufferCount,
                                                            pSubmits[s].pCommandBuffers);
            }
        }
    }
}

void VulkanCaptureManager::PreProcess_vkQueueSubmit2(VkQueue              queue,
                                                     uint32_t             submitCount,
                                                     const VkSubmitInfo2* pSubmits,
                                                     VkFence              fence)
{
    GFXRECON_UNREFERENCED_PARAMETER(queue);
    GFXRECON_UNREFERENCED_PARAMETER(submitCount);
    GFXRECON_UNREFERENCED_PARAMETER(pSubmits);
    GFXRECON_UNREFERENCED_PARAMETER(fence);

    std::unordered_map<uint64_t, std::map<size_t, size_t>> ranges;

    // This must be done before QueueSubmitWriteFillMemoryCmd is called
    // and tracked mapped memory regions are reseted
    if (pSubmits)
    {
        for (uint32_t s = 0; s < submitCount; ++s)
        {
            for (uint32_t c = 0; c < pSubmits[s].commandBufferInfoCount; ++c)
            {
                vulkan_wrappers::CommandBufferWrapper* primary =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(
                        pSubmits[s].pCommandBufferInfos[c].commandBuffer);

                if (primary != nullptr)
                {
                    if (IsCaptureModeTrack())
                    {
                        assert(state_tracker_ != nullptr);

                        state_tracker_->TrackMappedAssetsWrites(primary);
                        state_tracker_->MarkDirtyAssets(primary);
                    }

                    MarkReferencedMemoryRanges(primary, ranges);

                    for (auto secondary : primary->secondaries)
                    {
                        if (IsCaptureModeTrack())
                        {
                            state_tracker_->TrackMappedAssetsWrites(secondary);
                            state_tracker_->MarkDirtyAssets(secondary);
                        }

                        MarkReferencedMemoryRanges(secondary, ranges);
                    }
                }
            }
        }
    }

    QueueSubmitWriteFillMemoryCmd(ranges);

    PreQueueSubmit();

    if (IsCaptureModeTrack())
    {
        std::vector<VkCommandBuffer> command_buffs;
        if (pSubmits)
        {
            for (uint32_t s = 0; s < submitCount; ++s)
            {
                if (pSubmits[s].pCommandBufferInfos)
                {
                    for (uint32_t c = 0; c < pSubmits[s].commandBufferInfoCount; ++c)
                    {
                        command_buffs.push_back(pSubmits[s].pCommandBufferInfos[c].commandBuffer);
                    }
                }
            }

            state_tracker_->TrackTlasToBlasDependencies(command_buffs.size(), command_buffs.data());
        }
    }
}

void VulkanCaptureManager::QueueSubmitWriteFillMemoryCmd(std::unordered_map<uint64_t, std::map<size_t, size_t>>& ranges)
{
    if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
        GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
    {
        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        manager->ProcessMemoryEntries(
            [this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
                WriteFillMemoryCmd(memory_id, offset, size, start_address);
            },
            ranges);
    }
    else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
    {
        std::lock_guard<std::mutex> lock(GetMappedMemoryLock());

        for (auto wrapper : mapped_memory_)
        {
            VkDeviceSize size = wrapper->mapped_size;
            if (size == VK_WHOLE_SIZE)
            {
                assert(wrapper->mapped_offset <= wrapper->allocation_size);
                size = wrapper->allocation_size - wrapper->mapped_offset;
            }

            // If the memory is mapped, write the entire mapped region.
            // We set offset to 0, because the pointer returned by vkMapMemory already includes the offset.
            WriteFillMemoryCmd(wrapper->handle_id, 0, size, wrapper->mapped_data);
        }
    }
}

void VulkanCaptureManager::PreProcess_vkCreateDescriptorUpdateTemplate(
    VkResult                                    result,
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if ((result == VK_SUCCESS) && (pCreateInfo != nullptr) && (pDescriptorUpdateTemplate != nullptr))
    {
        SetDescriptorUpdateTemplateInfo((*pDescriptorUpdateTemplate), pCreateInfo);
    }
}

void VulkanCaptureManager::PreProcess_vkCreateDescriptorUpdateTemplateKHR(
    VkResult                                    result,
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if ((result == VK_SUCCESS) && (pCreateInfo != nullptr) && (pDescriptorUpdateTemplate != nullptr))
    {
        SetDescriptorUpdateTemplateInfo((*pDescriptorUpdateTemplate), pCreateInfo);
    }
}

void VulkanCaptureManager::PreProcess_vkGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    if (!device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        GFXRECON_LOG_ERROR_ONCE("The application is using vkGetBufferDeviceAddress, which requires the "
                                "bufferDeviceAddressCaptureReplay "
                                "feature for accurate capture and replay. The capture device does not support this "
                                "feature, so replay of "
                                "the captured file may fail.");
    }
}

void VulkanCaptureManager::PreProcess_vkGetBufferOpaqueCaptureAddress(VkDevice                         device,
                                                                      const VkBufferDeviceAddressInfo* pInfo)
{
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    if (!device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        GFXRECON_LOG_ERROR_ONCE("The application is using vkGetBufferOpaqueCaptureAddress, which requires the "
                                "bufferDeviceAddressCaptureReplay "
                                "feature for accurate capture and replay. The capture device does not support this "
                                "feature, so replay of "
                                "the captured file may fail.");
    }
}

void VulkanCaptureManager::PreProcess_vkGetDeviceMemoryOpaqueCaptureAddress(
    VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
{
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    if (!device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        GFXRECON_LOG_ERROR_ONCE(
            "The application is using vkGetDeviceMemoryOpaqueCaptureAddress, which requires the "
            "bufferDeviceAddressCaptureReplay "
            "feature for accurate capture and replay. The capture device does not support this feature, so replay "
            "of "
            "the captured file may fail.");
    }
}

void VulkanCaptureManager::PreProcess_vkGetAccelerationStructureDeviceAddressKHR(
    VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo)
{
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    if (!device_wrapper->property_feature_info.feature_accelerationStructureCaptureReplay)
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The application is using vkGetAccelerationStructureDeviceAddressKHR, which may require the "
            "accelerationStructureCaptureReplay feature for accurate capture and replay. The capture device does "
            "not "
            "support this feature, so replay of the captured file may fail.");
    }
}

void VulkanCaptureManager::PreProcess_vkGetRayTracingShaderGroupHandlesKHR(
    VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData)
{
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    if (!device_wrapper->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The application is using vkGetRayTracingShaderGroupHandlesKHR, which may require the "
            "rayTracingPipelineShaderGroupHandleCaptureReplay feature for accurate capture and replay. The capture "
            "device does not support this feature, so replay of the captured file may fail.");
    }
}

void VulkanCaptureManager::PreProcess_vkGetAndroidHardwareBufferPropertiesANDROID(
    VkDevice                                  device,
    const struct AHardwareBuffer*             hardware_buffer,
    VkAndroidHardwareBufferPropertiesANDROID* pProperties)
{
    GFXRECON_UNREFERENCED_PARAMETER(pProperties);
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    if (hardware_buffer != nullptr)
    {
        ProcessReferenceToAndroidHardwareBuffer(device, const_cast<AHardwareBuffer*>(hardware_buffer));
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
#endif
}

void VulkanCaptureManager::PostProcess_vkSetPrivateData(VkResult          result,
                                                        VkDevice          device,
                                                        VkObjectType      objectType,
                                                        uint64_t          objectHandle,
                                                        VkPrivateDataSlot privateDataSlot,
                                                        uint64_t          data)
{
    GFXRECON_UNREFERENCED_PARAMETER(privateDataSlot);

    if (privateDataSlot != VK_NULL_HANDLE)
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackSetPrivateData(device, objectType, objectHandle, privateDataSlot, data);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkSetLocalDimmingAMD(VkDevice       device,
                                                            VkSwapchainKHR swapChain,
                                                            VkBool32       localDimmingEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(swapChain);

    if (swapChain != VK_NULL_HANDLE)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackSetLocalDimmingAMD(device, swapChain, localDimmingEnable);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDebugMarkerInsertEXT(VkCommandBuffer                   commandBuffer,
                                                                 const VkDebugMarkerMarkerInfoEXT* pMarkerInfo)
{
    if (pMarkerInfo != nullptr)
    {
        // Look for the debug marker that identifies this command buffer as a VR frame boundary.
        if (util::platform::StringContains(pMarkerInfo->pMarkerName, graphics::kVulkanVrFrameDelimiterString))
        {
            auto cmd_buffer_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
            GFXRECON_ASSERT(cmd_buffer_wrapper != nullptr);
            cmd_buffer_wrapper->is_frame_boundary = true;
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdInsertDebugUtilsLabelEXT(VkCommandBuffer             commandBuffer,
                                                                     const VkDebugUtilsLabelEXT* pLabelInfo)
{
    if (pLabelInfo != nullptr)
    {
        // Look for the label that identifies this command buffer as a VR frame boundary.
        if (util::platform::StringContains(pLabelInfo->pLabelName, graphics::kVulkanVrFrameDelimiterString))
        {
            auto cmd_buffer_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
            GFXRECON_ASSERT(cmd_buffer_wrapper != nullptr);
            cmd_buffer_wrapper->is_frame_boundary = true;
        }
    }
}

#if defined(__ANDROID__)
void VulkanCaptureManager::OverrideGetPhysicalDeviceSurfacePresentModesKHR(uint32_t*         pPresentModeCount,
                                                                           VkPresentModeKHR* pPresentModes)
{
    assert((pPresentModeCount != nullptr) && (pPresentModes != nullptr));

    for (uint32_t i = 0; i < (*pPresentModeCount); ++i)
    {
        pPresentModes[i] = VK_PRESENT_MODE_FIFO_KHR;
    }
}
#endif

bool VulkanCaptureManager::CheckBindAlignment(VkDeviceSize memoryOffset)
{
    if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
         GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
        !GetPageGuardAlignBufferSizes())
    {
        return (memoryOffset % util::platform::GetSystemPageSize()) == 0;
    }

    return true;
}

bool VulkanCaptureManager::CheckCommandBufferWrapperForFrameBoundary(
    const vulkan_wrappers::CommandBufferWrapper* command_buffer_wrapper)
{
    GFXRECON_ASSERT(command_buffer_wrapper != nullptr);
    if (command_buffer_wrapper->is_frame_boundary)
    {
        // Do common capture manager end of frame processing.
        EndFrame();
        return true;
    }
    return false;
}

bool VulkanCaptureManager::CheckPNextChainForFrameBoundary(const VkBaseInStructure* current)
{
    if (current == nullptr)
    {
        return false;
    }

    while (current->sType != VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT && current->pNext != nullptr)
    {
        current = current->pNext;
    }

    if (current->sType == VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT)
    {
        const VkFrameBoundaryEXT* frame_boundary = reinterpret_cast<const VkFrameBoundaryEXT*>(current);

        if (frame_boundary->flags & VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT)
        {
            EndFrame();
            return true;
        }
    }

    return false;
}

void VulkanCaptureManager::PreProcess_vkBindBufferMemory(VkDevice       device,
                                                         VkBuffer       buffer,
                                                         VkDeviceMemory memory,
                                                         VkDeviceSize   memoryOffset)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(buffer);
    GFXRECON_UNREFERENCED_PARAMETER(memory);

    if (!CheckBindAlignment(memoryOffset))
    {
        GFXRECON_LOG_WARNING_ONCE("Buffer bound to device memory at an offset which is not page aligned. Corruption "
                                  "might occur. In that case set "
                                  "Page Guard Align Buffer Sizes env variable to true.");
    }
}

void VulkanCaptureManager::PreProcess_vkBindBufferMemory2(VkDevice                      device,
                                                          uint32_t                      bindInfoCount,
                                                          const VkBindBufferMemoryInfo* pBindInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    for (uint32_t i = 0; i < bindInfoCount; ++i)
    {
        if (!CheckBindAlignment(pBindInfos[i].memoryOffset))
        {
            GFXRECON_LOG_WARNING_ONCE(
                "Buffer bound to device memory at an offset which is not page aligned. Corruption "
                "might occur. In that case set "
                "Page Guard Align Buffer Sizes env variable to true.");
        }
    }
}

void VulkanCaptureManager::PreProcess_vkBindImageMemory(VkDevice       device,
                                                        VkImage        image,
                                                        VkDeviceMemory memory,
                                                        VkDeviceSize   memoryOffset)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(image);
    GFXRECON_UNREFERENCED_PARAMETER(memory);

    if (!CheckBindAlignment(memoryOffset))
    {
        GFXRECON_LOG_WARNING_ONCE("Image bound to device memory at an offset which is not page aligned. Corruption "
                                  "might occur. In that case set "
                                  "Page Guard Align Buffer Sizes env variable to true.");
    }
}

void VulkanCaptureManager::PreProcess_vkBindImageMemory2(VkDevice                     device,
                                                         uint32_t                     bindInfoCount,
                                                         const VkBindImageMemoryInfo* pBindInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    for (uint32_t i = 0; i < bindInfoCount; ++i)
    {
        if (!CheckBindAlignment(pBindInfos[i].memoryOffset))
        {
            GFXRECON_LOG_WARNING_ONCE("Image bound to device memory at an offset which is not page aligned. Corruption "
                                      "might occur. In that case set "
                                      "Page Guard Align Buffer Sizes env variable to true.");
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCreateShaderModule(VkResult                        result,
                                                            VkDevice                        device,
                                                            const VkShaderModuleCreateInfo* pCreateInfo,
                                                            const VkAllocationCallbacks*    pAllocator,
                                                            VkShaderModule*                 pShaderModule)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pShaderModule);

    if (result == VK_SUCCESS)
    {
        // spirv-parsing for buffer-references
        gfxrecon::util::SpirVParsingUtil spirv_util;

        if (spirv_util.ParseBufferReferences(pCreateInfo->pCode, pCreateInfo->codeSize))
        {
            auto buffer_reference_infos = spirv_util.GetBufferReferenceInfos();

            if (!buffer_reference_infos.empty())
            {
                GFXRECON_LOG_WARNING_ONCE(
                    "Shader is using the 'SPV_KHR_physical_storage_buffer' feature. "
                    "Resource tracking for buffers accessed via references is currently unsupported");
            }
        }

        vulkan_wrappers::ShaderModuleWrapper* shader_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ShaderModuleWrapper>(*pShaderModule);
        if (shader_wrapper != nullptr)
        {
            if (!spirv_util.SPIRVReflectPerformReflectionOnShaderModule(
                    pCreateInfo->codeSize, pCreateInfo->pCode, shader_wrapper->used_descriptors_info))
            {
                GFXRECON_LOG_WARNING("Reflection on shader %" PRIu64 "failed", shader_wrapper->handle_id);
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindPipeline(VkCommandBuffer     commandBuffer,
                                                         VkPipelineBindPoint pipelineBindPoint,
                                                         VkPipeline          pipeline)
{
    if (commandBuffer != VK_NULL_HANDLE && pipeline != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper);

        const vulkan_wrappers::PipelineWrapper* ppl_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(pipeline);
        assert(ppl_wrapper != nullptr);

        vulkan_state_info::PipelineBindPoints bind_point =
            vulkan_state_info::VkPipelinePointToPipelinePoint(pipelineBindPoint);
        cmd_buf_wrapper->bound_pipelines[bind_point] = ppl_wrapper;
    }
}

void VulkanCaptureManager::PostProcess_vkCreateGraphicsPipelines(VkResult                            result,
                                                                 VkDevice                            device,
                                                                 VkPipelineCache                     pipelineCache,
                                                                 uint32_t                            createInfoCount,
                                                                 const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                                 const VkAllocationCallbacks*        pAllocator,
                                                                 VkPipeline*                         pPipelines)
{
    if (result == VK_SUCCESS && createInfoCount && pPipelines != nullptr)
    {
        for (uint32_t p = 0; p < createInfoCount; ++p)
        {
            vulkan_wrappers::PipelineWrapper* ppl_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(pPipelines[p]);
            assert(ppl_wrapper != nullptr);

            for (uint32_t s = 0; s < pCreateInfos[p].stageCount; ++s)
            {
                const vulkan_wrappers::ShaderModuleWrapper* shader_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::ShaderModuleWrapper>(
                        pCreateInfos[p].pStages[s].module);
                assert(shader_wrapper != nullptr);

                ppl_wrapper->bound_shaders.push_back(*shader_wrapper);
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCreateComputePipelines(VkResult                           result,
                                                                VkDevice                           device,
                                                                VkPipelineCache                    pipelineCache,
                                                                uint32_t                           createInfoCount,
                                                                const VkComputePipelineCreateInfo* pCreateInfos,
                                                                const VkAllocationCallbacks*       pAllocator,
                                                                VkPipeline*                        pPipelines)
{
    if (result == VK_SUCCESS && createInfoCount && pPipelines != nullptr)
    {
        for (uint32_t p = 0; p < createInfoCount; ++p)
        {
            vulkan_wrappers::PipelineWrapper* ppl_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(pPipelines[p]);
            assert(ppl_wrapper != nullptr);

            const vulkan_wrappers::ShaderModuleWrapper* shader_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::ShaderModuleWrapper>(pCreateInfos[p].stage.module);
            assert(shader_wrapper != nullptr);

            ppl_wrapper->bound_shaders.push_back(*shader_wrapper);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCreateRayTracingPipelinesKHR(
    VkResult                                 result,
    VkDevice                                 device,
    VkDeferredOperationKHR                   deferredOperation,
    VkPipelineCache                          pipelineCache,
    uint32_t                                 createInfoCount,
    const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
    const VkAllocationCallbacks*             pAllocator,
    VkPipeline*                              pPipelines)
{
    if (result == VK_SUCCESS && createInfoCount && pPipelines != nullptr)
    {
        for (uint32_t p = 0; p < createInfoCount; ++p)
        {
            vulkan_wrappers::PipelineWrapper* ppl_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(pPipelines[p]);
            assert(ppl_wrapper != nullptr);

            for (uint32_t s = 0; s < pCreateInfos[p].stageCount; ++s)
            {
                const vulkan_wrappers::ShaderModuleWrapper* shader_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::ShaderModuleWrapper>(
                        pCreateInfos[p].pStages[s].module);
                assert(shader_wrapper != nullptr);

                ppl_wrapper->bound_shaders.push_back(*shader_wrapper);
            }
        }
    }
}

void VulkanCaptureManager::TrackPipelineDescriptors(vulkan_wrappers::CommandBufferWrapper* command_wrapper,
                                                    vulkan_state_info::PipelineBindPoints  ppl_bind_point)
{
    assert(command_wrapper != nullptr);
    assert(ppl_bind_point < vulkan_state_info::PipelineBindPoints::kBindPoint_count);

    const vulkan_wrappers::PipelineWrapper* ppl_wrapper = command_wrapper->bound_pipelines[ppl_bind_point];
    if (ppl_wrapper != nullptr)
    {
        for (const auto& stage : ppl_wrapper->bound_shaders)
        {
            for (const auto& set : stage.used_descriptors_info)
            {
                const uint32_t desc_set_index = set.first;
                for (const auto& desc : set.second)
                {
                    if (desc.second.accessed)
                    {
                        const uint32_t                               binding_index = desc.first;
                        const vulkan_wrappers::DescriptorSetWrapper* desc_set_wrapper =
                            command_wrapper->bound_descriptors[ppl_bind_point][desc_set_index];
                        assert(desc_set_wrapper);

                        const auto& descriptor_binding = desc_set_wrapper->bindings.find(binding_index);
                        if (descriptor_binding == desc_set_wrapper->bindings.end())
                        {
                            continue;
                        }

                        switch (descriptor_binding->second.type)
                        {
                            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                            {
                                for (uint32_t i = 0; i < descriptor_binding->second.count; ++i)
                                {
                                    vulkan_wrappers::ImageViewWrapper* img_view_wrapper =
                                        vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                                            descriptor_binding->second.images[i].imageView);

                                    if (img_view_wrapper != nullptr && img_view_wrapper->image != nullptr)
                                    {
                                        command_wrapper->referenced_assets.insert(img_view_wrapper->image);
                                    }
                                }
                            }
                            break;

                            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                            {
                                for (uint32_t i = 0; i < descriptor_binding->second.count; ++i)
                                {
                                    vulkan_wrappers::BufferWrapper* buf_wrapper =
                                        vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(
                                            descriptor_binding->second.buffers[i].buffer);
                                    if (buf_wrapper != nullptr)
                                    {
                                        command_wrapper->referenced_assets.insert(buf_wrapper);
                                    }
                                }
                            }
                            break;

                            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                            {
                                for (uint32_t i = 0; i < descriptor_binding->second.count; ++i)
                                {
                                    vulkan_wrappers::BufferViewWrapper* buf_view_wrapper =
                                        vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(
                                            descriptor_binding->second.uniform_texel_buffer_views[i]);
                                    if (buf_view_wrapper != nullptr && buf_view_wrapper->buffer != nullptr)
                                    {
                                        command_wrapper->referenced_assets.insert(buf_view_wrapper->buffer);
                                    }
                                }
                            }
                            break;

                            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                            {
                                for (uint32_t i = 0; i < descriptor_binding->second.count; ++i)
                                {
                                    vulkan_wrappers::ImageViewWrapper* img_view_wrapper =
                                        vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                                            descriptor_binding->second.storage_images[i].imageView);

                                    if (img_view_wrapper != nullptr && img_view_wrapper->image != nullptr)
                                    {
                                        command_wrapper->referenced_assets.insert(img_view_wrapper->image);
                                    }
                                }
                            }
                            break;

                            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                            {
                                for (uint32_t i = 0; i < descriptor_binding->second.count; ++i)
                                {
                                    vulkan_wrappers::BufferWrapper* buf_wrapper =
                                        vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(
                                            descriptor_binding->second.storage_buffers[i].buffer);
                                    if (buf_wrapper != nullptr)
                                    {
                                        command_wrapper->referenced_assets.insert(buf_wrapper);
                                    }
                                }
                            }
                            break;

                            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                            {
                                for (uint32_t i = 0; i < descriptor_binding->second.count; ++i)
                                {
                                    vulkan_wrappers::BufferViewWrapper* buf_view_wrapper =
                                        vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(
                                            descriptor_binding->second.storage_texel_buffer_views[i]);
                                    if (buf_view_wrapper != nullptr && buf_view_wrapper->buffer != nullptr)
                                    {
                                        command_wrapper->referenced_assets.insert(buf_view_wrapper->buffer);
                                    }
                                }
                            }
                            break;

                            case VK_DESCRIPTOR_TYPE_SAMPLER:
                            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                                break;

                            // Rest of descriptors are immutable within a shader
                            default:
                                GFXRECON_LOG_ERROR("%s:%s() Descriptor %u not handled",
                                                   __FILE__,
                                                   __func__,
                                                   descriptor_binding->second.type);
                                assert(0);
                                break;
                        }
                    }
                }
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDraw(VkCommandBuffer commandBuffer,
                                                 uint32_t        vertexCount,
                                                 uint32_t        instanceCount,
                                                 uint32_t        firstVertex,
                                                 uint32_t        firstInstance)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndexed(VkCommandBuffer commandBuffer,
                                                        uint32_t        indexCount,
                                                        uint32_t        instanceCount,
                                                        uint32_t        firstIndex,
                                                        int32_t         vertexOffset,
                                                        uint32_t        firstInstance)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDrawIndexed(
            commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndirect(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndexedIndirect(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndirectCount(VkCommandBuffer commandBuffer,
                                                              VkBuffer        buffer,
                                                              VkDeviceSize    offset,
                                                              VkBuffer        countBuffer,
                                                              VkDeviceSize    countBufferOffset,
                                                              uint32_t        maxDrawCount,
                                                              uint32_t        stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDrawIndirectCount(
            commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer,
                                                                     VkBuffer        buffer,
                                                                     VkDeviceSize    offset,
                                                                     VkBuffer        countBuffer,
                                                                     VkDeviceSize    countBufferOffset,
                                                                     uint32_t        maxDrawCount,
                                                                     uint32_t        stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDrawIndexedIndirectCount(
            commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer,
                                                                 VkBuffer        buffer,
                                                                 VkDeviceSize    offset,
                                                                 VkBuffer        countBuffer,
                                                                 VkDeviceSize    countBufferOffset,
                                                                 uint32_t        maxDrawCount,
                                                                 uint32_t        stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDrawIndirectCountKHR(
            commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer,
                                                                        VkBuffer        buffer,
                                                                        VkDeviceSize    offset,
                                                                        VkBuffer        countBuffer,
                                                                        VkDeviceSize    countBufferOffset,
                                                                        uint32_t        maxDrawCount,
                                                                        uint32_t        stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDrawIndexedIndirectCountKHR(
            commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDispatch(VkCommandBuffer commandBuffer,
                                                     uint32_t        groupCountX,
                                                     uint32_t        groupCountY,
                                                     uint32_t        groupCountZ)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDispatchIndirect(VkCommandBuffer commandBuffer,
                                                             VkBuffer        buffer,
                                                             VkDeviceSize    offset)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDispatchIndirect(commandBuffer, buffer, offset);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDispatchBase(VkCommandBuffer commandBuffer,
                                                         uint32_t        baseGroupX,
                                                         uint32_t        baseGroupY,
                                                         uint32_t        baseGroupZ,
                                                         uint32_t        groupCountX,
                                                         uint32_t        groupCountY,
                                                         uint32_t        groupCountZ)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDispatchBase(
            commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDispatchBaseKHR(VkCommandBuffer commandBuffer,
                                                            uint32_t        baseGroupX,
                                                            uint32_t        baseGroupY,
                                                            uint32_t        baseGroupZ,
                                                            uint32_t        groupCountX,
                                                            uint32_t        groupCountY,
                                                            uint32_t        groupCountZ)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDispatchBaseKHR(
            commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdTraceRaysNV(VkCommandBuffer commandBuffer,
                                                        VkBuffer        raygenShaderBindingTableBuffer,
                                                        VkDeviceSize    raygenShaderBindingOffset,
                                                        VkBuffer        missShaderBindingTableBuffer,
                                                        VkDeviceSize    missShaderBindingOffset,
                                                        VkDeviceSize    missShaderBindingStride,
                                                        VkBuffer        hitShaderBindingTableBuffer,
                                                        VkDeviceSize    hitShaderBindingOffset,
                                                        VkDeviceSize    hitShaderBindingStride,
                                                        VkBuffer        callableShaderBindingTableBuffer,
                                                        VkDeviceSize    callableShaderBindingOffset,
                                                        VkDeviceSize    callableShaderBindingStride,
                                                        uint32_t        width,
                                                        uint32_t        height,
                                                        uint32_t        depth)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_ray_tracing);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdTraceRaysNV(commandBuffer,
                                            raygenShaderBindingTableBuffer,
                                            raygenShaderBindingOffset,
                                            missShaderBindingTableBuffer,
                                            missShaderBindingOffset,
                                            missShaderBindingStride,
                                            hitShaderBindingTableBuffer,
                                            hitShaderBindingOffset,
                                            hitShaderBindingStride,
                                            callableShaderBindingTableBuffer,
                                            callableShaderBindingOffset,
                                            callableShaderBindingStride,
                                            width,
                                            height,
                                            depth);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdTraceRaysKHR(
    VkCommandBuffer                        commandBuffer,
    const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
    uint32_t                               width,
    uint32_t                               height,
    uint32_t                               depth)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_ray_tracing);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdTraceRaysKHR(commandBuffer,
                                             pRaygenShaderBindingTable,
                                             pMissShaderBindingTable,
                                             pHitShaderBindingTable,
                                             pCallableShaderBindingTable,
                                             width,
                                             height,
                                             depth);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdTraceRaysIndirectKHR(
    VkCommandBuffer                        commandBuffer,
    const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
    VkDeviceAddress                        indirectDeviceAddress)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_ray_tracing);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdTraceRaysIndirectKHR(commandBuffer,
                                                     pRaygenShaderBindingTable,
                                                     pMissShaderBindingTable,
                                                     pHitShaderBindingTable,
                                                     pCallableShaderBindingTable,
                                                     indirectDeviceAddress);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer,
                                                                  VkDeviceAddress indirectDeviceAddress)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_ray_tracing);

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindDescriptorSets(VkCommandBuffer        commandBuffer,
                                                               VkPipelineBindPoint    pipelineBindPoint,
                                                               VkPipelineLayout       layout,
                                                               uint32_t               firstSet,
                                                               uint32_t               descriptorSetCount,
                                                               const VkDescriptorSet* pDescriptorSets,
                                                               uint32_t               dynamicOffsetCount,
                                                               const uint32_t*        pDynamicOffsets)
{
    if (pDescriptorSets != nullptr && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        for (uint32_t i = 0; i < descriptorSetCount; ++i)
        {
            vulkan_wrappers::DescriptorSetWrapper* desc_set_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(pDescriptorSets[i]);
            assert(desc_set_wrapper != nullptr);

            cmd_buf_wrapper->bound_descriptors[vulkan_state_info::VkPipelinePointToPipelinePoint(pipelineBindPoint)]
                                              [firstSet + i] = desc_set_wrapper;
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindDescriptorSets2KHR(
    VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo)
{
    if (pBindDescriptorSetsInfo != nullptr && pBindDescriptorSetsInfo->pDescriptorSets != nullptr &&
        commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        for (uint32_t i = 0; i < pBindDescriptorSetsInfo->descriptorSetCount; ++i)
        {
            vulkan_wrappers::DescriptorSetWrapper* desc_set_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(
                    pBindDescriptorSetsInfo->pDescriptorSets[i]);
            assert(desc_set_wrapper != nullptr);

            std::vector<vulkan_state_info::PipelineBindPoints> points;
            vulkan_state_info::VkShaderStageFlagsToPipelinePoint(pBindDescriptorSetsInfo->stageFlags, points);

            for (auto point : points)
            {
                cmd_buf_wrapper->bound_descriptors[point][pBindDescriptorSetsInfo->firstSet + i] = desc_set_wrapper;
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyBuffer(VkCommandBuffer     commandBuffer,
                                                       VkBuffer            srcBuffer,
                                                       VkBuffer            dstBuffer,
                                                       uint32_t            regionCount,
                                                       const VkBufferCopy* pRegions)
{
    if (srcBuffer != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* src_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(srcBuffer);
        assert(src_buffer_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_buffer_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyImage(VkCommandBuffer    commandBuffer,
                                                      VkImage            srcImage,
                                                      VkImageLayout      srcImageLayout,
                                                      VkImage            dstImage,
                                                      VkImageLayout      dstImageLayout,
                                                      uint32_t           regionCount,
                                                      const VkImageCopy* pRegions)
{
    if (srcImage != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* src_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(srcImage);
        assert(src_img_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_img_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdCopyImage(
            commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyBufferToImage(VkCommandBuffer          commandBuffer,
                                                              VkBuffer                 srcBuffer,
                                                              VkImage                  dstImage,
                                                              VkImageLayout            dstImageLayout,
                                                              uint32_t                 regionCount,
                                                              const VkBufferImageCopy* pRegions)
{
    if (srcBuffer != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* src_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(srcBuffer);
        assert(src_buffer_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_buffer_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdCopyBufferToImage(
            commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyImageToBuffer(VkCommandBuffer          commandBuffer,
                                                              VkImage                  srcImage,
                                                              VkImageLayout            srcImageLayout,
                                                              VkBuffer                 dstBuffer,
                                                              uint32_t                 regionCount,
                                                              const VkBufferImageCopy* pRegions)
{
    if (srcImage != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* src_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(srcImage);
        assert(src_img_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_img_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdCopyImageToBuffer(
            commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyBuffer2(VkCommandBuffer          commandBuffer,
                                                        const VkCopyBufferInfo2* pCopyBufferInfo)
{
    if (pCopyBufferInfo != nullptr && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* src_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pCopyBufferInfo->srcBuffer);
        assert(src_buffer_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_buffer_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyImage2(VkCommandBuffer         commandBuffer,
                                                       const VkCopyImageInfo2* pCopyImageInfo)
{
    if (pCopyImageInfo != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* src_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pCopyImageInfo->srcImage);
        assert(src_img_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_img_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdCopyImage2(commandBuffer, pCopyImageInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyBufferToImage2(VkCommandBuffer                 commandBuffer,
                                                               const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    if (pCopyBufferToImageInfo != nullptr && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* src_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pCopyBufferToImageInfo->srcBuffer);
        assert(src_buffer_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_buffer_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyImageToBuffer2(VkCommandBuffer                 commandBuffer,
                                                               const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    if (pCopyImageToBufferInfo != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* src_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pCopyImageToBufferInfo->srcImage);
        assert(src_img_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_img_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyBuffer2KHR(VkCommandBuffer          commandBuffer,
                                                           const VkCopyBufferInfo2* pCopyBufferInfo)
{
    if (pCopyBufferInfo != nullptr && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* src_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pCopyBufferInfo->srcBuffer);
        assert(src_buffer_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_buffer_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyImage2KHR(VkCommandBuffer         commandBuffer,
                                                          const VkCopyImageInfo2* pCopyImageInfo)
{
    if (pCopyImageInfo != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* src_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pCopyImageInfo->srcImage);
        assert(src_img_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_img_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyBufferToImage2KHR(
    VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    if (pCopyBufferToImageInfo != nullptr && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* src_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pCopyBufferToImageInfo->srcBuffer);
        assert(src_buffer_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_buffer_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyImageToBuffer2KHR(
    VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    if (pCopyImageToBufferInfo != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* src_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pCopyImageToBufferInfo->srcImage);
        assert(src_img_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_img_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBlitImage(VkCommandBuffer    commandBuffer,
                                                      VkImage            srcImage,
                                                      VkImageLayout      srcImageLayout,
                                                      VkImage            dstImage,
                                                      VkImageLayout      dstImageLayout,
                                                      uint32_t           regionCount,
                                                      const VkImageBlit* pRegions,
                                                      VkFilter           filter)
{
    if (srcImage != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* src_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(srcImage);
        assert(src_img_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_img_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdBlitImage(
            commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBlitImage2(VkCommandBuffer         commandBuffer,
                                                       const VkBlitImageInfo2* pBlitImageInfo)
{
    if (pBlitImageInfo != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* src_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pBlitImageInfo->srcImage);
        assert(src_img_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_img_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdBlitImage2(commandBuffer, pBlitImageInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBlitImage2KHR(VkCommandBuffer         commandBuffer,
                                                          const VkBlitImageInfo2* pBlitImageInfo)
{
    if (pBlitImageInfo != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* src_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pBlitImageInfo->srcImage);
        assert(src_img_wrapper != nullptr);

        cmd_buf_wrapper->referenced_assets.insert(src_img_wrapper);
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdUpdateBuffer(
    VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdFillBuffer(
    VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdClearColorImage(VkCommandBuffer                commandBuffer,
                                                            VkImage                        image,
                                                            VkImageLayout                  imageLayout,
                                                            const VkClearColorValue*       pColor,
                                                            uint32_t                       rangeCount,
                                                            const VkImageSubresourceRange* pRanges)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdClearDepthStencilImage(VkCommandBuffer                 commandBuffer,
                                                                   VkImage                         image,
                                                                   VkImageLayout                   imageLayout,
                                                                   const VkClearDepthStencilValue* pDepthStencil,
                                                                   uint32_t                        rangeCount,
                                                                   const VkImageSubresourceRange*  pRanges)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdClearDepthStencilImage(
            commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdResolveImage(VkCommandBuffer       commandBuffer,
                                                         VkImage               srcImage,
                                                         VkImageLayout         srcImageLayout,
                                                         VkImage               dstImage,
                                                         VkImageLayout         dstImageLayout,
                                                         uint32_t              regionCount,
                                                         const VkImageResolve* pRegions)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdResolveImage(
            commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdResolveImage2(VkCommandBuffer            commandBuffer,
                                                          const VkResolveImageInfo2* pResolveImageInfo)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdResolveImage2(commandBuffer, pResolveImageInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdResolveImage2KHR(VkCommandBuffer            commandBuffer,
                                                             const VkResolveImageInfo2* pResolveImageInfo)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdResolveImage2(commandBuffer, pResolveImageInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer,
                                                            uint32_t        taskCount,
                                                            uint32_t        firstTask)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawMeshTasksIndirectNV(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer,
                                                                         VkBuffer        buffer,
                                                                         VkDeviceSize    offset,
                                                                         VkBuffer        countBuffer,
                                                                         VkDeviceSize    countBufferOffset,
                                                                         uint32_t        maxDrawCount,
                                                                         uint32_t        stride)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDrawMeshTasksIndirectCountNV(
            commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer,
                                                             uint32_t        groupCountX,
                                                             uint32_t        groupCountY,
                                                             uint32_t        groupCountZ)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawMeshTasksIndirectEXT(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer,
                                                                          VkBuffer        buffer,
                                                                          VkDeviceSize    offset,
                                                                          VkBuffer        countBuffer,
                                                                          VkDeviceSize    countBufferOffset,
                                                                          uint32_t        maxDrawCount,
                                                                          uint32_t        stride)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackCmdDrawMeshTasksIndirectCountEXT(
            commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanCaptureManager::PostProcess_vkAllocateDescriptorSets(VkResult                           result,
                                                                VkDevice                           device,
                                                                const VkDescriptorSetAllocateInfo* pAllocateInfo,
                                                                VkDescriptorSet*                   pDescriptorSets)
{
    if (result == VK_SUCCESS)
    {
        auto                                thread_data       = GetThreadData();
        vulkan_state_info::CreateParameters create_parameters = std::make_shared<util::MemoryOutputStream>(
            thread_data->parameter_buffer_->GetData(), thread_data->parameter_buffer_->GetDataSize());

        for (uint32_t i = 0; i < pAllocateInfo->descriptorSetCount; ++i)
        {
            if (pDescriptorSets[i] != VK_NULL_HANDLE)
            {
                vulkan_wrappers::DescriptorSetWrapper* wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(pDescriptorSets[i]);

                if (wrapper != nullptr)
                {
                    vulkan_state_tracker::InitializePoolObjectState(device,
                                                                    wrapper,
                                                                    i,
                                                                    pAllocateInfo,
                                                                    format::ApiCallId::ApiCall_vkAllocateDescriptorSets,
                                                                    create_parameters);
                }
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCreateDescriptorSetLayout(VkResult                               result,
                                                                   VkDevice                               device,
                                                                   const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
                                                                   const VkAllocationCallbacks*           pAllocator,
                                                                   VkDescriptorSetLayout*                 pSetLayout)
{
    if (result == VK_SUCCESS && pCreateInfo != nullptr && *pSetLayout != VK_NULL_HANDLE)
    {
        vulkan_wrappers::DescriptorSetLayoutWrapper* wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetLayoutWrapper>(*pSetLayout);

        if (wrapper != nullptr)
        {
            auto                                thread_data       = GetThreadData();
            vulkan_state_info::CreateParameters create_parameters = std::make_shared<util::MemoryOutputStream>(
                thread_data->parameter_buffer_.get()->GetData(), thread_data->parameter_buffer_.get()->GetDataSize());

            vulkan_state_tracker::
                InitializeState<VkDevice, vulkan_wrappers::DescriptorSetLayoutWrapper, VkDescriptorSetLayoutCreateInfo>(
                    device,
                    wrapper,
                    pCreateInfo,
                    format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout,
                    std::make_shared<util::MemoryOutputStream>(create_parameters->GetData(),
                                                               create_parameters->GetDataSize()));
        }
    }
}

void VulkanCaptureManager::TrackUpdateDescriptorSets(uint32_t                    write_count,
                                                     const VkWriteDescriptorSet* writes,
                                                     uint32_t                    copy_count,
                                                     const VkCopyDescriptorSet*  copies)
{
    // When processing descriptor updates, we pack the unique handle ID into the stored
    // VkWriteDescriptorSet/VkCopyDescriptorSet handles so that the state writer can determine if the object still
    // exists at state write time by checking for the ID in the active state table.
    if (writes != nullptr)
    {
        for (uint32_t i = 0; i < write_count; ++i)
        {
            const VkWriteDescriptorSet* write = &writes[i];
            auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(write->dstSet);
            assert(wrapper != nullptr);

            wrapper->dirty = true;

            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings, where the next binding is dstBinding+1 and
            // starting from array element 0.  Track the current count, binding, and array element to handle
            // consecutive updates.
            uint32_t current_count             = write->descriptorCount;
            uint32_t current_binding           = write->dstBinding;
            uint32_t current_dst_array_element = write->dstArrayElement;
            uint32_t current_src_array_element = 0;

            for (;;)
            {
                auto& binding = wrapper->bindings[current_binding];

                // Update current and write counts for binding's descriptor count. If current count is
                // greater than the count for the descriptor range defined by dstArrayElement through binding count,
                // consecutive bindings are being updated.
                uint32_t current_writes = std::min(current_count, (binding.count - current_dst_array_element));

                bool* written_start = &binding.written[current_dst_array_element];
                std::fill(written_start, written_start + current_writes, true);

                if (binding.type == VK_DESCRIPTOR_TYPE_MUTABLE_VALVE)
                {
                    VkDescriptorType* mutable_type_start = &binding.mutable_type[current_dst_array_element];
                    std::fill(mutable_type_start, mutable_type_start + current_writes, write->descriptorType);
                }

                switch (write->descriptorType)
                {
                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                    {
                        format::HandleId*            dst_sampler_ids = &binding.sampler_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info        = &binding.images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info        = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_sampler_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::SamplerWrapper>(src_info[i].sampler);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    {
                        format::HandleId*            dst_sampler_ids = &binding.sampler_ids[current_dst_array_element];
                        format::HandleId*            dst_image_ids   = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info        = &binding.images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info        = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_sampler_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::SamplerWrapper>(src_info[i].sampler);
                            dst_image_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                    {
                        format::HandleId*            dst_image_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info      = &binding.images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info      = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_image_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    {
                        format::HandleId*            dst_image_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info      = &binding.storage_images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info      = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_image_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    {
                        format::HandleId*             dst_buffer_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorBufferInfo*       dst_info       = &binding.buffers[current_dst_array_element];
                        const VkDescriptorBufferInfo* src_info       = &write->pBufferInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_buffer_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(src_info[i].buffer);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                    {
                        format::HandleId*             dst_buffer_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorBufferInfo*       dst_info = &binding.storage_buffers[current_dst_array_element];
                        const VkDescriptorBufferInfo* src_info = &write->pBufferInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_buffer_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(src_info[i].buffer);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                    {
                        format::HandleId*   dst_view_ids = &binding.handle_ids[current_dst_array_element];
                        VkBufferView*       dst_info = &binding.uniform_texel_buffer_views[current_dst_array_element];
                        const VkBufferView* src_info = &write->pTexelBufferView[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_view_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferViewWrapper>(src_info[i]);
                            dst_info[i] = src_info[i];
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                    {
                        format::HandleId*   dst_view_ids = &binding.handle_ids[current_dst_array_element];
                        VkBufferView*       dst_info = &binding.storage_texel_buffer_views[current_dst_array_element];
                        const VkBufferView* src_info = &write->pTexelBufferView[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_view_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferViewWrapper>(src_info[i]);
                            dst_info[i] = src_info[i];
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        VkWriteDescriptorSetInlineUniformBlock* write_inline_uniform_struct =
                            graphics::GetPNextStruct<VkWriteDescriptorSetInlineUniformBlock>(
                                write, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK);

                        if (write_inline_uniform_struct != nullptr)
                        {
                            uint8_t*       dst_inline_uniform_data = binding.inline_uniform_block.get();
                            const uint8_t* src_inline_uniform_data =
                                reinterpret_cast<const uint8_t*>(write_inline_uniform_struct->pData);
                            memcpy(dst_inline_uniform_data, src_inline_uniform_data, current_writes);
                        }
                    }
                    break;
                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                        // TODO
                        break;
                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    {
                        VkWriteDescriptorSetAccelerationStructureKHR* write_accel_struct =
                            graphics::GetPNextStruct<VkWriteDescriptorSetAccelerationStructureKHR>(
                                write, VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR);

                        if (write_accel_struct != nullptr)
                        {
                            format::HandleId* dst_accel_struct_ids = &binding.handle_ids[current_dst_array_element];
                            VkAccelerationStructureKHR* dst_accel_struct =
                                &binding.acceleration_structures[current_dst_array_element];
                            const VkAccelerationStructureKHR* src_accel_struct =
                                &write_accel_struct->pAccelerationStructures[current_src_array_element];

                            for (uint32_t i = 0; i < current_writes; ++i)
                            {
                                dst_accel_struct_ids[i] =
                                    vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                                        src_accel_struct[i]);
                                dst_accel_struct[i] = src_accel_struct[i];
                            }
                        }
                    }
                    break;
                    default:
                        GFXRECON_LOG_WARNING("Attempting to track descriptor state for unrecognized descriptor type");
                        break;
                }

                // Check for consecutive update.
                if (current_count == current_writes)
                {
                    break;
                }
                else
                {
                    current_count -= current_writes;
                    current_binding += 1;
                    current_dst_array_element = 0;
                    current_src_array_element += current_writes;
                }
            }
        }
    }

    if (copies != nullptr)
    {
        for (uint32_t i = 0; i < copy_count; ++i)
        {
            auto copy        = &copies[i];
            auto dst_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(copy->dstSet);
            auto src_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(copy->srcSet);
            assert((dst_wrapper != nullptr) && (src_wrapper != nullptr));

            dst_wrapper->dirty = true;

            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to/from consecutive bindings.
            uint32_t current_count             = copy->descriptorCount;
            uint32_t current_dst_binding       = copy->dstBinding;
            uint32_t current_src_binding       = copy->srcBinding;
            uint32_t current_dst_array_element = copy->dstArrayElement;
            uint32_t current_src_array_element = copy->srcArrayElement;

            for (;;)
            {
                auto& dst_binding = dst_wrapper->bindings[current_dst_binding];
                auto& src_binding = src_wrapper->bindings[current_src_binding];

                assert(src_binding.type == dst_binding.type);

                // Check available counts for consecutive updates.
                uint32_t dst_copy_count = dst_binding.count - current_dst_array_element;
                uint32_t src_copy_count = src_binding.count - current_src_array_element;
                uint32_t current_copies = std::min(current_count, std::min(dst_copy_count, src_copy_count));

                bool* written_start = &dst_binding.written[current_dst_array_element];
                std::fill(written_start, written_start + current_copies, true);

                memcpy(&dst_binding.handle_ids[current_dst_array_element],
                       &src_binding.handle_ids[current_src_array_element],
                       (sizeof(format::HandleId) * current_copies));

                if (src_binding.images != nullptr)
                {
                    memcpy(&dst_binding.sampler_ids[current_dst_array_element],
                           &src_binding.sampler_ids[current_src_array_element],
                           (sizeof(format::HandleId) * current_copies));

                    memcpy(&dst_binding.images[current_dst_array_element],
                           &src_binding.images[current_src_array_element],
                           (sizeof(VkDescriptorImageInfo) * current_copies));
                }
                if (src_binding.storage_images != nullptr)
                {
                    memcpy(&dst_binding.storage_images[current_dst_array_element],
                           &src_binding.storage_images[current_src_array_element],
                           (sizeof(VkDescriptorImageInfo) * current_copies));
                }
                if (src_binding.buffers != nullptr)
                {
                    memcpy(&dst_binding.buffers[current_dst_array_element],
                           &src_binding.buffers[current_src_array_element],
                           (sizeof(VkDescriptorBufferInfo) * current_copies));
                }
                if (src_binding.storage_buffers != nullptr)
                {
                    memcpy(&dst_binding.storage_buffers[current_dst_array_element],
                           &src_binding.storage_buffers[current_src_array_element],
                           (sizeof(VkDescriptorBufferInfo) * current_copies));
                }
                if (src_binding.acceleration_structures != nullptr)
                {
                    memcpy(&dst_binding.acceleration_structures[current_dst_array_element],
                           &src_binding.acceleration_structures[current_src_array_element],
                           (sizeof(VkWriteDescriptorSetAccelerationStructureKHR) * current_copies));
                }
                if (src_binding.inline_uniform_block != nullptr)
                {
                    memcpy(&dst_binding.inline_uniform_block[current_dst_array_element],
                           &src_binding.inline_uniform_block[current_src_array_element],
                           current_copies);
                }
                if (src_binding.uniform_texel_buffer_views != nullptr)
                {
                    memcpy(&dst_binding.uniform_texel_buffer_views[current_dst_array_element],
                           &src_binding.uniform_texel_buffer_views[current_src_array_element],
                           (sizeof(VkBufferView) * current_copies));
                }
                if (src_binding.storage_texel_buffer_views != nullptr)
                {
                    memcpy(&dst_binding.storage_texel_buffer_views[current_dst_array_element],
                           &src_binding.storage_texel_buffer_views[current_src_array_element],
                           (sizeof(VkBufferView) * current_copies));
                }
                if (src_binding.mutable_type != nullptr)
                {
                    memcpy(&dst_binding.mutable_type[current_dst_array_element],
                           &src_binding.mutable_type[current_src_array_element],
                           (sizeof(VkDescriptorType) * current_copies));
                }

                // Check for consecutive update.
                if (current_count == current_copies)
                {
                    break;
                }
                else
                {
                    current_count -= current_copies;

                    if (dst_copy_count == src_copy_count)
                    {
                        // Both bindings must increment.
                        current_dst_binding += 1;
                        current_src_binding += 1;
                        current_dst_array_element = 0;
                        current_src_array_element = 0;
                    }
                    else if (dst_copy_count < src_copy_count)
                    {
                        // Only the destination binding must increment.
                        current_dst_binding += 1;
                        current_dst_array_element = 0;
                        current_src_array_element += current_copies;
                    }
                    else
                    {
                        // Only the source binding must increment.
                        current_src_binding += 1;
                        current_src_array_element = 0;
                        current_dst_array_element += current_copies;
                    }
                }
            }
        }
    }
}

void VulkanCaptureManager::ResetCommandBuffer(vulkan_wrappers::CommandBufferWrapper* wrapper)
{
    wrapper->referenced_assets.clear();
    wrapper->secondaries.clear();

    for (uint32_t point = vulkan_state_info::kBindPoint_graphics; point != vulkan_state_info::kBindPoint_count; ++point)
    {
        wrapper->bound_descriptors[point].clear();
        wrapper->bound_pipelines[point] = nullptr;
    }
}

void VulkanCaptureManager::MarkReferencedMemoryRanges(vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper,
                                                      std::unordered_map<uint64_t, std::map<size_t, size_t>>& ranges)
{
    assert(cmd_buf_wrapper != nullptr);

    util::PageGuardManager* pg_manager = util::PageGuardManager::Get();
    if (pg_manager == nullptr)
    {
        return;
    }

    const size_t page_size = util::platform::GetSystemPageSize();
    for (auto asset : cmd_buf_wrapper->referenced_assets)
    {
        assert(asset);

        if (!asset->size || asset->bind_memory_wrapper == nullptr)
        {
            continue;
        }

        const size_t first_page = asset->bind_offset / page_size;
        const size_t last_page  = (asset->bind_offset + asset->size - 1) / page_size;
        assert(first_page <= last_page);

        assert(asset->bind_memory_id != format::kNullHandleId);
        auto new_entry = ranges.emplace(asset->bind_memory_id, std::map<size_t, size_t>());
        if (new_entry.second)
        {
            new_entry.first->second.emplace(std::make_pair(first_page, last_page));
        }
        else
        {
            auto new_range = ranges[asset->bind_memory_id].emplace(std::make_pair(first_page, last_page));
            if (!new_range.second)
            {
                if (ranges[asset->bind_memory_id][first_page] < last_page)
                {
                    ranges[asset->bind_memory_id][first_page] = last_page;
                }
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCreateImageView(VkResult                     result,
                                                         VkDevice                     device,
                                                         const VkImageViewCreateInfo* pCreateInfo,
                                                         const VkAllocationCallbacks* pAllocator,
                                                         VkImageView*                 pView)
{
    if (result == VK_SUCCESS && pCreateInfo != nullptr)
    {
        vulkan_wrappers::ImageViewWrapper* img_view_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(*pView);

        if (img_view_wrapper != nullptr)
        {
            img_view_wrapper->image = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pCreateInfo->image);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCreateBufferView(VkResult                      result,
                                                          VkDevice                      device,
                                                          const VkBufferViewCreateInfo* pCreateInfo,
                                                          const VkAllocationCallbacks*  pAllocator,
                                                          VkBufferView*                 pView)
{
    if (result == VK_SUCCESS && pCreateInfo != nullptr)
    {
        vulkan_wrappers::BufferViewWrapper* buf_view_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(*pView);
        if (buf_view_wrapper != nullptr)
        {
            buf_view_wrapper->buffer = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pCreateInfo->buffer);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindVertexBuffers(VkCommandBuffer     commandBuffer,
                                                              uint32_t            firstBinding,
                                                              uint32_t            bindingCount,
                                                              const VkBuffer*     pBuffers,
                                                              const VkDeviceSize* pOffsets)
{
    if (commandBuffer != VK_NULL_HANDLE && pBuffers != nullptr)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        for (uint32_t i = 0; i < bindingCount; ++i)
        {
            if (pBuffers[i] != VK_NULL_HANDLE)
            {
                vulkan_wrappers::BufferWrapper* buffer_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pBuffers[i]);
                assert(buffer_wrapper);

                cmd_buf_wrapper->referenced_assets.insert(buffer_wrapper);
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindVertexBuffers2(VkCommandBuffer     commandBuffer,
                                                               uint32_t            firstBinding,
                                                               uint32_t            bindingCount,
                                                               const VkBuffer*     pBuffers,
                                                               const VkDeviceSize* pOffsets,
                                                               const VkDeviceSize* pSizes,
                                                               const VkDeviceSize* pStrides)
{
    if (commandBuffer != VK_NULL_HANDLE && pBuffers != nullptr)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        for (uint32_t i = 0; i < bindingCount; ++i)
        {
            if (pBuffers[i] != VK_NULL_HANDLE)
            {
                vulkan_wrappers::BufferWrapper* buffer_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pBuffers[i]);
                assert(buffer_wrapper);

                cmd_buf_wrapper->referenced_assets.insert(buffer_wrapper);
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindVertexBuffers2EXT(VkCommandBuffer     commandBuffer,
                                                                  uint32_t            firstBinding,
                                                                  uint32_t            bindingCount,
                                                                  const VkBuffer*     pBuffers,
                                                                  const VkDeviceSize* pOffsets,
                                                                  const VkDeviceSize* pSizes,
                                                                  const VkDeviceSize* pStrides)
{
    if (commandBuffer != VK_NULL_HANDLE && pBuffers != nullptr)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        for (uint32_t i = 0; i < bindingCount; ++i)
        {
            if (pBuffers[i] != VK_NULL_HANDLE)
            {
                vulkan_wrappers::BufferWrapper* buffer_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pBuffers[i]);
                assert(buffer_wrapper);

                cmd_buf_wrapper->referenced_assets.insert(buffer_wrapper);
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindIndexBuffer(VkCommandBuffer commandBuffer,
                                                            VkBuffer        buffer,
                                                            VkDeviceSize    offset,
                                                            VkIndexType     indexType)
{
    if (commandBuffer != VK_NULL_HANDLE && buffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(buffer);
        assert(buffer_wrapper);

        cmd_buf_wrapper->referenced_assets.insert(buffer_wrapper);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindIndexBuffer2KHR(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType)
{
    if (commandBuffer != VK_NULL_HANDLE && buffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(buffer);
        assert(buffer_wrapper);

        cmd_buf_wrapper->referenced_assets.insert(buffer_wrapper);
    }
}

void VulkanCaptureManager::PostProcess_vkBindBufferMemory(
    VkResult result, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
    if (result == VK_SUCCESS)
    {
        assert((device != VK_NULL_HANDLE) && (buffer != VK_NULL_HANDLE) && (memory != VK_NULL_HANDLE));

        auto wrapper            = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(buffer);
        wrapper->bind_device    = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
        wrapper->bind_memory_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceMemoryWrapper>(memory);
        wrapper->bind_offset    = memoryOffset;
        wrapper->bind_pnext     = nullptr;

        vulkan_wrappers::DeviceMemoryWrapper* mem_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
        assert(mem_wrapper != nullptr);

        vulkan_wrappers::AssetWrapperBase* asset = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(buffer);
        assert(asset != nullptr);

        asset->bind_offset = memoryOffset;

        vulkan_wrappers::DeviceMemoryWrapper* dev_mem_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
        assert(dev_mem_wrapper != nullptr);
        if (dev_mem_wrapper != nullptr)
        {
            asset->bind_memory_id      = dev_mem_wrapper->handle_id;
            asset->bind_memory_wrapper = dev_mem_wrapper;

            assert(asset->size);

            dev_mem_wrapper->asset_map_lock.lock();
            dev_mem_wrapper->bound_assets[memoryOffset] = asset;
            dev_mem_wrapper->asset_map_lock.unlock();
        }
    }
}

void VulkanCaptureManager::PostProcess_vkBindBufferMemory2(VkResult                      result,
                                                           VkDevice                      device,
                                                           uint32_t                      bindInfoCount,
                                                           const VkBindBufferMemoryInfo* pBindInfos)
{
    if ((result == VK_SUCCESS) && (pBindInfos != nullptr))
    {

        for (uint32_t i = 0; i < bindInfoCount; ++i)
        {
            assert((device != VK_NULL_HANDLE) && (pBindInfos[i].buffer != VK_NULL_HANDLE) &&
                   (pBindInfos[i].memory != VK_NULL_HANDLE));

            auto wrapper         = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pBindInfos[i].buffer);
            wrapper->bind_device = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
            wrapper->bind_memory_id =
                vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceMemoryWrapper>(pBindInfos[i].memory);
            wrapper->bind_offset = pBindInfos[i].memoryOffset;
            wrapper->bind_pnext  = nullptr;

            vulkan_wrappers::DeviceMemoryWrapper* mem_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(pBindInfos[i].memory);
            assert(mem_wrapper != nullptr);

            // if (pBindInfos[i].pNext != nullptr)
            // {
            //     wrapper->bind_pnext = vulkan_trackers::TrackStruct(pBindInfos[i].pNext,
            //     wrapper->bind_pnext_memory);
            // }

            vulkan_wrappers::AssetWrapperBase* asset =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pBindInfos[i].buffer);
            assert(asset != nullptr);

            asset->bind_offset = pBindInfos->memoryOffset;

            vulkan_wrappers::DeviceMemoryWrapper* dev_mem_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(pBindInfos[i].memory);
            assert(dev_mem_wrapper != nullptr);
            if (dev_mem_wrapper != nullptr)
            {
                asset->bind_memory_id      = dev_mem_wrapper->handle_id;
                asset->bind_memory_wrapper = dev_mem_wrapper;

                assert(asset->size);

                dev_mem_wrapper->asset_map_lock.lock();
                dev_mem_wrapper->bound_assets[pBindInfos[i].memoryOffset] = asset;
                dev_mem_wrapper->asset_map_lock.unlock();
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkBindImageMemory(
    VkResult result, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
    if (result == VK_SUCCESS)
    {
        assert((device != VK_NULL_HANDLE) && (image != VK_NULL_HANDLE));

        auto wrapper            = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image);
        wrapper->bind_device    = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
        wrapper->bind_memory_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceMemoryWrapper>(memory);
        wrapper->bind_offset    = memoryOffset;
        wrapper->bind_pnext     = nullptr;

        vulkan_wrappers::DeviceMemoryWrapper* mem_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
        assert(mem_wrapper != nullptr);

        vulkan_wrappers::AssetWrapperBase* asset = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image);
        assert(asset != nullptr);

        asset->bind_offset = memoryOffset;

        vulkan_wrappers::DeviceMemoryWrapper* dev_mem_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
        assert(dev_mem_wrapper != nullptr);
        if (dev_mem_wrapper != nullptr)
        {
            assert(asset->size);

            asset->bind_memory_id      = dev_mem_wrapper->handle_id;
            asset->bind_memory_wrapper = dev_mem_wrapper;

            dev_mem_wrapper->asset_map_lock.lock();
            dev_mem_wrapper->bound_assets[memoryOffset] = asset;
            dev_mem_wrapper->asset_map_lock.unlock();
        }
    }
}

void VulkanCaptureManager::PostProcess_vkBindImageMemory2(VkResult                     result,
                                                          VkDevice                     device,
                                                          uint32_t                     bindInfoCount,
                                                          const VkBindImageMemoryInfo* pBindInfos)
{
    if ((result == VK_SUCCESS) && (pBindInfos != nullptr))
    {
        for (uint32_t i = 0; i < bindInfoCount; ++i)
        {
            assert((device != VK_NULL_HANDLE) && (pBindInfos[i].image != VK_NULL_HANDLE));

            auto wrapper         = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pBindInfos[i].image);
            wrapper->bind_device = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
            wrapper->bind_memory_id =
                vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceMemoryWrapper>(pBindInfos[i].memory);
            wrapper->bind_offset = pBindInfos[i].memoryOffset;
            wrapper->bind_pnext  = nullptr;

            vulkan_wrappers::DeviceMemoryWrapper* mem_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(pBindInfos[i].memory);
            assert(mem_wrapper != nullptr);

            // if (bind_info_pnext != nullptr)
            // {
            //     wrapper->bind_pnext = vulkan_trackers::TrackStruct(bind_info_pnext, wrapper->bind_pnext_memory);
            // }

            vulkan_wrappers::AssetWrapperBase* asset =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pBindInfos[i].image);
            assert(asset != nullptr);

            asset->bind_offset = pBindInfos->memoryOffset;

            vulkan_wrappers::DeviceMemoryWrapper* dev_mem_wrapper =
                vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(pBindInfos[i].memory);
            assert(dev_mem_wrapper != nullptr);
            if (dev_mem_wrapper != nullptr)
            {
                asset->bind_memory_id      = dev_mem_wrapper->handle_id;
                asset->bind_memory_wrapper = dev_mem_wrapper;

                assert(asset->size);

                dev_mem_wrapper->asset_map_lock.lock();
                dev_mem_wrapper->bound_assets[pBindInfos[i].memoryOffset] = asset;
                dev_mem_wrapper->asset_map_lock.unlock();
            }
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
