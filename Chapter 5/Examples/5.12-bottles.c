// bottles.c
#include <stdio.h>
#define MAX 100
int main(void) {

	int count = MAX + 1;
	
	while (--count > 0) {

		printf("%d bottles of beer on the wall,\n"
			"%d bottles of beer!\n", count, count);
		printf("Take one down and pass it around,\n");
		printf("%d bottles of beer on the wall!\n\n",
			 count - 1);
	}

	return 0;
}
