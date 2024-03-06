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

#ifndef GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_BASE_H
#define GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_BASE_H

#include "decode/api_decoder.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_object_info_table.h"
#include "decode/struct_pointer_decoder.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "decode/vulkan_replay_dump_resources_json.h"
#include "format/format.h"
#include "util/defines.h"
#include <cstdint>
#include <limits>
#include <vector>
#include <unordered_map>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

static constexpr uint64_t INVALID_BLOCK_INDEX = std::numeric_limits<uint64_t>::max();

class VulkanReplayDumpResourcesBase
{
  public:
    VulkanReplayDumpResourcesBase() = delete;

    VulkanReplayDumpResourcesBase(const VulkanReplayOptions& options, const VulkanObjectInfoTable& object_info_table);

    VkResult CloneCommandBuffer(uint64_t                     bcb_index,
                                const CommandBufferInfo*     original_command_buffer_info,
                                const encode::DeviceTable*   device_table,
                                const encode::InstanceTable* inst_table);

    void FinalizeDrawCallCommandBuffer(VkCommandBuffer original_command_buffer);

    void FinalizeDispatchRaysCommandBuffer(VkCommandBuffer original_command_buffer);

    void OverrideCmdDraw(const ApiCallInfo& call_info,
                         PFN_vkCmdDraw      func,
                         VkCommandBuffer    original_command_buffer,
                         uint32_t           vertex_count,
                         uint32_t           instance_count,
                         uint32_t           first_vertex,
                         uint32_t           first_instance);

    void OverrideCmdDrawIndexed(const ApiCallInfo&   call_info,
                                PFN_vkCmdDrawIndexed func,
                                VkCommandBuffer      original_command_buffer,
                                uint32_t             index_count,
                                uint32_t             instance_count,
                                uint32_t             first_index,
                                int32_t              vertex_offset,
                                uint32_t             first_instance);

    void OverrideCmdDrawIndirect(const ApiCallInfo&    call_info,
                                 PFN_vkCmdDrawIndirect func,
                                 VkCommandBuffer       original_command_buffer,
                                 const BufferInfo*     buffer_info,
                                 VkDeviceSize          offset,
                                 uint32_t              draw_count,
                                 uint32_t              stride);

    void OverrideCmdDrawIndexedIndirect(const ApiCallInfo&           call_info,
                                        PFN_vkCmdDrawIndexedIndirect func,
                                        VkCommandBuffer              original_command_buffer,
                                        const BufferInfo*            buffer_info,
                                        VkDeviceSize                 offset,
                                        uint32_t                     draw_count,
                                        uint32_t                     stride);

    void OverrideCmdDrawIndirectCount(const ApiCallInfo&         call_info,
                                      PFN_vkCmdDrawIndirectCount func,
                                      VkCommandBuffer            original_command_buffer,
                                      const BufferInfo*          buffer_info,
                                      VkDeviceSize               offset,
                                      const BufferInfo*          count_buffer_info,
                                      VkDeviceSize               count_buffer_offset,
                                      uint32_t                   max_draw_count,
                                      uint32_t                   stride);

    void OverrideCmdDrawIndexedIndirectCount(const ApiCallInfo&                call_info,
                                             PFN_vkCmdDrawIndexedIndirectCount func,
                                             VkCommandBuffer                   original_command_buffer,
                                             const BufferInfo*                 buffer_info,
                                             VkDeviceSize                      offset,
                                             const BufferInfo*                 count_buffer_info,
                                             VkDeviceSize                      count_buffer_offset,
                                             uint32_t                          max_draw_count,
                                             uint32_t                          stride);

    void OverrideCmdDrawIndirectCountKHR(const ApiCallInfo&            call_info,
                                         PFN_vkCmdDrawIndirectCountKHR func,
                                         VkCommandBuffer               original_command_buffer,
                                         const BufferInfo*             buffer_info,
                                         VkDeviceSize                  offset,
                                         const BufferInfo*             count_buffer_info,
                                         VkDeviceSize                  count_buffer_offset,
                                         uint32_t                      max_draw_count,
                                         uint32_t                      stride);

