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

#ifndef GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_CLIENT_OBJECT_INFO_H
#define GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_CLIENT_OBJECT_INFO_H

// #include "decode/vulkan_frame_inspector_client_indirect_commands.h"
#include "format/format.h"
#include "vulkan/vulkan.h"

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <unordered_map>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct FIVulkanObjectInfo
{
    FIVulkanObjectInfo(format::HandleId parent_id, format::HandleId id) : parent_id(parent_id), id(id) {}

    virtual ~FIVulkanObjectInfo() = default;

    format::HandleId parent_id{ format::kNullHandleId };
    format::HandleId id{ format::kNullHandleId };
};

struct FIVulkanPoolInfo : public FIVulkanObjectInfo
{
    FIVulkanPoolInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    std::unordered_set<format::HandleId> child_ids;
};

struct FIVulkanPoolObjectInfo : public FIVulkanObjectInfo
{
    FIVulkanPoolObjectInfo(format::HandleId parent_id, format::HandleId pool_id, format::HandleId id) :
        FIVulkanObjectInfo(parent_id, id), pool_id(pool_id)
    {}

    format::HandleId pool_id{ format::kNullHandleId };
};

struct FIInstanceInfo : public FIVulkanObjectInfo
{
    FIInstanceInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        struct
        {
            std::string application_name;
            uint32_t    application_version = 0;
            std::string engine_name;
            uint32_t    engine_version = 0;
            uint32_t    api_version    = 0;
        } application_info;

        std::vector<std::string> enabled_layer_names;
        std::vector<std::string> enabled_extension_names;
    } create_info;
};

struct FIPhysicalDeviceInfo : public FIVulkanObjectInfo
{
    FIPhysicalDeviceInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}
};

struct FIDeviceQueueCreateInfo
{
    VkDeviceQueueCreateFlags flags;
    uint32_t                 queue_family_index;
    uint32_t                 queue_count;
    std::vector<float>       queue_priorities;
};

struct FIDeviceInfo : public FIVulkanObjectInfo
{
    FIDeviceInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        VkDeviceCreateFlags                  flags;
        std::vector<FIDeviceQueueCreateInfo> queue_create_infos;
        std::vector<std::string>             enabled_layer_names;
        std::vector<std::string>             enabled_extension_names;
        VkPhysicalDeviceFeatures             enabled_features;
    } create_info;
};

struct FICommandPoolInfo : public FIVulkanPoolInfo
{
    FICommandPoolInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanPoolInfo(parent_id, id) {}

    struct
    {
        VkCommandPoolCreateFlags flags;
        uint32_t                 queue_family_index;
    } create_info;
};

struct FISubpassDescription
{
    VkSubpassDescriptionFlags          flags;
    VkPipelineBindPoint                pipeline_bind_point;
    std::vector<VkAttachmentReference> input_attachments;
    std::vector<VkAttachmentReference> color_attachments;
    std::vector<VkAttachmentReference> resolve_attachments;
    std::vector<VkAttachmentReference> depth_stencil_attachment;
    std::vector<uint32_t>              p_preserve_attachments;
};

struct FIRenderPassInfo : public FIVulkanObjectInfo
{
    FIRenderPassInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        std::vector<VkAttachmentDescription> attachments;
        std::vector<FISubpassDescription>    subpasses;
        std::vector<VkSubpassDependency>     dependencies;
    } create_info;
};

struct FIDeviceMemoryInfo : public FIVulkanObjectInfo
{
    FIDeviceMemoryInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        VkDeviceSize allocation_size;
        uint32_t     memory_type_index;
    } create_info;
};

struct FIBufferInfo : public FIVulkanObjectInfo
{
    FIBufferInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        VkBufferCreateFlags   flags;
        VkDeviceSize          size;
        VkBufferUsageFlags    usage;
        VkSharingMode         sharing_mode;
        std::vector<uint32_t> queue_family_indices;
    } create_info;

    struct
    {
        const FIDeviceMemoryInfo* bound_memory = nullptr;
        VkDeviceSize              offset       = 0;
    } bound_memory_info;
};

struct FIBufferViewInfo : public FIVulkanObjectInfo
{
    FIBufferViewInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        VkBufferViewCreateFlags flags;
        FIBufferInfo*           buffer;
        VkFormat                format;
        VkDeviceSize            offset;
        VkDeviceSize            range;
    } create_info;
};

