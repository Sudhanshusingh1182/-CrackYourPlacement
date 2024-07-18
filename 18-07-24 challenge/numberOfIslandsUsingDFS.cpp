class Solution {
  private:
    void dfs(int r,int c, vector<vector<int>>&vis,vector<vector<char>>& grid, int n, int m){
        vis[r][c]=1;
        
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int newr= r + i;
                int newc= c+ j;
                if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && grid[newr][newc]=='1'){
                    dfs(newr,newc,vis,grid,n,m);
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m= grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis ,grid, n,m);
                }
            }
        }
        
        return cnt;
    }
};