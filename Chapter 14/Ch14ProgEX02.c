/* Write a program that prompts the user to enter the day, month, and year. The
 * month can be a month number, a month name, or a month abbreviation. The program
 * then should return the total number of days in the year up through the given day.
 * (Do take leap years into account.
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MOINYEAR 12
#define MAXNAMEL 10
int getmonth(void);
int months2days(char *);
void flush(void);

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
	int sum, day, month, year;

	puts("Enter the year, month, and day:\n");
	printf("Year: ");
	while (scanf("%d", &year) == 0)
	{
		puts("Please choose a positive year.");
		flush();
	}

	printf("Month: ");
	month = getmonth();

	sum = months2days(months[month-2].name);

	if (year % 4 == 0)
		months[1].days++;
	
	printf("Day: ");
	while (scanf("%d", &day) == 0 || (day < 1 || day > months[month-1].days))
		printf("There is no such day as %s %d %d; choose a day between 1 and %d.\n",
			       	months[month-1].name, day, year, months[month-1].days);
	flush();

	if (month > 2 && year % 4 == 0)
		sum += 1;

	printf("%d days from beginning of %d through %s %d\n", sum + day, year, months[month-1].name, day);
	puts("Done!");

	return 0;
}

int getmonth(void)
{
	char input[MAXNAMEL];
	bool monthFound = false;
	int month, i;

	while (monthFound == false)
	{
		scanf("%s", input);
		if (!isdigit(input[0]))
		{
			for (i = 0; i < MOINYEAR; i++)
				if (strcmp(input, months[i].name) == 0 || strcmp(input, months[i].abbrev) == 0)
				{
					monthFound = true;
					month = months[i].monumb;
					break;
				}
		}
		else
		{
			for (i = strlen(input)-1; i >= 0; i--)
				ungetc(input[i], stdin);
			scanf("%d", &month);
			if (month > 0 && month < MOINYEAR)
				monthFound = true;
		}
		flush();
		if (monthFound == false)
			puts("Invalid input; try again");
	}
	return month;
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

void flush(void)
{
	while (getchar() != '\n')
		continue;
}
