# Assignment 03-07

## Aim
To implement a pizza order management system using a circular queue where orders can be placed, served, and displayed.

## Steps Followed
1. Defined a `PizzaParlour` class that simulates a circular queue with maximum capacity.
2. Maintained `front` and `rear` pointers to track the queue status.
3. Implemented methods to check if the queue is full or empty.
4. Implemented `placeOrder` to enqueue an order if space is available.
5. Implemented `serveOrder` to dequeue the oldest order if any orders are pending.
6. Implemented `displayOrders` to show all current orders in the queue.
7. Provided a menu-driven interface for user interaction.

## Code
```cpp
#include <iostream>
using namespace std;

#define MAX 5  // Maximum orders in queue

class PizzaParlour {
    int orders[MAX];
    int front, rear;
public:
    PizzaParlour() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX-1) || (rear == (front-1) % (MAX-1));
    }

    bool isEmpty() {
        return front == -1;
    }

    void placeOrder(int orderID) {
        if(isFull()) {
            cout << "Order queue is full! Cannot place order " << orderID << ".\n";
            return;
        }

        if(front == -1) front = 0;  // First order
        rear = (rear + 1) % MAX;
        orders[rear] = orderID;
        cout << "Order " << orderID << " placed successfully.\n";
    }

    void serveOrder() {
        if(isEmpty()) {
            cout << "No orders to serve!\n";
            return;
        }

        cout << "Serving order " << orders[front] << ".\n";

        if(front == rear) { // Only one order
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void displayOrders() {
        if(isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Pending orders: ";
        int i = front;
        while(true) {
            cout << orders[i] << " ";
            if(i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << "\n";
    }
};

int main() {
    PizzaParlour pp;
    int choice, orderID;

    do {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> orderID;
                pp.placeOrder(orderID);
                break;
            case 2:
                pp.serveOrder();
                break;
            case 3:
                pp.displayOrders();
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
1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter choice: 1
Enter Order ID: 101
Order 101 placed successfully.

1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter choice: 3
Pending orders: 101 

1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter choice: 2
Serving order 101.

1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter choice: 4
Exiting...
