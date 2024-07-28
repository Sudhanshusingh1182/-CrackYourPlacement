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
private:
    ListNode* reverse(ListNode* head){
      if(!head || !head->next)  return head;

      ListNode* newnode= reverse(head->next);

      head->next->next= head;
      head->next=NULL;
      return newnode; 
    }  

public:
    
    ListNode * solve(ListNode* temp1 , ListNode* temp2){
        
        ListNode * prev = NULL;
        int carry=0,sum=0;
        while(temp1 && temp2){
            sum= carry + temp1->val + temp2->val;
            temp1->val = sum%10;
            carry= sum/10;
            prev= temp1;
            temp1= temp1->next;
            temp2=temp2->next;
        }

        while(temp1){
              sum= carry + temp1->val;
              temp1->val = sum %10;
              carry= sum/10; 
              prev= temp1;
              temp1= temp1->next;
        }

        if(carry){
          ListNode* newnode= new ListNode(carry);
          prev->next= newnode;
        }

        return temp1? temp1 : prev ;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!l1 && l2) return l2;

        if(l1 && !l2)  return l1;
        
        ListNode* head1= reverse(l1);
        ListNode* head2= reverse(l2);

        ListNode * temp1=head1;
        ListNode* temp2= head2;

        //I want to determine that whose length is longer : 

        int cnt1=0 ,cnt2=0;

        while(temp1){
          cnt1++;
          temp1 = temp1->next;
        }

        while(temp2){
          cnt2++;
          temp2=temp2->next;
        }

          ListNode* ansNode =  cnt1>=cnt2 ?  solve(head1 , head2) :  solve(head2,head1);

        ListNode* reversedAnsNode= reverse(cnt1 >= cnt2 ? head1 : head2);

        return reversedAnsNode;
        
      
    }
};