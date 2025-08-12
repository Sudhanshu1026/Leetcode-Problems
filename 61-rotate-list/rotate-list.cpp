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
        //Basic Edge cases!!
        if (head==NULL || head->next==NULL ) 
        return head;



        // Count nodes and get last node
        int count = 0;
        ListNode *temp=head;
        while(temp){
            count++;
            temp=temp->next;
        } 
      
        k = k % count;
        // Edge case:if k=0. -> No need to rotate
        if (k == 0) 
        return head;

         count = count - k;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (count--) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;

      //Create a tail pointer and move it to end
        ListNode *tail=curr; 
        while(tail->next!=NULL)
        tail=tail->next;
     
    //Link last node and first node
    tail->next=head;
    head=curr;



        return head;
    }
};
