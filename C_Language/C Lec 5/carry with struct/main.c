#include <stdio.h>

struct Calculation {
    int num1;
    int num2;
    int addition;
    int subtraction;
    int multiplication;
    int division;
};

struct Calculation carry(struct Calculation data) {
    data.addition = data.num1 + data.num2;
    data.subtraction = data.num1 - data.num2;
    data.multiplication = data.num1 * data.num2;

    if (data.num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        data.division = data.num1 / data.num2;
    }

    return data;
}

int main() {
    struct Calculation input;

    printf("Enter two numbers: ");
    scanf("%d %d", &input.num1, &input.num2);

    struct Calculation result = carry(input);

    printf("Addition: %d\n", result.addition);
    printf("Subtraction: %d\n", result.subtraction);
    printf("Multiplication: %d\n", result.multiplication);
    if (result.num2 != 0) {
        printf("Division: %d\n", result.division);
    }

    return 0;
}
