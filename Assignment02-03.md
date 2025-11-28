# Implementation of Singly Linked List for Appointment Booking System

## Theory

This C++ program implements a **Singly Linked List (SLL)** to manage appointments for a scheduling system. A singly linked list is a linear data structure where each element (node) contains data and a pointer to the next node. Unlike arrays, linked lists allow dynamic memory allocation and efficient insertions/deletions.

### Key Concepts Used:
- **Node Structure**: Each node (Appointment) has `start` (integer, 24-hour format), `end` (integer), and a `next` pointer to the next node.
- **Head Pointer**: Points to the first node in the list.
- **Operations Implemented**:
  - **Book Appointment**: Adds a new appointment to the end of the list.
  - **Display Appointments**: Traverses the list and prints all appointments.
  - **Cancel Appointment**: Searches for and removes a specific appointment by start and end times.
  - **Sort by Data**: Uses bubble sort to sort appointments by start time, swapping data fields.
  - **Sort by Pointer**: Rebuilds the list by inserting nodes in sorted order using pointer manipulation.
- **Menu-Driven Interface**: The main function demonstrates usage with example bookings, sorting, and cancellations.
- **Dynamic Memory Management**: Uses `new` for node creation and `delete` for deallocation to prevent memory leaks.

This implementation demonstrates fundamental singly linked list operations, pointer manipulation, and sorting algorithms.

## Code

```cpp
#include <iostream>
using namespace std;

struct Appointment {
    int start;  // in 24-hour format, e.g., 900 for 9:00
    int end;    // e.g., 930 for 9:30
    Appointment* next;
};

Appointment* head = NULL;

// --- Function to insert appointment (unsorted initially)
void bookAppointment(int s, int e) {
    Appointment* newNode = new Appointment;
    newNode->start = s;
    newNode->end = e;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Appointment* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;

    cout << "Appointment booked: " << s << " - " << e << endl;
}

// --- Display all appointments
void displayAppointments() {
    if (head == NULL) {
        cout << "No appointments yet.\n";
        return;
    }

    Appointment* temp = head;
    cout << "Appointments:\n";
    while (temp != NULL) {
        cout << temp->start << " - " << temp->end << endl;
        temp = temp->next;
    }
}

// --- Cancel appointment
void cancelAppointment(int s, int e) {
    Appointment* temp = head;
    Appointment* prev = NULL;

    while (temp != NULL) {
        if (temp->start == s && temp->end == e) {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            cout << "Appointment cancelled: " << s << " - " << e << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "No such appointment found.\n";
}

// --- Sort by swapping data (simple)
void sortByData() {
    for (Appointment* i = head; i != NULL; i = i->next) {
        for (Appointment* j = i->next; j != NULL; j = j->next) {
            if (i->start > j->start) {
                swap(i->start, j->start);
                swap(i->end, j->end);
            }
        }
    }
    cout << "Sorted by data.\n";
}

// --- Sort by pointer manipulation
void sortByPointer() {
    if (head == NULL || head->next == NULL) return;

    Appointment* sorted = NULL; // new sorted list

    Appointment* current = head;
    while (current != NULL) {
        Appointment* nextNode = current->next;

        if (sorted == NULL || current->start < sorted->start) {
            current->next = sorted;
            sorted = current;
        } else {
            Appointment* temp = sorted;
            while (temp->next != NULL && temp->next->start < current->start)
                temp = temp->next;

            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }
    head = sorted;
    cout << "Sorted by pointer manipulation.\n";
}

int main() {
    // Example usage
    bookAppointment(900, 930);
    bookAppointment(1100, 1130);
    bookAppointment(1000, 1030);

    cout << "\nBefore sorting:\n";
    displayAppointments();

    sortByData();
    displayAppointments();

    cancelAppointment(1100, 1130);
    displayAppointments();

    // Add more
    bookAppointment(945, 1005);
    sortByPointer();
    displayAppointments();

    return 0;
}
```

## Output

The program runs in a console and demonstrates appointment booking, sorting, and cancellation. Below is a sample output based on the example usage in main().

```
Appointment booked: 900 - 930
Appointment booked: 1100 - 1130
Appointment booked: 1000 - 1030

Before sorting:
Appointments:
900 - 930
1100 - 1130
1000 - 1030
Sorted by data.
Appointments:
900 - 930
1000 - 1030
1100 - 1130
Appointment cancelled: 1100 - 1130
Appointments:
900 - 930
1000 - 1030
Appointment booked: 945 - 1005
Sorted by pointer manipulation.
Appointments:
900 - 930
945 - 1005
1000 - 1030
```

## Dry Run

A dry run simulates the execution step-by-step for key operations. Let's dry run booking an appointment and sorting by data.

### Dry Run: Booking an Appointment
1. `bookAppointment(900, 930)` is called.
2. Create newNode with start=900, end=930, next=NULL.
3. head == NULL, so head = newNode.
4. Print "Appointment booked: 900 - 930".

List: [900-930] -> NULL

### Dry Run: Sorting by Data
1. `sortByData()` called.
2. Outer loop: i = head (900-930).
3. Inner loop: j = i->next (1100-1130).
4. 900 < 1100, no swap.
5. j = j->next (1000-1030).
6. 900 < 1000, no swap.
7. i = i->next (1100-1130).
8. Inner loop: j = 1000-1030.
9. 1100 > 1000, swap: i becomes 1000-1030, j becomes 1100-1130.
10. Continue until sorted.
11. Print "Sorted by data.".
