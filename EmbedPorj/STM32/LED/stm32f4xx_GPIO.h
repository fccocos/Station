#ifndef _STM32F4XX_GPIO_H_
#define _STM32F4XX_GPIO_H_

#include "stm32f4xx.h"

/*GPIO 引脚定义*/
#define GPIO_Pin_0 ((uint16_t)0x0001) /*!< 选择 Pin0 (1<<0)*/
#define GPIO_Pin_1 ((uint16_t)0x0002) /*!< 选择 Pin1 (1<<1)*/
#define GPIO_Pin_2 ((uint16_t)0x0004) /*!< 选择 Pin2 (1<<2)*/
#define GPIO_Pin_3 ((uint16_t)0x0008)
#define GPIO_Pin_4 ((uint16_t)0x0010)
#define GPIO_Pin_5 ((uint16_t)0x0020)
#define GPIO_Pin_6 ((uint16_t)0x0040)
#define GPIO_Pin_7 ((uint16_t)0x0080)
#define GPIO_Pin_8 ((uint16_t)0x0100)
#define GPIO_Pin_9 ((uint16_t)0x0200)
#define GPIO_Pin_10 ((uint16_t)0x0400)
#define GPIO_Pin_11 ((uint16_t)0x0800)
#define GPIO_Pin_12 ((uint16_t)0x1000)
#define GPIO_Pin_13 ((uint16_t)0x2000)
#define GPIO_Pin_14 ((uint16_t)0x4000)
#define GPIO_Pin_15 ((uint16_t)0x8000)
#define GPIO_Pin_All ((uint16_t)0xffff)

/*GPIO 端口配置模式的枚举定义*/
typedef enum{
	GPIO_Mode_IN = 0x00,  /*输入模式*/
	GPIO_Mode_OUT = 0x01, /*输出模式*/
	GPIO_Mode_AF = 0x02,  /*复用模式*/
	GPIO_Mode_AN = 0x03,  /*模拟模式*/
}GPIOMode_Type;

/*GPIO 输出类型枚举定义*/
typedef enum{
	GPIO_OType_PP = 0x00, /*推挽输出*/
	GPIO_OType_OD = 0x01, /*开漏输出*/
}GPIOOType_Type;

/*GPIO 输出速率枚举定义*/
typedef enum{
	GPIO_Speed_2MHZ = 0x00,
	GPIO_Speed_25MHZ = 0x01,
  GPIO_Speed_50MHZ = 0x02,
  GPIO_Speed_100MHZ = 0x03	
}GPIOSpeed_Type;
/*GPIO 输出模式*/
typedef enum{
	GPIO_Pupd_NOPULL = 0x00, /*浮空*/
	GPIO_Pupd_UP     = 0x01,
	GPIO_PUpd_DOWN   = 0x02
}GPIOPupd_Type;

/*GPIO初始化结构体*/
typedef struct {
	uint32_t GPIO_Pin; /*选择要配置的 GPIO 引脚  可输入 GPIO_Pin_ 定义的宏*/
	GPIOMode_Type GPIO_Mode;
	GPIOSpeed_Type GPIO_Speed;
	GPIOOType_Type GPIO_OType;
	GPIOPupd_Type GPIO_Pupd;
}GPIO_InitType;

void GPIO_SetBits(GPIO_TYPE *GPIOx, uint16_t GPIO_Pin);

void GPIO_ResetBits(GPIO_TYPE *GPIOx, uint16_t GPIO_Pin);

void init_GPIO(GPIO_TYPE* GPIOx, GPIO_InitType* initStruct);


#endif
