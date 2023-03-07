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

#ifndef GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_CLIENT_INDIRECT_COMMANDS_H
#define GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_CLIENT_INDIRECT_COMMANDS_H

#include "decode/vulkan_frame_inspector_client_vulkan_commands_info.h"
#include "format/format.h"
#include "graphics/vulkan_util.h"
#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
class VulkanIndirectCommandInfo : public VulkanCommandInfo
{
  public:
    VulkanIndirectCommandInfo(format::CommandIndexType index, vulkan_command_type type) : VulkanCommandInfo(index, type)
    {}

    const T& GetParams() { return command_params_; }

  protected:
    T command_params_;
};

struct draw_indirect_params_t
{
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t firstVertex;
    uint32_t firstInstance;
};

class VulkanCommandDrawIndirectInfo : public VulkanIndirectCommandInfo<draw_indirect_params_t>
{
  public:
    VulkanCommandDrawIndirectInfo(format::CommandIndexType index) :
        VulkanIndirectCommandInfo(index, VULKAN_CMD_DRAW_INDIRECT)
    {}
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_CLIENT_INDIRECT_COMMANDS_H */
