class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow= head;
        ListNode* fast= head;
        bool f=0;

        while(fast!=NULL){
           slow=slow->next;
           fast=fast->next;
           
           if(fast!=NULL) fast=fast->next;

           if(slow == fast){
              f=1;
              break;
           }
        }

        if(fast==NULL) return 0;
        
        return f;
    }
};