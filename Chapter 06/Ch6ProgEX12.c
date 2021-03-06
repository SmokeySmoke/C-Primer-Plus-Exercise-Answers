/* Consider these two infinite series:
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...

Write a program that evaluates running totals of these two series up to some 
 limit of number of terms. Hint -1 times itself an odd number of times is -1,
 and -1 times itself an even number of times is 1. Have the user enter the
 limit interactively; let a zero or negative value terminate input. Look at
 the running totals after 100 terms, 1000 terms, 10,000 terms. Does either 
 series appear to be converging to some value?
*/
#include <stdio.h>
#define NEGONE -1
int main(void) {

	int i, n, sign;
	float sum1, sum2;


	printf("Enter the limit for calculating these infinite series:\n"
		"a) 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...\n"
		"b) 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...\n");
	scanf("%d", &i);

	while (i > 0) {

		for (n = 2, sum1 = 1.0; n <= i; n++)
			sum1 += 1.0 / (float) n;
		printf("a) %f\n", sum1);

		for (n = 2, sum2 = 1.0, sign = 1; n <= i; sign *= -1, n++) {

			if (sign == 1)
				sum2 -= 1.0 / (float) n;
			else
				sum2 += 1.0 / (float) n;
		}
		printf("b) %f\nEnter another limit: ", sum2);		
		scanf("%d", &i);
	}
	return 0;
}

