/* Write and test a fibonacci() function that uses a loop
 * instead of recursion to calculate Fibonacci numbers.
 */
#include <stdio.h>
unsigned long fibonacci(unsigned int);

int main(void)
{
	unsigned num;

	printf("Enter a limit for the fibonacci function: ");
	while (scanf("%u", &num) != 1)
		printf("Number must be a positive integer: ");

	printf("Fibonacci # = %lu\n", fibonacci(num));

	return 0;
}

unsigned long fibonacci(unsigned int n)
{
	unsigned int i, fib[n];
	fib[0] = fib[1] = 1;

	if (n > 2)
		for (i = 2; i <= n; i++)
			fib[i] = fib[i-1] + fib[i-2];

	return fib[n-1];
}
