/**
 * @file main.c
 * @author Gunfire (gunfirefc70@163.com)
 * @brief Realizing the control of independent keys
 * @version 0.1
 * @date 2022-05-24
 * @OnChipMemories: STC89C516RD+
 * @types: C51 chip macrocomputer
 * @copyright Copyright (c) 2022
 *
 */

#include <reg52.h>

//按键状态
#define KEY1_PRESS 1
#define KEY2_PRESS 2
#define KEY3_PRESS 3
#define KEY4_PRESS 4
#define KEY_UNPRESS 0  

//声明按键
sbit key1 = P3 ^ 1;
sbit key2 = P3 ^ 0;
sbit key3 = P3 ^ 2;
sbit key4 = P3 ^ 3;

//声明LED
sbit LED1 = P2 ^ 0;
sbit LED2 = P2 ^ 1;
sbit LED3 = P2 ^ 2;
sbit LED4 = P2 ^ 3;

/**
 *  1. 设置P3.1,P3.0,P3.2,P3.4为高电平（51单片机除P0口，其他端口默认为高电平）
    2. 通过软件方法来为按键消抖
    3. 为K1, K2,K3,K4编写控制程序
    4. 控制对象LED，控制对象的状态：亮和灭
    5. 实际控制P0端口P0.0~P0.7端口的高低电平
 */
/*软件消抖流程*/
/**
 * 1. 先设置IO为高电平
 * 2. 判断按键是否按下
 * 3. 延迟10ms
 * 4. 判断IO是否为低电平
 * 5. 如果为低电平，写入控制程序
 */

void sleep(unsigned int seconds)
{
    while (seconds--)
        ;
}

unsigned char key_scan(unsigned char mode)
{
    static unsigned char key = 1;
    if(mode) key=1;
    if(key==1&&(key1==0||key2==0||key3==0||key4==0))
    {
        sleep(1000);
        key=0;
        if(key1==0) return KEY1_PRESS;
        if(key2==0) return KEY2_PRESS;
        if(key3==0) return KEY3_PRESS;
        if(key4==0) return KEY4_PRESS;
    }
    else if(key1==1&&key2==1&&key3==1&&key4==1)
    {
        key=1;
    }
    return KEY_UNPRESS;
}

void main()
{
    int pressed = 1;
    while (1)
    {
        unsigned char key = key_scan(0);
        if(key == KEY1_PRESS)
            LED1 = !LED1;
        if(key == KEY2_PRESS)
            LED2 = !LED2;
        if(key == KEY3_PRESS)
            LED3 = !LED3;
        if(key == KEY4_PRESS)
            LED4 = !LED4;
    }
}
