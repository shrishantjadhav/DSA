# Assignment 04-02

## Aim
To implement a Binary Search Tree (BST) with operations to insert nodes, count the total number of nodes, find the height of the tree, and generate the mirror image of the tree.

## Steps Followed
1. Defined a `Node` structure with data, left, and right pointers.
2. Implemented a BST class with:
   - `insert` method to add nodes in BST order.
   - `countNodes` method to recursively count total nodes.
   - `height` method to calculate height of the BST.
   - `mirror` method to create a mirror image by swapping left and right children recursively.
   - `inorder` traversal to display nodes in sorted order.
3. Added sample values to the BST for demonstration.
4. Displayed the inorder traversal, total nodes, height, and inorder traversal after mirroring.
5. Used proper recursion and standard STL algorithms.

## Code
```cpp
#include <iostream>
#include <algorithm> // for std::swap

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

    int countNodes(Node* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int height(Node* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    void mirror(Node* node) {
        if (!node) return;
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
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

    int countNodes() { return countNodes(root); }

    int height() { return height(root); }

    void mirror() { mirror(root); }

    void inorder() { inorder(root); cout << endl; }
};

int main() {
    BST tree;

    // Insert some sample values to demonstrate
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Total number of nodes: " << tree.countNodes() << endl;

    cout << "Height of the BST: " << tree.height() << endl;

    tree.mirror();
    cout << "After mirror image, Inorder traversal: ";
    tree.inorder();

    return 0;
}
```

## Output (Sample)
```
Inorder traversal: 20 30 40 50 60 70 80 
Total number of nodes: 7
Height of the BST: 3
After mirror image, Inorder traversal: 80 70 60 50 40 30 20
