#include "xpt2046.h"
#include "intrins.h"



void xpt2046_write_data(u8 dat)
{
    u8 i;
    DCLK = 0;
    _nop_();
    for(i=0;i<8; i++)
    {
        DIN = dat>>7;
        dat<<=1;

        DCLK = 1; // 上升沿写数据
        _nop_();

        DCLK = 0;
        _nop_();
    }
}


u16 xpt2046_read_data(void)
{
    u8 i;
    u16 dat=0;

    DCLK = 0;
    _nop_();

    for(i=0; i<12;i++)
    {
        dat <<=1;

        DCLK = 1;
        _nop_();
        DCLK = 0;
        _nop_();
        dat |= DOUT; // 从高位开始读取数据
    }
    return dat;
}

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

u16 xpt2046_read_adc_value(u8 cmd)
{
    u16 adc_value = 0;

    DCLK = 0; // 先拉低时钟
    CS = 0; // 使能xpt2046
    
    /*写入控制字节*/
    xpt2046_write_data(cmd);
    delay_10us(6); // 延时60us，等待ADC转换完成

    DCLK= 0;
    _nop_();
    /*发送一个时钟清除busy*/
    DCLK = 1;
    _nop_();

    adc_value = xpt2046_read_data();

    CS = 1; // 关闭xpt2046

    return adc_value;

}