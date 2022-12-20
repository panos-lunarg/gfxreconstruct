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

#include "format/format.h"

#include <vector>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct VulkanCommandInfo
{
    format::CommandIndexType index;
};

struct VulkanCommandBindPipelineInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetViewportInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetScissorInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetLineWidthInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthBiasInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetBlendConstantsInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthBoundsInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetStencilCompareMaskInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetStencilWriteMaskInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetStencilReferenceInfo : public VulkanCommandInfo
{};

struct VulkanCommandBindDescriptorSetsInfo : public VulkanCommandInfo
{};

struct VulkanCommandBindIndexBufferInfo : public VulkanCommandInfo
{};

struct VulkanCommandBindVertexBuffersInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawIndexedInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawIndirectInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawIndexedIndirectInfo : public VulkanCommandInfo
{};

struct VulkanCommandDispatchInfo : public VulkanCommandInfo
{};

struct VulkanCommandDispatchIndirectInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyBufferInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyImageInfo : public VulkanCommandInfo
{};

struct VulkanCommandBlitImageInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyBufferToImageInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyImageToBufferInfo : public VulkanCommandInfo
{};

struct VulkanCommandUpdateBufferInfo : public VulkanCommandInfo
{};

struct VulkanCommandFillBufferInfo : public VulkanCommandInfo
{};

struct VulkanCommandClearColorImageInfo : public VulkanCommandInfo
{};

struct VulkanCommandClearDepthStencilImageInfo : public VulkanCommandInfo
{};

struct VulkanCommandClearAttachmentsInfo : public VulkanCommandInfo
{};

struct VulkanCommandResolveImageInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetEventInfo : public VulkanCommandInfo
{};

struct VulkanCommandResetEventInfo : public VulkanCommandInfo
{};

struct VulkanCommandWaitEventsInfo : public VulkanCommandInfo
{};

struct VulkanCommandPipelineBarrierInfo : public VulkanCommandInfo
{};

struct VulkanCommandBeginQueryInfo : public VulkanCommandInfo
{};

struct VulkanCommandEndQueryInfo : public VulkanCommandInfo
{};

struct VulkanCommandResetQueryPoolInfo : public VulkanCommandInfo
{};

struct VulkanCommandWriteTimestampInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyQueryPoolResultsInfo : public VulkanCommandInfo
{};

struct VulkanCommandPushConstantsInfo : public VulkanCommandInfo
{};

struct VulkanCommandBeginRenderPassInfo : public VulkanCommandInfo
{};

struct VulkanCommandNextSubpassInfo : public VulkanCommandInfo
{};

struct VulkanCommandEndRenderPassInfo : public VulkanCommandInfo
{};

struct VulkanCommandExecuteCommandsInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDeviceMaskInfo : public VulkanCommandInfo
{};

struct VulkanCommandDispatchBaseInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawIndirectCountInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawIndexedIndirectCountInfo : public VulkanCommandInfo
{};

struct VulkanCommandBeginRenderPass2Info : public VulkanCommandInfo
{};

struct VulkanCommandNextSubpass2Info : public VulkanCommandInfo
{};

struct VulkanCommandEndRenderPass2Info : public VulkanCommandInfo
{};

struct VulkanCommandSetEvent2Info : public VulkanCommandInfo
{};

struct VulkanCommandResetEvent2Info : public VulkanCommandInfo
{};

struct VulkanCommandWaitEvents2Info : public VulkanCommandInfo
{};

struct VulkanCommandPipelineBarrier2Info : public VulkanCommandInfo
{};

struct VulkanCommandWriteTimestamp2Info : public VulkanCommandInfo
{};

struct VulkanCommandCopyBuffer2Info : public VulkanCommandInfo
{};

struct VulkanCommandCopyImage2Info : public VulkanCommandInfo
{};

struct VulkanCommandCopyBufferToImage2Info : public VulkanCommandInfo
{};

struct VulkanCommandCopyImageToBuffer2Info : public VulkanCommandInfo
{};

struct VulkanCommandBlitImage2Info : public VulkanCommandInfo
{};

struct VulkanCommandResolveImage2Info : public VulkanCommandInfo
{};

struct VulkanCommandBeginRenderingInfo : public VulkanCommandInfo
{};

struct VulkanCommandEndRenderingInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetCullModeInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetFrontFaceInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetPrimitiveTopologyInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetViewportWithCountInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetScissorWithCountInfo : public VulkanCommandInfo
{};

