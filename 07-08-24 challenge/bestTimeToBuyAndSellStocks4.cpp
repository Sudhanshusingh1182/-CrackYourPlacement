class Solution {
public:
    int f(int ind , int buy , int transaction , int k , vector<int>&prices, vector<vector<vector<int>>>&dp){
       
       if(ind==prices.size() || transaction==k) return 0;

       if(dp[ind][buy][transaction]!=-1) return dp[ind][buy][transaction];
       
       int profit=0;
       if(buy){
         int buy = -prices[ind]+ f(ind+1,0,transaction, k,prices,dp);
         int skip= 0 + f(ind+1,1,transaction,k,prices,dp);

         profit= max(buy,skip);
       }

       else{
         int sell= prices[ind]+ f(ind+1,1,transaction+1,k,prices,dp);
         int skip= 0 + f(ind+1,0,transaction, k,prices,dp);

         profit= max(sell,skip);
       }

       return dp[ind][buy][transaction]= profit;

    }

    int fTab(int k , vector<int>&prices){
        int n= prices.size();
        //vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(k+1,0)));
        vector<vector<int>>next(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));

        for(int ind=n-1;ind>=0;ind--){
          for(int buy=0;buy<=1;buy++){
            for(int transaction=0;transaction<k;transaction++){
                int profit=0;
                if(buy){
                  int buy = -prices[ind]+ next[0][transaction];
                  int skip= 0 + next[1][transaction]; 

                  profit= max(buy,skip);
                }

                else{
                  int sell= prices[ind]+ next[1][transaction+1]; 
                  int skip= 0 + next[0][transaction]; 

                  profit= max(sell,skip);
                }

                curr[buy][transaction]= profit;

            }
          }

          next=curr;
        }

        return next[1][0];
    } 
    

    int maxProfit(int k, vector<int>& prices) {
        // int n= prices.size();
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(k+1,-1)));

        // return f(0,1,0,k,prices,dp);

        return fTab(k,prices);
    }
};