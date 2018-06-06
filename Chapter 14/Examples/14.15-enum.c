// enum.c -- uses enumerated values
#include <stdio.h>
#include <string.h>	// for strcmp(), strchr()
#include <stdbool.h>	// C99 feature
char * s_gets(char * st, int n);

enum spectrum {red, orange, yellow, green, blue, violet};
const char * colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};
#define LEN 30

int main(void)
{
	char choice[LEN];
	enum spectrum color;
	bool color_is_found = false;

	puts("Enter a color (empty line to quit):");
	while (s_gets(choice, LEN) != NULL && choice[0] != '\0')
	{
		for (color = red; color <= violet; color++)
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		if (color_is_found)
			switch(color)
			{
				case red    : puts("Roses are red.");
					      break;
				case orange : puts("Poppies are orange.");
					      break;
				case yellow : puts("Sunflowers are yellow.");
					      break;
				case green  : puts("Grass is green.");
					      break;
				case blue   : puts("Blueballs are blue.");
					      break;
				case violet : puts("Violets are violet.");
					      break;
			}
		else
			printf("I don't know about the color %s.\n", choice);
		color_is_found = false;
		puts("Next color, please (empty line to quit):");
	}
	puts("Goodbye!");

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
