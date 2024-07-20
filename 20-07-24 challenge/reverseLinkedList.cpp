class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        // if(head==NULL || head->next==NULL)  return head;

        // ListNode * front = reverseList(head->next);

        // head->next->next=head;

        // head->next=NULL;

        // return front;

        //recursive approach 

        ListNode * prev =NULL;
        ListNode * temp= head;

        while(temp!=NULL){
            ListNode * front= temp->next;
            
            temp->next=prev;
            prev=temp;
            temp=front;

        }

        return prev;
    }
};