    void OverrideCmdDrawIndexedIndirectCountKHR(const ApiCallInfo&                   call_info,
                                                PFN_vkCmdDrawIndexedIndirectCountKHR func,
                                                VkCommandBuffer                      original_command_buffer,
                                                const BufferInfo*                    buffer_info,
                                                VkDeviceSize                         offset,
                                                const BufferInfo*                    count_buffer_info,
                                                VkDeviceSize                         count_buffer_offset,
                                                uint32_t                             max_draw_count,
                                                uint32_t                             stride);

    void OverrideCmdBeginRenderPass(const ApiCallInfo&                                   call_info,
                                    PFN_vkCmdBeginRenderPass                             func,
                                    VkCommandBuffer                                      original_command_buffer,
                                    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
                                    VkSubpassContents                                    contents);

    void OverrideCmdBeginRenderPass2(const ApiCallInfo&                                   call_info,
                                     PFN_vkCmdBeginRenderPass2                            func,
                                     VkCommandBuffer                                      original_command_buffer,
                                     StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
                                     StructPointerDecoder<Decoded_VkSubpassBeginInfo>*    pSubpassBeginInfo);

    void OverrideCmdEndRenderPass(const ApiCallInfo&     call_info,
                                  PFN_vkCmdEndRenderPass func,
                                  VkCommandBuffer        original_command_buffer);

    void OverrideCmdEndRenderPass2(const ApiCallInfo&                              call_info,
                                   PFN_vkCmdEndRenderPass2                         func,
                                   VkCommandBuffer                                 original_command_buffer,
                                   StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);

    void OverrideCmdNextSubpass(const ApiCallInfo&   call_info,
                                PFN_vkCmdNextSubpass func,
                                VkCommandBuffer      original_command_buffer,
                                VkSubpassContents    contents);

    void OverrideCmdNextSubpass2(const ApiCallInfo&                                call_info,
                                 PFN_vkCmdNextSubpass2                             func,
                                 VkCommandBuffer                                   original_command_buffer,
                                 StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
                                 StructPointerDecoder<Decoded_VkSubpassEndInfo>*   pSubpassEndInfo);

    void OverrideCmdBindPipeline(const ApiCallInfo&    call_info,
                                 PFN_vkCmdBindPipeline func,
                                 VkCommandBuffer       original_command_buffer,
                                 VkPipelineBindPoint   pipelineBindPoint,
                                 const PipelineInfo*   pipeline);

    void OverrideCmdDispatch(const ApiCallInfo& call_info,
                             PFN_vkCmdDispatch  func,
                             VkCommandBuffer    original_command_buffer,
                             uint32_t           groupCountX,
                             uint32_t           groupCountY,
                             uint32_t           groupCountZ);

    void OverrideCmdDispatchIndirect(const ApiCallInfo&        call_info,
                                     PFN_vkCmdDispatchIndirect func,
                                     VkCommandBuffer           original_command_buffer,
                                     const BufferInfo*         buffer_info,
                                     VkDeviceSize              offset);

    void
    OverrideCmdTraceRaysKHR(const ApiCallInfo&                                             call_info,
                            PFN_vkCmdTraceRaysKHR                                          func,
                            VkCommandBuffer                                                original_command_buffer,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
                            StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
                            uint32_t                                                       width,
                            uint32_t                                                       height,
                            uint32_t                                                       depth);

    void OverrideCmdBindDescriptorSets(const ApiCallInfo&          call_info,
                                       PFN_vkCmdBindDescriptorSets func,
                                       VkCommandBuffer             original_command_buffer,
                                       VkPipelineBindPoint         pipeline_bind_point,
                                       const PipelineLayoutInfo*   layout_info,
                                       uint32_t                    first_set,
                                       uint32_t                    descriptor_sets_count,
                                       const format::HandleId*     descriptor_sets_ids,
                                       uint32_t                    dynamicOffsetCount,
                                       const uint32_t*             pDynamicOffsets);

