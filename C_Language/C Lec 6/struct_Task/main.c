#include <stdio.h>
#include <stdlib.h>

struct emp{
int id;
char name[10];
int age;
int salary;
int overtime;
int deduction;
int total_salary;
};

int main()
{
    struct emp e1;

    printf("Enter id for empolyee : ");
    scanf("%d",&e1.id);

    printf("\nEnter Name for empolyee : ");
    scanf("%s",e1.name);

    printf("\nEnter Age for empolyee : ");
    scanf("%d",&e1.age);

    printf("\nEnter Salary for empolyee : ");
    scanf("%d",&e1.salary);

    printf("\nEnter Overtime for empolyee : ");
    scanf("%d",&e1.overtime);

    printf("\nEnter Deduction for empolyee : ");
    scanf("%d",&e1.deduction);

    // Total salary
    e1.total_salary=e1.salary+e1.overtime-e1.deduction;

    printf(" id: %d\n Name: %s\n Age: %d\n salary: %d\n overtime: %d\n deduction: %d\n TotalSalary: %d\n",e1.id,e1.name,e1.age,e1.salary,e1.overtime,e1.deduction,e1.total_salary);
}
