/* Write a program that initializes and array-of-double and then
 * copies the contents of the array into three other arrays. (All
 * four arrays should be declared in the main program.) To make the
 * first copy, use a function with array notation. To make the second
 * copy, use a function with pointer notation and pointer incrementing.
 * Have the first two functions take as arguments the name of the target
 * array, the name of the source array, and the number of elements to be
 * copied. Have the third function take as arguments the name of the target,
 * the name of the source, and a pointer to the element following the last
 * element of the source. That is, the function calls would look like this,
 * given the following declarations:
 *
 * 	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
 * 	double target1[5];
 * 	double target2[5];
 * 	double target3[5];
 * 	copy_arr(target1, source, 5);
 * 	copy_ptr(target2, source, 5);
 *
 * 	copy_ptrs(target3, source, source + 5);v
 */
#include <stdio.h>
#define SIZE 5
void copy_arr(double [], const double [], int);
void copy_ptr(double *, const double *, int);
void copy_ptrs(double [], const double [], double *);

int main(void)
{
	double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[SIZE];
	double target2[SIZE];
	double target3[SIZE];
	int i;

 	copy_arr(target1, source, SIZE);
	copy_ptr(target2, source, SIZE);
	copy_ptrs(target3, source, source + SIZE);
 	
	for (i = 0; i < SIZE; i++)
		printf("target1[%d] = %.1lf\n", i, target1[i]);
	putchar('\n');

	for (i = 0; i < SIZE; i++)
		printf("target2[%d] = %.1lf\n", i, target2[i]);
	putchar('\n');

	for (i = 0; i < SIZE; i++)
		printf("target3[%d] = %.1lf\n", i, target3[i]);

	return 0;
}

void copy_arr(double ar[], const double src[], int n)
{
	while (n-- >= 0)
		ar[n] = src[n];

	return;
}

void copy_ptr(double * ar, const double * src, int n)
{
	while (n-- >= 0)
		*(ar++) = *(src++);

	return;
}

void copy_ptrs(double ar[], const double src[], double * srcEnd)
{
	const double * ptr;

	for (ptr = src; ptr < srcEnd; ptr++)
		*(ar++) = *ptr;
	return;
}
