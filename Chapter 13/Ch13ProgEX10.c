/* Write a program that opens a text file whose name is obtained interactively.
 * Set up a loop that asks the user to enter a file position. The program then 
 * should print the part of the file starting at that position and proceed to
 * the next newline character. Let negative or nonnumeric input terminate the
 * user-input loop.
 */
#include <stdio.h>
#include <stdlib.h>
#define NAMESIZE 81

int main(void)
{
	char ch;
	char fname[NAMESIZE];
	long fpos;
	FILE * fp;

	printf("Enter the name of the file to search in: ");
	scanf("%s", fname);
	if ((fp = fopen(fname, "r")) == NULL)
	{
		printf("Could not open file \"%s\"!\n", fname);
		exit(EXIT_FAILURE);
	}

	printf("Enter a file position: ");
	while (scanf("%ld", &fpos) == 1)
	{
		if (fpos < 0)
			break;
		fseek(fp, fpos, SEEK_SET);
		while ((ch = getc(fp)) != '\n')
			putchar(ch);
		printf("\nEnter another file position (negative or nonnumeric input to quit): ");
	}
	puts("Done!");

	return 0;
}
