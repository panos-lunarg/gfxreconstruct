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

#ifndef GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_CLIENT_VULKAN_COMMANDS_INFO_H
#define GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_CLIENT_VULKAN_COMMANDS_INFO_H

#include "decode/vulkan_frame_inspector_client_object_info.h"
#include "format/format.h"
#include "util/defines.h"
#include "vulkan/vulkan.h"

#include <map>
#include <iostream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

enum vulkan_command_type : uint32_t
{
    VULKAN_CMD_BIND_PIPELINE,
    VULKAN_CMD_SET_VIEWPORT,
    VULKAN_CMD_SET_SCISSOR,
    VULKAN_CMD_SET_LINE_WIDTH,
    VULKAN_CMD_SET_DEPTH_BIAS,
    VULKAN_CMD_SET_BLEND_CONSTANTS,
    VULKAN_CMD_SET_DEPTH_BOUNDS,
    VULKAN_CMD_SET_STENCIL_COMPARE_MASK,
    VULKAN_CMD_SET_STENCIL_WRITE_MASK,
    VULKAN_CMD_SET_STENCIL_REFERENCE,
    VULKAN_CMD_BIND_DESCRIPTOR_SETS,
    VULKAN_CMD_BIND_INDEX_BUFFER,
    VULKAN_CMD_BIND_VERTEX_BUFFERS,
    VULKAN_CMD_DRAW,
    VULKAN_CMD_DRAW_INDEXED,
    VULKAN_CMD_DRAW_INDIRECT,
    VULKAN_CMD_DRAW_INDEXED_INDIRECT,
    VULKAN_CMD_DISPATCH,
    VULKAN_CMD_DISPATCH_INDIRECT,
    VULKAN_CMD_COPY_BUFFER,
    VULKAN_CMD_COPY_IMAGE,
    VULKAN_CMD_BLIT_IMAGE,
    VULKAN_CMD_COPY_BUFFER_TO_IMAGE,
    VULKAN_CMD_COPY_IMAGE_TO_BUFFER,
    VULKAN_CMD_UPDATE_BUFFER,
    VULKAN_CMD_FILL_BUFFER,
    VULKAN_CMD_CLEAR_COLOR_IMAGE,
    VULKAN_CMD_CLEAR_DEPTH_STENCIL_IMAGE,
    VULKAN_CMD_CLEAR_ATTACHMENTS,
    VULKAN_CMD_RESOLVE_IMAGE,
    VULKAN_CMD_SET_EVENT,
    VULKAN_CMD_RESET_EVENT,
    VULKAN_CMD_WAIT_EVENTS,
    VULKAN_CMD_PIPELINE_BARRIER,
    VULKAN_CMD_BEGIN_QUERY,
    VULKAN_CMD_END_QUERY,
    VULKAN_CMD_RESET_QUERY_POOL,
    VULKAN_CMD_WRITE_TIMESTAMP,
    VULKAN_CMD_COPY_QUERY_POOL_RESULTS,
    VULKAN_CMD_PUSH_CONSTANTS,
    VULKAN_CMD_BEGIN_RENDER_PASS,
    VULKAN_CMD_NEXT_SUBPASS,
    VULKAN_CMD_END_RENDER_PASS,
    VULKAN_CMD_EXECUTE_COMMANDS,
    VULKAN_CMD_SET_DEVICE_MASK,
    VULKAN_CMD_DISPATCH_BASE,
    VULKAN_CMD_DRAW_INDIRECT_COUNT,
    VULKAN_CMD_DRAW_INDEXED_INDIRECT_COUNT,
    VULKAN_CMD_BEGIN_RENDER_PASS2,
    VULKAN_CMD_NEXT_SUBPASS2,
    VULKAN_CMD_END_RENDER_PASS2,
    VULKAN_CMD_SET_EVENT2,
    VULKAN_CMD_RESET_EVENT2,
    VULKAN_CMD_WAIT_EVENTS2,
    VULKAN_CMD_PIPELINE_BARRIER2,
    VULKAN_CMD_WRITE_TIMESTAMP2,
    VULKAN_CMD_COPY_BUFFER2,
    VULKAN_CMD_COPY_IMAGE2,
    VULKAN_CMD_COPY_BUFFER_TO_IMAGE2,
    VULKAN_CMD_COPY_IMAGE_TO_BUFFER2,
    VULKAN_CMD_BLIT_IMAGE2,
    VULKAN_CMD_RESOLVE_IMAGE2,
    VULKAN_CMD_BEGIN_RENDERING,
    VULKAN_CMD_END_RENDERING,
    VULKAN_CMD_SET_CULL_MODE,
    VULKAN_CMD_SET_FRONT_FACE,
    VULKAN_CMD_SET_PRIMITIVE_TOPOLOGY,
    VULKAN_CMD_SET_VIEWPORT_WITH_COUNT,
    VULKAN_CMD_SET_SCISSOR_WITH_COUNT,
    VULKAN_CMD_BIND_VERTEX_BUFFERS2,
    VULKAN_CMD_SET_DEPTH_TEST_ENABLE,
    VULKAN_CMD_SET_DEPTH_WRITE_ENABLE,
    VULKAN_CMD_SET_DEPTH_COMPARE_OP,
    VULKAN_CMD_SET_DEPTH_BOUNDS_TEST_ENABLE,
    VULKAN_CMD_SET_STENCIL_TEST_ENABLE,
    VULKAN_CMD_SET_STENCIL_OP,
    VULKAN_CMD_SET_RASTERIZER_DISCARD_ENABLE,
    VULKAN_CMD_SET_DEPTH_BIAS_ENABLE,
    VULKAN_CMD_SET_PRIMITIVE_RESTART_ENABLE,
    VULKAN_CMD_BEGIN_RENDERING_KHR,
    VULKAN_CMD_END_RENDERING_KHR,
    VULKAN_CMD_SET_DEVICE_MASK_KHR,
    VULKAN_CMD_DISPATCH_BASE_KHR,
    VULKAN_CMD_PUSH_DESCRIPTOR_SET_KHR,
    VULKAN_CMD_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_KHR,
    VULKAN_CMD_BEGIN_RENDER_PASS2KHR,
    VULKAN_CMD_NEXT_SUBPASS2KHR,
    VULKAN_CMD_END_RENDER_PASS2KHR,
    VULKAN_CMD_DRAW_INDIRECT_COUNT_KHR,
    VULKAN_CMD_DRAW_INDEXED_INDIRECT_COUNT_KHR,
    VULKAN_CMD_SET_FRAGMENT_SHADING_RATE_KHR,
    VULKAN_CMD_SET_EVENT2KHR,
    VULKAN_CMD_RESET_EVENT2KHR,
    VULKAN_CMD_WAIT_EVENTS2KHR,
    VULKAN_CMD_PIPELINE_BARRIER2KHR,
    VULKAN_CMD_WRITE_TIMESTAMP2KHR,
    VULKAN_CMD_WRITE_BUFFER_MARKER2AMD,
    VULKAN_CMD_COPY_BUFFER2KHR,
    VULKAN_CMD_COPY_IMAGE2KHR,
    VULKAN_CMD_COPY_BUFFER_TO_IMAGE2KHR,
    VULKAN_CMD_COPY_IMAGE_TO_BUFFER2KHR,
    VULKAN_CMD_BLIT_IMAGE2KHR,
    VULKAN_CMD_RESOLVE_IMAGE2KHR,
    VULKAN_CMD_TRACE_RAYS_INDIRECT2KHR,
    VULKAN_CMD_DEBUG_MARKER_BEGIN_EXT,
    VULKAN_CMD_DEBUG_MARKER_END_EXT,
    VULKAN_CMD_DEBUG_MARKER_INSERT_EXT,
    VULKAN_CMD_BIND_TRANSFORM_FEEDBACK_BUFFERS_EXT,
    VULKAN_CMD_BEGIN_TRANSFORM_FEEDBACK_EXT,
    VULKAN_CMD_END_TRANSFORM_FEEDBACK_EXT,
    VULKAN_CMD_BEGIN_QUERY_INDEXED_EXT,
    VULKAN_CMD_END_QUERY_INDEXED_EXT,
    VULKAN_CMD_DRAW_INDIRECT_BYTE_COUNT_EXT,
    VULKAN_CMD_DRAW_INDIRECT_COUNT_AMD,
    VULKAN_CMD_DRAW_INDEXED_INDIRECT_COUNT_AMD,
    VULKAN_CMD_BEGIN_CONDITIONAL_RENDERING_EXT,
    VULKAN_CMD_END_CONDITIONAL_RENDERING_EXT,
    VULKAN_CMD_SET_VIEWPORT_W_SCALING_NV,
    VULKAN_CMD_SET_DISCARD_RECTANGLE_EXT,
    VULKAN_CMD_BEGIN_DEBUG_UTILS_LABEL_EXT,
    VULKAN_CMD_END_DEBUG_UTILS_LABEL_EXT,
    VULKAN_CMD_INSERT_DEBUG_UTILS_LABEL_EXT,
    VULKAN_CMD_SET_SAMPLE_LOCATIONS_EXT,
    VULKAN_CMD_BIND_SHADING_RATE_IMAGE_NV,
    VULKAN_CMD_SET_VIEWPORT_SHADING_RATE_PALETTE_NV,
    VULKAN_CMD_SET_COARSE_SAMPLE_ORDER_NV,
    VULKAN_CMD_BUILD_ACCELERATION_STRUCTURE_NV,
    VULKAN_CMD_COPY_ACCELERATION_STRUCTURE_NV,
    VULKAN_CMD_TRACE_RAYS_NV,
    VULKAN_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_NV,
    VULKAN_CMD_WRITE_BUFFER_MARKER_AMD,
    VULKAN_CMD_DRAW_MESH_TASKS_NV,
    VULKAN_CMD_DRAW_MESH_TASKS_INDIRECT_NV,
    VULKAN_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_NV,
    VULKAN_CMD_SET_EXCLUSIVE_SCISSOR_NV,
    VULKAN_CMD_SET_CHECKPOINT_NV,
    VULKAN_CMD_SET_PERFORMANCE_MARKER_INTEL,
    VULKAN_CMD_SET_PERFORMANCE_STREAM_MARKER_INTEL,
    VULKAN_CMD_SET_PERFORMANCE_OVERRIDE_INTEL,
    VULKAN_CMD_SET_LINE_STIPPLE_EXT,
    VULKAN_CMD_SET_CULL_MODE_EXT,
    VULKAN_CMD_SET_FRONT_FACE_EXT,
    VULKAN_CMD_SET_PRIMITIVE_TOPOLOGY_EXT,
    VULKAN_CMD_SET_VIEWPORT_WITH_COUNT_EXT,
    VULKAN_CMD_SET_SCISSOR_WITH_COUNT_EXT,
    VULKAN_CMD_BIND_VERTEX_BUFFERS2EXT,
    VULKAN_CMD_SET_DEPTH_TEST_ENABLE_EXT,
    VULKAN_CMD_SET_DEPTH_WRITE_ENABLE_EXT,
    VULKAN_CMD_SET_DEPTH_COMPARE_OP_EXT,
    VULKAN_CMD_SET_DEPTH_BOUNDS_TEST_ENABLE_EXT,
    VULKAN_CMD_SET_STENCIL_TEST_ENABLE_EXT,
    VULKAN_CMD_SET_STENCIL_OP_EXT,
    VULKAN_CMD_PREPROCESS_GENERATED_COMMANDS_NV,
    VULKAN_CMD_EXECUTE_GENERATED_COMMANDS_NV,
    VULKAN_CMD_BIND_PIPELINE_SHADER_GROUP_NV,
    VULKAN_CMD_SET_FRAGMENT_SHADING_RATE_ENUM_NV,
    VULKAN_CMD_SET_VERTEX_INPUT_EXT,
    VULKAN_CMD_BIND_INVOCATION_MASK_HUAWEI,
    VULKAN_CMD_SET_PATCH_CONTROL_POINTS_EXT,
    VULKAN_CMD_SET_RASTERIZER_DISCARD_ENABLE_EXT,
    VULKAN_CMD_SET_DEPTH_BIAS_ENABLE_EXT,
    VULKAN_CMD_SET_LOGIC_OP_EXT,
    VULKAN_CMD_SET_PRIMITIVE_RESTART_ENABLE_EXT,
    VULKAN_CMD_SET_COLOR_WRITE_ENABLE_EXT,
    VULKAN_CMD_DRAW_MULTI_EXT,
    VULKAN_CMD_DRAW_MULTI_INDEXED_EXT,
    VULKAN_CMD_BUILD_MICROMAPS_EXT,
    VULKAN_CMD_COPY_MICROMAP_EXT,
    VULKAN_CMD_COPY_MICROMAP_TO_MEMORY_EXT,
    VULKAN_CMD_COPY_MEMORY_TO_MICROMAP_EXT,
    VULKAN_CMD_WRITE_MICROMAPS_PROPERTIES_EXT,
    VULKAN_CMD_SET_TESSELLATION_DOMAIN_ORIGIN_EXT,
    VULKAN_CMD_SET_DEPTH_CLAMP_ENABLE_EXT,
    VULKAN_CMD_SET_POLYGON_MODE_EXT,
    VULKAN_CMD_SET_RASTERIZATION_SAMPLES_EXT,
    VULKAN_CMD_SET_SAMPLE_MASK_EXT,
    VULKAN_CMD_SET_ALPHA_TO_COVERAGE_ENABLE_EXT,
    VULKAN_CMD_SET_ALPHA_TO_ONE_ENABLE_EXT,
    VULKAN_CMD_SET_LOGIC_OP_ENABLE_EXT,
    VULKAN_CMD_SET_COLOR_BLEND_ENABLE_EXT,
    VULKAN_CMD_SET_COLOR_BLEND_EQUATION_EXT,
    VULKAN_CMD_SET_COLOR_WRITE_MASK_EXT,
    VULKAN_CMD_SET_RASTERIZATION_STREAM_EXT,
    VULKAN_CMD_SET_CONSERVATIVE_RASTERIZATION_MODE_EXT,
    VULKAN_CMD_SET_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT,
    VULKAN_CMD_SET_DEPTH_CLIP_ENABLE_EXT,
    VULKAN_CMD_SET_SAMPLE_LOCATIONS_ENABLE_EXT,
    VULKAN_CMD_SET_COLOR_BLEND_ADVANCED_EXT,
    VULKAN_CMD_SET_PROVOKING_VERTEX_MODE_EXT,
    VULKAN_CMD_SET_LINE_RASTERIZATION_MODE_EXT,
    VULKAN_CMD_SET_LINE_STIPPLE_ENABLE_EXT,
    VULKAN_CMD_SET_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT,
    VULKAN_CMD_SET_VIEWPORT_W_SCALING_ENABLE_NV,
    VULKAN_CMD_SET_VIEWPORT_SWIZZLE_NV,
    VULKAN_CMD_SET_COVERAGE_TO_COLOR_ENABLE_NV,
    VULKAN_CMD_SET_COVERAGE_TO_COLOR_LOCATION_NV,
    VULKAN_CMD_SET_COVERAGE_MODULATION_MODE_NV,
    VULKAN_CMD_SET_COVERAGE_MODULATION_TABLE_ENABLE_NV,
    VULKAN_CMD_SET_COVERAGE_MODULATION_TABLE_NV,
    VULKAN_CMD_SET_SHADING_RATE_IMAGE_ENABLE_NV,
    VULKAN_CMD_SET_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV,
    VULKAN_CMD_SET_COVERAGE_REDUCTION_MODE_NV,
    VULKAN_CMD_OPTICAL_FLOW_EXECUTE_NV,
    VULKAN_CMD_BUILD_ACCELERATION_STRUCTURES_KHR,
    VULKAN_CMD_BUILD_ACCELERATION_STRUCTURES_INDIRECT_KHR,
    VULKAN_CMD_COPY_ACCELERATION_STRUCTURE_KHR,
    VULKAN_CMD_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_KHR,
    VULKAN_CMD_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_KHR,
    VULKAN_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_KHR,
    VULKAN_CMD_TRACE_RAYS_KHR,
    VULKAN_CMD_TRACE_RAYS_INDIRECT_KHR,
    VULKAN_CMD_SET_RAY_TRACING_PIPELINE_STACK_SIZE_KHR,
    VULKAN_CMD_DRAW_MESH_TASKS_EXT,
    VULKAN_CMD_DRAW_MESH_TASKS_INDIRECT_EXT,
    VULKAN_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_EXT
};

