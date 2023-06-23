/*******************************************************************/
/*******************************************************************/
/***  -	   EXTI_interface.h                                     ***/
/***  - Created  : 1/6/2023                                     ***/
/***  - Author   : Hassan Ehab                                   ***/
/***  - Version  : V01                                           ***/
/*******************************************************************/
/*******************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum
{
	_EXTI_LINE_0 = 0U ,
	_EXTI_LINE_1      ,
	_EXTI_LINE_2      ,
	_EXTI_LINE_3      ,
	_EXTI_LINE_4      ,
	_EXTI_LINE_5      ,
	_EXTI_LINE_6      ,
	_EXTI_LINE_7      ,
	_EXTI_LINE_8      ,
	_EXTI_LINE_9      ,
	_EXTI_LINE_10     ,
	_EXTI_LINE_11     ,
	_EXTI_LINE_12     ,
	_EXTI_LINE_13     ,
	_EXTI_LINE_14     ,
	_EXTI_LINE_15
}EXTI_LINES_e;

typedef enum
{
	_RAISE_STATE 		= 0U ,
	_FALL_STATE      		 ,
	_ON_CHANGE_STATE
}TRIGGER_Type_e;


typedef enum
{
	PORTA_EXTI = 0 ,
	PORTB_EXTI     ,
	PORTC_EXTI     ,
	PORTD_EXTI     ,
	PORTE_EXTI     ,
	PORTH_EXTI = 7
}Port_t;





void MEXTI_vEnableLine(EXTI_LINES_e Copy_eLineNUM);

void MEXTI_vDisableLine(EXTI_LINES_e Copy_eLineNUM);

void MEXTI_vEventTriggerType(EXTI_LINES_e Copy_eLineNUM , TRIGGER_Type_e Copy_eEventType  );

void MEXTI_vTrigSW(EXTI_LINES_e Copy_eLineNUM);

u8 MEXTI_vGetPendingStatus(EXTI_LINES_e Copy_eLineNUM);

void MEXTI_vSelectPort(Port_t Copy_ePortNum,  EXTI_LINES_e Copy_eLineNUM);

void MEXTI_vSetCallBack( u8 Copy_EXTINum,  void (*Copy_EXTI_CallBack)(void));




#endif
