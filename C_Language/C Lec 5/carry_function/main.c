#include <stdio.h>

void calc(int *a, int *b, int *sum, int *sub, int *mul);

int main()
{
    int num1, num2;
    printf("Enter two numbers:\n ");
    scanf("%d %d", &num1, &num2);
    int sum, sub,mul;


    calc(&num1, &num2, &sum, &sub, &mul);

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n",sub);
    printf("Product: %d\n", mul);

    return 0;
}
void calc(int *a, int *b, int *sum, int *sub, int *mul) {
    *sum = *a + *b;
    *sub = *a - *b;
    *mul = *a * *b;
}
