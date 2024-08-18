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
    void flatten(TreeNode* root) {
        if(root) revPreOrder(root);
    }

private:
     TreeNode* head = NULL;
     void revPreOrder(TreeNode* root){
       if(root->right) revPreOrder(root->right);
       if(root->left) revPreOrder(root->left);

       root->left = NULL;
       root->right= head;
       head=root;
     }
};