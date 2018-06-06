/* Write a function that takes as arguments the name of an array of type int
 * elements, the size of an array, and a value representing the number of picks.
 * The function then should select the indicated number of items at random from
 * the array and print them. No array element is to be picked more than once.
 * (This simulates picking lottery numbers or jury members.) Also, if your
 * implementation has time() (discussed in Chapter 12) or a similar function
 * available, use its output with srand() to initialize the rand() random-
 * number generator. Write a simple program that tests the function.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void lottery(const unsigned[], const unsigned, const unsigned);


int main(void)
{
	unsigned ar[SIZE] = {1,2,3,4,5,6,7,8,9,10};
	unsigned picks;

	printf("Enter the number of lottery picks: ");
	while (scanf("%u", &picks) == 0 || picks > SIZE)
	{
		printf("Invalid input; enter an unsigned integer less than or equal to %d.\n", SIZE);
		while (getchar() != '\n')
			continue;
	}
	lottery(ar, SIZE, picks);
	
	return 0;
}

void lottery(const unsigned ar[], const unsigned arsize, const unsigned picks)
{
	srand(clock());
	_Bool isPicked[arsize];
	unsigned winner, i;
       
	for (i = 0; i < arsize; i++)
		isPicked[i] = 0;

	i = picks;
	while (i > 0)
	{
		winner = rand() % 10;
		if (isPicked[winner] == 0)
		{
			isPicked[winner] = 1;
			i--;
		}
	}
	puts("Winning numbers:");
	for (i = 0; i < arsize; i++)
		if (isPicked[i])
			printf("\t%u",ar[i]);
	putchar('\n');
}	
