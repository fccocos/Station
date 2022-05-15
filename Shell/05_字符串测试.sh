#!/bin/bash

echo "请输入一个字符串str1>>>"
read str1
echo "请输入一个字符串str2>>>"
read str2

[ -z $str1 ]
echo " str1 is null? $?"

[ -n $str1 ]
echo " str1 is not null? $?"

[ -z $str2 ]
echo " str2 is null? $?"

[ -n $str2 ]
echo " str2 is not null? $?"

test $str1 = $str2
echo " str1==str2? $?"

test $str1 != $str2
echo " str1!=str2? $?"


