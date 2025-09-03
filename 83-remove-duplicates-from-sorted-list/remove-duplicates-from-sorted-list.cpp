class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;   // ✅ check before accessing head->next

        ListNode *curr = head->next, *prev = head, *temp = NULL;
     
        if (head->next != NULL) {        // ✅ safe check, since head is not NULL now
            while (curr) {
                if (prev->val == curr->val) {
                    temp = curr;
                    curr = curr->next;
                    // delete temp;      // ❌ do not delete in LeetCode, just unlink
                    prev->next = curr;
                } else {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
     
        return head;
    }
};
