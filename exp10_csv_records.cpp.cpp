// Experiment 10: CSV reader/writer with fstream and file pointers (seekg, seekp, tellg, tellp)
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student { int id; string name; int marks; };
const string FILE_NAME = "students.csv";

// Fixed-width fields so a record can be updated in place with seekp
void writeAll(const vector<Student>& v, vector<streampos>& offsets) {
    ofstream out(FILE_NAME);
    out << "id,name,marks\n";
    for (const auto& s : v) {
        offsets.push_back(out.tellp());                        // tellp: where this record begins
        out << setw(3) << setfill('0') << s.id << ',' << setw(10) << setfill(' ') << left << s.name
            << ',' << right << setw(3) << s.marks << "\n";
    }
    cout << "Wrote " << v.size() << " records, file size via tellp = " << out.tellp() << " bytes\n";
}

vector<Student> readAll() {
    ifstream in(FILE_NAME);
    vector<Student> v; string line;
    getline(in, line);                                         // skip header
    while (getline(in, line)) {
        stringstream ss(line); string id, name, marks;
        getline(ss, id, ','); getline(ss, name, ','); getline(ss, marks, ',');
        name.erase(0, name.find_first_not_of(' ')); name.erase(name.find_last_not_of(' ') + 1);
        v.push_back({stoi(id), name, stoi(marks)});
    }
    return v;
}

int main() {
    vector<Student> students = {{1, "Asha", 88}, {2, "Ravi", 72}, {3, "Meena", 95}, {4, "Karan", 55}};
    vector<streampos> offsets;
    writeAll(students, offsets);

    cout << "\nAll records:\n";
    for (const auto& s : readAll()) cout << "  " << s.id << " " << s.name << " " << s.marks << "\n";

    // seekg + tellg: random read of record #3 (index 2)
    ifstream in(FILE_NAME);
    in.seekg(offsets[2]);
    string line; getline(in, line);
    cout << "\nRandom read (seekg) of record 3: " << line << "  | tellg now = " << in.tellg() << "\n";
    in.seekg(0, ios::end);
    cout << "File size via seekg/tellg: " << in.tellg() << " bytes\n";
    in.close();

    // seekp: update marks of record 2 in place (marks field = last 3 chars before '\n')
    fstream io(FILE_NAME, ios::in | ios::out);
    streampos marksPos = offsets[1] + streamoff(3 + 1 + 10 + 1);   // id + ',' + name + ','
    io.seekp(marksPos);
    io << setw(3) << 99;
    io.close();
    cout << "\nAfter in-place update (seekp) of record 2 marks -> 99:\n";
    for (const auto& s : readAll()) cout << "  " << s.id << " " << s.name << " " << s.marks << "\n";
    return 0;
}
