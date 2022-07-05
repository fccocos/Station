#ifndef _LDC12864_H
#define _LDC12864_H

#include "public.h"

#define LDC12864_DATAPORT P0 //8位数据总线，用于传递命令或数据

sbit ldc12864_RS = P2^6;    // 寄存器选择端， 1 表示数据寄存器   0 表示指令寄存器
sbit ldc12864_RW = P2^5;    // 数据读写选择端 1 表示读  0 表示写
sbit ldc12864_E = P2^7;     // 使能信号，用于发送数据
sbit ldc12864_PSB = P3^2;   // 8/4位并口选择端 1 表示8位  0 表示4位

void ldc12864_init(void);

void ldc12864_show_string(u8 x, u8 y, u8 *str);

#endif 