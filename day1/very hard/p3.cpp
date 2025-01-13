#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    int real, imag;
public:
    Complex(int r, int i) : real(r), imag(i) {}

    Complex operator+(Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator*(Complex &c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    double magnitude() {
        return sqrt(real * real + imag * imag);
    }

    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    int type;
    cout << "Enter Operation Type (1 for Addition, 2 for Multiplication, 3 for Magnitude): ";
    cin >> type;

    int r1, i1, r2, i2;

    if (type == 1 || type == 2) {
        cout << "Enter Complex Number 1 (real and imaginary parts): ";
        cin >> r1 >> i1;
        cout << "Enter Complex Number 2 (real and imaginary parts): ";
        cin >> r2 >> i2;
        Complex c1(r1, i1), c2(r2, i2);

        if (type == 1) {
            Complex result = c1 + c2;
            cout << "Result: ";
            result.display();
        } else if (type == 2) {
            Complex result = c1 * c2;
            cout << "Result: ";
            result.display();
        }
    } else if (type == 3) {
        cout << "Enter Complex Number (real and imaginary parts): ";
        cin >> r1 >> i1;
        Complex c1(r1, i1);
        cout << "Magnitude: " << c1.magnitude() << endl;
    } else {
        cout << "Invalid operation type." << endl;
    }

    return 0;
}
