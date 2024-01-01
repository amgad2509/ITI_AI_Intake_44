#include <iostream>

using namespace std;

class Queue
{
    int* arr;
    int Size;
    int front;
    int last;
    int len;
public:
    // Constructors //
    Queue()
    {
        front=0;
        Size=5;
        last=Size-1;
        len=0;
    }
    Queue(int _size)
    {
        front=0;
        Size=_size;
        last=Size-1;
        arr=new int[Size];
        len=0;
    }
    ///////copy Constractor ///////////
//    Queue(Queue& q)
//    {
//        tos=q.tos;
//        Size=q.Size;
//        current=q.current;
//        arr=new int[Size];
//        int i;
//        for(i=0;i<tos;i++)
//        {
//            arr[i]=q.arr[i];
//        }
//    }

//    Queue& operator=(const Queue& q)
//    {
//        if (this == &q)
//        {
//            return *this; // In the state of self equality we check the address for this and our object (c1=c2)
//        }
//
//        delete[] arr;
//        Size = q.Size;
//        tos = q.tos;
//        arr = new int[Size];
//
//        for (int i = 0; i < tos; i++)
//        {
//            arr[i] = q.arr[i];
//        }
//
//        return *this;
//    }

    //////// Overload the + operator , Help for concat /////////////
//    Queue operator+ (const Queue& q2)
//    {
//        Queue result(tos + q2.tos); // Call for Constructor takes Size
//
//        for (int i = 0; i < tos; i++)
//        {
//            result.Enquee(arr[i]);
//        }
//
//        for (int i = 0; i < q2.tos; i++)
//        {
//            result.Enquee(q2.arr[i]);
//        }
//
//        return result;
//    }
//    ~Queue() //This a Destructor for Queue
//    {
//       delete [] arr;
//    }
    int is_Full()
    {
        if (len==Size)
            return 1;
        else
            return 0;
    }
    int is_Empty()
    {
        if (len==0)
            return 1;
        else
            return 0;
    }
    int Enquee(int n)
    {
        if (is_Full())
        {
            cout<< "Array is Full";
            return 0;
        }
        else
        {
            last=(last+1)%Size;
            arr[last]=n;
            len ++;
            return 1;
        }
    }
    int Dequee(int * n)
    {
        if (is_Empty())
        {
            cout<< "Array is Empty";
            return 0;
        }
        else
        {
            front=(front+1)%Size;
            *n=arr[front];
            --len;
            return 1;
        }
    }
//    void view_content()
//{
//    current = 0;
//
//    while (current != tos)
//    {
//        int x;
//        Dequee(&x);
//        cout << "\n" << x;
//    }
//}

};

int main()
{
    int x;

    // Objects From Queue //
    Queue q1(4);
    Queue q2(4);
    Queue q3;

    // PUSH IN Queue //
    q1.Enquee(50);
    q1.Enquee(20);
    q1.Enquee(30);
    q1.Enquee(40);

    q1.Dequee(&x);
    cout<<endl<<x;


//    q2.Enquee(50);
//    q2.Enquee(20);
//    q2.Enquee(30);
//    q2.Enquee(40);
//
//    q3=q1+q2;
    // POP FROM Queue & RETURN VALUE//
//    q1.pop(&x);
//    cout<<endl<<x;
//
//    q1.pop(&x);
//    cout<<endl<<x;
//
//    q1.pop(&x);
//    cout<<endl<<x;
//
//    q1.pop(&x);
//    cout<<endl<<x;


//    // PUSH AGAIN IN STACK //
//    q1.push(50);
//    q1.push(20);
//    q1.push(30);
//
//    // Test view_content Function //
//    q3.view_content();
    return 0;
}
