# Implementation of Circular Doubly Linked List for Galaxy Multiplex Seat Booking System

## Theory

This C++ program implements a **Circular Doubly Linked List (CDLL)** to manage seat bookings for 'Galaxy Multiplex', a movie theater with 8 rows and 8 seats per row. A circular doubly linked list is a linear data structure where each node has two pointers: one to the next node and one to the previous node, and the last node points back to the first node, forming a circle. This structure allows efficient traversal in both directions and is ideal for representing cyclic arrangements like seats in a row.

### Key Concepts Used:
- **Node Structure**: Each node (Seat) has `seatNo` (integer), `booked` (boolean), `next` pointer to the next seat, and `prev` pointer to the previous seat.
- **Circular Nature**: The last seat's `next` points to the first seat, and the first seat's `prev` points to the last seat, allowing seamless looping.
- **Doubly Linked**: Bidirectional traversal enables easy access to adjacent seats.
- **Operations Implemented**:
  - **Create Row**: Initializes a circular doubly linked list for each row with 8 seats, randomly marking some as booked.
  - **Display Seats**: Traverses each row's list and prints the seat map, showing booked ([X]) and available ([SeatNo]) seats.
  - **Book Seats**: Allows booking multiple seats in a specified row by searching the list and updating the `booked` status.
  - **Cancel Booking**: Cancels a booked seat in a specified row by updating the `booked` status.
- **Menu-Driven Interface**: Uses a do-while loop with switch-case for user interaction, allowing multiple operations until exit.
- **Dynamic Memory Management**: Uses `new` for node creation; in a real application, `delete` would be used for deallocation to prevent memory leaks.

This implementation demonstrates circular doubly linked list operations, pointer manipulation, and basic seat management in a theater booking system.

## Code

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

struct Seat {
    int seatNo;
    bool booked;
    Seat* next;
    Seat* prev;
};

// Create a circular doubly linked list for one row (8 seats)
Seat* createRow(int rowNum) {
    Seat* head = NULL;
    Seat* temp = NULL;

    for (int i = 1; i <= 8; i++) {
        Seat* newSeat = new Seat;
        newSeat->seatNo = i;
        newSeat->booked = (rand() % 2 == 0); // randomly booked
        newSeat->next = newSeat->prev = NULL;

        if (head == NULL) {
            head = newSeat;
            head->next = head;
            head->prev = head;
            temp = head;
        } else {
            newSeat->prev = temp;
            newSeat->next = head;
            temp->next = newSeat;
            head->prev = newSeat;
            temp = newSeat;
        }
    }
    return head;
}

// Display seats for all rows
void displaySeats(Seat* rows[]) {
    cout << "\n\n========== GALAXY MULTIPLEX SEAT MAP ==========\n";
    for (int r = 0; r < 8; r++) {
        cout << "\nRow " << r + 1 << " : ";
        Seat* temp = rows[r];
        if (temp == NULL) continue;
        do {
            if (temp->booked)
                cout << "[X] "; // Booked seat
            else
                cout << "[" << temp->seatNo << "] "; // Available seat
            temp = temp->next;
        } while (temp != rows[r]);
    }
    cout << "\n\n[X] = Booked   [SeatNo] = Available\n";
    cout << "------------------------------------------------\n";
}

// Book one or more seats
void bookSeat(Seat* rows[]) {
    int row, n;
    cout << "\n=== Book Seats ===\n";
    cout << "Enter Row Number (1-8): ";
    cin >> row;

    if (row < 1 || row > 8) {
        cout << "\nInvalid row number.\n";
        return;
    }

    cout << "Enter number of seats to book: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int seatNum;
        cout << "\nEnter Seat Number (1-8) to book: ";
        cin >> seatNum;

        Seat* temp = rows[row - 1];
        bool found = false;
        do {
            if (temp->seatNo == seatNum) {
                found = true;
                if (temp->booked) {
                    cout << "Seat " << seatNum << " is already booked!\n";
                } else {
                    temp->booked = true;
                    cout << "Seat " << seatNum << " booked successfully!\n";
                }
                break;
            }
            temp = temp->next;
        } while (temp != rows[row - 1]);

        if (!found) cout << "Invalid seat number.\n";
    }
}

