// Experiment 4: Single and multilevel inheritance: Person -> Student -> GraduateStudent
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name; int age;
public:
    Person(string n, int a) : name(n), age(a) { cout << "Person ctor\n"; }
    virtual ~Person() { cout << "Person dtor\n"; }
    void showPerson() const { cout << "Name: " << name << ", Age: " << age << "\n"; }
};

class Student : public Person {        // single inheritance
protected:
    int roll; string course;
public:
    Student(string n, int a, int r, string c) : Person(n, a), roll(r), course(c) { cout << "Student ctor\n"; }
    ~Student() { cout << "Student dtor\n"; }
    void showStudent() const { showPerson(); cout << "Roll: " << roll << ", Course: " << course << "\n"; }
};

class GraduateStudent : public Student {   // multilevel inheritance
    string thesis, supervisor;
public:
    GraduateStudent(string n, int a, int r, string c, string t, string s)
        : Student(n, a, r, c), thesis(t), supervisor(s) { cout << "GraduateStudent ctor\n"; }
    ~GraduateStudent() { cout << "GraduateStudent dtor\n"; }
    void showGrad() const {
        showStudent();
        cout << "Thesis: " << thesis << ", Supervisor: " << supervisor << "\n";
    }
};

int main() {
    cout << "== Single inheritance ==\n";
    { Student s("Anil", 20, 12, "B.Tech CSE"); s.showStudent(); }
    cout << "\n== Multilevel inheritance ==\n";
    { GraduateStudent g("Sita", 24, 5, "M.Tech CSE", "Federated Learning", "Dr. Rao"); g.showGrad(); }
    return 0;
}
