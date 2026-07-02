# Quest replay NativeActivity library, packaged into an APK by the Gradle
# module in this directory. Added by the repository-root CMakeLists.txt when
# configured with the Android NDK toolchain and OpenXR support is enabled
# (OpenXR is required for Quest).

add_library(gfxrecon-quest-replay
            SHARED
                ${GFXRECON_SOURCE_DIR}/tools/tool_settings.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/parse_dump_resources_cli.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/parse_dump_resources_cli.cpp
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_settings.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/recapture_vulkan_entry.cpp
                ${GFXRECON_SOURCE_DIR}/tools/replay/recapture_vulkan_entry.h
                ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_recapture_func_table.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_feature.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_main_common.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_main_common.cpp
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_openxr_feature.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_openxr_feature.cpp
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_vulkan_feature.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_vulkan_feature.cpp
                ${GFXRECON_SOURCE_DIR}/tools/replay/android_main.cpp)

target_include_directories(gfxrecon-quest-replay
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/external/precompiled/android/include
                               ${GFXRECON_SOURCE_DIR}
                               ${CMAKE_BINARY_DIR})

target_link_libraries(
        gfxrecon-quest-replay
        gfxrecon_application
        gfxrecon_decode
        gfxrecon_encode
        gfxrecon_graphics
        gfxrecon_format
        platform_specific
        project_version
        openxr_loader)

# ANativeActivity_onCreate lives in the static native_app_glue library and is
# only referenced at runtime via dlsym by the NativeActivity framework, so
# force the linker to keep and export it.
# Refer to: https://github.com/android-ndk/ndk/issues/381
target_link_options(gfxrecon-quest-replay PRIVATE "LINKER:-u,ANativeActivity_onCreate")
