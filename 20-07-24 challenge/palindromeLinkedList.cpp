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

    bool isPalindrome(ListNode* head) {
        
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    ListNode *reversedHead = reverseList(slow);

    // Compare the first half with the reversed second half
    ListNode *temp1 = head;
    ListNode *temp2 = reversedHead;

    while (temp2) {
        if (temp1->val != temp2->val)  
            return false;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true;
    }
};
