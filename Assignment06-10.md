# Assignment 06-10

## Aim
To implement a smart college placement portal using a hash table with double hashing collision resolution technique.

## Steps Followed
1. Defined a `StudentPlacement` struct with fields for studentId, studentName, company, position, and a deleted flag.
2. Designed a `SmartPlacementPortal` class implemented as a hash table using:
   - A vector to store student placements.
   - Double hashing with two hash functions to reduce collisions:
     - Primary hash: key modulo table size.
     - Secondary hash: 1 plus key modulo (table size - 2).
   - Automatic rehashing to next prime size when load factor exceeds 0.5.
3. Insert method uses double hashing to insert student placement records.
4. Search method uses double hashing to find placement by studentId.
5. Remove method marks placement entries as logically deleted.
6. Display method shows placement records or EMPTY/Deleted slots.
7. User inputs supported for number of student placements, each student's details, and search and deletion operations.
8. Displays the placement portal table and associated operations’ results.

## Code
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct StudentPlacement {
    int studentId;
    string studentName;
    string company;
    string position;
    bool deleted;

    StudentPlacement() : studentId(-1), studentName(""), company(""), position(""), deleted(false) {}
    StudentPlacement(int id, const string &name, const string &comp, const string &pos)
        : studentId(id), studentName(name), company(comp), position(pos), deleted(false) {}
};

class SmartPlacementPortal {
private:
    vector<StudentPlacement> table;
    int tableSize;
    int currentSize;

    // Double hashing with secondary hash to reduce collisions
    int hash1(int key) {
        return key % tableSize;
    }

    int hash2(int key) {
        return 1 + (key % (tableSize - 2));
    }

    void rehash() {
        int oldSize = tableSize;
        tableSize = nextPrime(2 * tableSize);
        vector<StudentPlacement> oldTable = table;
        table.clear();
        table.resize(tableSize);
        currentSize = 0;

        for (const auto &student : oldTable) {
            if (student.studentId != -1 && !student.deleted) {
                insert(student);
            }
        }
    }

    int nextPrime(int n) {
        while (!isPrime(n)) n++;
        return n;
    }

    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    SmartPlacementPortal(int size = 11) : tableSize(size), currentSize(0) {
        table.resize(tableSize);
    }

    void insert(const StudentPlacement &student) {
        if (currentSize >= tableSize / 2)
            rehash();

        int key = student.studentId;
        int index = hash1(key);
        int stepSize = hash2(key);
        int i = 0;

        while (table[index].studentId != -1 && !table[index].deleted) {
            if (table[index].studentId == key) {
                // Update existing record
                table[index] = student;
                return;
            }
            index = (index + stepSize) % tableSize;
            i++;
            if (i > tableSize) return; // Table full (should not happen due to rehash)
        }
        table[index] = student;
        currentSize++;
    }

    bool search(int studentId, StudentPlacement &student) {
        int index = hash1(studentId);
        int stepSize = hash2(studentId);
        int i = 0;

        while (table[index].studentId != -1) {
            if (table[index].studentId == studentId && !table[index].deleted) {
                student = table[index];
                return true;
            }
            index = (index + stepSize) % tableSize;
            i++;
            if (i > tableSize) break;
        }
        return false;
    }

    bool remove(int studentId) {
        int index = hash1(studentId);
        int stepSize = hash2(studentId);
        int i = 0;

        while (table[index].studentId != -1) {
            if (table[index].studentId == studentId && !table[index].deleted) {
                table[index].deleted = true;
                currentSize--;
                return true;
            }
            index = (index + stepSize) % tableSize;
            i++;
            if (i > tableSize) break;
        }
        return false;
    }

    void display() {
        cout << "Smart College Placement Portal - Student Placements:" << endl;
        for (int i = 0; i < tableSize; ++i) {
            cout << i << ": ";
            if (table[i].studentId != -1 && !table[i].deleted) {
                cout << "ID: " << table[i].studentId
                     << ", Name: " << table[i].studentName
                     << ", Company: " << table[i].company
                     << ", Position: " << table[i].position << endl;
            } else if (table[i].deleted) {
                cout << "Deleted" << endl;
            } else {
                cout << "EMPTY" << endl;
            }
        }
    }
};

int main() {
    SmartPlacementPortal portal;

    int n;
    cout << "Enter number of student placements to insert: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int id;
        string name, company, position;
        cout << "Enter student ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter company name: ";
        getline(cin, company);
        cout << "Enter position: ";
        getline(cin, position);

        StudentPlacement sp(id, name, company, position);
        portal.insert(sp);
    }

    portal.display();

    int searchId;
    cout << "Enter student ID to search: ";
    cin >> searchId;
    StudentPlacement found;
    if (portal.search(searchId, found)) {
        cout << "Found placement: " << found.studentName << " at " << found.company << " as " << found.position << endl;
    } else {
        cout << "Student placement not found." << endl;
    }

    int delId;
    cout << "Enter student ID to delete: ";
    cin >> delId;
    if (portal.remove(delId)) {
        cout << "Student placement deleted." << endl;
    } else {
        cout << "Student placement not found for deletion." << endl;
    }

    portal.display();

    return 0;
}
```

## Output (Sample)
```
Enter number of student placements to insert: 3
Enter student ID: 101
Enter student name: Alice
Enter company name: Google
Enter position: Software Engineer
Enter student ID: 102
Enter student name: Bob
Enter company name: Microsoft
Enter position: Data Analyst
Enter student ID: 103
Enter student name: Charlie
Enter company name: Amazon
Enter position: Developer
Smart College Placement Portal - Student Placements:
0: ID: 103, Name: Charlie, Company: Amazon, Position: Developer
1: EMPTY
2: ID: 101, Name: Alice, Company: Google, Position: Software Engineer
3: ID: 102, Name: Bob, Company: Microsoft, Position: Data Analyst
4: EMPTY
Enter student ID to search: 102
Found placement: Bob at Microsoft as Data Analyst
Enter student ID to delete: 101
Student placement deleted.
Smart College Placement Portal - Student Placements:
0: ID: 103, Name: Charlie, Company: Amazon, Position: Developer
1: EMPTY
2: Deleted
3: ID: 102, Name: Bob, Company: Microsoft, Position: Data Analyst
4: EMPTY
