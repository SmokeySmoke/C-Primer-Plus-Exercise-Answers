/* Write a program that requests your first name and does the following with it:
a) prints it enclosed in double quotation marks
b) prints it in a field 20 characters wide, with the whole field
	in quotes and the name at the right end of the field 
c) prints it at the left end of a field 20 characters wide,
	with the whole field enclosed in quotes
d) prints it in a field three characters wider than the name */

#include <stdio.h>
#include <string.h>	// for strlen()

int main(void) {

	char name[15];

	printf("What is your first name?\n");	// prompt user for name
	scanf("%s", name);

	printf("\"%s\"\n", name);	// a)
	printf("\"%20s\"\n", name);	// b)
	printf("\"%-20s\"\n", name);	// c)
	printf("\"%*s\"\n", (strlen(name) + 3), name);	// d)

	return 0;
}
