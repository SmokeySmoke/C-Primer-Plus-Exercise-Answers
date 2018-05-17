/* Polar coordinates describe a vector in terms of magnitude and
 * the counterclockwise angle from the x-axis to the vector. Rectangular
 * coordinates describe the same vector in terms of x and y components. 
 * Write a program that reads the magnitude and angle (in degrees) if a
 * vector and then displays the x and y components. The relevant equations
 * are these:
 *
 * 	x = r cos A	y = r sin A
 *
 * To do the conversion, use a function that takes a structure containing the
 * rectangular coordinates (or use pointers to such structures, if you prefer).
 */
#include <stdio.h>
#include <math.h>

struct polar_coord {
	double magnitude, angle;
};

void show_polar_coord(struct polar_coord);

int main(void)
{
	struct polar_coord polar;

	puts("Enter magnitude and angle for the x and y coordinates (q to quit)");
	printf("Magnitude: ");
	do
	{
		if (scanf("%lf", &polar.magnitude) == 0)
			break;
		printf("Angle: ");
		if (scanf("%lf", &polar.angle) == 0)
			break;
		puts("x and y coordinates:");
		show_polar_coord(polar);
		puts("Enter the next magnitude and angle (q to quit)");
	} while (1);
	puts("Bye.");

	return 0;
}

void show_polar_coord(struct polar_coord polar)
{
	printf("x = %lf\n"
	       "y = %lf\n", polar.magnitude * (cos(polar.angle)),
	       		    polar.magnitude * (sin(polar.angle)));
}
