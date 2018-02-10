/* Write a program that initializes a two-dimensional array
 * of double and uses one of the copy functions from exercise
 * 2 to copy it to a second two-dimensional array. (Because a
 * two-dimensional array is an array of arrays, a one-dimensional
 * copy function can be used with each subarray.)
 */
#include <stdio.h>
#define ROWS 2
#define COLS 5
void copy_arr(double [], const double [], int);

int main(void)
{
	double source[ROWS][COLS] = {
		{1.1, 2.2, 3.3, 4.4, 5.5},
		{5.5, 4.4, 3.3, 2.2, 1.1}
	};
	double target[ROWS][COLS];
	int col, row;

	for (row = 0; row < ROWS; row++)
		for (col = 0; col < COLS; col++)
			printf("source[%d][%d] = %.1lf\n", row, col, source[row][col]);
	putchar('\n');

	for (row =0; row < ROWS; row++)
		copy_arr(target[row], source[row], COLS);

	for (row = 0; row < ROWS; row++)
		for (col = 0; col < COLS; col++)
			printf("target[%d][%d] = %.1lf\n", row, col, target[row][col]);
	putchar('\n');

	return 0;
}

void copy_arr(double ar[], const double src[], int n)
{
	while (n-- >= 0)
		ar[n] = src[n];

	return;
}
