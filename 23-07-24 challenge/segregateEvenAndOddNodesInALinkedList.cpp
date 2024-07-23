class Solution{
public:
    Node* divide(int N, Node *head){
        vector<int> even;
        vector<int>odd;
        
        Node * temp = head;
        
        while(temp){
            
            if(temp->data %2==0)  even.push_back(temp->data);
            
            else  odd.push_back(temp->data);
            
            temp=temp->next;
        }
        
        temp= head;
        
        for(int i=0;i<even.size();i++){
            temp->data = even[i];
            temp=temp->next;
        }
        
        for(int i=0;i<odd.size();i++){
            temp->data = odd[i];
            temp=temp->next;
        }
        
        return head;
    }
};