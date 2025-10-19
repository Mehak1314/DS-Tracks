class Solution {
public:
    ListNode* rotateLeft(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length
        ListNode* temp = head;
        int n = 1;
        while (temp->next) {
            temp = temp->next;
            n++;
        }

        // Step 2: Normalize k
        k = k % n;
        if (k == 0) return head;

        // Step 3: Find (k-th) node
        ListNode* curr = head;
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }

        // Step 4: Update links
        ListNode* newHead = curr->next;
        curr->next = nullptr;
        temp->next = head;

        return newHead;
    }
};
