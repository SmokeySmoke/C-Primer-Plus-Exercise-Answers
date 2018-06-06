/* Modify listing 14.14 so that as each record is read from the file
 * and shown to you, you are given the chance to delete the record or
 * to modify its contents. If you delete the record, use the vacated
 * array position for the next record to be read. To allow changing
 * the existing contents, You'll need to use the "r+b" mode instead
 * of the "a+b" mode, and you'll have to pay more attention to
 * positioning the file pointer so that appended records don't
 * overwrite existing records. It's simplest to make all changes in
 * the data stored in program memory and then write the final set of
 * information to the file. One approach to keeping track is to add
 * a member to the book structure that indicates whether it is to be 
 * deleted.
 */
// booksave.c -- saves structure contents in a file
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXTITL	40
#define MAXAUTL 40
#define MAXBKS	100		// maximum number of books
char * s_gets(char * st, int n);
void flush(void);

struct book {			// set up book template
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	bool del;
};

int main(void)
{
	char ch;
	struct book library[MAXBKS];		// array of book structures
	int count = 0;
	int index, filecount, i, j;
	FILE * pbooks;
	int size = sizeof (struct book);

	if ((pbooks = fopen("book.dat", "r+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}

	rewind(pbooks);		// go to start of file
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("Current contents of book.dat:\n");
		printf("%s by %s: $%.2f\n", library[count].title,
				library[count].author, library[count].value);

		printf("Delete contents of this book? (y or n): ");
		while ((ch = getchar()) != 'y' && ch != 'n')
		{
			puts("Please choose y for yes or n for no.");
			flush();
		}
		flush();
		if (ch == 'y')
			library[count].del = true;
		else
		{
			printf("Modify contents of this book? (y or n): ");
			while ((ch = getchar()) != 'y' && ch != 'n')
			{
				puts("Please choose y for yes or n for no.");
				flush();
			}
			flush();
			if (ch == 'y')
			{
				printf("Title: ");
				s_gets(library[count].title, MAXTITL);
				printf("Author: ");
				s_gets(library[count].author, MAXAUTL);
				printf("Value: ");
				while (scanf("%f", &library[count].value) == 0)
				{
					puts("Invalid input; enter a number.");
					flush();
				}
				flush();
			}
		}
		count++;
	}
	if (count == MAXBKS)
	{
		fputs("The book.dat file is full.", stderr);
		exit(2);
	}
	filecount = count;

	puts("Please add book titles.");
	puts("Press [enter] at the start of a line to stop.");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
			&& library[count].title[0] != '\0')
	{
		library[count].del = false;
		puts("Now enter the author.");
		s_gets(library[count].author, MAXAUTL);
		puts("Now enter the value.");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;		// clear input line
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}
	fclose(pbooks);
	if ((pbooks = fopen("book.dat", "w+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}
	rewind(pbooks);

	for (index = 0; index < count; index++)
		if (library[index].del == false)
		{
			printf("Here is the list of your books:\n");
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value); 
			fwrite(&library[index], size, 1, pbooks);
		}
	fclose(pbooks);

	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)	// i.e., ret_val != NULL
	{
		find = strchr(st, '\n');	// look for newline
		if (find)			// if the address is not NULL,
			*find = '\0';		// place a null character there
		else 
			while (getchar() != '\n')
				continue;	// dispose of rest of line
	}
	return ret_val;
}

void flush(void)
{
	while (getchar() != '\n')
		continue;
}
