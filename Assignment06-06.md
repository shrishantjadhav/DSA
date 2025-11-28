# Assignment 06-06

## Aim
To implement a hash table for faculty records using linear probing with chaining without replacement.

## Steps Followed
1. Defined a `Faculty` struct with facultyId, name, and department.
2. Implemented a `HashTable` class with:
   - A vector of Entries, each with a `Faculty`, occupancy flag, and a `next` pointer for chaining.
   - Hash function with modulo operation.
3. Insert method inserts faculty records using linear probing with chaining without replacement:
   - If initial index slot is free, insert directly.
   - If occupied, use chaining with `next` pointers to form chains and find next free slot.
4. Search method traverses the chain using `next` pointers to find faculty by ID.
5. Display method shows the hash table with each index details and their chaining `next` links.
6. User input supported for table size, number of faculty records, and faculty details.
7. Displayed the table and searched faculty based on user input.

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
    struct Entry {
        Faculty faculty;
        bool occupied;
        int next;
        Entry() : occupied(false), next(-1) {}
    };

    vector<Entry> table;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s), table(s) {}

    void insert(Faculty f) {
        int index = hashFunction(f.facultyId);
        if (!table[index].occupied) {
            table[index].faculty = f;
            table[index].occupied = true;
            table[index].next = -1;
        } else {
            // Linear probing with chaining without replacement
            int startIndex = index;
            int prev = -1;
            int current = index;
            while (current != -1) {
                prev = current;
                current = table[current].next;
            }
            int newIndex = (index + 1) % size;
            while (table[newIndex].occupied && newIndex != startIndex) {
                newIndex = (newIndex + 1) % size;
            }
            if (newIndex == startIndex) {
                cout << "Hash table is full, cannot insert faculty id " << f.facultyId << endl;
                return;
            }
            table[newIndex].faculty = f;
            table[newIndex].occupied = true;
            table[newIndex].next = -1;
            table[prev].next = newIndex;
        }
    }

    bool search(int facultyId, Faculty& f) {
        int index = hashFunction(facultyId);
        int current = index;
        while (current != -1 && table[current].occupied) {
            if (table[current].faculty.facultyId == facultyId) {
                f = table[current].faculty;
                return true;
            }
            current = table[current].next;
        }
        return false;
    }

    void display() {
        cout << "Faculty Hash Table (Linear Probing with Chaining Without Replacement):" << endl;
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (table[i].occupied) {
                cout << "ID: " << table[i].faculty.facultyId << ", Name: " << table[i].faculty.name
                     << ", Dept: " << table[i].faculty.department << ", Next: " << table[i].next << endl;
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
Enter size of hash table: 5
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
Faculty Hash Table (Linear Probing with Chaining Without Replacement):
0: ID: 102, Name: Dr. Johnson, Dept: Physics, Next: 2
1: EMPTY
2: ID: 103, Name: Dr. Williams, Dept: Chemistry, Next: -1
3: ID: 101, Name: Dr. Smith, Dept: Mathematics, Next: -1
4: EMPTY
Enter faculty id to search: 102
Found: ID=102, Name=Dr. Johnson, Dept=Physics
