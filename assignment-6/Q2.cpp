#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertNode(Node *&head, int d)
{
    Node *newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void display(Node *head)
{
    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data;
}

int main()
{
    Node *head = NULL;

    insertNode(head, 20);
    insertNode(head, 100);
    insertNode(head, 40);
    insertNode(head, 80);
    insertNode(head, 60);
    display(head);

    return 0;
}
