#include "public.h"


void delay_10us(uint ten_us)
{
    while(ten_us--);
}
void delay_ms(uint ms)
{
    int i,j;
    for(i=ms;i>00;i--)
        for(j=110;j>0;j--)
            ;
}