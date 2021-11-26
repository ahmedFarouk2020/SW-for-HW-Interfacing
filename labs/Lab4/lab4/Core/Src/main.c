#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

#include "SEVEN_SEGMENT.h"

int main(void) {

	SEVEN_SEGMENT_Init();
  while (1) {

	  static unsigned char digit = 0;

	  SEVEN_SEGMENT_Write_Digit(digit);

	  //delay
	  for (int i = 0; i < 1000000; i++){}

	  digit++;
	  // keep it inside the boundary (0 to 9)
	  digit = digit % 10;

  }
  return 0;
}
