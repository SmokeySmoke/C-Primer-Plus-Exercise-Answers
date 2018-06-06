/* Revise the book-listing program in Listing 14.2 so that it prints the book
 * descriptions in the order entered, then alphabetized by title, and then in
 * order of increased value.
 */

#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);
#define MAXTITL	40
#define MAXAUTL 40
#define MAXBKS	100		// maximum number of books

struct book {			// set up book template
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
//void alpha(struct book[], int);

int main(void)
{
	struct book library[MAXBKS];		// array of book structures
	struct book temp;			// temp book structure
	int count = 0;
	int index, i;

	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
			&& library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;		// clear input line
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}

	if (count > 0)
	{
		printf("\nHere is the list of your books:\n");
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);

		puts("\nAlphabetical order:");
		for (index = 0; index < count; index++)
			for (i = index; i < count; i++)
				if (strncmp(library[index].title, library[i].title, MAXTITL) > 0)
				{
					temp = library[index];
					library[index] = library[i];
					library[i] = temp;
				}
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);

		puts("\nValue order:");
		for (index = 0; index < count; index++)
			for (i = index; i < count; i++)
				if (library[index].value > library[i].value)
				{
					temp = library[index];
					library[index] = library[i];
					library[i] = temp;
				}
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);
	}
	else
		printf("No books? Too bad.\n");

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
