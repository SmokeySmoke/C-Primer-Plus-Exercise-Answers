#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {	//int and float overflow, float underflow

	printf("Overflow Int:\t%d\n", INT_MAX + 1);
	printf("Overflow Float:\t%f\n", FLT_MAX + 1.0);
	printf("Underflow Float:\t%f\n", FLT_MIN - 1.0);

	return 0;
}
