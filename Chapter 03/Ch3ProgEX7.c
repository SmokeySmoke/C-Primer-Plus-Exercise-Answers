#include <stdio.h>

int main(void) { /* prompt user for height in inches, print height in centimeters */

	int heightIn, heightCm;
	printf("Enter height in inches: ");
	scanf("%d", &heightIn);
	heightCm = heightIn * 2.54;
	printf("Your height in centimeters is: %d\n", heightCm);

	return 0;
}
