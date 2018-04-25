/* Write a program that implements a menu by using an array of pointers to functions.
 * For instance, choosing a from the menu would activate the function pointed to by
 * the first element of the array.
 */
#include <stdio.h>

void fun1(void);
void fun2(void);
void fun3(void);

int main(void)
{
	char ch;
	int choice;
	void (*pf[3])(void) = { fun1, fun2, fun3 };

	puts("Choose a function:\n"
			"\ta) fun1\n"
			"\tb) fun2\n"
			"\tc) fun3");
	while ((ch = getchar()) != 'a' && ch != 'b' && ch != 'c')
	{
		puts("Invalid input; try again");
		while (getchar() != '\n')
			continue;
	}

	switch (ch)
	{
		case 'a' : choice = 0; break;
		case 'b' : choice = 1; break;
		case 'c' : choice = 2; break;
		default  : puts("Error!");
	}
	(*pf[choice])();

	return 0;
}

void fun1(void)
{
	puts("fun1()");
}

void fun2(void)
{
	puts("fun2()");
}

void fun3(void)
{
	puts("fun3()");
}
