#include <stdio.h>

int main(void) { //prompts user for age in years and prints age in seconds 

	unsigned short age;
	unsigned long long ageSec;

	printf("Enter your age in years: ");
	scanf("%s", &age);

	ageSec = age * 3.156e+7;
	printf("\nYou are at least %llu seconds old.\n", ageSec);

	return 0;
}
