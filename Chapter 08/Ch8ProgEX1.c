/* Devise a program that counts the number of characters in its
 input up to the end of file.
*/
#include <stdio.h>
int main (void)
{
    int n;

    while (getchar() != EOF)
        n++;
    printf("# of characters: %d\n", n);

    return 0;
}
