/*
 * SEVEN_SEGMENT.c
 *
 *  Created on: Nov 25, 2021
 *      Author: Farouk
 */

#include "GPIO_Interface.h"

#include "SevenSegment.h"
#include "SevenSegment_Config.h"


		/* Shared Data */
char SevenSegment_CurrentDisplayedNumber = NO_DATA_DISPLAYED;

/**************
 * Initialize pins that will be used to write on 7 segment
 *
 * Args: None
 * Return: None
 */
void SevenSegment_Init(void)
{
	/* Enable PORTA CLK */
	GPIO_EnableClk(PORTA);

	GPIO_Init(PORTA, 0 , OUTPUT_PUSHPULL);// a
	GPIO_Init(PORTA, 1 , OUTPUT_PUSHPULL);// b
	GPIO_Init(PORTA, 2 , OUTPUT_PUSHPULL);// c
	GPIO_Init(PORTA, 3 , OUTPUT_PUSHPULL);// d
	GPIO_Init(PORTA, 4 , OUTPUT_PUSHPULL);// e
	GPIO_Init(PORTA, 5 , OUTPUT_PUSHPULL);// f
	GPIO_Init(PORTA, 6 , OUTPUT_PUSHPULL);// g
}


/**************
 * Display digit (0 to 9) on 7 segment display
 *
 * Args:
 * 		digit -> unsigned char
 * Return: None
 */
void SevenSegment_WriteDigit(unsigned char digit)
{
	char Int_value = SevenSegment_ConvertToInt(digit);
	if(SevenSegment_IsDesiredValueAlreadyDisplayed(Int_value))
	{
		return ;
	}

	switch(Int_value)
	{

		case 0:
		{
			GPIO_WritePin(PORTA, 0, 1);// a
			GPIO_WritePin(PORTA, 1, 1);// b
			GPIO_WritePin(PORTA, 2, 1);// c
			GPIO_WritePin(PORTA, 3, 1);// d
			GPIO_WritePin(PORTA, 4, 1);// e
			GPIO_WritePin(PORTA, 5, 1);// f
			GPIO_WritePin(PORTA, 6, 0);// g

			SevenSegment_CurrentDisplayedNumber = 0;
			break;
		}
		case 1:
		{
			GPIO_WritePin(PORTA, 0, 0);// a
			GPIO_WritePin(PORTA, 1, 1);// b
			GPIO_WritePin(PORTA, 2, 1);// c
			GPIO_WritePin(PORTA, 3, 0);// d
			GPIO_WritePin(PORTA, 4, 0);// e
			GPIO_WritePin(PORTA, 5, 0);// f
			GPIO_WritePin(PORTA, 6, 0);// g

			SevenSegment_CurrentDisplayedNumber = 1;
			break;
		}
		case 2:
		{
			GPIO_WritePin(PORTA, 0, 1);// a
			GPIO_WritePin(PORTA, 1, 1);// b
			GPIO_WritePin(PORTA, 2, 0);// c
			GPIO_WritePin(PORTA, 3, 1);// d
			GPIO_WritePin(PORTA, 4, 1);// e
			GPIO_WritePin(PORTA, 5, 0);// f
			GPIO_WritePin(PORTA, 6, 1);// g

			SevenSegment_CurrentDisplayedNumber = 2;
			break;
		}
		case 3:
		case '3':
		{
			GPIO_WritePin(PORTA, 0, 1);// a
			GPIO_WritePin(PORTA, 1, 1);// b
			GPIO_WritePin(PORTA, 2, 1);// c
			GPIO_WritePin(PORTA, 3, 1);// d
			GPIO_WritePin(PORTA, 4, 0);// e
			GPIO_WritePin(PORTA, 5, 0);// f
			GPIO_WritePin(PORTA, 6, 1);// g

			SevenSegment_CurrentDisplayedNumber = 3;
			break;
		}

		case 4:
		{
			GPIO_WritePin(PORTA, 0, 0);// a
			GPIO_WritePin(PORTA, 1, 1);// b
			GPIO_WritePin(PORTA, 2, 1);// c
			GPIO_WritePin(PORTA, 3, 0);// d
			GPIO_WritePin(PORTA, 4, 0);// e
			GPIO_WritePin(PORTA, 5, 1);// f
			GPIO_WritePin(PORTA, 6, 1);// g

			SevenSegment_CurrentDisplayedNumber = 4;
			break;
		}
		case 5:
		{
			GPIO_WritePin(PORTA, 0, 1);// a
			GPIO_WritePin(PORTA, 1, 0);// b
			GPIO_WritePin(PORTA, 2, 1);// c
			GPIO_WritePin(PORTA, 3, 1);// d
			GPIO_WritePin(PORTA, 4, 0);// e
			GPIO_WritePin(PORTA, 5, 1);// f
			GPIO_WritePin(PORTA, 6, 1);// g

			SevenSegment_CurrentDisplayedNumber = 5;
			break;
		}
		case 6:
		{
			GPIO_WritePin(PORTA, 0, 1);// a
			GPIO_WritePin(PORTA, 1, 0);// b
			GPIO_WritePin(PORTA, 2, 1);// c
			GPIO_WritePin(PORTA, 3, 1);// d
			GPIO_WritePin(PORTA, 4, 1);// e
			GPIO_WritePin(PORTA, 5, 1);// f
			GPIO_WritePin(PORTA, 6, 1);// g

			SevenSegment_CurrentDisplayedNumber = 6;
			break;
		}
		case 7:
		{
			GPIO_WritePin(PORTA, 0, 1);// a
			GPIO_WritePin(PORTA, 1, 1);// b
			GPIO_WritePin(PORTA, 2, 1);// c
			GPIO_WritePin(PORTA, 3, 0);// d
			GPIO_WritePin(PORTA, 4, 0);// e
			GPIO_WritePin(PORTA, 5, 0);// f
			GPIO_WritePin(PORTA, 6, 0);// g

			SevenSegment_CurrentDisplayedNumber = 7;
			break;
		}
		case 8:
		{
			GPIO_WritePin(PORTA, 0, 1);// a
			GPIO_WritePin(PORTA, 1, 1);// b
			GPIO_WritePin(PORTA, 2, 1);// c
			GPIO_WritePin(PORTA, 3, 1);// d
			GPIO_WritePin(PORTA, 4, 1);// e
			GPIO_WritePin(PORTA, 5, 1);// f
			GPIO_WritePin(PORTA, 6, 1);// g

			SevenSegment_CurrentDisplayedNumber = 8;
			break;
		}
		case 9:
		{
			GPIO_WritePin(PORTA, 0, 1);// a
			GPIO_WritePin(PORTA, 1, 1);// b
			GPIO_WritePin(PORTA, 2, 1);// c
			GPIO_WritePin(PORTA, 3, 1);// d
			GPIO_WritePin(PORTA, 4, 0);// e
			GPIO_WritePin(PORTA, 5, 1);// f
			GPIO_WritePin(PORTA, 6, 1);// g

			SevenSegment_CurrentDisplayedNumber = 9;
			break;
		}
		default:
			//SevenSegment_CurrentDisplayedNumber = NO_DATA_DISPLAYED;
			break;
	}
}


char SevenSegment_IsDesiredValueAlreadyDisplayed(char desired_value)
{
	return (desired_value == SevenSegment_CurrentDisplayedNumber);
}



char SevenSegment_ConvertToInt(char digit)
{
	if(digit > 9) {
		return (digit - '0');
	}
	return digit;
}

