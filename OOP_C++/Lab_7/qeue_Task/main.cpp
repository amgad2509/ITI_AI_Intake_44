#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int size;
    int front;
    int last;
    int len;

public:
    Queue(int _size = 5)
    {
        front = 0;
        size = _size;
        last = size - 1;
        arr = new int[size];
        len = 0;
    }

    // Copy constructor
    Queue(const Queue& other)
    {
        size = other.size;
        front = other.front;
        last = other.last;
        len = other.len;
        arr = new int[size];

        // Copy elements
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // Overloaded assignment operator
    Queue& operator=(const Queue& other)
    {
        if (this != &other) {
            delete[] arr;

            size = other.size;
            front = other.front;
            last = other.last;
            len = other.len;
            arr = new int[size];

            // Copy elements
            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    ~Queue()
    {
        delete[] arr;
    }

    int isFull()
    {
        return len == size;
    }

    int isEmpty()
    {
        return len == 0;
    }

    int Enqueue(int n)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return 0;
        }
        else
        {
            last = (last + 1) % size;
            arr[last] = n;
            len++;
            return 1;
        }
    }

    int Dequeue(int& n) {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        else
        {
            n = arr[front];
            front = (front + 1) % size;
            len--;
            return 1;
        }
    }

    int get_peak(int& n) {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        else
        {
            n = arr[front];
            return 1;
        }
    }

    void view_content()
    {
        int tempFront = front;

        for (int i = 0; i < len; ++i)
        {
            cout << arr[tempFront] << " ";
            tempFront = (tempFront + 1) % size;
        }

        cout << endl;
    }
};

int main() {
    int x;

    Queue q1(4);
    Queue q3;

    q1.Enqueue(50);
    q1.Enqueue(20);
    q1.Enqueue(30);
    q1.Enqueue(40);

    // View content of the queue
    cout << "================= Start Testing View_Content Function & Peak & Dequeue================"<<endl<< endl;
    cout << "Queue Content: ";
    q1.view_content();

    // Get peak element
    if (q1.get_peak(x))
    {
        cout << "Peek Element: " << x << endl;
    }

    // Dequeue an element
    if (q1.Dequeue(x))
    {
        cout << "Dequeued Element: " << x << endl;
    }

    // View content after deque
    cout << "Queue Content after Dequeue: ";
    q1.view_content();
    cout << "================= End of Testing View_Content Function & Peak & Dequeue================"<<endl<< endl;

    ////// Test Copy Constructor
    cout << "================= Start Testing Copy Constructor ================"<<endl<< endl;
    Queue q2=q1; // Will go to Copy CONSTRUCTOR TO Creat Copy from Object
    q2.view_content();
    cout << "================= End of Testing Copy Constructor ================"<<endl<< endl;
    ////// Test Assignment Operator
    cout << "================= Start Testing Assignment Operator ================"<<endl<< endl;
    q3=q2;
    q3.view_content();
    cout << "================= End of Testing Assignment Operator ================"<<endl<< endl;
    return 0;
}
