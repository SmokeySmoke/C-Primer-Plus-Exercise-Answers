/* Use nested loops to produce the following pattern:
F
FE
FED
FEDC
FEDCB
FEDCBA
*/
#include <stdio.h>
int main(void) {

    int row, numlet;
    char letter;
    
    for (row = 1; row <= 6; row++) {    // six rows

        for (letter = 'F', numlet = 1; numlet <= row; letter--, numlet++)
            printf("%c", letter);

        printf("\n");
    }
    return 0;
}
