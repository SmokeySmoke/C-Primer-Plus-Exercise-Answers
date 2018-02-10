/* Write a program that initializes a two-dimensional 3x5 array-of-double
 * and uses a VLA-based function to copy it to a second two-dimensional
 * array. Also provide a VLA-based function to display the contents of
 * the two arrays. The two functions should be capable, in general, of 
 * processing arbitrary NxM arrays. (If you don't have access to a VLA-
 * capable compiler, use the traditional C approach of functions that
 * can process an Nx5 array).
 */
#include <stdio.h>
#define ROWS 3
#define COLS 5
void copyVLA(int , int, const double [*][*], double ar[*][*]);
void showVLA(int, int, const double [*][*]);

int main(void)
{
	const double source[ROWS][COLS] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};
	double target[ROWS][COLS];
	int row, col;

	copyVLA(ROWS, COLS, source, target);

	printf("source:\n");
	showVLA(ROWS, COLS, source);
	putchar('\n');
	printf("target:\n");
	showVLA(ROWS, COLS, target);

	return 0;
}

void copyVLA(int n, int m, const double src[n][m], double ar[n][m])
{
	int row, col;

	for (row = 0; row < n; row++)
		for (col = 0; col < m; col++)
			ar[row][col] = src[row][col];

	return;
}

void showVLA(int n, int m, const double ar[n][m])
{
	int row, col;

	for (row = 0; row < n; row++)
		for (col = 0; col < m; col++)
			printf("[%d][%d] = %.0lf\n", row, col, ar[row][col]);

	return;
}
