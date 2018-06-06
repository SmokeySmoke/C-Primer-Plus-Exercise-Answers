// Redo Programming Exercise 8, but this time use a recursive function.


/* Chapter 6, "C Control Statements: Looping," (Listing 6.20)
 * shows a power() function that returned the result of raising 
 * a type double number to a positive integer value. Improve the
 * function so that it correctly handles negative powers. Also,
 * build into the function that 0 to any power other than 0 is 0
 * and that any number to the 0 power is 1. (It should report that
 * 0 to the 0 is undefined, then say it's using a value of 1.)
 * Use a loop. Test the function in a program.
 */

#include <stdio.h>
double power(double, int);  // ANSI prototype

int main(void)
{
	double num;
	int pow;

	printf("Enter a double value: ");
	scanf("%lf", &num);
	printf("Enter a integer power to raise the first value by: ");
	scanf("%d", &pow);

	printf("%lf ^ %d = %lf\n", num, pow, power(num, pow));

	return 0;
}
double power(double n, int p)   // function definition
{
    double pow;
    int i;

    if (n == 0 && p == 0)
    {
	    printf("0 to the 0 power is undefined; using a value of 1.\n");
	    p = 1;
    }
    if (n == 0)
	    pow = 0; 
    else if (p == 0)
	    pow = 1;
    else if (p == 1)
	    pow = n;
    else if (p == -1)
	    pow = 1/n;
    else
    {
	    if (p > 0)
		    pow = n * power(n, p-1);
	    else
		    pow = power(n, p+1) / n;
    }

    return pow;         // return the value of pow
}
