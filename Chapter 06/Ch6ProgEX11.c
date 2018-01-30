/* Write a program that reads eight integers into an array
 and then prints them in reverse order.
*/
#include <stdio.h>
int main(void) {

    int index, i[8];

    for (index = 7; index >= 0; index--) {
        i[index] = index;
        printf("%d", i[index]);
    }
    printf("\n");

    return 0;
}