static const char* vulkan_command_to_str(vulkan_command_type type)
{
    switch (type)
    {
        GFXR_CASE_TO_STR(VULKAN_CMD_BIND_PIPELINE)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_VIEWPORT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_SCISSOR)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_LINE_WIDTH)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_BIAS)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_BLEND_CONSTANTS)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_BOUNDS)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_STENCIL_COMPARE_MASK)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_STENCIL_WRITE_MASK)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_STENCIL_REFERENCE)
        GFXR_CASE_TO_STR(VULKAN_CMD_BIND_DESCRIPTOR_SETS)
        GFXR_CASE_TO_STR(VULKAN_CMD_BIND_INDEX_BUFFER)
        GFXR_CASE_TO_STR(VULKAN_CMD_BIND_VERTEX_BUFFERS)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_INDEXED)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_INDIRECT)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_INDEXED_INDIRECT)
        GFXR_CASE_TO_STR(VULKAN_CMD_DISPATCH)
        GFXR_CASE_TO_STR(VULKAN_CMD_DISPATCH_INDIRECT)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_BUFFER)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_IMAGE)
        GFXR_CASE_TO_STR(VULKAN_CMD_BLIT_IMAGE)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_BUFFER_TO_IMAGE)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_IMAGE_TO_BUFFER)
        GFXR_CASE_TO_STR(VULKAN_CMD_UPDATE_BUFFER)
        GFXR_CASE_TO_STR(VULKAN_CMD_FILL_BUFFER)
        GFXR_CASE_TO_STR(VULKAN_CMD_CLEAR_COLOR_IMAGE)
        GFXR_CASE_TO_STR(VULKAN_CMD_CLEAR_DEPTH_STENCIL_IMAGE)
        GFXR_CASE_TO_STR(VULKAN_CMD_CLEAR_ATTACHMENTS)
        GFXR_CASE_TO_STR(VULKAN_CMD_RESOLVE_IMAGE)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_EVENT)
        GFXR_CASE_TO_STR(VULKAN_CMD_RESET_EVENT)
        GFXR_CASE_TO_STR(VULKAN_CMD_WAIT_EVENTS)
        GFXR_CASE_TO_STR(VULKAN_CMD_PIPELINE_BARRIER)
        GFXR_CASE_TO_STR(VULKAN_CMD_BEGIN_QUERY)
        GFXR_CASE_TO_STR(VULKAN_CMD_END_QUERY)
        GFXR_CASE_TO_STR(VULKAN_CMD_RESET_QUERY_POOL)
        GFXR_CASE_TO_STR(VULKAN_CMD_WRITE_TIMESTAMP)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_QUERY_POOL_RESULTS)
        GFXR_CASE_TO_STR(VULKAN_CMD_PUSH_CONSTANTS)
        GFXR_CASE_TO_STR(VULKAN_CMD_BEGIN_RENDER_PASS)
        GFXR_CASE_TO_STR(VULKAN_CMD_NEXT_SUBPASS)
        GFXR_CASE_TO_STR(VULKAN_CMD_END_RENDER_PASS)
        GFXR_CASE_TO_STR(VULKAN_CMD_EXECUTE_COMMANDS)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEVICE_MASK)
        GFXR_CASE_TO_STR(VULKAN_CMD_DISPATCH_BASE)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_INDIRECT_COUNT)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_INDEXED_INDIRECT_COUNT)
        GFXR_CASE_TO_STR(VULKAN_CMD_BEGIN_RENDER_PASS2)
        GFXR_CASE_TO_STR(VULKAN_CMD_NEXT_SUBPASS2)
        GFXR_CASE_TO_STR(VULKAN_CMD_END_RENDER_PASS2)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_EVENT2)
        GFXR_CASE_TO_STR(VULKAN_CMD_RESET_EVENT2)
        GFXR_CASE_TO_STR(VULKAN_CMD_WAIT_EVENTS2)
        GFXR_CASE_TO_STR(VULKAN_CMD_PIPELINE_BARRIER2)
        GFXR_CASE_TO_STR(VULKAN_CMD_WRITE_TIMESTAMP2)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_BUFFER2)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_IMAGE2)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_BUFFER_TO_IMAGE2)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_IMAGE_TO_BUFFER2)
        GFXR_CASE_TO_STR(VULKAN_CMD_BLIT_IMAGE2)
        GFXR_CASE_TO_STR(VULKAN_CMD_RESOLVE_IMAGE2)
        GFXR_CASE_TO_STR(VULKAN_CMD_BEGIN_RENDERING)
        GFXR_CASE_TO_STR(VULKAN_CMD_END_RENDERING)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_CULL_MODE)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_FRONT_FACE)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_PRIMITIVE_TOPOLOGY)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_VIEWPORT_WITH_COUNT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_SCISSOR_WITH_COUNT)
        GFXR_CASE_TO_STR(VULKAN_CMD_BIND_VERTEX_BUFFERS2)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_TEST_ENABLE)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_WRITE_ENABLE)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_COMPARE_OP)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_BOUNDS_TEST_ENABLE)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_STENCIL_TEST_ENABLE)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_STENCIL_OP)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_RASTERIZER_DISCARD_ENABLE)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_BIAS_ENABLE)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_PRIMITIVE_RESTART_ENABLE)
        GFXR_CASE_TO_STR(VULKAN_CMD_BEGIN_RENDERING_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_END_RENDERING_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEVICE_MASK_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_DISPATCH_BASE_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_PUSH_DESCRIPTOR_SET_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_BEGIN_RENDER_PASS2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_NEXT_SUBPASS2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_END_RENDER_PASS2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_INDIRECT_COUNT_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_INDEXED_INDIRECT_COUNT_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_FRAGMENT_SHADING_RATE_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_EVENT2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_RESET_EVENT2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_WAIT_EVENTS2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_PIPELINE_BARRIER2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_WRITE_TIMESTAMP2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_WRITE_BUFFER_MARKER2AMD)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_BUFFER2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_IMAGE2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_BUFFER_TO_IMAGE2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_IMAGE_TO_BUFFER2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_BLIT_IMAGE2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_RESOLVE_IMAGE2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_TRACE_RAYS_INDIRECT2KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_DEBUG_MARKER_BEGIN_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_DEBUG_MARKER_END_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_DEBUG_MARKER_INSERT_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_BIND_TRANSFORM_FEEDBACK_BUFFERS_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_BEGIN_TRANSFORM_FEEDBACK_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_END_TRANSFORM_FEEDBACK_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_BEGIN_QUERY_INDEXED_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_END_QUERY_INDEXED_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_INDIRECT_BYTE_COUNT_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_INDIRECT_COUNT_AMD)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_INDEXED_INDIRECT_COUNT_AMD)
        GFXR_CASE_TO_STR(VULKAN_CMD_BEGIN_CONDITIONAL_RENDERING_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_END_CONDITIONAL_RENDERING_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_VIEWPORT_W_SCALING_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DISCARD_RECTANGLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_BEGIN_DEBUG_UTILS_LABEL_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_END_DEBUG_UTILS_LABEL_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_INSERT_DEBUG_UTILS_LABEL_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_SAMPLE_LOCATIONS_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_BIND_SHADING_RATE_IMAGE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_VIEWPORT_SHADING_RATE_PALETTE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_COARSE_SAMPLE_ORDER_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_BUILD_ACCELERATION_STRUCTURE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_ACCELERATION_STRUCTURE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_TRACE_RAYS_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_WRITE_BUFFER_MARKER_AMD)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_MESH_TASKS_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_MESH_TASKS_INDIRECT_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_EXCLUSIVE_SCISSOR_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_CHECKPOINT_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_PERFORMANCE_MARKER_INTEL)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_PERFORMANCE_STREAM_MARKER_INTEL)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_PERFORMANCE_OVERRIDE_INTEL)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_LINE_STIPPLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_CULL_MODE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_FRONT_FACE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_PRIMITIVE_TOPOLOGY_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_VIEWPORT_WITH_COUNT_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_SCISSOR_WITH_COUNT_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_BIND_VERTEX_BUFFERS2EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_TEST_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_WRITE_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_COMPARE_OP_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_BOUNDS_TEST_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_STENCIL_TEST_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_STENCIL_OP_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_PREPROCESS_GENERATED_COMMANDS_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_EXECUTE_GENERATED_COMMANDS_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_BIND_PIPELINE_SHADER_GROUP_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_FRAGMENT_SHADING_RATE_ENUM_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_VERTEX_INPUT_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_BIND_INVOCATION_MASK_HUAWEI)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_PATCH_CONTROL_POINTS_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_RASTERIZER_DISCARD_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_BIAS_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_LOGIC_OP_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_PRIMITIVE_RESTART_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_COLOR_WRITE_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_MULTI_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_MULTI_INDEXED_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_BUILD_MICROMAPS_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_MICROMAP_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_MICROMAP_TO_MEMORY_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_MEMORY_TO_MICROMAP_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_WRITE_MICROMAPS_PROPERTIES_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_TESSELLATION_DOMAIN_ORIGIN_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_CLAMP_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_POLYGON_MODE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_RASTERIZATION_SAMPLES_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_SAMPLE_MASK_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_ALPHA_TO_COVERAGE_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_ALPHA_TO_ONE_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_LOGIC_OP_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_COLOR_BLEND_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_COLOR_BLEND_EQUATION_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_COLOR_WRITE_MASK_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_RASTERIZATION_STREAM_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_CONSERVATIVE_RASTERIZATION_MODE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_CLIP_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_SAMPLE_LOCATIONS_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_COLOR_BLEND_ADVANCED_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_PROVOKING_VERTEX_MODE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_LINE_RASTERIZATION_MODE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_LINE_STIPPLE_ENABLE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_VIEWPORT_W_SCALING_ENABLE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_VIEWPORT_SWIZZLE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_COVERAGE_TO_COLOR_ENABLE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_COVERAGE_TO_COLOR_LOCATION_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_COVERAGE_MODULATION_MODE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_COVERAGE_MODULATION_TABLE_ENABLE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_COVERAGE_MODULATION_TABLE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_SHADING_RATE_IMAGE_ENABLE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_COVERAGE_REDUCTION_MODE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_OPTICAL_FLOW_EXECUTE_NV)
        GFXR_CASE_TO_STR(VULKAN_CMD_BUILD_ACCELERATION_STRUCTURES_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_BUILD_ACCELERATION_STRUCTURES_INDIRECT_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_ACCELERATION_STRUCTURE_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_TRACE_RAYS_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_TRACE_RAYS_INDIRECT_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_SET_RAY_TRACING_PIPELINE_STACK_SIZE_KHR)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_MESH_TASKS_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_MESH_TASKS_INDIRECT_EXT)
        GFXR_CASE_TO_STR(VULKAN_CMD_DRAW_MESH_TASKS_INDIRECT_COUNT_EXT)
        default:
            assert(0);
            return "XXX";
    }
}

