#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to detect and remove loop
void removeLoop(Node* head) {
    Node *slow = head, *fast = head;

    // Step 1: Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // Loop detected
        if (slow == fast)
            break;
    }

    // No loop found
    if (fast == NULL || fast->next == NULL)
        return;

    // Step 2: Find the start of the loop
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Remove loop
    fast->next = NULL;
}

// Helper function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with a loop
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create a loop for testing (5 -> 3)
    head->next->next->next->next->next = head->next->next;

    removeLoop(head);

    cout << "Linked list after removing loop:\n";
    printList(head);

    return 0;
}
