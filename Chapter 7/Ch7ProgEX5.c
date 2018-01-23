/* Using a switch statement, write a program that reads
 input up to #, replaces each period with an exclamation
 mark, replaces each exclamation mark initially present
 with two exclamation marks, and reports at the end the
 number of substitutions it has made.
*/
#include <stdio.h>
int main(void)
{
    char ch;
    int sub = 0;

    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
            case '.' : printf("!");
                       sub++;
                       break;
            case '!' : printf("!!");
                       sub++;
                       break;
            default  : printf("%c", ch);
        }
    }
    printf("\n# of substitutions: %d\n", sub);
    return 0;
}
