#!/bin/bash

# 对要操作的文件进行备份，防止意外
cp ~/.bashrc ~/.bashrc.backup

# 将要设置的环境变量追加到~/.bashrc文件中
echo "export $1=$2">> ~/.bashrc

echo export $1=$2 成功导入

