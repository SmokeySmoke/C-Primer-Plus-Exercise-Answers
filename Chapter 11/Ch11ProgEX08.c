/* Write a function called string_in() that takes two string pointers
 * as arguments. If the second string is contained in the first string,
 * have the function return the address at which the contained string
 * begins. For instance, string_in("hats", "at") would return the address
 * of the a in hats. Otherwise, have the function return the null pointer.
 * Test the function in a complete program that uses a loop to provide 
 * input values for feeding into the function.
 */
#include <stdio.h>
#include <string.h>
#define SIZE 20
char * string_in(const char *, const char *);
char * s_gets(char * st, int n);

int main(void)
{
	char str1[SIZE], str2[SIZE];
	char * ps, *pc;
	int count;

	puts("Enter a string:");
	while (s_gets(str1, SIZE))
	{
		puts("Enter a string to search the first string for:");
		s_gets(str2, SIZE);
		ps = string_in(str1, str2);
		if (ps == NULL)
			puts("Second string not found in first string!");
		else
		{
			printf("*ps = %c\n", *ps);
			printf("\"%s\" found in the first string here:\n%s\n",
					str2, str1);
			for (pc = str1; pc != ps; pc++)
				count++;
			while (count > 0)
			{
				putchar(' ');
				count--;
			}
			while (count++ < strlen(str2))
				putchar('^');
		}
		puts("\nEnter another string:");
	}
	puts("Done!");

	return 0;
}

char * string_in(const char * s1, const char * s2)
{
	const char * ps1 = s1;
	const char * ps2 = s2;
	const char * ret_val = NULL;
	_Bool find = 0;

	while (*ps2)
	{
		if (*ps1 == *ps2)
		{
			if (find == 0)
			{
				find = 1;
				ret_val = ps1;
			} 
			("IF - ret_val = %c\n", *ret_val);
			ps2++;
		} else
		{
			find = 0;
			ps2 = s2;
			ret_val = NULL;
		}
		ps1++;
	}
	
	return ret_val;
}

char * s_gets(char * st, int n)
{
	char * ret_val, ps;
	int j, i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)	// i.e., ret_val != NULL
	{
		while (st[i] != '\n' && st[i] && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else if (st[i] == '\b')
			for (j = i; j <= strlen(&st[i]) + 1; j++)
				st[j] = st[j+1];
		else 	// must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
