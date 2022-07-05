#ifndef _DS20B18_H
#define _DS20B18_H
#include <public.h>

// DS10B20温度传感器的单总线
sbit DS18B20_BUS = P3^7;

// DS10B20初始化
u8 ds18b20_init();
//发送复位脉冲
void ds18b20_reset();
//检测DS10B20是否响应
u8 ds18b20_check();
//启动DS18B20转换
void ds18b20_start();
//写字节
void ds18b20_write_one_byte(u8 bstr);
//读字节
u8 ds18b20_read_one_byte();
//读一位
u8 ds18b20_read_one_bit();

float ds18b20_get_tempurature();

#endif