/*
 * EXTI.c
 *
 *  Created on: Dec 23, 2021
 *      Author: Farouk
 */

#include "GPIO_Interface.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"


void EXTI_enableClk(void)
{
	// enable clk (SYSCFG_ENB)
	RCC_APB2ENR |= 1<<14;
}

void EXTI_EnableLine(unsigned char lineId)
{
	EXTI_IMR |= (1<<lineId);
}

void EXTI_trigger(unsigned char trigger_edge, unsigned char lineId)
{
	// set trigger mode
	EXTI_RTSR |= ((trigger_edge>>4) <<lineId);
	EXTI_FTSR |= (trigger_edge <<lineId);
}

void EXTI_enableNVIC(unsigned char lineId)
{
	NVIC_ISER0 = (1<< lineId);
}


void EXTI_disableNVIC(unsigned char lineId)
{
	// set line
	NVIC_ISER0 = ~(1<< lineId);
}



void EXTI_init(unsigned char portId, unsigned char pinId)
{
	// enable RCC and EXTI
	GPIO_EnableClk(portId);



	// enable EXI peripheral
	EXTI_enableClk();

	// config DIO pin
	GPIO_Init(portId,pinId,INPUT_PULLUP);

	// enable EXTI on pin
	EXTI_EnableLine(0);

	// config trigger edge
	EXTI_trigger(FALLING_EDGE, 0);

	// enable NVIC mask
	EXTI_enableNVIC(6);
}


void EXTI_clearFlag(unsigned char lineId)
{
	EXTI_PR = (1<< lineId);
}


void EXTI_setCallBack(void(*ptr_function)(void))
{
	 function_callback = ptr_function;
}

void EXTI0_IRQHandler(void)
{
	if(function_callback != NULL)
	{
		function_callback();
	}
}
