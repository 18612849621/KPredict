

# include
include_directories(
    ${COMMON_INCLUDE_DIRS}
    ${CUDA_INCLUDE_DIRS}
    ${TEST_INCLUDE_DIRS}
    ${HEADER_INCLUDE_DIR}
)

# exe
add_executable(test_main test_main.cc)

# link
target_link_libraries(
    test_main PRIVATE
    ${GLOG_LIBRARY}
    ${TEST_LIBRARY}
    Threads::Threads
)

add_executable(test_memory test_memory.cc)

target_link_libraries(
    test_memory PRIVATE
    ${GLOG_LIBRARY}
    ${TEST_LIBRARY}
    Threads::Threads
    # KPredict
    lib_memory
    lib_utils
)