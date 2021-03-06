/* Write a program that reads characters from the standard input
 * to the end-of-file. For each character, have the program report
 * whether it is a letter. If it is a letter, also report its 
 * numerical location in the alphabet. For example, c and C would
 * both be letter 3. Incorporate a function that takes a character
 * as an argument and returns the numerical location if the character
 * is a letter and that returns -1 otherwise.
 */
#include <stdio.h>
#include <ctype.h>
int char_numLoc(char);

int main(void)
{
	char ch;

	while ((ch = getchar()) != EOF)
		printf("%c is number %d in the alphabet.\n",
			       	ch, char_numLoc(ch));

	return 0;
}

int char_numLoc(char ch)
{
	int n;

	if (isalpha(ch))
	{
		if (isupper(ch))
			n = ch - 64;
		else if (islower(ch))
			n = ch - 96;
	} else
		n = -1;

	return n;
}
