class Solution
{
    public:
    
    void inorder(Node *root,vector<int>&ans){
        
        if(root==NULL)
        return ;
        
        inorder(root->left,ans);
        ans.push_back(root->key);
        inorder(root->right,ans);
        
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        vector<int> ans;
        
        inorder(root , ans);
        
        int n=ans.size();
        int successor=-1;
        int predeccesor=-1;
        for(int i=0;i<n;i++){
            if(ans[i]>key){
                successor=ans[i];
                break;
            }
            
        }
        
        for(int i=n-1;i>=0;i--){
            
            if(ans[i]<key){
                predeccesor=ans[i];
                break;
            }
            
        }
        pre= new Node(predeccesor);
        suc=new Node(successor);
        
    }
};