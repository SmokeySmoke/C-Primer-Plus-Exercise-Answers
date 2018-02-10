/* Write a function that sets each element in an array to the sum of
 * the corresponding elements in two other arrays. That is, if array
 * 1 has the values 2,4,5, and 8 and array 2 has the values 1,0,4, and
 * 6, the function assigns array 3 the values 3,4,9, and 14. The function
 * should take three array names and an array size as arguments. Test the
 * function in a simple program.
 */
#include <stdio.h>
#define SIZE 4
void arrAdd(int [],int [],int [],int);

int main(void)
{
	int array1[SIZE] = {2,4,5,8};
	int array2[SIZE] = {1,0,4,6};
	int array3[SIZE];

	arrAdd(array1, array2, array3, SIZE);
	for (int i = 0; i < SIZE; i++)
		printf("array3[%d] = %d\n", i, array3[i]);

	return 0;
}

void arrAdd(int ar1[], int ar2[], int sum[], int arrlen)
{
	for (int i = 0; i < arrlen; i++)
		sum[i] = ar1[i] + ar2[i];

	return;
}
