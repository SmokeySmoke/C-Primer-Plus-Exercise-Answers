/* A text file holds information about a softball team. each line has
 * data arranged as follows:
 *
 * 	4 Jessie Joybat 5 2 1 1
 *
 * The first item is the players number, conveniently in the range 0-18.
 * The second item is the player's first name, and the third is the players
 * last name. Each name is a single word. The next item is the player's 
 * official times at bat, followed by the number of hits, walks, and runs
 * batted in (RBIs). The file may contain data for more than one game,
 * so the same player may have more than one line of data, and there
 * may be data for other players between those lines. Write a program
 * that stores the data into an array of structures. The structure should have
 * members to represent the first and last names, the at bats, hits, walks,
 * and RBIs(runs batted in), and the batting average (to be calculated later).
 * You can use the player number as an array index. The program should read to
 * end-of-file, and it should keep cumulative totals for each player.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXPLAYERS 19
#define MAXNAML 20

struct player {
	struct {
		char first[MAXNAML];
		char last[MAXNAML];
	};
	int timesAtBat;
	int hits;
	int walks;
	int runsBatted;
	float avg;
};
struct player team[MAXPLAYERS];

int main(int argc, char * argv[])
{
	FILE * fp;
	int i, n;
	char ch;

	if (argc == 1)
	{
		printf("Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
	       if ((fp = fopen(argv[1], "r")) == NULL)
		{
			printf("Error opening %s!\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	       rewind(fp);

	       while ((ch = getc(fp)) != EOF)
	       {
		       ungetc(ch, fp);
		       fscanf(fp, "%d", &n);
		       fscanf(fp, "%s", team[n].first);
		       fscanf(fp, "%s", team[n].last);
		       fscanf(fp, "%d", &i);
		       team[n].timesAtBat += i;
		       fscanf(fp, "%d", &i);
		       team[n].hits += i;
		       fscanf(fp, "%d", &i);
		       team[n].walks += i;
		       fscanf(fp, "%d", &i);
		       team[n].runsBatted += i;
	       }
	       fclose(fp);
	       for (i = 0; i < MAXPLAYERS; i++)
	       {
		       if (team[i].first[0] == '\0')
			       continue;

		       team[i].avg = (float) team[i].hits / (float) team[i].timesAtBat;
		       printf("\n#%d - %s %s\n"
		  	      "AtBats:\t%d\n"
			      "Hits:\t%d\n"
			      "Walks:\t%d\n"
			      "RBIs:\t%d\n"
			      "Batting average:\t%.3f\n\n", i, team[i].first, team[i].last,
			      				  team[i].timesAtBat,
							  team[i].hits,
							  team[i].walks,
							  team[i].runsBatted,
							  team[i].avg);
	       }
	}
	puts("Done!");

	return 0;
}
