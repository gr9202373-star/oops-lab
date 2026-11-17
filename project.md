# school managment system
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class
class Person {
protected:
    int id;
    string name;
    int age;

public:
    Person(int id, string name, int age) {
        this->id = id;
        this->name = name;
        this->age = age;
    }

    int getId() { return id; }

    virtual void display() {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age;
    }
};

// Student inherits from Person
class Student : public Person {
private:
    string grade;
    double marks;

public:
    Student(int id, string name, int age, string grade, double marks)
        : Person(id, name, age) {
        this->grade = grade;
        this->marks = marks;
    }

    void display() {
        Person::display();
        cout << ", Class: " << grade << ", Marks: " << marks << endl;
    }
};

// Teacher inherits from Person
class Teacher : public Person {
private:
    string subject;

public:
    Teacher(int id, string name, int age, string subject)
        : Person(id, name, age) {
        this->subject = subject;
    }

    void display() {
        Person::display();
        cout << ", Subject: " << subject << endl;
    }
};

// School manages students and teachers
class School {
private:
    vector<Student> students;
    vector<Teacher> teachers;

public:
    void addStudent() {
        int id, age;
        string name, grade;
        double marks;

        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter class: ";
        cin >> grade;
        cout << "Enter marks: ";
        cin >> marks;

        students.push_back(Student(id, name, age, grade, marks));
        cout << "Student added!\n";
    }

    void addTeacher() {
        int id, age;
        string name, subject;

        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter subject: ";
        cin >> subject;

        teachers.push_back(Teacher(id, name, age, subject));
        cout << "Teacher added!\n";
    }

    void showStudents() {
        cout << "\n--- Students ---\n";
        if (students.empty()) cout << "No students.\n";
        for (int i = 0; i < students.size(); i++)
            students[i].display();
    }

    void showTeachers() {
        cout << "\n--- Teachers ---\n";
        if (teachers.empty()) cout << "No teachers.\n";
        for (int i = 0; i < teachers.size(); i++)
            teachers[i].display();
    }

    void deleteStudent() {
        int id;
        cout << "Enter student ID to delete: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                cout << "Student deleted!\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

int main() {
    School school;
    int choice;

    do {
        cout << "\n===== School Management =====\n";
        cout << "1. Add Student\n";
        cout << "2. Add Teacher\n";
        cout << "3. Show Students\n";
        cout << "4. Show Teachers\n";
        cout << "5. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: school.addStudent(); break;
            case 2: school.addTeacher(); break;
            case 3: school.showStudents(); break;
            case 4: school.showTeachers(); break;
            case 5: school.deleteStudent(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
```
