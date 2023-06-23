/*******************************************************************/
/*******************************************************************/
/***  -	   SYSCFG_private.h                               	      ***/
/***  - Created  : 1/6/2023                                     ***/
/***  - Author   : Hassan Ehab                                   ***/
/***  - Version  : V01                                           ***/
/*******************************************************************/
/*******************************************************************/

#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H

#define SYSCFG_BASE_ADDRESS 0x40013800

typedef struct
{
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR1;
	volatile u32 EXTICR2;
	volatile u32 EXTICR3;
	volatile u32 EXTICR4;
	volatile u32 CMPCR;

}SYSCFG_REG_s;

#define MSYSCFG ((SYSCFG_REG_s *)(SYSCFG_BASE_ADDRESS))

#endif
