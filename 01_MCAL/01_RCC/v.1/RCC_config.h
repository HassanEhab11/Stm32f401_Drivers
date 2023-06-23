/*******************************************************************/
/*******************************************************************/
/***  -	   RCC_config.h                                         ***/
/***  - Created  : 29/5/2023                                     ***/
/***  - Author   : Hassan Ehab                                   ***/
/***  - Version  : V01                                           ***/
/*******************************************************************/
/*******************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*- CLKSRC option :	 1) HSI            2) HSE           3) PLL                  */
#define CLOCK_SOURCE	HSI

/*- HSE option :     1) _HSE_CRYSTAL   2) _HSE_RC                               */
#define HSE_SOURCE  _HSE_CRYSTAL

/*- PLL option :     1) _HSE_PLL       2) _HSI_PLL                              */
#define PLL_SOURCE   _HSI_PLL

#endif /* RCC_CONFIG_H_ */
