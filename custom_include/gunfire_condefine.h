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

#define GUNFIRE_DC_STEP_MOTOR_CONTROL P1 // 直接用P1端口的低四位来控制步进电机

//蜂鸣器
sbit GUNFIRE_beep = P2^5;

// 数码管段选线
sbit GUNFIRE_DT_SegSelection_A2 = P2^4;
sbit GUNFIRE_DT_SegSelection_A1 = P2^3;
sbit GUNFIRE_DT_SegSelection_A0 = P2^2; 

// 独立键盘
sbit GUNFIRE_independentKey1 = P3^1;
sbit GUNFIRE_independentKey2 = P3^0;
sbit GUNFIRE_independentKey3 = P3^2;
sbit GUNFIRE_independentKey4 = P3^3;
#define GUNFIRE_INDEPENDENTKEY1_PRESSED 1
#define GUNFIRE_INDEPENDENTKEY2_PRESSED 2
#define GUNFIRE_INDEPENDENTKEY3_PRESSED 3
#define GUNFIRE_INDEPENDENTKEY4_PRESSED 4
#define GUNFIRE_INDEPENDENTKEY_UNPRESS 0

//74HC595芯片的移位寄存器时钟、存储寄存器时钟、串行数据输入
sbit GUNFIRE_HC595_SRCLK = P3^6;
sbit GUNFIRE_HC595_RCLK = P3^5;
sbit GUNFIRE_HC595_SER = P3^4;

//直流电机控制引脚
sbit GUNFIRE_DC_Motor = P1^0;

//直流步进电机相位控制引脚
sbit GUNFIRE_DC_Step_Motor_Phase_D = P1^0;
sbit GUNFIRE_DC_Step_Motor_Phase_C = P1^1;
sbit GUNFIRE_DC_Step_Motor_Phase_B = P1^2;
sbit GUNFIRE_DC_Step_Motor_Phase_A = P1^3;

void sleep(gu16 timeout)
{
    while(timeout--);
}
void delay_10us(gu16 ten_us)//1 == 10usec;
{
    while(ten_us--);
}

void delay_ms(gu16 ms)
{
    gu16 i,j;
    for(i=0; i<ms; i++)
        for(j=110; j>0; j--);
}

void G_Swap(gu8* dest1, gu8* dest2)
{
    gu8 tmp;
    tmp = *dest1;
    *dest1 = *dest2;
    *dest2 = tmp;
}
#endif