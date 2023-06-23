#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"



void MRCC_vInitSystemClock(void)
{
	CLR_BIT(RCC_REG->CR, CR_HSION);
	CLR_BIT(RCC_REG->CR, CR_HSEON);
	CLR_BIT(RCC_REG->CR, CR_PLLON);

#if CLOCK_SOURCE == HSI
	/* Select HSI as system clock */
	CLR_BIT(RCC_REG->CFGR, CFGR_SW0);
	CLR_BIT(RCC_REG->CFGR, CFGR_SW1);

	/* EN HSI */
	SET_BIT(RCC_REG->CR, CR_HSION);
	while(!GET_BIT(RCC_REG->CR, CR_HSIRDY));

#elif CLOCK_SOURCE == HSE
	/* Select HSE as system clock */
	SET_BIT(RCC_REG->CFGR, CFGR_SW0);
	CLR_BIT(RCC_REG->CFGR, CFGR_SW1);
	/* HSE Source */
#if HSE_SOURCE == _HSE_CRYSTAL
	CLR_BIT(RCC_REG->CR, CR_HSEBYP);
#elif  HSE_SOURCE == _HSE_RC
	SET_BIT(RCC_REG->CR, CR_HSEBYP);
#endif
	/* EN HSE */
	SET_BIT(RCC_REG->CR, CR_HSEON);
	while(!GET_BIT(RCC_REG->CR, CR_HSERDY));

#elif CLOCK_SOURCE == PLL
	/* Select PLL as system clock */
	SET_BIT(RCC_REG->CFGR, CFGR_SW0);
	CLR_BIT(RCC_REG->CFGR, CFGR_SW1);
	/* EN PLL */
	SET_BIT(RCC_REG->CR, CR_PLLON);
	while(!GET_BIT(RCC_REG->CR, CR_PLLRDY));

#endif

}


void MRCC_vSetPeripheralClock_Enable(BusType_e Copy_eBusType, u8 Copy_u8Peripheral)
{
	switch(Copy_eBusType)
	{
	case AHB1_BUS : SET_BIT(RCC_REG->AHB1ENR, Copy_u8Peripheral);   break;
	case AHB2_BUS : SET_BIT(RCC_REG->AHB2ENR, Copy_u8Peripheral);   break;
	case APB1_BUS : SET_BIT(RCC_REG->APB1ENR, Copy_u8Peripheral);   break;
	case APB2_BUS : SET_BIT(RCC_REG->APB2ENR, Copy_u8Peripheral);   break;
	}

}
void MRCC_vSetPeripheralClock_Disable(BusType_e Copy_eBusType, u8 Copy_u8Peripheral)
{

	switch(Copy_eBusType)
	{
	case AHB1_BUS : CLR_BIT(RCC_REG->AHB1ENR, Copy_u8Peripheral);   break;
	case AHB2_BUS : CLR_BIT(RCC_REG->AHB2ENR, Copy_u8Peripheral);   break;
	case APB1_BUS : CLR_BIT(RCC_REG->APB1ENR, Copy_u8Peripheral);   break;
	case APB2_BUS : CLR_BIT(RCC_REG->APB2ENR, Copy_u8Peripheral);   break;
	}



}
