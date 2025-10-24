#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node *prev;
    Node(char d)
    {
        data = d;
        next = prev = NULL;
    }
};

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    Node *left = head;
    Node *right = tail;
    while (left != right && left->prev != right)
    {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }

    return true;
}

int main()
{
    Node *head = new Node('a');
    head->next = new Node('b');
    head->next->prev = head;
    head->next->next = new Node('b');
    head->next->next->prev = head->next;
    head->next->next->next = new Node('b');
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node('a');
    head->next->next->next->next->prev = head->next->next->next;

    if (isPalindrome(head))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}
