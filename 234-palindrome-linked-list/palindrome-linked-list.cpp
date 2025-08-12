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
    bool isPalindrome(ListNode* head) {


     // Handle Edge Case : If only 1 Node Present.
    if(head->next==NULL)
      return 1;


      //Count total No's of Nodes
      int count=0;
      ListNode *temp=head;
      while(temp){
        count++;
        temp=temp->next;
      }
    
    //Finding size of two equal lists
    count=count/2;

    //Dividing list Into two parts.
    ListNode *curr=head,*prev=NULL;
    while(count--){
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;        //Divided list into 2 equal parts

    //'head' is pointing 1st list & 'curr' is pointing 2nd list.


    //Reverse the second list 
    ListNode *front=NULL;
    prev=NULL;

    while(curr){
        front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }

//Now 2nd list is reversed  
//'head' is pointing 1st list & 'prev' is pointing 2nd list.

        ListNode *head1=head,*head2=prev;

        while(head1){
            if(head1->val != head2->val) //Do not matched !...Not a palindrome
            return 0;

            head1=head1->next;
            head2=head2->next;
        }
     
     return 1;     //All matched witout loop break !...Its a palindrome

    }
};