/* Modify the get_first() function of Listing 8.8 so that
 it returns the first non-whitespace character encountered.
 Test it in a simple program.
*/
#include <stdio.h>
#include <ctype.h>
char get_first(void);
int main(void)
{
    printf("%c\n", get_first());

    return 0;
}
char get_first(void)
{
    int ch;

    for (ch = getchar(); isspace(ch); ch = getchar())
        continue;

    return ch;
}
