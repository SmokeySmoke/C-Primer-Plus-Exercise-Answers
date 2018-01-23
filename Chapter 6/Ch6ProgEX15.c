/* Write a program that reads in a line of input and then prints the line
 in reverse order. You can store the input in an array of char; assume 
 that the line is no longer than 255 characters. Recall that you can use
 scanf() with the %c specifier to read a character at a time from input
 and that the newline character (\n) is generated when you press the enter
 key.
*/
#include <stdio.h>
#include <string.h>
int main(void) {

	char line[255], i;

	printf("Enter a line no longer than 255 characters:\n");

	for (i = 0; scanf("%c", &line[i]), line[i] != '\n'; i++);

	while (i >= 0) {
		printf("%c", line[i]);
		i--;
	}
	printf("\n");

	return 0;
}

