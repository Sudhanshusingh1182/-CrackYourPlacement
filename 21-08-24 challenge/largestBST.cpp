class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    bool util(Node* root , int mini , int maxi){
        
        if(!root) return 1;
        
        if(root->data <= mini || root->data >= maxi) return 0;
        
        return util(root->left,mini,root->data) && util(root->right,root->data,maxi);
    }
    
    bool validBST(Node* root){
        return util(root,INT_MIN, INT_MAX); 
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	if(!root) return 0;
    	
    	//check if Valid BST
    	if(validBST(root)) return 1 + largestBst(root->left)+ largestBst(root->right);
    	
    	return max(largestBst(root->left), largestBst(root->right));
    	
    	
    }
};