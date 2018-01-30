#include <stdio.h>

void one_three(void);
void two(void);

int main(void) {
	printf("Starting now:\n");	
	one_three();
	printf("Done!\n");

	return 0;
}

void one_three(void) {
	
	printf("One\n");
	two();
	printf("Three\n");
}

void two(void) {
	
	printf("Two\n");
}