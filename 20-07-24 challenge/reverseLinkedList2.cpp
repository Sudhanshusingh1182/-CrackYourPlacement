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
    ListNode* reverse(ListNode* start , ListNode* end){
       if(start==end)  return start;

       ListNode* newHead= reverse(start->next, end);
       start->next->next= start;
       start->next= NULL;

       return newHead;
    }  
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         ListNode * dummy= new ListNode(0);
         dummy->next= head;
         ListNode* prev= dummy;

         for(int i=1;i<left;i++) prev=prev->next;

         ListNode* start= prev->next;

         ListNode* end= start;

         for(int i=left;i<right;i++){
          end= end->next;
         }

         ListNode* next= end->next;

         end= reverse(start,end);

         prev->next= end;
         start->next= next;

         return dummy->next;
    }
};