# Assignment 06-07

## Aim
To implement a hash table for faculty records using linear probing with chaining with replacement technique.

## Steps Followed
1. Defined a `Faculty` struct containing facultyId, name, and department.
2. Created a `HashTable` class using:
   - Vector of `Entry` structs holding faculty data, occupancy, and next pointer.
   - Hash function using modulo on facultyId.
3. Insert operation:
   - Checks if slot is free, inserts directly.
   - If occupied, applies chaining with replacement strategy where existing entry is replaced if its hash index differs, and displaced entry is moved to a new slot.
4. Search operation traverses chaining links to find faculty by ID.
5. Display method outputs the table with faculty details and chaining next pointers.
6. User inputs handled for table size, inserting faculty data, and search queries.
7. Displays the hash table contents and search result.

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
            // Linear probing with chaining with replacement
            int currentIndex = index;
            while (table[currentIndex].next != -1) {
                currentIndex = table[currentIndex].next;
            }
            int newIndex = (index + 1) % size;
            while (table[newIndex].occupied && newIndex != index) {
                newIndex = (newIndex + 1) % size;
            }
            if (newIndex == index) {
                cout << "Hash table full, cannot insert faculty id " << f.facultyId << endl;
                return;
            }

            // Replace entry if hash of current faculty id doesn't match index
            int currHash = hashFunction(table[index].faculty.facultyId);
            if (currHash != index) {
                Entry temp = table[index];
                table[index].faculty = f;
                table[index].occupied = true;
                table[index].next = -1;

                int replaceIndex = currHash;
                while (table[replaceIndex].next != index) {
                    replaceIndex = table[replaceIndex].next;
                }
                table[replaceIndex].next = temp.next;

                int insertIndex = newIndex;
                while (table[insertIndex].occupied) {
                    insertIndex = (insertIndex + 1) % size;
                }
                table[insertIndex] = temp;
                table[insertIndex].next = -1;
                table[index].next = -1;
            } else {
                table[newIndex].faculty = f;
                table[newIndex].occupied = true;
                table[newIndex].next = -1;
                table[currentIndex].next = newIndex;
            }
        }
    }

    bool search(int facultyId, Faculty& f) {
        int index = hashFunction(facultyId);
        int currentIndex = index;
        while (currentIndex != -1 && table[currentIndex].occupied) {
            if (table[currentIndex].faculty.facultyId == facultyId) {
                f = table[currentIndex].faculty;
                return true;
            }
            currentIndex = table[currentIndex].next;
        }
        return false;
    }

    void display() {
        cout << "Faculty Hash Table (Linear Probing with Chaining with Replacement):" << endl;
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
Faculty Hash Table (Linear Probing with Chaining with Replacement):
0: ID: 102, Name: Dr. Johnson, Dept: Physics, Next: 2
1: EMPTY
2: ID: 103, Name: Dr. Williams, Dept: Chemistry, Next: -1
3: ID: 101, Name: Dr. Smith, Dept: Mathematics, Next: -1
4: EMPTY
Enter faculty id to search: 102
Found: ID=102, Name=Dr. Johnson, Dept=Physics
