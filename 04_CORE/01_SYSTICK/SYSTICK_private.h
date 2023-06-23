/*******************************************************************/
/*******************************************************************/
/***  -	   SYSTICK_private.c                                     ***/
/***  - Created  : 31/5/2023                                     ***/
/***  - Author   : Hassan Ehab                                   ***/
/***  - Version  : V01                                           ***/
/*******************************************************************/
/*******************************************************************/

#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H


#define SYSTICK_BASE_ADDRESS 0xE000E010

typedef struct
{
	volatile u32 STK_CTRL;
	volatile u32 STK_LOAD;
	volatile u32 STK_VAL;
    volatile u32 STK_CALIB;

}SYSTICK_REG_s;

#define SYSTICK_REG ((volatile SYSTICK_REG_s *)SYSTICK_BASE_ADDRESS)

#define STK_CTRL_ENABLE		0
#define STK_CTRL_TICKINT	1
#define STK_CTRL_CLKSOURCE	2
#define STK_CTRL_COUNTFLAG	16

#define SINGLE_INTERVAL    1
#define PERIODIC_INTERVAL  2


#endif
