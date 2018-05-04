/* Write a function that rotates the bits of an unsigned int by a
 * specified number of bits to the left. For instance, rotate_l(x,4)
 * would move the bits in x four places to the left, and the bits lost
 * from the left end would reappear at the right end. That is, the bit 
 * moved out of the high-order position is placed in the low-order
 * position. Test the function in a program.
 */
#include <stdio.h>
#include <limits.h>
#define HIBIT 0x80000000	// high order bit of unsigned int on my machine

unsigned rotate_l(unsigned, unsigned);
char * itobs(int, char *);

int main(void)
{
	unsigned value, rotations;

	puts("Enter a value and the number of times to rotate bits left:");
	while (scanf("%u %u", &value, &rotations) != 2)
	{
		puts("Invalid input; enter two unsigned integers.");
		while (getchar() != '\n')
			continue;
	}
	printf("Value after %u rotations: %u\n", rotations, rotate_l(value, rotations));

	puts("\nDone!");
	return 0;
}

unsigned rotate_l(unsigned n, unsigned rotations)
{
	char bin_str[CHAR_BIT * sizeof(unsigned) + 1];
	printf("Binary string for %d:\n", n);
	puts(itobs(n, bin_str));
	_Bool shift = 0;

	printf("\nValue %u after %u rotations:\n", n, rotations);
	while (rotations-- > 0)
	{
		if ((n & HIBIT) == HIBIT)
			shift = 1;
		n <<= 1;
		if (shift == 1)
			n |= 0x1;
		shift = 0;
	}
	puts(itobs(n, bin_str));
	putchar('\n');

	return n;
}

char * itobs(int n, char * ps)
{
	int i;
	static const int size = CHAR_BIT * sizeof(int);

	for (i = size-1; i >= 0; i--, n >>= 1)
		ps[i] = (0x1 & n) + '0';
	ps[size] = '\0';

	return ps;
}
