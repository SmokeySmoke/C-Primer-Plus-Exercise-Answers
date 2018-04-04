/* Write a program that opens two files. You can obtain the 
 * filenames either by using command-line arguments or by
 * soliciting the user to enter them.
 *
 * 	b) Modify the program so that lines with the same
 * 	   line number are printed on the same line.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(int argc, char *argv[])
{
	char ch;
	FILE * fp1, * fp2;
	bool fp1isdone, fp2isdone;
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
				if (ch == '\n' && !fp2isdone)
					break;
				else if (ch == '\n')
				{
					putchar(ch);
					break;
				}
				putchar(ch);
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
			if ((ch = getc(fp2))  ==  EOF)
			{
				fp2isdone = true;
				fclose(fp2);
			}
			else
				ungetc(ch, fp2);
		}
	}
	puts("\nDone!");

	return 0;
}
