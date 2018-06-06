/* The 1988 United States Federal Tax Schedule was the simplest
 in recent times. It had four categories, and each category had
 two rates. Here is a summary (dollar amounts are taxable income):

Category            Tax

Single              15% of first $17,850 plus 28% of excess
Head of Household   15% of first $23,900 plus 28% of excess
Married, Joint      15% of first $29,750 plus 28% of excess
Married, Seperate   15% of first $13,875 plus 28% of excess

 For example, a single wage earner with a taxable income of $20,000
 owes 0.15 x $17,850 + 0.28 x ($20,000-$17,850). Write a program that
 lets the user specify the tax category and the taxable income and
 that then calculates the tax. Use a loop so that the user can enter
 several tax cases.
*/
#include <stdio.h>
#define INITIALTAX    0.15    // initial tax rate
#define EXCESSTAX    0.28    // excess tax rate
#define SINGLEBREAK 17850   // single taxable income tax breakpoint
#define HEADBREAK   23900   // head of household taxable income tax breakpoint
#define MJOINTBREAK 29750   // married, joint taxable income tax breakpoint
#define MSEPBREAK   13875   // married, seperate taxable income tax breakpoint

/*#define UNDERBREAK INITIALTAX * income
// calculation if under breakpoint
*/

#define SINGLEBASE  INITIALTAX * SINGLEBREAK
// base for single earner in excess of breakpoint
#define HEADBASE    INITIALTAX * HEADBREAK
// base for head of household taxable income in excess of breakpoint
#define MJOINTBASE  INITIALTAX * MJOINTBREAK
// base for married, joint taxable income in excess of breakpoint
#define MSEPBASE    INITIALTAX * MSEPBREAK
// base for married, seperate taxable income in excess of breakpoint
int main(void)
{
    float income, tax;
    unsigned short choice;
    
    printf("****************************************************************\n"
           "Category            Tax\n\n"
           "1) Single              %.0f%% of first $%d plus %.0f%% of excess\n"
           "2) Head of Household   %.0f%% of first $%d plus %.0f%% of excess\n"
           "3) Married, Joint      %.0f%% of first $%d plus %.0f%% of excess\n"
           "4) Married, Seperate   %.0f%% of first $%d plus %.0f%% of excess\n"
           "****************************************************************\n",
            INITIALTAX * 100, SINGLEBREAK, EXCESSTAX * 100,
            INITIALTAX * 100, HEADBREAK,   EXCESSTAX * 100,
            INITIALTAX * 100, MJOINTBREAK, EXCESSTAX * 100,
            INITIALTAX * 100, MSEPBREAK,   EXCESSTAX * 100);

    printf("Enter a number corresponding with the category choice (5 to quit): ");
    scanf("%hu", &choice);
    while (choice != 5)
    {
        printf("Enter taxable income: ");
        scanf("%f", &income);

        switch (choice)
        {
            case 1 : if (income <= SINGLEBREAK)
                        tax =  INITIALTAX * income;
                     else
                        tax = SINGLEBASE + (EXCESSTAX * (income - SINGLEBREAK));
                     break;
            case 2 : if (income <= HEADBREAK)
                        tax =  INITIALTAX * income;
                     else
                        tax = HEADBASE + (EXCESSTAX * (income - HEADBREAK));
                     break;
            case 3 : if (income <= MJOINTBREAK)
                        tax =  INITIALTAX * income;
                     else
                        tax = MJOINTBASE + (EXCESSTAX * (income - MJOINTBREAK));
                     break;
            case 4 : if (income <= MSEPBREAK)
                        tax =  INITIALTAX * income;
                     else
                        tax = MSEPBASE + (EXCESSTAX * (income - MSEPBREAK));
                     break;
            case 5 : continue;
            default: printf("Incorrect choice; choose a number from 1 to 4 (5 to quit): ");
                     scanf("%hu", &choice);
                     continue;
        }
        printf("\nTax = $%.2f\n", tax);

        printf("\nEnter another category (1 to 4, 5 to quit): ");
        scanf("%hu", &choice);
    }

    
    return 0;
}
