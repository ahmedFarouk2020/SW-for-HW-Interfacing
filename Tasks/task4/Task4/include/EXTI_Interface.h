/*
 * EXTI_Interface.h
 *
 *  Created on: Dec 23, 2021
 *      Author: Farouk
 */


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


	/* EXTI */
#define EXTI0	6
#define EXTI1	7

	/* Trigger modes */
#define FALLING_EDGE		0x01
#define RISSING_EDGE		0x10
#define ON_CHANGE			0x11

#define LINE0	0
#define LINE1	1
#define LINE2	2
#define LINE3	3
#define LINE4	4
#define LINE5	5
#define LINE6	6
#define LINE7	7
#define LINE8	8
#define LINE9	9

	/* function declarations */
void EXTI_enableClk(void);
void EXTI_EnableLine(unsigned char lineId);
void EXTI_DisableLine(unsigned char lineId);
void EXTI_trigger(unsigned char trigger_edge, unsigned char lineId);
void EXTI_init(unsigned char portId, unsigned char pinId, unsigned char EXTI);
void EXTI_disableNVIC(unsigned char lineId);
void EXTI_enableNVIC(unsigned char lineId);
void EXTI_clearFlag(unsigned char lineId);
void EXTI_setCallBack0(void(*ptr_function)(void));
void EXTI_setCallBack1(void(*ptr_function)(void));
void EXTI_DisableAllLines(void);
void EXTI_EnableAllLines(void);

#endif
