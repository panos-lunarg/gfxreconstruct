/*
** Copyright (c) 2024 LunarG, Inc.
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

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_draw_calls.h"
#include "format/format.h"
#include "graphics/vulkan_resources_util.h"
#include "util/image_writer.h"
#include "util/buffer_writer.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"
#include "util/logging.h"
#include "util/platform.h"
#include "util/to_string.h"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <sstream>
#include <vector>
#include <vulkan/vulkan_core.h>
#if !defined(WIN32)
#include <dirent.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

DrawCallsDumpingContext::DrawCallsDumpingContext(const std::vector<uint64_t>&              dc_indices,
                                                 const std::vector<std::vector<uint64_t>>& rp_indices,
                                                 VulkanObjectInfoTable&                    object_info_table,
                                                 const VulkanReplayOptions&                options,
                                                 VulkanReplayDumpResourcesJson&            dump_json) :
    original_command_buffer_info(nullptr),
    current_cb_index(0), dc_indices(dc_indices), RP_indices(rp_indices), active_renderpass(nullptr),
    active_framebuffer(nullptr), bound_pipelines{ nullptr }, current_renderpass(0), current_subpass(0),
    dump_resources_before(options.dump_resources_before), aux_command_buffer(VK_NULL_HANDLE), aux_fence(VK_NULL_HANDLE),
    device_table(nullptr), instance_table(nullptr), object_info_table(object_info_table),
    replay_device_phys_mem_props(nullptr), dump_resource_path(options.dump_resources_output_dir),
    image_file_format(options.dump_resources_image_format), dump_resources_scale(options.dump_resources_scale),
    dump_json(dump_json), dump_depth(options.dump_resources_dump_depth),
    color_attachment_to_dump(options.dump_resources_color_attachment_index),
    dump_vertex_index_buffers(options.dump_resources_dump_vertex_index_buffer),
    output_json_per_command(options.dump_resources_json_per_command),
    dump_immutable_resources(options.dump_resources_dump_immutable_resources),
    dump_all_image_subresources(options.dump_resources_dump_all_image_subresources),
    currently_bound_vertex_buffers(bound_vertex_buffers.end()), currently_bound_index_buffer(bound_index_buffers.end())
{
    must_backup_resources = (dc_indices.size() > 1);

    const size_t n_cmd_buffs = dump_resources_before ? 2 * dc_indices.size() : dc_indices.size();
    command_buffers.resize(n_cmd_buffs, VK_NULL_HANDLE);
}

DrawCallsDumpingContext::~DrawCallsDumpingContext()
{
    if (original_command_buffer_info)
    {
        const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);

        if (device_info == nullptr)
        {
            return;
        }

        VkDevice device = device_info->handle;
        assert(device_table);

        const CommandPoolInfo* pool_info = object_info_table.GetCommandPoolInfo(original_command_buffer_info->pool_id);
        assert(pool_info);

        if (command_buffers.size())
        {
            device_table->FreeCommandBuffers(device, pool_info->handle, command_buffers.size(), command_buffers.data());
        }

        if (aux_command_buffer != VK_NULL_HANDLE)
        {
            device_table->FreeCommandBuffers(device, pool_info->handle, 1, &aux_command_buffer);
            aux_command_buffer = VK_NULL_HANDLE;
        }

        if (aux_fence != VK_NULL_HANDLE)
        {
            device_table->DestroyFence(device, aux_fence, nullptr);
        }

        DestroyMutableResourceBackups();
        ReleaseIndirectDrawParams();
    }
}

void DrawCallsDumpingContext::InsertNewDrawParameters(
    uint64_t index, uint32_t vertex_count, uint32_t instance_count, uint32_t first_vertex, uint32_t first_instance)
{
    auto new_entry = draw_call_params.emplace(
        std::piecewise_construct,
        std::forward_as_tuple(index),
        std::forward_as_tuple(
            DrawCallsDumpingContext::kDraw, vertex_count, instance_count, first_vertex, first_instance));
    assert(new_entry.second);
}

void DrawCallsDumpingContext::InsertNewDrawIndexedParameters(uint64_t index,
                                                             uint32_t index_count,
                                                             uint32_t instance_count,
                                                             uint32_t first_index,
                                                             int32_t  vertexOffset,
                                                             uint32_t first_instance)
{
    auto new_entry = draw_call_params.emplace(std::piecewise_construct,
                                              std::forward_as_tuple(index),
                                              std::forward_as_tuple(DrawCallsDumpingContext::kDrawIndexed,
                                                                    index_count,
                                                                    instance_count,
                                                                    first_index,
                                                                    vertexOffset,
                                                                    first_instance));
    assert(new_entry.second);
}

void DrawCallsDumpingContext::InsertNewDrawIndirectParameters(
    uint64_t index, const BufferInfo* buffer_info, VkDeviceSize offset, uint32_t draw_count, uint32_t stride)
{
    auto new_entry = draw_call_params.emplace(
        std::piecewise_construct,
        std::forward_as_tuple(index),
        std::forward_as_tuple(DrawCallsDumpingContext::kDrawIndirect, buffer_info, offset, draw_count, stride));
    assert(new_entry.second);
}

void DrawCallsDumpingContext::InsertNewDrawIndexedIndirectParameters(
    uint64_t index, const BufferInfo* buffer_info, VkDeviceSize offset, uint32_t draw_count, uint32_t stride)
{
    auto new_entry = draw_call_params.emplace(
        std::piecewise_construct,
        std::forward_as_tuple(index),
        std::forward_as_tuple(DrawCallsDumpingContext::kDrawIndexedIndirect, buffer_info, offset, draw_count, stride));
    assert(new_entry.second);
}

void DrawCallsDumpingContext::InsertNewIndirectCountParameters(uint64_t          index,
                                                               const BufferInfo* buffer_info,
                                                               VkDeviceSize      offset,
                                                               const BufferInfo* count_buffer_info,
                                                               VkDeviceSize      count_buffer_offset,
                                                               uint32_t          max_draw_count,
                                                               uint32_t          stride)
{
    auto new_entry = draw_call_params.emplace(std::piecewise_construct,
                                              std::forward_as_tuple(index),
                                              std::forward_as_tuple(DrawCallsDumpingContext::kDrawIndirectCount,
                                                                    buffer_info,
                                                                    offset,
                                                                    count_buffer_info,
                                                                    count_buffer_offset,
                                                                    max_draw_count,
                                                                    stride));
    assert(new_entry.second);
}

void DrawCallsDumpingContext::InsertNewDrawIndexedIndirectCountParameters(uint64_t          index,
                                                                          const BufferInfo* buffer_info,
                                                                          VkDeviceSize      offset,
                                                                          const BufferInfo* count_buffer_info,
                                                                          VkDeviceSize      count_buffer_offset,
                                                                          uint32_t          max_draw_count,
                                                                          uint32_t          stride)
{
    auto new_entry = draw_call_params.emplace(std::piecewise_construct,
                                              std::forward_as_tuple(index),
                                              std::forward_as_tuple(DrawCallsDumpingContext::kDrawIndexedIndirectCount,
                                                                    buffer_info,
                                                                    offset,
                                                                    count_buffer_info,
                                                                    count_buffer_offset,
                                                                    max_draw_count,
                                                                    stride));
    assert(new_entry.second);
}

void DrawCallsDumpingContext::InsertNewDrawIndirectCountKHRParameters(uint64_t          index,
                                                                      const BufferInfo* buffer_info,
                                                                      VkDeviceSize      offset,
                                                                      const BufferInfo* count_buffer_info,
                                                                      VkDeviceSize      count_buffer_offset,
                                                                      uint32_t          max_draw_count,
                                                                      uint32_t          stride)
{
    auto new_entry = draw_call_params.emplace(std::piecewise_construct,
                                              std::forward_as_tuple(index),
                                              std::forward_as_tuple(DrawCallsDumpingContext::kDrawIndirectCountKHR,
                                                                    buffer_info,
                                                                    offset,
                                                                    count_buffer_info,
                                                                    count_buffer_offset,
                                                                    max_draw_count,
                                                                    stride));
    assert(new_entry.second);
}

void DrawCallsDumpingContext::InsertNewDrawIndexedIndirectCountKHRParameters(uint64_t          index,
                                                                             const BufferInfo* buffer_info,
                                                                             VkDeviceSize      offset,
                                                                             const BufferInfo* count_buffer_info,
                                                                             VkDeviceSize      count_buffer_offset,
                                                                             uint32_t          max_draw_count,
                                                                             uint32_t          stride)
{
    auto new_entry =
        draw_call_params.emplace(std::piecewise_construct,
                                 std::forward_as_tuple(index),
                                 std::forward_as_tuple(DrawCallsDumpingContext::kDrawIndexedIndirectCountKHR,
                                                       buffer_info,
                                                       offset,
                                                       count_buffer_info,
                                                       count_buffer_offset,
                                                       max_draw_count,
                                                       stride));
    assert(new_entry.second);
}

VkResult DrawCallsDumpingContext::CopyDrawIndirectParameters(uint64_t index)
{
    auto entry = draw_call_params.find(index);
    assert(entry != draw_call_params.end());

    DrawCallParameters& dc_params = entry->second;

    assert(IsDrawCallIndirect(dc_params.type));

    if (IsDrawCallIndirectCount(dc_params.type))
    {
        DrawCallParameters::DrawCallParamsUnion::DrawIndirectCountParams& ic_params =
            dc_params.dc_params_union.draw_indirect_count;

        const uint32_t max_draw_count = ic_params.max_draw_count;

        // Not sure from spec if max_draw_count can be zero. Assume it can
        if (!max_draw_count)
        {
            return VK_SUCCESS;
        }

        const VkDeviceSize draw_call_params_size =
            IsDrawCallIndexed(dc_params.type) ? sizeof(DrawCallParameters::DrawCallParamsUnion::DrawIndexedParams)
                                              : sizeof(DrawCallParameters::DrawCallParamsUnion::DrawParams);

        // Create a buffer to copy the parameters buffer
        const VkDeviceSize copy_buffer_size = draw_call_params_size * max_draw_count;
        assert(copy_buffer_size <= ic_params.params_buffer_info->size);

        ic_params.new_params_buffer_size = copy_buffer_size;

        VkResult res = CloneBuffer(object_info_table,
                                   device_table,
                                   replay_device_phys_mem_props,
                                   ic_params.params_buffer_info,
                                   &ic_params.new_params_buffer,
                                   &ic_params.new_params_memory,
                                   copy_buffer_size);
        if (res != VK_SUCCESS)
        {
            return res;
        }

        // Inject a cmdCopyBuffer to copy the draw params into the new buffer
        {
            const uint32_t            param_buffer_stride = ic_params.stride;
            std::vector<VkBufferCopy> regions(param_buffer_stride ? max_draw_count : 1);
            if (param_buffer_stride != draw_call_params_size)
            {
                VkDeviceSize src_offset = ic_params.params_buffer_offset;
                VkDeviceSize dst_offset = 0;
                for (uint32_t i = 0; i < max_draw_count; ++i)
                {
                    regions[i].size = draw_call_params_size;

                    regions[i].srcOffset = src_offset;
                    src_offset += param_buffer_stride;

                    regions[i].dstOffset = dst_offset;
                    dst_offset += draw_call_params_size;
                }
                assert(src_offset == copy_buffer_size);
            }
            else
            {
                regions[0].size      = copy_buffer_size;
                regions[0].srcOffset = ic_params.params_buffer_offset;
                regions[0].dstOffset = 0;
            }

            VkCommandBuffer cmd_buf = command_buffers[current_cb_index];
            device_table->CmdCopyBuffer(cmd_buf,
                                        ic_params.params_buffer_info->handle,
                                        ic_params.new_params_buffer,
                                        regions.size(),
                                        regions.data());

            VkBufferMemoryBarrier buf_barrier;
            buf_barrier.sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
            buf_barrier.pNext               = nullptr;
            buf_barrier.buffer              = ic_params.new_params_buffer;
            buf_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
            buf_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
            buf_barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            buf_barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            buf_barrier.size                = copy_buffer_size;
            buf_barrier.offset              = 0;

            device_table->CmdPipelineBarrier(cmd_buf,
                                             VK_PIPELINE_STAGE_TRANSFER_BIT,
                                             VK_PIPELINE_STAGE_TRANSFER_BIT,
                                             VkDependencyFlags{ 0 },
                                             0,
                                             nullptr,
                                             1,
                                             &buf_barrier,
                                             0,
                                             nullptr);
        }

        // Create a buffer to copy the draw count parameter
        const VkDeviceSize count_buffer_size = sizeof(uint32_t);
        assert(count_buffer_size <= ic_params.count_buffer_info->size);
        res = CloneBuffer(object_info_table,
                          device_table,
                          replay_device_phys_mem_props,
                          ic_params.count_buffer_info,
                          &ic_params.new_count_buffer,
                          &ic_params.new_count_memory,
                          count_buffer_size);
        if (res != VK_SUCCESS)
        {
            return res;
        }

        // Inject a cmdCopyBuffer to copy the count into the new buffer
        {
            VkBufferCopy region;
            region.size      = count_buffer_size;
            region.srcOffset = ic_params.count_buffer_offset;
            region.dstOffset = 0;

            VkCommandBuffer cmd_buf = command_buffers[current_cb_index];
            device_table->CmdCopyBuffer(
                cmd_buf, ic_params.params_buffer_info->handle, ic_params.new_params_buffer, 1, &region);

            VkBufferMemoryBarrier buf_barrier;
            buf_barrier.sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
            buf_barrier.pNext               = nullptr;
            buf_barrier.buffer              = ic_params.new_count_buffer;
            buf_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
            buf_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
            buf_barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            buf_barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            buf_barrier.size                = count_buffer_size;
            buf_barrier.offset              = 0;

            device_table->CmdPipelineBarrier(cmd_buf,
                                             VK_PIPELINE_STAGE_TRANSFER_BIT,
                                             VK_PIPELINE_STAGE_TRANSFER_BIT,
                                             VkDependencyFlags{ 0 },
                                             0,
                                             nullptr,
                                             1,
                                             &buf_barrier,
                                             0,
                                             nullptr);
        }
    }
    else
    {
        DrawCallParameters::DrawCallParamsUnion::DrawIndirectParams& i_params = dc_params.dc_params_union.draw_indirect;

        const uint32_t draw_count = i_params.draw_count;

        // According to spec drawCount can be zero. Nothing to do in this case
        if (!draw_count)
        {
            return VK_SUCCESS;
        }

        const VkDeviceSize draw_call_params_size =
            IsDrawCallIndexed(dc_params.type) ? sizeof(DrawCallParameters::DrawCallParamsUnion::DrawIndexedParams)
                                              : sizeof(DrawCallParameters::DrawCallParamsUnion::DrawParams);

        // Create a buffer to copy the parameters buffer
        const VkDeviceSize copy_buffer_size = draw_call_params_size * draw_count;
        assert(copy_buffer_size <= i_params.params_buffer_info->size);

        i_params.new_params_buffer_size = copy_buffer_size;

        VkResult res = CloneBuffer(object_info_table,
                                   device_table,
                                   replay_device_phys_mem_props,
                                   i_params.params_buffer_info,
                                   &i_params.new_params_buffer,
                                   &i_params.new_params_memory,
                                   copy_buffer_size);
        if (res != VK_SUCCESS)
        {
            return res;
        }

        // Inject a cmdCopyBuffer to copy the draw params into the new buffer
        {
            const uint32_t            param_buffer_stride = i_params.stride;
            std::vector<VkBufferCopy> regions(param_buffer_stride ? draw_count : 1);
            if (param_buffer_stride != draw_call_params_size)
            {
                VkDeviceSize src_offset = i_params.params_buffer_offset;
                VkDeviceSize dst_offset = 0;
                for (uint32_t i = 0; i < draw_count; ++i)
                {
                    regions[i].size = draw_call_params_size;

                    regions[i].srcOffset = src_offset;
                    src_offset += param_buffer_stride;

                    regions[i].dstOffset = dst_offset;
                    dst_offset += draw_call_params_size;
                }
                assert(src_offset == copy_buffer_size);
            }
            else
            {
                regions[0].size      = copy_buffer_size;
                regions[0].srcOffset = i_params.params_buffer_offset;
                regions[0].dstOffset = 0;
            }

            VkCommandBuffer cmd_buf = command_buffers[current_cb_index];
            device_table->CmdCopyBuffer(cmd_buf,
                                        i_params.params_buffer_info->handle,
                                        i_params.new_params_buffer,
                                        regions.size(),
                                        regions.data());

            VkBufferMemoryBarrier buf_barrier;
            buf_barrier.sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
            buf_barrier.pNext               = nullptr;
            buf_barrier.buffer              = i_params.new_params_buffer;
            buf_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
            buf_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
            buf_barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            buf_barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            buf_barrier.size                = copy_buffer_size;
            buf_barrier.offset              = 0;

            device_table->CmdPipelineBarrier(cmd_buf,
                                             VK_PIPELINE_STAGE_TRANSFER_BIT,
                                             VK_PIPELINE_STAGE_TRANSFER_BIT,
                                             VkDependencyFlags{ 0 },
                                             0,
                                             nullptr,
                                             1,
                                             &buf_barrier,
                                             0,
                                             nullptr);
        }
    }

    return VK_SUCCESS;
}

void DrawCallsDumpingContext::SnapshotBoundDescriptors(uint64_t index)
{
    const PipelineInfo* gr_pipeline_info = bound_pipelines[kBindPoint_graphics];
    if (gr_pipeline_info != nullptr)
    {
        auto entry = draw_call_params.find(index);
        assert(entry != draw_call_params.end());

        DrawCallParameters& dc_params = entry->second;

        // Iterate all shader stages
        for (const auto& shader_stage : gr_pipeline_info->shaders)
        {
            const VkShaderStageFlagBits shader_stage_flag = shader_stage.first;

            // Iterate all referenced descriptor sets in each shader stage
            for (const auto& shader_desc_set : shader_stage.second.used_descriptors_info)
            {
                const uint32_t desc_set_index = shader_desc_set.first;

                const auto& ppl_desc_set = bound_descriptor_sets_gr.find(desc_set_index);
                assert(ppl_desc_set != bound_descriptor_sets_gr.end());

                if (ppl_desc_set == bound_descriptor_sets_gr.end())
                {
                    continue;
                }

                for (const auto& shader_desc_binding : shader_desc_set.second)
                {
                    const uint32_t desc_set_binding_index = shader_desc_binding.first;

                    // if (!shader_desc_binding.second.accessed)
                    // {
                    //     continue;
                    // }

                    const auto& ppl_desc_binding = ppl_desc_set->second.descriptors.find(desc_set_binding_index);
                    assert(ppl_desc_binding != ppl_desc_set->second.descriptors.end());
                    if (ppl_desc_binding == ppl_desc_set->second.descriptors.end())
                    {
                        continue;
                    }

                    if (!CheckDescriptorCompatibility(shader_desc_binding.second.type,
                                                      ppl_desc_binding->second.desc_type))
                    {
                        GFXRECON_LOG_WARNING("Descriptors are incompatible:");
                        GFXRECON_LOG_WARNING("shader stage: %s",
                                             util::ToString<VkShaderStageFlagBits>(shader_stage_flag).c_str());
                        GFXRECON_LOG_WARNING("desc_set_index: %u", desc_set_index);
                        GFXRECON_LOG_WARNING("desc_set_binding_index: %u", desc_set_binding_index);
                        GFXRECON_LOG_WARNING("shader_desc_binding.second.type: %s",
                                             util::ToString<VkDescriptorType>(shader_desc_binding.second.type).c_str());
                        GFXRECON_LOG_WARNING(
                            "ppl_desc_binding->second.desc_type: %s",
                            util::ToString<VkDescriptorType>(ppl_desc_binding->second.desc_type).c_str());
                    }

                    dc_params.referenced_descriptors[shader_stage_flag][desc_set_index][desc_set_binding_index] =
                        ppl_desc_binding->second;
                }
            }
        }
    }
}

void DrawCallsDumpingContext::CopyVertexInputStateInfo(uint64_t dc_index)
{
    auto entry = draw_call_params.find(dc_index);
    assert(entry != draw_call_params.end());

    DrawCallParameters& dc_params = entry->second;

    const PipelineInfo* gr_pipeline_info = bound_pipelines[kBindPoint_graphics];
    assert(gr_pipeline_info != nullptr);

    // Pipeline has no vertex binding and/or attribute information.
    // This can be a case of shader generated vertices, or vertex buffer is bound as a UBO
    if (gr_pipeline_info != nullptr &&
        (!gr_pipeline_info->vertex_input_attribute_map.size() &&
         !gr_pipeline_info->vertex_input_attribute_map.size()) &&
        (!gr_pipeline_info->dynamic_vertex_input && !gr_pipeline_info->dynamic_vertex_binding_stride))
    {
        return;
    }

    // If VK_DYNAMIC_STATE_VERTEX_INPUT_EXT is enabled then get all vertex input state from
    // vkCmdSetVertexInputEXT
    if (gr_pipeline_info == nullptr || gr_pipeline_info->dynamic_vertex_input)
    {
        currently_bound_vertex_buffers->second.vertex_input_state = dynamic_vertex_input_state;
    }
    else
    {
        if (gr_pipeline_info)
        {
            // Copy vertex input binding state
            currently_bound_vertex_buffers->second.vertex_input_state.input_binding_map =
                gr_pipeline_info->vertex_input_binding_map;

            // If VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE_EXT is enabled, ignore strides from
            // pipeline and get them from vkCmdBindVertexBuffers2EXT instead
            if (gr_pipeline_info->dynamic_vertex_binding_stride)
            {
                for (auto& vb_binding : currently_bound_vertex_buffers->second.vertex_input_state.input_binding_map)
                {
                    const uint32_t binding = vb_binding.first;
                    if (dynamic_vertex_input_state.input_binding_map.find(binding) !=
                        dynamic_vertex_input_state.input_binding_map.end())
                    {
                        vb_binding.second.stride = dynamic_vertex_input_state.input_binding_map[binding].stride;
                    }
                }
            }

            // Copy vertex attributes info
            currently_bound_vertex_buffers->second.vertex_input_state.input_attribute_map =
                gr_pipeline_info->vertex_input_attribute_map;
        }
    }

    assert(currently_bound_vertex_buffers != bound_vertex_buffers.end());

    currently_bound_vertex_buffers->second.referencing_draw_calls.push_back(dc_index);
    dc_params.referenced_bind_vertex_buffers = currently_bound_vertex_buffers->first;

    if (IsDrawCallIndexed(dc_params.type))
    {
        assert(currently_bound_index_buffer != bound_index_buffers.end());

        currently_bound_index_buffer->second.referencing_draw_calls.push_back(dc_index);
        dc_params.referenced_bind_index_buffer = currently_bound_index_buffer->first;
    }
}

void DrawCallsDumpingContext::FinalizeCommandBuffer()
{
    assert(current_cb_index < command_buffers.size());
    VkCommandBuffer current_command_buffer = command_buffers[current_cb_index];
    assert(device_table != nullptr);

    assert(inside_renderpass);

    device_table->CmdEndRenderPass(current_command_buffer);
    device_table->EndCommandBuffer(current_command_buffer);

    // Increment index of command buffer that is going to be finalized next
    ++current_cb_index;
}

bool DrawCallsDumpingContext::MustDumpDrawCall(uint64_t index) const
{
    // Indices should be sorted
    if (!IsInsideRange(dc_indices, index))
    {
        return false;
    }

    for (size_t i = dump_resources_before ? current_cb_index / 2 : current_cb_index; i < dc_indices.size(); ++i)
    {
        if (index == dc_indices[i])
        {
            return true;
        }
        else if (index > dc_indices[i])
        {
            // Indices should be sorted
            return false;
        }
    }

    return false;
}

bool DrawCallsDumpingContext::ShouldHandleRenderPass(uint64_t index) const
{
    for (const auto& rp : RP_indices)
    {
        if (IsInsideRange(rp, index))
        {
            return true;
        }
    }

    return false;
}

VkResult DrawCallsDumpingContext::DumpDrawCalls(
    VkQueue queue, uint64_t qs_index, uint64_t bcb_index, const VkSubmitInfo& submit_info, VkFence fence)
{
    const size_t n_drawcalls = command_buffers.size();

    VkResult res = VK_SUCCESS;

    // Dump render targets
    for (size_t cb = 0; cb < n_drawcalls; ++cb)
    {
        GFXRECON_LOG_INFO("Submitting CB/DC %u of %zu (idx: %" PRIu64 ") for BeginCommandBuffer: %" PRIu64,
                          cb,
                          n_drawcalls,
                          dc_indices[CmdBufToDCVectorIndex(cb)],
                          bcb_index);

        if (!output_json_per_command)
        {
            dump_json.VulkanReplayDumpResourcesJsonBlockStart();
        }

        VkSubmitInfo si;
        si.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        si.pNext                = nullptr;
        si.waitSemaphoreCount   = !cb ? submit_info.waitSemaphoreCount : 0;
        si.pWaitSemaphores      = !cb ? submit_info.pWaitSemaphores : nullptr;
        si.pWaitDstStageMask    = !cb ? submit_info.pWaitDstStageMask : nullptr;
        si.commandBufferCount   = 1;
        si.pCommandBuffers      = &command_buffers[cb];
        si.signalSemaphoreCount = (cb == (n_drawcalls - 1)) ? submit_info.signalSemaphoreCount : 0;
        si.pSignalSemaphores    = (cb == (n_drawcalls - 1)) ? submit_info.pSignalSemaphores : nullptr;

        const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
        assert(device_info);

        const VkFenceCreateInfo ci = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
        VkFence                 submission_fence;
        if (fence == VK_NULL_HANDLE)
        {
            res = device_table->CreateFence(device_info->handle, &ci, nullptr, &submission_fence);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("CreateFence failed with %s", util::ToString<VkResult>(res).c_str());
                return res;
            }
        }
        else
        {
            submission_fence = fence;
        }

        res = device_table->QueueSubmit(queue, 1, &si, submission_fence);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
            return res;
        }

        // Wait
        res = device_table->WaitForFences(device_info->handle, 1, &submission_fence, VK_TRUE, ~0UL);
        if (res != VK_SUCCESS)
        {
            device_table->DestroyFence(device_info->handle, submission_fence, nullptr);
            GFXRECON_LOG_ERROR("WaitForFences failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }

        if (fence == VK_NULL_HANDLE)
        {
            device_table->DestroyFence(device_info->handle, submission_fence, nullptr);
        }

        // Dump render targets
        DumpRenderTargetAttachments(cb, qs_index, bcb_index);

        GenerateOutputJsonDrawCallInfo(cb, qs_index, bcb_index);

        if (!output_json_per_command)
        {
            dump_json.VulkanReplayDumpResourcesJsonBlockEnd();
        }
    }

    // Dump vertex/index buffers
    if (dump_vertex_index_buffers && res == VK_SUCCESS)
    {
        res = DumpVertexIndexBuffers();
    }

    // Dump immutable resources
    if (dump_immutable_resources && res == VK_SUCCESS)
    {
        res = DumpImmutableResources(qs_index, bcb_index);
    }

    if (res != VK_SUCCESS)
    {
        return res;
    }

    return res;
}

#define DEPTH_ATTACHMENT ~0

std::vector<std::string> DrawCallsDumpingContext::GenerateRenderTargetImageFilename(VkFormat format,
                                                                                    uint64_t cmd_buf_index,
                                                                                    uint64_t dc_index,
                                                                                    int      attachment_index) const
{
    std::vector<VkImageAspectFlagBits> aspects;
    bool                               combined_depth_stencil;
    graphics::GetFormatAspects(format, &aspects, &combined_depth_stencil);

    std::vector<std::string> filenames(aspects.size());

    for (size_t i = 0; i < aspects.size(); ++i)
    {
        std::string aspect_str_whole(util::ToString<VkImageAspectFlagBits>(aspects[i]));
        std::string aspect_str(aspect_str_whole.begin() + 16, aspect_str_whole.end() - 4);
        std::string attachment_str =
            attachment_index != DEPTH_ATTACHMENT ? "_att_" + std::to_string(attachment_index) : "_depth_att_";

        std::stringstream filename;
        if (VkFormatToImageWriterDataFormat(format) != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
        {
            if (dump_resources_before)
            {
                filename << "Draw_" << ((cmd_buf_index % 2) ? "after_" : "before_") << dc_index << attachment_str
                         << "_aspect_" << aspect_str;
            }
            else
            {
                filename << "Draw_" << dc_index << attachment_str << "_aspect_" << aspect_str;
            }
        }
        else
        {
            if (dump_resources_before)
            {
                filename << "Draw_" << ((cmd_buf_index % 2) ? "after_" : "before_") << dc_index << attachment_str
                         << util::ToString<VkFormat>(format) << "_aspect_" << aspect_str;
            }
            else
            {
                filename << "Draw_" << dc_index << attachment_str << util::ToString<VkFormat>(format) << "_aspect_"
                         << aspect_str;
            }
        }

        std::filesystem::path filedirname(dump_resource_path);
        std::filesystem::path filebasename(filename.str());
        filenames[i] = (filedirname / filebasename).string();
    }

    return filenames;
}

void DrawCallsDumpingContext::GenerateOutputJsonDrawCallInfo(uint64_t cmd_buf_index,
                                                             uint64_t qs_index,
                                                             uint64_t bcb_index) const
{
    const size_t                dc_index = dc_indices[CmdBufToDCVectorIndex(cmd_buf_index)];
    const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
    const uint64_t              rp       = RP_index.first;
    const uint64_t              sp       = RP_index.second;

    VulkanReplayDumpResourcesJson  draw_call_output_json;
    VulkanReplayDumpResourcesJson* output_json_writer;
    if (output_json_per_command)
    {
        const std::string dc_json_filename = "DrawCall_" + std::to_string(dc_index);
        draw_call_output_json.VulkanReplayDumpResourcesJsonOpen(dc_json_filename, dump_resource_path);
        draw_call_output_json.VulkanReplayDumpResourcesJsonBlockStart();

        output_json_writer = &draw_call_output_json;
    }
    else
    {
        output_json_writer = &dump_json;
    }

    for (size_t i = 0; i < render_targets[rp][sp].color_att_imgs.size(); ++i)
    {
        if (color_attachment_to_dump != kUnspecifiedColorAttachment &&
            static_cast<size_t>(color_attachment_to_dump) != i)
        {
            continue;
        }

        const ImageInfo* image_info = render_targets[rp][sp].color_att_imgs[i];

        const std::vector<std::string> filenames =
            GenerateRenderTargetImageFilename(image_info->format, cmd_buf_index, dc_index, i);

        output_json_writer->VulkanReplayDumpResourcesJsonData("DrawIndex", dc_index);
        output_json_writer->VulkanReplayDumpResourcesJsonData("BeginCommandBufferIndex", bcb_index);
        output_json_writer->VulkanReplayDumpResourcesJsonData("QueueSubmitIndex", qs_index);
        output_json_writer->VulkanReplayDumpResourcesJsonData(("RenderTargetImage_" + std::to_string(i)).c_str(),
                                                              filenames[0]);
    }

    if (dump_depth && render_targets[rp][sp].depth_att_img != nullptr)
    {
        const ImageInfo*               image_info = render_targets[rp][sp].depth_att_img;
        const std::vector<std::string> filenames =
            GenerateRenderTargetImageFilename(image_info->format, cmd_buf_index, dc_index, DEPTH_ATTACHMENT);

        for (size_t i = 0; i < filenames.size(); ++i)
        {
            output_json_writer->VulkanReplayDumpResourcesJsonData("RenderTargetDepth_", filenames[i]);
        }
    }

    // Emit in json output the references to vertex and index buffers dumped files
    if (dump_vertex_index_buffers)
    {
        const auto& dc_param_entry = draw_call_params.find(dc_index);
        assert(dc_param_entry != draw_call_params.end());
        if (dc_param_entry != draw_call_params.end())
        {
            const DrawCallParameters& dc_param = dc_param_entry->second;
            if (IsDrawCallIndexed(dc_param.type))
            {
                assert(dc_param.referenced_bind_index_buffer != DrawCallParameters::INVALID_BLOCK_INDEX);
                const auto bound_index_buffer_entry = bound_index_buffers.find(dc_param.referenced_bind_index_buffer);
                assert(bound_index_buffer_entry != bound_index_buffers.end());
                if (bound_index_buffer_entry != bound_index_buffers.end())
                {
                    const std::string index_buffer_filename = GenerateIndexBufferFilename(
                        dc_param.referenced_bind_index_buffer, bound_index_buffer_entry->second.index_type);

                    output_json_writer->VulkanReplayDumpResourcesJsonData("IndexBuffer", index_buffer_filename);
                }
            }

            const auto& dc_vbo = bound_vertex_buffers.find(dc_param.referenced_bind_vertex_buffers);
            if (dc_vbo != bound_vertex_buffers.end())
            {
                uint32_t i = 0;
                for (const auto& vb_binding : dc_vbo->second.vertex_input_state.input_binding_map)
                {
                    const std::string vb_filename =
                        GenerateVertexBufferFilename(dc_param.referenced_bind_vertex_buffers, vb_binding.first);
                    output_json_writer->VulkanReplayDumpResourcesJsonData(("VertexBuffer_" + std::to_string(i++)),
                                                                          vb_filename);
                }
            }
        }
    }

    // Emit in json output the references to dumped immutable descriptors
    if (dump_immutable_resources)
    {
        const auto& dc_param_entry = draw_call_params.find(dc_index);
        assert(dc_param_entry != draw_call_params.end());
        if (dc_param_entry != draw_call_params.end())
        {
            const DrawCallParameters& dc_param = dc_param_entry->second;
            for (const auto& shader_stage : dc_param.referenced_descriptors)
            {
                for (const auto& desc_set : shader_stage.second)
                {
                    const uint32_t desc_set_index = desc_set.first;

                    for (const auto& desc_binding : desc_set.second)
                    {
                        const uint32_t desc_set_binding_index = desc_binding.first;

                        const std::string shader_stage_name_whole =
                            util::ToString<VkShaderStageFlagBits>(shader_stage.first);
                        std::string shader_stage_name;
                        if (!shader_stage_name_whole.compare(shader_stage_name_whole.size() - 4, 4, "_BIT"))
                        {
                            shader_stage_name = shader_stage_name_whole.substr(16, shader_stage_name_whole.size() - 20);
                        }
                        else if (!shader_stage_name_whole.compare(shader_stage_name_whole.size() - 8, 8, "_BIT_KHR"))
                        {
                            shader_stage_name = shader_stage_name_whole.substr(16, shader_stage_name_whole.size() - 24);
                        }

                        std::string desc_entry = "Descriptor_stage:" + shader_stage_name +
                                                 "_set:" + std::to_string(desc_set_index) +
                                                 "_binding:" + std::to_string(desc_set_binding_index);

                        switch (desc_binding.second.desc_type)
                        {
                            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                            {
                                for (size_t img = 0; img < desc_binding.second.image_info.size(); ++img)
                                {
                                    if (desc_binding.second.image_info[img].image_view_info == nullptr)
                                    {
                                        continue;
                                    }

                                    const ImageInfo* img_info = object_info_table.GetImageInfo(
                                        desc_binding.second.image_info[img].image_view_info->image_id);
                                    assert(img_info != nullptr);

                                    desc_entry += "[" + std::to_string(img) + "]";

                                    std::vector<std::string> filenames = GenerateImageDescriptorFilename(img_info);
                                    for (std::string& filename : filenames)
                                    {
                                        filename += ImageFileExtension(img_info->format, image_file_format);
                                        output_json_writer->VulkanReplayDumpResourcesJsonData(desc_entry, filename);
                                    }
                                }
                            }
                            break;

                            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                            {
                                for (size_t buf = 0; buf < desc_binding.second.image_info.size(); ++buf)
                                {
                                    const BufferInfo* buf_info = desc_binding.second.buffer_info[buf].buffer_info;
                                    if (buf_info == nullptr)
                                    {
                                        continue;
                                    }

                                    desc_entry += "[" + std::to_string(buf) + "]";

                                    const std::string filename = GenerateBufferDescriptorFilename(buf_info->capture_id);
                                    output_json_writer->VulkanReplayDumpResourcesJsonData(desc_entry, filename);
                                }
                            }
                            break;

                            default:
                                break;
                        }
                    }
                }
            }
        }
    }

    if (output_json_per_command)
    {
        draw_call_output_json.VulkanReplayDumpResourcesJsonBlockEnd();
        draw_call_output_json.VulkanReplayDumpResourcesJsonClose();
    }
}

VkResult DrawCallsDumpingContext::DumpRenderTargetAttachments(uint64_t cmd_buf_index,
                                                              uint64_t qs_index,
                                                              uint64_t bcb_index) const
{
    assert(device_table != nullptr);

    const size_t                dc_index = dc_indices[CmdBufToDCVectorIndex(cmd_buf_index)];
    const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
    const uint64_t              rp       = RP_index.first;
    const uint64_t              sp       = RP_index.second;

    if (!render_targets[rp][sp].color_att_imgs.size() && render_targets[rp][sp].depth_att_img == nullptr)
    {
        return VK_SUCCESS;
    }

    assert(original_command_buffer_info);
    assert(original_command_buffer_info->parent_id != format::kNullHandleId);
    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    const PhysicalDeviceInfo* phys_dev_info = object_info_table.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table,
                                                *instance_table,
                                                *phys_dev_info->replay_device_info->memory_properties);

    // Dump color attachments
    for (size_t i = 0; i < render_targets[rp][sp].color_att_imgs.size(); ++i)
    {
        if (color_attachment_to_dump != kUnspecifiedColorAttachment &&
            static_cast<size_t>(color_attachment_to_dump) != i)
        {
            continue;
        }

        const ImageInfo* image_info = render_targets[rp][sp].color_att_imgs[i];

        const std::vector<std::string> filenames =
            GenerateRenderTargetImageFilename(image_info->format, cmd_buf_index, dc_index, i);

        const VkExtent3D extent{ render_area[rp].extent.width, render_area[rp].extent.height, 1 };
        VkResult         res = DumpImageToFile(image_info,
                                       device_info,
                                       device_table,
                                       instance_table,
                                       object_info_table,
                                       filenames,
                                       dump_resources_scale,
                                       image_file_format,
                                       dump_all_image_subresources,
                                       VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                       &extent);

        if (res != VK_SUCCESS)
        {
            return res;
        }
    }

    // Dump depth attachment
    if (dump_depth && render_targets[rp][sp].depth_att_img != nullptr)
    {
        const ImageInfo* image_info = render_targets[rp][sp].depth_att_img;

        std::vector<uint8_t>  data;
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;
        bool                  scaling_supported;

        const std::vector<std::string> filenames =
            GenerateRenderTargetImageFilename(image_info->format, cmd_buf_index, dc_index, DEPTH_ATTACHMENT);

        const VkExtent3D extent{ render_area[rp].extent.width, render_area[rp].extent.height, 1 };
        VkResult         res = DumpImageToFile(image_info,
                                       device_info,
                                       device_table,
                                       instance_table,
                                       object_info_table,
                                       filenames,
                                       dump_resources_scale,
                                       image_file_format,
                                       dump_all_image_subresources,
                                       VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                       &extent);

        if (res != VK_SUCCESS)
        {
            return res;
        }
    }

    return VK_SUCCESS;
}

std::vector<std::string> DrawCallsDumpingContext::GenerateImageDescriptorFilename(const ImageInfo* img_info) const
{
    assert(img_info != nullptr);

    std::vector<VkImageAspectFlagBits> aspects;
    bool                               combined_depth_stencil;
    graphics::GetFormatAspects(img_info->format, &aspects, &combined_depth_stencil);

    const uint32_t total_files =
        dump_all_image_subresources ? (aspects.size() * img_info->level_count * img_info->layer_count) : aspects.size();
    std::vector<std::string> filenames(total_files);

    uint32_t f = 0;
    for (size_t i = 0; i < aspects.size(); ++i)
    {
        std::string       aspect_str_whole(util::ToString<VkImageAspectFlagBits>(aspects[i]));
        std::string       aspect_str(aspect_str_whole.begin() + 16, aspect_str_whole.end() - 4);
        std::stringstream base_filename;

        const util::imagewriter::DataFormats output_format = VkFormatToImageWriterDataFormat(img_info->format);
        if (output_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED &&
            output_format != util::imagewriter::DataFormats::kFormat_ASTC)
        {
            base_filename << "Image_" << img_info->capture_id << "_aspect_" << aspect_str;
        }
        else
        {
            std::string whole_format_name = util::ToString<VkFormat>(img_info->format);
            std::string format_name(whole_format_name.begin() + 10, whole_format_name.end());

            base_filename << "Image_" << img_info->capture_id << "_" << format_name << "_aspect_" << aspect_str;
        }

        if (dump_all_image_subresources && (img_info->level_count > 1 || img_info->layer_count > 1))
        {
            for (uint32_t level = 0; level < img_info->level_count; ++level)
            {
                for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                {
                    std::stringstream sub_resources_str;
                    sub_resources_str << base_filename.str() << "_mip_" << level << "_layer_" << layer;
                    std::filesystem::path filedirname(dump_resource_path);
                    std::filesystem::path filebasename(sub_resources_str.str());
                    filenames[f++] = (filedirname / filebasename).string();
                }
            }
        }
        else
        {
            std::filesystem::path filedirname(dump_resource_path);
            std::filesystem::path filebasename(base_filename.str());
            filenames[f++] = (filedirname / filebasename).string();
        }
    }

    assert(f == total_files);

    return std::move(filenames);
}

std::string DrawCallsDumpingContext::GenerateBufferDescriptorFilename(format::HandleId buffer_id) const
{
    std::stringstream filename;

    filename << "Buffer_" << buffer_id << ".bin";

    std::filesystem::path filedirname(dump_resource_path);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

VkResult DrawCallsDumpingContext::DumpImmutableResources(uint64_t qs_index, uint64_t bcb_index) const
{
    // Create a list of all descriptors referenced by all draw calls
    std::unordered_set<const ImageInfo*> image_descriptors;

    struct buffer_descriptor_info
    {
        VkDeviceSize offset;
        VkDeviceSize range;
    };
    std::unordered_map<const BufferInfo*, buffer_descriptor_info> buffer_descriptors;

    for (const auto& dc_params : draw_call_params)
    {
        for (const auto& shader_stage : dc_params.second.referenced_descriptors)
        {
            const VkShaderStageFlagBits stage = shader_stage.first;
            for (const auto& desc_set : shader_stage.second)
            {
                const uint32_t desc_set_index = desc_set.first;
                for (const auto& desc_binding : desc_set.second)
                {
                    const uint32_t desc_binding_index = desc_binding.first;

                    switch (desc_binding.second.desc_type)
                    {
                        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                        {
                            for (size_t i = 0; i < desc_binding.second.image_info.size(); ++i)
                            {
                                if (desc_binding.second.image_info[i].image_view_info != nullptr)
                                {
                                    const ImageInfo* img_info = object_info_table.GetImageInfo(
                                        desc_binding.second.image_info[i].image_view_info->image_id);
                                    assert(img_info);

                                    image_descriptors.insert(img_info);
                                }
                            }
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                        {
                            for (size_t i = 0; i < desc_binding.second.buffer_info.size(); ++i)
                            {
                                if (desc_binding.second.buffer_info[i].buffer_info != nullptr)
                                {
                                    buffer_descriptors.emplace(
                                        std::piecewise_construct,
                                        std::forward_as_tuple(desc_binding.second.buffer_info[i].buffer_info),
                                        std::forward_as_tuple(
                                            buffer_descriptor_info{ desc_binding.second.buffer_info[i].offset,
                                                                    desc_binding.second.buffer_info[i].range }));
                                }
                            }
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                        case VK_DESCRIPTOR_TYPE_SAMPLER:
                            break;

                        default:
                            GFXRECON_LOG_WARNING_ONCE(
                                "%s(): Descriptor type (%s) not handled",
                                __func__,
                                util::ToString<VkDescriptorType>(desc_binding.second.desc_type).c_str());
                            break;
                    }
                }
            }
        }
    }

    assert(original_command_buffer_info);
    assert(original_command_buffer_info->parent_id != format::kNullHandleId);
    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    for (const auto& img_info : image_descriptors)
    {
        const std::vector<std::string> filenames = GenerateImageDescriptorFilename(img_info);

        VkResult res = DumpImageToFile(img_info,
                                       device_info,
                                       device_table,
                                       instance_table,
                                       object_info_table,
                                       filenames,
                                       dump_resources_scale,
                                       image_file_format,
                                       dump_all_image_subresources);

        if (res != VK_SUCCESS)
        {
            return res;
        }
    }

    const PhysicalDeviceInfo* phys_dev_info = object_info_table.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table,
                                                *instance_table,
                                                *phys_dev_info->replay_device_info->memory_properties);

    for (const auto& buf : buffer_descriptors)
    {
        const BufferInfo*  buffer_info = buf.first;
        const VkDeviceSize offset      = buf.second.offset;
        const VkDeviceSize range       = buf.second.range;
        const VkDeviceSize size        = range == VK_WHOLE_SIZE ? buffer_info->size - offset : range;

        std::vector<uint8_t> data;
        VkResult             res = resource_util.ReadFromBufferResource(
            buffer_info->handle, size, offset, buffer_info->queue_family_index, data);

        if (res != VK_SUCCESS)
        {
            return res;
        }

        const std::string filename = GenerateBufferDescriptorFilename(buffer_info->capture_id);
        util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
    }

    return VK_SUCCESS;
}

std::string DrawCallsDumpingContext::GenerateIndexBufferFilename(uint64_t    bind_index_buffer_index,
                                                                 VkIndexType type) const
{
    std::stringstream filename;

    std::string index_type_name_whole = util::ToString<VkIndexType>(type);
    std::string index_type_name(index_type_name_whole.begin() + 13, index_type_name_whole.end());
    filename << "IndexBuffer_" << bind_index_buffer_index << index_type_name << ".bin";

    std::filesystem::path filedirname(dump_resource_path);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

std::string DrawCallsDumpingContext::GenerateVertexBufferFilename(uint64_t bind_vertex_buffer_index,
                                                                  uint32_t binding) const
{
    std::stringstream filename;

    filename << "VertexBuffers_" << bind_vertex_buffer_index << "_binding_" << binding << ".bin";

    std::filesystem::path filedirname(dump_resource_path);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

VkResult DrawCallsDumpingContext::FetchDrawIndirectParams()
{
    assert(original_command_buffer_info);
    assert(original_command_buffer_info->parent_id != format::kNullHandleId);
    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    const PhysicalDeviceInfo* phys_dev_info = object_info_table.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table,
                                                *instance_table,
                                                *phys_dev_info->replay_device_info->memory_properties);

    for (auto& dc_param_entry : draw_call_params)
    {
        DrawCallParameters& dc_params = dc_param_entry.second;

        if (!IsDrawCallIndirect(dc_params.type))
        {
            continue;
        }

        if (IsDrawCallIndirectCount(dc_params.type))
        {
            DrawCallParameters::DrawCallParamsUnion::DrawIndirectCountParams& ic_params =
                dc_params.dc_params_union.draw_indirect_count;

            if (!ic_params.max_draw_count)
            {
                continue;
            }

            // Fetch draw count buffer
            std::vector<uint8_t> data;
            VkResult             res = resource_util.ReadFromBufferResource(
                ic_params.new_count_buffer, sizeof(uint32_t), 0, ic_params.count_buffer_info->queue_family_index, data);
            if (res != VK_SUCCESS)
            {
                return res;
            }

            assert(data.size() == sizeof(uint32_t));
            assert(ic_params.actual_draw_count == std::numeric_limits<uint32_t>::max());
            util::platform::MemoryCopy(&ic_params.actual_draw_count, sizeof(uint32_t), data.data(), data.size());
            assert(ic_params.actual_draw_count != std::numeric_limits<uint32_t>::max());

            if (!ic_params.actual_draw_count)
            {
                continue;
            }

            const uint32_t actual_draw_count = ic_params.actual_draw_count;

            VkDeviceSize params_actual_size;
            if (IsDrawCallIndexed(dc_params.type))
            {
                assert(ic_params.draw_indexed_params == nullptr);
                ic_params.draw_indexed_params =
                    new DrawCallParameters::DrawCallParamsUnion::DrawIndexedParams[actual_draw_count];
                if (ic_params.draw_indexed_params == nullptr)
                {
                    return VK_ERROR_OUT_OF_HOST_MEMORY;
                }

                // Now we know the exact draw count. We can fetch the exact draw params instead of the whole buffer
                params_actual_size =
                    sizeof(DrawCallParameters::DrawCallParamsUnion::DrawIndexedParams) * actual_draw_count;
            }
            else
            {
                assert(ic_params.draw_params == nullptr);
                ic_params.draw_params = new DrawCallParameters::DrawCallParamsUnion::DrawParams[actual_draw_count];
                if (ic_params.draw_params == nullptr)
                {
                    return VK_ERROR_OUT_OF_HOST_MEMORY;
                }

                // Now we know the exact draw count. We can fetch the exact draw params instead of the whole buffer
                params_actual_size = sizeof(DrawCallParameters::DrawCallParamsUnion::DrawParams) * actual_draw_count;
            }

            // Fetch param buffers
            res = resource_util.ReadFromBufferResource(ic_params.new_params_buffer,
                                                       params_actual_size,
                                                       0,
                                                       ic_params.params_buffer_info->queue_family_index,
                                                       data);
            if (res != VK_SUCCESS)
            {
                return res;
            }

            assert(data.size() == params_actual_size);
            if (IsDrawCallIndexed(dc_params.type))
            {
                util::platform::MemoryCopy(
                    ic_params.draw_indexed_params, params_actual_size, data.data(), params_actual_size);
            }
            else
            {
                util::platform::MemoryCopy(ic_params.draw_params, params_actual_size, data.data(), params_actual_size);
            }
        }
        else
        {
            DrawCallParameters::DrawCallParamsUnion::DrawIndirectParams& i_params =
                dc_params.dc_params_union.draw_indirect;

            if (!i_params.draw_count)
            {
                continue;
            }

            if (IsDrawCallIndexed(dc_params.type))
            {
                assert(i_params.draw_indexed_params == nullptr);
                i_params.draw_indexed_params =
                    new DrawCallParameters::DrawCallParamsUnion::DrawIndexedParams[i_params.draw_count];
                if (i_params.draw_indexed_params == nullptr)
                {
                    return VK_ERROR_OUT_OF_HOST_MEMORY;
                }
            }
            else
            {
                assert(i_params.draw_params == nullptr);
                i_params.draw_params = new DrawCallParameters::DrawCallParamsUnion::DrawParams[i_params.draw_count];
                if (i_params.draw_params == nullptr)
                {
                    return VK_ERROR_OUT_OF_HOST_MEMORY;
                }
            }

            std::vector<uint8_t> params_data;
            VkResult             res = resource_util.ReadFromBufferResource(i_params.new_params_buffer,
                                                                i_params.new_params_buffer_size,
                                                                0,
                                                                i_params.params_buffer_info->queue_family_index,
                                                                params_data);
            if (res != VK_SUCCESS)
            {
                return res;
            }

            assert(params_data.size() == i_params.new_params_buffer_size);

            if (IsDrawCallIndexed(dc_params.type))
            {
                util::platform::MemoryCopy(i_params.draw_indexed_params,
                                           i_params.new_params_buffer_size,
                                           params_data.data(),
                                           params_data.size());
            }
            else if (dc_params.type == DrawCallTypes::kDrawIndexedIndirect)
            {
                util::platform::MemoryCopy(
                    i_params.draw_params, i_params.new_params_buffer_size, params_data.data(), params_data.size());
            }
        }
    }

    return VK_SUCCESS;
}

VkResult DrawCallsDumpingContext::DumpVertexIndexBuffers()
{
    assert(draw_call_params.size() == dc_indices.size());

    // Fetch draw params for all Indirect and IndirectCount draw calls from the buffers
    // into the DrawCallParameters
    VkResult res = FetchDrawIndirectParams();
    if (res != VK_SUCCESS)
    {
        return res;
    }

    assert(original_command_buffer_info);
    assert(original_command_buffer_info->parent_id != format::kNullHandleId);
    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    const PhysicalDeviceInfo* phys_dev_info = object_info_table.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table,
                                                *instance_table,
                                                *phys_dev_info->replay_device_info->memory_properties);

    // Dump index buffers first. In the process parse the index buffers and note the greatest
    // index used in each buffer. This will help determine the vertex buffer sizes used in
    // indexed draw calls
    std::unordered_map<uint64_t, uint32_t> max_vertex_index_per_index_buffer;
    for (const auto& idx_buf : bound_index_buffers)
    {
        const uint64_t bind_index_buffer_block_index = idx_buf.first;

        if (idx_buf.second.referencing_draw_calls.empty())
        {
            continue;
        }

        // Buffer can be null
        if (idx_buf.second.buffer_info == nullptr)
        {
            continue;
        }

        // In order to deduce the index buffer's size find the greatest index count
        // used by all draw calls that reference this index buffer
        uint32_t max_abs_count   = 0;
        uint32_t max_index_count = 0;

        // Store all (indexCount, firstIndex) pairs used by all associated with this index buffer.
        // Latter we will parse the index buffer using all these pairs in order to detect the
        // greatest index.
        std::vector<std::pair<uint32_t, uint32_t>> index_count_first_index_pairs(
            idx_buf.second.referencing_draw_calls.size());
        uint32_t pair = 0;

        for (const auto ref_dc_index : idx_buf.second.referencing_draw_calls)
        {
            const auto& dc_params_entry = draw_call_params.find(ref_dc_index);
            assert(dc_params_entry != draw_call_params.end());

            const DrawCallParameters& dc_params = dc_params_entry->second;
            assert(IsDrawCallIndexed(dc_params.type));
            assert(dc_params.referenced_bind_index_buffer != DrawCallParameters::INVALID_BLOCK_INDEX);

            if (IsDrawCallIndirect(dc_params.type))
            {
                if (IsDrawCallIndirectCount(dc_params.type))
                {
                    const DrawCallParameters::DrawCallParamsUnion::DrawIndirectCountParams& ic_params =
                        dc_params.dc_params_union.draw_indirect_count;

                    if (!ic_params.max_draw_count)
                    {
                        continue;
                    }

                    assert(ic_params.draw_indexed_params != nullptr);
                    for (uint32_t d = 0; d < ic_params.max_draw_count; ++d)
                    {
                        const uint32_t index_count = ic_params.draw_indexed_params[d].index_count;
                        const uint32_t first_index = ic_params.draw_indexed_params[d].first_index;

                        index_count_first_index_pairs[pair++] = std::make_pair(index_count, first_index);

                        if (max_index_count < index_count)
                        {
                            max_index_count = index_count;
                        }

                        if (max_abs_count < index_count + first_index)
                        {
                            max_abs_count = index_count + first_index;
                        }
                    }
                }
                else
                {
                    const DrawCallParameters::DrawCallParamsUnion::DrawIndirectParams& i_params =
                        dc_params.dc_params_union.draw_indirect;

                    if (!i_params.draw_count)
                    {
                        continue;
                    }

                    assert(i_params.draw_indexed_params != nullptr);
                    for (uint32_t d = 0; d < i_params.draw_count; ++d)
                    {
                        const uint32_t index_count = i_params.draw_indexed_params[d].index_count;
                        const uint32_t first_index = i_params.draw_indexed_params[d].first_index;

                        index_count_first_index_pairs[pair++] = std::make_pair(index_count, first_index);

                        if (max_index_count < index_count)
                        {
                            max_index_count = index_count;
                        }

                        if (max_abs_count < index_count + first_index)
                        {
                            max_abs_count = index_count + first_index;
                        }
                    }
                }
            }
            else
            {
                const uint32_t index_count = dc_params.dc_params_union.draw_indexed.index_count;
                const uint32_t first_index = dc_params.dc_params_union.draw_indexed.first_index;

                index_count_first_index_pairs[pair++] = std::make_pair(index_count, first_index);

                if (max_index_count < index_count)
                {
                    max_index_count = index_count;
                }

                if (max_abs_count < index_count + first_index)
                {
                    max_abs_count = index_count + first_index;
                }
            }
        }

        if (!max_index_count)
        {
            continue;
        }

        const VkIndexType index_type = idx_buf.second.index_type;
        const uint32_t    index_size = VkIndexTypeToBytes(index_type);
        const uint32_t    offset     = idx_buf.second.offset;

        // Check if the exact size has been provided by vkCmdBindIndexBuffer2
        uint32_t total_size = (idx_buf.second.size != 0) ? (idx_buf.second.size) : (max_abs_count * index_size);

        assert(total_size <= idx_buf.second.buffer_info->size - offset);
        // There is something wrong with the calculations if this is true
        if (total_size > idx_buf.second.buffer_info->size - offset)
        {
            total_size = idx_buf.second.buffer_info->size - offset;
        }

        std::vector<uint8_t> index_data;
        res = resource_util.ReadFromBufferResource(idx_buf.second.buffer_info->handle,
                                                   total_size,
                                                   offset,
                                                   idx_buf.second.buffer_info->queue_family_index,
                                                   index_data);
        if (res != VK_SUCCESS)
        {
            return res;
        }

        std::string filename = GenerateIndexBufferFilename(bind_index_buffer_block_index, index_type);
        util::bufferwriter::WriteBuffer(filename, index_data.data(), index_data.size());

        // Parse indices and find the greatest vertex index. We should need this later
        // when we calculate the size of the vertex buffers
        uint32_t greatest_vertex_index = 0;
        for (const auto& pairs : index_count_first_index_pairs)
        {
            const uint32_t gvi = FindGreatestVertexIndex(index_data, pairs.first, pairs.second, index_type);
            if (greatest_vertex_index < gvi)
            {
                greatest_vertex_index = gvi;
            }
        }
        max_vertex_index_per_index_buffer.emplace(bind_index_buffer_block_index, greatest_vertex_index);
    }

    // Dump vertex buffer
    for (const auto& vbs : bound_vertex_buffers)
    {
        const uint64_t bind_vertex_buffers_index = vbs.first;

        if (vbs.second.referencing_draw_calls.empty())
        {
            continue;
        }

        // In order to deduce the vertex buffer's size find the greatest vertex count
        // used by all draw calls that reference this vertex buffer
        uint32_t max_vertex_count = 0;
        uint32_t max_first_vertex = 0;
        for (const auto ref_dc_index : vbs.second.referencing_draw_calls)
        {
            const auto& dc_params_entry = draw_call_params.find(ref_dc_index);
            assert(dc_params_entry != draw_call_params.end());

            const DrawCallParameters& dc_params = dc_params_entry->second;
            assert(dc_params.referenced_bind_vertex_buffers != DrawCallParameters::INVALID_BLOCK_INDEX);

            if (IsDrawCallIndexed(dc_params.type))
            {
                // For indexed draw calls the greatest vertex index will be used as the max vertex count
                assert(dc_params.referenced_bind_index_buffer != DrawCallParameters::INVALID_BLOCK_INDEX);
                const auto max_vertex_index_entry =
                    max_vertex_index_per_index_buffer.find(dc_params.referenced_bind_index_buffer);
                assert(max_vertex_index_entry != max_vertex_index_per_index_buffer.end());

                if (max_vertex_count < max_vertex_index_entry->second)
                {
                    max_vertex_count = max_vertex_index_entry->second;
                }
            }
            else
            {
                if (IsDrawCallIndirect(dc_params.type))
                {
                    if (IsDrawCallIndirectCount(dc_params.type))
                    {
                        const DrawCallParameters::DrawCallParamsUnion::DrawIndirectCountParams& ic_params =
                            dc_params.dc_params_union.draw_indirect_count;

                        if (!ic_params.max_draw_count)
                        {
                            continue;
                        }

                        assert(ic_params.draw_params != nullptr);
                        for (uint32_t d = 0; d < ic_params.max_draw_count; ++d)
                        {
                            if (max_vertex_count < ic_params.draw_params[d].vertex_count)
                            {
                                max_vertex_count = ic_params.draw_params[d].vertex_count;
                            }

                            if (max_first_vertex < ic_params.draw_params[d].first_vertex)
                            {
                                max_first_vertex = ic_params.draw_params[d].first_vertex;
                            }
                        }
                    }
                    else
                    {
                        const DrawCallParameters::DrawCallParamsUnion::DrawIndirectParams& i_params =
                            dc_params.dc_params_union.draw_indirect;

                        if (!i_params.draw_count)
                        {
                            continue;
                        }

                        assert(i_params.draw_params != nullptr);
                        for (uint32_t d = 0; d < i_params.draw_count; ++d)
                        {
                            if (max_vertex_count < i_params.draw_params[d].vertex_count)
                            {
                                max_vertex_count = i_params.draw_params[d].vertex_count;
                            }

                            if (max_first_vertex < i_params.draw_params[d].first_vertex)
                            {
                                max_first_vertex = i_params.draw_params[d].first_vertex;
                            }
                        }
                    }
                }
                else
                {
                    if (max_vertex_count < dc_params.dc_params_union.draw.vertex_count)
                    {
                        max_vertex_count = dc_params.dc_params_union.draw.vertex_count;
                    }

                    if (max_first_vertex < dc_params.dc_params_union.draw.first_vertex)
                    {
                        max_first_vertex = dc_params.dc_params_union.draw.first_vertex;
                    }
                }
            }
        }

        if (!max_vertex_count)
        {
            continue;
        }

        for (const auto& vb_binding : vbs.second.bound_vertex_buffer_per_binding)
        {
            const uint32_t binding = vb_binding.first;

            const auto& vb_binding_entry = vbs.second.vertex_input_state.input_binding_map.find(binding);
            assert(vb_binding_entry != vbs.second.vertex_input_state.input_binding_map.end());
            if (vb_binding_entry == vbs.second.vertex_input_state.input_binding_map.end())
            {
                continue;
            }

            // Ignore instance data for now
            if (vb_binding_entry->second.inputRate == VK_VERTEX_INPUT_RATE_INSTANCE)
            {
                continue;
            }

            // Buffers can be NULL
            if (vb_binding.second.buffer_info == nullptr)
            {
                continue;
            }

            const uint32_t offset = vb_binding.second.offset;
            uint32_t       total_size;
            if (vb_binding.second.size)
            {
                // Exact size was provided by vkCmdBindVertexBuffers2
                total_size = vb_binding.second.size;
            }
            else
            {
                const uint32_t binding_stride = vb_binding_entry->second.stride;
                if (binding_stride)
                {
                    total_size = (max_vertex_count + max_first_vertex) * binding_stride;
                }
                else
                {
                    // According to the spec providing a VkVertexInputBindingDescription.stride equal to zero is valid.
                    // In these cases we will assume that information for only 1 vertex will be consumed (since we can't
                    // tell where the next one is located). So calculate the total size of all attributes that are using
                    // that binding and use that as the size of the vertex information for 1 vertex.
                    total_size          = 0;
                    uint32_t min_offset = std::numeric_limits<uint32_t>::max();
                    for (const auto& ppl_attr : vbs.second.vertex_input_state.input_attribute_map)
                    {
                        if (ppl_attr.second.binding != binding)
                        {
                            continue;
                        }

                        total_size += vkuFormatElementSize(ppl_attr.second.format);

                        if (min_offset > ppl_attr.second.offset)
                        {
                            min_offset = ppl_attr.second.offset;
                        }
                    }

                    if (!total_size)
                    {
                        continue;
                    }

                    total_size += min_offset;
                }
            }

            assert(total_size <= vb_binding.second.buffer_info->size - offset);
            // There is something wrong with the calculations if this is true
            if (total_size > vb_binding.second.buffer_info->size - offset)
            {
                total_size = vb_binding.second.buffer_info->size - offset;
            }

            std::vector<uint8_t> vb_data;
            res = resource_util.ReadFromBufferResource(vb_binding.second.buffer_info->handle,
                                                       total_size,
                                                       offset,
                                                       vb_binding.second.buffer_info->queue_family_index,
                                                       vb_data);

            std::string filename = GenerateVertexBufferFilename(bind_vertex_buffers_index, binding);
            util::bufferwriter::WriteBuffer(filename, vb_data.data(), vb_data.size());
        }
    }

    return VK_SUCCESS;
}

VkResult DrawCallsDumpingContext::CloneCommandBuffer(CommandBufferInfo*           orig_cmd_buf_info,
                                                     const encode::DeviceTable*   dev_table,
                                                     const encode::InstanceTable* inst_table)
{
    assert(orig_cmd_buf_info);
    assert(dev_table);
    assert(inst_table);

    const CommandPoolInfo* cb_pool_info = object_info_table.GetCommandPoolInfo(orig_cmd_buf_info->pool_id);

    const VkCommandBufferAllocateInfo ai{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                                          nullptr,
                                          cb_pool_info->handle,
                                          VK_COMMAND_BUFFER_LEVEL_PRIMARY,
                                          1 };

    const DeviceInfo* dev_info = object_info_table.GetDeviceInfo(orig_cmd_buf_info->parent_id);

    for (size_t i = 0; i < command_buffers.size(); ++i)
    {
        assert(command_buffers[i] == VK_NULL_HANDLE);
        VkResult res = dev_table->AllocateCommandBuffers(dev_info->handle, &ai, &command_buffers[i]);

        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("AllocateCommandBuffers failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }

        const VkCommandBufferBeginInfo bi{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
        dev_table->BeginCommandBuffer(command_buffers[i], &bi);
    }

    assert(original_command_buffer_info == nullptr);
    original_command_buffer_info = orig_cmd_buf_info;

    assert(device_table == nullptr);
    device_table = dev_table;
    assert(instance_table == nullptr);
    instance_table = inst_table;

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info->parent_id != format::kNullHandleId);
    const PhysicalDeviceInfo* phys_dev_info = object_info_table.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    assert(phys_dev_info->replay_device_info);
    assert(phys_dev_info->replay_device_info->memory_properties.get());
    replay_device_phys_mem_props = phys_dev_info->replay_device_info->memory_properties.get();

    // Allocate auxiliary command buffer
    VkResult res = device_table->AllocateCommandBuffers(dev_info->handle, &ai, &aux_command_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateCommandBuffers failed with %s", util::ToString<VkResult>(res).c_str());
        assert(0);
        return res;
    }

    const VkFenceCreateInfo ci = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
    res                        = device_table->CreateFence(dev_info->handle, &ci, nullptr, &aux_fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("CreateFence failed with %s", util::ToString<VkResult>(res).c_str());
        assert(0);
        return res;
    }

    return VK_SUCCESS;
}

void DrawCallsDumpingContext::BindDescriptorSets(VkPipelineBindPoint                          pipeline_bind_point,
                                                 uint32_t                                     first_set,
                                                 const std::vector<const DescriptorSetInfo*>& descriptor_sets_infos,
                                                 uint32_t                                     dynamicOffsetCount,
                                                 const uint32_t*                              pDynamicOffsets)
{
    uint32_t dynamic_offset_index = 0;
    for (size_t i = 0; i < descriptor_sets_infos.size(); ++i)
    {
        uint32_t set_index = first_set + i;

        if (pipeline_bind_point == VK_PIPELINE_BIND_POINT_GRAPHICS)
        {
            bound_descriptor_sets_gr[set_index] = *descriptor_sets_infos[i];

            if (dynamicOffsetCount && pDynamicOffsets != nullptr)
            {
                for (const auto& binding : descriptor_sets_infos[i]->descriptors)
                {
                    const uint32_t bindind_index = binding.first;

                    if (binding.second.desc_type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC ||
                        binding.second.desc_type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC)
                    {
                        for (size_t ai = 0;
                             ai < bound_descriptor_sets_gr[set_index].descriptors[bindind_index].buffer_info.size();
                             ++ai)
                        {
                            bound_descriptor_sets_gr[set_index].descriptors[bindind_index].buffer_info[ai].offset +=
                                pDynamicOffsets[dynamic_offset_index];
                            ++dynamic_offset_index;
                        }
                    }
                }
            }
        }
    }

    assert((dynamic_offset_index == dynamicOffsetCount && pDynamicOffsets != nullptr) || (!dynamic_offset_index));
}

VkResult DrawCallsDumpingContext::CloneRenderPass(const RenderPassInfo*  original_render_pass,
                                                  const FramebufferInfo* fb_info)
{
    std::vector<VkAttachmentDescription> modified_attachemnts = original_render_pass->attachment_descs;

    // Fix storeOps and final layouts
    for (auto& att : modified_attachemnts)
    {
        att.storeOp     = VK_ATTACHMENT_STORE_OP_STORE;
        att.finalLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;

        if (vkuFormatHasStencil(att.format))
        {
            att.stencilStoreOp = VK_ATTACHMENT_STORE_OP_STORE;
        }
    }

    // Inform the original command buffer about the new image layouts
    for (const auto& att_ref : original_render_pass->subpass_refs[0].color_att_refs)
    {
        const ImageViewInfo* att_img_view_info =
            object_info_table.GetImageViewInfo(fb_info->attachment_image_view_ids[att_ref.attachment]);
        assert(att_img_view_info != nullptr);

        original_command_buffer_info->image_layout_barriers[att_img_view_info->image_id] = att_ref.layout;

        ImageInfo* img_info = object_info_table.GetImageInfo(att_img_view_info->image_id);
        assert(img_info != nullptr);
        img_info->intermediate_layout = att_ref.layout;
    }

    // Create new render passes
    render_pass_clones.emplace_back(std::vector<VkRenderPass>());
    auto new_render_pass = render_pass_clones.end() - 1;
    new_render_pass->resize(original_render_pass->subpass_refs.size());

    // Do one quick pass over the subpass references in order to check if the render pass
    // uses color and/or depth attachments. This information might be necessary when
    // defining the dependencies of the custom render passes
    bool has_color = false, has_depth = false;
    for (uint32_t sub = 0; sub < original_render_pass->subpass_refs.size(); ++sub)
    {
        if (original_render_pass->subpass_refs[sub].color_att_refs.size())
        {
            has_color = true;
        }

        if (original_render_pass->subpass_refs[sub].has_depth)
        {
            has_depth = true;
        }
    }

    // Create new render passes. For each subpass in the original render pass a new render pass will be created.
    // Each new render pass will progressively contain an additional subpass until all subpasses of the original
    // renderpass are exhausted.
    // For example for a render pass with 3 subpasses, 3 new render passes will be created and will contain the
    // following subpasses:
    // Renderpass 0: Will contain 1 subpass.
    // Renderpass 1: Will contain 2 subpass.
    // Renderpass 2: Will contain 3 subpass.
    // Each draw call that is marked for dumping will be "assigned" the appropriate render pass depending on which
    // subpasses it was called from in the original render pass
    std::vector<VkSubpassDescription> subpass_descs;
    for (uint32_t sub = 0; sub < original_render_pass->subpass_refs.size(); ++sub)
    {
        bool                             has_external_dependencies_post = false;
        bool                             has_external_dependencies_pre  = false;
        std::vector<VkSubpassDependency> modified_dependencies;
        for (uint32_t d = 0; d < original_render_pass->dependencies.size(); ++d)
        {
            const VkSubpassDependency& original_dep = original_render_pass->dependencies[d];

            if ((original_dep.srcSubpass > sub || original_dep.dstSubpass > sub) &&
                (original_dep.srcSubpass != VK_SUBPASS_EXTERNAL && original_dep.dstSubpass != VK_SUBPASS_EXTERNAL))
            {
                // Skip this dependency as out of scope
                continue;
            }

            auto new_dep = modified_dependencies.insert(modified_dependencies.end(), original_dep);
            if (new_dep->srcSubpass != VK_SUBPASS_EXTERNAL && new_dep->srcSubpass > sub)
            {
                new_dep->srcSubpass = sub;
            }
            else if (new_dep->dstSubpass != VK_SUBPASS_EXTERNAL && new_dep->dstSubpass > sub)
            {
                new_dep->dstSubpass = sub;
            }

            if (new_dep->srcSubpass == VK_SUBPASS_EXTERNAL)
            {
                // new_dep->srcStageMask |= VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
                // new_dep->srcAccessMask |= VK_ACCESS_TRANSFER_READ_BIT;

                has_external_dependencies_pre = true;
            }

            if (new_dep->dstSubpass == VK_SUBPASS_EXTERNAL)
            {
                new_dep->dstStageMask  = VK_PIPELINE_STAGE_TRANSFER_BIT;
                new_dep->dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;

                has_external_dependencies_post = true;
            }
        }

        // No post renderpass dependecy was detected
        if (!has_external_dependencies_post)
        {
            VkSubpassDependency post_dependency;
            post_dependency.srcSubpass    = sub;
            post_dependency.dstSubpass    = VK_SUBPASS_EXTERNAL;
            post_dependency.dstStageMask  = VK_PIPELINE_STAGE_TRANSFER_BIT;
            post_dependency.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;

            // Injecting one for color
            if (has_color)
            {
                post_dependency.srcStageMask  = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
                post_dependency.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

                modified_dependencies.push_back(post_dependency);
            }

            // Injecting one for depth
            if (has_depth)
            {
                post_dependency.srcStageMask =
                    VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT | VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT;
                post_dependency.srcAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;

                modified_dependencies.push_back(post_dependency);
            }
        }

        const RenderPassInfo::SubpassReferences& original_subp_ref = original_render_pass->subpass_refs[sub];
        auto new_subp_desc = subpass_descs.insert(subpass_descs.end(), VkSubpassDescription());

        new_subp_desc->flags                = original_subp_ref.flags;
        new_subp_desc->pipelineBindPoint    = original_subp_ref.pipeline_bind_point;
        new_subp_desc->inputAttachmentCount = original_subp_ref.input_att_refs.size();
        new_subp_desc->pInputAttachments =
            original_subp_ref.input_att_refs.size() ? original_subp_ref.input_att_refs.data() : nullptr;
        new_subp_desc->colorAttachmentCount = original_subp_ref.color_att_refs.size();
        new_subp_desc->pColorAttachments =
            original_subp_ref.color_att_refs.size() ? original_subp_ref.color_att_refs.data() : nullptr;
        new_subp_desc->pResolveAttachments =
            original_subp_ref.resolve_att_refs.size() ? original_subp_ref.resolve_att_refs.data() : nullptr;
        new_subp_desc->pDepthStencilAttachment =
            original_subp_ref.has_depth ? &original_subp_ref.depth_att_ref : nullptr;
        new_subp_desc->preserveAttachmentCount = original_subp_ref.preserve_att_refs.size();
        new_subp_desc->pPreserveAttachments =
            original_subp_ref.preserve_att_refs.size() ? original_subp_ref.preserve_att_refs.data() : nullptr;

        VkRenderPassCreateInfo ci;
        ci.sType           = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
        ci.pNext           = nullptr;
        ci.flags           = VkRenderPassCreateFlags(0);
        ci.attachmentCount = modified_attachemnts.size();
        ci.pAttachments    = modified_attachemnts.size() ? modified_attachemnts.data() : nullptr;

        assert(subpass_descs.size() == sub + 1);
        ci.subpassCount = sub + 1;
        ci.pSubpasses   = subpass_descs.data();

        ci.dependencyCount = modified_dependencies.size();
        ci.pDependencies   = modified_dependencies.size() ? modified_dependencies.data() : nullptr;

        const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
        VkDevice          device      = device_info->handle;

        VkResult res = device_table->CreateRenderPass(device, &ci, nullptr, &new_render_pass->at(sub));
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("CreateRenderPass failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }
    }

    return VK_SUCCESS;
}

VkResult DrawCallsDumpingContext::BeginRenderPass(const RenderPassInfo*  render_pass_info,
                                                  uint32_t               clear_value_count,
                                                  const VkClearValue*    p_clear_values,
                                                  const FramebufferInfo* framebuffer_info,
                                                  const VkRect2D&        render_area,
                                                  VkSubpassContents      contents)
{
    assert(render_pass_info);
    assert(framebuffer_info);

    std::vector<const ImageInfo*> color_att_imgs;

    inside_renderpass  = true;
    current_subpass    = 0;
    active_renderpass  = render_pass_info;
    active_framebuffer = framebuffer_info;

    // Parse color attachments
    uint32_t i = 0;
    for (const auto& att_ref : active_renderpass->subpass_refs[current_subpass].color_att_refs)
    {
        const uint32_t att_idx = att_ref.attachment;

        const ImageViewInfo* img_view_info =
            object_info_table.GetImageViewInfo(framebuffer_info->attachment_image_view_ids[att_idx]);
        assert(img_view_info);

        const ImageInfo* img_info = object_info_table.GetImageInfo(img_view_info->image_id);
        assert(img_info);

        color_att_imgs.push_back(img_info);
    }

    const ImageInfo* depth_img_info;

    if (active_renderpass->subpass_refs[current_subpass].has_depth)
    {
        const uint32_t       depth_att_idx = active_renderpass->subpass_refs[current_subpass].depth_att_ref.attachment;
        const ImageViewInfo* depth_img_view_info =
            object_info_table.GetImageViewInfo(framebuffer_info->attachment_image_view_ids[depth_att_idx]);
        assert(depth_img_view_info);

        depth_img_info = object_info_table.GetImageInfo(depth_img_view_info->image_id);
        assert(depth_img_info);
    }
    else
    {
        depth_img_info = nullptr;
    }

    SetRenderTargets(std::move(color_att_imgs), depth_img_info, true);

    SetRenderArea(render_area);

    VkResult res = CloneRenderPass(render_pass_info, framebuffer_info);
    if (res != VK_SUCCESS)
    {
        return res;
    }

    // Add vkCmdBeginRenderPass into the cloned command buffers using the modified render pass
    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(first, last);

    VkRenderPassBeginInfo bi;
    bi.sType           = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    bi.pNext           = nullptr;
    bi.clearValueCount = clear_value_count;
    bi.pClearValues    = p_clear_values;
    bi.framebuffer     = framebuffer_info->handle;
    bi.renderArea      = render_area;

    size_t cmd_buf_idx = current_cb_index;
    for (CommandBufferIterator it = first; it < last; ++it, ++cmd_buf_idx)
    {
        const uint64_t dc_index = dc_indices[CmdBufToDCVectorIndex(cmd_buf_idx)];

        // GetRenderPassIndex will tell us which render pass each cloned command buffer should use depending on the
        // assigned draw call index
        const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
        const uint64_t              rp       = RP_index.first;
        const uint64_t              sp       = RP_index.second;

        if (dc_index < RP_indices[rp][0])
        {
            continue;
        }

        if (dc_index > RP_indices[rp][RP_indices[rp].size() - 1] || rp > current_renderpass)
        {
            // Command buffers / Draw calls outside this specific render pass should get
            // assigned the original render pass
            bi.renderPass = render_pass_info->handle;
        }
        else
        {
            // Command buffers / Draw calls inside this render pass should get the newly created / modified
            // render pass
            assert(rp < render_pass_clones.size());
            assert(sp < render_pass_clones[rp].size());
            bi.renderPass = render_pass_clones[rp][sp];
        }

        device_table->CmdBeginRenderPass(*it, &bi, contents);
    }

    return VK_SUCCESS;
}

void DrawCallsDumpingContext::NextSubpass(VkSubpassContents contents)
{
    assert(active_renderpass);
    assert(active_framebuffer);

    std::vector<const ImageInfo*>    color_att_imgs;
    std::vector<VkAttachmentStoreOp> color_att_storeOps;
    std::vector<VkImageLayout>       color_att_final_layouts;

    ++current_subpass;

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(first, last);
    size_t cmd_buf_idx = current_cb_index;
    for (CommandBufferIterator it = first; it < last; ++it, ++cmd_buf_idx)
    {
        const uint64_t              dc_index = dc_indices[CmdBufToDCVectorIndex(cmd_buf_idx)];
        const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
        const uint64_t              rp       = RP_index.first;

        device_table->CmdNextSubpass(*it, contents);
    }

    assert(current_subpass < active_renderpass->subpass_refs.size());

    // Parse color attachments
    for (const auto& att_ref : active_renderpass->subpass_refs[current_subpass].color_att_refs)
    {
        const uint32_t att_idx = att_ref.attachment;
        assert(att_idx < active_framebuffer->attachment_image_view_ids.size());

        const ImageViewInfo* img_view_info =
            object_info_table.GetImageViewInfo(active_framebuffer->attachment_image_view_ids[att_idx]);
        assert(img_view_info);

        const ImageInfo* img_info = object_info_table.GetImageInfo(img_view_info->image_id);
        assert(img_info);

        color_att_imgs.push_back(img_info);
        color_att_storeOps.push_back(active_renderpass->attachment_descs[att_idx].storeOp);
        color_att_final_layouts.push_back(active_renderpass->attachment_descs[att_idx].finalLayout);
    }

    const ImageInfo*    depth_img_info;
    VkAttachmentStoreOp depth_att_storeOp;
    VkImageLayout       depth_final_layout;

    if (active_renderpass->subpass_refs[current_subpass].has_depth)
    {
        const uint32_t depth_att_idx = active_renderpass->subpass_refs[current_subpass].depth_att_ref.attachment;
        assert(depth_att_idx < active_framebuffer->attachment_image_view_ids.size());

        const ImageViewInfo* depth_img_view_info =
            object_info_table.GetImageViewInfo(active_framebuffer->attachment_image_view_ids[depth_att_idx]);
        assert(depth_img_view_info);

        depth_img_info = object_info_table.GetImageInfo(depth_img_view_info->image_id);
        assert(depth_img_info);
        depth_att_storeOp  = active_renderpass->attachment_descs[depth_att_idx].storeOp;
        depth_final_layout = active_renderpass->attachment_descs[depth_att_idx].finalLayout;
    }
    else
    {
        depth_img_info    = nullptr;
        depth_att_storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    }

    SetRenderTargets(std::move(color_att_imgs), depth_img_info, false);

    // Inform the original command buffer about the new image layouts
    for (const auto& att_ref : active_renderpass->subpass_refs[current_subpass].color_att_refs)
    {
        const ImageViewInfo* att_img_view_info =
            object_info_table.GetImageViewInfo(active_framebuffer->attachment_image_view_ids[att_ref.attachment]);
        assert(att_img_view_info != nullptr);

        original_command_buffer_info->image_layout_barriers[att_img_view_info->image_id] = att_ref.layout;

        ImageInfo* img_info = object_info_table.GetImageInfo(att_img_view_info->image_id);
        assert(img_info != nullptr);
        img_info->intermediate_layout = att_ref.layout;
    }
}

void DrawCallsDumpingContext::BindPipeline(VkPipelineBindPoint pipeline_bind_point, const PipelineInfo* pipeline)
{
    PipelineBindPoints bind_point = VkPipelineBindPointToPipelineBindPoint(pipeline_bind_point);

    bound_pipelines[bind_point] = pipeline;
}

void DrawCallsDumpingContext::EndRenderPass()
{
    assert(inside_renderpass);

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(first, last);
    size_t cmd_buf_idx = current_cb_index;
    for (CommandBufferIterator it = first; it < last; ++it, ++cmd_buf_idx)
    {
        const uint64_t              dc_index = dc_indices[CmdBufToDCVectorIndex(cmd_buf_idx)];
        const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
        const uint64_t              rp       = RP_index.first;
        const uint64_t              sp       = RP_index.second;

        if (dc_index < RP_indices[rp][0])
        {
            continue;
        }

        device_table->CmdEndRenderPass(*it);
    }

    ++current_renderpass;

    inside_renderpass = false;
}

void DrawCallsDumpingContext::BindVertexBuffers(uint64_t                              index,
                                                uint32_t                              firstBinding,
                                                const std::vector<const BufferInfo*>& buffer_infos,
                                                const VkDeviceSize*                   pOffsets)
{
    if (!buffer_infos.size())
    {
        return;
    }

    auto new_entry =
        bound_vertex_buffers.emplace(std::piecewise_construct, std::forward_as_tuple(index), std::forward_as_tuple());
    assert(new_entry.second);
    currently_bound_vertex_buffers = new_entry.first;

    for (size_t i = 0; i < buffer_infos.size(); ++i)
    {
        const uint32_t binding = static_cast<uint32_t>(firstBinding + i);
        currently_bound_vertex_buffers->second.bound_vertex_buffer_per_binding.emplace(
            std::piecewise_construct,
            std::forward_as_tuple(binding),
            std::forward_as_tuple(buffer_infos[i], pOffsets[i]));
    }
}

void DrawCallsDumpingContext::BindVertexBuffers2(uint64_t                              index,
                                                 uint32_t                              first_binding,
                                                 const std::vector<const BufferInfo*>& buffer_infos,
                                                 const VkDeviceSize*                   offsets,
                                                 const VkDeviceSize*                   sizes,
                                                 const VkDeviceSize*                   strides)
{
    if (!buffer_infos.size())
    {
        return;
    }

    auto new_entry =
        bound_vertex_buffers.emplace(std::piecewise_construct, std::forward_as_tuple(index), std::forward_as_tuple());
    assert(new_entry.second);
    currently_bound_vertex_buffers = new_entry.first;

    for (size_t i = 0; i < buffer_infos.size(); ++i)
    {
        VkDeviceSize buffer_size = 0;
        if (sizes[i] && buffer_infos[i] != nullptr)
        {
            if (sizes[i] == VK_WHOLE_SIZE)
            {
                assert(buffer_infos[i]->size > offsets[i]);
                buffer_size = buffer_infos[i]->size - offsets[i];
            }
            else
            {
                buffer_size = sizes[i];
            }
        }

        const uint32_t binding = static_cast<uint32_t>(first_binding + i);
        currently_bound_vertex_buffers->second.bound_vertex_buffer_per_binding.emplace(
            std::piecewise_construct,
            std::forward_as_tuple(binding),
            std::forward_as_tuple(buffer_infos[i], offsets[i], buffer_size, strides[i]));
    }
}

void DrawCallsDumpingContext::SetVertexInput(uint32_t                                   vertexBindingDescriptionCount,
                                             const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                             uint32_t                                   vertexAttributeDescriptionCount,
                                             const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions)
{
    for (uint32_t i = 0; i < vertexBindingDescriptionCount; ++i)
    {
        dynamic_vertex_input_state.input_binding_map[pVertexBindingDescriptions[i].binding].inputRate =
            pVertexBindingDescriptions[i].inputRate;
        dynamic_vertex_input_state.input_binding_map[pVertexBindingDescriptions[i].binding].stride =
            pVertexBindingDescriptions[i].stride;
    }

    for (uint32_t i = 0; i < vertexAttributeDescriptionCount; ++i)
    {
        dynamic_vertex_input_state.input_attribute_map[pVertexAttributeDescriptions[i].location].binding =
            pVertexAttributeDescriptions[i].binding;
        dynamic_vertex_input_state.input_attribute_map[pVertexAttributeDescriptions[i].location].format =
            pVertexAttributeDescriptions[i].format;
        dynamic_vertex_input_state.input_attribute_map[pVertexAttributeDescriptions[i].location].offset =
            pVertexAttributeDescriptions[i].offset;
    }
}

void DrawCallsDumpingContext::BindIndexBuffer(
    uint64_t index, const BufferInfo* buffer_info, VkDeviceSize offset, VkIndexType index_type, VkDeviceSize size)
{
    VkDeviceSize index_buffer_size = 0;
    if (size)
    {
        if (size == VK_WHOLE_SIZE && buffer_info != nullptr)
        {
            assert(buffer_info->size > offset);
            index_buffer_size = buffer_info->size - offset;
        }
        else
        {
            index_buffer_size = size;
        }
    }

    auto new_entry =
        bound_index_buffers.emplace(std::piecewise_construct,
                                    std::forward_as_tuple(index),
                                    std::forward_as_tuple(buffer_info, offset, index_type, index_buffer_size));
    assert(new_entry.second);
    currently_bound_index_buffer = new_entry.first;
}

void DrawCallsDumpingContext::SetRenderTargets(const std::vector<const ImageInfo*>& color_att_imgs,
                                               const ImageInfo*                     depth_att_img,
                                               bool                                 new_render_pass)
{
    if (new_render_pass)
    {
        render_targets.emplace_back(std::vector<RenderTargets>());
    }

    auto new_render_targets = render_targets.end() - 1;

    new_render_targets->emplace_back(RenderTargets());
    auto new_rts = new_render_targets->end() - 1;

    new_rts->color_att_imgs = color_att_imgs;
    new_rts->depth_att_img  = depth_att_img;
}

void DrawCallsDumpingContext::SetRenderArea(const VkRect2D& new_render_area)
{
    render_area.push_back(new_render_area);
}

void DrawCallsDumpingContext::ReleaseIndirectDrawParams()
{
    assert(original_command_buffer_info);
    assert(original_command_buffer_info->parent_id != format::kNullHandleId);
    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);

    if (device_info == nullptr)
    {
        return;
    }

    for (auto& dc_param_entry : draw_call_params)
    {
        DrawCallParameters& dc_params = dc_param_entry.second;
        if (IsDrawCallIndirect(dc_params.type))
        {
            if (IsDrawCallIndirectCount(dc_params.type))
            {
                DrawCallParameters::DrawCallParamsUnion::DrawIndirectCountParams& ic_params =
                    dc_params.dc_params_union.draw_indirect_count;

                if (ic_params.draw_params != nullptr)
                {
                    delete[] ic_params.draw_params;
                    ic_params.draw_params = nullptr;
                }

                if (ic_params.draw_indexed_params != nullptr)
                {
                    delete[] ic_params.draw_indexed_params;
                    ic_params.draw_indexed_params = nullptr;
                }

                if (ic_params.new_params_buffer != VK_NULL_HANDLE)
                {
                    device_table->DestroyBuffer(device_info->handle, ic_params.new_params_buffer, nullptr);
                    ic_params.new_params_buffer = VK_NULL_HANDLE;
                }

                if (ic_params.new_params_memory != VK_NULL_HANDLE)
                {
                    device_table->FreeMemory(device_info->handle, ic_params.new_params_memory, nullptr);
                    ic_params.new_params_memory = VK_NULL_HANDLE;
                }

                if (ic_params.new_count_buffer != VK_NULL_HANDLE)
                {
                    device_table->DestroyBuffer(device_info->handle, ic_params.new_count_buffer, nullptr);
                    ic_params.new_count_buffer = VK_NULL_HANDLE;
                }

                if (ic_params.new_count_memory != VK_NULL_HANDLE)
                {
                    device_table->FreeMemory(device_info->handle, ic_params.new_count_memory, nullptr);
                    ic_params.new_count_memory = VK_NULL_HANDLE;
                }
            }
            else
            {
                DrawCallParameters::DrawCallParamsUnion::DrawIndirectParams& i_params =
                    dc_params.dc_params_union.draw_indirect;

                if (i_params.draw_params != nullptr)
                {
                    delete[] i_params.draw_params;
                    i_params.draw_params = nullptr;
                }

                if (i_params.draw_indexed_params != nullptr)
                {
                    delete[] i_params.draw_indexed_params;
                    i_params.draw_indexed_params = nullptr;
                }

                if (i_params.new_params_buffer != VK_NULL_HANDLE)
                {
                    device_table->DestroyBuffer(device_info->handle, i_params.new_params_buffer, nullptr);
                    i_params.new_params_buffer = VK_NULL_HANDLE;
                }

                if (i_params.new_params_memory != VK_NULL_HANDLE)
                {
                    device_table->FreeMemory(device_info->handle, i_params.new_params_memory, nullptr);
                    i_params.new_params_memory = VK_NULL_HANDLE;
                }
            }
        }
    }
}

void DrawCallsDumpingContext::DestroyMutableResourceBackups()
{
    assert(original_command_buffer_info);

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    if (device_info == nullptr)
    {
        return;
    }

    VkDevice device = device_info->handle;

    for (size_t i = 0; i < mutable_resource_backups.images.size(); ++i)
    {
        device_table->DestroyImage(device, mutable_resource_backups.images[i], nullptr);
    }

    for (size_t i = 0; i < mutable_resource_backups.image_memories.size(); ++i)
    {
        device_table->FreeMemory(device, mutable_resource_backups.image_memories[i], nullptr);
    }

    mutable_resource_backups.images.clear();
    mutable_resource_backups.image_memories.clear();
    mutable_resource_backups.original_images.clear();

    for (size_t i = 0; i < mutable_resource_backups.buffers.size(); ++i)
    {
        device_table->DestroyBuffer(device, mutable_resource_backups.buffers[i], nullptr);
    }

    for (size_t i = 0; i < mutable_resource_backups.buffer_memories.size(); ++i)
    {
        device_table->FreeMemory(device, mutable_resource_backups.buffer_memories[i], nullptr);
    }

    mutable_resource_backups.buffers.clear();
    mutable_resource_backups.buffer_memories.clear();
    mutable_resource_backups.original_buffers.clear();
}

DrawCallsDumpingContext::RenderPassSubpassPair DrawCallsDumpingContext::GetRenderPassIndex(uint64_t dc_index) const
{
    assert(RP_indices.size());

    for (size_t rp = 0; rp < RP_indices.size(); ++rp)
    {
        const std::vector<uint64_t>& render_pass = RP_indices[rp];
        assert(render_pass.size());

        if (dc_index > render_pass[render_pass.size() - 1])
        {
            continue;
        }

        for (uint64_t sp = 0; sp < render_pass.size() - 1; ++sp)
        {
            if (dc_index > render_pass[sp] && dc_index < render_pass[sp + 1])
            {
                return RenderPassSubpassPair(rp, sp);
            }
        }
    }

    // If this is hit then probably there's something wrong with the draw call and/or render pass indices
    GFXRECON_LOG_ERROR(
        "It appears that there is an error with the provided Draw indices in combination with the render pass indices.")
    assert(0);

    return RenderPassSubpassPair(0, 0);
}

size_t DrawCallsDumpingContext::CmdBufToDCVectorIndex(size_t cmd_buf_index) const
{
    assert(cmd_buf_index < command_buffers.size());

    if (dump_resources_before)
    {
        assert(cmd_buf_index / 2 < dc_indices.size());

        return cmd_buf_index / 2;
    }
    else
    {
        assert(cmd_buf_index < dc_indices.size());

        return cmd_buf_index;
    }
}

uint32_t DrawCallsDumpingContext::GetDrawCallActiveCommandBuffers(CommandBufferIterator& first,
                                                                  CommandBufferIterator& last) const
{
    assert(current_cb_index <= command_buffers.size());

    first = command_buffers.begin() + current_cb_index;
    last  = command_buffers.end();

    return current_cb_index;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
