// a2g.c -- prints characters a through g
#include <stdio.h>
int main(void) {

	int ch = 96;

	while (ch++ < 'g')
		printf("%5c", ch);
	printf("\n");

	return 0;
}
