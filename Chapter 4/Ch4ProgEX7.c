/* Write a program that sets a type double variable to 1.0/3.0 and a type
 float variable to 1.0/3.0. Display each result three times - once showing
 four digits to the right of the decimal, once showing 12 digits to the
 right of the decimal, and once showing 16 digits to the right of the 
 decimal. Also have the program include float.h and display the values of
 FLT_DIG and DBL_DIG. Are the displayed values of 1.0/3.0 consistent with
 these values?
*/

#include <stdio.h>
#include <float.h>

int main(void) {

	double doublethird = 1.0/3.0;
	float floatthird = 1.0/3.0;

	printf("Float:\n");
	printf("%.4f %.12f %.16f\n",
		floatthird, floatthird, floatthird);
	
	printf("Value of FLT_DIG: %.16f\n", sizeof(FLT_DIG));

	printf("Double:\n");
	printf("%.4lf %.12lf %.16lf\n",
		doublethird, doublethird, doublethird);

	printf("Value of DBL_DIG: %.16lf\n", sizeof(DBL_DIG));

	return 0;
}
/* The displayed values of 1.0/3.0 is consistent with float and FLT_DIG
and with double and DBL_DIG */
