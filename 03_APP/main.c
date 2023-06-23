/*
 * main.c
 *
 *  Created on: May 30, 2023
 *      Author: hassa
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

u8 Pin_State =  0;
void main (void)
{
	/* Init System Clock */
	MRCC_vInitSystemClock();

	/* Init Peripheral Clock*/
	MRCC_vSetPeripheralClockState(AHB1_BUS, GPIOA_AHB1_EN, RCC_ENAPLE);
	MGPIO_vSetPIN_Output_PushPull_LowSpeed(PORT_A, PIN_1);
	MGPIO_vSetPIN_Input_LowSpeed(PORT_A, PIN_0, PULL_OFF);


	while (1)
	{
		Pin_State = MGPIO_u8GetPinState(PORT_A, PIN_0);
		if (Pin_State == 1)
			MGPIO_vSetPIN_State(PORT_A, PIN_1, PIN_HIGH);

		/* GPIOA Pin0 HIGh*/
		//for (int i = 0; i< 100000; i++);
		/* GPIOA Pin0 Low*/
		else if (Pin_State == 0)
		//	MGPIO_vSetPIN_Output_PushPull_LowSpeed(PORT_A, PIN_1, PIN_LOW);
			MGPIO_vSetPIN_State(PORT_A, PIN_1, PIN_LOW);

		//}
		/*MGPIO_vSetPIN_State(PORT_A, PIN_1, PIN_HIGH);
		for (int i = 0; i< 100000; i++);
		MGPIO_vSetPIN_State(PORT_A, PIN_1, PIN_LOW);
		for (int i = 0; i< 100000; i++);*/


	}





}

