#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape {
private:
    double length, breadth;
public:
    Rectangle(double l, double b) : length(l), breadth(b) {}
    double getArea() override {
        return length * breadth;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() override {
        return 3.14159 * radius * radius;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    int type;
    cout << "Enter shape type (1 for Rectangle, 2 for Circle, 3 for Triangle): ";
    cin >> type;

    Shape* shape = nullptr;

    if (type == 1) {
        double length, breadth;
        cout << "Enter length and breadth for Rectangle: ";
        cin >> length >> breadth;
        shape = new Rectangle(length, breadth);
    } else if (type == 2) {
        double radius;
        cout << "Enter radius for Circle: ";
        cin >> radius;
        shape = new Circle(radius);
    } else if (type == 3) {
        double base, height;
        cout << "Enter base and height for Triangle: ";
        cin >> base >> height;
        shape = new Triangle(base, height);
    }

    if (shape != nullptr) {
        cout << "The area is: " << shape->getArea() << endl;
        delete shape;
    }

    return 0;
}
