#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int searchInorder(int inorder[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node *build(int preorder[], int inorder[], int start, int end, int &prePos)
{
    if (start > end)
        return NULL;

    int rootValue = preorder[prePos++];
    Node *root = new Node(rootValue);

    if (start == end)
        return root;

    int mid = searchInorder(inorder, start, end, rootValue);

    root->left = build(preorder, inorder, start, mid - 1, prePos);
    root->right = build(preorder, inorder, mid + 1, end, prePos);

    return root;
}

void printInorder(Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int preorder[100], inorder[100];

    cout << "Enter preorder: ";
    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    cout << "Enter inorder: ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    int prePos = 0;
    Node *root = build(preorder, inorder, 0, n - 1, prePos);
    cout << "Tree (inorder): ";
    printInorder(root);
    cout << endl;

    return 0;
}
