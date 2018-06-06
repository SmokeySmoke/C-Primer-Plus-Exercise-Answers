/* Create a text file consisting of 20 rows of 30 integers. The integers should be in the range
 * 0-9 and be separated by spaces. The file is a digital representation of a picture, with the
 * values 0 through 9 representing increasing levels of darkness. Write a program that reads
 * the contents of the file into a 20-by-30 array of ints. In a crude approach toward converting
 * this digital representation to a picture, have the program use the values in this array to 
 * initialize a 20-by-31 array of chars, with a 0 value corresponding to a space character, a 1
 * value to the period character, and so on, with each larger number represented by a character
 * that occupies more space. For example, you might use # to represent 9. The last character
 * (the 31st) in each row should be a null character, making it an array of 20 strings. Have the
 * program display the resulting picture (that is, print the strings) and also store the result in
 * a text file. For example, suppose you start with this data:
 * 	
 *	0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
 *	0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
 *	0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
 *	0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
 *	0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
 *	0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
 *	0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
 *	5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
 *	8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
 *	9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9
 *	8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
 *	5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
 *	0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
 *	0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
 *	0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
 *	0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0
 *	0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
 *	0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
 *	0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
 *	0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
 *
 * For one particular choice of output characters, the ouput looks like this:
 * 	
 *	  #         *%##%*`           
 *	    #       *%##%**`          
 *	            *%.#%*~*`         
 *	    #       *%##%* ~*`        
 *	  #         *%##%*  ~*`       
 *	            *%#.%*   ~*`      
 *	            *%##%*    ~*`     
 *	*************%##%*************
 *	%%%%%%%%%%%%*%##%*%%%%%%%%%%%%
 *	#### #################:#######
 *	%%%%%%%%%%%%*%##%*%%%%%%%%%%%%
 *	*************%##%*************
 *	            *%##%*            
 *	            *%##%*    ==      
 *	    ``      *%##%*  *=  =*    
 *	    ::      *%##%* *=....=*   
 *	    ~~      *%##%*  *=  =*    
 *	    **      *%##%*    ==      
 *	            *%##%*            
 *	            *%##%*            
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

	char ch;
	char strar[20][31];
	int i, j;
	int ar[20][30];
	FILE * fp;
	i = j = 0;

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Could not open file \"%s\"!\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_SET);

	while (fscanf(fp, "%d", &ar[i][j]) == 1)
	{
		j++;
		if (j == 30)
		{
			i++;
			j = 0;
		}
	}
	fclose(fp);

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j <= 30; j++)
		{
			if (j == 30)
				strar[i][j] = '\0';
			else
				switch (ar[i][j])
				{
					case 0 : strar[i][j] = ' ';
						 break;
					case 1 : strar[i][j] = '.';
						 break;
					case 2 : strar[i][j] = '`';
						 break;
					case 3 : strar[i][j] = ':';
						 break;
					case 4 : strar[i][j] = '~';
						 break;
					case 5 : strar[i][j] = '*';
						 break;
					case 6 : strar[i][j] = '=';
						 break;
					case 7 : strar[i][j] = '$';
						 break;
					case 8 : strar[i][j] = '%';
						 break;
					case 9 : strar[i][j] = '#';
						 break;
					default: puts("Programming error!");
						 exit(EXIT_FAILURE);
				}
		}
	}

	for (i = 0; i < 20; i++)
		puts(strar[i]);

	if ((fp = fopen("EX12result.txt", "w")) == NULL)
	{
		puts("Could not write to file!");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 30; j++)
		{
			ch = strar[i][j];
			putc(ch, fp);
		}
		putc('\n', fp);
	}
	fclose(fp);
	puts("Done! Wrote result to \"EX12result.txt\"");

	return 0;
}
