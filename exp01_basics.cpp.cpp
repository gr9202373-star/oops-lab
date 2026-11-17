// Experiment 1: Data types, constants, variables, operators and I/O
#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
using namespace std;

int main() {
    // Data types and their sizes
    int i = 42; short s = 7; long l = 100000L; long long ll = 9000000000LL;
    float f = 3.14f; double d = 2.718281828; char c = 'A'; bool b = true;
    cout << "--- Data types ---\n";
    cout << "int: " << i << " (" << sizeof(int) << " bytes)\n"
         << "short: " << s << " (" << sizeof(short) << " bytes)\n"
         << "long: " << l << " (" << sizeof(long) << " bytes)\n"
         << "long long: " << ll << " (" << sizeof(long long) << " bytes)\n"
         << "float: " << f << " (" << sizeof(float) << " bytes)\n"
         << "double: " << d << " (" << sizeof(double) << " bytes)\n"
         << "char: " << c << " (" << sizeof(char) << " byte)\n"
         << "bool: " << boolalpha << b << " (" << sizeof(bool) << " byte)\n";
    cout << "INT_MAX = " << INT_MAX << ", DBL_MAX = " << DBL_MAX << "\n";

    // Constants
    const double PI = 3.14159;
    constexpr int DAYS = 7;
    cout << "\n--- Constants ---\nPI = " << PI << ", DAYS = " << DAYS << "\n";

    // Input
    int a, bb;
    cout << "\nEnter two integers: ";
    cin >> a >> bb;
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello, " << name << "!\n";

    // Operators
    cout << "\n--- Operators ---\n";
    cout << "a+b=" << a + bb << " a-b=" << a - bb << " a*b=" << a * bb << "\n";
    if (bb != 0) cout << "a/b=" << a / bb << " a%b=" << a % bb << "\n";
    cout << "a==b: " << (a == bb) << " a>b: " << (a > bb) << " a<b: " << (a < bb) << "\n";
    cout << "(a>0 && b>0): " << (a > 0 && bb > 0) << " (a>0 || b>0): " << (a > 0 || bb > 0)
         << " !(a>0): " << !(a > 0) << "\n";
    cout << "a&b=" << (a & bb) << " a|b=" << (a | bb) << " a^b=" << (a ^ bb)
         << " a<<1=" << (a << 1) << " a>>1=" << (a >> 1) << "\n";
    int x = a; x += 5; x *= 2;
    cout << "x after += 5, *= 2: " << x << "\n";
    cout << "x++ = " << x++ << "\n"; cout << "++x = " << ++x << "\n";
    cout << "Ternary max: " << (a > bb ? a : bb) << "\n";
    cout << "Type cast 7/2 = " << 7 / 2 << ", (double)7/2 = " << (double)7 / 2 << "\n";
    return 0;
}
