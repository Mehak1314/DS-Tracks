#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        this->data=value;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val == root->data) {
        cout << "Duplicate values not allowed!\n";
        return root;
    }
    else if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Function to find the minimum value node in BST (used in deletion)
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get inorder successor (smallest in right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data; // Copy the inorder successor's value
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

// Function to calculate maximum depth
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Function to calculate minimum depth
int minDepth(Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL)
        return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Inorder traversal (for testing)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int choice, val;

    while (true) {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Display Inorder Traversal\n";
        cout << "4. Find Maximum Depth\n";
        cout << "5. Find Minimum Depth\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            root = insert(root, val);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
            break;
        case 3:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Maximum Depth of BST: " << maxDepth(root) << endl;
            break;
        case 5:
            cout << "Minimum Depth of BST: " << minDepth(root) << endl;
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
