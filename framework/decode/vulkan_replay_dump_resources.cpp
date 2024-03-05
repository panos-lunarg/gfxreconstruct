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

#include "generated/generated_vulkan_struct_decoders.h"
#include "graphics/vulkan_resources_util.h"
#include "util/image_writer.h"
#include "util/buffer_writer.h"
#include "vulkan_replay_dump_resources.h"

#include "Vulkan-Utility-Libraries/vk_format_utils.h"
#include "util/logging.h"
#include "util/platform.h"

#include <sstream>
#if !defined(WIN32)
#include <dirent.h>
#endif

#define DELETE_STALE_DUMP_FILES

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
static bool IsInsideRange(const std::vector<T>& vec, T value)
{
    if (!vec.size())
    {
        return false;
    }
    else
    {
        return (value >= *(vec.begin()) && value <= *(vec.end() - 1));
    }
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

        case VK_FORMAT_R16G16B16A16_SFLOAT:
            return util::imagewriter::DataFormats::kFormat_R16G16B16A16_SFLOAT;

        case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
            return util::imagewriter::DataFormats::kFormat_B10G11R11_UFLOAT;

        case VK_FORMAT_B8G8R8A8_UNORM:
            return util::imagewriter::DataFormats::kFormat_BGRA;

        case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
            return util::imagewriter::DataFormats::kFormat_A2B10G10R10;

        case VK_FORMAT_D32_SFLOAT:
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            return util::imagewriter::DataFormats::kFormat_D32_FLOAT;

        case VK_FORMAT_X8_D24_UNORM_PACK32:
            return util::imagewriter::DataFormats::kFormat_D24_UNORM;

        case VK_FORMAT_D16_UNORM:
            return util::imagewriter::DataFormats::kFormat_D16_UNORM;

        default:
            GFXRECON_LOG_WARNING("%s() failed to handle format %s. Will dump as a plain binary file.",
                                 __func__,
                                 util::ToString<VkFormat>(format).c_str());
            return util::imagewriter::DataFormats::kFormat_UNSPECIFIED;
    }
}

static uint32_t GetMemoryTypeIndex(const VkPhysicalDeviceMemoryProperties& memory_properties,
                                   uint32_t                                type_bits,
                                   VkMemoryPropertyFlags                   property_flags)
{
    uint32_t memory_type_index = std::numeric_limits<uint32_t>::max();

    for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
    {
        if ((type_bits & (1 << i)) &&
            ((memory_properties.memoryTypes[i].propertyFlags & property_flags) == property_flags))
        {
            memory_type_index = i;
            break;
        }
    }

    return memory_type_index;
}

