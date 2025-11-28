# Implementation of Singly Linked List for Vertex Club Membership Management

## Theory

This C++ program implements a **Singly Linked List (SLL)** to manage membership records for the 'Vertex Club', a student club in the Department of Computer Engineering. The linked list is a linear data structure where each element (node) contains data and a pointer to the next node. Unlike arrays, linked lists allow dynamic memory allocation and efficient insertions/deletions.

### Key Concepts Used:
- **Node Structure**: Each node in the SLL has three fields: `prnnum` (PRN number, integer), `name` (string), `year` (string), and a `next` pointer to the next node.
- **Head Pointer**: Points to the first node (President). The last node (Secretary) has `next` as NULL.
- **Operations Implemented**:
  - **Add/Delete President**: President is always at the head. Adding inserts at the beginning; deleting removes the head.
  - **Add/Delete Secretary**: Secretary is at the tail. Adding appends to the end; deleting removes the last node.
  - **Add/Delete Members**: Members are added after the President (between head and tail). Deletion searches by PRN.
  - **Count Members**: Traverses the list and counts nodes.
  - **Display Members**: Traverses and prints all node details.
  - **Concatenate Lists**: Appends one list to another by linking the tail of the first to the head of the second.
  - **Reverse List**: Reverses the list by changing pointers iteratively.
  - **Search by PRN**: Linear search through the list for a matching PRN.
  - **Sort by PRN**: Bubble sort on the list, swapping data fields when PRNs are out of order.
- **Menu-Driven Interface**: Uses a do-while loop with switch-case for user interaction, allowing multiple operations until exit.
- **Dynamic Memory Management**: Uses `new` for node creation and `delete` for deallocation to prevent memory leaks.

This implementation demonstrates fundamental linked list operations, pointer manipulation, and basic sorting/searching algorithms.

## Code

