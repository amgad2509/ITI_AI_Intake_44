#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows,col;
    int i,j;
    printf("Enter The number of rows :");
    scanf("%d",&rows);

    printf("Enter The number of columns :");
    scanf("%d",&col);

    int** ptr=(int**)malloc(rows*sizeof(int*));
    for(i=0;i<rows;i++)
    {
        ptr[i]=(int*)malloc(col*sizeof(int));
    }


    for(i=0;i<rows;i++)
    {
         for(j=0;j<col;j++)
         {
            scanf("%d",&ptr[i][j]);
         }
    }

    for(i=0;i<rows;i++)
    {
         for(j=0;j<col;j++){
                if (j!=(col-1))
                   printf(" %d ,",ptr[i][j]);
                else
                   printf(" %d ",ptr[i][j]);
         }
         printf("\n");
    }

    return 0;
}
