/* Suppose list.h (Listing 17.3) uses the following definition of a list:
 *
 * 	#define MAXSIZE 100
 * 	typedef struct list
 * 	{
 * 		Item entries[MAXSIZE];	// array of items
 * 		int items;		// number of items in list
 * 	} List;
 *
 * Rewrite the list.c (Listing 17.5) functions to fit this definition and test the resulting
 * code with the films3.c (Listing 17.4) program.
 */
/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include "Ch17ProgEX3.h"

/* interface functions
 * set the list to empty */
void InitializeList(List * plist)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		plist->entries[i].title[0] = '\0';
		plist->entries[i].rating = 0;
	}
	plist->items = 0;
}

/* returns true if list is empty */
bool ListIsEmpty(const List * plist)
{
	if (plist->items == 0)
		return true;
	else
		return false;
}

/* returns true if list is full */
bool ListIsFull(const List * plist)
{
	if (plist->items == MAXSIZE)
		return true;
	else
		return false;
}

/* returns number of items in list */
unsigned int ListItemCount(const List * plist)
{
	return plist->items;
}

/* adds item to end of the list */
bool AddItem(Item item, List * plist)
{
	if (ListIsFull(plist))
		return false;		// quit function if list is full;
	
	plist->entries[plist->items] = item;
	plist->items++;
	return true;
}

/* visit each item in list and execute function pointed to by pfun */
void Traverse (const List * plist, void (* pfun)(Item item) )
{
	for (int i = 0; i < plist->items; i++)
		(*pfun)(plist->entries[i]);	// apply function to each item
}

/* Empty list */
void EmptyTheList(List * plist)
{
	InitializeList(plist);
}
