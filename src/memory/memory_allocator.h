#pragma once

class MemoryAllocator {
public:
  MemoryAllocator() = default;
  virtual ~MemoryAllocator() = 0;
};