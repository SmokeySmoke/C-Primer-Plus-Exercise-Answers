/* Generalize the to_binary function of Listing 9.8 to a 
 * to_base_n() function that takes a second argument in the
 * range 2-10. It should then print the number that is its
 * first argument to the number base given by the second
 * argument. For example, to_base_n(129, 8) would display
 * 201, the base-8 equivalent of 129. Test the function in
 * a complete program.
 */
#include <stdio.h>
void to_base_n(unsigned long num, unsigned short n);

int main(void)
{
	unsigned long number;
	unsigned short base;

	printf("Enter the number to find the base equivalent of: ");
	while (scanf("%lu", &number) != 1)
		printf("Number must be an positive integer.\n");

	printf("Enter a positive number between 2 and 10\n"
	       "to serve as the base: ");
	while (scanf("%hu", &base) != 1)
		printf("Base must be a positive integer.\n");

	printf("Base %u equivalent of %lu: ", base, number);
	to_base_n(number, base);
	putchar('\n');
	
	return 0;
}

void to_base_n(unsigned long num, unsigned short n)	// recursive function
{
	int r;

	while (n < 2 || n > 10)
	{
		printf("Base must be a number from 2-10: ");
		scanf("%hu", &n);
	}

	r = num % n;
	if (num >= n)
		to_base_n(num / n, n);
	printf("%d", r);

	return;
}
