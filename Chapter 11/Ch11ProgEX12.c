/* Write a program that reads input up to EOF and reports the number of words,
 * the number of uppercase letters, the number of lowercase letters, the number
 * of punctuation characters, and the number of digits. Use the ctype.h family
 * of functions.
 */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
	char input;
	bool inword = false;
	int nw, nup, nlow, npunc, ndig;
	nw = nup = nlow = npunc = ndig = 0;

	while ((input = getchar()) != EOF)
	{
		if (inword == true && isspace(input))
		{
			nw++;
			inword = false;
		} else
			inword = true;
		if (isupper(input))
			nup++;
		else if (islower(input))
			nlow++;
		else if (ispunct(input))
			npunc++;
		else if (isdigit(input))
			ndig++;
	}
	printf("# words = 	%d\n"
	       "# uppercase: 	%d\n"
	       "# lowercase:	%d\n"
	       "# punctuation:	%d\n"
	       "# digits:	%d\n",
	       nw, nup, nlow, npunc, ndig);

	return 0;
}
