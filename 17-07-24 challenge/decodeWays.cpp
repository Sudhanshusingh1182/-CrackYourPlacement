class Solution {
private:
    int f(int i , string &s,int n , vector<int>&dp){
      if(i==n) return dp[i]=1;

      if(s[i]=='0') return dp[i]=0;

      if(dp[i]!=-1) return dp[i];

      int take1= f(i+1,s,n,dp);

      int take2=0;

      if(i+1<n){
        if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))
         take2 = f(i+2,s,n,dp);
      }

      return dp[i]= take1 + take2;
    }  
public:
    int numDecodings(string s) {
        
        int n= s.length();

        vector<int>dp(101,-1);
        return f(0,s,n,dp);
    }
};