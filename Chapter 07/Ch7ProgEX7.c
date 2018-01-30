/* Write a program that requests the hours worked
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
#define BASIC 10.00     // basic pay rate per hour
#define HOURSBREAK 40   // Overtime breakpoint
#define OVERTIME 1.5    // Overtime rate
#define RATE1 0.15      // tax rate for first $300
#define RATE2 0.20      // tax rate for next $150
#define RATE3 0.25      // tax rate after $450
#define BREAK1 300.00   // first breakpoint for taxrates
#define BREAK2 450.00   // second breakpont for taxrates
#define BASE1 (RATE1 * BREAK1)
// cost for first $300
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1)))
// cost for next $150
int main(void)
{
    unsigned short hours;
    float gross_pay, tax, net_pay;

    printf("Enter the number of hours worked this week: "); // prompt for hours
    scanf("%hu", &hours);                                    // worked in a week

    if (hours <= HOURSBREAK)        // if hours are <= 40
        gross_pay = BASIC * hours;      // calculate gross
    else                            // otherwise calculate gross with overtime
        gross_pay = BASIC * ((hours - HOURSBREAK) * OVERTIME)
                     + (BASIC * HOURSBREAK);

    if (gross_pay <= BREAK1)            // if gross <= first tax breakpoint
        tax = gross_pay * RATE1;                 // calculate tax with first tax rate
    else if (gross_pay <= BREAK2)       // else if gross > first tax breakpoint
        tax = BASE1 + (RATE2 * (gross_pay - BREAK1));// calculate tax with second tax rate
    else
        tax = BASE2 + (RATE3 * (gross_pay - BREAK2));// calculate tax with third tax rate 

    printf("Gross pay - $%7.2f\nTax ------- $%7.2f\nNet Pay --- $%7.2f\n", // display gross, tax,
              gross_pay, tax, gross_pay - tax);                         // and net pay

    return 0;
}
