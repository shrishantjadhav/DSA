# Implementation of Doubly Linked List with Insertions and Deletions

## Theory

This C++ program implements a **Doubly Linked List (DLL)** with operations for inserting and deleting nodes at various positions. A doubly linked list is a linear data structure where each node has two pointers: one to the next node and one to the previous node, allowing bidirectional traversal. This makes insertions and deletions efficient at both ends and specific positions.

### Key Concepts Used:
- **Node Structure**: Each node has `data` (integer), `prev` pointer to the previous node, and `next` pointer to the next node.
- **Head Pointer**: Points to the first node in the list.
- **Operations Implemented**:
  - **Insert at Beginning**: Adds a new node at the start of the list.
  - **Insert at End**: Adds a new node at the end of the list.
  - **Insert at Position**: Adds a new node at a specified 1-based position.
  - **Delete from Beginning**: Removes the first node.
  - **Delete from End**: Removes the last node.
  - **Delete from Position**: Removes a node at a specified 1-based position.
  - **Display**: Traverses and prints all elements in the list.
- **Position-Based Operations**: Uses 1-based indexing for positions, with error handling for invalid positions.
- **Dynamic Memory Management**: Uses `new` for node creation and `delete` for deallocation to prevent memory leaks.

This implementation demonstrates doubly linked list operations for dynamic data management.

## Code

```cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// --- Insert at beginning ---
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

// --- Insert at end ---
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// --- Insert at a position (1-based) ---
void insertAtPosition(Node*& head, int value, int pos) {
    if (pos == 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Position out of range.\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// --- Delete from beginning ---
void deleteFromBeginning(Node*& head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}

// --- Delete from end ---
void deleteFromEnd(Node*& head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL; // list had only one node

    delete temp;
}

// --- Delete from a specific position (1-based) ---
void deleteFromPosition(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (pos == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Position out of range.\n";
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
}

// --- Display list ---
void display(Node* head) {
    Node* temp = head;
    cout << "DLL: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Insertions
    insertAtBeginning(head, 10);
    insertAtEnd(head, 20);
    insertAtPosition(head, 15, 2); // between 10 and 20
    insertAtEnd(head, 25);
    display(head); // 10 15 20 25

    // Deletions
    deleteFromBeginning(head);
    display(head); // 15 20 25

    deleteFromEnd(head);
    display(head); // 15 20

    deleteFromPosition(head, 2);
    display(head); // 15

    deleteFromPosition(head, 1);
    display(head); // empty

    return 0;
}
```

## Output

The program runs in a console and demonstrates insertions and deletions on the doubly linked list. Below is a sample output based on the example operations in main().

```
DLL: 10 15 20 25
DLL: 15 20 25
DLL: 15 20
DLL: 15
DLL:
```

## Dry Run

A dry run simulates the execution step-by-step for key operations. Let's dry run inserting at position and deleting from position.

### Dry Run: Insert at Position (15 at pos 2)
1. `insertAtPosition(head, 15, 2)` called with head = [10] <-> [20] -> NULL
2. pos != 1, temp = head (10).
3. Loop: i=1, i < 2-1=1? No, temp remains 10.
4. temp != NULL, proceed.
5. Create newNode with data=15.
6. newNode->next = temp->next (20), newNode->prev = temp (10).
7. temp->next->prev = newNode (20->prev = 15).
8. temp->next = newNode (10->next = 15).

List: [10] <-> [15] <-> [20] -> NULL

### Dry Run: Delete from Position (pos 2)
1. `deleteFromPosition(head, 2)` called with head = [15] <-> [20] -> NULL
2. head != NULL, pos != 1.
3. temp = head (15).
4. Loop: i=1, i < 2, temp = temp->next (20).
5. temp != NULL, proceed.
6. temp->next != NULL? No.
7. temp->prev != NULL, temp->prev->next = temp->next (15->next = NULL).
8. Delete temp (20).

List: [15] -> NULL
