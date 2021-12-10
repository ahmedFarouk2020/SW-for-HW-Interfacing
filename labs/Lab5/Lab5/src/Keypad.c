/*
 * Keypad.c
 *
 * Created: 9/12/2021 9:28:11 PM
 *  Author: farouk
 */ 
 
 
 
 #include "GPIO_interface.h"

 #include "Keypad_interface.h"
 #include "Keypad_private.h"
 #include "Keypad_config.h"
 

	/* global variables */
char Keypad_PressedButton = 127;
char Keypad_state = RELEASED;

	/* EXTERNAL LINKAGE (main.c) */
extern void KeypadCallouts_KeyPressNotificaton(void);


 /*****
 * Description: Initialization Gpio pin directions and values
 
 * Parameters: none (configurations of pins in the config.h file)
 
 * Return: none
 
 * EX: Keypad_Init();
 */
void Keypad_Init(void)
{
	GPIO_EnableClk(KEYPAD_PORT);
	// set direction of row pins (output)
	GPIO_Init(ROW0, OUTPUT_PUSHPULL);
	GPIO_Init(ROW1, OUTPUT_PUSHPULL);
	GPIO_Init(ROW2, OUTPUT_PUSHPULL);
	GPIO_Init(ROW3, OUTPUT_PUSHPULL);

	// set direction of col pins (input with pullup enabled)
	GPIO_Init(COL0, INPUT_PULLUP);
	GPIO_Init(COL1, INPUT_PULLUP);
	GPIO_Init(COL2, INPUT_PULLUP);
	GPIO_Init(COL3, INPUT_PULLUP);

	// set value to col pins (High) -- NO Effect -- output driver is disabled
	GPIO_WritePin(COL0,1);
	GPIO_WritePin(COL1,1);
	GPIO_WritePin(COL2,1);
	GPIO_WritePin(COL3,1);
	
	// set value to row pins (High)
	GPIO_WritePin(ROW0,1);
	GPIO_WritePin(ROW1,1);
	GPIO_WritePin(ROW2,1);
	GPIO_WritePin(ROW3,1);

}





/*****
 * Description: take index of pressed button and return button char(as written on the button)
 
 * Parameters: uint8 row index, uint8 colums index in the array
 
 * Return: the value of pressed button as showed on it (char)
 
 * EX: Keypad_GetPressedButton(0,1) -> '1'
 
 * NOTE: This Function can't be called by other module
 */
static char Keypad_GetPressedButton(unsigned char row, unsigned char col)
{
	if(row<NUM_OF_ROW && col<NUM_OF_COL)
	{
		return buttons[row][col];
	}
	return INVALID_INDEX; // ERROR
}


/*****
 * Description: take row index and assign zero to this index and one to the others 
 
 * Parameters: uint8 row index
 
 * Return: none
 
 * EX: Keypad_AssignRowValue(3)
 
 * NOTE: This Function can't be called by the other modules
 */
static void Keypad_AssignRowValue(unsigned char rowID)
{
	switch (rowID)
	{
		case 0:
		// write the value 1110 to the rows
			GPIO_WritePin(ROW0,0);
			GPIO_WritePin(ROW1,1);
			GPIO_WritePin(ROW2,1);
			GPIO_WritePin(ROW3,1);
			break;
		case 1:
			// write the value 1101 to the rows
			GPIO_WritePin(ROW0,1);
			GPIO_WritePin(ROW1,0);
			GPIO_WritePin(ROW2,1);
			GPIO_WritePin(ROW3,1);
			break;
		case 2:
			// write the value 1011 to the rows
			GPIO_WritePin(ROW0,1);
			GPIO_WritePin(ROW1,1);
			GPIO_WritePin(ROW2,0);
			GPIO_WritePin(ROW3,1);
			break;
		case 3:
			// write the value 0111 to the rows
			GPIO_WritePin(ROW0,1);
			GPIO_WritePin(ROW1,1);
			GPIO_WritePin(ROW2,1);
			GPIO_WritePin(ROW3,0);
			break;
	}
}



/*****
 * Description: take column index (0,1,2) and return column state(High, Low) 
 *
 * Parameters: uint8 colums index
 *
 * Return: uint8 column state(High, Low) 
 *
 * EX: Keypad_ReadColPin(0) -> 1
 *
 * NOTE: This Function can't be called by the other modules
 */
static char Keypad_ReadColPin(unsigned char colID)
{
	unsigned char result = 0;
	switch (colID)
	{
		case 0:
			result = GPIO_ReadPin(COL0);
			break;
		case 1:
			result = GPIO_ReadPin(COL1);
			break;
		case 2:
			result = GPIO_ReadPin(COL2);
			break;
		case 3:
			result = GPIO_ReadPin(COL3);
			break;
	}
	return result;
}

/********************************************************************/
/*****
 * Description: detect the pressed button and return its character ex: '1', '2', ...
 *
 * Parameters: none
 *
 * Return: The pressed button (char)
 *
 * EX: Keypad_ReadPressedButton();  -> '2'
 */

void Keypad_manage(void)
{

	// pressed button indecies  row, col
	char button_rowID = -1;
	char button_colID = -1;

	/* loop on row and each time assign zero to a row */
	for(unsigned char count_rawId=0; count_rawId<NUM_OF_ROW; count_rawId++)
	{
		// put value on raw pins
		Keypad_AssignRowValue(count_rawId);

		/* loop on cols to catch the zero value of them (i.e. where is the pressed button) */
		for(unsigned char count_colId=0; count_colId<NUM_OF_COL; count_colId++)
		{
			// get the col state (High , low)
			unsigned char col_state = Keypad_ReadColPin(count_colId);

			// if low?
			if (col_state == 0) // this is a problem
			{
				Keypad_state = PRESSED;

				// stuck here untill button released
				while(Keypad_ReadColPin(count_colId)==0);
				
				// button is detected
				button_rowID = count_rawId;
				button_colID = count_colId;

				// get key and save it in a buffer
				Keypad_PressedButton = Keypad_GetPressedButton(button_rowID, button_colID);

				// notify application
				KeypadCallouts_KeyPressNotificaton();
			}
		}
	}
}




char Keypad_GetKey(void)
{
	if(Keypad_state == PRESSED)
	{
		Keypad_state = RELEASED;
		return Keypad_PressedButton;
	}
	else
	{
		return NO_DATA;
	}
}

