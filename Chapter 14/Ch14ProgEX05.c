/* Write a program that fits the following recipe:
 *
 * 	a) Externally define a name structure template with
 * 	two members: a string to hold the first name and a
 * 	string to hold the last name.
 *
 * 	b) Externally define a student structure template with
 * 	three members: a name structure, a grade array to hold
 * 	three floating-point scores, and a variable to hold the
 * 	average of those three scores.
 *
 * 	c) Have the main() function declare an array of CSIZE 
 * 	(with CSIZE = 4) student structures and initialize the
 * 	name portions to names of your choice. Use functions to
 * 	perform the tasks described in parts d, e, f, and g.
 *
 * 	d) Interactively acquire scores for each student by 
 * 	prompting the user with a student name and a request
 * 	for scores. Place the scores in the grade array portion
 * 	of the appropriate structure. The required looping can be 
 * 	done in main() or in the function, as you prefer.
 *
 * 	e) Calculate the average score value for each structure and
 * 	assign it to the proper member.
 *
 * 	f) Print the information in each structure.
 *
 * 	g) Print the class average for each of the numeric structure members.
 */
#include <stdio.h>
#define MAXNAML 20
#define NSCORES 3
#define CSIZE 4

struct fullname {
	char first[MAXNAML];
	char last[MAXNAML];
};

struct student {
	struct fullname name;
	float score[NSCORES];
	float avg;
};

void getGrades(struct student *);
void getAvg(struct student *);
void showStud(const struct student *);
void showAvg(const struct student *, const int);
void flush(void);

int main(void)
{
	struct student studAR[CSIZE] = {
		{ {"James", "Cameron"}, {0}, 0 },
		{ {"Paulie", "Paulson"}, {0}, 0 },
		{ {"Niko", "Malkovitch"}, {0}, 0 },
		{ {"Hugh", "Mungus"}, {0}, 0 },
	};
	int i;

	for (i = 0; i < CSIZE; i++)
		getGrades(&studAR[i]);
	for (i = 0; i < CSIZE; i++)
		getAvg(&studAR[i]);
	for (i = 0; i < CSIZE; i++)
		showStud(&studAR[i]);

	showAvg(studAR, CSIZE);

	puts("\nDone!");

	return 0;
}

void getGrades(struct student * sp)
{
	printf("%s, Please enter your grades:\n", sp->name.first);
	for (int i = 0; i < NSCORES; i++)
		while (scanf("%f", &sp->score[i]) == 0)
		{
				puts("Invalid input; try again.");
				flush();
		}
}

void getAvg(struct student * sp)
{
	for (int i = 0; i < NSCORES; i++)
		sp->avg += sp->score[i];
	sp->avg /= NSCORES;
}

void showStud(const struct student * sp)
{
	printf("\n%s %s\n", sp->name.first, sp->name.last);
	printf("Grades: ");
	for (int i = 0; i < NSCORES; i++)
		printf("%.1f ", sp->score[i]);
	putchar('\n');
	printf("Average: %.1f\n", sp->avg);
}

void showAvg(const struct student * sp, const int size)
{
	float sum = 0;

	for (int i = 0; i < size; i++)
		sum += sp->avg;
	printf("\nClass average: %.1f\n", sum/size);
}

void flush(void)
{
	while (getchar() != '\n')
		continue;
}
