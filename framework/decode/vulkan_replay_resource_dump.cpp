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
#include "generated/generated_vulkan_struct_decoders.h"
#include "graphics/vulkan_resources_util.h"
#include "util/image_writer.h"
#include "util/buffer_writer.h"
#include "vulkan_replay_resource_dump.h"

#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <sstream>
#if !defined(WIN32)
#include <dirent.h>
#endif

//#define TIME_DUMPING
#define DELETE_STALE_DUMP_FILES

#ifdef TIME_DUMPING
#include <sys/time.h>
#endif

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
            GFXRECON_LOG_ERROR("%s() failed to handle format: %s", __func__, util::ToString<VkFormat>(format).c_str());
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

VulkanReplayResourceDumpBase::VulkanReplayResourceDumpBase(const VulkanReplayOptions&   options,
                                                           const VulkanObjectInfoTable& object_info_table) :
    QueueSubmit_indices_(options.QueueSubmit_Indices),
    recording_(false), dump_resources_before_(options.dump_resources_before), isolate_draw_call_(options.isolate_draw),
    object_info_table_(object_info_table), enabled_(options.BeginCommandBuffer_Indices.size()),
#if defined(__ANDROID__)
    dump_resource_path_("/storage/emulated/0/Download/dump_resources/")
#else
    dump_resource_path_("./")
#endif
{
    // These should match
    // assert(options.BeginCommandBuffer_Indices.size() == options.Draw_Indices.size());
    // assert(options.BeginCommandBuffer_Indices.size() == options.Dispatch_Indices.size());
    // assert(options.BeginCommandBuffer_Indices.size() == options.TraceRays_Indices.size());

    for (size_t i = 0; i < options.BeginCommandBuffer_Indices.size(); ++i)
    {
        const uint64_t bcb_index = options.BeginCommandBuffer_Indices[i];

        if (i < options.Draw_Indices.size() && options.Draw_Indices[i].size())
        {
            draw_call_contexts.emplace(
                bcb_index,
                DrawCallCommandBufferContext(
                    options.Draw_Indices[i].size() ? options.Draw_Indices[i] : std::vector<uint64_t>(),
                    options.RenderPass_Indices[i].size() ? options.RenderPass_Indices[i]
                                                         : std::vector<std::vector<uint64_t>>(),
                    object_info_table,
                    options.dump_resources_before,
                    dump_resource_path_));
        }

        if ((i < options.Dispatch_Indices.size() && options.Dispatch_Indices[i].size()) ||
            (i < options.TraceRays_Indices.size() && options.TraceRays_Indices[i].size()))
        {
            dispatch_ray_contexts.emplace(bcb_index,
                                          DispatchRaysCommandBufferContext(
                                              (options.Dispatch_Indices.size() && options.Dispatch_Indices[i].size())
                                                  ? options.Dispatch_Indices[i]
                                                  : std::vector<uint64_t>(),
                                              (options.TraceRays_Indices.size() && options.TraceRays_Indices[i].size())
                                                  ? options.TraceRays_Indices[i]
                                                  : std::vector<uint64_t>(),
                                              object_info_table_,
                                              dump_resources_before_,
                                              dump_resource_path_));
        }
    }

#if defined(__ANDROID__) && defined(DELETE_STALE_DUMP_FILES)
    // On Android there is an issue with files which are manually deleted (for example from adb shell) then fopen with
    // "wb" might fail with the error that the file already exists. Deleting the file from code can workaround this
    if (enabled_)
    {
        DIR* dump_resource_dir = opendir(dump_resource_path_.c_str());
        if (dump_resource_dir != nullptr)
        {
            struct dirent* dir;
            while ((dir = readdir(dump_resource_dir)) != nullptr)
            {
                const int len = strlen(dir->d_name);
                if (len > 3)
                {
                    const char* file_extension = &dir->d_name[len - 3];

                    if (!strcmp(file_extension, "bmp") || !strcmp(file_extension, "bin"))
                    {
                        std::string full_path = dump_resource_path_ + std::string(dir->d_name);
                        GFXRECON_LOG_INFO("Deleting file %s", full_path.c_str());
                        if (remove(full_path.c_str()))
                        {
                            GFXRECON_LOG_ERROR(" Failed to delete file %s (%s)", dir->d_name, strerror(errno));
                        }
                    }
                }
            }
        }
    }
#endif
}

VulkanReplayResourceDumpBase::DrawCallCommandBufferContext*
VulkanReplayResourceDumpBase::FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer)
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

    DrawCallCommandBufferContext* context = &context_entry->second;
    return context;
}

const VulkanReplayResourceDumpBase::DrawCallCommandBufferContext*
VulkanReplayResourceDumpBase::FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer) const
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

    const DrawCallCommandBufferContext* context = &context_entry->second;
    return context;
}

VulkanReplayResourceDumpBase::DrawCallCommandBufferContext*
VulkanReplayResourceDumpBase::FindDrawCallCommandBufferContext(uint64_t bcb_id)
{
    auto context_entry = draw_call_contexts.find(bcb_id);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    DrawCallCommandBufferContext* context = &context_entry->second;
    return context;
}

const VulkanReplayResourceDumpBase::DrawCallCommandBufferContext*
VulkanReplayResourceDumpBase::FindDrawCallCommandBufferContext(uint64_t bcb_id) const
{
    const auto context_entry = draw_call_contexts.find(bcb_id);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    const DrawCallCommandBufferContext* context = &context_entry->second;
    return context;
}

VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext*
VulkanReplayResourceDumpBase::FindDispatchRaysCommandBufferContext(uint64_t bcb_id)
{
    auto context_entry = dispatch_ray_contexts.find(bcb_id);
    if (context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    DispatchRaysCommandBufferContext* context = &context_entry->second;
    return context;
}

const VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext*
VulkanReplayResourceDumpBase::FindDispatchRaysCommandBufferContext(uint64_t bcb_id) const
{
    const auto context_entry = dispatch_ray_contexts.find(bcb_id);
    if (context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    const DispatchRaysCommandBufferContext* context = &context_entry->second;
    return context;
}

VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext*
VulkanReplayResourceDumpBase::FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer)
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

    DispatchRaysCommandBufferContext* context = &dr_context_entry->second;
    return context;
}

const VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext*
VulkanReplayResourceDumpBase::FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer) const
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

    const DispatchRaysCommandBufferContext* context = &dr_context_entry->second;
    return context;
}

