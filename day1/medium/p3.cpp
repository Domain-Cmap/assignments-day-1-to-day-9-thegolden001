#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.14159;

class Shape {
public:
    virtual double area() = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        return PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, breadth;
public:
    Rectangle(double l, double b) : length(l), breadth(b) {}
    double area() override {
        return length * breadth;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() override {
        return 0.5 * base * height;
    }
};

int main() {
    double radius, length, breadth, base, height;

    cout << "Enter radius for Circle: ";
    cin >> radius;

    cout << "Enter length and breadth for Rectangle: ";
    cin >> length >> breadth;

    cout << "Enter base and height for Triangle: ";
    cin >> base >> height;

    Circle circle(radius);
    Rectangle rectangle(length, breadth);
    Triangle triangle(base, height);

    cout << fixed << setprecision(2);

    cout << "Circle Area: " << circle.area() << endl;
    cout << "Rectangle Area: " << rectangle.area() << endl;
    cout << "Triangle Area: " << triangle.area() << endl;

    return 0;
}
