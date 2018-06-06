/* The ANSI library features a clock() function with this description:
 * 
 * 	#include <stdio.h>
 * 	clock_t clock(void);
 *
 * Here, clock_t is a type defined in time.h. The function returns the processor
 * time, which is given in some implementation-dependant units. (If the processor
 * time is unavailable or cannot be represented, the function returns a value of
 * -1.) However, CLOCKS_PER_SEC, also defined in time.h, is the number of processor
 * time units per second. Therefore, dividing the difference between two return values
 * of clock() by CLOCKS_PER_SEC gives you the number of seconds elapsed between the 
 * two calls. Typecasting the values to double before division enables you to get
 * fractions of a second. Write a function that takes a double argument representing
 * a desired time delay and then runs a loop until that amount of time has passed.
 * Write a simple program that tests the function.
 */
#include <stdio.h>
#include <time.h>
double delay(double);

int main(void)
{
	double delay_time;

	printf("Enter number of seconds to delay: ");
	while (scanf("%lf", &delay_time) == 0)
	{
		puts("Invalid input; try again.");
		while (getchar() != '\n')
			continue;
	}
	printf("Time delayed %.2lf seconds.\n", delay(delay_time));

	return 0;
}

double delay(double stop_time)
{
	double start_time = (double) clock();
	double time_passed = 0.0;

	while (time_passed < stop_time)
		time_passed = ((double) clock() - start_time) / CLOCKS_PER_SEC;

	return time_passed;
}
