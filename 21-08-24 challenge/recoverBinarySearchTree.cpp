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
    TreeNode* firstMistake , *secondMistake , *pre= NULL;
    void inorder(TreeNode* root ){
      if(!root) return;
      
      inorder(root->left);
      if(pre && pre->val > root->val){
         if(!firstMistake) firstMistake= pre;
         secondMistake=root;
      }

      pre=root;
      inorder(root->right);
      
    }

    void recoverTree(TreeNode* root) {

        inorder(root);
        
        swap(firstMistake->val,secondMistake->val);


    }
};