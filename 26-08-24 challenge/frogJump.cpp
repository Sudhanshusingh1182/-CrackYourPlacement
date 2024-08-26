class Solution {
public:
    bool solving_rec(vector<int>& stones,int idx,int last,unordered_map<int,int>&check){
        if(idx==stones.size()-1) return true;
        if(idx>=stones.size()) return false;
        bool ans1=false;
        bool ans2=false;
        bool ans3=false;
        if(check[stones[idx]+last-1] && last!=1){
            ans1=solving_rec(stones,check[stones[idx]+last-1],last-1,check);
        }
        if(check[stones[idx]+last]){
            ans2=solving_rec(stones,check[stones[idx]+last],last,check);
        }
        if(check[stones[idx]+last+1]){
            ans3=solving_rec(stones,check[stones[idx]+last+1],last+1,check);
        }
        return ans1||ans2||ans3;
    }
    bool solving_mem(vector<int>& stones,int idx,int last,unordered_map<int,int>&check,vector<vector<int>>&dp){
        if(idx==stones.size()-1) return true;
        if(idx>=stones.size()) return false;
        bool ans1=false;
        bool ans2=false;
        bool ans3=false;
        if(dp[idx][last]!=-1) return dp[idx][last];
        if(check[stones[idx]+last-1] && last!=1){
            ans1=solving_mem(stones,check[stones[idx]+last-1],last-1,check,dp);
        }
        if(check[stones[idx]+last]){
            ans2=solving_mem(stones,check[stones[idx]+last],last,check,dp);
        }
        if(check[stones[idx]+last+1]){
            ans3=solving_mem(stones,check[stones[idx]+last+1],last+1,check,dp);
        }
        dp[idx][last]=ans1||ans2||ans3;
        return dp[idx][last];
    }
    bool canCross(vector<int>& stones) {
        if(stones.size()<=1) return true;
        if(stones[1]!=1) return false;
        unordered_map<int,int>check;
        for(int i=0;i<stones.size();i++){
            check[stones[i]]=i;
        }
        // return solving_rec(stones,1,1,check);
        vector<vector<int>>dp(stones.size()+1,vector<int>(2000,-1));
        return solving_mem(stones,1,1,check,dp);
    }
};