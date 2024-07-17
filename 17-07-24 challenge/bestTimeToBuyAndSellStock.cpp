class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        int mini=prices[0];

        //buy ->minimum 
        //purchase ->max;
        //purchase-buy :max->ans 
        int profit=0;
        for(int i=0;i<n;i++){
           if(mini<prices[i]){
              profit= max(profit, prices[i]-mini);
           }
           else mini=prices[i];
        }

        return profit;
    }
};