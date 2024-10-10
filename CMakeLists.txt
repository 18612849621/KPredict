cmake_minimum_required(VERSION 3.10)
project(KPredict)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# tensorrt 8.6
set(TENSORRT_DIR /usr/local/TensorRT-8.6.1.6) 
set(TENSORRT_INCLUDE_DIR ${TENSORRT_DIR}/include)
set(TENSORRT_LIB_DIR ${TENSORRT_DIR}/lib)

# 添加包含目录
include_directories(${TENSORRT_INCLUDE_DIR})
include_directories("/usr/local/cuda-11.8/include")

# 查找 TensorRT 库
find_library(NV_INFER_LIBRARY nvinfer PATHS ${TENSORRT_LIB_DIR})
find_library(NV_ONNXPARSER_LIBRARY nvonnxparser PATHS ${TENSORRT_LIB_DIR})
find_library(NV_PLUGIN_LIBRARY nvinfer_plugin PATHS ${TENSORRT_LIB_DIR})

# 添加可执行文件
add_executable(test src/main.cc)

# link
target_link_libraries(test ${NV_INFER_LIBRARY} ${NV_ONNXPARSER_LIBRARY} ${NV_PLUGIN_LIBRARY})

# compile_options
target_compile_options(test PRIVATE 
    -Wno-deprecated-declarations
)