```cpp
/*Implementation of Singly Linked List to Manage ‘Vertex Club’ Membership Records.
The Department of Computer Engineering has a student club named ‘Vertex Club’ for second, third, and final year students. 
The first member is the President and the last member is the Secretary. 
Write a C++ program to: 
● Add/delete members (including President/Secretary) 
● Count members 
● Display members 
● Concatenate two division lists 
Also implement: reverse, search by PRN, and sort by 
PRN operations.*/

#include<iostream>
using namespace std;

typedef struct SLL
{
    int prnnum;
    string name;
    string year;
    struct SLL* next;
}SLL;

SLL* getNode()
{
    SLL* temp = new SLL;
    temp->next = NULL;
    return temp;
}

SLL* createList()
{
    return NULL;
}

SLL* addPresident(SLL* head)
{
    SLL* newnode = getNode();

    int prnnum;
    string name, year;

    cout << "\n\n=== Add President ===\n";
    cout << "Enter PRN number of President: ";
    cin >> prnnum;
    cout << "Enter name of President: ";
    cin >> name;
    cout << "Enter year of President: ";
    cin >> year;

    newnode->prnnum = prnnum;
    newnode->name = name;
    newnode->year = year;

    newnode->next = head;
    cout << "\nPresident added successfully!\n";
    return newnode;
}

SLL* deletePresident(SLL* head)
{
    if (head == NULL)
    {
        cout << "\nNo President to delete.\n";
        return NULL;
    }
    SLL* temp = head;
    head = head->next;
    delete temp;
    cout << "\nPresident deleted successfully!\n";
    return head;
}

SLL* addSecretary(SLL* head)
{
    SLL* newnode = getNode();
    int prnnum;
    string name, year;

    cout << "\n\n=== Add Secretary ===\n";
    cout << "Enter PRN number of Secretary: ";
    cin >> prnnum;
    cout << "Enter name of Secretary: ";
    cin >> name;
    cout << "Enter year of Secretary: ";
    cin >> year;

    newnode->prnnum = prnnum;
    newnode->name = name;
    newnode->year = year;

    if (head == NULL)
        return newnode;

    SLL* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    cout << "\nSecretary added successfully!\n";
    return head;
}

SLL* deleteSecretary(SLL* head)
{
    if (head == NULL)
    {
        cout << "\nNo Secretary to delete.\n";
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        cout << "\nSecretary deleted successfully!\n";
        return NULL;
    }
    SLL* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
    cout << "\nSecretary deleted successfully!\n";
    return head;
}

SLL* addMember(SLL* head)
{
    SLL* newnode = getNode();
    int prnnum;
    string name, year;

    cout << "\n\n=== Add Member ===\n";
    cout << "Enter PRN number of Member: ";
    cin >> prnnum;
    cout << "Enter name of Member: ";
    cin >> name;
    cout << "Enter year of Member: ";
    cin >> year;

    newnode->prnnum = prnnum;
    newnode->name = name;
    newnode->year = year;

    if (head == NULL)
        return newnode;

    newnode->next = head->next;
    head->next = newnode;
    cout << "\nMember added successfully!\n";
    return head;
}

SLL* deleteMember(SLL* head)
{
    if (head == NULL)
    {
        cout << "\nNo members to delete.\n";
        return NULL;
    }
    int prn;
    cout << "\nEnter PRN of member to delete: ";
    cin >> prn;
    SLL* temp = head;
    SLL* prev = NULL;
    while (temp != NULL && temp->prnnum != prn)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "\nMember not found.\n";
        return head;
    }
    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;
    delete temp;
    cout << "\nMember deleted successfully!\n";
    return head;
}

int countMembers(SLL* head)
{
    int count = 0;
    SLL* temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayMembers(SLL* head)
{
    cout << "\n\n=== Vertex Club Members ===\n";
    if (head == NULL)
    {
        cout << "No members in the list.\n";
        return;
    }
    SLL* temp = head;
    while (temp != NULL)
    {
        cout << "\n---------------------------------\n";
        cout << "PRN   : " << temp->prnnum << endl;
        cout << "Name  : " << temp->name << endl;
        cout << "Year  : " << temp->year << endl;
        temp = temp->next;
    }
    cout << "\n---------------------------------\n";
}

SLL* concatenateLists(SLL* head1, SLL* head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    SLL* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    cout << "\nLists concatenated successfully!\n";
    return head1;
}

SLL* reverseList(SLL* head)
{
    SLL* prev = NULL;
    SLL* curr = head;
    SLL* next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    cout << "\nList reversed successfully!\n";
    return prev;
}

void searchByPRN(SLL* head)
{
    if (head == NULL)
    {
        cout << "\nNo members in the list.\n";
        return;
    }
    int prn;
    cout << "\nEnter PRN to search: ";
    cin >> prn;
    SLL* temp = head;
    while (temp != NULL)
    {
        if (temp->prnnum == prn)
        {
            cout << "\nMember Found!\n";
            cout << "---------------------------------\n";
            cout << "PRN   : " << temp->prnnum << endl;
            cout << "Name  : " << temp->name << endl;
            cout << "Year  : " << temp->year << endl;
            cout << "---------------------------------\n";
            return;
        }
        temp = temp->next;
    }
    cout << "\nMember not found.\n";
}

SLL* sortByPRN(SLL* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    SLL* i = head;
    while (i != NULL)
    {
        SLL* j = i->next;
        while (j != NULL)
        {
            if (i->prnnum > j->prnnum)
            {
                swap(i->prnnum, j->prnnum);
                swap(i->name, j->name);
                swap(i->year, j->year);
            }
            j = j->next;
        }
        i = i->next;
    }
    cout << "\nList sorted by PRN successfully!\n";
    return head;
}

int main()
{
    SLL* head = NULL;
    head = createList();
    SLL* head2 = NULL;
    int choice1, choice2;

    do
    {
        cout << "\n\n========== VERTEX CLUB MENU ==========\n";
        cout << "1. Add/Delete President\n";
        cout << "2. Add/Delete Secretary\n";
        cout << "3. Add/Delete Members\n";
        cout << "4. Count Members\n";
        cout << "5. Display Members\n";
        cout << "6. Concatenate Lists\n";
        cout << "7. Reverse List\n";
        cout << "8. Search by PRN\n";
        cout << "9. Sort by PRN\n";
        cout << "0. Exit\n";
        cout << "-------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice1;

        switch (choice1)
        {
        case 1:
            cout << "\n1. Add President\n2. Delete President\nEnter choice: ";
            cin >> choice2;
            if (choice2 == 1)
                head = addPresident(head);
            else if (choice2 == 2)
                head = deletePresident(head);
            else
                cout << "\nInvalid key.\n";
            break;

        case 2:
            cout << "\n1. Add Secretary\n2. Delete Secretary\nEnter choice: ";
            cin >> choice2;
            if (choice2 == 1)
                head = addSecretary(head);
            else if (choice2 == 2)
                head = deleteSecretary(head);
            else
                cout << "\nInvalid key.\n";
            break;

        case 3:
            cout << "\n1. Add Member\n2. Delete Member\nEnter choice: ";
            cin >> choice2;
            if (choice2 == 1)
                head = addMember(head);
            else if (choice2 == 2)
                head = deleteMember(head);
            else
                cout << "\nInvalid key.\n";
            break;

        case 4:
            cout << "\nTotal Members: " << countMembers(head) << "\n";
            break;

        case 5:
            displayMembers(head);
            break;

        case 6:
            head2 = createList();
            cout << "\nCreating second list for concatenation...\n";
            head2 = addPresident(head2);
            head2 = addSecretary(head2);
            head = concatenateLists(head, head2);
            break;

        case 7:
            head = reverseList(head);
            break;

        case 8:
            searchByPRN(head);
            break;

        case 9:
            head = sortByPRN(head);
            break;

        case 0:
            cout << "\nExiting the Program. Thank you!\n";
            break;

        default:
            cout << "\nInvalid Choice. Try again.\n";
            break;
        }

    } while (choice1 != 0);

    return 0;
}
```

