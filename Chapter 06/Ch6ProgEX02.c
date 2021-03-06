/* Use nested loops to produce the following pattern:
$
$$
$$$
$$$$
$$$$$
*/
#include <stdio.h>
#define ROWS 5     // number of rows to print
int main(void) {

    int row, i;
    
    for (row = 1; row <= ROWS; row++) {
        
        for (i = 1; i <= row; i++) {
            printf("$");
        }
        printf("\n");
    }
    return 0;
}
