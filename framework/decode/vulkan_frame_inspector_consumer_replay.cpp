/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
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

#include "decode/vulkan_frame_inspector_vulkan_commands_info.h"
#include "decode/vulkan_frame_inspector_indirect_commands_info.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "decode/vulkan_frame_inspector_consumer_base.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanFrameInspectorConsumerBase::ReplayCmdPipelineBarrier(CommandBufferInfo*                cmd_buf,
                                                                VulkanCommandPipelineBarrierInfo* cmd_info,
                                                                VkCommandBuffer                   vk_cmd,
                                                                VkDevice                          device)
{
    GetDeviceTable(device)->CmdPipelineBarrier(vk_cmd,
                                               cmd_info->srcStageMask,
                                               cmd_info->dstStageMask,
                                               cmd_info->dependencyFlags,
                                               static_cast<uint32_t>(cmd_info->MemoryBarriers.size()),
                                               cmd_info->MemoryBarriers.data(),
                                               static_cast<uint32_t>(cmd_info->BufferMemoryBarriers.size()),
                                               cmd_info->BufferMemoryBarriers.data(),
                                               static_cast<uint32_t>(cmd_info->ImageMemoryBarriers.size()),
                                               cmd_info->ImageMemoryBarriers.data());
}

void VulkanFrameInspectorConsumerBase::ReplayCmdBeginRenderpas(CommandBufferInfo*                cmd_buf,
                                                               VulkanCommandBeginRenderPassInfo* cmd_info,
                                                               VkCommandBuffer                   vk_cmd,
                                                               VkDevice                          device)
{
    const VkRenderPassBeginInfo bi = { VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
                                       nullptr,
                                       cmd_info->renderpass,
                                       cmd_info->framebuffer,
                                       cmd_info->renderArea,
                                       static_cast<uint32_t>(cmd_info->clear_values.size()),
                                       cmd_info->clear_values.data() };

    GetDeviceTable(device)->CmdBeginRenderPass(vk_cmd, &bi, cmd_info->contents);
}

void VulkanFrameInspectorConsumerBase::ReplayCmdEndRenderpass(CommandBufferInfo*              cmd_buf,
                                                              VulkanCommandEndRenderPassInfo* cmd_info,
                                                              VkCommandBuffer                 vk_cmd,
                                                              VkDevice                        device)
{
    GetDeviceTable(device)->CmdEndRenderPass(vk_cmd);
}

void VulkanFrameInspectorConsumerBase::ReplayCmdBindPipeline(CommandBufferInfo*             cmd_buf,
                                                             VulkanCommandBindPipelineInfo* cmd_info,
                                                             VkCommandBuffer                vk_cmd,
                                                             VkDevice                       device)
{
    GetDeviceTable(device)->CmdBindPipeline(vk_cmd, cmd_info->pipelineBindPoint, cmd_info->pipeline);
}

void VulkanFrameInspectorConsumerBase::ReplayCmdBindDescriptorSets(CommandBufferInfo*                   cmd_buf,
                                                                   VulkanCommandBindDescriptorSetsInfo* cmd_info,
                                                                   VkCommandBuffer                      vk_cmd,
                                                                   VkDevice                             device)
{
    GetDeviceTable(device)->CmdBindDescriptorSets(vk_cmd,
                                                  cmd_info->pipelineBindPoint,
                                                  cmd_info->pipeline_layout,
                                                  cmd_info->first_set,
                                                  static_cast<uint32_t>(cmd_info->descriptor_sets.size()),
                                                  cmd_info->descriptor_sets.size() ? cmd_info->descriptor_sets.data()
                                                                                   : nullptr,
                                                  static_cast<uint32_t>(cmd_info->dynamic_offsets.size()),
                                                  cmd_info->dynamic_offsets.data());
}

void VulkanFrameInspectorConsumerBase::ReplayCmdSetViewport(CommandBufferInfo*            cmd_buf,
                                                            VulkanCommandSetViewportInfo* cmd_info,
                                                            VkCommandBuffer               vk_cmd,
                                                            VkDevice                      device)
{
    GetDeviceTable(device)->CmdSetViewport(vk_cmd,
                                           cmd_info->first_viewport,
                                           static_cast<uint32_t>(cmd_info->viewports.size()),
                                           cmd_info->viewports.data());
}

