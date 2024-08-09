class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&mp , int curr , set<int>&vis ,vector<int>&ans){
        
        if(vis.find(curr)!=vis.end()) return;

        ans.push_back(curr);
        vis.insert(curr);

        for(int x:mp[curr]){
          dfs(mp,x,vis,ans);
        }

    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        unordered_map<int,vector<int>>mp;

        for(auto arr: adjacentPairs){
          mp[arr[0]].push_back(arr[1]);
          mp[arr[1]].push_back(arr[0]);
        }

        int head=0;
        for(auto it:mp){
          if(it.second.size()==1){
            head=it.first;
            break;
          }
        }

        set<int>vis;
        vector<int>ans;
        dfs(mp,head,vis,ans);
        return ans;
    }
};