struct VulkanCommandInfo
{
    VulkanCommandInfo(format::CommandIndexType index, vulkan_command_type type) : index(index), type(type) {}
    virtual ~VulkanCommandInfo() = default;

    VulkanCommandInfo(const VulkanCommandInfo& other) = delete;
    VulkanCommandInfo& operator=(const VulkanCommandInfo& other) = delete;

    // This function is only relevant to the IndirectCommand child classes
    // virtual void FetchParameters() {}

    format::CommandIndexType index;
    vulkan_command_type      type;
};

static const char* vulkan_command_to_str(const VulkanCommandInfo* cmd)
{
    return vulkan_command_to_str(cmd->type);
}

struct VulkanCommandBindPipelineInfo : public VulkanCommandInfo
{
    VulkanCommandBindPipelineInfo(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_BIND_PIPELINE)
    {}

    VkPipelineBindPoint pipeline_bind_point;
    FIPipelineInfo*     pipeline;
};

struct VulkanCommandSetViewportInfo : public VulkanCommandInfo
{
    VulkanCommandSetViewportInfo(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_SET_VIEWPORT) {}

    uint32_t                first_viewport;
    std::vector<VkViewport> viewports;
};

struct VulkanCommandSetScissorInfo : public VulkanCommandInfo
{
    VulkanCommandSetScissorInfo(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_SET_SCISSOR) {}

