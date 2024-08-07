class Solution {
public:
    int f(int ind , bool buy , vector<int>&prices,vector<vector<int>>&dp){
       
       if(ind>=prices.size()) return 0;

       if(dp[ind][buy]!=-1) return dp[ind][buy];
       
       int profit=0;
       if(buy){
         int buyKro= -prices[ind]+ f(ind+1,0,prices,dp);
         int skipKaro= 0 + f(ind+1,1,prices,dp);
         profit= max(buyKro, skipKaro);
       }

       else{
        int sellKaro = prices[ind]+ f(ind+1,1,prices,dp);
        int skipKaro= 0 + f(ind+1,0,prices,dp);
        profit= max(sellKaro,skipKaro);
       }

       return dp[ind][buy]= profit;

    }
    
    int fTab(vector<int>&prices){
       int n = prices.size();
      //  vector<vector<int>>dp(n+1,vector<int>(2,0));
       vector<int>next(2,0);
       vector<int>curr(2,0); 
       //looping kaise krenge -> Jo memoization me tha ..uska just ulta -> ind-> (n-1) to 0 , buy -> 0 to 1

       for(int ind= n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
              int buyKro= -prices[ind]+ next[0]; 
              int skipKaro= 0 + next[1]; 
              profit= max(buyKro, skipKaro);
            }

            else{
              int sellKaro = prices[ind]+ next[1];
              int skipKaro= 0 + next[0];
              profit= max(sellKaro,skipKaro);
            }
            curr[buy]=profit;
        }
        next=curr;
       }

       //what to return -> see what the memoized solution returns -> check what you are returning -> 0 1 return kr rhe h

       return next[1];
    }
    
    int maxProfit(vector<int>& prices) {
        //2 parameters are changing -> 2D dp bnega
        // int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return f(0,1,prices,dp);

        return fTab(prices);
    }
};