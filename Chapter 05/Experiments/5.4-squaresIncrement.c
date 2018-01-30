/* squares.c -- produces a table of first 20 squares */
#include <stdio.h>

int main(void) {

	int num = 0;

	while (++num < 21) {

		printf("%4d %6d\n", num, num * num);
	}

	return 0;
}
