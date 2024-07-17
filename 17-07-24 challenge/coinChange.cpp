class Solution {
private:
    int f(int ind , int amount , vector<int>&coins ,vector<vector<int>>&dp){
      
       if(amount==0) return 0;
       if(ind<0 || amount< 0 ) return INT_MAX-1;
      

       if(dp[ind][amount]!=-1) return dp[ind][amount];

       int take=  1 + f(ind,amount-coins[ind],coins,dp);
       int not_take= f(ind-1,amount, coins,dp);
       
       return dp[ind][amount]= min(take,not_take);
    }  
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n= coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        int ans= f(n-1,amount,coins,dp);
        return ans== INT_MAX-1 ? -1 : ans;
    }
};