    uint32_t              first_scissor;
    std::vector<VkRect2D> scissors;
};

// struct VulkanCommandSetLineWidthInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetLineWidthInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_SET_LINE_WIDTH)
//     {}
// };

// struct VulkanCommandSetDepthBiasInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthBiasInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_SET_DEPTH_BIAS)
//     {}
// };

// struct VulkanCommandSetBlendConstantsInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetBlendConstantsInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_BLEND_CONSTANTS)
//     {}
// };

// struct VulkanCommandSetDepthBoundsInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthBoundsInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_BOUNDS)
//     {}
// };

// struct VulkanCommandSetStencilCompareMaskInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetStencilCompareMaskInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_STENCIL_COMPARE_MASK)
//     {}
// };

// struct VulkanCommandSetStencilWriteMaskInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetStencilWriteMaskInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_STENCIL_WRITE_MASK)
//     {}
// };

// struct VulkanCommandSetStencilReferenceInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetStencilReferenceInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_STENCIL_REFERENCE)
//     {}
// };

struct VulkanCommandBindDescriptorSetsInfo : public VulkanCommandInfo
{
    VulkanCommandBindDescriptorSetsInfo(format::CommandIndexType index) :
        VulkanCommandInfo(index, VULKAN_CMD_BIND_DESCRIPTOR_SETS)
    {}

    VkPipelineBindPoint               pipeline_bind_point;
    FIPipelineLayoutInfo*             pipeline_layout;
    uint32_t                          first_set;
    std::vector<FIDescriptorSetInfo*> descriptor_sets;
    std::vector<uint32_t>             dynamic_offsets;
};

struct VulkanCommandBindIndexBufferInfo : public VulkanCommandInfo
{
    VulkanCommandBindIndexBufferInfo(format::CommandIndexType index) :
        VulkanCommandInfo(index, VULKAN_CMD_BIND_INDEX_BUFFER)
    {}

    FIBufferInfo* buffer_info;
    VkDeviceSize  offset;
    VkIndexType   indexType;
};

struct VulkanCommandBindVertexBuffersInfo : public VulkanCommandInfo
{
    VulkanCommandBindVertexBuffersInfo(format::CommandIndexType index) :
        VulkanCommandInfo(index, VULKAN_CMD_BIND_VERTEX_BUFFERS)
    {}

    uint32_t                   firstBinding;
    std::vector<FIBufferInfo*> buffers;
    std::vector<VkDeviceSize>  offsets;
};

struct VulkanDrawCommandsBaseInfo : public VulkanCommandInfo
{
    VulkanDrawCommandsBaseInfo(format::CommandIndexType   index,
                               vulkan_command_type        type,
                               const FICommandBufferInfo* cmd_buffer_info) :
        VulkanCommandInfo(index, type)
    {
        // Copy active descriptors
        for (const auto desc_set : cmd_buffer_info->active_descriptor_sets)
        {
            descriptor_sets.emplace(desc_set.first, *desc_set.second);
        }

        bound_vertex_buffers = cmd_buffer_info->bound_vertex_buffers;
        bound_index_buffer   = cmd_buffer_info->bound_index_buffer;
        pipeline             = cmd_buffer_info->active_pipeline;
        renderpass           = cmd_buffer_info->active_renderpass;
        framebuffer          = cmd_buffer_info->active_framebuffer;
    }

