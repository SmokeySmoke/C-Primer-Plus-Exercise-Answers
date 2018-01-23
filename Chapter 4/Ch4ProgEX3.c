/* Write a program that reads in a floating-point number and
 prints it first in decimal-point notation and then in
 exponential notation. Have the output use the following formats 
 (the number of digits shown in the exponent may be different for
 your system:
	a) The input is 21.3 or 2.1e+001
	b) The input is +21.290 or 2.129E+001
*/
#include <stdio.h>

int main(void) {

	float n, n2;

	printf("a) Enter a floating point number:\n");	// prompt user for floating-point value
	scanf("%f", &n);				// a)
	printf("%.1f %.1e\n\n", n, n);			// display input in 21.3 and 2.1e+001 format

	printf("b) Enter a floating point number:\n");	// prompt user for another floating-point value
	scanf("%f", &n2);				// b)
	printf("%+.3f %+.3E\n", n2, n2);		// display input in +21.290 and 2.129E+001 format

	return 0;
}
