#pragma once
#include "memory_allocator.h"
#include "utils/utils.h"
#include "utils/utils_enum.h"
#include <memory>

class buffer {
public:
  explicit buffer() = default;
  explicit buffer(size_t byte_num,
                  std::shared_ptr<MemoryAllocator> allocator = nullptr,
                  void *ptr = nullptr);
  virtual ~buffer();

private:
  std::shared_ptr<MemoryAllocator> mem_allocator_;
  DeviceType device_type_;
  void *ptr_;
  size_t byte_size_;
};