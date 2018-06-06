/* Write a function that converts a binary string to a numeric value.
 * That is, if you have
 *
 * 	char * pbin = "01001001";
 *
 * you can pass pbin as an argument to the function and have that function
 * return an int value of 25. <- ??? should be 73?
 */
#include <stdio.h>
#include <string.h>
#include <limits.h>

int btoi(char *);
char * itobs(int, char *);

int main(void)
{
	char * pbin = "01001001";

	printf("%d\n", btoi(pbin));

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