## Output

The program runs in a console with a menu-driven interface. Below is a sample output for a session where a President, a Member, and a Secretary are added, then displayed, counted, searched, sorted, and the list is reversed.

```
========== VERTEX CLUB MENU ==========
1. Add/Delete President
2. Add/Delete Secretary
3. Add/Delete Members
4. Count Members
5. Display Members
6. Concatenate Lists
7. Reverse List
8. Search by PRN
9. Sort by PRN
0. Exit
-------------------------------------
Enter your choice: 1

1. Add President
2. Delete President
Enter choice: 1

=== Add President ===
Enter PRN number of President: 101
Enter name of President: Alice
Enter year of President: Second

President added successfully!

========== VERTEX CLUB MENU ==========
... (menu repeats)
Enter your choice: 3

1. Add Member
2. Delete Member
Enter choice: 1

=== Add Member ===
Enter PRN number of Member: 102
Enter name of Member: Bob
Enter year of Member: Third

Member added successfully!

========== VERTEX CLUB MENU ==========
... (menu repeats)
Enter your choice: 2

1. Add Secretary
2. Delete Secretary
Enter choice: 1

=== Add Secretary ===
Enter PRN number of Secretary: 103
Enter name of Secretary: Charlie
Enter year of Secretary: Final

Secretary added successfully!

========== VERTEX CLUB MENU ==========
... (menu repeats)
Enter your choice: 5

=== Vertex Club Members ===

---------------------------------
PRN   : 101
Name  : Alice
Year  : Second
---------------------------------
PRN   : 102
Name  : Bob
Year  : Third
---------------------------------
PRN   : 103
Name  : Charlie
Year  : Final
---------------------------------

========== VERTEX CLUB MENU ==========
... (menu repeats)
Enter your choice: 4

Total Members: 3

========== VERTEX CLUB MENU ==========
... (menu repeats)
Enter your choice: 8

Enter PRN to search: 102

Member Found!
---------------------------------
PRN   : 102
Name  : Bob
Year  : Third
---------------------------------

========== VERTEX CLUB MENU ==========
... (menu repeats)
Enter your choice: 9

List sorted by PRN successfully!

========== VERTEX CLUB MENU ==========
... (menu repeats)
Enter your choice: 5

=== Vertex Club Members ===

---------------------------------
PRN   : 101
Name  : Alice
Year  : Second
---------------------------------
PRN   : 102
Name  : Bob
Year  : Third
---------------------------------
PRN   : 103
Name  : Charlie
Year  : Final
---------------------------------

========== VERTEX CLUB MENU ==========
... (menu repeats)
Enter your choice: 7

List reversed successfully!

========== VERTEX CLUB MENU ==========
... (menu repeats)
Enter your choice: 5

=== Vertex Club Members ===

---------------------------------
PRN   : 103
Name  : Charlie
Year  : Final
---------------------------------
PRN   : 102
Name  : Bob
Year  : Third
---------------------------------
PRN   : 101
Name  : Alice
Year  : Second
---------------------------------

========== VERTEX CLUB MENU ==========
... (menu repeats)
Enter your choice: 0

Exiting the Program. Thank you!
```

## Dry Run

A dry run simulates the execution step-by-step for key operations. Let's dry run adding a President and then displaying the list.

### Dry Run: Adding a President
1. `main()` initializes `head = NULL`.
2. User chooses 1 (Add/Delete President), then 1 (Add President).
3. `addPresident(head)` is called with `head = NULL`.
4. `getNode()` creates a new node `newnode` with `next = NULL`.
5. User inputs: PRN = 101, Name = "Alice", Year = "Second".
6. Assign to `newnode`: `newnode->prnnum = 101`, `newnode->name = "Alice"`, `newnode->year = "Second"`.
7. `newnode->next = head` (which is NULL).
8. Print "President added successfully!".
9. Return `newnode` as new head.

List now: [101, "Alice", "Second"] -> NULL

### Dry Run: Displaying Members
1. User chooses 5 (Display Members).
2. `displayMembers(head)` called with head pointing to the node.
3. Print header "=== Vertex Club Members ===".
4. `temp = head` (points to node).
5. Loop: Print details of temp, then `temp = temp->next` (NULL).
6. Print footer.

Output as shown in the Output section.
