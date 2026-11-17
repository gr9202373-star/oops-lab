// Experiment 7: Generic Stack using templates
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack {
    vector<T> items;
public:
    void push(const T& v) { items.push_back(v); }
    void pop() {
        if (items.empty()) throw underflow_error("Stack underflow");
        items.pop_back();
    }
    T& top() {
        if (items.empty()) throw underflow_error("Stack is empty");
        return items.back();
    }
    bool empty() const { return items.empty(); }
    size_t size() const { return items.size(); }
};

template <typename T>
void test(const string& label, const vector<T>& vals) {
    Stack<T> s;
    cout << "Stack<" << label << ">: pushing ";
    for (const auto& v : vals) { s.push(v); cout << v << ' '; }
    cout << "\n  size=" << s.size() << ", popping: ";
    while (!s.empty()) { cout << s.top() << ' '; s.pop(); }
    cout << "\n";
}

int main() {
    test<int>("int", {1, 2, 3, 4});
    test<float>("float", {1.5f, 2.5f, 3.5f});
    test<string>("std::string", {"alpha", "beta", "gamma"});
    try { Stack<int> e; e.pop(); } catch (const exception& ex) { cout << "Caught: " << ex.what() << "\n"; }
    return 0;
}
