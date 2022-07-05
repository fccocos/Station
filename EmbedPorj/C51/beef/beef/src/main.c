/*************************************
 * 
 *        89c52 sdcc blink demo
 * 
 * CPU: 89C52
 * FREQ: 12MHz
 * PIN: P00
 * 
 * ***********************************
*/

#include <reg52.h>


sbit BEEP = P2^5;


void sleep(unsigned int seconds); 

void main()
{
    //蜂鸣器要想发出响声，就必须不断的输出高低电平
    //即，控制端P2.5必须输出脉冲
    int i = 2000;
    while( i--)
    {
        BEEP = !BEEP;
        sleep(50);
    }

}

void sleep(unsigned int seconds)
{
    while(seconds--);
}
