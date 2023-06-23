/***************************************************************************************
*                          Author : Kareem Ashraf                                      *
*                          Company: coretech  & IMT									   *
*                          Date   : 06/01/2023                                         *
*                          Version: 1.0                                                *
*                          Description:                                 *
***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "HLEDMAT_interface.h"
#include "HLEDMAT_private.h"
#include "HLEDMAT_config.h"

void HLEDMAT_voidInit(void)
{
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_ROW_PORT, HLED_MATRIX_ROW_PIN_0, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_ROW_PORT, HLED_MATRIX_ROW_PIN_1, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_ROW_PORT, HLED_MATRIX_ROW_PIN_2, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_ROW_PORT, HLED_MATRIX_ROW_PIN_3, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_ROW_PORT, HLED_MATRIX_ROW_PIN_4, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_ROW_PORT, HLED_MATRIX_ROW_PIN_5, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_ROW_PORT, HLED_MATRIX_ROW_PIN_6, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_ROW_PORT, HLED_MATRIX_ROW_PIN_7, MEDIUM_SPEED);

	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_COL_PORT, HLED_MATRIX_COL_PIN_0, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_COL_PORT, HLED_MATRIX_COL_PIN_1, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_COL_PORT, HLED_MATRIX_COL_PIN_2, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_COL_PORT, HLED_MATRIX_COL_PIN_3, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_COL_PORT, HLED_MATRIX_COL_PIN_4, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_COL_PORT, HLED_MATRIX_COL_PIN_5, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_COL_PORT, HLED_MATRIX_COL_PIN_6, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(HLED_MATRIX_COL_PORT, HLED_MATRIX_COL_PIN_7, MEDIUM_SPEED);

}

void HLEDMAT_voidDisplay(u8 *Copy_u8Frame)
{
	while(1)
	{
		u8 Local_u8BIT ;

		for(u32 i=0 ; i<8 ; i++)
		{
			/** make col idle state active low**/
			for(u32 x=0 ; x<8 ; x++)
			{
				MGPIO_vSetPIN_State(PORT_B, x, PIN_HIGH);
			}
			MGPIO_vSetPIN_State(PORT_B, i, PIN_LOW);
			for(u32 j=0 ; j<8 ; j++)
			{
				Local_u8BIT = GET_BIT(Copy_u8Frame[i],j) ;
				MGPIO_vSetPIN_State(PORT_A, j, Local_u8BIT);
			}
			MSTK_vBusyWait(2500);
		}
	}
}
