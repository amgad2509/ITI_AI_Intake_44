#include <stdio.h>
#include <stdlib.h>

void Factorial(int n);
int power(int base, int exponent);

int main()
{
    // for Factorial
    printf("**************** Factorial Task*************************\n");

    int n;
    printf("Enter a non-negative integer to Calculate Factorial: ");
    scanf("%d", &n);
    Factorial(n);


    printf("**************** Power Task*************************\n");
    ///for power Task
    int base;
    int exponent;
    printf("Enter the base: ");
    scanf("%d", &base);

    printf("Enter the power: ");
    scanf("%d", &exponent);

    int result = power(base, exponent);
    printf("%d^%d = %d\n", base, exponent, result);

    return 0;
}
void Factorial(int n)
{
    int factorial = 1;
    if (n < 0) {
        printf("Factorial is not defined for negative numbers\n");
    } else {
        int i;
        for (i = 1; i <= n; i++) {
            factorial *= i;
        }
        printf("Factorial of %d is %d\n", n, factorial);
    }
}
int power(int base, int exponent) {
    if (exponent < 0) {
        printf("Exponent should be a non-negative integer\n");
        return 0;
    }

    int result = 1;

    int i;
    for (i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}


