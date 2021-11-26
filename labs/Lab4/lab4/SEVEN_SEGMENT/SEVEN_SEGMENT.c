/*
 * SEVEN_SEGMENT.c
 *
 *  Created on: Nov 25, 2021
 *      Author: Farouk
 */


#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

#include "GPIO.h"
#include "SEVEN_SEGMENT.h"


/**************
 * Initialize pins that will be used to write on 7 segment
 *
 * Args: None
 * Return: None
 */
void SEVEN_SEGMENT_Init(void)
{
	GPIO_Init('A', 0 , OUTPUT, PUSH_PULL);// a
	GPIO_Init('A', 1 , OUTPUT, PUSH_PULL);// b
	GPIO_Init('A', 2 , OUTPUT, PUSH_PULL);// c
	GPIO_Init('A', 3 , OUTPUT, PUSH_PULL);// d
	GPIO_Init('A', 4 , OUTPUT, PUSH_PULL);// e
	GPIO_Init('A', 5 , OUTPUT, PUSH_PULL);// f
	GPIO_Init('A', 6 , OUTPUT, PUSH_PULL);// g
}


/**************
 * Display digit (0 to 9) on 7 segment display
 *
 * Args:
 * 		digit -> unsigned char
 * Return: None
 */
void SEVEN_SEGMENT_Write_Digit(unsigned char digit)
{
	switch(digit)
	{
		case 0:
		{
			GPIO_WritePin('A', 0, 1);// a
			GPIO_WritePin('A', 1, 1);// b
			GPIO_WritePin('A', 2, 1);// c
			GPIO_WritePin('A', 3, 1);// d
			GPIO_WritePin('A', 4, 1);// e
			GPIO_WritePin('A', 5, 1);// f
			GPIO_WritePin('A', 6, 0);// g
			break;
		}
		case 1:
		{
			GPIO_WritePin('A', 0, 0);// a
			GPIO_WritePin('A', 1, 1);// b
			GPIO_WritePin('A', 2, 1);// c
			GPIO_WritePin('A', 3, 0);// d
			GPIO_WritePin('A', 4, 0);// e
			GPIO_WritePin('A', 5, 0);// f
			GPIO_WritePin('A', 6, 0);// g
			break;
		}
		case 2:
		{
			GPIO_WritePin('A', 0, 1);// a
			GPIO_WritePin('A', 1, 1);// b
			GPIO_WritePin('A', 2, 0);// c
			GPIO_WritePin('A', 3, 1);// d
			GPIO_WritePin('A', 4, 1);// e
			GPIO_WritePin('A', 5, 0);// f
			GPIO_WritePin('A', 6, 1);// g
			break;
		}
		case 3:
		{
			GPIO_WritePin('A', 0, 1);// a
			GPIO_WritePin('A', 1, 1);// b
			GPIO_WritePin('A', 2, 1);// c
			GPIO_WritePin('A', 3, 1);// d
			GPIO_WritePin('A', 4, 0);// e
			GPIO_WritePin('A', 5, 0);// f
			GPIO_WritePin('A', 6, 1);// g
			break;
		}

		case 4:
		{
			GPIO_WritePin('A', 0, 0);// a
			GPIO_WritePin('A', 1, 1);// b
			GPIO_WritePin('A', 2, 1);// c
			GPIO_WritePin('A', 3, 0);// d
			GPIO_WritePin('A', 4, 0);// e
			GPIO_WritePin('A', 5, 1);// f
			GPIO_WritePin('A', 6, 1);// g
			break;
		}
		case 5:
		{
			GPIO_WritePin('A', 0, 1);// a
			GPIO_WritePin('A', 1, 0);// b
			GPIO_WritePin('A', 2, 1);// c
			GPIO_WritePin('A', 3, 1);// d
			GPIO_WritePin('A', 4, 0);// e
			GPIO_WritePin('A', 5, 1);// f
			GPIO_WritePin('A', 6, 1);// g
			break;
		}
		case 6:
		{
			GPIO_WritePin('A', 0, 1);// a
			GPIO_WritePin('A', 1, 0);// b
			GPIO_WritePin('A', 2, 1);// c
			GPIO_WritePin('A', 3, 1);// d
			GPIO_WritePin('A', 4, 1);// e
			GPIO_WritePin('A', 5, 1);// f
			GPIO_WritePin('A', 6, 1);// g
			break;
		}
		case 7:
		{
			GPIO_WritePin('A', 0, 1);// a
			GPIO_WritePin('A', 1, 1);// b
			GPIO_WritePin('A', 2, 1);// c
			GPIO_WritePin('A', 3, 0);// d
			GPIO_WritePin('A', 4, 0);// e
			GPIO_WritePin('A', 5, 0);// f
			GPIO_WritePin('A', 6, 0);// g
			break;
		}
		case 8:
		{
			GPIO_WritePin('A', 0, 1);// a
			GPIO_WritePin('A', 1, 1);// b
			GPIO_WritePin('A', 2, 1);// c
			GPIO_WritePin('A', 3, 1);// d
			GPIO_WritePin('A', 4, 1);// e
			GPIO_WritePin('A', 5, 1);// f
			GPIO_WritePin('A', 6, 1);// g
			break;
		}
		case 9:
		{
			GPIO_WritePin('A', 0, 1);// a
			GPIO_WritePin('A', 1, 1);// b
			GPIO_WritePin('A', 2, 1);// c
			GPIO_WritePin('A', 3, 1);// d
			GPIO_WritePin('A', 4, 0);// e
			GPIO_WritePin('A', 5, 1);// f
			GPIO_WritePin('A', 6, 1);// g
			break;
		}
	}
}








