/*
** Copyright (c) 2019-2022 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_VULKAN_OBJECT_INFO_H
#define GFXRECON_DECODE_VULKAN_OBJECT_INFO_H

#include "decode/vulkan_resource_allocator.h"
#include "decode/vulkan_resource_initializer.h"
#include "decode/window.h"
#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/vulkan_device_util.h"
#include "graphics/vulkan_shader_group_handle.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vulkan/vulkan_core.h"

#include <cstdint>
#include <memory>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <future>
#include <optional>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

//
// Enumerations defining index values for tables to track array counts reported by Vulkan API calls with variable length
// array parameters.
//
enum InstanceArrayIndices : uint32_t
{
    kInstanceArrayEnumeratePhysicalDevices      = 0,
    kInstanceArrayEnumeratePhysicalDeviceGroups = 1,
    // Aliases for extensions functions that were promoted to core.
    kInstanceArrayEnumeratePhysicalDeviceGroupsKHR = kInstanceArrayEnumeratePhysicalDeviceGroups
};

enum PhysicalDeviceArrayIndices : uint32_t
{
    kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties                          = 0,
    kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties                    = 1,
    kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2                         = 2,
    kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2                   = 3,
    kPhysicalDeviceArrayGetPhysicalDeviceDisplayPropertiesKHR                           = 4,
    kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlanePropertiesKHR                      = 5,
    kPhysicalDeviceArrayGetDisplayPlaneSupportedDisplaysKHR                             = 6,
    kPhysicalDeviceArrayGetPhysicalDeviceSurfaceFormats2KHR                             = 7,
    kPhysicalDeviceArrayGetPhysicalDeviceDisplayProperties2KHR                          = 8,
    kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlaneProperties2KHR                     = 9,
    kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsEXT                    = 10,
    kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesNV                  = 11,
    kPhysicalDeviceArrayGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = 12,
    kPhysicalDeviceArrayGetPhysicalDeviceSurfacePresentModes2EXT                        = 13,
    kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR   = 14,
    kPhysicalDeviceArrayGetPhysicalDeviceToolProperties                                 = 15,
    kPhysicalDeviceArrayGetPhysicalDeviceFragmentShadingRatesKHR                        = 16,
    kFramebufferArrayGetFramebufferTilePropertiesQCOM                                   = 17,
    kPhysicalDeviceArrayGetPhysicalDeviceOpticalFlowImageFormatsNV                      = 18,
    kPhysicalDeviceArrayGetPhysicalDeviceVideoFormatPropertiesKHR                       = 19,
    kVideoSessionKHRArrayGetVideoSessionMemoryRequirementsKHR                           = 20,
    kShaderEXTArrayGetShaderBinaryDataEXT                                               = 21,

    // Aliases for extensions functions that were promoted to core.
    kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2KHR =
        kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2,
    kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2KHR =
        kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2,
    kPhysicalDeviceArrayGetPhysicalDeviceToolPropertiesEXT = kPhysicalDeviceArrayGetPhysicalDeviceToolProperties,
};

enum DeviceArrayIndices : uint32_t
{
    kDeviceArrayGetImageSparseMemoryRequirements2                       = 0,
    kDeviceArrayGetPipelineExecutablePropertiesKHR                      = 1,
    kDeviceArrayGetPipelineExecutableStatisticsKHR                      = 2,
    kDeviceArrayGetPipelineExecutableInternalRepresentationsKHR         = 3,
    kDeviceArrayGetDeviceImageSparseMemoryRequirements                  = 4,
    kDeviceArrayGetEncodedVideoSessionParametersKHR                     = 5,
    kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesKHR = 6,
    kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsKHR    = 7,

    // Aliases for extensions functions that were promoted to core.
    kDeviceArrayGetImageSparseMemoryRequirements2KHR      = kDeviceArrayGetImageSparseMemoryRequirements2,
    kDeviceArrayGetDeviceImageSparseMemoryRequirementsKHR = kDeviceArrayGetDeviceImageSparseMemoryRequirements
};

enum QueueArrayIndices : uint32_t
{
    kQueueArrayGetQueueCheckpointDataNV  = 0,
    kQueueArrayGetQueueCheckpointData2NV = 1
};

enum ImageArrayIndices : uint32_t
{
    kImageArrayGetImageSparseMemoryRequirements = 0
};

enum PipelineCacheArrayIndices : uint32_t
{
    kPipelineCacheArrayGetPipelineCacheData = 0
};

enum PipelineArrayIndices : uint32_t
{
    kPipelineArrayGetShaderInfoAMD = 0
};

enum DisplayKHRArrayIndices : uint32_t
{
    kDisplayKHRArrayGetDisplayModePropertiesKHR  = 0,
    kDisplayKHRArrayGetDisplayModeProperties2KHR = 1
};

enum SurfaceKHRArrayIndices : uint32_t
{
    kSurfaceKHRArrayGetPhysicalDeviceSurfaceFormatsKHR      = 0,
    kSurfaceKHRArrayGetPhysicalDeviceSurfacePresentModesKHR = 1,
    kSurfaceKHRArrayGetPhysicalDevicePresentRectanglesKHR   = 2
};

enum SwapchainKHRArrayIndices : uint32_t
{
    kSwapchainKHRArrayGetSwapchainImagesKHR           = 0,
    kSwapchainKHRArrayGetPastPresentationTimingGOOGLE = 1
};

enum ValidationCacheEXTArrayIndices : uint32_t
{
    kValidationCacheEXTArrayGetValidationCacheDataEXT = 0
};

//
// Structures for storing Vulkan object info.
//

struct ReplayDeviceInfo
{
    std::optional<VkPhysicalDeviceProperties>       properties;
    std::optional<VkPhysicalDeviceMemoryProperties> memory_properties;

    // extensions
    std::optional<VkPhysicalDeviceRayTracingPipelinePropertiesKHR> raytracing_properties;
};

template <typename T>
struct VulkanObjectInfo
{
    typedef T HandleType;

    VulkanObjectInfo(VkObjectType type) : vk_object_type(type) {}

    VkObjectType vk_object_type;

    // Standard info stored for all Vulkan objects.
    HandleType       handle{ VK_NULL_HANDLE };            // Handle created for the object during replay.
    format::HandleId capture_id{ format::kNullHandleId }; // ID assigned to the object at capture.
    format::HandleId parent_id{ format::kNullHandleId };  // ID of the object's parent instance/device object.
};

template <typename T>
struct handle_create_result_t
{
    VkResult       result = VK_INCOMPLETE;
    std::vector<T> handles;
};

template <typename T>
struct VulkanObjectInfoAsync : public VulkanObjectInfo<T>
{
    VulkanObjectInfoAsync(VkObjectType type) : VulkanObjectInfo<T>(type) {}

    // track asynchronous compilation status
    std::shared_future<handle_create_result_t<T>> future;
    uint32_t                                      future_handle_index = 0;
};

// Info for a pool object which other objects will be allocated from.
template <typename T>
struct VulkanPoolInfo : public VulkanObjectInfo<T>
{
    VulkanPoolInfo(VkObjectType type) : VulkanObjectInfo<T>(type) {}

    std::unordered_set<format::HandleId> child_ids; // IDs of objects allocated from the pool.
};

// Info for objects that are allocated from pools.
template <typename T>
struct VulkanPoolObjectInfo : public VulkanObjectInfo<T>
{
    VulkanPoolObjectInfo(VkObjectType type) : VulkanObjectInfo<T>(type) {}

    format::HandleId pool_id{ format::kNullHandleId }; // ID of the pool that the object was allocated from.
};

//
// Declarations for Vulkan objects without additional replay state info.
//

struct EventInfo : public VulkanObjectInfo<VkEvent>
{
    EventInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_EVENT) {}
};

struct QueryPoolInfo : public VulkanObjectInfo<VkQueryPool>
{
    QueryPoolInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_QUERY_POOL) {}
};

struct PipelineLayoutInfo : public VulkanObjectInfo<VkPipelineLayout>
{
    PipelineLayoutInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_PIPELINE_LAYOUT) {}
};

struct PrivateDataSlotInfo : public VulkanObjectInfo<VkPrivateDataSlot>
{
    PrivateDataSlotInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_PRIVATE_DATA_SLOT) {}
};

struct SamplerInfo : public VulkanObjectInfo<VkSampler>
{
    SamplerInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_SAMPLER) {}
};

struct CommandPoolInfo : public VulkanPoolInfo<VkCommandPool>
{
    CommandPoolInfo() : VulkanPoolInfo(VK_OBJECT_TYPE_COMMAND_POOL) {}
};

struct SamplerYcbcrConversionInfo : public VulkanObjectInfo<VkSamplerYcbcrConversion>
{
    SamplerYcbcrConversionInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION) {}
};

struct DisplayModeKHRInfo : public VulkanObjectInfo<VkDisplayModeKHR>
{
    DisplayModeKHRInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_DISPLAY_MODE_KHR) {}
};

struct DebugReportCallbackEXTInfo : public VulkanObjectInfo<VkDebugReportCallbackEXT>
{
    DebugReportCallbackEXTInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT) {}
};

struct IndirectCommandsLayoutNVInfo : public VulkanObjectInfo<VkIndirectCommandsLayoutNV>
{
    IndirectCommandsLayoutNVInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV) {}
};

struct DebugUtilsMessengerEXTInfo : public VulkanObjectInfo<VkDebugUtilsMessengerEXT>
{
    DebugUtilsMessengerEXTInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT) {}
};

struct AccelerationStructureKHRInfo : public VulkanObjectInfo<VkAccelerationStructureKHR>
{
    AccelerationStructureKHRInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR) {}
};

struct AccelerationStructureNVInfo : public VulkanObjectInfo<VkAccelerationStructureNV>
{
    AccelerationStructureNVInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV) {}
};

struct PerformanceConfigurationINTELInfo : public VulkanObjectInfo<VkPerformanceConfigurationINTEL>
{
    PerformanceConfigurationINTELInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL) {}
};

struct MicromapEXTInfo : public VulkanObjectInfo<VkMicromapEXT>
{
    MicromapEXTInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_MICROMAP_EXT) {}
};

struct OpticalFlowSessionNVInfo : public VulkanObjectInfo<VkOpticalFlowSessionNV>
{
    OpticalFlowSessionNVInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV) {}
};

struct VideoSessionParametersKHRInfo : public VulkanObjectInfo<VkVideoSessionParametersKHR>
{
    VideoSessionParametersKHRInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR) {}
};

//
// Declarations for Vulkan objects with additional replay state info.
//

struct InstanceInfo : public VulkanObjectInfo<VkInstance>
{
    InstanceInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_INSTANCE) {}

    uint32_t                             api_version{ VK_MAKE_VERSION(1, 0, 0) };
    std::vector<std::string>             enabled_extensions;
    std::unordered_map<uint32_t, size_t> array_counts;

    // Capture and replay devices sorted in the order that they were originally retrieved from
    // vkEnumeratePhysicalDevices.
    std::vector<format::HandleId> capture_devices;
    std::vector<VkPhysicalDevice> replay_devices;

    std::unordered_map<VkPhysicalDevice, ReplayDeviceInfo> replay_device_info;
};

struct PhysicalDeviceInfo : public VulkanObjectInfo<VkPhysicalDevice>
{
    PhysicalDeviceInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_PHYSICAL_DEVICE) {}

    VkInstance                           parent{ VK_NULL_HANDLE };
    uint32_t                             parent_api_version{ 0 };
    std::vector<std::string>             parent_enabled_extensions;
    std::unordered_map<uint32_t, size_t> array_counts;

    // Capture device properties.
    uint32_t                         capture_api_version{ 0 };
    uint32_t                         capture_driver_version{ 0 };
    uint32_t                         capture_vendor_id{ 0 };
    uint32_t                         capture_device_id{ 0 };
    VkPhysicalDeviceType             capture_device_type{ VK_PHYSICAL_DEVICE_TYPE_OTHER };
    uint8_t                          capture_pipeline_cache_uuid[format::kUuidSize]{};
    std::string                      capture_device_name;
    VkPhysicalDeviceMemoryProperties capture_memory_properties{};

    // capture raytracing shader-binding-table properties
    // extracted from VkPhysicalDeviceRayTracingPipelinePropertiesKHR
    uint32_t shaderGroupHandleSize      = 0;
    uint32_t shaderGroupBaseAlignment   = 0;
    uint32_t shaderGroupHandleAlignment = 0;

    // Closest matching replay device.
    ReplayDeviceInfo* replay_device_info{ nullptr };
};

struct DeviceInfo : public VulkanObjectInfo<VkDevice>
{
    DeviceInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_DEVICE) {}

    VkPhysicalDevice                         parent{ VK_NULL_HANDLE };
    std::unique_ptr<VulkanResourceAllocator> allocator;
    std::unordered_map<uint32_t, size_t>     array_counts;

    std::unordered_map<format::HandleId, uint64_t> opaque_addresses;

    // Map pipeline ID to ray tracing shader group handle capture replay data.
    std::unordered_map<format::HandleId, const std::vector<uint8_t>> shader_group_handles;

    // The following values are only used when loading the initial state for trimmed files.
    std::vector<std::string>                   extensions;
    std::unique_ptr<VulkanResourceInitializer> resource_initializer;

    // Physical device property & feature state at device creation
    graphics::VulkanDevicePropertyFeatureInfo property_feature_info;

    std::unordered_map<uint32_t, VkDeviceQueueCreateFlags> queue_family_creation_flags;
    std::vector<bool>                                      queue_family_index_enabled;

    std::vector<VkPhysicalDevice> replay_device_group;
};

struct QueueInfo : public VulkanObjectInfo<VkQueue>
{
    QueueInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_QUEUE) {}

    std::unordered_map<uint32_t, size_t> array_counts;
    uint32_t                             family_index;
    uint32_t                             queue_index;
};

struct SemaphoreInfo : public VulkanObjectInfo<VkSemaphore>
{
    SemaphoreInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_SEMAPHORE) {}

    bool is_external{ false };

    // If a null-swapchain/surface interacts with a semaphore, replay needs to shadow signal it until a future call
    // waits on it.
    bool shadow_signaled{ false };
    // Fences can be reset, semaphores can't, so replay needs to know when a semaphore will not be submitted for a wait
    // operation to prevent validation errors around queue forward progress.
    bool forward_progress{ true };
    // If a semaphore is signaled with vkAcquireNextImage and also VkSubmitInfo, then the semaphore needs to be shadow
    // signaled with vkAcquireNextImage and regularly signaled with VkSubmitInfo
    bool signaled{ false };
};

struct FenceInfo : public VulkanObjectInfo<VkFence>
{
    FenceInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_FENCE) {}

    // If a null-swapchain/surface interacts with a fence, replay needs to to shadow signal it until a future call waits
    // on it.
    bool shadow_signaled{ false };
};

struct DeviceMemoryInfo : public VulkanObjectInfo<VkDeviceMemory>
{
    DeviceMemoryInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_DEVICE_MEMORY) {}

    VulkanResourceAllocator*            allocator{ nullptr };
    VulkanResourceAllocator::MemoryData allocator_data{ 0 };
};

struct BufferInfo : public VulkanObjectInfo<VkBuffer>
{
    BufferInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_BUFFER) {}

    // The following values are only used for memory portability.
    VulkanResourceAllocator::ResourceData allocator_data{ 0 };

    // This is only used when loading the initial state for trimmed files.
    VkMemoryPropertyFlags memory_property_flags{ 0 };

    VkBufferUsageFlags usage{ 0 };
    VkDeviceSize       size{ 0 };
    uint32_t           queue_family_index{ 0 };
};

struct BufferViewInfo : public VulkanObjectInfo<VkBufferView>
{
    BufferViewInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_BUFFER_VIEW) {}

    format::HandleId buffer_id{ format::kNullHandleId };
};

struct ImageInfo : public VulkanObjectInfo<VkImage>
{
    ImageInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_IMAGE) {}

    std::unordered_map<uint32_t, size_t> array_counts;

    bool is_swapchain_image{ false };

    // The following values are only used for memory portability.
    VulkanResourceAllocator::ResourceData allocator_data{ 0 };

    VkDeviceMemory                      memory{ VK_NULL_HANDLE };
    VulkanResourceAllocator::MemoryData memory_allocator_data{ 0 };

    // This is only used when loading the initial state for trimmed files.
    VkMemoryPropertyFlags memory_property_flags{ 0 };

    VkImageUsageFlags     usage{ 0 };
    VkImageType           type{};
    VkFormat              format{};
    VkExtent3D            extent{ 0, 0, 0 };
    VkImageTiling         tiling{};
    VkSampleCountFlagBits sample_count{};
    VkImageLayout         initial_layout{};
    uint32_t              layer_count{ 0 };
    uint32_t              level_count{ 0 };
    uint32_t              queue_family_index{ 0 };

    VkImageLayout current_layout{ VK_IMAGE_LAYOUT_UNDEFINED };
    VkImageLayout intermediate_layout{ VK_IMAGE_LAYOUT_UNDEFINED };
};

typedef struct PipelineCacheData
{
    std::vector<uint8_t> capture_cache_data;
    std::vector<uint8_t> replay_cache_data;
} PipelineCacheData;

struct PipelineCacheInfo : public VulkanObjectInfo<VkPipelineCache>
{
    PipelineCacheInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_PIPELINE_CACHE) {}

    std::unordered_map<uint32_t, size_t> array_counts;

    // hash id of capture time pipeline cache data to capture and replay time pipeline cache data map;
    std::unordered_map<uint32_t, std::vector<PipelineCacheData>> pipeline_cache_data;

    // cache was created using VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT flag.
    bool requires_external_synchronization = false;
};

struct ShaderModuleInfo : public VulkanObjectInfo<VkShaderModule>
{
    // All information stored in ShaderModuleInfo is populated and used
    // by the dump resources feature
    struct ShaderDescriptorInfo
    {
        ShaderDescriptorInfo(VkDescriptorType type, bool readonly, uint32_t accessed, uint32_t count, bool is_array) :
            type(type), readonly(readonly), accessed(accessed), count(count), is_array(is_array)
        {}

        ShaderDescriptorInfo(const ShaderDescriptorInfo& other) :
            type(other.type), readonly(other.readonly), accessed(other.accessed), count(other.count),
            is_array(other.is_array)
        {}

        VkDescriptorType type;
        bool             readonly;
        uint32_t         accessed;
        uint32_t         count;
        bool             is_array;
    };

    ShaderModuleInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_SHADER_MODULE) {}
    ShaderModuleInfo(const ShaderModuleInfo& other) : VulkanObjectInfo(VK_OBJECT_TYPE_SHADER_MODULE)
    {
        handle                = other.handle;
        parent_id             = other.parent_id;
        capture_id            = other.capture_id;
        used_descriptors_info = other.used_descriptors_info;
    }

    // One entry per descriptor binding
    using ShaderDescriptorSetInfo = std::map<uint32_t, ShaderDescriptorInfo>;

    // One entry per descriptor set
    using ShaderDescriptorSetsInfos = std::map<uint32_t, ShaderDescriptorSetInfo>;

    ShaderDescriptorSetsInfos used_descriptors_info;
};

struct PipelineInfo : public VulkanObjectInfoAsync<VkPipeline>
{
    PipelineInfo() : VulkanObjectInfoAsync(VK_OBJECT_TYPE_PIPELINE) {}

    std::unordered_map<uint32_t, size_t> array_counts;

    // The following information is populated and used only when the
    // dump resources feature is in use
    std::unordered_map<VkShaderStageFlagBits, ShaderModuleInfo> shaders;

    struct InputBindingDescription
    {
        uint32_t          stride;
        VkVertexInputRate inputRate;
    };

    struct InputAttributeDescription
    {
        uint32_t binding;
        VkFormat format;
        uint32_t offset;
    };

    // One entry per binding
    using VertexInputBindingMap = std::unordered_map<uint32_t, InputBindingDescription>;
    VertexInputBindingMap vertex_input_binding_map;

    // One entry per location
    using VertexInputAttributeMap = std::unordered_map<uint32_t, InputAttributeDescription>;
    VertexInputAttributeMap vertex_input_attribute_map;

    // Is VK_DYNAMIC_STATE_VERTEX_INPUT_EXT enabled
    bool dynamic_vertex_input{ false };

    // Is VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE_EXT enabled
    bool dynamic_vertex_binding_stride{ false };

    // map capture- to replay-time shader-group-handles
    std::unordered_map<graphics::shader_group_handle_t, graphics::shader_group_handle_t> shader_group_handle_map;
};

struct DescriptorPoolInfo : public VulkanPoolInfo<VkDescriptorPool>
{
    DescriptorPoolInfo() : VulkanPoolInfo(VK_OBJECT_TYPE_DESCRIPTOR_POOL) {}

    VkDescriptorPoolCreateFlags       flags{};
    uint32_t                          max_sets{ 0 };
    uint32_t                          max_inline_uniform_block_bindings{ 0 }; // For VK_EXT_inline_uniform_block.
    std::vector<VkDescriptorPoolSize> pool_sizes;
    std::vector<VkDescriptorPool>     retired_pools;
};

struct DescriptorUpdateTemplateInfo : public VulkanObjectInfo<VkDescriptorUpdateTemplate>
{
    DescriptorUpdateTemplateInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE) {}

    std::vector<VkDescriptorType>                descriptor_image_types;
    std::vector<VkDescriptorUpdateTemplateEntry> entries;
};

struct DisplayKHRInfo : public VulkanObjectInfo<VkDisplayKHR>
{
    DisplayKHRInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_DISPLAY_KHR) {}

    std::unordered_map<uint32_t, size_t> array_counts;
};

struct SurfaceKHRInfo : public VulkanObjectInfo<VkSurfaceKHR>
{
    SurfaceKHRInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_SURFACE_KHR) {}

    Window*                              window{ nullptr };
    std::unordered_map<uint32_t, size_t> array_counts;
    bool                                 surface_creation_skipped{ false };

    std::unordered_map<VkPhysicalDevice, VkSurfaceCapabilitiesKHR> surface_capabilities;
};

struct SwapchainKHRInfo : public VulkanObjectInfo<VkSwapchainKHR>
{
    SwapchainKHRInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_SWAPCHAIN_KHR) {}

    VkSurfaceKHR         surface{ VK_NULL_HANDLE };
    format::HandleId     surface_id{ format::kNullHandleId };
    DeviceInfo*          device_info{ nullptr };
    uint32_t             width{ 0 };
    uint32_t             height{ 0 };
    VkFormat             format{ VK_FORMAT_UNDEFINED };
    std::vector<VkImage> images; // This image could be virtual or real according to if it uses VirtualSwapchain.
    std::unordered_map<uint32_t, size_t> array_counts;

    // The acquired_indices value and the remapping performed with it.
    struct AcquiredData
    {
        uint32_t index = { 0 };
        bool     acquired{ false };
    };
    std::vector<AcquiredData> acquired_indices;

    // The following values are only used when loading the initial state for trimmed files.
    std::vector<uint32_t> queue_family_indices{ 0 };

    // For virtual swapchain, we want the compression on virtual images to be the same as on the true swapchain
    std::vector<VkImageCompressionFixedRateFlagsEXT> compression_fixed_rate_flags;
    std::shared_ptr<VkImageCompressionControlEXT>    compression_control;

    // When replay is restricted to a specific surface, a dummy swapchain is created for the omitted surfaces, requiring
    // backing images.
    uint32_t                  replay_image_count{ 0 };
    std::vector<ImageInfo>    image_infos;
    VkSwapchainCreateFlagsKHR image_flags{ 0 };
    VkFormat                  image_format{ VK_FORMAT_UNDEFINED };
    uint32_t                  image_array_layers{ 0 };
    VkImageUsageFlags         image_usage{ 0 };
    VkSharingMode             image_sharing_mode{ VK_SHARING_MODE_EXCLUSIVE };
};

struct ValidationCacheEXTInfo : public VulkanObjectInfo<VkValidationCacheEXT>
{
    ValidationCacheEXTInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_VALIDATION_CACHE_EXT) {}

    std::unordered_map<uint32_t, size_t> array_counts;
};

struct ImageViewInfo : public VulkanObjectInfo<VkImageView>
{
    ImageViewInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_IMAGE_VIEW) {}

    format::HandleId image_id{ format::kNullHandleId };
};

struct FramebufferInfo : public VulkanObjectInfo<VkFramebuffer>
{
    FramebufferInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_FRAMEBUFFER) {}

    VkFramebufferCreateFlags             framebuffer_flags{ 0 };
    std::unordered_map<uint32_t, size_t> array_counts;
    std::vector<format::HandleId>        attachment_image_view_ids;
};

struct DeferredOperationKHRInfo : public VulkanObjectInfo<VkDeferredOperationKHR>
{
    DeferredOperationKHRInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR) {}

    bool pending_state{ false };

    // Record CreateRayTracingPipelinesKHR parameters for safety.
    std::vector<VkRayTracingPipelineCreateInfoKHR>                 record_modified_create_infos;
    std::vector<std::vector<VkRayTracingShaderGroupCreateInfoKHR>> record_modified_pgroups;
    std::vector<VkPipeline>                                        replayPipelines;
    std::vector<format::HandleId>                                  capturePipelines;
};

struct VideoSessionKHRInfo : VulkanObjectInfo<VkVideoSessionKHR>
{
    VideoSessionKHRInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_VIDEO_SESSION_KHR) {}

    std::unordered_map<uint32_t, size_t> array_counts;

    // The following values are only used for memory portability.
    std::vector<VulkanResourceAllocator::ResourceData> allocator_datas;

    // This is only used when loading the initial state for trimmed files.
    std::vector<VkMemoryPropertyFlags> memory_property_flags;

    uint32_t queue_family_index{ 0 };
};

struct ShaderEXTInfo : VulkanObjectInfoAsync<VkShaderEXT>
{
    ShaderEXTInfo() : VulkanObjectInfoAsync(VK_OBJECT_TYPE_SHADER_EXT) {}

    std::unordered_map<uint32_t, size_t> array_counts;
};

struct CommandBufferInfo : public VulkanPoolObjectInfo<VkCommandBuffer>
{
    CommandBufferInfo() : VulkanPoolObjectInfo(VK_OBJECT_TYPE_COMMAND_BUFFER) {}

    bool                                                is_frame_boundary{ false };
    std::vector<format::HandleId>                       frame_buffer_ids;
    std::unordered_map<format::HandleId, VkImageLayout> image_layout_barriers;
};

struct RenderPassInfo : public VulkanObjectInfo<VkRenderPass>
{
    RenderPassInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_RENDER_PASS) {}

    std::vector<VkImageLayout>           attachment_description_final_layouts;
    std::vector<VkAttachmentDescription> attachment_descs;

    struct SubpassReferences
    {
        VkSubpassDescriptionFlags          flags;
        VkPipelineBindPoint                pipeline_bind_point;
        std::vector<VkAttachmentReference> input_att_refs;
        std::vector<VkAttachmentReference> color_att_refs;
        std::vector<VkAttachmentReference> resolve_att_refs;
        std::vector<uint32_t>              preserve_att_refs;

        bool                  has_depth;
        VkAttachmentReference depth_att_ref;
    };

    // The attachment references per subpass
    std::vector<SubpassReferences> subpass_refs;

    std::vector<VkSubpassDependency> dependencies;
};

struct DescriptorSetLayoutInfo : public VulkanObjectInfo<VkDescriptorSetLayout>
{
    DescriptorSetLayoutInfo() : VulkanObjectInfo(VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT) {}

    struct DescriptorBindingLayout
    {
        VkDescriptorType type;
        uint32_t         binding;
        uint32_t         count;
    };

    std::vector<DescriptorBindingLayout> bindings_layout;
};

struct DescriptorTypeImageInfo
{
    const ImageViewInfo* image_view_info;
    VkImageLayout        image_layout;
};

struct DescriptorTypeBufferInfo
{
    const BufferInfo* buffer_info;
    VkDeviceSize      offset;
    VkDeviceSize      range;
};

struct DescriptorSetBindingInfo
{
    VkDescriptorType                      desc_type{ VK_DESCRIPTOR_TYPE_MAX_ENUM };
    std::vector<DescriptorTypeImageInfo>  image_info;
    std::vector<DescriptorTypeBufferInfo> buffer_info;
    std::vector<const BufferViewInfo*>    texel_buffer_view_info;
    std::vector<uint8_t>                  inline_uniform_block;
};

struct DescriptorSetInfo : public VulkanPoolObjectInfo<VkDescriptorSet>
{
    DescriptorSetInfo() : VulkanPoolObjectInfo(VK_OBJECT_TYPE_DESCRIPTOR_SET) {}

    // One entry per binding
    using DescriptorBindingsInfo = std::unordered_map<uint32_t, DescriptorSetBindingInfo>;
    DescriptorBindingsInfo descriptors;
};

//
// Handle alias types for extension handle types that have been promoted to core types.
//

typedef SamplerYcbcrConversionInfo   SamplerYcbcrConversionKHRInfo;
typedef DescriptorUpdateTemplateInfo DescriptorUpdateTemplateKHRInfo;
typedef PrivateDataSlotInfo          PrivateDataSlotEXTInfo;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_OBJECT_INFO_H
