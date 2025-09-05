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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
           ListNode *head= new ListNode(0);   //Dummy Node 
           ListNode *tail=head; 

        while(list1 && list2){ //When both list exist
            
            //list 1 ka node add krna hai
            if(list1->val <= list2->val){
                tail->next=list1;
                tail=tail->next;
                list1=list1->next;
                tail->next=NULL;
            }
            else{
                tail->next=list2;
                tail=tail->next;
                list2=list2->next;
                tail->next=NULL;
            }
        }
        //when only list 1 exist
        if(list1)
        tail->next=list1;
        else //when list 2 only exist
        tail->next=list2;
       
       //delete dummy node
       tail=head;
       head=head->next;
       delete tail;


      return head;  
    }
};