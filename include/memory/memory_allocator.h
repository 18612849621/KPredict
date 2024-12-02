#pragma once
#include "utils/utils.h"
#include <cstddef>

class MemoryAllocator {
public:
  MemoryAllocator() = default;
  virtual ~MemoryAllocator() = default;
  virtual void *Allocate(size_t) const = 0;
  virtual void Deallocate(void *) const = 0;
  virtual void Memcpy(void *dst, void *src, size_t bytes_num,
                      MemcpyMode copy_mode = MemcpyMode::kMemcpyHostToHost);

protected:
  DeviceType device_type_ = DeviceType::kDeviceUnknown;
};

class HostMemoryAllocator : public MemoryAllocator {
public:
  static HostMemoryAllocator &GetOrNewInstance() {
    static HostMemoryAllocator instance;
    return instance;
  }
  void *Allocate(size_t) const override;
  void Deallocate(void *) const override;

private:
  HostMemoryAllocator();
  ~HostMemoryAllocator() override;
};