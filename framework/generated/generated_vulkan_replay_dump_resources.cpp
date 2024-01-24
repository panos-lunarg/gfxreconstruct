/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include "generated/generated_vulkan_replay_dump_resources.h"

#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanReplayResourceDump::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindPipeline                       func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    const PipelineInfo*                         pipeline)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdBindPipeline(call_info, func, commandBuffer, pipelineBindPoint, pipeline);
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewport                        func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstViewport, viewportCount, pViewports);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstViewport, viewportCount, pViewports);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetScissor                         func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstScissor, scissorCount, pScissors);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstScissor, scissorCount, pScissors);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetLineWidth                       func,
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, lineWidth);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, lineWidth);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBias                       func,
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetBlendConstants                  func,
    VkCommandBuffer                             commandBuffer,
    const float*                                blendConstants)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, blendConstants);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, blendConstants);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBounds                     func,
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, minDepthBounds, maxDepthBounds);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, minDepthBounds, maxDepthBounds);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilCompareMask              func,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, faceMask, compareMask);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, faceMask, compareMask);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilWriteMask                func,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, faceMask, writeMask);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, faceMask, writeMask);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilReference                func,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, faceMask, reference);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, faceMask, reference);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindDescriptorSets                 func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdBindDescriptorSets(call_info, func, commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets->GetPointer(), dynamicOffsetCount, pDynamicOffsets);
    }
}

void VulkanReplayResourceDump::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindIndexBuffer                    func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, buffer, offset, indexType);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, buffer, offset, indexType);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindVertexBuffers                  func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstBinding, bindingCount, pBuffers, pOffsets);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstBinding, bindingCount, pBuffers, pOffsets);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDraw                               func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdDraw(call_info, func, commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndexed                        func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdDrawIndexed(call_info, func, commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndirect                       func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdDrawIndirect(call_info, func, commandBuffer, buffer, offset, drawCount, stride);
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndexedIndirect                func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdDrawIndexedIndirect(call_info, func, commandBuffer, buffer, offset, drawCount, stride);
    }
}

void VulkanReplayResourceDump::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDispatch                           func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdDispatch(call_info, func, commandBuffer, groupCountX, groupCountY, groupCountZ);
    }
}

void VulkanReplayResourceDump::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDispatchIndirect                   func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdDispatchIndirect(call_info, func, commandBuffer, buffer, offset);
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyBuffer                         func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, srcBuffer, dstBuffer, regionCount, pRegions);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, srcBuffer, dstBuffer, regionCount, pRegions);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyImage                          func,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBlitImage                          func,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyBufferToImage                  func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyImageToBuffer                  func,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdUpdateBuffer                       func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, dstBuffer, dstOffset, dataSize, pData);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, dstBuffer, dstOffset, dataSize, pData);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdFillBuffer                         func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, dstBuffer, dstOffset, size, data);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, dstBuffer, dstOffset, size, data);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdClearColorImage                    func,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, image, imageLayout, pColor, rangeCount, pRanges);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, image, imageLayout, pColor, rangeCount, pRanges);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdClearDepthStencilImage             func,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, image, imageLayout, pDepthStencil, rangeCount, pRanges);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdClearAttachments                   func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, attachmentCount, pAttachments, rectCount, pRects);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, attachmentCount, pAttachments, rectCount, pRects);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResolveImage                       func,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetEvent                           func,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, event, stageMask);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, event, stageMask);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResetEvent                         func,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, event, stageMask);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, event, stageMask);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdWaitEvents(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWaitEvents                         func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPipelineBarrier                    func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginQuery                         func,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, queryPool, query, flags);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, queryPool, query, flags);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndQuery                           func,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, queryPool, query);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, queryPool, query);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResetQueryPool                     func,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, queryPool, firstQuery, queryCount);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, queryPool, firstQuery, queryCount);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteTimestamp                     func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pipelineStage, queryPool, query);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pipelineStage, queryPool, query);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyQueryPoolResults(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyQueryPoolResults               func,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdPushConstants(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPushConstants                      func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, layout, stageFlags, offset, size, pValues);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, layout, stageFlags, offset, size, pValues);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginRenderPass                    func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdBeginRenderPass(call_info, func, commandBuffer, pRenderPassBegin, contents);
    }
}

