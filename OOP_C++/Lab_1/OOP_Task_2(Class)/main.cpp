#include <iostream>
#include<string.h>

using namespace std;

class emp {
    int id;
    int age;
    int salary;
    char name[10];

public:
    void print()
     {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }

        ////////////////////////////////////////////// Setter ///////////////////////////////////

    void set_ID(int _id)
    {
        id=_id;
    }
    void set_age(int _age)
    {
        age = _age;
    }
    void set_Salary(int _Salary)
    {
        salary=_Salary;
    }
    void set_Name(char* _Name)
    {
        strcpy(name,_Name);
    }
    ////////////////////////////////////////////// Getter ///////////////////////////////////

    int get_ID()
    {
        return id;
    }
    int get_age()
    {
        return age;
    }
    int get_Salary()
    {
        return salary;
    }
    char* get_Name()
    {
        return name;
    }

};

int main() {
    int id,age,salary;
    char name[10];

    emp e1;
    cout << " Enter Your ID: " << endl;
    cin>>id;
    e1.set_ID(id);

    cout << " Enter Your Age: " << endl;
    cin>>age;
    e1.set_age(age);

    cout << " Enter Your Salary: "<< endl;
    cin>>salary;
    e1.set_Salary(salary);

    cout << " Enter Your Name: " << endl;
    cin>>name;
    e1.set_Name(name);

    e1.print();

    string test= e1.get_Name();
    cout << test ;

}
