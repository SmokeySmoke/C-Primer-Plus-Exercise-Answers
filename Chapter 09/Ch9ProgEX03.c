/* Write a function that takes three arguments: a character
 * and two integers. The character is to be printed. The first
 * integer specifies the number of times that the character
 * is to be printed on a line, and the second integer specifies
 * the number of lines that are to be printed. Write a program
 * that makes use of this function.
 */

#include <stdio.h>
void chlines(char, int, int);
int get_int(void);
void flushbuffer(void);

int main(void) 
{
	char ch;
	int num_char, num_lines;

	printf("Enter a character to print: ");
	ch = getchar();
	flushbuffer();

	printf("Enter the number of characters that\n"
	       "should be printed on a line: ");
	num_char = get_int();

	printf("Enter the number of lines that are to be printed: ");
	num_lines = get_int();

	chlines(ch, num_char, num_lines);

	return 0;
}
void chlines(char ch, int nc, int nl)
{
	int index;

	while (nl > 0)
	{
		for (index = 1; index < nc; index++)
			putchar(ch);
		putchar('\n');
		nl--;
	}

	return;
}
int get_int(void)
{
	int i;

	while (scanf("%d", &i) != 1)
	{
		flushbuffer();
		printf("Please enter an integer value: ");
	}

	return i;
}

void flushbuffer(void)
{
	while (getchar() != '\n')
		continue;

	return;
}	
