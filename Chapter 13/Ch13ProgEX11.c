/* Write a program that takes two command-line arguments. The first is a string;
 * the second is the name of a file. The program should then search the file, 
 * printing all lines containing the string. Because this task is line oriented
 * rather than character oriented, use fgets() insted of getc(). Use the standard
 * C library function strstr() (briefly described in exercise 7 of Chapter 11) to
 * search each line for the string. Assume no lines are longer than 255 characters.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 255

int main(int argc, char *argv[])
{
	if (argc == 1 || argc == 2 || argc > 3)
		printf("Usage: %s [string-to-search-for] [file]\n", argv[0]);
	else 
	{
		unsigned nl = 0;
		FILE * fp;
		char fline[MAXLINE];

		if ((fp = fopen(argv[2], "r")) == NULL)
		{
			printf("Could not open file %s!\n", argv[2]);
			exit(EXIT_FAILURE);
		}
		fseek(fp, 0L, SEEK_SET);

		while (fgets(fline, MAXLINE, fp))
		{
			nl++;
			if (strstr(fline, argv[1]) != NULL)
				printf("Line %u - %s", nl, fline);
		}
		printf("Done! Read %u lines.\n", nl);
	}

	return 0;
}
