# Implementation of Doubly Linked List with Bubble Sort

## Theory

This C++ program implements a **Doubly Linked List (DLL)** and performs bubble sort on it. A doubly linked list is a linear data structure where each node has two pointers: one to the next node and one to the previous node, allowing bidirectional traversal. Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

### Key Concepts Used:
- **Node Structure**: Each node has `data` (integer), `prev` pointer to the previous node, and `next` pointer to the next node.
- **Head Pointer**: Points to the first node in the list.
- **Operations Implemented**:
  - **Insert**: Adds a new node at the end of the list.
  - **Display**: Traverses and prints all elements in the list.
  - **Bubble Sort**: Sorts the list by repeatedly swapping adjacent elements if they are in the wrong order, using a flag to detect if any swaps occurred in a pass.
- **Sorting on Linked List**: Bubble sort adapted for doubly linked list, swapping data fields instead of nodes for simplicity.
- **Dynamic Memory Management**: Uses `new` for node creation; in a real application, `delete` would be used for deallocation.

This implementation demonstrates doubly linked list operations and the bubble sort algorithm.

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

// --- Insert node at end ---
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// --- Display DLL ---
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// --- Bubble Sort ---
void bubbleSort(Node* head) {
    if (head == NULL) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = NULL; // marks the end of sorted part

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; // last node is now sorted
    } while (swapped);
}

int main() {
    Node* head = NULL;

    // Example DLL: 5, 3, 8, 2, 7
    insert(head, 5);
    insert(head, 3);
    insert(head, 8);
    insert(head, 2);
    insert(head, 7);

    cout << "Original Doubly Linked List: ";
    display(head);

    bubbleSort(head);

    cout << "Sorted Doubly Linked List: ";
    display(head);

    return 0;
}
```

## Output

The program runs in a console and sorts the doubly linked list using bubble sort. Below is a sample output based on the example data in main().

```
Original Doubly Linked List: 5 3 8 2 7
Sorted Doubly Linked List: 2 3 5 7 8
```

## Dry Run

A dry run simulates the execution step-by-step for key operations. Let's dry run inserting nodes and performing bubble sort.

### Dry Run: Inserting Nodes
1. `insert(head, 5)` is called.
2. Create newNode with data=5, next=NULL, prev=NULL.
3. head == NULL, so head = newNode.

List: [5] (prev=NULL, next=NULL)

4. `insert(head, 3)` is called.
5. Create newNode with data=3, next=NULL, prev=NULL.
6. temp = head (5), while temp->next != NULL (false), so temp->next = newNode, newNode->prev = temp.

List: [5] <-> [3]

7. Repeat for 8, 2, 7, building the list.

### Dry Run: Bubble Sort (First Pass)
1. `bubbleSort(head)` called.
2. swapped = false, ptr1 = head (5).
3. ptr1->next != lptr (NULL), 5 > 3, swap: ptr1->data=3, ptr1->next->data=5, swapped=true.
4. ptr1 = ptr1->next (now 5).
5. ptr1->next != lptr, 5 > 8? No.
6. ptr1 = ptr1->next (8).
7. ptr1->next != lptr, 8 > 2, swap: ptr1->data=2, ptr1->next->data=8, swapped=true.
8. ptr1 = ptr1->next (8).
9. ptr1->next != lptr, 8 > 7, swap: ptr1->data=7, ptr1->next->data=8, swapped=true.
10. ptr1 = ptr1->next (8), now ptr1->next == lptr, end pass.
11. lptr = ptr1 (8).
12. Since swapped=true, repeat.
13. Continues until no swaps.
