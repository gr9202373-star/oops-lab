# C++ OOP Lab Experiments

| # | File | Topic |
|---|------|-------|
| 1 | exp01_basics.cpp | Data types, constants, variables, operators, I/O |
| 2 | exp02_bankaccount.cpp | Class hierarchy, access specifiers, member functions |
| 3 | exp03_constructors.cpp | Constructors, Rule of 5, Valgrind |
| 4 | exp04_inheritance.cpp | Single & multilevel inheritance |
| 5 | exp05_shapes.cpp | Virtual functions, abstract class |
| 6 | exp06_complex.cpp | Function & operator overloading |
| 7 | exp07_stack_template.cpp | Template Stack |
| 8 | exp08_stl_marks.cpp | STL containers & algorithms |
| 9 | exp09_bank_exceptions.cpp | Custom exception hierarchy |
| 10 | exp10_csv_records.cpp | fstream CSV, seekg/seekp/tellg/tellp |

## Build & run
```
make            # builds all (g++ -std=c++17)
./exp05_shapes
make clean
```
Memory check (Exp 3): `valgrind --leak-check=full ./exp03_constructors`
