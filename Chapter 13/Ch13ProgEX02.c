/* Write a file-copy program that takes the original filename and
 * the copy file from the command line. Use standard I/O and the
 * binary mode, if possible
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	long int fi_size;
	FILE *fi, *fo;

	putchar('\n');
	if (argc == 1 || argc == 2 || argc > 3)
	{
		printf("Usage: %s file-to-copy-from file-to-copy-into\n",
				argv[0]);
		exit(EXIT_FAILURE);
	} else
	{
		if ((fi = fopen(argv[1], "rb")) == NULL) 
		{
			printf("Error opening file \"%s\" for reading!\n"
			       "Exiting...", argv[1]);
			exit(EXIT_FAILURE);
		}
		if ((fo = fopen(argv[2], "wb")) == NULL)
		{
			printf("Error opening file \"%s\" for writing!\n"
			       "Exiting...", argv[2]);
			exit(EXIT_FAILURE);
		}
	}
	fseek(fi, 0L, SEEK_END);
	fi_size = ftell(fi);
	rewind(fi);

	char buf[fi_size];

	fread(buf, sizeof(char), fi_size, fi);		// read file into buffer
	if (ferror(fi) != 0)
	{
		printf("Error reading data from \"%s\"!\n"
		       "Exiting...\n", argv[1]);
		fclose(fi);
		fclose(fo);
		exit(EXIT_FAILURE);
	}
	printf("Successfully read data from \"%s\" into buffer!\n", argv[1]);
	fclose(fi);

	fwrite(buf, sizeof(char), fi_size, fo);		// write buffer to file
	if (ferror(fo) != 0)
	{
		printf("Error writing data to \"%s\"!\n"
		       "Exiting...\n", argv[2]);
		fclose(fo);
		exit(EXIT_FAILURE);
	}
	printf("Successfully wrote data from buffer into \"%s\"!\n", argv[2]);
	fclose(fo);

	puts("\nDone!");

	return 0;
}
