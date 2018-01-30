/* Daphne invests $100 at 10% simple interest. (That is, every year,
 the investment earns an interest equal to 10% of the original investment.)
 Deirdre invests $100 at 5% interest compounded anually. (That is, 
 interest is 5% of the current balance, including previous addition
 of interest.) Write a program that finds how many years it takes for the
 value of Deirdre's investment to exceed the value of Daphne's investment. 
 Also show the two values at that time.
*/
#include <stdio.h>
#define INVESTMENT 100.0
int main(void) {

	float daphne, dd;
	int years;

	for (daphne = dd = INVESTMENT, years = 0; daphne >= dd; years++) {

		daphne += INVESTMENT * 0.1;
		dd += dd * 0.05;
	}
	printf("It would take %d years for Deirdre's investment to exceed Daphne's investment.\n", years);
	printf("Daphne's investment:  %.2f\n", daphne);
	printf("Dierdre's investment: %.2f\n", dd);
	return 0;
}

