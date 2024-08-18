/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi=0;

    int solve(TreeNode* root){
       if(!root) return 0;

       int left = solve(root->left);
       int right = solve(root->right);

       //case1 : 
       int c1 = left + right + root->val;
       int c2 = root->val + max(left,right);
       int c3= root->val;

       maxi= max({maxi,c1,c2,c3});

       return max(c2,c3);

    }

    int maxPathSum(TreeNode* root) {
        
        maxi=INT_MIN;

        solve(root);

        return maxi;
    }
};