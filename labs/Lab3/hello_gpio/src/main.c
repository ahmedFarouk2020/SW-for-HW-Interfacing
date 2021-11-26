#include "stm32f401cc_interface.h"

int main(void) {
	RCC_AHB1ENR &= (~(1<<0));
	RCC_AHB1ENR |= 1;

	// put pin0 in portA output mode
	GPIOA_MODER &= (~(0x3 <<0)); // clear first 2 bits
	GPIOA_MODER |= (1<<0);		 // set first bit as output

	// set first pin as output push-pull
	GPIOA_OTYPER &= (~(1 << 0)); // clear first bit

	while (1) {

		// led is off
		GPIOA_ODR &= (~(1 << 0));
		for (int i = 0; i < 1000000; i++){}

		// led is on
		GPIOA_ODR |= (1 << 0);
		for (int i = 0; i < 1000000; i++){}
	}
	return 0;
}
