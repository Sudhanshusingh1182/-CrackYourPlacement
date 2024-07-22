class Solution {
   
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<int>>mp;

        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(i);
        }

        vector<vector<string>> ans;

        for(auto it : mp){
           vector<string>temp;
           for(auto x: it.second)
           temp.push_back(strs[x]);

          ans.push_back(temp); 
        }

        return ans;
    }
};