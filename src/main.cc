#include <NvInfer.h>
#include <cassert>
#include <cuda_runtime_api.h>
#include <iostream>

class Logger : public nvinfer1::ILogger {
public:
  // 在这里添加 noexcept
  void log(Severity severity, const char *msg) noexcept override {
    if (severity != Severity::kINFO) // 只显示警告和错误信息
      std::cout << msg << std::endl;
  }
};

int main() {
  // 创建 Logger
  Logger logger;

  std::cout << "TensorRT installation is working correctly!" << std::endl;
  return 0;
}
