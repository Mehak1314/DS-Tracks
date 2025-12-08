#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
bool check(Node *root, unordered_set<int> &seen)
{
    if (root == NULL)
        return false;
    if (seen.count(root->data))
        return true;

    seen.insert(root->data);

    return check(root->left, seen) ||
           check(root->right, seen);
}

int main()
{
    unordered_set<int> seen;
    bool flag = false;

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(2);

    if (check(root, seen))
        flag = true;

    if (flag)
        cout << "DUPLICATE VALUES FOUND.\n";
    else
        cout << "NO DUPLICATE VALUES.\n";

    return 0;
}
