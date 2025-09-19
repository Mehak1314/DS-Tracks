class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode *t1 = headA;
        ListNode *t2 = headB;

        while (t1 != t2) {
            // move to next, or switch list if NULL
            t1 = (t1 == NULL) ? headB : t1->next;
            t2 = (t2 == NULL) ? headA : t2->next;
        }
        return t1;  // will be intersection node or NULL
    }
};
