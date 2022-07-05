#ifndef _XPT2046_H
#define _XPT2046_H
#include "public.h"

sbit DIN = P3^4; // 串行数据输入引脚
sbit CS = P3^5;  // 片选信号，低电平有效
sbit DCLK = P3^6;// 外部时钟信号
sbit DOUT = P3^7;// 串行数据输出引脚

/*
8位由DIN输入的控制字节

7  6  5  4   3     2     1   0
S A2 A1 A0 MODE SER/DFR PD1 PD2

S         ---   开始位。 1 表示一个新的控制字码到来， 0 表示忽略PIN脚上的数据

A2 A1 A0  ---   通道选择。

MODE      ---   12/8转换分辨率选择位。 1 表示8位转换分辨率， 0 表示12位转换分辨率

SER/DFR   ---   单端输入/差分输入方式选择。 1 表示单端输入， 0 表示差分输入

PD1 PD2   ---   低功率模式选择位。 11 表示器件总是处于供电状态， 00 表示器件在变换之间处于低功率模式

*/

u16 xpt2046_read_adc_value(u8 cmd);


#endif //  _XPT2046_H
