#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {	// Define int and float max/min values on target system

	printf("Max Int:  \t%d\n", INT_MAX);
	printf("Min Int:  \t%d\n", INT_MIN);
	printf("Max Float:\t%f\n", FLT_MAX);
	printf("Min Float:\t%f\n", FLT_MIN);
	printf("Max Unsigned Long Long:\t%llu\n", ULLONG_MAX);

	return 0;
}
