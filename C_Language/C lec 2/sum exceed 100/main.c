#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int sum=0;
    do{
        printf("Enter your number: ");
        scanf("%d",&x);
        sum+=x;
    }while(sum<100);
    printf(" The sum is equal = %d",sum);
    return 0;
}
