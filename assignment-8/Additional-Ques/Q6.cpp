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

Node *buildTree(int postorder[], int inorder[], int start, int end, int &postPos)
{
    if (start > end)
        return NULL;

    int rootValue = postorder[postPos--];
    Node *root = new Node(rootValue);

    if (start == end)
        return root;

    int mid = searchInorder(inorder, start, end, rootValue);

    root->right = buildTree(postorder, inorder, mid + 1, end, postPos);
    root->left = buildTree(postorder, inorder, start, mid - 1, postPos);

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

    int postorder[100], inorder[100];

    cout << "Enter postorder: ";
    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    cout << "Enter inorder: ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    int postPos = n - 1;
    Node *root = buildTree(postorder, inorder, 0, n - 1, postPos);

    cout << "Tree (inorder): ";
    printInorder(root);
    cout << endl;

    return 0;
}
