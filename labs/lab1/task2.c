#include<stdio.h>

void main (void)
{
	
	printf("Enter the first number: ");
	float first_number = 0.0;
	scanf("%f", &first_number);
	
	printf("Enter the second number: ");
	float second_number = 0.0;
	scanf("%f", &second_number);

	printf("Enter the third number: ");
	float third_number = 0.0;
	scanf("%f", &third_number);

	// logic
	// calculate the summation of the numbers
	float sum = 0.0;
	sum = first_number + second_number + third_number;

	// calculate the average of the numbers
	float average = 0.0;
	average = (first_number + second_number + third_number)/3;

	// calculate the product of the numbers
	float product = 0.0;
	product = first_number * second_number * third_number;

	// get the largest value
	float max = 0.0;
	max = first_number>second_number ? first_number : second_number ;
	max = third_number > max ? third_number : max;

	// get the smallest value
	float min = 0.0;
	min = first_number<second_number ? first_number : second_number ;
	min = third_number < min ? third_number : min ;

	// print the result
	printf("Max number: %g \n" ,max);
	printf("Min number: %g \n", min);
	printf("Sum of numbers: %g \n", sum);
	printf("Average of number: %g \n", average);
	printf("Product of numbers: %g \n", product);

	
	

}