    FIPipelineInfo*    pipeline;
    FIRenderPassInfo*  renderpass;
    FIFramebufferInfo* framebuffer;

    // Copy of active descriptor sets
    std::unordered_map<uint32_t, FIDescriptorSetInfo> descriptor_sets;
    FIBoundVertexBuffersInfo                          bound_vertex_buffers;
    FIBoundIndexBufferInfo                            bound_index_buffer;
};

struct VulkanCommandDrawInfo : public VulkanDrawCommandsBaseInfo
{
    VulkanCommandDrawInfo(format::CommandIndexType index, const FICommandBufferInfo* cmd_buffer_info) :
        VulkanDrawCommandsBaseInfo(index, VULKAN_CMD_DRAW, cmd_buffer_info)
    {}

    uint32_t vertex_count;
    uint32_t instance_count;
    uint32_t first_vertex;
    uint32_t first_instance;
};

struct VulkanCommandDrawIndexedInfo : public VulkanDrawCommandsBaseInfo
{
    VulkanCommandDrawIndexedInfo(format::CommandIndexType index, const FICommandBufferInfo* cmd_buffer_info) :
        VulkanDrawCommandsBaseInfo(index, VULKAN_CMD_DRAW, cmd_buffer_info)
    {}

    uint32_t index_count;
    uint32_t instance_count;
    uint32_t first_index;
    int32_t  vertex_offset;
    uint32_t first_instance;
};

// struct VulkanCommandDispatchInfo : public VulkanCommandInfo
// {
//     VulkanCommandDispatchInfo(format::CommandIndexType index, vulkan_command_type type) : VulkanCommandInfo(index,
//     type)
//     {}
// };

// struct VulkanCommandCopyBufferInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyBufferInfo(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_COPY_BUFFER) {}
// };

// struct VulkanCommandCopyImageInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyImageInfo(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_COPY_IMAGE) {}
// };

// struct VulkanCommandBlitImageInfo : public VulkanCommandInfo
// {
//     VulkanCommandBlitImageInfo(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_BLIT_IMAGE) {}
// };

// struct VulkanCommandCopyBufferToImageInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyBufferToImageInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_BUFFER_TO_IMAGE)
//     {}

//     FIBufferInfo*                  srcBuffer;
//     FIImageInfo*                   dstImage;
//     VkImageLayout                  dstImageLayout;
//     std::vector<VkBufferImageCopy> regions;
// };

// struct VulkanCommandCopyImageToBufferInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyImageToBufferInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_IMAGE_TO_BUFFER)
//     {}
// };

// struct VulkanCommandUpdateBufferInfo : public VulkanCommandInfo
// {
//     VulkanCommandUpdateBufferInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_UPDATE_BUFFER)
//     {}
// };

// struct VulkanCommandFillBufferInfo : public VulkanCommandInfo
// {
//     VulkanCommandFillBufferInfo(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_FILL_BUFFER) {}
// };

// struct VulkanCommandClearColorImageInfo : public VulkanCommandInfo
// {
//     VulkanCommandClearColorImageInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_CLEAR_COLOR_IMAGE)
//     {}
// };

// struct VulkanCommandClearDepthStencilImageInfo : public VulkanCommandInfo
// {
//     VulkanCommandClearDepthStencilImageInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_CLEAR_DEPTH_STENCIL_IMAGE)
//     {}
// };

// struct VulkanCommandClearAttachmentsInfo : public VulkanCommandInfo
// {
//     VulkanCommandClearAttachmentsInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_CLEAR_ATTACHMENTS)
//     {}
// };

// struct VulkanCommandResolveImageInfo : public VulkanCommandInfo
// {
//     VulkanCommandResolveImageInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_RESOLVE_IMAGE)
//     {}
// };

// struct VulkanCommandSetEventInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetEventInfo(format::CommandIndexType index, vulkan_command_type type) : VulkanCommandInfo(index,
//     type)
//     {}
// };

// struct VulkanCommandResetEventInfo : public VulkanCommandInfo
// {
//     VulkanCommandResetEventInfo(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_RESET_EVENT) {}
// };

// struct VulkanCommandWaitEventsInfo : public VulkanCommandInfo
// {
//     VulkanCommandWaitEventsInfo(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_WAIT_EVENTS) {}
// };

// struct VulkanCommandPipelineBarrierInfo : public VulkanCommandInfo
// {
//     VulkanCommandPipelineBarrierInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_PIPELINE_BARRIER)
//     {}

//     VkPipelineStageFlags               srcStageMask;
//     VkPipelineStageFlags               dstStageMask;
//     VkDependencyFlags                  dependencyFlags;
//     std::vector<VkMemoryBarrier>       MemoryBarriers;
//     std::vector<VkBufferMemoryBarrier> BufferMemoryBarriers;
//     std::vector<VkImageMemoryBarrier>  ImageMemoryBarriers;
// };

// struct VulkanCommandBeginQueryInfo : public VulkanCommandInfo
// {
//     VulkanCommandBeginQueryInfo(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_BEGIN_QUERY) {}
// };

// struct VulkanCommandEndQueryInfo : public VulkanCommandInfo
// {
//     VulkanCommandEndQueryInfo(format::CommandIndexType index, vulkan_command_type type) : VulkanCommandInfo(index,
//     type)
//     {}
// };

// struct VulkanCommandResetQueryPoolInfo : public VulkanCommandInfo
// {
//     VulkanCommandResetQueryPoolInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_RESET_QUERY_POOL)
//     {}
// };

// struct VulkanCommandWriteTimestampInfo : public VulkanCommandInfo
// {
//     VulkanCommandWriteTimestampInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_WRITE_TIMESTAMP)
//     {}
// };

// struct VulkanCommandCopyQueryPoolResultsInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyQueryPoolResultsInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_QUERY_POOL_RESULTS)
//     {}
// };

// struct VulkanCommandPushConstantsInfo : public VulkanCommandInfo
// {
//     VulkanCommandPushConstantsInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_PUSH_CONSTANTS)
//     {}
// };

struct VulkanCommandBeginRenderPassInfo : public VulkanCommandInfo
{
    VulkanCommandBeginRenderPassInfo(format::CommandIndexType index) :
        VulkanCommandInfo(index, VULKAN_CMD_BEGIN_RENDER_PASS)
    {}

    FIRenderPassInfo*         renderpass_info;
    FIFramebufferInfo*        framebuffer_info;
    VkRect2D                  renderArea;
    std::vector<VkClearValue> clear_values;
    VkSubpassContents         contents;
};

// struct VulkanCommandNextSubpassInfo : public VulkanCommandInfo
// {
//     VulkanCommandNextSubpassInfo(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_NEXT_SUBPASS)
//     {}
// };

struct VulkanCommandEndRenderPassInfo : public VulkanCommandInfo
{
    VulkanCommandEndRenderPassInfo(format::CommandIndexType index) :
        VulkanCommandInfo(index, VULKAN_CMD_END_RENDER_PASS)
    {}
};

// struct VulkanCommandExecuteCommandsInfo : public VulkanCommandInfo
// {
//     VulkanCommandExecuteCommandsInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_EXECUTE_COMMANDS)
//     {}
// };

// struct VulkanCommandSetDeviceMaskInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDeviceMaskInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEVICE_MASK)
//     {}
// };

// struct VulkanCommandDispatchBaseInfo : public VulkanCommandInfo
// {
//     VulkanCommandDispatchBaseInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_DISPATCH_BASE)
//     {}
// };

// struct VulkanCommandBeginRenderPass2Info : public VulkanCommandInfo
// {
//     VulkanCommandBeginRenderPass2Info(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BEGIN_RENDER_PASS2)
//     {}
// };

// struct VulkanCommandNextSubpass2Info : public VulkanCommandInfo
// {
//     VulkanCommandNextSubpass2Info(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_NEXT_SUBPASS2)
//     {}
// };

