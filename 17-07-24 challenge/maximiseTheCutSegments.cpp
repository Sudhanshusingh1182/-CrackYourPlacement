class Solution
{   
    private:
    int f(int ind , int x , int y , int z, vector<int>&dp){
        
        if(ind<0)  return INT_MIN;
        
        if(ind==0)  return 0;
        
        if(dp[ind]!=-1)  return dp[ind];
        //x wala cut , y wala cut and z wala cut 
        
        int xc = 1 + f(ind-x,x,y,z,dp);
        int yc = 1 + f(ind-y,x,y,z,dp);
        int zc = 1+ f(ind-z , x,y,z,dp);
        
        return dp[ind] = max(xc, max(yc,zc));
        
    }
    
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {   
        //since there is only one varying parameter , single array is required.
        // vector<int>dp(n+1,-1);
        // return max(f(n ,x, y,z,dp),0);
        
        //tabulation 
        vector<int>dp(n+1,INT_MIN);
        
        dp[0]=0;
      
        for(int ind=1;ind<=n;ind++){
            
            if(ind>=x)
             dp[ind] = max(dp[ind] ,1 + dp[ind-x]);
            
            if(ind>=y)
             dp[ind] = max(dp[ind] ,1 + dp[ind-y]);
             
            if(ind>=z) 
             dp[ind] = max(dp[ind] ,1+ dp[ind-z]);
            
        }
        
        return dp[n]<0 ?0 :dp[n];
    }
};