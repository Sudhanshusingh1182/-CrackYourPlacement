class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        //we will use bfs traversal here 
        
        queue<pair<pair<int,int>,int>>q;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              
              if(grid[i][j]==2){
                  vis[i][j]=2;
                  q.push({{i,j},0});
              }
              
              
          }    
        }
        
        int tm=0;
        
        while(!q.empty()){
            
            auto it = q.front();
            
            int row = it.first.first;
            int col = it.first.second;
            
            int t = it.second;
            
            q.pop();
            
            tm = max(t,tm);
            
            
            
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int newr= row + dx[i];
                int newc = col + dy[i];
                
                if(newr>=0 && newr<n && newc>=0 && newc <m &&
                !vis[newr][newc] && grid[newr][newc]==1){
                    q.push({{newr,newc},t+1});
                    
                    vis[newr][newc]=2;
                    
                }
            }
            
        }
        
        //checking whetehr any rotten orange is still left 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1 && !vis[i][j])
                return -1;
            }
        }
        
        
        return tm;
    }
};