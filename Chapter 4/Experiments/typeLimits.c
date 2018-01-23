/* typelimits.c -- displays data type limits on target system */
#include <stdio.h>
#include <limits.h>	// integer limits
#include <float.h>	// floating-point limits

int main(void) {

	// ints
	printf("Some number limits for this system:\n");
	printf("# of bits in a char: %d\n", CHAR_BIT);
	printf("Maximum char value: %d\n", CHAR_MAX);
	printf("Minumum char value: %d\n", CHAR_MIN);
	printf("Maximum signed char value: %d\n", SCHAR_MAX);
	printf("Minimum signed char value: %d\n", SCHAR_MIN);
	printf("Maximum unsigned char value: %u\n", UCHAR_MAX);
	printf("Maximum short value: %d\n", SHRT_MAX);
	printf("Minimum short value: %d\n", SHRT_MIN);
	printf("Maximum unsigned short value: %u\n", USHRT_MAX);
	printf("Maximum int value: %d\n", INT_MAX);
	printf("Minimum int value: %d\n", INT_MIN);
	printf("Maximum unsigned int value: %u\n", UINT_MAX);
	printf("Maximum long value: %ld\n", LONG_MAX);
	printf("Minimum long value: %ld\n", LONG_MIN);
	printf("Maximum unsigned long value: %lu\n", ULONG_MAX);
	printf("Maximum long long value: %lld\n", LLONG_MAX);
	printf("Minimum long long value: %lld\n", LLONG_MIN);
	printf("Maximum unsigned long long value: %llu\n", ULLONG_MAX);

	// floating-points
	printf("# of bits in mantissa of float: %d\n",FLT_MANT_DIG);
	printf("Minimum # of significant decimal digits for float: %d\n", FLT_DIG);
	printf("Minimum base-10 negative exponent for a float ");
	printf("with a full set of significant figures: %f\n", FLT_MIN_10_EXP);
	printf("Maximum base-10 positive exponent for float: %e\n", DBL_MAX);
	printf("Minimum value for positive float retaining full precision: %e\n", FLT_MIN);
	printf("Maximum value for positive float: %e\n", FLT_MAX);
	printf("difference between 1.00 and the least float value greater than 1.00: %e\n", FLT_EPSILON);
	printf("Maximum double value: %e\n", DBL_MAX);

	return 0;
}
