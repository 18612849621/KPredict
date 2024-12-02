#include "memory/memory_allocator.h"
#include "glog/logging.h"
#include <cstring>

void MemoryAllocator::Memcpy(void *dst, void *src, size_t bytes_num,
                             kMemcpyMode copy_mode) {
  switch (copy_mode) {
  case kMemcpyMode::HostToHost: {
    memcpy(dst, src, bytes_num);
    break;
  }
  case kMemcpyMode::HostToDevice: {
    // 这里你可以调用设备相关的内存复制函数
    // 例如 CUDA 的 cudaMemcpy
    // cudaMemcpy(dst, src, bytes_num, cudaMemcpyHostToDevice);
    break;
  }
  case kMemcpyMode::DeviceToHost: {
    // 同样，处理 Device-to-Host 的复制
    // cudaMemcpy(dst, src, bytes_num, cudaMemcpyDeviceToHost);
    break;
  }
  case kMemcpyMode::DeviceToDevice: {
    // 处理 Device-to-Device 的复制
    // cudaMemcpy(dst, src, bytes_num, cudaMemcpyDeviceToDevice);
    break;
  }
  default:
    LOG(ERROR) << static_cast<int>(copy_mode) << "Unknown copy mode!";
    break;
  }
}
