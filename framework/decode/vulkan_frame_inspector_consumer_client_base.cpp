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
        FIDeviceInfo* device_in = dynamic_cast<FIDeviceInfo*>(object_table_.GetObject(device));
        assert(device_in);

        std::unique_ptr<FIRenderPassInfo> renderpass_info =
            std::make_unique<FIRenderPassInfo>(device_in->id, *pRenderPass->GetPointer());

        const auto ci = pCreateInfo->GetMetaStructPointer();

        object_table_.AddObject(std::move(renderpass_info));
    }
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
        FIDeviceInfo* device_in = dynamic_cast<FIDeviceInfo*>(object_table_.GetObject(device));
        assert(device_in);

        std::unique_ptr<FIFramebufferInfo> renderpass_info =
            std::make_unique<FIFramebufferInfo>(device_in->id, *pFramebuffer->GetPointer());

        const auto ci = pCreateInfo->GetMetaStructPointer();

        object_table_.AddObject(std::move(renderpass_info));
    }
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
        FIDeviceInfo* device_in = dynamic_cast<FIDeviceInfo*>(object_table_.GetObject(device));
        assert(device_in);

        std::unique_ptr<FIDescriptorSetLayoutInfo> desc_set_layout_info =
            std::make_unique<FIDescriptorSetLayoutInfo>(device_in->id, *pSetLayout->GetPointer());

        const auto ci = pCreateInfo->GetMetaStructPointer();

        object_table_.AddObject(std::move(desc_set_layout_info));
    }
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
        FIDeviceInfo* device_in = dynamic_cast<FIDeviceInfo*>(object_table_.GetObject(device));
        assert(device_in);

        std::unique_ptr<FIDescriptorPoolInfo> desc_pool_info =
            std::make_unique<FIDescriptorPoolInfo>(device_in->id, *pDescriptorPool->GetPointer());

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
        FIDeviceInfo* device_in = dynamic_cast<FIDeviceInfo*>(object_table_.GetObject(device));
        assert(device_in);

        const auto* ai    = pAllocateInfo->GetPointer();
        const auto* ai_ms = pAllocateInfo->GetMetaStructPointer();

        FIDescriptorPoolInfo* pool_info =
            dynamic_cast<FIDescriptorPoolInfo*>(object_table_.GetPool(ai_ms->descriptorPool));
        assert(pool_info);

        for (uint32_t i = 0; i < ai->descriptorSetCount; ++i)
        {
            std::unique_ptr<FIDescriptorSetInfo> desc_set =
                std::make_unique<FIDescriptorSetInfo>(device_in->id, pool_info->id, pDescriptorSets->GetPointer()[i]);

            object_table_.AddPoolObject(pool_info, std::move(desc_set));
        }
    }
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
        FIDeviceInfo* device_in = dynamic_cast<FIDeviceInfo*>(object_table_.GetObject(device));
        assert(device_in);

        std::unique_ptr<FIPipelineLayoutInfo> pipeline_layout_info =
            std::make_unique<FIPipelineLayoutInfo>(device_in->id, *pPipelineLayout->GetPointer());

        const auto ci = pCreateInfo->GetMetaStructPointer();

        object_table_.AddObject(std::move(pipeline_layout_info));
    }
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
        FIDeviceInfo* device_in = dynamic_cast<FIDeviceInfo*>(object_table_.GetObject(device));
        assert(device_in);

        for (uint32_t i = 0; i < createInfoCount; ++i)
        {
            std::unique_ptr<FIPipelineInfo> pipeline_info =
                std::make_unique<FIPipelineInfo>(device_in->id, *pPipelines->GetPointer());

            object_table_.AddObject(std::move(pipeline_info));
        }
    }
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
        FIDeviceInfo* device_in = dynamic_cast<FIDeviceInfo*>(object_table_.GetObject(device));
        assert(device_in);

        std::unique_ptr<FICommandPoolInfo> pool_info =
            std::make_unique<FICommandPoolInfo>(device_in->id, *pCommandPool->GetPointer());

        const auto ci = pCreateInfo->GetMetaStructPointer();

        pool_info->create_info.flags              = ci->decoded_value->flags;
        pool_info->create_info.queue_family_index = ci->decoded_value->queueFamilyIndex;

        object_table_.AddPool(std::move(pool_info));
    }
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
        FIDeviceInfo* device_in = dynamic_cast<FIDeviceInfo*>(object_table_.GetObject(device));
        assert(device_in);

        const auto         ai        = pAllocateInfo->GetMetaStructPointer();
        FICommandPoolInfo* pool_info = dynamic_cast<FICommandPoolInfo*>(object_table_.GetPool(ai->commandPool));
        assert(pool_info);

        const auto cmd_bufs = pCommandBuffers->GetPointer();
        for (uint32_t i = 0; i < pAllocateInfo->GetLength(); ++i)
        {
            std::unique_ptr<FICommandBufferInfo> command_buffer_info =
                std::make_unique<FICommandBufferInfo>(device_in->id, pool_info->id, cmd_bufs[i]);

            object_table_.AddPoolObject(pool_info, std::move(command_buffer_info));
        }
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

    assert(!command_buffer_in->command_list.size());

    command_buffer_in->state = kRecording;
}

