/* Use nested loops to produce the following pattern:
A
BC
DEF
GHIJ
KLMNO
PQRSTU
*/
#include <stdio.h>
int main(void) {

    int row, numlet;
    char letter = 'A';
    
    for (row = 1; row <= 6; row++) {    // six rows

        for (numlet = 1; numlet <= row; numlet++)
            printf("%c", letter++);

        printf("\n");
    }
    return 0;
}
