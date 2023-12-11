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

    VulkanReplayResourceDump(uint64_t                     begin_command_buffer_index,
                             uint64_t                     cmdDraw_index,
                             uint64_t                     cmdDispatch_index,
                             uint64_t                     CmdTraceRaysKHR_index,
                             uint64_t                     QueueSubmit_index,
                             const VulkanObjectInfoTable& object_info_table) :
        BeginCommandBuffer_Index(begin_command_buffer_index),
        CmdDraw_Index(cmdDraw_index), CmdDispatch_Index(cmdDispatch_index),
        CmdTraceRaysKHR_Index(CmdTraceRaysKHR_index), QueueSubmit_Index(QueueSubmit_index), recording(false),
        inside_renderpass(false), object_info_table_(object_info_table)
    {}

    VkResult CloneCommandBuffer(format::HandleId commandBuffer, PFN_vkAllocateCommandBuffers func);

    void FinalizeCommandBuffer(const encode::DeviceTable& device_table);

    void ModifyCommandBufferSubmision(std::vector<VkSubmitInfo>& modified_submit_infos);

    VkCommandBuffer GetClonedCommandBuffer() const { return command_buffer; }

    // Call with vkCmdBeginRendering(KHR)
    void SetRenderTargets(const std::vector<const ImageInfo*>&    color_att_imgs,
                          const std::vector<VkAttachmentStoreOp>& color_att_storeOps,
                          const ImageInfo*                        depth_att_img,
                          VkAttachmentStoreOp                     depth_storeOp);

    void SetRenderArea(const VkRect2D& render_area) { render_targets.render_area = render_area; }

    // Call with vkCmdBindDescriptorSets to scan for dumpable resources
    void UpdateDescriptors(VkPipelineBindPoint     pipeline_bind_point,
                           uint32_t                first_set,
                           const format::HandleId* descriptor_sets_ids,
                           uint32_t                descriptor_sets_count);

    void DumpAttachments(const encode::DeviceTable* device_table, uint64_t index);

    void DumpResources(const encode::DeviceTable* device_table, uint64_t index);

    void EnterRenderPass() { inside_renderpass = true; }
    void ExitRenderPass() { inside_renderpass = false; }

    bool DumpingSubmissionIndex(uint64_t index) const
    {
        assert(!recording);

        return QueueSubmit_Index == index;
    }

    bool DumpingDrawCallIndex(uint64_t index) const
    {
        assert(recording);
        assert(command_buffer != VK_NULL_HANDLE);

        return CmdDraw_Index == index;
    }

    bool DumpingDispatchIndex(uint64_t index) const
    {
        assert(recording);
        assert(command_buffer != VK_NULL_HANDLE);

        return CmdDispatch_Index == index;
    }

    bool DumpingTraceRaysIndex(uint64_t index) const
    {
        assert(recording);
        assert(command_buffer != VK_NULL_HANDLE);

        return CmdTraceRaysKHR_Index == index;
    }

    bool DumpingBeginCommandBufferIndex(uint64_t index) const { return BeginCommandBuffer_Index == index; }

    bool IsRecording() const { return recording; }

  private:
    VkCommandBuffer  command_buffer                 = VK_NULL_HANDLE;
    format::HandleId original_command_buffer        = format::kNullHandleId;
    VkCommandBuffer  original_command_buffer_handle = VK_NULL_HANDLE;

    struct
    {
        std::vector<const ImageInfo*>    color_att_imgs;
        std::vector<VkAttachmentStoreOp> color_att_storeOps;

        const ImageInfo*    depth_att_img{ nullptr };
        VkAttachmentStoreOp depth_att_storeOp;

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
        BIND_POINT_GRAPHICS = 0,
        BIND_POINT_COMPUTE,
        BIND_POINT_RAY_TRACING,

        BIND_POINT_COUNT = 3
    };

    descriptor_set_t bound_descriptor_sets[BIND_POINT_COUNT];

    uint64_t BeginCommandBuffer_Index;
    uint64_t CmdDraw_Index;
    uint64_t CmdDispatch_Index;
    uint64_t CmdTraceRaysKHR_Index;
    uint64_t QueueSubmit_Index;

    bool recording;
    bool inside_renderpass;

    const VulkanObjectInfoTable& object_info_table_;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_DECODE_VULKAN_REPLAY_RESOURCE_DUMPING_H */
