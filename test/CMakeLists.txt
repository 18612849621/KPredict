# include
set(COMMON_INCLUDE_DIRS /usr/include)
set(GMOCK_INCLUDE_DIRS /usr/local/include/gmock)
set(GTEST_INCLUDE_DIRS /usr/local/include/gtest)
set(CUDA_INCLUDE_DIR /usr/local/cuda-11.8/include)
set(SRC_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src)
# library
set(GLOG_LIBRARY /usr/lib/x86_64-linux-gnu/libglog.so)
set(GMOCK_LIBRARY /usr/local/lib/libgmock.a)
set(GTEST_LIBRARY /usr/local/lib/libgtest.a)

find_package(Threads REQUIRED)

# include
include_directories(
    ${COMMON_INCLUDE_DIRS}
    ${CUDA_INCLUDE_DIR}
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
    ${SRC_INCLUDE_DIR}
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
    # src
    lib_memory
)

