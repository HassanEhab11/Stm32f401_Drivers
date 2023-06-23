/*******************************************************************/
/*******************************************************************/
/***  -	   GPIO_program.c                                         ***/
/***  - Created  : 29/5/2023                                     ***/
/***  - Author   : Hassan Ehab                                   ***/
/***  - Version  : V01                                           ***/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"

#define PORT_NUM 8
#define SPEED_NUM 4

/************************ Static function prototype ***************************/
static void GPIOx_OutPut_PushPull(PORT_e Copy_ePortId, PIN_e Copy_ePinId);
static void GPIOx_OutPut_OpenDrain(PORT_e Copy_ePortId, PIN_e Copy_ePinId);
static void GPIOx_Input(PORT_e Copy_ePortId, PIN_e Copy_ePinId);
static void GPIOx_AF(PORT_e Copy_ePortId, PIN_e Copy_ePinId);
static void GPIOx_Analog(PORT_e Copy_ePortId, PIN_e Copy_ePinId);

static void GPIOx_Pin_LowSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId);
static void GPIOx_Pin_MediumSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId);
static void GPIOx_Pin_HighSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId);
static void GPIOx_Pin_VeryHighSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId);
/******************************************************************************/

static GPIOx_REG_s *GPIO_Port[PORT_NUM] = {GPIOA_REG, GPIOB_REG, GPIOC_REG, GPIOD_REG, GPIOE_REG, GPIOH_REG};
static void (*GPIOx_Pin_Speed[SPEED_NUM])(PORT_e Copy_ePortId, PIN_e Copy_ePinId) = {GPIOx_Pin_LowSpeed, GPIOx_Pin_MediumSpeed, GPIOx_Pin_HighSpeed, GPIOx_Pin_VeryHighSpeed};

void MGPIO_vSetPIN_Output_PushPull(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_SPEED_e Copy_ePinSpeed)
{
	GPIOx_OutPut_PushPull(Copy_ePortId, Copy_ePinId);
	GPIOx_Pin_Speed[Copy_ePinSpeed](Copy_ePortId, Copy_ePinId);

}

void MGPIO_vSetPIN_Output_Opendrain(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_SPEED_e Copy_ePinSpeed)
{
	GPIOx_OutPut_OpenDrain(Copy_ePortId, Copy_ePinId);
	GPIOx_Pin_Speed[Copy_ePinSpeed](Copy_ePortId, Copy_ePinId);
}

void MGPIO_vSetPIN_State(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_STATE_e Copy_ePinState)
{
	switch (Copy_ePinState)
		{
		case PIN_HIGH:
			SET_BIT(GPIO_Port[Copy_ePortId]->ODR, Copy_ePinId);
			break;
		case PIN_LOW:
			CLR_BIT(GPIO_Port[Copy_ePortId]->ODR, Copy_ePinId);
			break;
		}
}

void MGPIO_vSetPIN_Input(PORT_e Copy_ePortId, PIN_e Copy_ePinId, PIN_PULL_e Copy_ePullState, PIN_SPEED_e Copy_ePinSpeed)
{

	GPIOx_Input(Copy_ePortId, Copy_ePinId);
	GPIOx_Pin_Speed[Copy_ePinSpeed](Copy_ePortId, Copy_ePinId);

	switch(Copy_ePullState)
	{
	case PULL_OFF:
		GPIO_Port[Copy_ePortId]->PUPDR |= (u32) (Copy_ePullState <<(2U * Copy_ePinId));
		break;
	case PULL_UP:
		SET_BIT(GPIO_Port[Copy_ePortId]->PUPDR, (Copy_ePinId*2));
		CLR_BIT(GPIO_Port[Copy_ePortId]->PUPDR, ((Copy_ePinId*2) +1 ));
		break;
	case PULL_DOWN:
		CLR_BIT(GPIO_Port[Copy_ePortId]->PUPDR, (Copy_ePinId*2));
		SET_BIT(GPIO_Port[Copy_ePortId]->PUPDR, ((Copy_ePinId*2) +1 ));
		break;
	}

}

