#include <iostream>
#include<string.h>

using namespace std;
class person
{
    int id;
    char name[10];
    int age;
public:
    // Constructor for person
    person()
    {
        id=0;
        strcpy(name,"no name");
        age=0;
    }
    person(int _id , char* _name, int _age)
    {
        id=_id;
        strcpy(name,_name);
        age=_age;
    }
    // Setter
    void set_Id(int _id)
    {
        id=_id;
    }
    void set_Name(char* _name)
    {
        strcpy(name,_name);
//        name=_name;
    }
    void set_Age(int _age)
    {
        age=_age;
    }
    // Getter
    int get_Id()
    {
        return id;
    }
    char* get_Name()
    {
        return name;
    }
    int get_Age()
    {
        return age;
    }
    void print()
    {
        cout<<id<<" : "<<name<<" : "<<age;
    }
};
class student : public person
{
    char grade;
public:
    // Constructor for Student
    student (int _id ,char* _name,int _age,char _grade) :person(_id,_name,_age)
    {
        grade=_grade;
    }
    // Set_Grade
    void set_Grade(int _grade)
    {
        grade=_grade;
    }
    // Get_Grade
    char get_Grade()
    {
        return grade;
    }
    void print()
    {
        person::print();
        cout<<" : "<<grade;
    }
};
class employee :person
{
    int salary;
public:
    employee (int _id ,char* _name,int _age,int _salary) :person(_id,_name,_age)
    {
        salary=_salary;
    }
    void set_Salary(int _salary)
    {
        salary=_salary;
    }
    int get_Salary()
    {
        return salary;
    }
    void print()
    {
        person::print();
        cout<<" : "<<salary;
    }

};

int main()
{
    person p1(10,"amgad",23);
    student s1(10,"amgad",23,'a');
    employee e1(10,"amgad",23,15000);
    p1.print();
    cout<<endl;
    s1.print();
    cout<<endl;
    e1.print();
}
