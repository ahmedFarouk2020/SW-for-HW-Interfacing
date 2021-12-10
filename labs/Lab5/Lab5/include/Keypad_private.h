/*
 * Keypad_private.h
 *
 * Created: 9/12/2021 9:28:11 PM
 *  Author: farouk
 */ 


#ifndef KEYPAD_PRIVATE_H_
#define KEYPAD_PRIVATE_H_



#define RELEASED 	1
#define PRESSED 	0


// Private functions Declaration

/*****
 * Description: take index of pressed button and return button char(as written on the button) 
 * Parameters: unsigned char row index, unsigned char colums index in the array
 * Return: the value of pressed button as showed on it (char)
 * EX: Keypad_GetPressedButton(0,1) -> '1'
 * NOTE: This Function can't be called by other module
 */
static char Keypad_GetPressedButton(unsigned char row, unsigned char col);

static char Keypad_ReadColPin(unsigned char colID);

static void Keypad_AssignRowValue(unsigned char rowID);

#endif 
