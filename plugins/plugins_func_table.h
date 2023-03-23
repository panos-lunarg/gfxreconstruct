#ifndef  GFXRECON_PLUGINS_FUNC_TABLE_H
#define  GFXRECON_PLUGINS_FUNC_TABLE_H

#include "util/defines.h"
#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#include "entrypoints_pre.h"
#include "entrypoints_post.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugins)

static const char * func_table_pre[] =
{
{"CreateInstance_PreCall"},
{"DestroyInstance_PreCall"},
{"EnumeratePhysicalDevices_PreCall"},
{"GetPhysicalDeviceFeatures_PreCall"},
{"GetPhysicalDeviceFormatProperties_PreCall"},
{"GetPhysicalDeviceImageFormatProperties_PreCall"},
{"GetPhysicalDeviceProperties_PreCall"},
{"GetPhysicalDeviceQueueFamilyProperties_PreCall"},
{"GetPhysicalDeviceMemoryProperties_PreCall"},
{"CreateDevice_PreCall"},
{"DestroyDevice_PreCall"},
{"GetDeviceQueue_PreCall"},
{"QueueSubmit_PreCall"},
{"QueueWaitIdle_PreCall"},
{"DeviceWaitIdle_PreCall"},
{"AllocateMemory_PreCall"},
{"FreeMemory_PreCall"},
{"MapMemory_PreCall"},
{"UnmapMemory_PreCall"},
{"FlushMappedMemoryRanges_PreCall"},
{"InvalidateMappedMemoryRanges_PreCall"},
{"GetDeviceMemoryCommitment_PreCall"},
{"BindBufferMemory_PreCall"},
{"BindImageMemory_PreCall"},
{"GetBufferMemoryRequirements_PreCall"},
{"GetImageMemoryRequirements_PreCall"},
{"GetImageSparseMemoryRequirements_PreCall"},
{"GetPhysicalDeviceSparseImageFormatProperties_PreCall"},
{"QueueBindSparse_PreCall"},
{"CreateFence_PreCall"},
{"DestroyFence_PreCall"},
{"ResetFences_PreCall"},
{"GetFenceStatus_PreCall"},
{"WaitForFences_PreCall"},
{"CreateSemaphore_PreCall"},
{"DestroySemaphore_PreCall"},
{"CreateEvent_PreCall"},
{"DestroyEvent_PreCall"},
{"GetEventStatus_PreCall"},
{"SetEvent_PreCall"},
{"ResetEvent_PreCall"},
{"CreateQueryPool_PreCall"},
{"DestroyQueryPool_PreCall"},
{"GetQueryPoolResults_PreCall"},
{"CreateBuffer_PreCall"},
{"DestroyBuffer_PreCall"},
{"CreateBufferView_PreCall"},
{"DestroyBufferView_PreCall"},
{"CreateImage_PreCall"},
{"DestroyImage_PreCall"},
{"GetImageSubresourceLayout_PreCall"},
{"CreateImageView_PreCall"},
{"DestroyImageView_PreCall"},
{"CreateShaderModule_PreCall"},
{"DestroyShaderModule_PreCall"},
{"CreatePipelineCache_PreCall"},
{"DestroyPipelineCache_PreCall"},
{"GetPipelineCacheData_PreCall"},
{"MergePipelineCaches_PreCall"},
{"CreateGraphicsPipelines_PreCall"},
{"CreateComputePipelines_PreCall"},
{"DestroyPipeline_PreCall"},
{"CreatePipelineLayout_PreCall"},
{"DestroyPipelineLayout_PreCall"},
{"CreateSampler_PreCall"},
{"DestroySampler_PreCall"},
{"CreateDescriptorSetLayout_PreCall"},
{"DestroyDescriptorSetLayout_PreCall"},
{"CreateDescriptorPool_PreCall"},
{"DestroyDescriptorPool_PreCall"},
{"ResetDescriptorPool_PreCall"},
{"AllocateDescriptorSets_PreCall"},
{"FreeDescriptorSets_PreCall"},
{"UpdateDescriptorSets_PreCall"},
{"CreateFramebuffer_PreCall"},
{"DestroyFramebuffer_PreCall"},
{"CreateRenderPass_PreCall"},
{"DestroyRenderPass_PreCall"},
{"GetRenderAreaGranularity_PreCall"},
{"CreateCommandPool_PreCall"},
{"DestroyCommandPool_PreCall"},
{"ResetCommandPool_PreCall"},
{"AllocateCommandBuffers_PreCall"},
{"FreeCommandBuffers_PreCall"},
{"BeginCommandBuffer_PreCall"},
{"EndCommandBuffer_PreCall"},
{"ResetCommandBuffer_PreCall"},
{"CmdBindPipeline_PreCall"},
{"CmdSetViewport_PreCall"},
{"CmdSetScissor_PreCall"},
{"CmdSetLineWidth_PreCall"},
{"CmdSetDepthBias_PreCall"},
{"CmdSetBlendConstants_PreCall"},
{"CmdSetDepthBounds_PreCall"},
{"CmdSetStencilCompareMask_PreCall"},
{"CmdSetStencilWriteMask_PreCall"},
{"CmdSetStencilReference_PreCall"},
{"CmdBindDescriptorSets_PreCall"},
{"CmdBindIndexBuffer_PreCall"},
{"CmdBindVertexBuffers_PreCall"},
{"CmdDraw_PreCall"},
{"CmdDrawIndexed_PreCall"},
{"CmdDrawIndirect_PreCall"},
{"CmdDrawIndexedIndirect_PreCall"},
{"CmdDispatch_PreCall"},
{"CmdDispatchIndirect_PreCall"},
{"CmdCopyBuffer_PreCall"},
{"CmdCopyImage_PreCall"},
{"CmdBlitImage_PreCall"},
{"CmdCopyBufferToImage_PreCall"},
{"CmdCopyImageToBuffer_PreCall"},
{"CmdUpdateBuffer_PreCall"},
{"CmdFillBuffer_PreCall"},
{"CmdClearColorImage_PreCall"},
{"CmdClearDepthStencilImage_PreCall"},
{"CmdClearAttachments_PreCall"},
{"CmdResolveImage_PreCall"},
{"CmdSetEvent_PreCall"},
{"CmdResetEvent_PreCall"},
{"CmdWaitEvents_PreCall"},
{"CmdPipelineBarrier_PreCall"},
{"CmdBeginQuery_PreCall"},
{"CmdEndQuery_PreCall"},
{"CmdResetQueryPool_PreCall"},
{"CmdWriteTimestamp_PreCall"},
{"CmdCopyQueryPoolResults_PreCall"},
{"CmdPushConstants_PreCall"},
{"CmdBeginRenderPass_PreCall"},
{"CmdNextSubpass_PreCall"},
{"CmdEndRenderPass_PreCall"},
{"CmdExecuteCommands_PreCall"},
{"BindBufferMemory2_PreCall"},
{"BindImageMemory2_PreCall"},
{"GetDeviceGroupPeerMemoryFeatures_PreCall"},
{"CmdSetDeviceMask_PreCall"},
{"CmdDispatchBase_PreCall"},
{"EnumeratePhysicalDeviceGroups_PreCall"},
{"GetImageMemoryRequirements2_PreCall"},
{"GetBufferMemoryRequirements2_PreCall"},
{"GetImageSparseMemoryRequirements2_PreCall"},
{"GetPhysicalDeviceFeatures2_PreCall"},
{"GetPhysicalDeviceProperties2_PreCall"},
{"GetPhysicalDeviceFormatProperties2_PreCall"},
{"GetPhysicalDeviceImageFormatProperties2_PreCall"},
{"GetPhysicalDeviceQueueFamilyProperties2_PreCall"},
{"GetPhysicalDeviceMemoryProperties2_PreCall"},
{"GetPhysicalDeviceSparseImageFormatProperties2_PreCall"},
{"TrimCommandPool_PreCall"},
{"GetDeviceQueue2_PreCall"},
{"CreateSamplerYcbcrConversion_PreCall"},
{"DestroySamplerYcbcrConversion_PreCall"},
{"CreateDescriptorUpdateTemplate_PreCall"},
{"DestroyDescriptorUpdateTemplate_PreCall"},
{"GetPhysicalDeviceExternalBufferProperties_PreCall"},
{"GetPhysicalDeviceExternalFenceProperties_PreCall"},
{"GetPhysicalDeviceExternalSemaphoreProperties_PreCall"},
{"GetDescriptorSetLayoutSupport_PreCall"},
{"CmdDrawIndirectCount_PreCall"},
{"CmdDrawIndexedIndirectCount_PreCall"},
{"CreateRenderPass2_PreCall"},
{"CmdBeginRenderPass2_PreCall"},
{"CmdNextSubpass2_PreCall"},
{"CmdEndRenderPass2_PreCall"},
{"ResetQueryPool_PreCall"},
{"GetSemaphoreCounterValue_PreCall"},
{"WaitSemaphores_PreCall"},
{"SignalSemaphore_PreCall"},
{"GetBufferDeviceAddress_PreCall"},
{"GetBufferOpaqueCaptureAddress_PreCall"},
{"GetDeviceMemoryOpaqueCaptureAddress_PreCall"},
{"GetPhysicalDeviceToolProperties_PreCall"},
{"CreatePrivateDataSlot_PreCall"},
{"DestroyPrivateDataSlot_PreCall"},
{"SetPrivateData_PreCall"},
{"GetPrivateData_PreCall"},
{"CmdSetEvent2_PreCall"},
{"CmdResetEvent2_PreCall"},
{"CmdWaitEvents2_PreCall"},
{"CmdPipelineBarrier2_PreCall"},
{"CmdWriteTimestamp2_PreCall"},
{"QueueSubmit2_PreCall"},
{"CmdCopyBuffer2_PreCall"},
{"CmdCopyImage2_PreCall"},
{"CmdCopyBufferToImage2_PreCall"},
{"CmdCopyImageToBuffer2_PreCall"},
{"CmdBlitImage2_PreCall"},
{"CmdResolveImage2_PreCall"},
{"CmdBeginRendering_PreCall"},
{"CmdEndRendering_PreCall"},
{"CmdSetCullMode_PreCall"},
{"CmdSetFrontFace_PreCall"},
{"CmdSetPrimitiveTopology_PreCall"},
{"CmdSetViewportWithCount_PreCall"},
{"CmdSetScissorWithCount_PreCall"},
{"CmdBindVertexBuffers2_PreCall"},
{"CmdSetDepthTestEnable_PreCall"},
{"CmdSetDepthWriteEnable_PreCall"},
{"CmdSetDepthCompareOp_PreCall"},
{"CmdSetDepthBoundsTestEnable_PreCall"},
{"CmdSetStencilTestEnable_PreCall"},
{"CmdSetStencilOp_PreCall"},
{"CmdSetRasterizerDiscardEnable_PreCall"},
{"CmdSetDepthBiasEnable_PreCall"},
{"CmdSetPrimitiveRestartEnable_PreCall"},
{"GetDeviceBufferMemoryRequirements_PreCall"},
{"GetDeviceImageMemoryRequirements_PreCall"},
{"GetDeviceImageSparseMemoryRequirements_PreCall"},
{"DestroySurfaceKHR_PreCall"},
{"GetPhysicalDeviceSurfaceSupportKHR_PreCall"},
{"GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall"},
{"GetPhysicalDeviceSurfaceFormatsKHR_PreCall"},
{"GetPhysicalDeviceSurfacePresentModesKHR_PreCall"},
{"CreateSwapchainKHR_PreCall"},
{"DestroySwapchainKHR_PreCall"},
{"GetSwapchainImagesKHR_PreCall"},
{"AcquireNextImageKHR_PreCall"},
{"QueuePresentKHR_PreCall"},
{"GetDeviceGroupPresentCapabilitiesKHR_PreCall"},
{"GetDeviceGroupSurfacePresentModesKHR_PreCall"},
{"GetPhysicalDevicePresentRectanglesKHR_PreCall"},
{"AcquireNextImage2KHR_PreCall"},
{"GetPhysicalDeviceDisplayPropertiesKHR_PreCall"},
{"GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall"},
{"GetDisplayPlaneSupportedDisplaysKHR_PreCall"},
{"GetDisplayModePropertiesKHR_PreCall"},
{"CreateDisplayModeKHR_PreCall"},
{"GetDisplayPlaneCapabilitiesKHR_PreCall"},
{"CreateDisplayPlaneSurfaceKHR_PreCall"},
{"CreateSharedSwapchainsKHR_PreCall"},
{"CreateXlibSurfaceKHR_PreCall"},
{"GetPhysicalDeviceXlibPresentationSupportKHR_PreCall"},
{"CreateXcbSurfaceKHR_PreCall"},
{"GetPhysicalDeviceXcbPresentationSupportKHR_PreCall"},
{"CreateWaylandSurfaceKHR_PreCall"},
{"GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall"},
{"CreateAndroidSurfaceKHR_PreCall"},
{"CreateWin32SurfaceKHR_PreCall"},
{"GetPhysicalDeviceWin32PresentationSupportKHR_PreCall"},
{"GetPhysicalDeviceVideoCapabilitiesKHR_PreCall"},
{"GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall"},
{"CreateVideoSessionKHR_PreCall"},
{"DestroyVideoSessionKHR_PreCall"},
{"GetVideoSessionMemoryRequirementsKHR_PreCall"},
{"BindVideoSessionMemoryKHR_PreCall"},
{"CreateVideoSessionParametersKHR_PreCall"},
{"UpdateVideoSessionParametersKHR_PreCall"},
{"DestroyVideoSessionParametersKHR_PreCall"},
{"CmdBeginVideoCodingKHR_PreCall"},
{"CmdEndVideoCodingKHR_PreCall"},
{"CmdControlVideoCodingKHR_PreCall"},
{"CmdDecodeVideoKHR_PreCall"},
{"CmdBeginRenderingKHR_PreCall"},
{"CmdEndRenderingKHR_PreCall"},
{"GetPhysicalDeviceFeatures2KHR_PreCall"},
{"GetPhysicalDeviceProperties2KHR_PreCall"},
{"GetPhysicalDeviceFormatProperties2KHR_PreCall"},
{"GetPhysicalDeviceImageFormatProperties2KHR_PreCall"},
{"GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall"},
{"GetPhysicalDeviceMemoryProperties2KHR_PreCall"},
{"GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall"},
{"GetDeviceGroupPeerMemoryFeaturesKHR_PreCall"},
{"CmdSetDeviceMaskKHR_PreCall"},
{"CmdDispatchBaseKHR_PreCall"},
{"TrimCommandPoolKHR_PreCall"},
{"EnumeratePhysicalDeviceGroupsKHR_PreCall"},
{"GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall"},
{"GetMemoryWin32HandleKHR_PreCall"},
{"GetMemoryWin32HandlePropertiesKHR_PreCall"},
{"GetMemoryFdKHR_PreCall"},
{"GetMemoryFdPropertiesKHR_PreCall"},
{"GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall"},
{"ImportSemaphoreWin32HandleKHR_PreCall"},
{"GetSemaphoreWin32HandleKHR_PreCall"},
{"ImportSemaphoreFdKHR_PreCall"},
{"GetSemaphoreFdKHR_PreCall"},
{"CmdPushDescriptorSetKHR_PreCall"},
{"CreateDescriptorUpdateTemplateKHR_PreCall"},
{"DestroyDescriptorUpdateTemplateKHR_PreCall"},
{"CreateRenderPass2KHR_PreCall"},
{"CmdBeginRenderPass2KHR_PreCall"},
{"CmdNextSubpass2KHR_PreCall"},
{"CmdEndRenderPass2KHR_PreCall"},
{"GetSwapchainStatusKHR_PreCall"},
{"GetPhysicalDeviceExternalFencePropertiesKHR_PreCall"},
{"ImportFenceWin32HandleKHR_PreCall"},
{"GetFenceWin32HandleKHR_PreCall"},
{"ImportFenceFdKHR_PreCall"},
{"GetFenceFdKHR_PreCall"},
{"EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall"},
{"GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall"},
{"AcquireProfilingLockKHR_PreCall"},
{"ReleaseProfilingLockKHR_PreCall"},
{"GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall"},
{"GetPhysicalDeviceSurfaceFormats2KHR_PreCall"},
{"GetPhysicalDeviceDisplayProperties2KHR_PreCall"},
{"GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall"},
{"GetDisplayModeProperties2KHR_PreCall"},
{"GetDisplayPlaneCapabilities2KHR_PreCall"},
{"GetImageMemoryRequirements2KHR_PreCall"},
{"GetBufferMemoryRequirements2KHR_PreCall"},
{"GetImageSparseMemoryRequirements2KHR_PreCall"},
{"CreateSamplerYcbcrConversionKHR_PreCall"},
{"DestroySamplerYcbcrConversionKHR_PreCall"},
{"BindBufferMemory2KHR_PreCall"},
{"BindImageMemory2KHR_PreCall"},
{"GetDescriptorSetLayoutSupportKHR_PreCall"},
{"CmdDrawIndirectCountKHR_PreCall"},
{"CmdDrawIndexedIndirectCountKHR_PreCall"},
{"GetSemaphoreCounterValueKHR_PreCall"},
{"WaitSemaphoresKHR_PreCall"},
{"SignalSemaphoreKHR_PreCall"},
{"GetPhysicalDeviceFragmentShadingRatesKHR_PreCall"},
{"CmdSetFragmentShadingRateKHR_PreCall"},
{"WaitForPresentKHR_PreCall"},
{"GetBufferDeviceAddressKHR_PreCall"},
{"GetBufferOpaqueCaptureAddressKHR_PreCall"},
{"GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall"},
{"CreateDeferredOperationKHR_PreCall"},
{"DestroyDeferredOperationKHR_PreCall"},
{"GetDeferredOperationMaxConcurrencyKHR_PreCall"},
{"GetDeferredOperationResultKHR_PreCall"},
{"DeferredOperationJoinKHR_PreCall"},
{"GetPipelineExecutablePropertiesKHR_PreCall"},
{"GetPipelineExecutableStatisticsKHR_PreCall"},
{"GetPipelineExecutableInternalRepresentationsKHR_PreCall"},
{"CmdEncodeVideoKHR_PreCall"},
{"CmdSetEvent2KHR_PreCall"},
{"CmdResetEvent2KHR_PreCall"},
{"CmdWaitEvents2KHR_PreCall"},
{"CmdPipelineBarrier2KHR_PreCall"},
{"CmdWriteTimestamp2KHR_PreCall"},
{"QueueSubmit2KHR_PreCall"},
{"CmdWriteBufferMarker2AMD_PreCall"},
{"GetQueueCheckpointData2NV_PreCall"},
{"CmdCopyBuffer2KHR_PreCall"},
{"CmdCopyImage2KHR_PreCall"},
{"CmdCopyBufferToImage2KHR_PreCall"},
{"CmdCopyImageToBuffer2KHR_PreCall"},
{"CmdBlitImage2KHR_PreCall"},
{"CmdResolveImage2KHR_PreCall"},
{"CmdTraceRaysIndirect2KHR_PreCall"},
{"GetDeviceBufferMemoryRequirementsKHR_PreCall"},
{"GetDeviceImageMemoryRequirementsKHR_PreCall"},
{"GetDeviceImageSparseMemoryRequirementsKHR_PreCall"},
{"CreateDebugReportCallbackEXT_PreCall"},
{"DestroyDebugReportCallbackEXT_PreCall"},
{"DebugReportMessageEXT_PreCall"},
{"DebugMarkerSetObjectTagEXT_PreCall"},
{"DebugMarkerSetObjectNameEXT_PreCall"},
{"CmdDebugMarkerBeginEXT_PreCall"},
{"CmdDebugMarkerEndEXT_PreCall"},
{"CmdDebugMarkerInsertEXT_PreCall"},
{"CmdBindTransformFeedbackBuffersEXT_PreCall"},
{"CmdBeginTransformFeedbackEXT_PreCall"},
{"CmdEndTransformFeedbackEXT_PreCall"},
{"CmdBeginQueryIndexedEXT_PreCall"},
{"CmdEndQueryIndexedEXT_PreCall"},
{"CmdDrawIndirectByteCountEXT_PreCall"},
{"GetImageViewHandleNVX_PreCall"},
{"GetImageViewAddressNVX_PreCall"},
{"CmdDrawIndirectCountAMD_PreCall"},
{"CmdDrawIndexedIndirectCountAMD_PreCall"},
{"GetShaderInfoAMD_PreCall"},
{"CreateStreamDescriptorSurfaceGGP_PreCall"},
{"GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall"},
{"GetMemoryWin32HandleNV_PreCall"},
{"CreateViSurfaceNN_PreCall"},
{"CmdBeginConditionalRenderingEXT_PreCall"},
{"CmdEndConditionalRenderingEXT_PreCall"},
{"CmdSetViewportWScalingNV_PreCall"},
{"ReleaseDisplayEXT_PreCall"},
{"AcquireXlibDisplayEXT_PreCall"},
{"GetRandROutputDisplayEXT_PreCall"},
{"GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall"},
{"DisplayPowerControlEXT_PreCall"},
{"RegisterDeviceEventEXT_PreCall"},
{"RegisterDisplayEventEXT_PreCall"},
{"GetSwapchainCounterEXT_PreCall"},
{"GetRefreshCycleDurationGOOGLE_PreCall"},
{"GetPastPresentationTimingGOOGLE_PreCall"},
{"CmdSetDiscardRectangleEXT_PreCall"},
{"CmdSetDiscardRectangleEnableEXT_PreCall"},
{"CmdSetDiscardRectangleModeEXT_PreCall"},
{"SetHdrMetadataEXT_PreCall"},
{"CreateIOSSurfaceMVK_PreCall"},
{"CreateMacOSSurfaceMVK_PreCall"},
{"SetDebugUtilsObjectNameEXT_PreCall"},
{"SetDebugUtilsObjectTagEXT_PreCall"},
{"QueueBeginDebugUtilsLabelEXT_PreCall"},
{"QueueEndDebugUtilsLabelEXT_PreCall"},
{"QueueInsertDebugUtilsLabelEXT_PreCall"},
{"CmdBeginDebugUtilsLabelEXT_PreCall"},
{"CmdEndDebugUtilsLabelEXT_PreCall"},
{"CmdInsertDebugUtilsLabelEXT_PreCall"},
{"CreateDebugUtilsMessengerEXT_PreCall"},
{"DestroyDebugUtilsMessengerEXT_PreCall"},
{"SubmitDebugUtilsMessageEXT_PreCall"},
{"GetAndroidHardwareBufferPropertiesANDROID_PreCall"},
{"GetMemoryAndroidHardwareBufferANDROID_PreCall"},
{"CmdSetSampleLocationsEXT_PreCall"},
{"GetPhysicalDeviceMultisamplePropertiesEXT_PreCall"},
{"GetImageDrmFormatModifierPropertiesEXT_PreCall"},
{"CreateValidationCacheEXT_PreCall"},
{"DestroyValidationCacheEXT_PreCall"},
{"MergeValidationCachesEXT_PreCall"},
{"GetValidationCacheDataEXT_PreCall"},
{"CmdBindShadingRateImageNV_PreCall"},
{"CmdSetViewportShadingRatePaletteNV_PreCall"},
{"CmdSetCoarseSampleOrderNV_PreCall"},
{"CreateAccelerationStructureNV_PreCall"},
{"DestroyAccelerationStructureNV_PreCall"},
{"GetAccelerationStructureMemoryRequirementsNV_PreCall"},
{"BindAccelerationStructureMemoryNV_PreCall"},
{"CmdBuildAccelerationStructureNV_PreCall"},
{"CmdCopyAccelerationStructureNV_PreCall"},
{"CmdTraceRaysNV_PreCall"},
{"CreateRayTracingPipelinesNV_PreCall"},
{"GetRayTracingShaderGroupHandlesKHR_PreCall"},
{"GetRayTracingShaderGroupHandlesNV_PreCall"},
{"GetAccelerationStructureHandleNV_PreCall"},
{"CmdWriteAccelerationStructuresPropertiesNV_PreCall"},
{"CompileDeferredNV_PreCall"},
{"GetMemoryHostPointerPropertiesEXT_PreCall"},
{"CmdWriteBufferMarkerAMD_PreCall"},
{"GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall"},
{"GetCalibratedTimestampsEXT_PreCall"},
{"CmdDrawMeshTasksNV_PreCall"},
{"CmdDrawMeshTasksIndirectNV_PreCall"},
{"CmdDrawMeshTasksIndirectCountNV_PreCall"},
{"CmdSetExclusiveScissorEnableNV_PreCall"},
{"CmdSetExclusiveScissorNV_PreCall"},
{"CmdSetCheckpointNV_PreCall"},
{"GetQueueCheckpointDataNV_PreCall"},
{"InitializePerformanceApiINTEL_PreCall"},
{"UninitializePerformanceApiINTEL_PreCall"},
{"CmdSetPerformanceMarkerINTEL_PreCall"},
{"CmdSetPerformanceStreamMarkerINTEL_PreCall"},
{"CmdSetPerformanceOverrideINTEL_PreCall"},
{"AcquirePerformanceConfigurationINTEL_PreCall"},
{"ReleasePerformanceConfigurationINTEL_PreCall"},
{"QueueSetPerformanceConfigurationINTEL_PreCall"},
{"GetPerformanceParameterINTEL_PreCall"},
{"SetLocalDimmingAMD_PreCall"},
{"CreateImagePipeSurfaceFUCHSIA_PreCall"},
{"CreateMetalSurfaceEXT_PreCall"},
{"GetBufferDeviceAddressEXT_PreCall"},
{"GetPhysicalDeviceToolPropertiesEXT_PreCall"},
{"GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall"},
{"GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall"},
{"GetPhysicalDeviceSurfacePresentModes2EXT_PreCall"},
{"AcquireFullScreenExclusiveModeEXT_PreCall"},
{"ReleaseFullScreenExclusiveModeEXT_PreCall"},
{"GetDeviceGroupSurfacePresentModes2EXT_PreCall"},
{"CreateHeadlessSurfaceEXT_PreCall"},
{"CmdSetLineStippleEXT_PreCall"},
{"ResetQueryPoolEXT_PreCall"},
{"CmdSetCullModeEXT_PreCall"},
{"CmdSetFrontFaceEXT_PreCall"},
{"CmdSetPrimitiveTopologyEXT_PreCall"},
{"CmdSetViewportWithCountEXT_PreCall"},
{"CmdSetScissorWithCountEXT_PreCall"},
{"CmdBindVertexBuffers2EXT_PreCall"},
{"CmdSetDepthTestEnableEXT_PreCall"},
{"CmdSetDepthWriteEnableEXT_PreCall"},
{"CmdSetDepthCompareOpEXT_PreCall"},
{"CmdSetDepthBoundsTestEnableEXT_PreCall"},
{"CmdSetStencilTestEnableEXT_PreCall"},
{"CmdSetStencilOpEXT_PreCall"},
{"ReleaseSwapchainImagesEXT_PreCall"},
{"GetGeneratedCommandsMemoryRequirementsNV_PreCall"},
{"CmdPreprocessGeneratedCommandsNV_PreCall"},
{"CmdExecuteGeneratedCommandsNV_PreCall"},
{"CmdBindPipelineShaderGroupNV_PreCall"},
{"CreateIndirectCommandsLayoutNV_PreCall"},
{"DestroyIndirectCommandsLayoutNV_PreCall"},
{"AcquireDrmDisplayEXT_PreCall"},
{"GetDrmDisplayEXT_PreCall"},
{"CreatePrivateDataSlotEXT_PreCall"},
{"DestroyPrivateDataSlotEXT_PreCall"},
{"SetPrivateDataEXT_PreCall"},
{"GetPrivateDataEXT_PreCall"},
{"CmdSetFragmentShadingRateEnumNV_PreCall"},
{"GetImageSubresourceLayout2EXT_PreCall"},
{"GetDeviceFaultInfoEXT_PreCall"},
{"AcquireWinrtDisplayNV_PreCall"},
{"GetWinrtDisplayNV_PreCall"},
{"CreateDirectFBSurfaceEXT_PreCall"},
{"GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall"},
{"CmdSetVertexInputEXT_PreCall"},
{"GetMemoryZirconHandleFUCHSIA_PreCall"},
{"GetMemoryZirconHandlePropertiesFUCHSIA_PreCall"},
{"ImportSemaphoreZirconHandleFUCHSIA_PreCall"},
{"GetSemaphoreZirconHandleFUCHSIA_PreCall"},
{"CmdBindInvocationMaskHUAWEI_PreCall"},
{"GetMemoryRemoteAddressNV_PreCall"},
{"CmdSetPatchControlPointsEXT_PreCall"},
{"CmdSetRasterizerDiscardEnableEXT_PreCall"},
{"CmdSetDepthBiasEnableEXT_PreCall"},
{"CmdSetLogicOpEXT_PreCall"},
{"CmdSetPrimitiveRestartEnableEXT_PreCall"},
{"CreateScreenSurfaceQNX_PreCall"},
{"GetPhysicalDeviceScreenPresentationSupportQNX_PreCall"},
{"CmdSetColorWriteEnableEXT_PreCall"},
{"CmdDrawMultiEXT_PreCall"},
{"CmdDrawMultiIndexedEXT_PreCall"},
{"CreateMicromapEXT_PreCall"},
{"DestroyMicromapEXT_PreCall"},
{"CmdBuildMicromapsEXT_PreCall"},
{"BuildMicromapsEXT_PreCall"},
{"CopyMicromapEXT_PreCall"},
{"CopyMicromapToMemoryEXT_PreCall"},
{"CopyMemoryToMicromapEXT_PreCall"},
{"WriteMicromapsPropertiesEXT_PreCall"},
{"CmdCopyMicromapEXT_PreCall"},
{"CmdCopyMicromapToMemoryEXT_PreCall"},
{"CmdCopyMemoryToMicromapEXT_PreCall"},
{"CmdWriteMicromapsPropertiesEXT_PreCall"},
{"GetDeviceMicromapCompatibilityEXT_PreCall"},
{"GetMicromapBuildSizesEXT_PreCall"},
{"CmdDrawClusterHUAWEI_PreCall"},
{"CmdDrawClusterIndirectHUAWEI_PreCall"},
{"SetDeviceMemoryPriorityEXT_PreCall"},
{"GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall"},
{"GetDescriptorSetHostMappingVALVE_PreCall"},
{"CmdSetTessellationDomainOriginEXT_PreCall"},
{"CmdSetDepthClampEnableEXT_PreCall"},
{"CmdSetPolygonModeEXT_PreCall"},
{"CmdSetRasterizationSamplesEXT_PreCall"},
{"CmdSetSampleMaskEXT_PreCall"},
{"CmdSetAlphaToCoverageEnableEXT_PreCall"},
{"CmdSetAlphaToOneEnableEXT_PreCall"},
{"CmdSetLogicOpEnableEXT_PreCall"},
{"CmdSetColorBlendEnableEXT_PreCall"},
{"CmdSetColorBlendEquationEXT_PreCall"},
{"CmdSetColorWriteMaskEXT_PreCall"},
{"CmdSetRasterizationStreamEXT_PreCall"},
{"CmdSetConservativeRasterizationModeEXT_PreCall"},
{"CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall"},
{"CmdSetDepthClipEnableEXT_PreCall"},
{"CmdSetSampleLocationsEnableEXT_PreCall"},
{"CmdSetColorBlendAdvancedEXT_PreCall"},
{"CmdSetProvokingVertexModeEXT_PreCall"},
{"CmdSetLineRasterizationModeEXT_PreCall"},
{"CmdSetLineStippleEnableEXT_PreCall"},
{"CmdSetDepthClipNegativeOneToOneEXT_PreCall"},
{"CmdSetViewportWScalingEnableNV_PreCall"},
{"CmdSetViewportSwizzleNV_PreCall"},
{"CmdSetCoverageToColorEnableNV_PreCall"},
{"CmdSetCoverageToColorLocationNV_PreCall"},
{"CmdSetCoverageModulationModeNV_PreCall"},
{"CmdSetCoverageModulationTableEnableNV_PreCall"},
{"CmdSetCoverageModulationTableNV_PreCall"},
{"CmdSetShadingRateImageEnableNV_PreCall"},
{"CmdSetRepresentativeFragmentTestEnableNV_PreCall"},
{"CmdSetCoverageReductionModeNV_PreCall"},
{"GetShaderModuleIdentifierEXT_PreCall"},
{"GetShaderModuleCreateInfoIdentifierEXT_PreCall"},
{"GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall"},
{"CreateOpticalFlowSessionNV_PreCall"},
{"DestroyOpticalFlowSessionNV_PreCall"},
{"BindOpticalFlowSessionImageNV_PreCall"},
{"CmdOpticalFlowExecuteNV_PreCall"},
{"GetFramebufferTilePropertiesQCOM_PreCall"},
{"GetDynamicRenderingTilePropertiesQCOM_PreCall"},
{"CreateAccelerationStructureKHR_PreCall"},
{"DestroyAccelerationStructureKHR_PreCall"},
{"CmdBuildAccelerationStructuresKHR_PreCall"},
{"CmdBuildAccelerationStructuresIndirectKHR_PreCall"},
{"CopyAccelerationStructureToMemoryKHR_PreCall"},
{"CopyMemoryToAccelerationStructureKHR_PreCall"},
{"WriteAccelerationStructuresPropertiesKHR_PreCall"},
{"CmdCopyAccelerationStructureKHR_PreCall"},
{"CmdCopyAccelerationStructureToMemoryKHR_PreCall"},
{"CmdCopyMemoryToAccelerationStructureKHR_PreCall"},
{"GetAccelerationStructureDeviceAddressKHR_PreCall"},
{"CmdWriteAccelerationStructuresPropertiesKHR_PreCall"},
{"GetDeviceAccelerationStructureCompatibilityKHR_PreCall"},
{"GetAccelerationStructureBuildSizesKHR_PreCall"},
{"CmdTraceRaysKHR_PreCall"},
{"CreateRayTracingPipelinesKHR_PreCall"},
{"GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall"},
{"CmdTraceRaysIndirectKHR_PreCall"},
{"GetRayTracingShaderGroupStackSizeKHR_PreCall"},
{"CmdSetRayTracingPipelineStackSizeKHR_PreCall"},
{"CmdDrawMeshTasksEXT_PreCall"},
{"CmdDrawMeshTasksIndirectEXT_PreCall"},
{"CmdDrawMeshTasksIndirectCountEXT_PreCall"}
};

