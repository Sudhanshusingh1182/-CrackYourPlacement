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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans; 

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0}); // node and its level

        while (!q.empty()) {
            auto front = q.front();
            TreeNode* node = front.first;
            int level = front.second;
            q.pop();

            
            if (ans.size() == level) {
                ans.push_back(vector<int>()); // create a new level
            }

            ans[level].push_back(node->val);

            // Push the child nodes to the queue with their corresponding level
            if (node->left) {
                q.push({node->left, level + 1});
            }
            if (node->right) {
                q.push({node->right, level + 1});
            }
        }

        return ans;
    }
};