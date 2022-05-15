#!/bin/bash

echo 'please input a filename >>>'
read FILE

test -e $FILE
echo "存在？$?"

test -s $FILE
echo "非空？$?"

[ -r $FILE ]
echo 可读？$?

[ -w $FILE ]
echo 可写? $?

[ -x $FILE ]
echo 可执行？$?

test -b $FILE
echo 块文件? $?

test -c $FILE
echo 字符文件? $?

test -S $FILE
echo 套接字文件? $?

test -L $FILE
echo 硬链接文件? $?

test -d $FILE
echo 目录文件? $?

test -p $FILE
echo 管道文件? $?
