#pragma once

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