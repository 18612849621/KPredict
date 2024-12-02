#include "memory/memory_allocator.h"
#include "glog/logging.h"
#include <cstring>

void MemoryAllocator::Memcpy(void *dst, void *src, size_t bytes_num,
                             MemcpyMode copy_mode) {
  switch (copy_mode) {
  case MemcpyMode::kMemcpyHostToHost: {
    memcpy(dst, src, bytes_num);
    break;
  }
  case MemcpyMode::kMemcpyHostToDevice: {
    // 这里你可以调用设备相关的内存复制函数
    // 例如 CUDA 的 cudaMemcpy
    // cudaMemcpy(dst, src, bytes_num, cudaMemcpykHostToDevice);
    break;
  }
  case MemcpyMode::kMemcpyDeviceToHost: {
    // 同样，处理 Device-to-Host 的复制
    // cudaMemcpy(dst, src, bytes_num, cudaMemcpyDeviceToHost);
    break;
  }
  case MemcpyMode::kMemcpyDeviceToDevice: {
    // 处理 Device-to-Device 的复制
    // cudaMemcpy(dst, src, bytes_num, cudaMemcpyDeviceToDevice);
    break;
  }
  default: {
    LOG(ERROR) << static_cast<int>(copy_mode) << "Unknown copy mode!";
    break;
  }
  }
}

void MemoryAllocator::MemsetZero(void *ptr, size_t bytes_num,
                                 DeviceType device_type) {
  switch (device_type) {
    // 默认CPU内存 set zero
  case DeviceType::KDeviceCPU: {
    memset(ptr, 0, bytes_num);
    break;
  }
  default: {
    break;
  }
  }
}
