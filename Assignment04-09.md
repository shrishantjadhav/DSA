# Assignment 04-09

## Aim
To implement a Binary Search Tree (BST) to manage inventory items (products), including insertion, display in sorted order by product name, and listing expired products.

## Steps Followed
1. Defined a `Product` structure containing code, name, price, quantity, date received, and expiration date.
2. Defined a `Node` structure containing a Product and left and right pointers.
3. Implemented a BST class with:
   - Insert method to add product nodes sorted by product name.
   - Inorder traversal to display all products sorted by name.
   - Preorder traversal to list expired products by comparing expiration date with a preset current date.
4. Inserted sample product records.
5. Displayed all products sorted by name.
6. Displayed expired products based on the assumed current date using preorder traversal.

## Code
```cpp
#include <iostream>
#include <string>

using namespace std;

struct Product {
    int code;
    string name;
    double price;
    int quantity;
    string dateReceived;
    string expirationDate;
    Product(int c, string n, double p, int q, string dr, string ed)
        : code(c), name(n), price(p), quantity(q), dateReceived(dr), expirationDate(ed) {}
};

struct Node {
    Product product;
    Node* left;
    Node* right;
    Node(Product p) : product(p), left(NULL), right(NULL) {}
};

class BST {
private:
    Node* root;
    string currentDate = "2024-01-01"; // Assume current date for checking expiration

    Node* insert(Node* node, Product p) {
        if (!node) return new Node(p);
        if (p.name < node->product.name) node->left = insert(node->left, p);
        else node->right = insert(node->right, p);
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << "Code: " << node->product.code << ", Name: " << node->product.name
             << ", Price: " << node->product.price << ", Quantity: " << node->product.quantity
             << ", Date Received: " << node->product.dateReceived
             << ", Expiration Date: " << node->product.expirationDate << endl;
        inorder(node->right);
    }

    void preorderExpired(Node* node) {
        if (!node) return;
        if (node->product.expirationDate < currentDate) {
            cout << "Expired: Code: " << node->product.code << ", Name: " << node->product.name
                 << ", Expiration Date: " << node->product.expirationDate << endl;
        }
        preorderExpired(node->left);
        preorderExpired(node->right);
    }

public:
    BST() : root(NULL) {}

    void insert(Product p) { root = insert(root, p); }

    void displayAll() {
        cout << "All items in inventory (inorder by name):" << endl;
        inorder(root);
    }

    void listExpired() {
        cout << "Expired items (preorder traversal):" << endl;
        preorderExpired(root);
    }
};

int main() {
    BST inventory;

    // Sample products
    inventory.insert(Product(101, "Apple", 2.5, 100, "2023-01-01", "2024-02-01"));
    inventory.insert(Product(102, "Banana", 1.5, 200, "2023-02-01", "2023-12-01"));
    inventory.insert(Product(103, "Cherry", 3.0, 50, "2023-03-01", "2024-03-01"));
    inventory.insert(Product(104, "Date", 4.0, 75, "2023-04-01", "2023-11-01"));

    inventory.displayAll();
    cout << endl;
    inventory.listExpired();

    return 0;
}
```

## Output (Sample)
```
All items in inventory (inorder by name):
Code: 101, Name: Apple, Price: 2.5, Quantity: 100, Date Received: 2023-01-01, Expiration Date: 2024-02-01
Code: 102, Name: Banana, Price: 1.5, Quantity: 200, Date Received: 2023-02-01, Expiration Date: 2023-12-01
Code: 103, Name: Cherry, Price: 3, Quantity: 50, Date Received: 2023-03-01, Expiration Date: 2024-03-01
Code: 104, Name: Date, Price: 4, Quantity: 75, Date Received: 2023-04-01, Expiration Date: 2023-11-01

Expired items (preorder traversal):
Expired: Code: 102, Name: Banana, Expiration Date: 2023-12-01
Expired: Code: 104, Name: Date, Expiration Date: 2023-11-01
