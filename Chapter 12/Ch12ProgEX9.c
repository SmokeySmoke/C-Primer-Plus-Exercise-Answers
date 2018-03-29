/* Write a program with the following behaviour. First, it asks you how many
 * words you wish to enter. Then it has you enter the words, and then it
 * displays the words. Use malloc() and the answer to the first question
 * (the number of words) to create a dynamic array of the corresponding
 * number of pointers-to-char. (Note that because each element in the array
 * is a pointer-to-char, the pointer used to store the return value of malloc()
 * should be a pointer-to-a-pointer-to-char.) When reading the string, the program
 * should read the word into a temporary array of char pointers. Then it should copy
 * the word from the temporary array into the allocated storage. Thus, you wind up
 * with an array of character pointers, each pointing to an object of the precise
 * size needed to store the particular word. A sample run could look like this:
 *
 * 	How many words do you wish to enter? 5
 * 	Enter 5 words now:
 * 	I enjoyed doing this exercise
 * 	Here are your words:
 * 	I
 * 	enjoyed
 * 	doing
 * 	this
 * 	exercise
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TEMPSIZE 50

int main(void)
{
	unsigned int nwords, i, j, lcount;
	char ch;
	char temp[TEMPSIZE];

	printf("How many words do you wish to enter? ");
	scanf("%u", &nwords);
	char ** ar = (char **) malloc(nwords * sizeof(char *));
	while (getchar() != '\n')
		continue;

	printf("Enter %u words now:\n", nwords);
	for (i = 0; i < nwords; i++)
	{
		lcount = 0;
		for (j = 0; j < TEMPSIZE; j++)
		{
			ch = getchar();

			if (isspace(ch))
			{
				temp[j] = '\0';
				break;
			}
			else
				temp[j] = ch;

			lcount++;
		}
		ar[i] = (char *) malloc(lcount * sizeof(char));

		for (j = 0; j < strlen(temp) + 1; j++)
			ar[i][j] = temp[j];
	}
	puts("Here are your words:");
	for (i = 0; i < nwords; i++)
		printf("%s\n", ar[i]);

	return 0;
}
