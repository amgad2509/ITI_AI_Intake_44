#include <iostream>

using namespace std;

class Stack
{
    int* arr;
    int Size;
    int tos;

public:
    Stack() // This if we want the size to be 5
    {
        tos = 0;
        Size = 5;
        arr = new int[Size];
    }

    Stack(int _size)
    {
        tos = 0;
        Size = _size;
        arr = new int[Size];
    }

    Stack(const Stack& s) /// copy Constructor
    {
        tos = s.tos;
        Size = s.Size;
        arr = new int[Size];
        for (int i = 0; i < tos; i++)
        {
            arr[i] = s.arr[i];
        }
    }

    ~Stack() // Destructor for Stack
    {
        delete[] arr;
    }

    int is_Full()
    {
        return tos == Size;
    }

    int is_Empty()
    {
        return tos == 0;
    }

    int push(int n)
    {
        if (is_Full())
        {
            cout << "\n Array is Full";
            return 0;
        }
        else
        {
            arr[tos] = n;
            tos++;
            return 1;
        }
    }

    int pop(int* n)
    {
        if (is_Empty())
        {
            cout << "\n Array is Empty";
            return 0;
        }
        else
        {
            tos--;
            *n = arr[tos];
            return 1;
        }
    }

    void view_content()
    {
        for (int i = 0; i < tos; i++)
        {
            cout << "\n" << arr[i];
        }
    }

    Stack& operator=(const Stack& s)
    {
        if (this == &s)
        {
            return *this; // in the state of self equality we check the address for this and our object (c1=c2)
        }

        delete[] arr;
        Size = s.Size;
        tos = s.tos;
        arr = new int[Size];

        for (int i = 0; i < tos; i++)
        {
            arr[i] = s.arr[i];
        }

        return *this;
    }

    //////// Overload the + operator , Help for concat /////////////
    Stack operator+ (const Stack& s2)
    {
        Stack result(tos + s2.tos); // Call for Constructor takes Size

        for (int i = 0; i < tos; i++)
        {
            result.push(arr[i]);
        }

        for (int i = 0; i < s2.tos; i++)
        {
            result.push(s2.arr[i]);
        }

        return result;
    }
};

void view_content(Stack c1)
{
    while (!c1.is_Empty())
    {
        int x;
        c1.pop(&x);
        cout << "\n" << x;
    }
}

int main()
{
    int x;

    // Object From Stack //
    Stack c1(3);
    Stack c2(3);

    // PUSH IN STACK //
    c1.push(50);
    c1.push(20);
    c1.push(60);

    c2.push(30);
    c2.push(40);
    c2.push(60);

    // Concatenate c1 and c2 into c3
    Stack c3 = c2+c1;

    // Test view_content Function
    cout << "Contents of c3:" << endl;
    view_content(c3);

    cout << endl << "================================";

//    c1.pop(&x);
//    cout << endl << x;

    return 0;
}
