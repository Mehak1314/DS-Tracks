#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertBefore(Node*& head, int key, int val) {
    if (!head) return;
    if (head->data == key) {
        insertAtBeginning(head, val);
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next) {
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        cout << "Key not found.\n";
    }
}

void insertAfter(Node*& head, int key, int val) {
    Node* temp = head;
    while (temp && temp->data != key) {
        temp = temp->next;
    }
    if (temp) {
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        cout << "Key not found.\n";
    }
}

void deleteAtBeginning(Node*& head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd(Node*& head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteNode(Node*& head, int key) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    } else {
        cout << "Key not found.\n";
    }
}

void search(Node* head, int key) {
    int pos = 1;
    while (head) {
        if (head->data == key) {
            cout << "Node found at position " << pos << endl;
            return;
        }
        head = head->next;
        pos++;
    }
    cout << "Node not found.\n";
}

void display(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int choice, val, key;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete at Beginning\n";
        cout << "6. Delete at End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertAtBeginning(head, val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(head, val);
            break;
        case 3:
            cout << "Enter key to insert before: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> val;
            insertBefore(head, key, val);
            break;
        case 4:
            cout << "Enter key to insert after: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> val;
            insertAfter(head, key, val);
            break;
        case 5:
            deleteAtBeginning(head);
            break;
        case 6:
            deleteAtEnd(head);
            break;
        case 7:
            cout << "Enter key to delete: ";
            cin >> key;
            deleteNode(head, key);
            break;
        case 8:
            cout << "Enter key to search: ";
            cin >> key;
            search(head, key);
            break;
        case 9:
            display(head);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
