/*******************************************************************/
/*******************************************************************/
/***  -	   EXTI_program.c                                     ***/
/***  - Created  : 1/6/2023                                     ***/
/***  - Author   : Hassan Ehab                                   ***/
/***  - Version  : V01                                           ***/
/*******************************************************************/
/*******************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SYSCFG_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"

#define EXTI_NUM   16

static void (*EXTIx_CALLBACK[EXTI_NUM])(void) = {NULL};

void MEXTI_vEnableLine(EXTI_LINES_e Copy_eLineNUM)
{
	SET_BIT(MEXTI->IMR, Copy_eLineNUM);

}

void MEXTI_vDisableLine(EXTI_LINES_e Copy_eLineNUM)
{
	CLR_BIT(MEXTI->IMR, Copy_eLineNUM);

}

void MEXTI_vEventTriggerType(EXTI_LINES_e Copy_eLineNUM , TRIGGER_Type_e Copy_eEventType  )
{
	switch(Copy_eEventType)
	{
	case _RAISE_STATE :
		SET_BIT(MEXTI->RTSR, Copy_eLineNUM);
		CLR_BIT(MEXTI->FTSR, Copy_eLineNUM);

		break;
	case _FALL_STATE :
		SET_BIT(MEXTI->FTSR, Copy_eLineNUM);
		CLR_BIT(MEXTI->RTSR, Copy_eLineNUM);

		break;
	case _ON_CHANGE_STATE :
		SET_BIT(MEXTI->RTSR, Copy_eLineNUM);
		SET_BIT(MEXTI->FTSR, Copy_eLineNUM);
		break;

	}
}

void MEXTI_vTrigSW(EXTI_LINES_e Copy_eLineNUM)
{
	SET_BIT(MEXTI->SWIER ,Copy_eLineNUM );
}

u8 MEXTI_vGetPendingStatus(EXTI_LINES_e Copy_eLineNUM)
{
	return(GET_BIT( MEXTI -> PR,Copy_eLineNUM));
}

void MEXTI_vSelectPort(Port_t Copy_ePortNum,  EXTI_LINES_e Copy_eLineNUM)
{
	if(Copy_eLineNUM <= 3)
	{
		MSYSCFG->EXTICR1 &= ~(0b1111 << (4 * (Copy_eLineNUM % 4)));
		MSYSCFG->EXTICR1 |= (Copy_ePortNum << (4 * (Copy_eLineNUM % 4)));

	}
	else if(Copy_eLineNUM <= 7)
	{
		MSYSCFG->EXTICR2 &= ~(0b1111 << (4 * (Copy_eLineNUM % 4)));
		MSYSCFG->EXTICR2 |= (Copy_ePortNum << (4 * (Copy_eLineNUM % 4)));
	}
	else if(Copy_eLineNUM <= 11)
	{
		MSYSCFG->EXTICR3 &= ~(0b1111 << (4 * (Copy_eLineNUM % 4)));
		MSYSCFG->EXTICR3 |= (Copy_ePortNum << (4 * (Copy_eLineNUM % 4)));
	}
	else if(Copy_eLineNUM <= 15)
	{
		MSYSCFG->EXTICR4 &= ~(0b1111 << (4 * (Copy_eLineNUM % 4)));
		MSYSCFG->EXTICR4 |= (Copy_ePortNum << (4 * (Copy_eLineNUM % 4)));
	}
	else
	{
		//error
	}


}

/*Call Back Function to EXTI*/
void MEXTI_vSetCallBack( u8 Copy_EXTINum,  void (*Copy_EXTI_CallBack)(void))
{
	EXTIx_CALLBACK[Copy_EXTINum] = Copy_EXTI_CallBack ;
}


/***************************************   ISR FOR EXTIx    *******************************/

void EXTI0_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 0U);
	EXTIx_CALLBACK[0]();
}

void EXTI1_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 1U);
	EXTIx_CALLBACK[1]();
}

void EXTI2_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 2U);
	EXTIx_CALLBACK[2]();
}


void EXTI3_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 3U);
	EXTIx_CALLBACK[3]();
}

void EXTI4_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 4U);
	EXTIx_CALLBACK[4]();
}

void EXTI5_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 5U);
	EXTIx_CALLBACK[5]();
}

void EXTI6_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 6U);
	EXTIx_CALLBACK[6]();
}

void EXTI7_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 7U);
	EXTIx_CALLBACK[7]();
}
void EXTI8_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 8U);
	EXTIx_CALLBACK[8]();
}
void EXTI9_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 9U);
	EXTIx_CALLBACK[9]();
}
void EXTI10_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 10U);
	EXTIx_CALLBACK[10]();
}
void EXTI11_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 11U);
	EXTIx_CALLBACK[11]();
}
void EXTI12_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 12U);
	EXTIx_CALLBACK[12]();
}

void EXTI13_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 13U);
	EXTIx_CALLBACK[13]();
}
void EXTI14_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 14U);
	EXTIx_CALLBACK[14]();
}
void EXTI15_IRQHandler(void)
{
	SET_BIT(MEXTI -> PR , 15U);
	EXTIx_CALLBACK[15]();
}
