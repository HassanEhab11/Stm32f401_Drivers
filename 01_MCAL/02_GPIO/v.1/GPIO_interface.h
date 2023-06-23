/*******************************************************************/
/*******************************************************************/
/***  -	   GPIO_interface.h                                         ***/
/***  - Created  : 31/5/2023                                     ***/
/***  - Author   : Hassan Ehab                                   ***/
/***  - Version  : V01                                           ***/
/*******************************************************************/
/*******************************************************************/

#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

/* Port id of ARM Cortex M4 Black bill kit*/
typedef enum
{
	PORT_A=0,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F,
	PORT_G,
	PORT_H
}PORT_e;

/* Pin id of ARM Cortex M4 Black bill kit*/
typedef enum
{
	PIN_0 = 0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15
}PIN_e;

/* PIN state */
typedef enum
{
	PIN_LOW=0,
	PIN_HIGH
}PIN_STATE_e;

typedef enum
{
	PULL_OFF =0,
	PULL_UP = 0x00000001,
	PULL_DOWN = 0x00000002
}PIN_PULL_e;

void MGPIO_vSetPIN_State(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_STATE_e Copy_ePinState);
u8 MGPIO_u8GetPinState(PORT_e Copy_ePortId, PIN_e Copy_ePinId);


void MGPIO_vSetPIN_Output_PushPull_LowSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId);
void MGPIO_vSetPIN_Output_PushPull_MediumSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_STATE_e Copy_ePinState);
void MGPIO_vSetPIN_Output_PushPull_HighSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_STATE_e Copy_ePinState);
void MGPIO_vSetPIN_Output_PushPull_VHighSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_STATE_e Copy_ePinState);

void MGPIO_vSetPIN_Output_Opendrain_LowSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_STATE_e Copy_ePinState);
void MGPIO_vSetPIN_Output_Opendrain_MediumSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_STATE_e Copy_ePinState);
void MGPIO_vSetPIN_Output_Opendrain_HighSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_STATE_e Copy_ePinState);
void MGPIO_vSetPIN_Output_Opendrain_VHighSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_STATE_e Copy_ePinState);

void MGPIO_vSetPIN_Input_LowSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_PULL_e Copy_ePullState);
u8 MGPIO_vSetPIN_Input_MediumSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_PULL_e Copy_ePullState);
u8 MGPIO_vSetPIN_Input_HighSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_PULL_e Copy_ePullState);
u8 MGPIO_vSetPIN_Input_VHighSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_PULL_e Copy_ePullState);

#endif
