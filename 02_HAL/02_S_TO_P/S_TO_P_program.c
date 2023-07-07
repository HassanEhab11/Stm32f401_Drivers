
/* serial to parrallel */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"

#include "SYSTICK_interface.h"

#include "S_TO_P_config.h"
#include "S_TO_P_interface.h"



void Pin_Clock(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	MGPIO_vSetPIN_State(Copy_u8Port, Copy_u8Pin, PIN_HIGH);
	MSTK_vBusyWait(200);
	MGPIO_vSetPIN_State(Copy_u8Port, Copy_u8Pin, PIN_LOW);
	MSTK_vBusyWait(200);


}
void STOP_voidInit(void)
{
	MGPIO_vSetPIN_Output_PushPull(S_TO_P_PORT, S_TO_P_DS_PIN, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(S_TO_P_PORT, S_TO_P_ST_PIN, MEDIUM_SPEED);
	MGPIO_vSetPIN_Output_PushPull(S_TO_P_PORT, S_TO_P_SH_PIN, MEDIUM_SPEED);
}
void STOP_voidSend(u8 Copy_u8DataSend)
{
	u8 Local_u8Val = 0;
	u8 Local_u8Itirator = 0;

	for(Local_u8Itirator = 7; Local_u8Itirator >=0; Local_u8Itirator--)
	{
		Local_u8Val = GET_BIT(Copy_u8DataSend, Local_u8Itirator);
		MGPIO_vSetPIN_State(S_TO_P_PORT, S_TO_P_DS_PIN, Local_u8Val);
		Pin_Clock(S_TO_P_PORT, S_TO_P_SH_PIN);
	}

	/* send data to */
	Pin_Clock(S_TO_P_PORT, S_TO_P_ST_PIN);

}
