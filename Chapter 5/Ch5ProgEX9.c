/* Write a program that requests the user to enter a Fahrenheit
temperature. The program should read the temperature as a type
double number and pass it as an argument to a user-supplied
function called Temperatures(). This function should calculate
the Celsius equivalent and display all three temperatures with
a precision of two decimal places to the right of the decimal.
It should identify each value with the temperature scale it
represents. Here is the formula for converting Fahrenheit to Celsius:

Celsius = 5.0 / 9.0 * (Fahrenheit - 32.0)

The Kelvin scale, commonly used in science, is a scale in which
0 represents absolute zero, the lower limit to possible 
temperatures. Here is the formula for converting Celsius to Kelvin:

Kelvin = Celsius + 273.16

The Temperatures() function should use const to create symbolic
representations of the three constants that appear in the conversions.
The main() function should use a loop to allow the user to enter
temperatures repeatedly, stopping when a q or other nonnumeric value 
is entered. Use the fact that scanf() returns the number of items
read, so it will return 1 if it reads a number, but wont return 1
if the user enters q. The == operator tests for equality, so you
can use it to compare the return value of scanf() with 1.
*/
#include <stdio.h>
void Temperatures(double fahr);
int main(void) {

	double fahr;

	printf("Enter a fahrenheit temperature to convert to celsius: ");

	while (scanf("%lf", &fahr) == 1) {
		Temperatures(fahr);
		printf("Enter a fahrenheit temperature to convert to celsius"
				"(Non-number to quit): ");
	}
	return 0;
}
void Temperatures(double fahr) {

	const double FIVE = 5.0, NINE = 9.0, THIRTY2 = 32.0,
				 KELVIN_CONV = 273.16;

	double celsius = FIVE / NINE * (fahr - THIRTY2);

	double kelvin = celsius + KELVIN_CONV;

	printf("\nFahrenheit: %.2lf\nCelsius: %.2lf\nKelvin: %.2lf\n",
			 fahr, celsius, kelvin);
}