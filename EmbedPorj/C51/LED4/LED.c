#include <reg52.h>

typedef unsigned int u16;
typedef unsigned char u8;

sbit led0 = P2^0;
sbit led1 = P2^1;
sbit led2 = P2^2;
sbit led3 = P2^3;
sbit led4 = P2^4;
sbit led5 = P2^5;
sbit led6 = P2^6;
sbit led7 = P2^7;

void sleep(u16 timecout)
{
    while(timecout--);

}

int main(void)
{
    while(1)
    {
        led0 = 0;
        led1 = 0;
        led2 = 0;
        led3 = 0;
        led4 = 0;
        led5 = 0;
        led6 = 0;
        led7 = 0;
        sleep(500000);
        led0 = 1;
        led1 = 1;
        led2 = 1;
        led3 = 1;
        led4 = 1;
        led5 = 1;
        led6 = 1;
        led7 = 1;
        sleep(500000);
    }
}
