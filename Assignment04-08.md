# Assignment 04-08

## Aim
To implement a Binary Search Tree (BST) to manage employee records, with functionalities to insert employees, search by employee ID, and display employees sorted by employee ID.

## Steps Followed
1. Defined an `Employee` structure containing employee ID, name, department, and salary.
2. Defined a `Node` structure containing an `Employee` and left and right pointers.
3. Implemented a BST class with:
   - Insert method to add employee nodes sorted by employee ID.
   - Search method to find employee by ID.
   - Inorder traversal to display all employees sorted by employee ID.
4. Inserted sample employee data.
5. Provided user input to search for an employee by ID.
6. Displayed appropriate results including full employee details or not found message.

## Code
```cpp
#include <iostream>
#include <string>

using namespace std;

struct Employee {
    int empId;
    string name;
    string department;
    double salary;
    Employee(int id, string n, string d, double s) : empId(id), name(n), department(d), salary(s) {}
};

struct Node {
    Employee employee;
    Node* left;
    Node* right;
    Node(Employee e) : employee(e), left(NULL), right(NULL) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, Employee e) {
        if (!node) return new Node(e);
        if (e.empId < node->employee.empId) node->left = insert(node->left, e);
        else node->right = insert(node->right, e);
        return node;
    }

    Node* search(Node* node, int empId) {
        if (!node || node->employee.empId == empId) return node;
        if (empId < node->employee.empId) return search(node->left, empId);
        return search(node->right, empId);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << "Emp ID: " << node->employee.empId << ", Name: " << node->employee.name
             << ", Department: " << node->employee.department << ", Salary: " << node->employee.salary << endl;
        inorder(node->right);
    }

public:
    BST() : root(NULL) {}

    void insert(Employee e) { root = insert(root, e); }

    Employee* search(int empId) {
        Node* result = search(root, empId);
        return result ? &result->employee : NULL;
    }

    void displaySorted() {
        cout << "Employees sorted by Emp-ID (ascending):" << endl;
        inorder(root);
    }
};

int main() {
    BST tree;

    // Sample employees
    tree.insert(Employee(101, "Alice", "HR", 50000));
    tree.insert(Employee(102, "Bob", "IT", 60000));
    tree.insert(Employee(103, "Charlie", "Finance", 55000));
    tree.insert(Employee(104, "David", "IT", 65000));
    tree.insert(Employee(105, "Eve", "HR", 52000));

    tree.displaySorted();

    int searchId;
    cout << "\nEnter Emp-ID to search: ";
    cin >> searchId;
    Employee* emp = tree.search(searchId);
    if (emp) {
        cout << "Found: Emp ID: " << emp->empId << ", Name: " << emp->name
             << ", Department: " << emp->department << ", Salary: " << emp->salary << endl;
    } else {
        cout << "Employee with Emp-ID " << searchId << " not found." << endl;
    }

    return 0;
}
```

## Output (Sample)
```
Employees sorted by Emp-ID (ascending):
Emp ID: 101, Name: Alice, Department: HR, Salary: 50000
Emp ID: 102, Name: Bob, Department: IT, Salary: 60000
Emp ID: 103, Name: Charlie, Department: Finance, Salary: 55000
Emp ID: 104, Name: David, Department: IT, Salary: 65000
Emp ID: 105, Name: Eve, Department: HR, Salary: 52000

Enter Emp-ID to search: 103
Found: Emp ID: 103, Name: Charlie, Department: Finance, Salary: 55000
