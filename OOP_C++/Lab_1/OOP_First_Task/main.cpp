#include <iostream>
using namespace std;

struct emp {
    int id;
    int age;
    int salary;
    char name[10];

    void print()
     {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    emp e1 = {10, 23, 5000, "Amgad"};
    cout << " Enter Your ID: " << endl;
    cin>>e1.id;

    cout << " Enter Your Age: " << endl;
    cin>>e1.age;

    cout << " Enter Your Salary: "<< endl;
    cin>>e1.salary;

    cout << " Enter Your Name: " << endl;
    cin>>e1.name;

    e1.print();
}
