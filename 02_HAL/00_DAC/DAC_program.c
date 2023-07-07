

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_private.h"
#include "DAC_interface.h"
#include "DAC_config.h"
#include "DAC_private.h"

#include "file.h"
volatile u32 i = 0 ;

void HDAC_voidOutputValue(void)
{
	GPIOA->ODR_ = Song_raw[i];
	i++;
	if(i == 205312)
	{
       i = 0 ;
	}
}


