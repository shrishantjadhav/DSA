# Assignment 03-03

## Aim
To implement three stacks in a single array and provide operations to push, pop, and display elements of each stack.

## Steps Followed
1. Defined a class `MultiStack` with a single array divided equally into three parts, each representing a stack.
2. Maintained an array `top` to keep track of the top element index for each stack.
3. Implemented `push` operation that adds an element to the specified stack if there is space.
4. Implemented `pop` operation that removes the top element from the specified stack if not empty.
5. Implemented `display` operation to print all elements of the specified stack.
6. Created a menu-driven main function to allow user interaction to perform stack operations.

## Code
```cpp
#include <iostream>
using namespace std;

#define SIZE 30  // Total size of the array
#define NUM_STACKS 3  // Number of stacks

class MultiStack {
    int arr[SIZE];        // Array to hold all stacks
    int top[NUM_STACKS];  // Array to hold top indexes for each stack
    int stackSize;        // Maximum size of each stack (for simplicity, equal division)
public:
    MultiStack() {
        stackSize = SIZE / NUM_STACKS;
        for(int i = 0; i < NUM_STACKS; i++)
            top[i] = -1; // Initialize tops to -1
    }

    void push(int stackNum, int value) {
        if(stackNum < 1 || stackNum > NUM_STACKS) {
            cout << "Invalid Stack Number!\n";
            return;
        }

        int index = (stackNum - 1) * stackSize + top[stackNum-1] + 1;

        if(top[stackNum-1] >= stackSize - 1) {
            cout << "Stack Overflow on Stack " << stackNum << "!\n";
        } else {
            arr[index] = value;
            top[stackNum-1]++;
            cout << "Pushed " << value << " into Stack " << stackNum << "\n";
        }
    }

    void pop(int stackNum) {
        if(stackNum < 1 || stackNum > NUM_STACKS) {
            cout << "Invalid Stack Number!\n";
            return;
        }

        if(top[stackNum-1] == -1) {
            cout << "Stack Underflow on Stack " << stackNum << "!\n";
        } else {
            int index = (stackNum - 1) * stackSize + top[stackNum-1];
            cout << "Popped " << arr[index] << " from Stack " << stackNum << "\n";
            top[stackNum-1]--;
        }
    }

    void display(int stackNum) {
        if(stackNum < 1 || stackNum > NUM_STACKS) {
            cout << "Invalid Stack Number!\n";
            return;
        }

        if(top[stackNum-1] == -1) {
            cout << "Stack " << stackNum << " is empty.\n";
        } else {
            cout << "Stack " << stackNum << " elements: ";
            for(int i = 0; i <= top[stackNum-1]; i++) {
                int index = (stackNum - 1) * stackSize + i;
                cout << arr[index] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    MultiStack ms;
    int choice, stackNum, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter stack number (1-" << NUM_STACKS << "): ";
                cin >> stackNum;
                cout << "Enter value to push: ";
                cin >> value;
                ms.push(stackNum, value);
                break;
            case 2:
                cout << "Enter stack number (1-" << NUM_STACKS << "): ";
                cin >> stackNum;
                ms.pop(stackNum);
                break;
            case 3:
                cout << "Enter stack number (1-" << NUM_STACKS << "): ";
                cin >> stackNum;
                ms.display(stackNum);
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
1. Push
2. Pop
3. Display
4. Exit
Enter choice: 1
Enter stack number (1-3): 1
Enter value to push: 10
Pushed 10 into Stack 1

1. Push
2. Pop
3. Display
4. Exit
Enter choice: 3
Enter stack number (1-3): 1
Stack 1 elements: 10 

1. Push
2. Pop
3. Display
4. Exit
Enter choice: 2
Enter stack number (1-3): 1
Popped 10 from Stack 1

1. Push
2. Pop
3. Display
4. Exit
Enter choice: 3
Enter stack number (1-3): 1
Stack 1 is empty.

1. Push
2. Pop
3. Display
4. Exit
Enter choice: 4
Exiting...
