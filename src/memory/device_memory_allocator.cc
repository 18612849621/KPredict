#include <cuda.h>

#include "glog/logging.h"
#include "memory/memory_allocator.h"

DeviceMemoryAllocator::DeviceMemoryAllocator() {
  device_type_ = DeviceType::KDeviceGPU;
  LOG(INFO) << "DeviceMemoryAllocator create.";
}

DeviceMemoryAllocator::~DeviceMemoryAllocator() { LOG(INFO) << "DeviceMemoryAllocator destory."; }

void *DeviceMemoryAllocator::Allocate(size_t byte_num) const {
  if (!byte_num) {
    return nullptr;
  }
  void *mem_chunk = malloc(byte_num);
  return mem_chunk;
}

void DeviceMemoryAllocator::Deallocate(void *ptr) const {
  if (ptr) {
    free(ptr);
    ptr = nullptr;
  }
}
