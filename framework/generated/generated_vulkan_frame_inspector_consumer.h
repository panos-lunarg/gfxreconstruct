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

#ifndef GFXRECON_GENERATED_VULKAN_FRAME_INSPECTOR_CONSUMER_H
#define GFXRECON_GENERATED_VULKAN_FRAME_INSPECTOR_CONSUMER_H

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_object_info_table.h"
#include "util/defines.h"
#include "generated/generated_vulkan_consumer.h"
#include "application/application.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_handle_mapping_util.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanFrameInspectorConsumerBase : public VulkanConsumer
{
  public:
    VulkanFrameInspectorConsumerBase() {}

    VulkanFrameInspectorConsumerBase(std::shared_ptr<application::Application> application,
                                     const VulkanReplayOptions&                options) :
        VulkanConsumer()
    {}

    virtual ~VulkanFrameInspectorConsumerBase() override {}

    virtual void Process_vkCreateInstance(const ApiCallInfo&                                   call_info,
                                          VkResult                                             returnValue,
                                          StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                          HandlePointerDecoder<VkInstance>*                    pInstance) override;

    virtual void Process_vkDestroyInstance(const ApiCallInfo&                                   call_info,
                                           format::HandleId                                     instance,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateDevice(const ApiCallInfo&                                   call_info,
                                        VkResult                                             returnValue,
                                        format::HandleId                                     physicalDevice,
                                        StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                        HandlePointerDecoder<VkDevice>*                      pDevice) override;

    virtual void Process_vkDestroyDevice(const ApiCallInfo&                                   call_info,
                                         format::HandleId                                     device,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateBuffer(const ApiCallInfo&                                   call_info,
                                        VkResult                                             returnValue,
                                        format::HandleId                                     device,
                                        StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                        HandlePointerDecoder<VkBuffer>*                      pBuffer) override;

    virtual void Process_vkCreateBufferView(const ApiCallInfo&                                    call_info,
                                            VkResult                                              returnValue,
                                            format::HandleId                                      device,
                                            StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
                                            StructPointerDecoder<Decoded_VkAllocationCallbacks>*  pAllocator,
                                            HandlePointerDecoder<VkBufferView>*                   pView) override;

    virtual void Process_vkCreateImage(const ApiCallInfo&                                   call_info,
                                       VkResult                                             returnValue,
                                       format::HandleId                                     device,
                                       StructPointerDecoder<Decoded_VkImageCreateInfo>*     pCreateInfo,
                                       StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                       HandlePointerDecoder<VkImage>*                       pImage) override;

    virtual void Process_vkCreateImageView(const ApiCallInfo&                                   call_info,
                                           VkResult                                             returnValue,
                                           format::HandleId                                     device,
                                           StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                           HandlePointerDecoder<VkImageView>*                   pView) override;

    virtual void Process_vkCreateFramebuffer(const ApiCallInfo&                                     call_info,
                                             VkResult                                               returnValue,
                                             format::HandleId                                       device,
                                             StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
                                             StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                             HandlePointerDecoder<VkFramebuffer>* pFramebuffer) override;

    virtual void
    Process_vkCreateDescriptorSetLayout(const ApiCallInfo&                                             call_info,
                                        VkResult                                                       returnValue,
                                        format::HandleId                                               device,
                                        StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*           pAllocator,
                                        HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout) override;

    virtual void Process_vkCreateDescriptorUpdateTemplate(
        const ApiCallInfo&                                                  call_info,
        VkResult                                                            returnValue,
        format::HandleId                                                    device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate) override;

    virtual void Process_vkCreateDescriptorUpdateTemplateKHR(
        const ApiCallInfo&                                                  call_info,
        VkResult                                                            returnValue,
        format::HandleId                                                    device,
        StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate) override;

    virtual void
    Process_vkDestroyDescriptorPool(const ApiCallInfo&                                   call_info,
                                    format::HandleId                                     device,
                                    format::HandleId                                     descriptorPool,
                                    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkResetDescriptorPool(const ApiCallInfo&         call_info,
                                               VkResult                   returnValue,
                                               format::HandleId           device,
                                               format::HandleId           descriptorPool,
                                               VkDescriptorPoolResetFlags flags) override;

    virtual void
    Process_vkAllocateDescriptorSets(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    virtual void Process_vkFreeDescriptorSets(const ApiCallInfo&                     call_info,
                                              VkResult                               returnValue,
                                              format::HandleId                       device,
                                              format::HandleId                       descriptorPool,
                                              uint32_t                               descriptorSetCount,
                                              HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    virtual void
    Process_vkUpdateDescriptorSets(const ApiCallInfo&                                  call_info,
                                   format::HandleId                                    device,
                                   uint32_t                                            descriptorWriteCount,
                                   StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
                                   uint32_t                                            descriptorCopyCount,
                                   StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&               call_info,
                                                           format::HandleId                 device,
                                                           format::HandleId                 descriptorSet,
                                                           format::HandleId                 descriptorUpdateTemplate,
                                                           DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                               format::HandleId   commandBuffer,
                                                               format::HandleId   descriptorUpdateTemplate,
                                                               format::HandleId   layout,
                                                               uint32_t           set,
                                                               DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&               call_info,
                                                              format::HandleId                 device,
                                                              format::HandleId                 descriptorSet,
                                                              format::HandleId                 descriptorUpdateTemplate,
                                                              DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkDestroyCommandPool(const ApiCallInfo&                                   call_info,
                                              format::HandleId                                     device,
                                              format::HandleId                                     commandPool,
                                              StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkResetCommandPool(const ApiCallInfo&      call_info,
                                            VkResult                returnValue,
                                            format::HandleId        device,
                                            format::HandleId        commandPool,
                                            VkCommandPoolResetFlags flags) override;

    virtual void
    Process_vkAllocateCommandBuffers(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    virtual void Process_vkFreeCommandBuffers(const ApiCallInfo&                     call_info,
                                              format::HandleId                       device,
                                              format::HandleId                       commandPool,
                                              uint32_t                               commandBufferCount,
                                              HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    virtual void
    Process_vkBeginCommandBuffer(const ApiCallInfo&                                      call_info,
                                 VkResult                                                returnValue,
                                 format::HandleId                                        commandBuffer,
                                 StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) override;

    virtual void Process_vkResetCommandBuffer(const ApiCallInfo&        call_info,
                                              VkResult                  returnValue,
                                              format::HandleId          commandBuffer,
                                              VkCommandBufferResetFlags flags) override;

  protected:
    template <typename T>
    typename T::HandleType MapHandle(format::HandleId id,
                                     const T* (VulkanObjectInfoTable::*MapFunc)(format::HandleId) const) const
    {
        return handle_mapping::MapHandle(id, object_info_table_, MapFunc);
    }

    uint64_t MapHandle(uint64_t object, VkObjectType object_type)
    {
        return handle_mapping::MapHandle(object, object_type, object_info_table_);
    }

    uint64_t MapHandle(uint64_t object, VkDebugReportObjectTypeEXT object_type)
    {
        return handle_mapping::MapHandle(object, object_type, object_info_table_);
    }

    template <typename T>
    typename T::HandleType* MapHandles(HandlePointerDecoder<typename T::HandleType>* handles_pointer,
                                       size_t                                        handles_len,
                                       const T* (VulkanObjectInfoTable::*MapFunc)(format::HandleId) const) const
    {
        // This parameter is only referenced by debug builds.
        GFXRECON_UNREFERENCED_PARAMETER(handles_len);

        typename T::HandleType* handles = nullptr;

        if (handles_pointer != nullptr)
        {
            // The handle and ID array sizes are expected to be the same for mapping operations.
            assert(handles_len == handles_pointer->GetLength());

            handles = handle_mapping::MapHandleArray(handles_pointer, object_info_table_, MapFunc);
        }

        return handles;
    }

    template <typename T>
    void AddHandle(format::HandleId              parent_id,
                   const format::HandleId*       id,
                   const typename T::HandleType* handle,
                   T&&                           initial_info,
                   void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        if ((id != nullptr) && (handle != nullptr))
        {
            handle_mapping::AddHandle(
                parent_id, *id, *handle, std::forward<T>(initial_info), &object_info_table_, AddFunc);
        }
    }

    template <typename T>
    void AddHandle(format::HandleId              parent_id,
                   const format::HandleId*       id,
                   const typename T::HandleType* handle,
                   void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        if ((id != nullptr) && (handle != nullptr))
        {
            handle_mapping::AddHandle(parent_id, *id, *handle, &object_info_table_, AddFunc);
        }
    }

    template <typename T>
    void AddHandles(format::HandleId              parent_id,
                    const format::HandleId*       ids,
                    size_t                        ids_len,
                    const typename T::HandleType* handles,
                    size_t                        handles_len,
                    std::vector<T>&&              initial_infos,
                    void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        handle_mapping::AddHandleArray(
            parent_id, ids, ids_len, handles, handles_len, std::move(initial_infos), &object_info_table_, AddFunc);
    }

    template <typename T>
    void AddHandles(format::HandleId              parent_id,
                    const format::HandleId*       ids,
                    size_t                        ids_len,
                    const typename T::HandleType* handles,
                    size_t                        handles_len,
                    void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        handle_mapping::AddHandleArray(parent_id, ids, ids_len, handles, handles_len, &object_info_table_, AddFunc);
    }

    template <typename S, typename T>
    void AddPoolHandles(format::HandleId              parent_id,
                        format::HandleId              pool_id,
                        const format::HandleId*       ids,
                        size_t                        ids_len,
                        const typename T::HandleType* handles,
                        size_t                        handles_len,
                        std::vector<T>&&              initial_infos,
                        S* (VulkanObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                        void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        handle_mapping::AddHandleArray(parent_id,
                                       pool_id,
                                       ids,
                                       ids_len,
                                       handles,
                                       handles_len,
                                       std::move(initial_infos),
                                       &object_info_table_,
                                       GetPoolInfoFunc,
                                       AddFunc);
    }

    template <typename S, typename T>
    void AddPoolHandles(format::HandleId              parent_id,
                        format::HandleId              pool_id,
                        const format::HandleId*       ids,
                        size_t                        ids_len,
                        const typename T::HandleType* handles,
                        size_t                        handles_len,
                        S* (VulkanObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                        void (VulkanObjectInfoTable::*AddFunc)(T&&))
    {
        handle_mapping::AddHandleArray(
            parent_id, pool_id, ids, ids_len, handles, handles_len, &object_info_table_, GetPoolInfoFunc, AddFunc);
    }

    void RemoveHandle(format::HandleId id, void (VulkanObjectInfoTable::*RemoveFunc)(format::HandleId))
    {
        handle_mapping::RemoveHandle(id, &object_info_table_, RemoveFunc);
    }

    template <typename T>
    void RemovePoolHandle(format::HandleId id,
                          T* (VulkanObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                          void (VulkanObjectInfoTable::*RemovePoolFunc)(format::HandleId),
                          void (VulkanObjectInfoTable::*RemoveObjectFunc)(format::HandleId))
    {
        handle_mapping::RemovePoolHandle(id, &object_info_table_, GetPoolInfoFunc, RemovePoolFunc, RemoveObjectFunc);
    }

    template <typename S, typename T>
    void RemovePoolHandles(format::HandleId                                    pool_id,
                           const HandlePointerDecoder<typename T::HandleType>* handles_pointer,
                           size_t                                              handles_len,
                           S* (VulkanObjectInfoTable::*GetPoolInfoFunc)(format::HandleId),
                           void (VulkanObjectInfoTable::*RemoveFunc)(format::HandleId))
    {
        // This parameter is only referenced by debug builds.
        GFXRECON_UNREFERENCED_PARAMETER(handles_len);

        if (handles_pointer != nullptr)
        {
            // The handle and ID array sizes are expected to be the same for mapping operations.
            assert(handles_len == handles_pointer->GetLength());
            handle_mapping::RemoveHandleArray<S, T>(
                pool_id, handles_pointer, &object_info_table_, GetPoolInfoFunc, RemoveFunc);
        }
    }

    template <typename HandleInfoT>
    void SetOutputArrayCount(format::HandleId handle_id,
                             uint32_t         index,
                             size_t           count,
                             HandleInfoT* (VulkanObjectInfoTable::*HandleInfoFunc)(format::HandleId))
    {
        HandleInfoT* info = (object_info_table_.*HandleInfoFunc)(handle_id);
        if (info != nullptr)
        {
            info->array_counts[index] = static_cast<size_t>(count);
        }
    }

    template <typename CountT, typename HandleInfoT, typename ArrayT>
    CountT GetOutputArrayCount(const char*                   func_name,
                               VkResult                      original_result,
                               format::HandleId              handle_id,
                               uint32_t                      index,
                               const PointerDecoder<CountT>* original_count,
                               const ArrayT*                 original_array,
                               const HandleInfoT* (VulkanObjectInfoTable::*HandleInfoFunc)(format::HandleId) const)
    {
        assert((original_count != nullptr) && (original_array != nullptr));

        CountT replay_count = 0;

        if (!original_count->IsNull() && !original_array->IsNull())
        {
            // When the array parameter is not null, start with array count set equal to the capture count and then
            // adjust if the replay count is different.
            replay_count = (*original_count->GetPointer());

            // Only adjust the replay array count if the call succeeded on capture so that errors generated at capture,
            // such as VK_INCOMPLETE, continue to be generated at replay.
            if (original_result == VK_SUCCESS)
            {
                const HandleInfoT* info = (object_info_table_.*HandleInfoFunc)(handle_id);
                if (info != nullptr)
                {
                    auto entry = info->array_counts.find(index);
                    if ((entry != info->array_counts.end()) && (entry->second != replay_count))
                    {
                        GFXRECON_LOG_INFO("Replay adjusted the %s array count: capture count = %" PRIuPTR
                                          ", replay count = %" PRIuPTR,
                                          func_name,
                                          static_cast<size_t>(replay_count),
                                          entry->second);
                        replay_count = static_cast<CountT>(entry->second);
                    }
                }
            }
        }

        return replay_count;
    }

  private:
    struct QueueSubmitInfo
    {
        format::CommandIndexType        command_id;
        std::vector<CommandBufferInfo*> command_buffers;
        format::HandleId                queue;
    };

    VulkanObjectInfoTable        object_info_table_;
    std::vector<QueueSubmitInfo> queue_submissions;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
