#include <cuda.h>
#include <cuda_runtime.h>

#include "glog/logging.h"
#include "memory/memory_allocator.h"
#include "utils/utils.h"

DeviceMemoryAllocator::DeviceMemoryAllocator() {
  device_type_ = DeviceType::KDeviceGPU;
  LOG(INFO) << "DeviceMemoryAllocator create.";
}

DeviceMemoryAllocator::~DeviceMemoryAllocator() { LOG(INFO) << "DeviceMemoryAllocator destory."; }

void *DeviceMemoryAllocator::Allocate(size_t byte_num) const {
  if (!byte_num) {
    return nullptr;
  }
  void *ptr = nullptr;
  CheckCUDA(cudaMalloc(&ptr, byte_num));
  return ptr;
}

void DeviceMemoryAllocator::Deallocate(void *ptr) const {
  if (ptr) {
    cudaFree(ptr);
  }
}
