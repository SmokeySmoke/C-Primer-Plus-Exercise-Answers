/* Write and test a function called larger_of() that replaces
 * the contents of two double variables with the maximum of
 * the two values. For example, larger_of(x,y) would reset 
 * both x and y to the larger of the two.
 */
#include <stdio.h>
void larger_of(double *, double *);

int main(void)
{
	double x = 23, y = 18.4;

	larger_of(&x, &y);
	printf("x = %.1lf\ty = %.1lf\n", x, y);

	return 0;
}

void larger_of(double * u, double * v)
{
	double larger = (*u > *v) ? *u : *v;
	*u = *v = larger;

	return;
}
