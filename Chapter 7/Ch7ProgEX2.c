/* Write a program that reads input until encountering
 the #. Have the program print each input character and
 its ASCII decimal code. Print eight character-code pairs
 per line. Suggestion: Use a character count and the modulus
 operator(%) to print a newline character for every eight
 cycles of the loop.
*/
#include <stdio.h>
int main(void)
{
    char ch;
    int nc = 0;

    while ((ch = getchar()) != '#')
    {
        if (nc % 8 == 0)
        {
            printf("\n");
            nc = 0;
        }        
        printf("%c %d\t", ch, ch);
        nc++;
    }
    return 0;
}
