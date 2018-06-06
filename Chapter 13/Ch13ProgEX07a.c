/* Write a program that opens two files. You can obtain the 
 * filenames either by using command-line arguments or by
 * soliciting the user to enter them.
 *
 * 	a) Have the program print line 1 of the first file,
 * 	   line 1 of the second file, line 2 of the first
 * 	   file, line 2 of the second file, and so on, until
 * 	   the last line of the longer file (in terms of lines)
 * 	   is printed.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(int argc, char *argv[])
{
	char ch;
	bool fp1isdone, fp2isdone;
	FILE * fp1, * fp2;
	fp1isdone = fp2isdone = false;

	putchar('\n');
	if ((fp1 = fopen(argv[1], "r")) == NULL)
	{
		printf("Could not open file \"%s\"!\n"
		       "Exiting...\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((fp2 = fopen(argv[2], "r")) == NULL)
	{
		printf("Could not open file \"%s\"!\n"
		       "Exiting...\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	fseek(fp1, 0L, SEEK_SET);
	fseek(fp2, 0L, SEEK_SET);


	while (!fp1isdone || !fp2isdone)
	{
		if (!fp1isdone)
		{
			while ((ch = getc(fp1)) != EOF)
			{
				putchar(ch);
				if (ch == '\n')
					break;
			}
			if (ch == EOF)
			{
				fp1isdone = true;
				fclose(fp1);
			}
		}

		if (!fp2isdone)
		{
			while ((ch = getc(fp2)) != EOF)
			{
				putchar(ch);
				if (ch == '\n')
					break;
			}
	
			if (ch == EOF)
			{
				fp2isdone = true;
				fclose(fp2);
			}
		}
	}
	puts("\nDone!");

	return 0;
}
