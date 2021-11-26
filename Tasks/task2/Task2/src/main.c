#include "stm32f401cc_interface.h"



/* Declarations of functions */
void RGB_Init(void);
void Button_Init(void);
unsigned char ReadButtonPin(void);
void DebouncingDelay(void);
//-----------------------------------


int main(void) {

	/* Enable clk for GPIOB */
	RCC_AHB1ENR |= (1<<1);

	Button_Init();

	RGB_Init();

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
		stateOfButtonPin = ReadButtonPin();
		DebouncingDelay();
		stateOfButtonPin &= ReadButtonPin();



		// button is pressed
		if( (stateOfButtonPin==0) && (previousStateOfButtonPin==1) )
		{

			previousStateOfButtonPin = 0;

			// clear led pins
			GPIOB_ODR &= ~( (1<<5)|(1<<6)|(1<<7) );

			// set led pins
			GPIOB_ODR |= (ListOfColors[i]<<5);
			i++;

			// to ensure i will not exceed 7
			i = i%8;
		}

		// button released
		else if (stateOfButtonPin==1)
		{
			previousStateOfButtonPin = 1;
		}

		else {

		}

	}
	return 0;
}



void DebouncingDelay(void)
{
	// delay for 7ms which is the max number of debounce period
	int i=7000;
	for(;i>0;i--);
}

unsigned char ReadButtonPin(void)
{
	// get the state of GPIOB pin3
	unsigned char pin_state = ( GPIOB_IDR & (1<<3) ) >>3;
	return pin_state;
}


void Button_Init(void)
{
	/*
	 * Button Pin settings [GPIOB, PIN3, input, internal pull-up enabled]
	 */

	// put pin3 in portB in input mode --> button
	GPIOB_MODER &= ~( 0<<(3*2) );
	// connect pin3 in portB to internal pull-up resistor -> button
	GPIOB_PUPDR |= (1<<(3*2) );
}


void RGB_Init(void)
{
	/*
	 * RGB LED Pins settings [output, push-pull]
	 */
		// GPIOB PINs(5,6,7) --> output mode
	GPIOB_MODER |= ( (1<<5*2) |(1<<6*2) | (1<<7*2) );

	// set GPIOB PINs(5,6,7) as output push-pull
	// the below line can be deleted --> default output type is push-pull :)
	GPIOB_OTYPER &= ~( (1<<5)|(1<<6)|(1<<7) );
}
