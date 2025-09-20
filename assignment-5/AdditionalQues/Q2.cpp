if (!head || k == 1) return head;

        // Step 1: Check if there are k nodes
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head; // not enough nodes
            temp = temp->next;
        }

        // Step 2: Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: Connect rest of the list
        // head is now the tail of this reversed segment
        head->next = reverseKGroup(curr, k);

        // prev is the new head of this reversed segment
        return prev;
