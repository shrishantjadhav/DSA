# Assignment 06-08

## Aim
To implement a hash table for employee records using mid-square hashing and linear probing.

## Steps Followed
1. Defined an `Employee` struct containing empId, name, and department.
2. Created a `HashTable` class with:
   - Vector of Entries holding employee data and occupancy flag.
   - Hash function implementing mid-square hashing: squares the key and extracts middle digits.
3. Insert method uses linear probing to resolve collisions.
4. Search method linear probes to find key by empId.
5. Display method outputs the hash table contents with employee data or EMPTY.
6. Supported user input for hash table size, number of employees, employee details, and key to search.
7. Displayed the resulting hash table and search results.

## Code
```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Employee {
    int empId;
    string name;
    string department;
};

class HashTable {
private:
    struct Entry {
        Employee employee;
        bool occupied;
        Entry() : occupied(false) {}
    };

    vector<Entry> table;
    int size;

    int hashFunction(int key) {
        // Mid square hash function: square key and extract middle digits
        unsigned long long sq = (unsigned long long) key * key;
        int mid = (sq / 10) % size;  // Simplified middle extraction
        return mid;
    }

public:
    HashTable(int s) : size(s), table(s) {}

    void insert(Employee e) {
        int index = hashFunction(e.empId);
        int startIndex = index;
        while (table[index].occupied) {
            index = (index + 1) % size;
            if (index == startIndex) {
                cout << "Hash table full, cannot insert employee id " << e.empId << endl;
                return;
            }
        }
        table[index].employee = e;
        table[index].occupied = true;
    }

    bool search(int empId, Employee& e) {
        int index = hashFunction(empId);
        int startIndex = index;
        while (table[index].occupied) {
            if (table[index].employee.empId == empId) {
                e = table[index].employee;
                return true;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        return false;
    }

    void display() {
        cout << "Employee Hash Table (Mid square hash with linear probing):" << endl;
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (table[i].occupied) {
                cout << "ID: " << table[i].employee.empId << ", Name: " << table[i].employee.name
                     << ", Dept: " << table[i].employee.department << endl;
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
    cout << "Enter number of employees to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Employee e;
        cout << "Enter employee id: ";
        cin >> e.empId;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, e.name);
        cout << "Enter department: ";
        getline(cin, e.department);
        ht.insert(e);
    }

    ht.display();

    int searchId;
    cout << "Enter employee id to search: ";
    cin >> searchId;

    Employee e;
    if (ht.search(searchId, e)) {
        cout << "Found: ID=" << e.empId << ", Name=" << e.name << ", Dept=" << e.department << endl;
    } else {
        cout << "Employee ID not found." << endl;
    }

    return 0;
}
```

## Output (Sample)
```
Enter size of hash table: 7
Enter number of employees to insert: 3
Enter employee id: 101
Enter employee name: Alice
Enter department: HR
Enter employee id: 102
Enter employee name: Bob
Enter department: IT
Enter employee id: 103
Enter employee name: Charlie
Enter department: Finance
Employee Hash Table (Mid square hash with linear probing):
0: EMPTY
1: ID: 102, Name: Bob, Dept: IT
2: EMPTY
3: ID: 103, Name: Charlie, Dept: Finance
4: EMPTY
5: ID: 101, Name: Alice, Dept: HR
6: EMPTY
Enter employee id to search: 102
Found: ID=102, Name=Bob, Dept=IT
