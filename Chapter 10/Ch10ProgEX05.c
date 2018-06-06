/* Write a function that returns the difference between the
 * largest and smallest elements of an array-of-double. Test
 * the function in a simple program.
 */
#include <stdio.h>
double arDif(double [], int);

int main(void)
{
	double ar[] = {13.4,2.4,5.2,3.7,1.1,7.6};

	printf("Difference between smallest and largest"
	       "elements in array: %.2lf\n", arDif(ar, sizeof ar / sizeof ar[0]));

	return 0;
}

double arDif(double arr[], int arrLen)
{
	int i;
        double * largest, * smallest;
	smallest = &arr[0];
	largest = &arr[arrLen-1];

	for (i = 0; i < arrLen; i++)
	{
		if (arr[i] > *largest)
			largest = &arr[i];
		if (arr[i] < *smallest)
			smallest = &arr[i];
	}

	return *largest - *smallest;
}
