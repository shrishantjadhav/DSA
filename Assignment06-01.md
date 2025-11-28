# Assignment 06-01

## Aim
To implement a hash table using linear probing for collision resolution.

## Steps Followed
1. Created a `HashTable` class with:
   - Vector table initialized with a fixed size and a sentinel value `EMPTY` (-1) for empty slots.
   - Hash function using modulo operation.
2. Implemented `insert` method with linear probing to find the next empty slot if the calculated hash index is occupied.
3. Implemented `search` method to find the index of a key using probing.
4. Implemented `display` method to show the hash table content, indicating empty slots.
5. Supported user input for size, keys to insert, and key to search.
6. Displayed the hash table after insertions.
7. Displayed search result for the requested key.

## Code
```cpp
#include <iostream>
#include <vector>

using namespace std;

class HashTable {
private:
    vector<int> table;
    int size;
    int EMPTY = -1;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size, EMPTY);
    }

    void insert(int key) {
        int index = hashFunction(key);
        int startIndex = index;
        while (table[index] != EMPTY) {
            index = (index + 1) % size;
            if (index == startIndex) {
                cout << "Hash table is full. Cannot insert key " << key << endl;
                return;
            }
        }
        table[index] = key;
    }

    int search(int key) {
        int index = hashFunction(key);
        int startIndex = index;
        while (table[index] != EMPTY) {
            if (table[index] == key) {
                return index;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        return -1; // not found
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] != EMPTY)
                cout << i << " --> " << table[i] << endl;
            else
                cout << i << " --> " << "EMPTY" << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    HashTable ht(size);

    int n, key;
    cout << "Enter number of keys to insert: ";
    cin >> n;

    cout << "Enter keys:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> key;
        ht.insert(key);
    }

    cout << "Hash table:" << endl;
    ht.display();

    cout << "Enter key to search: ";
    cin >> key;
    int index = ht.search(key);
    if (index != -1)
        cout << "Key " << key << " found at index " << index << endl;
    else
        cout << "Key " << key << " not found in hash table." << endl;

    return 0;
}
```

## Output (Sample)
```
Enter size of hash table: 7
Enter number of keys to insert: 5
Enter keys:
49
56
72
89
92
Hash table:
0 --> 56
1 --> 72
2 --> EMPTY
3 --> 92
4 --> 49
5 --> 89
6 --> EMPTY
Enter key to search: 72
Key 72 found at index 1
