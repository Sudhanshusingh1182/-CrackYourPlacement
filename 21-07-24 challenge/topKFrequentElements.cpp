class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int,int>mp;
         priority_queue<pair<int,int>>pq;

         for(auto it:nums) mp[it]++;

         for(auto it:mp) pq.push({it.second,it.first});
         
         vector<int>ans;
         while(k-- && !pq.empty()){
              ans.push_back(pq.top().second);
              pq.pop();
         }

         return ans;
    }
};