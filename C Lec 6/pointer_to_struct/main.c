#include <stdio.h>
#include <stdlib.h>

struct emp {
    int id;
    char name[10];
    int age;
};


int main()
{
    struct emp e1={10,"ALI",30};
    struct emp * ptr =&e1;
    printf("\n Enter your ID: ");
    scanf("%d",&(*ptr).id);

    printf("\n Enter your Name : ");
    scanf("%s",&(*ptr).name);

    printf("\n Enter your Age : ");
    scanf("%d",&(*ptr).age);


    printf("\n The id is: %d",(*ptr).id);
    printf("\n The name is:%s",(*ptr).name);
    printf("\n The age is: %d",(*ptr).age);


    return 0;
}
