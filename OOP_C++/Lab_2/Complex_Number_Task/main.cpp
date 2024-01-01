#include <iostream>

using namespace std;

class Complex
{
    int real;
    int img;
public:
    Complex()
    {
        real=0;
        img=0;
    }
    void set_real(int _real)
    {
        real=_real;
    }
    void set_img(int _img)
    {
        img =_img;
    }
    int get_real()
    {
        return real;
    }
    int get_img()
    {
        return img;
    }
    void print()
    {
        if (img > 0)
        {
            cout << endl<<real<<"+"<<img<<"j";
        }
        else if (img <0)
        {
            cout << endl<<real<<img<<"j";
        }
        else
        {
            cout << endl<<real<<"j";
        }
    }
    void print(int r , int i)
    {
        if (img > 0)
        {
            cout << endl<<r<<"+"<<i<<"j";
        }
        else if (img <0)
        {
            cout << endl<<r<<i<<"j";
        }
        else
        {
            cout << endl<<r<<"j";
        }
    }
//////////////////Add For Class////////////////////////////////////
    Complex add (Complex c)
    {
        Complex result;
        result.real=c.real+real;
        result.img=c.img+img;
        return result;
    }
};

/////////////// Stand alone add for two objects///////////////////
Complex add(Complex c1,Complex c2)
{
    Complex result;
    result.set_real(c1.get_real()+c2.get_real());
    result.set_img(c1.get_img()+c2.get_img());
    return result;
}

int main()
{
    ////////////// Creat two objects C1 and C2 /////////////////////////
    Complex c1;
    Complex c2;
    Complex c3;

    //////////// Set Real For two objects C1 and C2 //////////////////////

    c1.set_real(5);
    c1.set_img(433);

    c2.set_real(3);
    c2.set_img(433);

    c3 = c1.add(c2);
    ///////////// Print C3 To Check the function /////////////////////////
    c3.print();

  Complex c4= add(c1,c2);
  c4.print();
  c1.print(3,4);
  return 0;
}
