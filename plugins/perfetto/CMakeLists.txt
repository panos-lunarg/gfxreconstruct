add_library(perfetto STATIC ${CMAKE_CURRENT_LIST_DIR}/../external/perfetto/sdk/perfetto.cc)

add_subdirectory(capture)
add_subdirectory(replay)