static VkResult CloneBuffer(const VulkanObjectInfoTable&            object_info_table,
                            const encode::DeviceTable*              device_table,
                            const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                            const BufferInfo*                       buffer_info,
                            VkBuffer*                               new_buffer,
                            VkDeviceMemory*                         new_buffer_memory,
                            VkDeviceSize                            override_size = 0)
{
    assert(device_table);
    assert(new_buffer);
    assert(buffer_info);
    assert(buffer_info->size || override_size);

    VkBufferCreateInfo ci;
    ci.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    ci.pNext                 = nullptr;
    ci.flags                 = VkBufferCreateFlags(0);
    ci.size                  = override_size ? override_size : buffer_info->size;
    ci.usage                 = buffer_info->usage | VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    ci.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    ci.queueFamilyIndexCount = buffer_info->queue_family_index;
    ci.pQueueFamilyIndices   = nullptr;

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(buffer_info->parent_id);
    VkDevice          device      = device_info->handle;

    VkResult res = device_table->CreateBuffer(device, &ci, nullptr, new_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("CreateBuffer failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    VkMemoryRequirements mem_reqs       = {};
    VkMemoryAllocateInfo mem_alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, nullptr };

    device_table->GetBufferMemoryRequirements(device, *new_buffer, &mem_reqs);
    mem_alloc_info.allocationSize = mem_reqs.size;

    assert(replay_device_phys_mem_props);
    uint32_t index =
        GetMemoryTypeIndex(*replay_device_phys_mem_props, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    if (index == std::numeric_limits<uint32_t>::max())
    {
        GFXRECON_LOG_ERROR("%s failed to find an appropriate memory type", __func__)
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    mem_alloc_info.memoryTypeIndex = index;

    assert(new_buffer_memory);
    res = device_table->AllocateMemory(device, &mem_alloc_info, nullptr, new_buffer_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateMemory failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->BindBufferMemory(device, *new_buffer, *new_buffer_memory, 0);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("BindBufferMemory failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

static uint32_t VkIndexTypeToBytes(VkIndexType type)
{
    switch (type)
    {
        case VK_INDEX_TYPE_UINT8_EXT:
            return 1;

        case VK_INDEX_TYPE_UINT16:
            return 2;

        case VK_INDEX_TYPE_UINT32:
            return 4;

        case VK_INDEX_TYPE_NONE_KHR:
        default:
            GFXRECON_LOG_ERROR("%s() Unrecognized/unhandled index type (%u)", __func__, static_cast<uint32_t>(type));
            assert(0);
            return 0;
    }
}

static uint32_t FindGreatestVertexIndex(const std::vector<uint8_t>& index_data, uint32_t index_count, VkIndexType type)
{
    switch (type)
    {
        case VK_INDEX_TYPE_UINT8_EXT:
        {
            uint8_t        restart_index = 0xff;
            const uint8_t* indices       = static_cast<const uint8_t*>(index_data.data());
            uint32_t       i             = 0;
            while (indices[i] == restart_index && i < index_count)
            {
                ++i;
            }

            if (i == index_count)
            {
                return 0;
            }

            uint8_t max = indices[i];

            for (; i < index_count; ++i)
            {
                if (indices[i] == restart_index)
                {
                    continue;
                }

                if (indices[i] > max)
                {
                    max = indices[i];
                }
            }

            return max;
        }
        break;

        case VK_INDEX_TYPE_UINT16:
        {
            uint16_t        restart_index = 0xff;
            const uint16_t* indices       = reinterpret_cast<const uint16_t*>(index_data.data());
            uint32_t        i             = 0;
            while (indices[i] == restart_index && i < index_count)
            {
                ++i;
            }

            if (i == index_count)
            {
                return 0;
            }

            uint16_t max = indices[i];

            for (; i < index_count; ++i)
            {
                if (indices[i] == restart_index)
                {
                    continue;
                }

                if (indices[i] > max)
                {
                    max = indices[i];
                }
            }

            return max;
        }
        break;

        case VK_INDEX_TYPE_UINT32:
        {
            uint32_t        restart_index = 0xff;
            const uint32_t* indices       = reinterpret_cast<const uint32_t*>(index_data.data());
            uint32_t        i             = 0;
            while (indices[i] == restart_index && i < index_count)
            {
                ++i;
            }

            if (i == index_count)
            {
                return 0;
            }

            uint32_t max = indices[i];

            for (; i < index_count; ++i)
            {
                if (indices[i] == restart_index)
                {
                    continue;
                }

                if (indices[i] > max)
                {
                    max = indices[i];
                }
            }

            return max;
        }
        break;

        case VK_INDEX_TYPE_NONE_KHR:
        default:
            GFXRECON_LOG_ERROR("%s() Unrecognized/unhandled index type (%u)", __func__, static_cast<uint32_t>(type));
            assert(0);
            return 0;
            break;
    }
}

VulkanReplayDumpResourcesBase::VulkanReplayDumpResourcesBase(const VulkanReplayOptions&   options,
                                                             const VulkanObjectInfoTable& object_info_table) :
    QueueSubmit_indices_(options.QueueSubmit_Indices),
    recording_(false), dump_resources_before_(options.dump_resources_before), object_info_table_(object_info_table)
{
    if (!options.Draw_Indices.size() && !options.Dispatch_Indices.size() && !options.TraceRays_Indices.size())
    {
        return;
    }

    dump_json_.VulkanReplayDumpResourcesJsonOpen(options.filename, options.dump_resources_output_dir);

    for (size_t i = 0; i < options.BeginCommandBuffer_Indices.size(); ++i)
    {
        const uint64_t bcb_index = options.BeginCommandBuffer_Indices[i];

        if (i < options.Draw_Indices.size() && options.Draw_Indices[i].size())
        {
            draw_call_contexts.emplace(bcb_index,
                                       DrawCallsDumpingContext(options.Draw_Indices[i].size() ? options.Draw_Indices[i]
                                                                                              : std::vector<uint64_t>(),
                                                               options.RenderPass_Indices[i].size()
                                                                   ? options.RenderPass_Indices[i]
                                                                   : std::vector<std::vector<uint64_t>>(),
                                                               object_info_table,
                                                               options.dump_resources_before,
                                                               options.dump_resources_output_dir,
                                                               options.dump_resources_image_format,
                                                               options.dump_resources_scale,
                                                               &dump_json_,
                                                               options.dump_resources_dump_vertex_index_buffer));
        }

        if ((i < options.Dispatch_Indices.size() && options.Dispatch_Indices[i].size()) ||
            (i < options.TraceRays_Indices.size() && options.TraceRays_Indices[i].size()))
        {
            dispatch_ray_contexts.emplace(bcb_index,
                                          DispatchTraceRaysDumpingContext(
                                              (options.Dispatch_Indices.size() && options.Dispatch_Indices[i].size())
                                                  ? options.Dispatch_Indices[i]
                                                  : std::vector<uint64_t>(),
                                              (options.TraceRays_Indices.size() && options.TraceRays_Indices[i].size())
                                                  ? options.TraceRays_Indices[i]
                                                  : std::vector<uint64_t>(),
                                              object_info_table_,
                                              options.dump_resources_before,
                                              options.dump_resources_output_dir,
                                              options.dump_resources_image_format,
                                              options.dump_resources_scale,
                                              &dump_json_));
        }
    }

#if defined(__ANDROID__) && defined(DELETE_STALE_DUMP_FILES)
    // On Android there is an issue with files which are manually deleted (for example from adb shell) then fopen with
    // "wb" might fail with the error that the file already exists. Deleting the file from code can workaround this
    DIR* dump_resource_dir = opendir(options.dump_resources_output_dir.c_str());
    if (dump_resource_dir != nullptr)
    {
        struct dirent* dir;
        while ((dir = readdir(dump_resource_dir)) != nullptr)
        {
            const int len = strlen(dir->d_name);
            if (len > 3)
            {
                const char* file_extension = &dir->d_name[len - 3];

                if (!strcmp(file_extension, "bmp") || !strcmp(file_extension, "png") || !strcmp(file_extension, "bin"))
                {
                    std::string full_path = options.dump_resources_output_dir + std::string(dir->d_name);
                    GFXRECON_LOG_INFO("Deleting file %s", full_path.c_str());
                    if (remove(full_path.c_str()))
                    {
                        GFXRECON_LOG_ERROR(" Failed to delete file %s (%s)", dir->d_name, strerror(errno));
                    }
                }
            }
        }
    }
#endif
}

VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer)
{
    auto begin_entry = cmd_buf_begin_map_.find(original_command_buffer);
    if (begin_entry == cmd_buf_begin_map_.end())
    {
        return nullptr;
    }

    auto context_entry = draw_call_contexts.find(begin_entry->second);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    DrawCallsDumpingContext* context = &context_entry->second;
    return context;
}

const VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer) const
{
    auto begin_entry = cmd_buf_begin_map_.find(original_command_buffer);
    if (begin_entry == cmd_buf_begin_map_.end())
    {
        return nullptr;
    }

    const auto context_entry = draw_call_contexts.find(begin_entry->second);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    const DrawCallsDumpingContext* context = &context_entry->second;
    return context;
}

VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(uint64_t bcb_id)
{
    auto context_entry = draw_call_contexts.find(bcb_id);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    DrawCallsDumpingContext* context = &context_entry->second;
    return context;
}

const VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(uint64_t bcb_id) const
{
    const auto context_entry = draw_call_contexts.find(bcb_id);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    const DrawCallsDumpingContext* context = &context_entry->second;
    return context;
}

VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(uint64_t bcb_id)
{
    auto context_entry = dispatch_ray_contexts.find(bcb_id);
    if (context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    DispatchTraceRaysDumpingContext* context = &context_entry->second;
    return context;
}

const VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(uint64_t bcb_id) const
{
    const auto context_entry = dispatch_ray_contexts.find(bcb_id);
    if (context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    const DispatchTraceRaysDumpingContext* context = &context_entry->second;
    return context;
}

VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer)
{
    auto bcb_entry = cmd_buf_begin_map_.find(original_command_buffer);
    if (bcb_entry == cmd_buf_begin_map_.end())
    {
        return nullptr;
    }

    auto dr_context_entry = dispatch_ray_contexts.find(bcb_entry->second);
    if (dr_context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    DispatchTraceRaysDumpingContext* context = &dr_context_entry->second;
    return context;
}

const VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer) const
{
    const auto bcb_entry = cmd_buf_begin_map_.find(original_command_buffer);
    if (bcb_entry == cmd_buf_begin_map_.end())
    {
        return nullptr;
    }

    const auto dr_context_entry = dispatch_ray_contexts.find(bcb_entry->second);
    if (dr_context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    const DispatchTraceRaysDumpingContext* context = &dr_context_entry->second;
    return context;
}

VkResult VulkanReplayDumpResourcesBase::CloneCommandBuffer(uint64_t                     bcb_index,
                                                           const CommandBufferInfo*     original_command_buffer_info,
                                                           const encode::DeviceTable*   device_table,
                                                           const encode::InstanceTable* inst_table)
{
    assert(device_table);
    assert(inst_table);

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(bcb_index);
    if (dc_context != nullptr)
    {
        VkResult res = dc_context->CloneCommandBuffer(original_command_buffer_info, device_table, inst_table);
        if (res == VK_SUCCESS)
        {
            recording_ = true;

            assert(cmd_buf_begin_map_.find(original_command_buffer_info->handle) == cmd_buf_begin_map_.end());
            cmd_buf_begin_map_[original_command_buffer_info->handle] = bcb_index;
        }
        else
        {
            return res;
        }
    }

    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(bcb_index);
    if (dr_context != nullptr)
    {
        VkResult res = dr_context->CloneCommandBuffer(original_command_buffer_info, device_table, inst_table);
        if (res == VK_SUCCESS)
        {
            recording_ = true;

            assert(cmd_buf_begin_map_.find(original_command_buffer_info->handle) == cmd_buf_begin_map_.end());
            cmd_buf_begin_map_[original_command_buffer_info->handle] = bcb_index;
        }
        else
        {
            return res;
        }
    }

    return VK_SUCCESS;
}

VkResult
VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::CopyIndirectDrawParameters(DrawCallParameters& dc_params)
{
    switch (dc_params.type)
    {
        case kDrawIndirect:
        case kDrawIndexedIndirect:
        {
            const uint32_t draw_count = dc_params.dc_params_union.draw_indirect.draw_count;

            // According to spec drawCount can be zero. Nothing to do in this case
            if (!draw_count)
            {
                return VK_SUCCESS;
            }

            VkDeviceSize draw_call_params_size;
            if (dc_params.type == kDrawIndirect)
            {
                draw_call_params_size = sizeof(DrawCallParameters::DrawCallParamsUnion::DrawParams);
            }
            else
            {
                draw_call_params_size = sizeof(DrawCallParameters::DrawCallParamsUnion::DrawIndexedParams);
            }

            const VkDeviceSize copy_buffer_size = draw_call_params_size * draw_count;
            assert(copy_buffer_size <= dc_params.dc_params_union.draw_indirect.params_buffer_info->size);

            dc_params.dc_params_union.draw_indirect.new_params_buffer_size = copy_buffer_size;

            VkResult res = CloneBuffer(object_info_table,
                                       device_table,
                                       replay_device_phys_mem_props,
                                       dc_params.dc_params_union.draw_indirect.params_buffer_info,
                                       &dc_params.dc_params_union.draw_indirect.new_params_buffer,
                                       &dc_params.dc_params_union.draw_indirect.new_params_memory,
                                       copy_buffer_size);

            if (res != VK_SUCCESS)
            {
                return res;
            }

            // Inject a cmdCopyBuffer to copy the draw params from the buffer
            {
                const uint32_t            param_buffer_stride = dc_params.dc_params_union.draw_indirect.stride;
                std::vector<VkBufferCopy> regions(param_buffer_stride ? draw_count : 1);
                if (param_buffer_stride)
                {
                    VkDeviceSize src_offset = 0;
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
                    regions[0].srcOffset = 0;
                    regions[0].dstOffset = 0;
                }

                VkCommandBuffer cmd_buf = command_buffers[current_cb_index];
                device_table->CmdCopyBuffer(cmd_buf,
                                            dc_params.dc_params_union.draw_indirect.params_buffer_info->handle,
                                            dc_params.dc_params_union.draw_indirect.new_params_buffer,
                                            regions.size(),
                                            regions.data());

                VkBufferMemoryBarrier buf_barrier;
                buf_barrier.sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
                buf_barrier.pNext               = nullptr;
                buf_barrier.buffer              = dc_params.dc_params_union.draw_indirect.new_params_buffer;
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
        break;

        default:
            assert(0);
            return VK_SUCCESS;
    }

    return VK_SUCCESS;
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::CopyVertexIndexBufferInfo(uint64_t            dc_index,
                                                                                       DrawCallParameters& dc_params)
{
    const PipelineInfo* gr_pipeline_info = bound_pipelines[kBindPoint_graphics];
    assert(gr_pipeline_info != nullptr);

    // Pipeline has no vertex binding and/or attribute information.
    // This can be a case of shader generated vertices, or vertex buffer is bound as a UBO
    if (gr_pipeline_info != nullptr &&
        (!gr_pipeline_info->vertex_attribute_info.size() && !gr_pipeline_info->vertex_attribute_info.size()))
    {
        return;
    }

    if (gr_pipeline_info->vertex_attribute_info.size())
    {
        assert(currently_bound_vertex_buffers != bound_vertex_buffers.end());

        currently_bound_vertex_buffers->second.referencing_draw_calls.push_back(dc_index);
        currently_bound_vertex_buffers->second.gr_pipeline_info = gr_pipeline_info;
        dc_params.referenced_bind_vertex_buffers                = currently_bound_vertex_buffers->first;
    }

    if (IsDrawCallIndexed(dc_params.type))
    {
        assert(currently_bound_index_buffer != bound_index_buffers.end());

        currently_bound_index_buffer->second.referencing_draw_calls.push_back(dc_index);
        dc_params.referenced_bind_index_buffer = currently_bound_index_buffer->first;
    }
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::FinalizeCommandBuffer()
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

void VulkanReplayDumpResourcesBase::FinalizeDrawCallCommandBuffer(VkCommandBuffer original_command_buffer)
{
    DrawCallsDumpingContext* context = FindDrawCallCommandBufferContext(original_command_buffer);
    assert(context);

    context->FinalizeCommandBuffer();

    UpdateRecordingStatus();
}

void VulkanReplayDumpResourcesBase::OverrideCmdDraw(const ApiCallInfo& call_info,
                                                    PFN_vkCmdDraw      func,
                                                    VkCommandBuffer    original_command_buffer,
                                                    uint32_t           vertex_count,
                                                    uint32_t           instance_count,
                                                    uint32_t           first_vertex,
                                                    uint32_t           first_instance)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t dc_index  = call_info.index;
    const bool     must_dump = MustDumpDrawCall(original_command_buffer, dc_index);

    if (dump_resources_before_ && must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && must_dump)
    {
        auto new_entry = dc_context->draw_call_params.emplace(
            std::piecewise_construct,
            std::forward_as_tuple(dc_index),
            std::forward_as_tuple(
                DrawCallsDumpingContext::kDraw, vertex_count, instance_count, first_vertex, first_instance));
        assert(new_entry.second);
        dc_context->CopyVertexIndexBufferInfo(dc_index, (new_entry.first->second));
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, vertex_count, instance_count, first_vertex, first_instance);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, vertex_count, instance_count, first_vertex, first_instance);
    }

    if (must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndexed(const ApiCallInfo&   call_info,
                                                           PFN_vkCmdDrawIndexed func,
                                                           VkCommandBuffer      original_command_buffer,
                                                           uint32_t             index_count,
                                                           uint32_t             instance_count,
                                                           uint32_t             first_index,
                                                           int32_t              vertexOffset,
                                                           uint32_t             first_instance)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t dc_index  = call_info.index;
    const bool     must_dump = MustDumpDrawCall(original_command_buffer, dc_index);

    if (dump_resources_before_ && must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    // Copy vertex attribute info
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && must_dump)
    {
        auto new_entry =
            dc_context->draw_call_params.emplace(std::piecewise_construct,
                                                 std::forward_as_tuple(dc_index),
                                                 std::forward_as_tuple(DrawCallsDumpingContext::kDrawIndexed,
                                                                       index_count,
                                                                       instance_count,
                                                                       first_index,
                                                                       vertexOffset,
                                                                       first_instance));
        assert(new_entry.second);
        dc_context->CopyVertexIndexBufferInfo(dc_index, new_entry.first->second);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, index_count, instance_count, first_index, vertexOffset, first_instance);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, index_count, instance_count, first_index, vertexOffset, first_instance);
    }

    if (must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndirect(const ApiCallInfo&    call_info,
                                                            PFN_vkCmdDrawIndirect func,
                                                            VkCommandBuffer       original_command_buffer,
                                                            const BufferInfo*     buffer_info,
                                                            VkDeviceSize          offset,
                                                            uint32_t              draw_count,
                                                            uint32_t              stride)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t dc_index  = call_info.index;
    const bool     must_dump = MustDumpDrawCall(original_command_buffer, dc_index);

    if (dump_resources_before_ && must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    // Copy vertex attribute info
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && must_dump)
    {
        auto new_entry = dc_context->draw_call_params.emplace(
            std::piecewise_construct,
            std::forward_as_tuple(dc_index),
            std::forward_as_tuple(DrawCallsDumpingContext::kDrawIndirect, buffer_info, offset, draw_count, stride));
        assert(new_entry.second);
        dc_context->CopyVertexIndexBufferInfo(dc_index, new_entry.first->second);
        dc_context->CopyIndirectDrawParameters(new_entry.first->second);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer_info->handle, offset, draw_count, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer_info->handle, offset, draw_count, stride);
    }

    if (must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndexedIndirect(const ApiCallInfo&           call_info,
                                                                   PFN_vkCmdDrawIndexedIndirect func,
                                                                   VkCommandBuffer              original_command_buffer,
                                                                   const BufferInfo*            buffer_info,
                                                                   VkDeviceSize                 offset,
                                                                   uint32_t                     draw_count,
                                                                   uint32_t                     stride)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t dc_index  = call_info.index;
    const bool     must_dump = MustDumpDrawCall(original_command_buffer, dc_index);

    if (dump_resources_before_ && must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && must_dump)
    {
        auto new_entry = dc_context->draw_call_params.emplace(
            std::piecewise_construct,
            std::forward_as_tuple(dc_index),
            std::forward_as_tuple(
                DrawCallsDumpingContext::kDrawIndexedIndirect, buffer_info, offset, draw_count, stride));
        assert(new_entry.second);
        dc_context->CopyVertexIndexBufferInfo(dc_index, new_entry.first->second);
        dc_context->CopyIndirectDrawParameters(new_entry.first->second);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer_info->handle, offset, draw_count, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer_info->handle, offset, draw_count, stride);
    }

    if (must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndirectCount(const ApiCallInfo&         call_info,
                                                                 PFN_vkCmdDrawIndirectCount func,
                                                                 VkCommandBuffer            original_command_buffer,
                                                                 const BufferInfo*          buffer_info,
                                                                 VkDeviceSize               offset,
                                                                 const BufferInfo*          count_buffer_info,
                                                                 VkDeviceSize               count_buffer_offset,
                                                                 uint32_t                   max_draw_count,
                                                                 uint32_t                   stride)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t dc_index  = call_info.index;
    const bool     must_dump = MustDumpDrawCall(original_command_buffer, dc_index);

    if (dump_resources_before_ && must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer_info->handle, offset, count_buffer_info->handle, count_buffer_offset, max_draw_count, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer,
             buffer_info->handle,
             offset,
             count_buffer_info->handle,
             count_buffer_offset,
             max_draw_count,
             stride);
    }

    if (must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndexedIndirectCount(const ApiCallInfo&                call_info,
                                                                        PFN_vkCmdDrawIndexedIndirectCount func,
                                                                        VkCommandBuffer   original_command_buffer,
                                                                        const BufferInfo* buffer_info,
                                                                        VkDeviceSize      offset,
                                                                        const BufferInfo* count_buffer_info,
                                                                        VkDeviceSize      count_buffer_offset,
                                                                        uint32_t          max_draw_count,
                                                                        uint32_t          stride)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t dc_index  = call_info.index;
    const bool     must_dump = MustDumpDrawCall(original_command_buffer, dc_index);

    if (dump_resources_before_ && must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer_info->handle, offset, count_buffer_info->handle, count_buffer_offset, max_draw_count, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer,
             buffer_info->handle,
             offset,
             count_buffer_info->handle,
             count_buffer_offset,
             max_draw_count,
             stride);
    }

    if (must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndirectCountKHR(const ApiCallInfo&            call_info,
                                                                    PFN_vkCmdDrawIndirectCountKHR func,
                                                                    VkCommandBuffer   original_command_buffer,
                                                                    const BufferInfo* buffer_info,
                                                                    VkDeviceSize      offset,
                                                                    const BufferInfo* count_buffer_info,
                                                                    VkDeviceSize      count_buffer_offset,
                                                                    uint32_t          max_draw_count,
                                                                    uint32_t          stride)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t dc_index  = call_info.index;
    const bool     must_dump = MustDumpDrawCall(original_command_buffer, dc_index);

    if (dump_resources_before_ && must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer_info->handle, offset, count_buffer_info->handle, count_buffer_offset, max_draw_count, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer,
             buffer_info->handle,
             offset,
             count_buffer_info->handle,
             count_buffer_offset,
             max_draw_count,
             stride);
    }

    if (must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndexedIndirectCountKHR(const ApiCallInfo& call_info,
                                                                           PFN_vkCmdDrawIndexedIndirectCountKHR func,
                                                                           VkCommandBuffer   original_command_buffer,
                                                                           const BufferInfo* buffer_info,
                                                                           VkDeviceSize      offset,
                                                                           const BufferInfo* count_buffer_info,
                                                                           VkDeviceSize      count_buffer_offset,
                                                                           uint32_t          max_draw_count,
                                                                           uint32_t          stride)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t dc_index  = call_info.index;
    const bool     must_dump = MustDumpDrawCall(original_command_buffer, dc_index);

    if (dump_resources_before_ && must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer_info->handle, offset, count_buffer_info->handle, count_buffer_offset, max_draw_count, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer,
             buffer_info->handle,
             offset,
             count_buffer_info->handle,
             count_buffer_offset,
             max_draw_count,
             stride);
    }

    if (must_dump)
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

bool VulkanReplayDumpResourcesBase::MustDumpDrawCall(VkCommandBuffer original_command_buffer, uint64_t index) const
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    const DrawCallsDumpingContext* context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (context != nullptr)
    {
        return context->MustDumpDrawCall(index);
    }
    else
    {
        return false;
    }
}

bool VulkanReplayDumpResourcesBase::MustDumpDispatch(VkCommandBuffer original_command_buffer, uint64_t index) const
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    const DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    assert(context);

    if (context != nullptr)
    {
        return context->MustDumpDispatch(index);
    }
    else
    {
        return false;
    }
}

bool VulkanReplayDumpResourcesBase::MustDumpTraceRays(VkCommandBuffer original_command_buffer, uint64_t index) const
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    const DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    assert(context);

    if (context != nullptr)
    {
        return context->MustDumpTraceRays(index);
    }
    else
    {
        return false;
    }
}

bool VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::MustDumpDrawCall(uint64_t index) const
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

bool VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::ShouldHandleRenderPass(uint64_t index) const
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

VkResult VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::DumpDrawCallsAttachments(
    VkQueue queue, uint64_t qs_index, uint64_t bcb_index, const VkSubmitInfo& submit_info, VkFence fence)
{
    // BackUpMutableResources(queue);

    const size_t n_drawcalls = command_buffers.size();
    for (size_t cb = 0; cb < n_drawcalls; ++cb)
    {
        GFXRECON_LOG_INFO("Submitting CB/DC %u of %zu (idx: %" PRIu64 ") for BeginCommandBuffer: %" PRIu64,
                          cb,
                          n_drawcalls,
                          dc_indices[CmdBufToDCVectorIndex(cb)],
                          bcb_index);

        p_dump_json->VulkanReplayDumpResourcesJsonBlockStart();

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

        // RevertMutableResources(queue);

        const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
        assert(device_info);

        VkResult res;

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

        // Revert render attachments layouts
        // res = RevertRenderTargetImageLayouts(dc_context, queue, dc_indices[cb]);
        // assert(res == VK_SUCCESS);
        // if (res != VK_SUCCESS)
        // {
        //     return res;
        // }

        p_dump_json->VulkanReplayDumpResourcesJsonBlockEnd();
    }

    // Dump vertex attributes
    if (dump_vertex_index_buffers)
    {
        DumpVertexIndexBuffers();
    }

    return VK_SUCCESS;
}

#define DEPTH_ATTACHMENT ~0

std::string VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::GenerateImageFilename(VkFormat format,
                                                                                          uint64_t cmd_buf_index,
                                                                                          uint64_t dc_index,
                                                                                          int attachment_index) const
{
    util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(format);

    std::vector<VkImageAspectFlagBits> aspects;
    bool                               combined_depth_stencil;
    graphics::GetFormatAspects(format, &aspects, &combined_depth_stencil);

    std::string aspect_str_whole(util::ToString<VkImageAspectFlagBits>(aspects[0]));
    std::string aspect_str(aspect_str_whole.begin() + 16, aspect_str_whole.end() - 4);
    std::string attachment_str =
        attachment_index != DEPTH_ATTACHMENT ? "_att_" + std::to_string(attachment_index) : "_depth_att_";

    std::stringstream filename;
    if (VkFormatToImageWriterDataFormat(format) != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
    {
        if (dump_resources_before)
        {
            filename << "Draw_" << ((cmd_buf_index % 2) ? "after_" : "before_") << dc_index << attachment_str
                     << "_aspect_" << aspect_str << util::ScreenshotFormatToCStr(image_file_format);
        }
        else
        {
            filename << "Draw_" << dc_index << attachment_str << "_aspect_" << aspect_str
                     << util::ScreenshotFormatToCStr(image_file_format);
        }
    }
    else
    {
        if (dump_resources_before)
        {
            filename << "Draw_" << ((cmd_buf_index % 2) ? "after_" : "before_") << dc_index << attachment_str
                     << "_aspect_" << aspect_str << ".bin";
        }
        else
        {
            filename << "Draw_" << dc_index << attachment_str << "_aspect_" << aspect_str << ".bin";
        }
    }

    std::filesystem::path filedirname(dump_resource_path);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

VkResult VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::DumpRenderTargetAttachments(uint64_t cmd_buf_index,
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
        const ImageInfo* image_info = render_targets[rp][sp].color_att_imgs[i];

        std::vector<uint8_t>  data;
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;
        bool                  scaling_supported;

        VkResult res = resource_util.ReadFromImageResourceStaging(
            image_info->handle,
            image_info->format,
            image_info->type,
            VkExtent3D{ render_area[rp].extent.width, render_area[rp].extent.height, 1 },
            image_info->level_count,
            image_info->layer_count,
            image_info->tiling,
            image_info->sample_count,
            // All ender targets should be transitioned by the
            // custom render passes into TRANSFER_SRC_OPTIMAL
            VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
            0,
            VK_IMAGE_ASPECT_COLOR_BIT,
            data,
            subresource_offsets,
            subresource_sizes,
            scaling_supported,
            false,
            dump_resources_scale);

        if (res != VK_SUCCESS)
        {
            return res;
        }

        util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(image_info->format);
        const std::string              filename = GenerateImageFilename(image_info->format, cmd_buf_index, dc_index, i);
        p_dump_json->VulkanReplayDumpResourcesJsonData("DrawIndex", dc_index);
        p_dump_json->VulkanReplayDumpResourcesJsonData("BeginCommandBufferIndex", bcb_index);
        p_dump_json->VulkanReplayDumpResourcesJsonData("QueueSubmitIndex", qs_index);
        if (output_image_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
        {
            VkExtent3D scaled_extent;
            if (scaling_supported)
            {
                scaled_extent.width  = image_info->extent.width * dump_resources_scale;
                scaled_extent.height = image_info->extent.height * dump_resources_scale;
                scaled_extent.depth  = image_info->extent.depth;
            }
            else
            {
                scaled_extent = image_info->extent;
            }

            p_dump_json->VulkanReplayDumpResourcesJsonData(("RenderTargetImage_" + std::to_string(i)).c_str(),
                                                           filename);

            const uint32_t texel_size = vkuFormatElementSizeWithAspect(image_info->format, VK_IMAGE_ASPECT_COLOR_BIT);
            const uint32_t stride     = texel_size * scaled_extent.width;

            if (image_file_format == util::ScreenshotFormat::kBmp)
            {
                util::imagewriter::WriteBmpImage(filename,
                                                 scaled_extent.width,
                                                 scaled_extent.height,
                                                 subresource_sizes[0],
                                                 data.data(),
                                                 stride,
                                                 output_image_format);
            }
            else if (image_file_format == util::ScreenshotFormat::kPng)
            {
                util::imagewriter::WritePngImage(filename,
                                                 scaled_extent.width,
                                                 scaled_extent.height,
                                                 subresource_sizes[0],
                                                 data.data(),
                                                 stride,
                                                 output_image_format);
            }
        }
        else
        {
            p_dump_json->VulkanReplayDumpResourcesJsonData(("RenderTargetImage_" + std::to_string(i)).c_str(),
                                                           filename);
            util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
        }
    }

    // Dump depth attachment
    if (render_targets[rp][sp].depth_att_img != nullptr)
    {
        const ImageInfo* image_info = render_targets[rp][sp].depth_att_img;

        std::vector<uint8_t>  data;
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;
        bool                  scaling_supported;

        VkResult res = resource_util.ReadFromImageResourceStaging(
            image_info->handle,
            image_info->format,
            image_info->type,
            VkExtent3D{ render_area[rp].extent.width, render_area[rp].extent.height, 1 },
            image_info->level_count,
            image_info->layer_count,
            image_info->tiling,
            image_info->sample_count,
            // All ender targets should be transitioned by the
            // custom render passes into TRANSFER_SRC_OPTIMAL
            VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
            0,
            VK_IMAGE_ASPECT_DEPTH_BIT,
            data,
            subresource_offsets,
            subresource_sizes,
            scaling_supported,
            false,
            dump_resources_scale);

        if (res != VK_SUCCESS)
        {
            return res;
        }

        util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(image_info->format);
        const std::string              filename =
            GenerateImageFilename(image_info->format, cmd_buf_index, dc_index, DEPTH_ATTACHMENT);
        if (output_image_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
        {
            VkExtent3D scaled_extent;
            if (scaling_supported)
            {
                scaled_extent.width  = image_info->extent.width * dump_resources_scale;
                scaled_extent.height = image_info->extent.height * dump_resources_scale;
                scaled_extent.depth  = image_info->extent.depth;
            }
            else
            {
                scaled_extent = image_info->extent;
            }

            p_dump_json->VulkanReplayDumpResourcesJsonData("RenderTargetDepth", filename);

            // This is a bit awkward
            const uint32_t texel_size =
                image_info->format != VK_FORMAT_X8_D24_UNORM_PACK32
                    ? vkuFormatElementSizeWithAspect(image_info->format, VK_IMAGE_ASPECT_DEPTH_BIT)
                    : 4;
            const uint32_t stride = texel_size * scaled_extent.width;

            if (image_file_format == util::ScreenshotFormat::kBmp)
            {
                util::imagewriter::WriteBmpImage(filename,
                                                 scaled_extent.width,
                                                 scaled_extent.height,
                                                 subresource_sizes[0],
                                                 data.data(),
                                                 stride,
                                                 output_image_format);
            }
            else
            {
                util::imagewriter::WritePngImage(filename,
                                                 scaled_extent.width,
                                                 scaled_extent.height,
                                                 subresource_sizes[0],
                                                 data.data(),
                                                 stride,
                                                 output_image_format);
            }
        }
        else
        {
            p_dump_json->VulkanReplayDumpResourcesJsonData("RenderTargetDepth", filename);
            util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
        }
    }

    // Emit in json output the references to vertex and index buffers dumped files
    if (dump_vertex_index_buffers)
    {
        const auto dc_param_entry = draw_call_params.find(dc_index);
        assert(dc_param_entry != draw_call_params.end());
        if (dc_param_entry != draw_call_params.end())
        {
            const DrawCallParameters& dc_param = dc_param_entry->second;
            if (IsDrawCallIndexed(dc_param.type))
            {
                assert(dc_param.referenced_bind_index_buffer != INVALID_BLOCK_INDEX);
                const auto bound_index_buffer_entry = bound_index_buffers.find(dc_param.referenced_bind_index_buffer);
                assert(bound_index_buffer_entry != bound_index_buffers.end());
                if (bound_index_buffer_entry != bound_index_buffers.end())
                {
                    const std::string index_buffer_filename = GenerateIndexBufferFilename(
                        dc_param.referenced_bind_index_buffer, bound_index_buffer_entry->second.index_type);

                    p_dump_json->VulkanReplayDumpResourcesJsonData("IndexBuffer", index_buffer_filename);
                }
            }

            const PipelineInfo* gr_pipeline_info = bound_pipelines[kBindPoint_graphics];
            if (gr_pipeline_info != nullptr && gr_pipeline_info->vertex_binding_info.size() &&
                dc_param.referenced_bind_vertex_buffers != INVALID_BLOCK_INDEX)
            {
                uint32_t i = 0;
                for (const auto& vb_binding : gr_pipeline_info->vertex_binding_info)
                {
                    const std::string vb_filename =
                        GenerateVertexBufferFilename(dc_param.referenced_bind_vertex_buffers, vb_binding.first);
                    p_dump_json->VulkanReplayDumpResourcesJsonData(("VertexBuffer_" + std::to_string(i++)),
                                                                   vb_filename);
                }
            }
        }
    }

    return VK_SUCCESS;
}

std::string
VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::GenerateIndexBufferFilename(uint64_t    bind_index_buffer_index,
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

std::string
VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::GenerateVertexBufferFilename(uint64_t bind_vertex_buffer_index,
                                                                                     uint32_t binding) const
{
    std::stringstream filename;

    filename << "VertexBuffers_" << bind_vertex_buffer_index << "_binding_" << binding << ".bin";

    std::filesystem::path filedirname(dump_resource_path);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

VkResult VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::FetchDrawIndirectParams()
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

        if (dc_params.type == DrawCallTypes::kDrawIndirect)
        {
            if (!dc_params.dc_params_union.draw_indirect.draw_count)
            {
                continue;
            }

            assert(dc_params.dc_params_union.draw_indirect.draw_params == nullptr);
            dc_params.dc_params_union.draw_indirect.draw_params =
                new DrawCallParameters::DrawCallParamsUnion::DrawParams[dc_params.dc_params_union.draw_indirect
                                                                            .draw_count];
            if (dc_params.dc_params_union.draw_indirect.draw_params == nullptr)
            {
                return VK_ERROR_OUT_OF_HOST_MEMORY;
            }
        }
        else if (dc_params.type == DrawCallTypes::kDrawIndexedIndirect)
        {
            if (!dc_params.dc_params_union.draw_indirect.draw_count)
            {
                continue;
            }

            assert(dc_params.dc_params_union.draw_indirect.draw_indexed_params == nullptr);
            dc_params.dc_params_union.draw_indirect.draw_indexed_params =
                new DrawCallParameters::DrawCallParamsUnion::DrawIndexedParams[dc_params.dc_params_union.draw_indirect
                                                                                   .draw_count];
            if (dc_params.dc_params_union.draw_indirect.draw_indexed_params == nullptr)
            {
                return VK_ERROR_OUT_OF_HOST_MEMORY;
            }
        }

        std::vector<uint8_t> params_data;
        VkResult             res = resource_util.ReadFromBufferResource(
            dc_params.dc_params_union.draw_indirect.new_params_buffer,
            dc_params.dc_params_union.draw_indirect.new_params_buffer_size,
            0,
            dc_params.dc_params_union.draw_indirect.params_buffer_info->queue_family_index,
            params_data);

        if (res != VK_SUCCESS)
        {
            return res;
        }

        assert(params_data.size() == dc_params.dc_params_union.draw_indirect.new_params_buffer_size);

        if (dc_params.type == DrawCallTypes::kDrawIndirect)
        {
            util::platform::MemoryCopy(dc_params.dc_params_union.draw_indirect.draw_params,
                                       dc_params.dc_params_union.draw_indirect.new_params_buffer_size,
                                       params_data.data(),
                                       params_data.size());
        }
        else if (dc_params.type == DrawCallTypes::kDrawIndexedIndirect)
        {
            util::platform::MemoryCopy(dc_params.dc_params_union.draw_indirect.draw_indexed_params,
                                       dc_params.dc_params_union.draw_indirect.new_params_buffer_size,
                                       params_data.data(),
                                       params_data.size());
        }
    }

    return VK_SUCCESS;
}

VkResult VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::DumpVertexIndexBuffers()
{
    assert(draw_call_params.size() == dc_indices.size());

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

        // In order to deduce the index buffer's size find the greatest index count
        // used by all draw calls that reference this index buffer
        uint32_t max_index_count = 0;
        for (const auto ref_dc_index : idx_buf.second.referencing_draw_calls)
        {
            const auto& dc_params_entry = draw_call_params.find(ref_dc_index);
            assert(dc_params_entry != draw_call_params.end());

            const DrawCallParameters& dc_params = dc_params_entry->second;
            assert(IsDrawCallIndexed(dc_params.type));
            assert(dc_params.referenced_bind_index_buffer != INVALID_BLOCK_INDEX);

            if (IsDrawCallIndirect(dc_params.type))
            {
                if (!dc_params.dc_params_union.draw_indirect.draw_count)
                {
                    continue;
                }

                assert(dc_params.dc_params_union.draw_indirect.draw_indexed_params != nullptr);
                const DrawCallParameters::DrawCallParamsUnion::DrawIndexedParams* indirect_indexed_params =
                    dc_params.dc_params_union.draw_indirect.draw_indexed_params;
                for (uint32_t d = 0; d < dc_params.dc_params_union.draw_indirect.draw_count; ++d)
                {
                    if (max_index_count < indirect_indexed_params[d].index_count)
                    {
                        max_index_count = indirect_indexed_params[d].index_count;
                    }
                }
            }
            else
            {
                if (max_index_count < dc_params.dc_params_union.draw_indexed.index_count)
                {
                    max_index_count = dc_params.dc_params_union.draw_indexed.index_count;
                }
            }
        }

        const VkIndexType index_type  = idx_buf.second.index_type;
        const uint32_t    index_size  = VkIndexTypeToBytes(index_type);
        const uint32_t    index_count = max_index_count;
        const uint32_t    offset      = idx_buf.second.offset;
        uint32_t          total_size  = index_count * index_size;

        assert(idx_buf.second.buffer_info != nullptr);
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

        // Parse indices and find the greatest vertex index. We should need this
        // later when we calculate the size of the vertex buffers
        uint32_t greatest_vertex_index = FindGreatestVertexIndex(index_data, index_count, index_type);
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
        // used by all draw calls that reference this index buffer
        uint32_t max_vertex_count = 0;
        for (const auto ref_dc_index : vbs.second.referencing_draw_calls)
        {
            const auto& dc_params_entry = draw_call_params.find(ref_dc_index);
            assert(dc_params_entry != draw_call_params.end());

            const DrawCallParameters& dc_params = dc_params_entry->second;
            assert(dc_params.referenced_bind_vertex_buffers != INVALID_BLOCK_INDEX);

            if (IsDrawCallIndexed(dc_params.type))
            {
                // For indexed draw calls the greatest vertex index will be used as the max vertex count
                assert(dc_params.referenced_bind_index_buffer != INVALID_BLOCK_INDEX);
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
                    if (!dc_params.dc_params_union.draw_indirect.draw_count)
                    {
                        continue;
                    }

                    assert(dc_params.dc_params_union.draw_indirect.draw_params != nullptr);
                    const DrawCallParameters::DrawCallParamsUnion::DrawParams* indirect_params =
                        dc_params.dc_params_union.draw_indirect.draw_params;
                    for (uint32_t d = 0; d < dc_params.dc_params_union.draw_indirect.draw_count; ++d)
                    {
                        if (max_vertex_count < indirect_params[d].vertex_count)
                        {
                            max_vertex_count = indirect_params[d].vertex_count;
                        }
                    }
                }
                else
                {
                    if (max_vertex_count < dc_params.dc_params_union.draw.vertex_count)
                    {
                        max_vertex_count = dc_params.dc_params_union.draw.vertex_count;
                    }
                }
            }
        }

        for (const auto& vb_binding : vbs.second.bound_vertex_buffer_per_binding)
        {
            const uint32_t binding = vb_binding.first;

            assert(vbs.second.gr_pipeline_info);

            const auto& ppl_vb_binding_entry = vbs.second.gr_pipeline_info->vertex_binding_info.find(binding);
            assert(ppl_vb_binding_entry != vbs.second.gr_pipeline_info->vertex_binding_info.end());
            if (ppl_vb_binding_entry == vbs.second.gr_pipeline_info->vertex_binding_info.end())
            {
                continue;
            }

            const uint32_t binding_stride = ppl_vb_binding_entry->second.stride;
            const uint32_t offset         = vb_binding.second.offset;
            uint32_t       total_size     = max_vertex_count * binding_stride;

            assert(vb_binding.second.buffer_info != nullptr);
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

VkResult VulkanReplayDumpResourcesBase::QueueSubmit(const std::vector<VkSubmitInfo>& submit_infos,
                                                    const encode::DeviceTable&       device_table,
                                                    VkQueue                          queue,
                                                    VkFence                          fence,
                                                    uint64_t                         index)
{
    bool     pre_submit = false;
    bool     submitted  = false;
    VkResult res;

    // First do a submission with all command buffer except the ones we are interested in
    std::vector<VkSubmitInfo>                 modified_submit_infos = submit_infos;
    std::vector<std::vector<VkCommandBuffer>> modified_command_buffer_handles(modified_submit_infos.size());
    for (size_t s = 0; s < modified_submit_infos.size(); s++)
    {
        size_t     command_buffer_count   = modified_submit_infos[s].commandBufferCount;
        const auto command_buffer_handles = modified_submit_infos[s].pCommandBuffers;

        for (uint32_t o = 0; o < command_buffer_count; ++o)
        {
            auto bcb_entry = cmd_buf_begin_map_.find(command_buffer_handles[o]);
            if (bcb_entry != cmd_buf_begin_map_.end())
            {
                continue;
            }
            else
            {
                pre_submit = true;
                modified_command_buffer_handles[s].push_back(command_buffer_handles[o]);
            }
        }

        if (modified_command_buffer_handles[s].size())
        {
            modified_submit_infos[s].commandBufferCount = modified_command_buffer_handles[s].size();
            modified_submit_infos[s].pCommandBuffers    = modified_command_buffer_handles[s].data();
        }
        else
        {
            modified_submit_infos[s].commandBufferCount = 0;
            modified_submit_infos[s].pCommandBuffers    = nullptr;
        }
    }

    if (pre_submit)
    {
        res =
            device_table.QueueSubmit(queue, modified_submit_infos.size(), modified_submit_infos.data(), VK_NULL_HANDLE);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
            goto error;
        }

        // Wait
        res = device_table.QueueWaitIdle(queue);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("QueueWaitIdle failed with %s", util::ToString<VkResult>(res).c_str());
            goto error;
        }
    }

    for (size_t s = 0; s < submit_infos.size(); s++)
    {
        size_t     command_buffer_count   = submit_infos[s].commandBufferCount;
        const auto command_buffer_handles = submit_infos[s].pCommandBuffers;

        for (size_t o = 0; o < command_buffer_count; ++o)
        {
            if (pre_submit)
            {
                // These semaphores have already been handled. Do not bother with them
                modified_submit_infos[s].waitSemaphoreCount = 0;
                modified_submit_infos[s].pSignalSemaphores  = 0;
            }

            DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(command_buffer_handles[o]);
            if (dc_context != nullptr)
            {
                assert(cmd_buf_begin_map_.find(command_buffer_handles[o]) != cmd_buf_begin_map_.end());

                res = dc_context->DumpDrawCallsAttachments(
                    queue, index, cmd_buf_begin_map_[command_buffer_handles[o]], modified_submit_infos[s], fence);
                if (res == VK_SUCCESS)
                {
                    submitted = true;
                }
                else
                {
                    goto error;
                }
            }

            DispatchTraceRaysDumpingContext* dr_context =
                FindDispatchRaysCommandBufferContext(command_buffer_handles[o]);
            if (dr_context != nullptr)
            {
                assert(cmd_buf_begin_map_.find(command_buffer_handles[o]) != cmd_buf_begin_map_.end());
                res = dr_context->DumpDispatchRaysMutableResources(
                    queue, index, cmd_buf_begin_map_[command_buffer_handles[o]], modified_submit_infos[s], fence);

                if (res == VK_SUCCESS)
                {
                    submitted = true;
                }
                else
                {
                    goto error;
                }
            }
        }
    }

    assert(res >= 0);

    // Looks like we didn't submit anything. Do the submission as it would have been done
    // without further modifications
    if (!submitted)
    {
        res = device_table.QueueSubmit(queue, submit_infos.size(), submit_infos.data(), fence);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
        }
    }
    else
    {
        assert(index == QueueSubmit_indices_[0]);
        QueueSubmit_indices_.erase(QueueSubmit_indices_.begin());

        // Once all submissions are complete terminate process
        if (QueueSubmit_indices_.size() == 0)
        {
            // The code in VulkanReplayDumpResourcesJsonClose would ideally be in
            // the VulkanReplayDumpResourcesJson destructor. But the destructor
            // doesn't get called when exit(0) is called, so we call this method
            // instead.
            dump_json_.VulkanReplayDumpResourcesJsonClose();
            exit(0);
        }
    }

error:
    if (res < 0)
    {
        GFXRECON_LOG_ERROR("Something went wrong. Terminating.")
        exit(0);
    }

    return res;
}

VkResult
VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::CloneCommandBuffer(const CommandBufferInfo*   orig_cmd_buf_info,
                                                                           const encode::DeviceTable* dev_table,
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

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::BindDescriptorSets(
    VkPipelineBindPoint                          pipeline_bind_point,
    uint32_t                                     first_set,
    const std::vector<const DescriptorSetInfo*>& descriptor_sets_infos,
    uint32_t                                     dynamicOffsetCount,
    const uint32_t*                              pDynamicOffsets)
{
    PipelineBindPoints bind_point = VkPipelineBindPointToPipelineBindPoint(pipeline_bind_point);

    for (size_t i = 0; i < descriptor_sets_infos.size(); ++i)
    {
        for (const auto& binding : descriptor_sets_infos[i]->descriptors)
        {
            switch (binding.second.desc_type)
            {
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                {
                    const ImageViewInfo* img_view_info =
                        object_info_table.GetImageViewInfo(binding.second.image_info.image_view_id);
                    assert(img_view_info);

                    const ImageInfo* img_info = object_info_table.GetImageInfo(img_view_info->image_id);
                    assert(img_info);

                    bound_descriptor_sets[bind_point][first_set + i].image_infos[binding.first] = img_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                {
                    const BufferInfo* buffer_info =
                        object_info_table.GetBufferInfo(binding.second.buffer_info.buffer_id);
                    assert(buffer_info);

                    bound_descriptor_sets[bind_point][first_set + i].buffer_infos[binding.first] = buffer_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    const BufferViewInfo* buffer_view_info =
                        object_info_table.GetBufferViewInfo(binding.second.texel_buffer_view);
                    assert(buffer_view_info);

                    const BufferInfo* buffer_info = object_info_table.GetBufferInfo(buffer_view_info->buffer_id);
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
                    break;

                default:
                    GFXRECON_LOG_WARNING_ONCE("%s(): Descriptor type (%s) not handled",
                                              __func__,
                                              util::ToString<VkDescriptorType>(binding.second.desc_type).c_str());
                    break;
            }
        }
    }
}

VkResult
VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::CloneRenderPass(const RenderPassInfo* original_render_pass)
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

VkResult
VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::BeginRenderPass(const RenderPassInfo*  render_pass_info,
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

    VkResult res = CloneRenderPass(render_pass_info);
    if (res != VK_SUCCESS)
    {
        return res;
    }

    // Add vkCmdBeginRenderPass into the cloned command buffers using the modified render pass
    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(first, last);

    VkRenderPassBeginInfo bi;
    bi.sType           = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    bi.pNext           = nullptr;
    bi.clearValueCount = clear_value_count;
    bi.pClearValues    = p_clear_values;
    bi.framebuffer     = framebuffer_info->handle;
    bi.renderArea      = render_area;

    size_t cmd_buf_idx = current_cb_index;
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it, ++cmd_buf_idx)
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

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::NextSubpass(VkSubpassContents contents)
{
    assert(active_renderpass);
    assert(active_framebuffer);

    std::vector<const ImageInfo*>    color_att_imgs;
    std::vector<VkAttachmentStoreOp> color_att_storeOps;
    std::vector<VkImageLayout>       color_att_final_layouts;

    ++current_subpass;

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(first, last);
    size_t cmd_buf_idx = current_cb_index;
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it, ++cmd_buf_idx)
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
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::BindPipeline(VkPipelineBindPoint pipeline_bind_point,
                                                                          const PipelineInfo* pipeline)
{
    VulkanReplayDumpResourcesBase::PipelineBindPoints bind_point =
        VkPipelineBindPointToPipelineBindPoint(pipeline_bind_point);

    bound_pipelines[bind_point] = pipeline;
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::EndRenderPass()
{
    assert(inside_renderpass);

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(first, last);
    size_t cmd_buf_idx = current_cb_index;
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it, ++cmd_buf_idx)
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

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::BindVertexBuffers(
    uint64_t                              index,
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

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::BindIndexBuffer(uint64_t          index,
                                                                             const BufferInfo* buffer_info,
                                                                             VkDeviceSize      offset,
                                                                             VkIndexType       index_type)
{
    auto new_entry = bound_index_buffers.emplace(
        std::piecewise_construct, std::forward_as_tuple(index), std::forward_as_tuple(buffer_info, offset, index_type));
    assert(new_entry.second);
    currently_bound_index_buffer = new_entry.first;
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::SetRenderTargets(
    const std::vector<const ImageInfo*>& color_att_imgs, const ImageInfo* depth_att_img, bool new_render_pass)
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

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::SetRenderArea(const VkRect2D& new_render_area)
{
    render_area.push_back(new_render_area);
}

bool VulkanReplayDumpResourcesBase::DumpingBeginCommandBufferIndex(uint64_t index) const
{
    const DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(index);

    if (dc_context == nullptr)
    {
        const DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(index);
        return dr_context != nullptr;
    }
    else
    {
        return true;
    }
}

bool VulkanReplayDumpResourcesBase::GetDrawCallActiveCommandBuffers(VkCommandBuffer original_command_buffer,
                                                                    cmd_buf_it&     first,
                                                                    cmd_buf_it&     last) const
{
    assert(IsRecording(original_command_buffer));

    const DrawCallsDumpingContext* stack = FindDrawCallCommandBufferContext(original_command_buffer);

    if (stack != nullptr)
    {
        stack->GetDrawCallActiveCommandBuffers(first, last);
        return true;
    }
    else
    {
        return false;
    }
}

VkCommandBuffer
VulkanReplayDumpResourcesBase::GetDispatchRaysCommandBuffer(VkCommandBuffer original_command_buffer) const
{
    assert(IsRecording(original_command_buffer));

    const DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);

    if (context != nullptr)
    {
        VkCommandBuffer dr_command_buffer = context->GetDispatchRaysCommandBuffer();
        assert(dr_command_buffer != VK_NULL_HANDLE);

        return dr_command_buffer;
    }
    else
    {
        return VK_NULL_HANDLE;
    }
}

bool VulkanReplayDumpResourcesBase::UpdateRecordingStatus()
{
    assert(recording_);

    for (const auto& entry : draw_call_contexts)
    {
        const DrawCallsDumpingContext& dc_context = entry.second;
        if (dc_context.IsRecording())
        {
            return true;
        }
    }

    for (const auto& entry : dispatch_ray_contexts)
    {
        const DispatchTraceRaysDumpingContext& dr_context = entry.second;
        if (dr_context.IsRecording())
        {
            return true;
        }
    }

    return (recording_ = false);
}

bool VulkanReplayDumpResourcesBase::MustDumpQueueSubmitIndex(uint64_t index) const
{
    // Indices should be sorted
    if (!IsInsideRange(QueueSubmit_indices_, index))
    {
        return false;
    }

    for (size_t i = 0; i < QueueSubmit_indices_.size(); ++i)
    {
        if (index == QueueSubmit_indices_[i])
        {
            return true;
        }
        else if (index > QueueSubmit_indices_[i])
        {
            return false;
        }
    }

    return false;
}

void VulkanReplayDumpResourcesBase::OverrideCmdBeginRenderPass(
    const ApiCallInfo&                                   call_info,
    PFN_vkCmdBeginRenderPass                             func,
    VkCommandBuffer                                      original_command_buffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                                    contents)
{
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        const auto render_pass_info_meta = pRenderPassBegin->GetMetaStructPointer();
        auto       framebuffer_id        = render_pass_info_meta->framebuffer;
        auto       render_pass_id        = render_pass_info_meta->renderPass;

        const FramebufferInfo* framebuffer_info = object_info_table_.GetFramebufferInfo(framebuffer_id);
        assert(framebuffer_info);

        const RenderPassInfo* render_pass_info = object_info_table_.GetRenderPassInfo(render_pass_id);
        assert(render_pass_info);

        // Do not record vkCmdBeginRenderPass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::BeginRenderPass
        VkResult res = dc_context->BeginRenderPass(render_pass_info,
                                                   pRenderPassBegin->GetPointer()->clearValueCount,
                                                   pRenderPassBegin->GetPointer()->pClearValues,
                                                   framebuffer_info,
                                                   pRenderPassBegin->GetPointer()->renderArea,
                                                   contents);
        assert(res == VK_SUCCESS);
    }
    else if (dc_context != nullptr)
    {
        VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, pRenderPassBegin->GetPointer(), contents);
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pRenderPassBegin->GetPointer(), contents);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBeginRenderPass2(
    const ApiCallInfo&                                   call_info,
    PFN_vkCmdBeginRenderPass2                            func,
    VkCommandBuffer                                      original_command_buffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>*    pSubpassBeginInfo)
{
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        const auto render_pass_info_meta = pRenderPassBegin->GetMetaStructPointer();
        auto       framebuffer_id        = render_pass_info_meta->framebuffer;
        auto       render_pass_id        = render_pass_info_meta->renderPass;

        const FramebufferInfo* framebuffer_info = object_info_table_.GetFramebufferInfo(framebuffer_id);
        assert(framebuffer_info);

        const RenderPassInfo* render_pass_info = object_info_table_.GetRenderPassInfo(render_pass_id);
        assert(render_pass_info);

        // Do not record vkCmdBeginRenderPass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::BeginRenderPass
        VkResult res = dc_context->BeginRenderPass(render_pass_info,
                                                   pRenderPassBegin->GetPointer()->clearValueCount,
                                                   pRenderPassBegin->GetPointer()->pClearValues,
                                                   framebuffer_info,
                                                   pRenderPassBegin->GetPointer()->renderArea,
                                                   pSubpassBeginInfo->GetPointer()->contents);

        assert(res == VK_SUCCESS);
    }
    else if (dc_context != nullptr)
    {
        VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, pRenderPassBegin->GetPointer(), pSubpassBeginInfo->GetPointer());
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pRenderPassBegin->GetPointer(), pSubpassBeginInfo->GetPointer());
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdNextSubpass(const ApiCallInfo&   call_info,
                                                           PFN_vkCmdNextSubpass func,
                                                           VkCommandBuffer      original_command_buffer,
                                                           VkSubpassContents    contents)
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    // Do not record NextSubpass commands in current DrawCall context command buffers.
    // It will be handled by DrawCallsDumpingContext::NextSubpass
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        dc_context->NextSubpass(contents);
    }
    else if (dc_context != nullptr)
    {
        VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, contents);
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, contents);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdNextSubpass2(
    const ApiCallInfo&                                call_info,
    PFN_vkCmdNextSubpass2                             func,
    VkCommandBuffer                                   original_command_buffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>*   pSubpassEndInfo)
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        // Do not record NextSubpass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::NextSubpass
        dc_context->NextSubpass(pSubpassBeginInfo->GetPointer()->contents);
    }
    else if (dc_context != nullptr)
    {
        VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, pSubpassBeginInfo->GetPointer(), pSubpassEndInfo->GetPointer());
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pSubpassBeginInfo->GetPointer(), pSubpassEndInfo->GetPointer());
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndRenderPass(const ApiCallInfo&     call_info,
                                                             PFN_vkCmdEndRenderPass func,
                                                             VkCommandBuffer        original_command_buffer)
{
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        // Do not record EndRenderPass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::EndRenderPass
        dc_context->EndRenderPass();
    }
    else if (dc_context != nullptr)
    {
        VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it);
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndRenderPass2(
    const ApiCallInfo&                              call_info,
    PFN_vkCmdEndRenderPass2                         func,
    VkCommandBuffer                                 original_command_buffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        // Do not record EndRenderPass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::EndRenderPass
        dc_context->EndRenderPass();
    }
    else if (dc_context != nullptr)
    {
        VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, pSubpassEndInfo->GetPointer());
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pSubpassEndInfo->GetPointer());
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindPipeline(const ApiCallInfo&    call_info,
                                                            PFN_vkCmdBindPipeline func,
                                                            VkCommandBuffer       original_command_buffer,
                                                            VkPipelineBindPoint   pipelineBindPoint,
                                                            const PipelineInfo*   pipeline)
{
    assert(pipeline);
    assert(IsRecording(original_command_buffer));

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, pipelineBindPoint, pipeline->handle);
        }

        DrawCallsDumpingContext* context = FindDrawCallCommandBufferContext(original_command_buffer);
        assert(context);
        context->BindPipeline(pipelineBindPoint, pipeline);
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, pipelineBindPoint, pipeline->handle);

        DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
        assert(context);
        context->BindPipeline(pipelineBindPoint, pipeline);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindDescriptorSets(const ApiCallInfo&          call_info,
                                                                  PFN_vkCmdBindDescriptorSets func,
                                                                  VkCommandBuffer             original_command_buffer,
                                                                  VkPipelineBindPoint         pipeline_bind_point,
                                                                  const PipelineLayoutInfo*   layout_info,
                                                                  uint32_t                    first_set,
                                                                  uint32_t                    descriptor_sets_count,
                                                                  const format::HandleId*     descriptor_sets_ids,
                                                                  uint32_t                    dynamicOffsetCount,
                                                                  const uint32_t*             pDynamicOffsets)
{
    assert(IsRecording(original_command_buffer));
    assert(descriptor_sets_ids);

    PipelineBindPoints                    bind_point = VkPipelineBindPointToPipelineBindPoint(pipeline_bind_point);
    std::vector<VkDescriptorSet>          desc_set_handles(descriptor_sets_count, VK_NULL_HANDLE);
    std::vector<const DescriptorSetInfo*> desc_set_infos(descriptor_sets_count, nullptr);

    for (uint32_t i = 0; i < descriptor_sets_count; ++i)
    {
        const DescriptorSetInfo* desc_set_info = object_info_table_.GetDescriptorSetInfo(descriptor_sets_ids[i]);
        assert(desc_set_info);
        desc_set_infos[i]   = desc_set_info;
        desc_set_handles[i] = desc_set_info->handle;
    }

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context)
    {
        dc_context->BindDescriptorSets(
            pipeline_bind_point, first_set, desc_set_infos, dynamicOffsetCount, pDynamicOffsets);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it,
             pipeline_bind_point,
             layout_info->handle,
             first_set,
             descriptor_sets_count,
             desc_set_handles.data(),
             dynamicOffsetCount,
             pDynamicOffsets);
    }

    VkCommandBuffer dr_cmd_buf = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_cmd_buf != VK_NULL_HANDLE)
    {
        func(dr_cmd_buf,
             pipeline_bind_point,
             layout_info->handle,
             first_set,
             descriptor_sets_count,
             desc_set_handles.data(),
             dynamicOffsetCount,
             pDynamicOffsets);
    }

    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    if (dr_context)
    {
        dr_context->BindDescriptorSets(
            pipeline_bind_point, first_set, desc_set_infos, dynamicOffsetCount, pDynamicOffsets);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindIndexBuffer(const ApiCallInfo&       call_info,
                                                               PFN_vkCmdBindIndexBuffer func,
                                                               VkCommandBuffer          original_command_buffer,
                                                               const BufferInfo*        buffer,
                                                               VkDeviceSize             offset,
                                                               VkIndexType              indexType)
{
    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    bool found = GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    if (found)
    {
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, buffer->handle, offset, indexType);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, buffer->handle, offset, indexType);
    }

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr)
    {
        dc_context->BindIndexBuffer(call_info.index, buffer, offset, indexType);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindVertexBuffers(const ApiCallInfo&         call_info,
                                                                 PFN_vkCmdBindVertexBuffers func,
                                                                 VkCommandBuffer            original_command_buffer,
                                                                 uint32_t                   firstBinding,
                                                                 uint32_t                   bindingCount,
                                                                 const format::HandleId*    buffer_ids,
                                                                 const VkDeviceSize*        pOffsets)
{
    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    bool            found = GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);

    std::vector<const BufferInfo*> buffer_infos(bindingCount, nullptr);
    std::vector<VkBuffer>          buffer_handles(bindingCount, VK_NULL_HANDLE);
    if (found || dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        for (uint32_t i = 0; i < bindingCount; ++i)
        {
            const BufferInfo* buffer_info = object_info_table_.GetBufferInfo(buffer_ids[i]);
            assert(buffer_info);

            buffer_infos[i]   = buffer_info;
            buffer_handles[i] = buffer_info->handle;
        }
    }

    if (found)
    {
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, firstBinding, bindingCount, buffer_handles.data(), pOffsets);
        }
    }

    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, firstBinding, bindingCount, buffer_handles.data(), pOffsets);
    }

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr)
    {
        assert(buffer_infos.size() == bindingCount);
        dc_context->BindVertexBuffers(call_info.index, firstBinding, buffer_infos, pOffsets);
    }
}

