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
    Complex(int _real, int _img)
    {
        real=_real;
        img=_img;
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
////////// operator Overloading ( Complex + Complex ) /////////////////
    Complex operator+(Complex const& c)
    {
        Complex res;
        res.real=c.real+real;
        res.img=c.img+img;
        return res;
    }
////////// operator Overloading ( complex + int ) /////////////////
    Complex operator+(int r)
    {
        Complex res;
        res.real=real+r;
        res.img=img;
        return res;
    }
    int operator== (Complex c)
    {
        if(real==c.real && img==c.img)
            return 1;
        else
            return 0;
    }
    int operator!= (Complex c)
    {
        return !(*this == c);
    }
    Complex operator++ ()
    {
        real++;
        Complex r(real,img);
        return *this;
    }
    Complex operator++(int)
    {
        Complex res(real,img);
        real++;
        return res;
    }
    Complex& operator+=(Complex c)
    {
        real=real+c.real;
        img=img+c.img;
        return *this;
    }
    explicit operator int ()
    {
        return real;
    }
};

///// operator Overloading (int + complex ) We need Stand alone func () ////////

    Complex operator+(int r,Complex& c)
    {
        Complex res;
        res.set_real(r+c.get_real());
        res.set_img(c.get_img());
        return res;
    }

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
    Complex c4;
    Complex c5;
    Complex c6;
    //////////// Set Real For two objects C1 and C2 AND C5//////////////////////

    c1.set_real(5);
    c1.set_img(433);

    c2.set_real(3);
    c2.set_img(433);

    c5.set_real(2);
    c5.set_img(43);

    c6.set_real(2);
    c6.set_img(43);
///////////// TEST EQUAL//////
    if(c1==c2)
    {
        cout<< "ARE EQUAL"<<endl;
    }
    else
        cout<< "Not Equal"<<endl;

///////////// TEST ++C OR C++ OR += //////

    c3=++c1;
    c4=c2++;
    c5+=c6;
    ///////// Print ////////////////
    cout<< "************ FOR C3=++C1 ****************";
    c3.print();
    cout<< "\n ************ FOR C4=C2++ ****************";
    c4.print();
    cout<< "\n ************ FOR C5+=C6 ****************";
    c5.print();

    //////////Explict int////////////////////
    int x=(int)c1;

  return 0;
}
