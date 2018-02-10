/* Write a function that returns the index of the largest value
 * stored in an array-of-double. Test the function in a simple
 * program.
 */
#include <stdio.h>
int largest(int [], int);

int main(void)
{
	int ar[] = {1,44,1024,2,6,26,72,2,6,501,2,76,1};

	printf("Index of largest value in array: %d\n",
			largest(ar, sizeof ar / sizeof ar[0]));

	return 0;
}

int largest(int arr[], int n)
{
	int i, largest, largestI;
	largest = largestI = 0;

	for (i =  0; i < n; i++)
		if (arr[i] > largest)
		{
			largest = arr[i];
			largestI = i;
		}

	return largestI;
}