    void OverrideCmdBindIndexBuffer(const ApiCallInfo&       call_info,
                                    PFN_vkCmdBindIndexBuffer func,
                                    VkCommandBuffer          original_command_buffer,
                                    const BufferInfo*        buffer,
                                    VkDeviceSize             offset,
                                    VkIndexType              indexType);

    void OverrideCmdBindVertexBuffers(const ApiCallInfo&         call_info,
                                      PFN_vkCmdBindVertexBuffers func,
                                      VkCommandBuffer            original_command_buffer,
                                      uint32_t                   firstBinding,
                                      uint32_t                   bindingCount,
                                      const format::HandleId*    buffer_ids,
                                      const VkDeviceSize*        pOffsets);

    VkResult QueueSubmit(const std::vector<VkSubmitInfo>& modified_submit_infos,
                         const encode::DeviceTable&       device_table,
                         VkQueue                          queue,
                         VkFence                          fence,
                         uint64_t                         index);

    bool MustDumpQueueSubmitIndex(uint64_t index) const;

    bool MustDumpDrawCall(VkCommandBuffer original_command_buffer, uint64_t dc_index) const;

    bool MustDumpDispatch(VkCommandBuffer original_command_buffer, uint64_t index) const;

    bool MustDumpTraceRays(VkCommandBuffer original_command_buffer, uint64_t index) const;

    bool DumpingBeginCommandBufferIndex(uint64_t index) const;

    bool IsRecording(VkCommandBuffer original_command_buffer) const;

    using cmd_buf_it = std::vector<VkCommandBuffer>::const_iterator;

    bool
    GetDrawCallActiveCommandBuffers(VkCommandBuffer original_command_buffer, cmd_buf_it& first, cmd_buf_it& last) const;

    VkCommandBuffer GetDispatchRaysCommandBuffer(VkCommandBuffer original_command_buffer) const;

  private:
    struct descriptor_set_bindings
    {
        // storage images
        std::unordered_map<uint32_t, const ImageInfo*> image_infos;

        // storage and texel buffers
        std::unordered_map<uint32_t, const BufferInfo*> buffer_infos;
    };

    using descriptor_set_t = std::unordered_map<uint32_t, descriptor_set_bindings>;

    enum PipelineBindPoints
    {
        kBindPoint_graphics = 0,
        kBindPoint_compute,
        kBindPoint_ray_tracing,

        kBindPoint_count
    };

    static PipelineBindPoints VkPipelineBindPointToPipelineBindPoint(VkPipelineBindPoint bind_point)
    {
        switch (bind_point)
        {
            case VK_PIPELINE_BIND_POINT_GRAPHICS:
                return kBindPoint_graphics;
            case VK_PIPELINE_BIND_POINT_COMPUTE:
                return kBindPoint_compute;
            case VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR:
                return kBindPoint_ray_tracing;
            default:
                GFXRECON_LOG_ERROR("Unrecognized pipeline bind point (%d)", bind_point);
                assert(0);
                return kBindPoint_count;
        }
    }

    // This class handles the context related to dumping the draw call render targets
    struct DrawCallsDumpingContext
    {
        DrawCallsDumpingContext(const std::vector<uint64_t>&              dc_indices,
                                const std::vector<std::vector<uint64_t>>& rp_indices,
                                const VulkanObjectInfoTable&              object_info_table,
                                bool                                      dump_resources_before,
                                const std::string&                        dump_resource_path,
                                util::ScreenshotFormat                    image_file_format,
                                float                                     dump_resource_scale,
                                VulkanReplayDumpResourcesJson*            dump_json,
                                bool                                      dump_vertex_index_buffers);

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

        VkResult CloneCommandBuffer(const CommandBufferInfo*     orig_cmd_buf_info,
                                    const encode::DeviceTable*   dev_table,
                                    const encode::InstanceTable* inst_table);

