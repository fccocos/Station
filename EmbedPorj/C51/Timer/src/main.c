#include <reg52.h>
#include <intrins.h>

#define LED P2
sbit led0 = P2^0;
sbit led1 = P2^1;
sbit led2 = P2^2;
sbit led3 = P2^3;


void timer0_init()
{
    TR0 = 1; //开启timer0
    ET0 = 1; // 开启timer0的中断
    EA = 1; // 开启cpu中断
    TMOD |= 0x01;//为timer0启用工作模式1 将TH0和TL0合并为一个16bit的定时器
    /*计算1ms的定时初始值
        外部晶振频率12MHz
        1个时钟周期 = 1/12M s
        1个机器周期 = 12个时钟周期 = 1us
        所以1ms = 1000个机器周期 = 1000us
        1000 = 2^10-24 = 2^10-(2^4 + 2^3)
        0100 0000 0000
    -   0000 0001 1000
        0000 0011 1110 1000--->1000

        1111 1111 1111 1111--->65535
    -   0000 0011 1110 1000--->1000
        1111 1100 0001 0111--->64535
    +   0000 0000 0000 0001--->1
        1111 1100 0001 1000
    0x   f    c     1    8
         ------     ------
            ||        ||
           TH0       TL0
    */
    TH0 = 0xfc;
    TL0 = 0x18;

}

void main(void)
{
    timer0_init();
    while(1);
}

void timer0_INT() interrupt 1
{
    static unsigned int i;
    unsigned char j;
    TH0 = 0xfc;
    TL0 = 0x18;
    i++;
    if(i==500)//定时1s
    {
        LED =~(0x01<<j++);
        if(j==8)
            j=0;
        i=0;
    }
}