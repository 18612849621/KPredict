#include "glog/logging.h"
#include "memory_allocator.h"

CpuMemoryAllocator::CpuMemoryAllocator() {
  device_type_ = DeviceType::CPU;
  LOG(INFO) << "CpuMemoryAllocator create.";
}

CpuMemoryAllocator::~CpuMemoryAllocator() {
  LOG(INFO) << "CpuMemoryAllocator destory.";
}

void *CpuMemoryAllocator::Allocate(size_t bytes_num) const {
  return malloc(bytes_num);
}

void CpuMemoryAllocator::Deallocate(void *ptr) const { free(ptr); }