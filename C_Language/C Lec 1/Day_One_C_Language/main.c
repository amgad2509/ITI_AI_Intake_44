#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");



    char character;
    printf("Enter char :");
    scanf("%c",&character);
    printf("%d",character);


    int n;
    printf("\nEnter your decimal:");
    scanf("%d",&n);
    printf("%c",n);

    int nn;
    printf("\nEnter your decimal:");
    scanf("%d",&nn);
    printf("%x",nn);




    int first,second,mul,sub,add;

    printf("\nEnter your numbers:");
    scanf("%d %d",&first,&second);
    add=first + second;
    sub=first-second;
    mul=first*second;

    printf("%d %d %d",add,sub,mul);

    return 0;
}
