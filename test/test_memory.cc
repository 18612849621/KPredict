#include <glog/logging.h>
#include <gtest/gtest.h>

#include <iostream>

#include "memory/buffer.h"
#include "memory/memory_allocator.h"
#include "utils/utils.h"
#include "utils/utils_enum.h"

TEST(MemoryAllocatorTest, HostMemoryAllocatorTest) {
  char str[] = "Hello world, CPU!";
  size_t str_byte_size = sizeof(str);
  LOG(INFO) << str << " | 's size is " << str_byte_size << " bytes.";
  Buffer buffer(str_byte_size, MemoryAllocatorFactory::GetInstance(DeviceType::KDeviceCPU));
  MemoryAllocator *memory_allocator_ptr =
      MemoryAllocatorFactory::GetInstance(DeviceType::KDeviceCPU).get();
  LOG(INFO) << "Device type is " << memory_allocator_ptr->device_type();
  char *test_string = static_cast<char *>(memory_allocator_ptr->Allocate(str_byte_size));
  memory_allocator_ptr->Memcpy(test_string, str, str_byte_size);
  LOG(INFO) << "Before set zero [" << test_string << "]";
  memory_allocator_ptr->MemsetZero(test_string, str_byte_size);
  LOG(INFO) << "After set zero [" << test_string << "]";
}

TEST(MemoryAllocatorTest, DeviceMemoryAllocatorTest) {
  char str[] = "Hello world, GPU!";
  size_t str_byte_size = sizeof(str);
  std::shared_ptr<MemoryAllocator> host_mem_alloctor_ptr =
      MemoryAllocatorFactory::GetInstance(DeviceType::KDeviceCPU);
  LOG(INFO) << str << " | 's size is " << str_byte_size << " bytes.";
  Buffer d_buffer(str_byte_size, MemoryAllocatorFactory::GetInstance(DeviceType::KDeviceGPU));
  Buffer h_buffer(str_byte_size, MemoryAllocatorFactory::GetInstance(DeviceType::KDeviceCPU));
  // 目前手动模拟实现buffer的copy
  host_mem_alloctor_ptr->Memcpy(d_buffer.GetMemPtr(), str, str_byte_size,
                                MemcpyMode::kMemcpyHostToDevice);
  // host_mem_alloctor_ptr->Memcpy(h_buffer.GetMemPtr(), d_buffer.GetMemPtr(), str_byte_size,
  //                               MemcpyMode::kMemcpyDeviceToHost);
  h_buffer.CopyFrom(d_buffer);
  LOG(INFO) << "Before set zero [" << static_cast<char *>(h_buffer.GetMemPtr()) << "]";
  host_mem_alloctor_ptr->MemsetZero(d_buffer.GetMemPtr(), str_byte_size, DeviceType::KDeviceGPU);
  h_buffer.CopyFrom(d_buffer);
  // host_mem_alloctor_ptr->Memcpy(h_buffer.GetMemPtr(), d_buffer.GetMemPtr(), str_byte_size,
  //                               MemcpyMode::kMemcpyDeviceToHost);
  LOG(INFO) << "After set zero [" << static_cast<char *>(h_buffer.GetMemPtr()) << "]";
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
