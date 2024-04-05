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

#ifndef GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_DRAW_CALLS_H
#define GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_DRAW_CALLS_H

#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_object_info_table.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_replay_dump_resources_json.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "format/format.h"
#include "util/defines.h"
#include "vulkan/vulkan_core.h"

#include <cstdint>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// This class handles the context related to dumping the draw call render targets
class DrawCallsDumpingContext
{
  public:
    DrawCallsDumpingContext(const std::vector<uint64_t>&              dc_indices,
                            const std::vector<std::vector<uint64_t>>& rp_indices,
                            VulkanObjectInfoTable&                    object_info_table,
                            const VulkanReplayOptions&                options,
                            VulkanReplayDumpResourcesJson&            dump_json);

    ~DrawCallsDumpingContext();

    bool IsRecording() const { return current_cb_index < command_buffers.size(); }

    bool MustDumpDrawCall(uint64_t index) const;

    bool ShouldHandleRenderPass(uint64_t index) const;

    void BindDescriptorSets(VkPipelineBindPoint                          pipeline_bind_point,
                            uint32_t                                     first_set,
                            const std::vector<const DescriptorSetInfo*>& descriptor_sets_infos,
                            uint32_t                                     dynamicOffsetCount,
                            const uint32_t*                              pDynamicOffsets);

    void BindPipeline(VkPipelineBindPoint bind_point, const PipelineInfo* pipeline);

    VkResult CloneCommandBuffer(CommandBufferInfo*           orig_cmd_buf_info,
                                const encode::DeviceTable*   dev_table,
                                const encode::InstanceTable* inst_table);

    VkResult CloneRenderPass(const RenderPassInfo* original_render_pass, const FramebufferInfo* fb_info);

    VkResult BeginRenderPass(const RenderPassInfo*  render_pass_info,
                             uint32_t               clear_value_count,
                             const VkClearValue*    p_clear_values,
                             const FramebufferInfo* framebuffer_info,
                             const VkRect2D&        render_area,
                             VkSubpassContents      contents);

    void NextSubpass(VkSubpassContents contents);

    void EndRenderPass();

    void BeginRendering(const std::vector<ImageInfo*>&    color_attachments,
                        const std::vector<VkImageLayout>& color_attachment_layouts,
                        ImageInfo*                        depth_attachment,
                        VkImageLayout                     depth_attachment_layout,
                        const VkRect2D&                   render_area);

    void EndRendering();

    void BindVertexBuffers(uint64_t                              index,
                           uint32_t                              firstBinding,
                           const std::vector<const BufferInfo*>& buffer_infos,
                           const VkDeviceSize*                   pOffsets);

    void BindVertexBuffers2(uint64_t                              index,
                            uint32_t                              first_binding,
                            const std::vector<const BufferInfo*>& buffer_infos,
                            const VkDeviceSize*                   offsets,
                            const VkDeviceSize*                   sizes,
                            const VkDeviceSize*                   strides);

    void SetVertexInput(uint32_t                                     vertexBindingDescriptionCount,
                        const VkVertexInputBindingDescription2EXT*   pVertexBindingDescriptions,
                        uint32_t                                     vertexAttributeDescriptionCount,
                        const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);

    void BindIndexBuffer(uint64_t          index,
                         const BufferInfo* buffer_info,
                         VkDeviceSize      offset,
                         VkIndexType       index_type,
                         VkDeviceSize      size = 0);

    void FinalizeCommandBuffer();

    void SetRenderTargets(const std::vector<ImageInfo*>& color_att_imgs, ImageInfo* depth_att_img, bool new_renderpass);

    void SetRenderArea(const VkRect2D& new_render_area);

    uint32_t GetDrawCallActiveCommandBuffers(CommandBufferIterator& first, CommandBufferIterator& last) const;

    VkResult
    DumpDrawCalls(VkQueue queue, uint64_t qs_index, uint64_t bcb_index, const VkSubmitInfo& submit_info, VkFence fence);

