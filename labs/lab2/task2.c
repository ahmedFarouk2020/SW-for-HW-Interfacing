#include<stdio.h>

void main (void)
{
	int col=0, row=0;

	int left_edge = 4;
	int right_edge = 4;

	// upper part
	for(row;row<5;row++)
	{
		for(col=0;col<9;col++)
		{			
		
			if((col>=left_edge) && (col<=right_edge))
			{
				printf("*");
			}
			else
			{
				printf(" ");			
			}
			
		}
		printf("\n");

		// update edges
		left_edge--;
		right_edge++;
		// reset col value
		col=0;
	
	}

	
	// lower part

	// reset row and col values
	row = 0;
	col = 0;

	// init values for edges to strat from
	left_edge = 0;
	right_edge = 8;

	for(row;row<4;row++)
	{
		
		// update edges
		left_edge++;
		right_edge--;

		for(col=0;col<9;col++)
		{			
		
			if((col>=left_edge) && (col<=right_edge))
			{
				printf("*");
			}
			else
			{
				printf(" ");			
			}
			
		}
		printf("\n");

		// reset col value

		col=0;
	
	}

}
