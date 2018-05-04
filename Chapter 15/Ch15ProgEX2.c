/* Write a program that reads two binary strings as command-line arguments
 * and prints the results of applying the ~ operator to each number and the 
 * results of applying the &, |, and ^ operators to the pair. Show the results
 * as binary strings.
 */
#include <stdio.h>
#include <string.h>
#include <limits.h>

int btoi(char *);
char * itobs(int, char *);

int main(int argc, char * argv[])
{
	if (argc != 3)
		printf("Usage: %s [binary string] [binary string]\n", argv[0]);
	else
	{
		int n1 = btoi(argv[1]);
		int n2 = btoi(argv[2]);
		char bin_str[CHAR_BIT * sizeof(int) + 1];

		printf("~%d =\t%s\n", n1, itobs(~n1, bin_str));
		printf("~%d =\t%s\n", n2, itobs(~n2, bin_str));
		
		printf("%d & %d =\t%s\n", n1, n2, itobs(n1 & n2, bin_str));
		printf("%d | %d =\t%s\n", n1, n2, itobs(n1 | n2, bin_str));
		printf("%d ^ %d =\t%s\n", n1, n2,  itobs(n1 ^ n2, bin_str));
	}
	puts("Done!");

	return 0;
}

int btoi(char * pbin)
{
	int size = strlen(pbin);
	int retval = 0x0;
	
	for (int i = 0; i < size; i++)
	{
		retval |= pbin[i] - '0';
		if (i < size-1)		// if not the low-order bit
			retval <<=1;	// 	- shift bits left
	}

	return retval;
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
