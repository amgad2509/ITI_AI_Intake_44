#include <stdio.h>
#include <stdlib.h>

int main()
{
      char choice;
      int flag = 0;
    do{
        system("cls");
        printf("Menu:\n");
        printf("Enter 'n' for New\n");
        printf("Enter 'd' for Display\n");
        printf("Enter 'e' for Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'n':
                printf("New Selected \n");
                break;
            case 'd':
                printf("Display selected\n");

                break;
            case 'e':
                printf("Exit Selected\n");
                flag=1;
                break;
        }getch();

    }while(flag==0);

}

