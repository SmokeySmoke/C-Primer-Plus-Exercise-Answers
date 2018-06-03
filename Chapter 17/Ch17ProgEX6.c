/* Write a function that takes three arguments: the name of an array of sorted integers, 
 * the number of elements of the array, and an integer to seek. The function returns the
 * value of 1 if the integer is in the array, and 0 if it isn't. Have the function use the
 *  binary search technique.
 */
#include <stdio.h>
#include <stdbool.h>
#define ARLEN 10
bool ArSearch(const int sortedAR[], const unsigned AR_elem, const int target);

int main(void)
{
	int ar[ARLEN] = {1,2,3,4,5,6,7,8,9,10};
	int target;

	puts("Enter a number to search for in the array (enter non-numerical data to quit):");
	while (scanf("%d", &target) == 1)
	{
		if (ArSearch(ar, ARLEN, target) == true)
			printf("Found ");
		else
			printf("Did not find ");
		printf("%d in the array!\n", target);
		puts("\nEnter another number to search for:");
	}
	puts("Bye!");

	return 0;
}

bool ArSearch(const int sortedAR[], const unsigned AR_elem, const int target)
{
	unsigned elem_left = AR_elem;
	unsigned start = 0;
	unsigned end = AR_elem-1;
	unsigned mid = (start + end) / 2;

	while (elem_left > 0)
	{	
		if (sortedAR[mid] == target) 	// if target is found	
			return true;		// 	return true;
		else if (sortedAR[mid] > target)
			end = mid-1;
		else
			start = mid+1;
		elem_left /= 2;
		mid = (start+end) / 2;
	}

	return false;
}
