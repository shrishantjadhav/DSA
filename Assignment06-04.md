# Assignment 06-04

## Aim
To implement a student records management system which allows adding student records and searching students by roll number.

## Steps Followed
1. Defined a `Student` struct with roll number, name, and marks.
2. Created a `StudentRecords` class to:
   - Store a vector of Student records.
   - Add a student record.
   - Find a student by roll number.
   - Display a student's details by roll number.
3. Implemented `addStudent` to add student data.
4. Implemented `findStudent` to get pointer to student object by roll number.
5. Implemented `displayStudent` to print the details or show not found message.
6. Supported user inputs for number of students, student details, and roll number to search.
7. Displayed the searched student data or appropriate error message.

## Code
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    int marks;
};

class StudentRecords {
private:
    vector<Student> records;

public:
    void addStudent(int rollNo, const string& name, int marks) {
        records.push_back({rollNo, name, marks});
    }

    Student* findStudent(int rollNo) {
        for (auto& student : records) {
            if (student.rollNo == rollNo) {
                return &student;
            }
        }
        return nullptr;
    }

    void displayStudent(int rollNo) {
        Student* student = findStudent(rollNo);
        if (student) {
            cout << "Roll Number: " << student->rollNo << endl;
            cout << "Name: " << student->name << endl;
            cout << "Marks: " << student->marks << endl;
        } else {
            cout << "Student with roll number " << rollNo << " not found." << endl;
        }
    }
};

int main() {
    StudentRecords sr;

    int n;
    cout << "Enter number of students to add: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int rollNo, marks;
        string name;
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter marks: ";
        cin >> marks;
        sr.addStudent(rollNo, name, marks);
    }

    int searchRollNo;
    cout << "Enter roll number to search: ";
    cin >> searchRollNo;
    sr.displayStudent(searchRollNo);

    return 0;
}
```

## Output (Sample)
```
Enter number of students to add: 2
Enter roll number: 101
Enter name: Alice
Enter marks: 85
Enter roll number: 102
Enter name: Bob
Enter marks: 90
Enter roll number to search: 102
Roll Number: 102
Name: Bob
Marks: 90
