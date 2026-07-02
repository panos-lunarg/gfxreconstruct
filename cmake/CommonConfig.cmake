###############################################################################
# Copyright (c) 2018-2026 LunarG, Inc.
# Copyright (c) 2019-2020 Advanced Micro Devices, Inc.
# All rights reserved
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
#
# Author: LunarG Team
# Author: AMD Developer Tools Team
# Description: Platform-neutral configuration included by the root
#              CMakeLists.txt for both desktop and Android (NDK) builds.
#
# Precondition - the caller must already have:
#   * defined GFXRECON_SOURCE_DIR
#   * placed external/cmake-modules on CMAKE_MODULE_PATH
#     (needed for the GetGitRevisionDescription module included below)
###############################################################################

# ---- C++ standard --------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

# ---- Version numbers -----------------------------------------------------
set(GFXRECONSTRUCT_PROJECT_VERSION_MAJOR 1)
set(GFXRECONSTRUCT_PROJECT_VERSION_MINOR 0)
set(GFXRECONSTRUCT_PROJECT_VERSION_PATCH 5)

set(GFXRECON_PROJECT_VERSION_SHA1 "unknown-build-source")

# ---- Git revision / build designation ------------------------------------
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC GIT_SHA1)
git_get_exact_tag(GIT_TAG)
set(GIT_BRANCH "")

if (GIT_REFSPEC)
    string(REGEX REPLACE ".*/(.+)$" "\\1" GIT_BRANCH ${GIT_REFSPEC})
    string(COMPARE EQUAL ${GIT_BRANCH} "master" GIT_IS_MASTER)
    string(REGEX MATCH "^vulkan-sdk-[0-9]+\.[0-9]+\.[0-9]+$" GIT_IS_SDK ${GIT_BRANCH})

    if (GIT_IS_MASTER OR GIT_IS_SDK)
        if (GIT_TAG)
            set(GIT_BRANCH ${GIT_TAG})
        else ()
            set(GIT_BRANCH "")
        endif ()
        if (NOT DEFINED GFXRECON_PROJECT_VERSION_DESIGNATION)
            set(GFXRECON_PROJECT_VERSION_DESIGNATION "")
        endif ()
    elseif (NOT DEFINED GFXRECON_PROJECT_VERSION_DESIGNATION)
        set(GFXRECON_PROJECT_VERSION_DESIGNATION "-dev")
    endif ()
elseif (GIT_TAG)
    string(REGEX MATCH "^v[0-9]+\.[0-9]+\.[0-9]+$" GIT_IS_VERSION_RELEASE_TAG ${GIT_TAG})
    if (GIT_IS_VERSION_RELEASE_TAG)
        set(GIT_BRANCH ${GIT_TAG})
        set(GFXRECON_PROJECT_VERSION_DESIGNATION "")
    endif ()
elseif (NOT DEFINED GFXRECON_PROJECT_VERSION_DESIGNATION)
    set(GFXRECON_PROJECT_VERSION_DESIGNATION "-unknown")
endif ()

if (GIT_SHA1)
    string(SUBSTRING ${GIT_SHA1} 0 7 GFXRECON_PROJECT_VERSION_SHA1)

    if (GIT_BRANCH)
        string(CONCAT GFXRECON_PROJECT_VERSION_SHA1 ${GIT_BRANCH} ":" ${GFXRECON_PROJECT_VERSION_SHA1})
    endif ()

    git_local_changes(GIT_LOCAL_STATE)
    string(COMPARE EQUAL ${GIT_LOCAL_STATE} "DIRTY" GIT_DIRTY)
    if (GIT_DIRTY)
        string(CONCAT GFXRECON_PROJECT_VERSION_SHA1 ${GFXRECON_PROJECT_VERSION_SHA1} "*")
    endif ()
endif ()

# ---- project_version library ---------------------------------------------
# Isolate the repo SHA in a library to reduce the amount of recompilation on
# git commit, checkout, etc.  Clients should #include PROJECT_VERSION_HEADER_FILE
# and call GetProjectVersionString().

# Adds all the configure time information into project_version_temp.h.in
configure_file("${GFXRECON_SOURCE_DIR}/project_version.h.in" "${CMAKE_BINARY_DIR}/project_version_temp.h.in")

# Generate a "project_version_$<CONFIG>.h" for the current config - necessary to determine the current build configuration
file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/project_version_$<CONFIG>.h" INPUT "${CMAKE_BINARY_DIR}/project_version_temp.h.in")

# Since project_version_$<CONFIG>.h differs per build, set a compiler definition that files can use to include it
add_definitions(-DPROJECT_VERSION_HEADER_FILE="project_version_$<CONFIG>.h")

configure_file("${GFXRECON_SOURCE_DIR}/project_version_string.h.in" "${CMAKE_BINARY_DIR}/project_version_string.h")
add_library(project_version STATIC "${GFXRECON_SOURCE_DIR}/project_version.cpp")
target_include_directories(project_version PUBLIC "${CMAKE_BINARY_DIR}")
