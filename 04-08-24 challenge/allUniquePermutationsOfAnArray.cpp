class Solution {
  public:
    void permutations(vector<int> &nums ,set<vector<int>>&s , int l , int h){
        
        if(l==h){
            s.insert(nums);
            return;
        }
        
        for(int i=l;i<=h;i++){
            swap(nums[l],nums[i]);
            
            permutations(nums,s,l+1,h);
            
            swap(nums[l],nums[i]);
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        
        set<vector<int>>s;
        vector<vector<int>>res;
        
        permutations(arr,s,0,arr.size()-1);
        
        for(auto it : s){
            res.push_back(it);
        }
        
        return res;
    }
};