void VulkanReplayResourceDump::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdNextSubpass                        func,
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdNextSubpass(call_info, func, commandBuffer, contents);
    }
}

void VulkanReplayResourceDump::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndRenderPass                      func,
    VkCommandBuffer                             commandBuffer)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdEndRenderPass(call_info, func, commandBuffer);
    }
}

void VulkanReplayResourceDump::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdExecuteCommands                    func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, commandBufferCount, pCommandBuffers);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, commandBufferCount, pCommandBuffers);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDeviceMask                      func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, deviceMask);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, deviceMask);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDispatchBase                       func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndirectCount                  func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdDrawIndirectCount(call_info, func, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndexedIndirectCount           func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdDrawIndexedIndirectCount(call_info, func, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanReplayResourceDump::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginRenderPass2                   func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdBeginRenderPass2(call_info, func, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    }
}

void VulkanReplayResourceDump::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdNextSubpass2                       func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdNextSubpass2(call_info, func, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }
}

void VulkanReplayResourceDump::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndRenderPass2                     func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdEndRenderPass2(call_info, func, commandBuffer, pSubpassEndInfo);
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetEvent2                          func,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, event, pDependencyInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, event, pDependencyInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResetEvent2                        func,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, event, stageMask);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, event, stageMask);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWaitEvents2                        func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, eventCount, pEvents, pDependencyInfos);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, eventCount, pEvents, pDependencyInfos);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPipelineBarrier2                   func,
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pDependencyInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pDependencyInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteTimestamp2                    func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, stage, queryPool, query);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, stage, queryPool, query);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyBuffer2                        func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pCopyBufferInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pCopyBufferInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyImage2                         func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pCopyImageInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pCopyImageInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyBufferToImage2                 func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pCopyBufferToImageInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pCopyBufferToImageInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyImageToBuffer2                 func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pCopyImageToBufferInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pCopyImageToBufferInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBlitImage2                         func,
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pBlitImageInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pBlitImageInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResolveImage2                      func,
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pResolveImageInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pResolveImageInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginRendering                     func,
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pRenderingInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pRenderingInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndRendering                       func,
    VkCommandBuffer                             commandBuffer)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCullMode                        func,
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, cullMode);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, cullMode);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetFrontFace                       func,
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, frontFace);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, frontFace);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPrimitiveTopology               func,
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, primitiveTopology);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, primitiveTopology);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewportWithCount               func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, viewportCount, pViewports);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, viewportCount, pViewports);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetScissorWithCount                func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, scissorCount, pScissors);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, scissorCount, pScissors);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindVertexBuffers2                 func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthTestEnable                 func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, depthTestEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, depthTestEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthWriteEnable                func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, depthWriteEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, depthWriteEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthCompareOp                  func,
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, depthCompareOp);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, depthCompareOp);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBoundsTestEnable           func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, depthBoundsTestEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, depthBoundsTestEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilTestEnable               func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, stencilTestEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, stencilTestEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilOp                       func,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, faceMask, failOp, passOp, depthFailOp, compareOp);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, faceMask, failOp, passOp, depthFailOp, compareOp);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRasterizerDiscardEnable         func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, rasterizerDiscardEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, rasterizerDiscardEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBiasEnable                 func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, depthBiasEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, depthBiasEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPrimitiveRestartEnable          func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, primitiveRestartEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, primitiveRestartEnable);
        }
    }
}










