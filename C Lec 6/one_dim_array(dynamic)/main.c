#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int size;
    printf("plz Enter How many element you want :");
    scanf("%d",&size);
    int * arr=malloc(size*sizeof(int));
    for(i=0;i<size;i++)
    {
        scanf("%d",arr+i);
    }
    for(i=0;i<size;i++)
    {
        printf(" %d",*(arr+i));
    }

    return 0;
}
