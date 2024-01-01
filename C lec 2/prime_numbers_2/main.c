#include <stdio.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Prime numbers up to %d: ", n);

    int i ;
    for (i = 2; i <= n; i++) {
        int isPrime = 1;
        int j;
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
