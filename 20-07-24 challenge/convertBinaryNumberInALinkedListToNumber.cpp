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
    int getDecimalValue(ListNode* head) {

        if(!head)  return 0; 
        
        string str;

        ListNode* temp= head;

        while(temp){
           str+=temp->val;
           temp=temp->next;
        }

        int ans=0, i= str.length()-1;

        while(i>=0){
          ans+= str[i]*pow(2,str.length()-1-i);

          i--;
        }

        return ans;
        
    }
};