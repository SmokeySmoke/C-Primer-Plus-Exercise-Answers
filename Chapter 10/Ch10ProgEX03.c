/* Write a function that returns the largest value stored
 * in an array-of-int. Test the function in a simple program.
 */
#include <stdio.h>
int largest(int [], int);

int main(void)
{
	int ar[] = {1,44,2,6,26,72,2,6};

	printf("Largest value in array: %d\n", largest(ar, sizeof ar / sizeof ar[0]));

	return 0;
}

int largest(int arr[], int n)
{
	int largest, i;

	for (i = 0; i < n; i++)
		if (arr[i] > largest)
			largest = arr[i];

	return largest;
}
