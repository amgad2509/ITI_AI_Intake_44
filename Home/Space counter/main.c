#include <stdio.h>
#include <stdlib.h>
#define size 10

int main()
{
    int arr[]= {6,1,1,1,1,1,9,4,6,6};
    int i, j, space=0;

    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arr[i]==arr[j] && space < j-i-1)
                space=j-i-1;
        }
    }
    printf("the biggest space is : %d", space);
    return 0;
}