    VkResult DumpRenderTargetAttachments(uint64_t cmd_buf_index, uint64_t qs_index, uint64_t bcb_index) const;

    VkResult DumpImmutableResources(uint64_t qs_index, uint64_t bcb_index) const;

    VkResult DumpVertexIndexBuffers();

    void InsertNewDrawParameters(
        uint64_t index, uint32_t vertex_count, uint32_t instance_count, uint32_t first_vertex, uint32_t first_instance);

    void InsertNewDrawIndexedParameters(uint64_t index,
                                        uint32_t index_count,
                                        uint32_t instance_count,
                                        uint32_t first_index,
                                        int32_t  vertexOffset,
                                        uint32_t first_instance);

    void InsertNewDrawIndirectParameters(
        uint64_t index, const BufferInfo* buffer_info, VkDeviceSize offset, uint32_t draw_count, uint32_t stride);

    void InsertNewDrawIndexedIndirectParameters(
        uint64_t index, const BufferInfo* buffer_info, VkDeviceSize offset, uint32_t draw_count, uint32_t stride);

    void InsertNewIndirectCountParameters(uint64_t          index,
                                          const BufferInfo* buffer_info,
                                          VkDeviceSize      offset,
                                          const BufferInfo* count_buffer_info,
                                          VkDeviceSize      count_buffer_offset,
                                          uint32_t          max_draw_count,
                                          uint32_t          stride);

    void InsertNewDrawIndexedIndirectCountParameters(uint64_t          index,
                                                     const BufferInfo* buffer_info,
                                                     VkDeviceSize      offset,
                                                     const BufferInfo* count_buffer_info,
                                                     VkDeviceSize      count_buffer_offset,
                                                     uint32_t          max_draw_count,
                                                     uint32_t          stride);

    void InsertNewDrawIndirectCountKHRParameters(uint64_t          index,
                                                 const BufferInfo* buffer_info,
                                                 VkDeviceSize      offset,
                                                 const BufferInfo* count_buffer_info,
                                                 VkDeviceSize      count_buffer_offset,
                                                 uint32_t          max_draw_count,
                                                 uint32_t          stride);

    void InsertNewDrawIndexedIndirectCountKHRParameters(uint64_t          index,
                                                        const BufferInfo* buffer_info,
                                                        VkDeviceSize      offset,
                                                        const BufferInfo* count_buffer_info,
                                                        VkDeviceSize      count_buffer_offset,
                                                        uint32_t          max_draw_count,
                                                        uint32_t          stride);

    void CopyVertexInputStateInfo(uint64_t dc_index);

    VkResult CopyDrawIndirectParameters(uint64_t index);

    void SnapshotBoundDescriptors(uint64_t index);

  private:
    std::vector<std::string> GenerateRenderTargetImageFilename(VkFormat format,
                                                               uint64_t cmd_buf_index,
                                                               uint64_t dc_index,
                                                               int      attachment_index) const;

    std::vector<std::string> GenerateImageDescriptorFilename(const ImageInfo* img_info) const;

    std::string GenerateBufferDescriptorFilename(format::HandleId buffer_id) const;

    std::string GenerateInlineUniformBufferDescriptorFilename(uint32_t set, uint32_t binding) const;

    std::string GenerateVertexBufferFilename(uint64_t bind_vertex_buffer_index, uint32_t binding) const;

    std::string GenerateIndexBufferFilename(uint64_t bind_index_buffer_index, VkIndexType type) const;

    using RenderPassSubpassPair = std::pair<uint64_t, uint64_t>;
    RenderPassSubpassPair GetRenderPassIndex(uint64_t dc_index) const;
    size_t                CmdBufToDCVectorIndex(size_t cmd_buf_index) const;

    void DestroyMutableResourceBackups();

    void ReleaseIndirectDrawParams();

    VkResult BackUpMutableResources(VkQueue queue);

    VkResult RevertMutableResources(VkQueue queue);

    VkResult FetchDrawIndirectParams();

    void GenerateOutputJsonDrawCallInfo(uint64_t cmd_buf_index, uint64_t qs_index, uint64_t bcb_index) const;