        VkResult CloneRenderPass(const RenderPassInfo* original_render_pass);

        VkResult BeginRenderPass(const RenderPassInfo*  render_pass_info,
                                 uint32_t               clear_value_count,
                                 const VkClearValue*    p_clear_values,
                                 const FramebufferInfo* framebuffer_info,
                                 const VkRect2D&        render_area,
                                 VkSubpassContents      contents);

        void NextSubpass(VkSubpassContents contents);

        void EndRenderPass();

        void BindVertexBuffers(uint64_t                              index,
                               uint32_t                              firstBinding,
                               const std::vector<const BufferInfo*>& buffer_infos,
                               const VkDeviceSize*                   pOffsets);

        void
        BindIndexBuffer(uint64_t index, const BufferInfo* buffer_info, VkDeviceSize offset, VkIndexType index_type);

        void FinalizeCommandBuffer();

        void SetRenderTargets(const std::vector<const ImageInfo*>& color_att_imgs,
                              const ImageInfo*                     depth_att_img,
                              bool                                 new_renderpass);

        void SetRenderArea(const VkRect2D& new_render_area);

        uint32_t GetDrawCallActiveCommandBuffers(cmd_buf_it& first, cmd_buf_it& last) const;

        VkResult DumpDrawCallsAttachments(
            VkQueue queue, uint64_t qs_index, uint64_t bcb_index, const VkSubmitInfo& submit_info, VkFence fence);

        VkResult DumpRenderTargetAttachments(uint64_t cmd_buf_index, uint64_t qs_index, uint64_t bcb_index) const;

        VkResult DumpVertexIndexBuffers();

        descriptor_set_t bound_descriptor_sets[kBindPoint_count];

        std::string
        GenerateImageFilename(VkFormat format, uint64_t cmd_buf_index, uint64_t dc_index, int attachment_index) const;

        std::string GenerateVertexBufferFilename(uint64_t bind_vertex_buffer_index, uint32_t binding) const;

        std::string GenerateIndexBufferFilename(uint64_t bind_index_buffer_index, VkIndexType type) const;

        using RenderPassSubpassPair = std::pair<uint64_t, uint64_t>;
        RenderPassSubpassPair GetRenderPassIndex(uint64_t dc_index) const;
        size_t                CmdBufToDCVectorIndex(size_t cmd_buf_index) const;

        void DestroyMutableResourceBackups();

        void ReleaseIndirectDrawParams();

        VkResult BackUpMutableResources(VkQueue queue);

        VkResult RevertMutableResources(VkQueue queue);

        const CommandBufferInfo*           original_command_buffer_info;
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
        bool                               inside_renderpass;
        VulkanReplayDumpResourcesJson*     p_dump_json;
        bool                               dump_vertex_index_buffers;

        std::vector<std::vector<VkRenderPass>> render_pass_clones;

        struct RenderTargets
        {
            RenderTargets() : depth_att_img(nullptr) {}

            std::vector<const ImageInfo*> color_att_imgs;
            const ImageInfo*              depth_att_img;
        };

        // render_targets is basically a 2d array (vector of vectors). It is indexed like render_targets[rp][sp]
        // where rp specifies the render pass and sp the subpass.
        std::vector<std::vector<RenderTargets>> render_targets;

        // Render area is constant between subpasses so this array will be single dimension array
        std::vector<VkRect2D> render_area;

        // Keep track of bound vertex buffers
        struct BoundVertexBuffersInfo
        {
            BoundVertexBuffersInfo() : gr_pipeline_info(nullptr) {}

            struct BufferPerBinding
            {
                BufferPerBinding() : buffer_info(nullptr), offset(0) {}
                BufferPerBinding(const BufferInfo* buffer_info, VkDeviceSize offset) :
                    buffer_info(buffer_info), offset(offset)
                {}

                const BufferInfo* buffer_info;
                VkDeviceSize      offset;
            };

