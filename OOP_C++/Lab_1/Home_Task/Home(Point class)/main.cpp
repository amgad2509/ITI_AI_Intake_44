#include <iostream>

using namespace std;


class Point {
private:
    double x;
    double y;

public:
    // Setter methods
    void setX(double xValue) {
        x = xValue;
    }

    void setY(double yValue) {
        y = yValue;
    }

    // Getter methods
    double getX(){
        return x;
    }

    double getY(){
        return y;
    }

    // Method to print the point
    void print() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point point1;
    point1.setX(1.5);
    point1.setY(4.0);

    Point point2;
    point2.setX(3.5);
    point2.setY(2.0);

    cout << "Coordinates of point1: (" << point1.getX() << ", " << point1.getY() << ")" << endl;
    cout << "Coordinates of point2: (" << point2.getX() << ", " << point2.getY() << ")" << endl;

    point1.print();
    point2.print();

    return 0;
}
