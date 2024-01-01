#include <stdio.h>
#include <stdlib.h>

int main()
{
    int degree;
    printf("Enter your degree between 0 and 100: ");
    scanf("%d", &degree);

    if (degree >= 90 && degree <= 100) {
        printf("your grad is Excellent\n");
    } else if (degree >= 80 && degree < 90) {
        printf("your grad is Very Good\n");
    } else if (degree >= 70 && degree < 80) {
        printf(" your grad is Good\n");
    } else if (degree >= 60 && degree < 70) {
        printf("your grad is Acceptable\n");
    } else if (degree >= 0 && degree < 60) {
        printf("You Failed\n");
    } else {
        printf("Invalid input. Please enter a degree between 0 and 100.\n");
    }

    return 0;
}
