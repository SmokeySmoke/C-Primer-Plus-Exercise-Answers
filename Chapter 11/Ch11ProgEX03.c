/* Design and test a function that reads the first word from a line of input
 * into an array and discards the rest of the line. It should skip over leading
 * whitespace. Define a word as a sequence of characters nwith no blanks, tabs,
 * or newlines in it. Use getchar().
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 25
void skipwhite(char *);

int main(void)
{
	char ar[SIZE];

	skipwhite(ar);
	puts(ar);

	return 0;
}

void skipwhite(char * str)
{
	bool inword = false;

	while(*str = getchar())
	{
		if (inword == true && isspace(*str))
			break;
		if (isspace(*str))
			continue;
		inword = true;
		str++;
	}
	*str = '\0';

	return;
}
