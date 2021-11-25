#include <stdio.h>

int Is_equals_one(int value)
{
    if (value == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Is_equals_zero(int value)
{
    if (value == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



double factorial(int number){
    double factorialOfTheNumber = 1;
	
    for (int i = 1; i <= number; ++i) {
        factorialOfTheNumber *= i;
    }
	
    return factorialOfTheNumber ;
}


double power(int base, int exponent ){
	
    if( Is_equals_one(base) )
    {
        return 1;
    }


    double result = 1;
	
    for (exponent; exponent>0; exponent--)
    {
		result = result * base;
    }
	
    return result;
}


double taylorExpansion(float x ,int iterations){
	
    if(Is_equals_zero(x))
    {
        return 1;
    }

    double expansion;
    
	for (int i = 0; i <= iterations; i++)
    {
        expansion += (power(x,i))/factorial(i);
    }
	
    return expansion;
}

int main() {
    float exponential_power;
    int numberOfIterations;
	
    printf("Enter exponential power: ");
    scanf("%f", &exponential_power);
	
    printf("Enter no of iterations: ");
    scanf("%d", &numberOfIterations);
	
    printf("%g\n", taylorExpansion(exponential_power, numberOfIterations));
	
    return 0;
}
