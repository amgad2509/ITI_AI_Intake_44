#include <stdio.h>
#include <stdlib.h>

struct emp {
    int id;
    char name[10];
    int age;
    int salary;
    int overtime;
    int deduction;
    int total_salary;
};

int main() {
    struct emp arr[5];
    int enteredIDs[5]; // An array to store entered ID
    int i;

    for (i = 0; i < 5; i++) {
        int newID;

        printf("*******************Employee number %d:*********************\n", i + 1);
        printf("Enter id for employee number %d: ", i + 1);
        scanf("%d", &newID);

        // Check if the ID found or not?
        int flag = 0;
        int j;
        for (j = 0; j < i; j++) {
            if (enteredIDs[j] == newID) {
                flag = 1;
                break;
            }
        }

        if (flag) {
            printf("ID %d is already entered Please enter a different id\n", newID);
            i--;
        } else {
            enteredIDs[i] = newID;

            arr[i].id = newID;
            printf("Enter Name for employee number %d: ", i + 1);
            scanf("%s", arr[i].name);

            printf("Enter Age for empolyee number %d: ",i+1);
            scanf("%d",&arr[i].age);

            printf("Enter Salary for empolyee number %d: ",i+1);
            scanf("%d",&arr[i].salary);

            printf("Enter Over time for empolyee number %d: ",i+1);
            scanf("%d",&arr[i].id);

            printf("Enter Deduction for empolyee number %d: ",i+1);
            scanf("%d",&arr[i].deduction);

            // Totalal salary
            arr[i].total_salary = arr[i].salary + arr[i].overtime - arr[i].deduction;
        }
    }

    for (i = 0; i < 5; i++)
    {
        printf("\nTotal Salary for employee %d is: %d\n", i + 1, arr[i].total_salary);
    }

    return 0;
}
