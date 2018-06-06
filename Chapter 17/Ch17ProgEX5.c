/* Write a program that lets you input a string. The program should push the
 * characters of the string onto a stack, one by one (see review question 5),
 * and then pop the characters from the stack and display them. This results
 * in displying the string in reverse order.
 */
#include <stdio.h>
#include "stack.h"
#define SLEN 100
int main(void)
{
	Item ch;
	Stack stack;

	InitializeStack(&stack);

	puts("Enter a string (enter EOF when done):");
	while ((ch = getchar()) != EOF)
		PushToStack(&ch, &stack);

	while (!StackIsEmpty(&stack))
	{
		PopFromStack(&ch, &stack);
		putchar(ch);
	}
	EmptyStack(&stack);
	puts("\nBye!");

	return 0;
}
