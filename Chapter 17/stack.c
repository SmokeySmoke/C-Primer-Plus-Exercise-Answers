/* stack.c -- implementation for stack.h */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAXSTACK 100

void InitializeStack(Stack * ps)
{
	ps->top = NULL;
	ps->items = 0;
}

bool StackIsEmpty(Stack * ps)
{
	return ps->items == 0 ? true : false;
}

bool StackIsFull(Stack * ps)
{
	return ps->items == MAXSTACK ? true : false;
}

unsigned ItemsInStack(Stack * ps)
{
	return ps->items;
}

bool PushToStack(Item * pi, Stack * ps)
{
	Node * new_node;

	if (StackIsFull(ps))
	{
		puts("Stack is full!");
		return false;		// early return
	}
	
	new_node = (Node *) malloc(sizeof(Node));
	if (new_node == NULL)
	{
		puts("Error allocating memory!");
		exit(EXIT_FAILURE);
	}
/* new node creation success! */
	new_node->item = *pi;
	if (ps->items == 0)		// if there are no items in stack
		new_node->prev = NULL;	//	set previous item to NULL
	else				// otherwise, previous item is the current top item
		new_node->prev = ps->top;
	ps->top = new_node;
	ps->items++;			// increment stack item count

	return true;
}

bool PopFromStack(Item * pi, Stack * ps)
{
	Node * temp;

	if (StackIsEmpty(ps))
	{
		puts("Stack is empty!");
		return false;		// early return
	}

	*pi = ps->top->item;	// store popped item in pi
	temp = ps->top;		// store address of popped items memory
	ps->top = ps->top->prev;// top is now the previous item in stack
	free(temp);		// free popped items memory
	ps->items--;		// decrement stack item count

	return true;
}

void EmptyStack(Stack * ps)
{
	while (!StackIsEmpty(ps))
		PopFromStack(NULL, ps);
}		
