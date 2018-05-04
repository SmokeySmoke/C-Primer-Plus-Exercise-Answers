/* Design a bit-field structure that holds the following information:
 *
 * 	Font ID: A number in the range 0-255
 * 	Font Size: A number in the range 0-127
 * 	Aligment: A number in the range 0-2 represented the choices Left, Center, and Right
 * 	Bold: Off (0) or ON(1)
 * 	Italic: Off(0) or ON(1)
 * 	Underline: Off(0) or ON(1)
 *
 * Use this structure in a program that displays the font parameters and uses a looped
 * menu to let the user change parameters. For example, a sample run might look like this:
 *
 * 	ID	SIZE	ALIGNMENT	B	I	U
 * 	 1	  12	  left	       off     off     off
 *
 * 	f)change font	s)change size	a)change alignment
 * 	b)toggle bold	i)toggle italic	u)toggle underline
 * 	q)quit
 * 	s
 * 	Enter font size (0-127): 36
 *
 * 	ID	SIZE	ALIGNMENT	B	I	U
 * 	 1	  36	  left	       off     off     off
 *
 * 	f)change font	s)change size	a)change alignment
 * 	b)toggle bold	i)toggle italic	u)toggle underline
 * 	q)quit
 * 	a
 * 	Select alignment:
 * 	l)left	c)center	r)right
 * 	r
 *
 * 	ID	SIZE	ALIGNMENT	B	I	U
 * 	 1	  36	 right	       off     off     off
 *
 * 	f)change font	s)change size	a)change alignment
 * 	b)toggle bold	i)toggle italic	u)toggle underline
 * 	q)quit
 * 	i
 *
 * 	ID	SIZE	ALIGNMENT	B	I	U
 * 	 1	  36	 right	       off      on     off
 *
 * 	f)change font	s)change size	a)change alignment
 * 	b)toggle bold	i)toggle italic	u)toggle underline
 * 	q)quit
 * 	q
 * 	Bye!
 *
 * The program should use the & operator and suitable masks to ensure that the ID and size
 * entries are converted to the specified range.
 */
#include <stdio.h>
#include <ctype.h>
#define IDMASK 		0x000000ff // last 8 bits selected
#define SIZEMASK 	0x0000007f // last 7 bits selected


struct font_param {
	unsigned fontID 	: 8;
	unsigned fontSize	: 7;
	unsigned 		: 1;

	unsigned alignment	: 2;
	_Bool bold		: 1;
	_Bool italic		: 1;
	_Bool underline		: 1;
};

const char * alignstr[3] = {"left", "center", "right"};
enum {LEFT, CENTER, RIGHT};

unsigned changeFont(void);
unsigned resizeFont(void);
void changeAlign(struct font_param *);
void flush(void);

int main(void)
{
	char ch;
	struct font_param font = { 1, 12, LEFT, 0, 0, 0 };

	do
	{
		puts("\nID	SIZE	ALIGNMENT	B	I	U");
		printf("%2u%10u%10s%11u%8u%8u\n", font.fontID, font.fontSize, alignstr[font.alignment],
						font.bold, font.italic, font.underline);	
		puts("f)change font	s)change size	a)change alignment\n"
		     "b)toggle bold	i)toggle italic	u)toggle underline\n"
		     "q)quit");
		ch = getchar();
		flush();
		switch (ch)
		{
			case 'f' : font.fontID = changeFont(); break;			// change font
			case 's' : font.fontSize = resizeFont(); break;			// change size
			case 'a' : changeAlign(&font); break;				// change alignment
			case 'b' : font.bold = font.bold == 0 ? 1 : 0; break;		// toggle bold
			case 'i' : font.italic = font.italic == 0 ? 1 : 0; break;	// toggle italic
			case 'u' : font.underline = font.underline == 0 ? 1 : 0; break;	// toggle underline
			case 'q' : break;						// quit
			default  : puts("Invalid input; Try again.");
		}
	} while (ch != 'q');
	puts("Bye!");

	return 0;
}

unsigned changeFont(void)
{
	unsigned id;
	int status;

	printf("Enter font ID (0-255): ");
	while ((status = scanf("%u", &id) != 1))
	{
		puts("Invalid input; enter a number between 0 and 255");
		if (status == 0)
			flush();
	}
	flush();

	return id & IDMASK;
}

unsigned resizeFont(void)
{
	unsigned size;
	int status;

	printf("Enter font size (0-127): ");
	while ((status = scanf("%u", &size) != 1))
	{
		puts("Invalid input; enter a number between 0 and 127");
		if (status == 0)
			flush();
	}
	flush();
	return size & SIZEMASK;
}

void changeAlign(struct font_param * pf)
{
	char ch;
	_Bool isAlign = 0;

	puts("Select alignment:\n"
	     "l)left	c)center	r)right");
	while (isAlign == 0)
	{
		ch = getchar();
		flush();
		if (isupper(ch))
			ch = tolower(ch);
		switch (ch)
		{
			case 'l' : pf->alignment = LEFT; isAlign = 1; break;
			case 'c' : pf->alignment = CENTER; isAlign = 1; break;
			case 'r' : pf->alignment = RIGHT; isAlign = 1; break;
			default  : puts("Invalid input; try again.");
		}
	}
}
void flush(void)
{
	while (getchar() != '\n')
		continue;
}


