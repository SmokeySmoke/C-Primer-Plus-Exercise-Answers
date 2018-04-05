/* Do Programming Exercise 12, but use variable-length arrays (VLAs) instead of standard arrays.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#define FNAME "EX13result.txt"

int main(int argc, char *argv[])
{
	bool dim1found = false;
	char ch;
	int i, j, bytes, dim1, dim2;
	FILE * fp;
	i = j = dim1 = dim2 = 0;

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Could not open file \"%s\"!\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_SET);
/*	fseek(fp, 0L, SEEK_END);	// causes seg fault in fscanf() in while test condition, not sure why
	bytes = ftell(fp);
	rewind(fp);
	for (i = 1; i <= bytes; i++)
	{
		ch = getc(fp);
		if (ch == '\n')
		{
			dim1found = true;
			dim2++;
		} else if (!dim1found && isdigit(ch))
			dim1++;

	}
	rewind(fp);
*/
	dim1 = 30;
	dim2 = 20;
	char strar[dim2][dim1 + 1];
	int ar[dim2][dim1];

	while (fscanf(fp, "%d", &ar[i][j]) == 1)
	{
		j++;
		if (j == dim1)
		{
			i++;
			j = 0;
		}
	}
	fclose(fp);

	for (i = 0; i < dim2; i++)
	{
		for (j = 0; j <= dim1; j++)
		{
			if (j == dim1)
				strar[i][j] = '\0';
			else
				switch (ar[i][j])
				{
					case 0 : strar[i][j] = ' ';
						 break;
					case 1 : strar[i][j] = '.';
						 break;
					case 2 : strar[i][j] = '`';
						 break;
					case 3 : strar[i][j] = ':';
						 break;
					case 4 : strar[i][j] = '~';
						 break;
					case 5 : strar[i][j] = '*';
						 break;
					case 6 : strar[i][j] = '=';
						 break;
					case 7 : strar[i][j] = '$';
						 break;
					case 8 : strar[i][j] = '%';
						 break;
					case 9 : strar[i][j] = '#';
						 break;
					default: puts("Programming error!");
						 exit(EXIT_FAILURE);
				}
		}
	}

	for (i = 0; i < dim2; i++)
		puts(strar[i]);

	if ((fp = fopen(FNAME, "w")) == NULL)
	{
		puts("Could not write to file!");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < dim2; i++)
	{
		for (j = 0; j < dim1; j++)
		{
			ch = strar[i][j];
			putc(ch, fp);
		}
		putc('\n', fp);
	}
	fclose(fp);
	printf("Done! Wrote result to \"%s\"\n", FNAME);

	return 0;
}