void VulkanReplayResourceDump::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginVideoCodingKHR                func,
    VkCommandBuffer                             commandBuffer,
    const VkVideoBeginCodingInfoKHR*            pBeginInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pBeginInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pBeginInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndVideoCodingKHR                  func,
    VkCommandBuffer                             commandBuffer,
    const VkVideoEndCodingInfoKHR*              pEndCodingInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pEndCodingInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pEndCodingInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdControlVideoCodingKHR              func,
    VkCommandBuffer                             commandBuffer,
    const VkVideoCodingControlInfoKHR*          pCodingControlInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pCodingControlInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pCodingControlInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDecodeVideoKHR                     func,
    VkCommandBuffer                             commandBuffer,
    const VkVideoDecodeInfoKHR*                 pDecodeInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pDecodeInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pDecodeInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginRenderingKHR                  func,
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pRenderingInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pRenderingInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndRenderingKHR                    func,
    VkCommandBuffer                             commandBuffer)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer);
        }
    }
}


void VulkanReplayResourceDump::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDeviceMaskKHR                   func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, deviceMask);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, deviceMask);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDispatchBaseKHR                    func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
        }
    }
}









void VulkanReplayResourceDump::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPushDescriptorSetKHR               func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
        }
    }
}


void VulkanReplayResourceDump::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginRenderPass2KHR                func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdBeginRenderPass2(call_info, func, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    }
}

void VulkanReplayResourceDump::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdNextSubpass2KHR                    func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdNextSubpass2(call_info, func, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }
}

void VulkanReplayResourceDump::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndRenderPass2KHR                  func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdEndRenderPass2(call_info, func, commandBuffer, pSubpassEndInfo);
    }
}












void VulkanReplayResourceDump::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndirectCountKHR               func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdDrawIndirectCountKHR(call_info, func, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndexedIndirectCountKHR        func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdDrawIndexedIndirectCountKHR(call_info, func, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}


void VulkanReplayResourceDump::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetFragmentShadingRateKHR          func,
    VkCommandBuffer                             commandBuffer,
    const VkExtent2D*                           pFragmentSize,
    const VkFragmentShadingRateCombinerOpKHR*   combinerOps)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pFragmentSize, combinerOps);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pFragmentSize, combinerOps);
        }
    }
}






void VulkanReplayResourceDump::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEncodeVideoKHR                     func,
    VkCommandBuffer                             commandBuffer,
    const VkVideoEncodeInfoKHR*                 pEncodeInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pEncodeInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pEncodeInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetEvent2KHR                       func,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, event, pDependencyInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, event, pDependencyInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResetEvent2KHR                     func,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, event, stageMask);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, event, stageMask);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWaitEvents2KHR                     func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, eventCount, pEvents, pDependencyInfos);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, eventCount, pEvents, pDependencyInfos);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPipelineBarrier2KHR                func,
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pDependencyInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pDependencyInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteTimestamp2KHR                 func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, stage, queryPool, query);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, stage, queryPool, query);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteBufferMarker2AMD              func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, stage, dstBuffer, dstOffset, marker);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, stage, dstBuffer, dstOffset, marker);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyBuffer2KHR                     func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pCopyBufferInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pCopyBufferInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyImage2KHR                      func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pCopyImageInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pCopyImageInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyBufferToImage2KHR              func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pCopyBufferToImageInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pCopyBufferToImageInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyImageToBuffer2KHR              func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pCopyImageToBufferInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pCopyImageToBufferInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBlitImage2KHR                      func,
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pBlitImageInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pBlitImageInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResolveImage2KHR                   func,
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pResolveImageInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pResolveImageInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdTraceRaysIndirect2KHR              func,
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, indirectDeviceAddress);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, indirectDeviceAddress);
        }
    }
}


void VulkanReplayResourceDump::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindIndexBuffer2KHR                func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, buffer, offset, size, indexType);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, buffer, offset, size, indexType);
        }
    }
}



