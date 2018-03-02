/* Modify exercise 8 so that it uses a function to return
 the value of the calculation.
*/
#include <stdio.h>
float diffDivProd(float n1, float n2);
int main(void) {

    float n1, n2;

    printf("Enter 2 floating-point numbers: ");
    
    while (scanf("%f %f", &n1, &n2)) {

        printf("%f\n", diffDivProd(n1, n2));
    }
    return 0;
}
float diffDivProd(float n1, float n2) {
    
    float n3;

    if (n1 > n2)
        n3 = (n1 - n2) / (n1 * n2);
    else
        n3 = (n2 - n1) / (n1 * n2);

    return n3;
}
