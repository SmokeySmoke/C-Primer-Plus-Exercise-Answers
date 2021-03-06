/* Write a program that creates an array with 26 elements and stores the
 26 lowercase letters in it. Also have it show the array contents.
*/
#include <stdio.h>

int main(void) {

    char ch[26], letter;  // char array ch with 26 elements
    int index;

    for (index = 0, letter = 'a';
          letter <= 'z'; index++, letter++) { // assign letters a through z to the char array ch[]

        ch[index] = letter;         
        printf("%c ", ch[index]);
    }

    printf("\n");

    return 0;
}
    
