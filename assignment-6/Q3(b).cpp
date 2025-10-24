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

int getSize(Node *head)
{
    if (head == NULL)
        return 0;

    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;

    cout << "Circular Linked List size: " << getSize(head) << endl;
    return 0;
}