void VulkanReplayResourceDump::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindDescriptorSets2KHR             func,
    VkCommandBuffer                             commandBuffer,
    const VkBindDescriptorSetsInfoKHR*          pBindDescriptorSetsInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pBindDescriptorSetsInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pBindDescriptorSetsInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPushConstants2KHR                  func,
    VkCommandBuffer                             commandBuffer,
    const VkPushConstantsInfoKHR*               pPushConstantsInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pPushConstantsInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pPushConstantsInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPushDescriptorSet2KHR              func,
    VkCommandBuffer                             commandBuffer,
    const VkPushDescriptorSetInfoKHR*           pPushDescriptorSetInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pPushDescriptorSetInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pPushDescriptorSetInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdPushDescriptorSetWithTemplate2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPushDescriptorSetWithTemplate2KHR  func,
    VkCommandBuffer                             commandBuffer,
    const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pPushDescriptorSetWithTemplateInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pPushDescriptorSetWithTemplateInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDescriptorBufferOffsets2EXT     func,
    VkCommandBuffer                             commandBuffer,
    const VkSetDescriptorBufferOffsetsInfoEXT*  pSetDescriptorBufferOffsetsInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pSetDescriptorBufferOffsetsInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pSetDescriptorBufferOffsetsInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT func,
    VkCommandBuffer                             commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pBindDescriptorBufferEmbeddedSamplersInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pBindDescriptorBufferEmbeddedSamplersInfo);
        }
    }
}



void VulkanReplayResourceDump::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDebugMarkerBeginEXT                func,
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pMarkerInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pMarkerInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDebugMarkerEndEXT                  func,
    VkCommandBuffer                             commandBuffer)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDebugMarkerInsertEXT               func,
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pMarkerInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pMarkerInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindTransformFeedbackBuffersEXT    func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginTransformFeedbackEXT          func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndTransformFeedbackEXT            func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginQueryIndexedEXT               func,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, queryPool, query, flags, index);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, queryPool, query, flags, index);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndQueryIndexedEXT                 func,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, queryPool, query, index);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, queryPool, query, index);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndirectByteCountEXT           func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    VkBuffer                                    counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
        }
    }
}


void VulkanReplayResourceDump::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndirectCountAMD               func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndexedIndirectCountAMD        func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
}






void VulkanReplayResourceDump::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginConditionalRenderingEXT       func,
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pConditionalRenderingBegin);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pConditionalRenderingBegin);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndConditionalRenderingEXT         func,
    VkCommandBuffer                             commandBuffer)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewportWScalingNV              func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstViewport, viewportCount, pViewportWScalings);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstViewport, viewportCount, pViewportWScalings);
        }
    }
}






void VulkanReplayResourceDump::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDiscardRectangleEXT             func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDiscardRectangleEnableEXT       func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    discardRectangleEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, discardRectangleEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, discardRectangleEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDiscardRectangleModeEXT         func,
    VkCommandBuffer                             commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, discardRectangleMode);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, discardRectangleMode);
        }
    }
}




void VulkanReplayResourceDump::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginDebugUtilsLabelEXT            func,
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pLabelInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pLabelInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndDebugUtilsLabelEXT              func,
    VkCommandBuffer                             commandBuffer)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdInsertDebugUtilsLabelEXT           func,
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pLabelInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pLabelInfo);
        }
    }
}


void VulkanReplayResourceDump::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetSampleLocationsEXT              func,
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pSampleLocationsInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pSampleLocationsInfo);
        }
    }
}



void VulkanReplayResourceDump::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindShadingRateImageNV             func,
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, imageView, imageLayout);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, imageView, imageLayout);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewportShadingRatePaletteNV    func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstViewport, viewportCount, pShadingRatePalettes);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstViewport, viewportCount, pShadingRatePalettes);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoarseSampleOrderNV             func,
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBuildAccelerationStructureNV       func,
    VkCommandBuffer                             commandBuffer,
    const VkAccelerationStructureInfoNV*        pInfo,
    VkBuffer                                    instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyAccelerationStructureNV        func,
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, dst, src, mode);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, dst, src, mode);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdTraceRaysNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdTraceRaysNV                        func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    raygenShaderBindingTableBuffer,
    VkDeviceSize                                raygenShaderBindingOffset,
    VkBuffer                                    missShaderBindingTableBuffer,
    VkDeviceSize                                missShaderBindingOffset,
    VkDeviceSize                                missShaderBindingStride,
    VkBuffer                                    hitShaderBindingTableBuffer,
    VkDeviceSize                                hitShaderBindingOffset,
    VkDeviceSize                                hitShaderBindingStride,
    VkBuffer                                    callableShaderBindingTableBuffer,
    VkDeviceSize                                callableShaderBindingOffset,
    VkDeviceSize                                callableShaderBindingStride,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteAccelerationStructuresPropertiesNV func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureNV*            pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
        }
    }
}


