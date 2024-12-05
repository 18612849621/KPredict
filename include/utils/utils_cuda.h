#pragma once
#include "cuda_runtime.h"
#include "glog/logging.h"

#define CHECK_CUDA(state)                                         \
  do {                                                           \
    if (state != cudaSuccess) {                                  \
      LOG(ERROR) << "CUDA Error: " << cudaGetErrorString(state); \
    }                                                            \
  } while (0)
