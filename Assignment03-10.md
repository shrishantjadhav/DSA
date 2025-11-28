# Assignment 03-10

## Aim
To simulate a call queue system using a linked list for managing customer calls.

## Steps Followed
1. Defined a `Node` structure representing a customer call with customer name and next pointer.
2. Created a `CallQueue` class to implement queue operations using linked list: enqueue, dequeue, and display.
3. Enqueue operation adds a customer call to the rear of the queue.
4. Dequeue operation removes the customer call from the front of the queue.
5. Display operation traverses the linked list and shows all customers in the queue.
6. Provided a menu-driven interface for user interaction with validation.

## Code
```cpp
#include <iostream>
#include <string>
using namespace std;

// Node structure for linked list
struct Node {
    string customerName;
    Node* next;
};

// Queue class using linked list
class CallQueue {
    Node* front;
    Node* rear;

public:
    CallQueue() {
        front = rear = nullptr;
    }

    // Enqueue a new customer call
    void enqueue(string name) {
        Node* newNode = new Node();
        newNode->customerName = name;
        newNode->next = nullptr;

        if(rear == nullptr) { // Queue empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Customer \"" << name << "\" added to the queue.\n";
    }

    // Dequeue a customer call
    void dequeue() {
        if(front == nullptr) {
            cout << "No calls in the queue. Waiting...\n";
            return;
        }
        Node* temp = front;
        cout << "Serving customer \"" << temp->customerName << "\".\n";
        front = front->next;
        if(front == nullptr) rear = nullptr;
        delete temp;
    }

    // Display all calls in queue
    void display() {
        if(front == nullptr) {
            cout << "No calls in the queue.\n";
            return;
        }
        cout << "Customers in queue: ";
        Node* temp = front;
        while(temp != nullptr) {
            cout << temp->customerName << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    CallQueue cq;
    int choice;
    string name;

    do {
        cout << "\n1. Add Customer Call\n2. Serve Customer\n3. Display Queue\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter customer name: ";
                cin.ignore(); // Ignore leftover newline
                getline(cin, name);
                cq.enqueue(name);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 4);

    return 0;
}
```

## Output (Sample)
```
1. Add Customer Call
2. Serve Customer
3. Display Queue
4. Exit
Enter choice: 1
Enter customer name: Alice
Customer "Alice" added to the queue.

1. Add Customer Call
2. Serve Customer
3. Display Queue
4. Exit
Enter choice: 3
Customers in queue: Alice 

1. Add Customer Call
2. Serve Customer
3. Display Queue
4. Exit
Enter choice: 2
Serving customer "Alice".

1. Add Customer Call
2. Serve Customer
3. Display Queue
4. Exit
Enter choice: 4
Exiting...
