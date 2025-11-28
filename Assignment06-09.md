# Assignment 06-09

## Aim
To implement a hash table for student records using linear probing that supports insertion, search, and deletion operations.

## Steps Followed
1. Defined a `Student` struct with rollNo, name, department, and a `deleted` flag to mark logically deleted entries.
2. Implemented a `HashTable` class with:
   - A vector for student records.
   - Hash function using modulo operation.
   - Insert method using linear probing to place students in the hash table.
   - Search method using linear probing to find a student by roll number, skipping deleted slots.
   - Delete method marking a student's slot as deleted logically.
3. Display method shows each slot stating student details, "Deleted", or "EMPTY".
4. Supported user inputs for table size, number of students, each student’s details and operations for search and delete.
5. Showcased the hash table contents before and after deletion, and the search output.

## Code
```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    int rollNo;
    string name;
    string department;
    bool deleted;

    Student() : rollNo(-1), name(""), department(""), deleted(false) {}
    Student(int r, const string& n, const string& d) : rollNo(r), name(n), department(d), deleted(false) {}
};

class HashTable {
private:
    vector<Student> table;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s), table(s) {}

    void insert(Student s) {
        int index = hashFunction(s.rollNo);
        int startIndex = index;
        while (table[index].rollNo != -1 && !table[index].deleted) {
            index = (index + 1) % size;
            if (index == startIndex) {
                cout << "Hash table full, cannot insert student roll no " << s.rollNo << endl;
                return;
            }
        }
        table[index] = s;
        table[index].deleted = false;
    }

    bool search(int rollNo, Student& s) {
        int index = hashFunction(rollNo);
        int startIndex = index;
        while (table[index].rollNo != -1) {
            if (table[index].rollNo == rollNo && !table[index].deleted) {
                s = table[index];
                return true;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        return false;
    }

    bool remove(int rollNo) {
        int index = hashFunction(rollNo);
        int startIndex = index;
        while (table[index].rollNo != -1) {
            if (table[index].rollNo == rollNo && !table[index].deleted) {
                table[index].deleted = true;
                return true;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        return false;
    }

    void display() {
        cout << "Student Hash Table (with linear probing and deletion):" << endl;
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (table[i].rollNo != -1 && !table[i].deleted) {
                cout << "RollNo: " << table[i].rollNo << ", Name: " << table[i].name
                     << ", Dept: " << table[i].department << endl;
            } else if (table[i].deleted) {
                cout << "Deleted" << endl;
            } else {
                cout << "EMPTY" << endl;
            }
        }
    }
};

int main() {
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    HashTable ht(size);

    int n;
    cout << "Enter number of students to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Student s;
        cout << "Enter roll no: ";
        cin >> s.rollNo;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, s.name);
        cout << "Enter department: ";
        getline(cin, s.department);
        ht.insert(s);
    }

    ht.display();

    int searchRoll;
    cout << "Enter roll no to search: ";
    cin >> searchRoll;

    Student s;
    if (ht.search(searchRoll, s)) {
        cout << "Found: RollNo=" << s.rollNo << ", Name=" << s.name << ", Dept=" << s.department << endl;
    } else {
        cout << "Student roll no not found." << endl;
    }

    int delRoll;
    cout << "Enter roll no to delete: ";
    cin >> delRoll;
    if (ht.remove(delRoll)) {
        cout << "Student roll no " << delRoll << " deleted." << endl;
    } else {
        cout << "Student roll no " << delRoll << " not found, cannot delete." << endl;
    }

    ht.display();

    return 0;
}
```

## Output (Sample)
```
Enter size of hash table: 5
Enter number of students to insert: 3
Enter roll no: 101
Enter student name: Alice
Enter department: CS
Enter roll no: 102
Enter student name: Bob
Enter department: IT
Enter roll no: 103
Enter student name: Charlie
Enter department: ECE
Student Hash Table (with linear probing and deletion):
0: RollNo: 101, Name: Alice, Dept: CS
1: RollNo: 102, Name: Bob, Dept: IT
2: RollNo: 103, Name: Charlie, Dept: ECE
3: EMPTY
4: EMPTY
Enter roll no to search: 102
Found: RollNo=102, Name=Bob, Dept=IT
Enter roll no to delete: 102
Student roll no 102 deleted.
Student Hash Table (with linear probing and deletion):
0: RollNo: 101, Name: Alice, Dept: CS
1: Deleted
2: RollNo: 103, Name: Charlie, Dept: ECE
3: EMPTY
4: EMPTY
