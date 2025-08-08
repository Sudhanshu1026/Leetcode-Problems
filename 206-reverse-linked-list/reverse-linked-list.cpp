
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int>ans;     // To store all data of linked list 
        ListNode *temp=head;

        while(temp!=NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }
     int i=ans.size()-1;    
     temp=head;
     while(temp!=NULL){         // Copy data from array to linked list in reverse order

        temp->val = ans[i];
        i--;
        temp = temp->next;

     }

     return head;
    }
};