// struct VulkanCommandEndRenderPass2Info : public VulkanCommandInfo
// {
//     VulkanCommandEndRenderPass2Info(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_END_RENDER_PASS2)
//     {}
// };

// struct VulkanCommandSetEvent2Info : public VulkanCommandInfo
// {
//     VulkanCommandSetEvent2Info(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_SET_EVENT2) {}
// };

// struct VulkanCommandResetEvent2Info : public VulkanCommandInfo
// {
//     VulkanCommandResetEvent2Info(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_RESET_EVENT2)
//     {}
// };

// struct VulkanCommandWaitEvents2Info : public VulkanCommandInfo
// {
//     VulkanCommandWaitEvents2Info(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_WAIT_EVENTS2)
//     {}
// };

// struct VulkanCommandPipelineBarrier2Info : public VulkanCommandInfo
// {
//     VulkanCommandPipelineBarrier2Info(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_PIPELINE_BARRIER2)
//     {}
// };

// struct VulkanCommandWriteTimestamp2Info : public VulkanCommandInfo
// {
//     VulkanCommandWriteTimestamp2Info(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_WRITE_TIMESTAMP2)
//     {}
// };

// struct VulkanCommandCopyBuffer2Info : public VulkanCommandInfo
// {
//     VulkanCommandCopyBuffer2Info(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_COPY_BUFFER2)
//     {}
// };

// struct VulkanCommandCopyImage2Info : public VulkanCommandInfo
// {
//     VulkanCommandCopyImage2Info(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_COPY_IMAGE2) {}
// };

// struct VulkanCommandCopyBufferToImage2Info : public VulkanCommandInfo
// {
//     VulkanCommandCopyBufferToImage2Info(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_BUFFER_TO_IMAGE2)
//     {}
// };

// struct VulkanCommandCopyImageToBuffer2Info : public VulkanCommandInfo
// {
//     VulkanCommandCopyImageToBuffer2Info(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_IMAGE_TO_BUFFER2)
//     {}
// };

// struct VulkanCommandBlitImage2Info : public VulkanCommandInfo
// {
//     VulkanCommandBlitImage2Info(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_BLIT_IMAGE2) {}
// };

// struct VulkanCommandResolveImage2Info : public VulkanCommandInfo
// {
//     VulkanCommandResolveImage2Info(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_RESOLVE_IMAGE2)
//     {}
// };

// struct VulkanCommandBeginRenderingInfo : public VulkanCommandInfo
// {
//     VulkanCommandBeginRenderingInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BEGIN_RENDERING)
//     {}
// };

// struct VulkanCommandEndRenderingInfo : public VulkanCommandInfo
// {
//     VulkanCommandEndRenderingInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_END_RENDERING)
//     {}
// };

// struct VulkanCommandSetCullModeInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetCullModeInfo(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_SET_CULL_MODE)
//     {}
// };

// struct VulkanCommandSetFrontFaceInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetFrontFaceInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_SET_FRONT_FACE)
//     {}
// };

// struct VulkanCommandSetPrimitiveTopologyInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetPrimitiveTopologyInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_PRIMITIVE_TOPOLOGY)
//     {}
// };

// struct VulkanCommandSetViewportWithCountInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetViewportWithCountInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_VIEWPORT_WITH_COUNT)
//     {}
// };

// struct VulkanCommandSetScissorWithCountInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetScissorWithCountInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_SCISSOR_WITH_COUNT)
//     {}
// };

// struct VulkanCommandBindVertexBuffers2Info : public VulkanCommandInfo
// {
//     VulkanCommandBindVertexBuffers2Info(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BIND_VERTEX_BUFFERS2)
//     {}
// };

// struct VulkanCommandSetDepthTestEnableInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthTestEnableInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_TEST_ENABLE)
//     {}
// };

// struct VulkanCommandSetDepthWriteEnableInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthWriteEnableInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_WRITE_ENABLE)
//     {}
// };

// struct VulkanCommandSetDepthCompareOpInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthCompareOpInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_COMPARE_OP)
//     {}
// };

// struct VulkanCommandSetDepthBoundsTestEnableInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthBoundsTestEnableInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_BOUNDS_TEST_ENABLE)
//     {}
// };

// struct VulkanCommandSetStencilTestEnableInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetStencilTestEnableInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_STENCIL_TEST_ENABLE)
//     {}
// };

// struct VulkanCommandSetStencilOpInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetStencilOpInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_SET_STENCIL_OP)
//     {}
// };

// struct VulkanCommandSetRasterizerDiscardEnableInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetRasterizerDiscardEnableInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_RASTERIZER_DISCARD_ENABLE)
//     {}
// };

// struct VulkanCommandSetDepthBiasEnableInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthBiasEnableInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_BIAS_ENABLE)
//     {}
// };

// struct VulkanCommandSetPrimitiveRestartEnableInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetPrimitiveRestartEnableInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_PRIMITIVE_RESTART_ENABLE)
//     {}
// };

// struct VulkanCommandBeginRenderingKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandBeginRenderingKHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BEGIN_RENDERING_KHR)
//     {}
// };

// struct VulkanCommandEndRenderingKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandEndRenderingKHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_END_RENDERING_KHR)
//     {}
// };

// struct VulkanCommandSetDeviceMaskKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDeviceMaskKHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEVICE_MASK_KHR)
//     {}
// };

// struct VulkanCommandDispatchBaseKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandDispatchBaseKHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_DISPATCH_BASE_KHR)
//     {}
// };

// struct VulkanCommandPushDescriptorSetKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandPushDescriptorSetKHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_PUSH_DESCRIPTOR_SET_KHR)
//     {}
// };

// struct VulkanCommandPushDescriptorSetWithTemplateKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandPushDescriptorSetWithTemplateKHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_KHR)
//     {}
// };

// struct VulkanCommandBeginRenderPass2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandBeginRenderPass2KHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BEGIN_RENDER_PASS2KHR)
//     {}
// };

// struct VulkanCommandNextSubpass2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandNextSubpass2KHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_NEXT_SUBPASS2KHR)
//     {}
// };

// struct VulkanCommandEndRenderPass2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandEndRenderPass2KHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_END_RENDER_PASS2KHR)
//     {}
// };

// struct VulkanCommandSetFragmentShadingRateKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetFragmentShadingRateKHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_FRAGMENT_SHADING_RATE_KHR)
//     {}
// };

// struct VulkanCommandSetEvent2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetEvent2KHRInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_SET_EVENT2KHR)
//     {}
// };

// struct VulkanCommandResetEvent2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandResetEvent2KHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_RESET_EVENT2KHR)
//     {}
// };

// struct VulkanCommandWaitEvents2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandWaitEvents2KHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_WAIT_EVENTS2KHR)
//     {}
// };

// struct VulkanCommandPipelineBarrier2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandPipelineBarrier2KHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_PIPELINE_BARRIER2KHR)
//     {}
// };

// struct VulkanCommandWriteTimestamp2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandWriteTimestamp2KHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_WRITE_TIMESTAMP2KHR)
//     {}
// };

// struct VulkanCommandWriteBufferMarker2AMDInfo : public VulkanCommandInfo
// {
//     VulkanCommandWriteBufferMarker2AMDInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_WRITE_BUFFER_MARKER2AMD)
//     {}
// };

// struct VulkanCommandCopyBuffer2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyBuffer2KHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_BUFFER2KHR)
//     {}
// };

// struct VulkanCommandCopyImage2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyImage2KHRInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_COPY_IMAGE2KHR)
//     {}
// };

// struct VulkanCommandCopyBufferToImage2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyBufferToImage2KHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_BUFFER_TO_IMAGE2KHR)
//     {}
// };

// struct VulkanCommandCopyImageToBuffer2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyImageToBuffer2KHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_IMAGE_TO_BUFFER2KHR)
//     {}
// };

// struct VulkanCommandBlitImage2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandBlitImage2KHRInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_BLIT_IMAGE2KHR)
//     {}
// };

