#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() { head = NULL; }

    // Insert at end
    void insert(int x) {
        ListNode* newNode = new ListNode(x);
        if (head == NULL) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Display the list
    void display() {
        ListNode* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);

    cout << "Linked List: ";
    list.display();

    Solution s;
    ListNode* mid = s.middleNode(list.head);
    cout << "Middle Node Value = " << mid->val << endl;

    return 0;
}
