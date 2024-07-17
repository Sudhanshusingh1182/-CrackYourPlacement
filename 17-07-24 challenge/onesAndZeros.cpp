class Solution {
 private: 
    int count1(string str){
      int cnt1=0;
      for(int i=0;i<str.length();i++){
        if(str[i]=='1') cnt1++;
      }

      return cnt1;
    }  

    int f(int ind, int m,int n, int sz, vector<string>&str,vector<vector<vector<int>>>&dp){
       
       if(m==0 && n==0) return 0;

       if(m<0 || n<0) return INT_MIN;

       if(ind<0) return 0;

       if(dp[ind][m][n]!=-1) return dp[ind][m][n];

       //include-exclude wala case
       int include=0,exclude=0;
       exclude= f(ind-1,m,n,sz,str,dp);

       //include
       int cnt1= count1(str[ind]);
       int cnt0= str[ind].length()- cnt1;
       if(cnt0 <=m && cnt1<=n) include=1+ f(ind-1 , m-cnt0,n-cnt1,sz, str,dp);

       return  dp[ind][m][n]= max(include,exclude);
    }


public:
    int findMaxForm(vector<string>& str, int m, int n) {
        
        int sz= str.size();

        //3d dp
        // vector<vector<vector<int>>>dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));

        // return f(sz-1,m,n,sz,str,dp);

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(auto &s: str){
           int cnt1= count1(s);
           int cnt0= s.length()-cnt1;

           for(int i=m;i>=cnt0;i--){
            for(int j=n;j>=cnt1;j--){
               dp[i][j]= max(dp[i][j],1+ dp[i-cnt0][j-cnt1]);
            }
           }
        }

        return dp[m][n];
    }
};