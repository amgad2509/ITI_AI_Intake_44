#include <stdio.h>
#include <stdlib.h>

int main()
{
    /////////// initilaize 2D array with zero////////////////////////////
    int i,j;
    int arr[3][4]={{0,0,0,0}};
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            if (j<3)
               printf("%d ,",arr[i][j]);
            else
                printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
        /////////// Scan and print data////////////////////////////
    printf("Enter elements for 3x4 array:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d", &arr[i][j]);
        }

    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            if (j<3)
                printf("%d ,",arr[i][j]);
            else
                printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    /////////// The sum for each row ////////////////////////////
    int sum [3];
    for(i=0;i<3;i++)
    {
        sum[i]=0;
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
           sum[i]+=arr[i][j];
        }
    }
    for(i=0;i<3;i++)
    {
        printf("\nThe sum for row %d is %d ",i+1,sum[i]);
    }

    /////////// The Avrage for each col ////////////////////////////
    int avg [4];
    for(i=0;i<4;i++)
    {
        avg[i]=0;
    }
    for(j=0;j<4;j++)
    {
        for(i=0;i<3;i++)
        {
           avg[j]+=arr[i][j];
        }
        avg[j]=avg[j]/3;
    }
    for(i=0;i<4;i++)
    {
        printf("\nThe Average for each column %d is %d ",i+1,avg[i]);
    }
    return 0;
}
