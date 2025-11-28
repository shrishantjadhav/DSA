# Assignment 03-09

## Aim
To implement two independent queues using arrays and provide enqueue, dequeue, and display operations for each.

## Steps Followed
1. Defined a class `MultiQueue` that contains two arrays representing two separate queues.
2. Maintained front and rear indices for both queues.
3. Implemented enqueue operations for each queue with overflow checks.
4. Implemented dequeue operations for each queue with underflow checks.
5. Implemented display functionality to show elements of each queue.
6. Provided a menu-driven interface for user interaction with both queues.
7. Provided appropriate messages for overflow, underflow, invalid choices, and display results.

## Code
```cpp
#include <iostream>
using namespace std;

#define SIZE 5  // Maximum size of each queue

class MultiQueue {
    int queue1[SIZE], queue2[SIZE];
    int front1, rear1, front2, rear2;

public:
    MultiQueue() {
        front1 = rear1 = -1;
        front2 = rear2 = -1;
    }

    // Add element to a queue
    void enqueue(int queueNum, int value) {
        if(queueNum == 1) {
            if(rear1 == SIZE - 1) {
                cout << "Queue 1 Overflow!\n";
                return;
            }
            if(front1 == -1) front1 = 0;
            queue1[++rear1] = value;
            cout << "Added " << value << " to Queue 1.\n";
        } else if(queueNum == 2) {
            if(rear2 == SIZE - 1) {
                cout << "Queue 2 Overflow!\n";
                return;
            }
            if(front2 == -1) front2 = 0;
            queue2[++rear2] = value;
            cout << "Added " << value << " to Queue 2.\n";
        } else {
            cout << "Invalid queue number!\n";
        }
    }

    // Delete element from a queue
    void dequeue(int queueNum) {
        if(queueNum == 1) {
            if(front1 == -1 || front1 > rear1) {
                cout << "Queue 1 Underflow!\n";
                return;
            }
            cout << "Deleted " << queue1[front1++] << " from Queue 1.\n";
        } else if(queueNum == 2) {
            if(front2 == -1 || front2 > rear2) {
                cout << "Queue 2 Underflow!\n";
                return;
            }
            cout << "Deleted " << queue2[front2++] << " from Queue 2.\n";
        } else {
            cout << "Invalid queue number!\n";
        }
    }

    // Display a queue
    void display(int queueNum) {
        if(queueNum == 1) {
            if(front1 == -1 || front1 > rear1) {
                cout << "Queue 1 is empty.\n";
                return;
            }
            cout << "Queue 1 elements: ";
            for(int i = front1; i <= rear1; i++) cout << queue1[i] << " ";
            cout << "\n";
        } else if(queueNum == 2) {
            if(front2 == -1 || front2 > rear2) {
                cout << "Queue 2 is empty.\n";
                return;
            }
            cout << "Queue 2 elements: ";
            for(int i = front2; i <= rear2; i++) cout << queue2[i] << " ";
            cout << "\n";
        } else {
            cout << "Invalid queue number!\n";
        }
    }
};

int main() {
    MultiQueue mq;
    int choice, queueNum, value;

    do {
        cout << "\n1. Add to Queue\n2. Delete from Queue\n3. Display Queue\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter queue number (1 or 2): ";
                cin >> queueNum;
                cout << "Enter value to add: ";
                cin >> value;
                mq.enqueue(queueNum, value);
                break;
            case 2:
                cout << "Enter queue number (1 or 2): ";
                cin >> queueNum;
                mq.dequeue(queueNum);
                break;
            case 3:
                cout << "Enter queue number (1 or 2): ";
                cin >> queueNum;
                mq.display(queueNum);
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
1. Add to Queue
2. Delete from Queue
3. Display Queue
4. Exit
Enter choice: 1
Enter queue number (1 or 2): 1
Enter value to add: 10
Added 10 to Queue 1.

1. Add to Queue
2. Delete from Queue
3. Display Queue
4. Exit
Enter choice: 3
Enter queue number (1 or 2): 1
Queue 1 elements: 10 

1. Add to Queue
2. Delete from Queue
3. Display Queue
4. Exit
Enter choice: 2
Enter queue number (1 or 2): 1
Deleted 10 from Queue 1.

1. Add to Queue
2. Delete from Queue
3. Display Queue
4. Exit
Enter choice: 4
Exiting...
