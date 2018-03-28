/* Gasoline consumption commonly is computed in miles per gallon
 * in the U.S. and in liters per 100 kilometers in Europe. What 
 * follows is part of a program that asks the user to choose a
 * mode (metric or U.S.) and then gathers the data and computes
 * fuel consumption:
 */
 // pe12-1a.c
 // compile with pe12-2a.c
 #include <stdio.h>
 #include "pe12-2a.h"
 int main(void)
{
	int mode;

	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);
	while (mode >= 0)
	{
		set_mode(mode);
		get_info();
		show_info();
		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit): ");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}
