#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>

#define null -1

struct emp {
    int id;
    char name[10];
    int age;
    int salary;
    int overtime;
    int deduction;
    int total_salary;
};

void print_menu();
void gotoxy(int x, int y);
void textattr(int i);
void display_all_employees(struct emp *arr, int n);
int find_employee_by_id(struct emp *arr, int n, int id);
void delete_employee_by_id(struct emp *arr, int n, int id);
void delete_employee_by_name(struct emp *arr, int n, const char name_to_delete[]);

int cursor = 0;
char menu[6][20] = {"New", "Display All", "Delete By ID", "Delete By Name", "Exit"};

int main() {
    int flag = 1;
    char ch;
    int i;
    struct emp *arr = NULL;
    int size = 5;
    printf("plz Enter How many element you want :");
    scanf("%d",&size);

    arr = (struct emp *)malloc(size * sizeof(struct emp)); // Allocate memory

    for (i = 0; i < size; i++) {
        arr[i].id = null;
    }

    do {
        system("cls");
        print_menu();

        ch = getch();
        switch (ch) {
            case -32:
                ch = getch();
                switch (ch) {
                    case 72: // up
                        cursor--;
                        if (cursor < 0)
                            cursor = 4;
                        break;
                    case 71: // home
                        cursor = 0;
                        break;
                    case 80: // down
                        cursor++;
                        if (cursor > 4)
                            cursor = 0;
                        break;
                    case 79: // end
                        cursor = 4;
                        break;
                }
                break;

            case 27: // ESC
                flag = 0;
                break;

            case 13: // enter
                if (cursor == 4)
                {
                    flag = 0;
                } else if (cursor == 0)
                { // New
                    int position;
                    printf("\nEnter the desired position to add or update employee: ");
                    scanf("%d", &position);

                    if (position < 0 || position >= size)
                    {
                        printf("\nInvalid position, Please enter a position between 0 and %d\n", size - 1);
                    }
                    else
                        {
                        if (arr[position].id != null)
                         {
                            char choice;
                            printf("\nEmployee with ID %d already exists ,want to update or not (Y/N)? ", arr[position].id);
                            scanf(" %c", &choice);

                            if (choice == 'Y' || choice == 'y')
                            {
                                // Update the data
                                printf("\nEnter ID for employee: ");
                                scanf("%d", &arr[position].id);
                                printf("\nEnter Name for employee: ");
                                scanf("%s", arr[position].name);
                                printf("\nEnter Age for employee: ");
                                scanf("%d", &arr[position].age);
                                printf("\nEnter Salary for employee: ");
                                scanf("%d", &arr[position].salary);
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else
                         {
                            int id_to_add;
                            printf("\nEnter ID for employee: ");
                            scanf("%d", &id_to_add);

                            int duplicate = 0;

                            int i;
                            for (i = 0; i < size; i++)
                                {
                                if (arr[i].id == id_to_add)
                                {
                                    printf("\nEmployee with ID %d already exists,Cannot add a duplicate ID\n", id_to_add);
                                    duplicate = 1;
                                    ch=getch();
                                    break;
                                }
                            }

                            if (!duplicate)
                            {
                                // If no duplicate ID
                                arr[position].id = id_to_add;
                                printf("\nEnter Name for employee: ");
                                scanf("%s", arr[position].name);
                                printf("\nEnter Age for employee: ");
                                scanf("%d", &arr[position].age);
                                printf("\nEnter Salary for employee: ");
                                scanf("%d", &arr[position].salary);
                            }
                        }
                    }
                } else if (cursor == 1)
                { // Display All
                    display_all_employees(arr, size);
                } else if (cursor == 2) { // Delete By ID
                    int id_to_delete;
                    printf("Enter ID to delete: ");
                    scanf("%d", &id_to_delete);
                    delete_employee_by_id(arr, size, id_to_delete);
                }
                else if (cursor == 3)
                    { // Delete By Name
                    char name_to_delete[10];
                    printf("Enter Name to delete: ");
                    scanf("%s", name_to_delete);
                    delete_employee_by_name(arr, size, name_to_delete);
                }
                break;
        }
    } while (flag);

    // Free Heap
    free(arr);

    return 0;
}

 void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

 void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void print_menu() {
    int i;
    for (i = 0; i < 5; i++) {
        gotoxy(10, 5 + i);

        if (cursor == i) {
            textattr(0x27);
        }
        printf("%s", menu[i]);
        textattr(0x07);
    }
}

void display_all_employees(struct emp arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i].id != null) {
            printf("\n***************EMPLOYEE: %d *********************************",i+1);
            printf("\nEmployee ID: %d", arr[i].id);
            printf("\nName: %s\n", arr[i].name);
            printf("\nAge: %d\n", arr[i].age);
            printf("\nSalary: %d\n", arr[i].salary);
        }
    }
    getch();
}

int find_employee_by_id(struct emp arr[], int n, int id) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i].id == id) {
            return i;
        }
    }
    return -1; // Not found
}

void delete_employee_by_id(struct emp arr[], int n, int id) {
    int index = find_employee_by_id(arr, n, id);
    if (index != -1) {
        arr[index].id = null;
    }
}

void delete_employee_by_name(struct emp arr[], int n, const char name_to_delete[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i].id != null && strcmp(arr[i].name, name_to_delete) == 0) {
            arr[i].id = null;
        }
    }
}
