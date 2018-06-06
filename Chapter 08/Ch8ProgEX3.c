/* Write a program that reads input as a stream of characters
 until encountering EOF. Have it report the number of uppercase
 letters, the number of lowercase letters, and the number of other
 characters in the input. You may assume that the numeric values
 for the lowercase letters are sequential and assume the same for
 uppercase. Or, more portably, you can use the appropriate classification
 functions from the ctype.h library.
*/
#include <stdio.h>
#include <ctype.h>  // for isupper(), islower()
int main (void)
{
    int ch, n_upper, n_lower, n_other;
    n_upper = n_lower = n_other = 0;

    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            n_upper++;
        else if (islower(ch))
            n_lower++;
        else
            n_other++;
    }
    printf("Uppercase: %d\n"
           "Lowercase: %d\n"
           "Other:     %d\n",
            n_upper, n_lower, n_other);

    return 0;
}
