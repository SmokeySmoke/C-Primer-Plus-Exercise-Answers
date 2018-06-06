/* Write a program that generates 1000 random numbers in the range
 * 1-10. Don't save or print the numbers, but do print how many times
 * each number was produced. Have the program do this for 10 different
 * seed values. Do the numbers appear in equal amounts? You can use the
 * functions from this chapter or the ANSI C rand() and srand() functions,
 * which follow the same format that our functions do. This is one way to
 * examine the randomness of a particular random-number generator.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIMIT 1000
#define ARRDIM1 10
#define ARRDIM2 10
int main(void)
{
	int narr[ARRDIM2][ARRDIM1];
	int i, j, n;

	srand((unsigned int) time(0));
	puts("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10");
	printf("-----------------------------------------------------------------------------------");

	for (j = 0; j < ARRDIM2; j++)
	{
		srand((unsigned int) time(0));
		if (j >= 9)
			printf("\n%d|\t", j+1);
		else
			printf("\n%d |\t", j+1);

		for (i = 0; i < LIMIT; i++)
		{
		n = rand() % 10 + 1;
		narr[j][n-1] = n;
		}

		for (i = 0; i < ARRDIM1; i++)
			printf("%d\t", narr[j][i]);
	}
	putchar('\n');

	return 0;
}