VkResult VulkanReplayResourceDumpBase::CloneCommandBuffer(uint64_t                   bcb_index,
                                                          const CommandBufferInfo*   original_command_buffer_info,
                                                          const encode::DeviceTable* device_table)
{
    assert(device_table);

    GFXRECON_WRITE_CONSOLE("%s(bcb_index: %" PRIu64 ", original_command_buffer_info: %" PRIu64 ")",
                           __func__,
                           bcb_index,
                           original_command_buffer_info->capture_id);

    DrawCallCommandBufferContext* dc_context = FindDrawCallCommandBufferContext(bcb_index);
    if (dc_context != nullptr)
    {
        VkResult res = dc_context->CloneCommandBuffer(original_command_buffer_info, device_table);
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

    DispatchRaysCommandBufferContext* dr_context = FindDispatchRaysCommandBufferContext(bcb_index);
    if (dr_context != nullptr)
    {
        VkResult res = dr_context->CloneCommandBuffer(original_command_buffer_info, device_table);
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

void VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::FinalizeCommandBuffer()
{
    GFXRECON_WRITE_CONSOLE("  Finalizing command buffer %u (out of %zu) dc: %" PRIu64,
                           current_cb_index,
                           command_buffers.size(),
                           dc_indices[CmdBufToDCVectorIndex(current_cb_index)]);

    assert(current_cb_index < command_buffers.size());
    VkCommandBuffer current_clone = command_buffers[current_cb_index];
    assert(device_table != nullptr);

    assert(inside_renderpass);
    if (inside_renderpass)
    {
        device_table->CmdEndRenderPass(current_clone);
    }

    device_table->EndCommandBuffer(current_clone);

    // Increment index of command buffer that is going to be finalized next
    ++current_cb_index;
}

void VulkanReplayResourceDumpBase::FinalizeDrawCallCommandBuffer(VkCommandBuffer original_command_buffer)
{
    DrawCallCommandBufferContext* context = FindDrawCallCommandBufferContext(original_command_buffer);
    assert(context);

    context->FinalizeCommandBuffer();

    UpdateRecordingStatus();
}

void VulkanReplayResourceDumpBase::FinalizeDispatchRaysCommandBuffer(VkCommandBuffer original_command_buffer)
{
    DispatchRaysCommandBufferContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    assert(context);

    context->FinalizeCommandBuffer();

    UpdateRecordingStatus();
}

void VulkanReplayResourceDumpBase::OverrideCmdDraw(const ApiCallInfo& call_info,
                                                   PFN_vkCmdDraw      func,
                                                   VkCommandBuffer    original_command_buffer,
                                                   uint32_t           vertexCount,
                                                   uint32_t           instanceCount,
                                                   uint32_t           firstVertex,
                                                   uint32_t           firstInstance)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, vertexCount, instanceCount, firstVertex, firstInstance);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdDrawIndexed(const ApiCallInfo&   call_info,
                                                          PFN_vkCmdDrawIndexed func,
                                                          VkCommandBuffer      original_command_buffer,
                                                          uint32_t             indexCount,
                                                          uint32_t             instanceCount,
                                                          uint32_t             firstIndex,
                                                          int32_t              vertexOffset,
                                                          uint32_t             firstInstance)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdDrawIndirect(const ApiCallInfo&    call_info,
                                                           PFN_vkCmdDrawIndirect func,
                                                           VkCommandBuffer       original_command_buffer,
                                                           VkBuffer              buffer,
                                                           VkDeviceSize          offset,
                                                           uint32_t              drawCount,
                                                           uint32_t              stride)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer, offset, drawCount, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer, offset, drawCount, stride);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdDrawIndexedIndirect(const ApiCallInfo&           call_info,
                                                                  PFN_vkCmdDrawIndexedIndirect func,
                                                                  VkCommandBuffer              original_command_buffer,
                                                                  VkBuffer                     buffer,
                                                                  VkDeviceSize                 offset,
                                                                  uint32_t                     drawCount,
                                                                  uint32_t                     stride)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer, offset, drawCount, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer, offset, drawCount, stride);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdDrawIndirectCount(const ApiCallInfo&         call_info,
                                                                PFN_vkCmdDrawIndirectCount func,
                                                                VkCommandBuffer            original_command_buffer,
                                                                VkBuffer                   buffer,
                                                                VkDeviceSize               offset,
                                                                VkBuffer                   countBuffer,
                                                                VkDeviceSize               countBufferOffset,
                                                                uint32_t                   maxDrawCount,
                                                                uint32_t                   stride)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdDrawIndexedIndirectCount(const ApiCallInfo&                call_info,
                                                                       PFN_vkCmdDrawIndexedIndirectCount func,
                                                                       VkCommandBuffer original_command_buffer,
                                                                       VkBuffer        buffer,
                                                                       VkDeviceSize    offset,
                                                                       VkBuffer        countBuffer,
                                                                       VkDeviceSize    countBufferOffset,
                                                                       uint32_t        maxDrawCount,
                                                                       uint32_t        stride)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdDrawIndirectCountKHR(const ApiCallInfo&            call_info,
                                                                   PFN_vkCmdDrawIndirectCountKHR func,
                                                                   VkCommandBuffer original_command_buffer,
                                                                   VkBuffer        buffer,
                                                                   VkDeviceSize    offset,
                                                                   VkBuffer        countBuffer,
                                                                   VkDeviceSize    countBufferOffset,
                                                                   uint32_t        maxDrawCount,
                                                                   uint32_t        stride)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdDrawIndexedIndirectCountKHR(const ApiCallInfo& call_info,
                                                                          PFN_vkCmdDrawIndexedIndirectCountKHR func,
                                                                          VkCommandBuffer original_command_buffer,
                                                                          VkBuffer        buffer,
                                                                          VkDeviceSize    offset,
                                                                          VkBuffer        countBuffer,
                                                                          VkDeviceSize    countBufferOffset,
                                                                          uint32_t        maxDrawCount,
                                                                          uint32_t        stride)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

bool VulkanReplayResourceDumpBase::ShouldDumpDrawCall(VkCommandBuffer original_command_buffer, uint64_t index) const
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    const DrawCallCommandBufferContext* context = FindDrawCallCommandBufferContext(original_command_buffer);
    assert(context);

    return context->ShouldDumpDrawCall(index);
}

bool VulkanReplayResourceDumpBase::ShouldDumpDispatch(VkCommandBuffer original_command_buffer, uint64_t index) const
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    const DispatchRaysCommandBufferContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    assert(context);

    return context->ShouldDumpDispatch(index);
}

bool VulkanReplayResourceDumpBase::ShouldDumpTraceRays(VkCommandBuffer original_command_buffer, uint64_t index) const
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    const DispatchRaysCommandBufferContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    assert(context);

    return context->ShouldDumpTraceRays(index);
}

bool VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::ShouldDumpDrawCall(uint64_t index) const
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

