#include<stdio.h>

void main(void)
{
	printf("Enter the elapsed time: ");
	int time_elapsed = 0;
	scanf("%d", &time_elapsed);

	// logic
	// get hours
	int hours = 0;
	hours = time_elapsed/(60*60);
	
	// get minutes
	int minutes = 0;	
	minutes = (time_elapsed-hours*60*60)/60;

	// get seconds
	int seconds = 0;
	seconds = time_elapsed - ((hours*60*60)+(minutes*60));

	// print the result (time --> Hours:minutes:seconds)
	printf("The Elaspsed Time is %d:%d:%d \n", hours, minutes, seconds);

}
