#include "SevenSegment.h"
#include "Keypad_interface.h"




void KeypadCallouts_KeyPressNotificaton(void);



void main(void)
{
	Keypad_Init();

	SevenSegment_Init();

	while(1)
	{
		Keypad_manage();
	}

}

void KeypadCallouts_KeyPressNotificaton(void)
{
	char key = Keypad_GetKey();

	SevenSegment_WriteDigit(key);

}


