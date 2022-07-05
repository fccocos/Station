#include <reg52.h>
#include <intrins.h>
#define LED_PORT P2

typedef unsigned int u16;
typedef unsigned char u8;

void sleep(u16 timecout)
{
    while (timecout--)
        ;
}

void shitf_8_right()
{
    int i;
    for (i = 0; i < 8; i++)
    {
        LED_PORT = ~(0x01 >> i);
        sleep(500000);
    }
}

// void test01()
// {
//     LED_PORT = ~LED_PORT;
//     sleep(500000);
//     LED_PORT = ~LED_PORT;
//     sleep(500000);
// }

void test02()
{
    while (1)
    {
        int i;
        for (i = 0; i < 8; i++)
        {
            LED_PORT = ~(0x01 << i);
            sleep(100000);
        }
        // 0111 1111 ~ 1000 0000  >>1 0100 0000 ~ 1011 1111 (~ >>1)

        for (i = 1; i < 8; i++)
        {
            LED_PORT = ~LED_PORT;
            LED_PORT = ~(LED_PORT >> 1);
            sleep(100000);
        }
    }
}

int main(void)
{
    int i;
    LED_PORT = ~0x01; //
    sleep(100000);
    while (1)
    {
        for (i = 0; i < 7; i++)
        {
            LED_PORT = _crol_(LED_PORT, 1);
            sleep(100000);
        }
        // 0111 1111 ~ 1000 0000  >>1 0100 0000 ~ 1011 1111 (~ >>1)

        for (i = 0; i < 7; i++)
        {
            LED_PORT = _cror_(LED_PORT, 1);
            sleep(100000);
        }
    }
}
