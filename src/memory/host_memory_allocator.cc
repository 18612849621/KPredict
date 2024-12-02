#include "glog/logging.h"
#include "memory/memory_allocator.h"

HostMemoryAllocator::HostMemoryAllocator() {
  device_type_ = DeviceType::KDeviceCPU;
  LOG(INFO) << "HostMemoryAllocator create.";
}

HostMemoryAllocator::~HostMemoryAllocator() {
  LOG(INFO) << "HostMemoryAllocator destory.";
}

void *HostMemoryAllocator::Allocate(size_t bytes_num) const {
  if (!bytes_num) {
    return nullptr;
  }
  void *mem_chunk = malloc(bytes_num);
  return mem_chunk;
}

void HostMemoryAllocator::Deallocate(void *ptr) const {
  if (ptr) {
    free(ptr);
  }
}