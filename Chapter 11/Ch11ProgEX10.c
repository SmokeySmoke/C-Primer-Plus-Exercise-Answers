
/* Write a function that takes a string as an argument and removes the
 * spaces from a string. Test it in a program that uses a loop to read
 * lines until you enter an empty line. The program should apply the 
 * function to each input string and display the result.
 */
#include <stdio.h>
#include <string.h>
#define SIZE 20
void rmspace(char *);
char * s_gets(char *, int);

int main(void)
{
	char s[SIZE];

	puts("Enter a string to remove spaces from:");
	while (s_gets(s, SIZE))
	{
		printf("\n%s without spaces is ");
		rmspace(s);
		puts(s);
		puts("\nEnter another string to remove spaces from:");
	}
	puts("Done!");

	return 0;
}

void rmspace(char * str)
{
	char * ps = str;
	int i;

	while (*ps)
	{
		if (*ps != ' ')
			ps++;
		else
			for (i = 0; i <= strlen(ps); i++)
				 *(ps + i) = *(ps + i+1);
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
