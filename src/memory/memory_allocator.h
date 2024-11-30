#pragma once
#include <cstddef>

class MemoryAllocator {
  enum class DeviceType : int { CPU = 0, GPU = 1, UNKOWN = 2 };

public:
  MemoryAllocator()                      = default;
  virtual ~MemoryAllocator()             = 0;
  virtual void *Allocate(size_t) const   = 0;
  virtual void  Deallocate(void *) const = 0;

private:
  DeviceType device_type_ = DeviceType::UNKOWN;
};