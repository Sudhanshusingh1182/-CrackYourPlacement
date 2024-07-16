class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;

        //m-1 : use sets 

        //m-2 : Without using sets

        ListNode * temp = head;

        while(temp && temp->next){
           if(temp->val==temp->next->val) {
                ListNode* nodeToDlt= temp->next;

                temp->next= temp->next->next;
           }

           else temp=temp->next;

        }

        return head;
    }
};