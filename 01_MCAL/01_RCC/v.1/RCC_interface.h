/*******************************************************************/
/*******************************************************************/
/***  -	   RCC_interface.h                                         ***/
/***  - Created  : 29/5/2023                                     ***/
/***  - Author   : Hassan Ehab                                   ***/
/***  - Version  : V01                                           ***/
/*******************************************************************/
/*******************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


typedef enum
{
   AHB1_BUS = 0,   
   AHB2_BUS,   
   APB1_BUS,   
   APB2_BUS,   
}BusType_e;


/* RCC State */
#define RCC_ENAPLE	 0
#define RCC_DISAPLE	 1

/*********** Macros Of :- RCC AHB1 CLK ENABLE ***************/

#define GPIOA_AHB1_EN     0U 
#define GPIOB_AHB1_EN     1U 
#define GPIOC_AHB1_EN     2U            
#define GPIOD_AHB1_EN     3U 
#define GPIOE_AHB1_EN     4U 
#define GPIOH_AHB1_EN     7U 
#define CRCEN_AHB1_EN     12U 
#define DMA1EN_AHB1_EN    21U 
#define DMA2EN_AHB1_EN    22U 


	/********* Macros Of :- RCC APB1 peripheral clock enable register *********/

#define TIM2_APB1_EN						0U
#define TIM3_APB1_EN						1U
#define TIM4_APB1_EN						2U
#define TIM5_APB1_EN					    3U
#define WWDG_APB1_EN						11U
#define SPI2_APB1_EN						14U
#define SPI3_APB1_EN						15U
#define UART2_APB1_EN						17U
#define I2C1_APB1_EN						21U
#define I2C2_APB1_EN						22U
#define I2C3_APB1_EN						23U
#define PWR_APB1_EN		         			28U



/**********  Macros Of :- RCC APB2 peripheral clock enable register (RCC_APB2ENR) *********/
			         					
#define TIM1_APB2_EN				 0U
#define USART1_APB2_EN				 4U
#define USART6_APB2_EN				 5U
#define ADC1_APB2_EN				 8U
#define SDIO_APB2_EN				 11U
#define SPI1_APB2_EN     			 12U
#define SYSCFG_APB2_EN				 14U
#define TIM9_APB2_EN				 16U
#define TIM10_APB2_EN				 17U
#define TIM11_APB2_EN				 18U

/*****************************************************************************************/


/* Init System Clock */
void MRCC_vInitSystemClock(void);
/* Enable | Disaple peripheral clock */
void MRCC_vSetPeripheralClockState(BusType_e Copy_eBusType, u8 Copy_u8Peripheral, u8 Copy_u8State);








#endif
