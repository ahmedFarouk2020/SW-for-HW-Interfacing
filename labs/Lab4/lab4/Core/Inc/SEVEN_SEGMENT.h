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
void SEVEN_SEGMENT_Init(void);



/**************
 * Display digit (0 to 9) on 7 segment display
 *
 * Args:
 * 		digit -> unsigned char
 * Return: None
 */
void SEVEN_SEGMENT_Write_Digit(unsigned char digit);

#endif /* INC_SEVEN_SEGMENT_H_ */
