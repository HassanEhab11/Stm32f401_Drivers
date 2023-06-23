/*******************************************************************/
/*******************************************************************/
/***  -	   SYSTICK_interface.c                                     ***/
/***  - Created  : 31/5/2023                                     ***/
/***  - Author   : Hassan Ehab                                   ***/
/***  - Version  : V01                                           ***/
/*******************************************************************/
/*******************************************************************/

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

#define  AHB_8   1
#define  AHB     2


void MSTK_vInit(void);

void MSTK_vBusyWait(u32 Copy_u32TicksNum);

void MSTK_vBusyWait_AHP_8MHZ(u32 Copy_u32Time_ms);

void MSTK_vSTOP(void);

u32  MSTK_u32GetRemTime(void);

u32  MSTK_u32GetElapsedTime(void);

void MSTK_vSingleInterval(u32 Copy_u32Time ,void (*Copy_Syctick_Callback)(void));

void MSTK_vPeriodicInterval(u32 Copy_u32Time ,void (*Copy_Syctick_Callback)(void));




#endif
