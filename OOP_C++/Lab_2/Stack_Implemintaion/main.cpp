#include <iostream>

using namespace std;

class Stack
{
    int arr[5];
    int Size;
    int tos;
public:
    Stack()
    {
        tos=0;
        Size=5;
    }
    int is_Full()
    {
        if (tos==Size)
            return 1;
        else
            return 0;
    }
    int is_Empty()
    {
        if (tos==0)
            return 1;
        else
            return 0;
    }
    int push(int n)
    {
        if (is_Full())
        {
            cout<< "Array is Full";
            return 0;
        }
        else
        {
            arr[tos]=n;
            tos++;
            return 1;
        }
    }
    int pop(int * n)
    {
        if (is_Empty())
        {
            cout<< "Array is Empty";
            return 0;
        }
        else
        {
            tos--;
            *n=arr[tos];
            return 1;
        }
    }
    void view_content()
    {
        // copy of the current stack//
        Stack tempStack = *this;

        while (!tempStack.is_Empty())
        {
            int x;
            tempStack.pop(&x);
            cout <<"\n"<<x;
        }
   }
};

void view_content(Stack s1)
    {
        while (!s1.is_Empty())
        {
            int x;
            s1.pop(&x);
            cout <<"\n"<<x;
        }
   }

int main()
{
    int x;

    // Object From Stack //
    Stack s1;
    Stack s2;

    // PUSH IN STACK //
    s1.push(50);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    // POP FROM STACK & RETURN VALUE//
    s2=s1;

    s2.pop(&x);
    cout<<endl<<x;

    s2.pop(&x);
    cout<<endl<<x;

    s2.pop(&x);
    cout<<endl<<x;

    // PUSH AGAIN IN STACK //
//    s1.pop(&x);
//    cout<<endl<<x;

    // Test view_content Function //
    view_content(s1);
    return 0;
}
