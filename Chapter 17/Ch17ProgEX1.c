/* Modify Listing 17.2 so that it displays the movie list both in the original order and in
 * reverse order. One approach is to modify the linked-list definition so that the list can be
 * traversed in both directions. Another approach is to use recursion.
 */
#include <stdio.h>
#include <stdlib.h>	// has the malloc prototype
#include <string.h>	// has the strcpy prototype
#define TSIZE	45	// size of array to hold title

struct film {
	char title[TSIZE];
	int rating;
	struct film * next;	// points to next struct in list
	struct film * prev;	// points to previous structure in list
};
char * s_gets(char * st, int n);

int main(void)
{
	struct film * head = NULL;
	struct film * tail = NULL;
	struct film * prev, * current;
	char input[TSIZE];

	puts("Enter first movie title:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *) malloc(sizeof(struct film));
		if (head == NULL)	// first structure
		{
			head = current;
			head->prev = NULL;
		}
		else			// subsequent structures
		{
			prev->next = current;
			current->prev = prev;
		}
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title (empty line to stop):");
		prev = current;
	}
	tail = current;
/* Show list of structures */
	if (head == NULL)
		printf("No data entered.");
	else
		printf("Here is the movie list:\n");
	current = head;
	while (current != NULL)
	{
		printf("Movie: %s  Rating: %d\n",
			       	current->title, current->rating);
		current = current->next;
	}
	putchar('\n');
/* show list of structures in reverse order */
	if (head != NULL)
		puts("Reverse order:");
	current = tail;
	while (current != NULL)
	{
		printf("Movie: %s  Rating: %d\n",
				current->title, current->rating);
		current = current->prev;
	}

/* Program done, so free allocated memory */
	current = head;
	while (current != NULL)
	{
		free(current);
		current = current->next;
	}
	printf("\nBye!\n");

	return 0;
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
