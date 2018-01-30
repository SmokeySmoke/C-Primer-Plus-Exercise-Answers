/* Write a program that requests your height in inches and
 your name, and then displays the information in
 the following form:
Dabney, you are 6.208 feet tall

 Use type float, and use / for division. If you prefer,
 request the height in centimeters and display it in meters. 
*/
#include <stdio.h>

int main(void) {

	float height;
	char name[15];

	printf("What is your height in inches?\n");	// prompt user for height
	scanf("%f", &height);

	printf("What is your name?\n");			// prompt user for name
	scanf("%s", name);	

	printf("%s, you are %.3f feet tall.\n", name, height / 12); // display name and height in feet

	return 0;
}
