#include <stdio.h>

int main(void) { /* prompt user for amount of water in quarts, 
					  print number of water molecules */

	float water, molecules;

	printf("Enter amount of water in quarts: ");
	scanf("%f", &water);

	water = water * 950;	// convert water quarts to grams

	molecules = water / 3.0e-23;

	printf("Number of molecules: %e\n", molecules);

	return 0;
}
