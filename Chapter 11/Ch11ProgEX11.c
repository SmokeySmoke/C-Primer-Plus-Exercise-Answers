/* Write a program that reads in up to 10 strings or to EOF, whichever
 * comes first. Have it offer the user a menu with 5 choices: print the
 * original list of strings, print the strings in ASCII collating sequence,
 * print the strings in order of increasing length, print the strings in
 * order of the length of the first word in the string, and quit. Have the
 * menu recycle until the user enters the quit request. The program, of course,
 * should actually perform the promised tasks.
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define NUMSTR 10
#define STRLEN 40
char * s_gets(char * st, int n);
void flush(void);

int main(void)
{
	char strings[NUMSTR][STRLEN];
	char choice;
	char * pstrings[NUMSTR];
	char * temp;
	int wlen[NUMSTR] = {0};
	int i, j, k;
	int count = 0;
	bool inword = false;

	puts("Enter 10 strings or EOF to end string input:\n");
	while (count < NUMSTR && s_gets(strings[count], STRLEN))
		count++;
	putchar('\n');
	for (i = 0; i < count; i++)
		pstrings[i] = strings[i];

	do
	{
		puts("Enter the number corresponding to your desired action:\n"
		     "1) Print original list of strings\n"
		     "2) Print the strings in ASCII collating sequence\n"
		     "3) Print the strings in order of increasing length\n"
		     "4) Print the strings in order of the length of the first word in the string\n"
		     "5) Quit");
		choice = getchar();
		flush();
		putchar('\n');

		switch (choice)
		{
			case '1' : for (i = 0; i < count; i++)		// print original list of strings
					   puts(strings[i]);
				   break;
			case '2' : for (i = 0; i < count; i++)		// print strings in ASCII collating sequence
				   {
					   for (j = i; j < count; j++)
						   if (strcmp(pstrings[i], strings[j]) > 0)
						   {
							   temp = pstrings[i];
							   pstrings[i] = pstrings[j];
							   pstrings[j] = temp;
						   }
					   puts(pstrings[i]);
				   }
				   break;
			case '3' : for (i = 0; i < count; i++)		// print strings in order of increasing length
				   {
					   for (j = i; j < count; j++)
						   if (strlen(pstrings[i]) > strlen(strings[j]))
						   {
							   temp = pstrings[i];
							   pstrings[i] = pstrings[j];
							   pstrings[j] = temp;
						   }
					   puts(pstrings[i]);
				   }
				   break;
			case '4' : for (i = 0; i < count; i++) 		// print strings in order of length of the first word
				   {
					   for (j = 0; j <= strlen(strings[i]); j++)
					   {
						   if (inword == false && isspace(strings[i][j]))
						   	   continue;
						   else if (inword == true && isspace(strings[i][j]))
							   break;
						   else
						   {
							   inword = true;
							   wlen[i]++;
						   }
					   }
				   }
				   for (i = 0; i < count; i++)
				   {
					   for (j = i; j < count; j++)
						   if (wlen[i] > wlen[j])
						   {
							   k = wlen[i];
							   wlen[i] = wlen[j];
							   wlen[j] = k;

							   temp = pstrings[i];
							   pstrings[i] = pstrings[j];
							   pstrings[j] = temp;
						   }
					   puts(pstrings[i]);
				   }
				   break;
			case '5' : break;				// quit
			default  : puts("Invalid input. Please enter a number from 1 to 5.");
		}
		putchar('\n');
	} while (choice != '5');

	puts("Done!");

	return 0;
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

void flush(void)
{
	while (getchar() != '\n')
		continue;
	return;
}
