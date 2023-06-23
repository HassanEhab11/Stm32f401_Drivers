/*******************************************************************/
/*******************************************************************/
/***  -	   RCC_private.h                                         ***/
/***  - Created  : 29/5/2023                                     ***/
/***  - Author   : Hassan Ehab                                   ***/
/***  - Version  : V01                                           ***/
/*******************************************************************/
/*******************************************************************/

/*==================================================================================*/
/*                                                                                  */
/*	  - Developer can't Edit in it                                                  */
/*	  - Register _ Defination		                                                */
/*	  - Design :                                                                    */
/*					- #define	:	YES                                             */
/*					- Union		:	NO                                              */
/*					- Struct	:	YES                                             */
/*					                                                                */
/*==================================================================================*/

/*==================================================================================*/
/*==================    guard of file will call on time in .c	    ================*/
/*==================================================================================*/ 

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


#define RCC_BASE_ADDRESS     0x40023800

typedef struct
{
	
	volatile u32 CR  		   ;   /* RCC clock control register */
	volatile u32 PLLCFGR 	   ;
	volatile u32 CFGR 		   ;   /* RCC clock configuration register */
	volatile u32 CIR 		   ;
	volatile u32 AHB1RSTR  	   ;
	volatile u32 AHB2RSTR	   ;
	volatile u32 RESERVED_0	   ;
	volatile u32 RESERVED_1	   ;
	volatile u32 APB1RSTR	   ;
	volatile u32 APB2RSTR	   ;
	volatile u32 RESERVED_2	   ;
	volatile u32 RESERVED_3	   ;
	volatile u32 AHB1ENR	   ;
	volatile u32 AHB2ENR	   ;
	volatile u32 RESERVED_4	   ;
	volatile u32 RESERVED_5	   ;
	volatile u32 APB1ENR	   ;
    volatile u32 APB2ENR	   ;
	volatile u32 RESERVED_6	   ;
	volatile u32 RESERVED_7	   ;
    volatile u32 AHB1LPENR	   ;
    volatile u32 AHB2LPENR	   ;
	volatile u32 RESERVED_8	   ;
	volatile u32 RESERVED_9	   ;
    volatile u32 APB1LPENR	   ;
    volatile u32 APB2LPENR	   ;
	volatile u32 RESERVED_10   ;
	volatile u32 RESERVED_11   ;
    volatile u32 BDCR		   ;
    volatile u32 CSR		   ;
	volatile u32 RESERVED_12   ;
	volatile u32 RESERVED_13   ;
	volatile u32 SSCGR		   ;
	volatile u32 PLLI2SCFGR	   ;
	volatile u32 DCKCFGR	   ;

}RCC_REG_t;

#define	RCC_REG ((volatile RCC_REG_t *)RCC_BASE_ADDRESS)


/************ RCC_CR PINS ****************/
#define	CR_HSION     0U
#define	CR_HSIRDY    1U
#define	CR_HSEON     16U
#define	CR_HSERDY    17U
#define	CR_HSEBYP    18U
#define	CR_CSSON     19U
#define	CR_PLLON     24U
#define	CR_PLLRDY    25U

#define	PLLCFGR_PLLSRC  22U

#define	CFGR_SW0        0U
#define	CFGR_SW1        1U
#define	CFGR_MCO1_1     21U
#define	CFGR_MCO1_2     22U
#define	CFGR_MCO1PRE_1  24U
#define	CFGR_MCO1PRE_2  25U
#define	CFGR_MCO1PRE_3  26U

#define	AHB1ENR_GPIOAEN     0U
#define	AHB1ENR_GPIOBEN     1U
#define	AHB1ENR_GPIOCEN     2U
#define	AHB1ENR_GPIODEN     3U
#define	AHB1ENR_GPIOEEN     4U
#define	AHB1ENR_GPIOFEN     5U
#define	AHB1ENR_GPIOGEN     6U
#define	AHB1ENR_GPIOHEN     7U
#define	AHB1ENR_GPIOIEN     8U
#define	AHB1ENR_CRCEN       12U
#define	AHB1ENR_DMA1EN      21U
#define	AHB1ENR_DMA2EN      22U

#define AHB2ENR_OTGFSEN     7U

#define APB1ENR_TIM2EN      0U
#define APB1ENR_TIM3EN      1U
#define APB1ENR_TIM4EN      2U
#define APB1ENR_TIM5EN      3U
#define APB1ENR_WWDGEN      11U
#define APB1ENR_SPI2EN      14U
#define APB1ENR_SPI3EN      15U
#define APB1ENR_USART2      17U
#define APB1ENR_I2C1        21U
#define APB1ENR_I2C2        22U
#define APB1ENR_I2C3        23U
#define APB1ENR_PWR         28U

#define APB2ENR_TIM1EN      0U
#define APB2ENR_USART1EN    4U
#define APB2ENR_USART6EN    5U
#define APB2ENR_ADC1EN      8U
#define APB2ENR_SDIOEN      11U
#define APB2ENR_SPI1EN      12U
#define APB2ENR_SPI4EN      13U
#define APB2ENR_SYSCFGEN    14U
#define APB2ENR_TIM9EN      16U
#define APB2ENR_TIM10EN     17U
#define APB2ENR_TIM11EN     18U



#endif














 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
