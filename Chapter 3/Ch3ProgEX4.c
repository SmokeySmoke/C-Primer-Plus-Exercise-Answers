#include <stdio.h>

int main(void) { /* prompts user for floating-point value and 
					  prints in fixed point, exponential, and p notations */

	float value;

	printf("Enter a floating-point value: ");
	scanf("%f", &value);

	printf("\nfixed-point notation: %f\n", value);
	printf("exponential notation: %e\n", value);
	printf("p notation: %a\n", value);

	return 0;
}
