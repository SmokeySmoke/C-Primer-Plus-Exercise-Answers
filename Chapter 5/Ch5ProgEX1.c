/* Write a program that converts time in minutes to time in hours and minutes.
 Use #define or const to creat a symbolic constant for 60. Use a while loop to
 allow the user to enter values repeatedly and terminate the loop if a value 
 for the time of 0 or less is entered */
#include <stdio.h>
#define MIN_IN_HOUR 60
int main(void) {

	int timeM, hours, mins;

	printf("Convert time in minutes to hours and minutes!\n");
	printf("Enter time in minutes (<=0 to quit):\n");
	scanf("%d", &timeM);

	while (timeM > 0) {

		hours = timeM / MIN_IN_HOUR;
		mins = timeM % MIN_IN_HOUR;
		printf("%d minutes is %d hours and %d minutes.\n",
			 timeM, hours, mins);
		printf("Enter time in minutes (<=0 to quit:)\n");
		scanf("%d", &timeM);
	}
	return 0;
}
