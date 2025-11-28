# Assignment 04-10

## Aim
To implement a Binary Search Tree (BST) to manage inventory of products with capabilities to insert, display, delete by product code, and delete expired products.

## Steps Followed
1. Defined a `Product` structure with code, name, price, quantity, date received, and expiration date.
2. Defined a `Node` structure containing a `Product` and pointers to left and right children.
3. Implemented BST class with:
   - Insert method to add products sorted by product code.
   - Delete by product code method handling all deletion cases.
   - Method to collect expired products based on expiration date compared to current preset date.
   - Method to delete all expired products.
   - Inorder traversal to display all current products.
4. Inserted sample products into the BST.
5. Demonstrated:
   - Display all products.
   - Delete a specific product by code.
   - Delete all expired products.
   - Display products after each operation.
   
## Code
```cpp
#include <iostream>
#include <string>
#include <vector>

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
    string currentDate = "2024-01-01"; // Assume current date

    Node* insert(Node* node, Product p) {
        if (!node) return new Node(p);
        if (p.code < node->product.code) node->left = insert(node->left, p);
        else node->right = insert(node->right, p);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int code) {
        if (!node) return node;
        if (code < node->product.code) node->left = deleteNode(node->left, code);
        else if (code > node->product.code) node->right = deleteNode(node->right, code);
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
            node->product = temp->product;
            node->right = deleteNode(node->right, temp->product.code);
        }
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

    void collectExpired(Node* node, vector<int>& expiredCodes) {
        if (!node) return;
        collectExpired(node->left, expiredCodes);
        if (node->product.expirationDate < currentDate) {
            expiredCodes.push_back(node->product.code);
        }
        collectExpired(node->right, expiredCodes);
    }

public:
    BST() : root(NULL) {}

    void insert(Product p) { root = insert(root, p); }

    void deleteByCode(int code) { root = deleteNode(root, code); }

    void deleteExpired() {
        vector<int> expiredCodes;
        collectExpired(root, expiredCodes);
        for (int code : expiredCodes) {
            deleteByCode(code);
        }
    }

    void displayAll() {
        cout << "All items in inventory (inorder by code):" << endl;
        inorder(root);
    }
};

int main() {
    BST inventory;

    // Sample products
    inventory.insert(Product(101, "Apple", 2.5, 100, "2023-01-01", "2024-02-01"));
    inventory.insert(Product(102, "Banana", 1.5, 200, "2023-02-01", "2023-12-01"));
    inventory.insert(Product(103, "Cherry", 3.0, 50, "2023-03-01", "2024-03-01"));
    inventory.insert(Product(104, "Date", 4.0, 75, "2023-04-01", "2023-11-01"));

    cout << "Initial inventory:" << endl;
    inventory.displayAll();

    // Delete a product by code
    inventory.deleteByCode(102);
    cout << "\nAfter deleting product code 102:" << endl;
    inventory.displayAll();

    // Delete expired products
    inventory.deleteExpired();
    cout << "\nAfter deleting expired products:" << endl;
    inventory.displayAll();

    return 0;
}
```

## Output (Sample)
```
Initial inventory:
Code: 101, Name: Apple, Price: 2.5, Quantity: 100, Date Received: 2023-01-01, Expiration Date: 2024-02-01
Code: 102, Name: Banana, Price: 1.5, Quantity: 200, Date Received: 2023-02-01, Expiration Date: 2023-12-01
Code: 103, Name: Cherry, Price: 3, Quantity: 50, Date Received: 2023-03-01, Expiration Date: 2024-03-01
Code: 104, Name: Date, Price: 4, Quantity: 75, Date Received: 2023-04-01, Expiration Date: 2023-11-01

After deleting product code 102:
Code: 101, Name: Apple, Price: 2.5, Quantity: 100, Date Received: 2023-01-01, Expiration Date: 2024-02-01
Code: 103, Name: Cherry, Price: 3, Quantity: 50, Date Received: 2023-03-01, Expiration Date: 2024-03-01
Code: 104, Name: Date, Price: 4, Quantity: 75, Date Received: 2023-04-01, Expiration Date: 2023-11-01

After deleting expired products:
Code: 101, Name: Apple, Price: 2.5, Quantity: 100, Date Received: 2023-01-01, Expiration Date: 2024-02-01
Code: 103, Name: Cherry, Price: 3, Quantity: 50, Date Received: 2023-03-01, Expiration Date: 2024-03-01
