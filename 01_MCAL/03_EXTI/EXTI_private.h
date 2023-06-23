/*******************************************************************/
/*******************************************************************/
/***  -	   EXTI_private.h                               	      ***/
/***  - Created  : 1/6/2023                                     ***/
/***  - Author   : Hassan Ehab                                   ***/
/***  - Version  : V01                                           ***/
/*******************************************************************/
/*******************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define EXTI_BASE_ADDRESS 0x40013C00

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_REG_s;

#define MEXTI ((EXTI_REG_s *)(EXTI_BASE_ADDRESS))

#endif