void VulkanReplayResourceDump::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteBufferMarkerAMD               func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pipelineStage, dstBuffer, dstOffset, marker);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pipelineStage, dstBuffer, dstOffset, marker);
        }
    }
}


void VulkanReplayResourceDump::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMeshTasksNV                    func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, taskCount, firstTask);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, taskCount, firstTask);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMeshTasksIndirectNV            func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, buffer, offset, drawCount, stride);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, buffer, offset, drawCount, stride);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMeshTasksIndirectCountNV       func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetExclusiveScissorEnableNV        func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkBool32*                             pExclusiveScissorEnables)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetExclusiveScissorNV              func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCheckpointNV                    func,
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pCheckpointMarker);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pCheckpointMarker);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPerformanceMarkerINTEL          func,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceMarkerInfoINTEL*         pMarkerInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pMarkerInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pMarkerInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPerformanceStreamMarkerINTEL    func,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceStreamMarkerInfoINTEL*   pMarkerInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pMarkerInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pMarkerInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPerformanceOverrideINTEL        func,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceOverrideInfoINTEL*       pOverrideInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pOverrideInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pOverrideInfo);
        }
    }
}










void VulkanReplayResourceDump::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetLineStippleEXT                  func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, lineStippleFactor, lineStipplePattern);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, lineStippleFactor, lineStipplePattern);
        }
    }
}


void VulkanReplayResourceDump::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCullModeEXT                     func,
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, cullMode);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, cullMode);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetFrontFaceEXT                    func,
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, frontFace);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, frontFace);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPrimitiveTopologyEXT            func,
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, primitiveTopology);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, primitiveTopology);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewportWithCountEXT            func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, viewportCount, pViewports);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, viewportCount, pViewports);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetScissorWithCountEXT             func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, scissorCount, pScissors);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, scissorCount, pScissors);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindVertexBuffers2EXT              func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthTestEnableEXT              func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, depthTestEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, depthTestEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthWriteEnableEXT             func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, depthWriteEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, depthWriteEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthCompareOpEXT               func,
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, depthCompareOp);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, depthCompareOp);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBoundsTestEnableEXT        func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, depthBoundsTestEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, depthBoundsTestEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilTestEnableEXT            func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, stencilTestEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, stencilTestEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilOpEXT                    func,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, faceMask, failOp, passOp, depthFailOp, compareOp);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, faceMask, failOp, passOp, depthFailOp, compareOp);
        }
    }
}



void VulkanReplayResourceDump::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPreprocessGeneratedCommandsNV      func,
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pGeneratedCommandsInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pGeneratedCommandsInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdExecuteGeneratedCommandsNV         func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, isPreprocessed, pGeneratedCommandsInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, isPreprocessed, pGeneratedCommandsInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindPipelineShaderGroupNV          func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline,
    uint32_t                                    groupIndex)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pipelineBindPoint, pipeline, groupIndex);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pipelineBindPoint, pipeline, groupIndex);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBias2EXT                   func,
    VkCommandBuffer                             commandBuffer,
    const VkDepthBiasInfoEXT*                   pDepthBiasInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pDepthBiasInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pDepthBiasInfo);
        }
    }
}



void VulkanReplayResourceDump::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetFragmentShadingRateEnumNV       func,
    VkCommandBuffer                             commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    const VkFragmentShadingRateCombinerOpKHR*   combinerOps)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, shadingRate, combinerOps);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, shadingRate, combinerOps);
        }
    }
}




void VulkanReplayResourceDump::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetVertexInputEXT                  func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT*  pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
        }
    }
}



void VulkanReplayResourceDump::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindInvocationMaskHUAWEI           func,
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, imageView, imageLayout);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, imageView, imageLayout);
        }
    }
}


