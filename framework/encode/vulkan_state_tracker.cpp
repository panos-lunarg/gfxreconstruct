/*
** Copyright (c) 2019-2024 LunarG, Inc.
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

#include "encode/vulkan_state_tracker.h"

#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_info.h"
#include "encode/custom_vulkan_struct_handle_wrappers.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_track_struct.h"
#include "graphics/vulkan_util.h"
#include "util/logging.h"
#include "util/platform.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"
#include "vulkan/vulkan_core.h"

#include "util/page_status_tracker.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VulkanStateTracker::VulkanStateTracker() {}

VulkanStateTracker::~VulkanStateTracker() {}

void VulkanStateTracker::TrackCommandExecution(vulkan_wrappers::CommandBufferWrapper* wrapper,
                                               format::ApiCallId                      call_id,
                                               const util::MemoryOutputStream*        parameter_buffer)
{
    assert(wrapper != nullptr);

    if ((call_id == format::ApiCallId::ApiCall_vkBeginCommandBuffer) ||
        (call_id == format::ApiCallId::ApiCall_vkResetCommandBuffer))
    {
        // Clear command data on command buffer reset.
        wrapper->command_data.Clear();
        wrapper->pending_layouts.clear();
        wrapper->recorded_queries.clear();
        wrapper->tlas_build_info_map.clear();
        wrapper->modified_assets.clear();

        for (size_t i = 0; i < vulkan_state_info::CommandHandleType::NumHandleTypes; ++i)
        {
            wrapper->command_handles[i].clear();
        }
    }

    if (call_id != format::ApiCallId::ApiCall_vkResetCommandBuffer)
    {
        // Append the command data.
        size_t size = parameter_buffer->GetDataSize();
        wrapper->command_data.Write(&size, sizeof(size));
        wrapper->command_data.Write(&call_id, sizeof(call_id));
        wrapper->command_data.Write(parameter_buffer->GetData(), size);
    }
}

void VulkanStateTracker::TrackTrimCommandPool(VkDevice device, VkCommandPool command_pool)
{
    assert(command_pool != VK_NULL_HANDLE);

    auto wrapper               = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandPoolWrapper>(command_pool);
    wrapper->trim_command_pool = true;

    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->device     = device_wrapper;
}

void VulkanStateTracker::TrackResetCommandPool(VkCommandPool command_pool)
{
    assert(command_pool != VK_NULL_HANDLE);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandPoolWrapper>(command_pool);

    for (const auto& entry : wrapper->child_buffers)
    {
        entry.second->command_data.Clear();
        entry.second->pending_layouts.clear();
        entry.second->recorded_queries.clear();
        entry.second->tlas_build_info_map.clear();
        entry.second->modified_assets.clear();

        for (size_t i = 0; i < vulkan_state_info::CommandHandleType::NumHandleTypes; ++i)
        {
            entry.second->command_handles[i].clear();
        }
    }
}

void VulkanStateTracker::TrackPhysicalDeviceMemoryProperties(VkPhysicalDevice                        physical_device,
                                                             const VkPhysicalDeviceMemoryProperties* properties)
{
    assert((physical_device != VK_NULL_HANDLE) && (properties != nullptr));

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device);

    wrapper->memory_properties = *properties;
}

void VulkanStateTracker::TrackPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice               physical_device,
                                                                  uint32_t                       property_count,
                                                                  const VkQueueFamilyProperties* properties)
{
    assert((physical_device != VK_NULL_HANDLE) && (properties != nullptr));

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device);
    wrapper->queue_family_properties_call_id = format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties;
    wrapper->queue_family_properties_count   = property_count;
    wrapper->queue_family_properties         = std::make_unique<VkQueueFamilyProperties[]>(property_count);
    memcpy(wrapper->queue_family_properties.get(), properties, property_count);
}

void VulkanStateTracker::TrackPhysicalDeviceQueueFamilyProperties2(format::ApiCallId               call_id,
                                                                   VkPhysicalDevice                physical_device,
                                                                   uint32_t                        property_count,
                                                                   const VkQueueFamilyProperties2* properties)
{
    assert((physical_device != VK_NULL_HANDLE) && (properties != nullptr));

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device);
    wrapper->queue_family_properties_call_id = call_id;
    wrapper->queue_family_properties_count   = property_count;
    wrapper->queue_family_properties2        = std::make_unique<VkQueueFamilyProperties2[]>(property_count);
    memcpy(wrapper->queue_family_properties2.get(), properties, property_count);

    // Copy pNext structure and update pNext pointers.
    for (uint32_t i = 0; i < property_count; ++i)
    {
        if (properties[i].pNext != nullptr)
        {
            const VkBaseOutStructure* next = reinterpret_cast<const VkBaseOutStructure*>(properties[i].pNext);
            if (next->sType == VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV)
            {
                const VkQueueFamilyCheckpointPropertiesNV* original =
                    reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(next);

                std::unique_ptr<VkQueueFamilyCheckpointPropertiesNV> copy =
                    std::make_unique<VkQueueFamilyCheckpointPropertiesNV>(*original);

                if (copy->pNext != nullptr)
                {
                    // At time of implementation, only VkQueueFamilyCheckpointPropertiesNV was allowed.
                    copy->pNext = nullptr;
                    GFXRECON_LOG_WARNING("Omitting unrecognized pNext structure from queue family properties tracking");
                }

                wrapper->queue_family_properties2[i].pNext = copy.get();
                wrapper->queue_family_checkpoint_properties.push_back(std::move(copy));
            }
            else
            {
                // At time of implementation, only VkQueueFamilyCheckpointPropertiesNV was allowed.
                wrapper->queue_family_properties2[i].pNext = nullptr;
                GFXRECON_LOG_WARNING("Omitting unrecognized pNext structure from queue family properties tracking");
            }
        }
    }
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceSupport(VkPhysicalDevice physical_device,
                                                           uint32_t         queue_family_index,
                                                           VkSurfaceKHR     surface,
                                                           VkBool32         supported)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE));

    auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
    auto& entry =
        wrapper
            ->surface_support[vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device)];
    entry[queue_family_index] = supported;
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceCapabilities(VkPhysicalDevice                physical_device,
                                                                VkSurfaceKHR                    surface,
                                                                const VkSurfaceCapabilitiesKHR* capabilities)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE) && (capabilities != nullptr));

    auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
    auto& entry   = wrapper->surface_capabilities[vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(
        physical_device)];

    entry.surface_info.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
    entry.surface_info.pNext   = nullptr;
    entry.surface_info.surface = surface;

    entry.surface_capabilities.sType               = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR;
    entry.surface_capabilities.pNext               = nullptr;
    entry.surface_capabilities.surfaceCapabilities = *capabilities;
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceCapabilities2(VkPhysicalDevice                       physical_device,
                                                                 const VkPhysicalDeviceSurfaceInfo2KHR& surface_info,
                                                                 VkSurfaceCapabilities2KHR* surface_capabilities)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface_info.surface != VK_NULL_HANDLE));

    auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface_info.surface);
    auto& entry   = wrapper->surface_capabilities[vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(
        physical_device)];

    entry.surface_info.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
    entry.surface_info.pNext   = nullptr;
    entry.surface_info.surface = surface_info.surface;

    if (surface_info.pNext != nullptr)
    {
        entry.surface_info.pNext = vulkan_trackers::TrackStruct(surface_info.pNext, entry.surface_info_pnext_memory);
    }

    entry.surface_capabilities.sType               = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR;
    entry.surface_capabilities.pNext               = nullptr;
    entry.surface_capabilities.surfaceCapabilities = surface_capabilities->surfaceCapabilities;

    if (surface_capabilities->pNext != nullptr)
    {
        entry.surface_capabilities.pNext =
            vulkan_trackers::TrackStruct(surface_capabilities->pNext, entry.surface_capabilities_pnext_memory);
    }
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceFormats(VkPhysicalDevice          physical_device,
                                                           VkSurfaceKHR              surface,
                                                           uint32_t                  format_count,
                                                           const VkSurfaceFormatKHR* formats)
{
    GFXRECON_ASSERT(physical_device != VK_NULL_HANDLE);

    if (surface != VK_NULL_HANDLE && format_count > 0)
    {
        auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
        auto& entry   = wrapper->surface_formats[vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(
            physical_device)];

        entry.surface_info.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
        entry.surface_info.pNext   = nullptr;
        entry.surface_info.surface = surface;

        std::vector<VkSurfaceFormat2KHR> surface_formats(format_count);

        for (uint32_t i = 0; i < format_count; ++i)
        {
            surface_formats[i].sType         = VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR;
            surface_formats[i].pNext         = nullptr;
            surface_formats[i].surfaceFormat = formats[i];
        }
        entry.surface_format_count = format_count;
        entry.surface_formats =
            vulkan_trackers::TrackStructs(surface_formats.data(), format_count, entry.surface_formats_memory);
    }
}

void VulkanStateTracker::TrackPhysicalDeviceSurfaceFormats2(VkPhysicalDevice                       physical_device,
                                                            const VkPhysicalDeviceSurfaceInfo2KHR& surface_info,
                                                            uint32_t                               surface_format_count,
                                                            VkSurfaceFormat2KHR*                   surface_formats)
{
    GFXRECON_ASSERT(physical_device != VK_NULL_HANDLE);

    if (surface_info.surface != VK_NULL_HANDLE && surface_format_count > 0)
    {
        auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface_info.surface);
        auto& entry   = wrapper->surface_formats[vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(
            physical_device)];

        entry.surface_info.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
        entry.surface_info.pNext   = nullptr;
        entry.surface_info.surface = surface_info.surface;

        if (surface_info.pNext != nullptr)
        {
            entry.surface_info.pNext =
                vulkan_trackers::TrackStruct(surface_info.pNext, entry.surface_info_pnext_memory);
        }

        entry.surface_format_count = surface_format_count;
        entry.surface_formats =
            vulkan_trackers::TrackStructs(surface_formats, surface_format_count, entry.surface_formats_memory);
    }
}

void VulkanStateTracker::TrackPhysicalDeviceSurfacePresentModes(VkPhysicalDevice        physical_device,
                                                                VkSurfaceKHR            surface,
                                                                uint32_t                mode_count,
                                                                const VkPresentModeKHR* modes,
                                                                const void*             surface_info_pnext)
{
    assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE) && (modes != nullptr));

    auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
    auto& entry = wrapper->surface_present_modes[vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(
        physical_device)];
    entry.present_modes.assign(modes, modes + mode_count);

    entry.surface_info_pnext = nullptr;
    if (surface_info_pnext != nullptr)
    {
        entry.surface_info_pnext = vulkan_trackers::TrackStruct(surface_info_pnext, entry.surface_info_pnext_memory);
    }
}

void VulkanStateTracker::TrackDeviceGroupSurfacePresentModes(VkDevice                          device,
                                                             VkSurfaceKHR                      surface,
                                                             VkDeviceGroupPresentModeFlagsKHR* pModes,
                                                             const void*                       surface_info_pnext)
{
    assert((device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE) && (pModes != nullptr));

    auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SurfaceKHRWrapper>(surface);
    auto& entry =
        wrapper->group_surface_present_modes[vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device)];
    entry.present_modes = *pModes;

    entry.surface_info_pnext = nullptr;
    if (surface_info_pnext != nullptr)
    {
        entry.surface_info_pnext = vulkan_trackers::TrackStruct(surface_info_pnext, entry.surface_info_pnext_memory);
    }
}

void VulkanStateTracker::TrackBufferDeviceAddress(VkDevice device, VkBuffer buffer, VkDeviceAddress address)
{
    assert((device != VK_NULL_HANDLE) && (buffer != VK_NULL_HANDLE));

    auto wrapper       = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(buffer);
    wrapper->device_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->address   = address;
}

void VulkanStateTracker::TrackTLASBuildCommand(
    VkCommandBuffer                                        command_buffer,
    uint32_t                                               info_count,
    const VkAccelerationStructureBuildGeometryInfoKHR*     infos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* pp_buildRange_infos)
{
    if (info_count && infos && pp_buildRange_infos)
    {
        vulkan_wrappers::CommandBufferWrapper* buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);

        for (uint32_t i = 0; i < info_count; ++i)
        {
            if (infos[i].type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR &&
                infos[i].dstAccelerationStructure != VK_NULL_HANDLE && infos[i].geometryCount && infos[i].pGeometries)
            {
                vulkan_wrappers::AccelerationStructureKHRWrapper* tlas_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                        infos[i].dstAccelerationStructure);

                tlas_wrapper->blas.clear();

                for (uint32_t g = 0; g < infos[i].geometryCount; ++g)
                {
                    if (infos[i].pGeometries[g].geometryType == VK_GEOMETRY_TYPE_INSTANCES_KHR)
                    {
                        const VkDeviceAddress address = infos[i].pGeometries[g].geometry.instances.data.deviceAddress;
                        const uint32_t        primitive_count = pp_buildRange_infos[i]->primitiveCount;
                        // According to spec both address and primitiveCount can be 0.
                        // Nothing to handle in these cases.
                        if (address && primitive_count)
                        {
                            const vulkan_wrappers::CommandBufferWrapper::tlas_build_info tlas_info = {
                                address, primitive_count, pp_buildRange_infos[i]->primitiveOffset
                            };

                            buf_wrapper->tlas_build_info_map.emplace_back(
                                std::make_pair(tlas_wrapper, std::move(tlas_info)));
                        }
                    }
                }
            }
        }
    }
}

void VulkanStateTracker::TrackBeginRenderPass(VkCommandBuffer command_buffer, const VkRenderPassBeginInfo* begin_info)
{
    assert((command_buffer != VK_NULL_HANDLE) && (begin_info != nullptr));

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    wrapper->active_render_pass =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::RenderPassWrapper>(begin_info->renderPass);
    wrapper->render_pass_framebuffer =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::FramebufferWrapper>(begin_info->framebuffer);

    if (wrapper->render_pass_framebuffer != nullptr)
    {
        for (size_t i = 0; i < wrapper->render_pass_framebuffer->attachments.size(); ++i)
        {
            if (wrapper->render_pass_framebuffer->attachments[i]->is_swapchain_image)
            {
                continue;
            }

            const bool has_stencil = vkuFormatHasStencil(wrapper->render_pass_framebuffer->attachments[i]->format);
            if ((!has_stencil &&
                 wrapper->active_render_pass->attachment_info.store_op[i] == VK_ATTACHMENT_STORE_OP_STORE) ||
                (has_stencil &&
                 wrapper->active_render_pass->attachment_info.stencil_store_op[i] == VK_ATTACHMENT_STORE_OP_STORE))
            {
                wrapper->modified_assets.insert(wrapper->render_pass_framebuffer->attachments[i]);
            }
        }
    }
}

void VulkanStateTracker::TrackEndRenderPass(VkCommandBuffer command_buffer)
{
    assert(command_buffer != VK_NULL_HANDLE);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    assert((wrapper->active_render_pass != VK_NULL_HANDLE) && (wrapper->render_pass_framebuffer != VK_NULL_HANDLE));

    auto render_pass_wrapper = wrapper->active_render_pass;
    auto framebuffer_wrapper = wrapper->render_pass_framebuffer;
    assert((framebuffer_wrapper != nullptr) && (render_pass_wrapper != nullptr));

    uint32_t attachment_count = static_cast<uint32_t>(framebuffer_wrapper->attachments.size());
    assert(attachment_count <= render_pass_wrapper->attachment_info.attachment_final_layouts.size());

    for (uint32_t i = 0; i < attachment_count; ++i)
    {
        wrapper->pending_layouts[framebuffer_wrapper->attachments[i]] =
            render_pass_wrapper->attachment_info.attachment_final_layouts[i];
    }

    // Clear the active render pass state now that the pass has ended.
    wrapper->active_render_pass      = nullptr;
    wrapper->render_pass_framebuffer = nullptr;
}

void VulkanStateTracker::TrackExecuteCommands(VkCommandBuffer        command_buffer,
                                              uint32_t               command_buffer_count,
                                              const VkCommandBuffer* command_buffers)
{
    assert((command_buffer != VK_NULL_HANDLE) && (command_buffers != nullptr));

    auto primary_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);

    for (uint32_t i = 0; i < command_buffer_count; ++i)
    {
        auto secondary_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffers[i]);
        assert(secondary_wrapper != nullptr);

        for (const auto& layout_entry : secondary_wrapper->pending_layouts)
        {
            primary_wrapper->pending_layouts[layout_entry.first] = layout_entry.second;
        }

        for (const auto& secondary_query_pool_entry : secondary_wrapper->recorded_queries)
        {
            auto& primary_query_pool_info = primary_wrapper->recorded_queries[secondary_query_pool_entry.first];

            for (const auto& secondary_query_entry : secondary_query_pool_entry.second)
            {
                auto& primary_query_info  = primary_query_pool_info[secondary_query_entry.first];
                primary_query_info.active = secondary_query_entry.second.active;

                if (primary_query_info.active)
                {
                    primary_query_info.flags              = secondary_query_entry.second.flags;
                    primary_query_info.query_type_index   = secondary_query_entry.second.query_type_index;
                    primary_query_info.queue_family_index = secondary_query_entry.second.queue_family_index;
                }
            }
        }
    }
}

void VulkanStateTracker::TrackImageBarriers(VkCommandBuffer             command_buffer,
                                            uint32_t                    image_barrier_count,
                                            const VkImageMemoryBarrier* image_barriers)
{
    assert(command_buffer != VK_NULL_HANDLE);

    if ((image_barrier_count > 0) && (image_barriers != nullptr))
    {
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);

        for (uint32_t i = 0; i < image_barrier_count; ++i)
        {
            auto image_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image_barriers[i].image);
            wrapper->pending_layouts[image_wrapper] = image_barriers[i].newLayout;
        }
    }
}

void VulkanStateTracker::TrackImageBarriers2KHR(VkCommandBuffer                 command_buffer,
                                                uint32_t                        image_barrier_count,
                                                const VkImageMemoryBarrier2KHR* image_barriers)
{
    assert(command_buffer != VK_NULL_HANDLE);

    if ((image_barrier_count > 0) && (image_barriers != nullptr))
    {
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);

        for (uint32_t i = 0; i < image_barrier_count; ++i)
        {
            auto image_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image_barriers[i].image);
            wrapper->pending_layouts[image_wrapper] = image_barriers[i].newLayout;
        }
    }
}

void VulkanStateTracker::TrackCommandBufferSubmissions(uint32_t submit_count, const VkSubmitInfo* submits)
{
    if ((submit_count > 0) && (submits != nullptr) && (submits->commandBufferCount > 0))
    {
        for (uint32_t submit = 0; submit < submit_count; ++submit)
        {
            uint32_t               command_buffer_count = submits[submit].commandBufferCount;
            const VkCommandBuffer* command_buffers      = submits[submit].pCommandBuffers;

            for (uint32_t cmd = 0; cmd < command_buffer_count; ++cmd)
            {
                auto command_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffers[cmd]);
                assert(command_wrapper != nullptr);

                TrackQuerySubmissions(command_wrapper);
            }
        }
    }
}

void VulkanStateTracker::TrackCommandBufferSubmissions2(uint32_t submit_count, const VkSubmitInfo2* submits)
{
    if ((submit_count > 0) && (submits != nullptr) && (submits->commandBufferInfoCount > 0))
    {
        for (uint32_t submit = 0; submit < submit_count; ++submit)
        {
            uint32_t                         command_buffer_count = submits[submit].commandBufferInfoCount;
            const VkCommandBufferSubmitInfo* command_buffer_infos = submits[submit].pCommandBufferInfos;

            for (uint32_t cmd = 0; cmd < command_buffer_count; ++cmd)
            {
                auto command_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(
                    command_buffer_infos[cmd].commandBuffer);
                assert(command_wrapper != nullptr);

                TrackQuerySubmissions(command_wrapper);
            }
        }
    }
}

void VulkanStateTracker::TrackQuerySubmissions(vulkan_wrappers::CommandBufferWrapper* command_wrapper)
{
    // Apply pending image layouts.
    for (const auto& layout_entry : command_wrapper->pending_layouts)
    {
        auto image_wrapper = layout_entry.first;
        assert(image_wrapper != nullptr);

        image_wrapper->current_layout = layout_entry.second;
    }

    // Apply pending query activations.
    for (const auto& query_pool_entry : command_wrapper->recorded_queries)
    {
        auto query_pool_wrapper = query_pool_entry.first;
        assert(query_pool_wrapper != nullptr);

        for (const auto& query_entry : query_pool_entry.second)
        {
            auto& query_info  = query_pool_wrapper->pending_queries[query_entry.first];
            query_info.active = query_entry.second.active;

            if (query_info.active)
            {
                query_info.flags              = query_entry.second.flags;
                query_info.query_type_index   = query_entry.second.query_type_index;
                query_info.queue_family_index = query_entry.second.queue_family_index;
            }
        }
    }
}

void VulkanStateTracker::TrackResetDescriptorPool(VkDescriptorPool descriptor_pool)
{
    assert(descriptor_pool != VK_NULL_HANDLE);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorPoolWrapper>(descriptor_pool);

    // Pool reset implicitly frees descriptor sets, so remove all wrappers from the state tracker.
    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (const auto& set_entry : wrapper->child_sets)
    {
        state_table_.RemoveWrapper(set_entry.second);
    }
}

void VulkanStateTracker::TrackQueryActivation(
    VkCommandBuffer command_buffer, VkQueryPool query_pool, uint32_t query, VkQueryControlFlags flags, uint32_t index)
{
    assert((command_buffer != VK_NULL_HANDLE) && (query_pool != VK_NULL_HANDLE));

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    const vulkan_wrappers::CommandPoolWrapper* command_pool_wrapper = wrapper->parent_pool;

    auto& query_pool_info =
        wrapper->recorded_queries[vulkan_wrappers::GetWrapper<vulkan_wrappers::QueryPoolWrapper>(query_pool)];
    auto& query_info              = query_pool_info[query];
    query_info.active             = true;
    query_info.flags              = flags;
    query_info.query_type_index   = index;
    query_info.queue_family_index = command_pool_wrapper->queue_family_index;
}

void VulkanStateTracker::TrackQueryReset(VkCommandBuffer command_buffer,
                                         VkQueryPool     query_pool,
                                         uint32_t        first_query,
                                         uint32_t        query_count)
{
    assert((command_buffer != VK_NULL_HANDLE) && (query_pool != VK_NULL_HANDLE));

    auto  wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    auto& query_pool_info =
        wrapper->recorded_queries[vulkan_wrappers::GetWrapper<vulkan_wrappers::QueryPoolWrapper>(query_pool)];

    for (uint32_t i = first_query; i < query_count; ++i)
    {
        query_pool_info[i].active = false;
    }
}

void VulkanStateTracker::TrackQueryReset(VkQueryPool query_pool, uint32_t first_query, uint32_t query_count)
{
    assert(query_pool != VK_NULL_HANDLE);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::QueryPoolWrapper>(query_pool);
    assert((first_query + query_count) <= wrapper->pending_queries.size());

    for (uint32_t i = first_query; i < query_count; ++i)
    {
        wrapper->pending_queries[i].active = false;
    }
}

void VulkanStateTracker::TrackSemaphoreSignalState(VkSemaphore signal)
{
    if (signal != VK_NULL_HANDLE)
    {
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(signal);
        assert(wrapper != nullptr);
        wrapper->signaled = true;
    }
}

void VulkanStateTracker::TrackSemaphoreSignalState(uint32_t           wait_count,
                                                   const VkSemaphore* waits,
                                                   uint32_t           signal_count,
                                                   const VkSemaphore* signals)
{
    if (((waits != nullptr) && (wait_count > 0)) || ((signals != nullptr) && (signal_count > 0)))
    {
        if (waits != nullptr)
        {
            for (uint32_t i = 0; i < wait_count; ++i)
            {
                auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(waits[i]);
                assert(wrapper != nullptr);
                wrapper->signaled = false;
            }
        }

        if (signals != nullptr)
        {
            for (uint32_t i = 0; i < signal_count; ++i)
            {
                auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(signals[i]);
                assert(wrapper != nullptr);
                wrapper->signaled = true;
            }
        }
    }
}

void VulkanStateTracker::TrackSemaphoreInfoSignalState(uint32_t                     wait_count,
                                                       const VkSemaphoreSubmitInfo* wait_infos,
                                                       uint32_t                     signal_count,
                                                       const VkSemaphoreSubmitInfo* signal_infos)
{
    if (((wait_infos != nullptr) && (wait_count > 0)) || ((signal_infos != nullptr) && (signal_count > 0)))
    {
        if (wait_infos != nullptr)
        {
            for (uint32_t i = 0; i < wait_count; ++i)
            {
                auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(wait_infos[i].semaphore);
                assert(wrapper != nullptr);
                wrapper->signaled = false;
            }
        }

        if (signal_infos != nullptr)
        {
            for (uint32_t i = 0; i < signal_count; ++i)
            {
                auto wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::SemaphoreWrapper>(signal_infos[i].semaphore);
                assert(wrapper != nullptr);
                wrapper->signaled = true;
            }
        }
    }
}

void VulkanStateTracker::TrackAcquireImage(
    uint32_t image_index, VkSwapchainKHR swapchain, VkSemaphore semaphore, VkFence fence, uint32_t deviceMask)
{
    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchain);

    assert(wrapper != nullptr);

    if (image_index >= wrapper->image_acquired_info.size())
    {
        wrapper->image_acquired_info.resize(image_index + 1);
        wrapper->image_acquired_info[image_index].last_presented_queue = VK_NULL_HANDLE;
    }

    wrapper->image_acquired_info[image_index].is_acquired          = true;
    wrapper->image_acquired_info[image_index].acquired_device_mask = deviceMask;
    wrapper->image_acquired_info[image_index].acquired_semaphore_id =
        vulkan_wrappers::GetWrappedId<vulkan_wrappers::SemaphoreWrapper>(semaphore);
    wrapper->image_acquired_info[image_index].acquired_fence_id =
        vulkan_wrappers::GetWrappedId<vulkan_wrappers::FenceWrapper>(fence);
}

void VulkanStateTracker::TrackPresentedImages(uint32_t              count,
                                              const VkSwapchainKHR* swapchains,
                                              const uint32_t*       image_indices,
                                              VkQueue               queue)
{
    assert((count > 0) && (swapchains != nullptr) && (image_indices != nullptr));

    for (uint32_t i = 0; i < count; ++i)
    {
        auto     wrapper     = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchains[i]);
        uint32_t image_index = image_indices[i];

        assert((wrapper != nullptr) && (image_index < wrapper->image_acquired_info.size()));

        wrapper->last_presented_image                                  = image_index;
        wrapper->image_acquired_info[image_index].is_acquired          = false;
        wrapper->image_acquired_info[image_index].last_presented_queue = queue;
    }
}

void VulkanStateTracker::TrackAccelerationStructureKHRDeviceAddress(VkDevice                   device,
                                                                    VkAccelerationStructureKHR accel_struct,
                                                                    VkDeviceAddress            address)
{
    assert((device != VK_NULL_HANDLE) && (accel_struct != VK_NULL_HANDLE));

    auto wrapper       = vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(accel_struct);
    wrapper->device_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->address   = address;

    assert(address);
    as_device_addresses_map.emplace(address, wrapper);
}

void VulkanStateTracker::TrackDeviceMemoryDeviceAddress(VkDevice device, VkDeviceMemory memory, VkDeviceAddress address)
{
    assert((device != VK_NULL_HANDLE) && (memory != VK_NULL_HANDLE));

    auto wrapper       = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    wrapper->device_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->address   = address;

    device_memory_addresses_map.emplace(address, wrapper);
}

void VulkanStateTracker::TrackRayTracingShaderGroupHandles(VkDevice    device,
                                                           VkPipeline  pipeline,
                                                           size_t      data_size,
                                                           const void* data)
{
    assert((device != VK_NULL_HANDLE) && (pipeline != VK_NULL_HANDLE));

    auto           wrapper   = vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(pipeline);
    const uint8_t* byte_data = reinterpret_cast<const uint8_t*>(data);
    wrapper->device_id       = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
    wrapper->shader_group_handle_data.assign(byte_data, byte_data + data_size);
}

void VulkanStateTracker::TrackAcquireFullScreenExclusiveMode(VkDevice device, VkSwapchainKHR swapchain)
{
    assert(swapchain != VK_NULL_HANDLE);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchain);
    wrapper->acquire_full_screen_exclusive_mode = true;
}

void VulkanStateTracker::TrackReleaseFullScreenExclusiveMode(VkDevice device, VkSwapchainKHR swapchain)
{
    assert(swapchain != VK_NULL_HANDLE);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchain);
    wrapper->release_full_screen_exclusive_mode = true;
}

void VulkanStateTracker::TrackSetPrivateData(
    VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data)
{
    assert(privateDataSlot != VK_NULL_HANDLE);

    auto wrapper        = vulkan_wrappers::GetWrapper<vulkan_wrappers::PrivateDataSlotWrapper>(privateDataSlot);
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);

    wrapper->device        = device_wrapper;
    wrapper->object_type   = objectType;
    wrapper->object_handle = vulkan_wrappers::GetWrappedId(objectHandle, objectType);
    wrapper->data          = data;
}

void VulkanStateTracker::TrackSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable)
{
    assert(swapChain != VK_NULL_HANDLE);

    auto wrapper        = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapChain);
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);

    wrapper->device                   = device_wrapper;
    wrapper->using_local_dimming_AMD  = true;
    wrapper->local_dimming_enable_AMD = localDimmingEnable;
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::InstanceWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Physical devices are not explicitly destroyed, so need to be removed from the state tracker when their parent
    // instance is destroyed.
    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (const auto physical_device_entry : wrapper->child_physical_devices)
    {
        for (const auto display_entry : physical_device_entry->child_displays)
        {
            for (const auto display_mode_entry : display_entry->child_display_modes)
            {
                state_table_.RemoveWrapper(display_mode_entry);
            }

            state_table_.RemoveWrapper(display_entry);
        }

        state_table_.RemoveWrapper(physical_device_entry);
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::DeviceWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Queues are not explicitly destroyed, so need to be removed from the state tracker when their parent device is
    // destroyed.
    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (const auto& entry : wrapper->child_queues)
    {
        state_table_.RemoveWrapper(entry);
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::CommandPoolWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Destroying the pool implicitly destroys objects allocated from the pool, which need to be removed from state
    // tracking.
    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (const auto& entry : wrapper->child_buffers)
    {
        state_table_.RemoveWrapper(entry.second);
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::DescriptorPoolWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Destroying the pool implicitly destroys objects allocated from the pool, which need to be removed from state
    // tracking.
    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (const auto& entry : wrapper->child_sets)
    {
        state_table_.RemoveWrapper(entry.second);
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::SwapchainKHRWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    // Swapchain images are not explicitly destroyed, so need to be removed from state tracking when the parent
    // swapchain is destroyed.
    std::unique_lock<std::mutex> lock(state_table_mutex_);
    for (auto entry : wrapper->child_images)
    {
        state_table_.RemoveWrapper(entry);
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::DeviceMemoryWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    const auto& entry = device_memory_addresses_map.find(wrapper->address);
    if (entry != device_memory_addresses_map.end())
    {
        device_memory_addresses_map.erase(entry);
    }
}

void VulkanStateTracker::DestroyState(vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper)
{
    assert(wrapper != nullptr);
    wrapper->create_parameters = nullptr;

    const auto& entry = as_device_addresses_map.find(wrapper->address);
    if (entry != as_device_addresses_map.end())
    {
        as_device_addresses_map.erase(entry);
    }
}

void VulkanStateTracker::TrackTlasToBlasDependencies(uint32_t               command_buffer_count,
                                                     const VkCommandBuffer* command_buffers)
{
    if (!command_buffer_count || !command_buffers)
    {
        return;
    }

    for (uint32_t c = 0; c < command_buffer_count; ++c)
    {
        const vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffers[c]);

        for (const auto& tlas_build_info : cmd_buf_wrapper->tlas_build_info_map)
        {
            // Sanity checks. Build infos with one of these 0 should not be inserted in the map
            assert(tlas_build_info.second.address);
            assert(tlas_build_info.second.blas_count);

            // Find to which device memory this address belongs
            const VkDeviceAddress                       address         = tlas_build_info.second.address;
            const vulkan_wrappers::DeviceMemoryWrapper* dev_mem_wrapper = nullptr;
            for (const auto& dev_mem : device_memory_addresses_map)
            {
                if (address >= dev_mem.second->address &&
                    address < dev_mem.second->address + dev_mem.second->allocation_size)
                {
                    dev_mem_wrapper = dev_mem.second;
                    break;
                }
            }

            assert(dev_mem_wrapper);
            if (!dev_mem_wrapper)
            {
                continue;
            }

            assert(dev_mem_wrapper->address);
            assert(address >= dev_mem_wrapper->address);

            // Calculate total offset:
            //  address:        The address of the buffer where the
            //                  VkAccelerationStructureInstanceKHRs are located.
            //  base_address:   The device address of the device memory where
            //                  the buffer is bound.
            //  buffer_offset:  The offset within the buffer as provided in the
            //                  BuildAccelerationStructureKHR command.
            const VkDeviceAddress base_address  = dev_mem_wrapper->address;
            const VkDeviceAddress buffer_offset = tlas_build_info.second.offset;
            const VkDeviceSize    total_offset  = (address - base_address) + buffer_offset;

            const VkAccelerationStructureInstanceKHR* instances = nullptr;
            const util::PageGuardManager*             manager   = util::PageGuardManager::Get();

            // Check with page guard manager first. The memory might be already and the
            // PageGuardManager can provide the pointer
            if (manager)
            {
                const void* mapped_memory = manager->GetMappedMemory(dev_mem_wrapper->handle_id);
                if (mapped_memory)
                {
                    instances = reinterpret_cast<const VkAccelerationStructureInstanceKHR*>(
                        static_cast<const uint8_t*>(mapped_memory) + total_offset);
                }
            }

            const uint32_t blas_count      = tlas_build_info.second.blas_count;
            bool           needs_unmapping = false;
            if (!instances)
            {
                // If PageGuardManager is not used or if it couldn't find the memory id it means that
                // we need to map the memory.
                VkDevice                 device        = dev_mem_wrapper->parent_device->handle;
                const VulkanDeviceTable* device_table  = vulkan_wrappers::GetDeviceTable(device);
                const VkDeviceSize       map_size      = sizeof(VkAccelerationStructureInstanceKHR) * blas_count;
                void*                    mapped_memory = nullptr;
                const VkResult           result =
                    device_table->MapMemory(device, dev_mem_wrapper->handle, total_offset, map_size, 0, &mapped_memory);

                if (result == VK_SUCCESS)
                {
                    needs_unmapping = true;

                    instances = reinterpret_cast<const VkAccelerationStructureInstanceKHR*>(mapped_memory);
                }
            }

            if (instances)
            {
                vulkan_wrappers::AccelerationStructureKHRWrapper* tlas_wrapper = tlas_build_info.first;

                for (uint32_t b = 0; b < blas_count; ++b)
                {
                    // Find to which BLAS the device address stored in
                    // VkAccelerationStructureInstanceKHR::accelerationStructureReference referes to
                    const uint64_t as_reference = instances[b].accelerationStructureReference;

                    const auto blas_dev_mem_pair = as_device_addresses_map.find(as_reference);
                    if (blas_dev_mem_pair != as_device_addresses_map.end())
                    {
                        tlas_wrapper->blas.push_back(blas_dev_mem_pair->second);
                    }
                }

                // If we had to map the device memory unmap it now
                if (needs_unmapping)
                {
                    VkDevice                 device       = dev_mem_wrapper->parent_device->handle;
                    const VulkanDeviceTable* device_table = vulkan_wrappers::GetDeviceTable(device);
                    device_table->UnmapMemory(device, dev_mem_wrapper->handle);
                }
            }
        }
    }
}

void VulkanStateTracker::TrackCmdCopyBuffer(VkCommandBuffer     commandBuffer,
                                            VkBuffer            srcBuffer,
                                            VkBuffer            dstBuffer,
                                            uint32_t            regionCount,
                                            const VkBufferCopy* pRegions)
{
    if (dstBuffer != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* dst_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(dstBuffer);
        assert(dst_buffer_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_buffer_wrapper);
    }
}

void VulkanStateTracker::TrackCmdCopyImage(VkCommandBuffer    commandBuffer,
                                           VkImage            srcImage,
                                           VkImageLayout      srcImageLayout,
                                           VkImage            dstImage,
                                           VkImageLayout      dstImageLayout,
                                           uint32_t           regionCount,
                                           const VkImageCopy* pRegions)
{
    if (dstImage != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* dst_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(dstImage);
        assert(dst_img_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_img_wrapper);
    }
}

void VulkanStateTracker::TrackCmdCopyBufferToImage(VkCommandBuffer          commandBuffer,
                                                   VkBuffer                 srcBuffer,
                                                   VkImage                  dstImage,
                                                   VkImageLayout            dstImageLayout,
                                                   uint32_t                 regionCount,
                                                   const VkBufferImageCopy* pRegions)
{
    if (dstImage != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* dst_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(dstImage);
        assert(dst_img_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_img_wrapper);
    }
}

void VulkanStateTracker::TrackCmdCopyImageToBuffer(VkCommandBuffer          commandBuffer,
                                                   VkImage                  srcImage,
                                                   VkImageLayout            srcImageLayout,
                                                   VkBuffer                 dstBuffer,
                                                   uint32_t                 regionCount,
                                                   const VkBufferImageCopy* pRegions)
{
    if (dstBuffer != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* dst_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(dstBuffer);
        assert(dst_buffer_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_buffer_wrapper);
    }
}

void VulkanStateTracker::TrackCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo)
{
    if (pCopyBufferInfo != nullptr && pCopyBufferInfo->dstBuffer != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* dst_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pCopyBufferInfo->dstBuffer);
        assert(dst_buffer_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_buffer_wrapper);
    }
}

void VulkanStateTracker::TrackCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo)
{
    if (pCopyImageInfo != nullptr && pCopyImageInfo->dstImage != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* dst_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pCopyImageInfo->dstImage);
        assert(dst_img_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_img_wrapper);
    }
}

void VulkanStateTracker::TrackCmdCopyBufferToImage2(VkCommandBuffer                 commandBuffer,
                                                    const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    if (pCopyBufferToImageInfo != nullptr && pCopyBufferToImageInfo->dstImage != VK_NULL_HANDLE &&
        commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* dst_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pCopyBufferToImageInfo->dstImage);
        assert(dst_img_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_img_wrapper);
    }
}

void VulkanStateTracker::TrackCmdCopyImageToBuffer2(VkCommandBuffer                 commandBuffer,
                                                    const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    if (pCopyImageToBufferInfo != nullptr && pCopyImageToBufferInfo->dstBuffer != VK_NULL_HANDLE &&
        commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* dst_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pCopyImageToBufferInfo->dstBuffer);
        assert(dst_buffer_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_buffer_wrapper);
    }
}

void VulkanStateTracker::TrackCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo)
{
    if (pCopyBufferInfo != nullptr && pCopyBufferInfo->dstBuffer != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* dst_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pCopyBufferInfo->dstBuffer);
        assert(dst_buffer_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_buffer_wrapper);
    }
}

void VulkanStateTracker::TrackCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo)
{
    if (pCopyImageInfo != nullptr && pCopyImageInfo->dstImage != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* dst_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pCopyImageInfo->dstImage);
        assert(dst_img_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_img_wrapper);
    }
}

void VulkanStateTracker::TrackCmdCopyBufferToImage2KHR(VkCommandBuffer                 commandBuffer,
                                                       const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    if (pCopyBufferToImageInfo != nullptr && pCopyBufferToImageInfo->dstImage != VK_NULL_HANDLE &&
        commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* dst_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pCopyBufferToImageInfo->dstImage);
        assert(dst_img_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_img_wrapper);
    }
}

void VulkanStateTracker::TrackCmdCopyImageToBuffer2KHR(VkCommandBuffer                 commandBuffer,
                                                       const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    if (pCopyImageToBufferInfo != nullptr && pCopyImageToBufferInfo->dstBuffer != VK_NULL_HANDLE &&
        commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* dst_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pCopyImageToBufferInfo->dstBuffer);
        assert(dst_buffer_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_buffer_wrapper);
    }
}

void VulkanStateTracker::TrackCmdBlitImage(VkCommandBuffer    commandBuffer,
                                           VkImage            srcImage,
                                           VkImageLayout      srcImageLayout,
                                           VkImage            dstImage,
                                           VkImageLayout      dstImageLayout,
                                           uint32_t           regionCount,
                                           const VkImageBlit* pRegions,
                                           VkFilter           filter)
{
    if (dstImage != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* dst_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(dstImage);
        assert(dst_img_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_img_wrapper);
    }
}

void VulkanStateTracker::TrackCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo)
{
    if (pBlitImageInfo != nullptr && pBlitImageInfo->dstImage != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* dst_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pBlitImageInfo->dstImage);
        assert(dst_img_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_img_wrapper);
    }
}

void VulkanStateTracker::TrackCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo)
{
    TrackCmdBlitImage2(commandBuffer, pBlitImageInfo);
}

void VulkanStateTracker::TrackCmdUpdateBuffer(
    VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData)
{
    if (dstBuffer != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* dst_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(dstBuffer);
        assert(dst_buffer_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_buffer_wrapper);
    }
}

void VulkanStateTracker::TrackCmdFillBuffer(
    VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data)
{
    if (dstBuffer != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* dst_buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(dstBuffer);
        assert(dst_buffer_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_buffer_wrapper);
    }
}

void VulkanStateTracker::TrackCmdClearColorImage(VkCommandBuffer                commandBuffer,
                                                 VkImage                        image,
                                                 VkImageLayout                  imageLayout,
                                                 const VkClearColorValue*       pColor,
                                                 uint32_t                       rangeCount,
                                                 const VkImageSubresourceRange* pRanges)
{
    if (image != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* dst_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image);
        assert(dst_img_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_img_wrapper);
    }
}

void VulkanStateTracker::TrackCmdClearDepthStencilImage(VkCommandBuffer                 commandBuffer,
                                                        VkImage                         image,
                                                        VkImageLayout                   imageLayout,
                                                        const VkClearDepthStencilValue* pDepthStencil,
                                                        uint32_t                        rangeCount,
                                                        const VkImageSubresourceRange*  pRanges)
{
    if (image != VK_NULL_HANDLE && commandBuffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* dst_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image);
        assert(dst_img_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_img_wrapper);
    }
}

void VulkanStateTracker::TrackCmdResolveImage(VkCommandBuffer       commandBuffer,
                                              VkImage               srcImage,
                                              VkImageLayout         srcImageLayout,
                                              VkImage               dstImage,
                                              VkImageLayout         dstImageLayout,
                                              uint32_t              regionCount,
                                              const VkImageResolve* pRegions)
{
    if (dstImage != VK_NULL_HANDLE && dstImage != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* dst_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(dstImage);
        assert(dst_img_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_img_wrapper);
    }
}

void VulkanStateTracker::TrackCmdResolveImage2(VkCommandBuffer            commandBuffer,
                                               const VkResolveImageInfo2* pResolveImageInfo)
{
    if (commandBuffer != VK_NULL_HANDLE && pResolveImageInfo != nullptr &&
        pResolveImageInfo->dstImage != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* dst_img_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pResolveImageInfo->dstImage);
        assert(dst_img_wrapper != nullptr);

        cmd_buf_wrapper->modified_assets.insert(dst_img_wrapper);
    }
}

void VulkanStateTracker::TrackCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask)
{
    if (taskCount)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanStateTracker::TrackCmdDrawMeshTasksIndirectNV(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    if (drawCount)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanStateTracker::TrackCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer,
                                                              VkBuffer        buffer,
                                                              VkDeviceSize    offset,
                                                              VkBuffer        countBuffer,
                                                              VkDeviceSize    countBufferOffset,
                                                              uint32_t        maxDrawCount,
                                                              uint32_t        stride)
{
    if (maxDrawCount)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanStateTracker::TrackCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer,
                                                  uint32_t        groupCountX,
                                                  uint32_t        groupCountY,
                                                  uint32_t        groupCountZ)
{
    if (groupCountX && groupCountY && groupCountZ)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanStateTracker::TrackCmdDrawMeshTasksIndirectEXT(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    if (drawCount)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanStateTracker::TrackCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer,
                                                               VkBuffer        buffer,
                                                               VkDeviceSize    offset,
                                                               VkBuffer        countBuffer,
                                                               VkDeviceSize    countBufferOffset,
                                                               uint32_t        maxDrawCount,
                                                               uint32_t        stride)
{
    if (maxDrawCount)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanStateTracker::TrackMappedAssetsWrites(vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper)
{
    assert(cmd_buf_wrapper != nullptr);

    // Nothing to do if there's no active manager
    util::PageGuardManager* manager = util::PageGuardManager::Get();
    if (manager == nullptr)
    {
        return;
    }

    std::unordered_map<uint64_t, util::PageStatusTracker::PageStatus&> memories_page_status;
    manager->GetModifiedMemoryRegions(memories_page_status);
    const size_t page_size = util::platform::GetSystemPageSize();

    for (const auto& entry : memories_page_status)
    {
        vulkan_wrappers::DeviceMemoryWrapper* dev_mem_wrapper = state_table_.GetDeviceMemoryWrapper(entry.first);
        assert(dev_mem_wrapper != nullptr);

        dev_mem_wrapper->asset_map_lock.lock();
        for (auto& asset : dev_mem_wrapper->bound_assets)
        {
            if (asset.second->dirty || !asset.second->size)
            {
                continue;
            }

            const size_t first_page = asset.first / page_size;
            const size_t last_page  = (asset.first + asset.second->size - 1) / page_size;

            assert(first_page <= last_page);
            assert(first_page <= entry.second.size());

            for (size_t page = first_page; page < entry.second.size() && page <= last_page; ++page)
            {
                if (entry.second[page])
                {
                    asset.second->dirty = true;
                    break;
                }
            }
        }
        dev_mem_wrapper->asset_map_lock.unlock();
    }
}

void VulkanStateTracker::TrackPipelineDescriptors(vulkan_wrappers::CommandBufferWrapper* command_wrapper,
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
                            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                            {
                                for (uint32_t i = 0; i < descriptor_binding->second.count; ++i)
                                {
                                    vulkan_wrappers::ImageViewWrapper* img_view_wrapper =
                                        vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                                            descriptor_binding->second.storage_images[i].imageView);

                                    if (img_view_wrapper != nullptr && img_view_wrapper->image != nullptr)
                                    {
                                        command_wrapper->modified_assets.insert(img_view_wrapper->image);
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
                                        command_wrapper->modified_assets.insert(buf_wrapper);
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
                                        command_wrapper->modified_assets.insert(buf_view_wrapper->buffer);
                                    }
                                }
                            }
                            break;

                            // Rest of descriptors are immutable within a shader
                            default:
                                break;
                        }
                    }
                }
            }
        }
    }
}

void VulkanStateTracker::TrackCmdDraw(VkCommandBuffer commandBuffer,
                                      uint32_t        vertexCount,
                                      uint32_t        instanceCount,
                                      uint32_t        firstVertex,
                                      uint32_t        firstInstance)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanStateTracker::TrackCmdDrawIndexed(VkCommandBuffer commandBuffer,
                                             uint32_t        indexCount,
                                             uint32_t        instanceCount,
                                             uint32_t        firstIndex,
                                             int32_t         vertexOffset,
                                             uint32_t        firstInstance)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanStateTracker::TrackCmdDrawIndirect(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanStateTracker::TrackCmdDrawIndexedIndirect(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanStateTracker::TrackCmdDrawIndirectCount(VkCommandBuffer commandBuffer,
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
}

void VulkanStateTracker::TrackCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer,
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
}

void VulkanStateTracker::TrackCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer,
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
}

void VulkanStateTracker::TrackCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer,
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
}

void VulkanStateTracker::TrackCmdDispatch(VkCommandBuffer commandBuffer,
                                          uint32_t        groupCountX,
                                          uint32_t        groupCountY,
                                          uint32_t        groupCountZ)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);
}

void VulkanStateTracker::TrackCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);
}

void VulkanStateTracker::TrackCmdDispatchBase(VkCommandBuffer commandBuffer,
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
}

void VulkanStateTracker::TrackCmdDispatchBaseKHR(VkCommandBuffer commandBuffer,
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
}

void VulkanStateTracker::TrackCmdTraceRaysNV(VkCommandBuffer commandBuffer,
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
}

void VulkanStateTracker::TrackCmdTraceRaysKHR(VkCommandBuffer                        commandBuffer,
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
}

void VulkanStateTracker::TrackCmdTraceRaysIndirectKHR(
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
}

void VulkanStateTracker::TrackCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer,
                                                       VkDeviceAddress indirectDeviceAddress)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    TrackPipelineDescriptors(cmd_buf_wrapper, vulkan_state_info::PipelineBindPoints::kBindPoint_ray_tracing);
}

void VulkanStateTracker::MarkDirtyAssets(vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper)
{
    assert(cmd_buf_wrapper != nullptr);

    for (auto asset : cmd_buf_wrapper->modified_assets)
    {
        assert(asset);
        asset->dirty = true;
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
