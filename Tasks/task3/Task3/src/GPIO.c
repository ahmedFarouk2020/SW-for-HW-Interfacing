/***************************************
 * 				GPIO.c
 * contains implementation of all module's functions
 *
 * Author: Farouk
 *
 * Date: 3-12-2021
 *
 */

#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"

void GPIO_RCC_Init(unsigned char port)
{
	RCC_AHB1ENR |= (1 <<port);
}

void GPIO_Init(unsigned char Port, unsigned char PIN_NO, unsigned char PIN_Dir)
{
	switch(Port)
	{
		case PORTA:
			// clear this bit field
			GPIOA_MODER &= ~(0x03 << (2*PIN_NO));
			// assign value for the bit field
			GPIOA_MODER |= (PIN_Dir>>4) <<(2*PIN_NO); // 0x10

			if((PIN_Dir>>4) == 1) /* output */
			{
				// clear the bit field
				GPIOA_OTYPER &= ~(1 << PIN_NO);
				// assign value for the bit field
				GPIOA_OTYPER |= (PIN_Dir & 0x0f) <<PIN_NO;
			}

			else if ((PIN_Dir>>4) == 1)  /* input */
			{
				// clear bit field
				GPIOA_PUPDR &= ~(3 << (PIN_NO*2));
				// assign value for the bit field
				GPIOA_PUPDR |= (PIN_Dir & 0x0f) <<(PIN_NO*2);
			}
			else
			{
				// error
			}
			break;

		case PORTB:
			// clear this bit field
			GPIOB_MODER &= ~(0x03 << (2*PIN_NO));
			// assign value for the bit field
			GPIOB_MODER |= (PIN_Dir>>4) <<(2*PIN_NO);

			if((PIN_Dir>>4) == 1)   /* output */
			{
				// clear the bit field
				GPIOB_OTYPER &= ~(1 << PIN_NO);
				// assign value for the bit field
				GPIOB_OTYPER |= (PIN_Dir & 0x0f) <<PIN_NO;
			}

			else if ((PIN_Dir>>4) == 1)  /* input */
			{
				// clear bit field
				GPIOB_PUPDR &= ~(3 << (PIN_NO*2));
				// assign value for the bit field
				GPIOB_PUPDR |= (PIN_Dir & 0x0f) <<(PIN_NO*2);
			}
			else { /* error */ }
	}

}

void GPIO_WritePin(unsigned char Port, unsigned char PIN_NO, unsigned char Data)
{
	// filtering Data
	if(Data != 0) { Data=1; }

	switch(Port)
	{
		case PORTA:
			// clear bits
			GPIOA_ODR &= ~(1<< PIN_NO);
			// assign "Data" to bits
			GPIOA_ODR |= (Data << PIN_NO);
			break;

		case PORTB:
			// clear bits
			GPIOB_ODR &= ~(1<< PIN_NO);
			// assign "Data" to bits
			GPIOB_ODR |= (Data << PIN_NO);
			break;
	}
}

unsigned char GPIO_ReadPin(char Port, unsigned char PIN_NO)
{
	unsigned char PinState = 255;

	switch(Port)
	{
		case(PORTA):
				PinState = ( GPIOA_IDR & (1<<PIN_NO) ) >> PIN_NO;
				break;
		case(PORTB):
				PinState = ( GPIOB_IDR & (1<<PIN_NO) ) >> PIN_NO;
				break;

	}// end switch

	return PinState;
}