struct FIImageInfo : public FIVulkanObjectInfo
{
    FIImageInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        VkImageCreateFlags    flags;
        VkImageType           image_type;
        VkFormat              format;
        VkExtent3D            extent;
        uint32_t              mip_levels;
        uint32_t              array_layers;
        VkSampleCountFlagBits samples;
        VkImageTiling         tiling;
        VkImageUsageFlags     usage;
        VkSharingMode         sharing_mode;
        std::vector<uint32_t> queue_family_indices;
        VkImageLayout         initial_layout;
    } create_info;

    struct
    {
        const FIDeviceMemoryInfo* bound_memory = nullptr;
        VkDeviceSize              offset       = 0;
    } bound_memory_info;
};

struct FIImageViewInfo : public FIVulkanObjectInfo
{
    FIImageViewInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        VkImageViewCreateFlags  flags;
        FIImageInfo*            image;
        VkImageViewType         view_type;
        VkFormat                format;
        VkComponentMapping      components;
        VkImageSubresourceRange subresource_range;
    } create_info;
};

struct FIFramebufferInfo : public FIVulkanObjectInfo
{
    FIFramebufferInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        VkFramebufferCreateFlags      flags;
        FIRenderPassInfo*             render_pass;
        std::vector<FIImageViewInfo*> attachments;
        uint32_t                      width;
        uint32_t                      height;
        uint32_t                      layers;
    } create_info;
};

enum CommandBufferState
{
    kInitial,
    kRecording,
    kExecutable,
    kPending,
    kInvalid
};

struct FIDescriptorPoolInfo : public FIVulkanPoolInfo
{
    FIDescriptorPoolInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanPoolInfo(parent_id, id) {}

    struct
    {
        VkDescriptorPoolCreateFlags       flags;
        uint32_t                          max_sets;
        std::vector<VkDescriptorPoolSize> pool_sizes;
    } create_info;
};

struct FISamplerInfo : public FIVulkanObjectInfo
{
    FISamplerInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        VkSamplerCreateFlags flags;
        VkFilter             mag_filter;
        VkFilter             min_filter;
        VkSamplerMipmapMode  mipmap_mode;
        VkSamplerAddressMode address_mode_u;
        VkSamplerAddressMode address_mode_v;
        VkSamplerAddressMode address_mode_w;
        float                mip_lod_bias;
        VkBool32             anisotropy_enable;
        float                max_anisotropy;
        VkBool32             compare_enable;
        VkCompareOp          compare_op;
        float                min_lod;
        float                max_lod;
        VkBorderColor        border_color;
        VkBool32             unnormalized_coordinates;
    } create_info;
};

struct FIShaderModuleInfo : public FIVulkanObjectInfo
{
    FIShaderModuleInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        VkShaderModuleCreateFlags flags;
        std::vector<uint32_t>     code;
    } create_info;
};

struct descriptor_set_layout_binding
{
    uint32_t                    binding;
    VkDescriptorType            descriptor_type;
    uint32_t                    descriptor_count;
    VkShaderStageFlags          stage_flags;
    std::vector<FISamplerInfo*> immutable_samplers;
};

struct FIDescriptorSetLayoutInfo : public FIVulkanObjectInfo
{
    FIDescriptorSetLayoutInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        VkDescriptorSetLayoutCreateFlags           flags;
        std::vector<descriptor_set_layout_binding> bindings;
    } create_info;
};

struct FIDescriptorBufferInfo
{
    FIBufferInfo* buffer;
    VkDeviceSize  offset;
    VkDeviceSize  range;
};

struct FIDescriptorImageInfo
{
    FISamplerInfo*   sampler;
    FIImageViewInfo* image_view;
    VkImageLayout    image_layout;
};

static const char* desc_type_to_str(VkDescriptorType type)
{
    switch (type)
    {
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_SAMPLER)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_STORAGE_IMAGE)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_STORAGE_BUFFER)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM)
        GFXR_CASE_TO_STR(VK_DESCRIPTOR_TYPE_MUTABLE_EXT)
        default:
            assert(0);
            return "XXX";
    };
}

struct FIDescriptorSetBinding
{
    VkDescriptorType descriptor_type;

    struct binding_info
    {
        FIDescriptorImageInfo  image_info;
        FIDescriptorBufferInfo buffer_info;
        FIBufferViewInfo*      texel_buffer_view;
    };

    std::vector<binding_info> binding;
};

struct FIDescriptorSetInfo : public FIVulkanPoolObjectInfo
{
    FIDescriptorSetInfo(format::HandleId parent_id, format::HandleId pool_id, format::HandleId id) :
        FIVulkanPoolObjectInfo(parent_id, pool_id, id)
    {}

