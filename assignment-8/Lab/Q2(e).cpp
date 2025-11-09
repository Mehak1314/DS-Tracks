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

// Function to insert nodes into BST
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

// Find maximum node in a subtree (used for predecessor)
node* findMax(node* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to find inorder predecessor in BST
node* inorderPredecessor(node* root, node* p) {
    if (p->left != NULL) {
        // Case 1: Left subtree exists
        return findMax(p->left);
    }

    // Case 2: No left subtree
    node* predecessor = NULL;
    while (root != NULL) {
        if (p->data > root->data) {
            predecessor = root;
            root = root->right;
        }
        else if (p->data < root->data) {
            root = root->left;
        }
        else break;
    }
    return predecessor;
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
    cout << "Enter node value to find its inorder predecessor: ";
    cin >> key;

    // Find pointer to the node (manual search)
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

    node* pred = inorderPredecessor(root, p);

    if (pred)
        cout << "Inorder Predecessor of " << key << " is: " << pred->data << endl;
    else
        cout << "No Inorder Predecessor exists for " << key << endl;

    return 0;
}
