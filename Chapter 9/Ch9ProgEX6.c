/* Write and test a function that take the addresses of
 * three double variables as arguments and that moves the
 * value of the smallest value into the first variable,
 * the middle value to the second variable, and the largest
 * value into the third variable.
 */
#include <stdio.h>
void big_med_small(double *, double *, double *);

int main(void)
{
	double x = 100.5, y = 22.7, z = 155;

	big_med_small(&x,&y,&z);
	printf("x = %.2lf\ty = %.2lf\tz = %.2lf\n", x, y, z);

	return 0;
}

void big_med_small(double * px, double * py, double * pz)
{
	double big, med, small;

	if (*px > *py && *px > *pz)
	{
		big = *px;
		if (*py > *pz)
		{
			med = *py;
			small = *pz;
		} else
		{
			med = *pz;
			small = *py;
		}
	} else if (*py > *px && *py > *px)
	{
		big = *py;
		if (*px > *pz)
		{
			med = *px;
			small = *pz;
		} else
		{
			med = *pz;
			small = *px;
		}
	} else
	{
		big = *pz;
		if (*px > *py)
		{
			med = *px;
			small = *py;
		} else 
		{
			med = *py;
			small = *px;
		}
	}	

	*px = small;
	*py = med;
	*pz = big;

	return;
}
