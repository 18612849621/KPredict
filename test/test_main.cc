#include "memory/memory_allocator.h"
#include "utils/utils.h"
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
  MemoryAllocator *memory_allocator_ptr = new HostMemoryAllocator();
  char *test_string =
      static_cast<char *>(memory_allocator_ptr->Allocate(sizeof(str)));
  memory_allocator_ptr->Memcpy(test_string, str, sizeof(str));
  LOG(INFO) << test_string;
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