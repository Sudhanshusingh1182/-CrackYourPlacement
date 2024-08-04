class Solution
{
    public: 
    
    void inorder(vector<int>&ans , Node* root){
        if(!root) return;
        
        inorder(ans,root->left);
        ans.push_back(root->data);
        inorder(ans,root->right);
    }
    
    Node* arrayToDLL(vector<int>&ans , int n){
        if(n==0) return NULL;
        
        Node* head= new Node(ans[0]);
        Node* temp = head;
        
        for(int i=1;i<n;i++){
            Node* newNode = new Node(ans[i]);
            temp->right = newNode;
            newNode->left = temp;
            temp=temp->right;
        }
        
        return head;
    }
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
       
       vector<int>ans;
       
       inorder(ans,root);
       
       int n = ans.size();
       
       Node* res= arrayToDLL(ans,n);
       
       return res;
    }
};