#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<string.h>
#define null -32

 void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }


void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
int main()
{
    char menu[3][10]={"New","Display","Exit"};
    int i;
    int cursor=0;
    int flag=1;
    char ch;


    do
    {
        system("cls");
        for(i=0;i<3;i++)
    {
        gotoxy(10,7+i);

        if(cursor==i)
        {
            textattr(0x27);
        }
        printf("%s",menu[i]);
        textattr(0x07);
    }

        ch=getch();
        switch(ch)
        {
            case -32:
                ch=getch();
                switch(ch)
                {
                    case 72:
                    cursor--;//up
                    if(cursor<0)
                        cursor=2;
                    break;
                case 71: //home
                    cursor=0;
                    break;
                case 80: //down
                    cursor++;
                    if(cursor>2)
                    cursor=0;
                    break;

                 case 79: //End
                    cursor=2;
                    break;
                }
                break;


            case 27://ESC
                flag=0;
                break;
            case 13://enter
                if(cursor==2)
                {
                    flag=0;
                }
                else
                    {
                    system("cls");
                    printf("%s",menu[cursor]);
                    getch();
                    break;
                    }
            }

    }while(flag);
         return 0;

}