            // One entry for each vertex buffer bound at each binding
            std::unordered_map<uint32_t, BufferPerBinding> bound_vertex_buffer_per_binding;

            // A list of all draw calls that reference these vertex buffers
            std::vector<uint64_t> referencing_draw_calls;

            // The currently bound pipeline
            const PipelineInfo* gr_pipeline_info;
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

            BoundIndexBuffer(const BufferInfo* buffer_info, VkDeviceSize offset, VkIndexType index_type) :
                buffer_info(buffer_info), offset(offset), index_type(index_type)
            {}

            const BufferInfo* buffer_info;
            VkDeviceSize      offset;
            VkIndexType       index_type;

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
                    GFXRECON_LOG_ERROR(
                        "%s() Unrecognized draw call type (%u)", __func__, static_cast<uint32_t>(dc_type))
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
                    GFXRECON_LOG_ERROR(
                        "%s() Unrecognized draw call type (%u)", __func__, static_cast<uint32_t>(dc_type))
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
                    GFXRECON_LOG_ERROR(
                        "%s() Unrecognized draw call type (%u)", __func__, static_cast<uint32_t>(dc_type))
                    assert(0);
                    return false;
            }
        }

        struct DrawCallParameters
        {
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
                    // handle the memory allocation ourselves.
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
                    // handle the memory allocation ourselves.
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
                       type == DrawCallTypes::kDrawIndirectCountKHR ||
                       type == DrawCallTypes::kDrawIndexedIndirectCountKHR);
            }

            DrawCallTypes type;

            uint64_t referenced_bind_vertex_buffers;
            uint64_t referenced_bind_index_buffer;
        };

        // One entry for each draw call
        std::unordered_map<uint64_t, DrawCallParameters> draw_call_params;

        void CopyVertexIndexBufferInfo(uint64_t dc_index, DrawCallParameters& dc_params);

        VkResult CopyIndirectDrawParameters(DrawCallParameters& dc_params);

        VkResult FetchDrawIndirectParams();

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
        const VulkanObjectInfoTable&            object_info_table;
        const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props;
    };

    // This class handles the context related to dumping Dispatch and TraceRays resouces
    struct DispatchTraceRaysDumpingContext
    {
        DispatchTraceRaysDumpingContext(const std::vector<uint64_t>&   dispatch_indices,
                                        const std::vector<uint64_t>&   trace_rays_indices,
                                        const VulkanObjectInfoTable&   object_info_table,
                                        bool                           dump_resources_before,
                                        const std::string&             dump_resource_path,
                                        util::ScreenshotFormat         image_file_format,
                                        float                          dump_resources_scale,
                                        VulkanReplayDumpResourcesJson* p_dump_json);

        ~DispatchTraceRaysDumpingContext();

        VkResult CloneCommandBuffer(const CommandBufferInfo*     orig_cmd_buf_info,
                                    const encode::DeviceTable*   dev_table,
                                    const encode::InstanceTable* inst_table);

        VkCommandBuffer GetDispatchRaysCommandBuffer() const { return DR_command_buffer; }

        void BindPipeline(VkPipelineBindPoint bind_point, const PipelineInfo* pipeline);

        bool IsRecording() const;

        bool MustDumpDispatch(uint64_t index) const;

        bool MustDumpTraceRays(uint64_t index) const;

        std::string GenerateImageFilename(VkFormat format,
                                          bool     is_dispatch,
                                          uint64_t index,
                                          uint32_t desc_set,
                                          uint32_t desc_binding,
                                          bool     before_cmd) const;

        std::string GenerateBufferFilename(
            bool is_dispatch, uint64_t index, uint32_t desc_set, uint32_t desc_binding, bool before_cmd) const;

        void BindDescriptorSets(VkPipelineBindPoint                          pipeline_bind_point,
                                uint32_t                                     first_set,
                                const std::vector<const DescriptorSetInfo*>& descriptor_sets_infos,
                                uint32_t                                     dynamicOffsetCount,
                                const uint32_t*                              pDynamicOffsets);

        void CloneDispatchRaysResources(uint64_t index, bool cloning_before_cmd, bool is_dispatch);

        VkResult DumpDispatchRaysMutableResources(
            VkQueue queue, uint64_t qs_index, uint64_t bcb_index, const VkSubmitInfo& submit_info, VkFence fence);

        VkResult DumpMutableResources(uint64_t bcb_index, uint64_t index, uint64_t qs_index, bool is_dispatch);

        void CopyImageResource(const ImageInfo* src_image_info, VkImage dst_image);

        void CopyBufferResource(const BufferInfo* src_buffer_info, VkBuffer dst_buffer);

        void DestroyMutableResourcesClones();

        void FinalizeCommandBuffer();

        const CommandBufferInfo*       original_command_buffer_info;
        VkCommandBuffer                DR_command_buffer;
        std::vector<uint64_t>          dispatch_indices;
        std::vector<uint64_t>          trace_rays_indices;
        const PipelineInfo*            bound_pipelines[kBindPoint_count];
        bool                           dump_resources_before;
        const std::string&             dump_resource_path;
        util::ScreenshotFormat         image_file_format;
        float                          dump_resources_scale;
        VulkanReplayDumpResourcesJson* p_dump_json;

        descriptor_set_t bound_descriptor_sets[kBindPoint_count];

        // For each Dispatch/TraceRays that we dump we create a clone of all mutable resources used in the
        // shaders/pipeline and the content of the original resources are copied into the clones
        struct DumpableResourceBackup
        {
            DumpableResourceBackup() = default;

            std::vector<const ImageInfo*>              original_images;
            std::vector<VkImage>                       images;
            std::vector<VkDeviceMemory>                image_memories;
            std::vector<std::pair<uint32_t, uint32_t>> image_desc_set_binding_pair;

            std::vector<const BufferInfo*>             original_buffers;
            std::vector<VkBuffer>                      buffers;
            std::vector<VkDeviceMemory>                buffer_memories;
            std::vector<std::pair<uint32_t, uint32_t>> buffer_desc_set_binding_pair;
        };

        // This map should hold copies of all mutable resources per Dispach/TraceRays index
        std::unordered_map<uint64_t, DumpableResourceBackup> mutable_resources_clones;
        std::unordered_map<uint64_t, DumpableResourceBackup> mutable_resources_clones_before;

        const encode::DeviceTable*              device_table;
        const encode::InstanceTable*            instance_table;
        const VulkanObjectInfoTable&            object_info_table;
        const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props;
        size_t                                  current_dispatch_index;
        size_t                                  current_trace_rays_index;
    };

    std::vector<uint64_t> QueueSubmit_indices_;

    // One per BeginCommandBuffer index
    std::unordered_map<uint64_t, DrawCallsDumpingContext>         draw_call_contexts;
    std::unordered_map<uint64_t, DispatchTraceRaysDumpingContext> dispatch_ray_contexts;

    // Mapping between the original VkCommandBuffer handle and BeginCommandBuffer index
    std::unordered_map<VkCommandBuffer, uint64_t> cmd_buf_begin_map_;

    bool recording_;
    bool dump_resources_before_;

    const VulkanObjectInfoTable& object_info_table_;

  private:
    VulkanReplayDumpResourcesJson dump_json_;

    bool UpdateRecordingStatus();

    VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
    FindDispatchRaysCommandBufferContext(uint64_t bcb_id);

    const VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
    FindDispatchRaysCommandBufferContext(uint64_t bcb_id) const;

    VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
    FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer);

    const VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
    FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer) const;

    VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
    FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer);

    const VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
    FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer) const;

    VulkanReplayDumpResourcesBase::DrawCallsDumpingContext* FindDrawCallCommandBufferContext(uint64_t bcb_id);

    const VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
    FindDrawCallCommandBufferContext(uint64_t bcb_id) const;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_BASE_H */
