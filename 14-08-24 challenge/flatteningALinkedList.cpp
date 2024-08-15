class Solution {
  public:
    
    Node* sortedMerge(Node* head1, Node* head2)  
{  
   
   if(head1==NULL)  return head2;
   
   if(head2==NULL)  return head1;
   
   if(head1->data <head2->data){
       head1->bottom = sortedMerge(head1->bottom , head2);
       return head1;
   }
   
   else{
   head2->bottom = sortedMerge(head1,head2->bottom);
   
   return head2;
       
   }
   
}
    
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        
        if(!root) return NULL;
        
        Node* newNode = flatten(root->next);
        
        Node* ans = sortedMerge(root,newNode);
        
        return ans;
    }
};