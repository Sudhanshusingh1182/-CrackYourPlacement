//M-1 : tc-> o(n) , sc->o(n)

class Solution {
public:
    bool check(int mid,vector<int> &nums,int k){
      int total=0;
      int j=0,n=nums.size();
      for(int i=0;i<n;i++){
        while(j<n && nums[j]-nums[i]<=mid)j++;
        j--;
        total+=(j-i);
      }
      return total>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
      int n = nums.size();
      sort(nums.begin(),nums.end());
      int l=0,r = nums[n-1]-nums[0];
      while(l<r){
        int mid = (l+r)/2;
        if(check(mid,nums,k)){
          r=mid;
        }
        else{
          l=mid+1;
        }
      }
      return l;
    }
};

//M-2 : tc->o(n) , sc->o(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        //s-1 : Insert the new nodes in between the original linked list

        Node* curr = head;

        while(curr){
          Node* currNext = curr->next; //b
          curr->next = new Node(curr->val); //a->b 

          curr->next->next = currNext; //a->x->b

          curr= currNext; //curr=b
        }

        //s-2 : deep copy of random pointers
        curr= head;

        while(curr && curr->next ){
          if(curr->random == NULL){
            curr->next->random = NULL;
          }

          else{
            curr->next->random = curr->random->next;
          }

          curr=  curr->next->next;
        }

        //s-3 : separate the linked lists
        Node* newHead= head->next;
        Node* newCurr= newHead;
        curr= head;

        while(curr && newCurr){
          curr->next= curr->next == NULL ? NULL : curr->next->next;

          newCurr->next = newCurr->next == NULL ? NULL : newCurr->next->next;

          curr=curr->next;
          newCurr  = newCurr->next;
        }

        return newHead;
    }
};
