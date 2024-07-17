class Solution {
private:
    int f(int i, int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
          if(i==0 && j==0 ) return grid[i][j];

          if(i<0 || j<0) return 1000000;

          if(dp[i][j]!=-1)  return dp[i][j];

          int path1= grid[i][j] + f(i-1,j,grid,dp);
          int path2= grid[i][j]+ f(i,j-1,grid,dp);

          dp[i][j]= min(path1,path2);

          return dp[i][j];
    }  
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m= grid.size();
        int n= grid[0].size();

        // vector<vector<int>>dp(m,vector<int>(n+1,-1));

        // return f(m-1,n-1,grid,dp);

         vector<vector<int>>dp(m,vector<int>(n+1,0));

         dp[0][0]=grid[0][0];

         for(int j=1; j<n ;j++) dp[0][j]=dp[0][j-1]+ grid[0][j];

         for(int i=1;i<m;i++) dp[i][0]= dp[i-1][0] + grid[i][0];

         for(int i=1;i<m;i++){
          for(int j=1;j<n;j++) dp[i][j]= grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
         }
       
       return dp[m-1][n-1];


    }
};