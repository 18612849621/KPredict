include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CUDA_INCLUDE_DIRS}
)

add_library(lib_memory STATIC
    memory/buffer.cc
    memory/memory_allocator.cc
    memory/host_memory_allocator.cc
    memory/device_memory_allocator.cc
)

add_library(lib_utils STATIC
    utils/utils.cc
)

target_link_libraries(
    lib_memory PUBLIC 
    # ${CUDA_CUDA_LIBRARY} 
    ${CUDA_CUDART_LIBRARY}
)

