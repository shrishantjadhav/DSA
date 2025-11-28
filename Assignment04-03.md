# Assignment 04-03

## Aim
To implement a Binary Search Tree (BST) with operations to insert nodes and find the minimum and maximum values.

## Steps Followed
1. Defined a node structure with data, and left and right pointers.
2. Implemented BST class with:
   - An insert method to add nodes maintaining BST properties.
   - A method `findMin` to find the minimum value node by traversing leftmost nodes.
   - A method `findMax` to find the maximum value node by traversing rightmost nodes.
3. Inserted sample nodes for demonstration.
4. Displayed the minimum and maximum values in the BST.

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
        if (!node) return NULL;
        while (node->left) node = node->left;
        return node;
    }

    Node* findMax(Node* node) {
        if (!node) return NULL;
        while (node->right) node = node->right;
        return node;
    }

public:
    BST() : root(NULL) {}

    void insert(int val) { root = insert(root, val); }

    int findMin() {
        Node* minNode = findMin(root);
        return minNode ? minNode->data : -1; // assuming -1 for empty tree
    }

    int findMax() {
        Node* maxNode = findMax(root);
        return maxNode ? maxNode->data : -1;
    }
};

int main() {
    BST tree;

    // Insert some sample values
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Minimum value in BST: " << tree.findMin() << endl;
    cout << "Maximum value in BST: " << tree.findMax() << endl;

    return 0;
}
```

## Output (Sample)
```
Minimum value in BST: 20
Maximum value in BST: 80
