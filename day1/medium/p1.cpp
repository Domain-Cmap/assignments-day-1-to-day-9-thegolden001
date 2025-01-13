#include <iostream>
using namespace std;

const double PI = 3.14159;

double area(double radius) {
    return PI * radius * radius;
}

double area(double length, double breadth) {
    return length * breadth;
}

double area(double base, double height, bool isTriangle) {
    return 0.5 * base * height;
}

int main() {
    double radius, length, breadth, base, height;

    cout << "Enter the radius of the circle: ";
    cin >> radius;

    cout << "Enter the length and breadth of the rectangle: ";
    cin >> length >> breadth;

    cout << "Enter the base and height of the triangle: ";
    cin >> base >> height;

    cout << area(radius) << endl;
    cout << area(length, breadth) << endl;
    cout << area(base, height, true) << endl;

    return 0;
}
