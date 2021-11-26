#include<stdio.h>

void main (void)
{
	printf("Enter Initial velocity: ");
	float init_velocity = 0.0;
	scanf("%f", &init_velocity);

	printf("Enter time: ");
	float time = 0.0;
	scanf("%f", &time);
	
	printf("Enter acceleration: ");
	float acceleration = 0.0;
	scanf("%f", &acceleration);


	// calculate final velocity
	float final_velocity = 0.0;
	final_velocity = init_velocity + acceleration*time;
	
	// calculate the distance
	float distance = 0.0;
	distance = init_velocity*time + 0.5*acceleration*(time*time);

	// print the result
	printf("Final velocity: %g\n", final_velocity);
	printf("Distance: %g\n", distance);

	


}
