/*封装总线和外设基地址*/

/*
 block2 0x4000 0000~0x4fff ffff
 外设基地址    0x4000 0000
 APB1总线地址  0x4000 0000
 APB2总线地址  0x4001 0000 = 0x4000 0000 + 0x0001 0000
 AHB1总线地址  0x4002 0000 = 0x4000 0000 + 0x0002 0000
 AHB2总线地址  0x5000 0000 = 0x4000 0000 + 0x1000 0000
 AHB3总线地址  0x6000 0000
 GPIOA地址     0x4002 0000 = 0x4002 0000 + 0x0000 0000
 GPIOB地址     0x4002 0400 = 0x4002 0000 + 0x0000 0400
 GPIOC地址     0x4002 0800 = 0x4002 0000 + 0x0000 0800
 GPIOD地址     0x4002 0c00 = 0x4002 0000 + 0x0000 0c00
 GPIOE地址     0x4002 1000 = 0x4002 0000 + 0x0000 1000
 GPIOF地址     0x4002 1400 = 0x4002 0000 + 0x0000 1400
 GPIOG地址     0x4002 1800 = 0x4002 0000 + 0x0000 1800
 GPIOH地址     0x4002 1c00 = 0x4002 0000 + 0x0000 1c00
 GPIOF_MODER   0x4002 1400
 GPIOF_OTYPER  0x4002 1404
 GPIOF_OSPEEDER0x4002 1408
 GPIOF_PUPDR  0x4002 140c
 GPIOF_IDR     0x4002 1410
 GPIOF_ODR     0x4002 1414
 GPIPF_BSRR    0x4002 1418
 GPIOF_LCKR    0x4002 141c
 GPIOF_AFRL    0x4002 1420
 GPIOF_AFRH    0x4002 1424
 GPIOx_BSRR 端口置位/复位寄存器位表
   31  30    29   28  27  26  25  24  23  22  21  20  19  18  17  16
	BR15 BR14  BR13                 ......                          BR0             
   15  14    13   12  11  10  09  08  07  06  05  04  03  02  01  00
  BS15 BS14  BS13                 ......	                        BS0
	
	BRy: 表示寄存器的第y位是否复位，即是否清零。1表示复位， 0表示什么都不做
	BSy: 表示寄存器的第y位是否置位，即是否置1.  1表示置位， 0表示什么都不做
	BRy和BSy控制GPIOx第y根引脚的高低电平。
	
*/

#ifndef _STM32FXX_H_
#define _STM32FXX_H_

typedef unsigned int uint32_t ;
typedef unsigned short uint16_t ;
typedef unsigned char uint8_t ;

#define __IO volatile /*valatile表示一遍的变量，防止编译器优化*/


/*定义外设基地址*/
#define PERIPSH_BASE ((uint32_t)0x40000000)

/*总线基地址*/
#define APB1PERIPSH_BASE PERIPSH_BASE
#define APB2PERIPSH_BASE (PERIPSH_BASE + 0x00010000)
#define AHB1PERIPSH_BASE (PERIPSH_BASE + 0x00020000)

/*GPIOx*/
#define GPIOA_BASE (AHB1PERIPSH_BASE+0x0000)
#define GPIOB_BASE (AHB1PERIPSH_BASE+0x0400)
#define GPIOC_BASE (AHB1PERIPSH_BASE+0x0800)
#define GPIOD_BASE (AHB1PERIPSH_BASE+0x0c00)
#define GPIOE_BASE (AHB1PERIPSH_BASE+0x1000)
#define GPIOF_BASE (AHB1PERIPSH_BASE+0x1400)
#define GPIOG_BASE (AHB1PERIPSH_BASE+0x1800)
#define GPIOH_BASE (AHB1PERIPSH_BASE+0x1c00)

/*RCC寄存器*/
#define RCC_BASE (AHB1PERIPSH_BASE+0x3800)

