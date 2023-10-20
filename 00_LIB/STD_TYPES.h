/*************************************************************************/
/*************************************************************************/
/********************    Author     : Hassan Ehab     ********************/
/********************    Layer      : LIB             ********************/
/********************    SWC(Driver): STD_TYPES       ********************/
/********************    Version    : 1.00            ********************/
/********************    Date       : 17/08/2022      ********************/
/*************************************************************************/
/*************************************************************************/

#ifndef _STD_TYPES_H
#define _STD_TYPES_H

// u : unsigned  <----> s : signed (+,-) <---> f : floating point
// u(  8 - 16 - 32 )        
// s(  8 - 16 - 32 )
// f( 32 - 64 - 80 )
// char          --> 1  byte   --  8  bit
// short int     --> 2  byte   --  16  bit
// long int      --> 4  byte   --  32  bit
// float         --> 4  byte   --  32  bit
// double        --> 8  byte   --  64  bit
// long double   --> 10 byte   --  128 bit


typedef   unsigned char         u8  ;    // positive only 0 to 255
typedef   signed char           s8  ;    // positive and negative (0 -> 127) and (-1 -> -128)

typedef   unsigned short int    u16 ;
typedef    signed short int     s16 ;

typedef   unsigned long int     u32 ;
typedef     signed long int     s32 ;

typedef   float                 f32 ;
typedef   double                f64 ;
typedef   long double           f128;

#define NULL		(void * ) 0

#define OK                      0
#define NOK                     1
#define NULL_POINTER            2
#define BUSY_FUNC               3


//s32 Map(s32 Copy_s32InputMin, s32 Copy_s32InputMax, s32 Copy_s32OutputMin, s32 Copy_s32OutputMax, s32 Copy_s32InputVal)
//{
//	s32 Local_s32OutputVal;
//	Local_s32OutputVal = Copy_s32InputVal - Copy_s32InputMin;
//	Local_s32OutputVal *= Copy_s32OutputMax- Copy_s32OutputMin;
//	Local_s32OutputVal /= Copy_s32InputMax -Copy_s32InputMin;
//	Local_s32OutputVal += Copy_s32OutputMin;
//	return Local_s32OutputVal;
//}


#endif


