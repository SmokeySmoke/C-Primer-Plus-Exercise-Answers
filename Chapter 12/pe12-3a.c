// pe12-3a.c -- compile with Ch12ProgEX3.c
#include <stdio.h>
#include <stdlib.h>
#include "pe12-3a.h"

void set_mode(int * modeVal, int * prevModeVal)
{
	if (*modeVal > 1 || *modeVal < -1)
	{
		*modeVal = *prevModeVal;
		printf("Invalid mode specified. Mode %d(%s) used.\n", *modeVal, *modeVal ==  0 ? "Metric" : "US");
	}

	return;
}

void get_info(int * modeVal, double * distanceVal, double * fuelConsumedVal)
{
	if (*modeVal != 0 && *modeVal != 1)
	{
		puts("Programming error! mode != 0 or 1");
		exit(EXIT_FAILURE);
	}

	printf("Enter distance traveled in %s: ", *modeVal == 0 ? "kilometers" : "miles");
	scanf("%lf", distanceVal);

	printf("Enter fuel consumed in %s: ", *modeVal == 0 ? "liters" : "gallons");
	scanf("%lf", fuelConsumedVal);

	return;
}

void show_info(int * modeVal, double * distanceVal, double * fuelConsumedVal)
{
	printf("Fuel consumption is %.2lf %s per %s.\n", *modeVal == 0 ? (*fuelConsumedVal * 100) / *distanceVal : *distanceVal / *fuelConsumedVal, 
			*modeVal == 0 ? "liters" : "miles", *modeVal == 0 ? "100 km" : "gallon");
	return;
}
