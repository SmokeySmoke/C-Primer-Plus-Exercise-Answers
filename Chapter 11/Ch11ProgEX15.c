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
		ret_val = atoi(str);

	return ret_val;
}
