/* Write a program that reads input until end-of-file and echoes it to the display.
 * Have the program recognize and implement the following command-line arguments:
 *
 * 	-p	Print input as is
 * 	-u	Map input to all uppercase
 * 	-l	Map input to all lowercase
 *
 * Also, if there are no command-line arguments, let the program behave as if the 
 * -p argument had been used.
 */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char ch;
	bool is_p = false;
	bool is_u = false;
	bool is_l = false;

	if (argc == 1 || strcmp(argv[1], "-p") == 0)
		is_p = true;
	else if (strcmp(argv[1], "-u") == 0)
		is_u = true;
	else if (strcmp(argv[1], "-l") == 0)
		is_l = true;

	while ((ch = getchar()) != EOF)
	{
		if (is_u)
			ch = toupper(ch);
		else if (is_l)
			ch = tolower(ch);
		putchar(ch);
		
	}

	return 0;
}