void VulkanFrameInspectorConsumerBase::ReplayCmdSetScissor(CommandBufferInfo*           cmd_buf,
                                                           VulkanCommandSetScissorInfo* cmd_info,
                                                           VkCommandBuffer              vk_cmd,
                                                           VkDevice                     device)
{
    GetDeviceTable(device)->CmdSetScissor(
        vk_cmd, cmd_info->first_scissor, static_cast<uint32_t>(cmd_info->scissors.size()), cmd_info->scissors.data());
}

void VulkanFrameInspectorConsumerBase::ReplayCmdDraw(CommandBufferInfo*     cmd_buf,
                                                     VulkanCommandDrawInfo* cmd_info,
                                                     VkCommandBuffer        vk_cmd,
                                                     VkDevice               device)
{
    GetDeviceTable(device)->CmdDraw(
        vk_cmd, cmd_info->vertexCount, cmd_info->instanceCount, cmd_info->firstVertex, cmd_info->firstInstance);
}

void VulkanFrameInspectorConsumerBase::ReplayCmdDrawIndirect(CommandBufferInfo*             cmd_buf,
                                                             VulkanCommandDrawIndirectInfo* cmd_info,
                                                             VkCommandBuffer                vk_cmd,
                                                             VkDevice                       device)
{
    GetDeviceTable(device)->CmdDrawIndirect(
        vk_cmd, cmd_info->buffer_->handle, cmd_info->offset_, cmd_info->drawCount_, cmd_info->stride_);
}

format::CommandIndexType VulkanFrameInspectorConsumerBase::ReplayCommandBuffer(CommandBufferInfo*       cmd_buf,
                                                                               VkCommandBuffer          vk_cmd,
                                                                               format::CommandIndexType replay_until)
{
    VkDevice                 device            = GetObjectInfoTable().GetDeviceInfo(cmd_buf->parent_id)->handle;
    bool                     inside_renderpass = false;
    format::CommandIndexType last_index        = 0;

    for (auto& cmd : cmd_buf->command_list)
    {
        switch (cmd.second->type)
        {
            case decode::VULKAN_CMD_PIPELINE_BARRIER:
            {
                decode::VulkanCommandPipelineBarrierInfo* cmd_info =
                    dynamic_cast<decode::VulkanCommandPipelineBarrierInfo*>(cmd.second.get());
                assert(cmd_info);
                ReplayCmdPipelineBarrier(cmd_buf, cmd_info, vk_cmd, device);
            }
            break;
            case decode::VULKAN_CMD_BEGIN_RENDER_PASS:
            {
                decode::VulkanCommandBeginRenderPassInfo* cmd_info =
                    dynamic_cast<decode::VulkanCommandBeginRenderPassInfo*>(cmd.second.get());
                assert(cmd_info);
                ReplayCmdBeginRenderpas(cmd_buf, cmd_info, vk_cmd, device);
                inside_renderpass = true;
            }
            break;
            case decode::VULKAN_CMD_END_RENDER_PASS:
            {
                decode::VulkanCommandEndRenderPassInfo* cmd_info =
                    dynamic_cast<decode::VulkanCommandEndRenderPassInfo*>(cmd.second.get());
                assert(cmd_info);
                ReplayCmdEndRenderpass(cmd_buf, cmd_info, vk_cmd, device);
                inside_renderpass = false;
            }
            break;
            case decode::VULKAN_CMD_BIND_PIPELINE:
            {
                decode::VulkanCommandBindPipelineInfo* cmd_info =
                    dynamic_cast<decode::VulkanCommandBindPipelineInfo*>(cmd.second.get());
                assert(cmd_info);
                ReplayCmdBindPipeline(cmd_buf, cmd_info, vk_cmd, device);
            }
            break;
            case decode::VULKAN_CMD_BIND_DESCRIPTOR_SETS:
            {
                decode::VulkanCommandBindDescriptorSetsInfo* cmd_info =
                    dynamic_cast<decode::VulkanCommandBindDescriptorSetsInfo*>(cmd.second.get());
                assert(cmd_info);
                ReplayCmdBindDescriptorSets(cmd_buf, cmd_info, vk_cmd, device);
            }
            break;
            case decode::VULKAN_CMD_SET_VIEWPORT:
            {
                decode::VulkanCommandSetViewportInfo* cmd_info =
                    dynamic_cast<decode::VulkanCommandSetViewportInfo*>(cmd.second.get());
                assert(cmd_info);
                ReplayCmdSetViewport(cmd_buf, cmd_info, vk_cmd, device);
            }
            break;
            case decode::VULKAN_CMD_SET_SCISSOR:
            {
                decode::VulkanCommandSetScissorInfo* cmd_info =
                    dynamic_cast<decode::VulkanCommandSetScissorInfo*>(cmd.second.get());
                assert(cmd_info);
                ReplayCmdSetScissor(cmd_buf, cmd_info, vk_cmd, device);
            }
            break;
            case decode::VULKAN_CMD_DRAW_INDIRECT:
            {
                decode::VulkanCommandDrawIndirectInfo* cmd_info =
                    dynamic_cast<decode::VulkanCommandDrawIndirectInfo*>(cmd.second.get());
                assert(cmd_info);
                ReplayCmdDrawIndirect(cmd_buf, cmd_info, vk_cmd, device);
            }
            break;
            case decode::VULKAN_CMD_DRAW:
            {
                decode::VulkanCommandDrawInfo* cmd_info =
                    dynamic_cast<decode::VulkanCommandDrawInfo*>(cmd.second.get());
                assert(cmd_info);
                ReplayCmdDraw(cmd_buf, cmd_info, vk_cmd, device);
            }
            break;
            default:
                assert(0);
        }

        last_index = cmd.first;

        if (last_index == replay_until)
        {
            if (inside_renderpass)
            {
                ReplayCmdEndRenderpass(cmd_buf, nullptr, vk_cmd, device);
            }

            break;
        }
    }

    return last_index;
}

