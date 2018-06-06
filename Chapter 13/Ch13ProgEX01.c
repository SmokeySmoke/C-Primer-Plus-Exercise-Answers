/* Modify Listing 13.1 so that it solicits the user to enter
 * the filename and reads the user's response instead of using
 * command-line arguments
 */

#include <stdio.h>
#include <stdlib.h>	// exit prototype
#define SLEN 81

int main(void)
{
	char fname[SLEN];
	int ch;		// place to store each character as read
	FILE *fp;	// "file pointer"
	unsigned long count = 0;

	puts("Enter the filename:");
	scanf("%s", fname);
	if ((fp = fopen(fname, "r")) == NULL)
	{
		printf("Can't open %s\n", fname);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);	// same as putchar(ch);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", fname, count);

	return 0;
}
