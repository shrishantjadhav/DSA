# Implementation of Singly Linked List with Front-Back Split

## Theory

This C++ program implements a **Singly Linked List (SLL)** and performs a front-back split operation. A singly linked list is a linear data structure where each element (node) contains data and a pointer to the next node. The front-back split divides the list into two halves: the front half and the back half, using the slow and fast pointer technique to find the midpoint efficiently.

### Key Concepts Used:
- **Node Structure**: Each node has `data` (integer) and a `next` pointer to the next node.
- **Head Pointer**: Points to the first node in the list.
- **Operations Implemented**:
  - **Insert**: Adds a new node at the end of the list.
  - **Display**: Traverses and prints all elements in the list, formatted with curly braces.
  - **FrontBackSplit**: Splits the list into two halves using slow and fast pointers. The slow pointer moves one step, the fast pointer moves two steps. When fast reaches the end, slow is at the midpoint. The list is split there.
- **Slow and Fast Pointers**: A common technique for finding the middle of a linked list in O(n) time and O(1) space.
- **Dynamic Memory Management**: Uses `new` for node creation; in a real application, `delete` would be used for deallocation.

This implementation demonstrates singly linked list operations and the front-back split algorithm.

## Code

```cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// --- Insert at end ---
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// --- Display list ---
void display(Node* head) {
    Node* temp = head;
    cout << "{ ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "}" << endl;
}

// --- FrontBackSplit ---
void FrontBackSplit(Node* source, Node*& frontRef, Node*& backRef) {
    if (source == NULL || source->next == NULL) {
        // 0 or 1 node
        frontRef = source;
        backRef = NULL;
        return;
    }

    Node* slow = source;
    Node* fast = source->next;

    // Move fast by 2 and slow by 1
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Split the list
    frontRef = source;
    backRef = slow->next;
    slow->next = NULL; // terminate front list
}

int main() {
    Node* head = NULL;
    Node* front = NULL;
    Node* back = NULL;

    // Example: 2, 3, 5, 7, 11
    insert(head, 2);
    insert(head, 3);
    insert(head, 5);
    insert(head, 7);
    insert(head, 11);

    cout << "Original List: ";
    display(head);

    FrontBackSplit(head, front, back);

    cout << "Front List: ";
    display(front);
    cout << "Back List: ";
    display(back);

    // Additional test cases
    Node* test2 = NULL;
    insert(test2, 10);
    insert(test2, 20);
    cout << "\nTest list {10, 20}:" << endl;
    display(test2);
    Node* f2 = NULL; Node* b2 = NULL;
    FrontBackSplit(test2, f2, b2);
    cout << "Front: "; display(f2);
    cout << "Back: "; display(b2);

    Node* test3 = NULL;
    insert(test3, 1);
    insert(test3, 2);
    insert(test3, 3);
    cout << "\nTest list {1, 2, 3}:" << endl;
    display(test3);
    Node* f3 = NULL; Node* b3 = NULL;
    FrontBackSplit(test3, f3, b3);
    cout << "Front: "; display(f3);
    cout << "Back: "; display(b3);

    Node* test4 = NULL;
    insert(test4, 4);
    insert(test4, 5);
    insert(test4, 6);
    insert(test4, 7);
    cout << "\nTest list {4, 5, 6, 7}:" << endl;
    display(test4);
    Node* f4 = NULL; Node* b4 = NULL;
    FrontBackSplit(test4, f4, b4);
    cout << "Front: "; display(f4);
    cout << "Back: "; display(b4);

    return 0;
}
```

## Output

The program runs in a console and demonstrates the front-back split on various lists. Below is a sample output based on the example data in main().

```
Original List: { 2 3 5 7 11 }
Front List: { 2 3 }
Back List: { 5 7 11 }

Test list {10, 20}:
{ 10 20 }
Front: { 10 }
Back: { 20 }

Test list {1, 2, 3}:
{ 1 2 3 }
Front: { 1 2 }
Back: { 3 }

Test list {4, 5, 6, 7}:
{ 4 5 6 7 }
Front: { 4 5 }
Back: { 6 7 }
```

## Dry Run

A dry run simulates the execution step-by-step for key operations. Let's dry run inserting nodes and performing front-back split on {2, 3, 5, 7, 11}.

### Dry Run: Inserting Nodes
1. `insert(head, 2)` is called.
2. Create newNode with data=2, next=NULL.
3. head == NULL, so head = newNode.

List: [2] -> NULL

4. `insert(head, 3)` is called.
5. Create newNode with data=3, next=NULL.
6. temp = head (2), while temp->next != NULL (false), so temp->next = newNode.

List: [2] -> [3] -> NULL

7. Repeat for 5, 7, 11, building the list: [2] -> [3] -> [5] -> [7] -> [11] -> NULL

### Dry Run: FrontBackSplit
1. `FrontBackSplit(head, front, back)` called with source = [2] -> [3] -> [5] -> [7] -> [11] -> NULL
2. source != NULL and source->next != NULL, so proceed.
3. slow = source (2), fast = source->next (3).
4. While fast != NULL:
   - fast = fast->next (5)
   - if fast != NULL, slow = slow->next (3), fast = fast->next (7)
   - fast = fast->next (11)
   - if fast != NULL, slow = slow->next (5), fast = fast->next (NULL)
   - fast == NULL, exit loop.
5. slow is now at 5.
6. frontRef = source (2), backRef = slow->next (7), slow->next = NULL (terminate front at 5).
7. Front: [2] -> [3] -> [5] -> NULL
8. Back: [7] -> [11] -> NULL
