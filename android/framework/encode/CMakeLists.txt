add_library(gfxrecon_encode STATIC "")

target_sources(gfxrecon_encode
               PRIVATE
                   ${GFXRECON_SOURCE_DIR}/framework/encode/capture_manager.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/capture_manager.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/capture_settings.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/capture_settings.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_encoder_commands.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_api_call_encoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_api_call_encoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_array_size_2d.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_command_buffer_util.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_struct_encoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_struct_encoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_struct_handle_wrappers.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_struct_handle_wrappers.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/descriptor_update_template_info.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/handle_unwrap_memory.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/parameter_buffer.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/parameter_encoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/struct_pointer_encoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_capture_manager.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_capture_manager.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_handle_wrappers.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_handle_wrapper_util.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_handle_wrapper_util.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_info.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_table_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_tracker.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_tracker.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_writer.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_writer.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/perfetto/perfetto_encoder_commands.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/perfetto/perfetto_encoder_commands.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/perfetto/perfetto_tracing_categories.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/perfetto/perfetto_tracing_categories.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_encode_pnext_struct.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_command_buffer_util.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_command_buffer_util.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_dispatch_table.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_wrappers.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_wrappers.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_state_table.h
              )

add_library(perfetto STATIC ${GFXRECON_SOURCE_DIR}/external/perfetto/perfetto.cc)

target_include_directories(gfxrecon_encode
                           PUBLIC
                               ${CMAKE_BINARY_DIR}
                               ${GFXRECON_SOURCE_DIR}/external/perfetto
                               ${GFXRECON_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_encode gfxrecon_graphics gfxrecon_format gfxrecon_util vulkan_registry platform_specific android perfetto)
