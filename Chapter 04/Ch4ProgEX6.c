/* Write a program that requests the user's first name and then the users 
 last name. Have it print the entered names on one line and the number of
 letters in each name on the following line. Align each letter count with the end of the corresponding name, as in the following:

Melissa Honeybee
      7        8

 Next, have it print the same information, but with the counts aligned with
 the beginning of each name.

Melissa Honeybee
7       8
 */
#include <stdio.h>
#include <string.h>

int main(void) {

	char first[20], last[20];	

	printf("Enter your first and last names:\n");
	scanf("%s %s", first, last);

	printf("%s %s\n%*d %*d\n",
		first, last, 
		strlen(first), strlen(first),
		strlen(last), strlen(last));

	printf("%s %s\n%-*d %-*d\n",
		first, last, 
		strlen(first), strlen(first),
		strlen(last), strlen(last));

	return 0;
}
