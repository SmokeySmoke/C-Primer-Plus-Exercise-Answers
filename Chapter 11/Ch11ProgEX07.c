/* The strncpy(s1,s2,n) function copies exactly n characters from s2
 * to s1, truncating s2 or padding it with extra null characters as
 * necessary. The target string may not be null-terminated if the 
 * length of s2 is n or more. The function returns s1. Write your 
 * own version of this function; call it mystrncpy(). Test the 
 * function in a complete program that uses a loop to provide
 * input values for feeding into the function.
 */
#include <stdio.h>
#include <string.h>
#define SIZE 20
char * mystrncpy(char *, const char *, int);
char * s_gets(char * st, int n);

int main(void)
{
	char str1[SIZE], str2[SIZE];
	int numch;

	puts("Enter a string for str1:");
	while (s_gets(str1, SIZE) && *str1 != EOF)
	{
		puts("Enter a string for str2:");
		s_gets(str2, SIZE);
		if (*str2 == EOF)
			break;
		puts("How many characters from str2 should be added to str1?");
		scanf("%d", &numch);
		printf("added %d characters; str1 is now as follows:\n%s\n",
			       	numch, mystrncpy(str1, str2, numch));
		puts("Enter another string for str1:");
		while (getchar() != '\n')
			continue;
	}

	return 0;
}

char * mystrncpy(char * s1, const char * s2, int n)
{
	char * ps1 = s1 + strlen(s1);
	const char * ps2 = s2;

	while (n-- > 0)
		*ps1++ = *ps2++;
	*ps1 = '\0';

	return s1;
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
