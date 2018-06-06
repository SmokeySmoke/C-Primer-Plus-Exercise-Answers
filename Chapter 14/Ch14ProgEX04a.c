/* Write a program that creats a structure template with two members
 * according to the following criteria:
 *
 * 	a) The first member is a social security number. The second
 * 	member is a structure with three members. Its first member 
 * 	contains a first name, its second member contains a middle 
 * 	name, and its final member contains a last name. Create and
 * 	initialize an array of 5 such structures. Have the program
 * 	print the data in this format:
 * 
 * 		Dribble, Flossie M. - 302039823
 *
 * 	Only the initial letter of the middle name is printed, and
 * 	a period is added. Neither the initial (of course) nor the
 * 	period should be printed if the middle name member is empty.
 * 	Write a function to do the printing; pass the structure array
 * 	to the function.
 */
#include <stdio.h>
#include <ctype.h>
#define MAXNAML 20
#define ARSIZE 5
struct employInfo {
	long ssn;
	struct {
		char first[MAXNAML];
		char middle[MAXNAML];
		char last[MAXNAML];
	};
};

void printInfo(struct employInfo []);

int main(void)
{
	struct employInfo employs[ARSIZE] = {
		{ 302039823, {"Flossie", "Marilyn", "Dribble"} },
		{ 725649345, {"Walter", "Alias", "White"} },
		{ 843234685, {"Abraham", "Yosef", "Lincoln"} },
		{ 234874873, {"tingle", "Kooloo", "Limpah"} },
		{ 856642352, {"Lost", "colonel", "marbles"} }
	};
	printInfo(employs);
	puts("Done!");

	return 0;
}

void printInfo(struct employInfo ar[])
{
	unsigned i, count = ARSIZE;

	for (i = 0; i < count; i++)	
	{
		if (islower(ar[i].first[0]))	// capitalize first letters of names
			ar[i].first[0] = toupper(ar[i].first[0]);
		if (islower(ar[i].middle[0]))
			ar[i].middle[0] = toupper(ar[i].middle[0]);
		if (islower(ar[i].last[0]))
			ar[i].last[0] = toupper(ar[i].last[0]);
	}
	for (i = 0; i < count; i++)
		printf("%s, %s %c.\t- %ld\n",
			       	ar[i].last, ar[i].first, ar[i].middle[0], ar[i].ssn);
	return;	
}
