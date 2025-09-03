/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curr1=headA, *curr2=headB;

        // Count the numbers of nodes in list1 & List2
      int m=0,n=0;
      while(curr1){
        curr1=curr1->next;
        m++;
      }
         while(curr2){
        curr2=curr2->next;
        n++;
      }  
       
       curr1=headA, curr2=headB;
 
    //Bring both at same position
      while(n>m){
      curr2=curr2->next;
      n--;
      }

     while(m>n){
      curr1=curr1->next;
      m--;
      }
     
    
     while(curr1){
        if(curr1==curr2)
        return curr1;
        curr1=curr1->next;
        curr2=curr2->next;
     }


    return NULL;
    }
};