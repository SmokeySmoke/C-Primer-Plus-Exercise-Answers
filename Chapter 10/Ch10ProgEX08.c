/* Use a copy function from Programming exercise 2 to copy the third
 * through fifth elements of a seven-element array into a three-element
 * array. The function itself need not be altered; just choose the right
 * actual arguments. (The actual arguments need not be an array name and
 * array size. They only have to be the address of an array element and
 * a number of elements to be processed.
 */

#include <stdio.h>
#define SRCSIZE 7
#define TRGSIZE 3
void copy_arr(double [], const double [], int);

int main(void)
{
	double ar[SRCSIZE] = {1,2,3,4,5,6,7};
	double target[TRGSIZE];
	int i;

	for (i = 0; i < SRCSIZE; i++)
		printf("ar[%d] = %.0lf\n", i, ar[i]);
	
	copy_arr(target, &ar[2], TRGSIZE);

	for (i = 0; i < TRGSIZE; i++)
		printf("target[%d] = %.0lf\n", i, target[i]);

	return 0;
}

void copy_arr(double ar[], const double src[], int n)
{
	while (n-- >= 0)
		ar[n] = src[n];

	return;
}
