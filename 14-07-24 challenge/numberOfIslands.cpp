class Solution {
private:
    void dfs(int i, int j, vector<vector<bool>>&vis,vector<vector<char>>& grid,int n, int m){
       vis[i][j]=1;

       int dr[4]={-1,0,+1,0};
       int dc[4]={0,+1,0,-1};

       for(int x=0;x<4;x++){
        int newr= i+ dr[x];
        int newc= j+ dc[x];

        if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && grid[newr][newc]=='1'){
           dfs(newr,newc,vis,grid,n,m);
        }
       }
    }  
public:
    int numIslands(vector<vector<char>>& grid) {
        //basically we need to find the number of connected components
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));

        int cnt=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='1'){
              cnt++;
              dfs(i,j,vis,grid,n,m);
            }
          }
        }

        return cnt; 

    }
};