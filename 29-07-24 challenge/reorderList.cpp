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
    void reorderList(ListNode* head) {
        
        //Approach 1 : I can create a vector and then make a new LL

        //approach -2 : 

          if(!head || !head->next)  return;

         ListNode* first = head;
         ListNode* slow= head, *fast= head;

         while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second= reverse(slow->next);
        slow->next=NULL;

        ListNode* temp1 , *temp2;

        while(second){
          temp1= first->next;
          temp2= second->next;

          first->next=second;
          second->next=temp1;

          first=temp1;
          second=temp2;
        }
        
        
    }
};