VkResult VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::DumpDrawCallsAttachments(VkQueue  queue,
                                                                                              uint64_t bcb_index)
{
    BackUpMutableResources(queue);

#ifdef TIME_DUMPING
    double total_submission_time = 0;
    double total_dumping_time    = 0;
#endif

    const size_t n_drawcalls = command_buffers.size();
    for (size_t cb = 0; cb < n_drawcalls; ++cb)
    {
        GFXRECON_WRITE_CONSOLE("Submitting CB/DC %u of %zu (idx: %" PRIu64 ") for BeginCommandBuffer: %" PRIu64,
                               cb,
                               n_drawcalls,
                               dc_indices[CmdBufToDCVectorIndex(cb)],
                               bcb_index);

        VkSubmitInfo submit_info;
        submit_info.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submit_info.pNext                = nullptr;
        submit_info.waitSemaphoreCount   = 0;
        submit_info.pWaitSemaphores      = nullptr;
        submit_info.pWaitDstStageMask    = nullptr;
        submit_info.commandBufferCount   = 1;
        submit_info.pCommandBuffers      = &command_buffers[cb];
        submit_info.signalSemaphoreCount = 0;
        submit_info.pSignalSemaphores    = nullptr;

        RevertMutableResources(queue);

#ifdef TIME_DUMPING
        struct timeval tim;
        gettimeofday(&tim, NULL);
        double t0 = tim.tv_sec + (tim.tv_usec / 1000.0);
#endif
        VkResult res = device_table->QueueSubmit(queue, 1, &submit_info, VK_NULL_HANDLE);
        assert(res == VK_SUCCESS);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("QueueSubmit failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }

        // Wait
        res = device_table->QueueWaitIdle(queue);
        assert(res == VK_SUCCESS);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("QueueWaitIdle failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }

#ifdef TIME_DUMPING
        gettimeofday(&tim, NULL);
        double t1 = tim.tv_sec + (tim.tv_usec / 1000.0);
        double t  = t1 > t0 ? t1 - t0 : 0;
        total_submission_time += t;
        GFXRECON_WRITE_CONSOLE("Submittion %u took %g ms", cb, t);
#endif

#ifdef TIME_DUMPING
        GFXRECON_WRITE_CONSOLE("Dumping attachments for DC %u", cb)
        gettimeofday(&tim, NULL);
        t0 = tim.tv_sec + (tim.tv_usec / 1000.0);
#endif
        // Dump resources
        DumpRenderTargetAttachments(cb);

#ifdef TIME_DUMPING
        gettimeofday(&tim, NULL);
        t1 = tim.tv_sec + (tim.tv_usec / 1000.0);
        t  = t1 > t0 ? t1 - t0 : 0;
        total_dumping_time += t;
        GFXRECON_WRITE_CONSOLE("Dumping %u took %g ms", cb, t);
#endif

        // Revert render attachments layouts
        // res = RevertRenderTargetImageLayouts(dc_context, queue, dc_indices[cb]);
        // assert(res == VK_SUCCESS);
        // if (res != VK_SUCCESS)
        // {
        //     return res;
        // }
    }

#ifdef TIME_DUMPING
    GFXRECON_WRITE_CONSOLE("Total submission time: %g ms", total_submission_time);
    GFXRECON_WRITE_CONSOLE("Total dumping time: %g ms", total_dumping_time);
#endif

    return VK_SUCCESS;
}

VkResult
VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::DumpRenderTargetAttachments(uint64_t cmd_buf_index) const
{
    assert(device_table != nullptr);

    const size_t                dc_index = dc_indices[CmdBufToDCVectorIndex(cmd_buf_index)];
    const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
    const uint64_t              rp       = RP_index.first;
    const uint64_t              sp       = RP_index.second;

    if (!render_targets_[rp][sp].color_att_imgs.size() && render_targets_[rp][sp].depth_att_img == nullptr)
    {
        return VK_SUCCESS;
    }

    assert(original_command_buffer_info);
    assert(original_command_buffer_info->parent_id != format::kNullHandleId);
    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    const PhysicalDeviceInfo* phys_dev_info = object_info_table.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(
        device_info->handle, *device_table, *phys_dev_info->replay_device_info->memory_properties);

    for (size_t i = 0; i < render_targets_[rp][sp].color_att_imgs.size(); ++i)
    {
        const ImageInfo* image_info = render_targets_[rp][sp].color_att_imgs[i];

        std::vector<uint8_t>  data;
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;

        VkResult res = resource_util.ReadFromImageResourceStaging(
            image_info->handle,
            image_info->format,
            image_info->type,
            VkExtent3D{ render_area_[rp].extent.width, render_area_[rp].extent.height, 1 },
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
            subresource_sizes);

        if (res != VK_SUCCESS)
        {
            return res;
        }

        util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(image_info->format);

        if (output_image_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
        {
            std::stringstream filename;
            if (dump_resources_before)
            {
                filename << dump_resource_path << "vkCmdDraw_" << ((cmd_buf_index % 2) ? "after_" : "before_")
                         << dc_index << "_att_" << i << "_aspect_"
                         << util::ToString<VkImageAspectFlagBits>(VK_IMAGE_ASPECT_COLOR_BIT) << "_ml_" << 0 << "_al_"
                         << 0 << ".bmp";
            }
            else
            {
                filename << dump_resource_path << "vkCmdDraw_" << dc_index << "_att_" << i << "_aspect_"
                         << util::ToString<VkImageAspectFlagBits>(VK_IMAGE_ASPECT_COLOR_BIT) << "_ml_" << 0 << "_al_"
                         << 0 << ".bmp";
            }
            const uint32_t texel_size = vkuFormatElementSizeWithAspect(image_info->format, VK_IMAGE_ASPECT_COLOR_BIT);
            const uint32_t stride     = texel_size * image_info->extent.width;

            util::imagewriter::WriteBmpImage(filename.str(),
                                             image_info->extent.width,
                                             image_info->extent.height,
                                             subresource_sizes[0],
                                             data.data(),
                                             stride,
                                             output_image_format);
        }
        // else
        // {
        //     std::stringstream filename;
        //     filename << "/storage/emulated/0/Download/screens/vkCmdDraw_" << dc_index << "_att_" << i <<
        //     "_aspect_"
        //              << util::ToString<VkImageAspectFlagBits>(VK_IMAGE_ASPECT_COLOR_BIT) << "_ml_" << 0 << "_al_"
        //              << 0 << ".bin";

        //     util::bufferwriter::WriteBuffer(filename.str(), data.data(), data.size());
        // }
    }

    if (render_targets_[rp][sp].depth_att_img != nullptr)
    {
        const ImageInfo* image_info = render_targets_[rp][sp].depth_att_img;

        std::vector<uint8_t>  data;
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;

        VkResult res = resource_util.ReadFromImageResourceStaging(
            image_info->handle,
            image_info->format,
            image_info->type,
            VkExtent3D{ render_area_[rp].extent.width, render_area_[rp].extent.height, 1 },
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
            subresource_sizes);

        if (res != VK_SUCCESS)
        {
            return res;
        }

        std::stringstream filename;
        if (dump_resources_before)
        {
            filename << dump_resource_path << "vkCmdDraw_" << ((cmd_buf_index % 2) ? "after_" : "before_") << dc_index
                     << "_aspect_" << util::ToString<VkImageAspectFlagBits>(VK_IMAGE_ASPECT_DEPTH_BIT) << "_ml_" << 0
                     << "_al_" << 0 << ".bmp";
        }
        else
        {

            filename << dump_resource_path << "vkCmdDraw_" << dc_index << "_aspect_"
                     << util::ToString<VkImageAspectFlagBits>(VK_IMAGE_ASPECT_DEPTH_BIT) << "_ml_" << 0 << "_al_" << 0
                     << ".bmp";
        }

        // This is a bit awkward
        const uint32_t texel_size = image_info->format != VK_FORMAT_X8_D24_UNORM_PACK32
                                        ? vkuFormatElementSizeWithAspect(image_info->format, VK_IMAGE_ASPECT_DEPTH_BIT)
                                        : 4;
        const uint32_t stride = texel_size * image_info->extent.width;

        util::imagewriter::WriteBmpImage(filename.str(),
                                         image_info->extent.width,
                                         image_info->extent.height,
                                         subresource_sizes[0],
                                         data.data(),
                                         stride,
                                         VkFormatToImageWriterDataFormat(image_info->format));
    }

    return VK_SUCCESS;
}

VkResult VulkanReplayResourceDumpBase::ModifyAndSubmit(std::vector<VkSubmitInfo>  modified_submit_infos,
                                                       const encode::DeviceTable& device_table,
                                                       VkQueue                    queue,
                                                       VkFence                    fence,
                                                       uint64_t                   index)
{
    bool pre_submit = false;

    // First do a submission with all command buffer except the ones we are interested in
    std::vector<VkSubmitInfo>                 submit_infos_copy = modified_submit_infos;
    std::vector<std::vector<VkCommandBuffer>> modified_command_buffer_handles(submit_infos_copy.size());
    for (size_t s = 0; s < submit_infos_copy.size(); s++)
    {
        size_t     command_buffer_count   = submit_infos_copy[s].commandBufferCount;
        const auto command_buffer_handles = submit_infos_copy[s].pCommandBuffers;

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
            submit_infos_copy[s].commandBufferCount = modified_command_buffer_handles[s].size();
            submit_infos_copy[s].pCommandBuffers    = modified_command_buffer_handles[s].data();
        }
        else
        {
            submit_infos_copy.erase(submit_infos_copy.begin() + s);
        }
    }

    if (pre_submit)
    {
        assert(submit_infos_copy.size());

        VkResult res =
            device_table.QueueSubmit(queue, submit_infos_copy.size(), submit_infos_copy.data(), VK_NULL_HANDLE);

        assert(res == VK_SUCCESS);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("QueueSubmit failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }

        // Wait
        res = device_table.QueueWaitIdle(queue);
        assert(res == VK_SUCCESS);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("QueueWaitIdle failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }
    }

    bool submitted = false;
    for (size_t s = 0; s < modified_submit_infos.size(); s++)
    {
        size_t     command_buffer_count   = modified_submit_infos[s].commandBufferCount;
        const auto command_buffer_handles = modified_submit_infos[s].pCommandBuffers;

        // Don't wait and don't signal any semaphores
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
            DrawCallCommandBufferContext* dc_context = FindDrawCallCommandBufferContext(command_buffer_handles[o]);
            if (dc_context != nullptr)
            {
                assert(cmd_buf_begin_map_.find(command_buffer_handles[o]) != cmd_buf_begin_map_.end());
                VkResult res =
                    dc_context->DumpDrawCallsAttachments(queue, cmd_buf_begin_map_[command_buffer_handles[o]]);

                if (res == VK_SUCCESS)
                {
                    submitted = true;
                }
                else
                {
                    return res;
                }
            }

            DispatchRaysCommandBufferContext* dr_context =
                FindDispatchRaysCommandBufferContext(command_buffer_handles[o]);
            if (dr_context != nullptr)
            {
                assert(cmd_buf_begin_map_.find(command_buffer_handles[o]) != cmd_buf_begin_map_.end());
                VkResult res =
                    dr_context->DumpDispatchRaysMutableResources(queue, cmd_buf_begin_map_[command_buffer_handles[o]]);

                if (res == VK_SUCCESS)
                {
                    submitted = true;
                }
                else
                {
                    return res;
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
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("QueueSubmit failed with %s", util::ToString<VkResult>(res).c_str());
        }
    }
    else
    {
        assert(index == QueueSubmit_indices_[0]);
        QueueSubmit_indices_.erase(QueueSubmit_indices_.begin());

        // Once all submissions are complete terminate process
        if (QueueSubmit_indices_.size() == 0)
        {
            exit(0);
        }
    }

    return res;
}

VkResult VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::CloneCommandBuffer(
    const CommandBufferInfo* orig_cmd_buf_info, const encode::DeviceTable* dev_table)
{
    assert(orig_cmd_buf_info);
    assert(dev_table);

    const CommandPoolInfo* cb_pool_info = object_info_table.GetCommandPoolInfo(orig_cmd_buf_info->pool_id);

    const VkCommandBufferAllocateInfo ai{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                                          nullptr,
                                          cb_pool_info->handle,
                                          VK_COMMAND_BUFFER_LEVEL_PRIMARY,
                                          1 };

    const DeviceInfo* dev_info = object_info_table.GetDeviceInfo(orig_cmd_buf_info->parent_id);

    GFXRECON_WRITE_CONSOLE("Allocating %zu command buffers for draw call command buffer context:",
                           command_buffers.size())
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

    GFXRECON_WRITE_CONSOLE("Done")

    assert(original_command_buffer_info == nullptr);
    original_command_buffer_info = orig_cmd_buf_info;

    assert(device_table == nullptr);
    device_table = dev_table;

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

void VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::BindDescriptorSets(
    VkPipelineBindPoint                          pipeline_bind_point,
    VkPipelineLayout                             layout,
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
VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::CloneRenderPass(const RenderPassInfo* original_render_pass)
{
    std::vector<VkAttachmentDescription> modified_attachemnts = original_render_pass->attachment_descs;

    GFXRECON_WRITE_CONSOLE("%s()", __func__);

    GFXRECON_WRITE_CONSOLE("  frame buffer attachments:")
    for (size_t i = 0; i < active_framebuffer->attachment_image_view_ids.size(); ++i)
    {
        const ImageViewInfo* img_view_info =
            object_info_table.GetImageViewInfo(active_framebuffer->attachment_image_view_ids[i]);
        assert(img_view_info);

        const ImageInfo* img_info = object_info_table.GetImageInfo(img_view_info->image_id);
        assert(img_info);

        GFXRECON_WRITE_CONSOLE("    attachment %zu: %p", i, img_info->handle);
    }

    GFXRECON_WRITE_CONSOLE("  attachment descs:");
    for (size_t i = 0; i < modified_attachemnts.size(); ++i)
    {
        GFXRECON_WRITE_CONSOLE("    i: %zu", i);
        GFXRECON_WRITE_CONSOLE("      format: %s", util::ToString<VkFormat>(modified_attachemnts[i].format).c_str());
        GFXRECON_WRITE_CONSOLE("      loadOp: %s",
                               util::ToString<VkAttachmentLoadOp>(modified_attachemnts[i].loadOp).c_str());
        GFXRECON_WRITE_CONSOLE("      storeOp: %s",
                               util::ToString<VkAttachmentStoreOp>(modified_attachemnts[i].storeOp).c_str());
        GFXRECON_WRITE_CONSOLE("      stencilLoadOp: %s",
                               util::ToString<VkAttachmentLoadOp>(modified_attachemnts[i].stencilLoadOp).c_str());
        GFXRECON_WRITE_CONSOLE("      initialLayout: %s",
                               util::ToString<VkImageLayout>(modified_attachemnts[i].initialLayout).c_str());
        GFXRECON_WRITE_CONSOLE("      finalLayout: %s",
                               util::ToString<VkImageLayout>(modified_attachemnts[i].finalLayout).c_str());
    }

    GFXRECON_WRITE_CONSOLE("\n");
    GFXRECON_WRITE_CONSOLE("  Subpass refs:");
    for (size_t i = 0; i < original_render_pass->subpass_refs.size(); ++i)
    {
        GFXRECON_WRITE_CONSOLE("    Subpass: %zu", i);

        GFXRECON_WRITE_CONSOLE("      color:");
        for (size_t c = 0; c < original_render_pass->subpass_refs[i].color_att_refs.size(); ++c)
        {
            GFXRECON_WRITE_CONSOLE("        %zu", c);
            GFXRECON_WRITE_CONSOLE("          att: %u",
                                   original_render_pass->subpass_refs[i].color_att_refs[c].attachment);
            GFXRECON_WRITE_CONSOLE(
                "          layout: %s",
                util::ToString<VkImageLayout>(original_render_pass->subpass_refs[i].color_att_refs[c].layout).c_str());
        }

        GFXRECON_WRITE_CONSOLE("      -----------------------------------------");
        GFXRECON_WRITE_CONSOLE("      depth:");
        if (original_render_pass->subpass_refs[i].has_depth)
        {
            GFXRECON_WRITE_CONSOLE("          att: %u", original_render_pass->subpass_refs[i].depth_att_ref.attachment);
            GFXRECON_WRITE_CONSOLE(
                "          layout: %s",
                util::ToString<VkImageLayout>(original_render_pass->subpass_refs[i].depth_att_ref.layout).c_str());
        }

        GFXRECON_WRITE_CONSOLE("      -----------------------------------------");
        GFXRECON_WRITE_CONSOLE("      input");
        for (size_t c = 0; c < original_render_pass->subpass_refs[i].input_att_refs.size(); ++c)
        {
            GFXRECON_WRITE_CONSOLE("        %zu", c);
            GFXRECON_WRITE_CONSOLE("          att: %u",
                                   original_render_pass->subpass_refs[i].input_att_refs[c].attachment);
            GFXRECON_WRITE_CONSOLE(
                "          layout: %s",
                util::ToString<VkImageLayout>(original_render_pass->subpass_refs[i].input_att_refs[c].layout).c_str());
        }

        GFXRECON_WRITE_CONSOLE("      -----------------------------------------");
        GFXRECON_WRITE_CONSOLE("      preserve");
        for (size_t c = 0; c < original_render_pass->subpass_refs[i].preserve_att_refs.size(); ++c)
        {
            GFXRECON_WRITE_CONSOLE("      %zu", c);
            GFXRECON_WRITE_CONSOLE("        att: %u", original_render_pass->subpass_refs[i].preserve_att_refs[c]);
        }
        GFXRECON_WRITE_CONSOLE("    *****************************************");
    }

    GFXRECON_WRITE_CONSOLE("\n");
    GFXRECON_WRITE_CONSOLE("  Dependencies:");
    for (size_t i = 0; i < original_render_pass->dependencies.size(); ++i)
    {
        GFXRECON_WRITE_CONSOLE("    Dependency: %zu", i);

        GFXRECON_WRITE_CONSOLE("      srcSubpass: %u", original_render_pass->dependencies[i].srcSubpass);
        GFXRECON_WRITE_CONSOLE("      dstSubpass: %u", original_render_pass->dependencies[i].dstSubpass);
        GFXRECON_WRITE_CONSOLE(
            "      srcStageMask: %s",
            util::VkPipelineStageFlags2ToString(original_render_pass->dependencies[i].srcStageMask).c_str());
        GFXRECON_WRITE_CONSOLE(
            "      dstStageMask: %s",
            util::VkPipelineStageFlags2ToString(original_render_pass->dependencies[i].dstStageMask).c_str());
        GFXRECON_WRITE_CONSOLE(
            "      srcAccessMask: %s",
            util::VkAccessFlags2ToString(original_render_pass->dependencies[i].srcAccessMask).c_str());
        GFXRECON_WRITE_CONSOLE(
            "      dstAccessMask: %s",
            util::VkAccessFlags2ToString(original_render_pass->dependencies[i].dstAccessMask).c_str());
        GFXRECON_WRITE_CONSOLE(
            "      dependencyFlags: %s",
            util::ToString<VkDependencyFlags>(original_render_pass->dependencies[i].dependencyFlags).c_str());
    }

    GFXRECON_WRITE_CONSOLE("");
    GFXRECON_WRITE_CONSOLE("");
    GFXRECON_WRITE_CONSOLE("");
    GFXRECON_WRITE_CONSOLE("");

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
                GFXRECON_WRITE_CONSOLE("  RP %u skips dep %u (%u -> %u) as out of scope",
                                       sub,
                                       d,
                                       original_dep.srcSubpass,
                                       original_dep.dstSubpass);

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

            GFXRECON_WRITE_CONSOLE("  RP %u gets a new dependency:", sub)
            GFXRECON_WRITE_CONSOLE("      srcSubpass: %u", new_dep->srcSubpass);
            GFXRECON_WRITE_CONSOLE("      dstSubpass: %u", new_dep->dstSubpass);
            GFXRECON_WRITE_CONSOLE("      srcStageMask: %s",
                                   util::VkPipelineStageFlags2ToString(new_dep->srcStageMask).c_str());
            GFXRECON_WRITE_CONSOLE("      dstStageMask: %s",
                                   util::VkPipelineStageFlags2ToString(new_dep->dstStageMask).c_str());
            GFXRECON_WRITE_CONSOLE("      srcAccessMask: %s",
                                   util::VkAccessFlags2ToString(new_dep->srcAccessMask).c_str());
            GFXRECON_WRITE_CONSOLE("      dstAccessMask: %s",
                                   util::VkAccessFlags2ToString(new_dep->dstAccessMask).c_str());
            GFXRECON_WRITE_CONSOLE("      dependencyFlags: %s",
                                   util::ToString<VkDependencyFlags>(new_dep->dependencyFlags).c_str());
        }

        if (!has_external_dependencies_post)
        {
            GFXRECON_WRITE_CONSOLE("  No post renderpass dependecy was detected")

            VkSubpassDependency post_dependency;
            post_dependency.srcSubpass    = sub;
            post_dependency.dstSubpass    = VK_SUBPASS_EXTERNAL;
            post_dependency.dstStageMask  = VK_PIPELINE_STAGE_TRANSFER_BIT;
            post_dependency.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;

            if (has_color)
            {
                GFXRECON_WRITE_CONSOLE("    Injecting one for color")

                post_dependency.srcStageMask  = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
                post_dependency.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

                modified_dependencies.push_back(post_dependency);
            }

            if (has_depth)
            {
                GFXRECON_WRITE_CONSOLE("    Injecting one for depth")

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
VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::BeginRenderPass(const RenderPassInfo*  render_pass_info,
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
    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(first, last);
    size_t cmd_buf_idx = current_cb_index;
    for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it, ++cmd_buf_idx)
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
        else if (dc_index > RP_indices[rp][RP_indices[rp].size() - 1] || rp > current_renderpass)
        {
            break;
        }

        VkRenderPassBeginInfo bi = { VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO, nullptr };

        bi.clearValueCount = clear_value_count;
        bi.pClearValues    = p_clear_values;
        bi.framebuffer     = framebuffer_info->handle;
        bi.renderArea      = render_area;

        GFXRECON_WRITE_CONSOLE(
            "  cmd_buf_idx: %zu with dc index: %" PRIu64 " gets render pass: (%u, %u)", cmd_buf_idx, dc_index, rp, sp);

        assert(rp < render_pass_clones.size());
        assert(sp < render_pass_clones[rp].size());
        bi.renderPass = render_pass_clones[rp][sp];

        device_table->CmdBeginRenderPass(*it, &bi, contents);
    }

    return VK_SUCCESS;
}

void VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::NextSubpass(VkSubpassContents contents)
{
    assert(active_renderpass);
    assert(active_framebuffer);

    std::vector<const ImageInfo*>    color_att_imgs;
    std::vector<VkAttachmentStoreOp> color_att_storeOps;
    std::vector<VkImageLayout>       color_att_final_layouts;

    ++current_subpass;

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(first, last);
    size_t cmd_buf_idx = current_cb_index;
    for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it, ++cmd_buf_idx)
    {
        const uint64_t              dc_index = dc_indices[CmdBufToDCVectorIndex(cmd_buf_idx)];
        const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
        const uint64_t              rp       = RP_index.first;

        if (rp != current_renderpass)
        {
            continue;
        }

        GFXRECON_WRITE_CONSOLE("  cmd_buf_idx: %zu with dc index: %" PRIu64 " moves to subpass: (%u, %u)",
                               cmd_buf_idx,
                               dc_index,
                               rp,
                               current_subpass);

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

void VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::BindPipeline(VkPipelineBindPoint pipeline_bind_point,
                                                                              const PipelineInfo* pipeline)
{
    VulkanReplayResourceDumpBase::PipelineBindPoints bind_point =
        VkPipelineBindPointToPipelineBindPoint(pipeline_bind_point);

    bound_pipelines[bind_point] = pipeline;
}

void VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::EndRenderPass()
{
    assert(inside_renderpass);

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(first, last);
    size_t cmd_buf_idx = current_cb_index;
    for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it, ++cmd_buf_idx)
    {
        const uint64_t              dc_index = dc_indices[CmdBufToDCVectorIndex(cmd_buf_idx)];
        const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
        const uint64_t              rp       = RP_index.first;
        const uint64_t              sp       = RP_index.second;

        if (dc_index < RP_indices[rp][0])
        {
            continue;
        }
        else if (dc_index > RP_indices[rp][RP_indices[rp].size() - 1] || rp > current_renderpass)
        {
            break;
        }

        GFXRECON_WRITE_CONSOLE(
            "  cmd_buf_idx: %zu with dc index: %" PRIu64 " ends render pass: (%u, %u)", cmd_buf_idx, dc_index, rp, sp);

        device_table->CmdEndRenderPass(*it);
    }

    ++current_renderpass;

    inside_renderpass = false;
}

void VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::SetRenderTargets(
    const std::vector<const ImageInfo*>& color_att_imgs, const ImageInfo* depth_att_img, bool new_render_pass)
{
    if (new_render_pass)
    {
        render_targets_.emplace_back(std::vector<RenderTargets>());
    }

    auto render_targets = render_targets_.end() - 1;

    render_targets->emplace_back(RenderTargets());
    auto new_rts = render_targets->end() - 1;

    new_rts->color_att_imgs = color_att_imgs;
    new_rts->depth_att_img  = depth_att_img;
}

void VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::SetRenderArea(const VkRect2D& render_area)
{
    render_area_.push_back(render_area);
}

void VulkanReplayResourceDumpBase::ResetDescriptors(VkCommandBuffer original_command_buffer)
{
    DrawCallCommandBufferContext* stack = FindDrawCallCommandBufferContext(original_command_buffer);
    assert(stack);

    for (uint32_t i = 0; i < static_cast<uint32_t>(kBindPoint_count); ++i)
    {
        stack->bound_descriptor_sets[i].clear();
    }
}

bool VulkanReplayResourceDumpBase::DumpingBeginCommandBufferIndex(uint64_t index) const
{
    const auto dc_entry = draw_call_contexts.find(index);

    if (dc_entry == draw_call_contexts.end())
    {
        const auto dr_entry = dispatch_ray_contexts.find(index);
        return dr_entry != dispatch_ray_contexts.end();
    }
    else
    {
        return true;
    }
}

bool VulkanReplayResourceDumpBase::GetDrawCallActiveCommandBuffers(VkCommandBuffer original_command_buffer,
                                                                   cmd_buf_it&     first,
                                                                   cmd_buf_it&     last) const
{
    assert(IsRecording(original_command_buffer));

    const DrawCallCommandBufferContext* stack = FindDrawCallCommandBufferContext(original_command_buffer);

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
VulkanReplayResourceDumpBase::GetDispatchRaysCommandBuffer(VkCommandBuffer original_command_buffer) const
{
    assert(IsRecording(original_command_buffer));

    const DispatchRaysCommandBufferContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);

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

bool VulkanReplayResourceDumpBase::UpdateRecordingStatus()
{
    assert(recording_);

    for (const auto& entry : draw_call_contexts)
    {
        const DrawCallCommandBufferContext& dc_context = entry.second;
        if (dc_context.IsRecording())
        {
            return true;
        }
    }

    return (recording_ = false);
}

bool VulkanReplayResourceDumpBase::DumpingSubmissionIndex(uint64_t index) const
{
    for (size_t i = 0; i < QueueSubmit_indices_.size(); ++i)
    {
        // Indices should be sorted
        if (!IsInsideRange(QueueSubmit_indices_, index))
        {
            return false;
        }

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

VkResult VulkanReplayResourceDumpBase::OverrideCmdBeginRenderPass(
    const ApiCallInfo&                                   call_info,
    PFN_vkCmdBeginRenderPass                             func,
    VkCommandBuffer                                      original_command_buffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                                    contents)
{
    assert(IsRecording(original_command_buffer));

    const auto render_pass_info_meta = pRenderPassBegin->GetMetaStructPointer();
    auto       framebuffer_id        = render_pass_info_meta->framebuffer;
    auto       render_pass_id        = render_pass_info_meta->renderPass;

    const FramebufferInfo* framebuffer_info = object_info_table_.GetFramebufferInfo(framebuffer_id);
    assert(framebuffer_info);

    const RenderPassInfo* render_pass_info = object_info_table_.GetRenderPassInfo(render_pass_info_meta->renderPass);
    assert(render_pass_info);

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pRenderPassBegin->GetPointer(), contents);
    }

    // Do not record vkCmdBeginRenderPass commands in current DrawCall context command buffers.
    // It will be handled by DrawCallCommandBufferContext::BeginRenderPass
    DrawCallCommandBufferContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    assert(dc_context);
    return dc_context->BeginRenderPass(render_pass_info,
                                       pRenderPassBegin->GetPointer()->clearValueCount,
                                       pRenderPassBegin->GetPointer()->pClearValues,
                                       framebuffer_info,
                                       pRenderPassBegin->GetPointer()->renderArea,
                                       contents);
}

VkResult VulkanReplayResourceDumpBase::OverrideCmdBeginRenderPass2(
    const ApiCallInfo&                                   call_info,
    PFN_vkCmdBeginRenderPass2                            func,
    VkCommandBuffer                                      original_command_buffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>*    pSubpassBeginInfo)
{
    assert(IsRecording(original_command_buffer));

    const auto render_pass_info_meta = pRenderPassBegin->GetMetaStructPointer();
    auto       framebuffer_id        = render_pass_info_meta->framebuffer;
    auto       render_pass_id        = render_pass_info_meta->renderPass;

    const FramebufferInfo* framebuffer_info = object_info_table_.GetFramebufferInfo(framebuffer_id);
    assert(framebuffer_info);

    const RenderPassInfo* render_pass_info = object_info_table_.GetRenderPassInfo(render_pass_info_meta->renderPass);
    assert(render_pass_info);

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pRenderPassBegin->GetPointer(), pSubpassBeginInfo->GetPointer());
    }

    // Do not record vkCmdBeginRenderPass commands in current DrawCall context command buffers.
    // It will be handled by DrawCallCommandBufferContext::BeginRenderPass
    DrawCallCommandBufferContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    assert(dc_context);
    return dc_context->BeginRenderPass(render_pass_info,
                                       pRenderPassBegin->GetPointer()->clearValueCount,
                                       pRenderPassBegin->GetPointer()->pClearValues,
                                       framebuffer_info,
                                       pRenderPassBegin->GetPointer()->renderArea,
                                       pSubpassBeginInfo->GetPointer()->contents);
}

void VulkanReplayResourceDumpBase::OverrideCmdNextSubpass(const ApiCallInfo&   call_info,
                                                          PFN_vkCmdNextSubpass func,
                                                          VkCommandBuffer      original_command_buffer,
                                                          VkSubpassContents    contents)
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    DrawCallCommandBufferContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    assert(dc_context);
    dc_context->NextSubpass(contents);

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, contents);
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdNextSubpass2(
    const ApiCallInfo&                                call_info,
    PFN_vkCmdNextSubpass2                             func,
    VkCommandBuffer                                   original_command_buffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>*   pSubpassEndInfo)
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    DrawCallCommandBufferContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    assert(dc_context);
    dc_context->NextSubpass(pSubpassBeginInfo->GetPointer()->contents);

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pSubpassBeginInfo->GetPointer(), pSubpassEndInfo->GetPointer());
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdEndRenderPass(const ApiCallInfo&     call_info,
                                                            PFN_vkCmdEndRenderPass func,
                                                            VkCommandBuffer        original_command_buffer)
{
    assert(IsRecording(original_command_buffer));

    DrawCallCommandBufferContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    assert(dc_context);

    dc_context->EndRenderPass();

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer);
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdEndRenderPass2(
    const ApiCallInfo&                              call_info,
    PFN_vkCmdEndRenderPass2                         func,
    VkCommandBuffer                                 original_command_buffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    assert(IsRecording(original_command_buffer));

    DrawCallCommandBufferContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    assert(dc_context);

    dc_context->EndRenderPass();

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pSubpassEndInfo->GetPointer());
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdBindPipeline(const ApiCallInfo&    call_info,
                                                           PFN_vkCmdBindPipeline func,
                                                           VkCommandBuffer       original_command_buffer,
                                                           VkPipelineBindPoint   pipelineBindPoint,
                                                           const PipelineInfo*   pipeline)
{
    assert(pipeline);
    assert(IsRecording(original_command_buffer));

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, pipelineBindPoint, pipeline->handle);
        }

        DrawCallCommandBufferContext* context = FindDrawCallCommandBufferContext(original_command_buffer);
        assert(context);
        context->BindPipeline(pipelineBindPoint, pipeline);
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, pipelineBindPoint, pipeline->handle);

        DispatchRaysCommandBufferContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
        assert(context);
        context->BindPipeline(pipelineBindPoint, pipeline);
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdBindDescriptorSets(const ApiCallInfo&          call_info,
                                                                 PFN_vkCmdBindDescriptorSets func,
                                                                 VkCommandBuffer             original_command_buffer,
                                                                 VkPipelineBindPoint         pipeline_bind_point,
                                                                 VkPipelineLayout            layout,
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

    DrawCallCommandBufferContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context)
    {
        dc_context->BindDescriptorSets(
            pipeline_bind_point, layout, first_set, desc_set_infos, dynamicOffsetCount, pDynamicOffsets);
    }

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it,
             pipeline_bind_point,
             layout,
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
             layout,
             first_set,
             descriptor_sets_count,
             desc_set_handles.data(),
             dynamicOffsetCount,
             pDynamicOffsets);
    }

    DispatchRaysCommandBufferContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    if (dr_context)
    {
        dr_context->BindDescriptorSets(
            pipeline_bind_point, layout, first_set, desc_set_infos, dynamicOffsetCount, pDynamicOffsets);
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdDispatch(const ApiCallInfo& call_info,
                                                       PFN_vkCmdDispatch  func,
                                                       VkCommandBuffer    original_command_buffer,
                                                       uint32_t           groupCountX,
                                                       uint32_t           groupCountY,
                                                       uint32_t           groupCountZ)
{
    assert(IsRecording(original_command_buffer));

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, groupCountX, groupCountY, groupCountZ);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, groupCountX, groupCountY, groupCountZ);
    }

    DispatchRaysCommandBufferContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    if (dr_context != nullptr)
    {
        if (dr_context->ShouldDumpDispatch(call_info.index))
        {
            dr_context->CloneDispatchResources(call_info.index);
        }
    }
}

