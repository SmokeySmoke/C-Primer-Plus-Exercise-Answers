#include <stdio.h>

int main(void) {	// Prompt user for age in years and calculate age in days, then display both values
	
	int age, ageDays;
	
	printf("Please enter your age in years: ");	// Prompt user for age
	scanf("%d", &age);
	
	printf("Age in years: %d\nAge in days: %d\n", age, age * 365);	// Calculate age in days and display both values

	return 0;
}