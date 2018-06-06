/* Write a function called transform() that takes four arguments: the name of a source
 * array containing type double data, the name of a target array of type double, an int
 * representing the number of array elements, and the name of a function (or, equivalently,
 * a pointer to a function). The transform() function should apply the indicated function
 * to each element in the source array, placing the return value in the target array. For
 * example, the call
 * 
 * 	transform(source, target, 100, sin);
 *
 * would set target[0] to sin(source[0]), and so on, for 100 elements. Test the function in a 
 * program that calls transform() four times, using two functions from the math.h library and
 * two suitable functions of your own devising as arguments to successive calls of the transform()
 * function.
 */
#include <stdio.h>
#include <math.h>
#define ARSIZE 10

void transform(double [], double [], int, double function(double));
double times2(double);
double div2(double);

int main(void)
{
	int i;
	double source[ARSIZE];
	double target[ARSIZE] = {0};

	for (i = 0; i < ARSIZE; i++)
		source[i] = (double) i;

	transform(source, target, ARSIZE, sin);
	puts("Function sin():");
	for (i = 0; i < ARSIZE; i++)
		printf("source[%d] = %.2f\ttarget[%d] = %.2f\n", i, source[i], i, target[i]);

	transform(source, target, ARSIZE, sqrt);
	puts("Function sqrt():");
	for (i = 0; i < ARSIZE; i++)
		printf("source[%d] = %.2f\ttarget[%d] = %.2f\n", i, source[i], i, target[i]);

	transform(source, target, ARSIZE, times2);
	puts("Function times2()");
	for (i = 0; i < ARSIZE; i++)
		printf("source[%d] = %.2f\ttarget[%d] = %.2f\n", i, source[i], i, target[i]);
	
	transform(source, target, ARSIZE, div2);
	puts("Function div2()");
	for (i = 0; i < ARSIZE; i++)
		printf("source[%d] = %.2f\ttarget[%d] = %.2f\n", i, source[i], i, target[i]);

	return 0;
}

void transform(double src[], double trg[], const int arsize, double function(double))
{
	for(int i = 0; i < arsize; i++)
		trg[i] = function(src[i]);
}

double times2(double n)
{
	return n*2.0;
}

double div2(double n)
{
	return n/2;
}
