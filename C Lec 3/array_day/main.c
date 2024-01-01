#include <stdio.h>
#include <stdlib.h>

int main()
{
    /////////// initilaize with zero////////////////////////////
    int arr[5]={0};
    ////////////Scan and print ///////////////////////////////////

    int i;
    int sum=0;
    printf("Enter %d elements for the array:\n", 5);
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the array
    printf("Array elements: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    ///////////////sum of array ///////////////////////////////////
    for (i = 0; i < 5; i++)
    {
        sum+=arr[i];
    }
    printf("The sum of Array elements is : %d ",sum);
    ///////////////Max of array////////////////////
     int max=arr[0];
     for (i = 0; i < 5; i++)
    {
        if(max<arr[i])
            max=arr[i];
    }
    printf("\nThe Maximum of Array elements is : %d ",max);
    ///////////////Minimum of array////////////////////
     int min=arr[0];
     for (i = 0; i < 5; i++)
    {
        if(min>arr[i])
            min=arr[i];
    }
    printf("\nThe Minimum of Array elements is : %d ",min);
    ///////////////Search for Specific Target////////////////////
     int target;
     int flag=0;
     printf("\nEnter your Number you Want to search in array and return there index : ");
     scanf("%d",&target);
     for (i = 0; i < 5; i++)
    {
       if(arr[i]==target)
       {
           flag=1;
           break;
       }
       else
       {
           continue;
       }
    }
    if(flag==1)
    {
        printf("\nYour Target %d is found at index %d ",target,i);
    }
    else
    {
        printf("Your taget NOT Found in array");
    }
}

