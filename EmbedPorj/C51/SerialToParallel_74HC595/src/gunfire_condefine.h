#ifndef GUNFIRE_CONDEFINE_H
#define GUNFIRE_CONDEFINE_H

#include <reg52.h>


//变量类型重定义
typedef unsigned char gu8;
typedef unsigned int gu16;
typedef char gs8;
typedef int  gs16;
typedef unsigned long gu32;
typedef long gs32;

#define GUNFIRE_LED_MAXTRIX_K P0  //LED点阵
#define GUNFIRE_DITIGALTUBE_BIT_SELECTION P1 //2个四位一体数码管的位选线
#define GUNFIRE_8BITS_LED P2 //8为LED灯
#define GUNFIRE_KEYS_MAXTRIX P1 // 矩阵键盘的行线和列线

//蜂鸣器
sbit GUNFIRE_beep = P2^5;

// 数码管段选线
sbit GUNFIRE_DT_SegSelection_A2 = P2^4;
sbit GUNFIRE_DT_SegSelection_A1 = P2^3;
sbit GUNFIRE_DT_SegSelection_A0 = P2^2; 

// 独立键盘
sbit GUNFIRE_indpendentKey1 = P3^1;
sbit GUNFIRE_indpendentKey2 = P3^0;
sbit GUNFIRE_indpendentKey3 = P3^2;
sbit GUNFIRE_indpendentKey4 = P3^3;

//74HC595芯片的移位寄存器时钟、存储寄存器时钟、串行数据输入
sbit GUNFIRE_HC595_SRCLK = P3^6;
sbit GUNFIRE_HC595_RCLK = P3^5;
sbit GUNFIRE_HC595_SER = P3^4;

extern void sleep(gu16 timeout)
{
    while(timeout--);
}
extern void delay_10us(gu16 ten_us)//1 == 10usec;
{
    while(ten_us--);
}

extern void delay_ms(gu16 ms)
{
    gu16 i,j;
    for(i=0; i<ms; i++)
        for(j=110; j>0; j--);
}
#endif