void VulkanReplayDumpResourcesBase::FinalizeDispatchRaysCommandBuffer(VkCommandBuffer original_command_buffer)
{
    DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    assert(context);

    if (!context->IsRecording())
    {
        context->FinalizeCommandBuffer();
    }

    UpdateRecordingStatus();
}

void VulkanReplayDumpResourcesBase::OverrideCmdDispatch(const ApiCallInfo& call_info,
                                                        PFN_vkCmdDispatch  func,
                                                        VkCommandBuffer    original_command_buffer,
                                                        uint32_t           groupCountX,
                                                        uint32_t           groupCountY,
                                                        uint32_t           groupCountZ)
{
    assert(IsRecording(original_command_buffer));

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, groupCountX, groupCountY, groupCountZ);
        }
    }

    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    if (dump_resources_before_ && dr_context != nullptr)
    {
        if (dr_context->MustDumpDispatch(call_info.index))
        {
            dr_context->CloneDispatchRaysResources(call_info.index, true, true);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, groupCountX, groupCountY, groupCountZ);
    }

    if (dr_context != nullptr)
    {
        if (dr_context->MustDumpDispatch(call_info.index))
        {
            dr_context->CloneDispatchRaysResources(call_info.index, false, true);
            FinalizeDispatchRaysCommandBuffer(original_command_buffer);
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDispatchIndirect(const ApiCallInfo&        call_info,
                                                                PFN_vkCmdDispatchIndirect func,
                                                                VkCommandBuffer           original_command_buffer,
                                                                const BufferInfo*         buffer_info,
                                                                VkDeviceSize              offset)
{
    assert(IsRecording(original_command_buffer));

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, buffer_info->handle, offset);
        }
    }

    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    if (dump_resources_before_ && dr_context != nullptr)
    {
        if (dr_context->MustDumpDispatch(call_info.index))
        {
            dr_context->CloneDispatchRaysResources(call_info.index, true, true);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, buffer_info->handle, offset);
    }

    if (dr_context != nullptr)
    {
        if (dr_context->MustDumpDispatch(call_info.index))
        {
            dr_context->CloneDispatchRaysResources(call_info.index, false, true);
            FinalizeDispatchRaysCommandBuffer(original_command_buffer);
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdTraceRaysKHR(
    const ApiCallInfo&                                             call_info,
    PFN_vkCmdTraceRaysKHR                                          func,
    VkCommandBuffer                                                original_command_buffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                                       width,
    uint32_t                                                       height,
    uint32_t                                                       depth)
{
    assert(IsRecording(original_command_buffer));

    const VkStridedDeviceAddressRegionKHR* in_pRaygenShaderBindingTable   = pRaygenShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pMissShaderBindingTable     = pMissShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pHitShaderBindingTable      = pHitShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pCallableShaderBindingTable = pCallableShaderBindingTable->GetPointer();

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it,
                 in_pRaygenShaderBindingTable,
                 in_pMissShaderBindingTable,
                 in_pHitShaderBindingTable,
                 in_pCallableShaderBindingTable,
                 width,
                 height,
                 depth);
        }
    }

    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    if (dump_resources_before_ && dr_context != nullptr)
    {
        if (dr_context->MustDumpTraceRays(call_info.index))
        {
            dr_context->CloneDispatchRaysResources(call_info.index, true, false);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer,
             in_pRaygenShaderBindingTable,
             in_pMissShaderBindingTable,
             in_pHitShaderBindingTable,
             in_pCallableShaderBindingTable,
             width,
             height,
             depth);
    }

    if (dr_context != nullptr)
    {
        if (dr_context->MustDumpTraceRays(call_info.index))
        {
            dr_context->CloneDispatchRaysResources(call_info.index, false, false);
            FinalizeDispatchRaysCommandBuffer(original_command_buffer);
        }
    }
}

VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::DrawCallsDumpingContext(
    const std::vector<uint64_t>&              dc_indices,
    const std::vector<std::vector<uint64_t>>& rp_indices,
    const VulkanObjectInfoTable&              object_info_table,
    bool                                      dump_resources_before,
    const std::string&                        dump_resource_path,
    util::ScreenshotFormat                    image_file_format,
    float                                     dump_resources_scale,
    VulkanReplayDumpResourcesJson*            p_dump_json,
    bool                                      dump_vertex_index_buffers) :
    original_command_buffer_info(nullptr),
    current_cb_index(0), dc_indices(dc_indices), RP_indices(rp_indices), active_renderpass(nullptr),
    active_framebuffer(nullptr), bound_pipelines{ nullptr }, current_renderpass(0), current_subpass(0),
    dump_resources_before(dump_resources_before), aux_command_buffer(VK_NULL_HANDLE), aux_fence(VK_NULL_HANDLE),
    device_table(nullptr), instance_table(nullptr), object_info_table(object_info_table),
    replay_device_phys_mem_props(nullptr), dump_resource_path(dump_resource_path), image_file_format(image_file_format),
    dump_resources_scale(dump_resources_scale), p_dump_json(p_dump_json),
    dump_vertex_index_buffers(dump_vertex_index_buffers), currently_bound_vertex_buffers(bound_vertex_buffers.end()),
    currently_bound_index_buffer(bound_index_buffers.end())
{
    must_backup_resources = (dc_indices.size() > 1);

    const size_t n_cmd_buffs = dump_resources_before ? 2 * dc_indices.size() : dc_indices.size();
    command_buffers.resize(n_cmd_buffs, VK_NULL_HANDLE);
}

VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::~DrawCallsDumpingContext()
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

static VkResult CloneImage(const VulkanObjectInfoTable&            object_info_table,
                           const encode::DeviceTable*              device_table,
                           const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                           const ImageInfo*                        image_info,
                           VkImage*                                new_image,
                           VkDeviceMemory*                         new_image_memory)
{
    VkImageCreateInfo ci;
    ci.sType                 = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    ci.pNext                 = nullptr;
    ci.flags                 = VkImageCreateFlags(0);
    ci.imageType             = image_info->type;
    ci.format                = image_info->format;
    ci.extent                = image_info->extent;
    ci.mipLevels             = image_info->level_count;
    ci.arrayLayers           = image_info->layer_count;
    ci.samples               = image_info->sample_count;
    ci.tiling                = image_info->tiling;
    ci.usage                 = image_info->usage | VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    ci.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    ci.queueFamilyIndexCount = image_info->queue_family_index;
    ci.pQueueFamilyIndices   = nullptr;
    ci.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(image_info->parent_id);
    VkDevice          device      = device_info->handle;

    assert(device_table);
    assert(new_image);
    VkResult res = device_table->CreateImage(device, &ci, nullptr, new_image);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("CreateImage failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    VkMemoryRequirements mem_reqs       = {};
    VkMemoryAllocateInfo mem_alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, nullptr };

    device_table->GetImageMemoryRequirements(device, *new_image, &mem_reqs);
    mem_alloc_info.allocationSize = mem_reqs.size;

    assert(replay_device_phys_mem_props);
    uint32_t index =
        GetMemoryTypeIndex(*replay_device_phys_mem_props, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    if (index == std::numeric_limits<uint32_t>::max())
    {
        GFXRECON_LOG_ERROR("%s failed to find an appropriate memory type", __func__)
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    mem_alloc_info.memoryTypeIndex = index;

    assert(new_image_memory);
    res = device_table->AllocateMemory(device, &mem_alloc_info, nullptr, new_image_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateMemory failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->BindImageMemory(device, *new_image, *new_image_memory, 0);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("BindImageMemory failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::ReleaseIndirectDrawParams()
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
        if (dc_params.type == DrawCallTypes::kDrawIndirect &&
            dc_params.dc_params_union.draw_indirect.draw_params != nullptr)
        {
            delete[] dc_params.dc_params_union.draw_indirect.draw_params;
        }
        else if (dc_params.type == DrawCallTypes::kDrawIndexedIndirect &&
                 dc_params.dc_params_union.draw_indirect.draw_indexed_params != nullptr)
        {
            delete[] dc_params.dc_params_union.draw_indirect.draw_indexed_params;
        }

        if (dc_params.type == DrawCallTypes::kDrawIndirect || dc_params.type == DrawCallTypes::kDrawIndexedIndirect)
        {
            if (dc_params.dc_params_union.draw_indirect.new_params_buffer != VK_NULL_HANDLE)
            {
                device_table->DestroyBuffer(
                    device_info->handle, dc_params.dc_params_union.draw_indirect.new_params_buffer, nullptr);
            }

            if (dc_params.dc_params_union.draw_indirect.new_params_memory != VK_NULL_HANDLE)
            {
                device_table->FreeMemory(
                    device_info->handle, dc_params.dc_params_union.draw_indirect.new_params_memory, nullptr);
            }
        }
    }
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::DestroyMutableResourceBackups()
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

VkResult VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::RevertMutableResources(VkQueue queue)
{
    return VK_SUCCESS;

    if (!must_backup_resources || (!mutable_resource_backups.images.size() && !mutable_resource_backups.buffers.size()))
    {
        return VK_SUCCESS;
    }

    assert(aux_command_buffer);

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    VkDevice          device      = device_info->handle;

    device_table->ResetCommandBuffer(aux_command_buffer, 0);

    const VkCommandBufferBeginInfo bi = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
    device_table->BeginCommandBuffer(aux_command_buffer, &bi);

    VkImageMemoryBarrier img_barrier            = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER, nullptr };
    img_barrier.subresourceRange.baseMipLevel   = 0;
    img_barrier.subresourceRange.levelCount     = VK_REMAINING_MIP_LEVELS;
    img_barrier.subresourceRange.baseArrayLayer = 0;
    img_barrier.subresourceRange.layerCount     = VK_REMAINING_ARRAY_LAYERS;

    assert(mutable_resource_backups.images.size() == mutable_resource_backups.original_images.size());
    for (size_t i = 0; i < mutable_resource_backups.images.size(); ++i)
    {
        const VkImageAspectFlags aspect_mask =
            graphics::GetFormatAspectMask(mutable_resource_backups.original_images[i]->format);
        img_barrier.subresourceRange.aspectMask = aspect_mask;

        // Flush gpu caches and transition original image to appropriate layout
        img_barrier.srcAccessMask       = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
        img_barrier.dstAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
        img_barrier.oldLayout           = VK_IMAGE_LAYOUT_GENERAL;
        img_barrier.newLayout           = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        img_barrier.srcQueueFamilyIndex = 0;
        img_barrier.dstQueueFamilyIndex = 0;
        img_barrier.image               = mutable_resource_backups.original_images[i]->handle;

        device_table->CmdPipelineBarrier(aux_command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &img_barrier);

        // Transition back up image to appropriate layout
        img_barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
        img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        img_barrier.image         = mutable_resource_backups.images[i];

        device_table->CmdPipelineBarrier(aux_command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &img_barrier);

        // Copy
        VkImageCopy copy_region                   = {};
        copy_region.srcSubresource.aspectMask     = aspect_mask;
        copy_region.srcSubresource.baseArrayLayer = 0;
        copy_region.srcSubresource.layerCount     = mutable_resource_backups.original_images[i]->layer_count;
        copy_region.srcSubresource.mipLevel       = 0;
        copy_region.dstSubresource                = copy_region.srcSubresource;

        std::vector<VkImageCopy> copy_regions(mutable_resource_backups.original_images[i]->level_count);

        for (uint32_t j = 0; j < mutable_resource_backups.original_images[i]->level_count; ++j)
        {
            copy_region.extent.width  = std::max(1u, (mutable_resource_backups.original_images[i]->extent.width >> j));
            copy_region.extent.height = std::max(1u, (mutable_resource_backups.original_images[i]->extent.height >> j));
            copy_region.extent.depth  = std::max(1u, (mutable_resource_backups.original_images[i]->extent.depth >> j));

            copy_regions[j] = copy_region;
        }

        device_table->CmdCopyImage(aux_command_buffer,
                                   mutable_resource_backups.images[i],
                                   VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                   mutable_resource_backups.original_images[i]->handle,
                                   VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                   copy_regions.size(),
                                   copy_regions.data());
    }

    VkBufferMemoryBarrier buffer_barrier = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER, nullptr };
    VkBufferCopy          copy_region    = { 0, 0 };

    assert(mutable_resource_backups.buffers.size() == mutable_resource_backups.original_buffers.size());
    for (size_t i = 0; i < mutable_resource_backups.buffers.size(); ++i)
    {
        buffer_barrier.srcAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
        buffer_barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        buffer_barrier.buffer        = mutable_resource_backups.original_buffers[i]->handle;

        device_table->CmdPipelineBarrier(aux_command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         1,
                                         &buffer_barrier,
                                         0,
                                         nullptr);

        copy_region.size = mutable_resource_backups.original_buffers[i]->size;
        device_table->CmdCopyBuffer(aux_command_buffer,
                                    mutable_resource_backups.buffers[i],
                                    mutable_resource_backups.original_buffers[i]->handle,
                                    1,
                                    &copy_region);
    }

    device_table->EndCommandBuffer(aux_command_buffer);

    VkSubmitInfo si         = { VK_STRUCTURE_TYPE_SUBMIT_INFO, nullptr };
    si.waitSemaphoreCount   = 0;
    si.pWaitSemaphores      = nullptr;
    si.pWaitDstStageMask    = nullptr;
    si.signalSemaphoreCount = 0;
    si.pSignalSemaphores    = nullptr;
    si.commandBufferCount   = 1;
    si.pCommandBuffers      = &aux_command_buffer;

    VkResult res = device_table->ResetFences(device, 1, &aux_fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("ResetFences failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->QueueSubmit(queue, 1, &si, aux_fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR(
            "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->WaitForFences(device, 1, &aux_fence, VK_TRUE, std::numeric_limits<uint64_t>::max());
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("WaitForFences failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

VkResult VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::BackUpMutableResources(VkQueue queue)
{
    if (!must_backup_resources || (!mutable_resource_backups.images.size() && !mutable_resource_backups.buffers.size()))
    {
        return VK_SUCCESS;
    }

    assert(aux_command_buffer);

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    VkDevice          device      = device_info->handle;

    device_table->ResetCommandBuffer(aux_command_buffer, 0);

    const VkCommandBufferBeginInfo bi = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
    device_table->BeginCommandBuffer(aux_command_buffer, &bi);

    VkImageMemoryBarrier img_barrier            = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER, nullptr };
    img_barrier.subresourceRange.baseMipLevel   = 0;
    img_barrier.subresourceRange.levelCount     = VK_REMAINING_MIP_LEVELS;
    img_barrier.subresourceRange.baseArrayLayer = 0;
    img_barrier.subresourceRange.layerCount     = VK_REMAINING_ARRAY_LAYERS;

    assert(mutable_resource_backups.images.size() == mutable_resource_backups.original_images.size());
    for (size_t i = 0; i < mutable_resource_backups.images.size(); ++i)
    {
        const VkImageAspectFlags aspect_mask =
            graphics::GetFormatAspectMask(mutable_resource_backups.original_images[i]->format);
        img_barrier.subresourceRange.aspectMask = aspect_mask;

        // Flush gpu caches and transition original image to appropriate layout
        img_barrier.srcAccessMask       = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
        img_barrier.dstAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.oldLayout           = VK_IMAGE_LAYOUT_GENERAL;
        img_barrier.newLayout           = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        img_barrier.srcQueueFamilyIndex = 0;
        img_barrier.dstQueueFamilyIndex = 0;
        img_barrier.image               = mutable_resource_backups.original_images[i]->handle;

        device_table->CmdPipelineBarrier(aux_command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &img_barrier);

        // Transition back up image to appropriate layout
        img_barrier.srcAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
        img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        img_barrier.oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
        img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        img_barrier.image         = mutable_resource_backups.images[i];

        device_table->CmdPipelineBarrier(aux_command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &img_barrier);

        // Copy
        VkImageCopy copy_region                   = {};
        copy_region.srcSubresource.aspectMask     = aspect_mask;
        copy_region.srcSubresource.baseArrayLayer = 0;
        copy_region.srcSubresource.layerCount     = mutable_resource_backups.original_images[i]->layer_count;
        copy_region.srcSubresource.mipLevel       = 0;
        copy_region.dstSubresource                = copy_region.srcSubresource;

        std::vector<VkImageCopy> copy_regions(mutable_resource_backups.original_images[i]->level_count);

        for (uint32_t j = 0; j < mutable_resource_backups.original_images[i]->level_count; ++j)
        {
            copy_region.extent.width  = std::max(1u, (mutable_resource_backups.original_images[i]->extent.width >> j));
            copy_region.extent.height = std::max(1u, (mutable_resource_backups.original_images[i]->extent.height >> j));
            copy_region.extent.depth  = std::max(1u, (mutable_resource_backups.original_images[i]->extent.depth >> j));

            copy_regions[j] = copy_region;
        }

        device_table->CmdCopyImage(aux_command_buffer,
                                   mutable_resource_backups.original_images[i]->handle,
                                   VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                   mutable_resource_backups.images[i],
                                   VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                   copy_regions.size(),
                                   copy_regions.data());
    }

    VkBufferMemoryBarrier buffer_barrier = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER, nullptr };
    VkBufferCopy          copy_region    = { 0, 0 };

    assert(mutable_resource_backups.buffers.size() == mutable_resource_backups.original_buffers.size());
    for (size_t i = 0; i < mutable_resource_backups.buffers.size(); ++i)
    {
        buffer_barrier.srcAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
        buffer_barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        buffer_barrier.buffer        = mutable_resource_backups.original_buffers[i]->handle;

        device_table->CmdPipelineBarrier(aux_command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         1,
                                         &buffer_barrier,
                                         0,
                                         nullptr);

        copy_region.size = mutable_resource_backups.original_buffers[i]->size;
        device_table->CmdCopyBuffer(aux_command_buffer,
                                    mutable_resource_backups.original_buffers[i]->handle,
                                    mutable_resource_backups.buffers[i],
                                    1,
                                    &copy_region);
    }

    device_table->EndCommandBuffer(aux_command_buffer);

    VkSubmitInfo si         = { VK_STRUCTURE_TYPE_SUBMIT_INFO, nullptr };
    si.waitSemaphoreCount   = 0;
    si.pWaitSemaphores      = nullptr;
    si.pWaitDstStageMask    = nullptr;
    si.signalSemaphoreCount = 0;
    si.pSignalSemaphores    = nullptr;
    si.commandBufferCount   = 1;
    si.pCommandBuffers      = &aux_command_buffer;

    VkResult res = device_table->ResetFences(device, 1, &aux_fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("ResetFences failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->QueueSubmit(queue, 1, &si, aux_fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR(
            "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->WaitForFences(device, 1, &aux_fence, VK_TRUE, std::numeric_limits<uint64_t>::max());
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("WaitForFences failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::RenderPassSubpassPair
VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::GetRenderPassIndex(uint64_t dc_index) const
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

size_t VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::CmdBufToDCVectorIndex(size_t cmd_buf_index) const
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

uint32_t VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::GetDrawCallActiveCommandBuffers(cmd_buf_it& first,
                                                                                                 cmd_buf_it& last) const
{
    assert(current_cb_index <= command_buffers.size());

    first = command_buffers.begin() + current_cb_index;
    last  = command_buffers.end();

    return current_cb_index;
}

bool VulkanReplayDumpResourcesBase::IsRecording(VkCommandBuffer original_command_buffer) const
{
    if (recording_)
    {
        const DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
        if (dc_context)
        {
            if (dc_context->IsRecording())
            {
                return true;
            }
        }

        const DispatchTraceRaysDumpingContext* dr_context =
            FindDispatchRaysCommandBufferContext(original_command_buffer);
        if (dr_context != nullptr)
        {
            if (dr_context->IsRecording())
            {
                return true;
            }
        }
    }

    return false;
}

VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::DispatchTraceRaysDumpingContext(
    const std::vector<uint64_t>&   dispatch_indices,
    const std::vector<uint64_t>&   trace_rays_indices,
    const VulkanObjectInfoTable&   object_info_table,
    bool                           dump_resources_before,
    const std::string&             dump_resource_path,
    util::ScreenshotFormat         image_file_format,
    float                          dump_resources_scale,
    VulkanReplayDumpResourcesJson* p_dump_json) :
    original_command_buffer_info(nullptr),
    DR_command_buffer(VK_NULL_HANDLE), dispatch_indices(dispatch_indices),
    trace_rays_indices(trace_rays_indices), bound_pipelines{ nullptr }, dump_resources_before(dump_resources_before),
    dump_resource_path(dump_resource_path), image_file_format(image_file_format),
    dump_resources_scale(dump_resources_scale), device_table(nullptr), instance_table(nullptr),
    object_info_table(object_info_table), replay_device_phys_mem_props(nullptr), current_dispatch_index(0),
    current_trace_rays_index(0), p_dump_json(p_dump_json)
{}

VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::~DispatchTraceRaysDumpingContext()
{
    if (original_command_buffer_info)
    {
        if (DR_command_buffer != VK_NULL_HANDLE)
        {
            const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
            if (device_info)
            {
                DestroyMutableResourcesClones();

                VkDevice device = device_info->handle;

                assert(device_table);

                const CommandPoolInfo* pool_info =
                    object_info_table.GetCommandPoolInfo(original_command_buffer_info->pool_id);
                assert(pool_info);

                device_table->FreeCommandBuffers(device, pool_info->handle, 1, &DR_command_buffer);
                DR_command_buffer = VK_NULL_HANDLE;
            }
        }
    }
}

VkResult VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::CloneCommandBuffer(
    const CommandBufferInfo*     orig_cmd_buf_info,
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

    VkResult res = dev_table->AllocateCommandBuffers(dev_info->handle, &ai, &DR_command_buffer);

    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateCommandBuffers failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    const VkCommandBufferBeginInfo bi{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
    dev_table->BeginCommandBuffer(DR_command_buffer, &bi);

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

    return VK_SUCCESS;
}

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::BindPipeline(VkPipelineBindPoint bind_point,
                                                                                  const PipelineInfo* pipeline)
{
    PipelineBindPoints point = VkPipelineBindPointToPipelineBindPoint(bind_point);
    bound_pipelines[point]   = pipeline;
}

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::BindDescriptorSets(
    VkPipelineBindPoint                          pipeline_bind_point,
    uint32_t                                     first_set,
    const std::vector<const DescriptorSetInfo*>& descriptor_sets_infos,
    uint32_t                                     dynamicOffsetCount,
    const uint32_t*                              pDynamicOffsets)
{
    PipelineBindPoints bind_point = VkPipelineBindPointToPipelineBindPoint(pipeline_bind_point);

    for (size_t i = 0; i < descriptor_sets_infos.size(); ++i)
    {
        for (const auto& binding : descriptor_sets_infos[i]->descriptors)
        {
            switch (binding.second.desc_type)
            {
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                {
                    const ImageViewInfo* img_view_info =
                        object_info_table.GetImageViewInfo(binding.second.image_info.image_view_id);
                    assert(img_view_info);

                    const ImageInfo* img_info = object_info_table.GetImageInfo(img_view_info->image_id);
                    assert(img_info);

                    bound_descriptor_sets[bind_point][first_set + i].image_infos[binding.first] = img_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                {
                    const BufferInfo* buffer_info =
                        object_info_table.GetBufferInfo(binding.second.buffer_info.buffer_id);
                    assert(buffer_info);

                    bound_descriptor_sets[bind_point][first_set + i].buffer_infos[binding.first] = buffer_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    const BufferViewInfo* buffer_view_info =
                        object_info_table.GetBufferViewInfo(binding.second.texel_buffer_view);
                    assert(buffer_view_info);

                    const BufferInfo* buffer_info = object_info_table.GetBufferInfo(buffer_view_info->buffer_id);
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
                    break;

                default:
                    GFXRECON_LOG_WARNING_ONCE("%s(): Descriptor type (%s) not handled",
                                              __func__,
                                              util::ToString<VkDescriptorType>(binding.second.desc_type).c_str());
                    break;
            }
        }
    }
}

bool VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::MustDumpDispatch(uint64_t index) const
{
    // Indices should be sorted
    if (!IsInsideRange(dispatch_indices, index))
    {
        return false;
    }

    for (size_t i = dump_resources_before ? current_dispatch_index / 2 : current_dispatch_index;
         i < dispatch_indices.size();
         ++i)
    {
        if (index == dispatch_indices[i])
        {
            return true;
        }
        else if (index > dispatch_indices[i])
        {
            // Indices should be sorted
            return false;
        }
    }

    return false;
}

bool VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::MustDumpTraceRays(uint64_t index) const
{
    // Indices should be sorted
    if (!IsInsideRange(trace_rays_indices, index))
    {
        return false;
    }

    for (size_t i = dump_resources_before ? current_trace_rays_index / 2 : current_trace_rays_index;
         i < trace_rays_indices.size();
         ++i)
    {
        if (index == trace_rays_indices[i])
        {
            return true;
        }
        else if (index > trace_rays_indices[i])
        {
            // Indices should be sorted
            return false;
        }
    }

    return false;
}

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::CopyBufferResource(
    const BufferInfo* src_buffer_info, VkBuffer dst_buffer)
{
    assert(src_buffer_info);
    assert(dst_buffer != VK_NULL_HANDLE);
}

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::CopyImageResource(const ImageInfo* src_image_info,
                                                                                       VkImage          dst_image)
{
    assert(src_image_info != nullptr);
    assert(dst_image != VK_NULL_HANDLE);

    VkImageLayout old_layout;
    assert(original_command_buffer_info != nullptr);
    const auto img_layout_entry = original_command_buffer_info->image_layout_barriers.find(src_image_info->capture_id);
    if (img_layout_entry != original_command_buffer_info->image_layout_barriers.end())
    {
        old_layout = img_layout_entry->second;
    }
    else
    {
        old_layout = VK_IMAGE_LAYOUT_GENERAL;
    }

    // Make sure any potential writes are complete and transition image to TRANSFER_SRC_OPTIMAL layout
    VkImageMemoryBarrier img_barrier;
    img_barrier.sType               = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    img_barrier.pNext               = nullptr;
    img_barrier.srcAccessMask       = VK_ACCESS_MEMORY_WRITE_BIT;
    img_barrier.dstAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
    img_barrier.oldLayout           = old_layout;
    img_barrier.newLayout           = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    img_barrier.srcQueueFamilyIndex = src_image_info->queue_family_index;
    img_barrier.dstQueueFamilyIndex = src_image_info->queue_family_index;
    img_barrier.image               = src_image_info->handle;
    img_barrier.subresourceRange    = {
        graphics::GetFormatAspectMask(src_image_info->format), 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS
    };

    assert(device_table != nullptr);
    device_table->CmdPipelineBarrier(DR_command_buffer,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VkDependencyFlags(0),
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &img_barrier);

    // Transition destination image
    img_barrier.srcAccessMask = VK_ACCESS_NONE;
    img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    img_barrier.oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
    img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    img_barrier.image         = dst_image;

    device_table->CmdPipelineBarrier(DR_command_buffer,
                                     VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VkDependencyFlags(0),
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &img_barrier);

    assert(src_image_info->level_count);
    assert(src_image_info->layer_count);

    std::vector<VkImageCopy> copies(src_image_info->level_count, VkImageCopy());
    VkImageCopy              copy;
    copy.srcSubresource.aspectMask     = graphics::GetFormatAspectMask(src_image_info->format);
    copy.srcSubresource.baseArrayLayer = 0;
    copy.srcSubresource.layerCount     = src_image_info->layer_count;
    copy.srcOffset.x                   = 0;
    copy.srcOffset.y                   = 0;
    copy.srcOffset.z                   = 0;

    copy.dstSubresource.aspectMask     = graphics::GetFormatAspectMask(src_image_info->format);
    copy.dstSubresource.baseArrayLayer = 0;
    copy.dstSubresource.layerCount     = src_image_info->layer_count;
    copy.dstOffset.x                   = 0;
    copy.dstOffset.y                   = 0;
    copy.dstOffset.z                   = 0;

    for (uint32_t i = 0; i < src_image_info->level_count; ++i)
    {
        copy.srcSubresource.mipLevel = i;
        copy.dstSubresource.mipLevel = i;
        copy.extent.width            = (src_image_info->extent.width << i);
        copy.extent.height           = (src_image_info->extent.height << i);
        copy.extent.depth            = (src_image_info->extent.depth << i);

        copies[i] = copy;
    }

    device_table->CmdCopyImage(DR_command_buffer,
                               src_image_info->handle,
                               VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                               dst_image,
                               VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                               copies.size(),
                               copies.data());

    // Wait for transfer and transition source image back to previous layout
    img_barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
    img_barrier.dstAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    img_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    img_barrier.newLayout     = old_layout;
    img_barrier.image         = src_image_info->handle;

    device_table->CmdPipelineBarrier(DR_command_buffer,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VkDependencyFlags(0),
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &img_barrier);
}

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::CloneDispatchRaysResources(uint64_t index,
                                                                                                bool cloning_before_cmd,
                                                                                                bool is_dispatch)
{
    assert(IsRecording());
    assert(
        (is_dispatch &&
         index == dispatch_indices[(dump_resources_before ? (current_dispatch_index / 2) : current_dispatch_index)]) ||
        (!is_dispatch &&
         index ==
             trace_rays_indices[(dump_resources_before ? (current_trace_rays_index / 2) : current_trace_rays_index)]));

    // Scan for mutable resources in the bound pipeline
    const PipelineBindPoints bind_point = is_dispatch ? kBindPoint_compute : kBindPoint_ray_tracing;
    const PipelineInfo*      pipeline   = bound_pipelines[bind_point];
    assert(pipeline != nullptr);

    for (const auto& shader : pipeline->shaders)
    {
        for (const auto& desc_set : shader.second.used_descriptors_info)
        {
            const uint32_t set = desc_set.first;
            for (const auto& desc_binding : desc_set.second)
            {
                // Search for resources that are not marked as read only
                if (desc_binding.second.accessed && !desc_binding.second.readonly)
                {
                    const uint32_t binding = desc_binding.first;

                    switch (desc_binding.second.type)
                    {
                        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                        {
                            assert(bound_descriptor_sets[bind_point].find(set) !=
                                   bound_descriptor_sets[bind_point].end());

                            assert(bound_descriptor_sets[bind_point][set].image_infos.find(binding) !=
                                   bound_descriptor_sets[bind_point][set].image_infos.end());

                            const ImageInfo* img_info = bound_descriptor_sets[bind_point][set].image_infos[binding];
                            assert(img_info);

                            VkImage*        new_img_ptr        = nullptr;
                            VkDeviceMemory* new_img_memory_ptr = nullptr;

                            if (!cloning_before_cmd)
                            {
                                mutable_resources_clones.insert({ index, DumpableResourceBackup() });
                                mutable_resources_clones[index].original_images.push_back(img_info);
                                mutable_resources_clones[index].image_desc_set_binding_pair.push_back(
                                    std::make_pair(set, binding));

                                new_img_ptr = &*(mutable_resources_clones[index].images.insert(
                                    mutable_resources_clones[index].images.end(), VK_NULL_HANDLE));

                                new_img_memory_ptr = &*(mutable_resources_clones[index].image_memories.insert(
                                    mutable_resources_clones[index].image_memories.end(), VK_NULL_HANDLE));
                            }
                            else
                            {
                                mutable_resources_clones_before.insert({ index, DumpableResourceBackup() });
                                mutable_resources_clones_before[index].original_images.push_back(img_info);
                                mutable_resources_clones_before[index].image_desc_set_binding_pair.push_back(
                                    std::make_pair(set, binding));

                                new_img_ptr = &*(mutable_resources_clones_before[index].images.insert(
                                    mutable_resources_clones_before[index].images.end(), VK_NULL_HANDLE));

                                new_img_memory_ptr = &*(mutable_resources_clones_before[index].image_memories.insert(
                                    mutable_resources_clones_before[index].image_memories.end(), VK_NULL_HANDLE));
                            }

                            assert(new_img_ptr != nullptr);
                            assert(new_img_memory_ptr != nullptr);

                            CloneImage(object_info_table,
                                       device_table,
                                       replay_device_phys_mem_props,
                                       img_info,
                                       new_img_ptr,
                                       new_img_memory_ptr);

                            CopyImageResource(img_info, *new_img_ptr);
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                        {
                            assert(bound_descriptor_sets[bind_point].find(set) !=
                                   bound_descriptor_sets[bind_point].end());

                            assert(bound_descriptor_sets[bind_point][set].buffer_infos.find(binding) !=
                                   bound_descriptor_sets[bind_point][set].buffer_infos.end());

                            const BufferInfo* buf_info = bound_descriptor_sets[bind_point][set].buffer_infos[binding];
                            assert(buf_info);

                            VkBuffer*       new_buf_ptr        = nullptr;
                            VkDeviceMemory* new_buf_memory_ptr = nullptr;

                            if (!cloning_before_cmd)
                            {
                                mutable_resources_clones.insert({ index, DumpableResourceBackup() });
                                mutable_resources_clones[index].original_buffers.push_back(buf_info);
                                mutable_resources_clones[index].buffer_desc_set_binding_pair.push_back(
                                    std::make_pair(set, binding));

                                new_buf_ptr = &*(mutable_resources_clones[index].buffers.insert(
                                    mutable_resources_clones[index].buffers.end(), VK_NULL_HANDLE));

                                new_buf_memory_ptr = &*(mutable_resources_clones[index].buffer_memories.insert(
                                    mutable_resources_clones[index].buffer_memories.end(), VK_NULL_HANDLE));
                            }
                            else
                            {
                                mutable_resources_clones_before.insert({ index, DumpableResourceBackup() });
                                mutable_resources_clones_before[index].original_buffers.push_back(buf_info);
                                mutable_resources_clones_before[index].buffer_desc_set_binding_pair.push_back(
                                    std::make_pair(set, binding));

                                new_buf_ptr = &*(mutable_resources_clones_before[index].buffers.insert(
                                    mutable_resources_clones_before[index].buffers.end(), VK_NULL_HANDLE));

                                new_buf_memory_ptr = &*(mutable_resources_clones_before[index].buffer_memories.insert(
                                    mutable_resources_clones_before[index].buffer_memories.end(), VK_NULL_HANDLE));
                            }

                            assert(new_buf_ptr != nullptr);
                            assert(new_buf_memory_ptr != nullptr);

                            CloneBuffer(object_info_table,
                                        device_table,
                                        replay_device_phys_mem_props,
                                        buf_info,
                                        new_buf_ptr,
                                        new_buf_memory_ptr);

                            CopyBufferResource(buf_info, *new_buf_ptr);
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
                            break;

                        default:
                            GFXRECON_LOG_WARNING_ONCE(
                                "%s(): Descriptor type (%s) not handled",
                                __func__,
                                util::ToString<VkDescriptorType>(desc_binding.second.type).c_str());
                            break;
                    }
                }
            }
        }
    }

    if (is_dispatch)
    {
        ++current_dispatch_index;
    }
    else
    {
        ++current_trace_rays_index;
    }
}

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::DestroyMutableResourcesClones()
{
    for (auto& dr_entry : mutable_resources_clones)
    {
        for (size_t i = 0; i < dr_entry.second.original_images.size(); ++i)
        {
            const DeviceInfo* device_info =
                object_info_table.GetDeviceInfo(dr_entry.second.original_images[i]->parent_id);
            VkDevice device = device_info->handle;

            device_table->FreeMemory(device, dr_entry.second.image_memories[i], nullptr);
            device_table->DestroyImage(device, dr_entry.second.images[i], nullptr);
        }

        for (size_t i = 0; i < dr_entry.second.original_buffers.size(); ++i)
        {
            const DeviceInfo* device_info =
                object_info_table.GetDeviceInfo(dr_entry.second.original_buffers[i]->parent_id);
            VkDevice device = device_info->handle;

            device_table->FreeMemory(device, dr_entry.second.buffer_memories[i], nullptr);
            device_table->DestroyBuffer(device, dr_entry.second.buffers[i], nullptr);
        }
    }

    for (auto& dr_entry : mutable_resources_clones_before)
    {
        for (size_t i = 0; i < dr_entry.second.original_images.size(); ++i)
        {
            const DeviceInfo* device_info =
                object_info_table.GetDeviceInfo(dr_entry.second.original_images[i]->parent_id);
            VkDevice device = device_info->handle;

            device_table->FreeMemory(device, dr_entry.second.image_memories[i], nullptr);
            device_table->DestroyImage(device, dr_entry.second.images[i], nullptr);
        }

        for (size_t i = 0; i < dr_entry.second.original_buffers.size(); ++i)
        {
            const DeviceInfo* device_info =
                object_info_table.GetDeviceInfo(dr_entry.second.original_buffers[i]->parent_id);
            VkDevice device = device_info->handle;

            device_table->FreeMemory(device, dr_entry.second.buffer_memories[i], nullptr);
            device_table->DestroyBuffer(device, dr_entry.second.buffers[i], nullptr);
        }
    }
}

VkResult VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::DumpDispatchRaysMutableResources(
    VkQueue queue, uint64_t qs_index, uint64_t bcb_index, const VkSubmitInfo& submit_info, VkFence fence)
{
    VkSubmitInfo si;
    si.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    si.pNext                = nullptr;
    si.waitSemaphoreCount   = submit_info.waitSemaphoreCount;
    si.pWaitSemaphores      = submit_info.pWaitSemaphores;
    si.pWaitDstStageMask    = submit_info.pWaitDstStageMask;
    si.commandBufferCount   = 1;
    si.pCommandBuffers      = &DR_command_buffer;
    si.signalSemaphoreCount = submit_info.signalSemaphoreCount;
    si.pSignalSemaphores    = submit_info.pSignalSemaphores;

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    VkResult res;

    const VkFenceCreateInfo ci               = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
    VkFence                 submission_fence = VK_NULL_HANDLE;
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
    assert(res == VK_SUCCESS);
    if (res != VK_SUCCESS)
    {
        device_table->DestroyFence(device_info->handle, submission_fence, nullptr);
        GFXRECON_LOG_ERROR(
            "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    // Wait
    res = device_table->WaitForFences(device_info->handle, 1, &submission_fence, VK_TRUE, ~0UL);
    assert(res == VK_SUCCESS);
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

    for (auto disp_index : dispatch_indices)
    {
        DumpMutableResources(bcb_index, disp_index, qs_index, true);
    }

    for (auto tr_index : trace_rays_indices)
    {
        DumpMutableResources(bcb_index, tr_index, qs_index, false);
    }

    return VK_SUCCESS;
}

std::string VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::GenerateImageFilename(
    VkFormat format, bool is_dispatch, uint64_t index, uint32_t desc_set, uint32_t desc_binding, bool before_cmd) const
{
    util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(format);

    std::vector<VkImageAspectFlagBits> aspects;
    bool                               combined_depth_stencil;
    graphics::GetFormatAspects(format, &aspects, &combined_depth_stencil);

    std::string aspect_str_whole(util::ToString<VkImageAspectFlagBits>(aspects[0]));
    std::string aspect_str(aspect_str_whole.begin() + 16, aspect_str_whole.end() - 4);

    std::stringstream filename;
    if (before_cmd)
    {
        if (VkFormatToImageWriterDataFormat(format) != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
        {
            filename << (is_dispatch ? "Dispatch_" : "TraceRays_") << "before_" << index << "_set_" << desc_set
                     << "_binding_" << desc_binding << "_" << util::ToString<VkFormat>(format).c_str() << "_aspect_"
                     << aspect_str << util::ScreenshotFormatToCStr(image_file_format);
        }
        else
        {
            filename << (is_dispatch ? "Dispatch_" : "TraceRays_") << "before_" << index << "_set_" << desc_set
                     << "_binding_" << desc_binding << "_aspect_" << aspect_str << util::ToString<VkFormat>(format)
                     << ".bin";
        }
    }
    else
    {
        if (VkFormatToImageWriterDataFormat(format) != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
        {
            filename << (is_dispatch ? "Dispatch_" : "TraceRays_") << (dump_resources_before ? "after_" : "") << index
                     << "_set_" << desc_set << "_binding_" << desc_binding << "_"
                     << util::ToString<VkFormat>(format).c_str() << "_aspect_" << aspect_str
                     << util::ScreenshotFormatToCStr(image_file_format);
        }
        else
        {
            filename << (is_dispatch ? "Dispatch_" : "TraceRays_") << (dump_resources_before ? "after_" : "") << index
                     << "_set_" << desc_set << "_binding_" << desc_binding << "_aspect_" << aspect_str
                     << util::ToString<VkFormat>(format).c_str() << ".bin";
        }
    }

    std::filesystem::path filedirname(dump_resource_path);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

std::string VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::GenerateBufferFilename(
    bool is_dispatch, uint64_t index, uint32_t desc_set, uint32_t desc_binding, bool before_cmd) const
{
    std::stringstream filename;

    if (before_cmd)
    {
        filename << (is_dispatch ? "Dispatch_" : "TraceRays_") << "before_" << index << "_set_" << desc_set
                 << "_binding_" << desc_binding << "_buffer.bin";
    }
    else
    {
        filename << (is_dispatch ? "Dispatch_" : "TraceRays_") << (dump_resources_before ? "after_" : "") << index
                 << "_set_" << desc_set << "_binding_" << desc_binding << "_buffer.bin";
    }

    std::filesystem::path filedirname(dump_resource_path);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

VkResult VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::DumpMutableResources(uint64_t bcb_index,
                                                                                              uint64_t index,
                                                                                              uint64_t qs_index,
                                                                                              bool     is_dispatch)
{
    if (!mutable_resources_clones.size())
    {
        assert(!mutable_resources_clones_before.size());
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

    if (dump_resources_before)
    {
        assert(mutable_resources_clones_before.size());
        assert(mutable_resources_clones_before.find(index) != mutable_resources_clones_before.end());

        p_dump_json->VulkanReplayDumpResourcesJsonBlockStart();
        p_dump_json->VulkanReplayDumpResourcesJsonData(is_dispatch ? "DispatchIndex" : "TraceRaysIndex", index);
        p_dump_json->VulkanReplayDumpResourcesJsonData("BeginCommandBufferIndex", bcb_index);
        p_dump_json->VulkanReplayDumpResourcesJsonData("QueueSubmitIndex", qs_index);

        // Dump images
        for (size_t i = 0; i < mutable_resources_clones_before[index].original_images.size(); ++i)
        {
            const ImageInfo*      image_info = mutable_resources_clones_before[index].original_images[i];
            std::vector<uint8_t>  data;
            std::vector<uint64_t> subresource_offsets;
            std::vector<uint64_t> subresource_sizes;
            bool                  scaling_supported;

            VkResult res = resource_util.ReadFromImageResourceStaging(mutable_resources_clones_before[index].images[i],
                                                                      image_info->format,
                                                                      image_info->type,
                                                                      image_info->extent,
                                                                      image_info->level_count,
                                                                      image_info->layer_count,
                                                                      image_info->tiling,
                                                                      image_info->sample_count,
                                                                      VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                                                      0,
                                                                      VK_IMAGE_ASPECT_COLOR_BIT,
                                                                      data,
                                                                      subresource_offsets,
                                                                      subresource_sizes,
                                                                      scaling_supported,
                                                                      false,
                                                                      dump_resources_scale);

            if (res != VK_SUCCESS)
            {
                return res;
            }

            uint32_t    desc_set = mutable_resources_clones_before[index].image_desc_set_binding_pair[i].first;
            uint32_t    binding  = mutable_resources_clones_before[index].image_desc_set_binding_pair[i].second;
            std::string filename =
                GenerateImageFilename(image_info->format, is_dispatch, index, desc_set, binding, true);
            util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(image_info->format);
            p_dump_json->VulkanReplayDumpResourcesJsonData(("RenderTargetImage_" + std::to_string(i)).c_str(),
                                                           filename);
            if (output_image_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
            {
                VkExtent3D scaled_extent;
                if (scaling_supported)
                {
                    scaled_extent.width  = image_info->extent.width * dump_resources_scale;
                    scaled_extent.height = image_info->extent.height * dump_resources_scale;
                    scaled_extent.depth  = image_info->extent.depth;
                }
                else
                {
                    scaled_extent = image_info->extent;
                }

                const uint32_t texel_size =
                    vkuFormatElementSizeWithAspect(image_info->format, VK_IMAGE_ASPECT_COLOR_BIT);
                const uint32_t stride = texel_size * scaled_extent.width;

                if (image_file_format == util::ScreenshotFormat::kBmp)
                {
                    util::imagewriter::WriteBmpImage(filename,
                                                     scaled_extent.width,
                                                     scaled_extent.height,
                                                     subresource_sizes[0],
                                                     data.data(),
                                                     stride,
                                                     output_image_format);
                }
                else
                {
                    util::imagewriter::WritePngImage(filename,
                                                     scaled_extent.width,
                                                     scaled_extent.height,
                                                     subresource_sizes[0],
                                                     data.data(),
                                                     stride,
                                                     output_image_format);
                }
            }
            else
            {
                util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
            }
        }

        // Dump buffers
        for (size_t i = 0; i < mutable_resources_clones_before[index].original_buffers.size(); ++i)
        {
            const BufferInfo*    buffer_info = mutable_resources_clones_before[index].original_buffers[i];
            std::vector<uint8_t> data;

            VkResult res = resource_util.ReadFromBufferResource(mutable_resources_clones_before[index].buffers[i],
                                                                buffer_info->size,
                                                                0,
                                                                buffer_info->queue_family_index,
                                                                data);

            if (res != VK_SUCCESS)
            {
                return res;
            }

            uint32_t    desc_set = mutable_resources_clones_before[index].buffer_desc_set_binding_pair[i].first;
            uint32_t    binding  = mutable_resources_clones_before[index].buffer_desc_set_binding_pair[i].second;
            std::string filename = GenerateBufferFilename(is_dispatch, index, desc_set, binding, true);

            util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
        }
        p_dump_json->VulkanReplayDumpResourcesJsonBlockEnd();
    }

    assert(mutable_resources_clones.find(index) != mutable_resources_clones.end());

    p_dump_json->VulkanReplayDumpResourcesJsonBlockStart();
    p_dump_json->VulkanReplayDumpResourcesJsonData("BeginCommandBufferIndex", bcb_index);
    p_dump_json->VulkanReplayDumpResourcesJsonData(is_dispatch ? "DispatchIndex" : "TraceRaysIndex", index);
    p_dump_json->VulkanReplayDumpResourcesJsonData("QueueSubmitIndex", qs_index);

    for (size_t i = 0; i < mutable_resources_clones[index].original_images.size(); ++i)
    {
        const ImageInfo*      image_info = mutable_resources_clones[index].original_images[i];
        std::vector<uint8_t>  data;
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;
        bool                  scaling_supported;

        VkResult res = resource_util.ReadFromImageResourceStaging(mutable_resources_clones[index].images[i],
                                                                  image_info->format,
                                                                  image_info->type,
                                                                  image_info->extent,
                                                                  image_info->level_count,
                                                                  image_info->layer_count,
                                                                  image_info->tiling,
                                                                  image_info->sample_count,
                                                                  VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                                                  0,
                                                                  VK_IMAGE_ASPECT_COLOR_BIT,
                                                                  data,
                                                                  subresource_offsets,
                                                                  subresource_sizes,
                                                                  scaling_supported,
                                                                  false,
                                                                  dump_resources_scale);

        if (res != VK_SUCCESS)
        {
            return res;
        }

        uint32_t    desc_set = mutable_resources_clones[index].image_desc_set_binding_pair[i].first;
        uint32_t    binding  = mutable_resources_clones[index].image_desc_set_binding_pair[i].second;
        std::string filename = GenerateImageFilename(image_info->format, is_dispatch, index, desc_set, binding, false);
        util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(image_info->format);
        p_dump_json->VulkanReplayDumpResourcesJsonData(("RenderTargetImage_" + std::to_string(i)).c_str(), filename);
        if (output_image_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
        {
            VkExtent3D scaled_extent;
            if (scaling_supported)
            {
                scaled_extent.width  = image_info->extent.width * dump_resources_scale;
                scaled_extent.height = image_info->extent.height * dump_resources_scale;
                scaled_extent.depth  = image_info->extent.depth;
            }
            else
            {
                scaled_extent = image_info->extent;
            }

            const uint32_t texel_size = vkuFormatElementSizeWithAspect(image_info->format, VK_IMAGE_ASPECT_COLOR_BIT);
            const uint32_t stride     = texel_size * scaled_extent.width;

            if (image_file_format == util::ScreenshotFormat::kBmp)
            {
                util::imagewriter::WriteBmpImage(filename,
                                                 scaled_extent.width,
                                                 scaled_extent.height,
                                                 subresource_sizes[0],
                                                 data.data(),
                                                 stride,
                                                 output_image_format);
            }
            else
            {
                util::imagewriter::WritePngImage(filename,
                                                 scaled_extent.width,
                                                 scaled_extent.height,
                                                 subresource_sizes[0],
                                                 data.data(),
                                                 stride,
                                                 output_image_format);
            }
        }
        else
        {
            util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
        }
    }

    // Dump buffers
    for (size_t i = 0; i < mutable_resources_clones[index].original_buffers.size(); ++i)
    {
        const BufferInfo*    buffer_info = mutable_resources_clones[index].original_buffers[i];
        std::vector<uint8_t> data;

        VkResult res = resource_util.ReadFromBufferResource(
            mutable_resources_clones[index].buffers[i], buffer_info->size, 0, buffer_info->queue_family_index, data);

        if (res != VK_SUCCESS)
        {
            return res;
        }

        uint32_t    desc_set = mutable_resources_clones[index].buffer_desc_set_binding_pair[i].first;
        uint32_t    binding  = mutable_resources_clones[index].buffer_desc_set_binding_pair[i].second;
        std::string filename = GenerateBufferFilename(is_dispatch, index, desc_set, binding, false);

        util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
    }
    p_dump_json->VulkanReplayDumpResourcesJsonBlockEnd();

    return VK_SUCCESS;
}

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::FinalizeCommandBuffer()
{
    assert((dump_resources_before ? (current_dispatch_index / 2) : current_dispatch_index) == dispatch_indices.size() &&
           (dump_resources_before ? (current_trace_rays_index / 2) : current_trace_rays_index) ==
               trace_rays_indices.size());
    assert(DR_command_buffer != VK_NULL_HANDLE);

    device_table->EndCommandBuffer(DR_command_buffer);
}

bool VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::IsRecording() const
{
    if (!dump_resources_before)
    {
        return current_dispatch_index < dispatch_indices.size() || current_trace_rays_index < trace_rays_indices.size();
    }
    else
    {
        return ((current_dispatch_index / 2) < dispatch_indices.size()) ||
               ((current_trace_rays_index / 2) < trace_rays_indices.size());
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
