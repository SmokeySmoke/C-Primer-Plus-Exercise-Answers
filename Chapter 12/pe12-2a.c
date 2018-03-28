// pe12-2a.c -- compile with Ch12ProgEX2.c
#include <stdio.h>
#include <stdlib.h>
#include "pe12-2a.h"

static int mode = 0;
static double distance, fuelConsumed;

void set_mode(int modeVal)
{
	if (modeVal > 1 || modeVal < -1)
		printf("Invalid mode specified. Mode %d(%s) used.\n", mode, mode ==  0 ? "Metric" : "US");
	else
		mode = modeVal;

	return;
}

void get_info(void)
{
	if (mode != 0 && mode != 1)
	{
		puts("Programming error! mode != 0 or 1");
		exit(EXIT_FAILURE);
	}

	printf("Enter distance traveled in %s: ", mode == 0 ? "kilometers" : "miles");
	scanf("%lf", &distance);

	printf("Enter fuel consumed in %s: ", mode == 0 ? "liters" : "gallons");
	scanf("%lf", &fuelConsumed);

	return;
}

void show_info(void)
{
	printf("Fuel consumption is %.2lf %s per %s.\n", mode == 0 ? (fuelConsumed * 100) / distance : distance / fuelConsumed, 
			mode == 0 ? "liters" : "miles", mode == 0 ? "100 km" : "gallon");
	return;
}
