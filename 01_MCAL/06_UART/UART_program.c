#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"



void (*MUSART1_CallBack)(void);

void MUSART_VidInit ( void ){


	MUSART1 -> SR = 0 ;

	/* _8BIT_WORD_LENGTH*/
	CLR_BIT( MUSART1 -> CR1 , 12 );

	/* PARITY_DISABLE*/
	CLR_BIT( MUSART1 -> CR1 , 10 );


	/* INT_DISABLE*/
	CLR_BIT( MUSART1 -> CR1 , 5 );
	CLR_BIT( MUSART1 -> CR1 , 6 );
	CLR_BIT( MUSART1 -> CR1 , 7 );

	/* TRANSMITTER_ENABLE*/
	SET_BIT( MUSART1 -> CR1 , 3 );

	/* RECEIVER_ENABLE */

	SET_BIT( MUSART1 -> CR1 , 2 );


	/* ONE_STOP_BIT*/

	CLR_BIT( MUSART1 -> CR2 , 12 ); CLR_BIT( MUSART1 -> CR2 , 13 );


	// BAUD rate 9600

	MUSART1 -> BRR = 0x683 ;
	/* USART ENABLE */
	SET_BIT( MUSART1 -> CR1 , 13 );



}


void MUSART1_VidSendCharSync ( u8 Copy_u8Char ){

	MUSART1 -> DR = Copy_u8Char ;

	while( GET_BIT( MUSART1 -> SR , 6 ) == 0 );

	CLR_BIT( MUSART1 -> SR , 6 );

}

void MUSART1_VidSendStringSynch ( u8 * Copy_ptrString ){

	u8 LOC_u8Iterator = 0 ;

	while ( Copy_ptrString[ LOC_u8Iterator ] != '\0' ){

		MUSART1_VidSendCharSync( Copy_ptrString[ LOC_u8Iterator ] );
		LOC_u8Iterator++ ;

	}

}

u8 MUSART1_u8RecCharSynch ( void ){

	u8  LOC_u8Data  = 0 ;
	CLR_BIT ( MUSART1 -> SR, 5);

	while( ( GET_BIT ( MUSART1 -> SR, 5) == 0 ) );

	LOC_u8Data = MUSART1 -> DR;

	return LOC_u8Data;

}

u8 String[20];
u8 * MUSART1_PtrReadStringSynch ( void ){

	u8 LOC_Iterator = 0 , LOC_u8DataCome ;

	while( ( LOC_u8DataCome = MUSART1_u8RecCharSynch() ) != 13 ){

		String[ LOC_Iterator ] = LOC_u8DataCome ;
		LOC_Iterator++;
	}

	String[LOC_Iterator] = '\0';

	return ( String );

}


void MUSART1_VidSetCallBack( void (*ptr) (void) ){

	MUSART1_CallBack = ptr ;

}

void USART1_IRQHandler(void){

	MUSART1 -> SR = 0 ;
	MUSART1_CallBack();

}
