#include <iostream>
#include <unordered_set>
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
int main()
{
    unordered_set<Node *> visited;
    int flag = 1;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(5);
    head->next->next->next->next = head->next;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited.count(temp))
        {
            flag = 0;
            break;
        }
        else
        {
            visited.insert(temp);
        }
        temp = temp->next;
    }
    if (flag == 1)
        cout << "DUPLICATE NODES DONOT EXIST.\n";
    else
        cout << "DUPLICATE NODES FOUND.\n";
}
