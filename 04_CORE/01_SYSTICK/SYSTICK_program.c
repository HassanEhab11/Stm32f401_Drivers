/*******************************************************************/
/*******************************************************************/
/***  -	   SYSTICK_program.c                                     ***/
/***  - Created  : 31/5/2023                                     ***/
/***  - Author   : Hassan Ehab                                   ***/
/***  - Version  : V01                                           ***/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_private.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"

static void (*SYSTICK_CALLBACK)(void) = NULL;
static u8 Interval_State = 0;
static u32 AHP_Freq = 0;

void MSTK_vInit(void)
{
#if CLKSOURCE == AHB_8
	SYSTICK_REG->STK_CTRL = 0;
	AHP_Freq = 2000;

#elif CLKSOURCE == AHB
	AHP_Freq = 16000;
	SET_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_CLKSOURCE);
	CLR_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_ENABLE);
	CLR_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_TICKINT);
#endif

}

void MSTK_vBusyWait(u32 Copy_u32TicksNum)
{
	SYSTICK_REG->STK_LOAD = Copy_u32TicksNum;
	SET_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_ENABLE);
	while(!GET_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_COUNTFLAG));
	MSTK_vSTOP();
}

void MSTK_vBusyWait_AHP_8MHZ(u32 Copy_u32Time_ms)
{
	u32 Local_u32TickNumber = Copy_u32Time_ms * AHP_Freq;
	SYSTICK_REG->STK_LOAD = Local_u32TickNumber;
	SET_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_ENABLE);
	while(!GET_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_COUNTFLAG));
	MSTK_vSTOP();

}

void MSTK_vSTOP(void)
{
	CLR_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_ENABLE);
	CLR_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_TICKINT);
	SYSTICK_REG->STK_LOAD = 0;
	SYSTICK_REG->STK_VAL = 0;

}

u32  MSTK_u32GetRemTime(void)
{
	return (SYSTICK_REG->STK_VAL);
}

u32  MSTK_u32GetElapsedTime(void)
{
	return (SYSTICK_REG->STK_LOAD - SYSTICK_REG->STK_VAL);
}


void MSTK_vSingleInterval(u32 Copy_u32Time ,void (*Copy_Syctick_Callback)(void))
{
	SYSTICK_CALLBACK = Copy_Syctick_Callback;
	Interval_State = SINGLE_INTERVAL;
	SYSTICK_REG->STK_LOAD = Copy_u32Time;
	SET_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_TICKINT);
	SET_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_ENABLE);


}

void MSTK_vPeriodicInterval(u32 Copy_u32Time ,void (*Copy_Syctick_Callback)(void))
{
	SYSTICK_CALLBACK = Copy_Syctick_Callback;
	Interval_State = PERIODIC_INTERVAL;
	SYSTICK_REG->STK_LOAD = Copy_u32Time;
	SET_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_TICKINT);
	SET_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_ENABLE);


}


void SysTick_Handler(void)
{
	volatile u8 Local_u8Temp = 0;
	SYSTICK_CALLBACK();
	if( Interval_State == SINGLE_INTERVAL )
	{
		MSTK_vSTOP();
	}
	else if( Interval_State == PERIODIC_INTERVAL )
	{

	}
	else
	{

	}
	/* Clear By Reading it*/
	Local_u8Temp = GET_BIT(SYSTICK_REG->STK_CTRL, STK_CTRL_COUNTFLAG);
}
