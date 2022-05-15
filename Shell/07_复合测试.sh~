#!/bin/bash

echo "输入一个数字num》》》"
read num

# 判断0<=num<=100

echo "命令执行控制"
test $num -le 100 && test $num -ge 0
echo "0<=num<=100?$?"

echo "多重条件判断"
test $num -le 100 -a $num -ge 0
echo "0<=num<=100?$?"

echo "输入一个文件名filename》》》"
read filename

echo "命令执行控制"
[ -r $filename ] && [ -x $filename ] || [ -f $filename ]
echo "$?"

echo "多重条件判断"
test -r $filename -a -x $filename -o -f $filename
echo "$?"
 
