/* Write a program that reads input up to # and
 reports the number of times that the sequence
 ei occurs.
*/
#include <stdio.h>
int main(void)
{
    char ch, prev_ch;
    int n_ei = 0;

    while ((ch = getchar()) != '#')
    {
        if (ch == 'i' && prev_ch == 'e')
            n_ei++;
        prev_ch = ch;
    }
    printf("# of ei occurences: %d\n", n_ei);

    return 0;
}
