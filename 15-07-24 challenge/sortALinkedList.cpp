#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
     void insertAtTail(Node * &tail, Node * curr){
        tail->next=curr;
        tail=curr;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
       Node* oneHead=new Node(-1);
        Node* oneTail= oneHead;
        
        Node* zeroHead=new Node(-1);
        Node* zeroTail= zeroHead;
        
        Node* twoHead=new Node(-1);
        Node* twoTail= twoHead;
        
        Node * curr = head;
        
        while(curr!=NULL){
            if(curr->data==0){
                insertAtTail(zeroTail,curr);
            }
             else if(curr->data==1){
                insertAtTail(oneTail,curr);
            }
              else if(curr->data==2){
                insertAtTail(twoTail,curr);
            }
            curr=curr->next;
        }
        //at this point ,we are having three different l.l for 0,1 and 2
        
        //merging three linked lists
        
        if(oneHead->next!=NULL){
            zeroTail->next=oneHead->next;
        }
        else{
            //if 1 wali node doesn't have any element
            //directly join 0 and 2 wale nodes 
            zeroTail->next= twoHead->next;
        }
        
            oneTail->next=twoHead->next;
            twoTail->next=NULL;
            
            head=zeroHead->next;
       
       //delete the dummy nodes 
       
       delete(zeroHead);
       delete(oneHead);
       delete(twoHead);
       
       return head;
        
    }
};