// struct VulkanCommandResolveImage2KHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandResolveImage2KHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_RESOLVE_IMAGE2KHR)
//     {}
// };

// struct VulkanCommandDebugMarkerBeginEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandDebugMarkerBeginEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_DEBUG_MARKER_BEGIN_EXT)
//     {}
// };

// struct VulkanCommandDebugMarkerEndEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandDebugMarkerEndEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_DEBUG_MARKER_END_EXT)
//     {}
// };

// struct VulkanCommandDebugMarkerInsertEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandDebugMarkerInsertEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_DEBUG_MARKER_INSERT_EXT)
//     {}
// };

// struct VulkanCommandBindTransformFeedbackBuffersEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandBindTransformFeedbackBuffersEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BIND_TRANSFORM_FEEDBACK_BUFFERS_EXT)
//     {}
// };

// struct VulkanCommandBeginTransformFeedbackEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandBeginTransformFeedbackEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BEGIN_TRANSFORM_FEEDBACK_EXT)
//     {}
// };

// struct VulkanCommandEndTransformFeedbackEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandEndTransformFeedbackEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_END_TRANSFORM_FEEDBACK_EXT)
//     {}
// };

// struct VulkanCommandBeginQueryIndexedEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandBeginQueryIndexedEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BEGIN_QUERY_INDEXED_EXT)
//     {}
// };

// struct VulkanCommandEndQueryIndexedEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandEndQueryIndexedEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_END_QUERY_INDEXED_EXT)
//     {}
// };

// struct VulkanCommandBeginConditionalRenderingEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandBeginConditionalRenderingEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BEGIN_CONDITIONAL_RENDERING_EXT)
//     {}
// };

// struct VulkanCommandEndConditionalRenderingEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandEndConditionalRenderingEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_END_CONDITIONAL_RENDERING_EXT)
//     {}
// };

// struct VulkanCommandSetViewportWScalingNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetViewportWScalingNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_VIEWPORT_W_SCALING_NV)
//     {}
// };

// struct VulkanCommandSetDiscardRectangleEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDiscardRectangleEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DISCARD_RECTANGLE_EXT)
//     {}
// };

// struct VulkanCommandBeginDebugUtilsLabelEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandBeginDebugUtilsLabelEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BEGIN_DEBUG_UTILS_LABEL_EXT)
//     {}
// };

// struct VulkanCommandEndDebugUtilsLabelEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandEndDebugUtilsLabelEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_END_DEBUG_UTILS_LABEL_EXT)
//     {}
// };

// struct VulkanCommandInsertDebugUtilsLabelEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandInsertDebugUtilsLabelEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_INSERT_DEBUG_UTILS_LABEL_EXT)
//     {}
// };

// struct VulkanCommandSetSampleLocationsEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetSampleLocationsEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_SAMPLE_LOCATIONS_EXT)
//     {}
// };

// struct VulkanCommandBindShadingRateImageNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandBindShadingRateImageNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BIND_SHADING_RATE_IMAGE_NV)
//     {}
// };

// struct VulkanCommandSetViewportShadingRatePaletteNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetViewportShadingRatePaletteNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_VIEWPORT_SHADING_RATE_PALETTE_NV)
//     {}
// };

// struct VulkanCommandSetCoarseSampleOrderNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetCoarseSampleOrderNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_COARSE_SAMPLE_ORDER_NV)
//     {}
// };

// struct VulkanCommandBuildAccelerationStructureNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandBuildAccelerationStructureNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BUILD_ACCELERATION_STRUCTURE_NV)
//     {}
// };

// struct VulkanCommandCopyAccelerationStructureNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyAccelerationStructureNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_ACCELERATION_STRUCTURE_NV)
//     {}
// };

// struct VulkanCommandTraceRaysNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandTraceRaysNVInfo(format::CommandIndexType index) : VulkanCommandInfo(index, VULKAN_CMD_TRACE_RAYS_NV)
//     {}
// };

// struct VulkanCommandWriteAccelerationStructuresPropertiesNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandWriteAccelerationStructuresPropertiesNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_WRITE_ACCELERATION_STRUCTURES_PROPERTIES_NV)
//     {}
// };

// struct VulkanCommandWriteBufferMarkerAMDInfo : public VulkanCommandInfo
// {
//     VulkanCommandWriteBufferMarkerAMDInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_WRITE_BUFFER_MARKER_AMD)
//     {}
// };

// struct VulkanCommandDrawMeshTasksNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawMeshTasksNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_DRAW_MESH_TASKS_NV)
//     {}
// };

// struct VulkanCommandSetExclusiveScissorNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetExclusiveScissorNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_EXCLUSIVE_SCISSOR_NV)
//     {}
// };

// struct VulkanCommandSetCheckpointNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetCheckpointNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_CHECKPOINT_NV)
//     {}
// };

// struct VulkanCommandSetPerformanceMarkerINTELInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetPerformanceMarkerINTELInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_PERFORMANCE_MARKER_INTEL)
//     {}
// };

// struct VulkanCommandSetPerformanceStreamMarkerINTELInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetPerformanceStreamMarkerINTELInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_PERFORMANCE_STREAM_MARKER_INTEL)
//     {}
// };

// struct VulkanCommandSetPerformanceOverrideINTELInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetPerformanceOverrideINTELInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_PERFORMANCE_OVERRIDE_INTEL)
//     {}
// };

// struct VulkanCommandSetLineStippleEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetLineStippleEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_LINE_STIPPLE_EXT)
//     {}
// };

// struct VulkanCommandSetCullModeEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetCullModeEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_CULL_MODE_EXT)
//     {}
// };

// struct VulkanCommandSetFrontFaceEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetFrontFaceEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_FRONT_FACE_EXT)
//     {}
// };

// struct VulkanCommandSetPrimitiveTopologyEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetPrimitiveTopologyEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_PRIMITIVE_TOPOLOGY_EXT)
//     {}
// };

// struct VulkanCommandSetViewportWithCountEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetViewportWithCountEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_VIEWPORT_WITH_COUNT_EXT)
//     {}
// };

// struct VulkanCommandSetScissorWithCountEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetScissorWithCountEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_SCISSOR_WITH_COUNT_EXT)
//     {}
// };

// struct VulkanCommandBindVertexBuffers2EXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandBindVertexBuffers2EXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BIND_VERTEX_BUFFERS2EXT)
//     {}
// };

// struct VulkanCommandSetDepthTestEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthTestEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_TEST_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetDepthWriteEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthWriteEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_WRITE_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetDepthCompareOpEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthCompareOpEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_COMPARE_OP_EXT)
//     {}
// };

// struct VulkanCommandSetDepthBoundsTestEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthBoundsTestEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_BOUNDS_TEST_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetStencilTestEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetStencilTestEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_STENCIL_TEST_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetStencilOpEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetStencilOpEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_STENCIL_OP_EXT)
//     {}
// };

// struct VulkanCommandPreprocessGeneratedCommandsNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandPreprocessGeneratedCommandsNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_PREPROCESS_GENERATED_COMMANDS_NV)
//     {}
// };

// struct VulkanCommandExecuteGeneratedCommandsNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandExecuteGeneratedCommandsNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_EXECUTE_GENERATED_COMMANDS_NV)
//     {}
// };

// struct VulkanCommandBindPipelineShaderGroupNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandBindPipelineShaderGroupNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BIND_PIPELINE_SHADER_GROUP_NV)
//     {}

//     VkPipelineBindPoint pipelineBindPoint;
//     FIPipelineInfo*     pipeline;
// };

// struct VulkanCommandSetFragmentShadingRateEnumNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetFragmentShadingRateEnumNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_FRAGMENT_SHADING_RATE_ENUM_NV)
//     {}
// };

// struct VulkanCommandSetVertexInputEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetVertexInputEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_VERTEX_INPUT_EXT)
//     {}
// };

// struct VulkanCommandBindInvocationMaskHUAWEIInfo : public VulkanCommandInfo
// {
//     VulkanCommandBindInvocationMaskHUAWEIInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BIND_INVOCATION_MASK_HUAWEI)
//     {}
// };

// struct VulkanCommandSetPatchControlPointsEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetPatchControlPointsEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_PATCH_CONTROL_POINTS_EXT)
//     {}
// };

// struct VulkanCommandSetRasterizerDiscardEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetRasterizerDiscardEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_RASTERIZER_DISCARD_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetDepthBiasEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthBiasEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_BIAS_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetLogicOpEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetLogicOpEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_LOGIC_OP_EXT)
//     {}
// };

// struct VulkanCommandSetPrimitiveRestartEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetPrimitiveRestartEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_PRIMITIVE_RESTART_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetColorWriteEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetColorWriteEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_COLOR_WRITE_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandDrawMultiEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawMultiEXTInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_DRAW_MULTI_EXT)
//     {}
// };

// struct VulkanCommandDrawMultiIndexedEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandDrawMultiIndexedEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_DRAW_MULTI_INDEXED_EXT)
//     {}
// };

// struct VulkanCommandBuildMicromapsEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandBuildMicromapsEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BUILD_MICROMAPS_EXT)
//     {}
// };

// struct VulkanCommandCopyMicromapEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyMicromapEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_MICROMAP_EXT)
//     {}
// };

// struct VulkanCommandCopyMicromapToMemoryEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyMicromapToMemoryEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_MICROMAP_TO_MEMORY_EXT)
//     {}
// };

// struct VulkanCommandCopyMemoryToMicromapEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyMemoryToMicromapEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_MEMORY_TO_MICROMAP_EXT)
//     {}
// };

// struct VulkanCommandWriteMicromapsPropertiesEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandWriteMicromapsPropertiesEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_WRITE_MICROMAPS_PROPERTIES_EXT)
//     {}
// };

// struct VulkanCommandSetTessellationDomainOriginEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetTessellationDomainOriginEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_TESSELLATION_DOMAIN_ORIGIN_EXT)
//     {}
// };

// struct VulkanCommandSetDepthClampEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthClampEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_CLAMP_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetPolygonModeEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetPolygonModeEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_POLYGON_MODE_EXT)
//     {}
// };

// struct VulkanCommandSetRasterizationSamplesEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetRasterizationSamplesEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_RASTERIZATION_SAMPLES_EXT)
//     {}
// };

// struct VulkanCommandSetSampleMaskEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetSampleMaskEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_SAMPLE_MASK_EXT)
//     {}
// };

// struct VulkanCommandSetAlphaToCoverageEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetAlphaToCoverageEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_ALPHA_TO_COVERAGE_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetAlphaToOneEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetAlphaToOneEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_ALPHA_TO_ONE_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetLogicOpEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetLogicOpEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_LOGIC_OP_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetColorBlendEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetColorBlendEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_COLOR_BLEND_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetColorBlendEquationEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetColorBlendEquationEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_COLOR_BLEND_EQUATION_EXT)
//     {}
// };

// struct VulkanCommandSetColorWriteMaskEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetColorWriteMaskEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_COLOR_WRITE_MASK_EXT)
//     {}
// };

// struct VulkanCommandSetRasterizationStreamEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetRasterizationStreamEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_RASTERIZATION_STREAM_EXT)
//     {}
// };

// struct VulkanCommandSetConservativeRasterizationModeEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetConservativeRasterizationModeEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_CONSERVATIVE_RASTERIZATION_MODE_EXT)
//     {}
// };

// struct VulkanCommandSetExtraPrimitiveOverestimationSizeEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetExtraPrimitiveOverestimationSizeEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT)
//     {}
// };

// struct VulkanCommandSetDepthClipEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthClipEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_CLIP_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetSampleLocationsEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetSampleLocationsEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_SAMPLE_LOCATIONS_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetColorBlendAdvancedEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetColorBlendAdvancedEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_COLOR_BLEND_ADVANCED_EXT)
//     {}
// };

// struct VulkanCommandSetProvokingVertexModeEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetProvokingVertexModeEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_PROVOKING_VERTEX_MODE_EXT)
//     {}
// };

// struct VulkanCommandSetLineRasterizationModeEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetLineRasterizationModeEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_LINE_RASTERIZATION_MODE_EXT)
//     {}
// };

// struct VulkanCommandSetLineStippleEnableEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetLineStippleEnableEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_LINE_STIPPLE_ENABLE_EXT)
//     {}
// };

// struct VulkanCommandSetDepthClipNegativeOneToOneEXTInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetDepthClipNegativeOneToOneEXTInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT)
//     {}
// };

// struct VulkanCommandSetViewportWScalingEnableNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetViewportWScalingEnableNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_VIEWPORT_W_SCALING_ENABLE_NV)
//     {}
// };

// struct VulkanCommandSetViewportSwizzleNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetViewportSwizzleNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_VIEWPORT_SWIZZLE_NV)
//     {}
// };

// struct VulkanCommandSetCoverageToColorEnableNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetCoverageToColorEnableNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_COVERAGE_TO_COLOR_ENABLE_NV)
//     {}
// };

// struct VulkanCommandSetCoverageToColorLocationNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetCoverageToColorLocationNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_COVERAGE_TO_COLOR_LOCATION_NV)
//     {}
// };

// struct VulkanCommandSetCoverageModulationModeNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetCoverageModulationModeNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_COVERAGE_MODULATION_MODE_NV)
//     {}
// };

// struct VulkanCommandSetCoverageModulationTableEnableNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetCoverageModulationTableEnableNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_COVERAGE_MODULATION_TABLE_ENABLE_NV)
//     {}
// };

// struct VulkanCommandSetCoverageModulationTableNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetCoverageModulationTableNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_COVERAGE_MODULATION_TABLE_NV)
//     {}
// };

// struct VulkanCommandSetShadingRateImageEnableNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetShadingRateImageEnableNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_SHADING_RATE_IMAGE_ENABLE_NV)
//     {}
// };

// struct VulkanCommandSetRepresentativeFragmentTestEnableNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetRepresentativeFragmentTestEnableNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV)
//     {}
// };

// struct VulkanCommandSetCoverageReductionModeNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetCoverageReductionModeNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_COVERAGE_REDUCTION_MODE_NV)
//     {}
// };

// struct VulkanCommandOpticalFlowExecuteNVInfo : public VulkanCommandInfo
// {
//     VulkanCommandOpticalFlowExecuteNVInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_OPTICAL_FLOW_EXECUTE_NV)
//     {}
// };

// struct VulkanCommandBuildAccelerationStructuresKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandBuildAccelerationStructuresKHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_BUILD_ACCELERATION_STRUCTURES_KHR)
//     {}
// };

// struct VulkanCommandCopyAccelerationStructureKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyAccelerationStructureKHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_ACCELERATION_STRUCTURE_KHR)
//     {}
// };

// struct VulkanCommandCopyAccelerationStructureToMemoryKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyAccelerationStructureToMemoryKHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_KHR)
//     {}
// };

// struct VulkanCommandCopyMemoryToAccelerationStructureKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandCopyMemoryToAccelerationStructureKHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_KHR)
//     {}
// };

// struct VulkanCommandWriteAccelerationStructuresPropertiesKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandWriteAccelerationStructuresPropertiesKHRInfo(format::CommandIndexType index,
//                                                               vulkan_command_type      type) :
//         VulkanCommandInfo(index, type)
//     {}
// };

// struct VulkanCommandTraceRaysKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandTraceRaysKHRInfo(format::CommandIndexType index) : VulkanCommandInfo(index,
//     VULKAN_CMD_TRACE_RAYS_KHR)
//     {}
// };

// struct VulkanCommandSetRayTracingPipelineStackSizeKHRInfo : public VulkanCommandInfo
// {
//     VulkanCommandSetRayTracingPipelineStackSizeKHRInfo(format::CommandIndexType index) :
//         VulkanCommandInfo(index, VULKAN_CMD_SET_RAY_TRACING_PIPELINE_STACK_SIZE_KHR)
//     {}
// };

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_CLIENT_VULKAN_COMMANDS_INFO_H */
