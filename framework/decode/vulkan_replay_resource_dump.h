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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_RESOURCE_DUMPING_H
#define GFXRECON_DECODE_VULKAN_REPLAY_RESOURCE_DUMPING_H

#include "decode/vulkan_object_info_table.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "format/format.h"
#include "util/defines.h"
#include "vulkan/vulkan.h"

#include <vector>
#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReplayResourceDump
{
  public:
    VulkanReplayResourceDump() = delete;

    VulkanReplayResourceDump(const std::vector<uint64_t>&              begin_command_buffer_index,
                             const std::vector<std::vector<uint64_t>>& draw_indices,
                             const std::vector<std::vector<uint64_t>>& dispatch_indices,
                             const std::vector<std::vector<uint64_t>>& traceRays_indices,
                             const std::vector<uint64_t>&              queueSubmit_indices,
                             bool                                      isolate_draw,
                             const VulkanObjectInfoTable&              object_info_table);

    VkResult
    CloneCommandBuffer(uint64_t bcb_index, format::HandleId commandBuffer, const encode::DeviceTable* device_table);

    void FinalizeCommandBuffer(VkCommandBuffer original_command_buffer);

    VkResult ModifyAndSubmit(std::vector<VkSubmitInfo>  modified_submit_infos,
                             const encode::DeviceTable& device_table,
                             VkQueue                    queue,
                             VkFence                    fence,
                             uint64_t                   index);

    VkCommandBuffer GetCurrentCommandBuffer(VkCommandBuffer original_command_buffer) const;

    void SetRenderTargets(const std::vector<const ImageInfo*>&    color_att_imgs,
                          const std::vector<VkAttachmentStoreOp>& color_att_storeOps,
                          const std::vector<VkImageLayout>&       color_att_final_layouts,
                          const ImageInfo*                        depth_att_img,
                          VkAttachmentStoreOp                     depth_att_storeOp,
                          VkImageLayout                           depth_att_final_layout);

    void SetRenderArea(const VkRect2D& render_area) { render_targets.render_area = render_area; }

    // Call with vkCmdBindDescriptorSets to scan for dumpable resources
    void UpdateDescriptors(VkPipelineBindPoint     pipeline_bind_point,
                           uint32_t                first_set,
                           const format::HandleId* descriptor_sets_ids,
                           uint32_t                descriptor_sets_count);

    void EnterRenderPass() { inside_renderpass = true; }

    void ExitRenderPass() { inside_renderpass = false; }

    bool DumpingSubmissionIndex(uint64_t index) const;

    bool DumpingDrawCallIndex(VkCommandBuffer original_command_buffer, uint64_t index) const;

    bool DumpingDispatchIndex(VkCommandBuffer original_command_buffer, uint64_t index) const;

    bool DumpingTraceRaysIndex(VkCommandBuffer original_command_buffer, uint64_t index) const;

    bool DumpingBeginCommandBufferIndex(uint64_t index) const;

    bool IsRecording() const { return recording; }

    bool IsolateDrawCall() const { return isolate_draw_call; }

    using cmd_buf_it = std::vector<VkCommandBuffer>::const_iterator;
    void GetActiveCommandBuffers(VkCommandBuffer user_cmd_buffer, cmd_buf_it& first, cmd_buf_it& last) const;

  private:
    struct CommandBufferStack
    {
        CommandBufferStack(const std::vector<uint64_t>& dc_indices,
                           const std::vector<uint64_t>& dispatch_indices,
                           const std::vector<uint64_t>& traceRays_indices) :
            original_command_buffer_handle(VK_NULL_HANDLE),
            original_command_buffer_info(nullptr), command_buffers(dc_indices.size(), VK_NULL_HANDLE), current_index(0),
            dc_indices(std::move(dc_indices)), dispatch_indices(std::move(dispatch_indices)),
            traceRays_indices(std::move(traceRays_indices)), aux_command_buffer(VK_NULL_HANDLE), device_table(nullptr)
        {}

        VkCommandBuffer              original_command_buffer_handle;
        const CommandBufferInfo*     original_command_buffer_info;
        std::vector<VkCommandBuffer> command_buffers;
        uint32_t                     current_index;
        std::vector<uint64_t>        dc_indices;
        std::vector<uint64_t>        dispatch_indices;
        std::vector<uint64_t>        traceRays_indices;

        VkCommandBuffer aux_command_buffer;

        const encode::DeviceTable* device_table;
    };

    std::vector<uint64_t> QueueSubmit_indices;

    // One per BeginCommandBuffer index
    std::map<uint64_t, CommandBufferStack> cmd_buf_stacks;

    // Mapping between the original VkCommandBuffer handle and BeginCommandBuffer index
    std::map<VkCommandBuffer, uint64_t> cmd_buf_begin_map;

  private:
    bool UpdateRecordingStatus();

    void DumpAttachments(const CommandBufferStack& stack, uint64_t dc_index);

    void DumpResources(const CommandBufferStack& stack, uint64_t dc_index);

    VkResult RevertRenderTargetImageLayouts(const CommandBufferStack& stack, VkQueue queue);

    struct
    {
        std::vector<const ImageInfo*>    color_att_imgs;
        std::vector<VkAttachmentStoreOp> color_att_storeOps;
        std::vector<VkImageLayout>       color_att_final_layouts;

        const ImageInfo*    depth_att_img{ nullptr };
        VkAttachmentStoreOp depth_att_storeOp;
        VkImageLayout       depth_att_final_layout;

        VkRect2D render_area{ 0 };
    } render_targets;

    struct descriptor_set_bindings
    {
        std::map<uint32_t, const ImageInfo*>  image_infos;
        std::map<uint32_t, const BufferInfo*> buffer_infos;
    };

    using descriptor_set_t = std::map<uint32_t, descriptor_set_bindings>;

    enum DescriptorSetBindPoints
    {
        kBindPoint_graphics = 0,
        kBindPoint_compute,
        kBindPoint_ray_tracing,

        kBindPoint_count = 3
    };

    descriptor_set_t bound_descriptor_sets[kBindPoint_count];

    bool recording;
    bool inside_renderpass;
    bool isolate_draw_call;

    const VulkanObjectInfoTable& object_info_table_;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_DECODE_VULKAN_REPLAY_RESOURCE_DUMPING_H */
