/* The harmonic mean of two numbers is obtained by taking the inverses of the
 * two numbers, averaging them, and taking the inverse of the result. Use a #define
 * directive to define a macro "function" that performs this operation. Write a simple
 * program that tests the macro.
 */
#include <stdio.h>
#define HARMEAN(X,Y) (1.0 / (((1/X) + (1/Y)) / 2))

int main(void)
{
	float x, y;

	printf("Enter two values to find Harmonic Mean: ");
	while (scanf("%f %f", &x, &y) == 2)
	{
		printf("Harmonic mean of %.2f and %.2f is %.2f\n", 
				x, y, HARMEAN(x,y));
		printf("Next two values: ");
	}
	puts("Bye!");

	return 0;
}
