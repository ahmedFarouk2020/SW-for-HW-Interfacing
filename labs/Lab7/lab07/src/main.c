#include "GPIO_Interface.h"
#include "EXTI_Interface.h"

void ISR_led(void)
{
	GPIO_WritePin(PORTA,PIN1,1);
	EXTI_clearFlag(0);
}


void main(void)
{
	GPIO_EnableClk(PORTA);
	GPIO_Init(PORTA,PIN1,OUTPUT_PUSHPULL); // led
	EXTI_init(PORTA,PIN0);
	//EXTI_setCallBack(ISR_led);
	while(1)
	{

	}
}




