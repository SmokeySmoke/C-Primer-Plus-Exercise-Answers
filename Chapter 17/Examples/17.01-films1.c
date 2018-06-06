// films1.c -- using an array of structures
#include <stdio.h>
#include <string.h>
#define TSIZE	45	// size of array to hold title
#define FMAX	5	// maximum number of film titles

struct film {
	char title[TSIZE];
	int rating;
};
char * s_gets(char * st, int n);
int main(void)
{
	struct film movies[FMAX];
	int i = 0;
	int j;

	puts("Enter first movie title:");
	while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL && 
			movies[i].title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d", &movies[i++].rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title (empty line to stop):");
	}
	if (i == 0)
		printf("No data entered.");
	else
		printf("Here is the movie list:\n");

	for (j = 0; j < i; j++)
		printf("Movie: %s  Rating: %d\n", movies[j].title,
				movies[j].rating);
	printf("Bye!\n");

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