void VulkanReplayResourceDump::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPatchControlPointsEXT           func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    patchControlPoints)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, patchControlPoints);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, patchControlPoints);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRasterizerDiscardEnableEXT      func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, rasterizerDiscardEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, rasterizerDiscardEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBiasEnableEXT              func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, depthBiasEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, depthBiasEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetLogicOpEXT                      func,
    VkCommandBuffer                             commandBuffer,
    VkLogicOp                                   logicOp)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, logicOp);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, logicOp);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPrimitiveRestartEnableEXT       func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, primitiveRestartEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, primitiveRestartEnable);
        }
    }
}


void VulkanReplayResourceDump::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetColorWriteEnableEXT             func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorWriteEnables)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, attachmentCount, pColorWriteEnables);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, attachmentCount, pColorWriteEnables);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMultiEXT                       func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawInfoEXT*                   pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMultiIndexedEXT                func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawIndexedInfoEXT*            pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    const int32_t*                              pVertexOffset)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBuildMicromapsEXT                  func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, infoCount, pInfos);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, infoCount, pInfos);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyMicromapEXT                    func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapInfoEXT*                pInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyMicromapToMemoryEXT            func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyMemoryToMicromapEXT            func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteMicromapsPropertiesEXT        func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    micromapCount,
    const VkMicromapEXT*                        pMicromaps,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawClusterHUAWEI                  func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, groupCountX, groupCountY, groupCountZ);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, groupCountX, groupCountY, groupCountZ);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawClusterIndirectHUAWEI          func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, buffer, offset);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, buffer, offset);
        }
    }
}



void VulkanReplayResourceDump::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdUpdatePipelineIndirectBufferNV     func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pipelineBindPoint, pipeline);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pipelineBindPoint, pipeline);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetTessellationDomainOriginEXT     func,
    VkCommandBuffer                             commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, domainOrigin);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, domainOrigin);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthClampEnableEXT             func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClampEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, depthClampEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, depthClampEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPolygonModeEXT                  func,
    VkCommandBuffer                             commandBuffer,
    VkPolygonMode                               polygonMode)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, polygonMode);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, polygonMode);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRasterizationSamplesEXT         func,
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, rasterizationSamples);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, rasterizationSamples);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetSampleMaskEXT                   func,
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       samples,
    const VkSampleMask*                         pSampleMask)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, samples, pSampleMask);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, samples, pSampleMask);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetAlphaToCoverageEnableEXT        func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, alphaToCoverageEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, alphaToCoverageEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetAlphaToOneEnableEXT             func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, alphaToOneEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, alphaToOneEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetLogicOpEnableEXT                func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    logicOpEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, logicOpEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, logicOpEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetColorBlendEnableEXT             func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorBlendEnables)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstAttachment, attachmentCount, pColorBlendEnables);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstAttachment, attachmentCount, pColorBlendEnables);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetColorBlendEquationEXT           func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendEquationEXT*              pColorBlendEquations)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstAttachment, attachmentCount, pColorBlendEquations);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstAttachment, attachmentCount, pColorBlendEquations);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetColorWriteMaskEXT               func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorComponentFlags*                pColorWriteMasks)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstAttachment, attachmentCount, pColorWriteMasks);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstAttachment, attachmentCount, pColorWriteMasks);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRasterizationStreamEXT          func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    rasterizationStream)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, rasterizationStream);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, rasterizationStream);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetConservativeRasterizationModeEXT func,
    VkCommandBuffer                             commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, conservativeRasterizationMode);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, conservativeRasterizationMode);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT func,
    VkCommandBuffer                             commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, extraPrimitiveOverestimationSize);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, extraPrimitiveOverestimationSize);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthClipEnableEXT              func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClipEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, depthClipEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, depthClipEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetSampleLocationsEnableEXT        func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, sampleLocationsEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, sampleLocationsEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetColorBlendAdvancedEXT           func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendAdvancedEXT*              pColorBlendAdvanced)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstAttachment, attachmentCount, pColorBlendAdvanced);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetProvokingVertexModeEXT          func,
    VkCommandBuffer                             commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, provokingVertexMode);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, provokingVertexMode);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetLineRasterizationModeEXT        func,
    VkCommandBuffer                             commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, lineRasterizationMode);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, lineRasterizationMode);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetLineStippleEnableEXT            func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, stippledLineEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, stippledLineEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthClipNegativeOneToOneEXT    func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, negativeOneToOne);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, negativeOneToOne);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewportWScalingEnableNV        func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, viewportWScalingEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, viewportWScalingEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewportSwizzleNV               func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportSwizzleNV*                  pViewportSwizzles)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, firstViewport, viewportCount, pViewportSwizzles);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, firstViewport, viewportCount, pViewportSwizzles);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoverageToColorEnableNV         func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, coverageToColorEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, coverageToColorEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoverageToColorLocationNV       func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, coverageToColorLocation);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, coverageToColorLocation);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoverageModulationModeNV        func,
    VkCommandBuffer                             commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, coverageModulationMode);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, coverageModulationMode);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoverageModulationTableEnableNV func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, coverageModulationTableEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, coverageModulationTableEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoverageModulationTableNV       func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    const float*                                pCoverageModulationTable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, coverageModulationTableCount, pCoverageModulationTable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, coverageModulationTableCount, pCoverageModulationTable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetShadingRateImageEnableNV        func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, shadingRateImageEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, shadingRateImageEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRepresentativeFragmentTestEnableNV func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, representativeFragmentTestEnable);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, representativeFragmentTestEnable);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoverageReductionModeNV         func,
    VkCommandBuffer                             commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, coverageReductionMode);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, coverageReductionMode);
        }
    }
}


