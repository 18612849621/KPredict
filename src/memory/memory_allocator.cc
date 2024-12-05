#include "memory/memory_allocator.h"

#include <cstring>

#include "glog/logging.h"
#include "utils/utils.h"

void MemoryAllocator::Memcpy(void *dst, void *src, size_t byte_num, MemcpyMode copy_mode) {
  switch (copy_mode) {
    case MemcpyMode::kMemcpyHostToHost: {
      memcpy(dst, src, byte_num);
      break;
    }
    case MemcpyMode::kMemcpyHostToDevice: {
      CHECK_CUDA(cudaMemcpy(dst, src, byte_num, cudaMemcpyHostToDevice));
      break;
    }
    case MemcpyMode::kMemcpyDeviceToHost: {
      CHECK_CUDA(cudaMemcpy(dst, src, byte_num, cudaMemcpyDeviceToHost));
      break;
    }
    case MemcpyMode::kMemcpyDeviceToDevice: {
      CHECK_CUDA(cudaMemcpy(dst, src, byte_num, cudaMemcpyDeviceToDevice));
      break;
    }
    default: {
      LOG(ERROR) << "Unknown copy mode.";
      break;
    }
  }
}

void MemoryAllocator::MemsetZero(void *ptr, size_t byte_num, DeviceType device_type) {
  switch (device_type) {
    // 默认CPU内存 set zero
    case DeviceType::KDeviceCPU: {
      memset(ptr, 0, byte_num);
      break;
    }
    case DeviceType::KDeviceGPU: {
      cudaMemset(ptr, 0, byte_num);
      break;
    }
    default: {
      LOG(ERROR) << "Unknown device type.";
      break;
    }
  }
}
