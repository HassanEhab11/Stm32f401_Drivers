/*******************************************************************/
/*******************************************************************/
/***  -	   GPIO_private.h                                         ***/
/***  - Created  : 31/5/2023                                     ***/
/***  - Author   : Hassan Ehab                                   ***/
/***  - Version  : V01                                           ***/
/*******************************************************************/
/*******************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS  0x40020000
#define GPIOB_BASE_ADDRESS  0x40020400
#define GPIOC_BASE_ADDRESS  0x40020800
#define GPIOD_BASE_ADDRESS  0x40020C00
#define GPIOE_BASE_ADDRESS  0x40021000
#define GPIOH_BASE_ADDRESS  0x40021C00

typedef struct
{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;
}GPIOx_REG_s;

#define GPIOA_REG ((GPIOx_REG_s *)GPIOA_BASE_ADDRESS)
#define GPIOB_REG ((GPIOx_REG_s *)GPIOB_BASE_ADDRESS)
#define GPIOC_REG ((GPIOx_REG_s *)GPIOC_BASE_ADDRESS)
#define GPIOD_REG ((GPIOx_REG_s *)GPIOD_BASE_ADDRESS)
#define GPIOE_REG ((GPIOx_REG_s *)GPIOE_BASE_ADDRESS)
#define GPIOH_REG ((GPIOx_REG_s *)GPIOH_BASE_ADDRESS)

#endif
