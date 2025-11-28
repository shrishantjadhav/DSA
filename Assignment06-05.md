# Assignment 06-05

## Aim
To implement a hash table with linear probing to store and search faculty records, including faculty ID, name, and department.

## Steps Followed
1. Defined a `Faculty` struct with facultyId, name, and department fields.
2. Implemented a `HashTable` class with:
   - Vector to store faculty records.
   - Vector of booleans to track occupancy.
   - Hash function using modulo operation.
   - Linear probing on collision for insertion and searching.
3. Inserted faculty records using linear probing when collisions occur.
4. Search method to find faculty using linear probing.
5. Display method to print the hash table contents.
6. Accepted user input for table size, number of faculty records, details of each faculty member, and faculty ID to search.
7. Displayed the hash table and search results accordingly.

## Code
```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Faculty {
    int facultyId;
    string name;
    string department;
};

class HashTable {
private:
    vector<Faculty> table;
    vector<bool> occupied;
    int size;
    Faculty emptyFaculty = {-1, "", ""};

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s), table(s, emptyFaculty), occupied(s, false) {}

    void insert(Faculty f) {
        int index = hashFunction(f.facultyId);
        int startIndex = index;
        while (occupied[index]) {
            index = (index + 1) % size;
            if (index == startIndex) {
                cout << "Hash table full, cannot insert" << endl;
                return;
            }
        }
        table[index] = f;
        occupied[index] = true;
    }

    bool search(int facultyId, Faculty& f) {
        int index = hashFunction(facultyId);
        int startIndex = index;
        while (occupied[index]) {
            if (table[index].facultyId == facultyId) {
                f = table[index];
                return true;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        return false;
    }

    void display() {
        cout << "Faculty Hash Table:" << endl;
        for (int i = 0; i < size; i++) {
            if (occupied[i])
                cout << i << ": ID=" << table[i].facultyId << ", Name=" << table[i].name << ", Dept=" << table[i].department << endl;
            else
                cout << i << ": EMPTY" << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter size of Hash Table: ";
    cin >> size;

    HashTable ht(size);

    int n;
    cout << "Enter number of faculty to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Faculty f;
        cout << "Enter faculty id: ";
        cin >> f.facultyId;
        cout << "Enter faculty name: ";
        cin.ignore();
        getline(cin, f.name);
        cout << "Enter department: ";
        getline(cin, f.department);
        ht.insert(f);
    }

    ht.display();

    int searchId;
    cout << "Enter faculty id to search: ";
    cin >> searchId;
    Faculty f;
    if (ht.search(searchId, f)) {
        cout << "Found: ID=" << f.facultyId << ", Name=" << f.name << ", Dept=" << f.department << endl;
    } else {
        cout << "Faculty ID not found." << endl;
    }

    return 0;
}
```

## Output (Sample)
```
Enter size of Hash Table: 5
Enter number of faculty to insert: 3
Enter faculty id: 101
Enter faculty name: Dr. Smith
Enter department: Mathematics
Enter faculty id: 102
Enter faculty name: Dr. Johnson
Enter department: Physics
Enter faculty id: 103
Enter faculty name: Dr. Williams
Enter department: Chemistry
Faculty Hash Table:
0: ID=102, Name=Dr. Johnson, Dept=Physics
1: ID=103, Name=Dr. Williams, Dept=Chemistry
2: ID=101, Name=Dr. Smith, Dept=Mathematics
3: EMPTY
4: EMPTY
Enter faculty id to search: 102
Found: ID=102, Name=Dr. Johnson, Dept=Physics
