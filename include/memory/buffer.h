#pragma once
#include <memory>

#include "memory_allocator.h"
#include "utils/utils.h"
#include "utils/utils_enum.h"

class Buffer : public std::enable_shared_from_this<Buffer> {
 public:
  explicit Buffer() = default;
  explicit Buffer(size_t byte_num, std::shared_ptr<MemoryAllocator> mem_allocator_ = nullptr,
                  void *ptr = nullptr);
  virtual ~Buffer();
  virtual bool CopyFrom(Buffer &buffer);
  virtual bool CopyFrom(Buffer *buffer);
  virtual DeviceType GetDeviceType() const { return device_type_; };
  void *GetMemPtr() { return mem_ptr_; };
  size_t GetBufferByteSize() { return byte_num_; };
  std::shared_ptr<Buffer> SharedFromThis() { return shared_from_this(); };

 private:
  MemcpyMode GetMemCopyMode(DeviceType buffer_device_type) const;

 private:
  std::shared_ptr<MemoryAllocator> mem_allocator_;
  DeviceType device_type_;
  void *mem_ptr_;
  size_t byte_num_;
  DISALLOW_COPY_AND_ASSIGN(Buffer);
};