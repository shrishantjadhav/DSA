# Assignment 03-01

## Aim
To build a simple stock price tracker using a stack implemented via linked list that allows recording, removing, and viewing the most recent stock price.

## Steps Followed
1. Defined a singly linked list node structure to represent each stock price.
2. Implemented stack operations:
   - `record(price)`: Push a new price onto the stack.
   - `remove()`: Pop and remove the most recent price.
   - `latest()`: Peek the most recent price without removing.
   - `isEmpty()`: Check if the stack is empty.
3. Provided a menu-driven interface to allow user interaction for these operations.
4. Managed dynamic memory correctly while adding and removing nodes.
5. Displayed appropriate messages for user actions.

## Code
```cpp
#include<iostream>
using namespace std;

typedef struct SLL
{
    int price;
    struct SLL* next;
}SLL;

SLL* head = NULL;

void record(int price)
{
    SLL* newnode = new SLL;
    newnode->price = price;
    newnode->next = head;
    head = newnode;
    cout<<"\nPrice recorded successfully!\n";
}

void remove()
{
    if(head == NULL)
    {
        cout<<"\nNo prices to remove.\n";
        return;
    }

    SLL* temp = head;
    head = head->next;
    delete temp;
    cout<<"\nMost recent price removed successfully!\n";
}

void latest()
{
    if(head == NULL)
    {
        cout<<"\nNo prices recorded.\n";
        return;
    }

    cout<<"\nMost recent price is : "<<head->price<<"\n";
}

void isEmpty()
{
    if(head == NULL)
    {
        cout<<"\nStack is empty.\n";
    }
    else
    {
        cout<<"\nStack is not empty.\n";
    }
}

int main()
{
    int choice, price;

    while(choice != 0)
    {
        cout<<"\n***** STOCK PRICE TRACKER *****";
        cout<<"\n1. Record Price";
        cout<<"\n2. Remove Price";
        cout<<"\n3. Latest Price";
        cout<<"\n4. Check is Empty";
        cout<<"\n0. Exit";
        cout<<"\nEnter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"\nEnter price to record : ";
                cin>>price;
                record(price);
                break;

            case 2:
                remove();
                break;

            case 3:
                latest();
                break;

            case 4:
                isEmpty();
                break;

            case 0: 
                cout<<"\nExiting the Program.";
                break;

            default:
                cout<<"\nInvalid Choice. Try again.";
                break;
        }
        
    }

    return 0;
}
```

## Output (Sample)
```
***** STOCK PRICE TRACKER *****
1. Record Price
2. Remove Price
3. Latest Price
4. Check is Empty
0. Exit
Enter your choice : 1

Enter price to record : 120

Price recorded successfully!

***** STOCK PRICE TRACKER *****
Enter your choice : 3

Most recent price is : 120

***** STOCK PRICE TRACKER *****
Enter your choice : 2

Most recent price removed successfully!

***** STOCK PRICE TRACKER *****
Enter your choice : 4

Stack is empty.

***** STOCK PRICE TRACKER *****
Enter your choice : 0

Exiting the Program.
