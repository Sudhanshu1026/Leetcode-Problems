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
    int getDecimalValue(ListNode* head) {
         ListNode *temp=head;
          
          int count =0;
         //Count no of nodes
         while(temp){
          temp=temp->next;
          count++;
         }
         count=count-1;
         int num=0;
         temp=head; 

         while(temp){
            num = num + temp->val * pow(2,count);
            temp=temp->next;
            count--;

         }
         return num;
    }
};