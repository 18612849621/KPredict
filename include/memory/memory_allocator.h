#pragma once
#include <cstddef>
#include <memory>

#include "glog/logging.h"
#include "utils/utils.h"
#include "utils/utils_enum.h"

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

class DeviceMemoryAllocator : public MemoryAllocator {
 public:
  explicit DeviceMemoryAllocator();
  void *Allocate(size_t) const override;
  void Deallocate(void *) const override;
  ~DeviceMemoryAllocator() override;
};

class MemoryAllocatorFactory {
 public:
  static std::shared_ptr<MemoryAllocator> GetInstance(DeviceType device_type) {
    switch (device_type) {
      case DeviceType::KDeviceCPU: {
        static std::shared_ptr<HostMemoryAllocator> allocator_ptr =
            std::make_shared<HostMemoryAllocator>();
        return allocator_ptr;
      }
      case DeviceType::KDeviceGPU: {
        static std::shared_ptr<DeviceMemoryAllocator> allocator_ptr =
            std::make_shared<DeviceMemoryAllocator>();
        return allocator_ptr;
      }
      default: {
        LOG(FATAL) << "Can't produce alloc from unknown device type.";
        break;
      }
    }
    return nullptr;
  };
};