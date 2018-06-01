/* films3.c -- using an ADT-style linked list
 * compile with list.c				*/
#include <stdio.h>
#include <stdlib.h>		// prototype for exit()
#include "Ch17ProgEX2.h"	// defines List, Item
void showmovies(Item item);
char * s_gets(char * st, int n);
int main(void)
{
	List movies;
	Item temp;

/* Initialize	*/
	InitializeList(&movies);
	if (ListIsFull(&movies))
	{
		fprintf(stderr, "No memory available! Bye!\n");
		exit(1);
	}

/* gather and store */
	puts("Enter first movie title:");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d", &temp.rating);
		while (getchar() != '\n')
			continue;
		if (AddItem(temp, &movies)==false)
		{
			fprintf(stderr, "Problem allocating memory\n");
			break;
		}
		if (ListIsFull(&movies))
		{
			puts("The list is now full.");
			break;
		}
		puts("Enter next movie title (empty line to stop):");
	}

/* display */
	if (ListIsEmpty(&movies))
		printf("No data entered.");
	else
	{
		printf("Here is the movie list:\n");
		Traverse(&movies, showmovies);
	}
	printf("You entered %d movies.\n", ListItemCount(&movies));

/* clean up */
	EmptyTheList(&movies);
	printf("Bye!\n");

	return 0;
}

void showmovies(Item item)
{
	printf("Movie: %s  Rating: %d\n", item.title,
			item.rating);
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)	// i.e., ret_val != NULL
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else 	// must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

