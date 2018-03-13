/* Write a function that replaces the contents of a string with
 * the string reversed. Test the function in a complete program
 * that uses a loop to provide input values for feeding to the
 * function.
 */
#include <stdio.h>
#include <string.h>
#define SIZE 20
void revstr(char *);
char * s_gets(char * st, int n);

int main(void)
{
	char s[SIZE];

	puts("Enter a string to reverse:");
	while (s_gets(s, SIZE))
	{
		printf("\n%s reversed is: ", s);
		revstr(s);
		puts(s);
		putchar('\n');
		puts("Enter another string to reverse:");
	}

	return 0;
}

void revstr(char * str)
{
	char temp;
	char * top, * end;
	int len = strlen(str);
	int i = 0;

	for (top = str, end = str + len - 1; i < len / 2; top++, end--, i++)
	{
		temp = *top;
		*top = *end;
		*end = temp;
	}

	return;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)	// i.e., ret_val != NULL
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else 	// must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
