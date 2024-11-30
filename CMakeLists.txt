cmake_minimum_required(VERSION 3.10)
project(KPredict)

# 强制使用 C++20 标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 添加包含目录
include_directories("/usr/local/cuda-11.8/include")

# 添加可执行文件
add_executable(test src/main.cc)

