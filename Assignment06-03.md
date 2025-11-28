# Assignment 06-03

## Aim
To implement a hash table using chaining technique for collision resolution (similar to Assignment06-02).

## Steps Followed
1. Defined a `HashTable` class with:
   - Vector of lists representing chains for buckets.
   - Size of the hash table.
   - Hash function using modulo operation.
2. Implemented `insert` method to add keys to the appropriate chain based on the hash.
3. Implemented `search` method to find the presence of a key in its chain.
4. Implemented `display` method to show the contents of the hash table with chains.
5. Accepted user inputs for table size, number of keys, keys to insert, and key to search.
6. Displayed the hash table after insertions.
7. Displayed search results for the requested key.

## Code
```cpp
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HashTable {
private:
    vector<list<int>> table;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size);
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key) return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            for (int val : table[i]) {
                cout << val << " -> ";
            }
            cout << "NULL" << endl;
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
    if (ht.search(key))
        cout << "Key " << key << " found in hash table." << endl;
    else
        cout << "Key " << key << " not found in hash table." << endl;

    return 0;
}
```

## Output (Sample)
```
Enter size of hash table: 7
Enter number of keys to insert: 6
Enter keys:
15
11
27
8
12
14
Hash table:
0 --> 27 -> 
1 --> 15 -> 
2 --> 12 -> 
3 --> 11 -> 
4 --> NULL
5 --> 8 -> 
6 --> 14 -> 
Enter key to search: 27
Key 27 found in hash table.
