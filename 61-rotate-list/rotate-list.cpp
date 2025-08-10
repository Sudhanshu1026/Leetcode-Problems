/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Count nodes and get last node
        int count = 1; 
        ListNode* last = head;
        while (last->next != NULL) {
            count++;
            last = last->next;
        }

        k = k % count;
        if (k == 0) return head;

        int steps = count - k;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (steps--) {
            prev = curr;
            curr = curr->next;
        }

        last->next = head;
        prev->next = NULL;

        return curr;
    }
};
