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
    void inorder(TreeNode* root, int dist, int level, map<int, vector<pair<int,int>>>& mp) {
        if (!root) return;

        mp[dist].emplace_back(level, root->val);
        inorder(root->left, dist - 1, level + 1, mp);
        inorder(root->right, dist + 1, level + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<pair<int, int>>> mp; // dist -> vector of (level, val)

        if (!root) return res;

        inorder(root, 0, 0, mp);

        for (auto& [dist, nodes] : mp) {
            sort(nodes.begin(), nodes.end());
            vector<int> col;
            for (auto& [level, value] : nodes) {
                col.push_back(value);
            }
            res.push_back(col);
        }

        return res;
    }
};