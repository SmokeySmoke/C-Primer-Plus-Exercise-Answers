/* Write a function that takes two int arguments: a value and a bit position. Have the
 * function return 1 if that particular bit position is 1, and have it return 0 otherwise.
 * Test the function in a program.
 */
#include <stdio.h>

_Bool bitStat(int, int);

int main(void)
{
	int value, position;

	printf("Enter a value and a bit position to check: ");
	while (scanf("%d %d", &value, &position) != 2)
	{
		puts("Invalid input; enter two integers.");
		while (getchar() != '\n')
			continue;
	}
	printf("Bit position %d in value %d is %s.\n",
		       	position, value, bitStat(value, position) == 1 ? "ON" : "OFF");

	return 0;
}

_Bool bitStat(int val, int pos)
{
	const unsigned mask = 0x1;
	_Bool retval = 0;

	if (pos > 0)
		val >>= pos;
	if ((val & mask) == 1)
		retval = 1;
	
	return retval;
}
