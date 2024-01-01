#include <iostream>

using namespace std;

class Point {
    int x;
    int y;

public:
    void setx(int _x) {
        x = _x;
    }

    void sety(int _y) {
        y = _y;
    }

    void set_point(int _x, int _y) {
        x = _x;
        y = _y;
    }

    int getx() {
        return x;
    }

    int gety() {
        return y;
    }

    void print() {
        cout << "(" << x << " , " << y << ")" << endl;
    }

    Point() {
        x = y = 0;
    }

    Point(int xy) {
        x = y = xy;
    }

    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

class Rectangle {
    Point ul;
    Point lr;

public:
    Rectangle()
    {

    }
    Rectangle(int x1 , int y1 , int x2, int y2) :ul(x1,y1),lr(x2,y2)
    {
        //ul.set_point(x1,y1);
        //lr.set_point(x2,y2);
    }
    void set_rectangle(Point _ul,Point _lr)
    {
        ul=_ul;
        lr=_lr;
    }
    void set_rectangle(int x , int y , int x1, int y1)
    {
        ul.set_point(x,y);
        lr.set_point(x1,y1);
    }
    void setUL(Point _ul)
    {
        ul=_ul;
    }
    void setUL(int x , int y)
    {
        ul.set_point(x,y);
    }
    void setLR(Point _lr)
    {
        lr=_lr;
    }
    void setLR(int x , int y)
    {
        lr.set_point(x,y);
    }

    Point getUL() {
        return ul;
    }

    Point getLR() {
        return lr;
    }

    void print() {
        cout << "Upper left Point: ";
        ul.print();
        cout << "Lower right Point: ";
        lr.print();
    }
};

int main() {
    Point p1(70,80);
    p1.print();

    Rectangle r1;
    r1.getUL().print();
    r1.getLR().print();
    r1.setUL(p1.getx(),p1.gety());
    r1.setUL(p1);
    r1.print();
    return 0;
}
