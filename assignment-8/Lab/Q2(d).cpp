#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to insert node into BST
node* insertInBST(node* root, int data) {
    if (root == NULL) {
        root = new node(data);
        return root;
    }
    if (data < root->data)
        root->left = insertInBST(root->left, data);
    else
        root->right = insertInBST(root->right, data);
    return root;
}

// Function to find minimum node (used for successor)
node* findMin(node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find inorder successor in BST
node* inorderSuccessor(node* root, node* p) {
    if (p->right != NULL) {
        // Case 1: If right subtree exists
        return findMin(p->right);
    }

    // Case 2: No right subtree
    node* successor = NULL;
    while (root != NULL) {
        if (p->data < root->data) {
            successor = root;
            root = root->left;
        }
        else if (p->data > root->data) {
            root = root->right;
        }
        else break;
    }
    return successor;
}

int main() {
    node* root = NULL;
    int n, data;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter BST elements: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insertInBST(root, data);
    }

    int key;
    cout << "Enter node value to find its inorder successor: ";
    cin >> key;

    // manually locate the node pointer
    node* p = root;
    while (p != NULL && p->data != key) {
        if (key < p->data)
            p = p->left;
        else
            p = p->right;
    }

    if (p == NULL) {
        cout << "Node not found in BST!" << endl;
        return 0;
    }

    node* succ = inorderSuccessor(root, p);

    if (succ)
        cout << "Inorder Successor of " << key << " is: " << succ->data << endl;
    else
        cout << "No Inorder Successor exists for " << key << endl;

    return 0;
}