void VulkanReplayResourceDumpBase::OverrideCmdDispatchIndirect(const ApiCallInfo&        call_info,
                                                               PFN_vkCmdDispatchIndirect func,
                                                               VkCommandBuffer           original_command_buffer,
                                                               VkBuffer                  buffer,
                                                               VkDeviceSize              offset)
{
    assert(IsRecording(original_command_buffer));

    VulkanReplayResourceDumpBase::cmd_buf_it first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, buffer, offset);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, buffer, offset);
    }
}

VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::DrawCallCommandBufferContext(
    const std::vector<uint64_t>&              dc_indices,
    const std::vector<std::vector<uint64_t>>& rp_indices,
    const VulkanObjectInfoTable&              object_info_table,
    bool                                      dump_resources_before,
    std::string                               dump_resource_path) :
    original_command_buffer_info(nullptr),
    current_cb_index(0), dc_indices(dc_indices), RP_indices(rp_indices), active_renderpass(nullptr),
    active_framebuffer(nullptr), bound_pipelines{ nullptr }, current_renderpass(0), current_subpass(0),
    dump_resources_before(dump_resources_before), aux_command_buffer(VK_NULL_HANDLE), aux_fence(VK_NULL_HANDLE),
    device_table(nullptr), object_info_table(object_info_table), replay_device_phys_mem_props(nullptr),
    dump_resource_path(dump_resource_path)
{
    must_backup_resources = dc_indices.size() > 1;

    const size_t n_cmd_buffs = dump_resources_before ? 2 * dc_indices.size() : dc_indices.size();
    command_buffers.resize(n_cmd_buffs, VK_NULL_HANDLE);
}

VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::~DrawCallCommandBufferContext()
{
    if (original_command_buffer_info)
    {
        if (aux_command_buffer != VK_NULL_HANDLE)
        {
            const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
            VkDevice          device      = device_info->handle;

            assert(device_table);

            const CommandPoolInfo* pool_info =
                object_info_table.GetCommandPoolInfo(original_command_buffer_info->pool_id);
            assert(pool_info);

            device_table->FreeCommandBuffers(device, pool_info->handle, 1, &aux_command_buffer);
            aux_command_buffer = VK_NULL_HANDLE;
        }

        DestroyMutableResourceBackups();
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

VkResult CloneBuffer(const VulkanObjectInfoTable&            object_info_table,
                     const encode::DeviceTable*              device_table,
                     const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                     const BufferInfo*                       buffer_info,
                     VkBuffer*                               new_buffer,
                     VkDeviceMemory*                         new_buffer_memory)
{
    VkBufferCreateInfo ci;
    ci.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    ci.pNext                 = nullptr;
    ci.flags                 = VkBufferCreateFlags(0);
    ci.size                  = buffer_info->size;
    ci.usage                 = buffer_info->usage | VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    ci.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    ci.queueFamilyIndexCount = buffer_info->queue_family_index;
    ci.pQueueFamilyIndices   = nullptr;

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(buffer_info->parent_id);
    VkDevice          device      = device_info->handle;

    assert(device_table);
    assert(new_buffer);

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

void VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::DestroyMutableResourceBackups()
{
    assert(original_command_buffer_info);

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    VkDevice          device      = device_info->handle;

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

VkResult VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::RevertMutableResources(VkQueue queue)
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
        GFXRECON_LOG_ERROR("QueueSubmit failed with %s", util::ToString<VkResult>(res).c_str());
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

VkResult VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::BackUpMutableResources(VkQueue queue)
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
        GFXRECON_LOG_ERROR("QueueSubmit failed with %s", util::ToString<VkResult>(res).c_str());
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

VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::RenderPassSubpassPair
VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::GetRenderPassIndex(uint64_t dc_index) const
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
    assert(0);

    return RenderPassSubpassPair(0, 0);
}

size_t VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::CmdBufToDCVectorIndex(size_t cmd_buf_index) const
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

uint32_t
VulkanReplayResourceDumpBase::DrawCallCommandBufferContext::GetDrawCallActiveCommandBuffers(cmd_buf_it& first,
                                                                                            cmd_buf_it& last) const
{
    assert(current_cb_index <= command_buffers.size());

    first = command_buffers.begin() + current_cb_index;
    last  = command_buffers.end();

    return current_cb_index;
}

bool VulkanReplayResourceDumpBase::IsRecording(VkCommandBuffer original_command_buffer) const
{
    if (recording_)
    {
        const DrawCallCommandBufferContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
        if (dc_context)
        {
            if (dc_context->IsRecording())
            {
                return true;
            }
        }

        const DispatchRaysCommandBufferContext* dr_context =
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

VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::DispatchRaysCommandBufferContext(
    const std::vector<uint64_t>& dispatch_indices,
    const std::vector<uint64_t>& trace_rays_indices,
    const VulkanObjectInfoTable& object_info_table,
    bool                         dump_resources_before,
    std::string                  dump_resource_path) :
    original_command_buffer_info(nullptr),
    DR_command_buffer(VK_NULL_HANDLE), dispatch_indices(dispatch_indices),
    trace_rays_indices(trace_rays_indices), bound_pipelines{ nullptr }, dump_resources_before(dump_resources_before),
    dump_resource_path(dump_resource_path), device_table(nullptr), object_info_table(object_info_table),
    replay_device_phys_mem_props(nullptr), current_dispatch_index(0), current_trace_rays_index(0)
{}

VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::~DispatchRaysCommandBufferContext()
{
    DestroyMutableResourcesClones();

    if (original_command_buffer_info)
    {
        if (DR_command_buffer != VK_NULL_HANDLE)
        {
            const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
            if (device_info)
            {
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

VkResult VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::CloneCommandBuffer(
    const CommandBufferInfo* orig_cmd_buf_info, const encode::DeviceTable* dev_table)
{
    assert(orig_cmd_buf_info);
    assert(dev_table);

    const CommandPoolInfo* cb_pool_info = object_info_table.GetCommandPoolInfo(orig_cmd_buf_info->pool_id);

    const VkCommandBufferAllocateInfo ai{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                                          nullptr,
                                          cb_pool_info->handle,
                                          VK_COMMAND_BUFFER_LEVEL_PRIMARY,
                                          1 };

    const DeviceInfo* dev_info = object_info_table.GetDeviceInfo(orig_cmd_buf_info->parent_id);

    GFXRECON_WRITE_CONSOLE("Allocating a command buffer for Dispatch/TraceRays command buffer context:")

    VkResult res = dev_table->AllocateCommandBuffers(dev_info->handle, &ai, &DR_command_buffer);

    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateCommandBuffers failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    const VkCommandBufferBeginInfo bi{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
    dev_table->BeginCommandBuffer(DR_command_buffer, &bi);

    GFXRECON_WRITE_CONSOLE("Done")

    assert(original_command_buffer_info == nullptr);
    original_command_buffer_info = orig_cmd_buf_info;

    assert(device_table == nullptr);
    device_table = dev_table;

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info->parent_id != format::kNullHandleId);
    const PhysicalDeviceInfo* phys_dev_info = object_info_table.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    assert(phys_dev_info->replay_device_info);
    assert(phys_dev_info->replay_device_info->memory_properties.get());
    replay_device_phys_mem_props = phys_dev_info->replay_device_info->memory_properties.get();

    // Allocate auxiliary command buffer
    // VkResult res = device_table->AllocateCommandBuffers(dev_info->handle, &ai, &aux_command_buffer);
    // if (res != VK_SUCCESS)
    // {
    //     GFXRECON_LOG_ERROR("AllocateCommandBuffers failed with %s", util::ToString<VkResult>(res).c_str());
    //     assert(0);
    //     return res;
    // }

    // const VkFenceCreateInfo ci = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
    // res                        = device_table->CreateFence(dev_info->handle, &ci, nullptr, &aux_fence);
    // if (res != VK_SUCCESS)
    // {
    //     GFXRECON_LOG_ERROR("CreateFence failed with %s", util::ToString<VkResult>(res).c_str());
    //     assert(0);
    //     return res;
    // }

    return VK_SUCCESS;
}

void VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::BindPipeline(VkPipelineBindPoint bind_point,
                                                                                  const PipelineInfo* pipeline)
{
    PipelineBindPoints point = VkPipelineBindPointToPipelineBindPoint(bind_point);
    bound_pipelines[point]   = pipeline;
}

void VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::BindDescriptorSets(
    VkPipelineBindPoint                          pipeline_bind_point,
    VkPipelineLayout                             layout,
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

bool VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::ShouldDumpDispatch(uint64_t index) const
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

bool VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::ShouldDumpTraceRays(uint64_t index) const
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

void VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::CopyBufferResource(
    const BufferInfo* src_buffer_info, VkBuffer dst_buffer)
{
    assert(src_buffer_info);
    assert(dst_buffer != VK_NULL_HANDLE);
}

void VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::CopyImageResource(const ImageInfo* src_image_info,
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

    const VkImageSubresourceRange range{
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

    copy.extent = src_image_info->extent;

    for (uint32_t i = 0; i < src_image_info->level_count; ++i)
    {
        copy.srcSubresource.mipLevel = i;
        copy.dstSubresource.mipLevel = i;

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

void VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::CloneDispatchResources(uint64_t index)
{
    assert(IsRecording());
    assert(index == dispatch_indices[current_dispatch_index]);

    // Scan for mutable resources in the bound pipeline
    const PipelineInfo* compute_pipeline = bound_pipelines[kBindPoint_compute];
    assert(compute_pipeline != nullptr);

    for (const auto& shader : compute_pipeline->shaders)
    {
        for (const auto& desc_set : shader.used_descriptors_info)
        {
            const uint32_t set = desc_set.first;
            for (const auto& desc_binding : desc_set.second)
            {
                // Search for resources that are not marked as read only
                if (!desc_binding.second.readonly)
                {
                    const uint32_t binding = desc_binding.first;

                    switch (desc_binding.second.type)
                    {
                        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                        {
                            assert(bound_descriptor_sets[kBindPoint_compute].find(set) !=
                                   bound_descriptor_sets[kBindPoint_compute].end());

                            assert(bound_descriptor_sets[kBindPoint_compute][set].image_infos.find(binding) !=
                                   bound_descriptor_sets[kBindPoint_compute][set].image_infos.end());

                            const ImageInfo* img_info =
                                bound_descriptor_sets[kBindPoint_compute][set].image_infos[binding];

                            mutable_resources_clones.insert({ index, DumpableResourceBackup() });
                            mutable_resources_clones[index].original_images.push_back(img_info);
                            mutable_resources_clones[index].image_desc_set_binding_pair.push_back(
                                std::make_pair(set, binding));

                            VkImage* new_img_ptr = &*(mutable_resources_clones[index].images.insert(
                                mutable_resources_clones[index].images.end(), VK_NULL_HANDLE));

                            VkDeviceMemory* new_img_memory_ptr =
                                &*(mutable_resources_clones[index].image_memories.insert(
                                    mutable_resources_clones[index].image_memories.end(), VK_NULL_HANDLE));

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
                            assert(bound_descriptor_sets[kBindPoint_compute].find(set) !=
                                   bound_descriptor_sets[kBindPoint_compute].end());

                            assert(bound_descriptor_sets[kBindPoint_compute][set].buffer_infos.find(binding) !=
                                   bound_descriptor_sets[kBindPoint_compute][set].buffer_infos.end());

                            const BufferInfo* buf_info =
                                bound_descriptor_sets[kBindPoint_compute][set].buffer_infos[binding];

                            mutable_resources_clones.insert({ index, DumpableResourceBackup() });
                            mutable_resources_clones[index].original_buffers.push_back(buf_info);
                            mutable_resources_clones[index].buffer_desc_set_binding_pair.push_back(
                                std::make_pair(set, binding));

                            VkBuffer* new_buf_ptr = &*(mutable_resources_clones[index].buffers.insert(
                                mutable_resources_clones[index].buffers.end(), VK_NULL_HANDLE));

                            VkDeviceMemory* new_buf_memory_ptr =
                                &*(mutable_resources_clones[index].buffer_memories.insert(
                                    mutable_resources_clones[index].buffer_memories.end(), VK_NULL_HANDLE));

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

    ++current_dispatch_index;
    if (!IsRecording())
    {
        FinalizeCommandBuffer();
    }
}

void VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::DestroyMutableResourcesClones()
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
}

VkResult
VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::DumpDispatchRaysMutableResources(VkQueue  queue,
                                                                                                 uint64_t bcb_index)
{
#ifdef TIME_DUMPING
    double total_submission_time = 0;
    double total_dumping_time    = 0;
#endif

    GFXRECON_WRITE_CONSOLE("Submitting Dispatc/TraceRays command buffer for BeginCommandBuffer: %" PRIu64, bcb_index);

    VkSubmitInfo submit_info;
    submit_info.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.pNext                = nullptr;
    submit_info.waitSemaphoreCount   = 0;
    submit_info.pWaitSemaphores      = nullptr;
    submit_info.pWaitDstStageMask    = nullptr;
    submit_info.commandBufferCount   = 1;
    submit_info.pCommandBuffers      = &DR_command_buffer;
    submit_info.signalSemaphoreCount = 0;
    submit_info.pSignalSemaphores    = nullptr;

#ifdef TIME_DUMPING
    struct timeval tim;
    gettimeofday(&tim, NULL);
    double t0 = tim.tv_sec + (tim.tv_usec / 1000.0);
#endif

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    const VkFenceCreateInfo ci = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };

    VkFence  submission_fence;
    VkResult res = device_table->CreateFence(device_info->handle, &ci, nullptr, &submission_fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("CreateFence failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->QueueSubmit(queue, 1, &submit_info, submission_fence);
    assert(res == VK_SUCCESS);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("QueueSubmit failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    // Wait
    res = device_table->WaitForFences(device_info->handle, 1, &submission_fence, VK_TRUE, ~0UL);
    assert(res == VK_SUCCESS);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("WaitForFences failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    device_table->DestroyFence(device_info->handle, submission_fence, nullptr);

#ifdef TIME_DUMPING
    gettimeofday(&tim, NULL);
    double t1 = tim.tv_sec + (tim.tv_usec / 1000.0);
    double t  = t1 > t0 ? t1 - t0 : 0;
    total_submission_time += t;
    GFXRECON_WRITE_CONSOLE("Submittion took %g ms", t);
#endif

#ifdef TIME_DUMPING
    GFXRECON_WRITE_CONSOLE("Dumping resources")
    gettimeofday(&tim, NULL);
    t0 = tim.tv_sec + (tim.tv_usec / 1000.0);
#endif

    for (auto index : dispatch_indices)
    {
        DumpMutableResources(index, true);
    }

    for (auto index : trace_rays_indices)
    {
        DumpMutableResources(index, true);
    }

#ifdef TIME_DUMPING
    gettimeofday(&tim, NULL);
    t1 = tim.tv_sec + (tim.tv_usec / 1000.0);
    t  = t1 > t0 ? t1 - t0 : 0;
    total_dumping_time += t;
    GFXRECON_WRITE_CONSOLE("Dumping took %g ms", t);
#endif

    return VK_SUCCESS;
}

VkResult VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::DumpMutableResources(uint64_t index,
                                                                                              bool     is_dispatch)
{
    assert(mutable_resources_clones.find(index) != mutable_resources_clones.end());

    assert(original_command_buffer_info);
    assert(original_command_buffer_info->parent_id != format::kNullHandleId);
    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    const PhysicalDeviceInfo* phys_dev_info = object_info_table.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(
        device_info->handle, *device_table, *phys_dev_info->replay_device_info->memory_properties);

    for (size_t i = 0; i < mutable_resources_clones[index].original_images.size(); ++i)
    {
        const ImageInfo*      image_info = mutable_resources_clones[index].original_images[i];
        std::vector<uint8_t>  data;
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;

        VkResult res = resource_util.ReadFromImageResourceStaging(image_info->handle,
                                                                  image_info->format,
                                                                  image_info->type,
                                                                  image_info->extent,
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
                                                                  subresource_sizes);

        if (res != VK_SUCCESS)
        {
            return res;
        }

        util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(image_info->format);

        if (output_image_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
        {
            uint32_t desc_set = mutable_resources_clones[index].image_desc_set_binding_pair[i].first;
            uint32_t binding  = mutable_resources_clones[index].image_desc_set_binding_pair[i].second;

            std::stringstream filename;
            filename << dump_resource_path << (is_dispatch ? "vkCmdDispatch_" : "vkCmdTraceRays_") << index
                     << "desc_set_" << desc_set << "_binding_" << binding << "_aspect_"
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
                                             output_image_format);
        }
        // else
        // {
        //     std::stringstream filename;
        //     filename << "/storage/emulated/0/Download/screens/vkCmdDraw_" << dc_index << "_att_" << i <<
        //     "_aspect_"
        //              << util::ToString<VkImageAspectFlagBits>(VK_IMAGE_ASPECT_COLOR_BIT) << "_ml_" << 0 << "_al_"
        //              << 0 << ".bin";

        //     util::bufferwriter::WriteBuffer(filename.str(), data.data(), data.size());
        // }
    }

    return VK_SUCCESS;
}

void VulkanReplayResourceDumpBase::DispatchRaysCommandBufferContext::FinalizeCommandBuffer()
{
    assert(current_dispatch_index == dispatch_indices.size() && current_trace_rays_index == trace_rays_indices.size());
    assert(DR_command_buffer != VK_NULL_HANDLE);

    GFXRECON_WRITE_CONSOLE("Finalizing Dispach/TraceRays command buffer")

    device_table->EndCommandBuffer(DR_command_buffer);
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
