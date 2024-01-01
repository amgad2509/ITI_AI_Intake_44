#include <iostream>

using namespace std;
class shape
{
protected:
    int dim1;
    int dim2;
public:
    // Constructors for Shape
    shape(){dim1=dim2=1;}
    shape(int dim){dim1=dim2=dim;}
    shape(int _dim1 , int _dim2)
    {
        dim1=_dim1;
        dim2=_dim2;
    }
    // Setter
    void set_Dim1(int _dim1)
    {
        dim1=_dim1;
    }
    void set_Dim2(int _dim2)
    {
        dim2=_dim2;
    }
    // getter
    int get_Dim1()
    {
        return dim1;
    }
    int get_Dim2()
    {
        return dim2;
    }
    void print()
    {
        cout<<"("<<dim1<<" , "<<dim2<<" )";
    }
};
class Rectangel : public shape
{
public:
    Rectangel(){}
    Rectangel(int _dim1,int _dim2):shape(_dim1,_dim2)
    {

    }
    float calc_Area()
    {
        return dim1*dim2;
    }
};
class Triangle : public shape
{
public:
    Triangle (){}
    Triangle(int _dim1,int _dim2) :shape(_dim1,_dim2)
    {

    }
    float calc_Area()
    {
        return 0.5*dim1*dim2;
    }
};
class Circle : public shape
{
public:
    Circle (){}
    Circle(int _dim1) :shape(_dim1)
    {
    }
    void set_Dim1(int _dim1)
    {
        dim1=_dim1;
        dim2=_dim1;

    }
    void set_Dim2(int _dim2)
    {
        dim1=_dim2;
        dim2=_dim2;
    }
    float calc_Area()
    {
        return 3.14*dim1*dim2;
    }
};
int main()
{
    Rectangel r1(10,20);
    r1.print();
    cout<<endl<<"And The Area is "<<r1.calc_Area();
    cout<<"\n======================================";
    Triangle t1(10,20);
    cout<<endl;
    t1.print();
    cout<<endl<<"And The Area is "<<t1.calc_Area();
    cout<<"\n======================================";
    Circle c1(10);
    cout<<endl;
    c1.print();
    cout<<endl<<"And The Area is "<<c1.calc_Area();
    cout<<"\n======================================";
}
