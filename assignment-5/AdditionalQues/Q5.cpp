#include <iostream>
using namespace std;

struct Node {
    int coeff;  // coefficient
    int pow;    // power
    Node* next;
    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

Node* addPolynomial(Node* p1, Node* p2) {
    Node* head = NULL;   // head of result list
    Node* tail = NULL;   // pointer to build the list

    while (p1 && p2) {
        Node* newNode = NULL;

        if (p1->pow == p2->pow) {
            newNode = new Node(p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        } 
        else if (p1->pow > p2->pow) {
            newNode = new Node(p1->coeff, p1->pow);
            p1 = p1->next;
        } 
        else {
            newNode = new Node(p2->coeff, p2->pow);
            p2 = p2->next;
        }

        if (!head) { // first node
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Add remaining terms
    while (p1) {
        tail->next = new Node(p1->coeff, p1->pow);
        tail = tail->next;
        p1 = p1->next;
    }

    while (p2) {
        tail->next = new Node(p2->coeff, p2->pow);
        tail = tail->next;
        p2 = p2->next;
    }

    return head;
}

// Helper function to print polynomial
void printPoly(Node* head) {
    while (head) {
        cout << head->coeff << "x^" << head->pow;
        if (head->next) cout << " + ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: (5x^2 + 4x^1 + 2x^0) + (5x^1 + 5x^0)
    Node* p1 = new Node(5, 2);
    p1->next = new Node(4, 1);
    p1->next->next = new Node(2, 0);

    Node* p2 = new Node(5, 1);
    p2->next = new Node(5, 0);

    Node* result = addPolynomial(p1, p2);

    cout << "Resultant Polynomial: ";
    printPoly(result);
    return 0;
}
