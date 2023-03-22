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

#include "decode/vulkan_frame_inspector_consumer_client_base.h"
#include "decode/vulkan_frame_inspector_client_vulkan_commands_info.h"
#include "decode/vulkan_frame_inspector_client_object_info.h"
#include "decode/vulkan_frame_inspector_client_indirect_commands.h"
#include "format/format_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateInstance(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*                    pInstance)

{
    if (returnValue == VK_SUCCESS)
    {
        std::unique_ptr<FIInstanceInfo> instance_info =
            std::make_unique<FIInstanceInfo>(format::kNullHandleId, *pInstance->GetPointer());

        auto replay_create_info = pCreateInfo->GetPointer();
        if (replay_create_info)
        {
            if (replay_create_info->pApplicationInfo)
            {
                instance_info->create_info.application_info.application_name =
                    replay_create_info->pApplicationInfo->pApplicationName;

                instance_info->create_info.application_info.application_version =
                    replay_create_info->pApplicationInfo->applicationVersion;

                instance_info->create_info.application_info.api_version =
                    replay_create_info->pApplicationInfo->apiVersion;

                instance_info->create_info.application_info.engine_version =
                    replay_create_info->pApplicationInfo->engineVersion;

                instance_info->create_info.application_info.engine_name =
                    replay_create_info->pApplicationInfo->pEngineName;
            }

            for (uint32_t i = 0; i < replay_create_info->enabledExtensionCount; ++i)
            {
                instance_info->create_info.enabled_extension_names.emplace_back(
                    replay_create_info->ppEnabledExtensionNames[i]);
            }

            for (uint32_t i = 0; i < replay_create_info->enabledLayerCount; ++i)
            {
                instance_info->create_info.enabled_layer_names.emplace_back(replay_create_info->ppEnabledLayerNames[i]);
            }
        }

        object_table_.AddObject(std::move(instance_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyInstance(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(instance);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkEnumeratePhysicalDevices(
    const ApiCallInfo&                      call_info,
    VkResult                                returnValue,
    format::HandleId                        instance,
    PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices)
{
    if (pPhysicalDevices->GetPointer() && (returnValue == VK_SUCCESS || returnValue == VK_INCOMPLETE))
    {
        FIInstanceInfo* instance_info = dynamic_cast<FIInstanceInfo*>(object_table_.GetObject(instance));
        assert(instance_info);

        uint32_t                count        = *pPhysicalDeviceCount->GetPointer();
        const format::HandleId* phys_dev_ids = pPhysicalDevices->GetPointer();
        for (uint32_t i = 0; i < count; ++i)
        {
            std::unique_ptr<FIPhysicalDeviceInfo> phys_dev_info =
                std::make_unique<FIPhysicalDeviceInfo>(instance_info->id, phys_dev_ids[i]);

            object_table_.AddObject(std::move(phys_dev_info));
        }
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateDevice(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*                      pDevice)
{
    if (returnValue == VK_SUCCESS)
    {
        FIPhysicalDeviceInfo* phys_dev_info =
            dynamic_cast<FIPhysicalDeviceInfo*>(object_table_.GetObject(physicalDevice));
        assert(phys_dev_info);

        std::unique_ptr<FIDeviceInfo> device_info =
            std::make_unique<FIDeviceInfo>(phys_dev_info->id, *pDevice->GetPointer());

        const auto ci = pCreateInfo->GetPointer();

        for (uint32_t i = 0; i < ci->enabledExtensionCount; ++i)
        {
            device_info->create_info.enabled_extension_names.push_back(ci->ppEnabledExtensionNames[i]);
        }

        for (uint32_t i = 0; i < ci->enabledLayerCount; ++i)
        {
            device_info->create_info.enabled_layer_names.push_back(ci->ppEnabledLayerNames[i]);
        }

        if (ci->pEnabledFeatures)
        {
            device_info->create_info.enabled_features = *ci->pEnabledFeatures;
        }
        else
        {
            memset(&device_info->create_info.enabled_features, 0, sizeof(device_info->create_info.enabled_features));
        }

        for (uint32_t i = 0; i < ci->queueCreateInfoCount; ++i)
        {
            const std::vector<float> priorities(ci->pQueueCreateInfos[i].pQueuePriorities,
                                                ci->pQueueCreateInfos[i].pQueuePriorities + ci->queueCreateInfoCount);

            FIDeviceQueueCreateInfo qci{ ci->pQueueCreateInfos[i].flags,
                                         ci->pQueueCreateInfos[i].queueFamilyIndex,
                                         ci->pQueueCreateInfos[i].queueCount,
                                         std::move(priorities) };

            device_info->create_info.queue_create_infos.push_back(std::move(qci));
        }

        object_table_.AddObject(std::move(device_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyDevice(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(device);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateRenderPass(
    const ApiCallInfo&                                    call_info,
    VkResult                                              returnValue,
    format::HandleId                                      device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
    HandlePointerDecoder<VkRenderPass>*                   pRenderPass)
{
    if (returnValue == VK_SUCCESS)
    {
        std::unique_ptr<FIRenderPassInfo> renderpass_info =
            std::make_unique<FIRenderPassInfo>(device, *pRenderPass->GetPointer());

        const auto ci = pCreateInfo->GetMetaStructPointer();

        std::vector<VkAttachmentDescription> attachments(ci->decoded_value->attachmentCount);
        for (uint32_t i = 0; i < ci->decoded_value->attachmentCount; ++i)
        {
            attachments[i] = ci->decoded_value->pAttachments[i];
        }

        std::vector<FISubpassDescription> subpass_descriptions(ci->decoded_value->subpassCount);
        std::vector<VkSubpassDependency>  subpass_dependency(ci->decoded_value->subpassCount);
        for (uint32_t i = 0; i < ci->decoded_value->subpassCount; ++i)
        {}

        object_table_.AddObject(std::move(renderpass_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyRenderPass(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(renderPass);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateFramebuffer(
    const ApiCallInfo&                                     call_info,
    VkResult                                               returnValue,
    format::HandleId                                       device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
    HandlePointerDecoder<VkFramebuffer>*                   pFramebuffer)
{
    if (returnValue == VK_SUCCESS)
    {
        std::unique_ptr<FIFramebufferInfo> renderpass_info =
            std::make_unique<FIFramebufferInfo>(device, *pFramebuffer->GetPointer());

        const auto                    ci = pCreateInfo->GetMetaStructPointer();
        std::vector<FIImageViewInfo*> attamchments(ci->decoded_value->attachmentCount);

        const format::HandleId* img_view_ids = ci->pAttachments.GetPointer();
        for (uint32_t i = 0; i < ci->decoded_value->attachmentCount; ++i)
        {
            FIImageViewInfo* img_view = dynamic_cast<FIImageViewInfo*>(object_table_.GetObject(img_view_ids[i]));
            if (img_view)
            {
                renderpass_info->create_info.attachments.push_back(img_view);
            }
        }

        renderpass_info->create_info.flags  = ci->decoded_value->flags;
        renderpass_info->create_info.height = ci->decoded_value->height;
        renderpass_info->create_info.width  = ci->decoded_value->width;
        renderpass_info->create_info.layers = ci->decoded_value->layers;
        renderpass_info->create_info.render_pass =
            dynamic_cast<FIRenderPassInfo*>(object_table_.GetObject(ci->renderPass));

        object_table_.AddObject(std::move(renderpass_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(framebuffer);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                                             call_info,
    VkResult                                                       returnValue,
    format::HandleId                                               device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*           pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>*                   pSetLayout)
{
    if (returnValue == VK_SUCCESS)
    {
        std::unique_ptr<FIDescriptorSetLayoutInfo> desc_set_layout_info =
            std::make_unique<FIDescriptorSetLayoutInfo>(device, *pSetLayout->GetPointer());

        const auto ci           = pCreateInfo->GetMetaStructPointer();
        const auto desc_binding = ci->pBindings->GetMetaStructPointer();
        for (uint32_t i = 0; i < ci->decoded_value->bindingCount; ++i)
        {
            const VkDescriptorSetLayoutBinding* binding = desc_binding[i].decoded_value;
            if (binding->pImmutableSamplers)
            {
                std::vector<FISamplerInfo*> immutable_samplers(binding->descriptorCount);
                for (uint32_t s = 0; s < binding->descriptorCount; ++s)
                {
                    immutable_samplers[s] = dynamic_cast<FISamplerInfo*>(
                        object_table_.GetObject(desc_binding->pImmutableSamplers.GetPointer()[s]));
                }

                desc_set_layout_info->create_info.bindings.emplace_back(
                    descriptor_set_layout_binding{ binding->binding,
                                                   binding->descriptorType,
                                                   binding->descriptorCount,
                                                   binding->stageFlags,
                                                   std::move(immutable_samplers) });
            }
            else
            {
                desc_set_layout_info->create_info.bindings.emplace_back(descriptor_set_layout_binding{
                    binding->binding, binding->descriptorType, binding->descriptorCount, binding->stageFlags, {} });
            }

            desc_set_layout_info->create_info.flags = ci->decoded_value->flags;
        }

        object_table_.AddObject(std::move(desc_set_layout_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(descriptorSetLayout);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                                        call_info,
    VkResult                                                  returnValue,
    format::HandleId                                          device,
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*                   pDescriptorPool)
{
    if (returnValue == VK_SUCCESS)
    {
        std::unique_ptr<FIDescriptorPoolInfo> desc_pool_info =
            std::make_unique<FIDescriptorPoolInfo>(device, *pDescriptorPool->GetPointer());

        const auto ci = pCreateInfo->GetMetaStructPointer();

        object_table_.AddPool(std::move(desc_pool_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*                     pDescriptorSets)
{
    if (returnValue == VK_SUCCESS)
    {
        const auto* ai    = pAllocateInfo->GetPointer();
        const auto* ai_ms = pAllocateInfo->GetMetaStructPointer();

        for (uint32_t i = 0; i < ai->descriptorSetCount; ++i)
        {
            std::unique_ptr<FIDescriptorSetInfo> desc_set =
                std::make_unique<FIDescriptorSetInfo>(device, ai_ms->descriptorPool, pDescriptorSets->GetPointer()[i]);

            object_table_.AddPoolObject(ai_ms->descriptorPool, std::move(desc_set));
        }
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkFreeDescriptorSets(
    const ApiCallInfo&                     call_info,
    VkResult                               returnValue,
    format::HandleId                       device,
    format::HandleId                       descriptorPool,
    uint32_t                               descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets)
{
    FIDescriptorPoolInfo* pool_info = dynamic_cast<FIDescriptorPoolInfo*>(object_table_.GetPool(descriptorPool));
    assert(pool_info);

    const format::HandleId* desc_set_ids = pDescriptorSets->GetPointer();
    for (uint32_t i = 0; i < descriptorSetCount; ++i)
    {
        objects_pending_for_deletion_.pool_object.push_back(std::make_pair(pool_info->id, desc_set_ids[i]));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkResetDescriptorPool(const ApiCallInfo&         call_info,
                                                                           VkResult                   returnValue,
                                                                           format::HandleId           device,
                                                                           format::HandleId           descriptorPool,
                                                                           VkDescriptorPoolResetFlags flags)
{
    FIDescriptorPoolInfo* pool_info = dynamic_cast<FIDescriptorPoolInfo*>(object_table_.GetPool(descriptorPool));
    assert(pool_info);

    for (auto desc_set_id : pool_info->child_ids)
    {
        objects_pending_for_deletion_.pool_object.push_back(std::make_pair(descriptorPool, desc_set_id));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.pools.push_back(descriptorPool);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                                  call_info,
    format::HandleId                                    device,
    uint32_t                                            descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                            descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies)
{
    const Decoded_VkWriteDescriptorSet* desc_writes = pDescriptorWrites->GetMetaStructPointer();

    for (uint32_t i = 0; i < descriptorWriteCount; ++i)
    {
        FIDescriptorSetInfo* set = dynamic_cast<FIDescriptorSetInfo*>(object_table_.GetObject(desc_writes[i].dstSet));
        assert(set);

        const VkWriteDescriptorSet* write = desc_writes[i].decoded_value;
        assert(write);

        switch (write->descriptorType)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            {
                const Decoded_VkDescriptorImageInfo* decoded_img_info =
                    desc_writes[i].pImageInfo->GetMetaStructPointer();

                FIDescriptorSetBinding binding;
                binding.descriptor_type = write->descriptorType;
                binding.binding.emplace_back(FIDescriptorSetBinding::binding_info{
                    { dynamic_cast<FISamplerInfo*>(object_table_.GetObject(decoded_img_info->sampler)),
                      dynamic_cast<FIImageViewInfo*>(object_table_.GetObject(decoded_img_info->imageView)),
                      decoded_img_info->decoded_value->imageLayout },
                    {},
                    {} });

                set->bindings[write->dstBinding] = std::move(binding);
            }
            break;

            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            {
                const Decoded_VkDescriptorBufferInfo* decoded_buf_info =
                    desc_writes[i].pBufferInfo->GetMetaStructPointer();

                FIDescriptorSetBinding binding;
                binding.descriptor_type = write->descriptorType;
                binding.binding.emplace_back(FIDescriptorSetBinding::binding_info{
                    {},
                    { dynamic_cast<FIBufferInfo*>(object_table_.GetObject(decoded_buf_info->buffer)),
                      decoded_buf_info->decoded_value->offset,
                      decoded_buf_info->decoded_value->range },
                    {} });

                set->bindings[write->dstBinding] = std::move(binding);
            }
            break;

            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                assert(0);
                break;

            default:
                assert(0);
                break;
        };
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                                        call_info,
    VkResult                                                  returnValue,
    format::HandleId                                          device,
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkPipelineLayout>*                   pPipelineLayout)
{
    if (returnValue == VK_SUCCESS)
    {
        std::unique_ptr<FIPipelineLayoutInfo> pipeline_layout_info =
            std::make_unique<FIPipelineLayoutInfo>(device, *pPipelineLayout->GetPointer());

        const auto ci = pCreateInfo->GetMetaStructPointer();

        for (uint32_t i = 0; i < ci->decoded_value->setLayoutCount; ++i)
        {
            FIDescriptorSetLayoutInfo* desc_set_layout =
                dynamic_cast<FIDescriptorSetLayoutInfo*>(object_table_.GetObject(ci->pSetLayouts.GetPointer()[i]));
            assert(desc_set_layout);

            pipeline_layout_info->create_info.set_layouts.push_back(desc_set_layout);
        }

        for (uint32_t i = 0; i < ci->decoded_value->pushConstantRangeCount; ++i)
        {
            pipeline_layout_info->create_info.push_constant_ranges.push_back(ci->decoded_value->pPushConstantRanges[i]);
        }

        pipeline_layout_info->create_info.flags = ci->decoded_value->flags;

        object_table_.AddObject(std::move(pipeline_layout_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateShaderModule(
    const ApiCallInfo&                                      call_info,
    VkResult                                                returnValue,
    format::HandleId                                        device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
    HandlePointerDecoder<VkShaderModule>*                   pShaderModule)
{
    if (returnValue == VK_SUCCESS)
    {
        std::unique_ptr<FIShaderModuleInfo> shader_info =
            std::make_unique<FIShaderModuleInfo>(device, *pShaderModule->GetPointer());

        const auto ci = pCreateInfo->GetMetaStructPointer();

        shader_info->create_info.code.resize(ci->decoded_value->codeSize / sizeof(uint32_t));
        util::platform::MemoryCopy(shader_info->create_info.code.data(),
                                   ci->decoded_value->codeSize,
                                   ci->decoded_value->pCode,
                                   ci->decoded_value->codeSize);

        shader_info->create_info.flags = ci->decoded_value->flags;

        object_table_.AddObject(std::move(shader_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyShaderModule(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(shaderModule);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(pipelineLayout);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateSampler(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkSamplerCreateInfo>*   pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSampler>*                     pSampler)
{
    if (returnValue == VK_SUCCESS)
    {
        std::unique_ptr<FISamplerInfo> sampler_info = std::make_unique<FISamplerInfo>(device, *pSampler->GetPointer());

        const VkSamplerCreateInfo* ci                      = pCreateInfo->GetMetaStructPointer()->decoded_value;
        sampler_info->create_info.flags                    = ci->flags;
        sampler_info->create_info.mag_filter               = ci->magFilter;
        sampler_info->create_info.min_filter               = ci->minFilter;
        sampler_info->create_info.mipmap_mode              = ci->mipmapMode;
        sampler_info->create_info.address_mode_u           = ci->addressModeU;
        sampler_info->create_info.address_mode_v           = ci->addressModeV;
        sampler_info->create_info.address_mode_w           = ci->addressModeW;
        sampler_info->create_info.mip_lod_bias             = ci->mipLodBias;
        sampler_info->create_info.anisotropy_enable        = ci->anisotropyEnable;
        sampler_info->create_info.max_anisotropy           = ci->maxAnisotropy;
        sampler_info->create_info.compare_enable           = ci->compareEnable;
        sampler_info->create_info.compare_op               = ci->compareOp;
        sampler_info->create_info.min_lod                  = ci->minLod;
        sampler_info->create_info.max_lod                  = ci->maxLod;
        sampler_info->create_info.border_color             = ci->borderColor;
        sampler_info->create_info.unnormalized_coordinates = ci->unnormalizedCoordinates;

        object_table_.AddObject(std::move(sampler_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroySampler(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(sampler);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateBuffer(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*                      pBuffer)
{
    if (returnValue == VK_SUCCESS)
    {
        std::unique_ptr<FIBufferInfo> buffer_info = std::make_unique<FIBufferInfo>(device, *pBuffer->GetPointer());

        const Decoded_VkBufferCreateInfo* ci = pCreateInfo->GetMetaStructPointer();

        buffer_info->create_info.flags        = ci->decoded_value->flags;
        buffer_info->create_info.size         = ci->decoded_value->size;
        buffer_info->create_info.sharing_mode = ci->decoded_value->sharingMode;
        buffer_info->create_info.usage        = ci->decoded_value->usage;

        if (!ci->pQueueFamilyIndices.IsNull())
        {
            const uint32_t* indices = ci->pQueueFamilyIndices.GetPointer();
            for (uint32_t i = 0; i < ci->decoded_value->queueFamilyIndexCount; ++i)
            {
                buffer_info->create_info.queue_family_indices.push_back(indices[i]);
            }
        }

        object_table_.AddObject(std::move(buffer_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyBuffer(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(buffer);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateBufferView(
    const ApiCallInfo&                                    call_info,
    VkResult                                              returnValue,
    format::HandleId                                      device,
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
    HandlePointerDecoder<VkBufferView>*                   pView)
{
    if (returnValue == VK_SUCCESS)
    {
        std::unique_ptr<FIBufferViewInfo> view_info = std::make_unique<FIBufferViewInfo>(device, *pView->GetPointer());

        const Decoded_VkBufferViewCreateInfo* ci = pCreateInfo->GetMetaStructPointer();

        FIBufferInfo* buffer = dynamic_cast<FIBufferInfo*>(object_table_.GetObject(ci->buffer));
        assert(buffer);

        view_info->create_info.buffer = buffer;
        view_info->create_info.flags  = ci->decoded_value->flags;
        view_info->create_info.format = ci->decoded_value->format;
        view_info->create_info.offset = ci->decoded_value->offset;
        view_info->create_info.range  = ci->decoded_value->range;

        object_table_.AddObject(std::move(view_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyBufferView(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(bufferView);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateImage(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>*     pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*                       pImage)
{
    if (returnValue == VK_SUCCESS)
    {
        std::unique_ptr<FIImageInfo> image_info = std::make_unique<FIImageInfo>(device, *pImage->GetPointer());

        const Decoded_VkImageCreateInfo* ci = pCreateInfo->GetMetaStructPointer();

        image_info->create_info.flags          = ci->decoded_value->flags;
        image_info->create_info.image_type     = ci->decoded_value->imageType;
        image_info->create_info.format         = ci->decoded_value->format;
        image_info->create_info.extent         = ci->decoded_value->extent;
        image_info->create_info.mip_levels     = ci->decoded_value->mipLevels;
        image_info->create_info.array_layers   = ci->decoded_value->arrayLayers;
        image_info->create_info.samples        = ci->decoded_value->samples;
        image_info->create_info.tiling         = ci->decoded_value->tiling;
        image_info->create_info.usage          = ci->decoded_value->usage;
        image_info->create_info.sharing_mode   = ci->decoded_value->sharingMode;
        image_info->create_info.initial_layout = ci->decoded_value->initialLayout;

        if (!ci->pQueueFamilyIndices.IsNull())
        {
            const uint32_t* indices = ci->pQueueFamilyIndices.GetPointer();
            for (uint32_t i = 0; i < ci->decoded_value->queueFamilyIndexCount; ++i)
            {
                image_info->create_info.queue_family_indices.push_back(indices[i]);
            }
        }

        object_table_.AddObject(std::move(image_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyImage(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(image);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateImageView(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImageView>*                   pView)
{
    const Decoded_VkImageViewCreateInfo* ci = pCreateInfo->GetMetaStructPointer();
    if (!object_table_.GetObject(ci->image))
    {
        return;
    }

    std::unique_ptr<FIImageViewInfo> view_info = std::make_unique<FIImageViewInfo>(device, *pView->GetPointer());

    view_info->create_info.flags     = ci->decoded_value->flags;
    view_info->create_info.view_type = ci->decoded_value->viewType;
    view_info->create_info.format    = ci->decoded_value->format;

    FIImageInfo* image_info = dynamic_cast<FIImageInfo*>(object_table_.GetObject(ci->image));
    assert(image_info);
    view_info->create_info.image = image_info;

    if (ci->components->decoded_value)
    {
        view_info->create_info.components = *ci->components->decoded_value;
    }

    if (ci->subresourceRange)
    {
        view_info->create_info.subresource_range = *ci->subresourceRange->decoded_value;
    }

    object_table_.AddObject(std::move(view_info));
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyImageView(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(imageView);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateGraphicsPipelines(
    const ApiCallInfo&                                          call_info,
    VkResult                                                    returnValue,
    format::HandleId                                            device,
    format::HandleId                                            pipelineCache,
    uint32_t                                                    createInfoCount,
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
    HandlePointerDecoder<VkPipeline>*                           pPipelines)
{
    if (returnValue == VK_SUCCESS)
    {
        for (uint32_t i = 0; i < createInfoCount; ++i)
        {
            std::unique_ptr<FIPipelineInfo> pipeline_info =
                std::make_unique<FIPipelineInfo>(device, *pPipelines->GetPointer());

            const auto ci = pCreateInfos->GetMetaStructPointer();

            // Shader stages
            for (uint32_t i = 0; i < ci->decoded_value->stageCount; ++i)
            {
                FIShaderModuleInfo* shader_info = dynamic_cast<FIShaderModuleInfo*>(
                    object_table_.GetObject(ci->pStages->GetMetaStructPointer()->module));
                pipeline_info->create_info.stages.emplace(
                    ci->decoded_value->pStages[i].stage,
                    FIPipelineShaderStageInfo{ ci->decoded_value->pStages[i].flags,
                                               ci->decoded_value->pStages[i].stage,
                                               shader_info,
                                               ci->decoded_value->pStages[i].pName });
            }

            // Vertex input
            if (!ci->pVertexInputState->GetMetaStructPointer()->pVertexAttributeDescriptions->IsNull())
            {
                const VkVertexInputAttributeDescription* va_ci =
                    ci->pVertexInputState->GetMetaStructPointer()
                        ->pVertexAttributeDescriptions->GetMetaStructPointer()
                        ->decoded_value;

                for (uint32_t i = 0; i < ci->decoded_value->pVertexInputState->vertexAttributeDescriptionCount; ++i)
                {
                    pipeline_info->create_info.vertex_input.vertex_attribute_description.emplace_back(va_ci[i]);
                }

                for (uint32_t i = 0; i < ci->decoded_value->pVertexInputState->vertexBindingDescriptionCount; ++i)
                {
                    pipeline_info->create_info.vertex_input.vertex_binding_description.emplace_back(
                        ci->decoded_value->pVertexInputState->pVertexBindingDescriptions[i]);
                }
            }

            // Viewport
            if (!ci->pViewportState->GetMetaStructPointer()->pViewports->IsNull())
            {
                const VkViewport* viewports =
                    ci->pViewportState->GetMetaStructPointer()->pViewports->GetMetaStructPointer()->decoded_value;

                for (uint32_t i = 0; i < ci->decoded_value->pViewportState->viewportCount; ++i)
                {
                    pipeline_info->create_info.viewport_state.viewports.push_back(viewports[i]);
                }
            }

            if (!ci->pViewportState->GetMetaStructPointer()->pScissors->IsNull())
            {
                const VkRect2D* scissors =
                    ci->pViewportState->GetMetaStructPointer()->pScissors->GetMetaStructPointer()->decoded_value;

                for (uint32_t i = 0; i < ci->decoded_value->pViewportState->scissorCount; ++i)
                {
                    pipeline_info->create_info.viewport_state.scissors.push_back(scissors[i]);
                }
            }

            // Input assembly
            if (ci->decoded_value->pInputAssemblyState)
            {
                pipeline_info->create_info.input_assembly.flags = ci->decoded_value->pInputAssemblyState->flags;
                pipeline_info->create_info.input_assembly.primitive_restart_enable =
                    ci->decoded_value->pInputAssemblyState->primitiveRestartEnable;
                pipeline_info->create_info.input_assembly.topology = ci->decoded_value->pInputAssemblyState->topology;
            }

            // Rasterization state
            if (ci->decoded_value->pRasterizationState)
            {
                pipeline_info->create_info.rasterization_state.flags = ci->decoded_value->pRasterizationState->flags;
                pipeline_info->create_info.rasterization_state.depth_clamp_enable =
                    ci->decoded_value->pRasterizationState->depthClampEnable;
                pipeline_info->create_info.rasterization_state.rasterizer_discard_enable =
                    ci->decoded_value->pRasterizationState->rasterizerDiscardEnable;
                pipeline_info->create_info.rasterization_state.polygon_mode =
                    ci->decoded_value->pRasterizationState->polygonMode;
                pipeline_info->create_info.rasterization_state.cull_mode =
                    ci->decoded_value->pRasterizationState->cullMode;
                pipeline_info->create_info.rasterization_state.front_face =
                    ci->decoded_value->pRasterizationState->frontFace;
                pipeline_info->create_info.rasterization_state.depth_bias_enable =
                    ci->decoded_value->pRasterizationState->depthBiasEnable;
                pipeline_info->create_info.rasterization_state.depth_bias_constant_factor =
                    ci->decoded_value->pRasterizationState->depthBiasConstantFactor;
                pipeline_info->create_info.rasterization_state.depth_bias_clamp =
                    ci->decoded_value->pRasterizationState->depthBiasClamp;
                pipeline_info->create_info.rasterization_state.depth_bias_slope_factor =
                    ci->decoded_value->pRasterizationState->depthBiasSlopeFactor;
                pipeline_info->create_info.rasterization_state.line_width =
                    ci->decoded_value->pRasterizationState->lineWidth;
            }

            // Layout
            pipeline_info->create_info.layout =
                dynamic_cast<FIPipelineLayoutInfo*>(object_table_.GetObject(ci->layout));
            pipeline_info->create_info.renderPass =
                dynamic_cast<FIRenderPassInfo*>(object_table_.GetObject(ci->renderPass));

            object_table_.AddObject(std::move(pipeline_info));
        }
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyPipeline(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(pipeline);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCreateCommandPool(
    const ApiCallInfo&                                     call_info,
    VkResult                                               returnValue,
    format::HandleId                                       device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
    HandlePointerDecoder<VkCommandPool>*                   pCommandPool)
{
    if (returnValue == VK_SUCCESS)
    {
        std::unique_ptr<FICommandPoolInfo> pool_info =
            std::make_unique<FICommandPoolInfo>(device, *pCommandPool->GetPointer());

        const auto ci = pCreateInfo->GetMetaStructPointer();

        pool_info->create_info.flags              = ci->decoded_value->flags;
        pool_info->create_info.queue_family_index = ci->decoded_value->queueFamilyIndex;

        object_table_.AddPool(std::move(pool_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkDestroyCommandPool(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.pools.push_back(commandPool);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*                     pCommandBuffers)
{
    if (returnValue == VK_SUCCESS)
    {
        const auto ai = pAllocateInfo->GetMetaStructPointer();

        const auto cmd_bufs = pCommandBuffers->GetPointer();
        for (uint32_t i = 0; i < pAllocateInfo->GetLength(); ++i)
        {
            std::unique_ptr<FICommandBufferInfo> command_buffer_info =
                std::make_unique<FICommandBufferInfo>(device, ai->commandPool, cmd_bufs[i]);

            object_table_.AddPoolObject(ai->commandPool, std::move(command_buffer_info));
        }
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkResetCommandBuffer(const ApiCallInfo&        call_info,
                                                                          VkResult                  returnValue,
                                                                          format::HandleId          commandBuffer,
                                                                          VkCommandBufferResetFlags flags)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    command_buffer_in->Reset();
}

void VulkanFrameInspectorConsumerClientBase::Process_vkResetCommandPool(const ApiCallInfo&      call_info,
                                                                        VkResult                returnValue,
                                                                        format::HandleId        device,
                                                                        format::HandleId        commandPool,
                                                                        VkCommandPoolResetFlags flags)
{
    FICommandPoolInfo* pool_info = dynamic_cast<FICommandPoolInfo*>(object_table_.GetPool(commandPool));
    assert(pool_info);

    for (auto cmd_buf : pool_info->child_ids)
    {
        FICommandBufferInfo* cmd_buf_info = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(cmd_buf));
        assert(cmd_buf_info);

        cmd_buf_info->Reset();
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                                      call_info,
    VkResult                                                returnValue,
    format::HandleId                                        commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    command_buffer_in->Reset();

    assert(!command_buffer_in->command_list.size());
}

void VulkanFrameInspectorConsumerClientBase::Process_vkEndCommandBuffer(const ApiCallInfo& call_info,
                                                                        VkResult           returnValue,
                                                                        format::HandleId   commandBuffer)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                     call_info,
    format::HandleId                       device,
    format::HandleId                       commandPool,
    uint32_t                               commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers)
{
    FICommandPoolInfo* pool_info = dynamic_cast<FICommandPoolInfo*>(object_table_.GetPool(commandPool));
    assert(pool_info);

    const format::HandleId* cmd_buf_ids = pCommandBuffers->GetPointer();
    for (uint32_t i = 0; i < commandBufferCount; ++i)
    {
        objects_pending_for_deletion_.pool_object.push_back(std::make_pair(pool_info->id, cmd_buf_ids[i]));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                                    contents)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    auto render_pass_begin_info = pRenderPassBegin->GetMetaStructPointer();

    FIFramebufferInfo* framebuffer =
        dynamic_cast<FIFramebufferInfo*>(object_table_.GetObject(render_pass_begin_info->framebuffer));
    assert(framebuffer);

    FIRenderPassInfo* renderpass = command_buffer_in->active_renderpass =
        dynamic_cast<FIRenderPassInfo*>(object_table_.GetObject(render_pass_begin_info->renderPass));
    assert(renderpass);

    std::shared_ptr<VulkanCommandBeginRenderPassInfo> command =
        std::make_shared<VulkanCommandBeginRenderPassInfo>(call_info.index);

    command_buffer_in->active_framebuffer = framebuffer;
    command_buffer_in->active_renderpass  = renderpass;

    command->renderpass_info  = command_buffer_in->active_renderpass;
    command->framebuffer_info = command_buffer_in->active_framebuffer;
    command->contents         = contents;

    const VkRenderPassBeginInfo* in_begin_infos = pRenderPassBegin->GetPointer();
    command->renderArea                         = in_begin_infos->renderArea;
    for (uint32_t i = 0; i < in_begin_infos->clearValueCount; ++i)
    {
        command->clear_values.push_back(in_begin_infos->pClearValues[i]);
    }

    command_buffer_in->EmplaceCommand(std::move(command));
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCmdEndRenderPass(const ApiCallInfo& call_info,
                                                                        format::HandleId   commandBuffer)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    std::shared_ptr<VulkanCommandEndRenderPassInfo> command =
        std::make_shared<VulkanCommandEndRenderPassInfo>(call_info.index);

    command_buffer_in->EmplaceCommand(std::move(command));
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCmdBindPipeline(const ApiCallInfo&  call_info,
                                                                       format::HandleId    commandBuffer,
                                                                       VkPipelineBindPoint pipelineBindPoint,
                                                                       format::HandleId    pipeline)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    command_buffer_in->active_pipeline = dynamic_cast<FIPipelineInfo*>(object_table_.GetObject(pipeline));
    assert(command_buffer_in->active_pipeline);

    std::shared_ptr<VulkanCommandBindPipelineInfo> command =
        std::make_shared<VulkanCommandBindPipelineInfo>(call_info.index);

    command->pipeline = dynamic_cast<FIPipelineInfo*>(object_table_.GetObject(pipeline));

    command->pipeline_bind_point = pipelineBindPoint;

    command_buffer_in->EmplaceCommand(std::move(command));
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCmdDraw(const ApiCallInfo& call_info,
                                                               format::HandleId   commandBuffer,
                                                               uint32_t           vertexCount,
                                                               uint32_t           instanceCount,
                                                               uint32_t           firstVertex,
                                                               uint32_t           firstInstance)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    std::shared_ptr<VulkanCommandDrawInfo> command =
        std::make_shared<VulkanCommandDrawInfo>(call_info.index, command_buffer_in);

    command->vertex_count   = vertexCount;
    command->instance_count = instanceCount;
    command->first_vertex   = firstVertex;
    command->first_instance = firstInstance;

    command_buffer_in->EmplaceCommand(std::move(command));
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCmdDrawIndirect(const ApiCallInfo& call_info,
                                                                       format::HandleId   commandBuffer,
                                                                       format::HandleId   buffer,
                                                                       VkDeviceSize       offset,
                                                                       uint32_t           drawCount,
                                                                       uint32_t           stride)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    std::shared_ptr<client::VulkanCommandDrawIndirectInfo> command =
        std::make_shared<client::VulkanCommandDrawIndirectInfo>(call_info.index, command_buffer_in);

    command->buffer     = buffer;
    command->offset     = offset;
    command->draw_count = drawCount;
    command->stride     = stride;

    command_buffer_in->EmplaceCommand(std::move(command));
}
void VulkanFrameInspectorConsumerClientBase::Process_vkCmdDrawIndirectCount(const ApiCallInfo& call_info,
                                                                            format::HandleId   commandBuffer,
                                                                            format::HandleId   buffer,
                                                                            VkDeviceSize       offset,
                                                                            format::HandleId   countBuffer,
                                                                            VkDeviceSize       countBufferOffset,
                                                                            uint32_t           maxDrawCount,
                                                                            uint32_t           stride)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    std::shared_ptr<client::VulkanCommandDrawIndirectCountInfo> command =
        std::make_shared<client::VulkanCommandDrawIndirectCountInfo>(call_info.index, command_buffer_in);

    command->buffer              = buffer;
    command->offset              = offset;
    command->count_buffer        = countBuffer;
    command->count_buffer_offset = countBufferOffset;
    command->max_draw_count      = maxDrawCount;
    command->stride              = stride;

    command_buffer_in->EmplaceCommand(std::move(command));
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCmdDrawIndexed(const ApiCallInfo& call_info,
                                                                      format::HandleId   commandBuffer,
                                                                      uint32_t           indexCount,
                                                                      uint32_t           instanceCount,
                                                                      uint32_t           firstIndex,
                                                                      int32_t            vertexOffset,
                                                                      uint32_t           firstInstance)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    std::shared_ptr<VulkanCommandDrawIndexedInfo> command =
        std::make_shared<VulkanCommandDrawIndexedInfo>(call_info.index, command_buffer_in);

    command->index_count    = indexCount;
    command->instance_count = instanceCount;
    command->first_index    = firstIndex;
    command->vertex_offset  = vertexOffset;
    command->first_instance = firstInstance;

    command_buffer_in->EmplaceCommand(std::move(command));
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCmdSetViewport(
    const ApiCallInfo&                        call_info,
    format::HandleId                          commandBuffer,
    uint32_t                                  firstViewport,
    uint32_t                                  viewportCount,
    StructPointerDecoder<Decoded_VkViewport>* pViewports)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    std::shared_ptr<VulkanCommandSetViewportInfo> command =
        std::make_shared<VulkanCommandSetViewportInfo>(call_info.index);

    const Decoded_VkViewport* viewports = pViewports->GetMetaStructPointer();

    for (uint32_t i = 0; i < viewportCount; ++i)
    {
        command->viewports.push_back(*viewports[i].decoded_value);
    }

    command->first_viewport = firstViewport;

    command_buffer_in->EmplaceCommand(std::move(command));
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCmdSetScissor(const ApiCallInfo& call_info,
                                                                     format::HandleId   commandBuffer,
                                                                     uint32_t           firstScissor,
                                                                     uint32_t           scissorCount,
                                                                     StructPointerDecoder<Decoded_VkRect2D>* pScissors)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    std::shared_ptr<VulkanCommandSetScissorInfo> command =
        std::make_shared<VulkanCommandSetScissorInfo>(call_info.index);

    const Decoded_VkRect2D* scissors = pScissors->GetMetaStructPointer();

    for (uint32_t i = 0; i < scissorCount; ++i)
    {
        command->scissors.push_back(*scissors[i].decoded_value);
    }

    command->first_scissor = firstScissor;

    command_buffer_in->EmplaceCommand(std::move(command));
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCmdBindIndexBuffer(const ApiCallInfo& call_info,
                                                                          format::HandleId   commandBuffer,
                                                                          format::HandleId   buffer,
                                                                          VkDeviceSize       offset,
                                                                          VkIndexType        indexType)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    std::shared_ptr<VulkanCommandBindIndexBufferInfo> command =
        std::make_shared<VulkanCommandBindIndexBufferInfo>(call_info.index);

    FIBufferInfo* buffer_info = dynamic_cast<FIBufferInfo*>(object_table_.GetObject(buffer));
    assert(buffer_info);

    command->buffer_info = buffer_info;
    command->offset      = offset;
    command->indexType   = indexType;

    command_buffer_in->EmplaceCommand(std::move(command));

    command_buffer_in->bound_index_buffer =
        FIBoundIndexBufferInfo{ command->buffer_info, command->offset, command->indexType };
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCmdBindVertexBuffers(const ApiCallInfo& call_info,
                                                                            format::HandleId   commandBuffer,
                                                                            uint32_t           firstBinding,
                                                                            uint32_t           bindingCount,
                                                                            HandlePointerDecoder<VkBuffer>* pBuffers,
                                                                            PointerDecoder<VkDeviceSize>*   pOffsets)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    std::shared_ptr<VulkanCommandBindVertexBuffersInfo> command =
        std::make_shared<VulkanCommandBindVertexBuffersInfo>(call_info.index);

    const format::HandleId* buffers = pBuffers->GetPointer();
    const VkDeviceSize*     offsets = pOffsets->GetPointer();
    for (uint32_t i = 0; i < bindingCount; ++i)
    {
        FIBufferInfo* buffer = dynamic_cast<FIBufferInfo*>(object_table_.GetObject(buffers[i]));
        assert(buffer);
        command->buffers.push_back(buffer);
        command->offsets.push_back(offsets[i]);

        command_buffer_in->bound_vertex_buffers[firstBinding + i] = FIBoundVertexBufferInfo{ buffer, offsets[i] };
    }

    command->firstBinding = firstBinding;

    command_buffer_in->EmplaceCommand(std::move(command));
}

void VulkanFrameInspectorConsumerClientBase::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                     call_info,
    format::HandleId                       commandBuffer,
    VkPipelineBindPoint                    pipelineBindPoint,
    format::HandleId                       layout,
    uint32_t                               firstSet,
    uint32_t                               descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets,
    uint32_t                               dynamicOffsetCount,
    PointerDecoder<uint32_t>*              pDynamicOffsets)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    std::shared_ptr<VulkanCommandBindDescriptorSetsInfo> command =
        std::make_shared<VulkanCommandBindDescriptorSetsInfo>(call_info.index);

    command->pipeline_bind_point = pipelineBindPoint;
    command->pipeline_layout     = dynamic_cast<FIPipelineLayoutInfo*>(object_table_.GetObject(layout));
    command->first_set           = firstSet;

    const format::HandleId* desc_set_ids = pDescriptorSets->GetPointer();
    // const uint32_t*         offsets      = pDynamicOffsets->GetPointer();
    for (uint32_t i = 0; i < descriptorSetCount; ++i)
    {
        FIDescriptorSetInfo* desc_set = dynamic_cast<FIDescriptorSetInfo*>(object_table_.GetObject(desc_set_ids[i]));
        assert(desc_set);

        command_buffer_in->active_descriptor_sets[firstSet + i] = desc_set;
        command->descriptor_sets.push_back(desc_set);
        // command->dynamic_offsets.push_back(offsets[i]);
    }

    command_buffer_in->EmplaceCommand(std::move(command));
}

void VulkanFrameInspectorConsumerClientBase::Process_vkQueueSubmit(const ApiCallInfo& call_info,
                                                                   VkResult           returnValue,
                                                                   format::HandleId   queue,
                                                                   uint32_t           submitCount,
                                                                   StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                                                   format::HandleId                            fence)
{
    std::unique_ptr<QueueSubmitInfo> queue_submit_info = std::make_unique<QueueSubmitInfo>(call_info.index);

    const Decoded_VkSubmitInfo* submit_infos = pSubmits->GetMetaStructPointer();
    for (uint32_t i = 0; i < submitCount; ++i)
    {
        const format::HandleId* cmd_buf_ids = submit_infos->pCommandBuffers.GetPointer();
        for (uint32_t cb = 0; cb < submit_infos->decoded_value->commandBufferCount; ++cb)
        {
            FICommandBufferInfo* cmd_buf_info =
                dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(cmd_buf_ids[cb]));
            assert(cmd_buf_info);

            assert(queue_submit_info->command_buffers.find(cmd_buf_info->id) ==
                   queue_submit_info->command_buffers.end());
            queue_submit_info->command_buffers.emplace(cmd_buf_info->id, cmd_buf_info->command_list);
        }

        if (submit_infos->pSignalSemaphores.GetPointer())
        {
            queue_submit_info->signal_semaphores.push_back(submit_infos->pSignalSemaphores.GetPointer()[i]);
        }

        if (submit_infos->pWaitDstStageMask.GetPointer())
        {
            queue_submit_info->wait_semaphores.push_back(submit_infos->pSignalSemaphores.GetPointer()[i]);
        }

        if (submit_infos->pWaitDstStageMask.GetPointer())
        {
            queue_submit_info->wait_dst_stage_mask.push_back(submit_infos->pWaitDstStageMask.GetPointer()[i]);
        }
    }

    // Update indirect commands with the parameters received from the device
    for (auto& cmd_buf : queue_submit_info->command_buffers)
    {
        for (auto& cmd : cmd_buf.second)
        {
            const auto& it = draw_indirect_params.find(std::make_pair(call_info.index, cmd->index));
            if (it != draw_indirect_params.end())
            {
                if (cmd->type == it->second.command_type)
                {
                    client::VulkanCommandDrawIndirectInfo* draw_indirect =
                        dynamic_cast<client::VulkanCommandDrawIndirectInfo*>(cmd.get());
                    assert(draw_indirect);

                    draw_indirect->GetParams() = std::move(it->second.command_params);
                    draw_indirect->draw_count  = it->second.draw_count;
                    draw_indirect->is_accurate = true;
                }
                else
                {
                    GFXRECON_LOG_WARNING("%s (%" PRIu64 ", %" PRIu64
                                         ") indirect command is of the wrong type. Expected %s, got %s",
                                         __func__,
                                         call_info.index,
                                         cmd->index,
                                         vulkan_command_to_str(cmd->type),
                                         vulkan_command_to_str(it->second.command_type));
                    assert(0);
                }
            }
            else
            {
                GFXRECON_LOG_WARNING(
                    "%s (%" PRIu64 ", %" PRIu64 ") was not found", __func__, call_info.index, cmd->index);
                assert(0);
            }
        }
    }

    queue_submit_info->fence = fence;
    queue_submit_info->queue = queue;

    EmplaceSerializedCommand(std::move(queue_submit_info));
}

void VulkanFrameInspectorConsumerClientBase::Process_vkQueuePresentKHR(
    const ApiCallInfo&                              call_info,
    VkResult                                        returnValue,
    format::HandleId                                queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    std::unique_ptr<QueuePresentInfo> queue_present_info = std::make_unique<QueuePresentInfo>(call_info.index);

    const Decoded_VkPresentInfoKHR* pi = pPresentInfo->GetMetaStructPointer();

    const format::HandleId* swapchain_ids = pi->pSwapchains.GetPointer();
    const uint32_t*         image_indices = pi->pImageIndices.GetPointer();
    for (uint32_t i = 0; i < pi->decoded_value->swapchainCount; ++i)
    {
        queue_present_info->image_indices.push_back(image_indices[i]);
        queue_present_info->swapchains.push_back(swapchain_ids[i]);
    }

    const format::HandleId* semaphore_ids = pi->pWaitSemaphores.GetPointer();
    for (uint32_t i = 0; i < pi->decoded_value->waitSemaphoreCount; ++i)
    {
        queue_present_info->wait_semaphores.push_back(semaphore_ids[i]);
    }

    EmplaceSerializedCommand(std::move(queue_present_info));
}

void VulkanFrameInspectorConsumerClientBase::Process_vkAllocateMemory(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  pAllocateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*                pMemory)
{
    if (returnValue == VK_SUCCESS)
    {
        std::unique_ptr<FIDeviceMemoryInfo> dev_mem_info =
            std::make_unique<FIDeviceMemoryInfo>(device, *pMemory->GetPointer());

        const Decoded_VkMemoryAllocateInfo* ci = pAllocateInfo->GetMetaStructPointer();

        dev_mem_info->create_info.allocation_size   = ci->decoded_value->allocationSize;
        dev_mem_info->create_info.memory_type_index = ci->decoded_value->memoryTypeIndex;

        object_table_.AddObject(std::move(dev_mem_info));
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkFreeMemory(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    objects_pending_for_deletion_.objects.push_back(memory);
}

void VulkanFrameInspectorConsumerClientBase::Process_vkBindBufferMemory(const ApiCallInfo& call_info,
                                                                        VkResult           returnValue,
                                                                        format::HandleId   device,
                                                                        format::HandleId   buffer,
                                                                        format::HandleId   memory,
                                                                        VkDeviceSize       memoryOffset)
{
    if (returnValue == VK_SUCCESS)
    {
        FIBufferInfo* buffer_info = dynamic_cast<FIBufferInfo*>(object_table_.GetObject(buffer));
        assert(buffer_info);

        FIDeviceMemoryInfo* dev_mem_info = dynamic_cast<FIDeviceMemoryInfo*>(object_table_.GetObject(memory));
        assert(dev_mem_info);

        buffer_info->bound_memory_info.bound_memory = dev_mem_info;
        buffer_info->bound_memory_info.offset       = memoryOffset;
    }
}

void VulkanFrameInspectorConsumerClientBase::Process_vkBindImageMemory(const ApiCallInfo& call_info,
                                                                       VkResult           returnValue,
                                                                       format::HandleId   device,
                                                                       format::HandleId   image,
                                                                       format::HandleId   memory,
                                                                       VkDeviceSize       memoryOffset)
{
    if (returnValue == VK_SUCCESS)
    {
        FIImageInfo* image_info = dynamic_cast<FIImageInfo*>(object_table_.GetObject(image));
        assert(image_info);

        FIDeviceMemoryInfo* dev_mem_info = dynamic_cast<FIDeviceMemoryInfo*>(object_table_.GetObject(memory));
        assert(dev_mem_info);

        image_info->bound_memory_info.bound_memory = dev_mem_info;
        image_info->bound_memory_info.offset       = memoryOffset;
    }
}

void VulkanFrameInspectorConsumerClientBase::DeletePendingObjects()
{
    for (auto& obj : objects_pending_for_deletion_.objects)
    {
        object_table_.DeleteObject(obj);
    }
    objects_pending_for_deletion_.objects.clear();

    for (auto& obj : objects_pending_for_deletion_.pool_object)
    {
        object_table_.DeletePoolObject(obj.first, obj.second);
    }
    objects_pending_for_deletion_.pool_object.clear();

    for (auto& pool : objects_pending_for_deletion_.pools)
    {
        object_table_.DeletePool(pool);
    }
    objects_pending_for_deletion_.pools.clear();
}

void VulkanFrameInspectorConsumerClientBase::DumpFrame() const
{
    for (const auto& serialize_cmd : commands_)
    {
        switch (serialize_cmd->type)
        {
            case SERIALIZED_CMD_QUEUE_SUBMIT:
            {
                QueueSubmitInfo* queue_submit_info = reinterpret_cast<QueueSubmitInfo*>(serialize_cmd.get());
                assert(queue_submit_info);
                GFXRECON_WRITE_CONSOLE("vkQueueSubmit (%" PRIu64 ")\n", queue_submit_info->index);

                for (const auto& cmd_buf : queue_submit_info->command_buffers)
                {
                    GFXRECON_WRITE_CONSOLE("  vkCommandBuffer (%" PRIu64 ")\n", cmd_buf.first);
                    for (const auto& cmd : cmd_buf.second)
                    {
                        GFXRECON_WRITE_CONSOLE(
                            "    - (%" PRIu64 ") %s\n", cmd->index, vulkan_command_to_str(cmd.get()));
                        switch (cmd->type)
                        {
                            case VULKAN_CMD_DRAW:
                            {
                                VulkanCommandDrawInfo* draw_cmd = dynamic_cast<VulkanCommandDrawInfo*>(cmd.get());
                                assert(draw_cmd);

                                GFXRECON_WRITE_CONSOLE("Set Binding\n");
                                for (const auto& desc_set : draw_cmd->descriptor_sets)
                                {
                                    for (const auto& binding : desc_set.second.bindings)
                                    {
                                        GFXRECON_WRITE_CONSOLE("%u    %u        %s\n",
                                                               desc_set.first,
                                                               binding.first,
                                                               desc_type_to_str(binding.second.descriptor_type));
                                    }
                                }

                                GFXRECON_WRITE_CONSOLE("Pipeline: %" PRIu64 "\n", draw_cmd->pipeline->id);
                                if (draw_cmd->bound_vertex_buffers.size())
                                {
                                    GFXRECON_WRITE_CONSOLE("Vertex Buffers:\n");
                                    for (const auto& vert_buf : draw_cmd->bound_vertex_buffers)
                                    {
                                        GFXRECON_WRITE_CONSOLE("  %u: %" PRIu64 " @ %zu\n",
                                                               vert_buf.first,
                                                               vert_buf.second.buffer->id,
                                                               vert_buf.second.offset);
                                    }
                                }
                            }
                            break;

                            case VULKAN_CMD_DRAW_INDIRECT:
                            {
                                client::VulkanCommandDrawIndirectInfo* draw_cmd =
                                    dynamic_cast<client::VulkanCommandDrawIndirectInfo*>(cmd.get());
                                assert(draw_cmd);

                                GFXRECON_WRITE_CONSOLE("draw count: %u", draw_cmd->draw_count);

                                for (uint32_t i = 0; i < draw_cmd->draw_count; ++i)
                                {
                                    GFXRECON_WRITE_CONSOLE("  %u: (vc: %u ic: %u fv: %u fi: %u)",
                                                           i,
                                                           draw_cmd->GetParams()[i].indirect.vertexCount,
                                                           draw_cmd->GetParams()[i].indirect.instanceCount,
                                                           draw_cmd->GetParams()[i].indirect.firstVertex,
                                                           draw_cmd->GetParams()[i].indirect.firstInstance)
                                }

                                GFXRECON_WRITE_CONSOLE("Set Binding\n");
                                for (const auto& desc_set : draw_cmd->descriptor_sets)
                                {
                                    for (const auto& binding : desc_set.second.bindings)
                                    {
                                        GFXRECON_WRITE_CONSOLE("%u    %u        %s\n",
                                                               desc_set.first,
                                                               binding.first,
                                                               desc_type_to_str(binding.second.descriptor_type));
                                    }
                                }

                                GFXRECON_WRITE_CONSOLE("Pipeline: %" PRIu64 "\n", draw_cmd->pipeline->id);
                                if (draw_cmd->bound_vertex_buffers.size())
                                {
                                    GFXRECON_WRITE_CONSOLE("Vertex Buffers:\n");
                                    for (const auto& vert_buf : draw_cmd->bound_vertex_buffers)
                                    {
                                        GFXRECON_WRITE_CONSOLE("  %u: %" PRIu64 " @ %zu\n",
                                                               vert_buf.first,
                                                               vert_buf.second.buffer->id,
                                                               vert_buf.second.offset);
                                    }
                                }
                            }

                            default:
                                break;
                        }
                    }
                }
            }
            break;

            case SERIALIZED_CMD_QUEUE_PRESENT:
            {
                QueuePresentInfo* queue_present_info = reinterpret_cast<QueuePresentInfo*>(serialize_cmd.get());
                assert(queue_present_info);
                GFXRECON_WRITE_CONSOLE("vkQueuePresentKHR (%" PRIu64 ")\n", queue_present_info->index);
            }
            break;

            default:
                assert(0);
        }
    }
}

bool VulkanFrameInspectorConsumerClientBase::GetIndirectCommandParamsOverSocket(util::Socket& socket)
{
    size_t n   = 0;
    int    ret = socket.Receive(&n, sizeof(n));

    size_t i;
    for (i = 0; i < n; ++i)
    {
        draw_indirect_command_t cmd;

        ret = socket.Receive(&cmd.queue_submit_index, sizeof(cmd.queue_submit_index));
        assert(ret > -1);

        ret = socket.Receive(&cmd.command_index, sizeof(cmd.command_index));
        assert(ret > -1);

        ret = socket.Receive(&cmd.command_type, sizeof(cmd.command_type));
        assert(ret > -1);

        ret = socket.Receive(&cmd.draw_count, sizeof(cmd.draw_count));
        assert(ret > -1);

        cmd.command_params.resize(cmd.draw_count);
        ret = socket.Receive(cmd.command_params.data(), cmd.draw_count * sizeof(indirect_draw_parameters_union));
        assert(ret > -1);

        draw_indirect_params.insert({ std::make_pair(cmd.queue_submit_index, cmd.command_index), std::move(cmd) });
    }

    socket.Send(&i, sizeof(i));

    return true;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
