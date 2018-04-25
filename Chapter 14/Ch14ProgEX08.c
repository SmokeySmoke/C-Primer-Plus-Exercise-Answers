/* The Colossus Airlines fleet consists of one plane with a seating
 * capacity of 12. It makes one flight daily. Write a seating reservation
 * program with the following features:
 *
 * 	a) The program uses an array of 12 structures. Each structure
 * 	should hold a seat identification number, a marker that indicates
 * 	whether the seat is assigned, the last name of the seat holder,
 * 	and the first name of the seat holder.
 *
 * 	b) The program displays the following menu:
 *
 * 		To choose a function, enter its letter label:
 * 		a) Show number of empty seats
 * 		b) Show list of empty seats
 * 		c) Show alphabetical list of seats
 * 		d) Assign a customer to a seat assignment
 * 	 	e) Delete a seat assignment
 * 	 	f) Quit
 *
 * 	 c) The program successfully executes the promises of its
 * 	 menu. Choices d) and e) require additional input, and each
 * 	 should enable the user to abort an entry.
 *
 * 	 d) After executing a particular function, The program shows
 * 	 the menu again, except for choice f).
 *
 * 	 e) Data is saved in a file between runs. When the program is 
 * 	 restarted, it first loads in the data, if any, from the file.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAML 20
#define NSEATS  12

struct seating {
	int id;
	bool assigned;
	struct {
		char lname[MAXNAML];
		char fname[MAXNAML];
	};
};

struct seating seat[NSEATS];

int getNempty(const struct seating []);
void showLempty(const struct seating []);
void showAlpha(const struct seating []);
void flush(void);

int main(void)
{
	struct seating temp[NSEATS];
	char ch;
	char fname[MAXNAML], lname[MAXNAML];
	int i = 0;
	bool isfirst = true;
	FILE * fp;

	if ((fp = fopen("SeatInfo.dat", "r+b")) == NULL)
	{
		puts("ERROR: Could not open SeatInfo.dat");
		exit(EXIT_FAILURE);
	}
	rewind(fp);
	while (i < NSEATS && fread(&temp[i], sizeof (struct seating), 1, fp) == 1)
	{
		if (i == 0)
			puts("Current contents of SeatInfo.dat:");
		printf("Seat #%d: %s %s\n", temp[i].id, temp[i].lname, temp[i].fname);
		i++;
	}
	fclose(fp);
	putchar('\n');
	for (int j = 0; j < i; j++)
		if (temp[j].assigned == true)
			seat[temp[j].id-1] = temp[j];
		
	
	do
	{	
		for (i = 0; i < NSEATS; i++)
			seat[i].id = i+1;

		puts("To choose a function, enter its letter label:\n"
		     "a) Show number of empty seats\n"
		     "b) Show list of empty seats\n"
		     "c) Show alphabetical list of seats\n"
		     "d) Assign a customer to a seat assignment\n"
		     "e) Delete a seat assignment");
		if (isfirst)
	   		puts("f) Quit");

		ch = getchar();
		flush();
		putchar('\n');

		switch (ch)
		{
			case 'a' : printf("There are %d empty seats.\n", getNempty(seat)); break;
			case 'b' : showLempty(seat); break;
			case 'c' : showAlpha(seat);  break;
			case 'd' : puts("Enter your first and last names (0 to abort): ");
				   scanf("%s", fname);
				   if (fname[0] == '0')
					   break;
				   scanf("%s", lname);
				   for (i = 0; i < NSEATS; i++)
				   {
					if (seat[i].assigned == false)
					{
						printf("You will be assigned to seat #%d.\n", seat[i].id);
						strncpy(seat[i].fname, fname, MAXNAML-1);
						strncpy(seat[i].lname, lname, MAXNAML-1);
						seat[i].assigned = true;
						break;
					}
					if (i == NSEATS-1)
						puts("All seats are taken.");
				   }
				   break;
			case 'e' : showAlpha(seat);
				   puts("Which seat would you like to vacate? (0 to abort)");
				   while (scanf("%d", &i) == 0)
				   {
					   puts("Invalid input; Try again.");
					   flush();
				   }
				   flush();
				   if (i == 0)
					   break;
				   i--;
				   seat[i].fname[0] = '\0';
				   seat[i].lname[0] = '\0';
				   seat[i].assigned = false;
				   break;
			case 'f' : break;
			default  : puts("Invalid input! Try again."); break;	
		}
		isfirst = false;
		putchar('\n');
	} while (ch != 'f');
	if ((fp = fopen("SeatInfo.dat", "w+r")) == NULL)
	{
		puts("ERROR: Could not write to SeatInfo.dat");
		exit(EXIT_FAILURE);
	}
	rewind(fp);
	puts("Writing to SeatInfo.dat...");
	i = 0;
	while(i < NSEATS-getNempty(seat))
	{
		if (seat[i].assigned == true)
		{
			fwrite(&seat[i], sizeof (struct seating), 1, fp);
			i++;
		}
	}
	fclose(fp);

	puts("Done!");

	return 0;
}

int getNempty(const struct seating sar[])
{
	int count = 0;
	for (int i = 0; i < NSEATS; i++)
		if (sar[i].assigned == false)
			count++;
	return count;

}
void showLempty(const struct seating sar[])
{
	puts("\nEmpty seats:");
	for (int i = 0; i < NSEATS; i++)
		if (sar[i].assigned == false)
			printf("Seat #%d\n", sar[i].id);
	putchar('\n');
}
void showAlpha(const struct seating ar[])
{
	int i, j;
	struct seating sar[NSEATS];
	struct seating temp;
	for (i = 0; i < NSEATS; i++)
		sar[i] = ar[i];

	puts("Alphabetical list of seats:");
	for (i = 0; i < NSEATS; i++)
		for (j = i+1; j < NSEATS; j++)
			if (strcmp(sar[i].lname, sar[j].lname) > 0)
			{
				temp = sar[i];
				sar[i] = sar[j];
				sar[j] = temp;
			}
	for (i = 0; i < NSEATS; i++)
		if (sar[i].assigned == true)
			printf("%s, %s: Seat #%d\n",
					sar[i].lname, sar[i].fname, sar[i].id);
}

void flush(void)
{
	while (getchar() != '\n')
		continue;
}