    VkResult RevertRenderTargetImageLayouts(VkQueue queue, uint64_t dc_index);

    CommandBufferInfo*                 original_command_buffer_info;
    std::vector<VkCommandBuffer>       command_buffers;
    size_t                             current_cb_index;
    std::vector<uint64_t>              dc_indices;
    std::vector<std::vector<uint64_t>> RP_indices;
    const RenderPassInfo*              active_renderpass;
    const FramebufferInfo*             active_framebuffer;
    const PipelineInfo*                bound_pipelines[kBindPoint_count];
    uint32_t                           current_renderpass;
    uint32_t                           current_subpass;
    uint32_t                           n_subpasses;
    bool                               dump_resources_before;
    const std::string&                 dump_resource_path;
    util::ScreenshotFormat             image_file_format;
    float                              dump_resources_scale;
    VulkanReplayDumpResourcesJson&     dump_json;
    bool                               dump_depth;
    int32_t                            color_attachment_to_dump;
    bool                               dump_vertex_index_buffers;
    bool                               output_json_per_command;
    bool                               dump_immutable_resources;
    bool                               dump_all_image_subresources;

    enum RenderPassType
    {
        kNone,
        kRenderPass,
        kDynamicRendering
    };

    RenderPassType current_render_pass_type;

    std::vector<std::vector<VkRenderPass>> render_pass_clones;

    struct RenderPassAttachmentLayouts
    {
        bool                       is_dynamic;
        std::vector<VkImageLayout> color_attachment_layouts;
        VkImageLayout              depth_attachment_layout;
    };

    std::unordered_map<uint32_t, RenderPassAttachmentLayouts> dynamic_rendering_attachment_layouts;

    struct RenderTargets
    {
        RenderTargets() : depth_att_img(nullptr) {}

        std::vector<ImageInfo*> color_att_imgs;
        ImageInfo*              depth_att_img;
    };

    // render_targets is basically a 2d array (vector of vectors). It is indexed like render_targets[rp][sp]
    // where rp specifies the render pass and sp the subpass.
    std::vector<std::vector<RenderTargets>> render_targets;

    // Render area is constant between subpasses so this array will be single dimension array
    std::vector<VkRect2D> render_area;

    // One entry per descriptor set
    std::unordered_map<uint32_t, DescriptorSetInfo> bound_descriptor_sets_gr;

    struct VertexInputState
    {
        // One entry per binding
        PipelineInfo::VertexInputBindingMap input_binding_map;

        // One entry per location
        PipelineInfo::VertexInputAttributeMap input_attribute_map;
    };

    // Keep track of CmdSetVertexInputEXT
    VertexInputState dynamic_vertex_input_state;

    // Keep track of bound vertex buffers
    struct BoundVertexBuffersInfo
    {
        struct BufferPerBinding
        {
            BufferPerBinding() : buffer_info(nullptr), offset(0) {}
            BufferPerBinding(const BufferInfo* buffer_info,
                             VkDeviceSize      offset,
                             VkDeviceSize      size   = 0,
                             VkDeviceSize      stride = 0) :
                buffer_info(buffer_info),
                offset(offset), size(size), stride(stride)
            {}

            const BufferInfo* buffer_info;
            VkDeviceSize      offset;

            // These are provided only by CmdBindVertexBuffers2
            VkDeviceSize size;
            VkDeviceSize stride;
        };

        // One entry for each vertex buffer bound at each binding
        std::unordered_map<uint32_t, BufferPerBinding> bound_vertex_buffer_per_binding;

        // A list of all draw calls that reference these vertex buffers
        std::vector<uint64_t> referencing_draw_calls;

        // Store the vertex input state taken either from the current pipeline or from
        // CmdSetVertexInputEXT/CmdBindVertexBuffers2
        VertexInputState vertex_input_state;
    };

    // One entry for each vkCmdBindVertexBuffers
    using BoundVertexBuffersMaps = std::unordered_map<uint64_t, BoundVertexBuffersInfo>;
    BoundVertexBuffersMaps bound_vertex_buffers;

