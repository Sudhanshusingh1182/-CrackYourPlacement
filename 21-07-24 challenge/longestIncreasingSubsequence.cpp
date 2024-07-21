class Solution {
public:
    int f(int ind , int prevInd, vector<int>&nums , vector<vector<int>>&dp){
       if(ind==nums.size() ) return 0;

       if(dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1];

       //exclude-include wala case
       int exclude= f(ind+1,prevInd,nums ,dp);

       int include=0;
       if(prevInd==-1) include= 1+ f(ind+1,ind,nums,dp);

       else if(nums[prevInd]<nums[ind]) include=1+ f(ind+1,ind,nums,dp);

       return dp[ind][prevInd+1]= max(include,exclude);

    }

    int lengthOfLIS(vector<int>& nums) {

        //  int n= nums.size(); 
        //  vector<vector<int>>dp(n,vector<int>(n+1,-1));
        //  return f(0,-1,nums,dp);

        int n=nums.size();
        int ans=1;
        vector<int>dp(n+1,1);

        for(int i=0;i<n;i++){
          for(int j=0;j<i;j++){
            if(nums[i]> nums[j]) dp[i]=max(dp[i],1+dp[j]),ans=max(ans,dp[i]);
          }
        }

        return ans;
    }
};