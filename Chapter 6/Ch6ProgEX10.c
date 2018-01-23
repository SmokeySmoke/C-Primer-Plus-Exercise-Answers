/* Write a program that requests lower and upper integer limits,
 calculates the sum of all the integer squares from the square
 of the lower limit to the square of the upper limit, and displays
 the answer. The program should then continue to prompt for limits
 and display answers until the user enters an upper limit that is
 equal to or less than the lower limit. A sample run should look
 something like this:

Enter lower and upper integer limits: 5 9
The sums of the squares from 25 to 81 is 255
Enter the next set of limits: 3 25
The sums of the squares from 9 to 625 is 5520
Enter the next set of limits: 5 5
Done
*/
#include <stdio.h>
int main(void) {

    int lower, upper, allsq, diff;

    printf("Enter lower and upper integer limits: ");
    scanf("%d %d", &lower, &upper);

    while (upper > lower) {

        for (diff = lower, allsq = 0; diff <= upper; diff++)
            allsq += diff * diff;

        printf("The sums of the squares from %d ", lower *= lower);
        printf("to %d ", upper *= upper);
        printf("is %d\n", allsq);

        printf("Enter the next set of limits: ");
        scanf("%d %d", &lower, &upper);
    }
    printf("Done\n");
    return 0;
}