void VulkanFrameInspectorConsumerBase::ReplayQueueSubmit(QueueSubmitInfo*         submit_cmd,
                                                         format::CommandIndexType replay_until)
{
    assert(submit_cmd);
    assert(submit_cmd->type == SERIALIZED_CMD_QUEUE_SUBMIT);

    std::vector<VkSemaphore> wait_semaphores;
    for (auto& sem : submit_cmd->wait_semaphores)
    {
        auto sem_info = object_info_table_.GetSemaphoreInfo(sem);
        wait_semaphores.push_back(sem_info->handle);
    }

    std::vector<VkSemaphore> signal_semaphores;
    for (auto& sem : submit_cmd->signal_semaphores)
    {
        auto sem_info = object_info_table_.GetSemaphoreInfo(sem);
        signal_semaphores.push_back(sem_info->handle);
    }

    std::vector<VkCommandBuffer> command_buffers;
    for (auto& cmd_buf : submit_cmd->command_buffers)
    {
        auto                              cmd_buf_info = object_info_table_.GetCommandBufferInfo(cmd_buf);
        CommandPoolInfo*                  cmd_pool = GetObjectInfoTable().GetCommandPoolInfo(cmd_buf_info->parent_id);
        const VkCommandBufferAllocateInfo ai       = {
            VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO, nullptr, cmd_pool->handle, cmd_buf_info->level, 1
        };

        VkCommandBuffer new_cmd_buf;
        VkDevice        device = GetObjectInfoTable().GetDeviceInfo(cmd_pool->parent_id)->handle;
        VkResult        res    = GetDeviceTable(device)->AllocateCommandBuffers(device, &ai, &new_cmd_buf);
        if (res != VK_SUCCESS)
        {
            assert(0);
            return;
        }
        command_buffers.push_back(new_cmd_buf);

        if (ReplayCommandBuffer(cmd_buf_info, new_cmd_buf, replay_until) == replay_until)
        {
            break;
        }
    }

    VkSubmitInfo submit_info = { VK_STRUCTURE_TYPE_SUBMIT_INFO,
                                 nullptr,
                                 static_cast<uint32_t>(wait_semaphores.size()),
                                 wait_semaphores.size() ? wait_semaphores.data() : nullptr,
                                 submit_cmd->wait_dst_stage_mask.data(),
                                 static_cast<uint32_t>(command_buffers.size()),
                                 command_buffers.size() ? command_buffers.data() : nullptr,
                                 static_cast<uint32_t>(signal_semaphores.size()),
                                 signal_semaphores.size() ? signal_semaphores.data() : nullptr };
}

