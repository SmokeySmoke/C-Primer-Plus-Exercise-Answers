/* Write a function that reverses the contents of an array of double 
 * and test it in a simple program.
 */
#include <stdio.h>
void revArr(double [], int);

int main(void)
{
	double ar[] = {1,2,3,4,5,6,7,8,9};
	int i, arlen = sizeof ar / sizeof ar[0];

	for (i = 0; i < arlen; i++)
		printf("ar[%d] = %.1lf\n", i, ar[i]);

	revArr(ar, arlen);
	printf("\nReversed: \n");
	for (i = 0; i < arlen; i++)
		printf("ar[%d] = %.1lf\n", i, ar[i]);

	return 0;
}

void revArr(double arr[], int arrlen)
{
	double temp, *start, *end;
	start = arr;
	end = &arr[arrlen-1];

	for (int i = arrlen/2; i > 0; i--, end--, start++)
	{
		temp = *start;
		*start = *end;
		*end = temp;
	}

	return;
}
