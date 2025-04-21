/*
** Copyright (c) 2023 Valve Corporation
** Copyright (c) 2023 LunarG, Inc.
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

#include "util/page_guard_manager.h"
#include <cstdint>
#include <cstring>
#include <linux/fs.h>
#include <linux/userfaultfd.h>

#if USERFAULTFD_SUPPORTED == 1
#include "util/logging.h"
#include "util/platform.h"

#include <cassert>
#include <cinttypes>
#include <sys/syscall.h>
#include <sys/ioctl.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <poll.h>

// #define WRITE_PROTECT_WITH_UFFD

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

static const char* PAGEMAP_FILE = "/proc/self/pagemap";

void PageGuardManager::UffdTerminate()
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    for (auto& entry : memory_info_)
    {
        ReleaseTrackedMemory(&entry.second);
    }

    if (uffd_fd_ != -1)
    {
        if (close(uffd_fd_))
        {
            GFXRECON_LOG_ERROR("Error closing uffd_fd: %s (%d)", strerror(errno), errno);
        }
        uffd_fd_ = -1;
    }

    if (pagemap_fd_ != -1)
    {
        if (close(pagemap_fd_))
        {
            GFXRECON_LOG_ERROR("Error closing pagemap_fd: %s (%d)", strerror(errno), errno);
        }
        pagemap_fd_ = -1;
    }

    uffd_is_init_ = false;
}

bool PageGuardManager::UffdInit()
{
    assert(uffd_fd_ == -1);

    // open the userfault fd
    uffd_fd_ = static_cast<int>(syscall(SYS_userfaultfd, UFFD_USER_MODE_ONLY | O_NONBLOCK));
    if (uffd_fd_ == -1)
    {
        GFXRECON_LOG_ERROR("syscall/userfaultfd: %s", strerror(errno));
        return false;
    }

    // enable for api version and check features
    const uint64_t required_features[] = { UFFD_FEATURE_WP_ASYNC, UFFD_FEATURE_WP_UNPOPULATED };

    struct uffdio_api uffdio_api;
    uffdio_api.api      = UFFD_API;
    uffdio_api.features = 0;
    for (size_t i = 0; i < sizeof(required_features) / sizeof(required_features[0]); ++i)
    {
        uffdio_api.features |= required_features[i];
    }

    if (ioctl(uffd_fd_, UFFDIO_API, &uffdio_api) == -1)
    {
        GFXRECON_LOG_ERROR("ioctl/uffdio_api: %s", strerror(errno));
        return false;
    }

    if (uffdio_api.api != UFFD_API)
    {
        GFXRECON_LOG_ERROR("Unsupported userfaultfd api");
        return false;
    }

    for (size_t i = 0; i < sizeof(required_features) / sizeof(required_features[0]); ++i)
    {
        if ((uffdio_api.features & required_features[i]) != required_features[i])
        {
            GFXRECON_LOG_ERROR("Unsupported userfaultfd feature: 0x%" PRIx64 "\n", required_features[i]);
            return false;
        }
    }

    const uint64_t requested_ioctls[] = { 0x1 << _UFFDIO_REGISTER, 0x1 << _UFFDIO_UNREGISTER };
    for (size_t i = 0; i < sizeof(requested_ioctls) / sizeof(requested_ioctls[0]); ++i)
    {
        if ((uffdio_api.ioctls & requested_ioctls[i]) != requested_ioctls[i])
        {
            GFXRECON_LOG_ERROR("Unsupported userfaultfd ioctl: 0x%" PRIx64 "\n", requested_ioctls[i]);
            return false;
        }
    }

    return true;
}

bool PageGuardManager::InitializeUserFaultFd()
{
    assert(!uffd_is_init_);

    uffd_fd_    = -1;
    pagemap_fd_ = -1;

    if (!UffdInit())
    {
        assert(0);
        goto init_failed;
    }

    pagemap_fd_ = open(PAGEMAP_FILE, O_RDONLY);
    if (pagemap_fd_ == -1)
    {
        GFXRECON_LOG_ERROR("Error opening \"%s\": %s", PAGEMAP_FILE, strerror(errno));
        goto init_failed;
    }

    uffd_is_init_ = true;

    return true;

init_failed:
    UffdTerminate();
    return false;
}

static bool PageScanIoctl(int                 pagemap_fd,
                          uint64_t            flags,
                          struct page_region* output,
                          const void*         address,
                          size_t              n_pages,
                          size_t              page_size,
                          uint64_t            category,
                          uint64_t            ret_category,
                          uint64_t*           walk_end)
{
    GFXRECON_ASSERT(pagemap_fd != -1);

    struct pm_scan_arg arg;
    arg.size                = sizeof(struct pm_scan_arg);
    arg.flags               = flags;
    arg.start               = GFXRECON_PTR_TO_UINT64(address);
    arg.end                 = GFXRECON_PTR_TO_UINT64(address) + (n_pages * page_size);
    arg.walk_end            = 0;
    arg.vec                 = GFXRECON_PTR_TO_UINT64(output);
    arg.vec_len             = output ? n_pages : 0;
    arg.max_pages           = n_pages;
    arg.category_inverted   = 0;
    arg.category_mask       = category;
    arg.category_anyof_mask = 0;
    arg.return_mask         = ret_category;

    if (ioctl(pagemap_fd, PAGEMAP_SCAN, &arg) == -1)
    {
        GFXRECON_LOG_ERROR("ioctl/pagemap_scan failed: %s (%d)\n", strerror(errno), errno);
        GFXRECON_LOG_ERROR("arg.start: 0x%" PRIx64, arg.start);
        GFXRECON_LOG_ERROR("arg.end: 0x%" PRIx64, arg.end);
        GFXRECON_LOG_ERROR("n_pages: %" PRIu64, n_pages);
        return false;
    }

    if (walk_end != nullptr)
    {
        *walk_end = arg.walk_end;
    }

    return true;
}

bool PageGuardManager::UffdRegisterMemory(const void* address, size_t length)
{
    assert(uffd_fd_ != -1);

    if (!length || (length % system_page_size_))
    {
        GFXRECON_LOG_ERROR(
            "Attempting to register a memory region with a non page aligned length (%zu) (system's page size %zu).",
            length,
            system_page_size_);
    }

    if (!util::platform::IsAddressAligned(address, system_page_size_))
    {
        GFXRECON_LOG_ERROR("Attempting to register a memory region with non page aligned base address (%zu) (system's "
                           "page size: %zu).",
                           address,
                           system_page_size_);
    }

    // Register region to UFFD
    struct uffdio_register uffdio_register;
    uffdio_register.range.start = GFXRECON_PTR_TO_UINT64(address);
    uffdio_register.range.len   = length;
    uffdio_register.mode        = UFFDIO_REGISTER_MODE_WP;
    if (ioctl(uffd_fd_, UFFDIO_REGISTER, &uffdio_register) == -1)
    {
        GFXRECON_LOG_ERROR("ioctl/uffdio_register: %s (%d)", strerror(errno), errno);
        GFXRECON_LOG_ERROR("uffdio_register.range.start: 0x%" PRIx64, uffdio_register.range.start);
        GFXRECON_LOG_ERROR("uffdio_register.range.len: %" PRId64, uffdio_register.range.len);
        return false;
    }

    bool res;
#ifdef WRITE_PROTECT_WITH_UFFD
    // Write protect with UFFD
    struct uffdio_writeprotect uffd_write_protect;
    uffd_write_protect.range.start = GFXRECON_PTR_TO_UINT64(address);
    uffd_write_protect.range.len   = length;
    uffd_write_protect.mode        = UFFDIO_WRITEPROTECT_MODE_WP;
    if (ioctl(uffd_fd_, UFFDIO_WRITEPROTECT, &uffd_write_protect) == -1)
    {
        GFXRECON_LOG_ERROR("ioctl/uffdio_writeprotect: %s (%d)", strerror(errno), errno);
        GFXRECON_LOG_ERROR("uffd_write_protect.range.start: 0x%llx", uffd_write_protect.range.start);
        GFXRECON_LOG_ERROR("uffd_write_protect.range.len: %llu", uffd_write_protect.range.len);
        GFXRECON_LOG_ERROR("uffd_write_protect.mode: 0x%llx", uffd_write_protect.mode);
        res = false;
    }
    else
    {
        res = true;
    }
#else
    // Write protect with PAGEMAP_SCAN ioctl
    res = PageScanIoctl(pagemap_fd_,
                        PM_SCAN_WP_MATCHING,
                        NULL,
                        address,
                        length / system_page_size_,
                        system_page_size_,
                        PAGE_IS_WRITTEN,
                        0,
                        NULL);
#endif

    return res;
}

void PageGuardManager::UffdScanPages(const void*                    address,
                                     size_t                         n_pages,
                                     PageStatusTracker::PageStatus& active_writes,
                                     bool                           clear)
{
    GFXRECON_ASSERT(address != nullptr);
    GFXRECON_ASSERT(n_pages);
    GFXRECON_ASSERT(active_writes.size() == n_pages);
    GFXRECON_ASSERT(clear);

    page_region_output_.resize(n_pages);
    std::memset(page_region_output_.data(), 0, page_region_output_.size() * sizeof(struct page_region));

    uint64_t flags    = clear ? (PM_SCAN_WP_MATCHING | PM_SCAN_CHECK_WPASYNC) : PM_SCAN_CHECK_WPASYNC;
    uint64_t walk_end = 0;
    if (PageScanIoctl(pagemap_fd_,
                      flags,
                      page_region_output_.data(),
                      address,
                      n_pages,
                      system_page_size_,
                      PAGE_IS_WRITTEN,
                      PAGE_IS_WRITTEN,
                      &walk_end) == false)
    {
        return;
    }

    const size_t scanned_pages = (walk_end - GFXRECON_PTR_TO_UINT64(address)) / system_page_size_;
    if (scanned_pages != n_pages)
    {
        GFXRECON_LOG_WARNING("ioctl/pagemap_scan did not scan till end of region (scanned %zu pages instead of %zu)",
                             scanned_pages,
                             n_pages);
    }

    size_t active_write_page = 0;
    for (size_t i = 0; i < scanned_pages; ++i)
    {
        if (page_region_output_[i].start == 0 && page_region_output_[i].end == 0)
        {
            break;
        }

        GFXRECON_ASSERT(!(page_region_output_[i].start % system_page_size_));
        GFXRECON_ASSERT(!(page_region_output_[i].end % system_page_size_));
        GFXRECON_ASSERT(page_region_output_[i].end > page_region_output_[i].start);

        const size_t n_pages = (page_region_output_[i].end - page_region_output_[i].start) / system_page_size_;
        for (size_t p = 0; p < n_pages; ++p)
        {
            GFXRECON_ASSERT(page_region_output_[i].categories == PAGE_IS_WRITTEN);
            active_writes[active_write_page++] = 1;
        }
    }
}

void PageGuardManager::UffdUnregisterMemory(const void* address, size_t length)
{
    assert(uffd_fd_ != -1);

#ifdef WRITE_PROTECT_WITH_UFFD
    struct uffdio_range uffdio_unregister;
    uffdio_unregister.start = GFXRECON_PTR_TO_UINT64(address);
    uffdio_unregister.len   = static_cast<uint64_t>(length);
    if (ioctl(uffd_fd_, UFFDIO_UNREGISTER, &uffdio_unregister) == -1)
    {
        GFXRECON_LOG_ERROR("ioctl/uffdio_unregister: %s", strerror(errno));
        GFXRECON_LOG_ERROR("uffdio_unregister.start: 0x%" PRIx64, uffdio_unregister.start);
        GFXRECON_LOG_ERROR("uffdio_unregister.len: %" PRId64, uffdio_unregister.len);
    }
#else
    PageScanIoctl(
        pagemap_fd_, PM_SCAN_WP_MATCHING, nullptr, nullptr, length / system_page_size_, system_page_size_, 0, 0, NULL);
#endif
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(util)

#else

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

bool PageGuardManager::InitializeUserFaultFd()
{
    return false;
}

void PageGuardManager::UffdTerminate() {}

bool PageGuardManager::UffdRegisterMemory(const void* address, size_t length)
{
    GFXRECON_UNREFERENCED_PARAMETER(address);
    GFXRECON_UNREFERENCED_PARAMETER(length);

    return false;
}

void PageGuardManager::UffdUnregisterMemory(const void* address, size_t length)
{
    GFXRECON_UNREFERENCED_PARAMETER(address);
    GFXRECON_UNREFERENCED_PARAMETER(length);
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(util)

#endif // USERFAULTFD_SUPPORTED == 1
