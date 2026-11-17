// Experiment 8: STL containers and algorithms on a student marks dataset
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

struct Student { string name; int marks; };

int main() {
    vector<Student> v = {{"Asha", 88}, {"Ravi", 72}, {"Meena", 95}, {"Karan", 55},
                         {"Divya", 67}, {"Sam", 91}, {"Neha", 38}};

    // sort descending by marks
    sort(v.begin(), v.end(), [](const Student& a, const Student& b) { return a.marks > b.marks; });
    cout << "Rank list:\n";
    for (const auto& s : v) cout << "  " << s.name << " - " << s.marks << "\n";

    // find_if: first student below pass marks
    auto it = find_if(v.begin(), v.end(), [](const Student& s) { return s.marks < 40; });
    if (it != v.end()) cout << "Failed student: " << it->name << " (" << it->marks << ")\n";

    // transform: add 5 grace marks (capped at 100)
    vector<int> graced(v.size());
    transform(v.begin(), v.end(), graced.begin(), [](const Student& s) { return min(100, s.marks + 5); });
    cout << "Marks after +5 grace: ";
    for (int m : graced) cout << m << ' ';
    cout << "\n";

    // accumulate, min/max
    double avg = accumulate(v.begin(), v.end(), 0.0, [](double a, const Student& s) { return a + s.marks; }) / v.size();
    auto [mn, mx] = minmax_element(v.begin(), v.end(), [](const Student& a, const Student& b) { return a.marks < b.marks; });
    cout << "Average: " << avg << ", Highest: " << mx->name << ", Lowest: " << mn->name << "\n";

    // map: ordered by name
    map<string, int> ordered;
    for (const auto& s : v) ordered[s.name] = s.marks;
    cout << "\nmap (sorted by name):\n";
    for (const auto& [n, m] : ordered) cout << "  " << n << ": " << m << "\n";

    // unordered_map: O(1) lookup
    unordered_map<string, int> lookup(ordered.begin(), ordered.end());
    string q = "Meena";
    auto f = lookup.find(q);
    cout << "\nunordered_map lookup " << q << ": " << (f != lookup.end() ? to_string(f->second) : "not found") << "\n";

    // count_if
    cout << "Students with distinction (>=75): "
         << count_if(v.begin(), v.end(), [](const Student& s) { return s.marks >= 75; }) << "\n";
    return 0;
}
