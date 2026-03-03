/*
** Copyright (c) 2026 LunarG, Inc.
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

#include <android/log.h>
#include "sigaction_wrapper.h"
#include <csignal>
#include <assert.h>
#include <dlfcn.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

#define APPNAME "gfxrecon"

struct sigaction s_original_sigsegv_handler = {};
struct sigaction s_last_sigsegv_handler     = {};

#define PRINTF_VERBOSE(...) __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, __VA_ARGS__);
#define PRINTF_ERROR(...) __android_log_print(ANDROID_LOG_ERROR, APPNAME, __VA_ARGS__);

static void print_dl_addr_info(const void* addr)
{
    PRINTF_VERBOSE("%s(%p)", __func__, addr);

    if (nullptr == addr)
    {
        return;
    }

    Dl_info addr_info = {};
    dladdr(addr, &addr_info);
    PRINTF_VERBOSE("  dli_fname: %s", addr_info.dli_fname ? addr_info.dli_fname : "null");
    PRINTF_VERBOSE("  dli_fbase: %p", addr_info.dli_fbase);
    PRINTF_VERBOSE("  dli_sname: %s", addr_info.dli_sname ? addr_info.dli_sname : "null");
    PRINTF_VERBOSE("  dli_saddr: %p", addr_info.dli_saddr);
}

extern "C"
{
    using sigaction_fp_t                      = int (*)(int, const struct sigaction*, struct sigaction*);
    sigaction_fp_t             real_sigaction = nullptr;

    static void sigaction_init(const struct sigaction* act, struct sigaction* old_act)
    {
        PRINTF_VERBOSE("%s()", __func__);

        real_sigaction = reinterpret_cast<sigaction_fp_t>(dlsym(RTLD_NEXT, "sigaction"));
        if (nullptr == real_sigaction)
        {
            PRINTF_VERBOSE("dlsym error: %s\n", dlerror());
        }

        int ret = real_sigaction(SIGSEGV, nullptr, &s_original_sigsegv_handler);
        if (ret)
        {
            PRINTF_ERROR("  calling real_sigaction failed: %s", dlerror());
        }

        PRINTF_VERBOSE("  s_original_sigsegv_handler.sa_sigaction: %p", s_original_sigsegv_handler.sa_sigaction);
        print_dl_addr_info(reinterpret_cast<void*>(s_original_sigsegv_handler.sa_sigaction));
        s_last_sigsegv_handler = s_original_sigsegv_handler;

        print_dl_addr_info(reinterpret_cast<void*>(act->sa_sigaction));
    }

    int sigaction(int signum, const struct sigaction* act, struct sigaction* old_act)
    {
        PRINTF_VERBOSE("%s(%d %p %p)", __func__, signum, act, old_act);

        if (nullptr == real_sigaction)
        {
            sigaction_init(act, old_act);
        }

        if (SIGSEGV == signum)
        {
            PRINTF_VERBOSE("  Not us");
            if (nullptr != act)
            {
                PRINTF_VERBOSE("   act->sa_sigaction: %p", act->sa_sigaction);
                print_dl_addr_info(reinterpret_cast<void*>(act->sa_sigaction));
            }

            if (nullptr != old_act)
            {
                *old_act = s_last_sigsegv_handler;
            }

            if (nullptr != act)
            {
                s_last_sigsegv_handler = *act;
            }

            return 0;
        }
        else if (GFXRECON_MEMPROT_SIGNAL == signum)
        {
            PRINTF_VERBOSE("  This is us");
            if (nullptr != act)
            {
                print_dl_addr_info(reinterpret_cast<void*>(act->sa_sigaction));
            }

            return real_sigaction(SIGSEGV, act, old_act);
        }
        else
        {
            return real_sigaction(signum, act, old_act);
        }
    }
} // extern "C"

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
