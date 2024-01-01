#include <stdio.h>
#include <stdlib.h>


int main()
{
    char current,previous;
    int words_num = 0;
    int char_num = 0;

    printf("please enter your sentence: ");
    current=previous=getch();
    printf("%c",current);

    while(current != 13)
    {
        current=getch();
        printf("%c",current);
        if((previous >= 'A' && previous <= 'Z') || (previous >= 'a' && previous <= 'z'))
        {
           if(current == 13 || current == 32 || current == 8)
            {
                words_num+=1;
                char_num+=1;
            }
            else if((current>= 'A' && current <= 'Z') || (current >= 'a' && current <= 'z'))
                char_num+=1;
        }

        previous = current;
    }
    printf("\nNumber of words = %d\nNumber of litters = %d\nNumber of spaces = %d",words_num,char_num,words_num-1);
    return 0;
}
