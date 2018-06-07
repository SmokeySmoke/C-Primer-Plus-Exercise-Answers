/* Modify the Pet Club program so that all pets with the
 * same name are stored in a list in the same node. When
 * the user chooses to find a pet, the program should
 * request the pet name and then list all pets (along with
 * their kinds) having that name.
 *
 * petclub.c -- use a binary search tree */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "17.10-tree.h"

char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char * st, int n);
bool searchname(const char * name, const Trnode * root);

int main(void)
{
	Tree pets;
	char choice;

	InitializeTree(&pets);
	while ((choice = menu()) != 'q')
	{
		switch (choice)
		{
			case 'a' : addpet(&pets);
			    break;
			case 'l' : showpets(&pets);
			    break;
			case 'f' : findpet(&pets);
			    break;
			case 'n' : printf("%d pets in club\n",
						   TreeItemCount(&pets));
			    break;
			case 'd' : droppet(&pets);
			    break;
			default  : puts("Switching error");
		}
	}
	DeleteAll(&pets);
	puts("Bye.");

	return 0;
}

char menu(void)
{
	int ch;

	puts("Nerfville Pet Club Membership Program");
	puts("Enter the letter corresponding to your choice:");
	puts("a) add a pet		l) show list of pets");
	puts("n) number of pets		f) find pets");
	puts("d) delete a pet		q) quit");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')	// discard rest of line
			continue;
		ch = tolower(ch);
		if (strchr("alfndq", ch) == NULL)
			puts("Please enter an a, l, f, n, d, or q:");
		else
			break;
	}
	if (ch == EOF)		// make EOF cause program to quit
		ch = 'q';

	return ch;
}

void addpet(Tree * pt)
{
	Item temp;

	if (TreeIsFull(pt))
		puts("No room in the club!");
	else
	{
		puts("Please enter name of pet:");
		s_gets(temp.petname, SLEN);
		puts("Please enter pet kind:");
		s_gets(temp.petkind, SLEN);
		uppercase(temp.petname);
		uppercase(temp.petkind);
		AddItem(&temp, pt);
	}
}

void showpets(const Tree * pt)
{
	if (TreeIsEmpty(pt))
		puts("No entries!");
	else
		Traverse(pt, printitem);
}

void printitem(Item item)
{
	printf("Pet: %-19s	Kind: %-19s\n", item.petname,
			item.petkind);
}

void findpet(const Tree * pt)
{
	char name[SLEN];
	bool found;

	if (TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;		// quit function if tree is empty
	}

	puts("Please enter name of pet you wish to find:");
	s_gets(name, SLEN);
	uppercase(name);
	
	found = searchname(name, pt->root);

	if (!found)
		printf("There is no member named %s.\n", name);
}

void droppet(Tree * pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;		// quit function if tree is empty
	}

	puts("Please enter name of pet you wish to delete:");
	s_gets(temp.petname, SLEN);
	puts("Please enter pet kind:");
	s_gets(temp.petkind, SLEN);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ", temp.petname, temp.petkind);
	if (DeleteItem(&temp, pt))
		printf("is dropped from the club.\n");
	else
		printf("is not a member.\n");
}

void uppercase(char * str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
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

bool searchname(const char * name, const Trnode * root)
{
	static bool retval = false;
	int compare;

	if (root == NULL)
		return retval;

	compare = strncmp(name, root->item.petname, SLEN);
	if (compare < 0)
		searchname(name, root->left);
	else if (compare > 0)
		searchname(name, root->right);
	else
	{
		retval = true;
		printf("%s the %s\n",
			       	root->item.petname, root->item.petkind);
		searchname(name, root->left);
		searchname(name, root->right);

		return retval;
	}
	return retval;
}

