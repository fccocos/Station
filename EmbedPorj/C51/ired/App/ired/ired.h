#ifndef _IRED_H
#define _IRED_H

#define GIRED_DATA_SIZE 4

#include "public.h"


sbit ired = P3^2; // 红外接收头的数据引脚

// 声明变量
extern u8 gired_data[GIRED_DATA_SIZE];

// 函数声明
void ired_init(void);


#endif 

