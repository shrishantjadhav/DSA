# Assignment 04-01

## Aim
To implement a Binary Search Tree (BST) with operations for insertion, deletion, and level-wise display.

## Steps Followed
1. Defined a node structure with data, and left and right child pointers.
2. Implemented a function `createNode` to allocate and initialize a new node.
3. Implemented recursive `insert` method to add nodes preserving BST properties.
4. Implemented `deleteNode` method for removing nodes handling three cases:
   - Node with no children (leaf).
   - Node with one child.
   - Node with two children, replacing with inorder successor.
5. Implemented `minValueNode` function to find inorder successor for deletion.
6. Implemented `levelOrder` traversal to display BST level-wise using a queue.
7. Provided a menu-driven interface for the user to perform insert, delete, and display operations.
8. Added input validation and appropriate messages for user interaction.

## Code
```cpp
#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insert a node into BST
Node* insert(Node* root, int value) {
    if(root == nullptr) return createNode(value);

    if(value < root->data) root->left = insert(root->left, value);
    else if(value > root->data) root->right = insert(root->right, value);
    else cout << "Duplicate value not allowed.\n";

    return root;
}

// Find minimum value node in BST
Node* minValueNode(Node* node) {
    Node* current = node;
    while(current && current->left != nullptr) current = current->left;
    return current;
}

// Delete a node from BST
Node* deleteNode(Node* root, int value) {
    if(root == nullptr) return root;

    if(value < root->data)
        root->left = deleteNode(root->left, value);
    else if(value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node with one or no child
        if(root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Level-wise display of BST
void levelOrder(Node* root) {
    if(root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    cout << "Level-wise BST: ";
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if(temp->left != nullptr) q.push(temp->left);
        if(temp->right != nullptr) q.push(temp->right);
    }
    cout << "\n";
}

int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Level-wise Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 3:
                levelOrder(root);
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
1. Insert
2. Delete
3. Level-wise Display
4. Exit
Enter choice: 1
Enter value to insert: 50

1. Insert
2. Delete
3. Level-wise Display
4. Exit
Enter choice: 1
Enter value to insert: 30

1. Insert
2. Delete
3. Level-wise Display
4. Exit
Enter choice: 3
Level-wise BST: 50 30 

1. Insert
2. Delete
3. Level-wise Display
4. Exit
Enter choice: 2
Enter value to delete: 30

1. Insert
2. Delete
3. Level-wise Display
4. Exit
Enter choice: 3
Level-wise BST: 50 

1. Insert
2. Delete
3. Level-wise Display
4. Exit
Enter choice: 4
Exiting...