    // A pointer to the last bound vertex buffers.
    BoundVertexBuffersMaps::iterator currently_bound_vertex_buffers;

    // Keep track of bound index buffer
    struct BoundIndexBuffer
    {
        BoundIndexBuffer() : buffer_info(nullptr), offset(0), index_type(VK_INDEX_TYPE_MAX_ENUM) {}

        BoundIndexBuffer(const BufferInfo* buffer_info,
                         VkDeviceSize      offset,
                         VkIndexType       index_type,
                         VkDeviceSize      size) :
            buffer_info(buffer_info),
            offset(offset), index_type(index_type), size(size)
        {}

        const BufferInfo* buffer_info;
        VkDeviceSize      offset;
        VkIndexType       index_type;

        // This is provided only by vkCmdBindIndexBuffer2KHR
        VkDeviceSize size;

        // A list of all draw calls that reference this index buffer
        std::vector<uint64_t> referencing_draw_calls;
    };

    // One entry for each vkCmdBindIndexBuffer
    using BoundIndexBuffersMap = std::unordered_map<uint64_t, BoundIndexBuffer>;
    BoundIndexBuffersMap bound_index_buffers;

    // A pointer to the last bound index buffer.
    BoundIndexBuffersMap::iterator currently_bound_index_buffer;

    enum DrawCallTypes
    {
        kDraw,
        kDrawIndirect,
        kDrawIndirectCount,
        kDrawIndirectCountKHR,
        kDrawIndexed,
        kDrawIndexedIndirect,
        kDrawIndexedIndirectCount,
        kDrawIndexedIndirectCountKHR
    };

    static bool IsDrawCallIndexed(DrawCallTypes dc_type)
    {
        switch (dc_type)
        {
            case kDraw:
            case kDrawIndirect:
            case kDrawIndirectCount:
            case kDrawIndirectCountKHR:
                return false;

            case kDrawIndexed:
            case kDrawIndexedIndirect:
            case kDrawIndexedIndirectCount:
            case kDrawIndexedIndirectCountKHR:
                return true;

            default:
                GFXRECON_LOG_ERROR("%s() Unrecognized draw call type (%u)", __func__, static_cast<uint32_t>(dc_type))
                assert(0);
                return false;
        }
    }

    static bool IsDrawCallIndirect(DrawCallTypes dc_type)
    {
        switch (dc_type)
        {
            case kDraw:
            case kDrawIndexed:
                return false;

            case kDrawIndirect:
            case kDrawIndirectCount:
            case kDrawIndirectCountKHR:
            case kDrawIndexedIndirect:
            case kDrawIndexedIndirectCount:
            case kDrawIndexedIndirectCountKHR:
                return true;

            default:
                GFXRECON_LOG_ERROR("%s() Unrecognized draw call type (%u)", __func__, static_cast<uint32_t>(dc_type))
                assert(0);
                return false;
        }
    }

    static bool IsDrawCallIndirectCount(DrawCallTypes dc_type)
    {
        switch (dc_type)
        {
            case kDraw:
            case kDrawIndexed:
            case kDrawIndirect:
            case kDrawIndexedIndirect:
                return false;

            case kDrawIndirectCount:
            case kDrawIndirectCountKHR:
            case kDrawIndexedIndirectCount:
            case kDrawIndexedIndirectCountKHR:
                return true;

            default:
                GFXRECON_LOG_ERROR("%s() Unrecognized draw call type (%u)", __func__, static_cast<uint32_t>(dc_type))
                assert(0);
                return false;
        }
    }

    struct DrawCallParameters
    {
        static constexpr uint64_t INVALID_BLOCK_INDEX = std::numeric_limits<uint64_t>::max();

        union DrawCallParamsUnion
        {
            struct DrawParams
            {
                uint32_t vertex_count;
                uint32_t instance_count;
                uint32_t first_vertex;
                uint32_t first_instance;
            };

            DrawParams draw;