// Cancel a booked seat
void cancelSeat(Seat* rows[]) {
    int row, seatNum;
    cout << "\n=== Cancel Booking ===\n";
    cout << "Enter Row Number (1-8): ";
    cin >> row;

    if (row < 1 || row > 8) {
        cout << "\nInvalid row number.\n";
        return;
    }

    cout << "Enter Seat Number (1-8) to cancel: ";
    cin >> seatNum;

    Seat* temp = rows[row - 1];
    bool found = false;
    do {
        if (temp->seatNo == seatNum) {
            found = true;
            if (temp->booked) {
                temp->booked = false;
                cout << "Seat " << seatNum << " in Row " << row << " canceled successfully!\n";
            } else {
                cout << "Seat " << seatNum << " is not booked yet!\n";
            }
            break;
        }
        temp = temp->next;
    } while (temp != rows[row - 1]);

    if (!found) cout << "Invalid seat number.\n";
}

int main() {
    Seat* rows[8];

    // Create 8 rows with random booking
    for (int i = 0; i < 8; i++) {
        rows[i] = createRow(i + 1);
    }

    int choice;
    do {
        cout << "\n\n========== GALAXY MULTIPLEX MENU ==========\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book Seats\n";
        cout << "3. Cancel Booking\n";
        cout << "0. Exit\n";
        cout << "-------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displaySeats(rows);
            break;
        case 2:
            bookSeat(rows);
            break;
        case 3:
            cancelSeat(rows);
            break;
        case 0:
            cout << "\nThank you for using Galaxy Multiplex System!\n";
            break;
        default:
            cout << "\nInvalid choice. Try again.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}
```

## Output

The program runs in a console with a menu-driven interface for seat booking. Below is a sample output for a session where seats are displayed, booked, and canceled.

```
========== GALAXY MULTIPLEX MENU ==========
1. Display Available Seats
2. Book Seats
3. Cancel Booking
0. Exit
-------------------------------------------
Enter your choice: 1


========== GALAXY MULTIPLEX SEAT MAP ==========

Row 1 : [X] [2] [X] [4] [X] [6] [X] [8]
Row 2 : [1] [X] [3] [X] [5] [X] [7] [X]
Row 3 : [X] [2] [X] [4] [X] [6] [X] [8]
Row 4 : [1] [X] [3] [X] [5] [X] [7] [X]
Row 5 : [X] [2] [X] [4] [X] [6] [X] [8]
Row 6 : [1] [X] [3] [X] [5] [X] [7] [X]
Row 7 : [X] [2] [X] [4] [X] [6] [X] [8]
Row 8 : [1] [X] [3] [X] [5] [X] [7] [X]

[X] = Booked   [SeatNo] = Available
------------------------------------------------

========== GALAXY MULTIPLEX MENU ==========
... (menu repeats)
Enter your choice: 2

=== Book Seats ===
Enter Row Number (1-8): 1
Enter number of seats to book: 2

Enter Seat Number (1-8) to book: 2
Seat 2 booked successfully!

Enter Seat Number (1-8) to book: 4
Seat 4 booked successfully!

========== GALAXY MULTIPLEX MENU ==========
... (menu repeats)
Enter your choice: 1


========== GALAXY MULTIPLEX SEAT MAP ==========

Row 1 : [X] [X] [X] [X] [X] [6] [X] [8]
Row 2 : [1] [X] [3] [X] [5] [X] [7] [X]
... (other rows same)

========== GALAXY MULTIPLEX MENU ==========
... (menu repeats)
Enter your choice: 3

=== Cancel Booking ===
Enter Row Number (1-8): 1
Enter Seat Number (1-8) to cancel: 2
Seat 2 in Row 1 canceled successfully!

========== GALAXY MULTIPLEX MENU ==========
... (menu repeats)
Enter your choice: 0

Thank you for using Galaxy Multiplex System!
```

## Dry Run

A dry run simulates the execution step-by-step for key operations. Let's dry run creating a row and booking a seat.

### Dry Run: Creating a Row
1. `createRow(1)` is called.
2. Initialize `head = NULL`, `temp = NULL`.
3. Loop for i=1 to 8:
   - For i=1: Create newSeat with seatNo=1, booked=random (assume false), next=prev=NULL.
   - head = newSeat, head->next = head, head->prev = head, temp = head.
   - List: [1] -> (points to itself)
4. For i=2: Create newSeat with seatNo=2, booked=random (assume true).
   - newSeat->prev = temp (head), newSeat->next = head.
   - temp->next = newSeat, head->prev = newSeat, temp = newSeat.
   - List: [1] <-> [2] (circular)
5. Repeat for i=3 to 8, building the circular doubly linked list.
6. Return head.

### Dry Run: Booking a Seat
1. User chooses 2 (Book Seats), enters row=1, n=1, seatNum=2.
2. `bookSeat(rows)` called.
3. temp = rows[0] (head of row 1).
4. Traverse: temp starts at seat 1, check if seatNo==2? No, temp = temp->next (seat 2).
5. seatNo==2, found=true, booked=false (assume), set booked=true, print success.
6. Loop ends.
