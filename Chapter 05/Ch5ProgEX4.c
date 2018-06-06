/* Write a program that asks the user to enter a height in centimeters and
then displays the height in centimeters and in feet and inches. Fractional
centimeters and inches should be allowed, and the program should allow the
user to continue entering heights until a nonpositive value in entered. A
sample run should look like this:

Enter a height in centimeters: 182
182.0 cm = 5 feet, 11.7 inches
Enter a height in centimeters (<=0 to quit): 168.7
168.7 cm = 5 feet, 6.4 inches
Enter a height in centimeters (<=0 to quit): 0
bye

*/
#include <stdio.h>
#define CM_PER_IN 0.39370
#define IN_PER_FT 12
int main(void) {

	float centimeters, inches;
	int feet;

	printf("Enter a height in centimeters: ");
	scanf("%f", &centimeters);

	while (centimeters > 0) {

		inches = centimeters * CM_PER_IN;
		feet = inches / IN_PER_FT;
		inches = inches - (12 * feet);

		printf("%.1f cm = %d feet, %.1f inches\n",
				 centimeters, feet, inches);
		printf("Enter a height in centimeters (<=0 to quit): ");
		scanf("%f", &centimeters);
	}
	printf("bye\n");

	return 0;
}
