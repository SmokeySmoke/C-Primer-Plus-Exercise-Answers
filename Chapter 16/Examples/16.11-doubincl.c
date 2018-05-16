// doubincl.c -- include header twice
#include <stdio.h>
#include "16.10-names.h"
#include "16.10-names.h"	// accidental second inclusion

int main(void)
{
	names winner = {"Less", "Ismoor"};
	printf("The winner is %s %s.\n", winner.first,
		       	winner.last);
	return 0;
}
