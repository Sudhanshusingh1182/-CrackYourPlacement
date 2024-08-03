/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*>parent;
    
    void addParent(TreeNode* root){
      if(!root) return;

      //left 
      if(root->left) parent[root->left]=root;
      addParent(root->left);

      //right
      if(root->right) parent[root->right]= root;
      addParent(root->right);
      
    }

    void bfs(vector<int>&result , TreeNode* target ,int k){
       queue<TreeNode*> q;
       q.push(target);
       unordered_set<int>vis;
       vis.insert(target->val);

       while(!q.empty()){
          int n= q.size();

          if(k==0) break;

          while(n--){
            TreeNode* curr = q.front();
            q.pop();
            
            //left ke liye processing
            if(curr->left && !vis.count(curr->left->val)){
               q.push(curr->left);
               vis.insert(curr->left->val);
            }

            //right ke liye processing
            if(curr->right && !vis.count(curr->right->val)){
               q.push(curr->right);
               vis.insert(curr->right->val);
            }

            //parent ke liye processing
            if(parent.count(curr) && !vis.count(parent[curr]->val)){
              q.push(parent[curr]);
              vis.insert(parent[curr]->val);
            }

          }

          k--;
       }
       
       while(!q.empty()){
         result.push_back(q.front()->val);
         q.pop();
       }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int>result;

        //populate parent 
        addParent(root);
        
        bfs(result , target,k);
        return result;

    }
};