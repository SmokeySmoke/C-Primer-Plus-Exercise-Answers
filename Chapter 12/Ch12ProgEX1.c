/* Rewrite the program in Listing 12.4 so that it 
 * does not use global variables
 */

#include <stdio.h>
void critic(int *);

int main(void)
{
	int units;

	printf("How many pounds to a firkin of butter?\n");
	while (scanf("%d", &units) == 0)
		puts("Invalid input; try again.");

	while (units != 56)
		critic(&units);
	printf("You must have looked it up!\n");

	return 0;
}

void critic(int * units)
{
	printf("No luck, my friend. Try again.\n");

	while (scanf("%d", units))
	{
		puts("Invalid input; try again.");
		while (getchar() != '\n')
			continue;
	}
}