u8 MGPIO_u8GetPinState(PORT_e Copy_ePortId, PIN_e Copy_ePinId)
{
	u8 Local_u8PinVal = 0;
		Local_u8PinVal = GET_BIT(GPIO_Port[Copy_ePortId]->IDR, Copy_ePinId);

		return Local_u8PinVal;
}


/************************** Static Function Implementation ***************/
static void GPIOx_OutPut_PushPull(PORT_e Copy_ePortId, PIN_e Copy_ePinId)
{
	/* PIN OUTPUT */
	SET_BIT(GPIO_Port[Copy_ePortId]->MODER, (Copy_ePinId*2));
	CLR_BIT(GPIO_Port[Copy_ePortId]->MODER, ((Copy_ePinId*2) +1 ));

	/* PIN PUSH PULL*/
	CLR_BIT(GPIO_Port[Copy_ePortId]->OTYPER, Copy_ePinId);

}

static void GPIOx_OutPut_OpenDrain(PORT_e Copy_ePortId, PIN_e Copy_ePinId)
{
	/* PIN OUTPUT */
	SET_BIT(GPIO_Port[Copy_ePortId]->MODER, (Copy_ePinId*2));
	CLR_BIT(GPIO_Port[Copy_ePortId]->MODER, ((Copy_ePinId*2) +1 ));

	/* PIN OPEN DRAIN*/
	SET_BIT(GPIO_Port[Copy_ePortId]->OTYPER, Copy_ePinId);

}
static void GPIOx_Input(PORT_e Copy_ePortId, PIN_e Copy_ePinId)
{
	/* PIN OUTPUT */
	CLR_BIT(GPIO_Port[Copy_ePortId]->MODER, (Copy_ePinId*2));
	CLR_BIT(GPIO_Port[Copy_ePortId]->MODER, ((Copy_ePinId*2) +1 ));
}

static void GPIOx_AF(PORT_e Copy_ePortId, PIN_e Copy_ePinId)
{
	/* PIN OUTPUT */
	CLR_BIT(GPIO_Port[Copy_ePortId]->MODER, (Copy_ePinId*2));
	SET_BIT(GPIO_Port[Copy_ePortId]->MODER, ((Copy_ePinId*2) +1 ));
}
static void GPIOx_Analog(PORT_e Copy_ePortId, PIN_e Copy_ePinId)
{
	/* PIN OUTPUT */
	SET_BIT(GPIO_Port[Copy_ePortId]->MODER, (Copy_ePinId*2));
	SET_BIT(GPIO_Port[Copy_ePortId]->MODER, ((Copy_ePinId*2) +1 ));
}
static void GPIOx_Pin_LowSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId)
{
	/* PIN LOW SPEED */
	CLR_BIT(GPIO_Port[Copy_ePortId]->OSPEEDR, (Copy_ePinId*2));
	CLR_BIT(GPIO_Port[Copy_ePortId]->OSPEEDR, ((Copy_ePinId*2) +1 ));

}

static void GPIOx_Pin_MediumSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId)
{
	/* PIN Medium SPEED */
	SET_BIT(GPIO_Port[Copy_ePortId]->OSPEEDR, (Copy_ePinId*2));
	CLR_BIT(GPIO_Port[Copy_ePortId]->OSPEEDR, ((Copy_ePinId*2) +1 ));

}

static void GPIOx_Pin_HighSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId)
{
	/* PIN High SPEED */
	CLR_BIT(GPIO_Port[Copy_ePortId]->OSPEEDR, (Copy_ePinId*2));
	SET_BIT(GPIO_Port[Copy_ePortId]->OSPEEDR, ((Copy_ePinId*2) +1 ));

}

static void GPIOx_Pin_VeryHighSpeed(PORT_e Copy_ePortId, PIN_e Copy_ePinId)
{
	/* PIN Very High SPEED */
	SET_BIT(GPIO_Port[Copy_ePortId]->OSPEEDR, (Copy_ePinId*2));
	SET_BIT(GPIO_Port[Copy_ePortId]->OSPEEDR, ((Copy_ePinId*2) +1 ));

}
