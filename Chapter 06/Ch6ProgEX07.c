/* Write a program that reads a single word into a character array and
 then prints the word backward. Hint: Use strlen() (Chapter 4) to compute
 the index of the last character in the array.
*/
#include <stdio.h>
#include <string.h>
#define WORD "Success!"
int main(void) {

    char str[20] = WORD;
    int index;

    for (index = strlen(WORD); index >= 0; index--)
        printf("%c", str[index]);
    printf("\n");
    return 0;
}
