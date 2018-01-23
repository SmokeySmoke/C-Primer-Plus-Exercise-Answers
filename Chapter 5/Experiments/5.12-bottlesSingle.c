// bottles.c
#include <stdio.h>
#define MAX 100
int main(void) {

	int count = MAX + 1;
	
	while (--count > 0) {

		if (count == 1)
			printf("%d bottle of beer on the wall,\n"
				"%d bottle of beer!\n", count, count);
		else	
			printf("%d bottles of beer on the wall,\n"
				"%d bottles of beer!\n", count, count);
		
		printf("Take one down and pass it around,\n");

		if (count == 2)
			printf("%d bottle of beer on the wall!\n\n",
				 count - 1);
		else if (count == 1) {
			printf("No more bottles of beer on the wall!\n");
			count - 1;
		} else 
			printf("%d bottles of beer on the wall!\n\n",
				count - 1);
	}

	return 0;
}
