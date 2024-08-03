class Solution{
  public:
    bool isPossible(Node* root , int l , int r){
        
        if(!root) return false;
        
        if(l==r) return true;
        
        return isPossible(root->left ,l,root->data -1) || isPossible(root->right,root->data +1,r );
        
    }
    
    bool isDeadEnd(Node *root)
    {
       
       if(!root) return false;
       
       bool f = isPossible(root , 1 ,INT_MAX);
       return f;
    }
};    