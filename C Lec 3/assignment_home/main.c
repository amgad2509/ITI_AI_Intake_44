#include <stdio.h>
#include <stdlib.h>
int main() {
    ///////////////////////FACTORIAL////////////////////////////////
    int n;
    int factorial = 1;

    printf("Enter Your Number : ");
    scanf("%d", &n);

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

