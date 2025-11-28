# Implementation of Doubly Linked List for Binary Number Operations

## Theory

This C++ program implements a **Doubly Linked List (DLL)** to represent binary numbers and perform operations like 1's complement, 2's complement, and binary addition. A doubly linked list is a linear data structure where each node has two pointers: one to the next node and one to the previous node, allowing bidirectional traversal.

### Key Concepts Used:
- **Node Structure**: Each node has `bit` (integer, 0 or 1), `prev` pointer to the previous node, and `next` pointer to the next node.
- **Head Pointers**: `head1` and `head2` for two binary numbers.
- **Operations Implemented**:
  - **Insert**: Adds a bit to the end of the list.
  - **Display**: Traverses and prints the binary number.
  - **1's Complement**: Flips each bit (0 to 1, 1 to 0).
  - **2's Complement**: Computes 1's complement and adds 1, handling carry.
  - **Add Binary**: Adds two binary numbers from least significant bit (LSB) to most significant bit (MSB), managing carry.
- **Binary Arithmetic**: Demonstrates fundamental binary operations using linked lists.
- **Dynamic Memory Management**: Uses `new` for node creation; in a real application, `delete` would be used for deallocation.

This implementation demonstrates doubly linked list operations and binary number manipulation.

## Code

```cpp
#include <iostream>
using namespace std;

struct Node {
    int bit;
    Node* prev;
    Node* next;
};

Node* head1 = NULL;
Node* head2 = NULL;

// --- Insert bit at end of list ---
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->bit = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// --- Display list (binary number) ---
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->bit;
        temp = temp->next;
    }
    cout << endl;
}

// --- a) 1’s complement ---
void onesComplement(Node* head) {
    Node* temp = head;
    cout << "1's Complement: ";
    while (temp != NULL) {
        cout << (temp->bit == 0 ? 1 : 0);
        temp = temp->next;
    }
    cout << endl;
}

// --- a) 2’s complement ---
void twosComplement(Node* head) {
    // Step 1: find 1’s complement
    Node* temp = head;
    while (temp != NULL) {
        temp->bit = (temp->bit == 0 ? 1 : 0);
        temp = temp->next;
    }

    // Step 2: add 1 starting from LSB
    int carry = 1;
    Node* last = head;
    while (last->next != NULL)
        last = last->next;

    while (last != NULL && carry) {
        int sum = last->bit + carry;
        last->bit = sum % 2;
        carry = sum / 2;
        last = last->prev;
    }

    // Step 3: if carry remains, add new node at beginning
    if (carry == 1) {
        Node* newNode = new Node;
        newNode->bit = 1;
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    cout << "2's Complement: ";
    display(head);
}

// --- b) Add two binary numbers ---
Node* addBinary(Node* head1, Node* head2) {
    // Move to last node of both lists
    Node* t1 = head1;
    Node* t2 = head2;
    while (t1->next != NULL) t1 = t1->next;
    while (t2->next != NULL) t2 = t2->next;

    Node* result = NULL;
    int carry = 0;

    // Traverse from right to left
    while (t1 != NULL || t2 != NULL || carry) {
        int b1 = (t1 ? t1->bit : 0);
        int b2 = (t2 ? t2->bit : 0);

        int sum = b1 + b2 + carry;
        int bit = sum % 2;
        carry = sum / 2;

        // Insert at beginning
        Node* newNode = new Node;
        newNode->bit = bit;
        newNode->prev = NULL;
        newNode->next = result;
        if (result != NULL)
            result->prev = newNode;
        result = newNode;

        if (t1) t1 = t1->prev;
        if (t2) t2 = t2->prev;
    }
    return result;
}

int main() {
    // Example 1:  Binary 1011 (11)
    insert(head1, 1);
    insert(head1, 0);
    insert(head1, 1);
    insert(head1, 1);

    cout << "Binary Number 1: ";
    display(head1);

    onesComplement(head1);

    // Rebuild for 2’s complement because bits changed
    head1 = NULL;
    insert(head1, 1);
    insert(head1, 0);
    insert(head1, 1);
    insert(head1, 1);
    twosComplement(head1);

    // Second binary: 0110 (6)
    insert(head2, 0);
    insert(head2, 1);
    insert(head2, 1);
    insert(head2, 0);

    cout << "\nBinary Number 2: ";
    display(head2);

    Node* result = addBinary(head1, head2);
    cout << "Addition Result: ";
    display(result);

    return 0;
}
```

## Output

The program runs in a console and performs binary operations. Below is a sample output based on the example data in main().

```
Binary Number 1: 1011
1's Complement: 0100
2's Complement: 0101

Binary Number 2: 0110
Addition Result: 1011
```

## Dry Run

A dry run simulates the execution step-by-step for key operations. Let's dry run inserting bits and computing 1's complement.

### Dry Run: Inserting Bits
1. `insert(head1, 1)` is called.
2. Create newNode with bit=1, next=NULL, prev=NULL.
3. head1 == NULL, so head1 = newNode.

List: [1] (prev=NULL, next=NULL)

4. `insert(head1, 0)` is called.
5. Create newNode with bit=0, next=NULL, prev=NULL.
6. temp = head1 (1), while temp->next != NULL (false), so temp->next = newNode, newNode->prev = temp.

List: [1] <-> [0]

### Dry Run: 1's Complement
1. `onesComplement(head1)` called.
2. temp = head1 (1).
3. Print (1 == 0 ? 1 : 0) → 0
4. temp = temp->next (0).
5. Print (0 == 0 ? 1 : 0) → 1
6. temp = temp->next (1).
7. Print (1 == 0 ? 1 : 0) → 0
8. temp = temp->next (1).
9. Print (1 == 0 ? 1 : 0) → 0
10. temp = NULL, end. Print endl.
