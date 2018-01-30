/* Write a program that reads integers until 0 is entered.
 After input terminates, the program should report the 
 total number of even integers (excluding the 0) entered,
 the average value of the even integers, the total number
 of odd integers entered, and the average value of the odd
 integers.
*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    int i, n_even, n_odd, e_total, o_total;
    n_even = n_odd = e_total = o_total = 0;

    scanf("%d", &i);
    while (i != 0) 
    {
        if ((pow(-1, i)) == 1)
        {
            ++n_even;
            e_total += i;
        } else {
            ++n_odd;
            o_total += i;
        }
        scanf("%d", &i);
    }
    printf("Even integers: %d Average value: %d\n",
             n_even, e_total / n_even);
    printf("Odd integers:  %d Average value: %d\n",
             n_odd, o_total / n_odd);
    return 0;
}
