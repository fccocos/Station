#include "stm32f4xx_GPIO.h"


void GPIO_SetBits(GPIO_TYPE *GPIOx, uint16_t GPIO_Pin)
{
	GPIOx->BSRRL = GPIO_Pin;
}

void GPIO_ResetBits(GPIO_TYPE *GPIOx, uint16_t GPIO_Pin)
{
	GPIOx->BSRRH = GPIO_Pin;
}

void init_GPIO(GPIO_TYPE* GPIOx, GPIO_InitType* initStruct)
{
	uint32_t pinpos=0x00, pos=0x00, curpin = 0x00;
	/*GPIO Mode Configuration*/
	for(pinpos=0x00; pinpos <16; pinpos++)
	{
		/*获取当前pin的位置*/
		pos = ((uint32_t)0x01<<pinpos);

		/*获取到pin与initStruct结构体中的GPIO_PIN进行&运算，如果为1，则当前pin就是1， 否则为0*/
		curpin = pos&initStruct->GPIO_Pin;
		if(curpin == pos)
		{
			/*MODER为清空*/
			GPIOx->MODER &= ~((uint32_t)3<<2*pinpos);

			/*设置GPIO的输出模式*/
			GPIOx->MODER |= (((uint32_t)initStruct->GPIO_Mode))<<(2*pinpos); 

			/*清空PUPDR寄存器的GPIO_Pin引脚*/
			GPIOx->PUPDR &= ~((uint32_t)3<<2*pinpos);
			/*设置GPIO的上拉.下拉模式*/
			GPIOx->PUPDR |= ((uint32_t)initStruct->GPIO_Pupd << (2*pinpos)); 
			
			if(initStruct->GPIO_Mode == GPIO_Mode_OUT||initStruct->GPIO_Mode == GPIO_Mode_AF)
			{
				GPIOx->OSPEEDR &= ~((uint32_t)3 << (2*pinpos));
				GPIOx->OSPEEDR |= ((uint32_t)initStruct->GPIO_Speed << (2*pinpos));

				GPIOx->OTYPER &= ~(1<<(pinpos));
                GPIOx->OTYPER |= ((uint32_t)initStruct->GPIO_OType<<(pinpos));

			}
		}
	}
}
