#include <gunfire_condefine.h>

int main()
{
    delay_ms(2000);//两秒的准备
    while(1)
    {
    GUNFIRE_DC_Motor = 1;
    delay_ms(5000);//跑5s
    GUNFIRE_DC_Motor = 0;
    delay_ms(3000);//休息3s
    }
}