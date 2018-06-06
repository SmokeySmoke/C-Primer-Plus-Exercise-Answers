/* Modify assumption a) in exercise 7 so that the 
 program presents a menu of pay rates from which
 to choose. Use a switch to select the pay rate.
 The beginning of a run should look like this:

*****************************************************************
Enter the number corresponding to the desired pay rate or action:
1) $8.75/hr                         2) $9.33/hr
3) $10.00/hr                        4) $11.20/hr
5) quit
*****************************************************************

 If choices 1 through 4 are selected, the program should request 
 the hours worked. The program should recycle until 5 is entered.
 If something other than choices 1 through 5 is entered, the program
 should remind the user what the proper choices are and then recycle.
 Use #defined constants for the various earning rates and tax rates.

EX 7 -- Write a program that requests the hours worked
 in a week and then prints the gross pay, the taxes,
 and the net pay. Assume the following:

    a) Basic pay rate = $10.00/hr
    b) Overtime (in excess of 40 hours) = time and a half
    c) Tax rate: 15% of the first $300
       20% of the next $150
       25% of the rest

 Use #define constants, and don't worry if the example
 does not conform to current tax law. 
*/
#include <stdio.h>
#define EARNRATE1 8.75  // first pay rate
#define EARNRATE2 9.33  // second pay rate
#define EARNRATE3 10.00 // third pay rate
#define EARNRATE4 11.20 // fourth pay rate
#define HOURSBREAK 40   // Overtime breakpoint
#define OVERTIME 1.5    // Overtime rate
#define TAXRATE1 0.15   // tax rate for first $300
#define TAXRATE2 0.20   // tax rate for next $150
#define TAXRATE3 0.25   // tax rate after $450
#define BREAK1 300.00   // first breakpoint for taxrates
#define BREAK2 450.00   // second breakpont for taxrates
#define BASE1 (TAXRATE1 * BREAK1)
// cost for first $300
#define BASE2 (BASE1 + (TAXRATE2 * (BREAK2 - BREAK1)))
// cost for next $150
int main(void)
{
    unsigned short hours, pay_choice = 0;
    float pay_rate, gross_pay, tax, net_pay;


    while (pay_choice != 5)
    {
        printf("*****************************************************************\n"
               "Enter the number corresponding to the desired pay rate or action:\n"
               "1) $%.2f/hr                         2) $%.2f/hr\n"
               "3) $%.2f/hr                        4) $%.2f/hr\n"
               "5) quit\n"
               "*****************************************************************\n",
                EARNRATE1, EARNRATE2, EARNRATE3, EARNRATE4);

        scanf("%hu", &pay_choice);

        switch (pay_choice)
        {
            case 1 : pay_rate = EARNRATE1;
                     break;
            case 2 : pay_rate = EARNRATE2;
                     break;
            case 3 : pay_rate = EARNRATE3;
                     break;
            case 4 : pay_rate = EARNRATE4;
                     break;
            case 5 : continue;
            default: printf("Incorrect choice; choose a number from 1 to 5.\n");
                     continue;
        }
        printf("Enter the number of hours worked this week: "); // prompt for hours
        scanf("%hu", &hours);                                    // worked in a week
    
        if (hours <= HOURSBREAK)        // if hours are <= 40
            gross_pay = pay_rate * hours;      // calculate gross
        else                            // otherwise calculate gross with overtime
            gross_pay = pay_rate * ((hours - HOURSBREAK) * OVERTIME)
                         + (pay_rate * HOURSBREAK);
    
        if (gross_pay <= BREAK1)            // if gross <= first tax breakpoint
            tax = gross_pay * TAXRATE1;                 // calculate tax with first tax rate
        else if (gross_pay <= BREAK2)       // else if gross > first tax breakpoint
            tax = BASE1 + (TAXRATE2 * (gross_pay - BREAK1));// calculate tax with second tax rate
        else
            tax = BASE2 + (TAXRATE3 * (gross_pay - BREAK2));// calculate tax with third tax rate 
    
        printf("Gross pay - $%7.2f\nTax ------- $%7.2f\nNet Pay --- $%7.2f\n", // display gross, tax,
                  gross_pay, tax, gross_pay - tax);                         // and net pay
    }
        return 0;
}   
