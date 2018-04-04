/* Write a program that sequentially displays onscreen all the
 * files listed in the command line. Use argc to control a loop.
 */
#include <stdio.h>

int main(int argc, char * argv[])
{
	int i;
	FILE * fp;

	puts("\nCommand line arguments that are files:");
	for (i = 1; i <= argc; i++)
	{
		if ((fp = fopen(argv[i], "r")) == NULL)
			continue;
		printf("\t- ");
		puts(argv[i]);
		fclose(fp);
	}
	puts("\nDone!");

	return 0;
}
