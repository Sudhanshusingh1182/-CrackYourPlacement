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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        return Sum(root,0,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right , targetSum);
    }

    int Sum(TreeNode* root , long long pre , int& sum){
      if(!root) return 0;

      long long curr =(long long) pre + root->val;

      return (curr==sum) + Sum(root->left, curr , sum)+ Sum(root->right, curr,sum);
    }
};