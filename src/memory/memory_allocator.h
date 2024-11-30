#pragma once
#include <cstddef>
enum class DeviceType : int { CPU = 0, GPU = 1, UNKNOWN = 2 };
class MemoryAllocator {
public:
  MemoryAllocator()                      = default;
  virtual ~MemoryAllocator()             = default;
  virtual void *Allocate(size_t) const   = 0;
  virtual void  Deallocate(void *) const = 0;

protected:
  DeviceType device_type_ = DeviceType::UNKNOWN;
};

class CpuMemoryAllocator : public MemoryAllocator {
public:
  static CpuMemoryAllocator &GetOrNewInstance() {
    static CpuMemoryAllocator instance;
    return instance;
  }
  void *Allocate(size_t) const override;
  void  Deallocate(void *) const override;

private:
  CpuMemoryAllocator();
  ~CpuMemoryAllocator() override;
};