#!/bin/bash

# 自定定义变量
echo '*****************'
echo 1. 给只定义变量复制时等号两边不能有括号
echo 2. 用$变量名来引用变量
echo 3. 用\"unset 变量名\"清楚变量值
echo 4. 可以\"用read 变量名\"来读取
echo 5. 用readonly定义的变量在定义的时候必须初始化，且不能被修改和清楚，相当于该变量只读
echo 6. 使用export定义的变量为环境变量，其他的shell都可以使用，相当于该变量变成了一个全局变量，但该变量时一个临时的，当系统重启或shell重启后会被清除。
echo '*****************'

num=10 #自定的普通变量
export envval=中国人 #环境变量
read string #可输入的变量

# 输出自定普通变量
echo 自定普通变量 num=$num
# 清除普通变量的值
unset num
# 打印num现在的值
echo num=$num
# 打印输入变量的值
echo 输入变量的值 string=$string
# 打印环境变量的值
echo 环境变量的值 envval=$envval

echo 当前shell脚本02_自定义变量.sh运行到此结束
