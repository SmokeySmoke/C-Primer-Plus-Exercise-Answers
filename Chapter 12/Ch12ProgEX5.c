/* Write a program that generates a list of 100 random
 * numbers in the range 1-10 in a sorted decreasing
 * order. (You can adapt the sorting algorithm from
 * Chapter 11, "Character Strings and String Functions",
 * to type int. In this case, just sort the numbers themselves
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TOP 100
void intsrt(int [], int);

int main(void)
{
	int rn[TOP];
	int i;

	srand((unsigned int) time(0));	// randomize seed
	puts("Original array contents:");
	for (i = 0; i < TOP; i++)
	{
		rn[i] = rand() % 10 + 1;
		printf("rn[%d] = %d\n", i, rn[i]);
	}	

	intsrt(rn, TOP);
	
	puts("\nArray after intsrt:");
	for (i = 0; i < TOP; i++)
		printf("rn[%d] = %d\n", i, rn[i]);

	return 0;

}

void intsrt(int rn[], int n)
{
	int * temp = (int *) malloc(sizeof (int));
	int top, seek;

	for (top = 0; top < n-1; top++)
		for (seek = top+1; seek < n; seek++)
			if (rn[top] < rn[seek])
			{
				*temp = rn[top];
				rn[top] = rn[seek];
				rn[seek] = *temp;
			}
	return;
}
