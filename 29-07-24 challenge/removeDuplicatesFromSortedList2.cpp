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
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head || !head->next)  return head;
        

        ListNode* curr= head;
        ListNode* dummy = new ListNode(-1);
        dummy->next= head;
        ListNode* prev= dummy;
        
        while (curr) {
            // Move to the end of the current set of duplicates
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next;
            }

            
            if (prev->next == curr) {
                prev = prev->next; 
            } else {
               
                prev->next = curr->next;
            }

            curr = curr->next;
        }

        ListNode* new_head = dummy->next;
        delete dummy; 
        return new_head;
    }
    
};