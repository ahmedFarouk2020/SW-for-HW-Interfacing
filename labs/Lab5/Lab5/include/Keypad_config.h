/*
 * Keypad_config.h
 *
 * Created: 9/12/2021 9:28:11 PM
 *  Author: farouk
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define NUM_OF_ROW   4
#define NUM_OF_COL   3


#define KEYPAD_PORT  PORTB

/* Pin Definition */
#define ROW0  PORTB, 4
#define ROW1  PORTB, 5
#define ROW2  PORTB, 6
#define ROW3  PORTB, 7

#define COL0  PORTB, 0
#define COL1  PORTB, 1
#define COL2  PORTB, 2
#define COL3  NO_PORT, 7

/***********************
char buttons[4][4] = {
	{'7', '8', '9','/'},
	{'4', '5', '6','*'},
	{'1', '2', '3','-'},
	{'C', '0', '=','+'}
};
**********************/

char buttons[4][3] = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
	{'#', '0', '*'}
};


	/* ERRORS */
#define INVALID_INDEX      -1
#define NO_PRESSED_BUTTON  -2
#define NO_DATA 	   127

#endif
