/* Have a program request the user to enter an uppercase letter.
 Use nested loops to produce the following pattern:
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA

 The pattern should extend to the character entered. For example,
 the preceding pattern would result from an input value of E.
 Hint: Use an outer loop to handle the rows. Use three inner loops
 in a row, one to handle the spaces, one for printing letters in
 ascending order, and one for printing letters in descending order.
*/
#include <stdio.h>
int main(void) {

    int row, spaces;
    char i, ascLetter, descLetter;

    printf("Enter an uppercase letter: ");
    scanf("%c", &i);
    
    for (row = 1; row <= (i - 64); row++) {    // As many rows as input letter

        for (spaces = (i - 64) - row; spaces > 0; spaces--)
            printf(" ");
        for (ascLetter = 'A'; (ascLetter - 64) < row; ascLetter++)
            printf("%c", ascLetter);
        for (descLetter = ascLetter; descLetter >= 'A'; descLetter--)
            printf("%c", descLetter);
        printf("\n");
    }
    return 0;
}
