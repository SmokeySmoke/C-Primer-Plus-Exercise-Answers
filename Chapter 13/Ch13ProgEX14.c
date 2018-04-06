/* Digital images, particularly those radioed back from space, may have glitches. Add a de-glitching function
 * to programming exercise 12. It should compare each value to it's immediate neighbours to the left and right,
 * above and below. If the value differs by more than 1 from each of its neighbours, replace the value with the
 * average of the neighbouring values. You should round the average to the nearest integer value. Note that the
 * points along the boundaries have fewer that four neighbours, so they require special handling.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define FNAME "EX14result.txt"

int main(int argc, char *argv[])
{

	char ch;
	char strar[20][31];
	int i, j, avg;
	int ar[20][30];
	FILE * fp;
	i = j = 0;

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Could not open file \"%s\"!\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_SET);

	while (fscanf(fp, "%d", &ar[i][j]) == 1)
	{
		j++;
		if (j == 30)
		{
			i++;
			j = 0;
		}
	}
	fclose(fp);

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j <= 30; j++)
		{
			if (j == 30)
				strar[i][j] = '\0';
			else
			{
				if (i == 0)
				{
					if (j == 0)		// top left value
						avg = (ar[i+1][j] + ar[i][j+1] + ar[i+1][j+1]) / 3;
					else if (j == 19)	// top right value
						avg = (ar[i+1][j] + ar[i][j-1] + ar[i+1][j-1]) / 3;
					else			// top row other than corners
						avg = (ar[i+1][j] + ar[i][j-1] + ar[i+1][j-1] + ar[i+1][j+1] + ar[i][j+1]) / 5;

				} else if (i == 19)
				{
					if (j == 0)		// bottom left value
						avg = (ar[i-1][j] + ar[i][j+1] + ar[i-1][j+1]) / 3;
					else if (j == 19)	// bottom right value
						avg = (ar[i-1][j] + ar[i][j-1] + ar[i-1][j-1]) / 3;
					else			// bottome row other than corners
						avg = (ar[i-1][j] + ar[i][j-1] + ar[i-1][j-1] + ar[i-1][j+1] + ar[i][j+1]) / 5;
				} else
					avg = (ar[i+1][j] + ar[i][j-1] + ar[i+1][j-1] + ar[i+1][j+1] 
					     + ar[i][j+1] + ar[i-1][j+1] + ar[i-1][j] + ar[i-1][j-1]) / 8;
				if (ar[i][j] > avg)
				{
					if (ar[i][j] - avg > 1)
						ar[i][j] = avg;
				} else if (ar[i][j] < avg)
					if (ar[i][j] - avg > 1)
						ar[i][j] = avg;

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
	}

	for (i = 0; i < 20; i++)
		puts(strar[i]);

	if ((fp = fopen(FNAME, "w")) == NULL)
	{
		puts("Could not write to file!");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 30; j++)
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
