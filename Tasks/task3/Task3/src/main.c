/***************************************
 * 				main.c
 * contains the application
 *
 * Author: Farouk
 *
 * Date: 3-12-2021
 *
 */

#include "GPIO_Interface.h"


void DebouncingDelay(void);

int main(void) {

	/* Enable clk for GPIOB */
	GPIO_RCC_Init(PORTB);

	/* Button_Init */
	GPIO_Init(PORTB,PIN3,INPUT_PULLUP);

	/* RGB_Init */
	GPIO_Init(PORTB,PIN5,OUTPUT_PUSHPULL);
	GPIO_Init(PORTB,PIN6,OUTPUT_PUSHPULL);
	GPIO_Init(PORTB,PIN7,OUTPUT_PUSHPULL);

		// Define system variables
	unsigned char stateOfButtonPin = 1;
	unsigned char previousStateOfButtonPin = 1;

	unsigned char ListOfColors[8] = {
			0, // Black
			1, // Red
			2, // Green
			3, // Green&Red
			4, // Blue
			5, // Red&Blue
			6, // Blue&Green
			7 // White
	};

	unsigned char i = 1;

	while (1)
	{
		/*
		 * 1.read first time (might be correct OR in bounce phase)
		 * 2.delay 7ms (max bounce period is 6.2 ms)
		 * 3.read second time(might be "in bounce phase or correct" OR correct)
		 *   we AND the 2 reading so that we can get the right state if
		 *   one of the 2 reading is correct
		 * -----------------------------------------------------
		 * worst case: read button after 14 ms from pressing
		 */
		stateOfButtonPin = GPIO_ReadPin(PORTB,PIN3);
		DebouncingDelay();
		stateOfButtonPin &= GPIO_ReadPin(PORTB,PIN3);



		// button is pressed
		if( (stateOfButtonPin==0) && (previousStateOfButtonPin==1) )
		{
			previousStateOfButtonPin = 0;

			// clear led pins
			GPIO_WritePin(PORTB,PIN5,0);
			GPIO_WritePin(PORTB,PIN6,0);
			GPIO_WritePin(PORTB,PIN7,0);


			// assign proper to leds' pins
			unsigned char Pin5Logic = (ListOfColors[i]&1);
			unsigned char Pin6Logic = (ListOfColors[i]&2)>>1;
			unsigned char Pin7Logic = (ListOfColors[i]&4)>>2;

			GPIO_WritePin(PORTB,5,Pin5Logic);
			GPIO_WritePin(PORTB,6,Pin6Logic);
			GPIO_WritePin(PORTB,7,Pin7Logic);


			i++;

			// to ensure i will not exceed 7
			i = i%8;
		}

		// button released
		else if (stateOfButtonPin==1)
		{
			previousStateOfButtonPin = 1;
		}

		else {}

	}
	return 0;
}



void DebouncingDelay(void)
{
	// delay for 7ms which is the max number of debounce period
	int i=7000;
	for(;i>0;i--);
}
