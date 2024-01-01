#include <iostream>
#include <graphics.h>
using namespace std;
class point
{
    int x;
    int y;
public:
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    void setx(int _x)
    {
        x=_x;
    }
    void sety(int _y)
    {
        y=_y;
    }
    void print()
    {
        cout<<"("<<x<<","<<y<<")";
    }
    void setpoint(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
// constractors

    point ()
    {
//default
        x=y=0;
        cout<<"\n point parameterless constrctors";

    }
    point(int _r)
    {
        x=y=_r;
        cout<<"\n point one paramter constractor";
    }
    point(int _x,int _y)
    {
        x=_x;
        y=_y;
        cout<<"\n two paramters constractors";

    }
    ~point()
    {
        cout<<"\n point destractor ";
    }
};
class Rec
{
    point ul;
    point lr;
public:
    void print()
    {
        cout<<"\n upper left point :";
        ul.print();
        cout<<"\n lower right point:";
        lr.print();
    }

    point getul()
    {
        return ul;
    }
    point getlr()
    {
        return lr;
    }
    void setul(point _ul)
    {
        ul=_ul;
    }
    void setul(int x,int y)
    {
        ul.setpoint(x,y);
    }

    void setlr(point _lr)
    {
        lr=_lr;
    }
    void setlr(int x,int y)
    {
        lr.setpoint(x,y);
    }

    void setrect(point _ul,point _lr )
    {
        ul=_ul;
        lr=_lr;
    }
    void setrect(int x1,int y1,int x2,int y2)
    {
        ul.setpoint(x1,y1);
        lr.setpoint(x2,y2);
    }
    Rec()
    {
        cout<<"\n rectangle paramatelss constarctor";
    }
    Rec(int x1,int y1,int x2,int y2):ul(x1,y1),lr(x2,y2)
    {
        cout<<"\n rectangle 4 paramter constractor ";
        //ul.setpoint(x1,x2);
        //lr.setpoint(y1,y2);
    }
    void draw()
    {
        rectangle(ul.getx(),ul.gety(),lr.getx(),lr.gety());
    }

    ~Rec()
    {
        cout<<"\n rectangle destractor ";

    }
};

class Circle
{
    point center;
    int redius;
public:
    void set_center(int x ,int y)
    {
        center.setpoint(x,y);
    }
    void set_center(point _center)
    {

        center=_center;
    }
    void set_rad(int _rad)
    {
        redius=_rad;
    }
    Circle ()
    {
        redius =1;
    }
    Circle(int x , int y, int _redious):center(x,y)
    {
        redius=_redious;
    }
    void print()
    {
        center.print();
        cout<<"and rad= ";
    }
    void draw()
    {
        circle(center.getx(),center.gety(),redius);

    }
};
class Line {
    point start;
    point end;
public:
    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2) {
        // Constructor to set the starting and ending points of the line
    }

    void draw() {
        line(start.getx(), start.gety(), end.getx(), end.gety());
    }

    void print() {
        cout << "Start point: ";
        start.print();
        cout << "End point: ";
        end.print();
    }
};

class Triangle {
    point p1;
    point p2;
    point p3;
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
        : p1(x1, y1), p2(x2, y2), p3(x3, y3) {
    }

    void draw() {
        line(p1.getx(), p1.gety(), p2.getx(), p2.gety());
        line(p2.getx(), p2.gety(), p3.getx(), p3.gety());
        line(p3.getx(), p3.gety(), p1.getx(), p1.gety());
    }

    void print() {
        cout << "Point 1: ";
        p1.print();
        cout << "Point 2: ";
        p2.print();
        cout << "Point 3: ";
        p3.print();
    }
};

int main()
{
    int gdriver=DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");


    Rec r1 (50,50,80,80);
    r1.draw();



    r1 .print();




//    point p1(10,20);
    point p1 (70,80);
    p1.print();

    r1.setul(10,30);
    r1.print();

    Circle c(100, 100, 50);
    c.draw();
//
    Triangle t(200, 200, 250, 300, 300, 200);
    t.draw();

    Line l(50, 50, 200, 50);
    l.draw();



    getch();

    closegraph();
     return 0;
}

