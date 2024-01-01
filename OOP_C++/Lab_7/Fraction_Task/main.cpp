#include <iostream>
using namespace std;

class Fraction {
private:
    int num;
    int den;

public:

    // Getter and setter for numerator
    int getNum()
    {
        return num;
    }

    void setNum(int numerator)
    {
        num = numerator;
    }

    // Getter and setter for denominator
    int getDen()
    {
        return den;
    }

    void setDen(int denominator) {
        if (denominator != 0) {
            den = denominator;
        } else {
            cout << "Denominator cannot be zero We Setting to 1" << endl;
            den = 1;
        }
    }
    // Constructors
    Fraction()
    {
        num=0;
        den=1;
    }
    Fraction(int numerator, int denominator)
    {
        num=numerator;
        den=denominator;
    }
    Fraction(const Fraction& f)
    {
        num=f.num;
        den=f.den;
    }

    // Overload addition operator '+'
    Fraction operator+(const Fraction& f)
    {
        int newNum = num * f.den + f.num * den;
        int newDen = den * f.den;
        return Fraction(newNum, newDen).simplify();
    }

    // Overload subtraction operator '-'
    Fraction operator-(const Fraction& f)
    {
        int newNum = num * f.den - f.num * den;
        int newDen = den * f.den;
        return Fraction(newNum, newDen).simplify();
    }

    // Overload multiplication operator '*'
    Fraction operator*(const Fraction& f)
    {
        int newNum = num * f.num;
        int newDen = den * f.den;
        return Fraction(newNum, newDen).simplify();
    }

    // Overload division operator '/'
    Fraction operator/(const Fraction& f)
    {
        if (f.num != 0) {
            int newNum = num * f.den;
            int newDen = den * f.num;
            return Fraction(newNum, newDen).simplify();
        } else {
            cerr << "Cannot divide by Zeroooo" << endl;
            return *this;
        }
    }

    // Overload assignment operator '='
    Fraction& operator=(const Fraction& f)
    {
        if (this != &f) {
            num = f.num;
            den = f.den;
        }
        return *this;
    }

    // Simplify the fraction
    Fraction simplify()
    {
        int gcd = findGCD(num, den);
        return Fraction(num / gcd, den / gcd);
    }

    // Print method
    void print()
    {
        cout << num << "/" << den;
    }

    // Find the greatest common divisor (GCD)
    int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    // Create fractions
    Fraction fraction1(2, 4);
    Fraction fraction2(3, 6);

    // Print the original fractions
    cout << "Original Fraction 1: ";
    fraction1.print();
    cout << endl;

    cout << "Original Fraction 2: ";
    fraction2.print();
    cout << endl;

    // Overloaded addition
    Fraction sum = fraction1 + fraction2;

    // Print the simplified result
    cout << "Sum (Simplified): ";
    sum.print();
    cout << endl;

    // Overloaded subtraction
    Fraction difference = fraction1 - fraction2;
    cout << "Difference (Simplified): ";
    difference.print();
    cout << endl;

    // Overloaded multiplication
    Fraction product = fraction1 * fraction2;
    cout << "Product (Simplified): ";
    product.print();
    cout << endl;

    // Overloaded division
    Fraction quotient = fraction1 / fraction2;
    cout << "Quotient (Simplified): ";
    quotient.print();
    cout << endl;

    // CALLS Copy CONSTRUCTOR NOT Equal Operator
    Fraction assignedFraction = fraction1;
    cout << "Assigned Fraction: ";
    assignedFraction.print();
    cout << endl;

    // Overloaded assignment:

    // CALLS Equal Operator NOT Copy CONSTRUCOR Because assignedFraction_1 already created and initialized with Default Constructor
    Fraction assignedFraction_1;
    assignedFraction_1=fraction1;
    cout << "Assigned Fraction: ";
    assignedFraction.print();
    cout << endl;

    return 0;
}
