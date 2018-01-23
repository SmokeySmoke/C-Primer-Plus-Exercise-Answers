#include <stdio.h>

int main(void) { // prompts user for ASCII code value, prints character having that ASCII code

	int codeVal;

	printf("Enter ASCII code value: ");
	scanf("%d", &codeVal);
	printf("\n");

	printf("ASCII character: %c\n", codeVal);

	return 0;
}
