#include "ired.h"

// 声明变量
u8 gired_data[GIRED_DATA_SIZE]; // 地址码+地址反码+控制码+控制反码

// 函数声明
void ired_init(void)
{
    IT0 = 1;  // 下降沿触发
    EX0 = 1;  // 打开中断0
    EA = 1;   // 打开总中观
    ired = 1; // 红外接收头数据端口数据化
}

/*
1. 判别0，1。 通过高电平的时间来判断传输的数据是0还是1.
    - 高电平的时间为560us， 表明传输的数据是0
    - 高电平的时间为1680us, 表明传输的数据是1
2. 引导码： 由9ms的低电平和4.5ms的高电平组成。
3. 接收数据的顺序为：引导码-->8位地址码-->8位地址反码-->8位控制码-->8位控制反码
4. 由于不同红外接收头的物理差异，所以对于电平时间的把握不用那么精确。只要不超出一定的范围，都可以接收
*/

void ired_inter() interrupt 0 //外部中断服务0
{
    u8 ired_high_time = 0; // 处理高电平的时间
    u16 time_cnt = 0;      // us计数
    u8 i = 0, j = 0;

    if (ired == 0) // 此时处于低电平, 开始接收数据
    {
        /* 1. 接收引导码*/
        time_cnt = 1000;              // 1000*10 = 10 000(us) = 10ms
        while ((!ired) && (time_cnt)) // 引导码的9ms低电平，如果超过10ms，强制退出
        {
            delay_10us(1); // 10us
            time_cnt--;
            if (time_cnt == 0)
                return;
        }
        if (ired) // 引导码的4.5ms高电平的时间
        {
            time_cnt = 500;          // 500*10 = 50000(us) = 5ms
            while (ired && time_cnt) // 引导码的4.5ms的高电平时间，如果超过5ms，强制退出
            {
                delay_10us(1); // 10us
                time_cnt--;
                if (time_cnt == 0)
                    return;
            }
            /*引导处理完毕*/

            /* 2. 接收地址码、地址反码、控制码、控制反码*/
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 8; j++)
                {
                    /*先接收560us的脉冲，即560us的低电平时间*/
                    time_cnt = 600; // 600*10 = 6000(us) = 0.6ms
                    while ((ired == 0) && time_cnt)
                    {
                        delay_10us(1); // 10us
                        time_cnt--;
                        if (time_cnt == 0)
                            return;
                    }

                    /*接收0或1数据*/
                    time_cnt = 20;
                    while (ired)
                    {
                        delay_10us(10); // 100us
                        ired_high_time++;
                        if (ired_high_time > 20)
                            return;
                    }

                    /*开始读取数据*/
                    gired_data[i]>>=1;       // 从地位开开始读取数据
                    if (ired_high_time >= 8)   // 800us = 0.8ms, 大于0.8ms为1， 否则为0
                        gired_data[i] |= 0x80; // 地位赋值为1
                    ired_high_time = 0;        // 重新清零，等待下一次计算时间
                }
            }
        }                                   // ired
        if (gired_data[2] != ~gired_data[3]) // 校验控制码和反码，错误返回
        {
            for (i = 0; i < 4; i++)
                gired_data[i] = 0;
            return;
        }
    }
}