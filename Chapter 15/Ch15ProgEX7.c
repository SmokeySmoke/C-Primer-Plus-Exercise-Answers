/* Write a program with the same behaviour as described in exercise 6, but use
 * an unsigned long variable to hold the font information and use the bitwise
 * operators instead of bit members to manage the information.
 */
#include <stdio.h>
#include <ctype.h>
#define IDMASK 		0x1FE000  //    111111110000000000000
#define SIZEMASK 	0x1FC0    //            1111111000000
#define ALIGNMASK	0x18      //                    11000
#define BOLDMASK	0x4       //	                  100
#define ITALICMASK	0x2       //	                   10
#define UNDERLINEMASK	0x1       //                        1

#define ID_SHIFT	       13
#define SIZE_SHIFT		6
#define ALIGN_SHIFT		3
#define BOLD_SHIFT		2
#define ITALIC_SHIFT		1
#define UNDERLINE_SHIFT 	0

const char * alignstr[3] = {"left", "center", "right"};
enum {LEFT, CENTER, RIGHT};

void changeFont(unsigned long *);
void resizeFont(unsigned long *);
void changeAlign(unsigned long *);
void flush(void);

int main(void)
{
	char ch;
	unsigned long font = 0x0;
	font |= 1 << ID_SHIFT;
	font |= 12 << SIZE_SHIFT;

	do
	{
		puts("\nID	SIZE	ALIGNMENT	B	I	U");
		printf("%2lu%10lu%10s",
			       		 (font & IDMASK) >> ID_SHIFT, (font & SIZEMASK) >> SIZE_SHIFT,
			       					alignstr[(font & ALIGNMASK) >> ALIGN_SHIFT]);
		printf("%11s%8s%8s\n", (font & BOLDMASK) >> BOLD_SHIFT == 0? "off" : "on",
			         	 (font & ITALICMASK) >> ITALIC_SHIFT == 0? "off" : "on",
				       	 (font & UNDERLINEMASK) >> UNDERLINE_SHIFT == 0? "off" : "on");	
		puts("f)change font	s)change size	a)change alignment\n"
		     "b)toggle bold	i)toggle italic	u)toggle underline\n"
		     "q)quit");
		ch = getchar();
		flush();
		switch (ch)
		{
			case 'f' : changeFont(&font); break;				// change font
			case 's' : resizeFont(&font); break;				// change size
			case 'a' : changeAlign(&font); break;				// change alignment
			case 'b' : font ^= BOLDMASK; break;				// toggle bold
			case 'i' : font ^= ITALICMASK; break;				// toggle italic
			case 'u' : font ^= UNDERLINEMASK; break;			// toggle underline
			case 'q' : break;						// quit
			default  : puts("Invalid input; Try again.");
		}
	} while (ch != 'q');
	puts("Bye!");

	return 0;
}

void changeFont(unsigned long * ulp)
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

	id <<= ID_SHIFT;	// move id to proper bit position
	id &= IDMASK;		// convert to proper number of bits
	*ulp &= ~IDMASK;	// clear ID bit position in variable
	*ulp |= id;		// set proper bits in variable to id
}

void resizeFont(unsigned long * ulp)
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

	size <<= SIZE_SHIFT;
	size &= SIZEMASK;
	*ulp &= ~SIZEMASK;
	*ulp |= size;
}

void changeAlign(unsigned long * ulp)
{
	char ch;
	_Bool isAlign = 0;

	*ulp &= ~ALIGNMASK;	// clear alignment bits

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
			case 'l' : *ulp |= LEFT << ALIGN_SHIFT; isAlign = 1; break;
			case 'c' : *ulp |= CENTER << ALIGN_SHIFT; isAlign = 1; break;
			case 'r' : *ulp |= RIGHT << ALIGN_SHIFT; isAlign = 1; break;
			default  : puts("Invalid input; try again.");
		}
	}
}
void flush(void)
{
	while (getchar() != '\n')
		continue;
}


