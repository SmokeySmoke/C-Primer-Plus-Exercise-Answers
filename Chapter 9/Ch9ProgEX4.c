/* The harmonic mean of two numbers is obtained by taking the
 * inverses of the two numbers, averaging them, and taking
 * the inverse of the result. Write a function that takes
 * two double arguments and returns the harmonic mean of the
 * two numbers.
 */
#include <stdio.h>
double harmony(double, double);

int main(void)
{
	printf("%.2lf\n", harmony(13.0, 23.0)); 

	return 0;
}

double harmony(double x, double y)
{
	double mean;

	x -= 2 * x;
	y -= 2 * y;
	mean = (x + y) / 2;
	mean -= 2 * mean;

	return mean;
}	
