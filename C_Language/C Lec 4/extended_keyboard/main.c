#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Please enter your char to check: ");
    char ch=getch();
    if(ch==-32)
    {
        printf("\nYour key is Extended key");
        ch=getch();
        printf("%c : %d ",ch,ch);
    }
    else
    {
        printf("\nYour key is Normal key %c : %d",ch,ch);

    }
    return 0;
}
