/*
** Copyright (c) 2019-2022 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_OBJECT_INFO_H
#define GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_OBJECT_INFO_H

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_frame_inspector_vulkan_commands_info.h"
#include "format/format.h"
#include "vulkan/vulkan.h"

#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct CommandBufferInfo : public VulkanPoolObjectInfo<VkCommandBuffer>
{
    using command_list_t = std::map<format::CommandIndexType, std::unique_ptr<VulkanCommandInfo>>;

    command_list_t       command_list;
    VkCommandBufferLevel level;

    // Need to keep track of indirect commands separately in order to copy the indirect
    // command information from the buffer(s) after the submission has finished
    std::vector<VulkanCommandInfo*> indirect_commands;

    void EmplaceCommand(std::unique_ptr<VulkanCommandInfo> command)
    {
        auto result = command_list.emplace(command->index, std::move(command));
        if (!result.second)
        {
            GFXRECON_LOG_WARNING("Duplicate entry for command buffer %" PRIu64, command->index);
        }
    }

    void Reset() { command_list.clear(); }
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif // GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_OBJECT_INFO_H
