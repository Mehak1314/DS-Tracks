#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val): data(val),next(NULL){}
};
void insert(Node* &head,int val){
    Node* newnode= new Node(val);
    if(!head){
        head=newnode;
        return;
    }
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
        temp->next=newnode;
}
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}
int countAndDelete(Node*& head, int key) {
    int count = 0;

    // Dummy node to simplify deletion logic
    Node* dummy = new Node(-1);
    dummy->next = head;
    Node* curr = dummy;

    while (curr->next) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }

    // Update real head
    head = dummy->next;
    delete dummy;
    return count;
}

int main(){
    Node* head = nullptr;
    
    // Example input: 1->2->1->2->1->3->1
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 3);
    insert(head, 1);

    cout << "Original List: ";
    printList(head);

    int key = 1;
    int count = countAndDelete(head, key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}