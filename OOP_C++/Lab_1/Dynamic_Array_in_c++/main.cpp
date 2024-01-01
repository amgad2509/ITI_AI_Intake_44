#include <iostream>

using namespace std;

int main()
{
    int size,i;
    cout << " Enter The size for array : " << endl;
    cin>>size;

    int * arr=new int[size];

    for (i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    for (i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
