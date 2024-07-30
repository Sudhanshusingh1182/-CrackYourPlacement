class Solution {
public:
    set<vector<int>>s;
    void solve(vector<int> nums, int index, vector<vector<int>>&ans){
        if(index>=nums.size()){
            if(s.find(nums)==s.end()){
            ans.push_back(nums);
            s.insert(nums);
            }
            return;
        }
         
         for(int j=index;j<nums.size();j++){
            swap(nums[j],nums[index]);
            solve(nums,index+1,ans);
            //backtrack
            swap(nums[j],nums[index]);
            //lexicographically sort--> backtrack krna pdega
         }


    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int index=0;
        vector<vector<int>> ans;

        solve(nums,index,ans);
        return ans;
    }
};