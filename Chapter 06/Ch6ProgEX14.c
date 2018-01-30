/* Write a program that creates two eight-element arrays of doubles and
 uses a loop to let the user enter values for the eight elements of the
 eight elements of the first array. Have the program set the elements of
 the second array to the cumulative totals of the elements of the first
 array. For example, the fourth element of the second array should equal
 the sum of the first four elements of the first array, and the fifth 
 element of the second array should equal the sum of the first five 
 elements of the first array. (It's possible to do this with nested loops,
 but by using the fact that the fifth element of the second array equals 
 the fourth element of the second array plus the fifth element of the first
 array, you can avoid nesting and just use a single loop for this task.)
 Finally, use loops to display the contents of the two arrays, with the
 first array displayed on one line and with each element of the second
 array displayed below the corresponding element of the first array.
*/
#include <stdio.h>
int main(void) {

	int index;
	double i[8], j[8];

	printf("Enter 8 values:");
	for (index = 0; index < 8; index++) {
		scanf("%lf", &i[index]);
		j[index] = j[index - 1] + i[index];
	}

	for (index = 0; index < 8; index++)
		printf("%-12lf ", i[index]);
	printf("\n");

	for (index = 0; index < 8; index++)
		printf("%-12lf ", j[index]);
	printf("\n");

	return 0;
}

