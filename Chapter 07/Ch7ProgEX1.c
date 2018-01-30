/* Write a program that reads input until encountering
 the # character and then reports the number of spaces
 read, the number of newline characters read, and the
 number of all other characters read.
*/
#include <stdio.h>
int main(void)
{
    int ch, ns, nl, nc;
    ns = nl = nc = 0;

    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            ns++;
        else if (ch == '\n')
            nl++;
        else
            nc++;
    }
    printf("\n");
    printf("# of spaces:           %d\n", ns);
    printf("# of newlines:         %d\n", nl);
    printf("# of other characters: %d\n", nc);

    return 0;
}
