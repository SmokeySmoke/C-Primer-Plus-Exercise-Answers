// Do Programming Exercise 13, but use variable-length array function parameters

/* Write a program that prompts the user to enter three sets of five double
 * numbers each. You may assume the user responds correctly and doesn't enter
 * non-numeric data.) The program should accomplish all of the following:
 * 
 * 	a) Store the information in a 3x5 array.
 * 	b) Compute the average of each set of five values.
 * 	c) Compute the average of all the values.
 * 	d) Determine the largest value of the 15 values.
 * 	e) Report the results.
 *
 * Each major task should be handled by a seperate function using the 
 * traditional C approach to handling arrays. Accomplish task "b" by using
 * a function that computes and returns the average of a one-dimensional
 * array; use a loop to call this function three times. The other tasks should
 * take the entire array as an argument, and the functions performing tasks
 * "c" and "d" should return the answer to the calling program.
 */
#include <stdio.h>
#define ROWS 3
#define COLS 5
void store(int, int, double [*][*]);
double avgRow(int, const double [*]);
double avgAll(int, int, const double [*][*]);
double largest(int, int, const double [*][*]);

int main(void)
{
	double array[ROWS][COLS];
	double avgEach;
	int row;

	printf("Enter %d sets of %d double numbers:\n", ROWS, COLS);
	store(ROWS, COLS, array);

	printf("Average of each row:\n");
	for (row = 0; row < ROWS; row++)
		printf("row %d: %.1lf\n", row+1, avgRow(COLS, array[row]));

	printf("Average of all values: %.1lf\n", avgAll(ROWS, COLS, array));

	printf("Largest value: %.1lf\n", largest(ROWS, COLS, array));

	return 0;
}

void store(int rows, int cols, double ar[rows][cols])
{
	int row, col;
	for (row = 0; row < rows; row++)
		for (col = 0; col < cols; col++)
			scanf("%lf", &ar[row][col]);
	return;
}

double avgRow(int cols, const double ar[cols])
{
	double sum;
	int col;

	for (col = sum = 0; col < cols; col++)
		sum += ar[col];
	
	return sum / cols;
}

double avgAll(int rows, int cols, const double ar[rows][cols])
{
	int row, col;
	float sum = 0;

	for (row = 0; row < rows; row++)
		for (col = 0; col < cols; col++)
			sum += ar[row][col];

	return sum / (rows * cols);
}

double largest(int rows, int cols, double ar[rows][cols])
{
	float biggest = 0;
	int row, col;

	for (row = 0; row < rows; row++)
		for (col = 0; col < cols; col++)
			if (ar[row][col] > biggest)
				biggest = ar[row][col];
	return biggest;
}