void VulkanReplayResourceDump::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdOpticalFlowExecuteNV               func,
    VkCommandBuffer                             commandBuffer,
    VkOpticalFlowSessionNV                      session,
    const VkOpticalFlowExecuteInfoNV*           pExecuteInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, session, pExecuteInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, session, pExecuteInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindShadersEXT                     func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    stageCount,
    const VkShaderStageFlagBits*                pStages,
    const VkShaderEXT*                          pShaders)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, stageCount, pStages, pShaders);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, stageCount, pStages, pShaders);
        }
    }
}


void VulkanReplayResourceDump::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT func,
    VkCommandBuffer                             commandBuffer,
    VkImageAspectFlags                          aspectMask)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, aspectMask);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, aspectMask);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBuildAccelerationStructuresKHR     func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const * ppBuildRangeInfos)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, infoCount, pInfos, ppBuildRangeInfos);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, infoCount, pInfos, ppBuildRangeInfos);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBuildAccelerationStructuresIndirectKHR func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress*                      pIndirectDeviceAddresses,
    const uint32_t*                             pIndirectStrides,
    const uint32_t* const *                     ppMaxPrimitiveCounts)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyAccelerationStructureKHR       func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureInfoKHR*   pInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyAccelerationStructureToMemoryKHR func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyMemoryToAccelerationStructureKHR func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pInfo);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pInfo);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteAccelerationStructuresPropertiesKHR func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdTraceRaysKHR                       func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    if (IsRecording(commandBuffer))
    {
        OverrideCmdTraceRaysKHR(call_info, func, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    }
}

void VulkanReplayResourceDump::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdTraceRaysIndirectKHR               func,
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRayTracingPipelineStackSizeKHR  func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, pipelineStackSize);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, pipelineStackSize);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMeshTasksEXT                   func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, groupCountX, groupCountY, groupCountZ);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, groupCountX, groupCountY, groupCountZ);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMeshTasksIndirectEXT           func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, buffer, offset, drawCount, stride);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, buffer, offset, drawCount, stride);
        }
    }
}

void VulkanReplayResourceDump::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMeshTasksIndirectCountEXT      func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording(commandBuffer))
    {
        VulkanReplayResourceDumpBase::cmd_buf_it first, last;
        bool found = GetDrawCallActiveCommandBuffers(commandBuffer, first, last);
        if (found)
        {
            for (VulkanReplayResourceDumpBase::cmd_buf_it it = first; it < last; ++it)
            {
                 func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
            }
        }

        VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
             func(dispatch_rays_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
