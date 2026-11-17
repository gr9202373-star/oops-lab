// Experiment 6: Compile-time polymorphism: function overloading + operator overloading
#include <iostream>
using namespace std;

// Function overloading
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
int add(int a, int b, int c) { return a + b + c; }

class Complex {
    double re, im;
public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}
    Complex operator+(const Complex& o) const { return {re + o.re, im + o.im}; }
    Complex operator-(const Complex& o) const { return {re - o.re, im - o.im}; }
    Complex operator*(const Complex& o) const { return {re * o.re - im * o.im, re * o.im + im * o.re}; }
    bool operator==(const Complex& o) const { return re == o.re && im == o.im; }
    Complex& operator+=(const Complex& o) { re += o.re; im += o.im; return *this; }
    Complex operator-() const { return {-re, -im}; }
    friend ostream& operator<<(ostream& os, const Complex& c) {
        return os << c.re << (c.im < 0 ? " - " : " + ") << (c.im < 0 ? -c.im : c.im) << "i";
    }
    friend istream& operator>>(istream& is, Complex& c) { return is >> c.re >> c.im; }
};

int main() {
    cout << "add(2,3)=" << add(2, 3) << ", add(2.5,3.5)=" << add(2.5, 3.5)
         << ", add(1,2,3)=" << add(1, 2, 3) << "\n";
    Complex a(3, 4), b(1, -2);
    cout << "a = " << a << ", b = " << b << "\n";
    cout << "a + b = " << a + b << "\n";
    cout << "a - b = " << a - b << "\n";
    cout << "a * b = " << a * b << "\n";
    cout << "-a    = " << -a << "\n";
    a += b; cout << "a += b -> " << a << "\n";
    cout << "a == b ? " << (a == b ? "yes" : "no") << "\n";
    return 0;
}
