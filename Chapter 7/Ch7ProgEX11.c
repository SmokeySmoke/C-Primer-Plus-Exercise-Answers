/* The ABC Mail Order Grocery sells artichokes for $2.50 per pound,
 beets for $1.15 per pound, and carrots for $1.09 per pound. It gives
 a 5% discount for orders of $100 or more prior to adding shipping 
 costs. It charges $6.50 shipping and handling for any order of 5
 pounds or under, $14.00 shipping and handling for orders over 5
 pounds and under 20 pounds, and $14.00 plus $0.50 per pound for
 shipments of 20 pounds or more. Write a program that uses a switch
 statement in a loop such that a response of 'a' lets the user enter
 the pounds of artichokes desired, 'b' the pounds of beets, 'c' the
 pounds of carrots, and 'q' allows the user to exit the ordering 
 process. The program should keep track of cumulative totals. That is,
 if the user enters 4 pounds of beets and later enters 5 pounds of beets,
 the program should report 9 pounds of beets. The program then should
 compute the total charges, the discount, if any, the shipping charges,
 and the grand total. The program then should display all of the purchase
 information: the cost per pound, the pounds ordered, and the cost for that
 order for each vegetable, the total cost of the order, the discount 
 (if there is one), the shipping charge, and the grand total of all the
 charges.
*/
#include <stdio.h>
#include <stdbool.h>

#define ARTICHOKE  2.50  // prices per pound
#define BEET       1.15
#define CARROT     1.09
#define DISCOUNT   0.05  // % discount
#define DISCBREAK  100   // discount breakpoint in dollars
#define SHIP1      6.50  // first s/h rate
#define SHIP2      14.00 // seconds s/h rate
#define OVERSHIP   0.50  // s/h per pound over 
#define SHIPBREAK1 5     // first shipping breakpoint in pounds
#define SHIPBREAK2 20    // second shipping breakpoint in pounds

int main(void)
{
    printf("ABC Mail Order Grocery\n"
           "======================\n"
           "Artichoke --- $%.2f/lb\n"
           "Beet -------- $%.2f/lb\n"
           "Carrot ------ $%.2f/lb\n"
           "=============================\n",
            ARTICHOKE, BEET, CARROT);
    printf("%.0f%% discount on orders of $%d\n"
           "(before shipping) or more!\n"
           "========================================\n",
            DISCOUNT * 100, DISCBREAK);
    printf("Shipping and handling charges on orders:\n"
           "%d pounds and under ---------- $%.2f\n"
           "Over %d and under %d pounds -- $%.2f\n"
           "Over %d pounds -------------- $%.2f plus %.2f per pound over\n"
           "=============================================================\n",
            SHIPBREAK1, SHIP1,
            SHIPBREAK1, SHIPBREAK2, SHIP2,
            SHIPBREAK2, SHIP2, OVERSHIP);

    printf("\nEnter letter corresponding to item desired (q to quit):\n"
           "a) Artichoke\n"
           "b) Beet\n"
           "c) Carrot\n");

    bool isA, isB, isC, isDiscount;
    char choice;
    float pounds_A, pounds_B, pounds_C, total_pounds;
    float discount, shipping, subtotal, weight;
    int index;
    isA = isB = isC = isDiscount = false;
    pounds_A = pounds_B = pounds_C = total_pounds = 0;

    while ((choice = getchar()) != 'q')
    {
        switch (choice)
        {
            case 'a' : printf("\nHow many pounds of Artichoke "
                              "would you like to buy?\n");
                       scanf("%f", &weight);
                       pounds_A += weight;
                       isA = true;
                       getchar();
                       break;

            case 'b' : printf("\nHow many pounds of Beets "
                              "would you like to buy?\n");
                       scanf("%f", &weight);
                       pounds_B += weight;
                       isB = true;
                       getchar();
                       break;

            case 'c' : printf("\nHow many pounds of Carrots "
                              "would you like to buy?\n");
                       scanf("%f", &weight);
                       pounds_C += weight;
                       isC = true;
                       getchar();
                       break;

            default  : printf("\nInvalid choice;\n"
                              "a) Artichoke\n"
                              "b) Beet\n"
                              "c) Carrot\n");

                       getchar();
                       continue;
        }
        total_pounds += weight;
        printf("\nChoose another item (q to finalize order):\n");
    }
    subtotal = (pounds_A * ARTICHOKE) + (pounds_B * BEET) + (pounds_C * CARROT);
    if (subtotal >= DISCBREAK)
    {
        discount = subtotal * DISCOUNT;
        isDiscount = true;
    }
    if (total_pounds <= SHIPBREAK1)
        shipping = total_pounds * SHIP1;

    else if (total_pounds < SHIPBREAK2)
        shipping = total_pounds * SHIP2;

    else
        shipping = SHIP2 + ((total_pounds - SHIPBREAK2) * OVERSHIP);

    if (isA)
        printf("\n%.1f lb of Artichoke at $%.2f/lb\n = $%.2f\n",
                pounds_A, ARTICHOKE, pounds_A * ARTICHOKE);
    if (isB)
        printf("\n%.1f lb of Beets at $%.2f/lb\n = $%.2f\n",
                pounds_B, BEET, pounds_B * BEET);
    if (isC)
        printf("\n%.1f lb of Carrots at $%.2f/lb\n = $%.2f\n",
                pounds_C, CARROT, pounds_C * CARROT);
    printf("\nSubtotal     = $%.2f\n", subtotal);
    
    if (isDiscount)
        printf("Discount     = $%.2f\n", discount);

    printf("Total pounds = %.1f\n", total_pounds);

    printf("Shipping     = $%.2f\n", shipping);

    printf("Grand total  = $%.2f\n", (subtotal - discount) + shipping);
        
    return 0;
}
