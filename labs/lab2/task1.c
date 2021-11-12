#include<stdio.h>


void main (void)
{
	// construct UI
	printf("Enter a number (0:255): ");

	// fetch the input
	unsigned char input_number = 0;
	scanf("%hhu", &input_number); // bug if used "%c"

	printf("Enter the number of rotations(0:7): ");
	
	// fetch the number of rotations
	int number_of_rotations = 0;
	scanf("%d", &number_of_rotations);

	printf("Enter the direction of rotation[0:left , 1:right]: ");
	
	// fetch the direction of rotation
	int direction_of_rotation = 0;
	scanf("%d", &direction_of_rotation);

	// logic
	int final_result = 0;

	switch(direction_of_rotation)
	{
		case 0: // rotate left
		{
			unsigned char dropped_bits = 0;
			unsigned char shifted_number = 0;
			
						
			shifted_number = (input_number << number_of_rotations);
			dropped_bits = (input_number >> (8-number_of_rotations) );
			final_result = shifted_number | dropped_bits;

			break;
		}
		case 1: // rotate right
		{
			unsigned char dropped_bits = 0;
			unsigned char shifted_number = 0;
			
			shifted_number = (input_number >> number_of_rotations);
			dropped_bits = (input_number << (8-number_of_rotations) );
			final_result = shifted_number | dropped_bits;
			break;	
		}
	}

	// print results
	printf("The number in hex: %x\n", input_number);
	printf("The rotated number is: %x\n", final_result);
	printf("The rotated number is: %d\n", final_result);
		

}
