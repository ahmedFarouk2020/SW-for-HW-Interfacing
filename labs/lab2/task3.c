#include<stdio.h>

void main (void)
{
	// construct UI
	printf("Enter the length of fobnocci series: ");
	
	// get series length from user
	int series_length = 0;
	scanf("%d", &series_length);
	
	// print the result
	printf("Series: ");
	printf("0 1 ");

	int previous_element = 0;
	int last_element = 1;

	for(;series_length;series_length--)
	{
		int copyOfLastElement = last_element;
		last_element += previous_element;
		previous_element = copyOfLastElement;
		
		
		printf("%d ", last_element);
	}
	printf("\n");
}
