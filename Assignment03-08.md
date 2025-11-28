# Assignment 03-08

## Aim
To simulate a passenger queue management system using the queue data structure where passengers can be added, viewed, and removed from the queue.

## Steps Followed
1. Used the STL queue to maintain the passenger queue of strings representing passenger names.
2. Allowed user to:
   - Add a passenger to the queue.
   - View the passenger at the front of the queue without removing.
   - Remove the front passenger from the queue.
   - Exit the simulation and display the number of passengers left.
3. Implemented a menu-driven interface for interactive operations.
4. Managed input stream to correctly read passenger names with spaces.
5. Provided validation and appropriate messages for empty queue and invalid choices.

## Code
```cpp
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> passengerQueue;
    int choice;
    string name;

    do {
        cout << "\n1. Add Passenger\n2. Display Front Passenger\n3. Remove Passenger\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter passenger name: ";
                cin.ignore(); // Ignore leftover newline
                getline(cin, name);
                passengerQueue.push(name);
                cout << name << " added to the queue.\n";
                break;

            case 2:
                if(passengerQueue.empty()) {
                    cout << "Queue is empty.\n";
                } else {
                    cout << "Passenger at front: " << passengerQueue.front() << "\n";
                }
                break;

            case 3:
                if(passengerQueue.empty()) {
                    cout << "Queue is empty. No passenger to remove.\n";
                } else {
                    cout << "Removing passenger: " << passengerQueue.front() << "\n";
                    passengerQueue.pop();
                }
                break;

            case 4:
                cout << "Exiting...\n";
                cout << "Number of passengers left in queue: " << passengerQueue.size() << "\n";
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
1. Add Passenger
2. Display Front Passenger
3. Remove Passenger
4. Exit
Enter choice: 1
Enter passenger name: Alice Johnson
Alice Johnson added to the queue.

1. Add Passenger
2. Display Front Passenger
3. Remove Passenger
4. Exit
Enter choice: 2
Passenger at front: Alice Johnson

1. Add Passenger
2. Display Front Passenger
3. Remove Passenger
4. Exit
Enter choice: 3
Removing passenger: Alice Johnson

1. Add Passenger
2. Display Front Passenger
3. Remove Passenger
4. Exit
Enter choice: 4
Exiting...
Number of passengers left in queue: 0
