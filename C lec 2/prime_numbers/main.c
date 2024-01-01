#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n;
    printf("Enter a number to check if is the prime or not : ");
        scanf("%d", &n);

    if (n <= 1) {
        printf("%d is not prime.\n", n);
    } else {
        int isPrime = 1;
        int i;
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            printf("%d is prime.\n", n);
        } else {
            printf("%d is not prime.\n", n);
        }
    }

    return 0;
}
