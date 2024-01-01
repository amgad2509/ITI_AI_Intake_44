#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define null -32
#define menu_size 3
#define max_name_size 8

void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
    //declare variables
    char menu[menu_size][max_name_size] = {"New","Display","Exit"};
    char sub_menu_new[3][10] = {"New1","New2","New3"};
    char sub_menu_display[3][10] = {"Display1","Display2","Display3"};
    char ch;
    int i,cursor,sub_cursor,flag,menu_indecator;
    cursor = sub_cursor = flag = menu_indecator = 0;

    do
    {
        system("cls");
        for(i=0; i<menu_size; i++)
        {
            if(i==cursor)
                textattr(0x61);
            gotoxy(20,2+i);
            printf("%s",menu[i]);
            textattr(0x07);
        }

        ch = getch();
        if(ch==-32)
            ch = getch();

        switch(ch)
        {
        case 72://up
            cursor--;
            if(cursor==-1)
                cursor=menu_size-1;
            break;
        case 80://down
            cursor++;
            if(cursor==menu_size)
                cursor=0;
            break;
        case 71://Home
            cursor=0;
            break;
        case 79://end
            cursor=menu_size-1;
            break;
        case 13://enter
            system("cls");
            printf("\n%s Has been selected",menu[cursor]);
            if (cursor==2)
                flag=1;
            else
                ch = getch();
            break;
        case 27://esc
            printf("\nExit the code");
            flag=1;
            break;
        case 77://right
            if (menu_indecator == 0)
            {
                do
                {
                    menu_indecator = 1;
                    system("cls");
                    for(i=0; i<menu_size; i++)
                    {

                        gotoxy(20,2+i);
                        printf("%s",menu[i]);

                    }
                    switch(cursor)
                    {
                    case 0:

                        for(i=0; i<3; i++)
                        {
                            if(i==sub_cursor)
                                textattr(0x17);
                            gotoxy(30,2+i+cursor);
                            printf("%s",sub_menu_new[i]);
                            textattr(0x07);
                        }
                        ch = getch();
                        if(ch==-32)
                            ch = getch();
                        switch(ch)
                        {
                        case 72://up
                            sub_cursor--;
                            if(sub_cursor==-1)
                                sub_cursor=2;
                            break;
                        case 80://down
                            sub_cursor++;
                            if(sub_cursor==3)
                                sub_cursor=0;
                            break;
                        case 71://Home
                            sub_cursor=0;
                            break;
                        case 79://end
                            sub_cursor=2;
                            break;
                        case 75://left
                            menu_indecator = 0;
                            break;

                        }
                        break;
                    case 1:

                        for(i=0; i<3; i++)
                        {
                            if(i==sub_cursor)
                                textattr(0x17);
                            gotoxy(30,2+i+cursor);
                            printf("%s",sub_menu_display[i]);
                            textattr(0x07);
                        }
                        ch = getch();
                        if(ch==-32)
                            ch = getch();
                        switch(ch)
                        {
                        case 72://up
                            sub_cursor--;
                            if(sub_cursor==-1)
                                sub_cursor=2;
                            break;
                        case 80://down
                            sub_cursor++;
                            if(sub_cursor==3)
                                sub_cursor=0;
                            break;
                        case 71://Home
                            sub_cursor=0;
                            break;
                        case 79://end
                            sub_cursor=2;
                            break;
                        case 75://left
                            menu_indecator = 0;
                            break;
                        }
                        break;
                    }
                }
                while(menu_indecator == 1);
            }
            break;
        }
    }
    while(flag==0);
    return 0;
}
