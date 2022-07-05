#include "stm32f4xx.h"
#include "stm32f4xx_GPIO.h"

void Delay(uint32_t nCount);
void SystemInit(void);

int main(void)
{
    GPIO_InitType initStruct;

    /*开启GPIO时钟， 使用外设时都要先开启它的时钟*/
    RCC->AHB1ENR |= (1<<5);

    /*LED端口初始化*/
    /*初始化PF6引脚*/
    /*选择要控制的引脚*/
    initStruct.GPIO_Pin = GPIO_Pin_6;
    /*设置引脚输出模式*/
    initStruct.GPIO_Mode = GPIO_Mode_OUT;
    /*设置引脚为上拉模式*/
    initStruct.GPIO_Pupd = GPIO_Pupd_UP;
    /*设置引脚速率为2MHZ*/
    initStruct.GPIO_Speed = GPIO_Speed_2MHZ;

    /*初始化GPIOF*/
    init_GPIO(GPIOF, &initStruct);

    /*使用引脚输出低电平，点亮 LED1*/
    GPIO_ResetBits(GPIOF, GPIO_Pin_6);

    /*延时一段时间*/
    Delay(0xfffff);

    /*使引脚输出高电平，关闭 LED1*/
    GPIO_SetBits(GPIOF, GPIO_Pin_6);

    /*初始化PF7引脚*/
    initStruct.GPIO_Pin = GPIO_Pin_7;
    init_GPIO(GPIOF, &initStruct);

    /*使引脚输出低电平， 点亮LED2*/
    GPIO_ResetBits(GPIOF, GPIO_Pin_7);

    while(1);
    
}

void Delay(uint32_t nCount)
{
    while(nCount--);
}

void SystemInit(void)
{
    
}
