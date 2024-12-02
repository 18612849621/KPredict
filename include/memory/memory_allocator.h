#pragma once
#include "utils/utils.h"
#include "utils/utils_enum.h"
#include <cstddef>

class MemoryAllocator {
public:
  explicit MemoryAllocator() = default;
  virtual ~MemoryAllocator() = default;
  virtual void *Allocate(size_t) const = 0;
  virtual void Deallocate(void *) const = 0;
  virtual void Memcpy(void *dst, void *src, size_t bytes_num,
                      MemcpyMode copy_mode = MemcpyMode::kMemcpyHostToHost);
  virtual void MemsetZero(void *ptr, size_t bytes_num,
                          DeviceType device_type = DeviceType::KDeviceCPU);
  virtual DeviceType device_type() const { return device_type_; }

protected:
  DeviceType device_type_ = DeviceType::kDeviceUnknown;
};

class HostMemoryAllocator : public MemoryAllocator {
public:
  explicit HostMemoryAllocator();
  void *Allocate(size_t) const override;
  void Deallocate(void *) const override;
  ~HostMemoryAllocator() override;
};