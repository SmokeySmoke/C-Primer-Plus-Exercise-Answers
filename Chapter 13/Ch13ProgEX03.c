/* Write a file copy program that prompts the user to enter
 * the name of a text file to act as the source file and the
 * name of an output file. The program should use the toupper()
 * function from ctype.h to convert all text to uppercase as it's
 * written to the output file. Use standard I/O and the text mode.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SLEN 81

int main(void)
{
	char fs_name[SLEN], fo_name[SLEN], ch;
	long i, fs_size;
	FILE * fs, * fo;

	puts("Enter the filename of the source file to copy:");
	scanf("%s", fs_name);
	if ((fs = fopen(fs_name, "r")) == NULL)
	{
		printf("Could not open file \"%s\" for reading!\n"
		       "Exiting...\n", fs_name);
		exit(EXIT_FAILURE);
	}

	printf("Enter the filename to copy \"%s\" into:\n", fs_name);
	scanf("%s", fo_name);
	if ((fo = fopen(fo_name, "w")) == NULL)
	{
		printf("Could not open file \"%s\" for writing!\n"
		       "Exiting...\n", fo_name);
		exit(EXIT_FAILURE);
	}

	fseek(fs, 0L, SEEK_END);
	fs_size = ftell(fs);
	rewind(fs);

	for (i = 0; i < fs_size; i++)
	{
		ch = getc(fs);
		if (islower(ch))
			ch = toupper(ch);
		putc(ch, fo);
	}

	fclose(fs);
	fclose(fo);
	puts("Done!");

	return 0;
}