void VulkanFrameInspectorConsumerBase::Replay(format::CommandIndexType replay_until)
{
    for (const auto& sit : commands_)
    {
        decode::SerializedCommands* command_ptr = sit.second.get();

        switch (command_ptr->type)
        {
            case SERIALIZED_CMD_SET_EVENT:
            {
                decode::SetEventInfo* cmd_info = dynamic_cast<decode::SetEventInfo*>(command_ptr);
                assert(cmd_info);
            }
            break;
            case SERIALIZED_CMD_RESET_EVENT:
            {
                decode::ResetEventInfo* cmd_info = dynamic_cast<decode::ResetEventInfo*>(command_ptr);
                assert(cmd_info);
            }
            break;
            case SERIALIZED_CMD_WAIT_FOR_FENCES:
            {
                decode::WaitForFencesInfo* cmd_info = dynamic_cast<decode::WaitForFencesInfo*>(command_ptr);
                assert(cmd_info);
            }
            break;
            case SERIALIZED_CMD_RESET_FENCES:
            {
                decode::ResetFencesInfo* cmd_info = dynamic_cast<decode::ResetFencesInfo*>(command_ptr);
                assert(cmd_info);
            }
            break;
            case SERIALIZED_CMD_WAIT_SEMAPHORES:
            {
                decode::WaitSemaphoresInfo* cmd_info = dynamic_cast<decode::WaitSemaphoresInfo*>(command_ptr);
                assert(cmd_info);
            }
            break;
            case SERIALIZED_CMD_SIGNAL_SEMAPHORE:
            {
                decode::SignalSemaphore* cmd_info = dynamic_cast<decode::SignalSemaphore*>(command_ptr);
                assert(cmd_info);
            }
            break;
            case SERIALIZED_CMD_QUEUE_WAIT_IDLE:
            {
                decode::QueueWaitIdleInfo* cmd_info = dynamic_cast<decode::QueueWaitIdleInfo*>(command_ptr);
                assert(cmd_info);
            }
            break;
            case SERIALIZED_CMD_DEVICE_WAIT_IDLE:
            {
                decode::DeviceWaitIdle* cmd_info = dynamic_cast<decode::DeviceWaitIdle*>(command_ptr);
                assert(cmd_info);
            }
            break;
            case SERIALIZED_CMD_QUEUE_SUBMIT:
            {
                decode::QueueSubmitInfo* cmd_info = dynamic_cast<decode::QueueSubmitInfo*>(command_ptr);
                assert(cmd_info);
                ReplayQueueSubmit(cmd_info, replay_until);
            }
            break;
            case SERIALIZED_CMD_UPDATE_DESCRIPTOR_SETS:
            {
                decode::UpdateDescriptorSetsInfo* cmd_info =
                    dynamic_cast<decode::UpdateDescriptorSetsInfo*>(command_ptr);
                assert(cmd_info);
            }
            break;
            case SERIALIZED_CMD_GFXR_FILL_MEMORY:
            {
                decode::QueueSubmitInfo* cmd_info = dynamic_cast<decode::QueueSubmitInfo*>(command_ptr);
                assert(cmd_info);
            }
            break;
            case SERIALIZED_CMD_GFXR_BEGIN_RESOURCE_INIT:
            {
                decode::QueueSubmitInfo* cmd_info = dynamic_cast<decode::QueueSubmitInfo*>(command_ptr);
                assert(cmd_info);
            }
            break;
            case SERIALIZED_CMD_GFXR_END_RESOURCE_INIT:
            {
                decode::QueueSubmitInfo* cmd_info = dynamic_cast<decode::QueueSubmitInfo*>(command_ptr);
                assert(cmd_info);
            }
            break;
            case SERIALIZED_CMD_GFXR_INIT_BUFFER:
            {
                decode::QueueSubmitInfo* cmd_info = dynamic_cast<decode::QueueSubmitInfo*>(command_ptr);
                assert(cmd_info);
            }
            break;
            case SERIALIZED_CMD_GFXR_INIT_IMAGE:
            {
                decode::QueueSubmitInfo* cmd_info = dynamic_cast<decode::QueueSubmitInfo*>(command_ptr);
                assert(cmd_info);
            }
            break;

            default:
                break;
        }

        if (command_ptr->index == replay_until)
        {
            break;
        }
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
