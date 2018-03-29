/* Write and test in a loop a function that returns the
 * number of times it has been called.
 */
#include <stdio.h>
int fun(void);

static unsigned int ncalls = 0;

int main(void)
{
	unsigned int i, n, nloops;
	n = 0;

	printf("Enter the number of times to call fun(): ");
	scanf("%u", &nloops);
	putchar('\n');

	for (i = 0; i < nloops; i++)
		n = fun();

	printf("\nfun() called %d times!\n", n);

	return 0;
}

int fun(void)
{
	ncalls++;
	printf("fun() call #%d!\n", ncalls);

	return ncalls;
}
