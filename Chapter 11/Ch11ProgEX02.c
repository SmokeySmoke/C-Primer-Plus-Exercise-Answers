/* Modify and test the function in exercise 1 so that it stops after n characters
 * or after the first blank, tab, or newline, whichever comes first.
 */
#include <stdio.h>
#include <ctype.h>
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
		*(str+i) = getchar();
		if(isspace(*(str+i)))
			break;
	}
	*(str + ++i) = '\0';

	return;
}
