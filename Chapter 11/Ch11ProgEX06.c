/* Write a function called is_within() that takes a character
 * and a string pointer as its two function parameters. Have
 * the function return a nonzero value (true) if the character
 * is in the string and zero (false) otherwise. Test the function
 * in a complete program that uses a loop to provide input values
 * for feeding to the function.
 */
#include <stdio.h>
#define SIZE 20
_Bool is_within(char, const char *);
char * s_gets(char * st, int n);

int main(void)
{
	char ar[SIZE];

	puts("Enter a string:");
	while (s_gets(ar, SIZE))
	{
		puts("Enter a character to search for:");
		if (is_within(getchar(), ar))
			puts("Character found!");
		else
			puts("Character not found!");
		while (getchar() != '\n')
			continue;

		puts("Enter another string:");
	}
	return 0;
}

_Bool is_within(char ch, const char * str)
{
	_Bool ret_val = 0;
	const char * pc = str;

	while (*pc)
	{
		if (*pc == ch)
		{
			ret_val = 1;
			break;
		}
		pc++;
	}

	return ret_val;
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
