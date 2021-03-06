/* Devise a function called min(x, y) that returns
 * the smaller of two double values. Test the function
 * with a simple driver
 */
#include <stdio.h>
double min(double, double);

int main(void)
{
	double a, b;

	printf("Enter two double values: ");
	scanf("%lf %lf", &a, &b);
	printf("Largest number: %.1lf\n", min(a, b));

	return 0;
}

double min(double x, double y)
{
	return (x < y) ? x : y;
}
