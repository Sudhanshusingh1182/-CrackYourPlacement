class Solution {
private:

    ListNode* solve(ListNode* list1 , ListNode* list2){
      
      if(list1==NULL)   return list2;

      if(list2==NULL)   return list1;
      
      ListNode * newnode = NULL;

      if(list1->val < list2->val){
        newnode = list1;
        newnode->next = solve(list1->next , list2);
      }

      else{
        newnode = list2;
        newnode->next = solve(list1 , list2->next);
      }
      
      return newnode;

    }  
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;


        if(list1->val<=list2->val){
          return solve(list1,list2);
        }

        else{
          return solve(list2,list1);
        }
    }
};