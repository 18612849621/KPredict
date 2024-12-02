# KPredict
高性能模型推理框架

# abstract
本框架基于 cuda11.8 搭建

* 支持内存管理

# config

```shell
放到setting里
"clangd.arguments": [
    "--compile-commands-dir=/mnt/KPredict/build"
]
```

# script

```shell
# compile
mkdir build
cd build
cmake ..
make -j8

# run
build/test --log_dir=./logs --v=3 --logtostderr
```
