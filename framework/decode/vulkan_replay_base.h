/*
** Copyright (c) 2018-2020 Valve Corporation
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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_BASE_H
#define GFXRECON_DECODE_VULKAN_REPLAY_BASE_H

// #include "decode/vulkan_consumer_base.h"
#include "generated/generated_vulkan_consumer.h"
#include "graphics/vulkan_util.h"
#include "decode/vulkan_object_info_table.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_options.h"
#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const char kUnknownDeviceLabel[] = "<Unknown>";

class VulkanReplayBase : public VulkanConsumer
{
  public:
    VulkanReplayBase(const VulkanReplayOptions& options) :
        options_(options), loader_handle_(nullptr), get_instance_proc_addr_(nullptr), create_instance_proc_(nullptr),
        fatal_error_handler_(nullptr), loading_trim_state_(false)
    {}

    virtual ~VulkanReplayBase()
    {
        if (loader_handle_ != nullptr)
        {
            graphics::ReleaseLoader(loader_handle_);
        }
    }

    virtual void ProcessStateBeginMarker(uint64_t frame_number) override;

    virtual void ProcessStateEndMarker(uint64_t frame_number) override;

    virtual void ProcessFillMemoryCommand(format::CommandIndexType command_index,
                                          uint64_t                 memory_id,
                                          uint64_t                 offset,
                                          uint64_t                 size,
                                          const uint8_t*           data) override;

    void ProcessBeginResourceInitCommand(format::CommandIndexType command_index,
                                         format::HandleId         device_id,
                                         uint64_t                 max_resource_size,
                                         uint64_t                 max_copy_size) override;

    virtual void ProcessEndResourceInitCommand(format::CommandIndexType command_index,
                                               format::HandleId         device_id) override;

    virtual void ProcessInitBufferCommand(format::CommandIndexType command_index,
                                          format::HandleId         device_id,
                                          format::HandleId         buffer_id,
                                          uint64_t                 data_size,
                                          const uint8_t*           data) override;

    virtual void ProcessInitImageCommand(format::CommandIndexType     command_index,
                                         format::HandleId             device_id,
                                         format::HandleId             image_id,
                                         uint64_t                     data_size,
                                         uint32_t                     aspect,
                                         uint32_t                     layout,
                                         const std::vector<uint64_t>& level_sizes,
                                         const uint8_t*               data) override;

    virtual void
    ProcessCreateHardwareBufferCommand(format::CommandIndexType                            command_index,
                                       format::HandleId                                    memory_id,
                                       uint64_t                                            buffer_id,
                                       uint32_t                                            format,
                                       uint32_t                                            width,
                                       uint32_t                                            height,
                                       uint32_t                                            stride,
                                       uint64_t                                            usage,
                                       uint32_t                                            layers,
                                       const std::vector<format::HardwareBufferPlaneInfo>& plane_info) override;

    virtual void ProcessDestroyHardwareBufferCommand(format::CommandIndexType command_index,
                                                     uint64_t                 buffer_id) override;

    void SetFatalErrorHandler(std::function<void(const char*)> handler) { fatal_error_handler_ = handler; }

    const VulkanObjectInfoTable& GetObjectInfoTable() const { return object_info_table_; }

    VulkanObjectInfoTable& GetObjectInfoTable() { return object_info_table_; }

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

  protected:
    void                         InitializeLoader();
    void                         RaiseFatalError(const char* message) const;
    void                         AddInstanceTable(VkInstance instance);
    void                         AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa);
    const encode::DeviceTable*   GetDeviceTable(const void* handle) const;
    PFN_vkGetDeviceProcAddr      GetDeviceAddrProc(VkPhysicalDevice physical_device);
    PFN_vkCreateDevice           GetCreateDeviceProc(VkPhysicalDevice physical_device);
    const encode::InstanceTable* GetInstanceTable(const void* handle) const;
    void                         CheckResult(const char* func_name, VkResult original, VkResult replay);

    VkResult OverrideCreateDescriptorUpdateTemplate(
        PFN_vkCreateDescriptorUpdateTemplate                                      func,
        VkResult                                                                  original_result,
        const DeviceInfo*                                                         device_info,
        const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>*                         pDescriptorUpdateTemplate);

    void OverrideDestroyDescriptorUpdateTemplate(PFN_vkDestroyDescriptorUpdateTemplate func,
                                                 const DeviceInfo*                     device_info,
                                                 const DescriptorUpdateTemplateInfo*   descriptor_update_template_info,
                                                 const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideCreateDescriptorPool(PFN_vkCreateDescriptorPool func,
                                          VkResult                   original_result,
                                          const DeviceInfo*          device_info,
                                          const StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
                                          const StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
                                          HandlePointerDecoder<VkDescriptorPool>* pDescriptorPool);

    void OverrideDestroyDescriptorPool(PFN_vkDestroyDescriptorPool                                func,
                                       const DeviceInfo*                                          device_info,
                                       DescriptorPoolInfo*                                        descriptor_pool_info,
                                       const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideResetDescriptorPool(PFN_vkResetDescriptorPool  func,
                                         VkResult                   original_result,
                                         const DeviceInfo*          device_info,
                                         DescriptorPoolInfo*        pool_info,
                                         VkDescriptorPoolResetFlags flags);
    VkResult
    OverrideAllocateCommandBuffers(PFN_vkAllocateCommandBuffers                                     func,
                                   VkResult                                                         original_result,
                                   const DeviceInfo*                                                device_info,
                                   const StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
                                   HandlePointerDecoder<VkCommandBuffer>*                           pCommandBuffers);

    VkResult
    OverrideAllocateDescriptorSets(PFN_vkAllocateDescriptorSets                                     func,
                                   VkResult                                                         original_result,
                                   const DeviceInfo*                                                device_info,
                                   const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
                                   HandlePointerDecoder<VkDescriptorSet>*                           pDescriptorSets);

    VkResult OverrideGetFenceStatus(PFN_vkGetFenceStatus func,
                                    VkResult             original_result,
                                    const DeviceInfo*    device_info,
                                    const FenceInfo*     fence_info);

    VkResult OverrideCreateDevice(VkResult                                                   original_result,
                                  PhysicalDeviceInfo*                                        physical_device_info,
                                  const StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
                                  const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                  HandlePointerDecoder<VkDevice>*                            pDevice);

    void OverrideDestroyDevice(PFN_vkDestroyDevice                                        func,
                               const DeviceInfo*                                          device_info,
                               const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideEnumeratePhysicalDevices(PFN_vkEnumeratePhysicalDevices          func,
                                              VkResult                                original_result,
                                              InstanceInfo*                           instance_info,
                                              PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
                                              HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices);

    VkResult OverrideCreatePipelineCache(PFN_vkCreatePipelineCache                                      func,
                                         VkResult                                                       original_result,
                                         const DeviceInfo*                                              device_info,
                                         const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
                                         const StructPointerDecoder<Decoded_VkAllocationCallbacks>*     pAllocator,
                                         HandlePointerDecoder<VkPipelineCache>*                         pPipelineCache);

    VkResult OverrideGetPipelineCacheData(PFN_vkGetPipelineCacheData func,
                                          VkResult                   original_result,
                                          const DeviceInfo*          device_info,
                                          const PipelineCacheInfo*   pipeline_cache_info,
                                          PointerDecoder<size_t>*    pDataSize,
                                          PointerDecoder<uint8_t>*   pData);

    void OverrideGetPhysicalDeviceMemoryProperties(
        PFN_vkGetPhysicalDeviceMemoryProperties                         func,
        PhysicalDeviceInfo*                                             physical_device_info,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties);

    void OverrideGetPhysicalDeviceMemoryProperties2(
        PFN_vkGetPhysicalDeviceMemoryProperties2                         func,
        PhysicalDeviceInfo*                                              physical_device_info,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties);

    const VkAllocationCallbacks*
    GetAllocationCallbacks(const StructPointerDecoder<Decoded_VkAllocationCallbacks>* original_callbacks)
    {
        // Replay does not currently attempt emulate the captured application's use of VkAllocationCallbacks.
        GFXRECON_UNREFERENCED_PARAMETER(original_callbacks);
        return nullptr;
    }

    void InitializeResourceAllocator(const PhysicalDeviceInfo*       physical_device_info,
                                     VkDevice                        device,
                                     const std::vector<std::string>& enabled_device_extensions,
                                     VulkanResourceAllocator*        allocator);

    VkResult OverrideMapMemory(PFN_vkMapMemory   func,
                               VkResult          original_result,
                               const DeviceInfo* device_info,
                               DeviceMemoryInfo* memory_info,
                               VkDeviceSize      offset,
                               VkDeviceSize      size,
                               VkMemoryMapFlags  flags,
                               void**            ppData);

    void OverrideUnmapMemory(PFN_vkUnmapMemory func, const DeviceInfo* device_info, DeviceMemoryInfo* memory_info);

    VkResult OverrideFlushMappedMemoryRanges(PFN_vkFlushMappedMemoryRanges                            func,
                                             VkResult                                                 original_result,
                                             const DeviceInfo*                                        device_info,
                                             uint32_t                                                 memoryRangeCount,
                                             const StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges);

    VkResult
    OverrideInvalidateMappedMemoryRanges(PFN_vkInvalidateMappedMemoryRanges                       func,
                                         VkResult                                                 original_result,
                                         const DeviceInfo*                                        device_info,
                                         uint32_t                                                 memoryRangeCount,
                                         const StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges);

    void OverrideFreeMemory(PFN_vkFreeMemory                                           func,
                            const DeviceInfo*                                          device_info,
                            DeviceMemoryInfo*                                          memory_info,
                            const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideBindBufferMemory(PFN_vkBindBufferMemory func,
                                      VkResult               original_result,
                                      const DeviceInfo*      device_info,
                                      BufferInfo*            buffer_info,
                                      DeviceMemoryInfo*      memory_info,
                                      VkDeviceSize           memoryOffset);

    VkResult OverrideBindBufferMemory2(PFN_vkBindBufferMemory2                                     func,
                                       VkResult                                                    original_result,
                                       const DeviceInfo*                                           device_info,
                                       uint32_t                                                    bindInfoCount,
                                       const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos);

    VkResult OverrideBindImageMemory(PFN_vkBindImageMemory func,
                                     VkResult              original_result,
                                     const DeviceInfo*     device_info,
                                     ImageInfo*            image_info,
                                     DeviceMemoryInfo*     memory_info,
                                     VkDeviceSize          memoryOffset);

    VkResult OverrideBindImageMemory2(PFN_vkBindImageMemory2                                     func,
                                      VkResult                                                   original_result,
                                      const DeviceInfo*                                          device_info,
                                      uint32_t                                                   bindInfoCount,
                                      const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos);

    VkResult OverrideCreateBuffer(PFN_vkCreateBuffer                                         func,
                                  VkResult                                                   original_result,
                                  const DeviceInfo*                                          device_info,
                                  const StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
                                  const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                  HandlePointerDecoder<VkBuffer>*                            pBuffer);

    void OverrideDestroyBuffer(PFN_vkDestroyBuffer                                        func,
                               const DeviceInfo*                                          device_info,
                               BufferInfo*                                                buffer_info,
                               const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    VkResult OverrideCreateImage(PFN_vkCreateImage                                          func,
                                 VkResult                                                   original_result,
                                 const DeviceInfo*                                          device_info,
                                 const StructPointerDecoder<Decoded_VkImageCreateInfo>*     pCreateInfo,
                                 const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                 HandlePointerDecoder<VkImage>*                             pImage);

    void OverrideDestroyImage(PFN_vkDestroyImage                                         func,
                              const DeviceInfo*                                          device_info,
                              ImageInfo*                                                 image_info,
                              const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator);

    void OverrideGetImageSubresourceLayout(PFN_vkGetImageSubresourceLayout                         func,
                                           const DeviceInfo*                                       device_info,
                                           const ImageInfo*                                        image_info,
                                           const StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
                                           StructPointerDecoder<Decoded_VkSubresourceLayout>*      pLayout);

    VkResult OverrideAllocateMemory(PFN_vkAllocateMemory                                       func,
                                    VkResult                                                   original_result,
                                    const DeviceInfo*                                          device_info,
                                    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  pAllocateInfo,
                                    const StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                    HandlePointerDecoder<VkDeviceMemory>*                      pMemory);

    VkResult OverrideEnumeratePhysicalDeviceGroups(
        PFN_vkEnumeratePhysicalDeviceGroups                            func,
        VkResult                                                       original_result,
        InstanceInfo*                                                  instance_info,
        PointerDecoder<uint32_t>*                                      pPhysicalDeviceGroupCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties);

    void OverrideGetPhysicalDeviceProperties(PFN_vkGetPhysicalDeviceProperties func,
                                             PhysicalDeviceInfo*               physical_device_info,
                                             StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties);

    void OverrideGetPhysicalDeviceProperties2(PFN_vkGetPhysicalDeviceProperties2 func,
                                              PhysicalDeviceInfo*                physical_device_info,
                                              StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties);

    VkResult OverrideGetEventStatus(PFN_vkGetEventStatus func,
                                    VkResult             original_result,
                                    const DeviceInfo*    device_info,
                                    const EventInfo*     event_info);
    VkResult OverrideGetQueryPoolResults(PFN_vkGetQueryPoolResults func,
                                         VkResult                  original_result,
                                         const DeviceInfo*         device_info,
                                         const QueryPoolInfo*      query_pool_info,
                                         uint32_t                  firstQuery,
                                         uint32_t                  queryCount,
                                         size_t                    dataSize,
                                         PointerDecoder<uint8_t>*  pData,
                                         VkDeviceSize              stride,
                                         VkQueryResultFlags        flags);

  protected:
    // Can override PhysicalDeviceInfo::handle and PhysicalDeviceInfo::replay_device_info based on comparison between
    // capture and replay physical device properties or GPU override settings.
    void SelectPhysicalDevice(PhysicalDeviceInfo* physical_device_info);
    bool GetOverrideDevice(InstanceInfo* instance_info, PhysicalDeviceInfo* physical_device_info);
    void GetMatchingDevice(InstanceInfo* instance_info, PhysicalDeviceInfo* physical_device_info);
    void CheckReplayDeviceInfo(PhysicalDeviceInfo* physical_device_info);
    void SetPhysicalDeviceInstanceInfo(InstanceInfo*       instance_info,
                                       PhysicalDeviceInfo* physical_device_info,
                                       VkPhysicalDevice    replay_device);
    void CheckPhysicalDeviceCompatibility(PhysicalDeviceInfo* physical_device_info);
    void SelectPhysicalDeviceGroup(PhysicalDeviceInfo*                  physical_device_info,
                                   const std::vector<format::HandleId>& capture_device_group,
                                   std::vector<VkPhysicalDevice>&       replay_device_group);
    bool GetOverrideDeviceGroup(InstanceInfo*                  instance_info,
                                PhysicalDeviceInfo*            physical_device_info,
                                std::vector<VkPhysicalDevice>& replay_device_group);
    void GetMatchingDeviceGroup(InstanceInfo*                        instance_info,
                                PhysicalDeviceInfo*                  physical_device_info,
                                const std::vector<format::HandleId>& capture_device_group,
                                std::vector<VkPhysicalDevice>&       replay_device_group);
    void CheckPhysicalDeviceGroupCompatibility(InstanceInfo*                        instance_info,
                                               const std::vector<format::HandleId>& capture_device_group,
                                               const std::vector<VkPhysicalDevice>& replay_device_group);
    bool CheckTrimDeviceExtensions(VkPhysicalDevice physical_device, std::vector<std::string>* extensions);
    void SetInstancePhysicalDeviceEntries(InstanceInfo*           instance_info,
                                          size_t                  capture_device_count,
                                          const format::HandleId* capture_devices,
                                          size_t                  replay_device_count,
                                          const VkPhysicalDevice* replay_devices);
    void SetPhysicalDeviceProperties(PhysicalDeviceInfo*               physical_device_info,
                                     const VkPhysicalDeviceProperties* capture_properties,
                                     const VkPhysicalDeviceProperties* replay_properties);
    void GetImportedSemaphores(const HandlePointerDecoder<VkSemaphore>& semaphore_data,
                               std::vector<const SemaphoreInfo*>*       imported_semaphores);

    void GetImportedSemaphores(const StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* semaphore_info_data,
                               std::vector<const SemaphoreInfo*>*                         imported_semaphores);
    void GetShadowSemaphores(const HandlePointerDecoder<VkSemaphore>& semaphore_data,
                             std::vector<const SemaphoreInfo*>*       shadow_semaphores);

    void GetShadowSemaphores(const StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* semaphore_info_data,
                             std::vector<const SemaphoreInfo*>*                         shadow_semaphores);

    void TrackSemaphoreForwardProgress(const HandlePointerDecoder<VkSemaphore>& semaphore_data,
                                       std::vector<const SemaphoreInfo*>*       removed_semaphores);

    void TrackSemaphoreForwardProgress(const StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* semaphore_info_data,
                                       std::vector<const SemaphoreInfo*>*                         removed_semaphores);

    void GetNonForwardProgress(const HandlePointerDecoder<VkSemaphore>& semaphore_data,
                               std::vector<const SemaphoreInfo*>*       non_forward_progress_semaphores);

    void GetNonForwardProgress(const StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* semaphore_info_data,
                               std::vector<const SemaphoreInfo*>* non_forward_progress_semaphores);

    void SetPhysicalDeviceMemoryProperties(PhysicalDeviceInfo*                     physical_device_info,
                                           const VkPhysicalDeviceMemoryProperties* capture_properties,
                                           const VkPhysicalDeviceMemoryProperties* replay_properties);

    void* PreProcessExternalObject(uint64_t object_id, format::ApiCallId call_id, const char* call_name);

    void PostProcessExternalObject(
        VkResult replay_reslt, uint64_t object_id, void* object, format::ApiCallId call_id, const char* call_name);

    VkResult CreateSwapchainImage(const DeviceInfo*        device_info,
                                  const VkImageCreateInfo* image_create_info,
                                  VkImage*                 image,
                                  ImageInfo*               image_info);

    void ProcessImportAndroidHardwareBufferInfo(const Decoded_VkMemoryAllocateInfo* allocate_info);

  protected:
    struct HardwareBufferInfo
    {
        format::HandleId memory_id;
        AHardwareBuffer* hardware_buffer;
    };

    struct HardwareBufferPlaneInfo
    {
        uint64_t capture_offset;
        uint64_t replay_offset;
        uint32_t capture_row_pitch;
        uint32_t replay_row_pitch;
        uint32_t height;
    };

    struct HardwareBufferMemoryInfo
    {
        AHardwareBuffer*                     hardware_buffer;
        bool                                 compatible_strides;
        std::vector<HardwareBufferPlaneInfo> plane_info;
    };

    typedef std::unordered_map<uint64_t, HardwareBufferInfo>               HardwareBufferMap;
    typedef std::unordered_map<format::HandleId, HardwareBufferMemoryInfo> HardwareBufferMemoryMap;

    VulkanReplayOptions                                              options_;
    std::unordered_map<encode::DispatchKey, encode::DeviceTable>     device_tables_;
    util::platform::LibraryHandle                                    loader_handle_;
    std::unordered_map<encode::DispatchKey, PFN_vkGetDeviceProcAddr> get_device_proc_addrs_;
    PFN_vkGetInstanceProcAddr                                        get_instance_proc_addr_;
    std::unordered_map<encode::DispatchKey, PFN_vkCreateDevice>      create_device_procs_;
    PFN_vkCreateInstance                                             create_instance_proc_;
    std::unordered_map<encode::DispatchKey, encode::InstanceTable>   instance_tables_;
    std::function<void(const char*)>                                 fatal_error_handler_;
    VulkanObjectInfoTable                                            object_info_table_;
    HardwareBufferMap                                                hardware_buffers_;
    HardwareBufferMemoryMap                                          hardware_buffer_memory_info_;
    bool                                                             loading_trim_state_;

    // Used to track allocated external memory if replay uses VkImportMemoryHostPointerInfoEXT
    std::unordered_map<VkDeviceMemory, std::pair<void*, size_t>> external_memory_;

    // Used to track if any shadow sync objects are active to avoid checking if not needed
    std::unordered_set<VkSemaphore> shadow_semaphores_;
    std::unordered_set<VkFence>     shadow_fences_;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_DECODE_VULKAN_REPLAY_BASE_H */
