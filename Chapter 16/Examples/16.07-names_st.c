// names_st.c -- define names_st functions
#include <stdio.h>
#include "16.06-names_st.h"	// include the header file

// function definitions
void get_names(names * pn)
{
	printf("Please enter your first name: ");
	s_gets(pn->first, SLEN);

	printf("Please enter your last name: ");
	s_gets(pn->last, SLEN);
}

void show_names(const names * pn)
{
	printf("%s %s", pn->first, pn->last);
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)	// i.e., ret_val != NULL
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else 	// must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
