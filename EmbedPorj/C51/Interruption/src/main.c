#include <reg52.h>

sbit LED2 = P2 ^ 1;

sbit key2 = P3 ^ 2;


void init_INT0();

void delay_10us(unsigned int us);

void main(void)
{
    init_INT0();
    while (1)
    {}
}

void init_INT0()
{
    EA = 1;
    EX0 = 1;
    IT0 = 1;
}

void delay_10us(unsigned int us)
{
    while (us--)
        ;
}

void key_int() interrupt 0
{
    delay_10us(1000);
    if (key2 == 0)
    {
        LED2 = !LED2;
    }   
    
}