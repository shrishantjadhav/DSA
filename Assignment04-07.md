# Assignment 04-07

## Aim
To implement a Binary Search Tree (BST) with operations for insertion, deletion, searching, and displaying inorder traversal using a menu-driven interface.

## Steps Followed
1. Defined a `Node` structure with data, left, and right pointers.
2. Implemented recursive `insert` method to add values preserving BST order.
3. Implemented `deleteNode` method for deletion considering three cases:
   - Leaf node.
   - Node with one child.
   - Node with two children (replacing with inorder successor).
4. Implemented `find` method to search a value recursively in BST.
5. Implemented inorder traversal method to display BST nodes.
6. Created a menu that allows user operations: Insert, Delete, Find, Show, and Exit.
7. Provided proper input handling and user feedback.

## Code
```cpp
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int val) {
        if (!node) return node;
        if (val < node->data) node->left = deleteNode(node->left, val);
        else if (val > node->data) node->right = deleteNode(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    bool find(Node* node, int val) {
        if (!node) return false;
        if (val == node->data) return true;
        if (val < node->data) return find(node->left, val);
        return find(node->right, val);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() : root(NULL) {}

    void insert(int val) { root = insert(root, val); }

    void deleteVal(int val) { root = deleteNode(root, val); }

    bool find(int val) { return find(root, val); }

    void show() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice, val;

    while (true) {
        cout << "\nBST Operations Menu:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Find" << endl;
        cout << "4. Show" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insert(val);
                cout << "Inserted " << val << endl;
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                tree.deleteVal(val);
                cout << "Deleted " << val << " if it existed" << endl;
                break;
            case 3:
                cout << "Enter value to find: ";
                cin >> val;
                if (tree.find(val)) cout << val << " found" << endl;
                else cout << val << " not found" << endl;
                break;
            case 4:
                tree.show();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
```

## Output (Sample)
```
BST Operations Menu:
1. Insert
2. Delete
3. Find
4. Show
5. Exit
Enter your choice: 1
Enter value to insert: 50
Inserted 50

BST Operations Menu:
1. Insert
2. Delete
3. Find
4. Show
5. Exit
Enter your choice: 4
Inorder Traversal: 50

BST Operations Menu:
1. Insert
2. Delete
3. Find
4. Show
5. Exit
Enter your choice: 3
Enter value to find: 50
50 found

BST Operations Menu:
1. Insert
2. Delete
3. Find
4. Show
5. Exit
Enter your choice: 5
