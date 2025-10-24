#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) { 
        data = d; 
        next = NULL; 
    }
};

bool isCircular(Node* head) {
    if (head == NULL) return false;

    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
  return (temp == head);
}

int main() {
    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);

    cout << "List1: ";
    if (isCircular(head1)) 
    cout << "Circular\n";
    else
     cout << "Not Circular\n";

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = head2; 

    cout << "List2: ";
    if (isCircular(head2))
     cout << "Circular\n";
    else 
    cout << "Not Circular\n";

    return 0;
}
