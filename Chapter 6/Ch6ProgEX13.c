/* Write a program that creates an eight-element array of ints and sets the
 elements to the first eight powers of 2 and then prints the values. Use a
 for loop to set the values, and, for variety, use a do while loop to display
 the values.
*/
#include <stdio.h>
#include <math.h>
#define VALUE 2
int main(void) {

	int i[8], index;

	for (index = 1; index <= 8; index++)
		i[index] = pow(VALUE, index);

	index = 1;

	do {
		printf("%d ", i[index]);
		index++;
	} while (index <= 8);
	printf("\n");

	return 0;
}

