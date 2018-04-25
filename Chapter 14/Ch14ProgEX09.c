/* Colossus Airlines (from exercise 8) acquires a second plane (same capacity) and expands its
 * service to four flights daily (Flights 102, 311, 444, and 519). Expand the program to handle
 * four flights. Have a top-level menu that offers a choice of flights and the option to quit.
 * Selecting a particular flight should then bring up a menu similar to that of exercise 8.
 * However, one new item should be added: confirming a seat assignment. Also, the quit choice
 * should be replaced with the choice of exiting to the top-level menu. Each display should 
 * indicate which flight is currently being handled. Also, the seat assignment display should
 * indicate the confirmation status.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAML 20
#define NSEATS  12
#define NFLIGHTS 4

struct seating {
	int id;
	bool assigned;
	struct {
		char lname[MAXNAML];
		char fname[MAXNAML];
	};
};

struct plane {
	int flightN;
	struct seating seat[NSEATS];
};

struct plane flight[NFLIGHTS] = {
	{102}, {311}, {444}, {519}
};

int getNempty(const struct seating []);
void showLempty(const struct seating []);
void showAlpha(const struct seating []);
void flush(void);

int main(void)
{
	struct plane temp[NFLIGHTS], *pflight;
	char ch;
	char fname[MAXNAML], lname[MAXNAML];
	int j, k, choice, i = 0;
	bool isfirst = true;
	FILE * fp;

	if ((fp = fopen("SeatInfo.dat", "r+b")) == NULL)
	{
		puts("ERROR: Could not open SeatInfo.dat");
		exit(EXIT_FAILURE);
	}
	rewind(fp);
	while (i < NFLIGHTS && fread(&temp[i], sizeof (struct plane), 1, fp) == 1)
	{
		if (i == 0)
			puts("Current contents of SeatInfo.dat:");
		printf("\nFlight # %d:\n", temp[i].flightN);
		for (j = 0; j < NSEATS; j++)
			if (temp[i].seat[j].assigned == true)
				printf("Seat #%d: %s %s\n", temp[i].seat[j].id,
					       	temp[i].seat[j].lname, temp[i].seat[j].fname);
		i++;
	}
	fclose(fp);
	putchar('\n');
	for (int k = 0; k < NFLIGHTS; k++)
		for (int j = 0; j < i; j++)
			if (temp[k].seat[j].assigned == true)
				flight[k].seat[temp[k].seat[j].id-1] = temp[k].seat[j];
	
	do
	{
		puts("Choose a flight (0 to quit):");
		for (k = 1; k <= NFLIGHTS; k++)
			printf("%d - Flight #%d\n", k, flight[k-1].flightN);
		while (scanf("%d", &choice) == 0 && (choice < 1 || choice > NFLIGHTS))
		{
			puts("invalid input; Try again.");
			flush();
		}
		flush();
		if (choice == 0)
			break;
		choice--;
		pflight = &flight[choice];
	
		do
		{	
			for (j = 0; j < NFLIGHTS; j++)
				for (i = 0; i < NSEATS; i++)
					flight[j].seat[i].id = i+1;
	
			puts("To choose a function, enter its letter label:\n"
			     "a) Show number of empty seats\n"
			     "b) Show list of empty seats\n"
			     "c) Show alphabetical list of seats\n"
			     "d) Assign a customer to a seat assignment\n"
			     "e) Delete a seat assignment\n"
			     "f) Flight selection");
	
			ch = getchar();
			flush();
			putchar('\n');
			if (ch == 'f')
				break;
	
			switch (ch)
			{
				case 'a' : printf("There are %d empty seats.\n", getNempty(pflight->seat)); break;
				case 'b' : showLempty(pflight->seat); break;
				case 'c' : showAlpha(pflight->seat);  break;
				case 'd' : puts("Enter your first and last names (0 to abort): ");
					   scanf("%s", fname);
					   if (fname[0] == '0')
						   break;
					   scanf("%s", lname);
					   for (i = 0; i < NSEATS; i++)
					   {
						if (pflight->seat[i].assigned == false)
						{
							printf("You will be assigned to seat #%d.\n", pflight->seat[i].id);
							strncpy(pflight->seat[i].fname, fname, MAXNAML-1);
							strncpy(pflight->seat[i].lname, lname, MAXNAML-1);
							pflight->seat[i].assigned = true;
							break;
						}
						if (i == NSEATS-1)
							puts("All seats are taken.");
					   }
					   flush();
					   break;
				case 'e' : showAlpha(pflight->seat);
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
					   pflight->seat[i].fname[0] = '\0';
					   pflight->seat[i].lname[0] = '\0';
					   flight->seat[i].assigned = false;
					   break;
				case 'f' : break;
				default  : puts("Invalid input! Try again."); break;	
			}
			isfirst = false;
			putchar('\n');
		} while (ch != 'f');
	} while (ch != 'q');

	if ((fp = fopen("SeatInfo.dat", "w+r")) == NULL)
	{
		puts("ERROR: Could not write to SeatInfo.dat");
		exit(EXIT_FAILURE);
	}
	rewind(fp);
	puts("Writing to SeatInfo.dat...");
	for (j = 0; j < NFLIGHTS; j++)
		fwrite(&flight[j], sizeof (struct plane), 1, fp);

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
