/* Write a program that reads input as a stream of characters
 until encountering EOF. Have the program print each input character
 and its ASCII decimal value. Note that characters preceding the space
 character in the ASCII sequence are nonprinting characters. Treat them
 specially. If the nonprinting character is a newline or tab, print \n
 or \t, respectively. Otherwise, use control-character notation. For 
 instance, ASCII 1 is Ctrl+A, which can be displayed as ^A. Note that 
 the ASCII value for A is the value for Ctrl+A plus 64. A similar
 relation holds for the other nonprinting characters. Print 10 pairs
 per line, except start a fresh line each time a newline character is 
 encountered. (Note: The operating system may have special interpretations
 for some control characters and keep them from reaching the program.)
*/
#include <stdio.h>
int main (void)
{
    int ch, n_ch;

    while ((ch = getchar()) != EOF)
    {
        if (ch < ' ')           // if character is nonprinting character
            switch (ch)
            {
                case '\n' : printf("\\n: %d"     // print newline as \n;
                                   "\n", ch);    // start new line
                            n_ch = 0;            // reset number of characters on line
                            break;           
                case '\t' : printf("\\t: %d\t",  // print tab as \t
                                   ch);   
                            break;
                default   : printf("^%c\t",      // print others in
                                   ch + 64);     // control-character notation
            }
        else
            printf("%c: %d\t", ch, ch);          // otherwise, print character and ASCI decimal value
        n_ch++;                     // increment number of characters on line
        if (n_ch == 10)             // if number of characters on line is 10 
        {
            printf("\n");           // start new line
            n_ch = 0;               // reset number of characters on line
        }
    }

    return 0;
}
