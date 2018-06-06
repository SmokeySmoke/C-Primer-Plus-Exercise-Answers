/* Write a program that behaves like the modification of Listing 12.13,
 * which we discussed after showing the output of 12.13. That is, have
 * the program produce output like the following:
 * 
 * 	Enter the number of sets; enter q to stop: 18
 * 	How many sides and how many dice? 6 3
 * 	Here are 18 sets of 3 6-sided throws.
 * 	  12  10   6   9   8  14   8  15   9  14  12  17  11   7  10
 * 	  13   8  14
 * 	How many sets? Enter q to stop: q
 */

// manydice.c -- multiple dice rolls
// compile with diceroll.c
#include <stdio.h>
#include <stdlib.h>	// for library rand()
#include <time.h>	// for time()
#include "12.12-diceroll.h"	// for roll_n_dice()
// and for roll count
int main(void)
{
	int dice, roll, sets;
	int sides;
	int status, i;

	srand((unsigned int) time(0));	// randomize seed
	puts("Enter the number of sets; enter q to stop");
	while (scanf("%d", &sets))
	{
		puts("How many sides and how many dice? 0 to quit:");
		while ((status = scanf("%d %d", &sides, &dice)) && sides > 0 && dice > 0)
		{
			if ((status != 2))
			{
				if (status == EOF)
					break;		// exit loop
				else
				{
					printf("You should have entered an integer.");
					printf(" Let's begin again.\n");
					while (getchar() != '\n')
						continue;	// dispose of bad input
					puts("How many sides and how many dice?");
					continue;		// new loop cycle
				}
			}
			printf("Here are %d sets of %d %d-sided throws.\n",
					sets, dice, sides);

			for (i = 0; i < sets; i++)
			{
				roll = roll_n_dice(dice, sides);
				printf("%d\t", roll);
			}
			putchar('\n');
			break;
		}
		printf("\nThe rollem() function was called %d times.\n",
				roll_count);	// use extern variable
		roll_count = 0;

		puts("Enter a number of sets; enter q to stop");
	}
	printf("GOOD FORTUNE TO YOU!\n");

	return 0;
}
