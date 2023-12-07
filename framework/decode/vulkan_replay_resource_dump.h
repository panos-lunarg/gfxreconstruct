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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_RESOURCE_DUMPING
#define GFXRECON_DECODE_VULKAN_REPLAY_RESOURCE_DUMPING

#include "decode/vulkan_object_info_table.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "format/format.h"
#include "util/defines.h"
#include "vulkan/vulkan.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReplayResourceDump
{
  public:
    VulkanReplayResourceDump() = delete;

    VulkanReplayResourceDump(const VulkanObjectInfoTable& object_info_table) :
        recording(false), object_info_table_(object_info_table)
    {}

    VkResult CloneCommandBuffer(format::HandleId commandBuffer, PFN_vkAllocateCommandBuffers func);

    void FinalizeCommandBuffer(const encode::DeviceTable& device_table);

    void ModifyCommandBufferSubmision(std::vector<VkSubmitInfo>& modified_submit_infos);

    VkCommandBuffer GetClonedCommandBuffer() const { return command_buffer; }

    void SetRenderTargets(format::HandleId render_pass, format::HandleId frame_buffer, const VkRect2D& rp_area);

    void DetectWritableResources(const format::HandleId* descriptor_sets_ids, uint32_t descriptor_sets_count);

    void DumpAttachments(const encode::DeviceTable* device_table, uint64_t index);

    void DumpResources(const encode::DeviceTable* device_table, uint64_t index);

    bool DumpingSubmissionIndex(uint64_t index) const
    {
        assert(!recording);
        assert(command_buffer != VK_NULL_HANDLE);

        return g_dumpResourses_QueueSubmit_Index == index;
    }

    bool DumpingDrawCallIndex(uint64_t index) const
    {
        assert(recording);
        assert(command_buffer != VK_NULL_HANDLE);

        return g_dumpResourses_CmdDraw_Index == index;
    }

    bool DumpingBeginCommandBufferIndex(uint64_t index) const { return g_saveCmdBuf_BeginCommandBuffer_Index == index; }

    bool IsRecording() const { return recording; }

  private:
    VkCommandBuffer  command_buffer                 = VK_NULL_HANDLE;
    format::HandleId original_command_buffer        = format::kNullHandleId;
    VkCommandBuffer  original_command_buffer_handle = VK_NULL_HANDLE;

    struct
    {
        std::vector<VkAttachmentStoreOp> attachment_store_ops;
        std::vector<const ImageInfo*>    attachment_image_ids;
        VkRect2D                         rendering_arrea{};
    } render_targets;

    struct
    {
        std::vector<const ImageInfo*> image_infos;
    } storage_images;

    struct
    {
        std::vector<const BufferInfo*> buffer_infos;
    } storage_buffers;

    bool recording;

    const VulkanObjectInfoTable& object_info_table_;

    const uint64_t g_saveCmdBuf_BeginCommandBuffer_Index = 107;
    const uint64_t g_dumpResourses_CmdDraw_Index         = 114;
    const uint64_t g_dumpResourses_QueueSubmit_Index     = 579;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_DECODE_VULKAN_REPLAY_RESOURCE_DUMPING */
