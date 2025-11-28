# Assignment 03-06

## Aim
To simulate a patient queue management system using a queue data structure where patients can check in, be assigned to a doctor, and queue status can be displayed.

## Steps Followed
1. Defined a `Patient` structure with patient name and ID.
2. Used the STL queue to maintain the patient queue.
3. Implemented options for:
   - Patient check-in: Add a new patient to the queue with a unique ID.
   - Assign patient to doctor: Dequeue and display the patient assigned.
   - Display the queue list of patients.
4. Provided a menu-driven interface for user interaction.
5. Validated and displayed appropriate messages for actions.

## Code
```cpp
#include <iostream>
#include <queue>
using namespace std;

struct Patient {
    string name;
    int id;
};

int main() {
    queue<Patient> clinicQueue; // Queue to keep track of patients
    int choice;
    int nextID = 1;

    do {
        cout << "\n1. Check-in Patient\n2. Assign Patient to Doctor\n3. Display Queue\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                Patient p;
                cout << "Enter patient name: ";
                cin.ignore(); // To ignore newline from previous input
                getline(cin, p.name);
                p.id = nextID++;
                clinicQueue.push(p);
                cout << "Patient " << p.name << " checked in with ID " << p.id << ".\n";
                break;
            }

            case 2: {
                if(clinicQueue.empty()) {
                    cout << "No patients in the queue!\n";
                } else {
                    Patient p = clinicQueue.front();
                    clinicQueue.pop();
                    cout << "Assigning patient " << p.name << " (ID: " << p.id << ") to doctor.\n";
                }
                break;
            }

            case 3: {
                if(clinicQueue.empty()) {
                    cout << "Queue is empty.\n";
                } else {
                    cout << "Patients in queue:\n";
                    queue<Patient> temp = clinicQueue;
                    while(!temp.empty()) {
                        cout << "ID: " << temp.front().id << ", Name: " << temp.front().name << "\n";
                        temp.pop();
                    }
                }
                break;
            }

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
1. Check-in Patient
2. Assign Patient to Doctor
3. Display Queue
4. Exit
Enter choice: 1
Enter patient name: John Doe
Patient John Doe checked in with ID 1.

1. Check-in Patient
2. Assign Patient to Doctor
3. Display Queue
4. Exit
Enter choice: 3
Patients in queue:
ID: 1, Name: John Doe

1. Check-in Patient
2. Assign Patient to Doctor
3. Display Queue
4. Exit
Enter choice: 2
Assigning patient John Doe (ID: 1) to doctor.

1. Check-in Patient
2. Assign Patient to Doctor
3. Display Queue
4. Exit
Enter choice: 4
Exiting...
