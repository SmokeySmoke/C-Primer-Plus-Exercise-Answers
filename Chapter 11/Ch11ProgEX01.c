/* Design and test a function that fetches the next n characters from 
 * input (including blanks, tabs, and newlines), storing the results
 * in an array whose address is passed as an argument.
 */
#include <stdio.h>
#define SIZE 25
void chfetch(char *, int);

int main(void)
{
	char ar[SIZE];

	chfetch(ar, SIZE - 2);
	puts(ar);

	return 0;
}

void chfetch(char * str, int n)
{
	int i;

	for (i = 0; i <= n; i++)
	{
		*str = getchar();
		str++;
	}
	*(str + i+1) = '\0';

	return;
}
