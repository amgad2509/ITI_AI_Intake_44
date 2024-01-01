#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define null -32
void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
int main()
{
    int i, size, col, row;
    printf("\n Enter size of Magic box:  ");
    scanf("%d", &size);
    if (size%2!=0)
    {


    col = (size/2) + 1;
    row = 1;
    for (i=1 ; i<= size*size; i++){

        gotoxy(col*3 , row*3 );
        printf("  %d", i);

        if (i%size == 0)
            row++;
        else
        {
            row--;
            if (row == 0)
                row=size;
            col--;
            if(col == 0)
                col=size;
        }
    }
    }
    else
        printf("\n       Please Enter Odd Number\n");
    return 0;
}
