// Experiment 5: Runtime polymorphism with virtual functions and an abstract base class
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <string>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;                 // pure virtual -> abstract class
    virtual string name() const = 0;
    virtual ~Shape() = default;
};
class Circle : public Shape {
    double r;
public:
    explicit Circle(double r) : r(r) {}
    double area() const override { return M_PI * r * r; }
    string name() const override { return "Circle"; }
};
class Rectangle : public Shape {
    double l, w;
public:
    Rectangle(double l, double w) : l(l), w(w) {}
    double area() const override { return l * w; }
    string name() const override { return "Rectangle"; }
};
class Triangle : public Shape {
    double b, h;
public:
    Triangle(double b, double h) : b(b), h(h) {}
    double area() const override { return 0.5 * b * h; }
    string name() const override { return "Triangle"; }
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(5));
    shapes.push_back(make_unique<Rectangle>(4, 6));
    shapes.push_back(make_unique<Triangle>(3, 8));
    for (const auto& s : shapes)                       // dispatched at runtime
        cout << s->name() << " area = " << s->area() << "\n";
    // Shape s;  // ERROR: cannot instantiate abstract class
    return 0;
}