struct VulkanCommandBindVertexBuffers2Info : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthTestEnableInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthWriteEnableInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthCompareOpInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthBoundsTestEnableInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetStencilTestEnableInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetStencilOpInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetRasterizerDiscardEnableInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthBiasEnableInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetPrimitiveRestartEnableInfo : public VulkanCommandInfo
{};

struct VulkanCommandBeginRenderingKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandEndRenderingKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDeviceMaskKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandDispatchBaseKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandPushDescriptorSetKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandPushDescriptorSetWithTemplateKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandBeginRenderPass2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandNextSubpass2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandEndRenderPass2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawIndirectCountKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawIndexedIndirectCountKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetFragmentShadingRateKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetEvent2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandResetEvent2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandWaitEvents2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandPipelineBarrier2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandWriteTimestamp2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandWriteBufferMarker2AMDInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyBuffer2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyImage2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyBufferToImage2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyImageToBuffer2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandBlitImage2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandResolveImage2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandTraceRaysIndirect2KHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandDebugMarkerBeginEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandDebugMarkerEndEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandDebugMarkerInsertEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandBindTransformFeedbackBuffersEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandBeginTransformFeedbackEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandEndTransformFeedbackEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandBeginQueryIndexedEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandEndQueryIndexedEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawIndirectByteCountEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawIndirectCountAMDInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawIndexedIndirectCountAMDInfo : public VulkanCommandInfo
{};

struct VulkanCommandBeginConditionalRenderingEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandEndConditionalRenderingEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetViewportWScalingNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDiscardRectangleEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandBeginDebugUtilsLabelEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandEndDebugUtilsLabelEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandInsertDebugUtilsLabelEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetSampleLocationsEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandBindShadingRateImageNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetViewportShadingRatePaletteNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetCoarseSampleOrderNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandBuildAccelerationStructureNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyAccelerationStructureNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandTraceRaysNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandWriteAccelerationStructuresPropertiesNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandWriteBufferMarkerAMDInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawMeshTasksNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawMeshTasksIndirectNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawMeshTasksIndirectCountNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetExclusiveScissorNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetCheckpointNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetPerformanceMarkerINTELInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetPerformanceStreamMarkerINTELInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetPerformanceOverrideINTELInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetLineStippleEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetCullModeEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetFrontFaceEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetPrimitiveTopologyEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetViewportWithCountEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetScissorWithCountEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandBindVertexBuffers2EXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthTestEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthWriteEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthCompareOpEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthBoundsTestEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetStencilTestEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetStencilOpEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandPreprocessGeneratedCommandsNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandExecuteGeneratedCommandsNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandBindPipelineShaderGroupNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetFragmentShadingRateEnumNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetVertexInputEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandBindInvocationMaskHUAWEIInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetPatchControlPointsEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetRasterizerDiscardEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthBiasEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetLogicOpEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetPrimitiveRestartEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetColorWriteEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawMultiEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawMultiIndexedEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandBuildMicromapsEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyMicromapEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyMicromapToMemoryEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyMemoryToMicromapEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandWriteMicromapsPropertiesEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetTessellationDomainOriginEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthClampEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetPolygonModeEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetRasterizationSamplesEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetSampleMaskEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetAlphaToCoverageEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetAlphaToOneEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetLogicOpEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetColorBlendEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetColorBlendEquationEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetColorWriteMaskEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetRasterizationStreamEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetConservativeRasterizationModeEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetExtraPrimitiveOverestimationSizeEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthClipEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetSampleLocationsEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetColorBlendAdvancedEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetProvokingVertexModeEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetLineRasterizationModeEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetLineStippleEnableEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetDepthClipNegativeOneToOneEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetViewportWScalingEnableNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetViewportSwizzleNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetCoverageToColorEnableNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetCoverageToColorLocationNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetCoverageModulationModeNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetCoverageModulationTableEnableNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetCoverageModulationTableNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetShadingRateImageEnableNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetRepresentativeFragmentTestEnableNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetCoverageReductionModeNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandOpticalFlowExecuteNVInfo : public VulkanCommandInfo
{};

struct VulkanCommandBuildAccelerationStructuresKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandBuildAccelerationStructuresIndirectKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyAccelerationStructureKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyAccelerationStructureToMemoryKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandCopyMemoryToAccelerationStructureKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandWriteAccelerationStructuresPropertiesKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandTraceRaysKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandTraceRaysIndirectKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandSetRayTracingPipelineStackSizeKHRInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawMeshTasksEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawMeshTasksIndirectEXTInfo : public VulkanCommandInfo
{};

struct VulkanCommandDrawMeshTasksIndirectCountEXTInfo : public VulkanCommandInfo
{};


GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif // GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_OBJECT_INFO_H
