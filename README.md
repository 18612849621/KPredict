# KPredict
在线推理框架

# abstract
本框基于 cuda11.8 搭建

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
