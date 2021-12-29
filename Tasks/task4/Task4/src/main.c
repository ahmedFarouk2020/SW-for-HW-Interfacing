#include "GPIO_Interface.h"
#include "EXTI_Interface.h"

#include "SevenSegment.h"

void ISR_IncCounter(void);
void ISR_DecCounter(void);

volatile char counter = 0;

void main(void)
{
	GPIO_EnableClk(PORTA);// enable GPIOA clk
	GPIO_EnableClk(PORTB);// enable GPIOB clk

	GPIO_Init(PORTA,PIN5,OUTPUT_PUSHPULL); // led

	SevenSegment_Init();

	// define 2 external interrupt sources
	EXTI_init(PORTA,PIN1,EXTI1);
	EXTI_init(PORTA,PIN0,EXTI0);

	// set callback to these EXTIs
	EXTI_setCallBack0(ISR_IncCounter);
	EXTI_setCallBack1(ISR_DecCounter);

	unsigned char Loc_counter = 0;
	while(1)
	{
		EXTI_DisableAllLines();
		Loc_counter = counter; // the critical section
		EXTI_EnableAllLines();

		SevenSegment_WriteDigit(Loc_counter);

	}
}



void ISR_IncCounter(void)
{
	counter++;
	if(counter>9) { counter=9; }
	EXTI_clearFlag(LINE0);

}

void ISR_DecCounter(void)
{
	counter--;
	if(counter<0) { counter=0; }
	EXTI_clearFlag(LINE1);
}

