class Solution {
public:
    int fMem(int i , int j ,int n , int m ,vector<vector<char>>& matrix ,vector<vector<int>>&dp){
       if(i<0 || j<0) return 0;
        
       if(dp[i][j]!=-1)  return dp[i][j];

      //  if(matrix.size()==0) return 0;

       int cnt=0;

       if(matrix[i][j]=='1'){
         cnt= 1+ min(fMem(i,j-1,n,m,matrix,dp),min(fMem(i-1,j-1,n,m,matrix,dp),fMem(i-1,j,n,m,matrix,dp)));
       }

       return dp[i][j]= cnt;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m=matrix[0].size();

        if(n==0) return 0;
        
        //trying out tabulation methode
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        int maxSide=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(matrix[i][j]=='1'){
              if(i==0 || j==0) dp[i][j]= 1;
              
              else{
                dp[i][j]= min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
              }
              maxSide= max(maxSide, dp[i][j]);
            }
          }
        }

        return maxSide * maxSide;
         
    }
};