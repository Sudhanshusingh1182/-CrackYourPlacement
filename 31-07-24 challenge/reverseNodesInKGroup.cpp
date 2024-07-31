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
    int cnt(ListNode* head ){
      int n=0;
      while(head){
        n++;
        head=head->next;
      }

      return n;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;

        int num= cnt(head);
        if(num<k) return head;

        int x=k;
        ListNode* next , *prev= NULL;
        ListNode* curr= head;

        while(x--){
           next= curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
        }

        //we have prev as the new head

        head->next=  reverseKGroup(next,k);
        return prev;
    }
};