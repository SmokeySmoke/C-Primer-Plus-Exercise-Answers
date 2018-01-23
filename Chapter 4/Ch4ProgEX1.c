/* Write a program that asks for your first name,
your last name, and then prints the names in the format 
last, first */

#include <stdio.h>

int main(void) {

	char first[15], last[15];	// declare character arrays for 
					// first and last names
	printf("What is your first and last name?\n");	// prompt user for first and last names
	scanf("%s %s", first, last);

	printf("%s, %s\n", last, first);	//display last name then first name

	return 0;
}
