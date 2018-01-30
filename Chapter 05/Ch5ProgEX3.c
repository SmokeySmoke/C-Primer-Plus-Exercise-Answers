/* Write a program that asks the user to enter the number of days and
converts that value to weeks and days. For example, it would convert
18 days to 2 weeks, 4 days. Display the results in the following format:

18 days are 2 weeks, 4 days.

Use a while loop to allow the user to repeatedly enter day values;
terminate the loop when the user enters a nonpositive value, such
as 0 or -20 */
#include <stdio.h>
int main(void) {

	int i, weeks, days;

	printf("Convert number of days to weeks and days!\n");
	printf("Enter the number of days (<=0 to quit):\n");
	scanf("%d", &i);

	while (i > 0) {

		weeks = i / 7;
		days = i % 7;

		printf("%d days are %d weeks, %d days.\n", i, weeks, days);
		printf("Enter the number of days (<=0 to quit):\n");
		scanf("%d", &i);
	}
	printf("Done!\n");

	return 0;
}
