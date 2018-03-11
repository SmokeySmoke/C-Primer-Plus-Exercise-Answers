/* Design and test a function that searches the string specified
 * by the first function parameter for the first occurrence of a
 * character specified by the second function parameter. Have the
 * function return a pointer to the character if successful, and
 * a null if the character is not found in the string. (This
 * duplicates the way that the library strchr() function works.)
 * Test the function in a complete program that uses a loop to
 * provide input values for feeding to the function
 */
#include <stdio.h>
#include <stdbool.h>
#define SIZE 20
char * searchstr(const char *, char);
char * s_gets(char * st, int n);
void flush(void);

int main(void)
{
	char str[SIZE];
	char ch;
	char * pc, * pstr;
	int count;

	puts("Enter a string under 20 characters:");
	while (s_gets(str, SIZE))
	{
		
		pstr = str;

		puts("\nEnter a character to search for:");
		pc = searchstr(str, ch = getchar());
		flush();
		if (pc == NULL)
		{
			puts("Character not found or string too long!");
			puts("Please enter another string:");
			continue;
		}

		printf("\nFirst occurance of %c is here:\n", ch);
		puts(str);
		for (count = 0; pstr != pc; count++)
			pstr++;
		while (count-- > 0)
			putchar(' ');
		puts("^");

		puts("Enter another string:");
	}
	
	return 0;
}

char * searchstr(const char * str, char n)
{
	char * ret_val = str;
	bool nfound = false;

	while (*ret_val)
	{
		if (*ret_val == n)
		{
			nfound = true;
			break;
		}
		ret_val++;
	}
	if (nfound == false)
		ret_val = NULL;

	return ret_val;
}

void flush(void)
{
	while (getchar() != '\n')
		continue;

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
