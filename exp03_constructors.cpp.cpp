// Experiment 3: All constructor types + Rule of 5. Verify with: valgrind --leak-check=full ./exp03
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

class Buffer {
    int* data; size_t size;
public:
    Buffer() : data(nullptr), size(0) { cout << "Default ctor\n"; }
    explicit Buffer(size_t n) : data(new int[n]()), size(n) { cout << "Parameterized ctor (" << n << ")\n"; }
    Buffer(const Buffer& o) : data(new int[o.size]), size(o.size) {          // Copy ctor
        copy(o.data, o.data + o.size, data); cout << "Copy ctor\n";
    }
    Buffer(Buffer&& o) noexcept : data(o.data), size(o.size) {               // Move ctor
        o.data = nullptr; o.size = 0; cout << "Move ctor\n";
    }
    Buffer& operator=(const Buffer& o) {                                     // Copy assignment
        cout << "Copy assignment\n";
        if (this != &o) {
            int* nd = new int[o.size];
            copy(o.data, o.data + o.size, nd);
            delete[] data; data = nd; size = o.size;
        }
        return *this;
    }
    Buffer& operator=(Buffer&& o) noexcept {                                 // Move assignment
        cout << "Move assignment\n";
        if (this != &o) { delete[] data; data = o.data; size = o.size; o.data = nullptr; o.size = 0; }
        return *this;
    }
    ~Buffer() { delete[] data; cout << "Destructor (size " << size << ")\n"; }
    void fill(int v) { for (size_t i = 0; i < size; ++i) data[i] = v; }
    void print() const { for (size_t i = 0; i < size; ++i) cout << data[i] << ' '; cout << "\n"; }
};

int main() {
    Buffer a;                       // default
    Buffer b(3); b.fill(7);         // parameterized
    Buffer c(b);                    // copy
    Buffer d(std::move(b));         // move
    a = c;                          // copy assignment
    Buffer e; e = std::move(d);     // move assignment
    a.print(); c.print(); e.print();
    return 0;
}
