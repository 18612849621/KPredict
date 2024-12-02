#pragma once
#include <ostream>

enum class DeviceType : int {
  KDeviceCPU = 0,
  KDeviceGPU = 1,
  kDeviceUnknown = 2
};

enum class MemcpyMode : int {
  kMemcpyHostToHost = 0,
  kMemcpyHostToDevice = 1,
  kMemcpyDeviceToHost = 2,
  kMemcpyDeviceToDevice = 3
};

inline std::ostream &operator<<(std::ostream &os,
                                const DeviceType &device_type) {
  switch (device_type) {
  case DeviceType::KDeviceCPU:
    os << "KDeviceCPU";
    break;
  case DeviceType::KDeviceGPU:
    os << "KDeviceGPU";
    break;
  case DeviceType::kDeviceUnknown:
    os << "kDeviceUnknown";
    break;
  default:
    os << "Unknown DeviceType";
    break;
  }
  return os;
}
