#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyCircularList {
private:
    Node* head;

public:
    DoublyCircularList() { head = nullptr; }

    // Display list
    void display() {
        if (!head) { cout << "List is empty\n"; return; }
        Node* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return;
        }
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    // Insert after a node
    void insertAfter(int target, int val) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == target) {
                Node* newNode = new Node(val);
                Node* nxt = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
                newNode->next = nxt;
                nxt->prev = newNode;
                if (temp == head->prev) head->prev = newNode; // update tail
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << target << " not found.\n";
    }

    // Insert before a node
    void insertBefore(int target, int val) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == target) {
                Node* newNode = new Node(val);
                Node* prevNode = temp->prev;
                newNode->next = temp;
                newNode->prev = prevNode;
                prevNode->next = temp->prev = newNode;
                if (temp == head) head = newNode; // update head
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << target << " not found.\n";
    }

    // Delete a node
    void deleteNode(int val) {
        if (!head) { cout << "List is empty\n"; return; }
        Node* temp = head;
        do {
            if (temp->data == val) {
                if (temp->next == temp) { // only one node
                    delete temp;
                    head = nullptr;
                    return;
                }
                Node* prevNode = temp->prev;
                Node* nextNode = temp->next;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                if (temp == head) head = nextNode;
                delete temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << val << " not found.\n";
    }

    // Search a node
    bool search(int val) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == val) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }
};

// Menu-driven program
int main() {
    DoublyCircularList list;
    int choice, val, target;

    do {
        cout << "\n--- Circular Doubly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert after a node\n4. Insert before a node\n";
        cout << "5. Delete a node\n6. Search a node\n7. Display list\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; list.insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; list.insertAtEnd(val); break;
            case 3: cout << "Enter target node: "; cin >> target; cout << "Enter value: "; cin >> val; list.insertAfter(target, val); break;
            case 4: cout << "Enter target node: "; cin >> target; cout << "Enter value: "; cin >> val; list.insertBefore(target, val); break;
            case 5: cout << "Enter node to delete: "; cin >> val; list.deleteNode(val); break;
            case 6: cout << "Enter node to search: "; cin >> val; 
                    if(list.search(val)) cout << "Node found\n"; else cout << "Node not found\n"; break;
            case 7: list.display(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n"; 
        }
    } while(choice != 0);

    return 0;
}
