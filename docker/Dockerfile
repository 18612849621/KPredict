FROM nvidia/cuda:11.8.0-devel-ubuntu20.04

# 设置工作目录
WORKDIR /workspace

RUN ln -snf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime && echo "Asia/Shanghai" > /etc/timezone

# 更新包列表并安装依赖，并清理不需要的缓存
RUN apt update && \
    apt install -y libgoogle-glog-dev libgtest-dev cmake make g++ clangd git && \
    # 构建 googletest
    cd /usr/src/googletest && \
    cmake CMakeLists.txt && \
    make && \
    make install

RUN cd /workspace && git clone https://github.com/18612849621/KPredict.git && \
    git config --global user.name 18612849621 && git config --global user.email 1354368242@qq.com && \
    git config --global credential.helper 'cache --timeout=7200'

RUN apt install -y neovim

# 清理 apt 缓存
RUN rm -rf /var/lib/apt/lists/*

WORKDIR /workspace/KPredict
RUN git pull

