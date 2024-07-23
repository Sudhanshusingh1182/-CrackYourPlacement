class Solution {
public:
    void inorder(TreeNode* root , vector<int>&ans){
      if(root==NULL) return;

      inorder(root->left,ans);
      ans.push_back(root->val);
      inorder(root->right,ans);

    }
    int kthSmallest(TreeNode* root, int k) {
        
        //we can use the property that the inorder traversal of BST is sorted
        vector<int>ans;
        inorder(root,ans);
        
        return ans[k-1];

    }
};