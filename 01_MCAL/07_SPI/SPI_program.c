#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void (*MSPI1_CallBack) (void);

void MSPI_MastervoidInit(void)
{
	/*Clock phase */
	CLR_BIT(MSPI1->CR1, 0);   // 0: The first clock transition is the first data capture edge
	/* clock plarity*/
	SET_BIT(MSPI1->CR1, 1);   // 1: CK to 1 when idle

	/*master */
	SET_BIT(MSPI1->CR1, 2);   // 1: Master configuration

	/*LSB , MSB*/
	SET_BIT(MSPI1->CR1, 7);   // 1: LSB transmitted first

	/*send and recive*/
	SET_BIT(MSPI1->CR1, 10);   // 1: Output disabled (Receive-only mode)

	/*Slave select by S.W*/
	SET_BIT(MSPI1->CR1, 9);   // 1: Software slave management enabled

	/*8 bit data*/
	CLR_BIT(MSPI1->CR1, 11);   // 0: 8-bit data frame format is selected for transmission/reception



	/*Enable spi*/
	SET_BIT(MSPI1->CR1, 6);   // 1: Peripheral enabled

}

u8 MSPI1_VidSendDataU8 ( u8 Copy_u8Data ){

	MSPI1 -> DR = Copy_u8Data;

	while ( GET_BIT( MSPI1 -> SR , 7) == 1 );

	return (u8) MSPI1 -> DR ;

}

void MSPI_SendRecievptr(u8 Copy_DataTransmit,u8 *Copy_u8RetData)
{
	/*GPIO PIN Slave select Low , // Active low*/
	MGPIO_vSetPIN_State(SLAVE_1_PORT, SLAVE_1_PIN, PIN_LOW);

	/*REGISTER OF data = Copy_DataT*/
	MSPI1->DR = Copy_DataTransmit;
	while (GET_BIT(MSPI1->SR,7));
	//while (GET_BIT(MSPI1->SR,1));

	/* pointerReciev ??? = REGISTER OF data*/
	*Copy_u8RetData = MSPI1->DR;

	/*GPIO PIN Slave select HIGH  , // OFF high*/
	MGPIO_vSetPIN_State(SLAVE_1_PORT, SLAVE_1_PIN, PIN_HIGH);

}

void MSPI1_VidSetCallBack( void (*ptr) (void) ){

	MSPI1_CallBack = ptr;

}

void SPI1_IRQHandler(void){

	MSPI1_CallBack();

}