    struct
    {
        std::vector<FIDescriptorSetLayoutInfo*> pSetLayouts;
    } create_info;

    std::unordered_map<uint32_t, FIDescriptorSetBinding> bindings;
};

struct FIPipelineLayoutInfo : public FIVulkanObjectInfo
{
    FIPipelineLayoutInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        VkPipelineLayoutCreateFlags             flags;
        std::vector<FIDescriptorSetLayoutInfo*> set_layouts;
        std::vector<VkPushConstantRange>        push_constant_ranges;
    } create_info;
};

struct FIPipelineShaderStageInfo
{
    VkPipelineShaderStageCreateFlags flags;
    VkShaderStageFlagBits            stage;
    FIShaderModuleInfo*              module;
    std::string                      pName;
};

struct FIPipelineVertexInputInfo
{
    VkPipelineVertexInputStateCreateFlags          flags;
    std::vector<VkVertexInputBindingDescription>   vertex_binding_description;
    std::vector<VkVertexInputAttributeDescription> vertex_attribute_description;
};

struct FIPipelineInputAssemblyInfo
{
    VkPipelineInputAssemblyStateCreateFlags flags;
    VkPrimitiveTopology                     topology;
    VkBool32                                primitive_restart_enable;
};

struct FIPipelineViewportStateInfo
{
    VkPipelineViewportStateCreateFlags flags;
    std::vector<VkViewport>            viewports;
    std::vector<VkRect2D>              scissors;
};

struct FIPipelineRasterizationStateInfo
{
    VkPipelineRasterizationStateCreateFlags flags;
    VkBool32                                depth_clamp_enable;
    VkBool32                                rasterizer_discard_enable;
    VkPolygonMode                           polygon_mode;
    VkCullModeFlags                         cull_mode;
    VkFrontFace                             front_face;
    VkBool32                                depth_bias_enable;
    float                                   depth_bias_constant_factor;
    float                                   depth_bias_clamp;
    float                                   depth_bias_slope_factor;
    float                                   line_width;
};

struct FIPipelineInfo : public FIVulkanObjectInfo
{
    FIPipelineInfo(format::HandleId parent_id, format::HandleId id) : FIVulkanObjectInfo(parent_id, id) {}

    struct
    {
        std::map<VkShaderStageFlagBits, FIPipelineShaderStageInfo> stages;
        FIPipelineVertexInputInfo                                  vertex_input;
        FIPipelineInputAssemblyInfo                                input_assembly;
        FIPipelineViewportStateInfo                                viewport_state;
        FIPipelineRasterizationStateInfo                           rasterization_state;

        FIPipelineLayoutInfo* layout;
        FIRenderPassInfo*     renderPass;
    } create_info;
};

struct VulkanCommandInfo;

struct FIBoundVertexBufferInfo
{
    FIBufferInfo* buffer;
    VkDeviceSize  offset;
};

struct FIBoundIndexBufferInfo
{
    FIBufferInfo* buffer_info;
    VkDeviceSize  offset;
    VkIndexType   indexType;
};

using FIBoundVertexBuffersInfo = std::unordered_map<uint32_t, FIBoundVertexBufferInfo>;

struct FICommandBufferInfo : public FIVulkanPoolObjectInfo
{
    FICommandBufferInfo(format::HandleId parent_id, format::HandleId pool_id, format::HandleId id) :
        FIVulkanPoolObjectInfo(parent_id, pool_id, id)
    {}

    using vk_cmd_ptr_t   = std::shared_ptr<VulkanCommandInfo>;
    using command_list_t = std::vector<vk_cmd_ptr_t>;

    command_list_t       command_list;

    FIRenderPassInfo*                                  active_renderpass;
    FIFramebufferInfo*                                 active_framebuffer;
    FIPipelineInfo*                                    active_pipeline;
    std::unordered_map<uint32_t, FIDescriptorSetInfo*> active_descriptor_sets;

    FIBoundVertexBuffersInfo bound_vertex_buffers;
    FIBoundIndexBufferInfo   bound_index_buffer;

    struct
    {
    } create_info;

    void EmplaceCommand(vk_cmd_ptr_t command) { command_list.emplace_back(std::move(command)); }

    void Reset()
    {
        command_list.clear();
        active_descriptor_sets.clear();

        active_renderpass  = nullptr;
        active_framebuffer = nullptr;
        active_pipeline    = nullptr;
    }
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_DECODE_VULKAN_FRAME_INSPECTOR_CLIENT_OBJECT_INFO_H */
