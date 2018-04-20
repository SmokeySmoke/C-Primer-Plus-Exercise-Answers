/* Redo Review question 5, but make the argument the spelled-out name of the month
 * instead of the month number. (Don't forget about strcmp().) Test the function
 * in a simple program
 *
 * 	REVIEW QUESTION 5:
 * 		Write a function that, when given the month number, returns the total days in the year
 *	up to and including that month. Assume that the structure template of question 3 and
 *	an appropriate array of such structures are declared externally.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MOINYEAR 12
#define MAXNAMEL 10
int months2days(char *);

struct month {
	char name[MAXNAMEL];
	char abbrev[4];
	int days;
	int monumb;
};

struct month months[MOINYEAR] =
{
	{"January", "jan", 31, 1},	{"February", "feb", 28, 2},
	{"March", "mar", 31, 3},	{"April", "apr", 30, 4},
	{"May", "may", 31, 5},		{"June", "jun", 30, 6},
	{"July", "jul", 31, 7},		{"August", "aug", 31, 8},
	{"September", "sep", 30, 9},	{"October", "oct", 31, 10},
	{"November", "nov", 30, 11},	{"December", "dec", 31, 12}
};

int main(void)
{
	char input[MAXNAMEL];
	int sum;

	puts("Type a months name (q to quit):");
	while (scanf("%s", input) && input[0] != 'q')
	{
		if ((sum = months2days(input)) == 0)
			continue;
		else
			printf("%d days up to and including %s.\n", sum, input);

		puts("Enter another name of a month (q to quit):");
	}
	puts("Done!");

	return 0;
}

int months2days(char * month)
{
	int sum = 0;
	int i, j;

	if (islower(month[0]))
			month[0] = toupper(month[0]);

	for (i = 0; i < MOINYEAR; i++)
		if (strcmp(month, months[i].name) == 0)
			break;

	if (i == MOINYEAR)
		puts("Invalid input. Try again:");
	else
		for (j = 0; j <= i; j++)
			sum += months[j].days;

	return sum;
}
