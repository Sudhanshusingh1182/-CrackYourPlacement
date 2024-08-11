class Solution {
public:
    int dr[4]={-1,0,+1,0};
    int dc[4]={0,+1,0,-1};

    int dfs(int r , int c ,vector<vector<int>>&grid , vector<vector<int>>&vis , int n , int m){
        
        if(vis[r][c]!=-1) return vis[r][c];
        
        int ans = 1;

        for(int i=0;i<4;i++){
          int newr= r + dr[i];
          int newc= c + dc[i];
          
          if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]>grid[r][c] )
              ans= max(ans,1 + dfs(newr,newc,grid,vis,n,m));

        }
        vis[r][c]=ans;
        return vis[r][c];

    }
    

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n= matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>vis(n,vector<int>(m,-1));

        int maxi=0;

        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
             int ans= dfs(i,j,matrix,vis,n,m);
             maxi=max(maxi,ans);
          }
        } 

        return maxi;

    }
};