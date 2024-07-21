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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL)  return NULL;

        if(head->next==NULL && n==1)  return NULL;

        ListNode * temp= head;

        int len=0;

        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next;
            len++;
        }

        int cnt= len-n;

        if(cnt<0){
            head=head->next;
            return head;
        }

        ListNode * curr= head;

        for(int i=0;i<cnt;i++){
            curr=curr->next;
        }

        curr->next=curr->next->next; 

        return head;
    }
};

