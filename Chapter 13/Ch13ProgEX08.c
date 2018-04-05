/* Write a program that takes as command-line arguments a character
 * and zero r more filenames. If no arguments follow the character,
 * have the program read from standard input. Otherwise, have it open
 * each file in turn and report how many times the character appears in
 * each file. The filename and the character itself should be reported
 * along with the count. Include error-checking to see whether the number
 * of arguments is correct and whether the files can be opened. If a file
 * can't be opened, have the program report that fact and go on to the next
 * file.
 */

// removes newlines from text files
#include <stdio.h>
#define SLEN 81	// limit for filename
long srchfp(char, FILE *);

int main(int argc, char *argv[])
{
	int i;
	char ch;
	char fname[SLEN];
	FILE * fp;

	if (argc == 1)
		printf("Usage:  %s [Character to search for] [filename]...\n", argv[0]);	// display usage information
	else if (argc == 2)
	{
		ch = argv[1][0];

		printf("Enter filenames of files to search for %c in (EOF to finish):\n", ch);
		while (scanf("%s", fname) == 1)
		{
			if ((fp = fopen(fname, "r")) == NULL)
				printf("Error opening file \"%s\"! Skipping...\n", fname);
			else
				printf("\nCharacter '%c' appears %ld times in file \"%s\"\n", ch, srchfp(ch, fp), fname); 
			fclose(fp);
		}
	} else
	{
		ch = argv[1][0];

		putchar('\n');
		for (i = 2; i < argc; i++)			// for every command line argument
		{
			if ((fp = fopen(argv[i], "r")) == NULL)
				printf("Error opening file \"%s\"! Skipping...\n", fname);
			else
				printf("Character '%c' appears %ld times in file \"%s\"\n", ch, srchfp(ch, fp), argv[i]); 
		}
		fclose(fp);
	}
	puts("\nDone!");

	return 0;
}

long srchfp(char ch, FILE * fp)
{
	char fch;
	long bytes, count = 0;

	fseek(fp, 0L, SEEK_END);
	bytes = ftell(fp);
	rewind(fp);

	for (int i = 1; i <= bytes; i++)
	{
		fch = getc(fp);
		if (fch == ch)
			count++;
	}

	return count;
}
