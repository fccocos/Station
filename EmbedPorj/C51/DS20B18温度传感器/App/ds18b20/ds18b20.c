
/**
 * @file ds18b20.c
 * @author your name (you@domain.com)
 * @brief DS18B20温度读取过程的实现 
 * 1. reset
 * 2. send the SKIP_ROM(0xCC) command to DS18B20
 * 3. send the command of staring converter(0x44) to DS18B20
 * 4. delay
 * 5. send the SKIP_ROM(0xCC) command to DS18B20
 * 6. send the command of reading the memory of DS18B20(0xBE)
 * 6. read two bytes from DS18B20
 * 7. over
 * DS18B20温度读取的过程，其本质就是写命令和读数据的过程
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "ds18b20.h"
#include <intrins.h>

/*初始化序列*/
u8 ds18b20_init()
{
    ds18b20_reset();
    return ds18b20_check();
}

/*启动DS18B20的转换*/
void ds18b20_start()
{
    ds18b20_reset();//复位
    ds18b20_check();//检查是否连结了DS18B20
    ds18b20_write_one_byte(0xCC);//SKIP_ROM 命令
    ds18b20_write_one_byte(0x44);//转换命令
}

void ds18b20_reset()
{
    DS18B20_BUS = 0;
    delay_10us(75); // 750us
    DS18B20_BUS = 1;
    delay_10us(2); // 20us
}
/*检测DS10B20是否响应， 响应返回0，不响应返回1, 应答信号由DS18B20给出*/
u8 ds18b20_check()
{
    u8 time_tmp = 0;
    if (DS18B20_BUS && time_tmp < 20)
    {
        time_tmp++;
        delay_10us(1);
    }
    if (time_tmp >= 20)
        return 1;
    else
        time_tmp = 0;
    while ((!DS18B20_BUS) && time_tmp < 20)
    {
        time_tmp++;
        delay_10us(1);
    }
    if (time_tmp >= 20)
        return 1;
    return 0;
}

void ds18b20_write_one_byte(u8 bstr)
{
    u8 i = 0;
    u8 tmp = 0;
    for (i = 0; i < 8; i++)
    {
        //从地位开始写数据
        tmp = (bstr & 0x01);
        bstr >>= 1;
        if (tmp)
        {
            //写1时序
            DS18B20_BUS = 0;
            _nop_();
            _nop_(); // 2us
            DS18B20_BUS = 1;
            delay_10us(6); // 60us
        }
        else
        {
            //写0时序
            DS18B20_BUS = 0;
            delay_10us(6);
            DS18B20_BUS = 1;
            _nop_();
            _nop_();
        }
    }
}
u8 ds18b20_read_one_byte()
{
    u8 value=0;
    u8 tmp=0;
    u8 i=0;
    for (i = 0; i <8; i++)
    {
        //读地位字节从高位开始存储
        tmp = ds18b20_read_one_bit();
        value = (tmp<<7)|(value>>1);
    }
    return value;
}
u8 ds18b20_read_one_bit()
{
    u8 dat = 0;
    //读1时序
    DS18B20_BUS = 0;
    _nop_();
    _nop_(); // 2us
    DS18B20_BUS = 1;
    _nop_();
    _nop_(); // 2us
    if (DS18B20_BUS)
        dat = 1;
    else
        dat = 0;
    delay_10us(5);
    return dat;
}
/*获取DS18B20的温度数据*/
float ds18b20_get_tempurature()
{
    float tempur;
    u16 value=0;
    u8 tmpL=0;
    u8 tmpH=0;
    
    // 开始将温度数据转换
    ds18b20_start();
    ds18b20_reset();//复位
    ds18b20_check();
    ds18b20_write_one_byte(0xcc);//SKIP_ROM
    ds18b20_write_one_byte(0xbe);//读存储器
    //获取温度数据
    tmpL = ds18b20_read_one_byte();//低字节
    tmpH = ds18b20_read_one_byte();//高字节
    value = (tmpH<<8)+tmpL;//合并为16为
    
    //判断温度数据的正负号
    if((value&0xf800)==0xf800)
    {
        //温度数据为负数，负数取补码（=反码+1）
        value = (~value)+1;
        tempur = value*(-0.0625);
    }
    else
    {
        //温度数据为负数
        tempur = value*(0.0625);
    }
    return tempur;
}
