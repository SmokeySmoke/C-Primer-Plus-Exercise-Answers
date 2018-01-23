/* Write a program that requests two floating-point numbers and
 prints the value of their difference divided by their product.
 Have the program loop through pairs of input values until the
 user enters nonnumeric input.
*/
#include <stdio.h>
int main(void) {

    float n1, n2;

    printf("Enter 2 floating-point numbers: ");
    
    while (scanf("%f %f", &n1, &n2)) {

        if (n1 > n2)
            printf("%f\n", (n1 - n2) / (n1 * n2));
        else
            printf("%f\n", (n2 - n1) / (n1 * n2));
    }
    return 0;
}
