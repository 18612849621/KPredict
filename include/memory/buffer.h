#pragma once
#include "memory_allocator.h"
#include "utils/utils.h"
#include "utils/utils_enum.h"
#include <memory>

class buffer {
public:
  explicit buffer() = default;

private:
  std::shared_ptr<MemoryAllocator> mem_allocator_;
  DeviceType device_type_;
};