/* Design and test a function like that described in Programming Exercise 3
 * except that it accepts a second parameter specifying the maximum number
 * of characters that can be read.
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 25
void skipnwhite(char *, int);

int main(void)
{
	char ar[SIZE];

	skipnwhite(ar, SIZE-1);
	puts(ar);

	return 0;
}

void skipnwhite(char * str, int n)
{
	bool inword = false;
	int i = 0;

	while (i < n && (*str = getchar()))
	{
		if (inword == true && isspace(*str))
			break;
		if (isspace(*str))
			continue;
		inword = true;
		str++;
		i++;
	}
	*str = '\0';

	return;
}
