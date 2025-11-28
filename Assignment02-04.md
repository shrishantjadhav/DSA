# Implementation of Singly Linked List for Set Operations on Student Preferences

## Theory

This C++ program implements **Singly Linked Lists (SLL)** to represent sets of students who like Cricket and Football, and performs set operations like intersection, symmetric difference, and counting students who like neither. A singly linked list is a linear data structure where each element (node) contains data and a pointer to the next node. Unlike arrays, linked lists allow dynamic memory allocation and efficient insertions/deletions.

### Key Concepts Used:
- **Node Structure**: Each node has `data` (integer, student roll number) and a `next` pointer to the next node.
- **Head Pointers**: `headA` for Cricket set, `headB` for Football set.
- **Operations Implemented**:
  - **Insert**: Adds a new student to the end of the list.
  - **Display**: Traverses and prints all elements in the set.
  - **Exists**: Checks if a value is present in the list.
  - **Intersection (A ∩ B)**: Finds students who like both Cricket and Football.
  - **Symmetric Difference (A Δ B)**: Finds students who like either Cricket or Football but not both.
  - **Neither**: Counts students who like neither, given total students.
- **Set Theory Application**: Uses linked lists to simulate sets and perform mathematical set operations.
- **Dynamic Memory Management**: Uses `new` for node creation; in a real application, `delete` would be used for deallocation.

This implementation demonstrates singly linked list operations and basic set theory concepts.

## Code

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* headA = NULL; // Cricket
Node* headB = NULL; // Football

// --- Insert into linked list ---
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// --- Display a set ---
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// --- Check if value exists in list ---
bool exists(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}

// --- a) Students who like both Cricket and Football (A ∩ B) ---
void intersection(Node* A, Node* B) {
    Node* temp = A;
    cout << "Students who like both Cricket and Football: ";
    while (temp != NULL) {
        if (exists(B, temp->data))
            cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// --- b) Students who like either but not both (A Δ B) ---
void symmetricDifference(Node* A, Node* B) {
    cout << "Students who like either Cricket or Football but not both: ";

    Node* temp = A;
    while (temp != NULL) {
        if (!exists(B, temp->data))
            cout << temp->data << " ";
        temp = temp->next;
    }

    temp = B;
    while (temp != NULL) {
        if (!exists(A, temp->data))
            cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// --- c) Students who like neither Cricket nor Football ---
void neither(int totalStudents, Node* A, Node* B) {
    int count = 0;
    for (int i = 1; i <= totalStudents; i++) {
        if (!exists(A, i) && !exists(B, i))
            count++;
    }
    cout << "Number of students who like neither Cricket nor Football: " << count << endl;
}

// --- Main function ---
int main() {
    int total = 10; // total students (say roll numbers 1–10)

    // Students who like Cricket
    insert(headA, 1);
    insert(headA, 2);
    insert(headA, 5);
    insert(headA, 7);

    // Students who like Football
    insert(headB, 3);
    insert(headB, 5);
    insert(headB, 6);
    insert(headB, 7);

    cout << "Set A (Cricket): ";
    display(headA);

    cout << "Set B (Football): ";
    display(headB);

    cout << endl;
    intersection(headA, headB);
    symmetricDifference(headA, headB);
    neither(total, headA, headB);

    return 0;
}
```

## Output

The program runs in a console and performs set operations on student preferences. Below is a sample output based on the example data in main().

```
Set A (Cricket): 1 2 5 7
Set B (Football): 3 5 6 7

Students who like both Cricket and Football: 5 7
Students who like either Cricket or Football but not both: 1 2 3 6
Number of students who like neither Cricket nor Football: 4
```

## Dry Run

A dry run simulates the execution step-by-step for key operations. Let's dry run inserting into a list and computing the intersection.

### Dry Run: Inserting into List
1. `insert(headA, 1)` is called.
2. Create newNode with data=1, next=NULL.
3. headA == NULL, so headA = newNode.

List A: [1] -> NULL

4. `insert(headA, 2)` is called.
5. Create newNode with data=2, next=NULL.
6. temp = headA (1), while temp->next != NULL (false), so temp->next = newNode.

List A: [1] -> [2] -> NULL

### Dry Run: Intersection
1. `intersection(headA, headB)` called.
2. temp = headA (1).
3. exists(B, 1): Traverse B (3,5,6,7), 1 not found, return false. No print.
4. temp = temp->next (2).
5. exists(B, 2): 2 not in B, no print.
6. temp = temp->next (5).
7. exists(B, 5): 5 found in B, print 5.
8. temp = temp->next (7).
9. exists(B, 7): 7 found in B, print 7.
10. temp = NULL, end.
