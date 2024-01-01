#include <iostream>

using namespace std;

class Stack
{
    int* arr;
    int Size;
    int tos;
public:
    Stack() // This if we wants size to be 5
    {
        tos=0;
        Size=5;
    }
    Stack(int _size)
    {
        tos=0;
        Size=_size;
        arr=new int[Size];
    }
    Stack(Stack& s) /// ////copy Constractor ///////////
    {
        tos=s.tos;
        Size=s.Size;
        arr=new int[Size];
        int i;
        for(i=0;i<tos;i++)
        {
            arr[i]=s.arr[i];
        }
    }

    ~Stack() //This a Destructor for Stack
    {
       delete [] arr;
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
            cout<< "\n Array is Full";
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
            cout<< "\n Array is Empty";
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
//////// Without define copy constractor ///////////////////

//void view_content(Stack c1)
//    {
//        while (!c1.is_Empty())
//        {
//            int x;
//            c1.pop(&x);
//            cout <<"\n"<<x;
//        }
//   }

//////// //// view_content () Take data as Refrence ///////////////

//void view_content(Stack& c1)
//    {
//        while (!c1.is_Empty())
//        {
//            int x;
//            c1.pop(&x);
//            cout <<"\n"<<x;
//        }
//   }

//////// //// view_content () Take data as Address ///////////////

void view_content(Stack* c1)
    {
        while (!c1->is_Empty())
        {
            int x;
            c1->pop(&x);
            cout <<"\n"<<x;
        }
   }

int main()
{
    int x;

    // Object From Stack //
    Stack s1(3);

    // PUSH IN STACK //
    s1.push(50);
    s1.push(20);
    s1.push(50);

    // Test view_content Function //
    //s1.view_content();
    view_content(&s1);

    cout<<endl<<"================================";

    s1.pop(&x);
    cout<<endl<<x;

    return 0;
}
