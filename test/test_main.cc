#include "memory/buffer.h"
#include "memory/memory_allocator.h"
#include "utils/utils.h"
#include "utils/utils_enum.h"
#include <glog/logging.h>
#include <gtest/gtest.h>
#include <iostream>

TEST(LogTest, PrintTest) {
  LOG(INFO) << "This is INFO.";
  LOG(WARNING) << "This is WARNING.";
  LOG(ERROR) << "This is ERROR.";
}

TEST(MemoryAllocatorTest, CpuTest) {
  char str[] = "Hello world, CPU!";
  size_t str_byte_size = sizeof(str);
  LOG(INFO) << str << " | 's size is " << str_byte_size << " bytes.";
  Buffer buffer(str_byte_size,
                MemoryAllocatorFactory::GetInstance(DeviceType::KDeviceCPU));
  MemoryAllocator *memory_allocator_ptr = new HostMemoryAllocator();
  LOG(INFO) << "Device type is " << memory_allocator_ptr->device_type();
  char *test_string =
      static_cast<char *>(memory_allocator_ptr->Allocate(str_byte_size));
  memory_allocator_ptr->Memcpy(test_string, str, str_byte_size);
  LOG(INFO) << "Before set zero [" << test_string << "]";
  memory_allocator_ptr->MemsetZero(test_string, str_byte_size);
  LOG(INFO) << "After set zero [" << test_string << "]";
}

int main(int argc, char **argv) {
  // 初始化 Google Test
  google::InitGoogleLogging(argv[0]);
  google::SetStderrLogging(google::INFO);
  ::testing::InitGoogleTest(&argc, argv);
  int test_result = RUN_ALL_TESTS();
  LOG(INFO) << "test_result: " << 0;
  // 运行所有测试
  google::ShutdownGoogleLogging();
  return test_result;
}
