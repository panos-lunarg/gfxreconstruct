/*
** Copyright (c) 2023 LunarG, Inc.
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

#include "generated/generated_vulkan_enum_to_string.h"
#include "graphics/vulkan_resources_util.h"
#include "util/image_writer.h"
#include "util/buffer_writer.h"
#include "vulkan_replay_resource_dump.h"

#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <algorithm>
#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
static bool IsInsideRange(const std::vector<T>& vec, T value)
{
    assert(vec.size());

    return (value >= *(vec.begin()) && value <= *(vec.end() - 1));
}

static util::imagewriter::DataFormats VkFormatToImageWriterDataFormat(VkFormat format)
{
    switch (format)
    {
        case VK_FORMAT_R8G8B8_UNORM:
            return util::imagewriter::DataFormats::kFormat_RGB;

        case VK_FORMAT_R8G8B8A8_UNORM:
            return util::imagewriter::DataFormats::kFormat_RGBA;

        case VK_FORMAT_B8G8R8_UNORM:
            return util::imagewriter::DataFormats::kFormat_BGR;

        case VK_FORMAT_B8G8R8A8_UNORM:
            return util::imagewriter::DataFormats::kFormat_BGRA;

        case VK_FORMAT_D32_SFLOAT:
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            return util::imagewriter::DataFormats::kFormat_D32;

        case VK_FORMAT_D16_UNORM:
            return util::imagewriter::DataFormats::kFormat_D16;

        default:
            GFXRECON_LOG_ERROR("%s() failed to handle format: %s", __func__, util::ToString<VkFormat>(format).c_str());
            assert(0);
            return util::imagewriter::DataFormats::kFormat_UNSPECIFIED;
    }
}

VulkanReplayResourceDump::VulkanReplayResourceDump(const std::vector<uint64_t>&              begin_command_buffer_index,
                                                   const std::vector<std::vector<uint64_t>>& cmdDraw_index,
                                                   uint64_t                                  cmdDispatch_index,
                                                   uint64_t                                  CmdTraceRaysKHR_index,
                                                   const std::vector<uint64_t>&              QueueSubmit_index,
                                                   bool                                      isolate_draw,
                                                   const VulkanObjectInfoTable&              object_info_table) :
    CmdDispatch_Index(cmdDispatch_index),
    CmdTraceRaysKHR_Index(CmdTraceRaysKHR_index), QueueSubmit_Index(std::move(QueueSubmit_index)), current_draw_call(0),
    recording(false), inside_renderpass(false), isolate_draw_call(isolate_draw), object_info_table_(object_info_table)
{
    // These should match
    assert(begin_command_buffer_index.size() == cmdDraw_index.size());

    for (size_t i = 0; i < begin_command_buffer_index.size(); ++i)
    {
        const uint64_t bcb_index = begin_command_buffer_index[i];
        cmd_buf_stacks.emplace(bcb_index, CommandBufferStack(std::move(cmdDraw_index[i])));
    }
}

VkResult VulkanReplayResourceDump::CloneCommandBuffer(uint64_t                   bcb_index,
                                                      format::HandleId           commandBuffer,
                                                      const encode::DeviceTable* device_table)
{
    assert(device_table);

    auto entry = cmd_buf_stacks.find(bcb_index);
    if (entry == cmd_buf_stacks.end())
    {
        GFXRECON_LOG_ERROR("Couldn't find vkBeginCommandBuffer with index %" PRIx64, bcb_index);
        assert(0);
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    const CommandBufferInfo* cb_info      = object_info_table_.GetCommandBufferInfo(commandBuffer);
    const CommandPoolInfo*   cb_pool_info = object_info_table_.GetCommandPoolInfo(cb_info->pool_id);

    const VkCommandBufferAllocateInfo ai{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                                          nullptr,
                                          cb_pool_info->handle,
                                          VK_COMMAND_BUFFER_LEVEL_PRIMARY,
                                          1 };

    CommandBufferStack& stack    = entry->second;
    const DeviceInfo*   dev_info = object_info_table_.GetDeviceInfo(cb_info->parent_id);

    for (size_t i = 0; i < stack.command_buffers.size(); ++i)
    {
        assert(stack.command_buffers[i] == VK_NULL_HANDLE);
        VkResult res = device_table->AllocateCommandBuffers(dev_info->handle, &ai, &stack.command_buffers[i]);

        if (res == VK_SUCCESS)
        {
            recording = true;
        }
        else
        {
            return res;
        }
    }

    assert(stack.original_command_buffer_info == nullptr);
    stack.original_command_buffer_info = cb_info;

    assert(stack.original_command_buffer_handle == VK_NULL_HANDLE);
    stack.original_command_buffer_handle = cb_info->handle;

    assert(stack.device_table == nullptr);
    stack.device_table = device_table;

    assert(cmd_buf_begin_map.find(cb_info->handle) == cmd_buf_begin_map.end());
    cmd_buf_begin_map[cb_info->handle] = bcb_index;

    // Allocate auxiliary command buffer
    VkResult res = device_table->AllocateCommandBuffers(dev_info->handle, &ai, &stack.aux_command_buffer);
    assert(res == VK_SUCCESS);

    return VK_SUCCESS;
}

void VulkanReplayResourceDump::FinalizeCommandBuffer(VkCommandBuffer original_command_buffer)
{
    std::vector<VkImageMemoryBarrier> img_barriers;

    for (size_t i = 0; i < render_targets.color_att_imgs.size(); ++i)
    {
        if (render_targets.color_att_storeOps[i] == VK_ATTACHMENT_STORE_OP_STORE)
        {
            const ImageInfo* image_info = render_targets.color_att_imgs[i];

            std::vector<VkImageAspectFlagBits> aspects;
            bool                               combined_depth_stencil;
            graphics::GetFormatAspects(image_info->format, &aspects, &combined_depth_stencil);

            VkImageMemoryBarrier img_barrier;
            img_barrier.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            img_barrier.pNext                           = nullptr;
            img_barrier.srcAccessMask                   = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            img_barrier.dstAccessMask                   = VK_ACCESS_TRANSFER_READ_BIT;
            img_barrier.oldLayout                       = render_targets.color_att_final_layouts[i];
            img_barrier.newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
            img_barrier.srcQueueFamilyIndex             = 0;
            img_barrier.dstQueueFamilyIndex             = 0;
            img_barrier.image                           = image_info->handle;
            img_barrier.subresourceRange.aspectMask     = aspects[0];
            img_barrier.subresourceRange.baseArrayLayer = 0;
            img_barrier.subresourceRange.baseMipLevel   = 0;
            img_barrier.subresourceRange.layerCount     = VK_REMAINING_ARRAY_LAYERS;
            img_barrier.subresourceRange.levelCount     = VK_REMAINING_MIP_LEVELS;
            img_barriers.push_back(std::move(img_barrier));
        }
    }

    if (render_targets.depth_att_img)
    {
        const ImageInfo* image_info = render_targets.depth_att_img;

        std::vector<VkImageAspectFlagBits> aspects;
        bool                               combined_depth_stencil;
        graphics::GetFormatAspects(image_info->format, &aspects, &combined_depth_stencil);

        VkImageMemoryBarrier img_barrier;
        img_barrier.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        img_barrier.pNext                           = nullptr;
        img_barrier.srcAccessMask                   = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
        img_barrier.dstAccessMask                   = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.oldLayout                       = render_targets.depth_att_final_layout;
        img_barrier.newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        img_barrier.srcQueueFamilyIndex             = 0;
        img_barrier.dstQueueFamilyIndex             = 0;
        img_barrier.image                           = image_info->handle;
        img_barrier.subresourceRange.aspectMask     = aspects[0];
        img_barrier.subresourceRange.baseArrayLayer = 0;
        img_barrier.subresourceRange.baseMipLevel   = 0;
        img_barrier.subresourceRange.layerCount     = VK_REMAINING_ARRAY_LAYERS;
        img_barrier.subresourceRange.levelCount     = VK_REMAINING_MIP_LEVELS;
        img_barriers.push_back(std::move(img_barrier));
    }

    auto begin_entry = cmd_buf_begin_map.find(original_command_buffer);
    assert(begin_entry != cmd_buf_begin_map.end());

    auto stack_entry = cmd_buf_stacks.find(begin_entry->second);
    assert(stack_entry != cmd_buf_stacks.end());

    CommandBufferStack& stack         = stack_entry->second;
    VkCommandBuffer     current_clone = stack.command_buffers[stack.current_index];
    assert(stack.device_table != nullptr);

    if (inside_renderpass)
    {
        stack.device_table->CmdEndRenderPass(current_clone);
    }

    // Inset pipeline barrier after EndRenderPass
    if (img_barriers.size())
    {
        stack.device_table->CmdPipelineBarrier(current_clone,
                                               VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                               VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                               0,
                                               0,
                                               nullptr,
                                               0,
                                               nullptr,
                                               img_barriers.size(),
                                               img_barriers.data());
    }

    stack.device_table->EndCommandBuffer(current_clone);

    // Increment pointer to clone that is going to be finalized next
    ++stack.current_index;

    UpdateRecordingStatus();
}

VkResult VulkanReplayResourceDump::RevertRenderTargetImageLayouts(const CommandBufferStack& stack, VkQueue queue)
{
    std::vector<VkImageMemoryBarrier> img_barriers;

    for (size_t i = 0; i < render_targets.color_att_imgs.size(); ++i)
    {
        if (render_targets.color_att_storeOps[i] == VK_ATTACHMENT_STORE_OP_STORE)
        {
            const ImageInfo* image_info = render_targets.color_att_imgs[i];

            std::vector<VkImageAspectFlagBits> aspects;
            bool                               combined_depth_stencil;
            graphics::GetFormatAspects(image_info->format, &aspects, &combined_depth_stencil);

            VkImageMemoryBarrier img_barrier;
            img_barrier.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            img_barrier.pNext                           = nullptr;
            img_barrier.srcAccessMask                   = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            img_barrier.dstAccessMask                   = VK_ACCESS_TRANSFER_READ_BIT;
            img_barrier.oldLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
            img_barrier.newLayout                       = render_targets.color_att_final_layouts[i];
            img_barrier.srcQueueFamilyIndex             = 0;
            img_barrier.dstQueueFamilyIndex             = 0;
            img_barrier.image                           = image_info->handle;
            img_barrier.subresourceRange.aspectMask     = aspects[0];
            img_barrier.subresourceRange.baseArrayLayer = 0;
            img_barrier.subresourceRange.baseMipLevel   = 0;
            img_barrier.subresourceRange.layerCount     = VK_REMAINING_ARRAY_LAYERS;
            img_barrier.subresourceRange.levelCount     = VK_REMAINING_MIP_LEVELS;
            img_barriers.push_back(std::move(img_barrier));
        }
    }

    if (render_targets.depth_att_img)
    {
        const ImageInfo* image_info = render_targets.depth_att_img;

        std::vector<VkImageAspectFlagBits> aspects;
        bool                               combined_depth_stencil;
        graphics::GetFormatAspects(image_info->format, &aspects, &combined_depth_stencil);

        VkImageMemoryBarrier img_barrier;
        img_barrier.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        img_barrier.pNext                           = nullptr;
        img_barrier.srcAccessMask                   = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
        img_barrier.dstAccessMask                   = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.oldLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        img_barrier.newLayout                       = render_targets.depth_att_final_layout;
        img_barrier.srcQueueFamilyIndex             = 0;
        img_barrier.dstQueueFamilyIndex             = 0;
        img_barrier.image                           = image_info->handle;
        img_barrier.subresourceRange.aspectMask     = aspects[0];
        img_barrier.subresourceRange.baseArrayLayer = 0;
        img_barrier.subresourceRange.baseMipLevel   = 0;
        img_barrier.subresourceRange.layerCount     = VK_REMAINING_ARRAY_LAYERS;
        img_barrier.subresourceRange.levelCount     = VK_REMAINING_MIP_LEVELS;
        img_barriers.push_back(std::move(img_barrier));
    }

    assert(stack.device_table != nullptr);
    assert(stack.aux_command_buffer != VK_NULL_HANDLE);

    const VkCommandBufferBeginInfo bi{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
    stack.device_table->BeginCommandBuffer(stack.aux_command_buffer, &bi);

    if (img_barriers.size())
    {
        stack.device_table->CmdPipelineBarrier(stack.aux_command_buffer,
                                               VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                               VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                               0,
                                               0,
                                               nullptr,
                                               0,
                                               nullptr,
                                               img_barriers.size(),
                                               img_barriers.data());
    }

    stack.device_table->EndCommandBuffer(stack.aux_command_buffer);

    VkSubmitInfo si;
    si.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    si.pNext                = nullptr;
    si.waitSemaphoreCount   = 0;
    si.waitSemaphoreCount   = 0;
    si.pWaitSemaphores      = nullptr;
    si.pWaitDstStageMask    = nullptr;
    si.commandBufferCount   = 1;
    si.pCommandBuffers      = &stack.aux_command_buffer;
    si.signalSemaphoreCount = 0;
    si.pSignalSemaphores    = nullptr;

    VkResult res = stack.device_table->QueueSubmit(queue, 1, &si, VK_NULL_HANDLE);

    assert(res == VK_SUCCESS);
    if (res != VK_SUCCESS)
    {
        return res;
    }

    res = stack.device_table->QueueWaitIdle(queue);
    assert(res == VK_SUCCESS);

    return res;
}

void VulkanReplayResourceDump::DumpAttachments(const CommandBufferStack& stack, uint64_t dc_index)
{
    assert(stack.device_table != nullptr);

    if (!render_targets.color_att_imgs.size() && render_targets.depth_att_img == nullptr)
    {
        assert(render_targets.color_att_storeOps.size() == 0);
        return;
    }

    assert(stack.original_command_buffer_info);
    assert(stack.original_command_buffer_info->parent_id != format::kNullHandleId);
    const DeviceInfo* device_info = object_info_table_.GetDeviceInfo(stack.original_command_buffer_info->parent_id);
    assert(device_info);

    const PhysicalDeviceInfo* phys_dev_info = object_info_table_.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(
        device_info->handle, *stack.device_table, *phys_dev_info->replay_device_info->memory_properties);

    assert(render_targets.color_att_imgs.size() == render_targets.color_att_storeOps.size());
    for (size_t i = 0; i < render_targets.color_att_imgs.size(); ++i)
    {
        if (render_targets.color_att_storeOps[i] == VK_ATTACHMENT_STORE_OP_STORE)
        {
            const ImageInfo* image_info = render_targets.color_att_imgs[i];

            std::vector<uint8_t>  data;
            std::vector<uint64_t> subresource_offsets;
            std::vector<uint64_t> subresource_sizes;

            resource_util.ReadFromImageResourceStaging(
                image_info->handle,
                image_info->format,
                image_info->type,
                VkExtent3D{ render_targets.render_area.extent.width, render_targets.render_area.extent.height, 1 },
                image_info->level_count,
                image_info->layer_count,
                image_info->tiling,
                image_info->sample_count,
                image_info->current_layout,
                0,
                VK_IMAGE_ASPECT_COLOR_BIT,
                data,
                subresource_offsets,
                subresource_sizes);

            std::stringstream filename;
            filename << "vkCmdDraw_" << dc_index << "_att_" << i << "_aspect_"
                     << util::ToString<VkImageAspectFlagBits>(VK_IMAGE_ASPECT_COLOR_BIT) << "_ml_" << 0 << "_al_" << 0
                     << ".bmp";

            const uint32_t texel_size = vkuFormatElementSizeWithAspect(image_info->format, VK_IMAGE_ASPECT_COLOR_BIT);
            const uint32_t stride     = texel_size * image_info->extent.width;

            util::imagewriter::WriteBmpImage(filename.str(),
                                             image_info->extent.width,
                                             image_info->extent.height,
                                             subresource_sizes[0],
                                             data.data(),
                                             stride,
                                             VkFormatToImageWriterDataFormat(image_info->format));
        }
    }

    if (render_targets.depth_att_img != nullptr)
    {
        if (render_targets.depth_att_storeOp != VK_ATTACHMENT_STORE_OP_STORE)
        {
            GFXRECON_LOG_WARNING("Dumping depth attachment with a storeOp different than VK_ATTACHMENT_STORE_OP_STORE");
        }

        const ImageInfo* image_info = render_targets.depth_att_img;

        std::vector<uint8_t>  data;
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;

        resource_util.ReadFromImageResourceStaging(
            image_info->handle,
            image_info->format,
            image_info->type,
            VkExtent3D{ render_targets.render_area.extent.width, render_targets.render_area.extent.height, 1 },
            image_info->level_count,
            image_info->layer_count,
            image_info->tiling,
            image_info->sample_count,
            image_info->current_layout,
            0,
            VK_IMAGE_ASPECT_DEPTH_BIT,
            data,
            subresource_offsets,
            subresource_sizes);

        std::stringstream filename;
        filename << "vkCmdDraw_" << dc_index << "_aspect_"
                 << util::ToString<VkImageAspectFlagBits>(VK_IMAGE_ASPECT_DEPTH_BIT) << "_ml_" << 0 << "_al_" << 0
                 << ".bmp";

        const uint32_t texel_size = vkuFormatElementSizeWithAspect(image_info->format, VK_IMAGE_ASPECT_DEPTH_BIT);
        const uint32_t stride     = texel_size * image_info->extent.width;

        util::imagewriter::WriteBmpImage(filename.str(),
                                         image_info->extent.width,
                                         image_info->extent.height,
                                         subresource_sizes[0],
                                         data.data(),
                                         stride,
                                         VkFormatToImageWriterDataFormat(image_info->format));
    }
}

VkResult VulkanReplayResourceDump::ModifyAndSubmit(std::vector<VkSubmitInfo>  modified_submit_infos,
                                                   const encode::DeviceTable& device_table,
                                                   VkQueue                    queue,
                                                   VkFence                    fence,
                                                   uint64_t                   index)
{
    bool submitted = false;

    for (size_t s = 0; s < modified_submit_infos.size(); s++)
    {
        size_t     command_buffer_count   = modified_submit_infos[s].commandBufferCount;
        const auto command_buffer_handles = modified_submit_infos[s].pCommandBuffers;

        if (command_buffer_count)
        {
            modified_submit_infos[s].waitSemaphoreCount   = 0;
            modified_submit_infos[s].pWaitSemaphores      = nullptr;
            modified_submit_infos[s].pWaitDstStageMask    = nullptr;
            modified_submit_infos[s].signalSemaphoreCount = 0;
            modified_submit_infos[s].pSignalSemaphores    = nullptr;
        }

        for (uint32_t o = 0; o < command_buffer_count; ++o)
        {
            auto bcb_entry = cmd_buf_begin_map.find(command_buffer_handles[o]);
            if (bcb_entry != cmd_buf_begin_map.end())
            {
                auto stack_entry = cmd_buf_stacks.find(bcb_entry->second);
                assert(stack_entry != cmd_buf_stacks.end());
                const CommandBufferStack& stack = stack_entry->second;

                for (size_t cb = 0; cb < stack.command_buffers.size(); ++cb)
                {
                    VkCommandBuffer clone_buffer = stack.command_buffers[cb];

                    VkCommandBuffer* pCommandBuffers =
                        const_cast<VkCommandBuffer*>(modified_submit_infos[s].pCommandBuffers);
                    pCommandBuffers[o] = clone_buffer;

                    VkResult res = stack.device_table->QueueSubmit(
                        queue, modified_submit_infos.size(), modified_submit_infos.data(), VK_NULL_HANDLE);
                    assert(res == VK_SUCCESS);
                    if (res != VK_SUCCESS)
                    {
                        return res;
                    }
                    submitted = true;

                    // Wait
                    res = stack.device_table->QueueWaitIdle(queue);
                    assert(res == VK_SUCCESS);
                    if (res != VK_SUCCESS)
                    {
                        return res;
                    }

                    // Dump resources
                    DumpAttachments(stack, stack.dc_indices[cb]);

                    // Revert render attachments layouts
                    res = RevertRenderTargetImageLayouts(stack, queue);
                    assert(res == VK_SUCCESS);
                    if (res != VK_SUCCESS)
                    {
                        return res;
                    }
                }
            }
        }
    }

    VkResult res = VK_SUCCESS;

    // Looks like we didn't submit anything. Do the submission as it would have been done
    // without further modifications
    if (!submitted)
    {
        res = device_table.QueueSubmit(queue, modified_submit_infos.size(), modified_submit_infos.data(), fence);
    }
    else
    {
        assert(index == QueueSubmit_Index[0]);
        QueueSubmit_Index.erase(QueueSubmit_Index.begin());
        if (QueueSubmit_Index.size() == 0)
        {
            exit(0);
        }
    }

    return res;
}

void VulkanReplayResourceDump::SetRenderTargets(const std::vector<const ImageInfo*>&    color_att_imgs,
                                                const std::vector<VkAttachmentStoreOp>& color_att_storeOps,
                                                const std::vector<VkImageLayout>&       final_layouts,
                                                const ImageInfo*                        depth_att_img,
                                                VkAttachmentStoreOp                     depth_att_storeOp,
                                                VkImageLayout                           depth_att_final_layout)
{
    render_targets.color_att_imgs          = color_att_imgs;
    render_targets.color_att_storeOps      = color_att_storeOps;
    render_targets.color_att_final_layouts = final_layouts;
    render_targets.depth_att_img           = depth_att_img;
    render_targets.depth_att_storeOp       = depth_att_storeOp;
    render_targets.depth_att_final_layout  = depth_att_final_layout;
}

void VulkanReplayResourceDump::UpdateDescriptors(VkPipelineBindPoint     pipeline_bind_point,
                                                 uint32_t                first_set,
                                                 const format::HandleId* descriptor_sets_ids,
                                                 uint32_t                descriptor_sets_count)
{
    assert(descriptor_sets_ids);

    DescriptorSetBindPoints bind_point;
    switch (pipeline_bind_point)
    {
        case VK_PIPELINE_BIND_POINT_GRAPHICS:
            bind_point = BIND_POINT_GRAPHICS;
            break;

        case VK_PIPELINE_BIND_POINT_COMPUTE:
            bind_point = BIND_POINT_COMPUTE;
            break;

        case VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR:
            bind_point = BIND_POINT_RAY_TRACING;
            break;

        default:
            GFXRECON_LOG_ERROR("Unrecognized pipeline bind point (%d)", pipeline_bind_point);
            assert(0);
            return;
            break;
    }

    for (uint32_t i = 0; i < descriptor_sets_count; ++i)
    {
        const DescriptorSetInfo* desc_set_info = object_info_table_.GetDescriptorSetInfo(descriptor_sets_ids[i]);
        assert(desc_set_info);

        for (const auto& binding : desc_set_info->descriptors)
        {
            switch (binding.second.desc_type)
            {
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                {
                    const ImageViewInfo* img_view_info =
                        object_info_table_.GetImageViewInfo(binding.second.image_info.image_view_id);
                    assert(img_view_info);

                    const ImageInfo* img_info = object_info_table_.GetImageInfo(img_view_info->image_id);
                    assert(img_info);

                    bound_descriptor_sets[bind_point][first_set + i].image_infos[binding.first] = img_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                {
                    const BufferInfo* buffer_info =
                        object_info_table_.GetBufferInfo(binding.second.buffer_info.buffer_id);
                    assert(buffer_info);

                    bound_descriptor_sets[bind_point][first_set + i].buffer_infos[binding.first] = buffer_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    const BufferViewInfo* buffer_view_info =
                        object_info_table_.GetBufferViewInfo(binding.second.texel_buffer_view);
                    assert(buffer_view_info);

                    const BufferInfo* buffer_info = object_info_table_.GetBufferInfo(buffer_view_info->buffer_id);
                    assert(buffer_info);

                    bound_descriptor_sets[bind_point][first_set + i].buffer_infos[binding.first] = buffer_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    // These are read only resources
                    return;

                default:
                    GFXRECON_LOG_WARNING_ONCE("Descriptor type not handled")
            }
        }
    }
}

void VulkanReplayResourceDump::DumpResources(const CommandBufferStack& stack, uint64_t dc_index)
{
    // const DeviceInfo* device_info = object_info_table_.GetDeviceInfo(stack.original_command_buffer_info->parent_id);
    // assert(device_info);

    // const PhysicalDeviceInfo* phys_dev_info = object_info_table_.GetPhysicalDeviceInfo(device_info->parent_id);
    // assert(phys_dev_info);

    // graphics::VulkanResourcesUtil resource_util(
    //     device_info->handle, *stack.device_table, *phys_dev_info->replay_device_info->memory_properties);

    // DescriptorSetBindPoints bind_point;
    // if (CmdDraw_Index[current_draw_call])
    // {
    //     bind_point = BIND_POINT_GRAPHICS;
    // }
    // else if (CmdDispatch_Index)
    // {
    //     bind_point = BIND_POINT_COMPUTE;
    // }
    // else
    // {
    //     assert(CmdTraceRaysKHR_Index);

    //     bind_point = BIND_POINT_RAY_TRACING;
    // }

    // for (auto desc_set : bound_descriptor_sets[bind_point])
    // {
    //     for (const auto storage_image : desc_set.second.image_infos)
    //     {
    //         const ImageInfo* image_info = storage_image.second;

    //         std::vector<uint8_t>  data;
    //         std::vector<uint64_t> subresource_offsets;
    //         std::vector<uint64_t> subresource_sizes;

    //         resource_util.ReadFromImageResourceStaging(image_info->handle,
    //                                                    image_info->format,
    //                                                    image_info->type,
    //                                                    image_info->extent,
    //                                                    image_info->level_count,
    //                                                    image_info->layer_count,
    //                                                    image_info->tiling,
    //                                                    image_info->sample_count,
    //                                                    image_info->current_layout,
    //                                                    0,
    //                                                    VK_IMAGE_ASPECT_COLOR_BIT,
    //                                                    data,
    //                                                    subresource_offsets,
    //                                                    subresource_sizes);

    //         std::stringstream filename;
    //         filename << "storage_image_" << image_info->capture_id << "_index_" << index << ".bmp";

    //         const uint32_t texel_size = vkuFormatElementSize(image_info->format);
    //         const uint32_t stride     = texel_size * image_info->extent.width;

    //         util::imagewriter::WriteBmpImage(filename.str(),
    //                                          image_info->extent.width,
    //                                          image_info->extent.height,
    //                                          subresource_sizes[0],
    //                                          data.data(),
    //                                          stride,
    //                                          VkFormatToImageWriterDataFormat(image_info->format));
    //     }

    //     desc_set.second.image_infos.clear();

    //     for (const auto& storabe_buffer : desc_set.second.buffer_infos)
    //     {
    //         const BufferInfo*    buffer_info = storabe_buffer.second;
    //         std::vector<uint8_t> data;

    //         resource_util.ReadFromBufferResource(
    //             buffer_info->handle, buffer_info->size, buffer_info->queue_family_index, data);

    //         std::stringstream filename;
    //         filename << "storage_buffer_" << buffer_info->capture_id << "_index_" << index << ".bin";

    //         util::bufferwriter::WriteBuffer(filename.str(), data.data(), buffer_info->size);
    //     }

    //     desc_set.second.buffer_infos.clear();
    // }
}

bool VulkanReplayResourceDump::DumpingBeginCommandBufferIndex(uint64_t index) const
{
    const auto entry = cmd_buf_stacks.find(index);

    return entry != cmd_buf_stacks.end();
}

void VulkanReplayResourceDump::GetActiveCommandBuffers(VkCommandBuffer user_cmd_buffer,
                                                       cmd_buf_it&     first,
                                                       cmd_buf_it&     last)
{
    auto begin_cmd_entry = cmd_buf_begin_map.find(user_cmd_buffer);
    assert(begin_cmd_entry != cmd_buf_begin_map.end());

    auto stack_entry = cmd_buf_stacks.find(begin_cmd_entry->second);
    assert(stack_entry != cmd_buf_stacks.end());

    CommandBufferStack& stack = stack_entry->second;
    assert(stack_entry->second.original_command_buffer_handle == user_cmd_buffer);

    assert(stack.current_index <= stack.command_buffers.size());

    first = stack.command_buffers.begin() + stack.current_index;
    last  = stack.command_buffers.end();
}

bool VulkanReplayResourceDump::UpdateRecordingStatus()
{
    assert(recording);

    for (const auto& entry : cmd_buf_stacks)
    {
        const CommandBufferStack& stack = entry.second;
        if (stack.current_index < stack.command_buffers.size())
        {
            return true;
        }
    }

    return (recording = false);
}

bool VulkanReplayResourceDump::DumpingSubmissionIndex(uint64_t index) const
{
    assert(!recording);

    for (size_t i = 0; i < QueueSubmit_Index.size(); ++i)
    {
        // Indices should be sorted
        if (!IsInsideRange(QueueSubmit_Index, index))
        {
            return false;
        }

        if (index == QueueSubmit_Index[i])
        {
            return true;
        }
    }

    return false;
}

bool VulkanReplayResourceDump::DumpingDrawCallIndex(VkCommandBuffer original_command_buffer, uint64_t index) const
{
    assert(recording);
    assert(original_command_buffer != VK_NULL_HANDLE);

    const auto bcb_entry = cmd_buf_begin_map.find(original_command_buffer);
    if (bcb_entry == cmd_buf_begin_map.end())
    {
        return false;
    }

    const auto stack_entry = cmd_buf_stacks.find(bcb_entry->second);
    if (stack_entry == cmd_buf_stacks.end())
    {
        return false;
    }

    const CommandBufferStack& stack = stack_entry->second;
    assert(stack.current_index < stack.dc_indices.size());
    for (size_t i = stack.current_index; i < stack.dc_indices.size(); ++i)
    {
        // Indices should be sorted
        if (!IsInsideRange(stack.dc_indices, index))
        {
            return false;
        }

        if (index == stack.dc_indices[i])
        {
            return true;
        }
    }

    return false;
}

bool VulkanReplayResourceDump::DumpingDispatchIndex(uint64_t index) const
{
    assert(recording);

    return CmdDispatch_Index == index;
}

bool VulkanReplayResourceDump::DumpingTraceRaysIndex(uint64_t index) const
{
    assert(recording);

    return CmdTraceRaysKHR_Index == index;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