void VulkanFrameInspectorConsumerClientBase::Process_vkEndCommandBuffer(const ApiCallInfo& call_info,
                                                                        VkResult           returnValue,
                                                                        format::HandleId   commandBuffer)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    command_buffer_in->state = kExecutable;
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

    std::unique_ptr<VulkanCommandBeginRenderPassInfo> command =
        std::make_unique<VulkanCommandBeginRenderPassInfo>(call_info.index);

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

void VulkanFrameInspectorConsumerClientBase::Process_vkCmdBindPipeline(const ApiCallInfo&  call_info,
                                                                       format::HandleId    commandBuffer,
                                                                       VkPipelineBindPoint pipelineBindPoint,
                                                                       format::HandleId    pipeline)
{
    FICommandBufferInfo* command_buffer_in = dynamic_cast<FICommandBufferInfo*>(object_table_.GetObject(commandBuffer));
    assert(command_buffer_in);

    command_buffer_in->active_pipeline = dynamic_cast<FIPipelineInfo*>(object_table_.GetObject(pipeline));
    assert(command_buffer_in->active_pipeline);

    std::unique_ptr<VulkanCommandBindPipelineInfo> command =
        std::make_unique<VulkanCommandBindPipelineInfo>(call_info.index);

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

    std::unique_ptr<VulkanCommandDrawInfo> command = std::make_unique<VulkanCommandDrawInfo>(call_info.index);

    command->pipeline = command_buffer_in->active_pipeline;
    for (const auto desc_set : command_buffer_in->active_descriptor_sets)
    {
        command->descriptor_sets.emplace(desc_set.first, *desc_set.second);
    }

    command->vertex_count   = vertexCount;
    command->instance_count = instanceCount;
    command->first_vertex   = firstVertex;
    command->first_instance = firstInstance;

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

    std::unique_ptr<VulkanCommandBindDescriptorSetsInfo> command =
        std::make_unique<VulkanCommandBindDescriptorSetsInfo>(call_info.index);

    command->pipeline_bind_point = pipelineBindPoint;
    command->pipeline_layout     = dynamic_cast<FIPipelineLayoutInfo*>(object_table_.GetObject(layout));
    command->first_set           = firstSet;

    const format::HandleId* desc_set_ids = pDescriptorSets->GetPointer();
    const uint32_t*         offsets      = pDynamicOffsets->GetPointer();
    for (uint32_t i = 0; i < descriptorSetCount; ++i)
    {
        FIDescriptorSetInfo* desc_set = dynamic_cast<FIDescriptorSetInfo*>(object_table_.GetObject(desc_set_ids[i]));
        assert(desc_set);
        command_buffer_in->active_descriptor_sets[firstSet + i] = desc_set;
        command->descriptor_sets.push_back(desc_set);
        command->dynamic_offsets.push_back(offsets[i]);
    }

    command_buffer_in->EmplaceCommand(std::move(command));
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
