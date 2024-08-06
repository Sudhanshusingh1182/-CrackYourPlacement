class Solution {
public:
    int f(vector<int>&nums , int i){
       if(i>=nums.size())  return 0;

       int currVal=nums[i];
       int currSum=nums[i];
       int ind=i+1;

       while(ind<nums.size() && currVal== nums[ind]){
         currSum+=nums[ind];
         ind++;
       }
       
      

       while(ind<nums.size() && nums[ind]==currVal+1) ind++;

       return max(currSum+ f(nums,ind), f(nums,i));

    }

    int fMem(vector<int>&nums , int i , vector<int>&dp){
        if(i>=nums.size())  return 0;

        if(dp[i]!=-1)  return dp[i];

       int currVal=nums[i];
       int currSum=nums[i];
       int ind=i+1;

       while(ind<nums.size() && currVal== nums[ind]){
         currSum+=nums[ind];
         ind++;
       }
       
       

       while(ind<nums.size() && nums[ind]==currVal+1) ind++;

       return dp[i]= max(currSum+ fMem(nums,ind,dp), fMem(nums,i+1,dp));
    }

    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        // return f(nums, 0);
        vector<int>dp(nums.size()+1,-1);
        return fMem(nums,0,dp);
    }
};