#pragma once
#include <cstddef>

enum class DeviceType : int { CPU = 0, GPU = 1, UNKNOWN = 2 };
enum class kMemcpyMode : int {
  HostToHost     = 0,
  HostToDevice   = 1,
  DeviceToHost   = 2,
  DeviceToDevice = 3
};

class MemoryAllocator {
public:
  MemoryAllocator()                      = default;
  virtual ~MemoryAllocator()             = default;
  virtual void *Allocate(size_t) const   = 0;
  virtual void  Deallocate(void *) const = 0;
  virtual void  Memcpy(void *dst, void *src, size_t bytes_num);

protected:
  DeviceType device_type_ = DeviceType::UNKNOWN;
};

class HostMemoryAllocator : public MemoryAllocator {
public:
  static HostMemoryAllocator &GetOrNewInstance() {
    static HostMemoryAllocator instance;
    return instance;
  }
  void *Allocate(size_t) const override;
  void  Deallocate(void *) const override;

private:
  HostMemoryAllocator();
  ~HostMemoryAllocator() override;
};