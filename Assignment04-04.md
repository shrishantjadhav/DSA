# Assignment 04-04

## Aim
To implement a binary tree with non-recursive inorder and preorder traversals, count leaf nodes, and create a mirror image of the tree using iterative stack-based methods.

## Steps Followed
1. Defined a `Node` structure with data, left, and right pointers.
2. Implemented `inorderNonRecursive` method performing inorder traversal using an explicit stack.
3. Implemented `preorderNonRecursive` method performing preorder traversal using a stack.
4. Implemented `countLeafNodes` method to count leaf nodes using iterative traversal with stack.
5. Implemented `mirror` method to convert the tree to its mirror image iteratively using a stack.
6. Created a sample binary tree manually.
7. Demonstrated inorder traversal, preorder traversal, leaf node count, and mirror image impact on inorder traversal.
8. Provided user-friendly output messages.

## Code
```cpp
#include <iostream>
#include <stack>
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

    void inorderNonRecursive(Node* node) {
        stack<Node*> s;
        Node* current = node;
        while (current != NULL || !s.empty()) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
        cout << endl;
    }

    void preorderNonRecursive(Node* node) {
        if (!node) return;
        stack<Node*> s;
        s.push(node);
        while (!s.empty()) {
            Node* current = s.top();
            s.pop();
            cout << current->data << " ";
            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }
        cout << endl;
    }

    int countLeafNodes(Node* node) {
        if (!node) return 0;
        stack<Node*> s;
        int count = 0;
        s.push(node);
        while (!s.empty()) {
            Node* current = s.top();
            s.pop();
            if (!current->left && !current->right) count++;
            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }
        return count;
    }

    void mirror(Node* node) {
        if (!node) return;
        stack<Node*> s;
        s.push(node);
        while (!s.empty()) {
            Node* current = s.top();
            s.pop();
            swap(current->left, current->right);
            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }
    }

public:
    BinaryTree() : root(NULL) {}

    void setRoot(Node* node) { root = node; }

    void inorder() { inorderNonRecursive(root); }

    void preorder() { preorderNonRecursive(root); }

    int leafCount() { return countLeafNodes(root); }

    void mirrorImage() { mirror(root); }
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
