#!/bin/bash

# 容器名称
CONTAINER_NAME="pycdev"
# Docker 镜像
IMAGE_NAME="mydev"

# 检查容器是否存在
if docker ps -a --filter "name=${CONTAINER_NAME}" --format '{{.Names}}' | grep -q "${CONTAINER_NAME}"; then
    # 如果容器存在，删除它
    echo "容器 ${CONTAINER_NAME} 存在，正在删除..."
    docker rm -f ${CONTAINER_NAME}
else
    echo "容器 ${CONTAINER_NAME} 不存在。"
fi

docker run --gpus all -it --name ${CONTAINER_NAME} ${IMAGE_NAME}
