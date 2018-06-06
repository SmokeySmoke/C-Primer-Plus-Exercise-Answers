/* Write a program that shows you a menu offering you the choice
 of addition, subtraction, multiplication, or division. After getting
 your choice, the program asks for two numbers, then performs the
 requested operation. The program should accept only the offered menu
 choices. It should use type float for the numbers and allow the user
 to try again if he or she fails to enter a number. In the case of 
 division, the program should prompt the user to enter a new value
 if 0 is entered as the value for the second number. A typical program 
 run should look like this:

Enter the operation of your choice:
a. add          s. subtract
m. multiply     d. divide
q. quit
a
Enter first number: 22.4
Enter second number: one
Please enter a number, such as 2.5, -1.78E8, or 3: 1
22.4 + 1 = 23.4
Enter the operation of your choice:
a. add          s. subtract
m. multiply     d. divide
q. quit
d
Enter first number: 18.4
Enter second number: 0
Enter a number other than 0: 0.2
18.4 / 0.2 = 92
Enter the operation of your choice:
a. add          s. subtract
m. multiply     d. divide
q. quit
q
Bye.
*/
#include <stdio.h>
void getmenu(void);
float getnum(void);
float checkZero(void);
void flushBuffer(void);
int main(void)
{
    char choice;
    float n1, n2, answer;

    for (getmenu(); (choice = getchar()) != 'q'; getmenu())
    {
        if (choice == 'd')
        {
            printf("Enter first number: ");         // prompt user for first number
            n1 = checkZero();
            printf("Enter second number: ");        // prompt user for second number
            n2 = checkZero();
            printf("%.1f / %.1f = %.1f\n", n1, n2, n1 / n2);
            getchar();
            continue;
        }

        printf("Enter first number: ");         // prompt user for first number
        n1 = getnum();
        
        printf("Enter second number: ");        // prompt user for second number
        n2 = getnum();
        
        switch (choice)
        {
            case 'a' : printf("%.1f + %.1f = %.1f\n", n1, n2, n1 + n2);
                       break;
            case 's' : printf("%.1f - %.1f = %.1f\n", n1, n2, n1 - n2);
                       break;
            case 'm' : printf("%.1f x %.1f = %.1f\n", n1, n2, n1 * n2);
                       break;
            default  : printf("Program error!\n");
                       break;
        }
        flushBuffer();
    }
    printf("Bye.\n");
    return 0;
}
void getmenu(void)
{
    printf("Enter the operation of your choice:\n"  // show menu of choices
           "a. add          s. subtract\n"
           "m. multiply     d. divide\n"
           "q. quit\n");
}
float getnum(void)
{
    float n;
    while (scanf("%f", &n) == 0)
    {
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
        flushBuffer();
    }

    return n;
}
float checkZero(void)
{
    float n;
    while ((n = getnum()) == 0)
        printf("Enter a number other than 0: ");

    return n;
}
void flushBuffer(void)
{
    while (getchar() != '\n')
            continue;
}
