# Assignment 04-06

## Aim
To implement a Binary Search Tree (BST) to organize student records by marks and assign roll numbers based on marks (topper gets roll number 1).

## Steps Followed
1. Defined a `Student` structure containing name, marks, and roll number.
2. Defined a `Node` structure containing a `Student` object and left and right pointers.
3. Implemented a BST class with:
   - Insert method that inserts a student based on marks (higher marks go to left subtree).
   - Method to assign roll numbers to students by inorder traversal (ascending order).
   - Display method to show student's roll number, name, and marks inorder.
4. Inserted sample students into BST.
5. Assigned roll numbers starting from 1 to the student with highest marks.
6. Displayed the student records with roll numbers, names, and marks ordered by marks descending.

## Code
```cpp
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int marks;
    int rollNo;
    Student(string n, int m) : name(n), marks(m), rollNo(0) {}
};

struct Node {
    Student student;
    Node* left;
    Node* right;
    Node(Student s) : student(s), left(NULL), right(NULL) {}
};

class BST {
private:
    Node* root;
    int rollCounter;

    Node* insert(Node* node, Student s) {
        if (!node) return new Node(s);
        if (s.marks > node->student.marks) node->left = insert(node->left, s);
        else node->right = insert(node->right, s);
        return node;
    }

    void assignRollNumbers(Node* node) {
        if (!node) return;
        assignRollNumbers(node->left);
        node->student.rollNo = rollCounter++;
        assignRollNumbers(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << "Roll No: " << node->student.rollNo << ", Name: " << node->student.name << ", Marks: " << node->student.marks << endl;
        inorder(node->right);
    }

public:
    BST() : root(NULL), rollCounter(1) {}

    void insert(Student s) { root = insert(root, s); }

    void assignRollNumbers() { assignRollNumbers(root); }

    void display() { inorder(root); }
};

int main() {
    BST tree;

    // Sample students with names and marks
    tree.insert(Student("Alice", 95));
    tree.insert(Student("Bob", 87));
    tree.insert(Student("Charlie", 92));
    tree.insert(Student("David", 78));
    tree.insert(Student("Eve", 88));

    tree.assignRollNumbers();

    cout << "Student Roll Number Assignment based on Marks (Topper gets Roll No. 1):" << endl;
    tree.display();

    return 0;
}
```

## Output (Sample)
```
Student Roll Number Assignment based on Marks (Topper gets Roll No. 1):
Roll No: 1, Name: Alice, Marks: 95
Roll No: 2, Name: Charlie, Marks: 92
Roll No: 3, Name: Eve, Marks: 88
Roll No: 4, Name: Bob, Marks: 87
Roll No: 5, Name: David, Marks: 78