/*GPIO 寄存器列表*/
typedef struct {
	__IO uint32_t MODER;        /*GPIO 模式寄存器      偏移地址:0x00*/
	__IO uint32_t OTYPER;       /*GPIO 输出类型寄存器  偏移地址:0x04*/
	__IO uint32_t OSPEEDR;     /*GPIO 输出速度寄存器  偏移地址:0x08*/
	__IO uint32_t PUPDR;        /*GPIO 上拉/下拉寄存器 偏移地址:0x0c*/
	__IO uint32_t IDR;          /*GPIO 输入数据寄存器  偏移地址:0x10*/
	__IO uint32_t ODR;          /*GPIO 输出数据寄存器  地址偏移:0x14*/
	__IO uint16_t BSRRL;        /*GPIO 置位/复位寄存器低16位 地址偏移:0x18*/
	__IO uint16_t BSRRH;        /*GPIO 置位/复位寄存器高16位 地址偏移:0x1a*/
	__IO uint32_t LCKR;         /*GPIO 配置锁定寄存器  偏移地址: 0x1c*/
	__IO uint32_t AFR[2];        /*GPIO 复用功能配置寄存器 偏移地址:0x20-0x24*/
}GPIO_TYPE;

/*RCC 寄存器列表*/
typedef struct{
	__IO uint32_t CR;            /*RCC 时钟控制寄存器      CR(RCC Control Register)            0x00*/
	__IO uint32_t PLLCFGR;       /*RCC PLL 配置寄存器      PLLCFGR(RCC PLL Configure Register) 0x04*/
	__IO uint32_t CFGR;          /*RCC 时钟配置寄存器      CFGR(RCC Configure Register)        0x08*/
	__IO uint32_t CIR;           /*RCC 时钟中断寄存器      CIR(RCC Interrupt Register)         0x0c*/
	__IO uint32_t AHB1RSTR;      /*RCC AHB1外设复位寄存器  AHB1RSTR(RCC AHB1 Reset Register)   0x10*/ 
	__IO uint32_t AHB2RSTR;      /*RCC AHB2外设复位寄存器  AHB2RSTR(RCC AHB2 Reset Register)   0x14*/
	__IO uint32_t AHB3RSTR;      /*RCC AHB3外设复位寄存器  AHB3RSTR(RCC AHB3 Reset Register)   0x18*/
	__IO uint32_t RESERVED0;     /*预保留                                                      0x1c*/
	__IO uint32_t APB1RSTR;      /*RCC APB1外设复位寄存器                                      0x20*/
	__IO uint32_t APB2RSTR;      /*RCC APB2外设复位寄存器                                      0x24*/
	__IO uint32_t RESERVED1[2];  /*预保留                                                 0x28-0x2c*/
	__IO uint32_t AHB1ENR;       /*RCC AHB1外设时钟寄存器  AHB1ENR                             0x30*/
	__IO uint32_t AHB2ENR;       /*RCC AHB2外设时钟寄存器  AHB2ENR                             0x34*/
	__IO uint32_t AHB3ENR;       /*RCC AHB3外设时钟寄存器  AHB3ENR                             0x38*/
	/*
	RCC 后面还有很多寄存器，省略...
	*/
	
}RCC_TYPE;


#define GPIOA ((GPIO_TYPE*)GPIOA_BASE)
#define GPIOB ((GPIO_TYPE*)GPIOB_BASE)
#define GPIOC ((GPIO_TYPE*)GPIOC_BASE)
#define GPIOD ((GPIO_TYPE*)GPIOD_BASE)
#define GPIOE ((GPIO_TYPE*)GPIOE_BASE)
#define GPIOF ((GPIO_TYPE*)GPIOF_BASE)
#define GPIOG ((GPIO_TYPE*)GPIOG_BASE)
#define GPIOH ((GPIO_TYPE*)GPIOH_BASE)
#define RCC   ((RCC_TYPE*)RCC_BASE)




#endif