            struct DrawIndexedParams
            {
                uint32_t index_count;
                uint32_t instance_count;
                uint32_t first_index;
                int32_t  vertex_offset;
                uint32_t first_instance;
            };

            DrawIndexedParams draw_indexed;

            struct DrawIndirectParams
            {
                const BufferInfo* params_buffer_info;
                VkDeviceSize      params_buffer_offset;
                uint32_t          draw_count;
                uint32_t          stride;

                VkBuffer       new_params_buffer;
                VkDeviceMemory new_params_memory;
                VkDeviceSize   new_params_buffer_size;

                // Pointers that will point to host allocated memory and filled with the draw params
                // read back after executing on the gpu. Because of the union a data structure
                // with a non default destructor (vector/unique_ptr) cannot be used and we will
                // handle the memory managment ourselves.
                // One of these pointer will be used, depending on whether the draw call is indexed
                // or not.
                DrawParams*        draw_params;
                DrawIndexedParams* draw_indexed_params;
            };

            DrawIndirectParams draw_indirect;

            struct DrawIndirectCountParams
            {
                const BufferInfo* params_buffer_info;
                VkDeviceSize      params_buffer_offset;
                const BufferInfo* count_buffer_info;
                VkDeviceSize      count_buffer_offset;
                uint32_t          max_draw_count;
                uint32_t          stride;

                VkBuffer       new_params_buffer;
                VkDeviceMemory new_params_memory;
                VkDeviceSize   new_params_buffer_size;

                VkBuffer       new_count_buffer;
                VkDeviceMemory new_count_memory;

                // Pointers that will point to host allocated memory and filled with the draw params
                // read back after executing on the gpu. Because of the union a data structure
                // with a non default destructor (vector/unique_ptr) cannot be used and we will
                // handle the memory managment ourselves.
                // One of these pointer will be used, depending on whether the draw call is indexed
                // or not.
                DrawParams*        draw_params;
                DrawIndexedParams* draw_indexed_params;

                uint32_t actual_draw_count;
            };

            DrawIndirectCountParams draw_indirect_count;

            // Constructor for vkCmdDraw
            DrawCallParamsUnion(uint32_t vertex_count,
                                uint32_t instance_count,
                                uint32_t first_vertex,
                                uint32_t first_instance) :
                draw{ vertex_count, instance_count, first_vertex, first_instance }
            {}

            // Constructor for vkCmdDrawIndexed*
            DrawCallParamsUnion(uint32_t index_count,
                                uint32_t instance_count,
                                uint32_t first_index,
                                int32_t  vertex_offset,
                                uint32_t first_instance) :
                draw_indexed{ index_count, instance_count, first_index, vertex_offset, first_instance }
            {}

            // Constructor for vkCmdDrawIndirect*
            DrawCallParamsUnion(const BufferInfo* params_buffer_info,
                                VkDeviceSize      offset,
                                uint32_t          draw_count,
                                uint32_t          stride) :
                draw_indirect{ params_buffer_info, offset, draw_count, stride, VK_NULL_HANDLE,
                               VK_NULL_HANDLE,     0,      nullptr,    nullptr }
            {}

            // Constructor for vkCmdDraw*IndirectCount*
            DrawCallParamsUnion(const BufferInfo* params_buffer_info,
                                VkDeviceSize      params_buffer_offset,
                                const BufferInfo* count_buffer_info,
                                VkDeviceSize      count_buffer_offset,
                                uint32_t          max_draw_count,
                                uint32_t          stride) :
                draw_indirect_count{ params_buffer_info,
                                     params_buffer_offset,
                                     count_buffer_info,
                                     count_buffer_offset,
                                     max_draw_count,
                                     stride,
                                     VK_NULL_HANDLE,
                                     VK_NULL_HANDLE,
                                     0,
                                     VK_NULL_HANDLE,
                                     VK_NULL_HANDLE,
                                     nullptr,
                                     nullptr,
                                     std::numeric_limits<uint32_t>::max() }
            {}
        } dc_params_union;

