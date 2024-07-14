class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto it:nums) mp[it]++;

        int times= nums.size()/2;

        for(int i=0;i<nums.size();i++){
          if(mp[nums[i]]> times) return nums[i];
        }

        return -1;
    }
};