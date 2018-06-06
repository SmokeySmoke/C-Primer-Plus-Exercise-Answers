/* stack.h -- interface for a stack */
#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

typedef char Item;

typedef struct node
{
	Item item;
	struct node * prev;
} Node;

typedef struct stack
{
	Node * top;	// pointer to top of stack
	unsigned items;	// items in stack
} Stack;

/* operation:		Initialize the stack to empty
 * preconditions:	ps points to a stack
 * postconditions:	stack is initialized to empty		*/
void InitializeStack(Stack * ps);

/* operation:		determine whether stack is empty
 * preconditions:	ps points to an initialized stack
 * postconditions:	returns True if stack is empty;
 * 			otherwise returns False			*/
bool StackIsEmpty(Stack * ps);

/* operation:		determine whether stack is full
 * preconditions:	ps points to an initialized stack
 * postconditions:	returns True if stack is full;
 * 			otherwise returns False			*/
bool StackIsFull(Stack * ps);

/* operation:		determine number of items in stack
 * preconditions:	ps points to an initialized stack
 * postconditions:	returns number of items in stack	*/
unsigned ItemsInStack(Stack * ps);

/* operation:		add item to top of stack
 * preconditions:	pi points to item to be added
 * 			ps points to an initialized stack
 * postconditions:	if possible, adds item to top of stack
 * 			and returns True; otherwise, returns 
 * 			False					*/
bool PushToStack(Item * pi, Stack * ps);

/* operation:		remove item from top of stack
 * preconditions:	pi points to location to hold
 * 			removed item
 * 			ps points to an initialized stack
 * postconditions:	if possible, removed item from top of 
 * 			stack, stored item in pi, and returns 
 * 			True; otherwise returns False		*/
bool PopFromStack(Item * pi, Stack * ps);

/* operation:		empty the stack
 * preconditions:	ps points to an initialized stack
 * postconditions:	stack is emptied and frees associated
 * 			memory					*/
void EmptyStack(Stack * ps);

#endif
