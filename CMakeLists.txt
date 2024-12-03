cmake_minimum_required(VERSION 3.10)
project(KPredict)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# compile env
# import
find_package(Threads REQUIRED)
find_package(CUDA REQUIRED)
include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)
# include
set(COMMON_INCLUDE_DIRS /usr/include)
set(TEST_INCLUDE_DIRS /usr/local/include/gmock /usr/local/include/gtest)
set(HEADER_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
# library
find_library_if_exists(/usr/lib/x86_64-linux-gnu/libglog.so /usr/local/lib64/libglog.a GLOG_LIBRARY)
message(STATUS "GLOG Library found at: ${GLOG_LIBRARY}")
set(TEST_LIBRARY /usr/local/lib/libgmock.a /usr/local/lib/libgtest.a)

add_subdirectory(src)
add_subdirectory(test)
