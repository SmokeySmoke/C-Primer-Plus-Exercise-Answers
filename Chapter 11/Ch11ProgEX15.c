/* Use the character classification functions to prepare an implementation
 * of atoi(); have this version return the value of 0 if the input string
 * is not a pure number.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
int myatoi(char *);

int main(int argc, char * argv[])
{
	double n = atof(argv[1]);
	int p = myatoi(argv[2]);

	printf("%.2lf\n", pow(n, p));

	return 0;
}

int myatoi(char * str)
{
	bool ispure = true;
	int ret_val = 0;
	int i = 0;
	int multiplier = 1;
	char * pc = str;

	while (*pc && ispure == true)
	{
		if (!isdigit(*pc))
		{
			ispure = false;
			ret_val = 0;
			break;
		}
		pc++;
	}
	if (ispure == true)
	{
		pc = str;
		while (*pc)
		{
			switch(*pc)
			{
				case '0' : i = 0;
					   break;
				case '1' : i = 1;
					   break;
				case '2' : i = 2;
					   break;
			 	case '3' : i = 3;
					   break;
				case '4' : i = 4;
					   break;
				case '5' : i = 5;
					   break;
				case '6' : i = 6;
					   break;
				case '7' : i = 7;
					   break;
				case '8' : i = 8;
					   break;
				case '9' : i = 9;
					   break;
				default  : puts("Program error in myatoi() switch!");
			}
			i *= multiplier;
			ret_val += i;
			multiplier *= 10;
			pc++;
			
		}
	}

	return ret_val;
}
