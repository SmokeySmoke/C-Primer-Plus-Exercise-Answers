/* Write a program that asks the user to enter a number of miles traveled and
 the number of gallons of gasoline consumed. It should calculate then display
 the miles-per-gallon value, showing one place to the right of the decimal.
 Next, using the fact that one gallon is about 3.785 liters and one mile is
 1.609 kilometers, it should convert the mile-per-gallon value to liters-per-
 100-km value, the usual European way of expressing fuel consumption, and
 display the result, showing one place to the right of the decimal. Note
 that the U.S. scheme measures the distance traveled per amount of fuel
 (higher is better) whereas the European scheme measures the amount of
 fuel per distance (lower is better). Use symbolic constants (using const or
 #define) for the two conversion factors. */
#include <stdio.h>

float miAndGalToLtrsPer100km (float, float);
int main(void) {

	float miles, gallons;

	printf("Enter the number of miles traveled:\n");	// prompt user for miles traveled
	scanf("%f", &miles);

	printf("Enter the number of gallons of gasoline consumed:\n");	// prompt user for gallons of gas consumed
	scanf("%f", &gallons);

	printf("Miles-per-gallon: %.1f\n", miles / gallons);	// display miles-per-gallon

	printf("Litres-per-100km: %.1f\n", miAndGalToLtrsPer100km(miles, gallons)); // display litres-per-100km
	
	return 0;
}
float miAndGalToLtrsPer100km (float miles, float gallons) {

	const float litresInGallon = 3.785, kmInMile = 1.609;	// litres in gallon and km in mile constants
	
	float litresPer100km = ((gallons * litresInGallon) / (miles * kmInMile)) * 100; // calculate liters-per-100km

	return litresPer100km;
}
