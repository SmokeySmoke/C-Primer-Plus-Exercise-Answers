/* Write a program that accepts a positive integer as input
 and then displays all the prime numbers smaller than or 
 equal to that number.
*/
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    unsigned limit, div, num;
    bool isPrime;

    printf("Enter a positive integer: ");
    scanf("%u", &limit);

    printf("Prime numbers up to %u:\n", limit);

    for (num = 2; num <= limit; num++)
    {
        for (isPrime = true, div = 2; (div * div) <= num; div++)
            if (num % div == 0)
                isPrime = false;
        if (isPrime)
            printf("%u ", num);
    }
    printf("\n");
    return 0;
}
