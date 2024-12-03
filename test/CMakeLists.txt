# include
set(COMMON_INCLUDE_DIRS /usr/include)
set(GMOCK_INCLUDE_DIRS /usr/local/include/gmock)
set(GTEST_INCLUDE_DIRS /usr/local/include/gtest)
set(CUDA_INCLUDE_DIR /usr/local/cuda-11.8/include)
set(HEADER_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
# library
# set(GLOG_LIBRARY /usr/local/lib64/libglog.so)
set(GLOG_LIBRARY /usr/local/lib64/libglog.a)
set(GMOCK_LIBRARY /usr/local/lib/libgmock.a)
set(GTEST_LIBRARY /usr/local/lib/libgtest.a)

find_package(Threads REQUIRED)

# include
include_directories(
    ${COMMON_INCLUDE_DIRS}
    ${CUDA_INCLUDE_DIR}
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
    ${HEADER_INCLUDE_DIR}
)

# exe
add_executable(test_main test_main.cc)

# link
target_link_libraries(
    test_main PRIVATE
    ${GLOG_LIBRARY}
    ${GMOCK_LIBRARY}
    ${GTEST_LIBRARY}
    Threads::Threads
    # KPredict
    lib_memory
    lib_utils
)

