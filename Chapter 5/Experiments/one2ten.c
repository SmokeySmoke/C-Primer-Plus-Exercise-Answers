// one2ten.c -- prints integers 1 through 10
#include <stdio.h>
#define TEN 10
int main(void) {

	int n = 0;

	while (n++ < TEN)
		printf("%5d", n);
	printf("\n");

	return 0;
}
