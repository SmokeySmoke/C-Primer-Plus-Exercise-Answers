/* Write a program that requests a type double number and
prints the value of the number cubed. Use a function of
your own design to cube the value and print it. The main()
program should pass the entered value as a function.
*/
#include <stdio.h>
double cubed(double n);
int main(void) {

	double i, iCubed;

	printf("Enter a number to cube: ");
	scanf("%lf", &i);

	iCubed = cubed(i);
	printf("%.2lf cubed = %.2lf\n", i, iCubed);

	return 0;
}
double cubed(double n) {

	n = n * n * n;
	return n;
}