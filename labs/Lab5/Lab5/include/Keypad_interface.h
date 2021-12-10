/*
 * Keypad_interface.h
 *
 * Created: 9/12/2021 9:28:11 PM
 *  Author: farouk
 */ 


#ifndef Keypad_INTERFACE_H_
#define Keypad_INTERFACE_H_



//--------- Functions Definitions

/*****
 * Description: Initialization Gpio pin directions and values
 * Parameters: none (configurations of pins in the config.h file)
 * Return: none
 * EX: Keypad_Init();
 */
void Keypad_Init(void);

/*****
 * Description: detect the pressed button and return its character ex: '1', '2', ...
 * Parameters: none
 * Return: The pressed button (char) 
 * EX: Keypad_ReadPressedButton();  -> '2'
 */
char Keypad_ReadPressedButton(void);


void Keypad_manage(void);
void KeypadCallouts_KeyPressNotificaton(void);
char Keypad_GetKey(void);


#endif 
