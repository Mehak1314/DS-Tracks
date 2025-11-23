#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *insertBST(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);
    if (x < root->data)
        root->left = insertBST(root->left, x);
    else
        root->right = insertBST(root->right, x);
    return root;
}

void convertToList(Node *root, Node *&head, Node *&last)
{
    if (!root)
        return;
    convertToList(root->left, head, last);
    if (!last)
        head = root;
    else
    {
        last->right = root;
        root->left = last;
    }
    last = root;
    convertToList(root->right, head, last);
}

Node *mergeLists(Node *a, Node *b)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (a && b)
    {
        Node *temp;
        if (a->data < b->data)
        {
            temp = a;
            a = a->right;
        }
        else
        {
            temp = b;
            b = b->right;
        }
        temp->left = tail;
        if (tail)
            tail->right = temp;
        else
            head = temp;
        tail = temp;
    }

    while (a)
    {
        Node *temp = a;
        a = a->right;
        temp->left = tail;
        if (tail)
            tail->right = temp;
        else
            head = temp;
        tail = temp;
    }

    while (b)
    {
        Node *temp = b;
        b = b->right;
        temp->left = tail;
        if (tail)
            tail->right = temp;
        else
            head = temp;
        tail = temp;
    }

    return head;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        if (head->right != NULL)
            cout << "<->";
        head = head->right;
    }
}

int main()
{
    Node *t1 = NULL, *t2 = NULL;
    int x;

    cout << "Enter values for first BST (end with -1): ";
    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        t1 = insertBST(t1, x);
    }

    cout << "Enter values for second BST (end with -1): ";
    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        t2 = insertBST(t2, x);
    }

    Node *head1 = NULL, *last1 = NULL;
    Node *head2 = NULL, *last2 = NULL;

    convertToList(t1, head1, last1);
    convertToList(t2, head2, last2);

    Node *merged = mergeLists(head1, head2);

    cout << "Merged DLL: ";
    printList(merged);

    return 0;
}
