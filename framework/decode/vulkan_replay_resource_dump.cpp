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
#include "vulkan_replay_resource_dump.h"

#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

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

VkResult VulkanReplayResourceDump::CloneCommandBuffer(format::HandleId commandBuffer, PFN_vkAllocateCommandBuffers func)
{
    const CommandBufferInfo* cb_info      = object_info_table_.GetCommandBufferInfo(commandBuffer);
    const CommandPoolInfo*   cb_pool_info = object_info_table_.GetCommandPoolInfo(cb_info->pool_id);

    assert(command_buffer == VK_NULL_HANDLE);

    const VkCommandBufferAllocateInfo ai{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                                          nullptr,
                                          cb_pool_info->handle,
                                          VK_COMMAND_BUFFER_LEVEL_PRIMARY,
                                          1 };

    const DeviceInfo* dev_info = object_info_table_.GetDeviceInfo(cb_info->parent_id);
    VkResult          res      = func(dev_info->handle, &ai, &command_buffer);

    if (res == VK_SUCCESS)
    {
        recording                      = true;
        original_command_buffer        = commandBuffer;
        original_command_buffer_handle = cb_info->handle;
    }

    return res;
}

void VulkanReplayResourceDump::FinalizeCommandBuffer(const encode::DeviceTable& device_table)
{
    assert(command_buffer != VK_NULL_HANDLE);

    std::vector<VkImageMemoryBarrier> img_barriers;

    for (size_t i = 0; i < render_targets.color_att_imgs.size(); ++i)
    {
        if (render_targets.color_att_storeOps[i] == VK_ATTACHMENT_STORE_OP_STORE)
        {
            const ImageInfo* img = render_targets.color_att_imgs[i];

            std::vector<VkImageAspectFlagBits> aspects;
            bool                               combined_depth_stencil;
            graphics::GetFormatAspects(img->format, &aspects, &combined_depth_stencil);

            VkImageMemoryBarrier img_barrier;
            img_barrier.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            img_barrier.pNext                           = nullptr;
            img_barrier.srcAccessMask                   = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            img_barrier.dstAccessMask                   = VK_ACCESS_TRANSFER_READ_BIT;
            img_barrier.oldLayout                       = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
            img_barrier.newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
            img_barrier.srcQueueFamilyIndex             = 0;
            img_barrier.dstQueueFamilyIndex             = 0;
            img_barrier.image                           = img->handle;
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
        const ImageInfo* img = render_targets.depth_att_img;

        std::vector<VkImageAspectFlagBits> aspects;
        bool                               combined_depth_stencil;
        graphics::GetFormatAspects(img->format, &aspects, &combined_depth_stencil);

        VkImageMemoryBarrier img_barrier;
        img_barrier.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        img_barrier.pNext                           = nullptr;
        img_barrier.srcAccessMask                   = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
        img_barrier.dstAccessMask                   = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.oldLayout                       = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
        img_barrier.newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        img_barrier.srcQueueFamilyIndex             = 0;
        img_barrier.dstQueueFamilyIndex             = 0;
        img_barrier.image                           = img->handle;
        img_barrier.subresourceRange.aspectMask     = aspects[0];
        img_barrier.subresourceRange.baseArrayLayer = 0;
        img_barrier.subresourceRange.baseMipLevel   = 0;
        img_barrier.subresourceRange.layerCount     = VK_REMAINING_ARRAY_LAYERS;
        img_barrier.subresourceRange.levelCount     = VK_REMAINING_MIP_LEVELS;
        img_barriers.push_back(std::move(img_barrier));
    }

    device_table.CmdEndRenderPass(command_buffer);

    // Inset pipeline barrier after EndRenderPass
    device_table.CmdPipelineBarrier(command_buffer,
                                    VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                    VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                    0,
                                    0,
                                    nullptr,
                                    0,
                                    nullptr,
                                    img_barriers.size(),
                                    img_barriers.data());

    device_table.EndCommandBuffer(command_buffer);

    recording = false;
}

void VulkanReplayResourceDump::DumpAttachments(const encode::DeviceTable* device_table, uint64_t index)
{
    if (!render_targets.color_att_imgs.size() && render_targets.depth_att_img == nullptr)
    {
        assert(render_targets.color_att_storeOps.size() == 0);
        return;
    }

    assert(original_command_buffer != format::kNullHandleId);

    const CommandBufferInfo* cmd_buf_info = object_info_table_.GetCommandBufferInfo(original_command_buffer);
    assert(cmd_buf_info);

    const DeviceInfo* device_info = object_info_table_.GetDeviceInfo(cmd_buf_info->parent_id);
    assert(device_info);

    const PhysicalDeviceInfo* phys_dev_info = object_info_table_.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(
        device_info->handle, *device_table, *phys_dev_info->replay_device_info->memory_properties);

    assert(render_targets.color_att_imgs.size() == render_targets.color_att_storeOps.size());
    for (size_t i = 0; i < render_targets.color_att_imgs.size(); ++i)
    {
        if (render_targets.color_att_storeOps[i] == VK_ATTACHMENT_STORE_OP_STORE)
        {
            const ImageInfo* img = render_targets.color_att_imgs[i];

            std::vector<uint8_t>  data;
            std::vector<uint64_t> subresource_offsets;
            std::vector<uint64_t> subresource_sizes;

            resource_util.ReadFromImageResourceStaging(
                img->handle,
                img->format,
                img->type,
                VkExtent3D{ render_targets.render_area.extent.width, render_targets.render_area.extent.height, 1 },
                img->level_count,
                img->layer_count,
                img->tiling,
                img->sample_count,
                img->current_layout,
                0,
                VK_IMAGE_ASPECT_COLOR_BIT,
                data,
                subresource_offsets,
                subresource_sizes);

            std::stringstream ss;

            ss << "vkCmdDraw_" << CmdDraw_Index << "_att_" << i << "_aspect_"
               << util::ToString<VkImageAspectFlagBits>(VK_IMAGE_ASPECT_COLOR_BIT) << "_ml_" << 0 << "_al_" << 0
               << ".bmp";

            const uint32_t texel_size = vkuFormatElementSizeWithAspect(img->format, VK_IMAGE_ASPECT_COLOR_BIT);
            const uint32_t stride     = texel_size * img->extent.width;

            util::imagewriter::WriteBmpImage(ss.str(),
                                             img->extent.width,
                                             img->extent.height,
                                             subresource_sizes[0],
                                             data.data(),
                                             stride,
                                             VkFormatToImageWriterDataFormat(img->format));
        }
    }

    if (render_targets.depth_att_img != nullptr)
    {
        if (render_targets.depth_att_storeOp != VK_ATTACHMENT_STORE_OP_STORE)
        {
            GFXRECON_LOG_WARNING("Dumping depth attachment with a storeOp different than VK_ATTACHMENT_STORE_OP_STORE");
        }

        const ImageInfo* img = render_targets.depth_att_img;

        std::vector<uint8_t>  data;
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;

        resource_util.ReadFromImageResourceStaging(
            img->handle,
            img->format,
            img->type,
            VkExtent3D{ render_targets.render_area.extent.width, render_targets.render_area.extent.height, 1 },
            img->level_count,
            img->layer_count,
            img->tiling,
            img->sample_count,
            img->current_layout,
            0,
            VK_IMAGE_ASPECT_DEPTH_BIT,
            data,
            subresource_offsets,
            subresource_sizes);

        std::stringstream ss;

        ss << "vkCmdDraw_" << CmdDraw_Index << "_aspect_"
           << util::ToString<VkImageAspectFlagBits>(VK_IMAGE_ASPECT_DEPTH_BIT) << "_ml_" << 0 << "_al_" << 0 << ".bmp";

        const uint32_t texel_size = vkuFormatElementSizeWithAspect(img->format, VK_IMAGE_ASPECT_DEPTH_BIT);
        const uint32_t stride     = texel_size * img->extent.width;

        util::imagewriter::WriteBmpImage(ss.str(),
                                         img->extent.width,
                                         img->extent.height,
                                         subresource_sizes[0],
                                         data.data(),
                                         stride,
                                         VkFormatToImageWriterDataFormat(img->format));
    }

    exit(0);
}

void VulkanReplayResourceDump::ModifyCommandBufferSubmision(std::vector<VkSubmitInfo>& modified_submit_infos)
{
    for (size_t s = 0; s < modified_submit_infos.size(); s++)
    {
        size_t     command_buffer_count   = modified_submit_infos[s].commandBufferCount;
        const auto command_buffer_handles = modified_submit_infos[s].pCommandBuffers;
        for (uint32_t c = 0; c < command_buffer_count; ++c)
        {
            if (original_command_buffer_handle == command_buffer_handles[c])
            {
                VkCommandBuffer* pCommandBuffers =
                    const_cast<VkCommandBuffer*>(modified_submit_infos[s].pCommandBuffers);
                pCommandBuffers[c] = command_buffer;
            }
        }
    }
}

void VulkanReplayResourceDump::SetRenderTargets(const std::vector<const ImageInfo*>&    color_att_imgs,
                                                const std::vector<VkAttachmentStoreOp>& color_att_storeOps,
                                                const ImageInfo*                        depth_att_img,
                                                VkAttachmentStoreOp                     depth_storeOp)
{
    render_targets.color_att_imgs     = color_att_imgs;
    render_targets.color_att_storeOps = color_att_storeOps;
    render_targets.depth_att_img      = depth_att_img;
    render_targets.depth_att_storeOp  = depth_storeOp;
}

void VulkanReplayResourceDump::DetectWritableResources(uint32_t                first_set,
                                                       const format::HandleId* descriptor_sets_ids,
                                                       uint32_t                descriptor_sets_count)
{
    assert(descriptor_sets_ids);

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

                    bound_descriptor_sets[first_set + i].image_infos[binding.first] = img_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                {
                    const BufferInfo* buffer_info =
                        object_info_table_.GetBufferInfo(binding.second.buffer_info.buffer_id);
                    assert(buffer_info);

                    bound_descriptor_sets[first_set + i].buffer_infos[binding.first] = buffer_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    const BufferViewInfo* buffer_view_info =
                        object_info_table_.GetBufferViewInfo(binding.second.texel_buffer_view);
                    assert(buffer_view_info);

                    const BufferInfo* buffer_info = object_info_table_.GetBufferInfo(buffer_view_info->buffer_id);
                    assert(buffer_info);

                    bound_descriptor_sets[first_set + i].buffer_infos[binding.first] = buffer_info;
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

void VulkanReplayResourceDump::DumpResources(const encode::DeviceTable* device_table, uint64_t index)
{
    const CommandBufferInfo* cmd_buf_info = object_info_table_.GetCommandBufferInfo(original_command_buffer);
    assert(cmd_buf_info);

    const DeviceInfo* device_info = object_info_table_.GetDeviceInfo(cmd_buf_info->parent_id);
    assert(device_info);

    const PhysicalDeviceInfo* phys_dev_info = object_info_table_.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(
        device_info->handle, *device_table, *phys_dev_info->replay_device_info->memory_properties);

    for (auto desc_set : bound_descriptor_sets)
    {
        for (const auto storage_images : desc_set.second.image_infos)
        {
            const ImageInfo* img = storage_images.second;

            std::vector<uint8_t>  data;
            std::vector<uint64_t> subresource_offsets;
            std::vector<uint64_t> subresource_sizes;

            resource_util.ReadFromImageResourceStaging(img->handle,
                                                       img->format,
                                                       img->type,
                                                       img->extent,
                                                       img->level_count,
                                                       img->layer_count,
                                                       img->tiling,
                                                       img->sample_count,
                                                       img->current_layout,
                                                       0,
                                                       VK_IMAGE_ASPECT_COLOR_BIT,
                                                       data,
                                                       subresource_offsets,
                                                       subresource_sizes);

            std::stringstream ss;

            ss << "storage_image_" << img->capture_id << "_index_" << index << ".bmp";

            const uint32_t texel_size = vkuFormatElementSize(img->format);
            const uint32_t stride     = texel_size * img->extent.width;

            util::imagewriter::WriteBmpImage(ss.str(),
                                             img->extent.width,
                                             img->extent.height,
                                             subresource_sizes[0],
                                             data.data(),
                                             stride,
                                             VkFormatToImageWriterDataFormat(img->format));
        }

        desc_set.second.image_infos.clear();
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
