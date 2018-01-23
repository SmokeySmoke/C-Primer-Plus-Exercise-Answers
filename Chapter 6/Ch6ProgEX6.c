/* Write a program that prints a table with each line giving
 an integer, its square, and its cube. Ask the user to input
 the lower and upper limits for the table. Use a for loop.
*/
#include <stdio.h>
int main(void) {

    int lower, upper, line;

    printf("Enter lower and upper integer limits of table: ");

    for (scanf("%d %d", &lower, &upper), printf("int squared cubed\n");
            lower <= upper; lower++)
        printf("%2d%6d%7d\n", lower, lower * lower, lower * lower * lower); 
    return 0;
}
