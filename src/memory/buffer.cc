#include "memory/buffer.h"

#include "glog/logging.h"

Buffer::Buffer(size_t byte_num, std::shared_ptr<MemoryAllocator> mem_allocator_, void *ptr)
    : byte_num_(byte_num), mem_allocator_(mem_allocator_), mem_ptr_(ptr) {
  // 注意这里是外部传入了一个 mem ptr 我们这里就不需要再次分配了相当于用 Buffer 类将该内存管理起来了
  if (!mem_ptr_ && mem_allocator_) {
    device_type_ = mem_allocator_->device_type();
    mem_ptr_ = mem_allocator_->Allocate(byte_num_);
  }
}

Buffer::~Buffer() {
  if (mem_ptr_ && mem_allocator_) {
    mem_allocator_->Deallocate(mem_ptr_);
  }
}