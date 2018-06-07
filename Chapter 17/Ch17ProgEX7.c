/* Write a program that opens and reads a text file and records how many
 * times each word occurs in the file. Use a binary search tree modified
 * to store both a word and the number of times it occurs. After the program
 * has read the file, it should offer a menu with three choices. The first
 * choice is to list all the words alond with the number of occurrences. The
 * second is to let you enter a word, with the program reporting how many times
 * the word has occured in the file. The third choice is to quit.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "BinTree.h"
void string2upper(char * string);
void prepname(char * name);
char * s_gets(char * st, int n);
void flush(void);

int main(int argc, char * argv[])
{
	char ch;
	char * temp;
	Tree tree;
	Item word;
	Node * pn;
	FILE * fp;

	if (argc != 2)
	{
		printf("Usage - %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open %s!\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	rewind(fp);

	InitializeTree(&tree);
	while (fscanf(fp, "%s", word.string) == 1)
	{
		prepname(word.string);
		AddItem(&word, &tree);
	}
	fclose(fp);
	
	do
	{
		puts("a) show all words\n"
		     "w) show specific word\n"
	     	     "q) quit");
		
		ch = getchar();
		flush();
		if (isupper(ch))
			ch = tolower(ch);
		putchar('\n');
		switch(ch)
		{
			case 'a' : puts("[Word] - [Count]");
				   ShowTree(&tree); break;
			case 'w' : puts("Enter word to search for:");
				   s_gets(word.string, SLEN);
				   string2upper(word.string);
				   ShowItem(&word, &tree);
			case 'q' : break;
			default : puts("Invalid; Try again.");
		}
		putchar('\n');
	} while (ch != 'q');
	EmptyTree(&tree);
	puts("Bye!");

	return 0;
}

void string2upper(char * string)
{
	for (int i = 0; i < SLEN; i++)
		if (islower(string[i]))
			string[i] = toupper(string[i]);
}

void prepname(char * name)
{
	int i, j;
	i = 0;
	while (name[i] != '\0')
		i++;
	while (i++ < SLEN)
		name[i] = '\0';

	for (i = 0; i < SLEN; i++)
		if (name[i] != '\'' && !isalpha(name[i]))
			for (j = i; j < SLEN-1; j++)
				name[j] = name[j+1];
	string2upper(name);
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

void flush(void)
{
	while (getchar() != '\n')
		continue;
}
