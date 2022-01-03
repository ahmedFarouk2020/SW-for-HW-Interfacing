#include "GPIO_Interface.h"
#include "UART_Interface.h"


void main(void)
{
	GPIO_EnableClk(PORTA);
	GPIO_Init(PORTA,PIN2,ALTERNATE_FUNCTION_PP);
	UART_BindPin();

	UART_Init();

	UART_Transmit((char *)"Hello World");

	while(1) {}
}
