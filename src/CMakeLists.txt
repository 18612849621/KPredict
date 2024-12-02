include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_library(lib_memory STATIC
    memory/buffer.cc
    memory/memory_allocator.cc
    memory/host_memory_allocator.cc
)

add_library(lib_utils STATIC
    utils/utils.cc
)

