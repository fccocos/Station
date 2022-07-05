#include <reg52.h>

typedef unsigned int u16;
typedef unsigned char u8;

sbit LED_0 = P0^0;

void sleep(u16 us)
{
	while(us--);
}

int main()
{
	while(1)
	{
		LED_0 = 0; //点亮第一个LED
		sleep(500000);//延迟450ms
		LED_0 = 1; // 熄灭第一个LED
		sleep(500000); // 延迟450ms
	}
} 

