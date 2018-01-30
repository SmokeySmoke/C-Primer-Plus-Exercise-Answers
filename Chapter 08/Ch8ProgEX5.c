/* Modify the guessing program of Listing 8.4 so that it
 uses a more intelligent guessing strategy. For example,
 have the program initially guess 50, and have it ask
 the user whether the guess is high, low, or correct.
 If, say, the guess is low, have the next guess be halfway
 between 50 and 100, that is, 75. If that guess is high,
 let the next guess be halfway between 75 and 50, and so on.
 Using this binary search strategy, the program quickly zeros
 in on the correct answer, at least if the user does not cheat.
*/
#include <stdio.h>
#define MIN 1
#define MAX 100
int main(void)
{
    int upper_limit = MAX;
    int lower_limit = MIN;
    int guess = 50;
	char response;

	printf("Pick an integer from %d to %d. I will try to guess it.\n",
            MIN, MAX);
    printf("Respond with a y if my guess is right, an h if my\n"
	       "guess is too high, and an l if my guess is too low.\n"
           "Uh...is your number %d?\n", guess);

	while ((response = getchar()) != 'y')		// get response, compare to y
	{
        switch (response)
        {
            case 'h' : upper_limit = guess;
                       guess -= ((upper_limit - lower_limit) + 1) / 2;
                       break;
            case 'l' : lower_limit = guess;
                       guess += ((upper_limit - lower_limit) + 1) / 2;
                       break;
            default  : printf("Sorry, I understand only y, h, or l.\n");
        }
        printf("Well, then, is it %d?\n", guess);

	    while (getchar() != '\n')
     		continue;				// skip rest of input line
	}
	printf("I knew I could do it!\n");

    return 0;
}

