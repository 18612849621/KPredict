#include "memory/buffer.h"

#include "glog/logging.h"

Buffer::Buffer(size_t byte_num, std::shared_ptr<MemoryAllocator> mem_allocator_, void *ptr)
    : byte_num_(byte_num), mem_allocator_(mem_allocator_), ptr_(ptr) {
  if (!ptr_ && mem_allocator_) {
    device_type_ = mem_allocator_->device_type();
    ptr_ = mem_allocator_->Allocate(byte_num_);
  }
}

Buffer::~Buffer() {
  if (ptr_ && mem_allocator_) {
    mem_allocator_->Deallocate(ptr_);
  }
}