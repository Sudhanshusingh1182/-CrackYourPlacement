class Solution{
    public:
    
    int f(int ind1, int ind2, string &str1,string &str2,int n,int m,vector<vector<int>>&dp){
        if(ind1==n || ind2==m) return 0;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(str1[ind1]==str2[ind2]) return dp[ind1][ind2]= 1 + f(ind1+1,ind2+1,str1,str2,n,m,dp);
        
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi,f(i,j,S1,S2,n,m,dp));
            }
        }
        
        return maxi;
    }
};