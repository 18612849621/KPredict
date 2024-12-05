#include "memory/buffer.h"

#include "glog/logging.h"
#include "utils/utils_enum.h"

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

MemcpyMode Buffer::GetMemCopyMode(DeviceType buffer_device_type) const {
  DeviceType this_device_type = this->GetDeviceType();
  if (this_device_type == DeviceType::KDeviceCPU && buffer_device_type == DeviceType::KDeviceGPU) {
    return MemcpyMode::kMemcpyDeviceToHost;
  } else if (this_device_type == DeviceType::KDeviceGPU &&
             buffer_device_type == DeviceType::KDeviceGPU) {
    return MemcpyMode::kMemcpyDeviceToDevice;
  } else if (this_device_type == DeviceType::KDeviceGPU &&
             buffer_device_type == DeviceType::KDeviceCPU) {
    return MemcpyMode::kMemcpyHostToDevice;
  }
  // 默认纯cpu拷贝
  return MemcpyMode::kMemcpyHostToHost;
}

bool Buffer::CopyFrom(Buffer &buffer) {
  if (mem_allocator_ == nullptr) return false;
  if (buffer.GetMemPtr() == nullptr) return false;
  // 暂时使用字节数硬截断作为copy的手段
  size_t real_byte_num = buffer.GetBufferByteSize() > this->GetBufferByteSize()
                             ? this->GetBufferByteSize()
                             : buffer.GetBufferByteSize();
  mem_allocator_->Memcpy(this->mem_ptr_, buffer.GetMemPtr(), real_byte_num,
                         GetMemCopyMode(buffer.GetDeviceType()));
  return true;
}
bool Buffer::CopyFrom(Buffer *buffer) {
  if (mem_allocator_ == nullptr) return false;
  if (buffer->GetMemPtr() == nullptr) return false;
  DeviceType buffer_device_type = buffer->GetDeviceType();
  // 暂时使用字节数硬截断作为copy的手段
  size_t real_byte_num = buffer->GetBufferByteSize() > this->GetBufferByteSize()
                             ? this->GetBufferByteSize()
                             : buffer->GetBufferByteSize();
  mem_allocator_->Memcpy(this->mem_ptr_, buffer->GetMemPtr(), real_byte_num,
                         GetMemCopyMode(buffer->GetDeviceType()));
  return true;
}