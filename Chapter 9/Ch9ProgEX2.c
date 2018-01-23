/* Devise a function chline(ch, i, j) that prints
 * the required character in columns i through j.
 * Test it in a simple driver
 */
#include <stdio.h>
void chline(char, int, int);
int get_int(void);
void flushbuffer(void);

int main(void) 
{
	char ch;
	int col_start, col_end;

	printf("Enter a character to print in colums: ");
	ch = getchar();
	flushbuffer();

	printf("Enter the lower and upper limits of the columns\n"
	       "to print the character through:\n"
	       "Lower limit: ");
	col_start = get_int();

	printf("Upper limit: ");
	while ((col_end = get_int()) < col_start)
		printf("Upper limit must be greater than lower limit.\n");
	chline(ch, col_start, col_end);

	return 0;
}
void chline(char ch, int i, int j)
{
	int index;

	for (index = 1; index < i; index++)
		putchar(' ');
	for (index = 0; index <= (j - i); index++)
		putchar(ch);
	putchar('\n');

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
