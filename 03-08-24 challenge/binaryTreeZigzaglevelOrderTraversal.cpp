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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         
        vector<vector<int>>res;
        
        if(!root) return res;

        queue<TreeNode* >q;
        q.push(root);
        
        bool f=0;
        while(!q.empty()){
            vector<int>temp;
            int n= q.size();
            for(int i=0;i<n;i++){
               TreeNode* curr = q.front();
               temp.push_back(curr->val);
               q.pop();

               if(curr->left) q.push(curr->left);

               if(curr->right) q.push(curr->right);
            }

            if(!f){
               res.push_back(temp);
               f=!f;
            }

            else if(f){
               reverse(temp.begin(),temp.end());
               res.push_back(temp);
               f=!f;
            }


        }

        return res;

    }
};