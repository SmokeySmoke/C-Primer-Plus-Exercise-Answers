/* Modify Listing 16.17 so that it uses an array of struct names elements (as defined after
 * the listing) instead of an array of double. Use fewer elements, and initialize the array
 * explicitly to a suitable selection of names.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 40
#define NUM 5

struct names {
	char first[SLEN];
	char last[SLEN];
};

void showarray(const struct names [], int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
	struct names staff[NUM] = {
		{"Joseph", "Johnson"},
		{"Sammy", "Slinky"},
		{"Ronald", "McDonald"},
		{"Mango", "Monkey"},
		{"Chimmy", "Chongas"}
	};
	puts("Original list:");
	showarray(staff, NUM);
	qsort(staff, NUM, sizeof(struct names), mycomp);
	puts("\nSorted list:");
	showarray(staff, NUM);

	return 0;
}

void showarray(const struct names ar[], int n)
{
	int index;

	for (index = 0; index < n; index++)
		printf("staff[%d] - %s, %s\n", index+1, ar[index].last, ar[index].first);
}

// sort alphabetically
int mycomp(const void * p1, const void * p2)
{
	// need to use pointers to {struct names} to access members
	const struct names * a1 = (const struct names *) p1;
	const struct names * a2 = (const struct names *) p2;
	int status;

	if ((status = strcmp(a1->last, a2->last)) == 0)
		status = strcmp(a1->first, a2->first);

	return status;
}
