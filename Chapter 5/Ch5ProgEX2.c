/* Write a program that asks for an integer and then prints all the integers from (and including)
that value up to (and including) a value larger by 10. (That is, if the input is 5, the output
runs from 5 to 15.) be sure to seperate each output value by a space or tab or newline. */
#include <stdio.h>
int main(void) {

	int i, n = 0;

	printf("Enter an integer:\n");
	scanf("%d", &i);

	while (n++ <= 10) {
		printf("\t%d\n", i);
		++i;
	}		

	return 0;
}
