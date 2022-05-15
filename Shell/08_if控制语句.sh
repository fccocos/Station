#!/bin/bash

read num

if [ $num -gt 50 ]; then
	echo "num>50"
else 
	echo "num<=50"
fi

echo "*********************************"

# 阶梯式
if [ $num -gt 50 ]; then
	echo "num>50"
elif [ $num -lt 50 ]; then 
	echo "num<50"
else 
	echo "num==50"
fi

echo "*********************************"

# 嵌套式

if [ $num -gt 50 ]; then
	echo "num>50"
else 
	if [ $num -lt 50 ]; then	
		echo "num<50"
	else
		echo "num==50"
	fi
fi
