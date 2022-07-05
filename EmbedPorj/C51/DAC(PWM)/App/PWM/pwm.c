#include "pwm.h"

u8 gtime_h = 0;    // 定时器高八位
u8 gtime_l = 0;    // 定时器低八位
u8 gduty = 0;      // 占空比
u8 gtime_scale = 0;// pwm周期 = 初始定时器的值*time_scale

void pwm_init(u8 time_h, u8 time_l, u16 time_scale, u8 duty)
{
    gtime_h = time_h;
    gtime_l = time_l;
    gtime_scale = time_scale;
    gduty = duty;

    /*定时器的初始化*/
    TMOD |= 0x01;  // 选选择定时器0模式，工作方式1
    TH0 = gtime_h; // 设置定时器的初始值
    TL0 = gtime_l;
    ET0 = 1;      // 打开定时器0中断允许
    EA = 1;       // 打开总中断
    TR0 = 1;      // 打开定时器
}

void pwm__set_duty(u8 duty)
{
    gduty = duty;
}

void pwm_timer(void) interrupt 1 // 定时器0中断函数
{
    static u16 time = 0;
    
    TH0 = gtime_h;
    TL0 = gtime_l;

    time++;
    if(time>=gtime_scale)
        time = 0;
    if(time <=gduty)
        pwm = 1;
    else
        pwm = 0;
}