// vowels.c -- uses multiple labels
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;

	a_ct = e_ct = i_ct = o_ct = u_ct = 0;

	printf("Enter some text; enter # to quit.\n");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
			case 'a':
			case 'A': a_ct++;
					  break;

			case 'e':
			case 'E': e_ct++;
					  break;
			case 'i':
			case 'I': i_ct++;
					  break;
			case 'o':
			case 'O': o_ct++;
					  break;
			case 'u':
			case 'U': u_ct++;
					  break;
		}	// end of switch
	}		// while loop end
	printf("number of vowels: A\tE\tI\tO\tU\n");
	printf("                  %d\t%d\t%d\t%d\t%d\n",
			a_ct, e_ct, i_ct, o_ct, u_ct);

    return 0;
}