typedef void (VKAPI_PTR *PFN_CreateInstance_PreCall)(encode::VulkanCaptureManager* manager, const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
typedef void (VKAPI_PTR *PFN_DestroyInstance_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_EnumeratePhysicalDevices_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFeatures_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFormatProperties_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceImageFormatProperties_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceProperties_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceQueueFamilyProperties_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceMemoryProperties_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties);
typedef void (VKAPI_PTR *PFN_CreateDevice_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice);
typedef void (VKAPI_PTR *PFN_DestroyDevice_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetDeviceQueue_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
typedef void (VKAPI_PTR *PFN_QueueSubmit_PreCall)(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
typedef void (VKAPI_PTR *PFN_QueueWaitIdle_PreCall)(encode::VulkanCaptureManager* manager, VkQueue queue);
typedef void (VKAPI_PTR *PFN_DeviceWaitIdle_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device);
typedef void (VKAPI_PTR *PFN_AllocateMemory_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);
typedef void (VKAPI_PTR *PFN_FreeMemory_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_MapMemory_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);
typedef void (VKAPI_PTR *PFN_UnmapMemory_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory);
typedef void (VKAPI_PTR *PFN_FlushMappedMemoryRanges_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
typedef void (VKAPI_PTR *PFN_InvalidateMappedMemoryRanges_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
typedef void (VKAPI_PTR *PFN_GetDeviceMemoryCommitment_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);
typedef void (VKAPI_PTR *PFN_BindBufferMemory_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
typedef void (VKAPI_PTR *PFN_BindImageMemory_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
typedef void (VKAPI_PTR *PFN_GetBufferMemoryRequirements_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetImageMemoryRequirements_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetImageSparseMemoryRequirements_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSparseImageFormatProperties_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties);
typedef void (VKAPI_PTR *PFN_QueueBindSparse_PreCall)(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);
typedef void (VKAPI_PTR *PFN_CreateFence_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
typedef void (VKAPI_PTR *PFN_DestroyFence_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_ResetFences_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t fenceCount, const VkFence* pFences);
typedef void (VKAPI_PTR *PFN_GetFenceStatus_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkFence fence);
typedef void (VKAPI_PTR *PFN_WaitForFences_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);
typedef void (VKAPI_PTR *PFN_CreateSemaphore_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
typedef void (VKAPI_PTR *PFN_DestroySemaphore_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateEvent_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent);
typedef void (VKAPI_PTR *PFN_DestroyEvent_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetEventStatus_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkEvent event);
typedef void (VKAPI_PTR *PFN_SetEvent_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkEvent event);
typedef void (VKAPI_PTR *PFN_ResetEvent_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkEvent event);
typedef void (VKAPI_PTR *PFN_CreateQueryPool_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);
typedef void (VKAPI_PTR *PFN_DestroyQueryPool_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetQueryPoolResults_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags);
typedef void (VKAPI_PTR *PFN_CreateBuffer_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
typedef void (VKAPI_PTR *PFN_DestroyBuffer_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateBufferView_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView);
typedef void (VKAPI_PTR *PFN_DestroyBufferView_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateImage_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage);
typedef void (VKAPI_PTR *PFN_DestroyImage_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetImageSubresourceLayout_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout);
typedef void (VKAPI_PTR *PFN_CreateImageView_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView);
typedef void (VKAPI_PTR *PFN_DestroyImageView_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateShaderModule_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule);
typedef void (VKAPI_PTR *PFN_DestroyShaderModule_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreatePipelineCache_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache);
typedef void (VKAPI_PTR *PFN_DestroyPipelineCache_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetPipelineCacheData_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);
typedef void (VKAPI_PTR *PFN_MergePipelineCaches_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches);
typedef void (VKAPI_PTR *PFN_CreateGraphicsPipelines_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
typedef void (VKAPI_PTR *PFN_CreateComputePipelines_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
typedef void (VKAPI_PTR *PFN_DestroyPipeline_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreatePipelineLayout_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout);
typedef void (VKAPI_PTR *PFN_DestroyPipelineLayout_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateSampler_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler);
typedef void (VKAPI_PTR *PFN_DestroySampler_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateDescriptorSetLayout_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout);
typedef void (VKAPI_PTR *PFN_DestroyDescriptorSetLayout_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateDescriptorPool_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);
typedef void (VKAPI_PTR *PFN_DestroyDescriptorPool_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_ResetDescriptorPool_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags);
typedef void (VKAPI_PTR *PFN_AllocateDescriptorSets_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets);
typedef void (VKAPI_PTR *PFN_FreeDescriptorSets_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);
typedef void (VKAPI_PTR *PFN_UpdateDescriptorSets_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies);
typedef void (VKAPI_PTR *PFN_CreateFramebuffer_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);
typedef void (VKAPI_PTR *PFN_DestroyFramebuffer_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateRenderPass_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
typedef void (VKAPI_PTR *PFN_DestroyRenderPass_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetRenderAreaGranularity_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity);
typedef void (VKAPI_PTR *PFN_CreateCommandPool_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
typedef void (VKAPI_PTR *PFN_DestroyCommandPool_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_ResetCommandPool_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags);
typedef void (VKAPI_PTR *PFN_AllocateCommandBuffers_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);
typedef void (VKAPI_PTR *PFN_FreeCommandBuffers_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
typedef void (VKAPI_PTR *PFN_BeginCommandBuffer_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);
typedef void (VKAPI_PTR *PFN_EndCommandBuffer_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_ResetCommandBuffer_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);
typedef void (VKAPI_PTR *PFN_CmdBindPipeline_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
typedef void (VKAPI_PTR *PFN_CmdSetViewport_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports);
typedef void (VKAPI_PTR *PFN_CmdSetScissor_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors);
typedef void (VKAPI_PTR *PFN_CmdSetLineWidth_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float lineWidth);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBias_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
typedef void (VKAPI_PTR *PFN_CmdSetBlendConstants_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const float blendConstants[4]);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBounds_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);
typedef void (VKAPI_PTR *PFN_CmdSetStencilCompareMask_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);
typedef void (VKAPI_PTR *PFN_CmdSetStencilWriteMask_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);
typedef void (VKAPI_PTR *PFN_CmdSetStencilReference_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);
typedef void (VKAPI_PTR *PFN_CmdBindDescriptorSets_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets);
typedef void (VKAPI_PTR *PFN_CmdBindIndexBuffer_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
typedef void (VKAPI_PTR *PFN_CmdBindVertexBuffers_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);
typedef void (VKAPI_PTR *PFN_CmdDraw_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexed_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirect_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexedIndirect_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDispatch_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_CmdDispatchIndirect_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
typedef void (VKAPI_PTR *PFN_CmdCopyBuffer_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions);
typedef void (VKAPI_PTR *PFN_CmdCopyImage_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions);
typedef void (VKAPI_PTR *PFN_CmdBlitImage_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter);
typedef void (VKAPI_PTR *PFN_CmdCopyBufferToImage_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);
typedef void (VKAPI_PTR *PFN_CmdCopyImageToBuffer_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);
typedef void (VKAPI_PTR *PFN_CmdUpdateBuffer_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData);
typedef void (VKAPI_PTR *PFN_CmdFillBuffer_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);
typedef void (VKAPI_PTR *PFN_CmdClearColorImage_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
typedef void (VKAPI_PTR *PFN_CmdClearDepthStencilImage_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
typedef void (VKAPI_PTR *PFN_CmdClearAttachments_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects);
typedef void (VKAPI_PTR *PFN_CmdResolveImage_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions);
typedef void (VKAPI_PTR *PFN_CmdSetEvent_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
typedef void (VKAPI_PTR *PFN_CmdResetEvent_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
typedef void (VKAPI_PTR *PFN_CmdWaitEvents_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
typedef void (VKAPI_PTR *PFN_CmdPipelineBarrier_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
typedef void (VKAPI_PTR *PFN_CmdBeginQuery_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);
typedef void (VKAPI_PTR *PFN_CmdEndQuery_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);
typedef void (VKAPI_PTR *PFN_CmdResetQueryPool_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_PTR *PFN_CmdWriteTimestamp_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query);
typedef void (VKAPI_PTR *PFN_CmdCopyQueryPoolResults_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);
typedef void (VKAPI_PTR *PFN_CmdPushConstants_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues);
typedef void (VKAPI_PTR *PFN_CmdBeginRenderPass_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents);
typedef void (VKAPI_PTR *PFN_CmdNextSubpass_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSubpassContents contents);
typedef void (VKAPI_PTR *PFN_CmdEndRenderPass_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdExecuteCommands_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
typedef void (VKAPI_PTR *PFN_BindBufferMemory2_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);
typedef void (VKAPI_PTR *PFN_BindImageMemory2_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);
typedef void (VKAPI_PTR *PFN_GetDeviceGroupPeerMemoryFeatures_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);
typedef void (VKAPI_PTR *PFN_CmdSetDeviceMask_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t deviceMask);
typedef void (VKAPI_PTR *PFN_CmdDispatchBase_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_EnumeratePhysicalDeviceGroups_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);
typedef void (VKAPI_PTR *PFN_GetImageMemoryRequirements2_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetBufferMemoryRequirements2_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetImageSparseMemoryRequirements2_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFeatures2_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceProperties2_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFormatProperties2_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceImageFormatProperties2_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceQueueFamilyProperties2_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceMemoryProperties2_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSparseImageFormatProperties2_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);
typedef void (VKAPI_PTR *PFN_TrimCommandPool_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
typedef void (VKAPI_PTR *PFN_GetDeviceQueue2_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue);
typedef void (VKAPI_PTR *PFN_CreateSamplerYcbcrConversion_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);
typedef void (VKAPI_PTR *PFN_DestroySamplerYcbcrConversion_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateDescriptorUpdateTemplate_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);
typedef void (VKAPI_PTR *PFN_DestroyDescriptorUpdateTemplate_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalBufferProperties_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalFenceProperties_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalSemaphoreProperties_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);
typedef void (VKAPI_PTR *PFN_GetDescriptorSetLayoutSupport_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirectCount_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexedIndirectCount_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CreateRenderPass2_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
typedef void (VKAPI_PTR *PFN_CmdBeginRenderPass2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo);
typedef void (VKAPI_PTR *PFN_CmdNextSubpass2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo);
typedef void (VKAPI_PTR *PFN_CmdEndRenderPass2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);
typedef void (VKAPI_PTR *PFN_ResetQueryPool_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_PTR *PFN_GetSemaphoreCounterValue_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSemaphore semaphore, uint64_t* pValue);
typedef void (VKAPI_PTR *PFN_WaitSemaphores_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);
typedef void (VKAPI_PTR *PFN_SignalSemaphore_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo);
typedef void (VKAPI_PTR *PFN_GetBufferDeviceAddress_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_GetBufferOpaqueCaptureAddress_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_GetDeviceMemoryOpaqueCaptureAddress_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceToolProperties_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties);
typedef void (VKAPI_PTR *PFN_CreatePrivateDataSlot_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot);
typedef void (VKAPI_PTR *PFN_DestroyPrivateDataSlot_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_SetPrivateData_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);
typedef void (VKAPI_PTR *PFN_GetPrivateData_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData);
typedef void (VKAPI_PTR *PFN_CmdSetEvent2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);
typedef void (VKAPI_PTR *PFN_CmdResetEvent2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);
typedef void (VKAPI_PTR *PFN_CmdWaitEvents2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);
typedef void (VKAPI_PTR *PFN_CmdPipelineBarrier2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
typedef void (VKAPI_PTR *PFN_CmdWriteTimestamp2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query);
typedef void (VKAPI_PTR *PFN_QueueSubmit2_PreCall)(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);
typedef void (VKAPI_PTR *PFN_CmdCopyBuffer2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyImage2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyBufferToImage2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyImageToBuffer2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
typedef void (VKAPI_PTR *PFN_CmdBlitImage2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
typedef void (VKAPI_PTR *PFN_CmdResolveImage2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
typedef void (VKAPI_PTR *PFN_CmdBeginRendering_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);
typedef void (VKAPI_PTR *PFN_CmdEndRendering_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdSetCullMode_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
typedef void (VKAPI_PTR *PFN_CmdSetFrontFace_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFrontFace frontFace);
typedef void (VKAPI_PTR *PFN_CmdSetPrimitiveTopology_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
typedef void (VKAPI_PTR *PFN_CmdSetViewportWithCount_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);
typedef void (VKAPI_PTR *PFN_CmdSetScissorWithCount_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);
typedef void (VKAPI_PTR *PFN_CmdBindVertexBuffers2_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);
typedef void (VKAPI_PTR *PFN_CmdSetDepthTestEnable_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthWriteEnable_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthCompareOp_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBoundsTestEnable_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetStencilTestEnable_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetStencilOp_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
typedef void (VKAPI_PTR *PFN_CmdSetRasterizerDiscardEnable_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBiasEnable_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);
typedef void (VKAPI_PTR *PFN_CmdSetPrimitiveRestartEnable_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);
typedef void (VKAPI_PTR *PFN_GetDeviceBufferMemoryRequirements_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetDeviceImageMemoryRequirements_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetDeviceImageSparseMemoryRequirements_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
typedef void (VKAPI_PTR *PFN_DestroySurfaceKHR_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceSupportKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceFormatsKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfacePresentModesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
typedef void (VKAPI_PTR *PFN_CreateSwapchainKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
typedef void (VKAPI_PTR *PFN_DestroySwapchainKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetSwapchainImagesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);
typedef void (VKAPI_PTR *PFN_AcquireNextImageKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);
typedef void (VKAPI_PTR *PFN_QueuePresentKHR_PreCall)(encode::VulkanCaptureManager* manager, VkQueue queue, const VkPresentInfoKHR* pPresentInfo);
typedef void (VKAPI_PTR *PFN_GetDeviceGroupPresentCapabilitiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities);
typedef void (VKAPI_PTR *PFN_GetDeviceGroupSurfacePresentModesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes);
typedef void (VKAPI_PTR *PFN_GetPhysicalDevicePresentRectanglesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects);
typedef void (VKAPI_PTR *PFN_AcquireNextImage2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceDisplayPropertiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties);
typedef void (VKAPI_PTR *PFN_GetDisplayPlaneSupportedDisplaysKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays);
typedef void (VKAPI_PTR *PFN_GetDisplayModePropertiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties);
typedef void (VKAPI_PTR *PFN_CreateDisplayModeKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode);
typedef void (VKAPI_PTR *PFN_GetDisplayPlaneCapabilitiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities);
typedef void (VKAPI_PTR *PFN_CreateDisplayPlaneSurfaceKHR_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CreateSharedSwapchainsKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains);
typedef void (VKAPI_PTR *PFN_CreateXlibSurfaceKHR_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceXlibPresentationSupportKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID);
typedef void (VKAPI_PTR *PFN_CreateXcbSurfaceKHR_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceXcbPresentationSupportKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id);
typedef void (VKAPI_PTR *PFN_CreateWaylandSurfaceKHR_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display);
typedef void (VKAPI_PTR *PFN_CreateAndroidSurfaceKHR_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CreateWin32SurfaceKHR_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceWin32PresentationSupportKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceVideoCapabilitiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties);
typedef void (VKAPI_PTR *PFN_CreateVideoSessionKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession);
typedef void (VKAPI_PTR *PFN_DestroyVideoSessionKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetVideoSessionMemoryRequirementsKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_BindVideoSessionMemoryKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos);
typedef void (VKAPI_PTR *PFN_CreateVideoSessionParametersKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters);
typedef void (VKAPI_PTR *PFN_UpdateVideoSessionParametersKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo);
typedef void (VKAPI_PTR *PFN_DestroyVideoSessionParametersKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CmdBeginVideoCodingKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo);
typedef void (VKAPI_PTR *PFN_CmdEndVideoCodingKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo);
typedef void (VKAPI_PTR *PFN_CmdControlVideoCodingKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo);
typedef void (VKAPI_PTR *PFN_CmdDecodeVideoKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo);
typedef void (VKAPI_PTR *PFN_CmdBeginRenderingKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);
typedef void (VKAPI_PTR *PFN_CmdEndRenderingKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFeatures2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceProperties2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFormatProperties2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceImageFormatProperties2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceMemoryProperties2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);
typedef void (VKAPI_PTR *PFN_GetDeviceGroupPeerMemoryFeaturesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);
typedef void (VKAPI_PTR *PFN_CmdSetDeviceMaskKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t deviceMask);
typedef void (VKAPI_PTR *PFN_CmdDispatchBaseKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_TrimCommandPoolKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
typedef void (VKAPI_PTR *PFN_EnumeratePhysicalDeviceGroupsKHR_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);
typedef void (VKAPI_PTR *PFN_GetMemoryWin32HandleKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);
typedef void (VKAPI_PTR *PFN_GetMemoryWin32HandlePropertiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties);
typedef void (VKAPI_PTR *PFN_GetMemoryFdKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd);
typedef void (VKAPI_PTR *PFN_GetMemoryFdPropertiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);
typedef void (VKAPI_PTR *PFN_ImportSemaphoreWin32HandleKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo);
typedef void (VKAPI_PTR *PFN_GetSemaphoreWin32HandleKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);
typedef void (VKAPI_PTR *PFN_ImportSemaphoreFdKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo);
typedef void (VKAPI_PTR *PFN_GetSemaphoreFdKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd);
typedef void (VKAPI_PTR *PFN_CmdPushDescriptorSetKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites);
typedef void (VKAPI_PTR *PFN_CreateDescriptorUpdateTemplateKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);
typedef void (VKAPI_PTR *PFN_DestroyDescriptorUpdateTemplateKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CreateRenderPass2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
typedef void (VKAPI_PTR *PFN_CmdBeginRenderPass2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo);
typedef void (VKAPI_PTR *PFN_CmdNextSubpass2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo);
typedef void (VKAPI_PTR *PFN_CmdEndRenderPass2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);
typedef void (VKAPI_PTR *PFN_GetSwapchainStatusKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalFencePropertiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);
typedef void (VKAPI_PTR *PFN_ImportFenceWin32HandleKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo);
typedef void (VKAPI_PTR *PFN_GetFenceWin32HandleKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);
typedef void (VKAPI_PTR *PFN_ImportFenceFdKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo);
typedef void (VKAPI_PTR *PFN_GetFenceFdKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd);
typedef void (VKAPI_PTR *PFN_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses);
typedef void (VKAPI_PTR *PFN_AcquireProfilingLockKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_ReleaseProfilingLockKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceFormats2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceDisplayProperties2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties);
typedef void (VKAPI_PTR *PFN_GetDisplayModeProperties2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties);
typedef void (VKAPI_PTR *PFN_GetDisplayPlaneCapabilities2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities);
typedef void (VKAPI_PTR *PFN_GetImageMemoryRequirements2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetBufferMemoryRequirements2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetImageSparseMemoryRequirements2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
typedef void (VKAPI_PTR *PFN_CreateSamplerYcbcrConversionKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);
typedef void (VKAPI_PTR *PFN_DestroySamplerYcbcrConversionKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_BindBufferMemory2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);
typedef void (VKAPI_PTR *PFN_BindImageMemory2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);
typedef void (VKAPI_PTR *PFN_GetDescriptorSetLayoutSupportKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirectCountKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexedIndirectCountKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_GetSemaphoreCounterValueKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSemaphore semaphore, uint64_t* pValue);
typedef void (VKAPI_PTR *PFN_WaitSemaphoresKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);
typedef void (VKAPI_PTR *PFN_SignalSemaphoreKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFragmentShadingRatesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates);
typedef void (VKAPI_PTR *PFN_CmdSetFragmentShadingRateKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);
typedef void (VKAPI_PTR *PFN_WaitForPresentKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout);
typedef void (VKAPI_PTR *PFN_GetBufferDeviceAddressKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_GetBufferOpaqueCaptureAddressKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_CreateDeferredOperationKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation);
typedef void (VKAPI_PTR *PFN_DestroyDeferredOperationKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetDeferredOperationMaxConcurrencyKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR operation);
typedef void (VKAPI_PTR *PFN_GetDeferredOperationResultKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR operation);
typedef void (VKAPI_PTR *PFN_DeferredOperationJoinKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR operation);
typedef void (VKAPI_PTR *PFN_GetPipelineExecutablePropertiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties);
typedef void (VKAPI_PTR *PFN_GetPipelineExecutableStatisticsKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics);
typedef void (VKAPI_PTR *PFN_GetPipelineExecutableInternalRepresentationsKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations);
typedef void (VKAPI_PTR *PFN_CmdEncodeVideoKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo);
typedef void (VKAPI_PTR *PFN_CmdSetEvent2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);
typedef void (VKAPI_PTR *PFN_CmdResetEvent2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);
typedef void (VKAPI_PTR *PFN_CmdWaitEvents2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);
typedef void (VKAPI_PTR *PFN_CmdPipelineBarrier2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
typedef void (VKAPI_PTR *PFN_CmdWriteTimestamp2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query);
typedef void (VKAPI_PTR *PFN_QueueSubmit2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);
typedef void (VKAPI_PTR *PFN_CmdWriteBufferMarker2AMD_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);
typedef void (VKAPI_PTR *PFN_GetQueueCheckpointData2NV_PreCall)(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData);
typedef void (VKAPI_PTR *PFN_CmdCopyBuffer2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyImage2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyBufferToImage2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyImageToBuffer2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
typedef void (VKAPI_PTR *PFN_CmdBlitImage2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
typedef void (VKAPI_PTR *PFN_CmdResolveImage2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
typedef void (VKAPI_PTR *PFN_CmdTraceRaysIndirect2KHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress);
typedef void (VKAPI_PTR *PFN_GetDeviceBufferMemoryRequirementsKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetDeviceImageMemoryRequirementsKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetDeviceImageSparseMemoryRequirementsKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
typedef void (VKAPI_PTR *PFN_CreateDebugReportCallbackEXT_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);
typedef void (VKAPI_PTR *PFN_DestroyDebugReportCallbackEXT_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_DebugReportMessageEXT_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage);
typedef void (VKAPI_PTR *PFN_DebugMarkerSetObjectTagEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo);
typedef void (VKAPI_PTR *PFN_DebugMarkerSetObjectNameEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo);
typedef void (VKAPI_PTR *PFN_CmdDebugMarkerBeginEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);
typedef void (VKAPI_PTR *PFN_CmdDebugMarkerEndEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdDebugMarkerInsertEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);
typedef void (VKAPI_PTR *PFN_CmdBindTransformFeedbackBuffersEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes);
typedef void (VKAPI_PTR *PFN_CmdBeginTransformFeedbackEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets);
typedef void (VKAPI_PTR *PFN_CmdEndTransformFeedbackEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets);
typedef void (VKAPI_PTR *PFN_CmdBeginQueryIndexedEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index);
typedef void (VKAPI_PTR *PFN_CmdEndQueryIndexedEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirectByteCountEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride);
typedef void (VKAPI_PTR *PFN_GetImageViewHandleNVX_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageViewHandleInfoNVX* pInfo);
typedef void (VKAPI_PTR *PFN_GetImageViewAddressNVX_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirectCountAMD_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexedIndirectCountAMD_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_GetShaderInfoAMD_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo);
typedef void (VKAPI_PTR *PFN_CreateStreamDescriptorSurfaceGGP_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties);
typedef void (VKAPI_PTR *PFN_GetMemoryWin32HandleNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle);
typedef void (VKAPI_PTR *PFN_CreateViSurfaceNN_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CmdBeginConditionalRenderingEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);
typedef void (VKAPI_PTR *PFN_CmdEndConditionalRenderingEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdSetViewportWScalingNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings);
typedef void (VKAPI_PTR *PFN_ReleaseDisplayEXT_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkDisplayKHR display);
typedef void (VKAPI_PTR *PFN_AcquireXlibDisplayEXT_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display);
typedef void (VKAPI_PTR *PFN_GetRandROutputDisplayEXT_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities);
typedef void (VKAPI_PTR *PFN_DisplayPowerControlEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo);
typedef void (VKAPI_PTR *PFN_RegisterDeviceEventEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
typedef void (VKAPI_PTR *PFN_RegisterDisplayEventEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
typedef void (VKAPI_PTR *PFN_GetSwapchainCounterEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue);
typedef void (VKAPI_PTR *PFN_GetRefreshCycleDurationGOOGLE_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties);
typedef void (VKAPI_PTR *PFN_GetPastPresentationTimingGOOGLE_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings);
typedef void (VKAPI_PTR *PFN_CmdSetDiscardRectangleEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles);
typedef void (VKAPI_PTR *PFN_CmdSetDiscardRectangleEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDiscardRectangleModeEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode);
typedef void (VKAPI_PTR *PFN_SetHdrMetadataEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata);
typedef void (VKAPI_PTR *PFN_CreateIOSSurfaceMVK_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CreateMacOSSurfaceMVK_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_SetDebugUtilsObjectNameEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo);
typedef void (VKAPI_PTR *PFN_SetDebugUtilsObjectTagEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo);
typedef void (VKAPI_PTR *PFN_QueueBeginDebugUtilsLabelEXT_PreCall)(encode::VulkanCaptureManager* manager, VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
typedef void (VKAPI_PTR *PFN_QueueEndDebugUtilsLabelEXT_PreCall)(encode::VulkanCaptureManager* manager, VkQueue queue);
typedef void (VKAPI_PTR *PFN_QueueInsertDebugUtilsLabelEXT_PreCall)(encode::VulkanCaptureManager* manager, VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
typedef void (VKAPI_PTR *PFN_CmdBeginDebugUtilsLabelEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
typedef void (VKAPI_PTR *PFN_CmdEndDebugUtilsLabelEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdInsertDebugUtilsLabelEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
typedef void (VKAPI_PTR *PFN_CreateDebugUtilsMessengerEXT_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger);
typedef void (VKAPI_PTR *PFN_DestroyDebugUtilsMessengerEXT_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_SubmitDebugUtilsMessageEXT_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData);
typedef void (VKAPI_PTR *PFN_GetAndroidHardwareBufferPropertiesANDROID_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties);
typedef void (VKAPI_PTR *PFN_GetMemoryAndroidHardwareBufferANDROID_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer);
typedef void (VKAPI_PTR *PFN_CmdSetSampleLocationsEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceMultisamplePropertiesEXT_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties);
typedef void (VKAPI_PTR *PFN_GetImageDrmFormatModifierPropertiesEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties);
typedef void (VKAPI_PTR *PFN_CreateValidationCacheEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache);
typedef void (VKAPI_PTR *PFN_DestroyValidationCacheEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_MergeValidationCachesEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches);
typedef void (VKAPI_PTR *PFN_GetValidationCacheDataEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData);
typedef void (VKAPI_PTR *PFN_CmdBindShadingRateImageNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);
typedef void (VKAPI_PTR *PFN_CmdSetViewportShadingRatePaletteNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes);
typedef void (VKAPI_PTR *PFN_CmdSetCoarseSampleOrderNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders);
typedef void (VKAPI_PTR *PFN_CreateAccelerationStructureNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure);
typedef void (VKAPI_PTR *PFN_DestroyAccelerationStructureNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetAccelerationStructureMemoryRequirementsNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_BindAccelerationStructureMemoryNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos);
typedef void (VKAPI_PTR *PFN_CmdBuildAccelerationStructureNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset);
typedef void (VKAPI_PTR *PFN_CmdCopyAccelerationStructureNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode);
typedef void (VKAPI_PTR *PFN_CmdTraceRaysNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth);
typedef void (VKAPI_PTR *PFN_CreateRayTracingPipelinesNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
typedef void (VKAPI_PTR *PFN_GetRayTracingShaderGroupHandlesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);
typedef void (VKAPI_PTR *PFN_GetRayTracingShaderGroupHandlesNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);
typedef void (VKAPI_PTR *PFN_GetAccelerationStructureHandleNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData);
typedef void (VKAPI_PTR *PFN_CmdWriteAccelerationStructuresPropertiesNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);
typedef void (VKAPI_PTR *PFN_CompileDeferredNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, uint32_t shader);
typedef void (VKAPI_PTR *PFN_GetMemoryHostPointerPropertiesEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties);
typedef void (VKAPI_PTR *PFN_CmdWriteBufferMarkerAMD_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainEXT* pTimeDomains);
typedef void (VKAPI_PTR *PFN_GetCalibratedTimestampsEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksIndirectNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksIndirectCountNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdSetExclusiveScissorEnableNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables);
typedef void (VKAPI_PTR *PFN_CmdSetExclusiveScissorNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors);
typedef void (VKAPI_PTR *PFN_CmdSetCheckpointNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const void* pCheckpointMarker);
typedef void (VKAPI_PTR *PFN_GetQueueCheckpointDataNV_PreCall)(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData);
typedef void (VKAPI_PTR *PFN_InitializePerformanceApiINTEL_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo);
typedef void (VKAPI_PTR *PFN_UninitializePerformanceApiINTEL_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device);
typedef void (VKAPI_PTR *PFN_CmdSetPerformanceMarkerINTEL_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo);
typedef void (VKAPI_PTR *PFN_CmdSetPerformanceStreamMarkerINTEL_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo);
typedef void (VKAPI_PTR *PFN_CmdSetPerformanceOverrideINTEL_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo);
typedef void (VKAPI_PTR *PFN_AcquirePerformanceConfigurationINTEL_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration);
typedef void (VKAPI_PTR *PFN_ReleasePerformanceConfigurationINTEL_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPerformanceConfigurationINTEL configuration);
typedef void (VKAPI_PTR *PFN_QueueSetPerformanceConfigurationINTEL_PreCall)(encode::VulkanCaptureManager* manager, VkQueue queue, VkPerformanceConfigurationINTEL configuration);
typedef void (VKAPI_PTR *PFN_GetPerformanceParameterINTEL_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue);
typedef void (VKAPI_PTR *PFN_SetLocalDimmingAMD_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable);
typedef void (VKAPI_PTR *PFN_CreateImagePipeSurfaceFUCHSIA_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CreateMetalSurfaceEXT_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetBufferDeviceAddressEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceToolPropertiesEXT_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSurfacePresentModes2EXT_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
typedef void (VKAPI_PTR *PFN_AcquireFullScreenExclusiveModeEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain);
typedef void (VKAPI_PTR *PFN_ReleaseFullScreenExclusiveModeEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain);
typedef void (VKAPI_PTR *PFN_GetDeviceGroupSurfacePresentModes2EXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes);
typedef void (VKAPI_PTR *PFN_CreateHeadlessSurfaceEXT_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CmdSetLineStippleEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);
typedef void (VKAPI_PTR *PFN_ResetQueryPoolEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_PTR *PFN_CmdSetCullModeEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
typedef void (VKAPI_PTR *PFN_CmdSetFrontFaceEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFrontFace frontFace);
typedef void (VKAPI_PTR *PFN_CmdSetPrimitiveTopologyEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
typedef void (VKAPI_PTR *PFN_CmdSetViewportWithCountEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);
typedef void (VKAPI_PTR *PFN_CmdSetScissorWithCountEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);
typedef void (VKAPI_PTR *PFN_CmdBindVertexBuffers2EXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);
typedef void (VKAPI_PTR *PFN_CmdSetDepthTestEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthWriteEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthCompareOpEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBoundsTestEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetStencilTestEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetStencilOpEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
typedef void (VKAPI_PTR *PFN_ReleaseSwapchainImagesEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkReleaseSwapchainImagesInfoEXT* pReleaseInfo);
typedef void (VKAPI_PTR *PFN_GetGeneratedCommandsMemoryRequirementsNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_CmdPreprocessGeneratedCommandsNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);
typedef void (VKAPI_PTR *PFN_CmdExecuteGeneratedCommandsNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);
typedef void (VKAPI_PTR *PFN_CmdBindPipelineShaderGroupNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex);
typedef void (VKAPI_PTR *PFN_CreateIndirectCommandsLayoutNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout);
typedef void (VKAPI_PTR *PFN_DestroyIndirectCommandsLayoutNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_AcquireDrmDisplayEXT_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display);
typedef void (VKAPI_PTR *PFN_GetDrmDisplayEXT_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display);
typedef void (VKAPI_PTR *PFN_CreatePrivateDataSlotEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot);
typedef void (VKAPI_PTR *PFN_DestroyPrivateDataSlotEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_SetPrivateDataEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);
typedef void (VKAPI_PTR *PFN_GetPrivateDataEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData);
typedef void (VKAPI_PTR *PFN_CmdSetFragmentShadingRateEnumNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);
typedef void (VKAPI_PTR *PFN_GetImageSubresourceLayout2EXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkImageSubresource2EXT* pSubresource, VkSubresourceLayout2EXT* pLayout);
typedef void (VKAPI_PTR *PFN_GetDeviceFaultInfoEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo);
typedef void (VKAPI_PTR *PFN_AcquireWinrtDisplayNV_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkDisplayKHR display);
typedef void (VKAPI_PTR *PFN_GetWinrtDisplayNV_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay);
typedef void (VKAPI_PTR *PFN_CreateDirectFBSurfaceEXT_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb);
typedef void (VKAPI_PTR *PFN_CmdSetVertexInputEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);
typedef void (VKAPI_PTR *PFN_GetMemoryZirconHandleFUCHSIA_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);
typedef void (VKAPI_PTR *PFN_GetMemoryZirconHandlePropertiesFUCHSIA_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties);
typedef void (VKAPI_PTR *PFN_ImportSemaphoreZirconHandleFUCHSIA_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo);
typedef void (VKAPI_PTR *PFN_GetSemaphoreZirconHandleFUCHSIA_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);
typedef void (VKAPI_PTR *PFN_CmdBindInvocationMaskHUAWEI_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);
typedef void (VKAPI_PTR *PFN_GetMemoryRemoteAddressNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress);
typedef void (VKAPI_PTR *PFN_CmdSetPatchControlPointsEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t patchControlPoints);
typedef void (VKAPI_PTR *PFN_CmdSetRasterizerDiscardEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBiasEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);
typedef void (VKAPI_PTR *PFN_CmdSetLogicOpEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkLogicOp logicOp);
typedef void (VKAPI_PTR *PFN_CmdSetPrimitiveRestartEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);
typedef void (VKAPI_PTR *PFN_CreateScreenSurfaceQNX_PreCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceScreenPresentationSupportQNX_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window);
typedef void (VKAPI_PTR *PFN_CmdSetColorWriteEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables);
typedef void (VKAPI_PTR *PFN_CmdDrawMultiEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawMultiIndexedEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset);
typedef void (VKAPI_PTR *PFN_CreateMicromapEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap);
typedef void (VKAPI_PTR *PFN_DestroyMicromapEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CmdBuildMicromapsEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);
typedef void (VKAPI_PTR *PFN_BuildMicromapsEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);
typedef void (VKAPI_PTR *PFN_CopyMicromapEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_CopyMicromapToMemoryEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_CopyMemoryToMicromapEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_WriteMicromapsPropertiesEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, size_t dataSize, void* pData, size_t stride);
typedef void (VKAPI_PTR *PFN_CmdCopyMicromapEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyMicromapToMemoryEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyMemoryToMicromapEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_CmdWriteMicromapsPropertiesEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);
typedef void (VKAPI_PTR *PFN_GetDeviceMicromapCompatibilityEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility);
typedef void (VKAPI_PTR *PFN_GetMicromapBuildSizesEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT* pBuildInfo, VkMicromapBuildSizesInfoEXT* pSizeInfo);
typedef void (VKAPI_PTR *PFN_CmdDrawClusterHUAWEI_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_CmdDrawClusterIndirectHUAWEI_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
typedef void (VKAPI_PTR *PFN_SetDeviceMemoryPriorityEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, float priority);
typedef void (VKAPI_PTR *PFN_GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping);
typedef void (VKAPI_PTR *PFN_GetDescriptorSetHostMappingVALVE_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorSet descriptorSet, void** ppData);
typedef void (VKAPI_PTR *PFN_CmdSetTessellationDomainOriginEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin);
typedef void (VKAPI_PTR *PFN_CmdSetDepthClampEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthClampEnable);
typedef void (VKAPI_PTR *PFN_CmdSetPolygonModeEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPolygonMode polygonMode);
typedef void (VKAPI_PTR *PFN_CmdSetRasterizationSamplesEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples);
typedef void (VKAPI_PTR *PFN_CmdSetSampleMaskEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples, const VkSampleMask* pSampleMask);
typedef void (VKAPI_PTR *PFN_CmdSetAlphaToCoverageEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable);
typedef void (VKAPI_PTR *PFN_CmdSetAlphaToOneEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable);
typedef void (VKAPI_PTR *PFN_CmdSetLogicOpEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 logicOpEnable);
typedef void (VKAPI_PTR *PFN_CmdSetColorBlendEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables);
typedef void (VKAPI_PTR *PFN_CmdSetColorBlendEquationEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations);
typedef void (VKAPI_PTR *PFN_CmdSetColorWriteMaskEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks);
typedef void (VKAPI_PTR *PFN_CmdSetRasterizationStreamEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t rasterizationStream);
typedef void (VKAPI_PTR *PFN_CmdSetConservativeRasterizationModeEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode);
typedef void (VKAPI_PTR *PFN_CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize);
typedef void (VKAPI_PTR *PFN_CmdSetDepthClipEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthClipEnable);
typedef void (VKAPI_PTR *PFN_CmdSetSampleLocationsEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable);
typedef void (VKAPI_PTR *PFN_CmdSetColorBlendAdvancedEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced);
typedef void (VKAPI_PTR *PFN_CmdSetProvokingVertexModeEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode);
typedef void (VKAPI_PTR *PFN_CmdSetLineRasterizationModeEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode);
typedef void (VKAPI_PTR *PFN_CmdSetLineStippleEnableEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthClipNegativeOneToOneEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne);
typedef void (VKAPI_PTR *PFN_CmdSetViewportWScalingEnableNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable);
typedef void (VKAPI_PTR *PFN_CmdSetViewportSwizzleNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageToColorEnableNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageToColorLocationNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageModulationModeNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageModulationTableEnableNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageModulationTableNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable);
typedef void (VKAPI_PTR *PFN_CmdSetShadingRateImageEnableNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable);
typedef void (VKAPI_PTR *PFN_CmdSetRepresentativeFragmentTestEnableNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageReductionModeNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode);
typedef void (VKAPI_PTR *PFN_GetShaderModuleIdentifierEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier);
typedef void (VKAPI_PTR *PFN_GetShaderModuleCreateInfoIdentifierEXT_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties);
typedef void (VKAPI_PTR *PFN_CreateOpticalFlowSessionNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession);
typedef void (VKAPI_PTR *PFN_DestroyOpticalFlowSessionNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_BindOpticalFlowSessionImageNV_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout);
typedef void (VKAPI_PTR *PFN_CmdOpticalFlowExecuteNV_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo);
typedef void (VKAPI_PTR *PFN_GetFramebufferTilePropertiesQCOM_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties);
typedef void (VKAPI_PTR *PFN_GetDynamicRenderingTilePropertiesQCOM_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties);
typedef void (VKAPI_PTR *PFN_CreateAccelerationStructureKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure);
typedef void (VKAPI_PTR *PFN_DestroyAccelerationStructureKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CmdBuildAccelerationStructuresKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);
typedef void (VKAPI_PTR *PFN_CmdBuildAccelerationStructuresIndirectKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts);
typedef void (VKAPI_PTR *PFN_CopyAccelerationStructureToMemoryKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_CopyMemoryToAccelerationStructureKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_WriteAccelerationStructuresPropertiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride);
typedef void (VKAPI_PTR *PFN_CmdCopyAccelerationStructureKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyAccelerationStructureToMemoryKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyMemoryToAccelerationStructureKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_GetAccelerationStructureDeviceAddressKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_CmdWriteAccelerationStructuresPropertiesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);
typedef void (VKAPI_PTR *PFN_GetDeviceAccelerationStructureCompatibilityKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility);
typedef void (VKAPI_PTR *PFN_GetAccelerationStructureBuildSizesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo);
typedef void (VKAPI_PTR *PFN_CmdTraceRaysKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth);
typedef void (VKAPI_PTR *PFN_CreateRayTracingPipelinesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
typedef void (VKAPI_PTR *PFN_GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);
typedef void (VKAPI_PTR *PFN_CmdTraceRaysIndirectKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress);
typedef void (VKAPI_PTR *PFN_GetRayTracingShaderGroupStackSizeKHR_PreCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader);
typedef void (VKAPI_PTR *PFN_CmdSetRayTracingPipelineStackSizeKHR_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t pipelineStackSize);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksIndirectEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksIndirectCountEXT_PreCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

static const char * func_table_post[] =
{
{"CreateInstance_ PostCall"},
{"DestroyInstance_ PostCall"},
{"EnumeratePhysicalDevices_ PostCall"},
{"GetPhysicalDeviceFeatures_ PostCall"},
{"GetPhysicalDeviceFormatProperties_ PostCall"},
{"GetPhysicalDeviceImageFormatProperties_ PostCall"},
{"GetPhysicalDeviceProperties_ PostCall"},
{"GetPhysicalDeviceQueueFamilyProperties_ PostCall"},
{"GetPhysicalDeviceMemoryProperties_ PostCall"},
{"CreateDevice_ PostCall"},
{"DestroyDevice_ PostCall"},
{"GetDeviceQueue_ PostCall"},
{"QueueSubmit_ PostCall"},
{"QueueWaitIdle_ PostCall"},
{"DeviceWaitIdle_ PostCall"},
{"AllocateMemory_ PostCall"},
{"FreeMemory_ PostCall"},
{"MapMemory_ PostCall"},
{"UnmapMemory_ PostCall"},
{"FlushMappedMemoryRanges_ PostCall"},
{"InvalidateMappedMemoryRanges_ PostCall"},
{"GetDeviceMemoryCommitment_ PostCall"},
{"BindBufferMemory_ PostCall"},
{"BindImageMemory_ PostCall"},
{"GetBufferMemoryRequirements_ PostCall"},
{"GetImageMemoryRequirements_ PostCall"},
{"GetImageSparseMemoryRequirements_ PostCall"},
{"GetPhysicalDeviceSparseImageFormatProperties_ PostCall"},
{"QueueBindSparse_ PostCall"},
{"CreateFence_ PostCall"},
{"DestroyFence_ PostCall"},
{"ResetFences_ PostCall"},
{"GetFenceStatus_ PostCall"},
{"WaitForFences_ PostCall"},
{"CreateSemaphore_ PostCall"},
{"DestroySemaphore_ PostCall"},
{"CreateEvent_ PostCall"},
{"DestroyEvent_ PostCall"},
{"GetEventStatus_ PostCall"},
{"SetEvent_ PostCall"},
{"ResetEvent_ PostCall"},
{"CreateQueryPool_ PostCall"},
{"DestroyQueryPool_ PostCall"},
{"GetQueryPoolResults_ PostCall"},
{"CreateBuffer_ PostCall"},
{"DestroyBuffer_ PostCall"},
{"CreateBufferView_ PostCall"},
{"DestroyBufferView_ PostCall"},
{"CreateImage_ PostCall"},
{"DestroyImage_ PostCall"},
{"GetImageSubresourceLayout_ PostCall"},
{"CreateImageView_ PostCall"},
{"DestroyImageView_ PostCall"},
{"CreateShaderModule_ PostCall"},
{"DestroyShaderModule_ PostCall"},
{"CreatePipelineCache_ PostCall"},
{"DestroyPipelineCache_ PostCall"},
{"GetPipelineCacheData_ PostCall"},
{"MergePipelineCaches_ PostCall"},
{"CreateGraphicsPipelines_ PostCall"},
{"CreateComputePipelines_ PostCall"},
{"DestroyPipeline_ PostCall"},
{"CreatePipelineLayout_ PostCall"},
{"DestroyPipelineLayout_ PostCall"},
{"CreateSampler_ PostCall"},
{"DestroySampler_ PostCall"},
{"CreateDescriptorSetLayout_ PostCall"},
{"DestroyDescriptorSetLayout_ PostCall"},
{"CreateDescriptorPool_ PostCall"},
{"DestroyDescriptorPool_ PostCall"},
{"ResetDescriptorPool_ PostCall"},
{"AllocateDescriptorSets_ PostCall"},
{"FreeDescriptorSets_ PostCall"},
{"UpdateDescriptorSets_ PostCall"},
{"CreateFramebuffer_ PostCall"},
{"DestroyFramebuffer_ PostCall"},
{"CreateRenderPass_ PostCall"},
{"DestroyRenderPass_ PostCall"},
{"GetRenderAreaGranularity_ PostCall"},
{"CreateCommandPool_ PostCall"},
{"DestroyCommandPool_ PostCall"},
{"ResetCommandPool_ PostCall"},
{"AllocateCommandBuffers_ PostCall"},
{"FreeCommandBuffers_ PostCall"},
{"BeginCommandBuffer_ PostCall"},
{"EndCommandBuffer_ PostCall"},
{"ResetCommandBuffer_ PostCall"},
{"CmdBindPipeline_ PostCall"},
{"CmdSetViewport_ PostCall"},
{"CmdSetScissor_ PostCall"},
{"CmdSetLineWidth_ PostCall"},
{"CmdSetDepthBias_ PostCall"},
{"CmdSetBlendConstants_ PostCall"},
{"CmdSetDepthBounds_ PostCall"},
{"CmdSetStencilCompareMask_ PostCall"},
{"CmdSetStencilWriteMask_ PostCall"},
{"CmdSetStencilReference_ PostCall"},
{"CmdBindDescriptorSets_ PostCall"},
{"CmdBindIndexBuffer_ PostCall"},
{"CmdBindVertexBuffers_ PostCall"},
{"CmdDraw_ PostCall"},
{"CmdDrawIndexed_ PostCall"},
{"CmdDrawIndirect_ PostCall"},
{"CmdDrawIndexedIndirect_ PostCall"},
{"CmdDispatch_ PostCall"},
{"CmdDispatchIndirect_ PostCall"},
{"CmdCopyBuffer_ PostCall"},
{"CmdCopyImage_ PostCall"},
{"CmdBlitImage_ PostCall"},
{"CmdCopyBufferToImage_ PostCall"},
{"CmdCopyImageToBuffer_ PostCall"},
{"CmdUpdateBuffer_ PostCall"},
{"CmdFillBuffer_ PostCall"},
{"CmdClearColorImage_ PostCall"},
{"CmdClearDepthStencilImage_ PostCall"},
{"CmdClearAttachments_ PostCall"},
{"CmdResolveImage_ PostCall"},
{"CmdSetEvent_ PostCall"},
{"CmdResetEvent_ PostCall"},
{"CmdWaitEvents_ PostCall"},
{"CmdPipelineBarrier_ PostCall"},
{"CmdBeginQuery_ PostCall"},
{"CmdEndQuery_ PostCall"},
{"CmdResetQueryPool_ PostCall"},
{"CmdWriteTimestamp_ PostCall"},
{"CmdCopyQueryPoolResults_ PostCall"},
{"CmdPushConstants_ PostCall"},
{"CmdBeginRenderPass_ PostCall"},
{"CmdNextSubpass_ PostCall"},
{"CmdEndRenderPass_ PostCall"},
{"CmdExecuteCommands_ PostCall"},
{"BindBufferMemory2_ PostCall"},
{"BindImageMemory2_ PostCall"},
{"GetDeviceGroupPeerMemoryFeatures_ PostCall"},
{"CmdSetDeviceMask_ PostCall"},
{"CmdDispatchBase_ PostCall"},
{"EnumeratePhysicalDeviceGroups_ PostCall"},
{"GetImageMemoryRequirements2_ PostCall"},
{"GetBufferMemoryRequirements2_ PostCall"},
{"GetImageSparseMemoryRequirements2_ PostCall"},
{"GetPhysicalDeviceFeatures2_ PostCall"},
{"GetPhysicalDeviceProperties2_ PostCall"},
{"GetPhysicalDeviceFormatProperties2_ PostCall"},
{"GetPhysicalDeviceImageFormatProperties2_ PostCall"},
{"GetPhysicalDeviceQueueFamilyProperties2_ PostCall"},
{"GetPhysicalDeviceMemoryProperties2_ PostCall"},
{"GetPhysicalDeviceSparseImageFormatProperties2_ PostCall"},
{"TrimCommandPool_ PostCall"},
{"GetDeviceQueue2_ PostCall"},
{"CreateSamplerYcbcrConversion_ PostCall"},
{"DestroySamplerYcbcrConversion_ PostCall"},
{"CreateDescriptorUpdateTemplate_ PostCall"},
{"DestroyDescriptorUpdateTemplate_ PostCall"},
{"GetPhysicalDeviceExternalBufferProperties_ PostCall"},
{"GetPhysicalDeviceExternalFenceProperties_ PostCall"},
{"GetPhysicalDeviceExternalSemaphoreProperties_ PostCall"},
{"GetDescriptorSetLayoutSupport_ PostCall"},
{"CmdDrawIndirectCount_ PostCall"},
{"CmdDrawIndexedIndirectCount_ PostCall"},
{"CreateRenderPass2_ PostCall"},
{"CmdBeginRenderPass2_ PostCall"},
{"CmdNextSubpass2_ PostCall"},
{"CmdEndRenderPass2_ PostCall"},
{"ResetQueryPool_ PostCall"},
{"GetSemaphoreCounterValue_ PostCall"},
{"WaitSemaphores_ PostCall"},
{"SignalSemaphore_ PostCall"},
{"GetBufferDeviceAddress_ PostCall"},
{"GetBufferOpaqueCaptureAddress_ PostCall"},
{"GetDeviceMemoryOpaqueCaptureAddress_ PostCall"},
{"GetPhysicalDeviceToolProperties_ PostCall"},
{"CreatePrivateDataSlot_ PostCall"},
{"DestroyPrivateDataSlot_ PostCall"},
{"SetPrivateData_ PostCall"},
{"GetPrivateData_ PostCall"},
{"CmdSetEvent2_ PostCall"},
{"CmdResetEvent2_ PostCall"},
{"CmdWaitEvents2_ PostCall"},
{"CmdPipelineBarrier2_ PostCall"},
{"CmdWriteTimestamp2_ PostCall"},
{"QueueSubmit2_ PostCall"},
{"CmdCopyBuffer2_ PostCall"},
{"CmdCopyImage2_ PostCall"},
{"CmdCopyBufferToImage2_ PostCall"},
{"CmdCopyImageToBuffer2_ PostCall"},
{"CmdBlitImage2_ PostCall"},
{"CmdResolveImage2_ PostCall"},
{"CmdBeginRendering_ PostCall"},
{"CmdEndRendering_ PostCall"},
{"CmdSetCullMode_ PostCall"},
{"CmdSetFrontFace_ PostCall"},
{"CmdSetPrimitiveTopology_ PostCall"},
{"CmdSetViewportWithCount_ PostCall"},
{"CmdSetScissorWithCount_ PostCall"},
{"CmdBindVertexBuffers2_ PostCall"},
{"CmdSetDepthTestEnable_ PostCall"},
{"CmdSetDepthWriteEnable_ PostCall"},
{"CmdSetDepthCompareOp_ PostCall"},
{"CmdSetDepthBoundsTestEnable_ PostCall"},
{"CmdSetStencilTestEnable_ PostCall"},
{"CmdSetStencilOp_ PostCall"},
{"CmdSetRasterizerDiscardEnable_ PostCall"},
{"CmdSetDepthBiasEnable_ PostCall"},
{"CmdSetPrimitiveRestartEnable_ PostCall"},
{"GetDeviceBufferMemoryRequirements_ PostCall"},
{"GetDeviceImageMemoryRequirements_ PostCall"},
{"GetDeviceImageSparseMemoryRequirements_ PostCall"},
{"DestroySurfaceKHR_ PostCall"},
{"GetPhysicalDeviceSurfaceSupportKHR_ PostCall"},
{"GetPhysicalDeviceSurfaceCapabilitiesKHR_ PostCall"},
{"GetPhysicalDeviceSurfaceFormatsKHR_ PostCall"},
{"GetPhysicalDeviceSurfacePresentModesKHR_ PostCall"},
{"CreateSwapchainKHR_ PostCall"},
{"DestroySwapchainKHR_ PostCall"},
{"GetSwapchainImagesKHR_ PostCall"},
{"AcquireNextImageKHR_ PostCall"},
{"QueuePresentKHR_ PostCall"},
{"GetDeviceGroupPresentCapabilitiesKHR_ PostCall"},
{"GetDeviceGroupSurfacePresentModesKHR_ PostCall"},
{"GetPhysicalDevicePresentRectanglesKHR_ PostCall"},
{"AcquireNextImage2KHR_ PostCall"},
{"GetPhysicalDeviceDisplayPropertiesKHR_ PostCall"},
{"GetPhysicalDeviceDisplayPlanePropertiesKHR_ PostCall"},
{"GetDisplayPlaneSupportedDisplaysKHR_ PostCall"},
{"GetDisplayModePropertiesKHR_ PostCall"},
{"CreateDisplayModeKHR_ PostCall"},
{"GetDisplayPlaneCapabilitiesKHR_ PostCall"},
{"CreateDisplayPlaneSurfaceKHR_ PostCall"},
{"CreateSharedSwapchainsKHR_ PostCall"},
{"CreateXlibSurfaceKHR_ PostCall"},
{"GetPhysicalDeviceXlibPresentationSupportKHR_ PostCall"},
{"CreateXcbSurfaceKHR_ PostCall"},
{"GetPhysicalDeviceXcbPresentationSupportKHR_ PostCall"},
{"CreateWaylandSurfaceKHR_ PostCall"},
{"GetPhysicalDeviceWaylandPresentationSupportKHR_ PostCall"},
{"CreateAndroidSurfaceKHR_ PostCall"},
{"CreateWin32SurfaceKHR_ PostCall"},
{"GetPhysicalDeviceWin32PresentationSupportKHR_ PostCall"},
{"GetPhysicalDeviceVideoCapabilitiesKHR_ PostCall"},
{"GetPhysicalDeviceVideoFormatPropertiesKHR_ PostCall"},
{"CreateVideoSessionKHR_ PostCall"},
{"DestroyVideoSessionKHR_ PostCall"},
{"GetVideoSessionMemoryRequirementsKHR_ PostCall"},
{"BindVideoSessionMemoryKHR_ PostCall"},
{"CreateVideoSessionParametersKHR_ PostCall"},
{"UpdateVideoSessionParametersKHR_ PostCall"},
{"DestroyVideoSessionParametersKHR_ PostCall"},
{"CmdBeginVideoCodingKHR_ PostCall"},
{"CmdEndVideoCodingKHR_ PostCall"},
{"CmdControlVideoCodingKHR_ PostCall"},
{"CmdDecodeVideoKHR_ PostCall"},
{"CmdBeginRenderingKHR_ PostCall"},
{"CmdEndRenderingKHR_ PostCall"},
{"GetPhysicalDeviceFeatures2KHR_ PostCall"},
{"GetPhysicalDeviceProperties2KHR_ PostCall"},
{"GetPhysicalDeviceFormatProperties2KHR_ PostCall"},
{"GetPhysicalDeviceImageFormatProperties2KHR_ PostCall"},
{"GetPhysicalDeviceQueueFamilyProperties2KHR_ PostCall"},
{"GetPhysicalDeviceMemoryProperties2KHR_ PostCall"},
{"GetPhysicalDeviceSparseImageFormatProperties2KHR_ PostCall"},
{"GetDeviceGroupPeerMemoryFeaturesKHR_ PostCall"},
{"CmdSetDeviceMaskKHR_ PostCall"},
{"CmdDispatchBaseKHR_ PostCall"},
{"TrimCommandPoolKHR_ PostCall"},
{"EnumeratePhysicalDeviceGroupsKHR_ PostCall"},
{"GetPhysicalDeviceExternalBufferPropertiesKHR_ PostCall"},
{"GetMemoryWin32HandleKHR_ PostCall"},
{"GetMemoryWin32HandlePropertiesKHR_ PostCall"},
{"GetMemoryFdKHR_ PostCall"},
{"GetMemoryFdPropertiesKHR_ PostCall"},
{"GetPhysicalDeviceExternalSemaphorePropertiesKHR_ PostCall"},
{"ImportSemaphoreWin32HandleKHR_ PostCall"},
{"GetSemaphoreWin32HandleKHR_ PostCall"},
{"ImportSemaphoreFdKHR_ PostCall"},
{"GetSemaphoreFdKHR_ PostCall"},
{"CmdPushDescriptorSetKHR_ PostCall"},
{"CreateDescriptorUpdateTemplateKHR_ PostCall"},
{"DestroyDescriptorUpdateTemplateKHR_ PostCall"},
{"CreateRenderPass2KHR_ PostCall"},
{"CmdBeginRenderPass2KHR_ PostCall"},
{"CmdNextSubpass2KHR_ PostCall"},
{"CmdEndRenderPass2KHR_ PostCall"},
{"GetSwapchainStatusKHR_ PostCall"},
{"GetPhysicalDeviceExternalFencePropertiesKHR_ PostCall"},
{"ImportFenceWin32HandleKHR_ PostCall"},
{"GetFenceWin32HandleKHR_ PostCall"},
{"ImportFenceFdKHR_ PostCall"},
{"GetFenceFdKHR_ PostCall"},
{"EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_ PostCall"},
{"GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_ PostCall"},
{"AcquireProfilingLockKHR_ PostCall"},
{"ReleaseProfilingLockKHR_ PostCall"},
{"GetPhysicalDeviceSurfaceCapabilities2KHR_ PostCall"},
{"GetPhysicalDeviceSurfaceFormats2KHR_ PostCall"},
{"GetPhysicalDeviceDisplayProperties2KHR_ PostCall"},
{"GetPhysicalDeviceDisplayPlaneProperties2KHR_ PostCall"},
{"GetDisplayModeProperties2KHR_ PostCall"},
{"GetDisplayPlaneCapabilities2KHR_ PostCall"},
{"GetImageMemoryRequirements2KHR_ PostCall"},
{"GetBufferMemoryRequirements2KHR_ PostCall"},
{"GetImageSparseMemoryRequirements2KHR_ PostCall"},
{"CreateSamplerYcbcrConversionKHR_ PostCall"},
{"DestroySamplerYcbcrConversionKHR_ PostCall"},
{"BindBufferMemory2KHR_ PostCall"},
{"BindImageMemory2KHR_ PostCall"},
{"GetDescriptorSetLayoutSupportKHR_ PostCall"},
{"CmdDrawIndirectCountKHR_ PostCall"},
{"CmdDrawIndexedIndirectCountKHR_ PostCall"},
{"GetSemaphoreCounterValueKHR_ PostCall"},
{"WaitSemaphoresKHR_ PostCall"},
{"SignalSemaphoreKHR_ PostCall"},
{"GetPhysicalDeviceFragmentShadingRatesKHR_ PostCall"},
{"CmdSetFragmentShadingRateKHR_ PostCall"},
{"WaitForPresentKHR_ PostCall"},
{"GetBufferDeviceAddressKHR_ PostCall"},
{"GetBufferOpaqueCaptureAddressKHR_ PostCall"},
{"GetDeviceMemoryOpaqueCaptureAddressKHR_ PostCall"},
{"CreateDeferredOperationKHR_ PostCall"},
{"DestroyDeferredOperationKHR_ PostCall"},
{"GetDeferredOperationMaxConcurrencyKHR_ PostCall"},
{"GetDeferredOperationResultKHR_ PostCall"},
{"DeferredOperationJoinKHR_ PostCall"},
{"GetPipelineExecutablePropertiesKHR_ PostCall"},
{"GetPipelineExecutableStatisticsKHR_ PostCall"},
{"GetPipelineExecutableInternalRepresentationsKHR_ PostCall"},
{"CmdEncodeVideoKHR_ PostCall"},
{"CmdSetEvent2KHR_ PostCall"},
{"CmdResetEvent2KHR_ PostCall"},
{"CmdWaitEvents2KHR_ PostCall"},
{"CmdPipelineBarrier2KHR_ PostCall"},
{"CmdWriteTimestamp2KHR_ PostCall"},
{"QueueSubmit2KHR_ PostCall"},
{"CmdWriteBufferMarker2AMD_ PostCall"},
{"GetQueueCheckpointData2NV_ PostCall"},
{"CmdCopyBuffer2KHR_ PostCall"},
{"CmdCopyImage2KHR_ PostCall"},
{"CmdCopyBufferToImage2KHR_ PostCall"},
{"CmdCopyImageToBuffer2KHR_ PostCall"},
{"CmdBlitImage2KHR_ PostCall"},
{"CmdResolveImage2KHR_ PostCall"},
{"CmdTraceRaysIndirect2KHR_ PostCall"},
{"GetDeviceBufferMemoryRequirementsKHR_ PostCall"},
{"GetDeviceImageMemoryRequirementsKHR_ PostCall"},
{"GetDeviceImageSparseMemoryRequirementsKHR_ PostCall"},
{"CreateDebugReportCallbackEXT_ PostCall"},
{"DestroyDebugReportCallbackEXT_ PostCall"},
{"DebugReportMessageEXT_ PostCall"},
{"DebugMarkerSetObjectTagEXT_ PostCall"},
{"DebugMarkerSetObjectNameEXT_ PostCall"},
{"CmdDebugMarkerBeginEXT_ PostCall"},
{"CmdDebugMarkerEndEXT_ PostCall"},
{"CmdDebugMarkerInsertEXT_ PostCall"},
{"CmdBindTransformFeedbackBuffersEXT_ PostCall"},
{"CmdBeginTransformFeedbackEXT_ PostCall"},
{"CmdEndTransformFeedbackEXT_ PostCall"},
{"CmdBeginQueryIndexedEXT_ PostCall"},
{"CmdEndQueryIndexedEXT_ PostCall"},
{"CmdDrawIndirectByteCountEXT_ PostCall"},
{"GetImageViewHandleNVX_ PostCall"},
{"GetImageViewAddressNVX_ PostCall"},
{"CmdDrawIndirectCountAMD_ PostCall"},
{"CmdDrawIndexedIndirectCountAMD_ PostCall"},
{"GetShaderInfoAMD_ PostCall"},
{"CreateStreamDescriptorSurfaceGGP_ PostCall"},
{"GetPhysicalDeviceExternalImageFormatPropertiesNV_ PostCall"},
{"GetMemoryWin32HandleNV_ PostCall"},
{"CreateViSurfaceNN_ PostCall"},
{"CmdBeginConditionalRenderingEXT_ PostCall"},
{"CmdEndConditionalRenderingEXT_ PostCall"},
{"CmdSetViewportWScalingNV_ PostCall"},
{"ReleaseDisplayEXT_ PostCall"},
{"AcquireXlibDisplayEXT_ PostCall"},
{"GetRandROutputDisplayEXT_ PostCall"},
{"GetPhysicalDeviceSurfaceCapabilities2EXT_ PostCall"},
{"DisplayPowerControlEXT_ PostCall"},
{"RegisterDeviceEventEXT_ PostCall"},
{"RegisterDisplayEventEXT_ PostCall"},
{"GetSwapchainCounterEXT_ PostCall"},
{"GetRefreshCycleDurationGOOGLE_ PostCall"},
{"GetPastPresentationTimingGOOGLE_ PostCall"},
{"CmdSetDiscardRectangleEXT_ PostCall"},
{"CmdSetDiscardRectangleEnableEXT_ PostCall"},
{"CmdSetDiscardRectangleModeEXT_ PostCall"},
{"SetHdrMetadataEXT_ PostCall"},
{"CreateIOSSurfaceMVK_ PostCall"},
{"CreateMacOSSurfaceMVK_ PostCall"},
{"SetDebugUtilsObjectNameEXT_ PostCall"},
{"SetDebugUtilsObjectTagEXT_ PostCall"},
{"QueueBeginDebugUtilsLabelEXT_ PostCall"},
{"QueueEndDebugUtilsLabelEXT_ PostCall"},
{"QueueInsertDebugUtilsLabelEXT_ PostCall"},
{"CmdBeginDebugUtilsLabelEXT_ PostCall"},
{"CmdEndDebugUtilsLabelEXT_ PostCall"},
{"CmdInsertDebugUtilsLabelEXT_ PostCall"},
{"CreateDebugUtilsMessengerEXT_ PostCall"},
{"DestroyDebugUtilsMessengerEXT_ PostCall"},
{"SubmitDebugUtilsMessageEXT_ PostCall"},
{"GetAndroidHardwareBufferPropertiesANDROID_ PostCall"},
{"GetMemoryAndroidHardwareBufferANDROID_ PostCall"},
{"CmdSetSampleLocationsEXT_ PostCall"},
{"GetPhysicalDeviceMultisamplePropertiesEXT_ PostCall"},
{"GetImageDrmFormatModifierPropertiesEXT_ PostCall"},
{"CreateValidationCacheEXT_ PostCall"},
{"DestroyValidationCacheEXT_ PostCall"},
{"MergeValidationCachesEXT_ PostCall"},
{"GetValidationCacheDataEXT_ PostCall"},
{"CmdBindShadingRateImageNV_ PostCall"},
{"CmdSetViewportShadingRatePaletteNV_ PostCall"},
{"CmdSetCoarseSampleOrderNV_ PostCall"},
{"CreateAccelerationStructureNV_ PostCall"},
{"DestroyAccelerationStructureNV_ PostCall"},
{"GetAccelerationStructureMemoryRequirementsNV_ PostCall"},
{"BindAccelerationStructureMemoryNV_ PostCall"},
{"CmdBuildAccelerationStructureNV_ PostCall"},
{"CmdCopyAccelerationStructureNV_ PostCall"},
{"CmdTraceRaysNV_ PostCall"},
{"CreateRayTracingPipelinesNV_ PostCall"},
{"GetRayTracingShaderGroupHandlesKHR_ PostCall"},
{"GetRayTracingShaderGroupHandlesNV_ PostCall"},
{"GetAccelerationStructureHandleNV_ PostCall"},
{"CmdWriteAccelerationStructuresPropertiesNV_ PostCall"},
{"CompileDeferredNV_ PostCall"},
{"GetMemoryHostPointerPropertiesEXT_ PostCall"},
{"CmdWriteBufferMarkerAMD_ PostCall"},
{"GetPhysicalDeviceCalibrateableTimeDomainsEXT_ PostCall"},
{"GetCalibratedTimestampsEXT_ PostCall"},
{"CmdDrawMeshTasksNV_ PostCall"},
{"CmdDrawMeshTasksIndirectNV_ PostCall"},
{"CmdDrawMeshTasksIndirectCountNV_ PostCall"},
{"CmdSetExclusiveScissorEnableNV_ PostCall"},
{"CmdSetExclusiveScissorNV_ PostCall"},
{"CmdSetCheckpointNV_ PostCall"},
{"GetQueueCheckpointDataNV_ PostCall"},
{"InitializePerformanceApiINTEL_ PostCall"},
{"UninitializePerformanceApiINTEL_ PostCall"},
{"CmdSetPerformanceMarkerINTEL_ PostCall"},
{"CmdSetPerformanceStreamMarkerINTEL_ PostCall"},
{"CmdSetPerformanceOverrideINTEL_ PostCall"},
{"AcquirePerformanceConfigurationINTEL_ PostCall"},
{"ReleasePerformanceConfigurationINTEL_ PostCall"},
{"QueueSetPerformanceConfigurationINTEL_ PostCall"},
{"GetPerformanceParameterINTEL_ PostCall"},
{"SetLocalDimmingAMD_ PostCall"},
{"CreateImagePipeSurfaceFUCHSIA_ PostCall"},
{"CreateMetalSurfaceEXT_ PostCall"},
{"GetBufferDeviceAddressEXT_ PostCall"},
{"GetPhysicalDeviceToolPropertiesEXT_ PostCall"},
{"GetPhysicalDeviceCooperativeMatrixPropertiesNV_ PostCall"},
{"GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_ PostCall"},
{"GetPhysicalDeviceSurfacePresentModes2EXT_ PostCall"},
{"AcquireFullScreenExclusiveModeEXT_ PostCall"},
{"ReleaseFullScreenExclusiveModeEXT_ PostCall"},
{"GetDeviceGroupSurfacePresentModes2EXT_ PostCall"},
{"CreateHeadlessSurfaceEXT_ PostCall"},
{"CmdSetLineStippleEXT_ PostCall"},
{"ResetQueryPoolEXT_ PostCall"},
{"CmdSetCullModeEXT_ PostCall"},
{"CmdSetFrontFaceEXT_ PostCall"},
{"CmdSetPrimitiveTopologyEXT_ PostCall"},
{"CmdSetViewportWithCountEXT_ PostCall"},
{"CmdSetScissorWithCountEXT_ PostCall"},
{"CmdBindVertexBuffers2EXT_ PostCall"},
{"CmdSetDepthTestEnableEXT_ PostCall"},
{"CmdSetDepthWriteEnableEXT_ PostCall"},
{"CmdSetDepthCompareOpEXT_ PostCall"},
{"CmdSetDepthBoundsTestEnableEXT_ PostCall"},
{"CmdSetStencilTestEnableEXT_ PostCall"},
{"CmdSetStencilOpEXT_ PostCall"},
{"ReleaseSwapchainImagesEXT_ PostCall"},
{"GetGeneratedCommandsMemoryRequirementsNV_ PostCall"},
{"CmdPreprocessGeneratedCommandsNV_ PostCall"},
{"CmdExecuteGeneratedCommandsNV_ PostCall"},
{"CmdBindPipelineShaderGroupNV_ PostCall"},
{"CreateIndirectCommandsLayoutNV_ PostCall"},
{"DestroyIndirectCommandsLayoutNV_ PostCall"},
{"AcquireDrmDisplayEXT_ PostCall"},
{"GetDrmDisplayEXT_ PostCall"},
{"CreatePrivateDataSlotEXT_ PostCall"},
{"DestroyPrivateDataSlotEXT_ PostCall"},
{"SetPrivateDataEXT_ PostCall"},
{"GetPrivateDataEXT_ PostCall"},
{"CmdSetFragmentShadingRateEnumNV_ PostCall"},
{"GetImageSubresourceLayout2EXT_ PostCall"},
{"GetDeviceFaultInfoEXT_ PostCall"},
{"AcquireWinrtDisplayNV_ PostCall"},
{"GetWinrtDisplayNV_ PostCall"},
{"CreateDirectFBSurfaceEXT_ PostCall"},
{"GetPhysicalDeviceDirectFBPresentationSupportEXT_ PostCall"},
{"CmdSetVertexInputEXT_ PostCall"},
{"GetMemoryZirconHandleFUCHSIA_ PostCall"},
{"GetMemoryZirconHandlePropertiesFUCHSIA_ PostCall"},
{"ImportSemaphoreZirconHandleFUCHSIA_ PostCall"},
{"GetSemaphoreZirconHandleFUCHSIA_ PostCall"},
{"CmdBindInvocationMaskHUAWEI_ PostCall"},
{"GetMemoryRemoteAddressNV_ PostCall"},
{"CmdSetPatchControlPointsEXT_ PostCall"},
{"CmdSetRasterizerDiscardEnableEXT_ PostCall"},
{"CmdSetDepthBiasEnableEXT_ PostCall"},
{"CmdSetLogicOpEXT_ PostCall"},
{"CmdSetPrimitiveRestartEnableEXT_ PostCall"},
{"CreateScreenSurfaceQNX_ PostCall"},
{"GetPhysicalDeviceScreenPresentationSupportQNX_ PostCall"},
{"CmdSetColorWriteEnableEXT_ PostCall"},
{"CmdDrawMultiEXT_ PostCall"},
{"CmdDrawMultiIndexedEXT_ PostCall"},
{"CreateMicromapEXT_ PostCall"},
{"DestroyMicromapEXT_ PostCall"},
{"CmdBuildMicromapsEXT_ PostCall"},
{"BuildMicromapsEXT_ PostCall"},
{"CopyMicromapEXT_ PostCall"},
{"CopyMicromapToMemoryEXT_ PostCall"},
{"CopyMemoryToMicromapEXT_ PostCall"},
{"WriteMicromapsPropertiesEXT_ PostCall"},
{"CmdCopyMicromapEXT_ PostCall"},
{"CmdCopyMicromapToMemoryEXT_ PostCall"},
{"CmdCopyMemoryToMicromapEXT_ PostCall"},
{"CmdWriteMicromapsPropertiesEXT_ PostCall"},
{"GetDeviceMicromapCompatibilityEXT_ PostCall"},
{"GetMicromapBuildSizesEXT_ PostCall"},
{"CmdDrawClusterHUAWEI_ PostCall"},
{"CmdDrawClusterIndirectHUAWEI_ PostCall"},
{"SetDeviceMemoryPriorityEXT_ PostCall"},
{"GetDescriptorSetLayoutHostMappingInfoVALVE_ PostCall"},
{"GetDescriptorSetHostMappingVALVE_ PostCall"},
{"CmdSetTessellationDomainOriginEXT_ PostCall"},
{"CmdSetDepthClampEnableEXT_ PostCall"},
{"CmdSetPolygonModeEXT_ PostCall"},
{"CmdSetRasterizationSamplesEXT_ PostCall"},
{"CmdSetSampleMaskEXT_ PostCall"},
{"CmdSetAlphaToCoverageEnableEXT_ PostCall"},
{"CmdSetAlphaToOneEnableEXT_ PostCall"},
{"CmdSetLogicOpEnableEXT_ PostCall"},
{"CmdSetColorBlendEnableEXT_ PostCall"},
{"CmdSetColorBlendEquationEXT_ PostCall"},
{"CmdSetColorWriteMaskEXT_ PostCall"},
{"CmdSetRasterizationStreamEXT_ PostCall"},
{"CmdSetConservativeRasterizationModeEXT_ PostCall"},
{"CmdSetExtraPrimitiveOverestimationSizeEXT_ PostCall"},
{"CmdSetDepthClipEnableEXT_ PostCall"},
{"CmdSetSampleLocationsEnableEXT_ PostCall"},
{"CmdSetColorBlendAdvancedEXT_ PostCall"},
{"CmdSetProvokingVertexModeEXT_ PostCall"},
{"CmdSetLineRasterizationModeEXT_ PostCall"},
{"CmdSetLineStippleEnableEXT_ PostCall"},
{"CmdSetDepthClipNegativeOneToOneEXT_ PostCall"},
{"CmdSetViewportWScalingEnableNV_ PostCall"},
{"CmdSetViewportSwizzleNV_ PostCall"},
{"CmdSetCoverageToColorEnableNV_ PostCall"},
{"CmdSetCoverageToColorLocationNV_ PostCall"},
{"CmdSetCoverageModulationModeNV_ PostCall"},
{"CmdSetCoverageModulationTableEnableNV_ PostCall"},
{"CmdSetCoverageModulationTableNV_ PostCall"},
{"CmdSetShadingRateImageEnableNV_ PostCall"},
{"CmdSetRepresentativeFragmentTestEnableNV_ PostCall"},
{"CmdSetCoverageReductionModeNV_ PostCall"},
{"GetShaderModuleIdentifierEXT_ PostCall"},
{"GetShaderModuleCreateInfoIdentifierEXT_ PostCall"},
{"GetPhysicalDeviceOpticalFlowImageFormatsNV_ PostCall"},
{"CreateOpticalFlowSessionNV_ PostCall"},
{"DestroyOpticalFlowSessionNV_ PostCall"},
{"BindOpticalFlowSessionImageNV_ PostCall"},
{"CmdOpticalFlowExecuteNV_ PostCall"},
{"GetFramebufferTilePropertiesQCOM_ PostCall"},
{"GetDynamicRenderingTilePropertiesQCOM_ PostCall"},
{"CreateAccelerationStructureKHR_ PostCall"},
{"DestroyAccelerationStructureKHR_ PostCall"},
{"CmdBuildAccelerationStructuresKHR_ PostCall"},
{"CmdBuildAccelerationStructuresIndirectKHR_ PostCall"},
{"CopyAccelerationStructureToMemoryKHR_ PostCall"},
{"CopyMemoryToAccelerationStructureKHR_ PostCall"},
{"WriteAccelerationStructuresPropertiesKHR_ PostCall"},
{"CmdCopyAccelerationStructureKHR_ PostCall"},
{"CmdCopyAccelerationStructureToMemoryKHR_ PostCall"},
{"CmdCopyMemoryToAccelerationStructureKHR_ PostCall"},
{"GetAccelerationStructureDeviceAddressKHR_ PostCall"},
{"CmdWriteAccelerationStructuresPropertiesKHR_ PostCall"},
{"GetDeviceAccelerationStructureCompatibilityKHR_ PostCall"},
{"GetAccelerationStructureBuildSizesKHR_ PostCall"},
{"CmdTraceRaysKHR_ PostCall"},
{"CreateRayTracingPipelinesKHR_ PostCall"},
{"GetRayTracingCaptureReplayShaderGroupHandlesKHR_ PostCall"},
{"CmdTraceRaysIndirectKHR_ PostCall"},
{"GetRayTracingShaderGroupStackSizeKHR_ PostCall"},
{"CmdSetRayTracingPipelineStackSizeKHR_ PostCall"},
{"CmdDrawMeshTasksEXT_ PostCall"},
{"CmdDrawMeshTasksIndirectEXT_ PostCall"},
{"CmdDrawMeshTasksIndirectCountEXT_ PostCall"}
};

typedef VkResult (VKAPI_PTR *PFN_CreateInstance_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
typedef void (VKAPI_PTR *PFN_DestroyInstance_PostCall)(encode::VulkanCaptureManager* manager, VkInstance instance, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_EnumeratePhysicalDevices_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFeatures_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFormatProperties_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceImageFormatProperties_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceProperties_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceQueueFamilyProperties_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceMemoryProperties_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties);
typedef VkResult (VKAPI_PTR *PFN_CreateDevice_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice);
typedef void (VKAPI_PTR *PFN_DestroyDevice_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetDeviceQueue_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
typedef VkResult (VKAPI_PTR *PFN_QueueSubmit_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
typedef VkResult (VKAPI_PTR *PFN_QueueWaitIdle_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue);
typedef VkResult (VKAPI_PTR *PFN_DeviceWaitIdle_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device);
typedef VkResult (VKAPI_PTR *PFN_AllocateMemory_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);
typedef void (VKAPI_PTR *PFN_FreeMemory_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_MapMemory_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);
typedef void (VKAPI_PTR *PFN_UnmapMemory_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory);
typedef VkResult (VKAPI_PTR *PFN_FlushMappedMemoryRanges_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
typedef VkResult (VKAPI_PTR *PFN_InvalidateMappedMemoryRanges_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
typedef void (VKAPI_PTR *PFN_GetDeviceMemoryCommitment_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);
typedef VkResult (VKAPI_PTR *PFN_BindBufferMemory_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
typedef VkResult (VKAPI_PTR *PFN_BindImageMemory_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
typedef void (VKAPI_PTR *PFN_GetBufferMemoryRequirements_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetImageMemoryRequirements_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetImageSparseMemoryRequirements_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSparseImageFormatProperties_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties);
typedef VkResult (VKAPI_PTR *PFN_QueueBindSparse_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);
typedef VkResult (VKAPI_PTR *PFN_CreateFence_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
typedef void (VKAPI_PTR *PFN_DestroyFence_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_ResetFences_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t fenceCount, const VkFence* pFences);
typedef VkResult (VKAPI_PTR *PFN_GetFenceStatus_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkFence fence);
typedef VkResult (VKAPI_PTR *PFN_WaitForFences_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);
typedef VkResult (VKAPI_PTR *PFN_CreateSemaphore_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
typedef void (VKAPI_PTR *PFN_DestroySemaphore_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_CreateEvent_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent);
typedef void (VKAPI_PTR *PFN_DestroyEvent_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_GetEventStatus_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkEvent event);
typedef VkResult (VKAPI_PTR *PFN_SetEvent_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkEvent event);
typedef VkResult (VKAPI_PTR *PFN_ResetEvent_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkEvent event);
typedef VkResult (VKAPI_PTR *PFN_CreateQueryPool_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);
typedef void (VKAPI_PTR *PFN_DestroyQueryPool_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_GetQueryPoolResults_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags);
typedef VkResult (VKAPI_PTR *PFN_CreateBuffer_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
typedef void (VKAPI_PTR *PFN_DestroyBuffer_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_CreateBufferView_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView);
typedef void (VKAPI_PTR *PFN_DestroyBufferView_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_CreateImage_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage);
typedef void (VKAPI_PTR *PFN_DestroyImage_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetImageSubresourceLayout_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout);
typedef VkResult (VKAPI_PTR *PFN_CreateImageView_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView);
typedef void (VKAPI_PTR *PFN_DestroyImageView_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_CreateShaderModule_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule);
typedef void (VKAPI_PTR *PFN_DestroyShaderModule_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_CreatePipelineCache_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache);
typedef void (VKAPI_PTR *PFN_DestroyPipelineCache_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_GetPipelineCacheData_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);
typedef VkResult (VKAPI_PTR *PFN_MergePipelineCaches_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches);
typedef VkResult (VKAPI_PTR *PFN_CreateGraphicsPipelines_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
typedef VkResult (VKAPI_PTR *PFN_CreateComputePipelines_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
typedef void (VKAPI_PTR *PFN_DestroyPipeline_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_CreatePipelineLayout_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout);
typedef void (VKAPI_PTR *PFN_DestroyPipelineLayout_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_CreateSampler_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler);
typedef void (VKAPI_PTR *PFN_DestroySampler_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_CreateDescriptorSetLayout_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout);
typedef void (VKAPI_PTR *PFN_DestroyDescriptorSetLayout_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_CreateDescriptorPool_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);
typedef void (VKAPI_PTR *PFN_DestroyDescriptorPool_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_ResetDescriptorPool_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags);
typedef VkResult (VKAPI_PTR *PFN_AllocateDescriptorSets_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets);
typedef VkResult (VKAPI_PTR *PFN_FreeDescriptorSets_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);
typedef void (VKAPI_PTR *PFN_UpdateDescriptorSets_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies);
typedef VkResult (VKAPI_PTR *PFN_CreateFramebuffer_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);
typedef void (VKAPI_PTR *PFN_DestroyFramebuffer_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_CreateRenderPass_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
typedef void (VKAPI_PTR *PFN_DestroyRenderPass_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetRenderAreaGranularity_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity);
typedef VkResult (VKAPI_PTR *PFN_CreateCommandPool_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
typedef void (VKAPI_PTR *PFN_DestroyCommandPool_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_ResetCommandPool_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags);
typedef VkResult (VKAPI_PTR *PFN_AllocateCommandBuffers_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);
typedef void (VKAPI_PTR *PFN_FreeCommandBuffers_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
typedef VkResult (VKAPI_PTR *PFN_BeginCommandBuffer_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);
typedef VkResult (VKAPI_PTR *PFN_EndCommandBuffer_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer);
typedef VkResult (VKAPI_PTR *PFN_ResetCommandBuffer_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);
typedef void (VKAPI_PTR *PFN_CmdBindPipeline_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
typedef void (VKAPI_PTR *PFN_CmdSetViewport_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports);
typedef void (VKAPI_PTR *PFN_CmdSetScissor_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors);
typedef void (VKAPI_PTR *PFN_CmdSetLineWidth_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float lineWidth);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBias_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
typedef void (VKAPI_PTR *PFN_CmdSetBlendConstants_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const float blendConstants[4]);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBounds_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);
typedef void (VKAPI_PTR *PFN_CmdSetStencilCompareMask_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);
typedef void (VKAPI_PTR *PFN_CmdSetStencilWriteMask_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);
typedef void (VKAPI_PTR *PFN_CmdSetStencilReference_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);
typedef void (VKAPI_PTR *PFN_CmdBindDescriptorSets_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets);
typedef void (VKAPI_PTR *PFN_CmdBindIndexBuffer_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
typedef void (VKAPI_PTR *PFN_CmdBindVertexBuffers_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);
typedef void (VKAPI_PTR *PFN_CmdDraw_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexed_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirect_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexedIndirect_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDispatch_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_CmdDispatchIndirect_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
typedef void (VKAPI_PTR *PFN_CmdCopyBuffer_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions);
typedef void (VKAPI_PTR *PFN_CmdCopyImage_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions);
typedef void (VKAPI_PTR *PFN_CmdBlitImage_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter);
typedef void (VKAPI_PTR *PFN_CmdCopyBufferToImage_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);
typedef void (VKAPI_PTR *PFN_CmdCopyImageToBuffer_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);
typedef void (VKAPI_PTR *PFN_CmdUpdateBuffer_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData);
typedef void (VKAPI_PTR *PFN_CmdFillBuffer_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);
typedef void (VKAPI_PTR *PFN_CmdClearColorImage_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
typedef void (VKAPI_PTR *PFN_CmdClearDepthStencilImage_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges);
typedef void (VKAPI_PTR *PFN_CmdClearAttachments_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects);
typedef void (VKAPI_PTR *PFN_CmdResolveImage_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions);
typedef void (VKAPI_PTR *PFN_CmdSetEvent_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
typedef void (VKAPI_PTR *PFN_CmdResetEvent_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
typedef void (VKAPI_PTR *PFN_CmdWaitEvents_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
typedef void (VKAPI_PTR *PFN_CmdPipelineBarrier_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
typedef void (VKAPI_PTR *PFN_CmdBeginQuery_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);
typedef void (VKAPI_PTR *PFN_CmdEndQuery_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);
typedef void (VKAPI_PTR *PFN_CmdResetQueryPool_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_PTR *PFN_CmdWriteTimestamp_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query);
typedef void (VKAPI_PTR *PFN_CmdCopyQueryPoolResults_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);
typedef void (VKAPI_PTR *PFN_CmdPushConstants_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues);
typedef void (VKAPI_PTR *PFN_CmdBeginRenderPass_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents);
typedef void (VKAPI_PTR *PFN_CmdNextSubpass_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSubpassContents contents);
typedef void (VKAPI_PTR *PFN_CmdEndRenderPass_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdExecuteCommands_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
typedef VkResult (VKAPI_PTR *PFN_BindBufferMemory2_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);
typedef VkResult (VKAPI_PTR *PFN_BindImageMemory2_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);
typedef void (VKAPI_PTR *PFN_GetDeviceGroupPeerMemoryFeatures_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);
typedef void (VKAPI_PTR *PFN_CmdSetDeviceMask_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t deviceMask);
typedef void (VKAPI_PTR *PFN_CmdDispatchBase_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef VkResult (VKAPI_PTR *PFN_EnumeratePhysicalDeviceGroups_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);
typedef void (VKAPI_PTR *PFN_GetImageMemoryRequirements2_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetBufferMemoryRequirements2_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetImageSparseMemoryRequirements2_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFeatures2_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceProperties2_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFormatProperties2_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceImageFormatProperties2_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceQueueFamilyProperties2_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceMemoryProperties2_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSparseImageFormatProperties2_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);
typedef void (VKAPI_PTR *PFN_TrimCommandPool_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
typedef void (VKAPI_PTR *PFN_GetDeviceQueue2_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue);
typedef VkResult (VKAPI_PTR *PFN_CreateSamplerYcbcrConversion_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);
typedef void (VKAPI_PTR *PFN_DestroySamplerYcbcrConversion_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_CreateDescriptorUpdateTemplate_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);
typedef void (VKAPI_PTR *PFN_DestroyDescriptorUpdateTemplate_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalBufferProperties_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalFenceProperties_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalSemaphoreProperties_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);
typedef void (VKAPI_PTR *PFN_GetDescriptorSetLayoutSupport_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirectCount_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexedIndirectCount_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef VkResult (VKAPI_PTR *PFN_CreateRenderPass2_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
typedef void (VKAPI_PTR *PFN_CmdBeginRenderPass2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo);
typedef void (VKAPI_PTR *PFN_CmdNextSubpass2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo);
typedef void (VKAPI_PTR *PFN_CmdEndRenderPass2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);
typedef void (VKAPI_PTR *PFN_ResetQueryPool_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef VkResult (VKAPI_PTR *PFN_GetSemaphoreCounterValue_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSemaphore semaphore, uint64_t* pValue);
typedef VkResult (VKAPI_PTR *PFN_WaitSemaphores_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);
typedef VkResult (VKAPI_PTR *PFN_SignalSemaphore_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo);
typedef VkDeviceAddress (VKAPI_PTR *PFN_GetBufferDeviceAddress_PostCall)(encode::VulkanCaptureManager* manager, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef uint64_t (VKAPI_PTR *PFN_GetBufferOpaqueCaptureAddress_PostCall)(encode::VulkanCaptureManager* manager, uint64_t result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef uint64_t (VKAPI_PTR *PFN_GetDeviceMemoryOpaqueCaptureAddress_PostCall)(encode::VulkanCaptureManager* manager, uint64_t result, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceToolProperties_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties);
typedef VkResult (VKAPI_PTR *PFN_CreatePrivateDataSlot_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot);
typedef void (VKAPI_PTR *PFN_DestroyPrivateDataSlot_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_SetPrivateData_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);
typedef void (VKAPI_PTR *PFN_GetPrivateData_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData);
typedef void (VKAPI_PTR *PFN_CmdSetEvent2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);
typedef void (VKAPI_PTR *PFN_CmdResetEvent2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);
typedef void (VKAPI_PTR *PFN_CmdWaitEvents2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);
typedef void (VKAPI_PTR *PFN_CmdPipelineBarrier2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
typedef void (VKAPI_PTR *PFN_CmdWriteTimestamp2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query);
typedef VkResult (VKAPI_PTR *PFN_QueueSubmit2_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);
typedef void (VKAPI_PTR *PFN_CmdCopyBuffer2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyImage2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyBufferToImage2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyImageToBuffer2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
typedef void (VKAPI_PTR *PFN_CmdBlitImage2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
typedef void (VKAPI_PTR *PFN_CmdResolveImage2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
typedef void (VKAPI_PTR *PFN_CmdBeginRendering_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);
typedef void (VKAPI_PTR *PFN_CmdEndRendering_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdSetCullMode_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
typedef void (VKAPI_PTR *PFN_CmdSetFrontFace_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFrontFace frontFace);
typedef void (VKAPI_PTR *PFN_CmdSetPrimitiveTopology_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
typedef void (VKAPI_PTR *PFN_CmdSetViewportWithCount_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);
typedef void (VKAPI_PTR *PFN_CmdSetScissorWithCount_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);
typedef void (VKAPI_PTR *PFN_CmdBindVertexBuffers2_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);
typedef void (VKAPI_PTR *PFN_CmdSetDepthTestEnable_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthWriteEnable_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthCompareOp_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBoundsTestEnable_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetStencilTestEnable_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetStencilOp_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
typedef void (VKAPI_PTR *PFN_CmdSetRasterizerDiscardEnable_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBiasEnable_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);
typedef void (VKAPI_PTR *PFN_CmdSetPrimitiveRestartEnable_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);
typedef void (VKAPI_PTR *PFN_GetDeviceBufferMemoryRequirements_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetDeviceImageMemoryRequirements_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetDeviceImageSparseMemoryRequirements_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
typedef void (VKAPI_PTR *PFN_DestroySurfaceKHR_PostCall)(encode::VulkanCaptureManager* manager, VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceSupportKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceFormatsKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceSurfacePresentModesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
typedef VkResult (VKAPI_PTR *PFN_CreateSwapchainKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
typedef void (VKAPI_PTR *PFN_DestroySwapchainKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_GetSwapchainImagesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);
typedef VkResult (VKAPI_PTR *PFN_AcquireNextImageKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);
typedef VkResult (VKAPI_PTR *PFN_QueuePresentKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, const VkPresentInfoKHR* pPresentInfo);
typedef VkResult (VKAPI_PTR *PFN_GetDeviceGroupPresentCapabilitiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities);
typedef VkResult (VKAPI_PTR *PFN_GetDeviceGroupSurfacePresentModesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDevicePresentRectanglesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects);
typedef VkResult (VKAPI_PTR *PFN_AcquireNextImage2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceDisplayPropertiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties);
typedef VkResult (VKAPI_PTR *PFN_GetDisplayPlaneSupportedDisplaysKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays);
typedef VkResult (VKAPI_PTR *PFN_GetDisplayModePropertiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties);
typedef VkResult (VKAPI_PTR *PFN_CreateDisplayModeKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode);
typedef VkResult (VKAPI_PTR *PFN_GetDisplayPlaneCapabilitiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities);
typedef VkResult (VKAPI_PTR *PFN_CreateDisplayPlaneSurfaceKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkResult (VKAPI_PTR *PFN_CreateSharedSwapchainsKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains);
typedef VkResult (VKAPI_PTR *PFN_CreateXlibSurfaceKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkBool32 (VKAPI_PTR *PFN_GetPhysicalDeviceXlibPresentationSupportKHR_PostCall)(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID);
typedef VkResult (VKAPI_PTR *PFN_CreateXcbSurfaceKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkBool32 (VKAPI_PTR *PFN_GetPhysicalDeviceXcbPresentationSupportKHR_PostCall)(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id);
typedef VkResult (VKAPI_PTR *PFN_CreateWaylandSurfaceKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkBool32 (VKAPI_PTR *PFN_GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall)(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display);
typedef VkResult (VKAPI_PTR *PFN_CreateAndroidSurfaceKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkResult (VKAPI_PTR *PFN_CreateWin32SurfaceKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkBool32 (VKAPI_PTR *PFN_GetPhysicalDeviceWin32PresentationSupportKHR_PostCall)(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceVideoCapabilitiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties);
typedef VkResult (VKAPI_PTR *PFN_CreateVideoSessionKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession);
typedef void (VKAPI_PTR *PFN_DestroyVideoSessionKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_GetVideoSessionMemoryRequirementsKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements);
typedef VkResult (VKAPI_PTR *PFN_BindVideoSessionMemoryKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos);
typedef VkResult (VKAPI_PTR *PFN_CreateVideoSessionParametersKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters);
typedef VkResult (VKAPI_PTR *PFN_UpdateVideoSessionParametersKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo);
typedef void (VKAPI_PTR *PFN_DestroyVideoSessionParametersKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CmdBeginVideoCodingKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo);
typedef void (VKAPI_PTR *PFN_CmdEndVideoCodingKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo);
typedef void (VKAPI_PTR *PFN_CmdControlVideoCodingKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo);
typedef void (VKAPI_PTR *PFN_CmdDecodeVideoKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo);
typedef void (VKAPI_PTR *PFN_CmdBeginRenderingKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);
typedef void (VKAPI_PTR *PFN_CmdEndRenderingKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFeatures2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceProperties2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceFormatProperties2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceImageFormatProperties2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceMemoryProperties2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties);
typedef void (VKAPI_PTR *PFN_GetDeviceGroupPeerMemoryFeaturesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);
typedef void (VKAPI_PTR *PFN_CmdSetDeviceMaskKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t deviceMask);
typedef void (VKAPI_PTR *PFN_CmdDispatchBaseKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_TrimCommandPoolKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
typedef VkResult (VKAPI_PTR *PFN_EnumeratePhysicalDeviceGroupsKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties);
typedef VkResult (VKAPI_PTR *PFN_GetMemoryWin32HandleKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);
typedef VkResult (VKAPI_PTR *PFN_GetMemoryWin32HandlePropertiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties);
typedef VkResult (VKAPI_PTR *PFN_GetMemoryFdKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd);
typedef VkResult (VKAPI_PTR *PFN_GetMemoryFdPropertiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties);
typedef VkResult (VKAPI_PTR *PFN_ImportSemaphoreWin32HandleKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo);
typedef VkResult (VKAPI_PTR *PFN_GetSemaphoreWin32HandleKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);
typedef VkResult (VKAPI_PTR *PFN_ImportSemaphoreFdKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo);
typedef VkResult (VKAPI_PTR *PFN_GetSemaphoreFdKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd);
typedef void (VKAPI_PTR *PFN_CmdPushDescriptorSetKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites);
typedef VkResult (VKAPI_PTR *PFN_CreateDescriptorUpdateTemplateKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);
typedef void (VKAPI_PTR *PFN_DestroyDescriptorUpdateTemplateKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_CreateRenderPass2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
typedef void (VKAPI_PTR *PFN_CmdBeginRenderPass2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo);
typedef void (VKAPI_PTR *PFN_CmdNextSubpass2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo);
typedef void (VKAPI_PTR *PFN_CmdEndRenderPass2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);
typedef VkResult (VKAPI_PTR *PFN_GetSwapchainStatusKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceExternalFencePropertiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties);
typedef VkResult (VKAPI_PTR *PFN_ImportFenceWin32HandleKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo);
typedef VkResult (VKAPI_PTR *PFN_GetFenceWin32HandleKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle);
typedef VkResult (VKAPI_PTR *PFN_ImportFenceFdKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo);
typedef VkResult (VKAPI_PTR *PFN_GetFenceFdKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd);
typedef VkResult (VKAPI_PTR *PFN_EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses);
typedef VkResult (VKAPI_PTR *PFN_AcquireProfilingLockKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_ReleaseProfilingLockKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceFormats2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceDisplayProperties2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties);
typedef VkResult (VKAPI_PTR *PFN_GetDisplayModeProperties2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties);
typedef VkResult (VKAPI_PTR *PFN_GetDisplayPlaneCapabilities2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities);
typedef void (VKAPI_PTR *PFN_GetImageMemoryRequirements2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetBufferMemoryRequirements2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetImageSparseMemoryRequirements2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
typedef VkResult (VKAPI_PTR *PFN_CreateSamplerYcbcrConversionKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion);
typedef void (VKAPI_PTR *PFN_DestroySamplerYcbcrConversionKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_BindBufferMemory2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos);
typedef VkResult (VKAPI_PTR *PFN_BindImageMemory2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);
typedef void (VKAPI_PTR *PFN_GetDescriptorSetLayoutSupportKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirectCountKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexedIndirectCountKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef VkResult (VKAPI_PTR *PFN_GetSemaphoreCounterValueKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSemaphore semaphore, uint64_t* pValue);
typedef VkResult (VKAPI_PTR *PFN_WaitSemaphoresKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout);
typedef VkResult (VKAPI_PTR *PFN_SignalSemaphoreKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceFragmentShadingRatesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates);
typedef void (VKAPI_PTR *PFN_CmdSetFragmentShadingRateKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);
typedef VkResult (VKAPI_PTR *PFN_WaitForPresentKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout);
typedef VkDeviceAddress (VKAPI_PTR *PFN_GetBufferDeviceAddressKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef uint64_t (VKAPI_PTR *PFN_GetBufferOpaqueCaptureAddressKHR_PostCall)(encode::VulkanCaptureManager* manager, uint64_t result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef uint64_t (VKAPI_PTR *PFN_GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall)(encode::VulkanCaptureManager* manager, uint64_t result, VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
typedef VkResult (VKAPI_PTR *PFN_CreateDeferredOperationKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation);
typedef void (VKAPI_PTR *PFN_DestroyDeferredOperationKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator);
typedef uint32_t (VKAPI_PTR *PFN_GetDeferredOperationMaxConcurrencyKHR_PostCall)(encode::VulkanCaptureManager* manager, uint32_t result, VkDevice device, VkDeferredOperationKHR operation);
typedef VkResult (VKAPI_PTR *PFN_GetDeferredOperationResultKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR operation);
typedef VkResult (VKAPI_PTR *PFN_DeferredOperationJoinKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR operation);
typedef VkResult (VKAPI_PTR *PFN_GetPipelineExecutablePropertiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties);
typedef VkResult (VKAPI_PTR *PFN_GetPipelineExecutableStatisticsKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics);
typedef VkResult (VKAPI_PTR *PFN_GetPipelineExecutableInternalRepresentationsKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations);
typedef void (VKAPI_PTR *PFN_CmdEncodeVideoKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo);
typedef void (VKAPI_PTR *PFN_CmdSetEvent2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);
typedef void (VKAPI_PTR *PFN_CmdResetEvent2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);
typedef void (VKAPI_PTR *PFN_CmdWaitEvents2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);
typedef void (VKAPI_PTR *PFN_CmdPipelineBarrier2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
typedef void (VKAPI_PTR *PFN_CmdWriteTimestamp2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query);
typedef VkResult (VKAPI_PTR *PFN_QueueSubmit2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);
typedef void (VKAPI_PTR *PFN_CmdWriteBufferMarker2AMD_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);
typedef void (VKAPI_PTR *PFN_GetQueueCheckpointData2NV_PostCall)(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData);
typedef void (VKAPI_PTR *PFN_CmdCopyBuffer2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyImage2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyBufferToImage2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyImageToBuffer2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
typedef void (VKAPI_PTR *PFN_CmdBlitImage2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
typedef void (VKAPI_PTR *PFN_CmdResolveImage2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
typedef void (VKAPI_PTR *PFN_CmdTraceRaysIndirect2KHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress);
typedef void (VKAPI_PTR *PFN_GetDeviceBufferMemoryRequirementsKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetDeviceImageMemoryRequirementsKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_GetDeviceImageSparseMemoryRequirementsKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
typedef VkResult (VKAPI_PTR *PFN_CreateDebugReportCallbackEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);
typedef void (VKAPI_PTR *PFN_DestroyDebugReportCallbackEXT_PostCall)(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_DebugReportMessageEXT_PostCall)(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage);
typedef VkResult (VKAPI_PTR *PFN_DebugMarkerSetObjectTagEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo);
typedef VkResult (VKAPI_PTR *PFN_DebugMarkerSetObjectNameEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo);
typedef void (VKAPI_PTR *PFN_CmdDebugMarkerBeginEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);
typedef void (VKAPI_PTR *PFN_CmdDebugMarkerEndEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdDebugMarkerInsertEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);
typedef void (VKAPI_PTR *PFN_CmdBindTransformFeedbackBuffersEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes);
typedef void (VKAPI_PTR *PFN_CmdBeginTransformFeedbackEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets);
typedef void (VKAPI_PTR *PFN_CmdEndTransformFeedbackEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets);
typedef void (VKAPI_PTR *PFN_CmdBeginQueryIndexedEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index);
typedef void (VKAPI_PTR *PFN_CmdEndQueryIndexedEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirectByteCountEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride);
typedef uint32_t (VKAPI_PTR *PFN_GetImageViewHandleNVX_PostCall)(encode::VulkanCaptureManager* manager, uint32_t result, VkDevice device, const VkImageViewHandleInfoNVX* pInfo);
typedef VkResult (VKAPI_PTR *PFN_GetImageViewAddressNVX_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties);
typedef void (VKAPI_PTR *PFN_CmdDrawIndirectCountAMD_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawIndexedIndirectCountAMD_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef VkResult (VKAPI_PTR *PFN_GetShaderInfoAMD_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo);
typedef VkResult (VKAPI_PTR *PFN_CreateStreamDescriptorSurfaceGGP_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties);
typedef VkResult (VKAPI_PTR *PFN_GetMemoryWin32HandleNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle);
typedef VkResult (VKAPI_PTR *PFN_CreateViSurfaceNN_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CmdBeginConditionalRenderingEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);
typedef void (VKAPI_PTR *PFN_CmdEndConditionalRenderingEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdSetViewportWScalingNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings);
typedef VkResult (VKAPI_PTR *PFN_ReleaseDisplayEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display);
typedef VkResult (VKAPI_PTR *PFN_AcquireXlibDisplayEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display);
typedef VkResult (VKAPI_PTR *PFN_GetRandROutputDisplayEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities);
typedef VkResult (VKAPI_PTR *PFN_DisplayPowerControlEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo);
typedef VkResult (VKAPI_PTR *PFN_RegisterDeviceEventEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
typedef VkResult (VKAPI_PTR *PFN_RegisterDisplayEventEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence);
typedef VkResult (VKAPI_PTR *PFN_GetSwapchainCounterEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue);
typedef VkResult (VKAPI_PTR *PFN_GetRefreshCycleDurationGOOGLE_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties);
typedef VkResult (VKAPI_PTR *PFN_GetPastPresentationTimingGOOGLE_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings);
typedef void (VKAPI_PTR *PFN_CmdSetDiscardRectangleEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles);
typedef void (VKAPI_PTR *PFN_CmdSetDiscardRectangleEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDiscardRectangleModeEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode);
typedef void (VKAPI_PTR *PFN_SetHdrMetadataEXT_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata);
typedef VkResult (VKAPI_PTR *PFN_CreateIOSSurfaceMVK_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkResult (VKAPI_PTR *PFN_CreateMacOSSurfaceMVK_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkResult (VKAPI_PTR *PFN_SetDebugUtilsObjectNameEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo);
typedef VkResult (VKAPI_PTR *PFN_SetDebugUtilsObjectTagEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo);
typedef void (VKAPI_PTR *PFN_QueueBeginDebugUtilsLabelEXT_PostCall)(encode::VulkanCaptureManager* manager, VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
typedef void (VKAPI_PTR *PFN_QueueEndDebugUtilsLabelEXT_PostCall)(encode::VulkanCaptureManager* manager, VkQueue queue);
typedef void (VKAPI_PTR *PFN_QueueInsertDebugUtilsLabelEXT_PostCall)(encode::VulkanCaptureManager* manager, VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo);
typedef void (VKAPI_PTR *PFN_CmdBeginDebugUtilsLabelEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
typedef void (VKAPI_PTR *PFN_CmdEndDebugUtilsLabelEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer);
typedef void (VKAPI_PTR *PFN_CmdInsertDebugUtilsLabelEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
typedef VkResult (VKAPI_PTR *PFN_CreateDebugUtilsMessengerEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger);
typedef void (VKAPI_PTR *PFN_DestroyDebugUtilsMessengerEXT_PostCall)(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_SubmitDebugUtilsMessageEXT_PostCall)(encode::VulkanCaptureManager* manager, VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData);
typedef VkResult (VKAPI_PTR *PFN_GetAndroidHardwareBufferPropertiesANDROID_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties);
typedef VkResult (VKAPI_PTR *PFN_GetMemoryAndroidHardwareBufferANDROID_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer);
typedef void (VKAPI_PTR *PFN_CmdSetSampleLocationsEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo);
typedef void (VKAPI_PTR *PFN_GetPhysicalDeviceMultisamplePropertiesEXT_PostCall)(encode::VulkanCaptureManager* manager, VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties);
typedef VkResult (VKAPI_PTR *PFN_GetImageDrmFormatModifierPropertiesEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties);
typedef VkResult (VKAPI_PTR *PFN_CreateValidationCacheEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache);
typedef void (VKAPI_PTR *PFN_DestroyValidationCacheEXT_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_MergeValidationCachesEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches);
typedef VkResult (VKAPI_PTR *PFN_GetValidationCacheDataEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData);
typedef void (VKAPI_PTR *PFN_CmdBindShadingRateImageNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);
typedef void (VKAPI_PTR *PFN_CmdSetViewportShadingRatePaletteNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes);
typedef void (VKAPI_PTR *PFN_CmdSetCoarseSampleOrderNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders);
typedef VkResult (VKAPI_PTR *PFN_CreateAccelerationStructureNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure);
typedef void (VKAPI_PTR *PFN_DestroyAccelerationStructureNV_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_GetAccelerationStructureMemoryRequirementsNV_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements);
typedef VkResult (VKAPI_PTR *PFN_BindAccelerationStructureMemoryNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos);
typedef void (VKAPI_PTR *PFN_CmdBuildAccelerationStructureNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset);
typedef void (VKAPI_PTR *PFN_CmdCopyAccelerationStructureNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode);
typedef void (VKAPI_PTR *PFN_CmdTraceRaysNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth);
typedef VkResult (VKAPI_PTR *PFN_CreateRayTracingPipelinesNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
typedef VkResult (VKAPI_PTR *PFN_GetRayTracingShaderGroupHandlesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);
typedef VkResult (VKAPI_PTR *PFN_GetRayTracingShaderGroupHandlesNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);
typedef VkResult (VKAPI_PTR *PFN_GetAccelerationStructureHandleNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData);
typedef void (VKAPI_PTR *PFN_CmdWriteAccelerationStructuresPropertiesNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);
typedef VkResult (VKAPI_PTR *PFN_CompileDeferredNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t shader);
typedef VkResult (VKAPI_PTR *PFN_GetMemoryHostPointerPropertiesEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties);
typedef void (VKAPI_PTR *PFN_CmdWriteBufferMarkerAMD_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainEXT* pTimeDomains);
typedef VkResult (VKAPI_PTR *PFN_GetCalibratedTimestampsEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksIndirectNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksIndirectCountNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdSetExclusiveScissorEnableNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables);
typedef void (VKAPI_PTR *PFN_CmdSetExclusiveScissorNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors);
typedef void (VKAPI_PTR *PFN_CmdSetCheckpointNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const void* pCheckpointMarker);
typedef void (VKAPI_PTR *PFN_GetQueueCheckpointDataNV_PostCall)(encode::VulkanCaptureManager* manager, VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData);
typedef VkResult (VKAPI_PTR *PFN_InitializePerformanceApiINTEL_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo);
typedef void (VKAPI_PTR *PFN_UninitializePerformanceApiINTEL_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device);
typedef VkResult (VKAPI_PTR *PFN_CmdSetPerformanceMarkerINTEL_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo);
typedef VkResult (VKAPI_PTR *PFN_CmdSetPerformanceStreamMarkerINTEL_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo);
typedef VkResult (VKAPI_PTR *PFN_CmdSetPerformanceOverrideINTEL_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo);
typedef VkResult (VKAPI_PTR *PFN_AcquirePerformanceConfigurationINTEL_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration);
typedef VkResult (VKAPI_PTR *PFN_ReleasePerformanceConfigurationINTEL_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPerformanceConfigurationINTEL configuration);
typedef VkResult (VKAPI_PTR *PFN_QueueSetPerformanceConfigurationINTEL_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkQueue queue, VkPerformanceConfigurationINTEL configuration);
typedef VkResult (VKAPI_PTR *PFN_GetPerformanceParameterINTEL_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue);
typedef void (VKAPI_PTR *PFN_SetLocalDimmingAMD_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable);
typedef VkResult (VKAPI_PTR *PFN_CreateImagePipeSurfaceFUCHSIA_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkResult (VKAPI_PTR *PFN_CreateMetalSurfaceEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkDeviceAddress (VKAPI_PTR *PFN_GetBufferDeviceAddressEXT_PostCall)(encode::VulkanCaptureManager* manager, VkDeviceAddress result, VkDevice device, const VkBufferDeviceAddressInfo* pInfo);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceToolPropertiesEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceSurfacePresentModes2EXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
typedef VkResult (VKAPI_PTR *PFN_AcquireFullScreenExclusiveModeEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain);
typedef VkResult (VKAPI_PTR *PFN_ReleaseFullScreenExclusiveModeEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkSwapchainKHR swapchain);
typedef VkResult (VKAPI_PTR *PFN_GetDeviceGroupSurfacePresentModes2EXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes);
typedef VkResult (VKAPI_PTR *PFN_CreateHeadlessSurfaceEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef void (VKAPI_PTR *PFN_CmdSetLineStippleEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);
typedef void (VKAPI_PTR *PFN_ResetQueryPoolEXT_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
typedef void (VKAPI_PTR *PFN_CmdSetCullModeEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
typedef void (VKAPI_PTR *PFN_CmdSetFrontFaceEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFrontFace frontFace);
typedef void (VKAPI_PTR *PFN_CmdSetPrimitiveTopologyEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
typedef void (VKAPI_PTR *PFN_CmdSetViewportWithCountEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);
typedef void (VKAPI_PTR *PFN_CmdSetScissorWithCountEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);
typedef void (VKAPI_PTR *PFN_CmdBindVertexBuffers2EXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);
typedef void (VKAPI_PTR *PFN_CmdSetDepthTestEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthWriteEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthCompareOpEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBoundsTestEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetStencilTestEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetStencilOpEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
typedef VkResult (VKAPI_PTR *PFN_ReleaseSwapchainImagesEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkReleaseSwapchainImagesInfoEXT* pReleaseInfo);
typedef void (VKAPI_PTR *PFN_GetGeneratedCommandsMemoryRequirementsNV_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements);
typedef void (VKAPI_PTR *PFN_CmdPreprocessGeneratedCommandsNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);
typedef void (VKAPI_PTR *PFN_CmdExecuteGeneratedCommandsNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);
typedef void (VKAPI_PTR *PFN_CmdBindPipelineShaderGroupNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex);
typedef VkResult (VKAPI_PTR *PFN_CreateIndirectCommandsLayoutNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout);
typedef void (VKAPI_PTR *PFN_DestroyIndirectCommandsLayoutNV_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_AcquireDrmDisplayEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display);
typedef VkResult (VKAPI_PTR *PFN_GetDrmDisplayEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display);
typedef VkResult (VKAPI_PTR *PFN_CreatePrivateDataSlotEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot);
typedef void (VKAPI_PTR *PFN_DestroyPrivateDataSlotEXT_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_SetPrivateDataEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);
typedef void (VKAPI_PTR *PFN_GetPrivateDataEXT_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData);
typedef void (VKAPI_PTR *PFN_CmdSetFragmentShadingRateEnumNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);
typedef void (VKAPI_PTR *PFN_GetImageSubresourceLayout2EXT_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkImage image, const VkImageSubresource2EXT* pSubresource, VkSubresourceLayout2EXT* pLayout);
typedef VkResult (VKAPI_PTR *PFN_GetDeviceFaultInfoEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo);
typedef VkResult (VKAPI_PTR *PFN_AcquireWinrtDisplayNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, VkDisplayKHR display);
typedef VkResult (VKAPI_PTR *PFN_GetWinrtDisplayNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay);
typedef VkResult (VKAPI_PTR *PFN_CreateDirectFBSurfaceEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkBool32 (VKAPI_PTR *PFN_GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall)(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb);
typedef void (VKAPI_PTR *PFN_CmdSetVertexInputEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);
typedef VkResult (VKAPI_PTR *PFN_GetMemoryZirconHandleFUCHSIA_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);
typedef VkResult (VKAPI_PTR *PFN_GetMemoryZirconHandlePropertiesFUCHSIA_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties);
typedef VkResult (VKAPI_PTR *PFN_ImportSemaphoreZirconHandleFUCHSIA_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo);
typedef VkResult (VKAPI_PTR *PFN_GetSemaphoreZirconHandleFUCHSIA_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle);
typedef void (VKAPI_PTR *PFN_CmdBindInvocationMaskHUAWEI_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);
typedef VkResult (VKAPI_PTR *PFN_GetMemoryRemoteAddressNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress);
typedef void (VKAPI_PTR *PFN_CmdSetPatchControlPointsEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t patchControlPoints);
typedef void (VKAPI_PTR *PFN_CmdSetRasterizerDiscardEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthBiasEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);
typedef void (VKAPI_PTR *PFN_CmdSetLogicOpEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkLogicOp logicOp);
typedef void (VKAPI_PTR *PFN_CmdSetPrimitiveRestartEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);
typedef VkResult (VKAPI_PTR *PFN_CreateScreenSurfaceQNX_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
typedef VkBool32 (VKAPI_PTR *PFN_GetPhysicalDeviceScreenPresentationSupportQNX_PostCall)(encode::VulkanCaptureManager* manager, VkBool32 result, VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window);
typedef void (VKAPI_PTR *PFN_CmdSetColorWriteEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables);
typedef void (VKAPI_PTR *PFN_CmdDrawMultiEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawMultiIndexedEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset);
typedef VkResult (VKAPI_PTR *PFN_CreateMicromapEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap);
typedef void (VKAPI_PTR *PFN_DestroyMicromapEXT_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CmdBuildMicromapsEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);
typedef VkResult (VKAPI_PTR *PFN_BuildMicromapsEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);
typedef VkResult (VKAPI_PTR *PFN_CopyMicromapEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo);
typedef VkResult (VKAPI_PTR *PFN_CopyMicromapToMemoryEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo);
typedef VkResult (VKAPI_PTR *PFN_CopyMemoryToMicromapEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo);
typedef VkResult (VKAPI_PTR *PFN_WriteMicromapsPropertiesEXT_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, size_t dataSize, void* pData, size_t stride);
typedef void (VKAPI_PTR *PFN_CmdCopyMicromapEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyMicromapToMemoryEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyMemoryToMicromapEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo);
typedef void (VKAPI_PTR *PFN_CmdWriteMicromapsPropertiesEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);
typedef void (VKAPI_PTR *PFN_GetDeviceMicromapCompatibilityEXT_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility);
typedef void (VKAPI_PTR *PFN_GetMicromapBuildSizesEXT_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT* pBuildInfo, VkMicromapBuildSizesInfoEXT* pSizeInfo);
typedef void (VKAPI_PTR *PFN_CmdDrawClusterHUAWEI_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_CmdDrawClusterIndirectHUAWEI_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
typedef void (VKAPI_PTR *PFN_SetDeviceMemoryPriorityEXT_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDeviceMemory memory, float priority);
typedef void (VKAPI_PTR *PFN_GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping);
typedef void (VKAPI_PTR *PFN_GetDescriptorSetHostMappingVALVE_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkDescriptorSet descriptorSet, void** ppData);
typedef void (VKAPI_PTR *PFN_CmdSetTessellationDomainOriginEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin);
typedef void (VKAPI_PTR *PFN_CmdSetDepthClampEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthClampEnable);
typedef void (VKAPI_PTR *PFN_CmdSetPolygonModeEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkPolygonMode polygonMode);
typedef void (VKAPI_PTR *PFN_CmdSetRasterizationSamplesEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples);
typedef void (VKAPI_PTR *PFN_CmdSetSampleMaskEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples, const VkSampleMask* pSampleMask);
typedef void (VKAPI_PTR *PFN_CmdSetAlphaToCoverageEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable);
typedef void (VKAPI_PTR *PFN_CmdSetAlphaToOneEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable);
typedef void (VKAPI_PTR *PFN_CmdSetLogicOpEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 logicOpEnable);
typedef void (VKAPI_PTR *PFN_CmdSetColorBlendEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables);
typedef void (VKAPI_PTR *PFN_CmdSetColorBlendEquationEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations);
typedef void (VKAPI_PTR *PFN_CmdSetColorWriteMaskEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks);
typedef void (VKAPI_PTR *PFN_CmdSetRasterizationStreamEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t rasterizationStream);
typedef void (VKAPI_PTR *PFN_CmdSetConservativeRasterizationModeEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode);
typedef void (VKAPI_PTR *PFN_CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize);
typedef void (VKAPI_PTR *PFN_CmdSetDepthClipEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 depthClipEnable);
typedef void (VKAPI_PTR *PFN_CmdSetSampleLocationsEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable);
typedef void (VKAPI_PTR *PFN_CmdSetColorBlendAdvancedEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced);
typedef void (VKAPI_PTR *PFN_CmdSetProvokingVertexModeEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode);
typedef void (VKAPI_PTR *PFN_CmdSetLineRasterizationModeEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode);
typedef void (VKAPI_PTR *PFN_CmdSetLineStippleEnableEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable);
typedef void (VKAPI_PTR *PFN_CmdSetDepthClipNegativeOneToOneEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne);
typedef void (VKAPI_PTR *PFN_CmdSetViewportWScalingEnableNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable);
typedef void (VKAPI_PTR *PFN_CmdSetViewportSwizzleNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageToColorEnableNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageToColorLocationNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageModulationModeNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageModulationTableEnableNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageModulationTableNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable);
typedef void (VKAPI_PTR *PFN_CmdSetShadingRateImageEnableNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable);
typedef void (VKAPI_PTR *PFN_CmdSetRepresentativeFragmentTestEnableNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable);
typedef void (VKAPI_PTR *PFN_CmdSetCoverageReductionModeNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode);
typedef void (VKAPI_PTR *PFN_GetShaderModuleIdentifierEXT_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier);
typedef void (VKAPI_PTR *PFN_GetShaderModuleCreateInfoIdentifierEXT_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier);
typedef VkResult (VKAPI_PTR *PFN_GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties);
typedef VkResult (VKAPI_PTR *PFN_CreateOpticalFlowSessionNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession);
typedef void (VKAPI_PTR *PFN_DestroyOpticalFlowSessionNV_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator);
typedef VkResult (VKAPI_PTR *PFN_BindOpticalFlowSessionImageNV_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout);
typedef void (VKAPI_PTR *PFN_CmdOpticalFlowExecuteNV_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo);
typedef VkResult (VKAPI_PTR *PFN_GetFramebufferTilePropertiesQCOM_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties);
typedef VkResult (VKAPI_PTR *PFN_GetDynamicRenderingTilePropertiesQCOM_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties);
typedef VkResult (VKAPI_PTR *PFN_CreateAccelerationStructureKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure);
typedef void (VKAPI_PTR *PFN_DestroyAccelerationStructureKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator);
typedef void (VKAPI_PTR *PFN_CmdBuildAccelerationStructuresKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);
typedef void (VKAPI_PTR *PFN_CmdBuildAccelerationStructuresIndirectKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts);
typedef VkResult (VKAPI_PTR *PFN_CopyAccelerationStructureToMemoryKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);
typedef VkResult (VKAPI_PTR *PFN_CopyMemoryToAccelerationStructureKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);
typedef VkResult (VKAPI_PTR *PFN_WriteAccelerationStructuresPropertiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride);
typedef void (VKAPI_PTR *PFN_CmdCopyAccelerationStructureKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyAccelerationStructureToMemoryKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_CmdCopyMemoryToAccelerationStructureKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);
typedef VkDeviceAddress (VKAPI_PTR *PFN_GetAccelerationStructureDeviceAddressKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDeviceAddress result, VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo);
typedef void (VKAPI_PTR *PFN_CmdWriteAccelerationStructuresPropertiesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);
typedef void (VKAPI_PTR *PFN_GetDeviceAccelerationStructureCompatibilityKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility);
typedef void (VKAPI_PTR *PFN_GetAccelerationStructureBuildSizesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo);
typedef void (VKAPI_PTR *PFN_CmdTraceRaysKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth);
typedef VkResult (VKAPI_PTR *PFN_CreateRayTracingPipelinesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
typedef VkResult (VKAPI_PTR *PFN_GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall)(encode::VulkanCaptureManager* manager, VkResult result, VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData);
typedef void (VKAPI_PTR *PFN_CmdTraceRaysIndirectKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress);
typedef VkDeviceSize (VKAPI_PTR *PFN_GetRayTracingShaderGroupStackSizeKHR_PostCall)(encode::VulkanCaptureManager* manager, VkDeviceSize result, VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader);
typedef void (VKAPI_PTR *PFN_CmdSetRayTracingPipelineStackSizeKHR_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t pipelineStackSize);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksIndirectEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
typedef void (VKAPI_PTR *PFN_CmdDrawMeshTasksIndirectCountEXT_PostCall)(encode::VulkanCaptureManager* manager, VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
