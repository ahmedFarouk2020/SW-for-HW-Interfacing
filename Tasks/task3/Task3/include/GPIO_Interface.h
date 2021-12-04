/***************************************
 * 				GPIO_Interface.h
 * contains interface functions for this module (APIs)
 *
 * Author: Farouk
 *
 * Date: 3-12-2021
 *
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

// Ports
#define PORTA	0
#define PORTB	1

// PINs
#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

//write result
#define OK  0
#define NOK 1

/************************ MODES ***************************************
 * 																	  *
 * First digit for operation mode (INPUT-OUTPUT-...)				  *
 * 																	  *
 * Second digit for mode of operation mode (Push pull-pull down-..)	  *
 **********************************************************************
 */

#define INPUT_NOPULL 				0x00
#define INPUT_PULLUP 				0x01
#define INPUT_PULLDOWN 				0x02

#define OUTPUT_PUSHPULL 				0x10
#define OUTPUT_OPENDRAIN 				0x11

#define ALTERNATE_FUNCTION 	2
#define ANALOG 				3



//----------- APIs ----------
void GPIO_RCC_Init(unsigned char port);
void GPIO_Init( unsigned char Port, unsigned char PIN_NO, unsigned char PIN_Dir);
void GPIO_WritePin(unsigned char Port, unsigned char PIN_NO, unsigned char Data);
unsigned char GPIO_ReadPin( char Port, unsigned char PIN_NO);






void RGB_Init(void);

#endif /* INC_GPIO_H_ */