        // Constructor for vkCmdDraw
        DrawCallParameters(DrawCallTypes type,
                           uint32_t      vertex_count,
                           uint32_t      instance_count,
                           uint32_t      first_vertex,
                           uint32_t      first_instance) :
            dc_params_union(vertex_count, instance_count, first_vertex, first_instance),
            type(type), referenced_bind_vertex_buffers(INVALID_BLOCK_INDEX),
            referenced_bind_index_buffer(INVALID_BLOCK_INDEX)
        {
            assert(type == DrawCallTypes::kDraw);
        }

        // Constructor for vkCmdDrawIndexed*
        DrawCallParameters(DrawCallTypes type,
                           uint32_t      index_count,
                           uint32_t      instance_count,
                           uint32_t      first_index,
                           int32_t       vertex_offset,
                           uint32_t      first_instance) :
            dc_params_union(index_count, instance_count, first_index, vertex_offset, first_instance),
            type(type), referenced_bind_vertex_buffers(INVALID_BLOCK_INDEX),
            referenced_bind_index_buffer(INVALID_BLOCK_INDEX)
        {
            assert(type == DrawCallTypes::kDrawIndexed);
        }

        // Constructor for vkCmdDraw*Indirect
        DrawCallParameters(DrawCallTypes     type,
                           const BufferInfo* params_buffer_info,
                           VkDeviceSize      offset,
                           uint32_t          draw_count,
                           uint32_t          stride) :
            dc_params_union(params_buffer_info, offset, draw_count, stride),
            type(type), referenced_bind_vertex_buffers(INVALID_BLOCK_INDEX),
            referenced_bind_index_buffer(INVALID_BLOCK_INDEX)
        {
            assert(type == DrawCallTypes::kDrawIndirect || type == DrawCallTypes::kDrawIndexedIndirect);
        }

        // Constructor for vkCmdDraw*IndirectCount*
        DrawCallParameters(DrawCallTypes     type,
                           const BufferInfo* buffer_info,
                           VkDeviceSize      offset,
                           const BufferInfo* count_buffer_info,
                           VkDeviceSize      count_buffer_offset,
                           uint32_t          max_draw_count,
                           uint32_t          stride) :
            dc_params_union(buffer_info, offset, count_buffer_info, count_buffer_offset, max_draw_count, stride),
            type(type), referenced_bind_vertex_buffers(INVALID_BLOCK_INDEX),
            referenced_bind_index_buffer(INVALID_BLOCK_INDEX)
        {
            assert(type == DrawCallTypes::kDrawIndirectCount || type == DrawCallTypes::kDrawIndexedIndirectCount ||
                   type == DrawCallTypes::kDrawIndirectCountKHR || type == DrawCallTypes::kDrawIndexedIndirectCountKHR);
        }

        DrawCallTypes type;

        // The index block of the vkCmdBindVertexBuffers/vkCmdBindVertexBuffers2/vkCmdBindIndexBuffer
        // that were active when the draw call was issued
        uint64_t referenced_bind_vertex_buffers;
        uint64_t referenced_bind_index_buffer;

        // Keep copies of the descriptor bindings referenced by each draw call
        std::unordered_map<VkShaderStageFlagBits,
                           std::unordered_map<uint32_t, DescriptorSetInfo::DescriptorBindingsInfo>>
            referenced_descriptors;
    };

    // One entry for each draw call
    std::unordered_map<uint64_t, DrawCallParameters> draw_call_params;

    struct
    {
        std::vector<const ImageInfo*> original_images;
        std::vector<VkImage>          images;
        std::vector<VkDeviceMemory>   image_memories;

        std::vector<const BufferInfo*> original_buffers;
        std::vector<VkBuffer>          buffers;
        std::vector<VkDeviceMemory>    buffer_memories;
    } mutable_resource_backups;

    VkCommandBuffer aux_command_buffer;
    VkFence         aux_fence;
    bool            must_backup_resources;

    const encode::DeviceTable*              device_table;
    const encode::InstanceTable*            instance_table;
    VulkanObjectInfoTable&                  object_info_table;
    const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_DRAW_CALLS_H */
