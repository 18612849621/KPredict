#pragma once
#include <memory>

#include "memory_allocator.h"
#include "utils/utils.h"
#include "utils/utils_enum.h"

class Buffer {
 public:
  explicit Buffer() = default;
  explicit Buffer(size_t byte_num, std::shared_ptr<MemoryAllocator> mem_allocator_ = nullptr,
                  void *ptr = nullptr);
  virtual ~Buffer();

 private:
  std::shared_ptr<MemoryAllocator> mem_allocator_;
  DeviceType device_type_;
  void *ptr_;
  size_t byte_num_;
  DISALLOW_COPY_AND_ASSIGN(Buffer);
};