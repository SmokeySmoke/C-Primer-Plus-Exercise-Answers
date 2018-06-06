/* BinTree.h -- interface for binary search tree */
#ifndef _BINTREE_H_
#define _BINTREE_H_
#include <stdbool.h>
#define SLEN 25
typedef struct item
{
	char string[SLEN];
} Item;

typedef struct node
{
	Item item;
	unsigned count;
	struct node * left;
	struct node * right;
} Node;

typedef struct tree
{
	Node * root;
	unsigned size;
} Tree;

/* operations:		Initialize tree to empty
 * preconditions:	pt points to a tree
 * postconditions:	tree is initialized to empty		*/
void InitializeTree(Tree * pt);

/* operations: 		Determine whether tree is empty
 * preconditions:	pt points to an initialized tree
 * postconditions:	returns True if tree is empty;
 * 			otherwise returns False			*/
bool TreeIsEmpty(Tree * pt);

/* operations:		Find number of items in tree
 * preconditions:	pt points to an initialized tree
 * postconditions:	returns number of items in tree		*/
unsigned TreeItemCount(Tree * pt);

/* operations:		Add an item to a tree
 * preconditions:	pi points to the item to add to the tree
 * 			pt points to an initialized tree
 * postconditions:	if possible, adds item to the tree and
 * 			returns True; if item already exists, 
 * 			increments item count and returns True;
 * 			otherwise returns False			*/
bool AddItem(Item * pi, Tree * pt);

/* opertions:		Display item in tree
 * preconditions:	pi points to item to display
 * 			pt points to an initialized tree
 * postconditions:	if possible, displays the item in the
 * 			tree; otherwise displays error		*/
void ShowItem(Item * pi, Tree * pt);

/* operations:		display tree contents
 * preconditions:	pt points to an initialized tree
 * postconditions:	Displays contents of tree in order	*/
void ShowTree(Tree * pt);

/* operations:		empty binary tree
 * preconditions:	pt points to an initialized tree
 * postconditions:	empties tree and frees allocated memory	*/
void EmptyTree(Tree * pt);

#endif
