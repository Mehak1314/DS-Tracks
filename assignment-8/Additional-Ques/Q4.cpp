#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

Node *build(Node *root)
{
    int d;
    cout << "Enter data: ";
    cin >> d;

    if (d == -1)
        return NULL;

    root = new Node(d);

    cout << "Enter LEFT child of " << d << endl;
    root->left = build(root->left);

    cout << "Enter RIGHT child of " << d << endl;
    root->right = build(root->right);

    return root;
}

void rightView(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int lvl = q.size();

        for (int i = 0; i < lvl; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == lvl - 1)
                cout << curr->val << " ";

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
    }
}

int main()
{
    Node *root = nullptr;
    root = build(root);
    cout << "Right view of the tree: ";
    rightView(root);
    cout << endl;
    return 0;
}
