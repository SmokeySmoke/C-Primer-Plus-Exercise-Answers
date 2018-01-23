/* Chuckie Lucky won a million dollars (after taxes), which he
 places in an account that earns 8% a year. On the last day of
 each year, Chuckie withdraws $100,000. Write a program that 
 finds out how many years it takes for Chuckie to empty his
 account.
*/
#include <stdio.h>
#define INTEREST 0.08
#define BANK 1000000.00
int main(void) {

	float chuckie;
	int years;

	for (chuckie = BANK, years = 0; chuckie > 0;chuckie -= 100000, years++)
		chuckie += chuckie * INTEREST;
	printf("It would take Chuckie %d years to empty his account.\n", years);
	return 0;
}

