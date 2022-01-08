/*
 * UART.c
 *
 *  Created on: Dec 30, 2021
 *      Author: Farouk
 */
#include "UART_Private.h"
#include "UART_Interface.h"
#include <stdio.h>


/* read UART2 flag */
unsigned char UART_ReadFlag(void)
{
	return (USART_SR & (1<<6)) >> 6;
}


void UART_BindPin(void) {
	GPIOA_AFRL |=(0x7<<2 * 4); // put UART2 on PINA2
}


void UART_Init(void)
{

	// enable clk on UART2
	RCC_APB1ENR |= 1<<17;

	// baudrate define
	USART_BRR = 0x683;

	// enable UART2
	USART_CR1 |= 1<<13;

	// oversampling by 16 (default)
	USART_CR1 &= ~(1<<15);


	// define word size (8-bytes)
	USART_CR1 &= ~(1<<12);

	// enable transmitter
	USART_CR1 |= 1<<3;

}


void UART_Transmit(const char* string)
{
	// while the string finished
	while(*string) {
		// send byte
		USART_DR = *string;
		while(UART_ReadFlag() != 1);
		string++;

	}
}

void UART_PrintInt(unsigned short number)
{
    char str[4];
    sprintf(str,"%d",number);
    UART_Transmit(str);
}

