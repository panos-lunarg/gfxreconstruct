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

#ifndef VULKAN_FRAME_INSPECTOR_CONSUMER_CLIENT_OBJECT_TABLE_H
#define VULKAN_FRAME_INSPECTOR_CONSUMER_CLIENT_OBJECT_TABLE_H

#include "decode/vulkan_frame_inspector_client_object_info.h"
#include "util/logging.h"

#include <memory>
#include <inttypes.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanFrameInspectorObjectTable
{
  public:
    void AddObject(std::unique_ptr<FIVulkanObjectInfo> obj)
    {
        const format::HandleId id         = obj->id;
        auto                   new_object = objects_.insert(std::make_pair(obj->id, std::move(obj)));
        if (new_object.second == false)
        {
            GFXRECON_LOG_WARNING("Dublicate entry for object %" PRId64, id);
        }
    }

    void DeleteObject(format::HandleId id)
    {
        auto obj_it = objects_.find(id);
        if (obj_it != objects_.end())
        {
            obj_it->second.reset();
        }
    }

    void AddPool(std::unique_ptr<FIVulkanPoolInfo> pool)
    {
        assert(pool_objects_.find(pool->id) == pool_objects_.end());

        auto new_pool = pool_objects_.insert(std::make_pair(pool->id, std::move(pool)));
        if (new_pool.second == false)
        {
            GFXRECON_LOG_WARNING("Dublicate entry for pool %" PRId64, pool->id);
        }
    }

    void DeletePool(format::HandleId id)
    {
        auto pool_it = pool_objects_.find(id);
        if (pool_it != pool_objects_.end())
        {
            FIVulkanPoolInfo* pool_obj = pool_it->second.get();
            for (auto& obj : pool_obj->child_ids)
            {
                DeleteObject(obj);
            }

            pool_obj->child_ids.clear();
            pool_it->second.reset();
            pool_objects_.erase(pool_it);
        }
    }

    void AddPoolObject(format::HandleId pool_id, std::unique_ptr<FIVulkanPoolObjectInfo> obj)
    {
        assert(objects_.find(obj->id) == objects_.end());

        const format::HandleId obj_id = obj->id;

        auto new_obj = objects_.insert(std::make_pair(obj->id, std::move(obj)));
        if (new_obj.second == false)
        {
            GFXRECON_LOG_WARNING("Dublicate entry for pool object %" PRId64, obj->id);
            return;
        }

        auto pool_it = pool_objects_.find(pool_id);
        if (pool_it != pool_objects_.end())
        {
            FIVulkanPoolInfo* pool   = pool_it->second.get();
            auto              new_id = pool->child_ids.insert(obj_id);
            if (new_id.second == false)
            {
                GFXRECON_LOG_WARNING("Dublicate entry in pool % " PRId64 " for object %" PRId64, pool->id, obj->id);
            }
        }
    }

    void DeletePoolObject(format::HandleId pool_id, format::HandleId object_id)
    {
        auto pool_it = pool_objects_.find(pool_id);
        if (pool_it != pool_objects_.end())
        {
            FIVulkanPoolInfo* pool        = pool_it->second.get();
            auto              pool_obj_it = pool->child_ids.find(object_id);
            if (pool_obj_it != pool->child_ids.end())
            {
                pool->child_ids.erase(pool_obj_it);
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("%s: Pool %" PRIu64 " was not found", __func__, pool_id);
        }

        auto pool_obj_it = objects_.find(object_id);
        if (pool_obj_it != objects_.end())
        {
            objects_.erase(pool_obj_it);
        }
        else
        {
            GFXRECON_LOG_WARNING("%s: Object %" PRIu64 " was not found", __func__, object_id);
        }
    }

    FIVulkanObjectInfo* GetObject(format::HandleId id)
    {
        auto obj = objects_.find(id);
        if (obj == objects_.end())
        {
            return nullptr;
        }
        else
        {
            return obj->second.get();
        }
    }

    FIVulkanPoolInfo* GetPool(format::HandleId id)
    {
        auto pool = pool_objects_.find(id);
        if (pool == pool_objects_.end())
        {
            return nullptr;
        }
        else
        {
            return pool->second.get();
        }
    }

  private:
    std::unordered_map<format::HandleId, std::unique_ptr<FIVulkanObjectInfo>> objects_;
    std::unordered_map<format::HandleId, std::unique_ptr<FIVulkanPoolInfo>>   pool_objects_;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* VULKAN_FRAME_INSPECTOR_CONSUMER_CLIENT_OBJECT_TABLE_H */