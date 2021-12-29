/*
 * SEVEN_SEGMENT.h
 *
 *  Created on: Nov 25, 2021
 *      Author: Farouk
 */

#ifndef INC_SEVEN_SEGMENT_H_
#define INC_SEVEN_SEGMENT_H_




/**************
 * Initialize pins that will be used to write on 7 segment
 *
 * Args: None
 * Return: None
 */
void SevenSegment_Init(void);



/**************
 * Display digit (0 to 9) on 7 segment display
 *
 * Args:
 * 		digit -> unsigned char
 * Return: None
 */
void SevenSegment_WriteDigit(unsigned char digit);

char SevenSegment_IsDesiredValueAlreadyDisplayed(char desired_value);

char SevenSegment_ConvertToInt(char digit);

#endif /* INC_SEVEN_SEGMENT_H_ */
