/* Write a function that takes an int argument and returns the number
 * of "on" bits in the argument. Test the function in a program.
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MASK 0x1
#define SIZE CHAR_BIT * sizeof(int)

char * itobs(int, char *);

int main(int argc, char * argv[])
{
	if (argc != 2)
		printf("Usage: %s [integer]\n", argv[0]);
	else
	{
		int input = atoi(argv[1]);
		char bin_str[SIZE + 1]; 
		itobs(input, bin_str);

		int bitsON = 0;
		for (unsigned i = 0; i < SIZE; i++)
		{
			if ((input & MASK) == 1)
				bitsON++;
			input >>= 1;
		}
		printf("%d bits are ON in %s.\n", bitsON, argv[1]);
		printf("Binary string:\n%s\n", bin_str);
	}
	puts("Done!");
	return 0;
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
