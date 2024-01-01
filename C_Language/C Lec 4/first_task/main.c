#include <stdio.h>
#include <stdlib.h>

int main()
{
    char full_name[22];
    char f_name[10];
    char l_name[10];
    printf("pleas enter your first name :");
    gets(f_name);
    printf("\npleas enter your last name :");
    gets(l_name);

    strcpy(full_name,f_name);
    strcat(full_name," ");
    strcat(full_name,l_name);
    printf("\nyour full name is :");

    puts(full_name);

    return 0;
}
