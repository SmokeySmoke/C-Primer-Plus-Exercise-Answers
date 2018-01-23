#include <stdio.h>

int main(void) { /* prompt user for volume in cups and display
					volumes in pints, ounces, tablespoons, and teaspoons */
	float cups;
	
	printf("Enter a volume in cups: ");
	scanf("%f", &cups);

	printf("\nVolume in pints: %.2f", cups * 2);

	cups = cups * 8;
	printf("\nVolume in ounces: %.2f", cups);

	cups = cups * 2;
	printf("\nVolume in tablespoons: %.2f", cups);

	cups = cups * 3;
	printf("\nVolume in teaspoons: %.2f\n", cups);

	return 0;
}

/* a floating point data type makes more sense for this application because 
the user may input fractions of a cup, as in 1.5 cups, and the conversion may 
be a fraction, as in 1.75 cups is 3.5 pints */
