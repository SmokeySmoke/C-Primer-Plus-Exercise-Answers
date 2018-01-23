/* Write a program that reads input as a stream of characters
 until encountering EOF. Have it report the average number of
 letters per word. Don't count whitespace as being letters in 
 a word. Actually, punctuation shouldn't be counted either, but
 don't worry about that now. (If you do want to worry about it, 
 consider using the ispunct() function from the ctype.h family.
*/
#include <stdio.h>
#include <ctype.h>  // for ispunct(), isspace()
#include <stdbool.h>
int main (void)
{
    int ch, prev_ch, n_ch, n_w, sum;
    float average;
    bool inWord;
    n_ch = n_w  = sum = 0;

    while ((ch = getchar()) != EOF)
    {
        if (!isspace(ch) && !ispunct(ch))
        {
            n_ch++;
            inWord = true;
        } else if (isspace(ch))
            inWord = false;
        if (!inWord && !isspace(prev_ch))
        {
            n_w++;
            sum += n_ch;
            n_ch = 0;
        }
        prev_ch = ch;
    }
    average = (float) sum / n_w;
    printf("Average number of letters per word: %.1f\n", average);

    return 0;
}
