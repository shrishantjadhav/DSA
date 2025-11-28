# Assignment 04-05

## Aim
To implement a binary tree with recursive inorder and preorder traversals, count leaf nodes recursively, and create a mirror image recursively.

## Steps Followed
1. Defined a `Node` structure with data, left, and right pointers.
2. Implemented recursive methods:
   - `inorderRecursive` for inorder traversal.
   - `preorderRecursive` for preorder traversal.
   - `countLeafNodesRecursive` to count leaf nodes.
   - `mirrorRecursive` to create the mirror image.
3. Created a sample binary tree manually.
4. Displayed inorder traversal, preorder traversal, leaf count, and inorder traversal after mirroring.
5. Used recursion for all tree operations.

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

class BinaryTree {
private:
    Node* root;

    void inorderRecursive(Node* node) {
        if (!node) return;
        inorderRecursive(node->left);
        cout << node->data << " ";
        inorderRecursive(node->right);
    }

    void preorderRecursive(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }

    int countLeafNodesRecursive(Node* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        return countLeafNodesRecursive(node->left) + countLeafNodesRecursive(node->right);
    }

    void mirrorRecursive(Node* node) {
        if (!node) return;
        swap(node->left, node->right);
        mirrorRecursive(node->left);
        mirrorRecursive(node->right);
    }

public:
    BinaryTree() : root(NULL) {}

    void setRoot(Node* node) { root = node; }

    void inorder() { inorderRecursive(root); cout << endl; }

    void preorder() { preorderRecursive(root); cout << endl; }

    int leafCount() { return countLeafNodesRecursive(root); }

    void mirrorImage() { mirrorRecursive(root); }
};

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    BinaryTree tree;
    tree.setRoot(root);

    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Preorder Traversal: ";
    tree.preorder();

    cout << "Number of Leaf Nodes: " << tree.leafCount() << endl;

    tree.mirrorImage();
    cout << "After Mirror Image, Inorder Traversal: ";
    tree.inorder();

    return 0;
}
```

## Output (Sample)
```
Inorder Traversal: 4 2 5 1 6 3 7 
Preorder Traversal: 1 2 4 5 3 6 7 
Number of Leaf Nodes: 4
After Mirror Image, Inorder Traversal: 7 3 6 1 5 2 4
